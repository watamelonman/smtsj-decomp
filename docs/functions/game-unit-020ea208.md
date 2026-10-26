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

## M1-T773 — verified matches

All eight functions are 100% in the local objdiff report. Evidence below comes
from the original delinked ARM instructions and their relocation targets. The
functions borrow the singleton, its tables and the +0x70 slot records; none
allocates or transfers ownership. `Unk0ea208Work` is the singleton view,
`Unk0ea208Slot` is one 56-byte slot, and `Unk0ea208IdMap` is one 8-byte entry of
the static id tables.

| Function | Size | Behavior and evidence |
| --- | --- | --- |
| `Unk0ea208_GetArr58` | 76 B | Return entry i of the six-word table at work+0x58, or 0 when the singleton is missing/not ready (+0x1cc zero) or i is outside 0..5. Evidence: the `cmp r4,#6` bound after the guard and `ldr r0,[r0,#88]` after the scaled add. |
| `func_020ea6ac` | 96 B | Claim the first free +0x70 slot with `Unk0ea208_Unk_0eb2cc` and forward five caller values to `func_020eae84`; return when the singleton is missing/not ready or no slot is free. Evidence: the `bl Unk0ea208_Unk_0eb2cc` null check, `ldr ip,[sp,#32]` and the two stack stores. |
| `func_020eacb4` | 104 B | Translate an id through the `data_02150ca0` table (five key/value entries) then the `data_02150c80` table (four entries), returning the matching entry's value; return 0 when absent. Evidence: the two `ldr [r2,r3,lsl #3]` loops with bounds 5 and 4 and the final `mov r0,#0`. |
| `func_020ea3cc` | 108 B | Dispatch selector 4 to `Unk0ea208_Unk_0ea984(func_02044ec4(...))`, 9 to `func_020eaa90(func_02044ec4(...))`, and all others to group 39 entry 1; submit the result to `Unk0fedd4_Unk_0fee38`. Evidence: the two selector compares and the shared `bl Unk0fedd4_Unk_0fee38` epilogue. |
| `func_020ea320` | 112 B | Replace +0x58 table entry i: a zero handle clears it, otherwise store the `func_020cb1a0` record and pass i plus the `Unk0caea8_Unk_0cb044` result to `Unk0ea208_Unk_0ea390`. Evidence: `str [r?, #88]` on both paths and the two call relocations. |
| `func_020eb034` | 116 B | Release a slot's +0x20 and +0x34 handles and its four +0x24 handles through `func_02061424`, clearing each, then zero the scalar words through `Unk0ea208_Unk_0eae20`. Evidence: the guarded loads at +32/+52, the four-iteration +36 loop, and the final call. |
| `func_020ea630` | 124 B | Selector jump table: 0/1/5/6/7 call `func_020eacb4(selector)`, 2 -> `Unk0ea208_Unk_0ead3c`, 3 -> `Unk0ea208_Unk_0ead1c`, 4 -> `Unk0ea208_Unk_0ead4c`, 8 -> `Unk0ea208_Unk_0ead64`, 9 -> `Unk0ea208_Unk_0eada8`, 10 -> `Unk0ea208_Unk_0eade4`; other selectors return 0. Each arm returns the callee's r0: explicitly for the value-returning arms (0/1/5/6/7/9/10) and by leaving r0 untouched for the void-callee arms (2/3/4/8), matching the original. Evidence: `cmp r0,#10` / `addls pc,pc,r0,lsl #2` and every call relocation. |
| `func_020ea208` | 136 B | Store the `Unk09974c_Unk_099d14` object in +0x40 table entry i and submit it with the +0x24 handle to `func_02061f10`; a null `Unk09974c_Unk_099bac` result falls back to data_02150cc8. Evidence: `str r0,[r1,#64]`, the `ldreq` literal, `ldr r0,[r1,#36]` and the stack argument. |

No M1-T773 functions remain on the hard list. The two table getters share the
existing `Unk0ea208Work` view; the slot view gained the handles released by
`func_020eb034`, and `Unk0ea208_Unk_0ea984` now returns the resource that its
existing body already left in r0 (needed by `func_020ea3cc`).

## M1-T774 — verified matches

All eight functions are 100% in the local objdiff report. Evidence below comes
from the original delinked ARM instructions and their relocation targets. The
functions borrow the singleton, the battle entry, its id array and the +0x70
slot records; none allocates or transfers ownership. `Unk0ea208Work` is the
singleton view, `Unk0ea208Slot` one 56-byte slot, `Unk0ea208Desc` the borrowed
resource descriptor used by func_020eb324, and `Unk0ea208Graphic` the object
returned by `Unk065e88_Call_02065fc0`.

| Function | Size | Behavior and evidence |
| --- | --- | --- |
| `func_020ea290` | 144 B | Rebuild the six-entry +0x58 table for one battle entry: after the singleton/ready guard, reserve index 0 with group-39/entry-3 when the `0e8c68` state word is set, then copy each halfword of the entry's id array through `func_020ea320`, skipping values for which `Unk0cb0d0_IsAbove15e` returns 1. Evidence: the guarded `ldr [r0,#460]`, the `movne r6,#1` index base, the `ldrh`/`cmp #1` skip, and the six-iteration loop. |
| `func_020ea744` | 228 B | Resolve the id to a battle entry and queue its display request: the `0xa9`/thunk guard, the `0e8f20` mode word (passed as the field selector to `func_02049f6c`), the jump-table cases 1/3/4 setting the extra flag, the `*20` then divide-by-100 threshold, and the `func_02049c28` pair plus `func_0204a244` result passed to `func_020ea6ac`. Evidence: the `cmp r1,#27`, `addls pc`, `0x51eb851f` magic and the five-argument call setup. |
| `func_020eb0a8` | 208 B | Advance one slot's graphics state: state 1 waits for `func_0205ca48` on the +0x20 object, releases it, creates a replacement with `Unk065e88_Call_02065fc0(GetField8(), GetFieldC(), 1, 0)`, configures its animation through `func_0205c408`/`0205c41c`/`0205c6e0`, chooses 0xff0000ff when +0x10 is set otherwise 0xa5ff31ff, and stores the object with state 2. States other than 1/2 are ignored. Evidence: the two state compares, the +0x20 dereference/release, and the two colour literals. |
| `func_020eb178` | 184 B | Emit a finished slot's effects when `GetField8` is nonzero and the slot is in state 2: the +0x1c guard selects `func_0205de40(2, resource8, 5, +0x08, +0x0c, 1.0f, 1.0f, 0, 1.0f, 10)`; the +0x14 guard selects `func_02058e9c(2, +0x18, +0x08+15, +0x0c+15, 1.0f, 0, 12)`. Evidence: the saved `mov r1,r0`, the two guarded stack-argument blocks and the 0x3f800000/10/12 immediates. |
| `func_020eb324` | 356 B | Step through four descriptor stages in work+0x1d0: stage 0 loads descriptor 0xd3 after clearing +0x14, stage 1 does the same for ids 1..3, stage 2 creates the four named entries through `Unk05b82c_CreateNamedEntry` and runs `func_0205b9a0`, and stage 3 waits for all four `Unk05ae50_Unk_05b388` checks before running `Unk05ae50_Unk_05af2c` on each. The byte advances after stage 0/1/2/3; stages outside 0..3 and a completed stage 3 return 1, intermediate stages return 0. Evidence: the `ldrsb [work,#0x1d0]` jump table, the data_0213c72c-indexed loops and the +1 stores. |
| `func_020eb6e4` | 252 B | Release one work object: run `ForEachSlot`, free +0x0c/+0x08/+0x04/+0x00, clear the six +0x24, five +0x10 and one +0x3c handles through `func_020629c4`, call `Unk0fedd4_Unk_0fee18`, run `func_0205bb68` four times, and clear the singleton at `data_02176ddc`. Evidence: the four guarded release pairs, the bounds 6 and 5, the four-iteration loop and the final literal store. |
| `Unk0ea208_Unk_0ea878` | 268 B | Refresh a mode-1 entry's display table: read four accessor values, store group-14 entries 1/2/3 in slots 4/5/6, compare the remaining accessors and either store both in slots 3/4 then submit group-14 entry 0 with selector 3, or store the second in slot 3 and submit with selector 2. Evidence: the accessor argument 1, the 0xe table calls, the slot immediates 4/5/6/3/4 and the selectors 3/2. The body was already decompiler-derived and 100%; only its comment was rewritten. |
| `Unk0ea208_Unk_0ea984` | 268 B | Same refresh for a mode-0 entry: store group-14 entries 1/2/3 in slots 1/2/3, compare the remaining accessors and either store both in slots 1/2 then submit with selector 1, or store the second in slot 1 and submit with selector 0; return the submitted resource. Evidence: the accessor argument 0, the 0xe table calls, slots 1/2/3/1/2 and selectors 1/0. The body was already decompiler-derived and 100%; only its comment was rewritten. |

No M1-T774 functions remain on the hard list. The two decompiler-derived
bodies that were already at 100% (`0ea878`, `0ea984`) kept their generated
code; only the comments were expanded.

## M1-T775 — verified matches

All three functions are 100% in the local objdiff report. Evidence below comes
from the original delinked ARM instructions and their literal pools. The
functions do not own the battle entry, its id array or the +0x70 slot records;
created resources and handles are stored in the caller-owned work.
`Unk0ea208Work` gained the +0x1d4 frame word that the state machine bumps each
call.

| Function | Size | Behavior and evidence |
| --- | --- | --- |
| `func_020eaa90` | 404 B | Refresh one mode-0 battle entry's display table and scan its resulting id array: read the four `func_0204a1xx(arg, 0)` accessors, store group-14 entries 1/2/3 in table slots 1/2/3, compare the last two accessors, then either store both in slots 1/2 and submit group-14 entry 0 with selector 5 or store the second in slot 1 with selector 4. Pass the submitted resource to `func_02062208` and scan its halfwords: 0xffff sets a valid-range flag, 0xfffe clears it, and an 0x8001 outside that range stops the scan and returns the pointer one halfword past it. Evidence: the accessor immediates 0, the 0xe table relocations, slot/selector immediates 1/2/3/5/4, and the 0x8001/0xfffe/0xffff literal pool plus the `rsb`-derived 0xffff in the scan loop. |
| `func_020eae84` | 432 B | Initialize one +0x70 slot and build its graphics: after the `GetField8`/`GetFieldC` guard, store 1 at +0x00/+0x04, the position minus 12 at +0x08/+0x0c, the caller flags at +0x10/+0x14/+0x1c, and, when the sixth input is nonzero, the mapped `(u16)` value at +0x18 through `Unk0ddeb0_Unk_0ddfd8` then `Unk0ca69c_Unk_0ca6a4`. Create the main graphic with `Unk065e88_Call_02065fc0(resource8, resourceC, 1, 0)`, animation 6, colour 0xa5ff31ff (0xff0000ff when +0x10 is set), and store it at +0x20. Unless the fifth input is nonzero, also create the companion at +0x34 with animation 5 and `func_02050074(1,4) << 2`, then four more at +0x24 with animation 0..3 and colour -1. Evidence: the -12 offsets, creation arguments (1,0), animation values 6/5/0..3, both colour literals, and the four-iteration table loop. |
| `func_020eb488` | 580 B | Advance the work state machine: bump +0x1d4 and wrap it to zero at 0xffff, then dispatch on +0x1c4. State 1 waits for `func_020eb324`, clears +0x1c8 and moves to 2; state 2 allocates the shared `Unk0fedd4_Alloc` object and falls into state 3, which creates five +0x10 and six +0x24 text objects plus +0x3c; state 4 loads the four named resources at data_02150cd4/02150ce8/02150d00/02150d18 through `func_0205dcd4` and `func_0205c2c4`; state 5 falls into 6, which rebuilds the `data_02150ca0` (five entries) and `data_02150c80` (four entries) value tables with `func_0204fed8`, uses selector 13 instead of 7 when `Unk0e651c_Unk_0e666c(0x703)` is zero, submits the +0x3c resource and moves to 7; state 7 sets ready; state 8 advances the slots through `Unk0ea208_Unk_0eb230`. Evidence: the 0xffff wrap compare, the addls jump table, the 020629ac argument sets, the four resource names at 02150cd4/02150ce8/02150d00/02150d18, the 0x703 selector test, the id-table stores, and the state immediates 1..8. |

No M1-T775 functions remain on the hard list.
