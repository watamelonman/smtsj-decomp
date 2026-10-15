# Known global / shared structs

Layouts are taken only from matched C. Names are hedged (`unk_*`) until a use site
makes the meaning clear. Confidence: **certain** = offset+type observed in matching
code; **medium** = role guessed from callers/strings; **none** = placeholder.

## `GameState` — `include/GameState.h`

| Symbol | Addr | Notes |
|---|---|---|
| `gGameState` | BSS `0x0215dd2c` | Pointer to the live `GameState`. Returned by `GetGameState` (~60 callers). |
| `GameState` | (heap/static) | Pointed-to object; size at least `0x759C`. |
| `GameStateRoot` | `GameState.root` | Sub-object at `*gGameState`; fields at +4, +0xC, +0x14, +0x18, +0x5C. |

Important field groups (all **certain** on offset/type, **none–medium** on meaning):

| Offset | Field | Role (guess) | Conf |
|---|---|---|---|
| +0x0000 | `root` | pointer to `GameStateRoot` | certain |
| +0x38E8 | `unk_38e8` | sub-object base passed to `func_0209a884` | certain |
| +0x73CC | `unk_73cc` | mode / transition word | medium |
| +0x73D0 | `unk_73d0` | companion of `unk_73cc` | medium |
| +0x73D8 / +0x73E4 | `unk_73d8` / `unk_73e4` | flags around mode changes | medium |
| +0x73E8 | `unk_73e8` | mode id written by many screen changers | medium |
| +0x73F4..F8 | `unk_73f4`..`unk_73f8` | three `u16` args for a mode | medium |
| +0x7400 | `unk_7400` | cleared on one transition | none |
| +0x7430..38 | `unk_7430`..`unk_7438` | triple passed into `func_02052d7c` | medium |
| +0x7480 | `unk_7480` | `u8` argument stashed by a mode changer | none |
| +0x74F4 | `unk_74f4` | read by `GameState_GetUnkField74f4` | none |
| +0x7550 | `unk_7550` | sub-object for `Unk09974c_*` | certain (base) |
| +0x7598 | `unk_7598` | sub-object for `Unk11f2d0_*` | certain (base) |

Consumers rewritten to use the struct (no raw casts):  
`unit_0202f2a8.c`, `unit_0209e72c.c`, `unit_0209e96c.c`, `unit_0209ee4c.c`,
`unit_0209e418.c`, `unit_0209d42c.c`, `unit_021124f0.c`.

## Other frequent globals — `include/Globals.h`

Scalar BSS words still named `data_<addr>` in `symbols.txt` (rename later when meaning
is known). Declared in `Globals.h` for shared use:

`data_0215dd24` (next to `gGameState`), `data_0215ee98`, `data_02176e24`,
`data_02176e7c`, `data_02176274`, and other `data_02176*` flags.  
`data_02140ac8[]` is a data-section table whose address is returned by
`Unk02e000_GetAddr_data_02140ac8`.

## Per-file `*Work` structs

Many TUs still carry a local `<Module>Work` built from that file's field accesses
(`unk_XXXX` / older `UnkFieldXXXX`). Shared offsets like +4/+8/+0xC across files are
**not** merged into one shared header: they are almost certainly different object
types that happen to have a field there. Merge only when call-graph / type evidence
shows they are the same.

Still using raw `*(T*)(arg0+off)` / `FIELD` in ~120 files (~700 sites). Safe to
convert file-by-file once each TU's Work struct is complete and call sites agree on
the pointer type.
