# game/unit_0206f6e4

Both functions retain their original neutral symbols. The `VER` signature and
`UniteEvent_LoadEffects` callers establish resource loading and conversion, but
do not establish a more specific format name. Both match at 100% objdiff.

## func_0206f6e4 — 0x0206f6e4, 148 bytes

Takes a terminated path containing `/`. Looks up the suffix in the slot table,
returning an existing slot immediately. Otherwise loads the file, verifies the
three signed signature bytes against `VER`, allocates a slot, converts the file
through `func_0206f778`, and frees the file. Returns 255 on a missing file or bad
signature. The original bad-signature error path does not release the buffer;
this behavior is preserved. `UniteEvent_LoadEffects` supplies paths built from
`Data/Effect/%s` and stores the returned slot in its destination byte.

## func_0206f778 — 0x0206f778, 1016 bytes

Takes a slot and a borrowed complete file buffer. Requires a valid slot and at
most 16 records. Allocates and clears 8832 bytes for 16 runtime records. Checks
`VER`, reads the ASCII version digits at +4/+5, and selects either 552-byte
records or conversion from 544-byte records starting at +484. Legacy conversion
copies the leading and trailing strings, preserves the 308-byte aggregate, copies
168 bytes from +340, moves flag bytes, and clears version-dependent fields.

Copies four 32-byte auxiliary blocks, using the original eight-byte spacing;
older versions receive zero blocks with the first three bytes set to 255.
Resolves each trailing string through `func_02071efc`, installs the records and
header blocks through the existing slot helpers, releases temporary storage,
and returns the slot. The bad-signature path returns 255 after the error helper
without releasing temporary storage, as in the original. Count reloads follow
DEC-008. Typed record sizes and offsets derive from the original copy lengths,
field accesses, and loop strides; the temporary capacity derives from 8832/552.

## Validation

Instruction comparison matches both original sizes and all instructions.
`match_gate.py` verifies both at 100%; `checksum.py` verifies the original image.
No new tests are required by the card; existing unit tests and anticheat pass.

## Hard list

None.
