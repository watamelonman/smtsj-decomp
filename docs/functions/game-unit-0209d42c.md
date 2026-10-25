# src/game/unit_0209d42c.c

## M1-T706 — verified matching functions

All eight functions below report 100% in objdiff against the delinked original.
The implementations already existed in this worktree; this task verifies them and
adds explicit helper parameter types and behavior contracts. Evidence below is
from the original ARM instructions and relocations in
`build/delinks/src/game/unit_0209d42c.o`.

| Function | Size | Evidence and contract |
| --- | ---: | --- |
| `Unk09d42c_Unk_09d600` | 12 | Compares the signed input with 0xff and conditionally replaces it with zero; other inputs pass through. Neutral name retained. |
| `Unk09d42c_Init_data_02176278` | 32 | Passes the singleton address, zero, and 0x884 bytes to `func_02008848`. This storage clear supports the Init name. |
| `Unk09d42c_Unk_09d4e0` | 32 | Loads singleton words at +0x800/+0x804 and returns their equality as zero or one. Neutral name retained. |
| `Unk09d42c_Unk_09d4bc` | 36 | Clears singleton +0x808, then returns signed +0x800 > +0x804. Neutral name retained. |
| `Unk09d42c_Unk_09e080` | 48 | Reads state +0x73ec, looks up an eight-byte record through `Unk1124f0_Unk_11259c`, and invokes its +4 callback when present; otherwise returns one. State and selected record must exist. Neutral name retained. |
| `Unk09d42c_Unk_09e274` | 48 | Calls `GetGameState`; returns one for null or a signed -1 at +0x73e8, zero otherwise. Neutral name retained. |
| `Unk09d42c_Unk_09df70` | 64 | Calls `func_02052da0` with the state, loads signed bytes at +0x7482/+0x7483 for `Unk02f2a8_GetCell38e8`, and increments the returned cell's +2 halfword modulo 65536. Returns whether `Unk09a268_Unk_09a844` equals one. State and selected cell must exist. Neutral name retained. |
| `Unk09d42c_GetTable0Entry` | 72 | Calls resource lookup with (9, 0), obtains base and count, and returns base for negative/out-of-range indices or base + index * 2 otherwise. The lookup arguments and stride support the table-entry name. Returned storage is borrowed. |

No new behavioral tests: this card sets `tests_required = false`; original-object
comparison is the acceptance test. No hard functions remain for M1-T706.

## M1-T707 — verified matching functions

All eight functions report 100% against the original delinked object. Seven
implementations were already present; this card adds `func_0209e020`, types the
flag predicate parameter, and documents the contracts. Evidence is the original
ARM instructions and relocations in `build/delinks/src/game/unit_0209d42c.o`.

| Function | Size | Evidence and contract |
| --- | ---: | --- |
| `Unk09d42c_Unk_09e2f4` | 72 | Null state returns immediately. Resolves the input through work-area +0x358 and `func_0203611c`, writes root +0x18, sets root +0x14 to 4 and state +0x73e8 to 1. Present state requires valid root/work storage. Neutral name retained. |
| `Unk09d42c_GetTable1Entry` | 76 | Resource arguments (9, 1) and 106-byte stride support the name. Negative/out-of-range indices return the borrowed table base. |
| `Unk09d42c_GetTable2Entry` | 76 | Resource arguments (9, 2) and 24-byte stride support the name. Negative/out-of-range indices return the borrowed table base. |
| `Unk09d42c_GetTable3Entry` | 76 | Resource arguments (9, 3) and 52-byte stride support the name. Negative/out-of-range indices return the borrowed table base. |
| `Unk09d42c_MapId` | 80 | Explicit comparisons map zero to one and, for nonzero second argument, 62/63/64 to 65/66/67. Other inputs return their low byte. These ID substitutions support the name. |
| `Unk09d42c_Unk_09e2a4` | 80 | Null state returns immediately. Resolves the input through work-area +0x358 and `func_0203611c`, writes root +0x18, sets root +0x14 to 2, clears root +0xc and state +0x73e8. Present state requires valid root/work storage. Neutral name retained. |
| `func_0209e020` | 96 | Dispatches state word +0x73f0. At zero, predicate `Unk0a23f4_Unk_0a246c` returning 1 invokes `ScanVisor_Unk_0a2b18` then increments that word. At one, returns whether `Unk0a23f4_Unk_0a2448` is zero; otherwise returns zero. State must exist; neutral name retained. |
| `Unk09d42c_Unk_09d73c` | 108 | Scans group 9/table 4 six-byte records: flag/key/value halfwords. Returns the first matching key's value when the flag predicate succeeds, otherwise the input ID. Storage is borrowed. Neutral name retained. |

No new behavioral tests (`tests_required = false`); original-object comparison
checks every instruction and relocation. No hard functions remain for M1-T707.

## Not done in M1-T708
- `func_0209e33c`
- `func_0209d44c`
- `func_0209dfb0`
- `func_0209e3a8`
- `func_0209dadc`
- `func_0209da38`
- `func_0209d964`
- `func_0209d500`

## Not done in M1-T709
- `func_0209de58`
- `func_0209d7f4`
- `func_0209e0b0`
- `func_0209db70`
