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

## Other existing functions (M1-T059 scope)

These bodies were already present and are retained. The current report also
shows 100% for them; they are not part of M1-T058's eight-function acceptance set.

- `Unk0bb2b0_Unk_0bb38c`: forwards the lookup halfword at +0x10.
- `Unk0bb2b0_Unk_0bb3b4`: forwards the lookup halfword at +0x12.
- `Unk0bb2b0_Unk_0bb3dc`: forwards the 0x020a1428 lookup byte at +0x04.
- `Unk0bb2b0_Unk_0bb404`: forwards the 0x020a1428 lookup byte at +0x05.
- `Unk0bb2b0_Unk_0bb450`: adds argument 1 to the selected record's +0x1c value.
- `Unk0bb2b0_Unk_0bb490`: forwards bits 21 through 27 of the lookup word at +0x24.

## Hard list

None for M1-T058.
