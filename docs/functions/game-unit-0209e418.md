# game/unit_0209e418

All four functions match the original ARM instructions at 100% objdiff. Neutral
names are retained because the mode and resource semantics are not established.
The state and record pointers are borrowed; temporary 140-byte table contexts
are initialized and released within the function that owns them.

- `Unk09e418_Unk_09e418` (0x0209e418, 80 bytes): accepts three 16-bit
  arguments, stores them at +0x73f4/+0x73f6/+0x73f8, selects code 9 and mode 4,
  and clears root +4. A null game state is a no-op.
- `Unk09e418_Unk_09e468` (0x0209e468, 52 bytes): selects code 10 and
  mode 5 and clears root +4. A null game state is a no-op.
- `func_0209e49c` (0x0209e49c, 200 bytes): accepts signed grid coordinates
  and an argument. For an existing type-35 entry, stores the coordinates as
  signed bytes, resets the corresponding cell, selects the bit from record 23,
  sets the kind to 7 for zero or twice the argument minus one, clears its counter,
  and stores the argument and mode 6. Null state or missing/wrong entry is a no-op.
  Evidence: type compare at 0x0209e4e4 and stores at 0x0209e548–0x0209e55c.
- `func_0209e564` (0x0209e564, 456 bytes): accepts a resource-36 index,
  two signed grid coordinates, and a value (low eight bits forwarded). For a
  type-12 entry, visits its four link descriptors. Each enabled descriptor's
  low nibble resolves another resource entry; a type-12 entry at the same
  coordinates supplies bits 8–15 of its element word as the two-bit-write selector.
  Releases every constructed table and finally selects mode 12. Requires valid
  game state/resource indices and valid elements supplied by the resource layer.
  Evidence: resource ID 36, stride 40, type comparisons, four-iteration loop,
  and calls to `Unk0e651c_Set2Bits`. Bitfields preserve the original independent
  enable-bit tests and low-nibble extraction.

## Hard list

None.
