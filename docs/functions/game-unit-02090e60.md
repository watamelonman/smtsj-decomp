# `game/unit_02090e60.c` functions

Translation unit `.text` range: `0x02090e60` .. `0x020939f0` (Nintendo DS ARM9).
Only `func_020934c8` is currently written in C and matches the delinked original;
the other four remain linked from the original delink object.

## Matched

### `func_020934c8` — 0x020934c8, 240 bytes (100%)

Refreshes the 12-entry selectable list after the active group changed. Clears the
pending byte at `+0x353`, calls the list builder `func_020937a0` with the current
group (`+0x2f4` indexes a group table at `+0x354`), then walks the pointer table
at `+0x40c[12]`: it clears the UI flags, re-enables the entries that are still in
range (`+0x398`) and whose record has bit 0 set, and finally plays the selection
sound (`Unk06a224_Unk_06adc0(14)`) if the pending byte was set. The table access
is written as a struct array because that reproduces mwcc's indexed addressing.
Evidence: callers `func_02090e60`; the routine is the only writer of the
`+0x353`/`+0x40c` list state in this TU.

## Hard list (not matched in this attempt)

### `func_020935b8` — 0x020935b8, 488 bytes

Builds the entry display block at `+0xcc`: copies 12 bytes of entry metadata from
the record returned by `func_020a1428`, copies 12 bytes of label data, then
optionally updates the list and forwards the selected pointer to
`func_02069b24`. Closest C reconstruction was 496 bytes vs. 488. The remaining
difference is mwcc register allocation at function entry: the original keeps
`work` in `r4`, `arg1` in `r5` and `arg2` in `r7`, while every C spelling tried
(parameter types, local declaration order, aliases) keeps `arg2` in `r4` and
shifts the whole body. Recommend a decomp.me scratch
(`python3 tools/decompme.py --platform nds_arm9 ...`) to settle the allocation.

### `func_020937a0` — 0x020937a0, 592 bytes

Rebuilds the three list panels (the `+0x114`, `+0x118`, `+0x110`/`+0x11c`
groups): starts a draw list (`func_02063920`), optionally selects each of the 12
entries, calls `func_02061f10` for every panel, and at the end filters the 12
entries against the work area's record ids (`+0x348`/`+0x120`) plus
`Unk02e000_GetRecordFlag1`. Closest C reconstruction was 612 bytes vs. 592. The
original spills the `list` argument to `[sp,#4]` and keeps the loop result in
`r6`; mwcc kept the argument in `r9` in our version, changing the loop register
assignment. Needs a scratch to fix the spill/colouring.

### `func_02092624` — 0x02092624, 3748 bytes

Per-state drawing routine for the same screen (state word `+0x390`, 12 by 0xea4
bytes; one jump table). It issues many multi-argument draw calls whose stack
payloads include float `1.0` constants. Ghidra's C collapses those calls to four
arguments with expression arguments, so it compiled to 2344 bytes vs. 3748 —
roughly 350 instructions of stack-argument setup were lost. Reconstructing it
requires reading each call site's `r0-r3` and stack stores from the disassembly
and writing the real prototypes first; not attempted further in this pass.

### `func_02090e60` — 0x02090e60, 6084 bytes

Main per-frame state machine for this screen: 112 branches, one switch over
`+0x390` with cases 0..12 (several share blocks through `goto`), 220 calls and
five local stack arrays used to build event/menu payloads. Ghidra's export is
usable as a skeleton but, like `func_02092624`, drops long call-argument
payloads and local variable reuse (e.g. `unaff_r6`, `DAT_` constants); the
generated C is far shorter than the target and would need a case-by-case
disassembly pass. Recommended decomp.me scratch per case, starting with the
`+0x390` dispatch.
