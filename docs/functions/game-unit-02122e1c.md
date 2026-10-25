# src/game/unit_02122e1c.c

The eight M1-T747 functions match the original ARM instructions at 100% objdiff.
Offsets below are byte offsets within a borrowed work object. Indexed accesses
require caller-validated indices into the backing storage; these routines do not
check bounds. Field and callee semantics remain unknown, so neutral names stay.

- `Unk122e1c_SetUnkFields64_b0` (0x02122f7c, 12 B): writes its second and third arguments to +0x64 and +0xb0. Evidence: two `str` instructions with those offsets. The descriptive name describes only these observed stores.
- `Unk122e1c_Unk_122f88` (12 B): writes a word to +0x78 + index*4. Evidence: shifted-index `add`, then `str` at +0x78.
- `Unk122e1c_Unk_122f94` (12 B): reads a word from +0x78 + index*4. Evidence: shifted-index `add`, then `ldr` at +0x78.
- `Unk122e1c_Unk_122fa0` (12 B): writes a word to +0xc8 + index*4. Evidence: shifted-index `add`, then `str` at +0xc8.
- `Unk122e1c_Unk_12331c` (16 B): forwards the readable work word at +0x14 to `Unk0cb32c_Unk_0cb57c`, discarding its return value. Evidence: `ldr r0, [r0, #0x14]` and indirect tail call with an absolute callee relocation.
- `Unk122e1c_Unk_122f54` (20 B): returns 1 iff the byte at +0x60 is zero, otherwise 0. Evidence: `ldrb`, comparison with zero, conditional 1/0 moves.
- `Unk122e1c_Unk_122f68` (20 B): returns 1 iff the byte at +0x60 is eight, otherwise 0. Evidence: `ldrb`, comparison with eight, conditional 1/0 moves.
- `Unk122e1c_Unk_12332c` (20 B): forwards the readable work word at +0x14 and constant 1 to `func_0205caa8`, discarding its return value. Evidence: field load, `mov r1, #1`, and indirect tail call with an absolute callee relocation.

## M1-T748

All eight functions below match at 100% objdiff. Work pointers borrow writable
storage; indexed accesses require sufficient backing storage unless stated otherwise.
Names remain neutral where the instructions do not establish a higher-level purpose.

- `func_0212351c` (24 B): writes 0 for a zero value, otherwise 1, to +0x78 + index*4. Evidence: conditional moves and indexed store at 0212351c. Separate branch stores preserve the original compiler scheduling.
- `Unk122e1c_ClearSlots` (32 B): clears six slot words at +0xf8. Evidence: six-iteration indexed store loop at 02122fd0.
- `Unk122e1c_Unk_1241cc` (32 B): forwards the indexed word at +0x10 and the corresponding word from data_0213cd7c to func_0205caa8. Evidence: indexed loads and tail call at 021241cc. Both indices must be valid.
- `Unk122e1c_SetSlot` (36 B): writes one of six slots at +0xf8; null pointers and indices outside [0, 6) are ignored. Evidence: pointer and signed range checks at 02122fac.
- `Unk122e1c_Unk_123024` (36 B): calls Unk0fedd4_SetState1, clears +0x114/+0x61, and writes 1 to +0x60. Evidence: calls and stores at 02123024.
- `Unk122e1c_Unk_123048` (36 B): same observed stores with 2 at +0x60. Evidence: 02123048.
- `Unk122e1c_Unk_1232f8` (36 B): same observed stores with 6 at +0x60. Evidence: 021232f8.
- `Unk122e1c_Unk_1232c8` (48 B): calls Unk0fedd4_SetState0 and Unk0cb32c_Unk_0cb57c with +0x14, clears +0x114/+0x60, and stores -92 at +0xb8/+0x6c. Evidence: 021232c8 calls and stores.

No M1-T747 or M1-T748 functions remain on the hard list. Other existing
implementations are outside this card: 122ff0, 123294, 12306c, and 123534.
