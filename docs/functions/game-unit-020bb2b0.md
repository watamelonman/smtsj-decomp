# src/game/unit_020bb2b0.c

## M1-T058

All eight functions match at 100% in objdiff. Evidence below comes from the
original delinked object's ARM instructions and call relocations. Names remain
neutral because these accesses do not establish the fields' game meanings.
Lookup pointers are borrowed; these functions neither allocate nor free them.
The six handlers forward a value to `Unk03aae8_Unk_03acf4` and return 1.

| Function | Observed behavior and evidence |
| --- | --- |
| `Unk0bb2b0_Thunk_020a1428` | Passes the id and return pointer through to `func_020a1428`; original uses an interworking tail jump (`ldr ip` / `bx ip`). |
| `Unk0bb2b0_Thunk_020a1740` | Passes the id and return pointer through to `func_020a1740`; same interworking tail-jump sequence. |
| `Unk0bb2b0_Unk_0bb2b0` | Calls `Unk0bac80_Unk_0badc0`, loads its word at +0x40, and passes it to `Unk0bac80_Thunk_02044ec4`. Forwards that record's unsigned halfword at +0x1d8, evidenced by `add #0x100` then `ldrh #0xd8`. |
| `Unk0bb2b0_Unk_0bb2ec` | Gets argument 0 from `func_0203ac00`, truncates it to an unsigned 16-bit id (`lsl #16` / `lsr #16`), calls the 0x020a1740 thunk, and forwards the unsigned byte at +0x02 (`ldrb`). |
| `Unk0bb2b0_Unk_0bb314` | Uses the same truncated argument-0 lookup and forwards the unsigned halfword at +0x0c (`ldrh`). |
| `Unk0bb2b0_Unk_0bb33c` | Uses the same truncated argument-0 lookup and forwards the unsigned halfword at +0x14 (`ldrh`). |
| `Unk0bb2b0_Unk_0bb364` | Uses the same truncated argument-0 lookup and forwards the unsigned halfword at +0x0e (`ldrh`). |
| `Unk0bb2b0_Unk_0bb42c` | Truncates argument 0 to an unsigned 16-bit id and forwards `Unk02e000_GetRecordUnk1c(id)` directly. The original makes consecutive getter/setter calls with the getter's r0 result preserved. |

The local partial layouts encode only observed offsets and widths. Explicit
callee prototypes replace unspecified argument lists for these handlers. In
particular, `0bb42c` now expresses its result forwarding in C instead of relying
on a value incidentally left in r0 by a preceding call.

## M1-T059

All six functions match at 100% in objdiff. They take no C parameters: arguments
come from `func_0203ac00`. Each returns status 1. Names remain neutral because
the original instructions establish field widths and offsets, not game meaning.

| Function | Observed behavior and evidence |
| --- | --- |
| `Unk0bb2b0_Unk_0bb38c` | Truncates argument 0 to a 16-bit id, calls the 0x020a1740 thunk and forwards +0x10 (`ldrh`) to `Unk03aae8_Unk_03acf4`. |
| `Unk0bb2b0_Unk_0bb3b4` | Uses the same id lookup and forwards +0x12 (`ldrh`). |
| `Unk0bb2b0_Unk_0bb3dc` | Truncates argument 0 to a 16-bit id, calls the 0x020a1428 thunk and forwards +0x04 (`ldrb`). |
| `Unk0bb2b0_Unk_0bb404` | Uses the same id lookup and forwards +0x05 (`ldrb`). |
| `Unk0bb2b0_Unk_0bb450` | Reads the truncated argument-0 id, then argument 1, then `Unk02e000_GetRecordUnk1c(id)`. Adds the latter two values and passes the full word sum to `Unk02e000_SetRecordUnk1c`; original `add r1, r4, r1` directly precedes the call. The callee stores the low halfword at +0x1c and caps it at 500. See DEC-001 for the caller declaration. |
| `Unk0bb2b0_Unk_0bb490` | Uses the 0x020a1428 lookup, loads the word at +0x24 (`ldr`), and forwards unsigned bits 21..27, evidenced by `lsl #4` followed by `lsr #25`. |

Partial lookup layouts describe borrowed records without assigning unsupported
field meanings. Unsigned addition expresses the ARM word addition modulo 2^32.
The existing matching bodies were retained with typed fields and callee arguments.

## Hard list

None for M1-T058 or M1-T059.
