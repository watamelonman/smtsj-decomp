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

## M1-T777 additions

The two functions below are defined in `src/game/unit_0210fe28.c` and match the
delinked ARM code at **100% objdiff**. The work view now also exposes the
selection value at +0x10, the changed flag at +0x14, and the eight saved
selection bytes at +0x58; the message view is the two flag bytes plus sixteen
payload words used by the message providers.

## `func_0211030c` (844 bytes)

Runs the twelve-state entry sequence selected by the state word at +0x00.
States 0..3 advance the opening animation and drive the handle updates through
`Unk10fe28_Unk_110048`; states 4/5 and 7 apply `Unk10fe28_Unk_1102d4`; state 6
waits on the three gate calls and then either advances to state 8 or branches to
state 7; states 8..10 wait on the entry-selection gates; state 11 posts the
cleared message through `Unk0bc1a8_Unk_0bc9b4` using the header word. Evidence:
the state dispatch table at 0x02110330, the ordered calls and the literals at
0x021103b0..0x02110654. The case bodies are emitted in the original order
(4/5, 7, 6, 8, 10, 9, 11) because that ordering reproduces the original block
layout. The per-state `func_02065c30` call is shared by all paths after the
state-6 gate, as shown by the two branches to 0x02110558.

## `func_02110658` (972 bytes)

Handles interaction states 4 and 5. State 4 advances the entry field through
`func_0205e84c`, optionally skips the special index 4 with the +0x0c mode, and
then either consumes a request (`func_02053800(0,1)`) by selecting one of the
four saved bytes at +0x58, or handles the second request gate by saving the
selected byte and refreshing the +0x54 object. State 5 writes the chosen value
back into the four selection bytes and runs the changed-flag path through
`func_0205e84c(&work->unk_0010, ...)`. Evidence: the two-case dispatch at
0x02110670, the `func_0205e84c` argument setup at 0x02110688 and 0x021109f0,
and the saved-byte copies at 0x02110878. The index-4 skip is a `do/while` over
the +0x08 field; the shared `func_02065c30` call after the state-4 gate is
visible as the two branches to 0x02110558.

## Hard list (M1-T777)

- `func_021100c0` (532 bytes) — the state-0 prologue materialises a short-circuit
  boolean over `&work->unk_000c`, the request pointer and request byte 0 bit 3,
  then conditionally stores the +0x10 word from the request or zero. Tried
  nested `if`, `&&` chains, pointer variables, ternaries and a `switch` wrapper;
  mwcc 2.0/sp1p5 if-converts the first two tests into `cmpne` and drops the
  original's stack-spilled value and duplicate boolean test, so the function is
  left undefined (its asm stays in the delink). A decomp.me scratch is the next
  step.
- `func_02110a24` (1252 bytes) — grid drawing with four float alphas, the two
  selection passes and the signed halfword tables at 0x0213ca6c/78/80/94. The
  float clamp loop and call structure were recovered, but the remaining
  differences are register-allocation only (the +0x08 loop counter and the
  `sel` pointer land in the opposite callee-saved registers / stack slots from
  the original). Left undefined for a scratch.
- `func_02110fc8` (1048 bytes) — the twelve-state drawing/teardown dispatcher.
  Its state layout and calls are documented here for a follow-up, but it was not
  attempted within this card's budget. Left undefined.

