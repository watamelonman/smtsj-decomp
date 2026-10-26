# src/game/unit_020a6174.c

## M1-T872

Instruction addresses below refer to the original ARM9 image. Record indices are
unchecked and must be in 0..15; the caller owns all buffers.

- `Unk0a6174_Unk_0a6aac`: adds index times 16 to the base (0x020a6aac).
- `Unk0a6174_Unk_0a6ab4`: adds 0x100 and index times 16 (0x020a6ab4).
- `Unk0a6174_Unk_0a6a88`: returns zero for a null base, otherwise adds twice
  `Unk02f2a8_GridIndex45(x, y)` (0x020a6a88). Coordinates follow that callee's contract.
- `Unk0a6174_FindFree0c`: scans sixteen records for the first zero byte at
  record offset 0x0c, returning its index or -1 (0x020a6174).
- `Unk0a6174_FindFree10d`: same scan using offset 0x10d from the base,
  identifying the second bank's occupancy byte (0x020a61f8).
- `Unk0a6174_ClearBuffers`: clears 0xe14 and 0x200 bytes using
  `func_02008848`; either null pointer prevents both clears (0x020a69d0).
- `func_020a61a0`: rejects occupied first-bank records; otherwise sets +0x0c
  to one and writes the word, halfword, and byte fields through +0x0d.
  Returns one on insertion and zero on rejection (0x020a61a0).
- `func_020a6224`: second-bank insertion with occupancy at +0x0d and a third
  halfword at +8 (0x020a6224). See the hard list below.

## Hard list

- `func_020a6224` remains in the delinked object. A complete C insertion body
  reached 82.61%: all operations and offsets agreed, but the compiler moved the
  stack load of the +0x0a byte before the +8 halfword store, and the signed
  +0x0c byte load before the +0x0b store. Typed record layouts, volatile record
  access, and permutations of field assignments did not reproduce the original
  schedule. The unmatched body was removed; a human can open a decomp.me scratch.

The seven implemented M1-T872 functions are 100% in objdiff. The existing
`Unk0a6174_Unk_0a6548` body also remains at 100%.

## Not done in M1-T873
- `func_020a6280`
- `func_020a6848`
- `Unk0a6174_Unk_0a6548`
- `func_020a68b4`
- `func_020a6a08`
- `func_020a63cc`
- `func_020a6934`
- `func_020a7ca4`

## Not done in M1-T875
- `func_020a7108`
- `func_020a7474`

## Not done in M1-T874
- `func_020a7bd0`
- `func_020a62ec`
- `func_020a6468`
- `func_020a7ae4`
- `func_020a6ac0`
- `func_020a6c98`
- `func_020a6e94`
- `func_020a65c4`
- `Unk0a6174_FindFree0c`: hand-matched
- `Unk0a6174_FindFree10d`: hand-matched
- `Unk0a6174_ClearBuffers`: hand-matched
- `Unk0a6174_Unk_0a6548`: hand-matched
