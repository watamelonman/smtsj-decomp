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

No M1-T747 functions remain on the hard list. Other entries below predate this card.

- `Unk122e1c_Unk_123024`: decompiler-derived
- `Unk122e1c_Unk_123048`: decompiler-derived
- `Unk122e1c_Unk_1232f8`: decompiler-derived
- `Unk122e1c_Unk_1232c8`: decompiler-derived

## Not done in M1-T748
- `func_0212351c`
- `Unk122e1c_ClearSlots`
- `Unk122e1c_Unk_1241cc`
- `Unk122e1c_SetSlot`
- `Unk122e1c_Unk_122ff0`: decompiler-derived
- `Unk122e1c_Unk_123294`: decompiler-derived
- `Unk122e1c_Unk_12306c`: decompiler-derived

## Not done in M1-T749
- `Unk122e1c_Unk_123534`
- `func_021230b4`
- `func_02123340`
- `func_02122e1c`
- `func_021233e0`
- `Unk122e1c_Unk_1241cc`: decompiler-derived (plain cleanup)
- `Unk122e1c_SetSlot`: hand-matched
- `Unk122e1c_ClearSlots`: hand-matched
- `Unk122e1c_Unk_123534`: hand-matched
