# libs/unknown/lib_02061798

Seven of the card's eight functions are reconstructed from the original ARM
instructions and match at 100%. `func_02062264` is the exception: it is a
four-byte copy of the preceding function's unreachable epilogue and cannot be
expressed as a standalone C function (see Hard list).

All names remain neutral linker symbols: the surrounding records and the
public SDK sources found below do not establish an application-level API name.
Addresses below are call-site addresses from `config/arm9/relocs.txt` and are
labelled as such; they are not function start addresses.

## Source investigation

Searched the public NitroSystem reconstruction
([ntrtwl/NitroSystem](https://github.com/ntrtwl/NitroSystem)) for the font and
text-canvas code around `g2d_Font.c`, `g2d_TextCanvas.c` and
`g2d_CharCanvas.c`. No implementation with this 56-byte four-entry font
registry, its `+0x30` / `+0x34` / `+0x48` render-object fields, or the
`data_0216b5a0` / `data_0216b9a8` text globals was found. The code is therefore
reconstructed from the instructions and keeps the neutral symbols.

The C declares only the fields observed in the instructions. Unrelated bytes
in the caller's objects stay in `pad_*` arrays; no SDK struct layout is claimed.
`func_02063a44` and `func_02063a60` return two different globals, so the header
uses two distinct opaque types, `Unk061798ResultA` and `Unk061798ResultB`.

## func_0206191c — 12 bytes

Tail wrapper for `func_020618cc`. Takes the font id passed by callers in r0
(call sites `0x02060210`, `0x020608a0`, `0x02062118`) and returns the selected
56-byte font record; its glyph table starts at +0 and callers read it with
`ldrh` at +0 and at `+2*index`. Objdiff: 100%.

## func_020619f8 — 12 bytes

Tail wrapper for `func_02061970`, with the font id passed in r0 (call site
`0x02061b9c`). `func_02061970` forwards r0 through `func_02061950` to
`func_020618cc(id)` and loads byte +1 of that record. The caller adds the
returned u8 to a coordinate stored at +4. Objdiff: 100%.

## func_02063a44 — 12 bytes

Tail wrapper for `func_02063954`. Forwards the text pointer in r0 and the
character code in r1 and returns the result object (call sites `0x0211c464`,
`0x0211d8f8`, `0x0211d93c`). Objdiff: 100%.

## func_02063a60 — 12 bytes

No-argument tail wrapper for `func_02063a50`, which returns the singleton from
`data_0216b9a8` +4. Callers test the result for null and read fields through it
(call sites `0x020641c8`, `0x0206545c`). Objdiff: 100%.

## func_0206357c — 8 bytes

Takes a render-object pointer and a 32-bit value; stores the value at +0x30.
Callers pass a glyph/record value before advancing text (call sites
`0x02060318`, `0x02060550`, `0x02060654`). Objdiff: 100%.

## func_02063584 — 8 bytes

Takes a render-object pointer and a byte; stores the byte at +0x34. Callers use
it for a mode 0/1/2 and for the active count (call sites `0x02062634`,
`0x02063640`, `0x020636e4`). Objdiff: 100%.

## func_0206359c — 8 bytes

Takes a render-object pointer and a 32-bit value; stores the value at +0x48.
Call site `0x02063e88` uses it to clear the field on the object's first pointer
(also `0x02063ec4`). Objdiff: 100%.

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
