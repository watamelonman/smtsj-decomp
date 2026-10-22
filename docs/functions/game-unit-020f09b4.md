# src/game/unit_020f09b4.c

All seven functions in the TU are hand-matched (100% in objdiff). The definitions keep
their `symbols.txt` names; the names are neutral because callers and the two function
tables at 0x020f07c0 and 0x020f08b8 do not identify the module, and no string or data
reference supports a descriptive name.

- `Unk0f09b4_Nop_0f0b94`: hand-matched. Empty callback; the body is only `bx lr`.
- `Unk0f09b4_Thunk_020f7248`: hand-matched. Forwards its arguments to `func_020f7248`;
  the original is an interworking tail call (`ldr ip,[pc]; bx ip`).
- `Unk0f09b4_Unk_0f09b4`: hand-matched. Takes the work object in `r0`. Returns when
  `Unk0f7188_Unk_0f7210()` is zero; otherwise calls `func_020f82e0(&work->unk_0050)` and,
  only when `work->unk_0008 == 10`, calls `Unk0fedd4_SetState2()`.
- `Unk0f09b4_Unk_0f0b64`: hand-matched. Calls `Unk0feba0_Unk_0febe8(1)` and
  `Unk0fd9f0_Unk_0fda58(0)`, then re-initialises the list at `&work->unk_0050` with
  `Unk0e8228_Unk_0e8374(work->unk_004c)`.
- `func_020f0b1c`: hand-matched. `switch` on the index: 0/3/4/5 for indices 0..3 and 7
  for index 4 and above. The table has an explicit `case 4` in addition to `default` so
  mwcc emits the same five-entry jump table (`cmp r0,#4`).
- `func_020f09e4`: hand-matched. Takes the work object in `r0`; the first
  `Unk0f8448_GetUnkField10` call is present in the original even though its result is
  unused. Returns early when `work->unk_0008 == 1`, otherwise calls the 0e8228/0f57xx
  setup helpers. Iterates `Unk0f8448_GetUnkField0(&work->unk_0050)` times; each iteration
  calls `Unk0e8228_Unk_0e8e6c()`, reads `Unk0f8448_GetEntry` for the index, maps the kind
  to `mode`/`line`, and calls
  `func_020f53d0(1, func_020f0b1c(i), x, y, mode, line)`. When `line` is set it also calls
  `Unk0f51dc_Unk_0f5738(x, y)`. The loop advances `y` by 15 and, when the initial base was
  negative, moves the base by +40 first and by -8 per iteration. Source-level traps:
  the 0e8e6c call belongs inside the loop, `line = 0` must be assigned after the
  `Unk0f8448_GetEntry` call (a local `kind` keeps mwcc from hoisting it), and cases
  1→2 / 4→3 use fall-through so mwcc shares the `mode` stores as in the ROM.
- `func_020f0b98`: hand-matched. `r1` (named `blocked`) returns immediately when non-zero.
  Otherwise a `switch` on `r2` calls `Unk100208_Unk_100208(4)` for modes 0, 2, 3, 4, 5, 6
  and 8; modes 1, 7 and anything above 8 return. `r0` (`unused`) is not read. The switch
  deliberately has no `default` clause: values above 8 skip `addls` and return, which is
  the original layout.

## Hard list

- none
