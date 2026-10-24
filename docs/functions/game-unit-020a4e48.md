# game/unit_020a4e48

All five functions match the delinked ARM original at 100% objdiff.
Names are preserved from the symbol configuration; behavior below follows the
original instructions, without assigning a higher-level game purpose.

The shared `data_02176b08` layout is a mode word at +0, delay byte at +4,
step byte at +5, signed level byte at +6, elapsed byte at +7, and active word
at +8. Calls pass the literal register address `0x0400106c` (sub-screen master
brightness) to `func_0200292c`, with the level divided by two toward zero.

- `func_020a4e48(s32 defer_write)` (84 bytes): initializes mode 2, zero
  level/counter/delay/active, and step 3. Writes the initial level only when
  `defer_write` is zero. Evidence: stores at 020a4e54–020a4e70 and conditional
  register-helper call at 020a4e74–020a4e8c.
- `Unk0a4e48_Unk_0a4e9c(u32 mode)` (20 bytes): tail-calls
  `func_020a4eb0(mode, 0, 3)`. Evidence: argument setup and indirect branch
  at 020a4e9c–020a4eac.
- `func_020a4eb0(u32 mode, u32 delay, u32 step)` (136 bytes): activates the
  transition, resets elapsed time, truncates delay/step to bytes, and selects
  initial level -32, +32, 0, or 0 for modes 0–3. Other modes retain the previous
  level. Immediately writes the halved level. Evidence: byte stores, four-way
  jump table, and helper call at 020a4eb0–020a4f2c.
- `Unk0a4e48_Nop_0a4f38(void)` (4 bytes): empty callback, evidenced by the
  single `bx lr` instruction at 020a4f38.
- `func_020a4f3c(void)` (408 bytes): advances an active transition when the
  elapsed byte reaches the delay, otherwise increments elapsed. Modes 0/1
  move toward zero; modes 2/3 move toward -32/+32. Each update stores to the
  signed byte before checking/clamping the endpoint, preserving byte wrapping.
  Writes the halved level and resets elapsed after an update. Independently
  clears active when the selected endpoint has been reached, then returns
  active. Evidence: update switch at 020a4f80–020a5008, delay paths at
  020a501c–020a5038, and endpoint checks at 020a503c–020a50c8.

## Validation

`python3 tools/match_gate.py`: all five target functions report 100%.
The task waives new tests; objdiff verifies the complete compiled function
bodies against the original. No hard-list functions remain.
