# game/unit_021214e0

The unit remains linked from its delinked original until a human marks it complete.
Names remain the original neutral `func_` symbols: the observed operations do not
establish the surrounding feature's purpose. Partial structures describe only
accessed fields; padding and embedded storage do not imply ownership.

## func_021214e0 — matched (244 bytes)

Contract: accepts an integer mode and returns a Boolean. Mode 2 additionally
requires the work area's ID to equal lookup (8, 3). Rotate its direction by 2,
then adjust signed cell coordinates: direction 1 increments X, 2 increments Y,
3 decrements X, and 0 decrements Y. Query both map tables and test the first
cell's bits 16–19 for 1 and the second cell's first byte for 32. Preserve the
original table-pointer check (which does not check the first cell pointer).
The first cell must therefore exist when the second lookup succeeds.

Evidence: calls to `func_020361ec`, both `Unk038fbc_Unk_039160` calls, and
work fields at 0x358–0x365. Exact object comparison and objdiff both pass.

## func_021215d4 — matched (184 bytes)

Contract: owner and its selection pointer must be valid. Convert selection
byte +6 back to a byte, then query all three slots before processing results.
For each nonnegative result call `func_02058b14` with the owner's embedded
storage at 0x24a8, the result, and zero. No meaning is assigned to that callee's
zero argument beyond its observed value.

Evidence: selection pointer at 0x3e4, byte at +7, three
`Unk09a268_FindEntry` calls and three guarded `func_02058b14` calls.
Exact object comparison and objdiff both pass.

## func_0212168c — hard list (580 bytes, retained in delink)

Observed behavior: derive a fixed-point camera position from the view pointer
at owner +0, angle at view +0x94 and radius at +0x98, using the signed-halfword
table at 0x0212629c. Configure the view, translate from view +0x70/+0x78,
construct a direction-dependent matrix, submit the 92-byte model selected by
selection byte +6, and finish the geometry sequence. Geometry command ports
0x04000444 and 0x04000448 and the calls shared with `func_020f6f48` support
this description; the higher-level feature remains unknown.

Tried typed vectors, matrices, context and owner/view layouts; inline signed
angle wrapping; rounded signed 64-bit fixed-point multiplication; and explicit
switch assignments. A 580-byte candidate reproduced the instruction sequence
except for two halfword loads: mwcc emitted `[index, table]` where the original
uses `[table, index]`. Multiplication operand order and explicit case-0/case-2
assignments resolved the earlier register and branch differences. Pointer,
array, struct-table, inline-lookup and pointer-subtraction variants did not
resolve the remaining load encodings. The candidate is omitted rather than
claiming a match. This function needs a human decomp.me scratch using
`tools/decompme.py`; no scratch was uploaded.
