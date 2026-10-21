# src/game/unit_02000c04.c

- `main` (348 B): hand-written. ARM9 entry point: subsystem init, both screens' brightness set to
  -16, then the endless frame loop (frame counter at 0x0213d338+0x14; on the second frame the
  brightness is restored and the sub engine display is enabled, after that func_0202cd14 runs each
  frame). The word at 0x0212b35c has no relocation in config/arm9/relocs.txt, so it is read through
  its fixed address.
