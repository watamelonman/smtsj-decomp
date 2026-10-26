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

## M1-T770 — verified matches

All eight functions are 100% in the local objdiff report. Evidence below is
from the original delinked ARM instructions and their relocation targets.
Neutral names are retained because the higher-level purposes are unproven.
None of these functions allocate or transfer ownership.

| Function | Size | Behavior and evidence |
| --- | --- | --- |
| `Unk0ea208_Unk_0eb308` | 28 B | Resets the caller-owned work: word +0x1c4 = 1, words +0x1c8/+0x1cc = 0, byte +0x1d0 = 0. Evidence: `mov r1,#1` / `str r1,[r0,#452]`, zero stores at +456/+460, and a zero `strb` at +464. |
| `Unk0ea208_Unk_0ea70c` | 32 B | When the singleton at `data_02176ddc` and its +0x1cc word are both nonzero, calls `Unk0ea208_ForEachSlot` on the singleton. Evidence: the `cmp`/`ldrne`/`cmpne` guard and the call; callers are the state handlers in game/unit_020f470c and game/unit_020f4c50. |
| `Unk0ea208_Unk_0eac80` | 32 B | Fixed teardown sequence: `func_02057e18(31)`, `func_02057ddc(-1)`, `func_02057524(4)`. Evidence: `mov r0,#31`, `mvn r0,#0`, `mov r0,#4` before the three calls. |
| `Unk0ea208_Unk_0ead1c` | 32 B | Calls `Unk0e8228_Unk_0e8f38`; if the result is zero, calls `Unk0ea208_Unk_0ea85c`, otherwise forwards the borrowed result to `Unk0caea8_Unk_0cb044`. Evidence: the `cmp r0,#0` / `bne` split and both call relocations. |
| `Unk0ea208_Unk_0eae20` | 32 B | Zeroes six caller-owned words at +0x00, +0x04, +0x10, +0x14, +0x18 and +0x1c; +0x08 and +0x0c are left alone. Evidence: six zero `str` stores at exactly those offsets. |
| `Unk0ea208_GetField0` | 40 B | Returns the borrowed singleton word at +0x00, or 0 when the singleton is null or its +0x1cc word is zero. Evidence: `data_02176ddc` load, `[r0,#460]` check, `ldrne r0,[r0]`. |
| `Unk0ea208_GetField4` | 40 B | Same guard, returning the borrowed singleton word at +0x04. Evidence: `ldrne r0,[r0,#4]`. |
| `Unk0ea208_GetField8` | 40 B | Same guard, returning the borrowed singleton word at +0x08. Evidence: `ldrne r0,[r0,#8]`. |

No M1-T770 functions remain on the hard list. The typed work parameter and the
per-function comments record the observed stores, guards and forwarding without
changing the generated code.

## Hard list
None from M1-T770.

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
