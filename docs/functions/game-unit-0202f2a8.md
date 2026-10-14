# unit_0202f2a8

- `Unk02f2a8_Nop_0303c8`, `Unk02f2a8_Nop_0303cc`, `Unk02f2a8_Nop_035430`: empty callbacks.
- `Unk02f2a8_Thunk_0203428c` -> `func_0203428c`, `Unk02f2a8_Thunk_0206146c` -> `func_0206146c`: forwarders.
- `GetGameState`: return the global game-state pointer `gGameState`.
- `Unk02f2a8_Call_02057660`: call `func_02057660(2, 0)` (SDK range).
- `GameState_GetUnkField74f4`: read the u16 at +0x74F4 of the game state.
