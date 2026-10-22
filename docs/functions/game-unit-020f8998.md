# src/game/unit_020f8998.c

Both definitions keep their `symbols.txt` names; there is no string or caller evidence for a
descriptive name. `func_020f899c` is a per-frame state machine over a work object whose fields at
+0x7440 and +0x7481..+0x7484 are only known from this function, so the layout is local and neutral.
`Unk0f8998_Nop_0f8998` is referenced by the data word at 0x0213bf98 (see
`config/arm9/relocs.txt`), which is why it is a callback-shaped empty function.

- `Unk0f8998_Nop_0f8998` (4 B): empty callback (`bx lr`), no parameters, no return value.
- `func_020f899c` (556 B): per-frame update taking an `Unk0f8998Work *` and returning an `int`.
  It increments `counter` (+0x7484) and dispatches on the signed `state` byte (+0x7481):
  - state 0: once `counter > 10`, resolves the grid cell at (+0x7482, +0x7483) through
    `Unk02f2a8_Unk_034970` / `Unk038fbc_Unk_039160`, fetches element 5 through
    `Unk038fbc_GetElement`, and builds an 8-byte entry from the work area fields at +0x35c and
    +0x358 plus the cell's two bytes. The cell's low 3 bits at +0x04 are remapped to the entry's
    `unk_04` (1→0, 2→2, 3→3, 4→1; 0 and 5..7 leave the work-area value). It then fills the entry
    through `Unk116360_Unk_116404`, submits it with `func_02034b7c(..., 4, 1, 0, 1)`, plays sound
    45 and advances to state 1.
  - state 1: when `func_02052728() == 0`, runs `func_020a03fc` and `ScanVisor_Unk_0a2acc`, then
    advances to state 2.
  - state 2: when `func_02052728() == 1`, advances to state 3.
  - state 3: advances to state 4.
  - state 4: returns 1 when the word at +0x7440 is 1, otherwise 0.
  Every transition resets `counter` to 0. States outside 0..4 fall through and return 0.

Match notes:
- The cell at +0x04 must be read as a 3-bit bitfield: the `u32 unk_04 : 3` form produces the
  original `ldr` followed by `lsl #29` / `lsr #29`. A mask or an explicit shift pair is folded
  into `and #7`.
- The entry's +0x02/+0x03 bytes must be `s8`, so the call to `func_02034b7c` reloads them with
  `ldrsb`; `u8` gives `ldrb`.
- The `{0}` initializer for the entry has to be declared after the lookup calls, otherwise the
  zero stores are emitted before them.

## Hard list
None.
