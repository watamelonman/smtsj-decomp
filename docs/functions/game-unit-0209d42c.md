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

## Not done in M1-T707
- `Unk09d42c_GetTable1Entry`
- `Unk09d42c_GetTable2Entry`
- `Unk09d42c_GetTable3Entry`
- `Unk09d42c_MapId`
- `func_0209e020`
- `Unk09d42c_Unk_09d73c`

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
- `Unk09d42c_MapId`: hand-matched
- `Unk09d42c_GetTable1Entry`: hand-matched
- `Unk09d42c_GetTable2Entry`: hand-matched
- `Unk09d42c_GetTable3Entry`: hand-matched
- `Unk09d42c_Unk_09d73c`: hand-matched
