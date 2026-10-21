# src/game/unit_020ee904.c

The definitions keep their `symbols.txt` names. The linked symbols must stay as they are,
`symbols.txt` is protected, and the match gate looks each definition's name up in the target
object, so a definition written under a `#define`d name fails the gate. The descriptive names are
`#define` aliases in `include/game/unit_020ee904.h` for callers to use, and are the proposed
`symbols.txt` renames. They describe what the code does; there is no string or caller evidence yet.

The structs `Unk0ee904Work` (the object behind `data_02176de4`) and `Unk0ee904Obj` (the object
returned by `func_02044ec4`) only type the offsets these functions use.

| Descriptive name (alias) | Symbol | Size |
|---|---|---|
| `Unk0ee904_IsModeAvailable` | `func_020ee904` | 84 B |
| `Unk0ee904_SetupForState` | `func_020ee958` | 388 B |
| `Unk0ee904_ResetWork` | `Unk0ee904_Unk_0eeadc` | 68 B |

- `Unk0ee904_IsModeAvailable(void *self, int mode)` / `func_020ee904`: callback that returns 0
  when mode 1 is blocked (`Unk0e8228_Unk_0e8c9c` is set or `func_020e852c() < 1`) or mode 2 is
  blocked (`Unk0e8228_Thunk_02045c38` is set). Otherwise it returns 1. `self` is unused.
- `Unk0ee904_SetupForState(void *obj)` / `func_020ee958`: reads the state with
  `Unk0f8448_GetUnkField10(obj)` and does the setup calls for state 0 (two branches on
  `Unk0e8228_IsField4One`), state 1, or states 2/3 (`func_020e8d38` gets kind 6 or 7).
- `Unk0ee904_ResetWork(void)` / `Unk0ee904_Unk_0eeadc`: if `Unk0e8228_Unk_0e82ac()` is 0, it
  re-initialises the work object's 0x50 sub-object with `Unk0f8448_Init(.., 0)`. It then calls
  `Unk0e8228_Unk_0e8d18(1)` and `func_020f7e48(handle, 0, 8)`.

Match note: the 6/7 kind in `func_020ee958` has to be assigned to a local (`kind = 6; if (state == 3) kind = 7;`).
Written as a ternary, the compare is emitted before `mov r3,#6`.

## Hard list
None.
