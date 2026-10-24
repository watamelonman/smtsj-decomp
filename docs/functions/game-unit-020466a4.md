# src/game/unit_020466a4.c

Both functions match the original ARM instructions and retain their configured names.
Names remain neutral because the instruction evidence establishes record operations,
but does not establish their broader gameplay purpose.

- `Unk0466a4_Unk_0466a4` (0x020466a4, 68 bytes): refreshes the current-item context,
  peeks the current record, and writes status 2 when absent or status 3 when
  `func_020f8098` rejects its key. Otherwise preserves the caller's status. Returns 2.
  The caller supplies a writable halfword. Matched with typed item and callee declarations.
- `func_020466e8` (0x020466e8, 752 bytes): resolves the current item's work record,
  sets its mode to 5 when present, resets item field 0x14, and processes it through
  `func_020aa964`. Positive results may submit two conditional updates. A negative
  result writes status 2; zero returns immediately. Result 1 dispatches on item
  field 0x08: cases 1/2 increment work field 0x1e2, case 6 also applies a negated
  record byte, and case 5 conditionally updates another record. Finally refreshes
  slots and dispatches by the packed key's type byte. Returns 1. Requires the current
  item and a valid resolved work record on paths that dereference it, plus a writable
  status halfword. Partial struct views preserve observed offsets without guessing
  field meanings; the ten-slot bound is explicit in the original loop.

## Hard list

None.
