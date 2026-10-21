# src/game/unit_020bbfa4.c

- `Unk0bbfa4_Unk_0bc0a4`: Forward the input plus six to Unk0a0ce4_Unk_0a0d68; callers at 0x02047d5c and 0x02047d68 supply the input. Its domain is not yet known. ARM objdiff: 100%.
- `Unk0bbfa4_Unk_0bbfa4`: Add argument zero to state slot 12 and return command status 1. Unk118b04_Unk_118e50 stores the sum at state + 0x14 + index * 4. ARM objdiff: 100%.
- `Unk0bbfa4_Unk_0bbfc4`: Add argument zero to state slot 13 and return command status 1. Slot layout is evidenced by Unk118b04_Unk_118e50. ARM objdiff: 100%.
- `Unk0bbfa4_Unk_0bbfe4`: Add argument zero to state slot 14 and return command status 1. Slot layout is evidenced by Unk118b04_Unk_118e50. ARM objdiff: 100%.
- `Unk0bbfa4_Unk_0bc004`: Add argument zero to state slot 15 and return command status 1. Slot layout is evidenced by Unk118b04_Unk_118e50. ARM objdiff: 100%.
- `Unk0bbfa4_Unk_0bc024`: Publish state slot 12 as the command result, clamping signed negative values to zero; return command status 1. The getter uses state + 0x14. ARM objdiff: 100%.
- `Unk0bbfa4_Unk_0bc044`: Publish state slot 13 as the command result, clamping signed negative values to zero; return command status 1. The getter uses state + 0x14. ARM objdiff: 100%.
- `Unk0bbfa4_Unk_0bc064`: Publish state slot 14 as the command result, clamping signed negative values to zero; return command status 1. The getter uses state + 0x14. ARM objdiff: 100%.
- `Unk0bbfa4_Unk_0bc084`: decompiler-derived
- `Unk0bbfa4_Unk_0bc144`: decompiler-derived

## Not done in M1-T037
- `Unk0bbfa4_Unk_0bc17c`
- `func_020bc0b4`
- `Unk0bbfa4_Unk_0bc17c`: hand-matched

## M1-T036 evidence and validation

The eight functions above retain neutral names: the slot mechanics are known,
but the gameplay meaning of slots 12–15 is not established. The four increment
handlers appear in the function table at 0x0212c33c–0x0212c354; the three result
handlers appear at 0x0212c3d4–0x0212c3e4. The result helper
`Unk03aae8_Unk_03acf4` clears byte 0x3b and writes the supplied word at 0xa8
in the current command state. Negative checks interpret the stored word as signed.

The pre-existing C bodies already matched; this card adds explicit helper
prototypes and documents their contracts without changing those bodies.
No hard functions remain among the eight functions assigned to M1-T036.
