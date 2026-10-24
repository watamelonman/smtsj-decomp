# game/unit_02109dcc

All four functions match the delinked ARM instructions at 100% (616 bytes).
Names remain neutral because the instruction evidence does not establish the
subsystem or original API names. No module boundary changes are needed.

- `Unk109dcc_Unk_109dcc` (44 bytes): passes the resource at work offset
  `0x10` to `func_0205c704`, then calls `func_02061424` on the work object
  when the unsigned value pointed to by offset `4` is zero.
- `func_02109df8` (376 bytes): brackets submissions with calls to
  `func_020580ec` and the `02057524`/`02057534` pair. Submits record 20,
  then record 21. If the maximum is nonzero and the current value is smaller,
  copies a 24-byte record and scales its signed halfword at offset 12 using
  unsigned division; clamps the narrowed result to at least one and then to
  the original extent. Otherwise submits the full record. Finishes by
  submitting the resource at work offset `0x10`.
- `Unk109dcc_Unk_109f70` (36 bytes): if the offset `0x10` resource is non-null,
  passes it to `func_0205c3dc` and clears the slot. A null slot is a no-op.
- `func_02109f94` (160 bytes): calls `func_020611dc` with the other three
  functions as callbacks and constants 20, 4, 101, 1. Stores the four supplied
  pointers in the returned 20-byte work object, obtains the offset `0x10`
  resource from `func_0205c3c0`, and initializes it through three calls.

The work object borrows the current/maximum pointers; both must remain valid
through callback execution. The record layout and float-valued submission
arguments reproduce the observed halfword accesses and `0x3f800000` constants.

## Hard list

None.
