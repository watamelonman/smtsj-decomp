#!/usr/bin/env python3
"""Generate build.ninja for a ds-decomp project. Rule chain copied from zeldaret/ph
tools/configure.py and verified on Strange Journey (BMTE) 2026-10-13:
  dsd delink -> dsd lcf -> mwccarm (src) -> mwldarm (arm9.o) -> dsd rom config -> dsd rom build
Object paths come from `dsd json delinks` (object_to_link per delinks.txt file entry), so a
src/<name>.c is compiled to whatever object dsd expects for the entry named <name>.

config/toolchain.toml: mwcc_dir, wine (tools/wibo), dsd, cflags, ldflags, decompme_compiler.
Also writes config/checksums.sha1: every module (arm9, itcm, dtcm, overlays) against the
extracted originals, plus the full ROM when arm7_bios.bin is present (the secure-area CRC at
0x6C and header CRC at 0x15E cannot be recomputed without it, same as zeldaret).
"""
import hashlib, json, pathlib, subprocess, tomllib

ROOT = pathlib.Path(__file__).resolve().parent
CFG = "config/arm9/config.yaml"
MASK = [(0x6C, 0x6D), (0x15E, 0x15F)]  # secure-area CRC16, header CRC16
LDFLAGS = "-proc arm946e -nodead -nostdlib -interworking -map closure,unused -msgstyle gcc"


def sha1(p):
    return hashlib.sha1(pathlib.Path(p).read_bytes()).hexdigest()


def main():
    tc = tomllib.loads((ROOT / "config/toolchain.toml").read_text())
    mw, wine, dsd = tc["mwcc_dir"], tc.get("wine", "tools/wibo"), tc.get("dsd", "./dsd")
    info = json.loads(subprocess.run([dsd, "json", "delinks", "-c", CFG], cwd=ROOT,
                                     capture_output=True, text=True, check=True).stdout)
    lcf, objs_file = info["arm9_lcf_file"], info["arm9_objects_file"]
    files = info["files"]
    bios = (ROOT / "arm7_bios.bin").is_file()
    bios_flag = "--arm7-bios arm7_bios.bin" if bios else ""
    cfgs = [str(p.relative_to(ROOT)) for p in (ROOT / "config/arm9").rglob("*.txt")] + [CFG]
    L = [
        f"rule mwcc\n  command = {wine} {mw}/mwccarm.exe {tc['cflags']} -i include -i src -c $in -o $out\n  description = mwcc $in",
        f"rule delink\n  command = {dsd} delink --config-path {CFG}\n  description = dsd delink",
        f"rule lcf\n  command = {dsd} lcf -c {CFG}\n  description = dsd lcf",
        f"rule mwld\n  command = {wine} {mw}/mwldarm.exe {tc.get('ldflags', LDFLAGS)} -m Entry @{objs_file} {lcf} -o $out\n  description = mwldarm",
        f"rule rom_config\n  command = {dsd} rom config --elf $in --config {CFG}",
        f"rule rom_build\n  command = {dsd} rom build --config $in --rom $out {bios_flag}",
        f"rule objdiff\n  command = {dsd} objdiff --config-path {CFG} --scratch --compiler {tc.get('decompme_compiler', 'mwcc_30_131')} --c-flags \"{tc['cflags']}\" --custom-make ninja --skip-absent-objects",
    ]
    delinks = [f["delink_file"] for f in files]
    L.append(f"build {' '.join(delinks)}: delink {' '.join(cfgs)}")
    L.append(f"build {lcf} {objs_file}: lcf {' '.join(cfgs)}")
    link_inputs, base_objs = [], []
    for f in files:
        src = ROOT / f["name"]          # delinks.txt entries are named by source path
        src = src if src.suffix in (".c", ".cpp") and src.is_file() else None
        if src is not None:
            # objdiff base (build/src/X.o); dsd links it instead of the delink once `complete`
            base = "build/" + str(pathlib.Path(f["name"]).with_suffix(".o"))
            L.append(f"build {base}: mwcc {src.relative_to(ROOT)}")
            base_objs.append(base)
        link_inputs.append(f["object_to_link"])
    L += [f"build build/arm9.o: mwld {lcf} {objs_file} | {' '.join(link_inputs)}",
          "build build/build/rom_config.yaml: rom_config build/arm9.o",
          "build build/rom.nds: rom_build build/build/rom_config.yaml",
          # regenerate after base objects exist, else --skip-absent-objects drops their base_path
          f"build objdiff.json: objdiff {' '.join(cfgs)} | {' '.join(base_objs)}",
          f"default build/rom.nds objdiff.json {' '.join(base_objs)}"]
    (ROOT / "build.ninja").write_text("\n".join(L) + "\n")

    sums = []
    mods = [("extract/arm9/arm9.bin", "build/build/arm9.bin"), ("extract/arm9/itcm.bin", "build/build/itcm.bin"),
            ("extract/arm9/dtcm.bin", "build/build/dtcm.bin")]
    mods += [(str(p.relative_to(ROOT)), f"build/build/arm9_{p.stem}.bin")
             for p in sorted((ROOT / "extract/arm9_overlays").glob("ov*.bin"))]
    for orig, built in mods:
        sums.append(f"{sha1(ROOT / orig)}  {built}")
    tgt = tomllib.loads((ROOT / "config/target.toml").read_text()) if (ROOT / "config/target.toml").exists() else {}
    if bios and tgt.get("rom_sha1"):
        sums.append(f"{tgt['rom_sha1']}  build/rom.nds")
    elif tgt.get("rom_path") and pathlib.Path(tgt["rom_path"]).is_file():
        # without the BIOS: whole ROM with the 4 BIOS-dependent CRC bytes masked out
        data = bytearray(pathlib.Path(tgt["rom_path"]).read_bytes())
        for a, b in MASK:
            data[a:b + 1] = bytes(b - a + 1)
        sums.append(f"{hashlib.sha1(data).hexdigest()}  build/rom.nds  mask=" +
                    ",".join(f"{a:#x}-{b:#x}" for a, b in MASK))
    else:
        sums.append("# full-ROM check off: set rom_path in config/target.toml or add arm7_bios.bin")
    (ROOT / "config/checksums.sha1").write_text("\n".join(sums) + "\n")
    print(f"wrote build.ninja ({len(files)} delink units, {len(mods)} module checksums, rom check {'bios' if bios else ('masked' if tgt.get('rom_path') else 'off')})")


if __name__ == "__main__":
    main()
