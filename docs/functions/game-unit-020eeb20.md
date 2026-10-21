# game/unit_020eeb20

All eight functions match the delinked ARM original at 100% in objdiff.
Names remain neutral because the instructions establish operations and field offsets,
but do not establish a higher-level purpose. Layouts describe only accessed fields;
callback signatures are local contracts inferred from this unit's use.

| Function | Evidence and behavior |
| --- | --- |
| `Unk0eeb20_Unk_0eeb20` | Loads the shared pointer before calling the field-0x10 accessor on its argument, then forwards that value and the shared field 0x44 to `Unk0e8228_Unk_0e8d90`. |
| `Unk0eeb20_Unk_0eeb44` | Calls `func_020f7e48` with the shared field 0x40, zero and seven; calls `func_020f7d7c` with that field and 0x22. |
| `Unk0eeb20_Unk_0eeb74` | The four-way branch table maps the argument's field 0x10 values 0..3 to `func_020ea3cc` arguments 9, 10, 11, 8; other values do nothing. |
| `func_020eebc8` | Writes allocation size 0x50, header value four, and five callback pointers at offsets 0x0c, 0x10, 0x14, 0x1c and 0x20; clears offset 0x18. |
| `Unk0eeb20_Unk_0eec20` | Clears 0x50 bytes through `func_02008848`, publishes the work pointer in `data_02176de8`, and calls `func_020eec4c`. |
| `func_020eec4c` | Sets field 0x40 to 0x22; calls `func_020f711c` with the observed scalar arguments and callbacks at 0x020eee94/0x020eeebc; clears fields 0x44..0x4c. |
| `Unk0eeb20_Nop_0eecb8` | The sole instruction is `bx lr`: an empty callback. |
| `func_020eecbc` | Calls `func_020f7188` before inspecting field 0x08. State 11 calls `Unk0bc1a8_Unk_0bc9b4` with field 0x40 and zero; state 9 becomes 10. All other states are inert. |

The dispatch retains explicit inactive cases because the original has a twelve-entry
branch table; switch breaks reproduce its return epilogues. No module boundary changes.

## Hard functions

None.
