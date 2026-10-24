# game/unit_020f7eb4

All five M1-T246 functions match at 100% objdiff with the configured mwccarm
compiler. The TU remains linked from the delink pending human completion.

- `Unk0f7eb4_Unk_0f7eb4` (180 bytes): maps codes 0–7, 18 and 19 to
  7, 8, 0, 1, 2, 3, 5, 6, 4 and 15 respectively; other codes return 18.
  No evidence identifies the code domain, so the neutral symbol is retained.
- `func_020f7f68` (204 bytes): marks the work object active, initializes its
  script subsystem and loads message and condition-table resources. Evidence:
  strings at 0x02150e64 (`Data/Battle/Event/%s.bf`), 0x02150e7c
  (`Data/Battle/Event/%s.mbb`), 0x02150e98 (`BtlEvent`) and 0x02150ea4
  (`Data/Battle/Event/ProTable%s.tbb`). The last path uses the name after the
  `BtlEvent` prefix. The two trailing parameters are unused in the original.
- `Unk0f7eb4_Release` (68 bytes): returns immediately for inactive work;
  otherwise releases the script subsystem and both loaded resource handles,
  clearing those handles. The active flag itself is preserved. The existing
  Release symbol and paired initialization/release calls support the name.
- `Unk0f7eb4_Unk_0f8078` (32 bytes): resets words at +0x48 through +0x50,
  clears the byte at +0x54 and sets the selected handle at +0x84 to -1.
- `func_020f8098` (268 bytes): resets selection, then scans the signed record
  count at +0x80 through the table pointer at +0x7c. Each 36-byte record has
  a kind byte, condition byte, comparison halfword and 32-byte name. Matching
  nonzero kinds resolve a context with `func_02044ec4`; conditions 1 and 2
  require key bits 16–23 to equal 2 and 1 respectively and the record halfword
  to equal context +0x1d8. Condition 3 requires that context halfword to be zero.
  Kind zero bypasses these checks; other condition tags impose no restriction.
  A successful `func_0204b01c` result (anything except -1) is saved at +0x84,
  its kind at +0x88, and returns 1. Inactive work or exhaustion returns 0.
  Explicit condition case 0 reproduces the original four-entry jump table.

## Hard list

None.
