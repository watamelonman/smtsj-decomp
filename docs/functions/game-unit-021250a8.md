# src/game/unit_021250a8.c

Symbol names stay as `func_XXXXXXXX`: renaming needs `config/arm9/symbols.txt`, which this task
may not edit. Suggested names are given for a human to apply.

- `func_021250a8` (92 B): fills a callback descriptor: size/id 12, flag 0, then the ImageBgDual3D
  callbacks (`ImageBgDual3D_Unk_1252b4`, three `ImageBgDual3D_Nop_*`,
  `ImageBgDual3D_Clear_data_02176e8c`) and the message handler `func_02125104`.
  Suggested name: `ImageBgDual3D_InitDesc`.
- `func_02125104` (392 B): message handler. Type 0: reads a mode from the payload (only if flag
  bit 3 is set), stores it in `w->unk_0000`, builds a 16-slot request (mode 0: two zeroed buffers
  of 32 and 12 bytes filled by `func_0203546c` / `Unk02f2a8_Unk_03550c` keyed by work-area
  field 0x35c, put in slots 7 and 8; mode 1: slot 7 = `Unk0cb32c_Unk_0cb54c()`), sends it with
  `Unk0bc1a8_Unk_0bc928(36, 9, &req)` and sets `w->unk_0008 = 1`. Type 1 calls
  `Unk0bc1a8_Unk_0bc504(w, 0)`; types 2-4 and others do nothing. Matching notes: the payload
  check is a `static inline` helper that loads the value before testing the flag, and the two
  clearing loops need separate counters (a shared counter swaps r3/ip).
  Suggested name: `ImageBgDual3D_HandleMsg`.
- `func_0212528c` (40 B): stores `w` in `data_02176e8c` (the active ImageBgDual3D object), clears
  `w->unk_0008`, then tail-calls `func_02052634(1, 0, 31)`. Suggested name: `ImageBgDual3D_Activate`.

Hard list: none (all three functions match 100%).
