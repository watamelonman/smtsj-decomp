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

## M1-T771 — verified matches

All eight functions are 100% in the local objdiff report. Evidence below comes
from the delinked ARM and its relocation targets. These functions borrow the
singleton, table and slot memory; none allocates or transfers ownership. The
shared views are `Unk0ea208Work` (singleton) and `Unk0ea208Slot` (one of the six
56-byte records at work+0x70).

| Function | Size | Behavior and evidence |
| --- | --- | --- |
| `Unk0ea208_GetFieldC` | 40 B | Returns the borrowed work word at +0x0c when the singleton exists and its +0x1cc word is nonzero; otherwise 0. Evidence: `cmp r0,#0`, `ldr r1,[r0,#460]`, `ldrne r0,[r0,#12]`. |
| `Unk0ea208_GetField3c` | 40 B | Same guard as GetFieldC, returning the borrowed word at +0x3c. Evidence: `ldrne r0,[r0,#60]`. |
| `Unk0ea208_ForEachSlot` | 40 B | Calls `func_020eb034` once per slot: six records from +0x70, stride 56. Evidence: `add r5,r0,#112`, loop bound 6, `add r5,r5,#56`, and the call relocation. |
| `Unk0ea208_Unk_0eb2cc` | 44 B | Returns the first of the six +0x70 slot records whose +0x00 word is zero, or NULL when all are occupied. Evidence: `ldr r1,[r0]` / `bxeq lr`, stride 56, bound 6, final `mov r0,#0`. |
| `Unk0ea208_Unk_0ea828` | 52 B | Visits the first `Unk0e8228_Unk_0e8460()` entries of the 0e8228 +0x40 table and passes each to `func_020ea744`. Evidence: the count guard and the paired `bl Unk0e8228_GetArr40` / `bl func_020ea744` loop. |
| `Unk0ea208_Unk_0eb230` | 52 B | Calls `func_020eb0a8` for every +0x70 slot whose +0x00 word is nonzero. Evidence: `ldr r0,[r5]` / `beq` skip, stride 56, bound 6, and the call relocation. |
| `Unk0ea208_Unk_0ea390` | 60 B | Bounds-checks index 0..5, then forwards `work->UnkTable0024[i]` and the caller value to `func_02061f10` with fixed middle args -1, 0, 0. Evidence: `cmp r5,#6` / `popge`, `ldr r0,[r0,r5,lsl #2]` at +36, `mvn r1,#0`, and the stack argument store. |
| `Unk0ea208_Unk_0eada8` | 60 B | When the singleton exists and its +0x1cc word is nonzero, resolves group 39 entry 0 and passes it to `func_0204fed8` with selector 3; returns 0 on either guard failure. Evidence: `ldr r0,[r0,#460]`, `mov r0,#39` / `mov r1,#0`, then `mov r1,#3`. |

No M1-T771 function remains on the hard list.

## Not done in M1-T771
- `Unk0ea208_Unk_0eade4`: decompiler-derived
- `Unk0ea208_Unk_0eb264`: decompiler-derived
- `Unk0ea208_Unk_0eae40`: decompiler-derived

## M1-T772 — verified matches

All eight functions are 100% in the local objdiff report. Evidence below is from
the original delinked ARM instructions and their relocation targets. The
functions borrow the singleton, table, slot and record views; none allocates or
transfers ownership. `Unk0ea208Work` is the singleton view and `Unk0ea208Slot`
is one of the six 56-byte records at work+0x70.

| Function | Size | Behavior and evidence |
| --- | --- | --- |
| `Unk0ea208_Unk_0eade4` | 60 B | When the singleton exists and its +0x1cc word is nonzero, resolve group 39 entry 2 and pass the handle to `func_0204fed8` with selector 2; otherwise return 0. Evidence: guarded `ldr [r0,#460]`, `mov r0,#39` / `mov r1,#2`, then a second `mov r1,#2` before the 0204fed8 call. |
| `Unk0ea208_Unk_0eac40` | 64 B | Resolve group 39 entry 2 and submit it with work+0x3c to `func_02061f10` using fixed middle arguments -1, 0 and 3. Evidence: the 020445f4/0204fed8 pair with selector 1, the stack store of the result, `ldr r0,[r4,#60]`, `mvn r1,#0`, `mov r2,#0` and `mov r3,#3`. |
| `Unk0ea208_Unk_0eb264` | 64 B | Run the fixed teardown, call `func_020eb178` for each +0x70 slot whose +0x00 word is nonzero, then run the closing teardown. Evidence: `add r5,r4,#112`, the `ldr r0,[r5]` / `beq` skip, stride 56, bound 6, and both teardown call relocations. |
| `Unk0ea208_Unk_0ead64` | 68 B | Resolve group 5 through the 0e8228 table and inspect the `func_02044ec4` record: when bit 2 of byte +0x282 is set, report id 0x17d, otherwise report the halfword at +0x1d8. Evidence: `mov r0,#5`, the paired table calls, `ldrb [r0,#642]` shifted to isolate bit 2, `add r0,r0,#256` and `ldrh [r0,#216]`. |
| `Unk0ea208_Unk_0eae40` | 68 B | Initialize a caller-owned object: pass the first three inputs to `Unk065e88_SetUnkFieldsc_10` (+0x0c/+0x10), store the fourth at +0x28, then write 10, 4 and 2 at +0x24, +0x30 and +0x3c. Evidence: the first call receives the untouched r0/r1/r2, r3 is saved in r4 for SetUnkField28, and the constant moves precede the remaining setter calls. |
| `Unk0ea208_GetArr10` | 76 B | Return entry i of the five-word table at work+0x10, or 0 when the singleton is missing/not ready (+0x1cc zero) or i is outside 0..4. Evidence: `cmp r4,#5` and `ldr r0,[r0,#16]` after `add r0,r0,r4,lsl #2`. |
| `Unk0ea208_GetArr24` | 76 B | Return entry i of the six-word table at work+0x24, or 0 under the same singleton guard or when i is outside 0..5. Evidence: `cmp r4,#6` and `ldr r0,[r0,#36]` after the scaled add. |
| `Unk0ea208_GetArr40` | 76 B | Return entry i of the six-word table at work+0x40, or 0 under the same singleton guard or when i is outside 0..5. Evidence: `cmp r4,#6` and `ldr r0,[r0,#64]` after the scaled add. |

No M1-T772 targets remain on the hard list. The three guarded table getters
were rewritten to use the typed work view without changing the original
generated instructions, and the two setter/teardown bodies now name their
pointer parameters.

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
