# src/game/unit_020986ac.c

M1-T631: all eight functions match the original ARM instructions at 100% objdiff.
Addresses below refer to the original `extract/arm9/arm9.bin`; symbol boundaries
come from `config/arm9/symbols.txt`. Storage ownership remains with the base provider.

| Function | Contract and instruction evidence |
| --- | --- |
| `Unk0986ac_Nop_099230` | No arguments or effects; 0x02099230 is `bx lr` (4 B). |
| `Unk0986ac_Unk_098978` | Returns the supplied signed id minus 111; `sub r0, r0, #111` at 0x02098978 (8 B). BattleShowingTask callers feed this result to the flag-test wrapper. |
| `Unk0986ac_Thunk_02098714` | Returns `Unk0986ac_TestFlagBit(bit)` unchanged; indirect tail branch at 0x0209896c (12 B). |
| `Unk0986ac_Unk_09894c` | Forwards an in-range bit index and constant 1 to `Unk0986ac_SetFlagBit`; tail branch at 0x0209894c (16 B). |
| `Unk0986ac_Unk_09895c` | Forwards an in-range bit index and constant 0 to `Unk0986ac_SetFlagBit`; tail branch at 0x0209895c (16 B). |
| `Unk0986ac_Unk_098980` | Returns the unsigned byte at storage + 13; calls the base helper then `ldrb r0, [r0, #13]` at 0x02098980 (16 B). The byte's meaning remains unknown. |
| `Unk0986ac_Unk_0986ac` | Returns the borrowed 32-bit base-provider address plus 0x5c80; additions of 0x1c80 and 0x4000 at 0x020986ac (20 B). |
| `Unk0986ac_Unk_0986c0` | Returns the borrowed byte address for a bit index; adds signed `index >> 3` to the base helper result at 0x020986c0 (20 B). Callers must enforce storage bounds. |

No new behavior tests are required by this card: instruction identity is checked
against the original object, with the full-image checksum checking the linked build.
No M1-T631 functions remain on the hard list.

## Hard list
- `Unk0986ac_Unk_098990`: decompiler-derived
- `Unk0986ac_Unk_099300`: decompiler-derived
- `Unk0986ac_Unk_098918`: decompiler-derived

## Not done in M1-T632
- `Unk0986ac_TestFlagBit`
- `Unk0986ac_FindEmpty`
- `Unk0986ac_IsMode012`
- `Unk0986ac_Unk_0989a4`
- `Unk0986ac_Unk_098aa8`

## Not done in M1-T633
- `Unk0986ac_Unk_099274`
- `Unk0986ac_SetFlagBit`
- `Unk0986ac_Unk_099234`
- `Unk0986ac_Unk_0992b0`
- `Unk0986ac_Unk_09911c`
- `func_02098860`
- `func_020988bc`
- `func_02098740`

## Not done in M1-T634
- `func_02098b14`
- `func_02099318`
- `func_02098a08`
- `func_020987ac`
- `func_02099174`
- `func_020993a8`
- `func_02098fec`
- `func_02098b9c`
- `Unk0986ac_SetFlagBit`: hand-matched
- `Unk0986ac_TestFlagBit`: hand-matched
- `Unk0986ac_Unk_0989a4`: hand-matched
- `Unk0986ac_FindEmpty`: hand-matched
- `Unk0986ac_Unk_098aa8`: hand-matched
- `Unk0986ac_IsMode012`: hand-matched
- `Unk0986ac_Unk_099234`: hand-matched
- `Unk0986ac_Unk_099274`: hand-matched
- `Unk0986ac_Unk_0992b0`: hand-matched
- `Unk0986ac_Unk_09911c`: hand-matched
