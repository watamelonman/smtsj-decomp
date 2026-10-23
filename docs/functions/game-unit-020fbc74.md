# game/unit_020fbc74

All six functions match at 100% in objdiff. The private `Work0fbc74`
view describes the 96-byte allocation; handles are owned by this block.
Names remain neutral because the instruction evidence establishes field
operations but does not establish the subsystem's purpose.

- `func_020fbc74` (96 bytes): releases each non-null handle at +0x40..+0x4c
  and clears its slot. If the signed +0x28 value is positive, passes the embedded
  +0x04 block to `Unk0d297c_Unk_0d33ac`. Finally releases +0x30 and +0x34.
  Evidence: four-iteration loop and calls in the original instructions.
- `Unk0fbc74_Unk_0fbcd4` (92 bytes): ignores an unchanged id at +0x28;
  otherwise resolves the id and supplies its value to the +0x34 handle.
  State 4 copies the id to +0x28 and +0x2c and becomes state 5; other
  states update only +0x2c. Evidence: stores and state comparison.
- `Unk0fbc74_Unk_0fbd30` (68 bytes): outside state 4 returns zero.
  In state 4 an already-zero unsigned 16-bit +0x38 offset returns one;
  otherwise clears it, requests state 7, calls the external helper with 2,
  and returns zero. Evidence: halfword accesses and immediate arguments.
- `Unk0fbc74_Unk_0fbd74` (80 bytes): in state 4 advances the +0x38 offset
  by ten with 16-bit truncation, then resets it when it reaches the signed
  +0x3c limit. A changed offset sets state 7 and returns one; otherwise
  returns zero. Evidence: `strh`/`ldrh` and signed `ge` comparison.
- `Unk0fbc74_Unk_0fbdc4` (32 bytes): calls `func_02061424` with the work
  pointer only in state 4, returning one in that case and zero otherwise.
- `func_020fbde4` (240 bytes): requests a 96-byte block with callbacks
  `func_020fb634`, `func_020fb858`, and `func_020fbc74`. Stores its two
  parameters at +0x54/+0x58 and creates four handles configured with them.
  Configures the fourth handle with 12, initializes +0x50/+0x5c to zero and
  current/pending ids to -1, creates two auxiliary handles, and configures
  the second with (16, 1). Returns the allocated block. Evidence: allocator
  arguments, four-iteration loop, and subsequent stores/calls. Allocation
  success is assumed by the original, which immediately dereferences it.

## Hard list

None.
