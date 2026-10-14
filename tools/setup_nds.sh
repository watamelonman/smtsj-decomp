#!/usr/bin/env bash
# Human-run setup for one DS game (zeldaret/ph + mariopartyDS conventions). Never downloads a
# game. Ran end to end on Strange Journey (BMTE) 2026-10-13.
#   tools/setup_nds.sh /path/to/your/game.nds
set -euo pipefail
ROM=$(realpath "${1:?path to YOUR OWN .nds dump}")
python3 tools/verify_rom.py "$ROM"                      # No-Intro check; stops on mismatch
if ! { [ -x ./dsd ] && [ -d tools/mwccarm ] && [ -x tools/wibo ]; }; then python3 tools/download_tools.py; fi
./dsd rom extract --rom "$ROM" --output-path extract    # decompresses arm9/overlays, decrypts DS Protect
python3 tools/identify.py "$ROM"                        # gamecode, NitroSDK version (from extract), middleware
grep -q '^rom_path' config/target.toml || echo "rom_path = \"$ROM\"" >> config/target.toml
grep -q '^rom_sha1' config/target.toml || echo "rom_sha1 = \"$(sha1sum "$ROM" | cut -d' ' -f1)\"" >> config/target.toml
[ -f config/arm9/config.yaml ] || ./dsd init --rom-config extract/config.yaml --output-path config --build-path build
./configure.py && ninja                                 # baseline: everything linked from delinks
python3 tools/checksum.py                               # modules + ROM (CRC bytes masked without arm7_bios.bin)
# headless Ghidra with dsd's names and ARM/Thumb modes; GHIDRA_MAXMEM caps the heap (shared box)
REFORGE_SYMBOLS=config/arm9/symbols.txt GHIDRA_LOADBASE=$(python3 -c "import tomllib;print(tomllib.load(open('config/target.toml','rb'))['arm9_load'])") \
  nice -n 10 tools/ghidra_analyze.sh extract/arm9/arm9.bin ARM:LE:32:v5t || echo "ghidra skipped"
[ -f build/ghidra/functions.json ] && python3 tools/propose_tus.py
[ -f build/ghidra/functions.json ] && python3 tools/segment_tus.py   # whole-gap TU map -> config/arm9/delinks.segmented.txt
echo ">> review config/arm9/delinks.segmented.txt (or .proposed.txt), paste chosen entries into delinks.txt, then:"
echo "   ./configure.py && ninja && python3 tools/checksum.py && ./objdiff-cli report generate -o build/report.json"
echo "   cp build/report.json build/report.base.json && python3 tools/make_cards.py"
