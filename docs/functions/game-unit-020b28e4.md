# src/game/unit_020b28e4.c

## M1-T1037 functions

- `Unk0b28e4_Nop_0b28e4` (4 B): empty callback.
- `Unk0b28e4_Unk_0b64c8` (20 B): returns the byte pointer cached at `+0x04` plus its two-byte header.
- `func_020b6514` (20 B): stores one word at `+0xca0` of the object referenced by the word at `+0x00`.
- `Unk0b28e4_Unk_0b5e10` (28 B): sets the byte at `+0x37` and word at `+0x2c`, then forwards to `func_0205f7f4`.
- `func_020b64dc` (28 B): returns entry `index` (12 bytes each) of the table based at `+0x04`.
- `func_020b64f8` (28 B): stores two words at `+0xc8c` and `+0xc90` of the object referenced by the word at `+0x00`.
- `Unk0b28e4_Unk_0b6338` (56 B): releases the object cached at `+0x04`, clears the cache and restores callback set 13.
- `Unk0b28e4_Unk_0b6370` (68 B): zeroes the 44-byte block cached at `+0x04` (allocated by `Unk0b28e4_Unk_0b62e8`) and its two payload areas.

## M1-T1038 functions

All eight targets are 100% in objdiff. Three implementations were already present
from the dependency; this card verifies them and supplies the other five.
Names follow the protected symbol table; no new descriptive names are inferred.
Evidence below is the original ARM disassembly at each function address.

- `Unk0b28e4_GetEntry34` (72 B): returns zero for a null base or signed index
  outside 0..26; otherwise reads the word at `base + index*12 + 0x34`.
  The two explicit unsigned boolean temporaries preserve the original range tests.
- `Unk0b28e4_InitCallbacks` (76 B): writes size `0xcac`, clears slots 1, 5,
  and 6, and sets callback slots 3, 4, 7, and 8. Slot 2 remains untouched.
  The four stored function addresses support the existing callback name.
- `Unk0b28e4_Unk_0b62e8` (80 B): calls `func_020552ec(6, 3)`, allocates
  44 bytes and initializes the cached block only when absent, then calls
  `Unk0bc1a8_Unk_0bc928(13, 0xffff, 0)`.
- `func_020b3d28` (156 B): frees work pointers at `+4`, `+0x24`, `+0x28`,
  and `+0x2c`; releases and conditionally clears handles at `+0xc30` and
  `+0xc34`; selects bank 1 before releasing each of three pointers in both
  arrays at `+0xc54` and `+0xc60`.
- `func_020b4fb4` (188 B): scans signed ids at roster `+0x348`, bounded by
  the byte at `+0x357` and terminated by negative ids. Calls `func_02044ec4`
  for each id, then selects records whose indexed `+0x36c` word has byte 2
  equal to 1. Counts qualifying entries, skips `work->unk_0c6c * 3`, and
  forwards up to three to `func_020b5adc`. Record stride is `0x2e0`.
- `func_020b3570` (204 B): while flags at `+0xca4` / `+0xca8` are set,
  tests masks `0x200` / `0x100`. A successful first test dispatches
  `func_0203e93c(1, 128, 96, work+0x10, work+0x1b0/0x210)`;
  otherwise a successful second test clears the corresponding flag.
- `func_020b5264` (212 B): uses the same roster bounds and paging as
  `func_020b4fb4`, additionally requiring `func_0204a244` to return 1
  for the record returned by `func_02044ec4`.
- `func_020b5e2c` (220 B): formats two paths using `data_0214ff94` and
  `data_0214ffc0` into separate 50-byte stack buffers. Loads the first,
  copies its two 32-byte entries into consecutive slots (second slot masked
  to 8 bits), and frees it. Loads the second, adds `(slot << 4) & 255` to
  each nonzero signed byte in its 512-byte payload, uploads with constants
  `(1, data, 4, 32, 16)`, frees the payload, and returns the upload result.

Matching trials: the initial roster loops tested the roster bound at the loop
footer, producing eight extra bytes. Moving that bound to an early return
inside the three-slot loop matches the original branch structure. Declaring
the first path buffer before the second reproduces the original stack offsets.
All new bodies use typed fields; padding and array bounds describe observed
accesses, without assigning unsupported gameplay meanings.

Hard list for M1-T1038: none.

## M1-T1039 functions

Seven implementations are 100% in the full objdiff report. Names remain those
in the protected symbol table; comments describe observed operations rather
than inferring gameplay purposes. Evidence is ARM disassembly at each address.

- `func_020b6104` (236 B): formats two resource paths into 40-byte buffers,
  copies one 32-byte palette entry, expands 128 signed packed bytes into 256
  caller-owned bytes (low nibble first), offsets nonzero indices by slot*16,
  uploads a 16-by-16 resource, and frees the packed source.
- `func_020b61f0` (248 B): the corresponding conversion into a caller-owned
  256-byte buffer, cleared first; updates an existing target through
  `func_02056d88` after freeing the packed source.
- `func_020b5ccc` (324 B): draws decimal digits using 96-byte entries 10..19;
  values above 999 use entry 20 three times. Byte coordinates wrap, alignment
  controls the initial horizontal position, and digit spacing is five.
- `func_020b593c` (416 B): checks the first header's type byte at +0x8c,
  draws its resource, three numeric fields, and a marker for states 1..11.
- `func_020b5adc` (496 B): draws the indexed type-1 record in a 56-pixel row,
  including three numeric fields, an optional secondary marker, and the
  state-1..11 marker. Resource arrays start at +0xc3c and +0xc48.
- `func_020b4dd8` (476 B): scans the roster for type-1 entries with three-slot
  paging, records displayed ids at +0xc78, clears rows beyond the roster or
  negative sentinel, and draws resource 4's label centered using its width.
- `func_020b49cc` (492 B): maps page and slot to roster positions, reserves
  the first row of page 1 for `func_020b5338`, clears unavailable or non-type-1
  rows, records displayed ids, and draws resource 2's centered label.
- `func_020b63b4` (276 B): remains in the delinked original. It scans six
  type-2 records at stride 0x2e0 beginning with the word at +0x25ec, rejects
  duplicate +0x1d8 halfword ids, and copies 12-byte payloads to the cache.
  Capacity is checked once at entry against three, as in the original.

Matching trials: signed packed bytes and arithmetic `i >> 1` reproduce the
nibble conversion; signed division by two emits an unwanted correction.
Declaration order controls local register assignment. Explicit unsigned-byte
coordinates reproduce wrapping. The two roster routines clear out-of-range
rows rather than terminating immediately. Their first label clear starts at
x=64 (the second at x=128), as evidenced by the argument registers.

### Hard list for M1-T1039

- `func_020b63b4` (276 B): not matched; the function remains in the delinked
  original and no nonmatching body is retained. Best attempt was 98.84%
  (276 B) and differed only in register allocation. The original's duplicate-id
  loop keeps the cache pointer in r3, the saved count in r12, the index in r1
  and the id in r2, and reloads the count byte for the signed back-edge test.
  Its 12-byte payload copy counts down six 2-byte pieces in r3 while the
  destination stays in r12.
  Trials: typed cache fields; 12-byte struct assignment; source/destination
  pointer locals; declaration and assignment reordering; `for`, `while` and
  `do`/`while` loop forms; saved-count locals; local vs global cache pointer
  expressions; `u8`/`u16`/`u32` copy counters; 2-byte struct pair copies;
  explicit two-byte copy loops; and a `volatile` count read in the loop bound.
  The `volatile` form reproduced the missing back-edge reload, but mwcc then
  assigned cache/count/id to r1/r2/r3 instead of r3/r12/r1/r2, and the
  copy counter moved to r12 instead of r3. Other forms reproduced the
  register roles but folded the back-edge load into the saved count. Overall
  sizes were 260, 272 and 276 bytes; all instruction sequences were otherwise
  equivalent to the original. A human can use `tools/decompme.py` to open a
  scratch for this function.

## M1-T1040 functions

Four implementations are 100% in the objdiff report. Names remain those in the
protected symbol table; the comments describe observed operations. Evidence is
the ARM disassembly at each address.

- `func_020b32bc` (692 B): state dispatcher for callback-table slot +0xc. The
  switch on `work->unk_0000` (0..5) rebuilds or draws the page for states 1..5
  through `func_020b4674`, `func_020b49cc`/`func_020b4bb8`,
  `func_020b4dd8`/`func_020b4fb4`, `func_020b5070`/`func_020b5264`, with the
  page-rebuild flag at +0xc70 and the defer flag at +0xc74. The shared tail
  draws the status bar resources at entry indices 2, 3 and 9 when the +0xc6d
  counter is greater than one and +0xca0 is clear.
- `func_020b4674` (856 B): draws `work->unk_0c38` record rows. Each row draws
  its icon handle, the record's numbers (`func_020b5ccc`) or its flag-selected
  variant, and clears the state-5 page icons through `func_0202122c`.
- `func_020b5070` (500 B): draws the `work->unk_0c6c` page of type-1 roster
  entries. It skips `page*3` qualifying entries, forwards up to three to
  `func_020b5634`, records their ids at +0xc78, clears rows past the roster end
  or a negative id, and centres the resource-3 label using its width.
- `func_020b5338` (764 B): draws the reserved first page-1 row for the fixed
  first record: two background strips, the pc001 icon pair, two labels, the
  record bar (`func_020b3dc4`), the three category entries and eight command
  buttons. The button value at index 6 is forced to 1 when it is 0 or 5.

The draw-resource block at +0x30..+0xc2f is now a 32-entry array of 96-byte
entries (`Unk0b28e4Entry96`); every access through it is one of the observed
indices. The repeated `(page + 22) * 96` and `(page + 21) * 96` index formulas,
plus the older +0x01b0/+0x0210/+0x02d0 accesses, are congruent to 0x30 modulo
0x60. See DEC-004.

Matching trials: the dispatch switch needs an explicit `case 0: break;` to
reproduce the six-entry jump table; states 1 and 5 are separate bodies even
though they share a shape. Loop-local `u8` coordinates reproduce the byte
wrapping, and multiplier/increment order controls whether the compiler keeps
the row or the column counter in memory. `func_020b5338`'s grid uses a running
count of *drawn* entries (not the loop indices) for its position; its
category lookup compares through a local `u16` to reproduce the original
operand order. The record fields come from `func_020a1740`, whose +0, +2, +4,
+8 and +0x16 members are the only ones this TU reads.

### Hard list for M1-T1040

These four functions remain in the delinked original and no nonmatching body is
retained. Each is within a few instructions; the residue is register or stack
assignment, not a behavioural difference.

- `func_020b3dc4` (636 B): two-part progress bar. It scales the record count
  and the two +0x5a/+0x5b thresholds by 6/10 in 12-bit fixed point, then draws
  a filled part, a remainder and the overflow remainder. Best attempt was
  636 B with identical instructions except the prologue: mwcc keeps the first
  length (`filled`) in a callee-saved register and spills the second (`rest`)
  to a sixth outgoing-looking word, so the frame is 24 bytes with `r3` pushed
  instead of the original 20 bytes. The original reuses the fifth outgoing
  argument slot for `filled` and keeps `rest` in the register freed by the
  record pointer. Trials: `s16`/`u16` combinations for both length locals,
  assignment before/after the draw call, passing the local versus a
  recomputed cast as the ninth argument, `volatile` storage, and every
  declaration order. A human can open a scratch with `tools/decompme.py`.
- `func_020b4bb8` (544 B): per-slot redraw of the three rows after the page.
  It copies two 12-byte icon-id tables at entry and copies the selected table
  again inside each branch before indexing it by the record state. All
  behaviour matches at 552 B; the original keeps all four 12-byte stack
  copies, while mwcc 2.0/sp1p5 propagates the entry copies into the branch
  locals and emits only two. Trials: address-taken source pointers, `volatile`
  destination, `memcpy` (not inlined), assignment instead of initialization,
  declaration reordering, and every toolchain 1.2/2.0/dsi release in
  `tools/mwccarm` (all propagate). The remaining 8 bytes are the two missing
  copy loops.
- `func_020b5634` (776 B): one roster row, including background, icon, labels,
  bar, category grid and eight command buttons. Best attempt was 780 B; the
  only residue is register rotation in the grid and button loops (`col`/`x`
  one register lower than the original) plus one hoisted `y & 255` mask.
  Trials: per-row `u8 y` local, inline masked/unmasked coordinates, removing
  the unused counter and label locals, declaration permutations, and template
  order. The instruction sequence and structure are otherwise identical.
- `func_020b5f08` (508 B): builds the two icon resource paths, optionally dims
  the 32 BGR555 palette entries, copies two 32-byte entries, offsets the
  512-byte colour page and uploads it. Best attempt was 476 B. The original
  divides each 5-bit channel by 3 with a `smull` followed by `adds; movmi`
  that clears negative quotients; mwcc emits that guarded sequence only when
  it cannot prove the dividend non-negative, while the masked channel is
  provably in 0..31. Trials: every integer width for the channels, inline and
  local forms, explicit clamps and ternaries (only one of three survives
  optimisation), fixed-point and multiply/divide rewrites, all optimisation
  levels and all compiler releases. The guard is dead code for the observed
  range, but it is required for a byte match. A human can open a scratch with
  `tools/decompme.py`.


## M1-T1041 functions

The retained C implementations below each report 100% in objdiff. Their typed
work pointer is borrowed; initialization owns the resource buffers until
`func_020b3d28` releases them. Names remain the protected symbol-table names.
Evidence for their contracts is the original ARM instructions at each address.

- `func_020b28e8` (1180 B, 100%): initializes work flags, page counts and
  selection state, caches the global work pointer, loads six resource paths,
  prepares 32 draw entries and seven palette entries, and allocates three
  pairs of 256/512-byte icon buffers. The active-context branch initializes
  the background buffer and its two handles. The three byte fields written by
  the draw-entry loop (+0x5a..+0x5d within each entry) are named in
  `Unk0b28e4Entry96`; the loop itself uses the `Unk0b28e4EntryFlags` overlay
  explained in DEC-004 because that is the only form whose address arithmetic
  matches.
- `func_020b2dd0` (1260 B, 100%): handles borrowed callback events of kinds
  1, 3 and 4. Each optional payload word has a presence bit in the first two
  bytes. Event values select states 1..5, set rebuild/defer flags, update
  page counts and scan displayed roster ids. State 5 advances the cached
  six-byte selection cursor; its three flags are represented as bitfields.
  The one-element `value` array exists to force the stack slot the original
  writes through.
- `func_020b363c` (1772 B, 100%): processes page and row input after the
  rebuild/defer flags clear. Input masks 0x40/0x80 select rows, 0x100/0x200
  select pages, and 1/2 accept or cancel. Selection paths validate roster
  records and construct callback-13 requests with optional-word flags. The
  two accept paths and the cancel path repeat the page-restart sequence
  deliberately: a helper changes register allocation and loses the match.

Matching details in the retained attempt: initialization uses explicit byte
casts for palette slots and icon indices; event payload reads are inline and
preserve presence-bit tests; request clearing uses separate loops for two
flag bytes and sixteen words. The draw-entry loop keeps its `work + i*96`
anchored overlay; replacing it with `&work->unk_0030[i]` compiles to a
different loop prologue and drops `func_020b28e8` to 99%, so DEC-004 records
the constraint. The three bodies were re-verified with `tools/hand/cmp.py`
after these edits.

### Hard list for M1-T1041

- `func_020b4040` (1588 B): a full C candidate was written and iterated with
  `tools/hand/cmp.py` and `tools/hand/gatecheck.py` this attempt. Best measured
  result was **96.05%** for a 1584-byte candidate (396 instructions versus the
  original 397). The decisive change was giving `Unk0b28e4_Unk_0b5e10` a
  `void *` label argument: with the existing `u32` argument, mwcc hoists the
  label-array address into a callee-saved register and spills the row counter;
  with an escaping pointer it rematerializes the stack address like the
  original. That signature change left every other function in the unit at
  100% in the gatecheck report. Secondary fixes were `func_020b64dc(i)` (not
  `list[i]`), `col <= 7` for the button loops, and recomputing the direct-layout
  label position from `i`. An otherwise identical variant that passes the
  halfword directly scored 95.91%; the earlier hoisting version scored 88.42%.
  None is merged, so the function still links from the delink.

  Established contract: the function draws the three `func_020b64c8()` roster
  rows, using `func_020a1740`/`func_020a1428` per id, `func_020b5f08` for the
  icon, `func_0204fed8` for the two labels, `func_020b3dc4` for the bar and
  `func_020b5e10` for the category/button grids. It clears `work->unk_0c78`,
  draws an empty row for a zero id, selects between the direct-id and digit
  layouts through `Unk0a163c_Unk_0a17d8`, switches the category source at
  `record->unk_5b`, and finally draws the status label and returns 3 for
  `work->unk_0c38`. The stack copies of `data_0213c468` (8 B) and
  `data_0213c4a0` (16 B) are reproduced exactly by struct assignment.

  Specific mismatches in the 96.05% candidate:
  - The original materialises the `func_020dd364` argument through a 16-bit
    scratch at `sp-4` (`sub r8, sp, #4; strh [r8]; ldr [r8]`). Every typed
    form tried allocates a normal in-frame slot; the candidate keeps it at
    `sp+52`, so the frame is 80 bytes instead of 76 and the label arrays sit
    at +54/+62 instead of +52/+60.
  - The direct-layout label position: the original recomputes `i*56`
    (`mov/mul/add`) and masks the result again at each of the two calls; the
    candidate reuses the `y` local (`add`) and masks once.
  - The second-variant category/button loops rotate constants through
    different saved registers (original r7=16, r6=7, r5=row base,
    r8=table+row*6; candidate r6=16, r5=7, r8=row base, r7=table+row*6).
  - The two row-base temporaries land at +44/+48 instead of +24/+28, which
    moves table/record/list/resource slots to +24/+28/+32/+36/+40.
  The last three items are the residue after the stack offsets; the behaviour
  and call order already match.

  Variants tried: struct assignment versus `memcpy` for both label arrays
  (assignment matches the copy loop exactly); `u16[4]`/`u16[8]`,
  `u16[12]`, and a single struct containing both arrays; `volatile` arrays;
  pointer locals per region; declaration-order permutations; function-scope
  versus loop-scope `u8 row`/`col` and both declaration orders; explicit
  `base1`/`base2` locals in several declaration positions; reusing the dead
  `base1` slot for the `func_020dd364` halfword; `int` versus `u32 i`;
  `u8`, `u32`, `union`, `u16[1]`, `u16[2]`, compound-literal, by-value-union
  and `*(u32 *)&record->unk_22[col]` forms for the `func_020dd364` argument;
  `u32` versus `void *` for the `Unk0b28e4_Unk_0b5e10` label argument; and all
  mwcc 2.0 service packs plus the 1.2 releases (1.2 produces a 164-byte
  frame, far from the original). A human can open a scratch with
  `tools/decompme.py`; the original delink remains linked.
