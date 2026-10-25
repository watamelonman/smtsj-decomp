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

## M1-T618 verified functions

All eight functions below match at 100% in objdiff. Parameters and borrowed
record layouts follow original loads, stores and helper calls; no ownership
transfer is inferred except publication of the allocation in `func_02093a1c`.

| Function | Contract and evidence |
| --- | --- |
| `Unk0939f0_Unk_093ea8` | Requires a writable record. When the shared handle is nonzero, derives increments at +0x3c/+0x40/+0x44 from 0xff000 minus coordinates, dividing by 0xd000, then sets +0x6c to 4. |
| `Unk0939f0_Unk_093f0c` | Initializes a writable record: clears 0x20 bytes at +0xc, sets three byte defaults to 255, coordinates to 0xff000, six words to 255 and three words to zero. Preserves +0x6c. |
| `func_02093d14` | Returns a borrowed record for kinds 0–3. Kind 1 scans sixteen identifiers at +0xdd with stride 0x70; an unsuccessful scan falls through to kind 2. Invalid kinds return null. |
| `func_02093dfc` | Updates three fixed-point coordinates via `func_0206d950`, using signed halfword values and increments and bound 255; original shifts establish 12 fractional bits. |
| `func_0209432c` | Rejects indices above the original count-minus-one bound, then tests the selected query word for positivity. Original switch loads +0xd8/+0xf8/+0x118/+0x138. No additional lower bound is inferred. |
| `func_02094584` | Returns whether any selected state byte is nonzero. Original scan excludes matched index zero from the indexed state test, and always checks the leading and two trailing states. Null shared handle returns zero. |
| `func_0209461c` | Tests one selected state byte by kind and identifier. Null shared handle, invalid kind or unsuccessful identifier search returns zero. Original indexed load is at +0xdc with stride 0x70. |
| `func_02093a1c` | Allocates 0x850 bytes through `func_020611dc`, clears and initializes nineteen records, publishes the shared handle and clears all state bytes. Allocation failure returns without publication. Original callback arguments establish the two callback contracts. |

No module boundary changed. Existing symbol names remain unchanged because
higher-level purpose is not established. The 0x70-byte layout includes the
identifier at +0x6d and trailing padding, as established by the original stride.
This card requires no new runtime tests; instruction and relocation comparison
provides the acceptance check.

## M1-T619 verified functions

All three functions match the original ARM object at 100% objdiff, including
relocations. Neutral original symbols are retained because higher-level game
semantics are not established. Evidence is the corresponding instructions in
`build/delinks/src/game/unit_020939f0.o`.

| Function | Contract and evidence |
| --- | --- |
| `func_02093b6c` | Advances a borrowed writable 0x70-byte record by one tick. The state byte at +0x6c selects initialization, update, return interpolation and reset. Kinds 0–3 select the original 32-byte providers; kind 0 preserves the first eight bytes. Original comparisons use signed timing words at +0, +4 and +8. Fallthrough performs newly selected states in the same tick. |
| `func_020943dc` | Returns zero when the kind/index query is unavailable or the shared group is absent. Otherwise returns the selected duration word, adding thirteen ticks when the three packed bytes differ from 0xffffff00. Original query calls, byte offsets +0xd4/+0xd5/+0xd6 and 0x20 stride establish this behavior; repeated provider calls are retained. |
| `func_02093f70` | Requires an initialized shared group and a valid table index. Starts each available kind using the 0x148-byte table stride, resets ticks, sets state 1 and selects mode 1 or 2 from the packed byte triplet. Kind 0 retains current integer coordinates when already active; kind 1 claims the first inactive indexed record. Original identifier scan and lookup fallthrough are preserved, including behavior when no slot is free. |

The existing private layout now exposes the observed signed timing words and
fourth coordinate. No module boundary changed. Runtime tests are not required
by this card; object comparison checks the exact instructions and relocations.

## Hard list

None for M1-T617, M1-T618 or M1-T619.
