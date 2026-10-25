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

## M1-T600

All eight functions match at 100% objdiff. Evidence is each corresponding
symbol in `build/delinks/src/game/unit_0206a224.o`; names remain neutral because
instruction offsets and request constants do not establish higher-level intent.

- `Unk06a224_Unk_06a3a4` (80 bytes): reads signed halfwords from a borrowed
  object. For even +0x154, returns whether it is below (+0x158 - 1); for odd
  +0x154, returns whether (+0x156 + 24) is below +0x158. Signed remainder
  behavior includes negative odd selections.
- `Unk06a224_Unk_06a998` (100 bytes): indexes the borrowed pointer table at
  +0x15c. A nonnull entry supplies its leading unsigned halfword to
  `func_02099b10(id, 1)`. Clears the pointer and halfwords +0x154/+0x156,
  calls `func_02067d54`, and stores the used-slot count plus one at +0x158.
  The caller must provide a valid table index; the table length is unknown.
- `Unk06a224_Unk_06aa0c` (100 bytes): clears two flag bytes and sixteen
  request words, sets word 1 to 24 and flag 2, then submits to
  `func_020bcbc4` on channel 3.
- `Unk06a224_Unk_06aafc` (104 bytes): same request initialization, with
  word 1 = 2, word 7 = the caller's full word, and flags 0x82.
- `Unk06a224_Unk_06ab64` (104 bytes): calls `CampStatus_Copy12c` before
  initializing a request with word 1 = 11 and flag 2, submitted on channel 3.
- `Unk06a224_Unk_06accc` (104 bytes): submits the initialized request with
  word 1 = 10, word 7 = the caller's full word, and flags 0x82 on channel 3.
- `Unk06a224_Unk_06adc0` (104 bytes): submits the initialized request with
  word 1 = 25, word 7 = the caller's full word, and flags 0x82 on channel 3.
- `Unk06a224_Unk_06ae28` (108 bytes): tests group-zero masks 0x40, 0x80,
  0x20, and 0x10 through `func_020537b8`. Each nonzero result latches the
  corresponding word at +0x440, +0x444, +0x448, or +0x44c to one. Zero
  results preserve existing values in the caller-owned object.

Requests are stack-local and borrowed during submission. Their two alignment
bytes remain untouched, as in the target. No M1-T600 hard-list entries remain.

## Not done in M1-T601
- `Unk06a224_Unk_06ac54`
- `Unk06a224_Unk_06ad40`
- `func_0206abcc`
- `func_0206aa70`
- `func_0206a2ac`
- `func_0206a3f4`
- `Unk06a224_Unk_06ac54`: hand-matched
- `Unk06a224_Unk_06ad40`: hand-matched
