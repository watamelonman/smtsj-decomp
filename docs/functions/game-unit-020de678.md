# src/game/unit_020de678.c

## M1-T686

These eight ARM functions retain their existing symbol names. Evidence is the
instructions and relocations in `build/delinks/src/game/unit_020de678.o`.
Helper selector meanings and the global word's meaning remain unknown.

| Function | Size | Evidence and contract |
| --- | --- | --- |
| `Unk0de678_Nop_0df05c` | 4 B | At 0x020df05c, only `bx lr`; no arguments or side effects. |
| `Unk0de678_Nop_0df060` | 4 B | At 0x020df060, only `bx lr`; no arguments or side effects. |
| `Unk0de678_Thunk_02124e04` | 12 B | At 0x020df578, tail branch through the literal relocated to `Unk124c5c_Unk_124e04`; no arguments. |
| `Unk0de678_Get_data_021508d4` | 16 B | At 0x020de950, loads the address relocated to `data_021508d4`, then returns its first unsigned 32-bit word. |
| `Unk0de678_Unk_0dea60` | 16 B | At 0x020dea60, passes selector 31 to `Unk044394_Unk_044534`; no arguments. |
| `Unk0de678_Unk_0df598` | 16 B | At 0x020df598, passes selector 32 to `Unk044394_Unk_044428`; no arguments. |
| `Unk0de678_Unk_0df5a8` | 16 B | At 0x020df5a8, passes selector 32 to `Unk044394_Unk_044534`; no arguments. |
| `Unk0de678_Unk_0dee2c` | 20 B | At 0x020dee2c, adds 0xf1 then 0x500 to the integer argument and tail-calls `Unk0e651c_Unk_0e666c`; callers must avoid signed overflow. |

No hard-list entries for M1-T686.

## Other cards (existing work)

- `Unk0de678_Unk_0df584`: decompiler-derived
- `Unk0de678_Unk_0df0a4`: decompiler-derived

## Not done in M1-T687
- `func_020df330`
- `Unk0de678_Unk_0debf8`
- `Unk0de678_Unk_0df4cc`
- `Unk0de678_Unk_0df348`
- `Unk0de678_CountLeading`
- `func_020deedc`
- `Unk0de678_Unk_0de870`: decompiler-derived
- `Unk0de678_Unk_0df064`: decompiler-derived
- `Unk0de678_Unk_0dec94`: decompiler-derived

## Not done in M1-T688
- `Unk0de678_Unk_0df4f0`
- `Unk0de678_GetPair`
- `func_020df520`
- `func_020de720`
- `func_020de784`

## Not done in M1-T689
- `func_020dec18`
- `func_020de7e8`
- `func_020ded70`
- `func_020deb68`
- `func_020decd8`
- `func_020dee40`
- `func_020de8b0`

## Not done in M1-T690
- `func_020df374`
- `func_020df420`
- `func_020deaa0`
- `func_020df234`
- `func_020de960`
- `func_020def0c`
- `func_020df0cc`
- `Unk0de678_CountLeading`: hand-matched
- `Unk0de678_Unk_0debf8`: hand-matched
- `Unk0de678_GetPair`: hand-matched
- `Unk0de678_Unk_0df348`: hand-matched
- `Unk0de678_Unk_0df4cc`: hand-matched
- `Unk0de678_Unk_0df4f0`: hand-matched
