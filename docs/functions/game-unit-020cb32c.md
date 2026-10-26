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

## Hard list

None for M1-T867.

## Other existing bodies outside M1-T867
- `Unk0cb32c_Unk_0cb754`: decompiler-derived
- `Unk0cb32c_Unk_0cb440`: decompiler-derived
- `Unk0cb32c_Unk_0cb488`: decompiler-derived

## Not done in M1-T868
- `Unk0cb32c_Unk_0ccaf8`
- `Unk0cb32c_Unk_0cb504`
- `func_020ccc64`
- `func_020cba20`
- `func_020cbaa4`

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
- `Unk0cb32c_Unk_0ccaf8`: decompiler-derived (plain+fix cleanup)
- `Unk0cb32c_Unk_0cb504`: hand-matched
