# src/game/unit_020986ac.c

M1-T631: all eight functions match the original ARM instructions at 100% objdiff.
Addresses below refer to the original `extract/arm9/arm9.bin`; symbol boundaries
come from `config/arm9/symbols.txt`. Storage ownership remains with the base provider.

| Function | Contract and instruction evidence |
| --- | --- |
| `Unk0986ac_Nop_099230` | No arguments or effects; 0x02099230 is `bx lr` (4 B). |
| `Unk0986ac_Unk_098978` | Returns the supplied signed id minus 111; `sub r0, r0, #111` at 0x02098978 (8 B). BattleShowingTask callers feed this result to the flag-test wrapper. |
| `Unk0986ac_Thunk_02098714` | Returns `Unk0986ac_TestFlagBit(bit)` unchanged; indirect tail branch at 0x0209896c (12 B). |
| `Unk0986ac_Unk_09894c` | Forwards an in-range bit index and constant 1 to `Unk0986ac_SetFlagBit`; tail branch at 0x0209894c (16 B). |
| `Unk0986ac_Unk_09895c` | Forwards an in-range bit index and constant 0 to `Unk0986ac_SetFlagBit`; tail branch at 0x0209895c (16 B). |
| `Unk0986ac_Unk_098980` | Returns the unsigned byte at storage + 13; calls the base helper then `ldrb r0, [r0, #13]` at 0x02098980 (16 B). The byte's meaning remains unknown. |
| `Unk0986ac_Unk_0986ac` | Returns the borrowed 32-bit base-provider address plus 0x5c80; additions of 0x1c80 and 0x4000 at 0x020986ac (20 B). |
| `Unk0986ac_Unk_0986c0` | Returns the borrowed byte address for a bit index; adds signed `index >> 3` to the base helper result at 0x020986c0 (20 B). Callers must enforce storage bounds. |

No new behavior tests are required by this card: instruction identity is checked
against the original object, with the full-image checksum checking the linked build.
No M1-T631 functions remain on the hard list.

## M1-T632

All eight targets match at 100% objdiff. Existing C bodies already produced the
original instructions; this card verifies them and replaces provisional contracts.

| Function | Contract and instruction evidence |
| --- | --- |
| `Unk0986ac_Unk_098990` | Stores the argument byte at borrowed flag storage +13; `strb` at 0x02098990 (20 B). |
| `Unk0986ac_Unk_099300` | Calls `Unk02e000_Unk_02e0cc`, then `Unk05b82c_Unk_05b82c(191)`, and returns 1; relocations and immediate moves at 0x02099300 (24 B). |
| `Unk0986ac_TestFlagBit` | Tests mask `1 << (bit & 7)` in the byte returned by the storage helper; returns 0 or 1. Caller enforces index bounds; 0x02098714 (44 B). |
| `Unk0986ac_FindEmpty` | Scans 23 two-byte entries for a zero first signed byte; returns the index or sentinel 23. Stride-two loads and zero comparisons at 0x020989dc support the name (44 B). |
| `Unk0986ac_Unk_098918` | Takes a signed id, looks it up with `Unk09974c_Unk_099d78(id)`, and returns 0 for a missing borrowed record or absent middle flag field; otherwise returns `Unk09974c_GetFlagsMidMinus1(record)`. The incoming r0 reaches the lookup at 0x02098920 unchanged; its pointer result remains in r0 for `HasFlagsMid(record)` at 0x0209892c and is saved in r4 for the decoder. Caller 0x020c3090 loads the id from a table into r0 before calling at 0x020c3094 (52 B). |
| `Unk0986ac_IsMode012` | Returns 1 for the selector at +44 equal to 0, 1, or 2, otherwise 0. Three comparisons at 0x02098ae0 support the name (52 B). |
| `Unk0986ac_Unk_0989a4` | Reads the handle at borrowed record +4, looks it up with the third argument, and passes the result as argument five to `func_02061f10(a, -1, 0, 0, result)`; relocations and stack store at 0x020989a4 (56 B). |
| `Unk0986ac_Unk_098aa8` | Reads signed n at +56. For n <= 0 clears word +64 and byte +68; otherwise writes `(word_at_60 - 16) * n + 16` and the low byte of `31 * n`. Caller supplies aligned storage through +68 and representable signed arithmetic; 0x02098aa8 (56 B). |

No M1-T632 functions remain on the hard list. No new behavior tests are required;
objdiff checks instruction identity and checksum checks the linked original image.

## Not done in M1-T633
- `Unk0986ac_Unk_099274`
- `Unk0986ac_SetFlagBit`
- `Unk0986ac_Unk_099234`
- `Unk0986ac_Unk_0992b0`
- `Unk0986ac_Unk_09911c`
- `func_02098860`
- `func_020988bc`
- `func_02098740`

## Not done in M1-T634
- `func_02098b14`
- `func_02099318`
- `func_02098a08`
- `func_020987ac`
- `func_02099174`
- `func_020993a8`
- `func_02098fec`
- `func_02098b9c`
- `Unk0986ac_SetFlagBit`: hand-matched
- `Unk0986ac_Unk_099234`: hand-matched
- `Unk0986ac_Unk_099274`: hand-matched
- `Unk0986ac_Unk_0992b0`: hand-matched
- `Unk0986ac_Unk_09911c`: hand-matched
