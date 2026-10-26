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

## M1-T958: verified matches

All eight requested functions report 100% in `build/report.json`. Existing
bodies were verified against the original ARM instructions and given typed
pointer contracts; `func_020d1360` was added from its original control flow.
Work and object pointers are borrowed, valid, and large enough for the listed
fields. Unknown field/provider semantics retain neutral names.

- `Unk0cf5e8_Unk_0d1490` (28 B): returns whether signed word 0x98 is 1
  and word 0x294 is zero; CMP/LDREQ/CMPEQ establish the short circuit.
- `Unk0cf5e8_Unk_0d1470` (32 B): passes `data_02150648` to
  `Unk0de678_Unk_0dec94`, then writes 1 to work word 0x290.
- `Unk0cf5e8_Unk_0d14ac` (32 B): passes `data_02150654` to the same
  provider, then writes 1 to work word 0x294.
- `Unk0cf5e8_Unk_0d0f94` (48 B): calls `Unk0a0ce4_Unk_0a0da4(5)`,
  writes 4 to work word 4, calls `func_020d1360(work, 20)`, then stores
  its incoming value at word 0x0c. Instruction order is preserved.
- `Unk0cf5e8_Unk_0d0fc4` (48 B): calls `Unk122e1c_Unk_123294` with
  the handle at 0x20, stores its incoming value at 0x35c, writes 1 at
  word 4, then calls `func_020d1360(work, 3)`.
- `Unk0cf5e8_Unk_0d182c` (48 B): calls `func_020d174c` for indices
  0 and 1; returns zero immediately on failure, otherwise one.
- `Unk0cf5e8_Unk_0cf630` (56 B): when the global getter returns zero,
  calls the four providers with the original arguments (21/0 and 30);
  always calls `Unk0de678_Unk_0de870` and `Unk095560_Unk_0956c8` last.
- `func_020d1360` (60 B): state 10 calls `func_020d18a0(work)`;
  states 13 and 21 call `Unk122e1c_ClearSlots` with word 0x20;
  every path then stores the requested state in word zero. The switch
  reproduces the original comparison and branch order.

No M1-T958 hard functions remain. The TU still links from the delinked object;
its completion setting remains human-owned. No module boundary changed.

## Historical later-card omissions

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
- `Unk0cf5e8_Enter`: hand-matched
- `Unk0cf5e8_InitSlots`: hand-matched
