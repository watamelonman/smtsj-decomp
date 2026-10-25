# game/unit_020e5cb8

All four functions match the original ARM instructions at 100% objdiff.
Names are retained because the original data use establishes mechanics but not
higher-level gameplay terminology. The TU remains linked from the delink.

- `func_020e5cb8` (200 bytes): takes a caller-owned selection and signed trial
  count. Resolves its record key at offset 0x36, reads record word 0x24 bits
  7..13, and adds signed record field 1c divided by 20. Accessor IDs 0xbb and
  0x84 respectively scale the unsigned threshold by 150/100 and force success
  within the loop. Each ordinary trial compares a draw from (1,99) with that
  threshold. Nonpositive counts return zero. These offsets and calls are the
  evidence for the partial record/selection views and comments.
- `Unk0e5cb8_Unk_0e5d80` (76 bytes): accepts signed trial count and unsigned
  threshold, returns one on the first unsigned random draw below the threshold,
  otherwise zero. Original calls use bounds 1 and 99; nonpositive counts do
  not draw. The existing function body was rewritten with a typed RNG prototype.
- `func_020e5dcc` (160 bytes): accepts a selection and trial count. Flag 0x706
  and the record-kind check can reject immediately. The non-flag-B path chooses
  category-table byte 0 or 1 according to whether record field 1e is below 100,
  calls the trial helper, and writes selection byte 0x3b only on success. The
  flag-B path multiplies category byte 0x39 by `func_020e6a0c` and performs
  trials without writing that byte. The product preserves signed multiplication
  followed by conversion to the helper's unsigned threshold.
- `func_020e5e6c` (332 bytes): accepts a selection and returns a 16-bit entry ID.
  Reads six IDs at offset 0x28, excludes the three IDs in the table selected by
  the truncated record key plus 0x19a, and requires metadata byte 4 bits 2..3
  to be nonzero. Empty candidate sets return 0xffff. Otherwise stores 16-bit
  weights of 15 minus metadata byte 3, draws with bounds 1 and total minus 1,
  and returns the first candidate whose cumulative weight exceeds the draw.
  Input table weights must satisfy the original selector's range assumptions;
  no additional clamp or fallback is introduced.

## Validation

The build and objdiff compare compiled C against the delinked originals; no new
behavioral tests are required by this card. No assembly or code blobs are used.

## Hard list

None.
