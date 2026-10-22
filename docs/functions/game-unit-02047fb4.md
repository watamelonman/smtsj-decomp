# src/game/unit_02047fb4.c

All five functions are hand-matched at 100% in objdiff. The two work objects they touch are
returned by `Unk044904_Unk_045048` (manager +0x7804, the enemy talk-tone state) and
`Unk044904_Unk_045080` (manager +0x78e4, the effect/task state); `Unk0f7eb4_Unk_0f8078` resets
the same +0x48..+0x50 / +0x54 / +0x84 fields of that layout.

- `Unk047fb4_Unk_0480b4` (36 B, `int (void)`): returns 0 unless `Unk09d060_Unk_09d13c`
  reports the required mode active; otherwise hands the +0x78e4 work object to
  `Unk0f81a4_Unk_0f81a4` (which forwards its +0x84 field to `func_0204afe0`) and returns 2.
- `Unk047fb4_Unk_0481a0` (52 B, `int (u16 *)`): when the +0x78e4 work has a queued effect
  (`+0x48 != 0`), clears the name byte at +0x54 and the queued word, writes 2 to `arg0`, and
  returns 1.
- `func_02047fb4` (72 B, `int (u16 *)`): when bit 13 of the talk-tone work's +0x44 flags is
  set, clears +0x48, +0x4c, the halfword at +0x64 and that flag, writes 2 to `arg0`, and
  returns 1.
- `func_02047ffc` (184 B, `int (u16 *)`): advances the talk-tone script. `func_02045ca8`
  (wait check) or a clear bit-0 flag yields state 4 with `arg0[1] = 2`; bit 0 set clears the
  manager's +0x40 bit 16 and selects state 3 (running `Unk044904_Unk_045bd0(0)` first) when
  bit 1 is clear, or state 2 when it is set. Always ends with `func_02065b74`,
  `func_0202b730(0)`, `func_020450b8` and returns 1.
- `func_020480d8` (200 B, `int (u16 *)`): drives the +0x78e4 effect work. `func_0204b054`
  advances the work's +0x18 state and returns 0 only for state 3, 1 otherwise. On the
  state-3 path it sets state 3 if +0x4c is set or +0x88 == 3 (also raising the manager's
  +0x40 bit 7 when +0x50 is set), else state 4, then resets the work with
  `Unk0f7eb4_Unk_0f8078` and returns 1. On the nonzero path it returns 0 while +0x48 is
  clear, otherwise spawns the effect name at +0x54 through
  `func_0204f188(0, 0xffff, 6, name, 1)`, sets `arg0[0] = 2` and returns 1.

## Hard list

None.
