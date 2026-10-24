# src/game/unit_0205ae50.c

## M1-T425

All eight functions match the delinked ARM object at 100%. Evidence below is
from the original instruction sequences; field and subsystem meanings remain
unknown, so existing neutral symbols are retained. Work pointers are borrowed
and must be non-null unless explicitly described as optional.

- `Unk05ae50_Unk_05b228` (12 B): stores 1 in the byte at work +0x59
  (`MOV`, `STRB`); no ownership transfer.
- `Unk05ae50_Unk_05ae50` (16 B): calls `func_0205ad9c` and forwards its
  returned work pointer to `func_0205ae60`; the consecutive calls preserve R0.
- `Unk05ae50_Unk_05af2c` (16 B): obtains the singleton work and forwards it
  to `Unk05ae50_Unk_05af3c`, as established by the two original relocations.
- `Unk05ae50_Unk_05b388` (16 B): obtains the singleton work and forwards it
  to `func_0205b36c`, as established by the two original relocations.
- `Unk05ae50_Unk_05afd8` (20 B): clears the low two bits of an unsigned
  limit and stores it at `data_0216a184 + 0x5a8` (`BIC` and `STR`).
- `Unk05ae50_Unk_05b358` (20 B): returns exactly 0 or 1 according to the
  byte at work +0x59 (`LDRB`, compare, conditional moves).
- `func_0205b36c` (28 B): loads the optional linked work pointer at +0x14;
  returns 0 for null, otherwise calls `Unk05ae50_Unk_05b358` on that work.
  The original null guard and call support the typed link without assigning
  an unsupported semantic name.
- `Unk05ae50_Unk_05af3c` (40 B): passes the word at +0x10 to
  `func_02053000`, clears words +0x10, +8 and +0xc in that order, and returns
  1. The call relocation and ordered stores establish this contract.

## Hard list

None for M1-T425.

## Not done in M1-T427
- `func_0205ae60`
- `func_0205b234`
- `func_0205b02c`
- `Unk05ae50_Unk_05af64`: decompiler-derived

## Not done in M1-T426
- `Unk05ae50_Reset`
- `Unk05ae50_Unk_05afec`
- `Unk05ae50_WaitVCountThen_05af64`
- `func_0205b4c4`
- `func_0205b444`
- `func_0205b154`
- `func_0205b398`
- `Unk05ae50_Unk_05afec`: hand-matched
- `Unk05ae50_Reset`: hand-matched
- `Unk05ae50_WaitVCountThen_05af64`: hand-matched
