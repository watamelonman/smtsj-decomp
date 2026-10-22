# src/game/unit_020ee6dc.c

Callbacks for the work object initialised by `unit_020ee454`. Names stay neutral because the
object's purpose is not identified; the comments describe the observable behaviour.

- `Unk0ee6dc_Nop_0ee8b8` (4 B): empty callback (installed in the work function table).
- `Unk0ee6dc_Thunk_020f7248` (12 B): forwards to `func_020f7248`.
- `Unk0ee6dc_Unk_0ee6dc` (48 B): idle-gated per-frame update; updates the +0x50 sub-object and,
  when the work state is 10, calls `Unk0fedd4_SetState2`.
- `Unk0ee6dc_Unk_0ee880` (56 B): sets the UI modes, rebuilds the +0x50 sub-object from the +0x44
  handle and notifies it.
- `func_020ee844` (60 B): maps list index 0..3 to kind 1/2/6/7, default 7.
- `func_020ee8bc` (72 B): selection-change callback; ignores non-zero `flag`, and calls
  `Unk100208_Unk_100208(4)` for kinds 0, 2..6 and 8.
- `func_020ee70c` (300 B): draws the visible list, mirroring it when the x origin is negative;
  maps entry kinds 1..4 to the (show, kind) pair passed to `func_020f53d0`.

All seven functions match at 100% in objdiff.
