#!/usr/bin/env python3
"""Full-build checksum gate: runs the build, then compares SHA-1 of each built artifact with
the expected hash in config/checksums.sha1 (`<sha1>  <path>` lines, sha1sum format).

Expected hashes come from the maintainer's own dump (tools/identify.py writes them) or the Redump /
No-Intro record. Exit 0 only when every artifact matches.
"""
import hashlib, os, pathlib, subprocess, sys

BUILD = os.environ.get("FORGE_BUILD_CMD", "ninja")
SUMS = pathlib.Path("config/checksums.sha1")


def sha1(p):
    h = hashlib.sha1()
    with open(p, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def main():
    if not SUMS.exists() or not SUMS.read_text().strip():
        print("checksum: config/checksums.sha1 missing/empty; run tools/identify.py on your dump first")
        return 1
    r = subprocess.run(BUILD, shell=True, capture_output=True, text=True)
    if r.returncode:
        print(f"checksum: build `{BUILD}` failed:\n" + (r.stdout + r.stderr)[-3000:])
        return 1
    bad = 0
    for line in SUMS.read_text().splitlines():
        if not line.strip() or line.startswith("#"):
            continue
        want, path = line.split(None, 1)
        path = path.strip().lstrip("*")
        if not os.path.exists(path):
            print(f"checksum: {path} not built"); bad += 1; continue
        got = sha1(path)
        if got != want.lower():
            print(f"checksum: {path} sha1 {got} != expected {want}"); bad += 1
    if not bad:
        print("checksum: all artifacts byte-identical to the original")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
