# game/unit_020a0ce4 — M1-T447

All eight requested ARM functions match at 100% objdiff with mwccarm 2.0/sp1p5.
Evidence below is from the delinked original's instructions and relocations.
Existing routines belonging to adjacent cards are retained unchanged.

| Function | Address / size | Contract and evidence |
| --- | --- | --- |
| `Unk0a0ce4_Nop_0a0e94` | 0x020a0e94 / 4 B | No arguments or effects; only `bx lr`. The empty C body is the complete original behavior. |
| `Unk0a0ce4_Nop_0a0eb4` | 0x020a0eb4 / 4 B | No arguments or effects; only `bx lr`. |
| `Unk0a0ce4_Nop_0a0eb8` | 0x020a0eb8 / 4 B | No arguments or effects; only `bx lr`. |
| `Unk0a0ce4_Get_data_02176afc` | 0x020a0d94 / 16 B | Returns the unsigned shared word; literal relocation names `data_02176afc`, followed by a single word load. |
| `Unk0a0ce4_Unk_0a0e34` | 0x020a0e34 / 16 B | Calls `func_02053048` then `func_020b72a8`, passing no explicit arguments and discarding results. Broader purpose unknown. |
| `Unk0a0ce4_Unk_0a0e98` | 0x020a0e98 / 28 B | Calls `func_02052528(-1)`, `func_0205e590(0)`, then `func_020a1318()`. The `mvn` and `mov` establish the signed argument values; purpose remains unknown. |
| `Unk0a0ce4_ScaleFx10` | 0x020a1140 / 28 B | Returns zero for scale zero and the input for scale 1024; otherwise multiplies and arithmetic-shifts by 10. The two comparisons, conditional multiply and shift support the existing descriptive name. Callers at 0x020a115c and 0x020a1214 consume the low byte. Signed products must be representable in C; negative products round toward negative infinity. |
| `Unk0a0ce4_Unk_0a0ce4` | 0x020a0ce4 / 32 B | Preserves the signed index, calls `func_020445d0(0, 0)` and `func_0204fde0()`, then adds index shifted left five to the latter result. Callers at 0x020a0da4/0x020a0dd8 restrict indices to 0..299 and read the first two bytes of the returned address. No ownership transfer is evident. |

## Validation

No new behavioral tests are required by this card. Objdiff checks the original
instructions and relocations, including the three intentional no-op functions.
The match, checksum, anticheat and repository unittest gates were run locally.
No requested function remains on the hard list.

## Hard list
- `Unk0a0ce4_Unk_0a0d04`: decompiler-derived
- `Unk0a0ce4_Unk_0a12e8`: decompiler-derived
- `Unk0a0ce4_Unk_0a0d30`: decompiler-derived

## Not done in M1-T448
- `Unk0a0ce4_GetTableEntry`
- `Unk0a0ce4_Unk_0a0d68`
- `Unk0a0ce4_Unk_0a0da4`
- `Unk0a0ce4_Unk_0a0dd8`
- `Unk0a0ce4_Unk_0a0e44`

## Not done in M1-T449
- `func_020a0ebc`
- `func_020a0f20`
- `func_020a115c`
- `func_020a1214`
- `func_020a1318`
- `func_020a0fc0`
- `Unk0a0ce4_Unk_0a0d68`: hand-matched
- `Unk0a0ce4_Unk_0a0da4`: hand-matched
- `Unk0a0ce4_Unk_0a0dd8`: hand-matched
- `Unk0a0ce4_GetTableEntry`: hand-matched
- `Unk0a0ce4_Unk_0a0e44`: hand-matched
