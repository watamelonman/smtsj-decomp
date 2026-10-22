# src/game/unit_020b28e4.c

## M1-T1037 functions

- `Unk0b28e4_Nop_0b28e4` (4 B): empty callback.
- `Unk0b28e4_Unk_0b64c8` (20 B): returns the byte pointer cached at `+0x04` plus its two-byte header.
- `func_020b6514` (20 B): stores one word at `+0xca0` of the object referenced by the word at `+0x00`.
- `Unk0b28e4_Unk_0b5e10` (28 B): sets the byte at `+0x37` and word at `+0x2c`, then forwards to `func_0205f7f4`.
- `func_020b64dc` (28 B): returns entry `index` (12 bytes each) of the table based at `+0x04`.
- `func_020b64f8` (28 B): stores two words at `+0xc8c` and `+0xc90` of the object referenced by the word at `+0x00`.
- `Unk0b28e4_Unk_0b6338` (56 B): releases the object cached at `+0x04`, clears the cache and restores callback set 13.
- `Unk0b28e4_Unk_0b6370` (68 B): zeroes the command buffer at `+0x04` and its two payload areas.

## Not done in M1-T1038
- `Unk0b28e4_GetEntry34`
- `Unk0b28e4_InitCallbacks`
- `Unk0b28e4_Unk_0b62e8`
- `func_020b3d28`
- `func_020b4fb4`
- `func_020b3570`
- `func_020b5264`
- `func_020b5e2c`

## Not done in M1-T1039
- `func_020b6104`
- `func_020b61f0`
- `func_020b63b4`
- `func_020b5ccc`
- `func_020b593c`
- `func_020b4dd8`
- `func_020b49cc`
- `func_020b5adc`
- `Unk0b28e4_InitCallbacks`: hand-matched
- `Unk0b28e4_Unk_0b5e10`: hand-matched
- `Unk0b28e4_Unk_0b62e8`: hand-matched
- `Unk0b28e4_Unk_0b6338`: hand-matched
- `Unk0b28e4_Unk_0b6370`: hand-matched
- `Unk0b28e4_GetEntry34`: hand-matched
