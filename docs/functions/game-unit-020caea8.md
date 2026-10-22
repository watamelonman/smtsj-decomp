# src/game/unit_020caea8.c

All eight M1-T106 functions are hand-matched (100% objdiff). Linker symbols are kept as
definition names because `config/arm9/symbols.txt` is protected; descriptive names are only
claimed where the disassembly/callers support them (noted per entry).

- `Unk0caea8_Unk_0caf78`: sets the shared value at the object pointed to by `data_0215d070`
  (+0x90) to 0x400. Matched by passing a typed `u32` to `func_0202b730`; the callee's
  `str r0,[r1,#144]` shows the field. Returns nothing.
- `Unk0caea8_Unk_0caf88`: same field as above, set to 0. Matched; returns nothing.
- `Unk0caea8_Unk_0caf98`: sets that field to 0x400, forwards arg0 to
  `Unk0a0ce4_Unk_0a0d30` (which re-binds the `data_02176afc` object), then restores the
  field to 0. Matched; returns nothing.
- `Unk0caea8_Unk_0caf48`: if `*data_02176bc0` is non-null, releases it through
  `func_02053000(object)` and clears the pointer; always returns 1. The call needs the
  loaded pointer as an explicit argument, not just the incidental register value.
- `Unk0caea8_Unk_0cb044`: resolves resource entry `(10, 0)` with `func_020445f4` and looks
  up element arg0 with `func_0204fed8`; the returned pointer is discarded by the original.
  Matched; returns nothing.
- `Unk0caea8_Unk_0cb064`: the same lookup for resource entry `(10, 1)`. Matched; returns
  nothing.
- `Unk0caea8_GetInRange`: resolves resource entry `(10, 2)` and returns the element pointer
  for `i` only when `func_0204ff30(entry) <= i <= func_0204ff64(entry)`; otherwise returns
  0. The symbol's own name is kept; the callees' bodies confirm the first/last-index
  contract (`[+0x10]` and `[+0x10] + [+0xc] - 1`).
- `func_020cafbc`: returns 1 when the `(arg0, arg1)` pair occurs in the first subtable of
  `*data_02176bc0`, else 0. The record's subtable is resolved with
  `func_0204fdac(record, 0)`, its count with `func_0204fe18`, and its base with
  `func_0204fde0`; entries are 4-byte `{u16 x; u16 y;}` records. Both halves must be read
  into `u16` locals so mwcc emits the two unconditional `ldrh` loads and `cmpeq`, as in the
  ROM. A null `*data_02176bc0` returns 0 immediately.

`func_020caea8` (size 0xa0) also lives in this TU but is not part of this card and remains
undefined here.

## Hard list
- none
