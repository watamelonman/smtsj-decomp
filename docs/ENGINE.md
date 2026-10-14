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

## Verified vs assumed (Strange Journey BMTE, 2026-10-13, on the shared box)
- Verified end to end: verify_rom (No-Intro match) -> download_tools -> `dsd rom extract`
  (decompress + DS Protect decrypt) -> identify (NitroSDK 4.2 from arm9 build info) ->
  `dsd init --output-path config` -> configure.py -> ninja (delink, lcf, mwldarm, rom config,
  rom build) -> checksum: arm9/itcm/dtcm/ov000/ov001 byte-identical; full ROM identical
  except the 4 BIOS-dependent CRC bytes (0x6C-0x6D secure-area CRC, 0x15E-0x15F header CRC).
  Add your own `arm7_bios.bin` (as zeldaret does) to make the full ROM match.
- Verified: headless Ghidra 12.1.4 (OpenJDK 21, 2 GB heap, 2 CPUs, ~2 min) with
  ReForgeSymbols (pre) + ReForgeExport (post); propose_tus -> 13 anchor TUs -> configure ->
  checksum still identical -> objdiff report -> make_cards (13 cards).
- Verified: match gate on a probe TU (correct C passes at 100%, wrong field offset fails at
  99.5%); flipping a TU to `complete` links the compiled C and the image still matches.
- Compiler: three tiny functions matched with 2.0/sp1p5. The same probes rule out mwccarm
  1.2 (`push {r3, lr}` padding) but give identical output on every 2.0 release, so the exact
  2.0 service pack is NOT yet pinned. Settle it with a 50-200 byte function compiled under
  2.0/base, sp1, sp1p2, sp1p5, sp1p6, sp1p7, sp2, sp2p2, sp2p3, sp2p4.
- Not yet: overlays/ITCM in Ghidra (only main arm9 is imported), C++ name mangling, `.data`/
  `.rodata`/`.bss` ranges for TUs, decomp.me upload, dsd `check modules/symbols` rules.
