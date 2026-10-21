# unit_020b7898

TU `src/game/unit_020b7898.c`, `.text` 0x020b7898-0x020b78d8. Neither function has a direct
caller. Their addresses are entries 0 and 1 of a function-pointer table at 0x0213d6f8 (entry 2 is
0x020b78d8 in the next TU). Names stay neutral (see docs/naming.md) because the table's owner and
the callees are not identified yet. `include/game/unit_020b7898.h` adds descriptive aliases
(macros) that name each function by its observed call sequence; the definitions keep the
symbols.txt names because the match gate looks them up by name.

## Functions

### `Unk0b7898_Call_02052634` (0x020b7898, 24 bytes): 100%
Alias: `Unk0b7898_TableHook0_Call02052634With1_0_31`.
`void (void)`. Calls `func_02052634(1, 0, 31)`. 31 is the largest 5-bit value, but
`func_02052634` is not decompiled, so what the arguments mean is unconfirmed.

### `Unk0b7898_Unk_0b78b0` (0x020b78b0, 40 bytes): 100%
Alias: `Unk0b7898_TableHook1_Call111474Then02111494ThenSet02cbdc`.
`void (void)`. Calls `Unk111400_Unk_111474(4, 0xC03, 0)` and `func_02111494()`, then
`Unk02cad4_Unk_02cbdc(1)`, which stores 1 in `data_0213d338.unk_08`.

## Hard list
None.
