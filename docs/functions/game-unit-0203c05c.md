# game/unit_0203c05c

All seven functions match at 100% in objdiff. Names remain neutral because the
instruction sequences establish argument forwarding and dispatch, but do not
establish the commands' higher-level meaning. All handlers take no C arguments;
arguments are fetched by index through `func_0203ac00`.

| Function | Evidence and behavior |
| --- | --- |
| `Unk03c05c_Unk_03c05c` | 0x0203c05c–0x0203c084: forwards the full first argument to `ImageBgDual3D_Unk_125d10` only when `func_02095818` returns 5; returns 1. |
| `Unk03c05c_Unk_03c088` | 0x0203c088–0x0203c0c4: sign-extends two arguments from 16 bits, calls `ImageObj_Unk_077894`, calls `Unk02dcfc_SetCode8`, then calls `ScanVisor_Unk_0a2920(0)`; returns 3. |
| `Unk03c05c_Unk_03c0c8` | 0x0203c0c8–0x0203c0e8: sign-extends argument 0 from 16 bits, calls `ImageObj_Unk_0778d4`, then `Unk02dcfc_SetCode8`; returns 3. |
| `Unk03c05c_Unk_03c0ec` | 0x0203c0ec–0x0203c130: sign-extends three arguments from 16 bits and forwards them to `func_0209ed78`; returns 3. |
| `Unk03c05c_Unk_03c134` | 0x0203c134–0x0203c140: calls `Unk09ee4c_Unk_09ee4c`; returns 3. |
| `Unk03c05c_Unk_03c144` | 0x0203c144–0x0203c19c: reads three signed 16-bit arguments, writes 15 to work +0x18, and calls `func_0209e49c` in argument order 1,2,0; returns 3. |
| `func_0203c1a0` | 0x0203c1a0–0x0203c270: sign-extends argument 0 from 8 bits and maps nonzero argument 1 to flag 8. Calls `Unk111400_Unk_111474` with these and zero. Mode 0 calls `Unk09e418_Unk_09e468`, mode 2 calls `Unk0de678_Unk_0df584`; both then pass work to `Unk02dcfc_Unk_02de58`. Modes 3/4/5 call `Unk116598_Unk_11671c`, `Unk116598_Unk_117984`, or `ImageBgDual3D_Unk_1259e0`, respectively, and write work code 19/20/20 with work +0x1c cleared. Other modes do no further work; returns 3. |

The local partial context records only its work pointer at +0xe8. The partial
work layout records the 32-bit fields at +0x18 and +0x1c. Padding denotes unknown
fields, not established array bounds. These layouts stay local to this unit.

## Hard list

None.
