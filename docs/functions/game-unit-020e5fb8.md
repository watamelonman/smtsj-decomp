# src/game/unit_020e5fb8.c

- `Unk0e5fb8_Unk_0e6158` (8 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e5fb8_Unk_0e61b0` (12 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e5fb8_Unk_0e61bc` (12 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e5fb8_Unk_0e6254` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e5fb8_Unk_0e628c` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e5fb8_Unk_0e62c8` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e5fb8_Unk_0e6348` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e5fb8_Unk_0e63c8` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e5fb8_Unk_0e6448` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e5fb8_Unk_0e64c8` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk0e5fb8_Unk_0e61c8` (32 B): decompiler-derived (Ghidra output, cleaned)

## M1-T373 verification

All eight card functions match the delinked ARM object at 100% objdiff.
Existing C bodies already matched and were retained. Parameters are 32-bit integers;
these helpers do not take ownership of storage. No module boundary changed.

| Function | Contract and evidence |
| --- | --- |
| `Unk0e5fb8_Unk_0e6158` | At 0x020e6158, adds 0x8e0 to the unchecked argument. Caller 0x020e626c passes the result to `Unk094fe0_TestBit`, supporting bit-index units. |
| `Unk0e5fb8_Unk_0e61b0` | At 0x020e61b0, adds 0xff then 0x200, returning argument + 0x2ff. No bounds check; domain meaning remains unknown. |
| `Unk0e5fb8_Unk_0e61bc` | At 0x020e61bc, adds 0x7f then 0x300, returning argument + 0x37f. No bounds check; domain meaning remains unknown. |
| `Unk0e5fb8_GetOffset900` | At 0x020e6160, unsigned indices >= 256 select zero; returns 0x900 + 2 * index. `Get2Bits` consumes the result as a bit index. |
| `Unk0e5fb8_GetOffsetB00` | At 0x020e6174, unsigned indices >= 256 select zero; returns 0xb00 + 2 * index. `Get2BitsB00` consumes the result as a bit index. |
| `Unk0e5fb8_GetOffsetD00` | At 0x020e6188, unsigned indices >= 64 select zero; returns 0xd00 + 2 * index. `Get2BitsD00` consumes the result as a bit index. |
| `Unk0e5fb8_GetOffsetD80` | At 0x020e619c, unsigned indices >= 128 select zero; returns 0xd80 + 4 * index. `Get2BitsD80` and `Get2BitsD80Hi` address four bits with this base. |
| `Unk0e5fb8_Unk_0e6254` | At 0x020e6254, saves its argument across `Unk094fe0_Thunk_0202e8cc(void)` and calls 0x020e626c with the context and original argument. Preserves the existing void C interface; no semantic name is inferred. |

Offsets above count bits, not bytes. The unsigned comparisons also redirect indices
with the high bit set to entry zero. The three unchecked addition helpers require
inputs whose signed addition is representable under their existing C signatures.

## Hard list

None for M1-T373 or M1-T374.

## Not done in M1-T377
- `func_020e5fb8`

## Outside the M1-T375 card
- `Unk0e5fb8_Unk_0e649c` (100%): low-pair setter for the 0xd80 table. M1-T375 replaced its
  stale `GetOffsetD80()` declaration with the typed one and passes the index explicitly.

## M1-T376 verification

All eight card functions match at 100% objdiff (build/report.json). The existing hand-matched
bodies were kept. M1-T376 added a comment to each one and moved the `Unk094fe0_TestBit`
prototype above `GetBits`, its first user, so no call goes through an implicit declaration.
The descriptive names (`GetBits`, `SetBits`, `Get2Bits*`) describe what the code does and are
backed by the instructions cited below. Offsets count bits. The context borrows storage.

| Function | Size | Contract and evidence |
| --- | --- | --- |
| `Unk0e5fb8_GetBits` | 76 B | At 0x020e60b4, loops i < n, calling `TestBit(context, b + i)` and ORing `1 << i` for each set bit. Returns the bits packed LSB first; n <= 0 returns 0. |
| `Unk0e5fb8_SetBits` | 60 B | At 0x020e6100, writes `(bits >> i) & 1` to bit `a + i` through 0x0209502c for i < n. The inverse of `GetBits`. |
| `Unk0e5fb8_Get2Bits` | 60 B | At 0x020e62e0, calls `GetOffset900(b)` (b >= 256 selects 0) and returns `TestBit(o) \| TestBit(o+1) << 1` truncated to u8. Counterpart of setter 0x020e631c. |
| `Unk0e5fb8_Get2BitsB00` | 60 B | At 0x020e6360, the same read through `GetOffsetB00` (b >= 256 selects 0). Counterpart of 0x020e639c. |
| `Unk0e5fb8_Get2BitsD00` | 60 B | At 0x020e63e0, the same read through `GetOffsetD00` (b >= 64 selects 0). Counterpart of 0x020e641c. |
| `Unk0e5fb8_Get2BitsD80` | 60 B | At 0x020e6460, reads bits 0..1 of four-bit entry b through `GetOffsetD80` (b >= 128 selects 0). Counterpart of 0x020e649c. |
| `Unk0e5fb8_Get2BitsD80Hi` | 60 B | At 0x020e64e0, reads bits 2..3 of the same entry (TestBit at o+2 and o+3). |
| `Unk0e5fb8_Unk_0e649c` | 44 B | At 0x020e649c, writes value bits 0 and 1 to the low pair of the 0xd80 entry through `GetOffsetD80`. Higher value bits are ignored. |

Hard list for M1-T376: none. No new tests, because the card does not require them and objdiff
already checks the original instructions.

## M1-T374 verification

The eight existing C bodies match at 100% objdiff and are retained. Typed callee
prototypes replace unspecified argument lists. Neutral wrapper names and existing
void interfaces are retained: the instructions alone do not establish domain names
or a caller-visible return contract. Context storage remains owned by the thunk.
No module boundary changed.

| Function | Contract and instruction evidence |
| --- | --- |
| `Unk0e5fb8_Unk_0e628c` | 24 B at 0x020e628c: preserves the unchecked index across the context thunk and calls 0x020e62a4 with context/index. That helper sets the bit at index + 0x8e0. |
| `Unk0e5fb8_Unk_0e62c8` | 24 B at 0x020e62c8: forwards context/index to `Get2Bits`, which reads the pair at base 0x900; unsigned indices >= 256 select zero. |
| `Unk0e5fb8_Unk_0e6348` | 24 B at 0x020e6348: forwards context/index to `Get2BitsB00`, which reads the pair at base 0xb00; unsigned indices >= 256 select zero. |
| `Unk0e5fb8_Unk_0e63c8` | 24 B at 0x020e63c8: forwards context/index to `Get2BitsD00`, which reads the pair at base 0xd00; unsigned indices >= 64 select zero. |
| `Unk0e5fb8_Unk_0e6448` | 24 B at 0x020e6448: forwards context/index to `Get2BitsD80`, which reads the low pair of a four-bit entry at base 0xd80; unsigned indices >= 128 select zero. |
| `Unk0e5fb8_Unk_0e64c8` | 24 B at 0x020e64c8: forwards context/index to `Get2BitsD80Hi`, which reads the high pair of the same four-bit entry; unsigned indices >= 128 select zero. |
| `Unk0e5fb8_GetOffset800` | 28 B at 0x020e613c: multiplies row by ten, replaces unsigned columns >= 10 with zero, then returns 0x800 + row * 10 + column. Caller 0x020e61e8 passes this to `TestBit`, supporting bit-index units. Signed row arithmetic must remain representable. |
| `Unk0e5fb8_Unk_0e61c8` | 32 B at 0x020e61c8: preserves row/column in r5/r4 across the context thunk, then forwards context/row/column to 0x020e61e8, which reads the bit selected by `GetOffset800`. |

Validation: match gate (including build), anticheat, unit tests, and ROM checksum.
No new tests: the card exempts tests, and objdiff verifies the original instructions.

## M1-T375 verification

All eight card functions match the delinked ARM instructions at 100% objdiff.
The existing bodies were retained, with explicit index arguments in the three
pair setters and typed external callee declarations. Neutral names and existing
void interfaces are retained because domain meanings and caller-visible return
contracts are not established. Context arguments borrow storage; no ownership
changes or module boundary changes occur.

| Function | Size | Contract and evidence |
| --- | --- | --- |
| `Unk0e5fb8_Unk_0e620c` | 32 B | ARM at 0x020e620c saves row/column across the shared-context thunk and passes them with its result to 0x020e622c. |
| `Unk0e5fb8_Unk_0e626c` | 32 B | ARM at 0x020e626c computes index + 0x8e0 through 0x020e6158 and calls TestBit with the supplied context. Index addition is unchecked. |
| `Unk0e5fb8_Unk_0e61e8` | 36 B | ARM at 0x020e61e8 calls GetOffset800(row, column), then TestBit(context, offset). Columns >= 10 select zero; row arithmetic must be representable. |
| `Unk0e5fb8_Unk_0e62a4` | 36 B | ARM at 0x020e62a4 computes index + 0x8e0 and calls 0x0209502c with the supplied context and value 1. Signed index addition must be representable. |
| `Unk0e5fb8_Unk_0e622c` | 40 B | ARM at 0x020e622c calls GetOffset800(row, column), then 0x0209502c(context, offset, 1); same row/column contract as the reader. |
| `Unk0e5fb8_Unk_0e631c` | 44 B | ARM at 0x020e631c passes the index to GetOffset900 and writes value bits 0 and 1 through the shared-context setter at consecutive bit offsets. Unsigned indices >= 256 select zero. |
| `Unk0e5fb8_Unk_0e639c` | 44 B | ARM at 0x020e639c uses GetOffsetB00 and the same two writes; unsigned indices >= 256 select zero. |
| `Unk0e5fb8_Unk_0e641c` | 44 B | ARM at 0x020e641c uses GetOffsetD00 and the same two writes; unsigned indices >= 64 select zero. |

The pair setters ignore value bits above bit 1 and use an arithmetic right shift
of the signed masked second bit, matching the original instruction sequence.
No new tests are required by the card: objdiff checks the original instructions.
Hard list for M1-T375: none.
