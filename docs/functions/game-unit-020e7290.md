# game/unit_020e7290 — M1-T401

All eight card functions match the delinked ARM originals at 100% objdiff.
Names remain those in `config/arm9/symbols.txt`; no wider lifecycle meaning is inferred.
The work/resource structs are local partial views derived from the accesses below.

| Function | Evidence and contract |
| --- | --- |
| `Unk0e7290_Clear_data_02176cd8` | 020e7644, 20 bytes: writes null to the global work pointer. Does not release the old object. The store supports the existing Clear name. |
| `Unk0e7290_Unk_0e7790` | 020e7790, 24 bytes: if the global exists, stores the supplied word at +0x204. |
| `Unk0e7290_Set_0e7770` | 020e7770, 32 bytes: if the global exists, stores both supplied words at +0 and +4. These stores support the existing Set name. |
| `Unk0e7290_Unk_0e7734` | 020e7734, 60 bytes: rejects a null global or a +0x10 state other than 0 or 5. Otherwise calls `func_02061424` with the work pointer and returns 1. Rejection returns 0. |
| `Unk0e7290_Unk_0e77a8` | 020e77a8, 72 bytes: fetches resource (0x22, 0), queries the base with `func_0204fde0`, clamps the signed index to at least 1, and formats `base + resource[+0xc] * (index - 1)` using `data_02150bf0`. Destination storage belongs to the caller and must fit the formatted result. The existing ImageBg caller supplies its output buffer. |
| `Unk0e7290_Unk_0e77f0` | 020e77f0, 80 bytes: accepts only an existing work in state 0 or 5; clears +8, writes the supplied word to +0xc and clears +0x10. Returns 1 on acceptance, 0 on rejection. |
| `Unk0e7290_Unk_0e747c` | 020e747c, 100 bytes: requires a valid work pointer. Checks all four unsigned byte flags at +0xed, +0x149, +0x1a5 and +0x201. If any is zero, returns 0. Otherwise passes +0x8c to `func_02053000`, clears that field, moves +0xc to +8, clears +0xc and returns 1. |
| `func_020e7840` | 020e7840, 120 bytes: rejects a missing global or state other than 0 or 5. Stores the supplied word at +0xc, calls `func_020e7290(work, 0)`, `func_020e736c(work, 0)` and `Unk0e7290_Unk_0e747c(work)`, then forces +0x10 to 5 and returns 1. Each helper receives the current global, reloaded after the previous call. The third helper's return does not affect acceptance. |

## Validation

The delinked ARM instructions are the behavioral oracle; no new runtime test is
needed for this matching-only card. Each compiled function was compared against
the original instructions and relocations before running the repository gates.

## Hard list

None for M1-T401.

## Outside this card

The remaining TU functions `func_020e74e0`, `func_020e7570`, `func_020e7290`,
`func_020e7658`, and `func_020e736c` remain delinked and are outside M1-T401.
