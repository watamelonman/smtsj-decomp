# game/unit_0206e2a0

All eight functions match at 100% objdiff. Evidence below is the original ARM
instructions at each function address; no domain meaning is inferred for keys.
The entry stride is 0x148, with six 24-byte records beginning at +0x2c.
The count lives at `data_0216bac4`; the accessors reproduce the original signed
`count - 1 - index < 0` rejection, rather than introducing a lower-bound check.
Callers must supply valid nonnegative entry indices and subindices where needed.
The layouts are private to this unit, so no module boundary changes are needed.

- `Unk06e2a0_Unk_06e2a0` (0x0206e2a0, 24 bytes): returns the
  entry's +0x2c record region without validating the index. Neutral name retained.
- `func_0206e2b8` (0x0206e2b8, 124 bytes): searches six keys at
  entry +0x30 + j*24; returns the first matching +0x34 word. Returns zero for
  rejected entries or absent keys. The alternate `data_0216bafc` symbol is a
  typed view of +0x34 in the first entry. Original neutral symbol retained.
- `func_0206e334` (0x0206e334, 104 bytes): searches the same six
  keys and returns a borrowed pointer to the first matching record at
  entry +0x2c + j*24, or null for rejected entries or absent keys. The explicit
  cursor preserves the entry base for computing the result. Original neutral
  symbol retained; the key's domain is unknown.
- `Unk06e2a0_GetEntrySubUnk34` (0x0206e39c, 60 bytes): returns the
  +0x34 word selected by entry and subindex. Entry rejection returns zero;
  subindex is unchecked and must be 0..5. Address arithmetic supports the name.
- `Unk06e2a0_CopyEntryBc` (0x0206e3d8, 64 bytes): copies 32 bytes
  from entry +0xbc to the destination through `func_020086bc`.
- `Unk06e2a0_CopyEntryDc` (0x0206e418, 64 bytes): copies 32 bytes
  from entry +0xdc to the destination through `func_020086bc`.
- `Unk06e2a0_CopyEntryFc` (0x0206e458, 64 bytes): copies 32 bytes
  from entry +0xfc to the destination through `func_020086bc`.
- `Unk06e2a0_CopyEntry11c` (0x0206e498, 64 bytes): copies 32 bytes
  from entry +0x11c to the destination through `func_020086bc`.

The copy names are supported by the original source offsets and 32-byte call
argument. Each destination must provide 32 writable bytes. Rejected entries
leave it untouched. Entry and record pointers refer to global storage and do
not transfer ownership.

## Hard list

None.
