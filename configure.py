#!/usr/bin/env python3
"""Generate build.ninja for a ds-decomp project (shape copied from zeldaret/ph and
mariopartyrd/mariopartyDS tools/configure.py). UNTESTED: no ROM was available.

Unmatched code stays as dsd-delinked objects (build/delinks); a TU switches to C when its
`complete` entry in config/arm9/delinks.txt is set by a reviewed card. No INCLUDE_ASM.
config/toolchain.toml:
  mwcc_dir = "tools/mwccarm/2.0/sp1p5"   # the maintainer supplies; same layout as pret/zeldaret
  wine = "wine"                           # or wibo
  cflags = "-O4,p -proc arm946e -enum int -lang c99 -Cpp_exceptions off -interworking -gccinc -nolink -msgstyle gcc -sym on"
  decompme_compiler = "mwcc_30_131"
"""
import pathlib, tomllib

ROOT = pathlib.Path(__file__).parent


def main():
    tc = tomllib.loads((ROOT / "config/toolchain.toml").read_text())
    mw, wine, dsd = tc["mwcc_dir"], tc.get("wine", "wine"), tc.get("dsd", "dsd")
    cfg = "config/arm9/config.yaml"
    L = [
        f"rule mwcc\n  command = {wine} {mw}/mwccarm.exe {tc['cflags']} -i include -i src -c $in -o $out\n  description = mwcc $in",
        f"rule delink\n  command = {dsd} delink --config-path {cfg}",
        f"rule lcf\n  command = {dsd} lcf --config-path {cfg} --lcf-file build/linker_script.lcf --objects-file build/objects.txt",
        f"rule mwld\n  command = {wine} {mw}/mwldarm.exe -proc v5te -nostdlib -interworking -m _start -map closure,unused -o $out @build/objects.txt build/linker_script.lcf",
        f"rule rom\n  command = {dsd} rom build --config build/rom_config.yaml --rom $out",
        f"rule objdiff\n  command = {dsd} objdiff --config-path {cfg} --scratch --compiler {tc.get('decompme_compiler', 'mwcc_30_131')} --custom-make ninja",
        "build build/delinks.stamp: delink", "build build/linker_script.lcf build/objects.txt: lcf",
    ]
    objs = []
    for c in sorted(list(ROOT.glob("src/**/*.c")) + list(ROOT.glob("src/**/*.cpp"))):
        rel = c.relative_to(ROOT)
        o = f"build/src/{rel.relative_to('src').with_suffix('.o')}"
        L.append(f"build {o}: mwcc {rel}"); objs.append(o)
    L += [f"build build/arm9.o: mwld build/linker_script.lcf | build/delinks.stamp {' '.join(objs)}",
          "build build/rom.nds: rom | build/arm9.o", "build objdiff.json: objdiff",
          "default build/rom.nds objdiff.json"]
    (ROOT / "build.ninja").write_text("\n".join(L) + "\n")
    print(f"wrote build.ninja ({len(objs)} C units)")


if __name__ == "__main__":
    main()
