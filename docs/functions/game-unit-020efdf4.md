# game/unit_020efdf4

All five functions match the original ARM instructions and relocations. Names remain
neutral because the control flow and accessed fields do not establish a game-level purpose.
The handle arguments are opaque 32-bit values; local partial structures describe only
observed offsets, without claiming a complete shared object layout.

- `func_020efdf4` (0x020efdf4, 296 bytes): dispatches the handle's field 0x10
  after calling `func_020e8ebc(0)`. Value 0 checks the state helpers before applying
  mode 2 to work field 0x40. Value 1 invokes the setup helpers and applies values
  30 and mode 1. Value 2 fills context fields 0x1e8..0x1fc and passes the record
  at 0x1e8 to `func_020aa188`, then calls the final helpers. Other values return.
- `Unk0efdf4_Unk_0eff1c` (0x020eff1c, 28 bytes): calls
  `Unk0f8448_Init(handle, 0)` followed by `func_020f8264(handle)`.
- `Unk0efdf4_Unk_0eff38` (0x020eff38, 36 bytes): captures the global work
  pointer before querying the handle's field 0x10, then calls
  `Unk0e8228_Unk_0e8d90` with work field 0x4c as the first argument and the
  handle's field 0x10 as the second.
- `Unk0efdf4_Unk_0eff5c` (0x020eff5c, 48 bytes): calls
  `func_020f7e48(work->unk_0040, 0, 7)` followed by
  `func_020f7d7c(work->unk_0040, 34)` using the captured work pointer.
- `func_020eff8c` (0x020eff8c, 104 bytes): maps handle field 0x10 values
  0 and 2 to `func_020ea3cc(1)` and `(3)`. Value 1 queries identifier 0x707
  with `Unk0e651c_Unk_0e666c`, selecting 13 for zero or 2 otherwise.
  Other values return without calling `func_020ea3cc`.

## Hard list

None.
