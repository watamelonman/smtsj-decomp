# src/game/unit_021124f0.c

Symbol names stay neutral (`Unk1124f0_*`, `func_XXXXXXXX`): renaming needs
`config/arm9/symbols.txt`, which this task may not edit. All eight functions
match at 100% in objdiff.

- `Unk1124f0_Unk_1124f0` (72 B): returns 1 only when
  `Unk02f2a8_Unk_035b08(8, 10)` equals the `id` argument, the `(map, slot)`
  arguments are `(23, 10)`, and `Unk0e651c_Unk_0e666c(344)` returns 1;
  otherwise returns 0.
- `Unk1124f0_GetConst1` (8 B): constant accessor, always returns 1.
- `Unk1124f0_Unk_11259c` (16 B): returns `data_0213cb24 + index * 8` (the
  8-byte record at `index`). The original forms the sum in integer registers,
  so the source keeps the base-address cast.
- `Unk1124f0_Unk_112538` (36 B): when a game state exists, calls
  `func_0209a884(gs->unk_38E8, gs + 4)`; returns immediately when
  `GetGameState()` is null.
- `Unk1124f0_Unk_112564` (56 B): reads the work area's active record id at
  `+0x35C`, calls `Unk1124f0_Unk_1124f0(id, map, slot)`, and returns 2 when
  that gate returns 1, else 0. Uses a typed `Unk1124f0WorkArea` rather than
  raw offsets.
- `Unk1124f0_Unk_1125ac` (60 B): calls `func_02115bf4()` and
  `func_02116f84(a, b, c)`, then returns 1 only when both results are
  nonzero. Both calls are unconditional.
- `func_021125e8` (204 B): position-object gate. Looks up the object at
  work-area coordinates `(+0x364, +0x365)` with
  `Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(body, x, y), x, y)` and returns
  1 unless an event flag clears it. When resource 36's entry at `+0x35C` is
  type 2 and either its sub-type is not 1 or the object's `+4` bits 20..23
  are nonzero, flags `0x450`/`0x448` can set the result to 0; entry type 9
  with flag `0x55A` also clears it. The 4-bit field is represented as a
  bitfield (the original extracts it with `lsl #8` / `lsr #28`).
- `func_021126b4` (96 B): builds a 68-byte `Unk1124f0Req` (two mask bytes,
  then sixteen pointers), clears both parts, puts `value` in pointer slot 3,
  sets mask bit 3, and sends request 39 with `param` through
  `Unk0bc1a8_Unk_0bc928(39, param, &req)`. The two clearing loops need
  separate counters; a shared counter changes the register allocation.

Hard list: none.
