# src/game/unit_021241ec.c

## M1-T227

All eight functions below match the delinked ARM object at 100% objdiff.
Evidence is the disassembly of `build/delinks/src/game/unit_021241ec.o`;
addresses refer to the original ARM9 image. Neutral names are retained because
field meanings and the wider lifecycle are not established.

| Function | Size | Observed behavior and contract |
| --- | --- | --- |
| `Unk1241ec_Unk_1241ec` | 40 B | At 0x021241ec, calls `Unk0fedd4_Unk_0fedd4`, allocates with selector 1, sets fields 0x0c/0x10 to 0/43, then field 0x1c to 5. Takes no arguments. |
| `Unk1241ec_Unk_124214` | 16 B | At 0x02124214, calls `Unk0fedd4_Unk_0fee18` then `Unk0fedd4_Thunk_0205bb68`. Takes no arguments. |
| `Unk1241ec_Thunk_02124338` | 12 B | At 0x0212424c, interworking tail transfer through the literal address of `func_02124338`. Takes no arguments. |
| `Unk1241ec_Unk_124284` | 24 B | At 0x02124284, stores the full unsigned word argument at work offset 0x28 if `data_02176e84` is nonnull. |
| `Unk1241ec_Unk_12429c` | 24 B | At 0x0212429c, same optional-work contract, offset 0x2c. |
| `Unk1241ec_Unk_1242b4` | 24 B | At 0x021242b4, same optional-work contract, offset 0x30. |
| `Unk1241ec_Unk_1242cc` | 24 B | At 0x021242cc, same optional-work contract, offset 0x34. |
| `Unk1241ec_Unk_1242e4` | 24 B | At 0x021242e4, same optional-work contract, offset 0x38. |

The setters borrow the global allocation without taking ownership. They accept
any 32-bit value and do nothing when the pointer is null. Existing C already
matched all eight targets at baseline; this task adds explicit callee prototypes
and behavior contracts without changing their instructions.

## Other existing functions

- `Unk1241ec_Unk_124224`: forwards the current byte selector and the low 16 bits of x + 200 through `Unk0cb32c_Unk_0cb4e4` to `Unk0fedd4_Unk_0fee38`; already matched.
- `Unk1241ec_Unk_124258`: releases nonnull work and clears the global pointer; already matched.
- `Unk1241ec_Unk_1242fc`: conditionally resets words 0x28/0x2c/0x3c/0x38 to 1/0/1/0; already matched.

## Hard list

None for M1-T227. `func_02124338` remains supplied by the delinked object and
is outside this card.
