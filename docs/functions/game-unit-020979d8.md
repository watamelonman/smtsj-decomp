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

## Outside M1-T473

- `Unk0979d8_Unk_0979fc`: existing implementation; reset argument made explicit.
- `Unk0979d8_Unk_097f00`: existing implementation.
- `Unk0979d8_Unk_097f34`: existing implementation.

## Not done in M1-T474
- `Unk0979d8_CopyIds`
- `Unk0979d8_ClampField1e`
- `Unk0979d8_ClampField20`
- `Unk0979d8_HasId`
- `Unk0979d8_AddField344`

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
- `Unk0979d8_ClampField1e`: hand-matched
- `Unk0979d8_ClampField20`: hand-matched
- `Unk0979d8_HasId`: hand-matched
- `Unk0979d8_CopyIds`: hand-matched
- `Unk0979d8_GetPairLo`: hand-matched
- `Unk0979d8_GetPairHi`: hand-matched
- `Unk0979d8_ResetAllEntries`: hand-matched
- `Unk0979d8_ClampAllField1e`: hand-matched
- `Unk0979d8_ClampAllField20`: hand-matched
- `Unk0979d8_ResetAreaEntries`: hand-matched
- `Unk0979d8_AddField344`: hand-matched
