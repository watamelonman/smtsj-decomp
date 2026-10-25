# game/unit_020eef2c

The six C definitions below match at 100% in objdiff. Names retain their
configured neutral spelling: the instructions establish behavior, but not the
subsystem's purpose. The work block is caller-owned and contains six words.

| Function | Evidence and contract |
| --- | --- |
| `Unk0eef2c_Unk_0eef2c` | Clears 24 bytes, publishes the work pointer in `data_02176dec`, then calls the default initializer. Requires writable storage. |
| `Unk0eef2c_Unk_0eef58` | Stores words 33, 1, 0, 0, -241, 0 at offsets 0 through 20. |
| `Unk0eef2c_Nop_0eef80` | Single return instruction; empty callback. |
| `func_020eef84` | State 4 decrements the signed counter and stores counter * -241 / 10; at expiry it clears the offset and selects state 10. States 6 and 7 store (10 - counter) * -241 / 10 after decrementing; expiry calls `func_020f7de4` or `Unk0bc1a8_Unk_0bc9b4`, respectively, with word 0 and zero. Other states do nothing. Arithmetic assumes the original bounded transition counters. |
| `Unk0eef2c_Nop_0ef06c` | Single return instruction; empty callback. |
| `Unk0eef2c_Unk_0ef070` | State 1 returns immediately; other states call `func_02057e18(31)` then `func_02057df8()`. |
| `func_020ef090` | Not implemented in C; retained in the original delink. Message dispatcher described below. |

## Hard list

- `func_020ef090` (440 bytes): dispatches message kinds 1 through 4.
  Kind 3 starts state 4 with a ten-tick counter only from state 1.
  Kind 2 reads optional parameter 2 (default zero), selecting state 1 for zero.
  Kind 1 calls `Unk0bc1a8_Unk_0bc504(work, 0)`.
  Kind 4 reads optional parameters 6 and 7; when parameter 6 is zero,
  parameter 7 selects state 6 or 7 and ten ticks, or calls
  `Unk0bc1a8_Unk_0bc9b4` immediately from state 1.
  Tried a typed inline parameter block, a nullable bit-presence reader,
  and a nullable default-zero wrapper. The kind-2 switch reproduces the
  otherwise redundant comparison with 3. However, inline helpers generate
  400 bytes rather than 440: three temporary outputs stay in registers
  instead of the original stack slots at sp+8, sp+4 and sp+0. Scalar and
  single-element-array outputs and static/nonstatic inline variants did not
  resolve it; ordinary static helpers instead emitted calls (276-byte handler).
  A human can use `tools/decompme.py` to investigate the original helper layout.
  No compiler tricks or artificial volatile accesses were retained.
