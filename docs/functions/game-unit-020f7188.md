# src/game/unit_020f7188.c

## M1-T621: verified matches

All eight functions below score 100% in objdiff with the configured ARM compiler.
Names and contracts come from original ARM loads, stores and branch targets;
no gameplay meaning is inferred. The local struct describes offsets 0x00–0x1c,
not the full allocation size. Registered storage remains owned by the caller.

- `Unk0f7188_Nop_0f7884` (4 B): no parameters or effects; original is `bx lr`.
- `Unk0f7188_Nop_0f7ae0` (4 B): no parameters or effects; original is `bx lr`.
- `Unk0f7188_Nop_0f7ae4` (4 B): no parameters or effects; original is `bx lr`.
- `Unk0f7188_Call_02065cfc` (24 B): narrows its integer argument to signed
  16 bits and tail-calls `func_02065cfc(1, id)`. Target literal and shifts
  establish the wrapper name and argument conversion.
- `Unk0f7188_Unk_0f7ca8` (24 B): writes the supplied 32-bit value to offset
  0x18 of the registered object, if present.
- `Unk0f7188_Unk_0f780c` (36 B): registers non-null writable storage at
  `data_02176e08`, then clears offsets 0, 8, 0x14 and 0x18.
- `func_020f7c64` (44 B): if storage is registered, stores argument three at
  0x10, argument two as a halfword at 0x0c, and argument one at 4, in that
  order. Global reloads after stores preserve the original aliasing behavior.
- `Unk0f7188_Unk_0f7210` (56 B): requires a readable object; returns true only
  if offset 8 equals 10, offset 0x14 equals zero, and signed field 0x10 is
  at least signed field 0x1c. Does not modify the object.

## Existing implementation

`Unk0f7188_Unk_0f7cc0` remains unchanged. Its switch dispatches values
0, 1, 7, 8 and 10 to the field-0x18 setter with 1, and all others with 0.
Placing the setter before this caller yields 100% objdiff for both; placing
it after the caller caused the documented same-file call scoring artifact
(99.52%), despite matching instruction sequences.

## Hard list

None for M1-T621.

## Not done in M1-T622
- `func_020f7830`
- `func_020f7c10`
- `func_020f7bac`
- `func_020f7de4`
- `func_020f7d14`
- `func_020f7d7c`
- `func_020f7e48`

## Not done in M1-T623
- `func_020f7188`
- `func_020f7ae8`
- `func_020f7888`
- `func_020f7578`
- `func_020f7248`
