#!/usr/bin/env python3
"""Fetch the build tools the same way zeldaret/ph, zeldaret/st and mariopartyrd/mariopartyDS do
(their tools/download_tool.py). Human-run; agents may not run it (it is in tools/, protected).

  tools/download_tools.py [--only dsd,objdiff,wibo,mwccarm]

Sources (verified 2026-10-13):
  dsd      https://github.com/AetiasHax/ds-decomp/releases/download/<tag>/dsd-<os>-<arch>
  objdiff  https://github.com/encounter/objdiff/releases/download/<tag>/objdiff-cli-<os>-<arch>
  wibo     https://github.com/decompals/wibo/releases/download/<tag>/wibo-x86_64
  mwccarm  https://decomp.aetias.com/files/mwccarm.zip  (the zeldaret scripts use http://;
           plain http timed out from our box, https worked; zip has 1.2/*, 2.0/*, dsi/*)
Versions are pinned in config/toolchain.toml [tools].
"""
import argparse, hashlib, io, os, pathlib, platform, stat, sys, tomllib, urllib.request, zipfile

ROOT = pathlib.Path(__file__).resolve().parent.parent
TOOLS = ROOT / "tools"


def fetch(url):
    print("get", url)
    req = urllib.request.Request(url, headers={"User-Agent": "re-forge"})
    with urllib.request.urlopen(req, timeout=300) as r:
        return r.read()


def put_exe(path, data):
    path.write_bytes(data)
    path.chmod(path.stat().st_mode | stat.S_IXUSR | stat.S_IXGRP | stat.S_IXOTH)


def main():
    ap = argparse.ArgumentParser(); ap.add_argument("--only", default="dsd,objdiff,wibo,mwccarm")
    want = set(ap.parse_args().only.split(","))
    t = tomllib.loads((ROOT / "config/toolchain.toml").read_text()).get("tools", {})
    osn = {"Linux": "linux", "Darwin": "macos", "Windows": "windows"}[platform.system()]
    arch = {"x86_64": "x86_64", "AMD64": "x86_64", "aarch64": "aarch64", "arm64": "aarch64"}[platform.machine()]
    exe = ".exe" if osn == "windows" else ""
    if "dsd" in want:
        put_exe(ROOT / f"dsd{exe}", fetch(f"https://github.com/AetiasHax/ds-decomp/releases/download/{t['dsd']}/dsd-{osn}-{arch}{exe}"))
    if "objdiff" in want:
        put_exe(ROOT / f"objdiff-cli{exe}", fetch(f"https://github.com/encounter/objdiff/releases/download/{t['objdiff']}/objdiff-cli-{osn}-{arch}{exe}"))
    if "wibo" in want and osn == "linux":
        put_exe(TOOLS / "wibo", fetch(f"https://github.com/decompals/wibo/releases/download/{t['wibo']}/wibo-{arch}"))
    if "mwccarm" in want:
        data = fetch(t.get("mwccarm_url", "https://decomp.aetias.com/files/mwccarm.zip"))
        print("mwccarm.zip sha256", hashlib.sha256(data).hexdigest())
        want_sha = t.get("mwccarm_sha256")
        if want_sha and hashlib.sha256(data).hexdigest() != want_sha:
            sys.exit("mwccarm.zip hash changed; check the mirror before trusting it")
        zipfile.ZipFile(io.BytesIO(data)).extractall(TOOLS)   # -> tools/mwccarm/<ver>/
    print("done")


if __name__ == "__main__":
    main()
