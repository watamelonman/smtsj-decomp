# src/game/unit_020e1648.c

The M1-T1042 and M1-T1043 functions below are verified at 100% in objdiff.

- `Unk0e1648_Unk_0e5240` (12 B): reads entry `index` of `Unk0e1648Table.unk_000c` (the
  32-bit handle table at `+0xc`); the 0e51cc/0e51f4/0e5214 helpers use it to fetch their
  handles.
- `Unk0e1648_Get_data_02176c78` (16 B): returns word 0 of the global state block
  `data_02176c78`.
- `Unk0e1648_Unk_0e2da0` (16 B): returns `&work->unk_00d2[work->unk_007c]`, i.e. the
  `Unk0e1648Slot` selected by `work->unk_007c` (callers read its `unk_0002`/`unk_0004`
  fields, which sit at `+0xd4`/`+0xd6`). The array length (441 entries) is guessed from the
  gap size and is commented in the struct.
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

## M1-T1043

All eight functions match at 100%. Evidence is the delinked ARM instructions;
neutral names are retained where subsystem meanings are unknown. This task extends
the existing source rather than creating a replacement TU. No runtime tests were
added: the card requires instruction matching and checksum validation.

- `Unk0e1648_Unk_0e2d80` (32 B): tail-forwards work `+0x68` and the
  halfword at `work + 8 * work->unk_007c + 0xd4` to `func_020f3de8`.
  Uses the existing typed slot layout; the selected index must be valid.
- `Unk0e1648_IsId177to179` (32 B): returns one for IDs 177, 178 and 179,
  zero otherwise. The descriptive name is supported by the three immediate
  comparisons at `020e2dec`, `020e2df0` and `020e2df4`.
- `Unk0e1648_Unk_0e4f34` (32 B): forwards the ID to `func_0209993c`, then
  reduces the requested signed increment to `99 - value` when their sum exceeds
  99. The incoming ID is now explicit rather than relying on an unchanged r0.
- `Unk0e1648_Unk_0e50c8` (32 B): obtains a handle from `func_020445f4(30, 3)`
  and passes it with the incoming value to `func_0204fed8`.
- `Unk0e1648_Unk_0e51f4` (32 B): fetches the indexed handle through
  `Unk0e1648_Unk_0e5240`, then calls `func_0205caa8` with that handle and
  `data_0213c674[index]`. The index must be valid in both tables.
- `Unk0e1648_Unk_0e1664` (36 B): calls the global-null guard at `020e1648`;
  returns zero if null, otherwise the word at offset `0x58` of the pointee in
  `data_02176c78[1]`. Only the observed field is modelled in the private state type.
- `Unk0e1648_Unk_0e3f5c` (36 B): loads the selected slot's halfword at
  `+0xd6`, calls `Unk09974c_GetEntryUnk08`, and tests its result against 4.
- `Unk0e1648_Unk_0e4fd0` (40 B): returns one only when its first argument is
  4 and `func_0209993c` of the second argument returns a positive signed value;
  other kinds bypass the lookup and return zero.

## Hard list

No M1-T1043 functions remain unresolved.

- `Unk0e1648_Unk_0e533c`: decompiler-derived (outside M1-T1043).

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
