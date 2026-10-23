# src/game/unit_020e1648.c

The M1-T1042 and M1-T1043 functions below are verified at 100% in objdiff.

- `Unk0e1648_Unk_0e5240` (12 B): reads entry `index` of `Unk0e1648Table.unk_000c` (the
  32-bit handle table at `+0xc`); the 0e51cc/0e51f4/0e5214 helpers use it to fetch their
  handles.
- `Unk0e1648_Get_data_02176c78` (16 B): returns word 0 of the global state block
  `data_02176c78`.
- `Unk0e1648_Unk_0e2da0` (16 B): returns `&work->unk_00d2[work->unk_007c]`, i.e. the
  `Unk0e1648Slot` selected by `work->unk_007c` (callers read its `unk_0002`/`unk_0004`
  fields, which sit at `+0xd4`/`+0xd6`). The array length (440 entries) is guessed from
  the following field at `+0xe98` and is commented in the struct.
- `Unk0e1648_IsUnkeecSet` (20 B): returns non-zero when the mark byte at `+0xeec` is not
  `0xff`; `0e16f0` and `0e2f54` both write `0xff` there to clear it.
- `Unk0e1648_Unk_0e2cb0` (24 B): flips the boolean at `work->unk_0ec0` (zero becomes one,
  non-zero becomes zero).
- `Unk0e1648_Unk_0e5434` (24 B): forwards `0` to `Unk0e7ac4_Unk_0e8014` and
  `Unk0e7ac4_Unk_0e8030`, resetting those two subsystems.
- `Unk0e1648_Unk_0e1648` (28 B): returns 1 when word 1 of `data_02176c78` is null; `0e1664`
  uses it as a guard before dereferencing that word.
- `Unk0e1648_Unk_0e2c90` (32 B): lexicographic comparison of two work objects; returns the
  `unk_0006` difference, or the `unk_0004` difference when the first key matches.

## M1-T1043

All eight functions match at 100%. Evidence is the delinked ARM instructions;
neutral names are retained where subsystem meanings are unknown. This task extends
the existing source rather than creating a replacement TU. No runtime tests were
added: the card requires instruction matching and checksum validation.

- `Unk0e1648_Unk_0e2d80` (32 B): tail-forwards work `+0x68` and the
  halfword at `work + 8 * work->unk_007c + 0xd4` to `func_020f3de8`.
  Uses the existing typed slot layout; the selected index must be valid.
- `Unk0e1648_IsId177to179` (32 B): returns one for IDs 177, 178 and 179,
  zero otherwise. The descriptive name is supported by the three immediate
  comparisons at `020e2dec`, `020e2df0` and `020e2df4`.
- `Unk0e1648_Unk_0e4f34` (32 B): forwards the ID to `func_0209993c`, then
  reduces the requested signed increment to `99 - value` when their sum exceeds
  99. The incoming ID is now explicit rather than relying on an unchanged r0.
- `Unk0e1648_Unk_0e50c8` (32 B): obtains a handle from `func_020445f4(30, 3)`
  and passes it with the incoming value to `func_0204fed8`.
- `Unk0e1648_Unk_0e51f4` (32 B): fetches the indexed handle through
  `Unk0e1648_Unk_0e5240`, then calls `func_0205caa8` with that handle and
  `data_0213c674[index]`. The index must be valid in both tables.
- `Unk0e1648_Unk_0e1664` (36 B): calls the global-null guard at `020e1648`;
  returns zero if null, otherwise the word at offset `0x58` of the pointee in
  `data_02176c78[1]`. Only the observed field is modelled in the private state type.
- `Unk0e1648_Unk_0e3f5c` (36 B): loads the selected slot's halfword at
  `+0xd6`, calls `Unk09974c_GetEntryUnk08`, and tests its result against 4.
- `Unk0e1648_Unk_0e4fd0` (40 B): returns one only when its first argument is
  4 and `func_0209993c` of the second argument returns a positive signed value;
  other kinds bypass the lookup and return zero.

## M1-T1044

All eight functions match at 100% in objdiff. Evidence is the delinked ARM
instructions; names remain neutral because subsystem meanings are unknown.
The existing TU was extended. No runtime tests are required by this card;
objdiff verifies instruction and relocation identity.

- `Unk0e1648_Unk_0e51cc` (40 B): fetches the indexed handle, calls
  `func_0205c41c(handle, 0)`, then reapplies the corresponding global table word
  through `0e51f4`. The index must be valid for both tables.
- `Unk0e1648_Unk_0e536c` (40 B): writes one at `+0xee8`, copies the saved
  word at `+0xec4` to `+0xec0`, calls `func_020e5394(work)`, then writes state
  byte 7 at `+0`. These fields now use the typed work layout.
- `Unk0e1648_Unk_0e5214` (44 B): calls `func_0205c41c(handle, 0)`, fetches
  the indexed handle again, and explicitly forwards it to `func_0205c6ec`.
- `Unk0e1648_Unk_0e2f54` (48 B): returns if the `+0xeec` byte is `0xff`;
  otherwise calls `func_020e3174(work)`, resets handle index zero through
  `0e51cc`, and writes `0xff` to that marker.
- `Unk0e1648_Unk_0e533c` (48 B): explicitly passes work to `func_020e544c`,
  then applies value 2 when true or 3 when false to the handle at `+0xea0`.
- `func_020e5198` (52 B): tests the signed byte at the second argument's
  `+0x40`; forwards all six arguments to `func_02060b60` only when it is zero.
  ARM `ldrsb` establishes the field type; two stack loads/stores establish
  the fifth and sixth forwarded words. The object remains caller-owned.
- `Unk0e1648_Unk_0e5090` (56 B): calls `func_02063920`, applies the second
  argument through `0e50c8`, and passes `func_02063a30()` as the fifth argument
  of `func_02061f10(handle, -1, 0, 0, result)`.
- `func_020e544c` (56 B): switches on work `+0x68`, returning one for kinds
  zero through five and zero otherwise. The six-entry ARM jump table supports
  the explicit switch; this is not a guessed interpretation of the kinds.

## M1-T1045

All eight functions match at 100% in objdiff. Evidence is the delinked ARM
instructions; names remain neutral because the subsystem meanings are not
established. The card requires instruction matching and checksum validation, so
no runtime tests were added.

- `func_020e1698` (88 B): initialises a nine-word command/handler table: constant
  `0xf08` at `+0`, zeros at `+4`/`+0x18`, and the handlers `020e1b10`, `020e2190`,
  `020e28a8`, `020e1a48`, `020e2a5c` at `+0xc`, `+0x10`, `+0x14`, `+0x1c`, `+0x20`.
  `+0x8` is deliberately not written (no store targets it).
- `Unk0e1648_Unk_0e2d28` (68 B): requires state kind 1 (`+0x68`), then fetches the
  selected slot's `unk_0002` through `func_020f3de8` and reports whether the
  `Unk09974c_GetEntryUnk08` kind of its first halfword is 4.
- `Unk0e1648_Unk_0e2db0` (60 B): ranks a slot: returns 0 when the id's
  `Unk09974c_Unk_09a1e4` lookup is non-zero, else 1 when `unk_0002` exceeds
  `func_0209993c(unk_0000)` and 2 otherwise.
- `func_020e2e0c` (84 B): walks the 12-halfword table at `+0xeee` using the `+0xeed`
  cursor; rejects indexes past 11 and zero entries, arms `func_02065b10` with a new
  `func_02065c10` context, advances the cursor by reloading it after the calls, and
  returns 1.
- `func_020e2e60` (84 B): takes the `func_020f3de8` base for the work, indexes the
  4-byte entry selected by the `+0xeec` byte, ranks it with `0e2db0`, then applies
  it through `func_020e50e8` (mode 2 for rank 0, mode 0 otherwise) and requests
  animation id 1. The switch is required to match the ROM's branch layout.
- `Unk0e1648_Unk_0e4c64` (64 B): returns 0 when the `func_020f3de8` object for the
  work's `+0x68` id has a zero `+3` byte; otherwise forwards the id and value to
  `Unk0f3db4_Unk_0f4510` and reports non-zero.
- `func_020e490c` (88 B): appends slot entries `first..last` through
  `Unk0e1648_Unk_0e48a8`, saving the initial `+0xd0` count, then sorts the appended
  range with `func_02013c68` (record size 8) using `Unk0e1648_Unk_0e2c90`.
- `Unk0e1648_Unk_0e16f0` (64 B): publishes the work pointer at
  `data_02176c80 + 4`, resets the `02e000`/`0fc584` subsystems, clears `+0xee4`
  and the two state bytes, sets state 1, and marks `+0xeec` as idle (`0xff`).
  All fields now use the typed work layout.

## Hard list

No M1-T1045 functions remain unresolved.

- `Unk0e1648_Unk_0e16f0`: matched in M1-T1045.
- `Unk0e1648_Unk_0e4964`: matched in M1-T1046.

## M1-T1046

All eight functions match at 100% in objdiff. Evidence is the delinked ARM
instructions and relocations; neutral names are retained. Existing source was
extended rather than replaced. No runtime tests were added because this card
requires instruction identity and checksum validation.

- `func_020e2cc8` (96 B): requires the signed word at `+0xec0` to be 1,
  and a nonzero halfword at `+0xa` of the selected record. Returns 1 when its
  `+3` flag is clear, otherwise tests whether `0f4510` rejects the work id and
  selected slot's `+2` halfword. The selected index must be valid.
- `func_020e42e4` (96 B): returns 1 for state bytes 17..19; state 20 returns
  0 for substates 4 and 16 at `+2`, and 1 otherwise. Other states return 0.
  The nested switch preserves the original branch layout.
- `func_020e2f84` (100 B): looks up each of count byte ids through `0f44a8`,
  appends nonzero results through `020e30f0` with the index narrowed to 16 bits,
  then sorts the complete slot table using the existing comparator. Caller
  supplies count readable bytes and enough slot capacity.
- `Unk0e1648_Unk_0e48a8` (100 B): rejects ids whose `0f4448` result is below 1
  or whose selector-3 lookup is nonzero. Appends the id at record `+4` and
  selector-4 result at `+6`, then increments the count. Replaced integer address
  arithmetic with the existing typed slot array; caller supplies capacity.
- `func_020e4ca4` (100 B): accepts record kind 2 at `+2`, an accepted
  `0e4c64` work/value pair, or three zero entry ids at `+0xa/+0xe/+0x12`.
- `func_020e524c` (100 B): zeroes two flag bytes and sixteen request words,
  sets word 1 to 19 and flag bit 1, and submits the stack request to
  `020bcbc4(3, request)`. The callee must consume the request during the call.
- `func_020e41d0` (104 B): multiplies signed work words `+0xc8` and `+0x98`,
  adds the product to the shared `+0x344` word with upper cap 99999999, calls
  `0fc86c`, then applies the saved `+0x98` value to the selected slot's `+4`
  id through `02099b10`. Inputs must keep signed arithmetic representable.
- `Unk0e1648_Unk_0e4964` (104 B): forwards its id explicitly to `09974c`;
  entry kinds 3/4 use selector 6, kinds 5/6 use selector 7, and other kinds
  use zero. Applies the result to channel 1 through `0204faf0`.

No M1-T1046 functions remain on the hard list.

## M1-T1047

All eight functions match at 100% in objdiff. Evidence is the delinked ARM
instructions and relocations; existing neutral names are retained. No runtime
tests are required: instruction identity is the acceptance oracle.

- `Unk0e1648_Unk_0e4f54` (124 B): divides 99 by the largest active entry
  weight (flag +3 forces weight one), then caps it through the id lookup.
  Existing matching implementation now has its missing contract comment.
- `func_020e30f0` (132 B): resolves the record through work +0xcc and the
  supplied index, rejects selector-2 matches, then appends the value byte,
  index, record id and selector-4 result. Caller supplies slot capacity.
- `func_020e28a8` (136 B): for states above one, configures three ranges,
  dispatches by the work-kind predicate, and finalises the subsystem sequence.
- `func_020e40a4` (140 B): applies visible slot ids through +0xe94 and restores
  the selected id through +0xe98. Reloads callback-visible count before cursor
  advancement, matching the load at 020e40fc; only this read is volatile.
- `func_020e52b0` (140 B): submits a synchronous request with flags 0x0a,
  values 22 and 12, then clears handle zero and two subsystems.
- `func_020e4ff8` (152 B): for selected ids 211..410, submits a synchronous
  request with flags 0x82, value 18 and the selected id.
- `func_020e2eb4` (160 B): advances the three-entry cursor to a nonzero id,
  applies its rank with mode 2 or 0, requests animation zero and returns success.
- `func_020e4130` (160 B): refreshes multi-slot state; for fewer than eight
  slots, stores twelve times the visible count, clears unused handles/flags,
  and adjusts the count when the selected cursor is outside it.

No M1-T1047 functions remain on the hard list.

## M1-T1048

Six of the eight functions match at 100% in objdiff. Evidence is the delinked ARM
instructions and relocations; the existing TU was extended in address-adjacent
blocks. No runtime tests were added because this card's oracle is instruction
identity plus the checksum gate.

- `func_020e5394` (160 B): runs the next action step. For kinds accepted by
  `func_020e544c` it first reports selector 5/6 from `+0xec0`, then checks the
  `020e2cc8` and `020e2d28` predicates and reports 18, 8 or 0; other kinds use the
  `020e3f5c` predicate and report 8 or 0.
- `func_020e4238` (172 B): for work kind 7 with selected id 211..410, submits the
  intermediate `020e524c` request and then a 0x82 request with value 18 and the
  selected id in slot 7. An out-of-range id submits only `020e524c`.
- `func_020e50e8` (176 B): applies an animation mode to one slot id. Mode 0
  calls `099bac(id)`; mode 1 calls `0e50c8(6)`; mode 2 calls `099bac(id)` then
  `0e50c8(10)` and retains the `02063a30` result; every mode except 2 also applies group 7. The captured
  result becomes the fifth argument of `02061f10(handle, -1, 0, -1, result)`.
- `func_020e1a48` (200 B): releases the nine handle words at `+0xe94..+0xeb4`,
  the 23 handles at `+0xc`, the objects at `+0x8`/`+0x4` (the latter is the
  typed union of two halfword keys and one 32-bit handle), and clears the global
  work pointer at `data_02176c80+4`.
- `func_020e3e70` (236 B): configures three sprite slots. It writes the `+0xac`
  value as the record halfword at `+0xe`, submits an 11-argument `0205e048`
  request and two 10-argument `0205de40` requests (ids 13 and 14) using the
  `+0xa8` owner and the `+0xac`/`+0xb0` values. The returned record has a
  typed halfword at `+0xe`; scale arguments are `1.0f`.
- `func_020e2fe8` (264 B): restarts the slot list. It saves the kind at `+0xcc`,
  clears the count at `+0xd0`, appends the per-kind range from the `0f3db4`
  table (50/50/50/50/100/60 ids), then resets the block at `+0x6c` when `+0xee4`
  is clear, passing `min(count, 8)` as the range start, and calls `020e3174`. The 9-entry jump table confirms cases 0..8.

## Hard list

These two are left undefined in C so the delink object links them unchanged.
Both produce nearly identical code; the remaining difference is register
allocation, not semantics, and the trials below were measured with the project
compiler (`mwccarm 2.0/sp1p5`, `-O4,p`).

- `Unk0e1648_Unk_0e32e8` (208 B): charges `+0x98 * +0xc8` to the shared accumulator,
  applies the selected slot through `0f4398`/`099a28`, then `0f4538` and clears
  `+0xee8` when `0f4510` rejects the id. Trials with the id as `u16`/`u32`, the
  record as a typed/byte/void/integer pointer, several declaration orders, and
  local flag/argument forms all put the id in r9 and the record in r6, whereas
  the ROM keeps the id in r6 and the record in r7; the function body is otherwise
  equivalent (same size and calls).
- `Unk0e1648_Unk_0e4e28` (268 B): consumes up to 99 cost passes for the selected slot,
  subtracting the three entry weights and stopping when one goes negative. Trials
  with separate/reused loop counters, `do`/`while`/`for` loop forms, declaration
  permutations, `u32`/`s32` cost arrays and a grouped cost/remaining struct all
  leave one extra `add rN, sp, #0` setup: the compiler assigns the stack cost
  array base and the remaining budget to r5/r4 instead of the ROM's r4/r6. The
  rest of the instruction stream matches after that rotation.

## M1-T1049

All eight functions match at 100% in objdiff. The source extends the existing
TU; neutral linker names are retained. Typed work fields and private lookup
records come from the delinked ARM loads/stores. No runtime tests were added:
this card explicitly uses instruction identity and checksum validation.

- `func_020e4d08` (288 B): resolves the record using work kind and the supplied
  index, rejects its id flags or insufficient unsigned shared budget, then
  accepts an exempt record or checks all three ingredient quantities against
  their weights. Indices must be valid for the lookup tables.
- `func_020e3f80` (292 B): saves the work kind and rebuilds the slot table from
  five id ranges for kind 7, or two ranges otherwise. Resets visible count to
  min(count,8), preserves/adjusts the prior cursor when the second argument is
  zero, then refreshes the visible entries. Caller supplies table capacity.
- `func_020e2930` (300 B): submits sprite 17, looks up sprite 30, computes
  `92 / (11.5 * count)`, rounds its scaled height with a minimum of two,
  and submits its scaled cursor offset. Count must be nonzero. The `+0xb4`
  submission field has two bit-preserving views (See DEC-007).
- `func_020e2774` (308 B): handles input masks 64/128/16/32 to change `+0x98`
  by one or ten, bounded by one and `+0x8c`, resetting handle 1 or 2 on a
  change. Returns whether the quantity changed.
- `func_020e3174` (372 B): refreshes each visible slot's label through `+0xe94`,
  using selector 5 for lookup result one; restores the selected id and its
  mode through `+0xe98`, then refreshes three nonempty ingredient labels.
  The selected index and visible range must address valid slots.
- `func_020e2a5c` (564 B): dispatches message types 0..4. Type 0 sets the work
  kind from flagged parameter 3; types 1/2 close or clear the work; type 3
  restores states 8/19; type 4 consumes result codes 100..102 in state 19 or
  restores the 28-byte cursor block and saved mode otherwise. Parameters use
  the same presence-bit layout as `UniteEvent.c`; the callback consumes the
  message synchronously. Its handler-table pointer now has typed parameters.
- `func_020e49cc` (664 B): dispatches by id kind and selector to return fields
  from five lookup record layouts. Returns zero for unsupported selectors;
  kinds 0/7 return one only for selector 3. Bitfield widths follow the ARM
  halfword/byte loads and shifts, including the 14-bit and 10-bit properties.
- `func_020e1730` (792 B): on substate zero, creates the owner/resource pair,
  23 object handles and nine label handles, initializes cursor and render
  fields, derives timing from handles 21/22, refreshes visible handles and
  dispatches kind-specific list setup before entering state 2. Resources and
  counts are evidenced by the two resource globals and constant loop bounds.

No M1-T1049 functions remain on the hard list. Earlier hard-list entries remain
unchanged and undefined in C, so they continue linking from the delink object.

## M1-T1050

Two of the four functions match at 100% in objdiff; the other two remain
undefined in C so the delink object still supplies them. Evidence is the
delinked ARM instructions, literal pools and relocations. No runtime tests were
added: the card's oracle is instruction identity plus the checksum gate.

- `func_020e1b10` (1664 B): top-level work state machine. State 1 calls the
  object initializer; state 2 arms the thirteen slot handles and the two extra
  handles; state 3 waits on the entry animation and branches on the kind
  predicate; state 4 releases eight visible handles and both extra handles;
  state 5 saves the 28-byte cursor block into `data_02176c88` and restores the
  saved mode byte. States 10..15 and 18..20 drive selection, the twelve-entry
  cursor table, the score submission and the final substate dispatch. The
  21-entry jump table at 020e1b24 fixes the state numbers.
- `func_020e2190` (1508 B): action state machine for states 7, 9, 16 and 17.
  State 7 consumes the 0x800/0x400/0x1/0x2 input masks, starts the selected
  record and shares the state 9/19 transition; state 16 has its own
  0x800/0x1/0x2 handling; state 9 and 17 consume the quantity cursor and finish
  with the shared score update. All state, substate and handle fields use the
  existing typed work layout.

### Hard list

- `Unk0e1648_Unk_0e33b8` (2744 B): draws the ordinary multi-slot list. The C body is
  semantically equivalent and reaches the same 686-instruction length, but
  mwcc places the loop index in r8 and the row counter in r9, while the ROM
  keeps the index in r9 and the row in r8; it also chooses r7 rather than r6
  for the work kind/base pointer. Trials with separate/scoped loop counters,
  forward/backward declarations, `while`/`for` forms, explicit row induction,
  `int`/`u32` row types, a base-slot pointer, and a hoisted `kind` local all
  left the same two register swaps. The function is therefore left undefined
  so it continues to link from the delink object.
- `func_020e4344` (1380 B): draws the kind-4 list variant. The same register
  allocation difference appears (offset in r9 instead of r6, index in r6
  instead of r7, row in r7 instead of r9), plus two extra words from the
  compiler's handling of the final threshold block. The function is left
  undefined for the same reason and is available for a decomp.me scratch
  (`tools/decompme.py`).
- `Unk0e1648_Unk_0e33b8`: hand-matched
- `Unk0e1648_Unk_0e32e8`: hand-matched
- `Unk0e1648_Unk_0e4e28`: hand-matched
