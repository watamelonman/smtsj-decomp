# src/game/unit_0209a268.c

- `Unk09a268_Nop_09b3c8` (4 B): empty callback
- `func_0209a48c` (20 B): bit test. Returns 1 when bit `bit` of the byte at `p` is set, else 0;
  callers use bits 0-2 as a 3-value state selector and bits 3-5 as flags.
- `Unk09a268_Unk_09a7fc` (16 B): decompiler-derived (Ghidra output, cleaned)
- `Unk09a268_Unk_09a820` (16 B): decompiler-derived (Ghidra output, cleaned)
- `Unk09a268_Unk_09c498` (16 B): decompiler-derived (Ghidra output, cleaned)
- `Unk09a268_Unk_09a80c` (20 B): decompiler-derived (Ghidra output, cleaned)
- `Unk09a268_Unk_09a830` (20 B): decompiler-derived (Ghidra output, cleaned)
- `Unk09a268_Unk_09a870` (20 B): decompiler-derived (Ghidra output, cleaned)

## M1-T1010
- `Unk09a268_Unk_09c484` (20 B): returns the address of record `arg0` (stride 0x1c) in table
  `data_0213be64`.
- `Unk09a268_SetCtxUnk38` (24 B): stores its argument at +0x38 of the global context when present.
- `func_0209b720` (28 B): returns the global context's +0x34 word, or 0 when it is null.
- `Unk09a268_SetCtxUnk2c30` (32 B): stores two arguments at +0x2c and +0x30 of the global context
  when present.
- `Unk09a268_IsType1` (32 B): returns 1 when the pointer is non-null and its first byte is 1.
- `Unk09a268_SetBit` (36 B): sets or clears bit `bit` of the byte at `p` depending on `on`.
- `Unk09a268_Unk_09a844` (44 B): returns bit 5 of the state byte when GameState body +0x3e0 is
  nonzero, otherwise 1.
- `Unk09a268_Unk_09b3cc` (44 B): reloads the palette from the work's +0xc field when +0x2c is 0.

## Hard list
- None for this TU.

## Not done in M1-T1010
- `Unk09a268_Unk_09bb38`: decompiler-derived

## Not done in M1-T1011
- `Unk09a268_Unk_09a458`
- `Unk09a268_FindEntry`
- `Unk09a268_Unk_09c4a8`
- `func_0209a4fc`
- `Unk09a268_Unk_09a77c`
- `Unk09a268_SetOnlyBit`
- `func_0209c4e0`
- `Unk09a268_Unk_09cb10`: decompiler-derived

## Not done in M1-T1012
- `Unk09a268_Unk_09a3a0`
- `func_0209a53c`
- `Unk09a268_Unk_09beb0`
- `Unk09a268_Unk_09ae60`
- `func_0209a3ec`
- `func_0209a970`
- `func_0209be20`

## Not done in M1-T1013
- `func_0209cb68`
- `func_0209a588`
- `func_0209a884`
- `func_0209c768`
- `func_0209cd24`
- `func_0209cf54`
- `func_0209aebc`
- `func_0209c090`

## Not done in M1-T1016
- `func_0209c548`
- `func_0209aa00`
- `func_0209c1a0`

## Not done in M1-T1014
- `func_0209bd08`
- `func_0209ce30`
- `func_0209cbf8`
- `func_0209a268`
- `func_0209a638`
- `func_0209b5d8`
- `func_0209c9bc`
- `func_0209c854`
- `Unk09a268_Unk_09beb0`: hand-matched
- `Unk09a268_SetCtxUnk38`: hand-matched
- `Unk09a268_Unk_09a3a0`: hand-matched
- `Unk09a268_Unk_09a458`: hand-matched
- `Unk09a268_SetBit`: hand-matched
- `Unk09a268_FindEntry`: hand-matched
- `Unk09a268_Unk_09a77c`: hand-matched
- `Unk09a268_SetOnlyBit`: hand-matched
- `Unk09a268_SetCtxUnk2c30`: hand-matched
- `Unk09a268_Unk_09c4a8`: hand-matched
- `Unk09a268_IsType1`: hand-matched
- `Unk09a268_Unk_09ae60`: hand-matched

## M1-T1010 review corrections
- `Unk09a268_SetBit` now accepts `u8 *` with a full forward prototype; existing
  integer-address callers convert explicitly at the call boundary.
- `Unk09a268_Unk_09a844` uses a typed partial GameState body layout for +0x3e0
  and returns the bit-test result directly. `include/GameState.h` represents the
  body as opaque bytes, so the accessed body field is described locally.
- `Unk09a268_Unk_09c484` has a full index prototype. Its exceptional index-free
  call in `Unk09a268_Unk_09c498` preserves the original ABI (see DEC-002).
- All eight card functions and all 26 defined functions retain 100% objdiff matches.
