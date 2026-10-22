# game/unit_0202f078

All entries below were checked against the delinked ARM instruction stream; the
configured compiler reproduces every function in this translation unit at 100%.
The offsets and shapes are observed, but no string or caller establishes a
gameplay meaning, so the symbols remain neutral.

## M1-T114 functions

- `Unk02f078_Unk_02f0d8` (`0x0202f0d8`, 100%): calls `Unk02e000_Unk_02e774`
  and returns the unsigned byte at `+2`. That block is two bytes before the
  pointer returned by `Unk02e000_GetWorkArea` (which adds four).
- `Unk02f078_Unk_02f220` (`0x0202f220`, 100%): returns the unsigned work byte
  at `+0x361`.
- `Unk02f078_Unk_02f078` (`0x0202f078`, 100%): returns a borrowed pointer to
  the six-byte work block at `+0x36E`. Ownership stays with the work area.
- `Unk02f078_Unk_02f0b0` (`0x0202f0b0`, 100%): stores an unsigned argument in
  byte `+2` of the `Unk02e000_Unk_02e774` block.
- `Unk02f078_Unk_02f0c4` (`0x0202f0c4`, 100%): clears that same byte `+2`.
- `Unk02f078_Unk_02f20c` (`0x0202f20c`, 100%): stores an unsigned argument in
  work byte `+0x361`.
- `Unk02f078_Unk_02f0e8` (`0x0202f0e8`, 100%): reports whether byte `+2` of the
  `Unk02e000_Unk_02e774` block is nonzero as an int 0 or 1.
- `Unk02f078_Unk_02f08c` (`0x0202f08c`, 100%): calls `Unk02f078_Unk_02f078`,
  passes the returned block with value 0 and size 6 to `func_02008848`, then
  writes 100 to the block's second byte.

## M1-T115 functions

Reverified against `build/delinks/src/game/unit_0202f078.o` and a fresh objdiff
report. These five implementations were already present in the inherited source;
this card retains their matching code and clarifies the evidence and contracts.
Invalid indices return before calling either work/save accessor. The flag helpers
use the supplied bit number directly, leaving bit zero inaccessible. Entry
initialization replaces the entire byte with 3 when bit 1 is clear.

The descriptive names below refer only to instruction-level operations: byte
loads/tests and conditional stores establish the table/flag names, while the
comparison tree establishes the pair predicate. They imply no gameplay meaning.

- `Unk02f078_TestFlag380` (`0x0202f104`, 100%): reports bit `i` of the 37-bit
  flag array at work `+0x380`; ids outside 1..36 return zero.
- `Unk02f078_SetFlag380` (`0x0202f14c`, 100%): sets that bit for ids 1..36 and
  ignores other ids; already-set bits are not written again.
- `Unk02f078_IsAllowed_02f190` (`0x0202f190`, 100%): pair predicate over two
  small ids. Zero in the first argument is accepted, a zero second argument is
  accepted only with a zero first argument, and the remaining cases allow
  (2, any), (5, != 2), (1, 3 or 4), and (3, 4).
- `Unk02f078_InitEntry5e12` (`0x0202f230`, 100%): writes 3 to byte `i` of the
  table at `Unk02e000_Unk_02e774() + 0x5E12` unless bit 1 is already set; ids
  outside 0..63 are ignored.
- `Unk02f078_GetEntry5e12Bit0` (`0x0202f268`, 100%): returns bit 0 of that byte
  for ids 0..63 and zero otherwise.

## Hard list

None.
