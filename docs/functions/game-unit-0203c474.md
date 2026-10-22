# game/unit_0203c474

Scan-visor action handlers. The original registers each handler in the
8-byte-entry table at 0x0212b624 (the entry's second word is the function
pointer per `config/arm9/relocs.txt`). Handlers take no C arguments because the
table call is indirect; they return 1, except `Unk03c474_Unk_03c474` and
`Unk03c474_Unk_03c4a0`, which return 3 after switching task/script state. The
meaning of the return value itself is not established.

## M1-T116 handlers

All eight match at 100% in objdiff. Names stay neutral: the table and the callee
names establish which visor fields are touched, but not each action's user-facing
meaning.

| Function | Evidence and behavior |
| --- | --- |
| `Unk03c474_Unk_03c4c8` | 0x0203c4c8–0x0203c4dc: calls `ScanVisor_SetField214(1)`, which writes -3 to visor +0x214 when the visor data pointer exists; returns 1. |
| `Unk03c474_Unk_03c4dc` | 0x0203c4dc–0x0203c4f0: calls `ScanVisor_SetField214(0)`, which writes 3 to visor +0x214; returns 1. |
| `Unk03c474_Unk_03c4f0` | 0x0203c4f0–0x0203c504: calls `ScanVisor_SetRangeA(1)`, which writes 2 to visor +0x1c; returns 1. |
| `Unk03c474_Unk_03c504` | 0x0203c504–0x0203c518: calls `ScanVisor_SetRangeA(0)`, which writes -2 to visor +0x1c; returns 1. |
| `Unk03c474_Unk_03c518` | 0x0203c518–0x0203c52c: calls `ScanVisor_Unk_0a27e0(1)`, which forwards 1 to `Unk0fd268_SetDir` after a null check on the visor data; returns 1. |
| `Unk03c474_Unk_03c52c` | 0x0203c52c–0x0203c540: calls `ScanVisor_Unk_0a27e0(0)`, forwarding 0 to `Unk0fd268_SetDir`; returns 1. |
| `Unk03c474_Unk_03c558` | 0x0203c558–0x0203c56c: calls `ScanVisor_Thunk_020fc6b8(0)`, a thunk to `Unk0fc584_SetDir` that takes no arguments. The original still loads r0 = 0 before the branch, so the argument stays in the C. Returns 1. |
| `Unk03c474_Unk_03c5a4` | 0x0203c5a4–0x0203c5b8: calls `func_020a269c(1)`, which switches on the current visor mode (visor +0) and applies the value to that mode's setters (`ScanVisor_SetField34`, `ScanVisor_Unk_0a27e0`, `ScanVisor_SetRangeA`/`ScanVisor_SetField214`/`ScanVisor_Unk_0a2920` or `ScanVisor_Unk_0a28f4`); returns 1. |

## Other functions

- `Unk03c474_Unk_03c5b8` (20 B): decompiler-derived (Ghidra output, cleaned)
- `Unk03c474_Unk_03c5cc` (20 B): decompiler-derived (Ghidra output, cleaned)
- `Unk03c474_Unk_03c5e0` (20 B): decompiler-derived (Ghidra output, cleaned)
- `Unk03c474_Unk_03c5f4` (20 B): decompiler-derived (Ghidra output, cleaned)
- `Unk03c474_Unk_03c540` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk03c474_Unk_03c56c` (28 B): decompiler-derived (Ghidra output, cleaned)
- `Unk03c474_Unk_03c588` (28 B): decompiler-derived (Ghidra output, cleaned)
- `Unk03c474_Unk_03c4a0` (40 B): decompiler-derived (Ghidra output, cleaned)
- `Unk03c474_Unk_03c474` (44 B): decompiler-derived (Ghidra output, cleaned)
- `Unk03c474_Unk_03c638` (108 B): decompiler-derived (Ghidra output, cleaned)

## Hard list

- `Unk03c474_Unk_03c608`: no candidate matched locally
- `Unk03c474_Unk_03c608`: hand-matched
