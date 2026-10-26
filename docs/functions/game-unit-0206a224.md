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

## M1-T601

All six functions below match at 100% objdiff against the corresponding symbols
in `build/delinks/src/game/unit_0206a224.o`. Names remain neutral: instruction
constants, offsets and callees establish behavior but not a higher-level purpose.

- `Unk06a224_Unk_06ac54` (120 bytes): initializes two flag bytes and sixteen
  request words, sets word 1 = 20, word 6 = 1, word 7 = the caller word, and
  flags 0xc2. Submits the stack-local borrowed request on channel 3.
- `Unk06a224_Unk_06ad40` (128 bytes): initializes the same request layout,
  sets word 1 = 11, word 3 = 12 and flags 10, and calls `func_020bcacc` on
  channel 3. Then calls `func_020bc9f4(11, 0)` and `CampStatus_SetUnk1a8(0)`.
- `func_0206abcc` (136 bytes): forwards its borrowed source to
  `CampStatus_Copy12c`, preserving the second integer argument across that
  call. Submits word 1 = 11 with flag 2; a nonzero second argument also sets
  word 3 = 11 and flag 8. The request's alignment bytes remain untouched.
- `func_0206aa70` (140 bytes): submits word 1 = 2 with flag 2, then obtains
  the shared work area and reads a signed byte at caller index +0x348 into
  word 7, enabling flag 0x80. The caller must supply a valid byte-table index.
- `func_0206a2ac` (200 bytes): clears 24 slot pointers at +0x15c and repopulates
  them through `func_02067d54`. After `func_02063920`, obtains resources (12,17)
  and (6,0). An empty first slot emits ID 5 using the first resource; nonzero
  IDs in populated slots use the second resource. Each emission obtains a
  handle through `func_02063a30`; the last handle is passed as argument five
  to `func_02061f10` with the object at +0x150. As in the target, the provider
  must ensure at least one emission so the last handle is initialized.
- `func_0206a3f4` (1444 bytes): processes group-zero input masks 0x40, 0x80,
  0x20 and 0x10 to update signed selection/scroll/count fields at
  +0x154/+0x156/+0x158. Two-column movement wraps by count; lateral movement
  scrolls up to 22 entries with 24 visible slots. It rebuilds slots when the
  scroll changes, reports selection changes, and manages request latch
  +0x3d8 and flags +0x440..+0x44c. On latch release, it submits the selected
  ID and stores it at +0x3f0, or emits request 24 for selection/scroll zero.
  Input mask 0x800 triggers request 11 or the zero-selection notification.
  Returns zero after selection changes or the nonzero-selection request-11
  action, otherwise one. The caller owns a valid work object through +0x44c
  and valid populated slot pointers for the selected index.

Validation: match gate reports every defined function at 100%; anticheat and
all nine unit tests pass; checksum reports every artifact byte-identical.
No M1-T601 hard-list entries remain.
