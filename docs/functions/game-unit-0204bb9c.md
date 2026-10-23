# src/game/unit_0204bb9c.c
- `Unk04bb9c_SetCtxUnka14`: hand-matched
- `Unk04bb9c_IsKind02Or32to34`: hand-matched
- `Unk04bb9c_SetCtxUnk0c`: hand-matched
- `Unk04bb9c_IsCtxUnk8Clear`: hand-matched
- `Unk04bb9c_GetCtxUnka20`: hand-matched
- `Unk04bb9c_Unk_04c404`: hand-matched
- `Unk04bb9c_Unk_04c98c`: hand-matched
- `Unk04bb9c_Unk_04cbe8`: hand-matched
- `Unk04bb9c_Unk_04cc4c`: hand-matched

## M1-T784 context accessors

The singleton is borrowed from `data_0215eea4`; no accessor owns it.
Names already present in the symbol map are retained. Unknown accessors retain
`func_` names because field meaning is not established by their loads/stores.

| Function | Assembly evidence and contract |
| --- | --- |
| `Unk04bb9c_SetCtxUnka14` | Conditional word store at +0xa14; absent singleton is ignored. |
| `func_0204ca1c` | 0x0204ca1c: word load at +0xa14, returning -1 when absent. |
| `func_0204cb90` | 0x0204cb90: word load at +0xa18, returning 1 when absent. |
| `func_0204cbac` | 0x0204cbac: conditional halfword store at +0xa20. |
| `Unk04bb9c_GetCtxUnka20` | Halfword load at +0xa20, returning zero when absent. |
| `Unk04bb9c_IsKind02Or32to34` | 0x0204c13c: accepts exactly 0, 2, 32, 33, 34, using unsigned range comparison. |
| `Unk04bb9c_IsCtxUnk8Clear` | Absent singleton returns true; otherwise compares word +8 with zero. |
| `Unk04bb9c_SetCtxUnk0c` | 0x0204c464: sets word +8 to 1 and stores three halfwords at +0xc, +0xe, +0x10; absent singleton is ignored. |

No new behavioral tests: this card requires binary equivalence, checked by objdiff.
Hard list: none.
