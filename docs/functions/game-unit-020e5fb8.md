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

None for M1-T373. The pre-existing `GetOffset800` candidate is outside this card.

## Not done in M1-T377
- `func_020e5fb8`
- `Unk0e5fb8_Unk_0e622c`: decompiler-derived
- `Unk0e5fb8_Unk_0e631c`: decompiler-derived
- `Unk0e5fb8_Unk_0e639c`: decompiler-derived
- `Unk0e5fb8_Unk_0e641c`: decompiler-derived

## Not done in M1-T375
- `Unk0e5fb8_Unk_0e620c`
- `Unk0e5fb8_Unk_0e626c`
- `Unk0e5fb8_Unk_0e61e8`
- `Unk0e5fb8_Unk_0e62a4`
- `Unk0e5fb8_Unk_0e649c`: decompiler-derived

## Not done in M1-T376
- `Unk0e5fb8_SetBits`
- `Unk0e5fb8_Get2Bits`
- `Unk0e5fb8_Get2BitsB00`
- `Unk0e5fb8_Get2BitsD00`
- `Unk0e5fb8_Get2BitsD80`
- `Unk0e5fb8_Get2BitsD80Hi`
- `Unk0e5fb8_GetBits`
- `Unk0e5fb8_Unk_0e626c`: decompiler-derived (plain cleanup)
- `Unk0e5fb8_Unk_0e61e8`: decompiler-derived (plain cleanup)
- `Unk0e5fb8_Unk_0e62a4`: decompiler-derived (plain cleanup)
- `Unk0e5fb8_GetOffset900`: hand-matched
- `Unk0e5fb8_GetOffsetB00`: hand-matched
- `Unk0e5fb8_GetOffsetD00`: hand-matched
- `Unk0e5fb8_GetOffsetD80`: hand-matched
- `Unk0e5fb8_GetOffset800`: hand-matched
- `Unk0e5fb8_GetBits`: hand-matched
- `Unk0e5fb8_SetBits`: hand-matched
- `Unk0e5fb8_Unk_0e620c`: hand-matched
- `Unk0e5fb8_Get2Bits`: hand-matched
- `Unk0e5fb8_Get2BitsB00`: hand-matched
- `Unk0e5fb8_Get2BitsD00`: hand-matched
- `Unk0e5fb8_Get2BitsD80`: hand-matched
- `Unk0e5fb8_Get2BitsD80Hi`: hand-matched
