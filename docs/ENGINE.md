# Engine: Nintendo DS matching decompilation (ds-decomp + mwccarm + objdiff)

Conventions follow zeldaret/ph, zeldaret/st, mariopartyrd/mariopartyDS (ds-decomp) and
pret pokediamond/pokeplatinum (see re-forge `docs/prior-art.md`).

## Pipeline (human steps marked H)
1. **identify** (H) `tools/identify.py game.nds`: gamecode, arm9 load address, NitroSDK tag,
   sha1 (check against No-Intro). The SDK tag narrows the mwccarm version; confirm by
   matching small functions with candidate compilers.
2. **split** (H) `tools/setup_nds.sh game.nds`: `dsd rom extract` -> `dsd init` -> `dsd delink`
   -> `dsd lcf`. The configs in `config/arm9/` (delinks.txt, symbols.txt, relocs.txt) are
   human-owned. The repo keeps no assembly; unmatched code links from delinked objects.
3. **analyse** (H) headless Ghidra on `extract/arm9/arm9.bin` at the load address
   (ARM:LE:32:v5t; Thumb functions are detected by analysis) -> `build/ghidra/functions.json`.
   Also sig-match NitroSDK/MSL with `dsd sig apply` before naming game code.
4. **cards** (H) `tools/make_cards.py`: a card per translation unit (a delink entry).
5. **match** (agents) write `src/<unit>.c(pp)` until objdiff = 100%; then a human flips the
   unit to `complete` in delinks.txt so it links from C.
6. **gates** policy -> anticheat -> test -> match -> checksum (`dsd rom build` output
   sha1 == retail ROM).
7. **review** readability, as in the PS2 preset.
8. **hard functions** `tools/decompme.py` (platform `nds_arm9`) or `dsd objdiff --scratch`.

## Rules for workers
- No `asm` functions/blocks (mwcc `asm void f() {}`), no `.incbin`, no byte arrays as code.
- C++ games: mangled names must match (`symbols.txt`); keep class layout in `include/`.
- Thumb vs ARM: check the function's mode in objdiff; use `#pragma thumb on/off` only where
  the original was Thumb (this pragma is allowed; it selects instruction set, not asm).

## Toolchain (fetched like zeldaret/ph, zeldaret/st, mariopartyDS)
`tools/download_tools.py` (pins in config/toolchain.toml `[tools]`) downloads dsd, objdiff-cli,
wibo, and `mwccarm.zip` from https://decomp.aetias.com/files/mwccarm.zip, the mirror the
zeldaret and Mario Party DS scripts fetch automatically. That zip holds mwccarm 1.2/{base,b56,sp2,sp2p3,sp3,sp4},
2.0/{base,sp1,sp1p2,sp1p5,sp1p6,sp1p7,sp2,sp2p2,sp2p3,sp2p4} and dsi/*. On Linux it runs under
**wibo** (zeldaret default; wine works with `wine = "wine"`). pret/pokediamond instead asks users
to get mwccarm.zip from the pret Discord; pret/pokeplatinum uses mid-kid/metroskrew 0.1.3
(a packaged mwccarm, `tools/devtools/get_metroskrew.sh`). Pick the version per game by matching
a few small functions; 2.0/sp1p5 is only the zeldaret default.
`tools/verify_rom.py` checks the dump against config/nointro.toml before anything is extracted.
Optional: zeldaret also fetch encounter/sjiswrap for Shift-JIS string literals in source; add it
if the game's source uses Japanese strings.

## Verified vs assumed
- Verified: tool self-tests; dsd command names/flags from its README (2026-10).
- Assumed/untested: configure.py's ninja rules and the mwldarm flags are modelled on
  zeldaret/ph and mariopartyDS but have not been run; `dsd lcf` output-file flags may differ by
  dsd version (check `dsd lcf --help`).
