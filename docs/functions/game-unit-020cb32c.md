# src/game/unit_020cb32c.c

M1-T866: all eight functions below match the delinked ARM instructions at 100%.
Neutral names are retained because instruction evidence establishes operations,
but does not establish the surrounding subsystem's purpose.

- `Unk0cb32c_Nop_0cba74` (4 B): no parameters, no effects; original is `bx lr`.
- `Unk0cb32c_Nop_0cccc0` (4 B): no parameters, no effects; original is `bx lr`.
- `func_020cccb4` (12 B): takes a borrowed, non-null work pointer covering
  offset `0x124`; reads that word and returns on either outcome. An early return
  conditional reproduces the original `ldr r0, [r0, #0x124]; cmp r0, #0; bx lr`.
  An empty conditional was optimized away; the early return preserves the comparison.
- `Unk0cb32c_Unk_0cb35c` (16 B): forwards its 32-bit argument and constant 30
  to `func_0205e484`, using the original literal-load indirect tail call.
- `Unk0cb32c_Unk_0cb57c` (16 B): forwards its 32-bit argument and zero to
  original wrapper explicitly sets r1 to zero, so its declaration preserves it.
- `Unk0cb32c_Unk_0cb32c` (24 B): calls `122a78`, `124338`, then `1241ec`
  with no parameters and returns 1; this order is directly evidenced by its BLs.
- `Unk0cb32c_Unk_0cb344` (24 B): calls `124214`, `124258`, then `122aa0`
  with no parameters and returns 1; this order is directly evidenced by its BLs.
- `Unk0cb32c_Unk_0cb54c` (24 B): obtains the low byte of `func_020cb3dc()`
  Its callers consume the forwarded r0 result; the C declaration now returns it.

## M1-T867

All eight functions match at 100%. Work pointers are borrowed and word-aligned;
the caller retains ownership. Names remain neutral because the instructions
establish operations without establishing subsystem meaning.

- `Unk0cb32c_Unk_0cb564` (24 B): preserves its 32-bit first argument across
  `func_0205c41c()`, forwards it to `func_0205c6ec`, and returns the resulting
  r0. The second register argument is unused; the existing wrapper supplies zero.
- `Unk0cb32c_Unk_0cb4e4` (32 B): resolves `(30, arg0)` through
  `func_020445f4`, then calls `func_0204fed8` with that result and arg1.
  The original preserves arg1 in r4 and forwards the final r0 result.
- `Unk0cb32c_Unk_0cb7f0` (32 B): returns 1 when provider entry `0x752`
  returns zero, otherwise 0. Evidence: literal, BL, CMP and conditional MOVs.
- `Unk0cb32c_Unk_0ccaa8` (32 B): for state 2 calls `0cca80` with the same
  work pointer, then writes the new signed state to its first word. The explicit
  pointer argument preserves the original r0 at the conditional BL. Work must
  cover `+0x94` on that path and at least its first word otherwise.
- `Unk0cb32c_Unk_0cb58c` (40 B): compares signed results of `05caa0(x)`
  and `05ca88(x)`, in that order, returning 1 for greater than or equal.
  Signedness follows the original MOVGE/MOVLT conditions.
- `Unk0cb32c_Unk_0cca80` (40 B): reads the work word at `+0x94`, calls
  provider `0e666c(0x5f1)`, and forwards the word, zero and provider result
  to `122f88`. The provider call precedes the work load in the original.
- `Unk0cb32c_Unk_0cba78` (44 B): when the `1508d4` getter returns zero,
  calls `0bc9b4(15, 0)` then `0cb344`; always calls `0de870` then `0956c8`.
  Evidence: original conditional branch and BL order.
- `Unk0cb32c_Unk_0ccac8` (48 B): calls `0a0da4(5)`, writes 4 at work
  `+8`, enters state 13 through `0ccaa8`, then stores arg1 at `+0x0c`.
  Work must cover four words; original STR/BL order is preserved.

Validation: objdiff verifies the original instruction sequences, register
allocation, literals and relocations for all eight; no new behavioral tests
are required by this matching card.

## M1-T868

All eight requested functions match at 100% objdiff. Work/handle pointers are
borrowed and word-aligned; callers retain ownership. Names remain neutral because
instruction evidence does not establish a subsystem purpose.

- `Unk0cb32c_Unk_0ccaf8` (48 B): takes writable work through `+0xd8` and
  a 32-bit value. Calls `123294` with the `+0x94` handle, stores the value at
  `+0xd8`, sets `+8` to 1, then enters state 3 through `0ccaa8`. Evidence:
  original LDR, ordered STRs and BLs at `020ccaf8..020ccb24`.
- `Unk0cb32c_Unk_0cb754` (56 B): takes a writable handle slot; calls
  `0bc9b4(10,0)`, releases the handle through `2122e1c`, clears the slot,
  then calls `0e5530`, `0fd3ac`, `0cb344`, `0de870` in order. Evidence:
  original LDR/STR and BL sequence at `020cb754..020cb788`.
- `Unk0cb32c_Unk_0cb440` (72 B): maps unsigned selectors 0,1,2,3,4 to
  6,8,7,9,5 respectively and returns other inputs unchanged. Evidence:
  unsigned jump-table bound and five immediate-return blocks.
- `Unk0cb32c_Unk_0cb504` (72 B): takes a handle and two 32-bit selectors;
  calls `063920(handle)`, resolves the selectors through `0cb4e4`, converts
  that result through `063a30`, then forwards it as the fifth argument of
  `061f10(handle,-1,0,0,value)`. Evidence: BLs and stack store at `020cb504`.
- `func_020ccc64` (80 B): reads the low halfword of the work word at
  `+0xa8`. Selector 0 tests provider entry `0x5f1` and chooses 0 when
  nonzero or 3 otherwise; selector 1 chooses 1; all others choose 2.
  Calls `124224` with that result. Evidence: shifts, branches, literal and BLs.
- `func_020cba20` (84 B): forwards `0cb3dc()` to `095a2c`, then tests
  `0de8b0(0)`. If zero, calls `0cb32c`, `0bc928(15,65535,0)`,
  `0bc928(16,15,0)` and `0bc9f4(16,0)` in order. Evidence: conditional
  return and BL/literal sequence at `020cba20..020cba70`.
- `Unk0cb32c_Unk_0cb488` (92 B): borrows a handle word and takes signed
  x/y coordinates plus three 32-bit values. Builds a 16-byte stack descriptor
  with `060dd4(buffer,handle,0,index,arg4)`, then submits it through
  `059f70(*handle,0,x,y,buffer,0,arg5)`. Evidence: stack allocation,
  outgoing argument stores and two BLs at `020cb488..020cb4e0`.
- `func_020cbaa4` (92 B): writes descriptor size `0x130`, flags zero and
  six callback addresses at `+0x0c..+0x20`, preserving `+8`. Callback order:
  `0cbce4`, `0cc5d8`, `0cccb4`, `0cccc0`, `0cbc50`, `0cccc4`.
  Evidence: original STR offsets and six relocated literals. Callback types
  are opaque storage types here; this initializer never invokes them.

Validation: objdiff checks instructions, register allocation, literals and
relocations for all eight and preserves earlier matches. Behavioral tests are
not required by this matching card; the original instructions are the oracle.

## Hard list

None for M1-T866, M1-T867 or M1-T868.

## M1-T869

Seven functions match at 100% objdiff. Names remain neutral: instruction
and call evidence establishes the operations, not the subsystem's purpose.
Borrowed layout views and provider contracts live in
`include/game/unit_020cb32c.h`; providers retain ownership.

- `func_020cc21c` (96 B): takes borrowed work and a 32-bit selector;
  calls `0cb5b4(selector,&work->field_004)`. Result 1 calls `0ccb28`,
  result 2 calls `0ccba0` then `0cca80`, result 3 restores the state from
  `+8` through `0ccaa8`. Other results do nothing. Evidence: CMP/BL
  sequence at `020cc21c..020cc278`.
- `func_020cb3dc` (100 B): takes no parameters; maps unsigned provider
  selector 8/7/9/5 to 1/2/3/4, defaulting to 1. Evidence: jump table at
  `020cb3f0`, provider BL at `020cb3e0` and immediate return blocks.
- `func_020cb36c` (112 B): takes no parameters; builds a borrowed 68-byte
  stack descriptor with two zero flag bytes and sixteen zero words.
  Stores `0cb54c()` at `+0x20`, sets low flag `0x80`, and submits it to
  `0bc928(36,65535,descriptor)`. The provider must consume the descriptor
  synchronously. Evidence: original loops, stack allocation and STR/BLs.
- `func_020ccb28` (120 B): takes borrowed writable work; calls
  `0bc9b4(16,0)` then `044534(37)`. Re-reads the list count at `+0x20`
  each iteration, releases nonzero handles from `+0x10`, clears their
  slots, calls `0cb754` on `+0x94`, then clears `+0x124`. Evidence:
  original indexed LDR/STRs and ordered BLs at `020ccb28..020ccb9c`.
- `func_020cb8f8` (148 B): takes signed x/y and a 32-bit value. Returns
  if global work is null; otherwise brackets the first drawing call with
  `057ddc(255)` and `057df8()`. Both calls use mode 1, nested display
  field `+0xe0`, x, zero and value; first y is y+1, second y is unchanged.
  Evidence: global literal, pointer loads and BLs at `020cb8f8`.
- `func_020cb98c` (148 B): identical paired call contract to `0cb8f8`,
  using nested display field `+0xe4`. Evidence: LDR offsets at `020cb98c`.
- `func_020cbc50` (148 B): takes borrowed writable work; calls
  `044534(37)`, `0bc9b4(10,0)`, releases and clears nonzero list handles
  while re-reading the count, calls `0fd3ac` then `0e5530`, releases and
  clears the display at `+0x94`, calls `0dea60`, and clears global work.
  Evidence: ordered BLs and STRs at `020cbc50..020cbce0`.

### M1-T869 hard list

- `func_020cb78c` (100 B): left undefined in C, retaining the delinked
  original. Attempted typed C initializes providers and a borrowed handle
  slot, then calls `0bc928(10,65535,0)`, `124c5c()`, `124ce8(1)`.
  Achieved 91.72% objdiff: compiler emits `mov r0,#10` before the literal
  load into r1, whereas the original loads r1 first. Local word/halfword
  constants, equivalent constant expressions, explicit argument locals,
  and provider return declarations did not resolve scheduling. No
  nonmatching body is retained. A human can use `tools/decompme.py` for
  further compiler/scheduling investigation.

Validation: original instructions are the acceptance oracle; this card does
not require behavioral tests. Objdiff covers all seven new definitions and
all earlier definitions in this TU; checksum covers the linked original image.

## M1-T870

Seven of the eight requested functions match at 100% objdiff. Names remain
neutral: instruction and call evidence establishes the operations, not the
surrounding subsystem's purpose. Work pointers are borrowed; providers keep
ownership and the allocation stays live for the callback's duration.

- `func_020cb810` (232 B): selects nested display +0x94 or +0x98 from the word
  at display +0x64, then draws the paired passes. Evidence: the branch and
  paired `func_02060b60` BLs at 020cb810.
- `func_020cc27c` (324 B): advances the byte substate at work +4 through five
  provider-gated stages. Evidence: the five-way switch and guarded BLs at
  020cc27c.
- `func_020cbb00` (336 B): initializes the borrowed 0x130-byte work, builds the
  stride-26 list handles and display, and publishes the global work cell.
  Evidence: ordered stores and provider BLs at 020cbb00.
- `func_020cccc4` (372 B): interprets event kinds 1/3/4 and either hides list
  handles or selects a stride-26 entry. The local index is a one-element array
  with an initializer because that reproduces the original
  `add r1,sp; mov r0,#0; str r0,[r1]` zero store ordered before the state load
  (see DEC-021). Evidence: the event jump table and guarded field tests at
  020cccc4.
- `func_020cb5b4` (416 B): drives six byte substates and returns completion
  codes 1/2/3. Evidence: the switch, descriptor loops and guarded byte
  writeback at 020cb5b4.
- `func_020cc3c0` (536 B): advances five substates and constructs the slot-16
  parameters in work +0xdc. Descriptor accesses use a typed work view so mwcc
  emits the original `work + i` / `work + i*4` scaled indexing instead of a
  cached descriptor pointer (DEC-021). Evidence: descriptor flag stores and
  guarded BLs at 020cc3c0.
- `func_020cc5d8` (1192 B): handles provider selection and input only in state
  4 and prepares the state-6 parameters. The selection branch is an `if/else`
  with no trailing return, so the empty case returns through the shared
  epilogue as in the original. Evidence: the jump table, ordered input masks
  and BLs at 020cc5d8.

### M1-T870 hard list

- `func_020ccba0` (196 B): left undefined in C, retaining the delinked
  original. A typed C version reproduces the target instruction sequence,
  including the stride-26 halfword loads and ordered provider calls, but
  mwccarm 2.0/sp1p5 assigns `work` to r4 and `count` to r6 where the original
  uses `work` r7 and `count` r4; the other loop values are correspondingly
  permuted (i r7 vs r5, record r8 vs r6, count-1 r5 vs r8). Tried: local work
  aliases, explicit record and count-1 pointers, declaration reordering,
  one-element array locals, `register` qualifiers, const/restrict parameters,
  inlined loop/setup helpers, and per-function `opt_*` pragmas. Only
  `opt_strength_reduction off` moved work to r7, but it also removed the
  record induction pointer (emitting `mla` with stride registers) and changed
  the rest of the function. No non-matching body is retained. A human can use
  `tools/decompme.py` for further register-allocation investigation.

Validation: the original instructions are the acceptance oracle; objdiff
covers all seven new definitions and every earlier definition in this TU, and
the checksum covers the linked original image.

## M1-T871

- `func_020cbce4` (1336 B): matches at 100% objdiff. Takes a borrowed,
  word-aligned writable work allocation covering 0x130 bytes. Dispatches states
  0..14, waits for the corresponding providers, restores saved states, changes
  list-handle visibility, and updates the live display selectors at +0xa8/+0xc4.
  State 4 and out-of-range states perform only the final guarded display update.
  Evidence: original jump table at 020cbd00, ordered provider calls, field loads
  and stores, and the display guard at 020cc1f8. The neutral symbol is retained
  because these instructions do not establish the subsystem's meaning.
  States 3 and 11 pass a 114-byte halfword-aligned list by value to 020deaa0,
  followed by the selected index. The state-3 index argument also resets work
  +0xd4; keeping the assignment in the argument reproduces instruction scheduling
  (See DEC-022). The descriptor stores the callback through the same opaque
  function-pointer representation as its other typed callbacks.

Validation: match gate reports all 214 checked C functions at 100%, including
this callback and the earlier definitions. The original instructions are the
acceptance oracle; this card requires no new behavioral tests.

### M1-T871 hard list

None.
