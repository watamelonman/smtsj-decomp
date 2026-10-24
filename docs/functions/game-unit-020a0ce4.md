# game/unit_020a0ce4 — M1-T447 / M1-T448

All sixteen requested ARM functions match at 100% objdiff with mwccarm 2.0/sp1p5.
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

## M1-T448 functions

These existing C bodies were verified against the delinked ARM instructions;
typed helper declarations and evidence comments now replace incomplete declarations.
Neutral names are retained because the calls establish mechanics, not subsystem meaning.

| Function | Address / size | Contract and evidence |
| --- | --- | --- |
| `Unk0a0ce4_GetTableEntry` | 0x020a0e0c / 40 B | Signed index 0..28 selects a word from `data_0214cc84`; negative or larger indices select word zero. Two signed comparisons and the indexed word load support the table-entry name. |
| `Unk0a0ce4_Unk_0a0d04` | 0x020a0d04 / 44 B | Calls `0205e5ec(0)`, `0205e63c()`, `0205e5ec(1)` in order, then stores 1 in `data_02176afc`. Call relocations and immediate operands establish the sequence. |
| `Unk0a0ce4_Unk_0a0d68` | 0x020a0d68 / 44 B | Preserves its argument across `0205e65c()`, stores 5 in `data_02176afc`, calls `0205e5ec(5)`, then `0205e5ec(argument)`. |
| `Unk0a0ce4_Unk_0a12e8` | 0x020a12e8 / 48 B | Requires a valid borrowed work pointer with a word at +0x1c. Calls `0205bb68()` three times, passes that word to `020629c4`, then clears `data_02176b00`. Ownership of the forwarded value is not established. |
| `Unk0a0ce4_Unk_0a0da4` | 0x020a0da4 / 52 B | Returns -1 for signed indices outside 0..299. Otherwise obtains the entry from `020a0ce4` and passes zero-extended bytes +1 and +0 to `0205e6c0`, returning its result. Evidence: signed comparisons and two `ldrb` instructions. |
| `Unk0a0ce4_Unk_0a0dd8` | 0x020a0dd8 / 52 B | Same bounds and byte order as `020a0da4`, forwarding to `0205e740` and returning its result. |
| `Unk0a0ce4_Unk_0a0d30` | 0x020a0d30 / 56 B | Zero or the current shared value returns immediately. Otherwise calls `0205e65c()`, stores the argument in `data_02176afc`, and calls `0205e5ec(argument)`. Conditional comparisons and store/call order are preserved. |
| `Unk0a0ce4_Unk_0a0e44` | 0x020a0e44 / 80 B | Reads `Unk0b6570_Get_data_02176b88()`. Value 2 calls `020967a4(0)` then `02cbdc(10)`; 3 calls `02cbdc(15)`; 4 calls `02cbdc(1)`; other values return. The three comparisons and immediate call operands provide evidence. |

## Validation

No new behavioral tests are required by this card. Objdiff checks the original
instructions and relocations, including the three intentional no-op functions.
The match, checksum, anticheat and repository unittest gates were run locally.
No requested function remains on the hard list.

## Hard list

None for M1-T447 or M1-T448.

## Outside these cards (M1-T449)

- `func_020a0ebc`
- `func_020a0f20`
- `func_020a115c`
- `func_020a1214`
- `func_020a1318`
- `func_020a0fc0`
