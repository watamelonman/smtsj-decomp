# game/unit_02047c8c

All three ARM functions match the delinked original at 100% objdiff.
Names remain the original neutral symbols because the instructions establish control
flow and field use without establishing the sequence's game-facing purpose.

## func_02047c8c (52 bytes)

Takes a writable state record. Returns zero while the first predicate is false;
otherwise calls the intermediate helper, conditionally writes state 2 after a
second predicate, and returns one. Evidence: calls and conditional halfword store
in 02047c8c–02047cbc. No other state fields are accessed.

## func_02047cc0 (292 bytes)

Takes the same state record, with a signed halfword step at +6. Step zero
initializes the context, clears global +0x50/+0x54 when active, starts a 60-frame
operation and chooses a helper argument using entry +0x282 bit 2; it advances the
step and returns zero. Step one performs the corresponding follow-up calls,
configures the context using data_02143314, advances the step and returns one.
Other steps return one. Evidence: dispatch at 02047ce4 and stores at 02047d78
and 02047dd4. Entry and global layouts are partial views, not complete types.

## func_02047de4 (464 bytes)

Takes a writable state record and queries the current context. A zero readiness
result triggers cleanup, then selects state 2 or 3 using context +0x44 bits 3–4.
The pending path optionally creates an object from the +0x64 resource, submits
+0x48 and +0x4c IDs, and marks bit 13 of +0x44. A set bit selects state 2 and
returns one; otherwise it returns zero. Evidence: original calls and flag stores
at 02047e74–02047fac. The three-word local parameter block has only its first
word initialized here, as in the original; the called helper owns its interpretation.
Bitfield views preserve the original unsigned extraction instructions while the
whole-word flag view preserves updates to unrelated bits.

## Hard list

None.
