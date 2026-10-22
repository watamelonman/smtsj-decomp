# src/game/unit_020bbb44.c

Script-command handlers in the same family as `unit_020bb908.c` and `unit_020bbd6c.c`: they read
command arguments with `func_0203ac00(index)`, read a table selected by
`Unk0bac80_Unk_0badd0`/`Unk0bac80_Unk_0bae08`, and publish a value through
`Unk03aae8_Unk_03acf4` (the command result word). Every handler returns 1. The offsets and table
strides come from the delinked original; their gameplay meaning is not established, so the
`func_XXXXXXXX` symbols are kept (the match gate looks definitions up by these names).

- `func_020bbb44` (72 B): reads the table pointer from `Unk0bac80_Unk_0bae08` (state +0x68) and
  publishes the `u16` at +0xC of record `index` in 10-byte records. The index is read from command
  argument 0 and clamped to 0 when >= 3. A null table publishes 0. Returns 1.
- `func_020bbb8c` (72 B): identical to `func_020bbb44` but publishes the `u16` at +0xE of the
  record. Returns 1.
- `func_020bbbd4` (72 B): selects table 0 with `Unk0bac80_Unk_0badd0(0)`, reads its element count
  with `func_0204fe18` and its base with `func_0204fde0`, and publishes the `u16` at command
  argument 0. The index is replaced by 0 when it is not below the element count (unsigned
  compare). Returns 1.
- `func_020bbc1c` (96 B): calls `Unk0e5fb8_Unk_0e61c8(index, value & 0xFF)` with command arguments
  0 and 1 when index < 15, and publishes 1 on a non-zero result, else 0. Out-of-range indices
  publish 0 without the lookup. Returns 1.
- `func_020bbc7c` (56 B): calls `Unk0e5fb8_Unk_0e620c(index, value & 0xFF)` with command arguments
  0 and 1 when index < 15. Unlike `func_020bbc1c` it publishes nothing and does nothing for
  out-of-range indices. Returns 1.
- `func_020bbcb4` (108 B): selects table 1 with `Unk0bac80_Unk_0badd0(1)` and calls
  `func_0204fe18` (its result is discarded here), then reads the base with `func_0204fde0`.
  Rows are 20 bytes and entries are `u16` columns; command argument 0 is the row and argument 1
  the column, with column >= 10 replaced by column 0. Row >= 15 publishes 0. Returns 1.
- `func_020bbd20` (76 B): selects table 2 with `Unk0bac80_Unk_0badd0(2)`, reads its element count
  with `func_0204fe18` and base with `func_0204fde0`, and publishes the `u16` at
  `func_0203ac00(0) - 1`. That index is replaced by 0 when it is not below the count (unsigned
  compare, so the decremented value also wraps to 0 for argument 0). Returns 1.

## Hard list

- none
