# game/unit_020f868c

Both ARM functions match at 100% objdiff. Names are retained because the
callee meanings and sequence purpose are not established by this unit.
The local struct views describe only accessed fields, not full object sizes.

## `Unk0f868c_Unk_0f868c` (0x020f868c, 36 bytes)

Takes a non-null work pointer. Calls `Unk118b04_Unk_118e50(11, 1)`
then passes the embedded buffer at 0x124 and word at 0x120 to
`func_02052d7c`. Evidence: the two call sites and their argument loads.

## `func_020f86b0` (0x020f86b0, 744 bytes)

Takes a non-null work pointer with a valid nested object when adjusting its
fields. Increments the signed tick counter at 0x7484 on every call and
dispatches on the signed byte at 0x7481:

- State 0 calls `func_02052da0`; after ten ticks it submits work-area fields
  and signed bytes 0x7482/0x7483 to `func_02034b7c`, calls the helper with
  argument 47, resets ticks and advances state.
- State 1 subtracts rounded `4096 * (0.15 * ticks)` from object field 0x80
  and adds rounded `4096 * ticks` to field 0x8c. It resets ticks and advances
  when `func_02052728` returns zero.
- State 2 waits for that helper to return one, submits buffer 0x1a0 and
  word 0x19c to `func_02052d7c`, resets ticks and advances.
- State 3 adds rounded `4096 * (0.5 * (15 - ticks))` to field 0x8c while
  ticks are below fifteen, calls `func_02052da0`, and returns one only
  when work word 0x7440 is one. Other states return zero.

Rounding uses a sign test, addition/subtraction of 0.5, and truncation to
signed integer; ties go away from zero. Float operations preserve the
original order. Evidence: switch branches, field accesses, soft-float
runtime calls, and literal-pool values 0x3e19999a and 0x45800000.

## Hard list

None.
