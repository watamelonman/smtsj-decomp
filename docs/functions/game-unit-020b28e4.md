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

## Not done in M1-T1039
- `func_020b6104`
- `func_020b61f0`
- `func_020b63b4`
- `func_020b5ccc`
- `func_020b593c`
- `func_020b4dd8`
- `func_020b49cc`
- `func_020b5adc`
