# src/game/unit_020986ac.c

M1-T631: all eight functions match the original ARM instructions at 100% objdiff.
Addresses below refer to the original `extract/arm9/arm9.bin`; symbol boundaries
come from `config/arm9/symbols.txt`. Storage ownership remains with the base provider.

| Function | Contract and instruction evidence |
| --- | --- |
| `Unk0986ac_Nop_099230` | No arguments or effects; 0x02099230 is `bx lr` (4 B). |
| `Unk0986ac_Unk_098978` | Returns the supplied signed id minus 111; `sub r0, r0, #111` at 0x02098978 (8 B). BattleShowingTask callers feed this result to the flag-test wrapper. |
| `Unk0986ac_Thunk_02098714` | Returns `Unk0986ac_TestFlagBit(bit)` unchanged; indirect tail branch at 0x0209896c (12 B). |
| `Unk0986ac_Unk_09894c` | Forwards an in-range bit index and constant 1 to `Unk0986ac_SetFlagBit`; tail branch at 0x0209894c (16 B). |
| `Unk0986ac_Unk_09895c` | Forwards an in-range bit index and constant 0 to `Unk0986ac_SetFlagBit`; tail branch at 0x0209895c (16 B). |
| `Unk0986ac_Unk_098980` | Returns the unsigned byte at storage + 13; calls the base helper then `ldrb r0, [r0, #13]` at 0x02098980 (16 B). The byte's meaning remains unknown. |
| `Unk0986ac_Unk_0986ac` | Returns the borrowed 32-bit base-provider address plus 0x5c80; additions of 0x1c80 and 0x4000 at 0x020986ac (20 B). |
| `Unk0986ac_Unk_0986c0` | Returns the borrowed byte address for a bit index; adds signed `index >> 3` to the base helper result at 0x020986c0 (20 B). Callers must enforce storage bounds. |

No new behavior tests are required by this card: instruction identity is checked
against the original object, with the full-image checksum checking the linked build.
No M1-T631 functions remain on the hard list.

## M1-T632

All eight targets match at 100% objdiff. Existing C bodies already produced the
original instructions; this card verifies them and replaces provisional contracts.

| Function | Contract and instruction evidence |
| --- | --- |
| `Unk0986ac_Unk_098990` | Stores the argument byte at borrowed flag storage +13; `strb` at 0x02098990 (20 B). |
| `Unk0986ac_Unk_099300` | Calls `Unk02e000_Unk_02e0cc`, then `Unk05b82c_Unk_05b82c(191)`, and returns 1; relocations and immediate moves at 0x02099300 (24 B). |
| `Unk0986ac_TestFlagBit` | Tests mask `1 << (bit & 7)` in the byte returned by the storage helper; returns 0 or 1. Caller enforces index bounds; 0x02098714 (44 B). |
| `Unk0986ac_FindEmpty` | Scans 23 two-byte entries for a zero first signed byte; returns the index or sentinel 23. Stride-two loads and zero comparisons at 0x020989dc support the name (44 B). |
| `Unk0986ac_Unk_098918` | Takes a signed id, looks it up with `Unk09974c_Unk_099d78(id)`, and returns 0 for a missing borrowed record or absent middle flag field; otherwise returns `Unk09974c_GetFlagsMidMinus1(record)`. The incoming r0 reaches the lookup at 0x02098920 unchanged; its pointer result remains in r0 for `HasFlagsMid(record)` at 0x0209892c and is saved in r4 for the decoder. Caller 0x020c3090 loads the id from a table into r0 before calling at 0x020c3094 (52 B). |
| `Unk0986ac_IsMode012` | Returns 1 for the selector at +44 equal to 0, 1, or 2, otherwise 0. Three comparisons at 0x02098ae0 support the name (52 B). |
| `Unk0986ac_Unk_0989a4` | Reads the handle at borrowed record +4, looks it up with the third argument, and passes the result as argument five to `func_02061f10(a, -1, 0, 0, result)`; relocations and stack store at 0x020989a4 (56 B). |
| `Unk0986ac_Unk_098aa8` | Reads signed n at +56. For n <= 0 clears word +64 and byte +68; otherwise writes `(word_at_60 - 16) * n + 16` and the low byte of `31 * n`. Caller supplies aligned storage through +68 and representable signed arithmetic; 0x02098aa8 (56 B). |

No M1-T632 functions remain on the hard list. No new behavior tests are required;
objdiff checks instruction identity and checksum checks the linked original image.

## M1-T633

All eight targets match at 100% objdiff. Arguments and record pointers are
borrowed; field names remain neutral where application meaning is unknown.

| Function | Contract and instruction evidence |
| --- | --- |
| `Unk0986ac_Unk_099274` | Copies pending selector +24 to +20, resets +24 to -1, calls `Unk0986ac_Unk_09911c` for 2 or the no-op callback for 3; stores/branches at 0x02099274 (60 B). |
| `Unk0986ac_SetFlagBit` | Sets or clears mask `1 << (bit & 7)` in the borrowed byte selected by the storage helper. Caller enforces index bounds; byte loads/stores at 0x020986d4 (64 B). |
| `Unk0986ac_Unk_099234` | Decrements signed +56, recomputes outputs, then clears words +24/+40/+56/+64 and byte +68 if +56 is nonpositive. Caller supplies aligned storage through +68 and representable decrement; 0x02099234 (64 B). |
| `Unk0986ac_Unk_0992b0` | Dispatches selector +20: case 1 queues 2 at +24 only when the external predicate returns exactly 1; cases 2/4 call their handlers, other cases do nothing. Jump table at 0x020992b0 (80 B). |
| `Unk0986ac_Unk_09911c` | Returns for absent game state; otherwise invokes the operation on state +30104, forwards object +16/+4/+40, and writes boolean +56 from object +40 == 1 or state header +16 == 1. Loads/calls at 0x0209911c (88 B). |
| `func_02098860` | Scans ids 111..210 inclusive for a borrowed record matching the decoded middle field and a nonzero `Unk09974c_Unk_0998d8(id)`; returns 1 on the first match, else 0. Calls/comparisons at 0x02098860 (92 B). |
| `func_020988bc` | Scans the same range for a matching middle field with zero `func_0209a158(id)`; returns 0 on the first such record, otherwise 1. Calls/comparisons at 0x020988bc (92 B). |
| `func_02098740` | Returns the maximum high nibble of halfword +4 among records in ids 111..210 matching the decoded middle field and nonzero external predicate, or zero if none. Halfword load/shifts at 0x02098740 (108 B). |

The three scans use scoped propagation control to retain original loop-entry
checks and register allocation (See DEC-014). No behavior tests are required by
this card; instruction identity and full-image checksum are the acceptance checks.
No M1-T633 functions remain on the hard list.

## M1-T634

All eight targets match at 100% objdiff; all 32 C functions in the unit pass the
match gate. Anticheat, all nine repository tests, and the full-image checksum
pass. All pointers are borrowed;
unknown selectors and record meanings retain the existing neutral symbols.

| Function | Contract and instruction evidence |
| --- | --- |
| `func_02098b14` | Repeatedly probes the external operation while active, queues selector 2 on success, and updates output +60 and predicate +48; calls and stores at 0x02098b14 (136 B). |
| `func_02099318` | Initializes 72 bytes, stores borrowed source/record pointers, creates handle +16, and sets pending selector -1 for a zero source word. The initial load precedes the null check, so the state pointer must be readable; 0x02099318 (144 B). |
| `func_02098a08` | Looks up the record table, finds its first empty entry, and returns the sum of external values 0x5f80/0x5f81 plus 32, with ten units per index above 5, clamped at index 19; 0x02098a08 (160 B). |
| `func_020987ac` | Searches ids 111..210 with a matching middle field and enabled predicate; selectors 0/1/4 accept high nibble >= value, others require equality. Uses the existing DEC-014 scoped propagation control to preserve loop-entry comparisons; 0x020987ac (180 B). |
| `func_02099174` | Updates count +56 and derived outputs, conditionally calls external operation 14, and queues selector 3 when count reaches 1; requires a live state/header when the global state exists; 0x02099174 (188 B). |
| `func_020993a8` | Applies pending state, updates current state, then dispatches selector +44. Cases 0..2 probe signed coordinates at work-area +868/+869; case 4 queues teardown and resets fields; 0x020993a8 (236 B). |
| `func_02098fec` | Probes current coordinates then a direction-selected neighbor; on success stores selector 2, record field +16, coordinate bytes, and derived output. Directions 1/2/3/0 adjust x+/y+/x-/y-; 0x02098fec (304 B). |
| `func_02098b9c` | Probes current record types 1/2 and tile type 36, then direction-adjacent types 24..27; decodes packed permissions and queues selector 2 with kind, enabled status, coordinates, and derived output. Loads, bit shifts, provider calls and stores at 0x02098b9c..02098fe8 establish the contract (1104 B). All provider pointers are borrowed and coordinates must be valid. |

The selector predicate's signature now accepts the two extra integer arguments
observed at the new call sites. Its existing body ignores those arguments and
retains its original instructions. No behavioral tests are required by this card;
standalone instruction comparisons, objdiff, and the ROM checksum validate the work.

The dispatcher uses scoped `opt_lifetimes off` to retain original register
allocation (See DEC-016). Its typed packed fields preserve the original shift
pairs, including the eight-bit index in the type-36 record. All 1104 bytes match.
No M1-T634 functions remain on the hard list.
