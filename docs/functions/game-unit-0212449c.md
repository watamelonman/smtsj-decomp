# game/unit_0212449c

All four functions match at 100% objdiff with mwccarm 2.0/sp1p5.
Parameters borrow a word-aligned, 64-byte work block; resource handles remain
opaque integers. Names remain neutral because the specific screen is unproven.
Evidence below refers to the original ARM instructions at the listed addresses.

- `Unk12449c_Unk_12449c` (0x0212449c, 156 bytes): releases the handle at
  +24 through `func_020629c4`, then nonzero handles at +8..+20 through
  `func_0205c3dc`, +4 through `func_0205c368`, and +0 through
  `func_0205ddb4`. Clears those latter six slots, calls `func_0205bb68`
  four times, and calls `Unk044394_Unk_044534(30)` when +36 is nonzero.
  The original loads each handle immediately before its release call.
- `func_02124538` (0x02124538, 88 bytes): increments signed offsets at
  +28 and +32, replacing values >=192 with -192, then passes each of
  the four handles at +8..+20 to `func_0205c704`. The compare and
  conditional stores establish the signed wrap contract.
- `Unk12449c_Unk_124590` (0x02124590, 44 bytes): when +60 is nonzero,
  clears +40, calls `func_021245bc` with the same work block, then sets
  +40 to one. It does not restore the previous value of +40.
- `func_021245bc` (0x021245bc, 1696 bytes): brackets resource submissions
  with `func_02057524(4)` and `func_020572d8`. The +48 flag enables two
  offset submissions of entry 16 and entry 15. Within that branch, +56
  enables mode selection through `func_020cb3dc`: mode 1 uses entries
  4..0 and handle +8, modes 2/3 use entries 9..5 and handles +16/+12,
  and mode 4 uses entries 13..10 and handle +20. The original switch
  table includes mode 0 as a no-submission case. Color literals are
  0x081018ff, 0x186bdeff, 0x084aa5ff and 0x4a637bff; scale arguments
  carry the IEEE single-precision value 1.0. Independently, +40 enables
  entry 14 and +44 enables two submissions of handle +24 through
  `func_02060b60`. Repeated color-state calls and resource submission
  calls support the drawing interpretation without identifying a screen.

## Hard list

None.
