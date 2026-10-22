# game/unit_0203de08

All six functions in `0x0203DE08`-`0x0203E02C` match the original instruction bytes
and relocations at 100% in objdiff with mwccarm 2.0/sp1p5. Names stay neutral
because the evidence is the instruction stream and the call graph, not strings or
identified game data. Arguments come from `func_0203ac00(index)` rather than from
the handler's caller, so every function takes `void`.

The shared `+0x35C` value is an unsigned halfword inside the work area returned by
`Unk02e000_GetWorkArea`; the same field is read as `FIELD(u16, ..., 92)` from the
`+0x300` sub-block in `src/game/unit_0202f2a8.c`.

| Function | Size | Observed contract and evidence |
| --- | ---: | --- |
| `func_0203de08` | 164 | Reads selections 0 through 4 as signed halfwords. If either of the first two is negative, the fourth argument is the work-area `+0x35C` selector; otherwise it is `Unk02f2a8_Unk_035b08(a, b)`. Forwards value 4, the low bytes of values 2 and 3, and that selector to `func_0204c804`, then sets substate 24. Returns 3. |
| `func_0203deac` | 144 | Reads selections 0 through 3 as signed halfwords and makes the same selector choice as `func_0203de08`. Forwards the low bytes of values 2 and 3 plus the selector to `func_0204c8f4`, then sets substate 24. Returns 3. |
| `Unk03de08_Unk_03df3c` | 76 | Reads selections 0 and 1 as signed halfwords, passes both plus the work-area `+0x35C` selector to `func_0204b74c`, commits via `func_0204b6f4`, and sets substate 24. Returns 3. |
| `Unk03de08_Unk_03df88` | 68 | Reads selections 0 and 1 as signed halfwords and passes both plus the work-area `+0x35C` selector to `func_0204b74c`. Returns 1. |
| `Unk03de08_Unk_03dfcc` | 20 | Commits via `func_0204b6f4`, sets substate 24, and returns 3. |
| `Unk03de08_Unk_03dfe0` | 76 | Reads selections 0 and 1 as bytes, tests the result of `Unk02f2a8_Unk_035b08(a, b)` through `Unk02e000_TestFlag`, and publishes 1 or 0 with `Unk03aae8_Unk_03acf4`. Returns 1. |

## Hard list

None.
