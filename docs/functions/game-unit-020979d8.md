# src/game/unit_020979d8.c

## M1-T473: matched functions

All eight functions match the delinked ARM code at 100%. Record pointers are
borrowed; no helper allocates or transfers ownership. Index arguments are
forwarded unchanged to `Unk096754_GetAreaRecordIf` (02096754), which rejects
indices >= 3 and returns NULL for absent slots. Field meanings remain unknown,
so the indexed wrappers retain neutral names.

| Function | Contract and original-code evidence |
| --- | --- |
| `Unk0979d8_ResetFields` | At 020979d8 (36 bytes), NULL returns 0. Otherwise signed halfwords +0x0a and +0x0c are copied to +0x1e and +0x20, and 1 is returned. LDRSH/STRH pairs at 020979e4..020979f0 support the existing reset name. |
| `Unk0979d8_Unk_098124` | At 02098124 (24 bytes), calls the indexed lookup and returns unsigned byte +0x38, or 0 for NULL. LDRB at 02098134 establishes signedness and offset. |
| `Unk0979d8_Unk_09813c` | At 0209813c (24 bytes), returns signed halfword +0x1e, or 0 for NULL. LDRSH at 0209814c establishes the contract. |
| `Unk0979d8_Unk_098154` | At 02098154 (24 bytes), returns signed halfword +0x0a, or 0 for NULL. LDRSH at 02098164 establishes the contract. |
| `Unk0979d8_Unk_09816c` | At 0209816c (32 bytes), saves value across the indexed lookup and calls `Unk0979d8_ClampField1e` (02097b54) only for a present record. Value is forwarded as a full register; this wrapper performs no narrowing. |
| `Unk0979d8_Unk_09818c` | At 0209818c (24 bytes), returns signed halfword +0x20, or 0 for NULL. LDRSH at 0209819c establishes the contract. |
| `Unk0979d8_Unk_0981a4` | At 020981a4 (24 bytes), returns signed halfword +0x0c, or 0 for NULL. LDRSH at 020981b4 establishes the contract. |
| `Unk0979d8_Unk_0981bc` | At 020981bc (32 bytes), saves value across the indexed lookup and calls `Unk0979d8_ClampField20` (02097b84) only for a present record. Value is forwarded as a full register. |

The existing initializer at 020979fc now explicitly passes its record into
`ResetFields`, matching the original live-r0 argument. No module boundary changes.
The unsigned-byte getter uses a byte local with explicit branches so mwcc emits
the original conditional byte load without an extra result conversion.

### Hard list

None for M1-T473.

## M1-T474: matched functions

All eight functions match at 100% with the configured mwcc toolchain. Existing
matching implementations were retained; the two global clamp calls now explicitly
forward their signed argument instead of relying on the live r0 register and an
unprototyped call. No module boundary changes or new layout assumptions.

| Function | Contract and original-code evidence |
| --- | --- |
| `Unk0979d8_Unk_0979fc` | 020979fc, 36 bytes. NULL returns 0; otherwise clears unsigned +0x34, calls ResetFields on the same borrowed record, and returns 1. STRH at 02097a10 and BL at 02097a14 establish the operations. Field meaning is unknown. |
| `Unk0979d8_CopyIds` | 02097bec, 44 bytes. Copies six unsigned halfwords from record +0x28 into a caller-owned six-element buffer. NULL record leaves the output unchanged. The LDRH/STRH loop at 02097bf8..02097c10 supports the copy name; IDs are the same entries searched by HasId. |
| `Unk0979d8_ClampField1e` | 02097b54, 48 bytes. NULL returns 0. Reads signed maximum +0x0a. If value exceeds maximum, stores maximum; otherwise stores max(value, 1). Returns the signed halfword stored at +0x1e. LDRSH, comparisons, and STRH at 02097b60..02097b7c establish the clamp name and ordering, including nonpositive maxima. |
| `Unk0979d8_ClampField20` | 02097b84, 48 bytes. Same ordered clamp, using signed maximum +0x0c and destination +0x20; NULL returns 0. Evidence: 02097b90..02097bac. |
| `Unk0979d8_Unk_097f00` | 02097f00, 52 bytes. Forwards signed value to Unk096754_ClampField1c, then to Unk0979d8_Unk_09816c for slots 0, 1, 2. Calls at 02097f08..02097f2c establish forwarding; the first call consumes the original live r0. Wrappers ignore absent slots. |
| `Unk0979d8_Unk_097f34` | 02097f34, 52 bytes. Forwards signed value to Unk096754_ClampField1e, then to Unk0979d8_Unk_0981bc for slots 0, 1, 2. Evidence: calls at 02097f3c..02097f60 and live r0 on the first call. |
| `Unk0979d8_HasId` | 02097bb4, 56 bytes. NULL returns 0; otherwise compares the full-width integer ID against six unsigned halfwords at +0x28, returning 1 on equality and 0 if absent. LDRH and equality/loop branches at 02097bc4..02097be0 support the membership name. |
| `Unk0979d8_AddField344` | 020980e8, 60 bytes. Adds the signed delta to work-area +0x344, bounds the result to 0..99999999, and returns the stored value. ADD/STR at 020980f8..020980fc, conditional stores through 02098114, and literal at 02098120 establish the field and bounds. The field's gameplay meaning is unknown. |

### Hard list

None for M1-T474. No new tests are required by this card; objdiff checks the
compiled instructions against the original functions.

## Not done in M1-T475
- `Unk0979d8_ResetAllEntries`
- `Unk0979d8_GetPairLo`
- `Unk0979d8_GetPairHi`
- `Unk0979d8_ResetAreaEntries`
- `Unk0979d8_ClampAllField1e`
- `Unk0979d8_ClampAllField20`
- `func_02097ad0`
- `func_02098050`

## Not done in M1-T476
- `func_02097a20`
- `func_02097f68`
- `func_02097c18`
- `Unk0979d8_GetPairLo`: hand-matched
- `Unk0979d8_GetPairHi`: hand-matched
- `Unk0979d8_ResetAllEntries`: hand-matched
- `Unk0979d8_ClampAllField1e`: hand-matched
- `Unk0979d8_ClampAllField20`: hand-matched
- `Unk0979d8_ResetAreaEntries`: hand-matched
