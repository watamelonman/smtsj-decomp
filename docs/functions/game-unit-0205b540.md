# game/unit_0205b540

All eight functions match at 100% in the objdiff report. Evidence is the
original delinked ARM instructions at the corresponding ROM addresses.
Names with unknown game-level purpose remain unchanged. Entry pointers are
borrowed; this unit maintains a stack and never frees the entries themselves.

- `Unk05b540_Clear` (0205b540, 32 bytes): clears 0xc18 bytes at
  `data_0216a730` through 02008848.
- `Unk05b540_Init` (0205b560, 56 bytes): clears state and stores the two
  initial cursors, current cursors, and base. The second cursor is b+c.
- `func_0205b598` (396 bytes): pushes an entry with two unsigned reservation
  sizes. Mode zero allows 256 entries, aligns the second cursor to 16 unless
  kind is 2, records sizes, and checks the first cursor against 02058420.
  On overflow it scans entries up to the first null and calls 02007e94.
  Alternate mode allows 64 entries, records a slot, and, when first size is
  nonzero, invokes two indirect callbacks. Their low 16-bit results are
  multiplied by eight. Bounds failures call 02007e94 and return without push.
- `func_0205b724` (156 bytes): returns null for an empty stack; otherwise pops
  and returns the borrowed entry. Mode zero subtracts the recorded sizes at
  the decremented index, or restores initial cursors when empty. Alternate
  mode passes the entry's +0x14 slot to 02058824.
- `Unk05b540_Unk_05b7c0` (16 bytes): returns the +0x400 stack count.
- `Unk05b540_Unk_05b7d0` (16 bytes): returns the +0xc14 saved base.
- `Unk05b540_GetAddr_data_0216a730` (12 bytes): returns the shared state address.
- `Unk05b540_Unk_05b7ec` (64 bytes): if 0205aa08 returns an entry, formats
  its +0x2c name with the existing format data, sets byte +0x58 to one, and
  pushes it with zero reservation sizes.

See DEC-008 for volatile access constraints. Stack layout and cursor names
reflect indexed loads/stores, not an inferred resource type. The entry's kind,
slot, name, and flag are evidenced by +0x18 comparisons, +0x14 release calls,
the 32-byte formatting call, and the +0x58 byte store respectively.

## Hard list

None.
