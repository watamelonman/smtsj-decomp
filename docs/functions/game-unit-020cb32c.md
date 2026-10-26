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
  `Unk0cb32c_Unk_0cb564`. The second parameter is unused by that callee, but the
  original wrapper explicitly sets r1 to zero, so its declaration preserves it.
- `Unk0cb32c_Unk_0cb32c` (24 B): calls `122a78`, `124338`, then `1241ec`
  with no parameters and returns 1; this order is directly evidenced by its BLs.
- `Unk0cb32c_Unk_0cb344` (24 B): calls `124214`, `124258`, then `122aa0`
  with no parameters and returns 1; this order is directly evidenced by its BLs.
- `Unk0cb32c_Unk_0cb54c` (24 B): obtains the low byte of `func_020cb3dc()`
  (original AND with 255), passes it and index zero to `Unk0cb32c_Unk_0cb4e4`.
  Its callers consume the forwarded r0 result; the C declaration now returns it.

## Hard list
- `Unk0cb32c_Unk_0ccaa8`: decompiler-derived
- `Unk0cb32c_Unk_0cba78`: decompiler-derived

## Not done in M1-T867
- `Unk0cb32c_Unk_0cb564`
- `Unk0cb32c_Unk_0cb4e4`
- `Unk0cb32c_Unk_0cb7f0`
- `Unk0cb32c_Unk_0cb58c`
- `Unk0cb32c_Unk_0cca80`
- `Unk0cb32c_Unk_0ccac8`
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
- `Unk0cb32c_Unk_0cb4e4`: decompiler-derived (plain cleanup)
- `Unk0cb32c_Unk_0ccac8`: decompiler-derived (plain+fix cleanup)
- `Unk0cb32c_Unk_0ccaf8`: decompiler-derived (plain+fix cleanup)
- `Unk0cb32c_Unk_0cb564`: decompiler-derived (plain+fix cleanup)
- `Unk0cb32c_Unk_0cb504`: hand-matched
- `Unk0cb32c_Unk_0cb58c`: hand-matched
- `Unk0cb32c_Unk_0cb7f0`: hand-matched
- `Unk0cb32c_Unk_0cca80`: hand-matched
