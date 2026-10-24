# Work-area and packed-pair helpers

All eight functions match at 100% objdiff with the configured mwccarm compiler.
Evidence below refers to the original ARM instructions at each entry address.
The work area is borrowed from `Unk02e000_Thunk_0202e788`; none of these
functions transfers ownership. Field semantics are unknown beyond the observed
accesses, so no additional descriptive symbols are introduced.

- `Unk09727c_GetAreaS8` (0x0209727c, 92 bytes): jump-table cases 0..4
  use signed-byte loads from +0x16..+0x1a. Other indices return zero.
- `Unk09727c_GetAreaSub24` (0x020972d8, 16 bytes): adds 0x24 to the
  shared work-area pointer and returns the borrowed sub-block.
- `Unk09727c_GetAreaSub5a` (0x020972e8, 16 bytes): adds 0x5a to the
  shared work-area pointer and returns the borrowed sub-block.
- `Unk09727c_GetAreaSub48` (0x020972f8, 16 bytes): adds 0x48 to the
  shared work-area pointer and returns the borrowed sub-block.
- `Unk09727c_Unk_097308` (0x02097308, 56 bytes): obtains resource (48, 0),
  calls `func_0204fe18`, and reads the halfword table returned by
  `func_0204fde0`. Index 18 returns 100, after the resource calls. Other
  indices must designate a valid table entry; the original has no bounds check.
- `func_02097340` (0x02097340, 356 bytes): requires writable storage for
  19 packed halfwords and a valid work area. The low ten bits start with
  `Unk09727c_Unk_097308`, and the upper six bits start at zero. After
  `func_02099f7c`, entry 6 gets upper value 1 unless already 2 or 3.
  `func_0209846c` fills six temporary halfword IDs; `func_02096548`
  supplies each candidate upper value, accepted through
  `Unk02f078_IsAllowed_02f190`. Entries with upper value 5 have their low
  value halved, then capped at 50. Masks, shifts, loop bound 19 and call
  order support this description; the selectors' gameplay meaning is unknown.
  Explicit halfword masks in initialization preserve the original separate
  low-field replacement and upper-field clearing accesses.
- `Unk09727c_GetPairLo` (0x020974a4, 56 bytes): builds pairs into a
  40-byte local buffer and extracts the selected low ten bits with shifts
  by 22. Index must be 0..18; the spare halfword is not populated.
- `Unk09727c_GetPairHi` (0x020974dc, 56 bytes): builds the same local
  pairs and extracts the selected upper six bits with shifts by 16 and 26.
  Index must be 0..18.

Hard list: none.
