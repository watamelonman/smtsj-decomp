# game/unit_020f6f48

Both functions retain their configured neutral symbols because their higher-level
purpose is not established. No module boundary changes are introduced.

## func_020f6f48 — 0x020f6f48, 468 bytes

100% objdiff. Takes a writable work object containing the observed fields through
0x7481. States 0 and 1 return immediately; state 2 performs the reset sequence;
state 3 and other values do so only when the signed substate at 0x7481 is 0 or 1.
The sequence resets 128 entries via the embedded object at 0x24a8, copies the
three-word constants at 0x0213c96c and 0x0213c978, and passes those copies to the
observed setup routines. It initializes a zero vector and nine-word matrix,
writes the geometry command registers at 0x04000444 and 0x04000448, clears mask
0xa4 in global field 0xfc, and invokes the remaining setup calls, including the
embedded object at 0x41c and a sixteen-word temporary context.

Evidence is the original signed byte loads, jump table, loop bound, field
accesses, literal addresses and ordered calls. The layouts describe only observed
storage; no semantic relationship to other work structures is assumed. Local
aggregate initialization reproduces the original stack stores without extra
matrix copies. The standalone comparator reports an ARM/Thumb call-op difference
for func_02000edc before relocation; the actual linked objdiff report resolves it
and reports 100% for all 468 bytes.

## func_020f711c — 0x020f711c, 108 bytes

100% objdiff. Requires a writable 0x40-byte record. Stores the handle at 0x00,
0xffff at 0x04, ones at 0x08 and 0x0c, the signed input at both 0x10 and 0x18,
and zeros at 0x14 and 0x28. Copies the remaining scalar inputs and two callback
pointers into the remaining fields through 0x3c. Caller func_020eec4c supplies
handle 0x22, signed values -10 and -2, and two callbacks; this supports typed
parameters without assigning speculative field meanings. Standalone instruction
comparison also matches this function.

## Validation

The objdiff report records both functions at 100% (576 matched bytes total).
No new behavioral tests are required by the card; exact instruction comparison
and the repository gates provide validation for this matching task.

## Hard list

None.
