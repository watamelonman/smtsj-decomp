# game/unit_0209974c — M1-T553

The eight functions below match the original ARM instructions at 100% objdiff.
Record views are borrowed and require readable fields; subtraction promotes the
unsigned halfwords to signed 32-bit integers (result range -65535..65535).
Names remain neutral where the field's meaning is unknown.

| Function | Evidence and contract |
| --- | --- |
| `Unk09974c_Unk_099860` | `0x02099860/64`: unsigned halfword loads at +0; returns left minus right. |
| `Unk09974c_Unk_099870` | `0x02099870/74`: unsigned halfword loads at +0; returns left minus right. |
| `Unk09974c_Unk_099880` | `0x02099880/84`: unsigned halfword loads at +0x20; returns left minus right. |
| `Unk09974c_Unk_099890` | `0x02099890/94`: unsigned halfword loads at +0; returns left minus right. |
| `Unk09974c_Unk_0998a0` | `0x020998a0/a4`: unsigned halfword loads at +0; returns left minus right. |
| `Unk09974c_Unk_0998b0` | `0x020998b0/b4`: unsigned halfword loads at +0; returns left minus right. |
| `Unk09974c_GetEntryUnk08` | `0x020998c4` calls `Unk09974c_FindEntry`; `0x020998cc` loads byte +8 only for a nonnull entry; missing ids return zero. Existing name is supported by that load. `BattleShowingTask.c` also uses this result as a category selector. |
| `Unk09974c_Unk_0998d8` | `0x020998dc` forwards the id to `func_0209993c`; signed `gt/le` conditional moves produce exactly 1 for a positive result, otherwise 0. |

`FindEntry` at `0x02099780` scans ten 12-byte range entries, comparing
signed inclusive bounds at +0/+4. The lookup helper remains linked from the
original object, as do all functions outside this card. No module boundary changed.

## Validation

The original disassembly supplies the instruction-level acceptance oracle; the
card requires no new tests. Run the match, checksum, anticheat and unit-test gates.

## M1-T554

The following eight functions match at 100%. All record and resource pointers
are borrowed; cleanup receives a caller-owned writable 0x48-byte area.

| Function | Evidence and contract |
| --- | --- |
| `Unk09974c_HasFlagsMid` | `0x0209a114..a128`: load halfword +4, extract bits 8..11 and return whether nonzero. The observed extraction supports the existing name. |
| `Unk09974c_IsKind1or14` | `0x0209a0f4..a110`: extract byte +0x2a bits 0..6 and compare with 14 and 1, supporting the existing name. |
| `Unk09974c_Unk_099bac` | `0x02099bac..bcf`: zero id returns null; otherwise resolve resource (6, 0), then pass its pointer and id to `func_0204fed8`. |
| `Unk09974c_Unk_099bd4` | `0x02099bd4..bf7`: same resolution contract using resource (7, 0). |
| `Unk09974c_GetFlagsMidMinus1` | `0x0209a12c..a154`: test HasFlagsMid, return -1 when absent, otherwise extract the four-bit field and subtract one (range 0..14). |
| `func_0209a23c` | `0x0209a23c..a264`: category zero returns byte +5 of the `099bfc` record; other categories return zero. Category-zero ids require a present record. |
| `Unk09974c_Unk_09a090` | `0x0209a090..a0bc`: reject signed ids outside 51..110; for accepted ids return whether `099d14` record byte +0x2d is nonzero. The record must exist. |
| `Unk09974c_Unk_09974c` | `0x0209974c..977c`: when word +0 is nonzero, release pointer +0x10, clear that pointer, then clear all 0x48 bytes. Zero marker leaves the area untouched. |

No module boundary changed. The original instruction sequences are the acceptance
oracle; this card explicitly requires no new tests. No M1-T554 hard functions remain.

## M1-T555

All eight requested functions match at 100% objdiff. Existing matching C was
retained, with typed parameters and instruction evidence documented; the missing
`func_0209a158` implementation was added. No hard functions remain for this card.

| Function | Evidence and contract |
| --- | --- |
| `Unk09974c_Unk_09a0c0` | `0x0209a0c0..a0f0`: signed ids 51..110 require a present record; byte +0x2d equal to 1 or 3 returns 1, otherwise 0. |
| `Unk09974c_SetBit6ac` (card: `Unk09974c_SetSeenBit`) | `0x0209a1a0..a1e0`: set bit `(id - 51) & 7` at subblock +0x6ac plus signed byte index `(id - 51) >> 3`; indices >=162 are ignored. Callers require id >=51. The protected symbol map names this SetBit6ac, so that linker name is preserved; gameplay meaning “seen” is not established. |
| `Unk09974c_FindEntry` | `0x02099780..97c4`: scan ten 12-byte entries with signed inclusive bounds; return a borrowed entry or null. |
| `func_0209a158` | `0x0209a158..a19c`: test the same +0x6ac bit, returning exactly 0 or 1; indices >=162 return 0. Callers require id >=51. Subblock storage is borrowed. |
| `Unk09974c_Unk_0998f0` | `0x020998f0..9938`: absent entries or zero helper results return 0; mode byte +9 equal to 1 additionally requires signed result >=99; otherwise return 1. |
| `Unk09974c_Unk_099cc4` | `0x02099cc4..9d10`: multiply unsigned ten-bit field +4 by halfword percent +0x0e, divide unsigned by 100 and clamp nonzero products to at least 1; either zero input returns 0; 100 percent returns the field directly. |
| `Unk09974c_Unk_0999d4` | `0x020999d4..9a24`: mode 2 reads halfword at index id minus entry lower bound in the selected borrowed buffer; absent entry or other modes return 0. |
| `Unk09974c_Unk_099abc` | `0x02099abc..9b0c`: absent entry or zero value does nothing; mode 2 writes the indexed halfword; all present modes with nonzero value call SetBit6ac. The selected mode-2 buffer must be writable. |

No module boundary changed. Instruction comparison is the acceptance oracle;
this card requires no new tests. The TU remains linked from the original delink
until a human marks it complete.

## Not done in M1-T556
- `Unk09974c_Unk_099f24`
- `Unk09974c_Unk_09a1e4`
- `Unk09974c_Unk_099bfc`
- `Unk09974c_Unk_099c60`
- `Unk09974c_Unk_099d14`
- `Unk09974c_Unk_099d78`
- `Unk09974c_Unk_099ddc`
- `Unk09974c_Unk_099e40`
- `Unk09974c_Unk_0997c8`: decompiler-derived

## Not done in M1-T557
- `Unk09974c_Unk_099ea4`
- `func_02099a28`
- `func_0209993c`
- `func_02099b10`
- `func_02099f7c`
- `Unk09974c_GetEntryUnk08`: hand-matched
- `Unk09974c_HasFlagsMid`: hand-matched
- `Unk09974c_FindEntry`: hand-matched
- `Unk09974c_Unk_0998f0`: hand-matched
- `Unk09974c_Unk_099cc4`: hand-matched
- `Unk09974c_Unk_09a090`: hand-matched
- `Unk09974c_Unk_09a0c0`: hand-matched
- `Unk09974c_IsKind1or14`: hand-matched
- `Unk09974c_GetFlagsMidMinus1`: hand-matched
- `Unk09974c_SetSeenBit`: hand-matched
- `Unk09974c_Unk_099bfc`: hand-matched
- `Unk09974c_Unk_099c60`: hand-matched
- `Unk09974c_Unk_099d14`: hand-matched
- `Unk09974c_Unk_099d78`: hand-matched
- `Unk09974c_Unk_099ddc`: hand-matched
- `Unk09974c_Unk_0999d4`: hand-matched
- `Unk09974c_Unk_099abc`: hand-matched
- `Unk09974c_Unk_099e40`: hand-matched
- `Unk09974c_Unk_099ea4`: hand-matched
- `Unk09974c_Unk_099f24`: hand-matched
- `Unk09974c_Unk_09a1e4`: hand-matched
