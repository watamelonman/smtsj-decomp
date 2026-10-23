# game/unit_0206a224

## M1-T599

All eight functions below match the delinked ARM object at 100% objdiff.
Evidence is the corresponding symbol in `build/delinks/src/game/unit_0206a224.o`;
field meanings remain neutral where assembly establishes only an offset.

- `Unk06a224_Thunk_020d6cac`: 12-byte indirect tail thunk to
  `CampStatus_Copy168`, forwarding its borrowed source pointer. The callee assigns
  six byte pairs into shared work +0x168; no ownership transfers.
- `Unk06a224_Unk_06a224`: returns the full word at `data_0216b9b0 + 8`.
- `Unk06a224_GetUnk00`: returns the full word at `data_0216b9b0 + 0`.
  The target loads offset zero, supporting the existing accessor name.
- `Unk06a224_Unk_06a244`: stores its word argument at global +8.
- `Unk06a224_SetUnk00`: stores its word argument at global +0.
  The target stores offset zero, supporting the existing accessor name.
- `Unk06a224_Unk_06a9fc`: maps its integer argument through
  `Unk0986ac_Unk_098978` and returns `Unk0986ac_Thunk_02098714`'s result.
  The first callee subtracts 0x6f; the second tests the resulting flag bit.
  Callers in `unit_02065e88.c` pass IDs 180–182 and branch on the result.
- `Unk06a224_Unk_06a374`: takes a borrowed object with signed halfwords at
  +0x154 and +0x156. Returns one if the first is odd, otherwise whether the
  second is positive. Target signed loads and remainder instructions establish
  that negative odd values also return one.
- `Unk06a224_CountUsedSlots`: follows global +4, then pointer +0x408, and
  counts nonzero leading halfwords across 489 four-byte records. The target's
  halfword load, index shift by two, and 0x1e9 limit support the existing name.
  Returns a signed 16-bit count (0–489); both pointers must be valid.

No M1-T599 hard-list entries remain. Other cards' status is retained below.

## Not done in M1-T600
- `Unk06a224_Unk_06a3a4`
- `Unk06a224_Unk_06a998`
- `Unk06a224_Unk_06aa0c`
- `Unk06a224_Unk_06aafc`
- `Unk06a224_Unk_06ab64`
- `Unk06a224_Unk_06accc`
- `Unk06a224_Unk_06adc0`

## Not done in M1-T601
- `Unk06a224_Unk_06ac54`
- `Unk06a224_Unk_06ad40`
- `func_0206abcc`
- `func_0206aa70`
- `func_0206a2ac`
- `func_0206a3f4`
- `Unk06a224_Unk_06a3a4`: hand-matched
- `Unk06a224_Unk_06a998`: hand-matched
- `Unk06a224_Unk_06aa0c`: hand-matched
- `Unk06a224_Unk_06aafc`: hand-matched
- `Unk06a224_Unk_06ab64`: hand-matched
- `Unk06a224_Unk_06ac54`: hand-matched
- `Unk06a224_Unk_06accc`: hand-matched
- `Unk06a224_Unk_06ad40`: hand-matched
- `Unk06a224_Unk_06adc0`: hand-matched
