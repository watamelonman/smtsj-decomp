# game/unit_0210fe28 — M1-T776

The eight M1-T776 functions below match the delinked ARM code at **100% objdiff**
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

## Hard list (M1-T776)

None. No requested M1-T776 function was omitted.

## M1-T777 additions

`func_021100c0` and `func_02110fc8` are defined in
`src/game/unit_0210fe28.c` and match the delinked ARM code at **100% objdiff**.
`func_02110a24` was reconstructed but is still undefined in C; its measured
objdiff score and trials are recorded below. The work view also exposes the
selection value at +0x10, the changed flag at +0x14 and the eight saved
selection bytes at +0x58; the message view is the two flag bytes plus sixteen
payload words used by the message providers; the event view is the type word
followed by the flag-qualified payload word at +0x10.

The `func_02008904` arguments were recovered from the register setup: at
0x021100c0 the source is `func_02008904(sel, w->unk_0058, 8)` (copy the live
selection bytes into the saved area) and at 0x02110658 it is
`func_02008904(w->unk_0058, sel, 8)` (restore them). Earlier documentation had
the two directions reversed.

## `func_021100c0` (532 bytes)

Handles incoming event words 0 through 4. Case 0 reads the optional payload
through the flag-qualified helper: the value at payload +0x10 is stored to work
+0x0c only when byte +0 is bit 3; otherwise +0x0c is cleared. It then clears the
message flag through `Unk0bc1a8_SetFlag4Inv`, reinitializes the work with
`func_0210fe48`, resets the state and selection, copies the live selection into
+0x58 with `func_02008904`, and refreshes the +0x54 object. Case 1 clears a
stack message and sends it through `Unk0bc1a8_Unk_0bc514(w, 1, &message)`.
Case 2 clears a stack message and sends it through
`Unk0bc1a8_Unk_0bc928(0x28, header, &message)`. Case 3 reinitializes the work,
refreshes +0x54, restores entry values 2/8/9/0 and advances to state 4. Case 4
is empty. Evidence: the 0x021100c0 dispatch table (bounds 0..4), the payload
flag test `tst r0,#8` and conditional store at 0x021102f8, the two stack
message clears at 0x02110460/0x02110408, and the ordered `Unk10fe28_Unk_110048`
arguments at 0x021103bc..0x021103ec.

The odd `&w->unk_000c` test and the second pointer test reproduce the original
short-circuit shape; the compiler folds the helper's null check into the same
comparison. Both stack messages are live in the original frame, which is why
they occupy separate 68-byte slots.

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
0x02110670, the `func_0205e84c` call setups at 0x021106a0 and 0x02110a04, the
state-4 request branches at 0x0211070c/0x0211076c, and the saved-byte stores in
the state-5 body. The index-4 skip is the `do/while` at 0x021106c8.

## `func_02110fc8` (1048 bytes)

Draws and advances the entry screen, then dispatches on work +0x00. It first
returns when `Unk0bc1a8_IsSlotEmptyOrFlag8(Unk0bc1a8_GetHeaderWord(w))` is
nonzero, then brackets the frame with `func_020580ec(0/1)` and runs the palette,
render and alpha setup calls. States 2 and 3 draw the column grid (with the
special index 6 omitted in mode 1), place the cursor from the first entry's
+0xc/+0x18 fields through `func_02060b60`, and for state 3 send entries through
`func_02110f08(w, 1)` and `func_02110a24(w, 0)`. States 4, 5, 6, 7, 8 and 10
draw six row entries with `func_02057eb8`/`func_0205de40`, place the +0x48
cursor and the state-4 +0x4c cursor, submit the selection, draw the two labels
and the first entry, then call `func_02110a24(w, 1)`. States 0, 1, 9 and 11 are
empty. Evidence: the dispatch table at 0x02111014 (bounds 0..11), the conditional
state-3 continuation at 0x02111228, the two row loops and their 21/41 strides,
and the `func_02060b60`/`func_0205c748` argument stores at
0x021111b8..0x021114a4.

## `func_02110a24` (1252 bytes) — hard

Grid drawing with four per-column alphas. Recovered structure: alpha[i] is
`(f32)w->unk_0004 * (1.0f/6.0f) + i * -0.5f`, clamped to [0, 1]; four rows at
y = i*21 draw 4 columns at x = j*41 (2 columns on the last row); a selected
row draws the +0x30 entry and the four saved selection bytes at +0x58 through
`func_0205c848`/`func_0205dee8`; a final pass highlights the selected row using
`data_0213ca6c/78/80` and tints with `0x39f7efff`/`-1`. Evidence: the float
constants at data_0213ca94 and 0x3e2aaaab, the soft-float calls at
0x02110a24..0x02110ac4, the 21/41 multipliers, and the signed-halfword table
loads at 0x02110d60..0x02110e9c.

Measured on 2026-10-25 with the configured mwcc 2.0/sp1p5 build:
`objdiff-cli` reports **92.65%** for this function (1228 bytes vs 1252), with
the remaining differences confined to register allocation and loop signedness,
not the recovered call/argument structure. Trials attempted:

- alpha as a struct copied from `data_0213ca94` vs a local array plus cast copy;
- first-row base held in a local pointer, a struct pointer, a `u8 *` cast view,
  an inline helper parameter, and direct `alpha.v[i]` indexing;
- declaration orders `{p,base,i}`, `{i,p,base}`, `{base,p,i}` and the same with
  `pos`/loop counter first;
- selected-row loop counters as `int` (emits `blt`) vs `unsigned` (emits `blo`);
- one shared loop variable vs separate `i`/`j`/`k` scopes;
- float constants as literals vs named locals, and `0.0f` vs `0`.

Every variant reproduces the arithmetic and table/call sequence but leaves the
original's split of `r5`/`r6`/`r7` and its unsigned inner-loop branches; the
function is therefore left undefined and still linked from the delink. A
decomp.me scratch should start from the 92.65% candidate and focus on the
register allocator tie-break, not on semantics.
