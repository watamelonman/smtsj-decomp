#!/usr/bin/env bash
# Human-run setup for one DS game, following zeldaret/ph + mariopartyDS (ds-decomp).
# Never downloads a game. UNTESTED end to end.   tools/setup_nds.sh /path/to/your/game.nds
set -euo pipefail
ROM=${1:?path to YOUR OWN .nds dump}
DSD=${DSD:-./dsd}
python3 tools/verify_rom.py "$ROM"    # No-Intro check; stop on mismatch
[ -x ./dsd ] && [ -d tools/mwccarm ] || python3 tools/download_tools.py
python3 tools/identify.py "$ROM"         # gamecode, NitroSDK tag, sha1 (check vs No-Intro)
"$DSD" rom extract --rom "$ROM" --output-path extract
"$DSD" init --rom-config extract/config.yaml --output-path config --build-path build
# headless Ghidra on the arm9 binary at its load address (from identify.py / header)
GHIDRA_LOADBASE=${GHIDRA_LOADBASE:-0x02000000} tools/ghidra_analyze.sh extract/arm9/arm9.bin ARM:LE:32:v5t || echo "ghidra skipped"
./configure.py && ninja
grep -q rom_sha1 config/target.toml || echo "rom_sha1 = \"$(sha1sum "$ROM" | cut -d' ' -f1)\"" >> config/target.toml
./configure.py   # rewrites config/checksums.sha1 (modules + ROM if arm7_bios.bin)
python3 tools/checksum.py
./objdiff-cli report generate -o build/report.json && cp build/report.json build/report.base.json
python3 tools/make_cards.py --report build/report.json
