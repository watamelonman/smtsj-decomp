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

## Not done in M1-T874
- `func_020a7bd0`
- `func_020a62ec`
- `func_020a6468`
- `func_020a7ae4`
- `func_020a6ac0`
- `func_020a6c98`
- `func_020a6e94`
- `func_020a65c4`
- `Unk0a6174_FindFree0c`: hand-matched
- `Unk0a6174_FindFree10d`: hand-matched
- `Unk0a6174_ClearBuffers`: hand-matched
- `Unk0a6174_Unk_0a6548`: hand-matched
