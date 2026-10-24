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

## M1-T475: matched functions

All eight functions match the original ARM instructions. Record and work pointers
are borrowed. Pair access requires a valid record and an index in 0..19; the
original performs no bounds check. No module boundary changes.

| Function | Contract and original-code evidence |
| --- | --- |
| `Unk0979d8_ResetAllEntries` | 02097ddc, 64 bytes. Iterates up to twelve signed slots at work +0x348, stops at the first negative slot, resets each record, then calls ResetAreaEntries. |
| `Unk0979d8_GetPairLo` | 02097d54, 68 bytes. Builds twenty packed pairs using record +0x36 and IDs at +0x28, then returns the indexed low ten bits. LDRH and shifts establish the extraction. |
| `Unk0979d8_GetPairHi` | 02097d98, 68 bytes. Same pair construction; returns the indexed upper six bits. The final shifts establish the split. |
| `Unk0979d8_ResetAreaEntries` | 02097ebc, 68 bytes. Visits three signed slots at work +0x354; skips negative slots and records whose unsigned +0x34 equals 1. Restores remaining records, then resets area position. |
| `Unk0979d8_ClampAllField1e` | 02097e1c, 80 bytes. Calls global ClampField1c, then clamps +0x1e in up to twelve active records at work +0x74 + slot*60. First negative slot ends traversal. |
| `Unk0979d8_ClampAllField20` | 02097e6c, 80 bytes. Calls global ClampField1e, then clamps +0x20 using the same active-slot traversal. |
| `func_02097ad0` | 02097ad0, 132 bytes. NULL and unsigned state +0x34 equal to 1 or 7 return zero. Otherwise checks 0202e840 and the enable argument; when both hold, adds weights 1 and 3 for queried IDs 160 and 151 and weight 5 for record ID 397. Gameplay meaning remains unknown. |
| `func_02098050` | 02098050, 152 bytes. Sums unsigned record bytes +0x38. Modes 0/1 select CountEntries active slots; mode 2 selects three area slots. Modes 0/2 also include unsigned +0x6e from 0202e798. Negative slots are skipped; other modes return zero. |

Typed the work-area, record lookup and pair metadata lookup declarations. Kept
local count/pointer initialization after the mode-dependent byte read to preserve
the original instruction ordering in func_02098050.

### Hard list

None for M1-T475. Instruction matching supplies the acceptance check; the card
requires no new behavioral tests.

## Not done in M1-T476
- `func_02097a20`
- `func_02097f68`
- `func_02097c18`
