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

## Not done in M1-T869
- `func_020cc21c`
- `func_020cb3dc`
- `func_020cb78c`
- `func_020cb36c`
- `func_020ccb28`
- `func_020cb8f8`
- `func_020cb98c`
- `func_020cbc50`

## Not done in M1-T871
- `func_020cbce4`
