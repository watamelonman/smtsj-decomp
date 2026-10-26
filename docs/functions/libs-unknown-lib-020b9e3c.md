# libs/unknown/lib_020b9e3c — M2-T081

The eight functions below are parameterless ARM callbacks returning an `int`.
Each calls `func_020b8b38(id, 0, 0, 0)`, passes its integer result to
`Unk03aae8_Unk_03acf4`, then returns 1 regardless of that result.
The original instructions provide the contracts; the IDs' meanings remain unknown.
Existing `func_` symbols are retained to match the protected symbol configuration.

## Source investigation

Searched public NitroSDK / pret/pokeplatinum sources before reconstruction
([public repository](https://github.com/pret/pokeplatinum)). No matching source was
identified. Despite the library split label, the original callees access game state:
`func_020b8b38` stores the four arguments at offsets 0x20 through 0x2c of the
object returned by `Unk044904_Unk_045064`, calls `func_0204e9d8`, and normalizes
its result to 0 or 1. `Unk03aae8_Unk_03acf4` clears byte 0x3b and writes the
result to word 0xa8 of the state pointed to by `data_0215de34 + 4`.
These observations support integer arguments/results but no SDK or semantic name.

## Functions

| Symbol | ID | Original size | Contract / evidence |
| --- | ---: | ---: | --- |
| `func_020b9eec` | 95 | 36 bytes | At `0x020b9eec`, submit ID 95 with three zeros, publish the result, return 1. |
| `func_020b9f10` | 96 | 36 bytes | At `0x020b9f10`, submit ID 96 with three zeros, publish the result, return 1. |
| `func_020b9f34` | 97 | 36 bytes | At `0x020b9f34`, submit ID 97 with three zeros, publish the result, return 1. |
| `func_020b9f58` | 98 | 36 bytes | At `0x020b9f58`, submit ID 98 with three zeros, publish the result, return 1. |
| `func_020b9f7c` | 99 | 36 bytes | At `0x020b9f7c`, submit ID 99 with three zeros, publish the result, return 1. |
| `func_020b9fa0` | 100 | 36 bytes | At `0x020b9fa0`, submit ID 100 with three zeros, publish the result, return 1. |
| `func_020b9fc4` | 101 | 36 bytes | At `0x020b9fc4`, submit ID 101 with three zeros, publish the result, return 1. |
| `func_020b9fe8` | 102 | 36 bytes | At `0x020b9fe8`, submit ID 102 with three zeros, publish the result, return 1. |

## Validation

All eight bodies passed the objdiff match gate at 100% individually. The full
build/checksum gate reported all artifacts byte-identical to the original.
Anticheat passed, as did all nine repository unit tests. No new behavioral tests are required by this card; instruction equality is
the acceptance oracle. The TU remains linked from the original delink until a
human marks it complete.

## Hard list

None for M2-T081. Functions outside the eight listed above belong to other cards
and remain in the original delink.
