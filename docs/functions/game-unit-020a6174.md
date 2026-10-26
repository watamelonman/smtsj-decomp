# src/game/unit_020a6174.c

## M1-T872

Instruction addresses below refer to the original ARM9 image. Record indices are
unchecked and must be in 0..15; the caller owns all buffers.

- `Unk0a6174_Unk_0a6aac`: adds index times 16 to the base (0x020a6aac).
- `Unk0a6174_Unk_0a6ab4`: adds 0x100 and index times 16 (0x020a6ab4).
- `Unk0a6174_Unk_0a6a88`: returns zero for a null base, otherwise adds twice
  `Unk02f2a8_GridIndex45(x, y)` (0x020a6a88). Coordinates follow that callee's contract.
- `Unk0a6174_FindFree0c`: scans sixteen records for the first zero byte at
  record offset 0x0c, returning its index or -1 (0x020a6174).
- `Unk0a6174_FindFree10d`: same scan using offset 0x10d from the base,
  identifying the second bank's occupancy byte (0x020a61f8).
- `Unk0a6174_ClearBuffers`: clears 0xe14 and 0x200 bytes using
  `func_02008848`; either null pointer prevents both clears (0x020a69d0).
- `func_020a61a0`: rejects occupied first-bank records; otherwise sets +0x0c
  to one and writes the word, halfword, and byte fields through +0x0d.
  Returns one on insertion and zero on rejection (0x020a61a0).
- `func_020a6224`: second-bank insertion with occupancy at +0x0d and a third
  halfword at +8 (0x020a6224). See the hard list below.

## Hard list

- `func_020a6224` remains in the delinked object. A complete C insertion body
  reached 82.61%: all operations and offsets agreed, but the compiler moved the
  stack load of the +0x0a byte before the +8 halfword store, and the signed
  +0x0c byte load before the +0x0b store. Typed record layouts, volatile record
  access, and permutations of field assignments did not reproduce the original
  schedule. The unmatched body was removed; a human can open a decomp.me scratch.

The seven implemented M1-T872 functions are 100% in objdiff. The existing
`Unk0a6174_Unk_0a6548` body also remains at 100%.

## M1-T873

All eight functions below are 100% in objdiff. Names remain the original neutral
symbols because instruction evidence establishes mechanics, not game meaning.
Buffers and entry arrays are borrowed from the caller.

- `func_020a6280` (0x020a6280): rejects a null grid, coordinates rejected by
  `Unk02f2a8_IsInGrid45x40`, or a nonzero signed cell byte. Otherwise writes
  the kind and bank index into the two-byte cell and returns one; rejection
  returns zero. The grid must hold the cell selected by `GridIndex45`.
- `func_020a63cc` (0x020a63cc): sums +3 byte weights in four-byte records,
  stopping at the first zero +0 halfword key or eight entries. Selects with
  `func_02050074(1, 65535) % sum`; cumulative weight wraps at 256. Returns
  a borrowed entry or null for zero total or no cumulative match.
- `Unk0a6174_Unk_0a6548` (0x020a6548): verifies the inherited matched selector.
  All eight four-byte entries contribute their +2 byte weight, including entries
  with zero keys. Uses the same random range and wrapping cumulative byte as
  the keyed selector; returns an entry or null. Caller supplies eight entries.
- `func_020a6848` (0x020a6848): signed halfword IDs at +12/+16 enable checks
  when nonnegative. Compares each provider result from
  `Unk094fe0_Call_020950b4` with the boolean value of the following unsigned
  halfword. Both checks execute when enabled; no enabled checks returns one.
- `func_020a68b4` (0x020a68b4): applies those checks to IDs at +16/+20 and
  returns the twice-normalized conjunction. Caller supplies at least 24 bytes.
- `func_020a6934` (0x020a6934): checks the same +16/+20 pairs, requiring
  at least one nonnegative ID as well as all enabled comparisons to agree.
  Caller supplies at least 24 bytes; negative IDs cause no provider call.
- `func_020a6a08` (0x020a6a08): null grid returns immediately. Otherwise
  clears the indexed 16-byte record in bank one for kind 1 or bank two for
  kind 2, then clears the two-byte cell for every kind. Coordinates and stored
  indices must be valid; instruction evidence is the +1 index load, bank
  helper calls, and clear sizes 16 and 2.
- `func_020a7ca4` (0x020a7ca4): clears a 0xe14-byte grid and rebuilds it
  from two banks of sixteen 16-byte records. First-bank occupancy +12 uses
  coordinates +10/+11 and kind 1; second-bank occupancy +13 uses +11/+12
  and kind 2. Original loads and `func_020a6280` calls establish these fields.
  Records require 0x200 readable bytes; invalid coordinates are rejected by
  the insertion helper.

No M1-T873 functions remain on the hard list. No runtime tests were added:
this card disables that requirement and exact object comparison checks all
instructions against the original rather than adding guessed game semantics.

## Not done in M1-T875
- `func_020a7108`
- `func_020a7474`

## M1-T874

All eight functions below are 100% in objdiff. Names stay neutral because the
instructions establish mechanics, not game meaning. Records, grids, provider
tables and work buffers remain borrowed from the caller.

- `func_020a62ec` (0x020a62ec): selects a one-based outcome from two to five byte
  weights. Weights start at +0x14 for two entries and advance to +0x16, +0x19 and
  +0x1d for three, four and five; counts above five are treated as one. Uses
  `func_02050074(1, 65535) % sum` with a wrapping byte accumulator. Zero total or
  no cumulative hit returns one.
- `func_020a6468` (0x020a6468): instruction-for-instruction duplicate of the
  selector above, with the same +0x14/+0x16/+0x19/+0x1d weight tables.
- `func_020a7ae4` (0x020a7ae4): walks sixteen first-bank 16-byte records
  (occupancy +0x0c, signed provider id +4, state +0x0d). Provider entries are
  84 bytes and reached through the pointer at provider+8. Recomputes state with
  `func_020a6848`; a lost state calls `func_0204c780(record+10, record+11)` and a
  new state with word +0 == 2 calls `func_0204c698`, mapping byte +9 through
  1 -> 2, 3 -> 21, 5 -> 22. Effects require `on == 1`.
- `func_020a7bd0` (0x020a7bd0): same second-bank walk from records+0x100 using
  occupancy +0x0d, state +0x0e and 88-byte provider entries. The prior state
  chooses `func_020a68b4` or `func_020a6934`; state loss calls
  `func_0204c780(record+11, record+12)` and a new state with word +0 == 2 calls
  `func_0204c698(19, record+11, record+12)`.
- `func_020a6ac0` (0x020a6ac0): copies matching 84-byte provider entries into the
  first bank, scanning at most `min(func_0204fe18(provider+4), 256)`. Entry id is
  +0, cell coordinates +2/+3, filter byte +4 and provider state +8. State 3 is
  skipped. Region zero decrements the signed counter at grid+0xe10 (reset to 16)
  and accepts filter byte 0; other regions must match the four region bits at
  cell+4 (`>> 12`) and the filter byte. Inserts through `func_020a6848`,
  `Unk0a6174_FindFree0c`, `func_020a6280` and `func_020a61a0`.
- `func_020a6c98` (0x020a6c98): second-bank equivalent with 88-byte provider
  entries. Counts down grid+0xe12, enables entries when
  `Unk0e5fb8_Unk_0e6348(i) != 3` or byte +7 == 1, clears provider state with
  `Unk0e5fb8_Unk_0e639c(i, 0)`, and inserts using `func_020a68b4`,
  `Unk0a6174_FindFree10d`, `func_020a6280` and `func_020a6224`.
- `func_020a6e94` (0x020a6e94): rebuilds the map after clearing a five-word work
  block. Reads the rectangle at game-state+0x240 (left +8, top +9, width +0xa,
  height +0xb), count from `func_02098740(1)`, table from
  `Unk0387bc_GetEntry36(work, work-area+0x35c)`, and caps the iteration count by
  grid+0xe10. Each iteration selects a table weight with `func_020a62ec`, then an
  entry with `Unk0387bc_GetEntry32` and `func_020a63cc`, finds a free first-bank
  slot, picks a random start with `func_02050088(1, low, high)`, scans the
  rectangle cyclically through `func_020a65c4`/`func_020a6280`, and inserts with
  `func_020a61a0`. Provider entry/exit calls bracket the scan. Local declaration
  order mirrors the original register assignment, and the five-word work block is
  cleared only after the null-grid guard.
- `func_020a65c4` (0x020a65c4): placement validator. Rejects a null cell or a
  cell whose first byte is not 1; kind 1 needs flag bit 6 at cell+4 and kind 2
  needs bit 7. The radius-four diamond must be empty in the grid, the 3x3
  neighbourhood must not resolve through `Unk09a268_Unk_09c498` to a record with
  word +0x0c == 2 (overlay cells win over provider cells), and
  `func_020cafbc(x, y) == 1` vetoes placement. `opt_strength_reduction` is scoped
  off for this function to keep the original row/temporary register split; see
  DEC-021. No behaviour changes: the pragma only affects allocation.

`func_020a6224` remains on the M1-T872 hard list and is not part of this card.
The M1-T875 functions above remain out of scope; no runtime tests were added
because this card disables that requirement and exact object comparison covers
all instructions.
