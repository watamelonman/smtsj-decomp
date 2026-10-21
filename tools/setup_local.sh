#!/usr/bin/env bash
# Local (laptop) bootstrap for the Strange Journey decomp. Arch Linux first, any x86_64 Linux works.
# Idempotent: re-running skips what is already done. Never uses sudo and never downloads a game.
#
#   tools/setup_local.sh [/path/to/SMTSJ.nds]      (default: $SJ_ROM, then ~/Downloads/SMTSJ.nds)
#
# Steps: check prerequisites -> fetch dsd/objdiff-cli/wibo/mwccarm (tools/download_tools.py, pinned in
# config/toolchain.toml) -> verify the ROM against No-Intro -> link it as ./baserom.nds (git-ignored) ->
# dsd rom extract -> configure.py + ninja -> checksum (byte-identical) -> full match_gate -> report +
# progress graph. Nothing copyrighted is committed: dsd, objdiff-cli, tools/wibo, tools/mwccarm,
# extract/, build/, *.nds and arm7_bios.bin are all in .gitignore.
set -euo pipefail
cd "$(dirname "$0")/.."
ROM="${1:-${SJ_ROM:-$HOME/Downloads/SMTSJ.nds}}"
JOBS="${JOBS:-$(( $(nproc) > 2 ? $(nproc) - 1 : 1 ))}"
say() { printf '\n== %s\n' "$*"; }

say "prerequisites"
missing=()
need() { command -v "$1" >/dev/null 2>&1 || missing+=("$2"); }
need python3 python; need git git; need ninja ninja; need arm-none-eabi-objdump arm-none-eabi-binutils
need sha1sum coreutils; need nice coreutils
if [ "$(uname -m)" != x86_64 ]; then echo "note: wibo (runs the Windows mwccarm.exe) is x86_64-only; on $(uname -m) set wine in config/toolchain.toml"; fi
if [ ${#missing[@]} -gt 0 ]; then
  echo "missing: ${missing[*]}"
  echo "install with:  sudo pacman -S --needed $(printf '%s\n' "${missing[@]}" | sort -u | tr '\n' ' ')"
  exit 1
fi
python3 -c 'import sys; sys.exit(0 if sys.version_info >= (3, 11) else 1)' || { echo "python >= 3.11 needed (tomllib)"; exit 1; }
python3 -c 'import matplotlib' 2>/dev/null || echo "optional: sudo pacman -S --needed python-matplotlib   (for tools/progress_graph.py; it can also pip install --user)"
command -v claude >/dev/null || echo "optional: Claude Code not on PATH (only needed for agent-driven waves)"
echo "ok (python3 $(python3 -c 'import platform;print(platform.python_version())'), $(ninja --version 2>/dev/null | sed 's/^/ninja /'), $JOBS build jobs)"

say "build tools"
if [ -x ./dsd ] && [ -x ./objdiff-cli ] && [ -x tools/wibo ] && [ -f tools/mwccarm/2.0/sp1p5/mwccarm.exe ]; then
  echo "present (delete dsd objdiff-cli tools/wibo tools/mwccarm to refetch)"
else
  python3 tools/download_tools.py      # pinned versions; mwccarm.zip checked against its sha256
fi
./dsd --version 2>/dev/null | head -1 || true
./objdiff-cli --version 2>/dev/null | head -1 || true

say "ROM"
[ -f "$ROM" ] || { echo "ROM not found: $ROM  (pass the path, or set SJ_ROM)"; exit 1; }
ROM="$(realpath "$ROM")"
python3 tools/verify_rom.py "$ROM"
if [ "$(readlink baserom.nds 2>/dev/null || true)" != "$ROM" ]; then ln -sfn "$ROM" baserom.nds; fi
echo "baserom.nds -> $ROM   (configure.py uses \$SJ_ROM, then rom_path in config/target.toml, then this link)"
[ -f arm7_bios.bin ] && echo "arm7_bios.bin present: full-ROM check including header CRCs" \
  || echo "no arm7_bios.bin: the ROM check masks the 4 BIOS-dependent CRC bytes (modules are still checked in full)"

say "extract"
if [ -f extract/arm9/arm9.bin ] && [ -f extract/config.yaml ]; then echo "extract/ present"
else ./dsd rom extract --rom "$ROM" --output-path extract; fi

say "configure + build"
python3 configure.py
nice -n 10 ninja -j "$JOBS"

say "checksum"
python3 tools/checksum.py | tail -3

say "match gate (every C file since the first commit)"
ROOT_COMMIT="$(git rev-list --max-parents=0 HEAD | tail -1)"
FORGE_BUILD_CMD="ninja -j $JOBS" FORGE_BASE="$ROOT_COMMIT" nice -n 10 python3 tools/match_gate.py | tail -3
[ -f build/report.base.json ] || cp build/report.json build/report.base.json
python3 tools/anticheat.py --selftest | tail -1

say "progress"
python3 - <<'PY'
import json; m = json.load(open("build/report.json"))["measures"]
print(f"{m['matched_functions']}/{m['total_functions']} functions ({m['matched_functions_percent']:.2f}%), "
      f"{int(m['matched_code'])}/{int(m['total_code'])} code bytes ({m['matched_code_percent']:.2f}%)")
PY
python3 tools/progress_graph.py || echo "progress graph skipped (install python-matplotlib and rerun tools/progress_graph.py)"
if [ -n "$(git status --porcelain --untracked-files=no)" ]; then
  echo "WARNING: setup changed tracked files:"; git status --short --untracked-files=no
fi
say "done. Baseline is byte-identical. Next: LOCAL.md (matching waves by hand or with Claude Code)."
