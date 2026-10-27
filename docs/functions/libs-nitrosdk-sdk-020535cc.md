# sdk_020535cc

Two cards share this partial translation unit: M2-T409 (the eight query/setter
wrappers at 0x020537b8..0x02053bf8) and M2-T410 (the initializer, input
updater and state machine at 0x020535cc..0x020539dc). All sixteen functions now
match the delinked ARM instructions at 100%. Other functions remain supplied by
the delink; the split configuration remains human-owned.

A public-source search for NitroSDK PAD code in pret/pokeplatinum found no
matching implementation for this record/state wrapper. Reconstruction therefore
uses the original instructions and retains the original neutral symbols rather
than assigning speculative SDK names.

## Data layout (evidence from instruction offsets)

`data_021605e4` is an array of five 0x56-byte input records. Only record 0 is
refreshed by the updater; all five carry the same per-key timing tables.

| Offset | Type | Meaning |
| --- | --- | --- |
| +0x00 | u16 | held bits (`~KEYINPUT \| KEYMIRROR` over the tracked mask) |
| +0x02 | u16 | complement of +0x00 |
| +0x04 | u16 | newly pressed (`held & ~previous`) |
| +0x06 | u16 | newly released (`~held & previous`) |
| +0x08 | u16 | previous held bits |
| +0x0a | u16 | auto-repeat bits that fired this frame |
| +0x0c | u16 | keys currently in the auto-repeat phase |
| +0x0e | u16[12] | per-key first-fire delay |
| +0x26 | u16[12] | per-key repeat interval |
| +0x3e | u16[12] | per-key held-frame counter |

`data_02160794` is the state block: state at +0, running flag at +4, teardown
flag at +8, countdown at +0xc, reload at +0x10, dispatch flags at +0x14/+0x18/
+0x1c, busy flag at +0x20, timer at +0x24 and two callbacks at +0x28/+0x2c.
`data_021605e0` is a word-sized idle-frame counter.

## Functions

| Function | Behavior and instruction evidence | Match |
| --- | --- | --- |
| `func_020535cc` | Zeroes the five records with `func_020119c0` (one call per 0x56-byte record) and installs delay 60 / interval 0 for each of the twelve tracked keys. Evidence: 0x56 memset stride, constants 60 and 0 at the `func_020538dc` call. | 100% |
| `func_02053640` | Samples `KEYINPUT` and the 0x027fffa8 mirror, stores held/complemented/pressed/released/previous into record 0, seeds repeat bits with the pressed bits, then walks the twelve keys: first fire after `delay`, then repeat every `interval` while held; clears repeat state when the key is released. Resets the idle counter when any tracked key is down, then increments it. | 100% |
| `func_020537b8` | Tests the +0 held halfword against the supplied word mask. | 100% |
| `func_020537dc` | Tests the +2 complemented halfword against the supplied word mask. | 100% |
| `func_02053800` | Tests the +4 newly pressed halfword against the supplied word mask. | 100% |
| `func_02053824` | Tests the +0x0a auto-repeat halfword against the supplied word mask; used by the caller in `sdk_0205e800.c`. | 100% |
| `func_02053848` | Maps the one-hot key bits 1..0x800 to indices 0..11; returns -1 for any other value. Evidence: the sequential compare/move/bx chain in `func_020538dc`. | 100% |
| `func_020538dc` | Resolves a key bit to an index through `func_02053848` and stores the delay at +0x0e+2i and the interval at +0x26+2i for the selected record; returns 0 on an unknown key. | 100% |
| `func_02053924` | Applies the same delay and interval to all twelve keys of all five records. | 100% |
| `func_0205397c` | Resets the state block to state 3 and clears countdown, reload, busy, timer and callback slots; clears the three dispatch flags through their setters. | 100% |
| `func_020539cc` | Stores the reload word at `data_02160794 + 0x10`; the updater copies it into the countdown. | 100% |
| `func_020539dc` | Advances the state machine. With key-mirror bit 15 set it arms the countdown (returning 1 on that frame), then enters state 1 when the countdown expires and services at most one dispatch flag per call. With bit 15 clear it tears down: state 2 when the sequence was running (callback + 40-frame timer), state 3 otherwise. | 100% |
| `func_02053bc8` | Reads the state word at +0; the updater assigns states 0..3. | 100% |
| `func_02053bd8` | Stores the flag at +0x14, tested for equality to one before the provider sequence at 0x02053a78. | 100% |
| `func_02053be8` | Stores the flag at +0x18, tested for equality to one before the provider call at 0x02053ac0. | 100% |
| `func_02053bf8` | Stores the flag at +0x1c, tested for equality to one before callback dispatch at 0x02053adc. | 100% |

The flag setters preserve the full supplied word; they do not normalize values.
The address calculation for the +2/+4 queries preserves the base-symbol
relocation and the original multiply-accumulate instruction. An explicit local
bit intersection also reproduces the original `tst` operand order.

## Non-obvious reconstruction notes

- The held-bit update is written as `((KEYINPUT | mirror) ^ mask) & mask`.
  XOR followed by the mask inverts exactly the tracked bits, which is
  equivalent to `~(KEYINPUT | mirror) & mask` for the 16-bit register values
  and is the form the original instructions use (`eor` then `and`).
- `func_020539dc` must read `data_02160794` directly rather than caching a
  pointer: the original only saves r4/lr and reloads the block address from the
  literal pool after every call.
- `func_020538dc` takes its device index as `u8`; callers mask the loop counter
  at the call site (the callee's multiply-add uses the register directly).
- The record pointer in `func_020535cc` advances immediately after the clear
  call, so the loop emits `add sl, sl, #0x56` before the key loop.

## Validation

`python3 tools/match_gate.py` passes with all sixteen functions at 100%.
`python3 tools/checksum.py` reports all artifacts byte-identical to the
original. The anticheat gate passes and the unittest suite passes. No new
behavioral tests were required by these cards; instruction identity is the
acceptance check.

## Hard list

None.
