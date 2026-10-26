# libs/unknown/lib_02061798

Seven of the card's eight functions are reconstructed from the original ARM
instructions and match at 100%. `func_02062264` is the exception: it is a
four-byte copy of the preceding function's unreachable epilogue and cannot be
expressed as a standalone C function (see Hard list).

All names remain neutral linker symbols: the surrounding records and the
public SDK sources found below do not establish an application-level API name.

## Source investigation

Searched the public NitroSystem reconstruction
([ntrtwl/NitroSystem](https://github.com/ntrtwl/NitroSystem)) for the font and
text-canvas code around `g2d_Font.c`, `g2d_TextCanvas.c` and `g2d_CharCanvas.c`.
No implementation with this 56-byte four-entry font registry, its `+0x30` /
`+0x34` / `+0x48` render-object fields, or the `data_0216b5a0` /
`data_0216b9a8` text buffers was found. The code is therefore reconstructed
from the instructions and keeps the neutral symbols.

The C declares only the fields observed in the instructions. Unrelated bytes
in the caller's objects stay in `pad_*` arrays; no SDK struct layout is claimed.

## func_0206191c — 12 bytes

Tail wrapper for `func_020618cc`. Takes the font id passed by callers in r0
(`func_0206020c`, `func_0206089c`, `func_02062114`) and returns the record
selected by `func_020618cc`; the returned pointer is read as a u16 glyph table
(`ldrh` at +0 and at `+2*index`). Objdiff: 100%.

## func_020619f8 — 12 bytes

No-argument tail wrapper for `func_02061970`, which loads byte +1 of
`func_02061950(id)`. Callers add the returned u8 to a width (`func_02061ba0`).
Objdiff: 100%.

## func_02063a44 — 12 bytes

Tail wrapper for `func_02063954`. Forwards the text pointer and character code
and returns the text-buffer pointer; callers use that result
(`func_02011c468`, `func_02011d8fc`). Objdiff: 100%.

## func_02063a60 — 12 bytes

No-argument tail wrapper for `func_02063a50`, which returns the shared
text-buffer singleton from `data_0216b9a8` +4. Callers test the result for null
and read fields through it (`func_020641cc`, `func_02065460`). Objdiff: 100%.

## func_0206357c — 8 bytes

Takes a render-object pointer and a 32-bit value; stores the value at +0x30.
Callers pass a glyph/record value before advancing text
(`func_02060318`, `func_02060550`, `func_02060654`). Objdiff: 100%.

## func_02063584 — 8 bytes

Takes a render-object pointer and a byte; stores the byte at +0x34. Callers use
it for a mode 0/1/2 and for the active count (`func_02062634`,
`func_02063640`). Objdiff: 100%.

## func_0206359c — 8 bytes

Takes a render-object pointer and a 32-bit value; stores the value at +0x48.
`func_02063e88` uses it to clear the field on the object's first pointer.
Objdiff: 100%.

## Hard list

- `func_02062264` (4 bytes): the original instruction is only
  `pop {r3, r4, r5, r6, r7, pc}` (0xe8bd80f8). It is the unreachable trailing
  epilogue of `func_02062208`; `func_02062208` ends at 0x02062258 with a
  conditional return of the same form, then branches back to its loop, and no
  branch, call or literal anywhere in the ARM9 image targets 0x02062264.
  A standalone C function cannot emit a register pop without a matching push
  (an empty function compiles to `bx lr`), and expressing it would require
  inline asm, which the card forbids. Leave the symbol to the delink object;
  a human should correct the split so the epilogue stays part of
  `func_02062208` before this symbol is considered matchable.

## Validation

`tools/hand/cmp.py` reports OK for each of the seven reconstructed functions.
`ninja`, `tools/match_gate.py`, `tools/checksum.py`, `tools/anticheat.py` and
the repository unit tests are run before handing the change back.
