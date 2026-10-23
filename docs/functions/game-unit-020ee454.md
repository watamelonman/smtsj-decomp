# game/unit_020ee454

All six functions match at 100% in objdiff with mwccarm 2.0/sp1p5.
Names are retained because the instruction evidence establishes operations, not
subsystem meaning. No module boundary changes are introduced.

- `func_020ee454` (84 bytes): allocates a 52-byte task using callback
  `func_020ee1d4`, clears its first word, and exports a handle through
  `func_020615ec`. Evidence: allocation stack arguments and first-word store at
  0x020ee454–0x020ee498. Allocation is assumed successful, as in the original.
- `func_020ee4a8` (88 bytes): fills a descriptor with work size 244, kind 4,
  and six callback slots including one null slot. The word at +8 is preserved.
  Evidence: stores to +0, +4 and +0xc through +0x20 in the original.
- `Unk0ee454_Unk_0ee500` (44 bytes): clears the caller's writable 244-byte
  work block, stores its borrowed pointer in `data_02176de4`, and initializes it.
  Evidence: clear length 0xf4, global store and call to `func_020ee52c`.
- `func_020ee52c` (220 bytes): sets +0x40 to 29 and +0x44 to 1,
  configures the parent with arguments including -128 and 12, initializes
  the embedded child at +0x50, and installs its +0xa0/+0x9c callbacks.
  Evidence: original stores, call arguments and callback address literals.
  The local layout reserves the remainder of the 244-byte block as opaque child
  storage; no external layout or ownership is changed.
- `Unk0ee454_Nop_0ee608` (4 bytes): empty callback, proven by the sole
  `bx lr` instruction and its descriptor slot at +0x1c.
- `func_020ee60c` (208 bytes): calls the common updater, then dispatches on
  the unsigned state at +8. State 11 forwards id/zero; state 2 sets state 1
  and chooses id 27, 28 or 29 from another helper's result; state 9 updates
  the embedded child and sets state 10. Other states have no extra action.
  Evidence: the original twelve-entry jump table and immediate stores/calls.
  Case 11 precedes case 2 in C to reproduce the original body ordering.

Validation: standalone instruction/relocation comparisons, full objdiff report
(all six 100%), anticheat, nine repository unit tests, and checksum gate passed.
The TU remains linked from the delinked original pending human completion.

## Hard list

None.
