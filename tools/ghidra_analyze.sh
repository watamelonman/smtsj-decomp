#!/usr/bin/env bash
# Headless Ghidra pass: import the original executable, auto-analyse, export function data.
#   tools/ghidra_analyze.sh <binary> [processor]
# Needs GHIDRA_HOME (Ghidra 11.x+). PS2: install the ghidra-emotionengine-reloaded extension
# (processor MIPS-R5900 / "r5900"); NDS: ARM:LE:32:v5t, loaded at the arm9 base from
# config (or the NTRGhidra loader extension for whole-ROM import).
set -euo pipefail
BIN=${1:?binary}; PROC=${2:-${GHIDRA_PROCESSOR:-}}
: "${GHIDRA_HOME:?set GHIDRA_HOME to your Ghidra install}"
mkdir -p build/ghidra/proj
args=(build/ghidra/proj reforge -import "$BIN" -overwrite
      -scriptPath tools/ghidra -postScript ExportFunctions.py)
[ -n "$PROC" ] && args+=(-processor "$PROC")
[ -n "${GHIDRA_LOADBASE:-}" ] && args+=(-loader BinaryLoader -loader-baseAddr "$GHIDRA_LOADBASE")
REFORGE_OUT=build/ghidra "$GHIDRA_HOME/support/analyzeHeadless" "${args[@]}"
