# game/unit_0203d72c

All eight functions retain neutral names because argument forwarding and field
accesses establish behavior, but do not establish the meaning of the callees.
Evidence is the ARM instruction sequence at each function address in the original
ARM9 image. Every handler returns 3 and takes no C parameters; arguments come from
`func_0203ac00(index)`.

| Function | Size | Observed behavior |
| --- | ---: | --- |
| `Unk03d72c_Unk_03d72c` | 48 | Sign-extend argument 0 from 16 bits, call `Unk09d42c_Unk_09e2f4`, then set substate to 15. |
| `Unk03d72c_Unk_03d75c` | 128 | Read five arguments. If either of the first two is negative, use the unsigned halfword at work-area offset 0x35c; otherwise resolve them through `Unk02f2a8_Unk_035b08`. Pass the result and arguments 2–4 to `func_0209e564`. |
| `Unk03d72c_Unk_03d7dc` | 76 | Pass three full-width arguments to `Unk09ee4c_Unk_09efb4`, then set substate to 15. |
| `Unk03d72c_Unk_03d828` | 52 | Pass two signed 16-bit arguments to `func_0209ea18`. |
| `Unk03d72c_Unk_03d85c` | 52 | Pass two signed 16-bit arguments to `func_0209ebd0`. |
| `Unk03d72c_Unk_03d890` | 48 | Pass signed 16-bit argument 0 to `func_0209ee80`, then set substate to 15. |
| `Unk03d72c_Unk_03d8c0` | 48 | Pass signed 16-bit argument 0 to `Unk09ee4c_Unk_09ef50`, then set substate to 15. |
| `Unk03d72c_Unk_03d8f0` | 64 | Pass unsigned 8/16/8-bit arguments to `Unk094fe0_Unk_095258`. |

Substate is the word at offset 0x18 of the object referenced by context offset
0xe8. Local partial structs describe only these observed fields and the work-area
halfword; padding makes no claim about the contents of unobserved fields.

## Validation

Objdiff reports 100% for all eight functions. The match gate builds the project;
anticheat, all nine existing unit tests, and the full artifact checksum gate pass.
The unit remains linked from the delink pending human completion marking.

## Hard list

None.
