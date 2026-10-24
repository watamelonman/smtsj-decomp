# game/unit_020a9a90 — M1-T420 / M1-T421

All eleven functions below match at 100% in objdiff with mwccarm 2.0/sp1p5.
Names are retained from the symbol map; behavior descriptions follow the
original ARM instructions, without assigning unsupported game-level names.
Resource pointers are borrowed. Mode and glyph indices must select valid
entries; the original does not check bounds. Formatting uses a 32-byte local
buffer and passes its capacity to `func_02013b94`. See DEC-008 for variadic ABI.

| Function | Contract and instruction evidence |
| --- | --- |
| `Unk0a9a90_Nop_0a9a90` | Empty callback; a single `bx lr`. |
| `Unk0a9a90_Unk_0a9a94` | Calls resource setup and accessor, selects a 24-byte slot, follows pointers at +0x14 and +0x54, then returns the unsigned halfword at +4 of a 12-byte glyph record. |
| `func_020a9e14` | Formats text, selects slot and glyph using word table `data_0214d288` and byte table `data_0214d284`, and returns width from `func_020a9bb4` with drawing disabled. The callee accumulates each glyph's +4 metric. |
| `func_020a9e84` | Returns the selected glyph metric through the same two mode tables; retains the original variadic calling convention even though extra arguments are unused. |
| `func_020a9eb4` | Formats and draws at x/y with caller style using `func_020a9bb4`'s final flag set to 1; returns its accumulated width. |
| `func_020a9f34` | Measures text and mutates borrowed signed pixel coordinates. Alignment 1 adds (width-measured)/2 to x, 2 adds width-measured, 3 subtracts half the selected metric from y then falls through to 4, which subtracts measured/2 from x. Other values leave coordinates unchanged after measurement. Division truncates toward zero. |
| `func_020a9fd8` | Formats, adjusts local x/y via `func_020a9f34`, then draws using the mode tables and returns width. CampStatus callers supply coordinates, alignment, width, style and format. |
| `func_020aa078` | Formats and aligns local x/y, then passes a borrowed target and the selected slot/glyph to `func_020a9c88`. Unlike the preceding wrapper, it does not return a measured width. |

## M1-T421 glyph processing

| Function | Contract and instruction evidence |
| --- | --- |
| `func_020a9ac8` | Signed input byte to relative glyph index. `+`, `-`, `/` map to 10–12; `*`, `%`, `=`, `?`, `h` map to 23–27 minus the supplied base when nonzero; space maps to zero; other bytes subtract 48. Evidence: original switch branches and immediate return values. |
| `func_020a9bb4` | Borrows NUL-terminated text and valid slot/base indices; returns the sum of unsigned +4 metrics from 12-byte glyph records. Drawing skips spaces and uses x plus accumulated width, y, scale 1, and caller style. Submission flags begin at 1 and gain bit 30 after the first submitted glyph. Evidence: +0x14/+0x54 resource pointers, halfword loads, and 02058e9c arguments. |
| `func_020a9c88` | Borrows a target, valid slot/base indices, and NUL-terminated text. Source bounds use glyph +2/+6 and +0/+4 halfwords; destination bounds use y and x plus accumulated width. Non-spaces call 0205a508; spaces clear each covered pixel through 0205a0d8, truncating coordinates to unsigned 16 bits. Evidence: original rectangle stores and nested loops. |

Signed-byte cursor tests and explicit unsigned-byte reads converted to signed
arguments preserve the original separate byte loads without volatile access.
All three implementations match instruction words and relocations with the
local comparison helper and score 100% in objdiff. Existing wrappers also remain
at 100%. The TU continues to link from the delinked object until human completion.

## Hard list

None.
