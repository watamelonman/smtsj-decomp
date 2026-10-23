# BattleTask — M1-T611

These neutral symbols retain their existing names: the instruction/data evidence
establishes the operations below, but does not establish gameplay terminology.
Layouts in the C file are partial views inferred from original field accesses;
padding and one-byte resource tails do not specify allocation sizes.

| Function | Contract and evidence from original ARM instructions |
| --- | --- |
| `BattleTask_Unk_0481d4` | Tests the current work pointer twice; latches `data_02143334` and calls `func_02053048` once when latched work disappears. Returns a boolean. |
| `BattleTask_Unk_04822c` | Calls four external subsystem routines in the recorded order; no arguments. |
| `BattleTask_Unk_048244` | Calls six external subsystem routines in the recorded order; no arguments. |
| `func_02048264` | Ignores its first argument. A non-null signed-byte array supplies at most six IDs terminated by zero, with 65 subtracted. Otherwise scans ten work slots for type byte 2 and submits mapped IDs from +0x1d8. Finishes with `Unk0a5680_Unk_0a5fb0`. |
| `func_020482f0` | Resolves an entry and resource, initializes object fields +0x24/+0x30/+0x3c, sends two signed-halfword coordinate pairs and two vectors by value. Vectors use 12 fractional bits divided by 32 with signed truncation; resource bounds supply vertical offsets. Returns the resource object. |
| `BattleTask_Unk_0484d0` | Comparator accepts two slot addresses; null entries have coordinate 256, others supply the first signed halfword via `func_02049c28`. Returns first minus second. |
| `func_02048520` | Scans ten type-2 slots, excludes entries rejected by `func_0204a9ec`, configures remaining objects, propagates work bit 9, then sorts six slots beginning at +0x74 with the comparator. Requires live work. |
| `func_020485c4` (deferred) | Resets the resource at global +0x79b0 and sets count six. Registers eligible type-2 entries using entry bit 2 at +0x282 to choose the mapping path. Optionally scans six 12-byte request records, skips zero IDs, maps low-halfword IDs conditionally, then finalizes the resource. Requires live work/global state. |

No new tests are required by this card. Validation compares compiled instructions
and relocations against the original, followed by objdiff and full-image checksum.

## Hard list

- `func_020485c4` remains supplied by the delinked original. A readable typed
  implementation reproduced all 328 bytes in size and the instruction sequence,
  but objdiff reached only 98.54% because the compiler allocated different
  callee-saved registers to the work pointer, resource base, and zero constants.
  Tried separate loop counters, local declaration order/scope, resource pointer
  representations, and register hints without an exact match. The candidate is
  omitted rather than linking a partial match. A human can use
  `tools/decompme.py` for a scratch targeting the register allocation.
