# src/game/unit_020b28e4.c

## M1-T1037 functions

- `Unk0b28e4_Nop_0b28e4` (4 B): empty callback.
- `Unk0b28e4_Unk_0b64c8` (20 B): returns the byte pointer cached at `+0x04` plus its two-byte header.
- `func_020b6514` (20 B): stores one word at `+0xca0` of the object referenced by the word at `+0x00`.
- `Unk0b28e4_Unk_0b5e10` (28 B): sets the byte at `+0x37` and word at `+0x2c`, then forwards to `func_0205f7f4`.
- `func_020b64dc` (28 B): returns entry `index` (12 bytes each) of the table based at `+0x04`.
- `func_020b64f8` (28 B): stores two words at `+0xc8c` and `+0xc90` of the object referenced by the word at `+0x00`.
- `Unk0b28e4_Unk_0b6338` (56 B): releases the object cached at `+0x04`, clears the cache and restores callback set 13.
- `Unk0b28e4_Unk_0b6370` (68 B): zeroes the 44-byte block cached at `+0x04` (allocated by `Unk0b28e4_Unk_0b62e8`) and its two payload areas.

## M1-T1038 functions

All eight targets are 100% in objdiff. Three implementations were already present
from the dependency; this card verifies them and supplies the other five.
Names follow the protected symbol table; no new descriptive names are inferred.
Evidence below is the original ARM disassembly at each function address.

- `Unk0b28e4_GetEntry34` (72 B): returns zero for a null base or signed index
  outside 0..26; otherwise reads the word at `base + index*12 + 0x34`.
  The two explicit unsigned boolean temporaries preserve the original range tests.
- `Unk0b28e4_InitCallbacks` (76 B): writes size `0xcac`, clears slots 1, 5,
  and 6, and sets callback slots 3, 4, 7, and 8. Slot 2 remains untouched.
  The four stored function addresses support the existing callback name.
- `Unk0b28e4_Unk_0b62e8` (80 B): calls `func_020552ec(6, 3)`, allocates
  44 bytes and initializes the cached block only when absent, then calls
  `Unk0bc1a8_Unk_0bc928(13, 0xffff, 0)`.
- `func_020b3d28` (156 B): frees work pointers at `+4`, `+0x24`, `+0x28`,
  and `+0x2c`; releases and conditionally clears handles at `+0xc30` and
  `+0xc34`; selects bank 1 before releasing each of three pointers in both
  arrays at `+0xc54` and `+0xc60`.
- `func_020b4fb4` (188 B): scans signed ids at roster `+0x348`, bounded by
  the byte at `+0x357` and terminated by negative ids. Calls `func_02044ec4`
  for each id, then selects records whose indexed `+0x36c` word has byte 2
  equal to 1. Counts qualifying entries, skips `work->unk_0c6c * 3`, and
  forwards up to three to `func_020b5adc`. Record stride is `0x2e0`.
- `func_020b3570` (204 B): while flags at `+0xca4` / `+0xca8` are set,
  tests masks `0x200` / `0x100`. A successful first test dispatches
  `func_0203e93c(1, 128, 96, work+0x10, work+0x1b0/0x210)`;
  otherwise a successful second test clears the corresponding flag.
- `func_020b5264` (212 B): uses the same roster bounds and paging as
  `func_020b4fb4`, additionally requiring `func_0204a244` to return 1
  for the record returned by `func_02044ec4`.
- `func_020b5e2c` (220 B): formats two paths using `data_0214ff94` and
  `data_0214ffc0` into separate 50-byte stack buffers. Loads the first,
  copies its two 32-byte entries into consecutive slots (second slot masked
  to 8 bits), and frees it. Loads the second, adds `(slot << 4) & 255` to
  each nonzero signed byte in its 512-byte payload, uploads with constants
  `(1, data, 4, 32, 16)`, frees the payload, and returns the upload result.

Matching trials: the initial roster loops tested the roster bound at the loop
footer, producing eight extra bytes. Moving that bound to an early return
inside the three-slot loop matches the original branch structure. Declaring
the first path buffer before the second reproduces the original stack offsets.
All new bodies use typed fields; padding and array bounds describe observed
accesses, without assigning unsupported gameplay meanings.

Hard list for M1-T1038: none.

## M1-T1039 functions

Seven implementations are 100% in the full objdiff report. Names remain those
in the protected symbol table; comments describe observed operations rather
than inferring gameplay purposes. Evidence is ARM disassembly at each address.

- `func_020b6104` (236 B): formats two resource paths into 40-byte buffers,
  copies one 32-byte palette entry, expands 128 signed packed bytes into 256
  caller-owned bytes (low nibble first), offsets nonzero indices by slot*16,
  uploads a 16-by-16 resource, and frees the packed source.
- `func_020b61f0` (248 B): the corresponding conversion into a caller-owned
  256-byte buffer, cleared first; updates an existing target through
  `func_02056d88` after freeing the packed source.
- `func_020b5ccc` (324 B): draws decimal digits using 96-byte entries 10..19;
  values above 999 use entry 20 three times. Byte coordinates wrap, alignment
  controls the initial horizontal position, and digit spacing is five.
- `func_020b593c` (416 B): checks the first header's type byte at +0x8c,
  draws its resource, three numeric fields, and a marker for states 1..11.
- `func_020b5adc` (496 B): draws the indexed type-1 record in a 56-pixel row,
  including three numeric fields, an optional secondary marker, and the
  state-1..11 marker. Resource arrays start at +0xc3c and +0xc48.
- `func_020b4dd8` (476 B): scans the roster for type-1 entries with three-slot
  paging, records displayed ids at +0xc78, clears rows beyond the roster or
  negative sentinel, and draws resource 4's label centered using its width.
- `func_020b49cc` (492 B): maps page and slot to roster positions, reserves
  the first row of page 1 for `func_020b5338`, clears unavailable or non-type-1
  rows, records displayed ids, and draws resource 2's centered label.
- `func_020b63b4` (276 B): remains in the delinked original. It scans six
  type-2 records at stride 0x2e0 beginning with the word at +0x25ec, rejects
  duplicate +0x1d8 halfword ids, and copies 12-byte payloads to the cache.
  Capacity is checked once at entry against three, as in the original.

Matching trials: signed packed bytes and arithmetic `i >> 1` reproduce the
nibble conversion; signed division by two emits an unwanted correction.
Declaration order controls local register assignment. Explicit unsigned-byte
coordinates reproduce wrapping. The two roster routines clear out-of-range
rows rather than terminating immediately. Their first label clear starts at
x=64 (the second at x=128), as evidenced by the argument registers.

### Hard list for M1-T1039

- `func_020b63b4`: tried typed cache fields, a 12-byte struct assignment,
  separate source/destination locals, reordered declarations, and an explicit
  byte-copy loop. Best struct-copy trial compiled to 272 bytes versus 276;
  it cached a loop bound that the original reloads and kept the cache pointer
  across the payload copy. The byte loop produced 260 bytes and different
  scheduling. No nonmatching body is retained. A human can use
  `tools/decompme.py` to open a scratch for this function.
