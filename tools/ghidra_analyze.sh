#!/usr/bin/env bash
# Headless Ghidra pass (verified on Ghidra 12.1.4 + OpenJDK 21, Strange Journey arm9).
#   tools/ghidra_analyze.sh <binary> [processor]
# Env: GHIDRA_HOME (default /opt/ghidra/ghidra_*), GHIDRA_LOADBASE (raw binaries),
#      GHIDRA_MAXMEM (default 2G; the box is shared), REFORGE_SYMBOLS (dsd symbols.txt).
set -euo pipefail
BIN=${1:?binary}; PROC=${2:-${GHIDRA_PROCESSOR:-}}
GHIDRA_HOME=${GHIDRA_HOME:-$(find /opt/ghidra -maxdepth 1 -name "ghidra_*" -type d 2>/dev/null | sort | tail -1)}
[ -x "$GHIDRA_HOME/support/analyzeHeadless" ] || { echo "set GHIDRA_HOME"; exit 1; }
mkdir -p build/ghidra/proj
args=(build/ghidra/proj reforge -import "$BIN" -overwrite -max-cpu "${GHIDRA_CPUS:-2}"
      -scriptPath tools/ghidra -preScript ReForgeSymbols.java -postScript ReForgeExport.java -log build/ghidra/analyze.log)
[ -n "$PROC" ] && args+=(-processor "$PROC")
[ -n "${GHIDRA_LOADBASE:-}" ] && args+=(-loader BinaryLoader -loader-baseAddr "$GHIDRA_LOADBASE")
# analyzeHeadless reads GHIDRA_HEADLESS_MAXMEM (Ghidra 11/12 support/analyzeHeadless)
GHIDRA_HEADLESS_MAXMEM=${GHIDRA_MAXMEM:-2G} REFORGE_OUT=build/ghidra "$GHIDRA_HOME/support/analyzeHeadless" "${args[@]}"
