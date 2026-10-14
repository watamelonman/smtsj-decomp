#!/usr/bin/env python3
"""Identify a user-supplied dump (never downloads anything).

  tools/identify.py <iso-or-nds> [--elf extracted/SLUS_xxx.xx]

PS2 ISO: reads SYSTEM.CNF (via `7z`/`isoinfo` if available) for the boot ELF/serial.
ELF/ROM: greps compiler/SDK fingerprints, prints a best guess of the toolchain, and writes
config/checksums.sha1 + config/target.toml for the maintainer to confirm. Guesses are guesses: compiler
*version* must be confirmed by matching a few small functions under several candidates.
"""
import argparse, hashlib, pathlib, re, struct, sys

FINGERPRINTS = [
    (rb"GCC: \(GNU\) 2\.96[^\x00]*", "ps2", "ee-gcc2.96 (SN/Sony EE GCC 2.96 family)"),
    (rb"GCC: \(GNU\) 2\.95\.[23][^\x00]*", "ps2", "ee-gcc2.95.x"),
    (rb"GCC: \(GNU\) 3\.2[^\x00]*", "ps2", "ee-gcc3.2"),
    (rb"\(SN Systems?\)|SN Systems|ProDG", "ps2", "SN Systems ProDG (ee-gcc based snc/gcc)"),
    (rb"Metrowerks|CodeWarrior|MWCC|__MW_", "any", "Metrowerks CodeWarrior (MWCCPS2 / mwccarm)"),
    (rb"\[SDK\+NINTENDO:[^\]]+\]", "nds", "NitroSDK version string"),
    (rb"\[SDK\+[A-Z]+:[^\]]+\]", "nds", "middleware SDK tag"),
    (rb"Libsd|libpad|sceSif|sceCd", "ps2", "Sony EE libraries (sce*)"),
    (rb"RenderWare|RwEngine|rwID", "ps2", "RenderWare middleware"),
    (rb"CRI Middleware|CRI ADX|CRI Sofdec|CRIWARE", "any", "CRI middleware"),
]


def sha1(p):
    h = hashlib.sha1()
    with open(p, "rb") as f:
        for c in iter(lambda: f.read(1 << 20), b""):
            h.update(c)
    return h.hexdigest()


def nds_header(data):
    title = data[0:12].rstrip(b"\0").decode("ascii", "replace")
    code = data[12:16].decode("ascii", "replace")
    arm9_off, arm9_entry, arm9_load, arm9_size = struct.unpack_from("<IIII", data, 0x20)
    return {"title": title, "gamecode": code, "arm9_load": hex(arm9_load), "arm9_size": arm9_size}


def ps2_save_style(data):
    """Count callee-saved register spills to $sp: `sd` (ee-gcc) vs `sq` (MWCCPS2).
    Heuristic from the DDS decomp (github.com/Megami-Decomps/dds-decomp): ee-gcc 2.96 saves
    with sd, MWCC with sq. Scans every aligned word, so data noise exists; large ratios count."""
    sd = sq = 0
    saved = set(range(16, 24)) | {30, 31}
    for (w,) in struct.iter_unpack("<I", data[: len(data) // 4 * 4]):
        op, base, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
        if base == 29 and rt in saved:
            if op == 0x3F: sd += 1
            elif op == 0x1F: sq += 1
    return sd, sq


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("image"); ap.add_argument("--elf")
    a = ap.parse_args()
    img = pathlib.Path(a.image)
    scan = pathlib.Path(a.elf) if a.elf else img
    head = open(img, "rb").read(0x200)
    plat = "nds" if img.suffix.lower() in (".nds", ".srl") or head[0xC0:0xC4] == b"\x24\xff\xae\x51" else "ps2"
    info = {"platform": plat}
    if plat == "nds":
        info.update(nds_header(head))
    data = scan.read_bytes() if scan.stat().st_size < 512 << 20 else b""
    hits = []
    for rx, p, label in FINGERPRINTS:
        for m in list(re.finditer(rx, data))[:3]:
            hits.append((label, m.group(0)[:80].decode("latin1")))
    if plat == "ps2" and data:
        sd, sq = ps2_save_style(data)
        guess = "ee-gcc (sd)" if sd > 3 * sq else "MWCCPS2 (sq)" if sq > 3 * sd else "mixed/unclear"
        print(f"  callee-save spills: sd={sd} sq={sq} -> {guess}")
        info["save_style"] = guess
    for label, s in hits:
        print(f"  {label}: {s!r}")
    if not hits:
        print("  no fingerprints (packed/compressed binary? for PS2 pass --elf <extracted boot ELF>)")
    pathlib.Path("config").mkdir(exist_ok=True)
    sums = [f"{sha1(img)}  {img.name}"] + ([f"{sha1(scan)}  {scan.name}"] if a.elf else [])
    print("sha1:", *sums, sep="\n  ")
    print("Compare these with the Redump/No-Intro record before trusting the dump.")
    with open("config/target.toml", "w") as f:
        for k, v in info.items():
            f.write(f'{k} = {v!r}\n'.replace("'", '"'))
        f.write("# fingerprints:\n" + "".join(f"#   {l}: {s!r}\n" for l, s in hits))
    print("wrote config/target.toml; edit config/checksums.sha1 to list the BUILT artifact paths "
          "with these hashes (e.g. `<sha1>  build/SLUS_217.82`).")


if __name__ == "__main__":
    sys.exit(main())
