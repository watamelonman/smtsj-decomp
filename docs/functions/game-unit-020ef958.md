# src/game/unit_020ef958.c

All five functions match the delinked ARM object at 100% objdiff.
Names retain the configured symbols because the instruction evidence establishes
mechanics but does not establish the screen or gameplay purpose.

- `func_020ef958` (88 bytes): fills a caller-owned descriptor with a 0xf4-byte
  work size, count 4 and six callback slots (one null). Evidence: stores at
  descriptor offsets 0, 4 and 0xc through 0x20; offset 8 is left untouched.
- `Unk0ef958_Unk_0ef9b0` (44 bytes): clears the caller-owned work block through
  `func_02008848`, publishes its pointer in `data_02176df4`, and calls setup.
- `func_020ef9dc` (212 bytes): initializes work fields 0x40 and 0x4c to 27 and
  zero; installs three callbacks through `func_020f711c`, configures the embedded
  block at 0x50 through `func_020f81cc`, and sets its final two callbacks.
  The typed work layout names only offsets actually accessed by this unit.
- `Unk0ef958_Nop_0efab0` (4 bytes): empty callback; the original is `bx lr`.
  Its work pointer is unused and follows the descriptor callback contract.
- `func_020efab4` (220 bytes): calls `func_020f7188` and dispatches work state
  at offset 8. State 11 forwards field 0x40 with zero; state 2 performs the
  three-way selection (27/28/29), with a separate default path, then finalizes;
  state 9 becomes 10 and calls `func_020f8264` on the embedded block.
  Other states do nothing beyond the shared initial call. Keeping case 11
  before case 2 in source reproduces the original branch/body ordering.

## Validation

`ninja` builds the C object; objdiff verifies all five bodies against the
original object. The translation unit remains delink-backed as required by the
card; no completion configuration is changed.

## Hard list

None.
