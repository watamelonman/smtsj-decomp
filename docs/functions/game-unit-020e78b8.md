# game/unit_020e78b8

The four functions are ARM code. Layouts are partial and use neutral field names;
array extents cover the four words cleared or copied by these functions.

- `Unk0e78b8_IsState5`: returns false if `data_02176cd8` is null,
  otherwise compares its word at +0x10 with 5. This comparison is the evidence
  for the existing descriptive name. Takes no parameters.
- `func_020e78e4`: takes a writable descriptor and installs allocation size
  0x5c, kind 4, and six callback addresses; leaves +0x08 untouched.
- `func_020e7940`: takes writable work and a message. Type 1 forwards work
  with argument zero to `Unk0bc1a8_Unk_0bc504`. Type 4 reads payload +0x08
  when flag bit 1 is set. Values 1 and 3 reset +0x34/+0x38; value 1 also
  clears the four words at +0x04 and copies the four words at +0x14 there.
  The zero-initialized result aggregate preserves the original stack-backed
  extraction result without volatile accesses. Other types/values do nothing.
- `Unk0e78b8_Unk_0e7a30`: takes writable 0x5c-byte work, publishes it in
  `data_02176cdc`, initializes scalar fields, clears four 16-byte regions,
  calls `Unk05b82c_Unk_05b82c(65)`, and saves the resource call's return
  value at +0x54. The data reference alone does not establish a broader name.

## Hard list

None.
