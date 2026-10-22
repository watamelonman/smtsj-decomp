# src/game/unit_0209a268.c

- `Unk09a268_Nop_09b3c8` (4 B): empty callback
- `func_0209a48c` (20 B): bit test. Returns 1 when bit `bit` of the byte at `p` is set, else 0;
  callers use bits 0-2 as a 3-value state selector and bits 3-5 as flags.
- `Unk09a268_Unk_09a7fc` (16 B): decompiler-derived (Ghidra output, cleaned)
- `Unk09a268_Unk_09a820` (16 B): decompiler-derived (Ghidra output, cleaned)
- `Unk09a268_Unk_09c498` (16 B): decompiler-derived (Ghidra output, cleaned)
- `Unk09a268_Unk_09a80c` (20 B): decompiler-derived (Ghidra output, cleaned)
- `Unk09a268_Unk_09a830` (20 B): decompiler-derived (Ghidra output, cleaned)
- `Unk09a268_Unk_09a870` (20 B): decompiler-derived (Ghidra output, cleaned)

## M1-T1010
- `Unk09a268_Unk_09c484` (20 B): returns the address of record `arg0` (stride 0x1c) in table
  `data_0213be64`.
- `Unk09a268_SetCtxUnk38` (24 B): stores its argument at +0x38 of the global context when present.
- `func_0209b720` (28 B): returns the global context's +0x34 word, or 0 when it is null.
- `Unk09a268_SetCtxUnk2c30` (32 B): stores two arguments at +0x2c and +0x30 of the global context
  when present.
- `Unk09a268_IsType1` (32 B): returns 1 when the pointer is non-null and its first byte is 1.
- `Unk09a268_SetBit` (36 B): sets or clears bit `bit` of the byte at `p` depending on `on`.
- `Unk09a268_Unk_09a844` (44 B): returns bit 5 of the state byte when GameState body +0x3e0 is
  nonzero, otherwise 1.
- `Unk09a268_Unk_09b3cc` (44 B): reloads the palette from the work's +0xc field when +0x2c is 0.

## Hard list
- `func_0209a4fc` (64 B): not implemented in C. The original scans 128 records
  (24-byte stride) at work +0x24a4, compares each +8 word to the supplied ID,
  and calls `func_02058a1c(table, index)` for every match. Indexed struct, explicit
  cursor, byte/word addressing, split-base, integer-address and embedded-table
  formulations were compiled with mwccarm 2.0/sp1p5. The closest builds were
  68 B: they retain the full table address and emit an extra register move;
  the original retains work +0xa4 and adds 0x2400 at the call. Leave the delinked
  implementation in place; a human can use `tools/decompme.py` for a scratch.

## M1-T1011
- `Unk09a268_Unk_09bb38` (48 B): returns 1 when slots 0 and 9 are both empty,
  using the two `Unk0bc1a8_IsSlotEmpty` calls. Verified 100%.
- `Unk09a268_Unk_09a458` (52 B): forwards the index from `func_0209a3ec`
  to `func_02058b14`, with the table at work +0x24a4. Verified 100%.
- `Unk09a268_FindEntry` (56 B): scans the 128 records for the first pair of
  matching +8/+16 words; returns the index or -1. Verified 100%.
- `Unk09a268_Unk_09c4a8` (56 B): null handle returns 0; otherwise looks up an
  entry, maps its first byte through `func_0209bb68` (or uses index 0 when
  absent), then returns that 0x1c-byte table record. Verified 100%.
- `func_0209a4fc` (64 B): unmatched; see the hard list above.
- `Unk09a268_Unk_09a77c` (64 B): tests bits 0-2 and returns the first set
  index, defaulting to 0 when none is set. Verified 100%.
- `Unk09a268_SetOnlyBit` (64 B): selects one of bits 0-2 using `SetBit`,
  preserving bits 3-7; values outside 0-2 clear all three. Verified 100%.
- `func_0209c4e0` (72 B): nullable record classifier. Its original jump table
  returns 1 for first-byte values 1, 3, 4, 5 and 6, otherwise 0. Grouping shared
  switch cases reproduces the original jump targets. Verified 100%.
- No new descriptive names were introduced; unknown record semantics remain neutral.

## M1-T1012
- `Unk09a268_Unk_09a3a0` (76 B): returns the first record whose +8/+16 words
  match both arguments, forwarded to `func_02058af8` by index; returns 1 when
  the 128-record table has no match. Verified 100%.
- `func_0209a53c` (76 B): scans the 128 records for the +8 word equal to the
  argument and returns the s32 pointed to by the record's first word,
  arithmetically shifted right by 12, or 0 when
  no record matches. Verified 100%.
- `func_0209a3ec` (108 B): allocates a free 128-record slot through
  `func_02058a64`, fills it from the four arguments plus a byte through
  `func_02058944`, and returns the index (or -1 when the table is full).
  Verified 100%.
- `func_0209a970` (144 B): classifies a position from the work area's +0x364/
  +0x365 coordinates. The (first argument - 30) jump table selects a distance
  limit of 0, 1 or 2, and a Manhattan distance at or below that limit returns
  2, otherwise 0. Verified 100%.
- `Unk09a268_Unk_09ae60` (92 B): fills the 60-byte handler table's size, zero
  word and six callbacks. Verified 100%.
- `Unk09a268_Unk_09beb0` (80 B): returns byte +0x1B of the record selected for
  the two arguments, or 0 when that record is absent. Verified 100%.
- `func_0209be20` (144 B): returns byte +0x1A of the record selected for the
  two arguments; kinds 20 and 23 are served by `Unk1122bc_Unk_112460` and
  `Unk1124f0_Unk_1125ac` instead, and an absent record returns 0. Verified 100%.
- `Unk09a268_Unk_09cb10` (88 B): sets bit 3, clears bit 4, selects
  the state bit from record 5 byte +0x19, then writes current-cell byte +1 = 1
  and halfword +2 = 0, and runs `func_0209c548` on its argument. Verified 100%.

## M1-T1013
- `func_0209a588` (176 B): removes an id's entries through `0209a4fc`, then
  inserts variants 0, 1 and 2 through `Unk09a268_Unk_09a458`. Each argument
  equal to -1 is omitted; the third argument is a signed byte. Verified 100%.
- `func_0209c768` (236 B): increments the work and current-cell counters.
  Phase 0 waits until the work counter exceeds 40, clears cell bit 5 and
  sets owner words +20/+24 to 2. Phase 1 waits for owner word +20 = 1 and
  sets both words to 2 again. Phase 2 completes at owner state 1; other
  phases complete immediately. Verified 100%.
- `func_0209cb68` (144 B): dispatches signed transition kind 0/1/other to
  `0209c768`/`0209c854`/`0209c9bc`. On result 1 it calls record lookup 5,
  clears current-cell bits 3-5 and state bits 0-2, and zeros byte +1 and
  halfword +2. Verified 100%.
- `func_0209cd24` and `func_0209cf54` (268 B each): identical transition
  dispatchers; kind -1 completes immediately. After handler completion,
  record lookup at work +996 uses signed coordinates +0x7482/+0x7483.
  A type-1 record clears the cell as above; otherwise bits 3/4 are set,
  bit 5 and state bits are cleared, byte +1 becomes 2, and halfword +2
  becomes 0. Verified 100% for both. Keeping counter stores in their
  respective branches reproduces the original shared instruction suffix.
- `func_0209c090` (272 B): returns the inverse of a directional map-entry
  test, including true for an absent entry. Kind 16 maps directions 0-3
  to masks 2/4/1/8 and tests element 7's low nibble unless the selected
  map two-bit field equals 3. Other kinds delegate to `0209bd08`.
  Verified 100%.
- `func_0209aebc` (272 B): callback handling message types 0, 1 and 2.
  Type 0 calls mode setter `020525cc(0)` when payload +16 is absent or
  zero, then copies flagged payload +20 to work +52. Type 1 forwards the
  work to `Unk0bc1a8_Unk_0bc504(work, 0)`. Type 2 sets work +40 from
  message +16 == 1, clears +44/+48, then sets both when flagged payload
  +16 equals 1. Types 3/4 and out-of-range types do nothing. Verified 100%.
- Names remain neutral because the underlying transition meanings are unknown.

### M1-T1013 hard list
- `func_0209a884` (236 B): left undefined in C, retaining the delinked
  original. Reconstruction cleared 7200 bytes and visited a 45-by-40 grid,
  obtaining counts from `0209c1a0`. Positive counts filled cell byte +1,
  set bits 3/4 and selected state bits from record +25; count -1 marked
  the source record's first byte as 1. The candidate compiled to the exact
  original size but reached only 98.05% objdiff: target uses r6/r7/r8 for
  row/column/cell, whereas the candidate uses r8/r6/r7. Tried declaration
  order, narrower and unsigned coordinates, pointer/address forms, nested
  declaration scopes, register hints and for/while/do loop forms; no exact
  match. A human can use `tools/decompme.py` for further register-allocation
  investigation. No nonmatching implementation was retained.

## Not done in M1-T1016
- `func_0209c548`
- `func_0209aa00`
- `func_0209c1a0`

## M1-T1014
- `func_0209a268` (312 B): adds the seven fixed-size byte arrays of the second
  work block into the first, then copies the 162-byte block at +0xa84 between
  them through `func_02008904`. Verified 100%.
- `func_0209a638` (324 B): removes an id's entries, looks up the four-byte
  record for `index`, and re-inserts each of the three variants that is not -1.
  When the caller's check flag is set it verifies variants 0-2 through
  `Unk09a268_Unk_09a3a0` and clears the result on failure. Verified 100%.
- `func_0209b5d8` (328 B): work teardown callback. Releases the seven resource
  slots with the paired free calls, resets the shared engine state, re-arms the
  seven scan-visor paths, then clears `data_02176270`. Verified 100%.
- `func_0209bd08` (280 B): maps a cell kind and direction to the accepted
  direction mask via the original 41-entry jump table (kinds 3/8-12/14/23-28/37
  pass the mask, 4-7 filter by direction 0/2/3/1, 13/36 invert `mask == 1`,
  everything else is 0). Verified 100%.
- `func_0209c854` (360 B): kind-1 transition handler. Phase 0 waits 40 ticks,
  clears the cell flag and enters owner state 2; phase 1 waits 10 ticks and steps
  the work-area position by one cell according to the work-area kind 0-3 before
  notifying `02034b7c`; phase 2 completes on a non-zero +0x7440 word. Verified
  100%. The work-area kind field is volatile because the original re-reads it
  after the engine calls; that keeps both reads.
- `func_0209c9bc` (340 B): kind-2 transition handler. Phase 0 waits 40 ticks and
  enters owner state 2; phase 1 waits for owner state 1, clears owner +0xc and
  enters state 2; phase 2 waits for owner state 1, and once mode 13 matches,
  raises +0x73e0, clears owner +4, sets +0x757c to 4 and re-arms the seven
  scan-visor slots. Verified 100%.

### M1-T1014 hard list
- `func_0209cbf8` (300 B) and `func_0209ce30` (292 B): not implemented in C.
  Both are the same 0x1c-record map test as `0209c090` but with element 7
  (word field, cbf8) or element 8 (byte field, ce30): they look up the map entry,
  read the two-bit field at the record's +25 byte, and on a value other than 3
  store -1 at work +0x7480; otherwise they fetch record 5 and the current cell,
  classify the record type, set the cell kind to 1 (type 1) or 3, zero the cell
  counter and call `0209c548`. The candidates reproduce every instruction except
  the register assignment of the two pointer locals: the target keeps record 5
  in r6 and the current cell in r5, while mwccarm 2.0/sp1p5 consistently assigns
  record 5 to r5 and the cell to r6. Declaration order, declaration scope,
  pointer/scalar types, nested calls, const qualification and evaluation order
  were tried; the branch/layout otherwise matches. A human can use
  `tools/decompme.py` for a scratch (register allocation only).

- `Unk09a268_Unk_09beb0`: hand-matched
- `Unk09a268_SetCtxUnk38`: hand-matched
- `Unk09a268_Unk_09a3a0`: hand-matched
- `Unk09a268_Unk_09a458`: hand-matched
- `Unk09a268_SetBit`: hand-matched
- `Unk09a268_FindEntry`: hand-matched
- `Unk09a268_Unk_09a77c`: hand-matched
- `Unk09a268_SetOnlyBit`: hand-matched
- `Unk09a268_SetCtxUnk2c30`: hand-matched
- `Unk09a268_Unk_09c4a8`: hand-matched
- `Unk09a268_IsType1`: hand-matched
- `Unk09a268_Unk_09ae60`: hand-matched

## M1-T1010 review corrections
- `Unk09a268_SetBit` now accepts `u8 *` with a full forward prototype; existing
  integer-address callers convert explicitly at the call boundary.
- `Unk09a268_Unk_09a844` uses a typed partial GameState body layout for +0x3e0
  and returns the bit-test result directly. `include/GameState.h` represents the
  body as opaque bytes, so the accessed body field is described locally.
- `Unk09a268_Unk_09c484` has a full index prototype. Its exceptional index-free
  call in `Unk09a268_Unk_09c498` preserves the original ABI (see DEC-002).
- All eight card functions and all 26 defined functions retain 100% objdiff matches.

- M1-T1012 review: work-area +0x35c/+0x364/+0x365 and table-record byte
  accesses now use typed partial layouts; the entry lookup shares a local base.

## M1-T1015
- `func_0209bb68` (416 B): maps encoded cell values 0-40 to record kinds 0-28,
  grouping directional variants through the original jump table. Other values
  return 0. Verified byte-identical and 100% objdiff.
- `func_0209bf00` (400 B): tests the entry at the supplied coordinates against
  direction/mask. Kind 9 uses element 3's low nibble with direction masks
  2/4/1/8 and requires mask 0. Kinds 16/17 require mask 1 and test the packed
  map field indexed by element 7's second byte / element 8's first byte for 3.
  Other kinds delegate to `0209bd08`. Verified byte-identical and 100% objdiff.
- `func_0209b960` (472 B): resets slots 0/2/1/3/10, sends the flagged setup
  messages, and sets message word 1 to 1 for slots 3/10. Verified byte-identical
  and 100% objdiff.
- `func_0209b774` (492 B): similar slot setup, forwarding the argument as
  flagged word 4 for slot 0, then calling `020e7f44(0,14,9,12)` between the
  final slot-3 and slot-10 messages. Verified byte-identical and 100% objdiff.
- `func_0209b1d4` (500 B): callback state 0 waits for the engine transition
  and starts three resources; state 2 updates four resources unless disabled,
  sends flagged word-7 messages at counters 0/5, starts the fourth resource at
  counter 10 and increments the counter. State 14 waits for the transition,
  restores state from work +8 and calls `020525cc(0)`. Verified byte-identical
  and 100% objdiff.
- `func_0209afcc` (520 B): initialization callback for the 60-byte work object.
  Registers the global context, clears state, loads the three referenced assets,
  allocates/configures four resources, and arms fixed engine paths. Resource
  purposes remain unknown. Verified byte-identical and 100% objdiff.
- `func_0209b3f8` (480 B): drawing callback. Conditionally loads the palette,
  draws four resources, and adds two formatted overlays using the referenced
  strings, flag 0x701 and work +56. Verified byte-identical and 100% objdiff.
- Existing symbol names are retained because `config/arm9/symbols.txt` is
  human-owned. The new signatures describe observed fields and call arguments.

### M1-T1015 hard list
- `func_0209aca0` (448 B): left undefined in C, retaining the delinked original.
  The reconstruction visits the clipped seven-by-seven area around (x,y),
  bounded by x=0..44 and y=0..39, for encoded kinds 30/33/31/34. Cell kind 1
  transitions to kind 2 with flags 3/4 set, flag 5 and state bits cleared, and
  counter zero when `09a844` returns 1; otherwise its counter increments.
  Cell kind 3 clears all those flags, kind and counter when the predicate
  returns 1, otherwise increments its counter. Null handles and a false
  `1124a0` predicate return immediately; record lookup 20 precedes traversal.
  The first candidate reached 98.35% objdiff. Tried separate/reused bounds
  and loop variables, bound-evaluation order, declaration permutations,
  scope changes, initializers, register hints and signed/unsigned locals.
  The closest 448-byte candidate reproduces every instruction except three
  register operands: the original preserves incoming x in r5 for computing
  the two bounds, while the candidate preserves it in r9 and later reuses
  r9 as the column counter. Keeping a separate column local instead swaps
  the row/column registers throughout the loop. No differing C body is
  retained. A human can use `tools/decompme.py` for a register-allocation
  scratch; no upload was made.


## M1-T1016
- `func_0209c548` (544 B): sets owner +0x5c, forwards work +0x58 and
  +0xa4 to the setup helpers, and chooses the adjacent cell using direction
  0/1/2/3 (north/east/south/west). The engine predicate loop either arms
  transition kind 2 or advances until its predicate clears. Otherwise, compares
  current/adjacent entry word +4 nibbles at bits 12, 16 and 20 to arm kind 1
  and its +0x748c/+0x7490 flags. The middle nibble indexes signed bytes at
  work +0x34 and consults `0e63c8`. Typed partial layouts and packed fields
  preserve the observed access widths. Verified 100% objdiff.
- `func_0209aa00` (672 B): when `1124a0` permits, visits the clipped
  seven-by-seven neighborhood within x=0..44, y=0..39. Encoded kinds 30/33
  use Manhattan radius 1; 31/34 use radius 2. Inside the radius, cell kinds
  0/3 become 1; outside it, kinds 1/2 become 3. Both transitions set flag 3,
  clear flags 4/5, select record 20's state bits and clear the counter.
  Body +0x50 supplies the notification for 30/31, +0x52 for 33/34; only the
  first nonnegative notification is sent. The guarded inner loop computes
  row distance once, after checking that the column range is nonempty.
  Verified 100% objdiff.
- `func_0209c1a0` (740 B): returns zero for null handles, absent entries and
  unsupported mapped kinds; dispatches other kinds to their state predicates.
  Kind 3 tests element 0 byte +26 as a flag. Kinds 16/17 test packed two-bit
  flags for 3, then return -1 or 2 from the located cell classifier. Kind 19
  tries the three current-area predicates in order. Kinds 20/22 delegate to
  `09a970`; kind 23 doubles the packed two-bit flag selected by element 11.
  Verified 100% objdiff. Existing symbols remain because the symbol config
  is human-owned; the comments describe only behavior supported by accesses
  and calls, without assigning inferred gameplay names.

### M1-T1016 hard list
None.
- `func_0209cbf8`: hand-matched
- `func_0209ce30`: hand-matched
