# game/unit_020939f0

## M1-T617 verified functions

All eight functions below match the original ARM object at 100% objdiff.
The evidence is the corresponding function in
`build/delinks/src/game/unit_020939f0.o`; names remain neutral where the
callee's purpose is not established. Work pointers borrow writable storage.

| Function | Contract and evidence |
| --- | --- |
| `Unk0939f0_Thunk_02057678` | No arguments; forwards to `func_02057678`. Original thunk loads the callee address and branches. |
| `Unk0939f0_Set_data_02175d8c` | Stores one unsigned 32-bit value at `data_02175d8c`, as established by its sole store. |
| `Unk0939f0_Get_data_02175d8c` | Returns the unsigned 32-bit word loaded from `data_02175d8c`. |
| `Unk0939f0_Clear_data_02175d90` | Stores zero at `data_02175d90`; no arguments or return value. |
| `Unk0939f0_Unk_093da4` | Loads `data_02175d90` and forwards the word to `func_02061424`; no inferred handle lifecycle semantics. |
| `Unk0939f0_Reset` | Requires a writable work area of at least 0x70 bytes. Original stores zero at +8 (word), +0x6c (byte), +0x68 (word), then tail-calls `Unk0939f0_Unk_093f0c`. |
| `Unk0939f0_Unk_093dbc` | Borrows the work fields at +0xc, +0x60, +0x5c, +0x64, +0x2c, +0x3c, +0x4c for `func_02070440`, in that order. The original address additions establish this contract; the fields' higher-level meanings remain unknown. |
| `Unk0939f0_Unk_093b14` | Requires 19 writable entries of 0x70 bytes each. Calls `func_02093b6c` with kind 0 for entry 0, kind 1 for entries 1–16, kind 2 for entry 17 and kind 3 for entry 18. Evidence: original loop bound 16, stride 0x70 and final offsets 0x770/0x7e0. |

The source already contained matching candidates at task start. Typed work
fields, helper prototypes and per-function contracts preserve their code
shape. Object comparison verifies instructions and relocations directly;
this card does not require new runtime tests. No module boundary changed.

## Other existing C bodies

- `Unk0939f0_Unk_093ea8`: decompiler-derived, also verified at 100%.
- `Unk0939f0_Unk_093f0c`: decompiler-derived, also verified at 100%.

## Not done in M1-T618

- `func_02093d14`
- `func_02094584`
- `func_02093dfc`
- `func_0209432c`
- `func_0209461c`
- `func_02093a1c`

## Not done in M1-T619

- `func_02093b6c`
- `func_020943dc`
- `func_02093f70`

## Hard list

None for M1-T617.
