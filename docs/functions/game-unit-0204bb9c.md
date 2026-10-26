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
- `func_0204c4cc`: hand-matched
- `func_0204c564`: hand-matched
- `func_0204c780`: hand-matched
- `func_0204c8f4`: hand-matched

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

## M1-T785 slot and record helpers

The singleton also holds four parallel 32-entry slot arrays at +0x8b4 (signed
halfword state), +0x8f4, +0x934 and +0x974, and three 32-entry byte key arrays at
+0x9b4, +0x9d4 and +0x9f4. The offsets come from the literal/offset addressing in
the routines below; field meaning beyond load/store width is not established.

| Function | Assembly evidence and contract |
| --- | --- |
| `func_0204c4cc` | 0x0204c4cc: scans the 32 signed halfwords at +0x8b4 (ldrsh) for a negative slot, clears it, stores arg0 at +0x8f4, arg1 at +0x934 and the -1 sentinel at +0x974 (mov 0/sub 1), then returns the index; absent singleton or full table returns -1. |
| `func_0204c564` | 0x0204c564: same scan and +0x8f4/+0x934 stores, but the third store at +0x974 is the caller's third argument (strh r2 at +0x974) instead of -1; returns the index or -1. |
| `func_0204c780` | 0x0204c780: walks the 32 byte entries at +0x9b4, and when the entry is non-zero and its +0x9d4/+0x9f4 keys equal the two arguments, clears all three bytes and calls `func_0204b6f4`; absent singleton is ignored and nothing is returned. |
| `func_0204c8f4` | 0x0204c8f4: scans the 96 packed records from `Unk02e000_Unk_02e89c`, requires a non-zero six-bit kind, matches the three byte keys (980 maps to zero) and clears the kind (`and 63`) plus all three keys before calling `func_0204b6f4`. |

## M1-T785 card functions already present

`Unk04bb9c_Unk_04c404`, `Unk04bb9c_Unk_04c98c`, `Unk04bb9c_Unk_04cbe8` and
`Unk04bb9c_Unk_04cc4c` were implemented before this card and remain at 100%
objdiff; their evidence and contracts are unchanged from the file comments.

No new behavioral tests: this card requires binary equivalence, checked by objdiff.
Verification: all 16 C functions in the changed file report 100% in
`build/report.json`, including the four M1-T785 functions above. The full
build/checksum gate reports all artifacts byte-identical to the original;
anticheat and all nine repository unit tests pass.
Hard list: none.
