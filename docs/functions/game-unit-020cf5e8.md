# src/game/unit_020cf5e8.c

## M1-T957: verified matches

All eight functions compile to 100% objdiff matches. Evidence is the original ARM
instructions at the function addresses; field roles remain unknown. Pointer
parameters require valid objects containing the documented offsets.

- `Unk0cf5e8_Nop_0cf62c` (4 B): returns immediately (BX LR at 0x020cf62c).
- `Unk0cf5e8_Nop_0d11e8` (4 B): returns immediately (BX LR at 0x020d11e8).
- `Unk0cf5e8_Nop_0d11ec` (4 B): returns immediately (BX LR at 0x020d11ec).
- `Unk0cf5e8_Thunk_02124258` (12 B): tail-forwards to `Unk1241ec_Unk_124258`
  (0x02124258) through the literal-pool `ldr ip,[pc]; bx ip` branch. Incoming
  registers pass through; the `(void)` C prototype mirrors the target's current
  declaration and is only a local reconstruction, not evidence of no arguments.
- `Unk0cf5e8_Thunk_0212424c` (12 B): tail-forwards to `Unk1241ec_Thunk_02124338`
  (0x0212424c) through the literal-pool `ldr ip,[pc]; bx ip` branch. Incoming
  registers pass through; the `(void)` C prototype mirrors the target's current
  declaration and is only a local reconstruction, not evidence of no arguments.
- `Unk0cf5e8_Unk_0d139c` (24 B): returns the signed comparison of work
  words at 0x28c and 0x194, using LDR/CMP/MOVLT/MOVGE.
- `Unk0cf5e8_Unk_0d13fc` (24 B): returns the signed comparison of work
  words at 0x288 and 0xa0, using LDR/CMP/MOVLT/MOVGE.
- `Unk0cf5e8_Unk_0d1454` (28 B): returns whether object word 0x9c is 1
  and word 0x290 is 0. The short-circuit expression matches the conditional
  load and comparison exactly; the previous hard-list entry was stale.

## Historical hard list (now matched)

These entries are historical; `build/report.json` now reports 100% matches.

- `Unk0cf5e8_Unk_0d1470`: decompiler-derived
- `Unk0cf5e8_Unk_0d14ac`: decompiler-derived
- `Unk0cf5e8_Unk_0d0f94`: decompiler-derived
- `Unk0cf5e8_Unk_0d0fc4`: decompiler-derived
- `Unk0cf5e8_Unk_0d182c`: decompiler-derived
- `Unk0cf5e8_Unk_0cf630`: decompiler-derived

## Historical M1-T958 omissions

`Unk0cf5e8_Unk_0d1490` is now matched at 100%.

- `Unk0cf5e8_Unk_0d1490`
- `func_020d1360`
- `Unk0cf5e8_Unk_0d1414`: decompiler-derived
- `Unk0cf5e8_Unk_0d13b4`: decompiler-derived
- `Unk0cf5e8_Unk_0d0960`: decompiler-derived

## Historical M1-T959 omissions

`Unk0cf5e8_Enter` and `Unk0cf5e8_InitSlots` are now matched at 100%.

- `Unk0cf5e8_Enter`
- `func_020d185c`
- `func_020d19d4`
- `Unk0cf5e8_InitSlots`
- `func_020d16f8`

## Historical M1-T960 omissions
- `func_020cf668`
- `func_020d18a0`
- `func_020d1958`
- `func_020cf8e8`
- `func_020d0ff4`
- `func_020d03c0`
- `func_020d174c`
- `func_020d02c0`
- `Unk0cf5e8_Unk_0d1490`: hand-matched
- `Unk0cf5e8_Enter`: hand-matched
- `Unk0cf5e8_InitSlots`: hand-matched
