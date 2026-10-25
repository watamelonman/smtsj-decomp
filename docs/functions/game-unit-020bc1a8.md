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

## M1-T546

Evidence is the original ARM instructions in
`build/delinks/src/game/unit_020bc1a8.o`; all offsets below are bytes.

| Function | Size | Evidence and contract |
| --- | ---: | --- |
| `Unk0bc1a8_SetFlag4Inv` | 40 | 020bc548: nonzero mode clears mask 4 in payload -12; zero sets it. Null is ignored; other payloads require an aligned writable header. |
| `Unk0bc1a8_SetFlag1Inv` | 40 | 020bc570: same operation with mask 1. |
| `Unk0bc1a8_Unk_0bc514` | 52 | 020bc514: calls 02061424 on payload -52; nonzero mode then passes header -4 and the request word to 0bcacc. Payload is a live DS address. |
| `Unk0bc1a8_IsSlotEmpty` | 56 | 020bc650: signed index >=41 returns 1, otherwise tests the slot object against null. Other indices must address the initialized table. |
| `func_020bc614` | 60 | 020bc614: scans 41 twelve-byte slots and copies object +40 to +36 when occupied. Context is reloaded each iteration; see DEC-010. |
| `Unk0bc1a8_Unk_0bc5d4` | 64 | 020bc5d4: if context is absent, allocates eight bytes, installs data_0215034c as the table and sets the second word to 1. |
| `Unk0bc1a8_Unk_0bc9b4` | 64 | 020bc9b4: builds a borrowed 72-byte stack request through 0bc8c8 with mode 1; on success forwards it and the slot to 0bc770. |
| `Unk0bc1a8_Unk_0bcc34` | 72 | 020bcc34: scans 41 slots, clears the first object address equal to the supplied DS address, returns 1 on finding it and 0 otherwise. Requires initialized context. |

Seven existing bodies already matched and retain their instruction sequences.
The new loop initially allowed the compiler to hoist the context load; preserving
that observed read with volatile gives identical instructions (DEC-010).
All eight requested functions report 100%. No M1-T546 hard functions remain.
No new tests: the card waives them and objdiff verifies the original instructions.

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
- `Unk0bc1a8_Unk_0bc490`: hand-matched
- `Unk0bc1a8_IsSlotEmptyOrFlag8`: hand-matched
