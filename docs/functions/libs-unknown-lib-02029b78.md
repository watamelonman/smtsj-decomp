# libs/unknown/lib_02029b78

All nine functions match at 100% with the configured mwccarm 2.0/sp1p5.
They are the NitroSystem frame texture/palette VRAM manager. The linker names
remain neutral because `config/arm9/symbols.txt` is human-owned; the descriptive
NitroSystem names are used in the source comments and below.

## Source evidence

The public NitroSystem reconstruction in
[ctrl-cheeb-del/pokeheartgold `lib/NitroSystem/src`](https://github.com/ctrl-cheeb-del/pokeheartgold/tree/master/lib/NitroSystem/src)
contains exact implementations:

- [`gfd_frame_tex_vram_man.c`](https://github.com/ctrl-cheeb-del/pokeheartgold/blob/master/lib/NitroSystem/src/gfd_frame_tex_vram_man.c)
  — `NNS_GfdFreeFrmTexVram`, `NNS_GfdGetFrmTexVramState`,
  `NNS_GfdSetFrmTexVramState`.
- [`gfd_frame_pltt_vram_man.c`](https://github.com/ctrl-cheeb-del/pokeheartgold/blob/master/lib/NitroSystem/src/gfd_frame_pltt_vram_man.c)
  — `NNS_GfdInitFrmPlttVramManager`, `NNS_GfdAllocFrmPlttVram`,
  `NNS_GfdFreeFrmPlttVram`, `NNS_GfdGetFrmPlttVramState`,
  `NNS_GfdSetFrmPlttVramState`, `NNS_GfdResetFrmPlttVramState`.
  `AllocFromLo_` and `AllocFromHi_` are the file-local `static inline` helpers
  behind `NNS_GfdAllocFrmPlttVram`; both inlined into the 316-byte allocator.

The instruction streams agree instruction-for-instruction: loop bounds of five
24-byte texture regions with two copied words, the three-word palette manager
(`lo`, `hi`, `szByte` at +0/+4/+8), the `0x7FFF8` allocation limit and the
`(size >> 3) << 16 | (addr >> 3)` key packing. The function order in the
delinked object (`Init`, `Alloc`, `Free`, `Get`, `Set`, `Reset`) also matches
the public source file. The allocate path's `szByte == 0 ? 8 : up to eight`,
`0x7FFF8` ceiling, `bAllocFromLo == 1` branch, `0x10000` palette limit and
`(szByte >> 3) << 16 | (addr >> 3)` key packing all appear in the delinked
instruction stream.

## Functions

| Linker name | Size | NitroSystem name and behavior |
| --- | --- | --- |
| `func_02029b78` | 8 | `NNS_GfdFreeFrmTexVram` — frame texture release; there is no free list, so it ignores the key and returns zero. |
| `func_02029b80` | 64 | `NNS_GfdGetFrmTexVramState` — copies `head`/`tail` of the five 24-byte texture regions into a ten-word caller block. |
| `func_02029bc0` | 64 | `NNS_GfdSetFrmTexVramState` — restores `head`/`tail` of the five regions from a saved ten-word block. |
| `func_02029c00` | 76 | `NNS_GfdInitFrmPlttVramManager` — stores the palette byte limit, resets the bounds, then optionally installs the default alloc/free functions. |
| `func_02029c4c` | 316 | `NNS_GfdAllocFrmPlttVram` — rounds the size to eight bytes (zero becomes eight), rejects requests at or above `0x7FFF8`, and allocates from the low or high end through the inlined `AllocFromLo_`/`AllocFromHi_` helpers, returning the packed size/address key or zero on failure. |
| `func_02029d88` | 8 | `NNS_GfdFreeFrmPlttVram` — palette keys are never recycled; ignores the key and returns zero. |
| `func_02029d90` | 28 | `NNS_GfdGetFrmPlttVramState` — saves the palette allocator's `lo`/`hi` bounds. |
| `func_02029dac` | 28 | `NNS_GfdSetFrmPlttVramState` — restores the palette allocator's `lo`/`hi` bounds. |
| `func_02029dc8` | 28 | `NNS_GfdResetFrmPlttVramState` — sets `lo = 0` and `hi = szByte`, emptying the palette range. |

Statistics: 620 bytes of code, 9 functions, 9 at 100%. The compiler emits the
loops with pointer strides of 24 bytes and two-word output indices, matching the
original ARM. No inline assembly, byte blobs or special cases are used.

## Validation

`tools/match_gate.py` reports 100% for all nine functions,
`tools/checksum.py` reports the image byte-identical to the original, the
anticheat gate is clean, and the existing unit tests pass. The TU remains
linked from its delinked original until a human marks it `complete`.

## Hard list

None.
