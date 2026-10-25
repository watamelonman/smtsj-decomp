# src/game/unit_020bc1a8.c

## M1-T545

These ARM functions retain the existing C bodies. Evidence is the corresponding
function in `build/delinks/src/game/unit_020bc1a8.o`; offsets below are bytes.
Pointers are borrowed and non-null unless null behavior is specified.

| Function | Size | Evidence and contract |
| --- | ---: | --- |
| `Unk0bc1a8_GetConst0` | 8 | At 020bc420, returns constant zero. |
| `Unk0bc1a8_Unk_0bc504` | 16 | At 020bc504, forwards the payload address and mode to 0bc514 with a zero request argument, via an indirect tail call. The address is represented as a 32-bit DS word. |
| `Unk0bc1a8_GetHeaderWord` | 20 | At 020bc598, reads the aligned header word at payload -8, or returns 0xffff for null. |
| `Unk0bc1a8_GetHeaderWord4` | 20 | At 020bc5ac, reads the aligned header word at payload -4, or returns 0xffff for null. |
| `Unk0bc1a8_SetPrevWord` | 20 | At 020bc5c0, writes the aligned header word at payload -4 and returns 1; null returns 0 without writing. |
| `Unk0bc1a8_Unk_0bc6d4` | 20 | At 020bc6d4, writes the word at context +4 through data_02176ba8. Requires initialized context. |
| `Unk0bc1a8_Unk_0bc6e8` | 20 | At 020bc6e8, reads that same context word. Requires initialized context. |
| `Unk0bc1a8_Unk_0bc4e0` | 36 | At 020bc4e0, calls 0bcc34 with the object base, then invokes the optional function pointer at +28 with payload base +52. Requires a live object; callback may be null. |

Neutral names remain because the instructions establish operations but do not
establish the application meaning of the context word or callback.

Validation: all eight functions report 100% in objdiff. The match build,
checksum (all artifacts byte-identical), anticheat, and nine tool tests pass.
No new tests are required by this card; objdiff checks the original instructions.

## Hard list

No M1-T545 functions remain on the hard list.
The following older entries concern other cards:

- `Unk0bc1a8_Unk_0bc9b4`: decompiler-derived
- `Unk0bc1a8_Unk_0bcc34`: decompiler-derived

## Not done in M1-T546
- `Unk0bc1a8_SetFlag4Inv`
- `Unk0bc1a8_SetFlag1Inv`
- `Unk0bc1a8_Unk_0bc514`
- `Unk0bc1a8_IsSlotEmpty`
- `func_020bc614`
- `Unk0bc1a8_Unk_0bc5d4`

## Not done in M1-T547
- `Unk0bc1a8_IsSlotEmptyOrFlag8`
- `Unk0bc1a8_Unk_0bc490`
- `func_020bc1a8`
- `func_020bc8c8`
- `func_020bc3bc`
- `func_020bc428`
- `func_020bcbc4`
- `func_020bc6fc`
- `Unk0bc1a8_Unk_0bc928`: decompiler-derived

## Not done in M1-T548
- `func_020bc770`
- `func_020bc814`
- `func_020bc2fc`
- `func_020bc9f4`
- `func_020bcacc`
- `func_020bc200`
- `Unk0bc1a8_Unk_0bc514`: decompiler-derived (plain cleanup)
- `Unk0bc1a8_Unk_0bc5d4`: decompiler-derived (plain+fix cleanup)
- `Unk0bc1a8_Unk_0bc490`: hand-matched
- `Unk0bc1a8_SetFlag4Inv`: hand-matched
- `Unk0bc1a8_SetFlag1Inv`: hand-matched
- `Unk0bc1a8_IsSlotEmpty`: hand-matched
- `Unk0bc1a8_IsSlotEmptyOrFlag8`: hand-matched
