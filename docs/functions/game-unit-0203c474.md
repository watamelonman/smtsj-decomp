# game/unit_0203c474

Scan-visor action handlers. The original registers each handler in the
8-byte-entry table at 0x0212b624 (the entry's second word is the function
pointer per `config/arm9/relocs.txt`). These handlers take no C arguments; they return 1, except
`Unk03c474_Unk_03c474`, `Unk03c474_Unk_03c4a0`,
`Unk03c474_Unk_03c540` and `Unk03c474_Unk_03c638`, which return 3. The
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

## M1-T117 handlers

All eight match at 100% in objdiff. Evidence is the delinked ARM instructions
and relocations at the ranges below, plus the named callee implementations in
`src/ScanVisor.c` and `src/game/unit_0202dcfc.c`. Names remain neutral because
these operations do not establish a user-facing action name.

| Function | Evidence and behavior |
| --- | --- |
| `Unk03c474_Unk_03c5b8` | 0x0203c5b8–0x0203c5cc: calls `func_020a269c(0)` to apply 0 to the current-mode visor setters; returns 1. |
| `Unk03c474_Unk_03c5cc` | 0x0203c5cc–0x0203c5e0: calls `ScanVisor_Unk_0a273c(1)`, forwarding 1 to its five visor setters when visor data exists; returns 1. |
| `Unk03c474_Unk_03c5e0` | 0x0203c5e0–0x0203c5f4: calls `ScanVisor_Unk_0a273c(0)`, forwarding 0 to the same five setters; returns 1. |
| `Unk03c474_Unk_03c5f4` | 0x0203c5f4–0x0203c608: calls `ScanVisor_Unk_0a28b0(0)`, writing visor +0x210 = 50 and +0x214 = 0 when the data exists; returns 1. |
| `Unk03c474_Unk_03c540` | 0x0203c540–0x0203c558: calls the direction thunk with r0 = 1, then `Unk02dcfc_SetOwnerCode26()` to write owner worker +0x18 = 26; returns 3. |
| `Unk03c474_Unk_03c56c` | 0x0203c56c–0x0203c588: calls `ScanVisor_SetField34(1)` (visor +0x34 = -3), then `ScanVisor_Unk_0a2920(1)` (calls `ScanVisor_Unk_0a4904` on visor +0x24c); returns 1. |
| `Unk03c474_Unk_03c588` | 0x0203c588–0x0203c5a4: calls `ScanVisor_SetField34(0)` (visor +0x34 = 3), then `ScanVisor_Unk_0a2920(0)` (calls `ScanVisor_Unk_0a4864` on visor +0x24c); returns 1. |
| `Unk03c474_Unk_03c4a0` | 0x0203c4a0–0x0203c4c8: passes the result of `func_0203ac00(0)` directly in r0 to `func_0205e590`, obtains the owner, then calls `Unk02dcfc_Unk_02df00(owner->worker, 1)` to write worker +0x18 = 21 and +0x1c = 1; returns 3. |

The last handler's previous no-argument declaration hid the r0 data flow.
The delinked `func_0205e590` at 0x0205e590 copies incoming r0 to r1 before
calling `func_0208e008`, confirming it consumes that value. The explicit C
argument preserves the exact instructions. The owner view models only +0xe8.

## Other functions

- `Unk03c474_Unk_03c474` (44 B): decompiler-derived (Ghidra output, cleaned)
- `Unk03c474_Unk_03c638` (108 B): decompiler-derived (Ghidra output, cleaned)

## Hard list

- `Unk03c474_Unk_03c608`: no candidate matched locally
- `Unk03c474_Unk_03c608`: hand-matched
