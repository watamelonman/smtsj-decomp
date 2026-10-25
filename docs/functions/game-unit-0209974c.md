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

## Not done in M1-T555
- `Unk09974c_Unk_09a0c0`
- `Unk09974c_SetSeenBit`
- `Unk09974c_FindEntry`
- `func_0209a158`
- `Unk09974c_Unk_0998f0`
- `Unk09974c_Unk_099cc4`
- `Unk09974c_Unk_0999d4`
- `Unk09974c_Unk_099abc`

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
