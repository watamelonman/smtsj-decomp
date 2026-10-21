# src/game/unit_0212f7e4.c

- `func_0212f7e4` (4 B): forwarding thunk, a single `b func_021301f0`. Hand-matched.
  Descriptive name: `Unk12f7e4_Thunk_021301f0`, a `#define` alias declared in
  `include/game/unit_0212f7e4.h` (the definition keeps the symbols.txt name, which is protected).
  The project cflags use `-interworking`, which turns this tail call into `ldr ip, =func_021301f0; bx ip`
  (12 B). `#pragma interworking off` at the top of the TU gives the plain `b` the ROM has.

The rest of the delink range (0x0212f7e8..0x0212fa68, 0x280 B) looks like data (halfwords such
as `0xffff8067`), not code, so it is not decompiled here.

## Hard list
- none
