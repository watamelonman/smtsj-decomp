# src/game/unit_0206ae94.c

## M1-T994: verified matching functions

All eight functions below match the original ARM instructions at 100% objdiff.
Evidence is the instruction stream at the listed addresses, not inferred game semantics.
Pointers must reference valid objects; no ownership is transferred.

| Function | Address / size | Contract and evidence |
| --- | --- | --- |
| `Unk06ae94_GetUnkField4c` | 0x0206c764 / 8 B | Returns the word at +0x4c, as shown by the single load. |
| `Unk06ae94_Unk_06aed4` | 0x0206aed4 / 24 B | Resolves `(2, id)` through `func_020445d0`, then forwards the handle to `func_0204fde0`. Callee meanings remain unknown. |
| `Unk06ae94_Unk_06aeec` | 0x0206aeec / 24 B | Resolves `(2, id)` through `func_020445d0`, then forwards the handle to `func_0204fe18`. Callee meanings remain unknown. |
| `Unk06ae94_SetPair` | 0x0206c8c8 / 24 B | Signed comparison clamps indices >= 2 to 1, then stores two words at +0x158/+0x15c with stride 8. Caller must supply a nonnegative index. |
| `Unk06ae94_Unk_06c8e0` | 0x0206c8e0 / 24 B | ORs bit 2 into +0x34; stores arg2 at +0x3c and arg1 at +0x40. Field meanings remain unknown. |
| `Unk06ae94_Unk_06ae94` | 0x0206ae94 / 32 B | Calls `func_02052d34` only when the input mask overlaps the word at `data_021457e0`. |
| `Unk06ae94_Unk_06aeb4` | 0x0206aeb4 / 32 B | Calls `func_02052d58` under the same mask condition. |
| `Unk06ae94_CompareU32` | 0x0206c0d4 / 32 B | Unsigned compare of two pointed-to words returns -1, 0, or 1. Carry/HI branches establish unsigned ordering. |

## Hard list

None for M1-T994. The existing bodies already matched; this task verifies them and
adds typed declarations and evidence-based contracts. Other task entries below are
retained as historical notes rather than M1-T994 acceptance results.

## Not done in M1-T995
- `Unk06ae94_Unk_06c0b0`
- `Unk06ae94_Call_06c938`
- `Unk06ae94_Call_06c130`
- `Unk06ae94_Unk_06c8f8`
- `Unk06ae94_Call_06af04`
- `Unk06ae94_Unk_06d4e8`
- `func_0206ca64`
- `Unk06ae94_Unk_06b8e4`
- `Unk06ae94_Unk_06c76c`: decompiler-derived

## Not done in M1-T996
- `Unk06ae94_Unk_06c854`
- `func_0206c6d8`
- `func_0206c130`
- `func_0206b958`
- `func_0206c938`
- `func_0206bb84`
- `func_0206d3b4`

## Not done in M1-T997
- `func_0206ba4c`
- `func_0206b0f0`
- `func_0206d54c`
- `func_0206d268`
- `func_0206d7f4`
- `func_0206d68c`
- `func_0206ced4`
- `func_0206cd30`
- `Unk06ae94_Unk_06aed4`: hand-matched
- `Unk06ae94_Unk_06aeec`: hand-matched
- `Unk06ae94_SetPair`: hand-matched
- `Unk06ae94_Call_06af04`: hand-matched
- `Unk06ae94_Unk_06c0b0`: hand-matched
- `Unk06ae94_CompareU32`: hand-matched
- `Unk06ae94_Call_06c130`: hand-matched
- `Unk06ae94_Unk_06c8f8`: hand-matched
- `Unk06ae94_Call_06c938`: hand-matched
- `Unk06ae94_Unk_06b8e4`: hand-matched
- `Unk06ae94_Unk_06c854`: hand-matched
- `Unk06ae94_Unk_06d4e8`: hand-matched
