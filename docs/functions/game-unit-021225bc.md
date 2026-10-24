# game/unit_021225bc

All four functions retain their original neutral symbols: the instruction evidence
supports field operations and predicates, but does not establish gameplay names.
Local struct views describe borrowed storage and only the accessed fields. The
one-element state tail marks the start of a larger opaque region, not its extent.
The tile bitfield corresponds to bits 16–19 of the word at offset 4.

- `func_021225bc(int id, int selector, int x, int y)` — returns one only for
  the id returned by `(7,5)`, selector 2, coordinates `(10,27)`, and a clear
  flag `0x10f`. Evidence: the original comparisons and flag-helper call.
  Matched size: 84 bytes.
- `func_02122610(void)` — requires current work id at `+0x35c` to match
  `(7,5)`, the current signed-byte coordinates' tile nibble to equal 2, and
  id selector 2 to equal 2. Copies state data through `func_0209a884`, applies
  the two cell helpers with values 1 and 0, sets the bit selected by entry 5's
  byte `+0x19`, then writes cell byte 1 to 3 and halfword 2 to zero.
  Evidence: original loads, calls and stores. Matched size: 232 bytes.
- `func_021226f8(void)` — returns one immediately when any of the same
  prerequisites fails. Otherwise increments the cell's 16-bit counter and
  returns zero until `Unk09a268_Unk_09a844` returns exactly one. On completion,
  applies both helpers with value 1, sets the entry-selected bit, clears byte
  1 and halfword 2, and returns one. Evidence: original branches and stores.
  Matched size: 260 bytes.
- `func_021227fc(int x, int y)` — obtains selector 2 for the current work id,
  checks the coordinates using `func_021225bc`, and maps its exact result 1
  to 2, returning zero otherwise. Both work accessor calls are preserved.
  Evidence: original call sequence. Matched size: 84 bytes.

Validation uses comparison against the delinked original rather than added unit
tests, as permitted by this card. All four standalone instruction comparisons
match, including relocation targets. No hard functions remain.
