# src/game/unit_0209e96c.c

All three M1-T172 functions match the delinked ARM originals at 100% objdiff.
Names remain neutral because the specific gameplay meaning is not established.

- `Unk09e96c_Unk_09e96c` (96 bytes): obtains the global state, resolves the
  first argument through `Unk095560_Unk_095764` and `func_0204fe18`, stores the
  result and the second argument at +0x7434/+0x7438, initializes +0x7430 from
  `func_0204fde0`, invokes `func_02052d7c`, and selects mode 14. Null state is
  accepted. Arguments retain their full unsigned 32-bit values.
- `Unk09e96c_Unk_09e9cc` (76 bytes): initializes the same mode-14 state with
  zero arguments, calling `Unk095560_Unk_095764(0)` for its side effects.
  Null state is a no-op.
- `func_0209ea18` (440 bytes): uses signed grid coordinates to obtain an entry
  and a second source cell. Entry types 4–7 select record 4, 8–9 select record
  5, 24–25 select record 16, and 26–27 select record 17. Other types do nothing.
  Records 16 and 17 choose kind 1 or 3 by `Unk09a268_IsType1`; records 4 and 5
  use kind 1. The selected record's byte +0x19 sets the destination bit,
  destination byte +1 receives the kind, and its halfword +2 is cleared.
  The root's +0x5c flag becomes 1, the +0x58 notification is submitted, and
  the +0xa8 payload/+0xa4 argument are passed to `func_02052d7c`. Finally it
  stores the coordinates as bytes at +0x7482/+0x7483 and selects mode 15.
  Missing state, entry, source or record returns early. Coordinates must satisfy
  the existing grid accessors' contracts; the destination is assumed valid.

Evidence is the original instruction stream's accessor calls, byte/halfword
loads and stores, and mode constants. Local partial views describe the touched
fields without changing shared GameState ownership. The switch omits inactive
cases, reproducing the original branch table with ordinary C. The +0x3e4 table is
a typed `unk_03e4` member (size unknown) and the destination cell uses its own
typed local; both still match at 100%. The offsets are listed in docs/structs.md
for later folding into `GameState`.

Validation: project build and objdiff match gate; anticheat, unittest and ROM
checksum gates. No additional behavior tests are required by this matching card.

## Hard list

None.
