# src/game/unit_020ea208.c


## M1-T769 — verified matches

All eight functions are 100% in the local objdiff report. Evidence below is
from the original delinked ARM instructions and their relocation targets.
Neutral names are retained because the higher-level purposes are unproven.
These functions neither allocate nor transfer ownership.

| Function | Size | Behavior and evidence |
| --- | --- | --- |
| `Unk0ea208_Unk_0ead3c` | 16 B | Calls `Unk0e8228_Unk_0e8f38`, then forwards its r0 result to `Unk0caea8_Unk_0cb044`. |
| `Unk0ea208_Get_data_02176ddc` | 16 B | Loads the word at the `data_02176ddc` relocation and returns that borrowed singleton address, possibly zero. The existing symbol name identifies the storage. |
| `Unk0ea208_Unk_0eaca0` | 20 B | Passes -1 to `func_02057eb8`, then calls `func_020572d8`. |
| `Unk0ea208_Unk_0ea72c` | 24 B | Calls the singleton getter; returns zero if absent, otherwise loads its word at +0x1d4. |
| `Unk0ea208_Unk_0ead4c` | 24 B | Passes 8 to `Unk0e8228_Unk_0e8374`; forwards r0 through `Unk0e8228_GetArr88Field20` to `Unk09974c_Unk_099bac`. The table helper indexes +0x88 and reads a halfword at +0x20. |
| `Unk0ea208_Unk_0eb6cc` | 24 B | Requires a valid work pointer, compares its word at +0x1c4 with 8, and calls `Unk0ea208_Unk_0eb264` with that same pointer only on equality. |
| `Unk0ea208_Unk_0ea85c` | 28 B | Calls `func_020445f4(39, 3)` and forwards the result to `func_0204fed8` with selector 1; returns the latter result. |
| `Unk0ea208_Unk_0eac24` | 28 B | Calls `func_020445f4(39, 4)` and forwards the result to `func_0204fed8` with selector 1; returns the latter result. |

No M1-T769 functions remain on the hard list. The pre-existing candidates
already matched; typed call declarations now express the r0 forwarding rather
than relying on unspecified argument lists. Typing the shared 0cb044 declaration
also requires the existing 0ead1c caller to pass its saved result explicitly.

## Hard list
- `Unk0ea208_Unk_0eb308`: decompiler-derived
- `Unk0ea208_Unk_0eac80`: decompiler-derived
- `Unk0ea208_Unk_0ead1c`: decompiler-derived
- `Unk0ea208_Unk_0eae20`: decompiler-derived

## Not done in M1-T770
- `Unk0ea208_Unk_0ea70c`
- `Unk0ea208_GetField0`
- `Unk0ea208_GetField4`
- `Unk0ea208_GetField8`
- `Unk0ea208_Unk_0eb2cc`: decompiler-derived
- `Unk0ea208_Unk_0eb230`: decompiler-derived
- `Unk0ea208_Unk_0eada8`: decompiler-derived

## Not done in M1-T771
- `Unk0ea208_GetFieldC`
- `Unk0ea208_GetField3c`
- `Unk0ea208_ForEachSlot`
- `Unk0ea208_Unk_0ea828`
- `Unk0ea208_Unk_0ea390`
- `Unk0ea208_Unk_0eade4`: decompiler-derived
- `Unk0ea208_Unk_0eb264`: decompiler-derived
- `Unk0ea208_Unk_0eae40`: decompiler-derived

## Not done in M1-T772
- `Unk0ea208_Unk_0eac40`
- `Unk0ea208_Unk_0ead64`
- `Unk0ea208_GetArr10`
- `Unk0ea208_GetArr24`
- `Unk0ea208_GetArr40`

## Not done in M1-T773
- `Unk0ea208_GetArr58`
- `func_020ea6ac`
- `func_020eacb4`
- `func_020ea3cc`
- `func_020ea320`
- `func_020eb034`
- `func_020ea630`
- `func_020ea208`

## Not done in M1-T775
- `func_020eaa90`
- `func_020eae84`
- `func_020eb488`
- `Unk0ea208_Unk_0ea878`: decompiler-derived (plain cleanup)
- `Unk0ea208_Unk_0ea984`: decompiler-derived (plain cleanup)
- `Unk0ea208_Unk_0ea390`: hand-matched
- `Unk0ea208_GetField0`: hand-matched
- `Unk0ea208_GetField4`: hand-matched
- `Unk0ea208_GetField8`: hand-matched
- `Unk0ea208_GetFieldC`: hand-matched
- `Unk0ea208_GetArr10`: hand-matched
- `Unk0ea208_GetArr24`: hand-matched
- `Unk0ea208_GetField3c`: hand-matched
- `Unk0ea208_GetArr40`: hand-matched
- `Unk0ea208_GetArr58`: hand-matched
- `Unk0ea208_Unk_0ea70c`: hand-matched
- `Unk0ea208_Unk_0ea828`: hand-matched
- `Unk0ea208_Unk_0eac40`: hand-matched
- `Unk0ea208_ForEachSlot`: hand-matched
- `Unk0ea208_Unk_0ead64`: hand-matched
