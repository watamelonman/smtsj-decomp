# game/unit_0210fe28 — M1-T776

All eight functions below match the delinked ARM code at **100% objdiff**
with the configured mwccarm 2.0/sp1p5 build. Names remain the existing neutral
symbols: the call sequences and field accesses establish the behavior described
here, but do not establish original source names. Storage belongs to the caller;
the private work view describes only the offsets used by these functions.

## `Unk10fe28_Unk_10fe28` (32 bytes)

Resolves group 1 from the handle at work +0x18 using `func_0204fe68`, then
returns the entry at the index stored at +0x08 from `func_0204fed8`. Evidence:
the two calls and their literal/field arguments at 0x0210fe28. Requires a valid
work pointer and resource handle. `func_021100c0` stores the returned value and
passes it as the entry argument of `func_02061f10` on the +0x54 handle
(`bl; str r0,[sp]; ldr r0,[r4,#0x54]; bl func_02061f10` at 0x364/0x368 and
0x394/0x398); `func_02110658` does the same at 0x8b4/0x8b8, mirroring
`func_0210fe48`'s use of the same lookup.

## `Unk10fe28_Unk_1113e0` (32 bytes)

Calls the subordinate teardown `func_0210ff80`, releases the handle at +0x18
through `func_02053000`, then clears +0x18. Evidence: the ordered calls and
zero store at 0x021113e0. The caller supplies initialized work storage.

## `Unk10fe28_Unk_110048` (44 bytes)

Passes a value to `func_0205c408` for handle `work->unk_0028[i]`, then calls
`func_0205c6e0` on that same handle. Evidence: indexed loads from +0x28 around
the two calls at 0x02110048. The index must be in [0, 10); no bounds check is
present in the original.

## `Unk10fe28_Unk_1102d4` (56 bytes)

Calls `func_0205c704` for four handles selected by the signed halfwords in
`data_0213ca70`. Evidence: four-iteration loop, signed halfword loads and
indexed handle loads at 0x021102d4. Table values must index initialized slots.

## `Unk10fe28_Unk_110074` (76 bytes)

Initializes slots 0 and 1 with values 0 and 2, then slots 2 through 7 with
value 6 through `Unk10fe28_Unk_110048`. Evidence: the literal call arguments
and loop bound at 0x02110074. Slots 8 and 9 are not modified here.

## `func_02110f08` (192 bytes)

Submits six entries from the signed halfword table `data_0213ca88` through
`func_0205de40`, with unit scales and final argument 5. When +0x0c is 1,
table value 4 is skipped. A nonzero second parameter enables comparing the
loop index with +0x08 and setting the selected color to `~0x3900U`; other
entries use `0xaddeffff`. Calls `func_02057df8` after the loop. Evidence:
comparisons, color literals, table loads and submission arguments at 0x02110f08.
The table is declared const because this operation reads a fixed selection
mapping; that qualification also reproduces the original instruction scheduling.

## `func_0210ff80` (200 bytes)

Releases and clears +0x24, +0x50, +0x54, the ten handles at +0x28, +0x1c and
+0x20. Calls `Unk065e88_Unk_065eac` only for mode 1 at +0x0c, and calls
`func_0205bb68` once before releasing the ten handles and six times at the end.
Evidence: conditional handle checks, zero stores and call ordering at 0x0210ff80.
The two handles at +0x50/+0x54 are passed unconditionally to their release helper.

## `func_0210fe48` (312 bytes)

Registers six descriptors at `data_021514b0` with stride 0x18; obtains handles
at +0x1c and +0x20; creates the +0x50 and +0x54 handles; configures +0x50
using entry 10 of resource group 1 from +0x18; creates and associates ten
handles at +0x28. Mode 1 invokes `Unk065e88_Unk_065e88`. The final calls
include argument 0x39 and creation of +0x24 from `data_02151550`. Evidence:
the descriptor loop, field stores, literals and helper calls at 0x0210fe48.
Requires a valid preexisting +0x18 handle and caller-owned work storage.

## Hard list

None. No requested function was omitted. The TU remains linked from the delink
until a human changes its completion status, as required by the task card.
