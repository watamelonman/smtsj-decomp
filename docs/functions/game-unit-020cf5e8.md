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

## M1-T959: verified matches

All eight requested functions report 100% in `build/report.json`. Pointer
parameters borrow valid work storage; provider ownership is unchanged.

- `Unk0cf5e8_Unk_0d1414` (64 B): resolves halfwords 0xa8 and 0xa6
  indexed by word 0x288 with stride eight, submits the resolved pointer plus
  0x16, then increments word 0x288. Evidence: ARM loads/calls at 0x020d1414.
- `Unk0cf5e8_Enter` (68 B): calls the two entry providers, queries with zero,
  and when zero performs the setup calls with 30 and (21, 65535, 0).
  Evidence: ordered calls at 0x020cf5e8 support the existing entry name.
- `func_020d185c` (68 B): publishes halfword 0x2e != 0 for handle 0x20,
  slot 3; calls `func_020d18a0` if word 0x298 equals 1, then always calls
  `func_020d1958`. Evidence: loads and branches at 0x020d185c.
- `func_020d19d4` (68 B): truncates word 0x2b0 to an unsigned halfword;
  forwards 50 when that value is 2 and query 0x73a returns zero, otherwise
  forwards the halfword. Evidence: shifts, query and branches at 0x020d19d4.
- `Unk0cf5e8_Unk_0d13b4` (72 B): resolves halfwords 0x19c and 0x19a
  indexed by word 0x28c with stride eight, submits the resolved pointer plus
  0x16, then increments word 0x28c. Evidence: ARM loads/calls at 0x020d13b4.
- `Unk0cf5e8_InitSlots` (80 B): obtains six indexed values, then publishes
  all six through handle 0x20; the observed six-slot loops at 0x020d1908
  support the existing name. Slot storage starts at 0x36c.
- `Unk0cf5e8_Unk_0d0960` (84 B): queries with the incoming value and work+8;
  results 1 and 2 call their respective callbacks, 3 restores the state
  from word 4, and other values return. Evidence: comparisons at 0x020d0960.
- `func_020d16f8` (84 B): checks signed indices in [first, end); entries
  accepted by the first provider must pass the second provider with kind 3.
  Returns zero on failure, one otherwise, including an empty range.
  Evidence: signed comparisons and conditional calls at 0x020d16f8.

No M1-T959 hard functions remain. No module boundary changed. The unit
continues to link from the delink pending human completion approval.

## M1-T960: verified matches

All eight functions match the original ARM instructions, including symbol
relocations. Existing symbol names are retained because provider and field
semantics remain unknown. All work/descriptor pointers borrow valid storage;
no provider ownership contract changes.

- `func_020cf668` (92 B): initializes descriptor size 900, flags zero and six
  callback addresses at 0x0c..0x20, preserving word 8. Evidence: original
  stores and function-symbol literal pool at 0x020cf668. Callback signatures
  other than the known work-taking cleanup remain unknown.
- `func_020d18a0` (104 B): queries six indices, publishes whether each query
  returned zero, then publishes the six saved slots at 0x36c. Evidence:
  original loop bounds, loads and ordered calls at 0x020d18a0.
- `func_020d1958` (124 B): queries indices 0/1, publishes individual failures
  only in mode 2 (word 0x298), and always publishes/returns their union.
  Evidence: original comparisons and calls at 0x020d1958. Its return type was
  corrected to int, matching the final move into r0.
- `func_020cf8e8` (184 B): releases nonzero indexed handles, clears their
  words, tears down providers in order, performs four calls and clears
  global word `data_02176bd8`. Evidence: original calls/stores at 0x020cf8e8.
- `func_020d0ff4` (184 B): clears word 0x364, releases indexed handles,
  clears handle 0x20 and performs the distinct ordered exit-provider sequence.
  Evidence: original loads, stores and calls at 0x020d0ff4.
- `func_020d03c0` (216 B): switches on byte 8 through stages 0..4, polling
  providers before advancing, then resets the byte and enters state 17.
  Evidence: jump table and original calls/stores at 0x020d03c0.
- `func_020d174c` (224 B): checks five half-open ranges for index 0 and two
  for index 1, stopping on failure; other indices succeed. Evidence: original
  immediate bounds and branches at 0x020d174c.
- `func_020d02c0` (256 B): switches on byte 8 through stages 0..4, including
  one unconditional advance and two provider polls, then resets it and enters
  state 4. Evidence: jump table and original calls/stores at 0x020d02c0.

The four-word handle view spans 0x10..0x1c, bounded by the observed handle at
0x20; the original leading-record count controls iteration. The six-slot view
is established by the loop bound. No module boundary changed. No M1-T960 hard
functions remain. The TU still links from its delink pending human completion.

## M1-T961: verified matches

Seven of the eight requested functions match the original ARM instructions and
relocations. The work view was extended with typed sub-objects rather than raw
offsets: 26-byte leading records at 0x2e (kind halfword + 24-byte payload,
bounded by the four handles), four 28-byte provider blocks at 0x2a0, the
496-byte provider block at 0x98 (which contains the 0xa0/0x194 predicate
words), and the 0x318 block (two flag bytes followed by sixteen words).
All pointers are borrowed; no provider ownership changed.

- `func_020cf6c4` (548 B): publishes the work pointer to `data_02176bd8`,
  resets four ids, initializes the 0x98 provider block, builds the handle table
  from the leading records (kind 604 shifts both bounds), clears the 0x318
  block, publishes four provider blocks and seeds state `func_020d1360(work, 0)`,
  word 4 = 2 and the 0x35c..0x368 words. Evidence: ordered calls/stores at
  0x020cf6c4. Loop bound is re-read from word 0x310, which the original also
  does (signed compare).
- `func_020d0198` (296 B): six-stage intro: stage 0 sets direction, a provider
  and two slot flags, stage 1 waits on two providers before `func_02124ce8(3)`,
  stage 2 just advances, stages 3 and 4 share their tail (fallthrough in the
  original) and stage 5 resets the byte and enters state 10. Evidence: six-entry
  jump table and ordered calls at 0x020d0198.
- `func_020d0498` (360 B): five stages keyed on the saved word 0x29c; stage 3
  chooses state 13 (success provider path) or 4 (failure path) and shares one
  store and the `func_02124ce8(1)`/`Unk124c5c_Unk_124cc4` tail. Evidence: table,
  conditional branches and shared store at 0x020d0498.
- `func_020d0600` (388 B): five-stage teardown/start; stage 2 zeroes the 0x318
  block and selects message 5 or 6 from query 0x73a before publishing the block,
  stage 3 runs `func_020d10ac`. Evidence: literal 0x73a and ordered calls at
  0x020d0600.
- `func_020d0784` (476 B): five-stage tail; clears and publishes the 0x318
  block with message 5, then writes word 6 of the block from the third provider
  block and flag 8 before publishing with (22,21), entering state 11. Evidence:
  table, flag-5/flag-8 stores and ordered BLs at 0x020d0784.
- `func_020d10ac` (292 B): scene bring-up: resets four ids, installs providers,
  builds the handle table from the leading records, then publishes the handle
  range and enters the scene sequence (`func_02124c5c`, `func_02124ce8(1)`,
  `func_020d19d4`). Evidence: ordered calls/stores at 0x020d10ac.
- `func_020d14cc` (556 B): per-index flag scan over the provider byte block
  returned by `Unk0f3db4_Unk_0f3db4`; six switch cases use bounds
  50/50/50/50/100/60 and byte offsets 0/0/100/150/200/300. A record whose
  halfword kind 2 query returns zero must also pass the byte predicate.
  Evidence: six-entry table, loop bounds and `ldrb` offsets at 0x020d14cc.

## M1-T961 hard list

- `func_020d11f0` (368 B): the event callback was reproduced instruction for
  instruction except for three allocator effects: the original keeps the
  command selection in a 4-byte stack slot (frame `sub sp,#4`, five saved
  registers), uses a second callee-saved register for the handle-activation
  loop's argument copy, and advances the command pointer with a write-back
  `ldr r2,[r1],#4` (ours folds `+4` into the payload offsets). A scalar,
  `volatile`, one-field struct and one-element-array form of the selection all
  either avoid the frame or reload it after the 0x788 store; loop forms
  (`j = i`, `for (i, j)`, cached bound) are coalesced into one register by
  mwcc unless both counters are incremented, which adds instructions the
  original does not have. Every other instruction matches (checked with
  `tools/hand/cmp.py -v`). Needs a human decomp.me/permuter pass; the body is
  left as the delink assembly rather than faked.

The TU still links from its delink pending human completion. No module boundary
changed.
