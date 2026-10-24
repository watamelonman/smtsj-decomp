# sdk_0205e318 (M2-T086)

The eight functions below are reconstructed from ARM instructions and relocations.
Existing neutral linker names are retained because the subsystem's identity is not
established. The directory's SDK label alone does not establish provenance: this
unit calls game table lookup `Unk0a0ce4_GetTableEntry` and game code at 0208df48.
Public-source searches covered [pret/pokeplatinum](https://github.com/pret/pokeplatinum)
and [zeldaret/ph](https://github.com/zeldaret/ph); no matching implementation was
identified. No external implementation was copied.

All eight pass the standalone instruction/relocation comparison against the ROM.
Partial layouts describe only offsets accessed here. Indices and pointers are
unchecked, as in the original. No new module boundary is introduced.

| Function | Contract and instruction evidence |
| --- | --- |
| `func_0205e318` | Returns record `index` from the pointer at +0x14, using the observed 24-byte stride. |
| `func_0205e328` | Selects a pointer from the table at +4, then returns its eight-byte record at +0x34 + index*8. |
| `func_0205e33c` | Returns the indexed pointer from the table at +4. |
| `func_0205e3e4` | Ignores argument zero; stores the id at +0xa0. A nonzero id replaces allocation +0x9c using 02052ff0. Regardless of id, a nonnull allocation resolves +0x94 through 0202b768. A nonzero id then calls 0202b124 and 0202c4ec and stores the result of 0202b914 at +0x98. Always sets +0xdc to one. The allocation slot uses a volatile-qualified pointer to retain the explicit store/reload at 0205e404/0205e408; this does not imply established interrupt ownership. |
| `func_0205e464` | Calls 02029e6c only when state +0xdc is nonzero. |
| `func_0205e484` | Returns zero if 0205e4f8 already accepts the id. Otherwise looks up its table entry, calls 0208df48 on channel zero with flag `id != 25` and the supplied mode, stores the id at +0xd0 and +0xcc, and returns one. |
| `func_0205e4dc` | Tail-forwards the remembered +0xcc id and supplied mode to 0205e484, preserving its return value. |
| `func_0205e4f8` | Returns zero when 0208e164(0) is false. Otherwise returns one for a negative id or an id equal to +0xd0; returns zero for all other ids. |

## Remaining functions / hard list

No M2-T086 functions remain on the hard list. `func_0205e348` belongs to the
separate M2-T087 card and remains in the original delinked object. The TU remains
incomplete in the human-owned link configuration.

## Validation

The match gate checks every defined function against objdiff. The checksum gate
checks the original image; because this TU remains incomplete, it still links
from the delink. The unit tests and anticheat gate also run for this change.
