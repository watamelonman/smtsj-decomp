# src/game/unit_020e1648.c

These eight functions are all hand-matched (100% in objdiff).

- `Unk0e1648_Unk_0e5240` (12 B): reads the 32-bit entry `index` from the table at
  `base + 0xc`; the 0e51cc/0e51f4/0e5214 helpers use it to fetch their handles.
- `Unk0e1648_Get_data_02176c78` (16 B): returns word 0 of the global state block
  `data_02176c78`.
- `Unk0e1648_Unk_0e2da0` (16 B): returns the address of the 8-byte record selected by
  `work->unk_007c` in the table at `+0xd2` (callers read its u16 fields at `+0xd4`/`+0xd6`).
- `Unk0e1648_IsUnkeecSet` (20 B): returns non-zero when the mark byte at `+0xeec` is not
  `0xff`; `0e16f0` and `0e2f54` both write `0xff` there to clear it.
- `Unk0e1648_Unk_0e2cb0` (24 B): flips the boolean at `work->unk_0ec0` (zero becomes one,
  non-zero becomes zero).
- `Unk0e1648_Unk_0e5434` (24 B): forwards `0` to `Unk0e7ac4_Unk_0e8014` and
  `Unk0e7ac4_Unk_0e8030`, resetting those two subsystems.
- `Unk0e1648_Unk_0e1648` (28 B): returns 1 when word 1 of `data_02176c78` is null; `0e1664`
  uses it as a guard before dereferencing that word.
- `Unk0e1648_Unk_0e2c90` (32 B): lexicographic comparison of two work objects; returns the
  `unk_0006` difference, or the `unk_0004` difference when the first key matches.

## Hard list
- `Unk0e1648_Unk_0e2d80`: decompiler-derived
- `Unk0e1648_Unk_0e4f34`: decompiler-derived
- `Unk0e1648_Unk_0e50c8`: decompiler-derived
- `Unk0e1648_Unk_0e3f5c`: decompiler-derived
- `Unk0e1648_Unk_0e4fd0`: decompiler-derived

## Not done in M1-T1043
- `Unk0e1648_IsId177to179`
- `Unk0e1648_Unk_0e51f4`
- `Unk0e1648_Unk_0e1664`
- `Unk0e1648_Unk_0e533c`: decompiler-derived

## Not done in M1-T1044
- `Unk0e1648_Unk_0e51cc`
- `Unk0e1648_Unk_0e536c`
- `Unk0e1648_Unk_0e5214`
- `Unk0e1648_Unk_0e2f54`
- `func_020e5198`
- `Unk0e1648_Unk_0e5090`
- `func_020e544c`
- `Unk0e1648_Unk_0e16f0`: decompiler-derived

## Not done in M1-T1045
- `Unk0e1648_Unk_0e2db0`
- `Unk0e1648_Unk_0e4c64`
- `Unk0e1648_Unk_0e2d28`
- `func_020e2e0c`
- `func_020e2e60`
- `func_020e1698`
- `func_020e490c`
- `Unk0e1648_Unk_0e4964`: decompiler-derived

## Not done in M1-T1046
- `func_020e2cc8`
- `func_020e42e4`
- `func_020e2f84`
- `Unk0e1648_Unk_0e48a8`
- `func_020e4ca4`
- `func_020e524c`
- `func_020e41d0`

## Not done in M1-T1047
- `Unk0e1648_Unk_0e4f54`
- `func_020e30f0`
- `func_020e28a8`
- `func_020e40a4`
- `func_020e52b0`
- `func_020e4ff8`
- `func_020e2eb4`
- `func_020e4130`

## Not done in M1-T1048
- `func_020e5394`
- `func_020e4238`
- `func_020e50e8`
- `func_020e1a48`
- `func_020e32e8`
- `func_020e3e70`
- `func_020e2fe8`
- `func_020e4e28`
- `Unk0e1648_Unk_0e51f4`: decompiler-derived (proto cleanup)
- `Unk0e1648_Unk_0e51cc`: decompiler-derived (proto cleanup)
- `Unk0e1648_Unk_0e5214`: decompiler-derived (proto cleanup)
- `Unk0e1648_Unk_0e5090`: decompiler-derived (plain cleanup)
- `Unk0e1648_Unk_0e48a8`: decompiler-derived (struct cleanup)
- `Unk0e1648_IsUnkeecSet`: hand-matched
- `Unk0e1648_Unk_0e1664`: hand-matched
- `Unk0e1648_Unk_0e2d28`: hand-matched
- `Unk0e1648_Unk_0e2db0`: hand-matched
- `Unk0e1648_IsId177to179`: hand-matched
- `Unk0e1648_Unk_0e2f54`: hand-matched
- `Unk0e1648_Unk_0e4c64`: hand-matched
- `Unk0e1648_Unk_0e536c`: hand-matched
- `Unk0e1648_Unk_0e4f54`: hand-matched
