#!/usr/bin/env python3
"""Hash the user's ROM and compare with the No-Intro entry in config/nointro.toml.

  tools/verify_rom.py game.nds            # exit 0 = matches a known good dump
Checks the size, SHA-1 and header gamecode. No-Intro's DS set ships both "Decrypted" and
"Encrypted" (secure-area) dumps; a mismatch with the right size may only be the other form.
"""
import hashlib, pathlib, sys, tomllib

ROOT = pathlib.Path(__file__).resolve().parent.parent


def main():
    rom = pathlib.Path(sys.argv[1])
    db = tomllib.loads((ROOT / "config/nointro.toml").read_text())
    code = rom.open("rb").read(16)[12:16].decode("ascii", "replace")
    h = hashlib.sha1(); size = 0
    with rom.open("rb") as f:
        for c in iter(lambda: f.read(1 << 20), b""):
            h.update(c); size += len(c)
    sha = h.hexdigest()
    print(f"{rom.name}: gamecode {code}, {size} bytes, sha1 {sha}")
    e = db.get(code)
    if not e:
        print(f"no No-Intro entry for {code} in config/nointro.toml"); return 2
    ok = sha == e["sha1"] and size == e["size"]
    print(f"No-Intro: {e['name']}: sha1 {e['sha1']}, {e['size']} bytes -> {'MATCH' if ok else 'MISMATCH'}")
    if not ok and size != e["size"]:
        print("size differs: trimmed dump? re-dump untrimmed")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
