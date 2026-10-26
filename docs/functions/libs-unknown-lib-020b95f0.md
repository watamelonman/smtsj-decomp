# lib_020b95f0 — script request wrappers

## Evidence and source search

Searched public sources for `func_020b8b38` / NitroSDK and Strange Journey
script interpreter code; no matching public implementation was found. The ARM
instructions instead follow the existing adjacent `lib_020b91a8` and
`lib_020b9820` wrappers. Each calls operand reader `func_0203ac00`, request
provider `func_020b8b38`, and result writer `Unk03aae8_Unk_03acf4`, then returns
1. The functions use implicit script state and take no explicit parameters.
Request meanings beyond their numeric codes are unproven, so original neutral
symbols are retained. The provider result is forwarded without conversion.

## Functions

| Function | Bytes | Request | Operands | Contract |
| --- | ---: | ---: | --- | --- |
| `func_020b95f0` | 44 | 51 | 0 | Publish provider result; return 1. |
| `func_020b961c` | 56 | 52 | 0, 1 | Publish provider result; return 1. |
| `func_020b9654` | 56 | 53 | 0, 1 | Publish provider result; return 1. |
| `func_020b968c` | 56 | 54 | 0, 1 | Publish provider result; return 1. |
| `func_020b96c4` | 56 | 55 | 0, 1 | Publish provider result; return 1. |
| `func_020b96fc` | 56 | 56 | 0, 1 | Publish provider result; return 1. |
| `func_020b9778` | 56 | 58 | 0, 1 | Publish provider result; return 1. |
| `func_020b97b0` | 56 | 59 | 0, 1 | Publish provider result; return 1. |

Unused request words are zero. Operand reads remain in index order, since the
reader uses shared interpreter state.

## Validation

The original instruction sequences are the regression oracle; no new behavioral
test harness is required by this matching-only card. Objdiff checks every
implemented function against the delinked original.

Verified: all eight requested functions report 100% in objdiff; the match gate
(build included), anticheat gate, all nine unit tests, and checksum gate pass.
Checksum reports all artifacts byte-identical to the original. The TU remains
linked from the delink pending the human completion flag.

## Hard list

None for this card. `func_020b9734` and `func_020b97e8` are outside the eight
requested functions and remain supplied by the delink.
