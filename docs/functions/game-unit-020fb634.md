# src/game/unit_020fb634.c

The definition keeps its `symbols.txt` name, because `symbols.txt` is protected and the match gate
looks the definition up by name in the target object. The descriptive name is a `#define` alias in
`include/game/unit_020fb634.h` and is the proposed `symbols.txt` rename. It describes what the code
does. There is no string or caller evidence for it yet.

`Unk0fb634Work` only types the offsets this function uses. The 0x24-byte `list` at +0x04 is the object
that the `Unk0d297c_*` / `CampStatus_*` list helpers work on. Its size is a guess from its last known
field (+0x20).

| Descriptive name (alias) | Symbol | Size |
|---|---|---|
| `Unk0fb634_UpdateListScreen` | `func_020fb634` | 548 B |

- `Unk0fb634_UpdateListScreen(Unk0fb634Work *w)` / `func_020fb634`: per-frame update. It ticks the
  animation at +0x4c, then switches on `w->state`:
  - 0-3: waits for `func_02052728()` to return 0, then plays the animations at +0x40 (seq 5), +0x44 (seq 6)
    and +0x48 (seq 4) one after another, each one waiting until `func_0205c704` says the previous one is done.
  - 4 (idle): when the requested id (+0x2c) differs from the current one (+0x28), copies it and goes to 5.
  - 5: resets the first shown row (+0x38), frees the old list if the current id is > 0, and falls into 6.
  - 6: rebuilds the list for the current id (`func_020d2c44`), stores the row count (+0x3c) and sets
    +0x50 when there are more than 10 rows.
  - 7: walks up to 10 rows from the first shown row through `CampStatus_Unk_0d34e4` / `func_02063a30`,
    passes the last result to `func_02061f10(handle, -1, 0, 0, last)` when it is non-zero, and sets +0x50
    when more than 10 rows remain after the first shown row.
  - 8: waits for `func_02060f40(handle)` to return non-zero, then goes to 4 and runs the idle check.

Match notes:
- Both "more than 10" flags must be written as `if (n <= 10) flag = 0; else flag = 1;`. The `> 10` forms
  (if/else, ternary or boolean) emit the `movgt` before the `movle`.
- The row counter in state 7 is set from `last` after the `func_02063920()` call (`mov r6, r5`).
  `int rows = 0;` loads its own zero and scores 98.5%.
