# Changelog

## Unreleased
- Matched all five functions in `src/game/unit_02044394.c`, including shuffled entry initialization, with typed records and external call prototypes.
- `src/game/unit_0203c274.c`: all four script command handlers (`func_0203c274` BGR555→RGBA colour command, `func_0203c320` mode switch, `Unk03c274_Unk_03c434`, `Unk03c274_Unk_03c45c`) in matching C with real prototypes (100% in objdiff); descriptive `ScriptCmd_*` aliases in `include/game/unit_0203c274.h`; doc entries in `docs/functions/game-unit-0203c274.md`.
- `src/game/unit_020b7898.c`: `Unk0b7898_Call_02052634` and `Unk0b7898_Unk_0b78b0` (callbacks in the function table at 0x0213d6f8) in matching C (100% in objdiff), with the real `Unk02cad4_Unk_02cbdc(u32)` prototype; doc entries in `docs/functions/game-unit-020b7898.md`.
- `src/game/unit_0212f7e4.c`: `func_0212f7e4` (forwarding thunk to `func_021301f0`, plain `b` via `#pragma interworking off`) in matching C (100% in objdiff).
- `src/game/unit_020fb634.c`: `func_020fb634` (paged list screen update state machine) in matching C with a typed `Unk0fb634Work` struct (100% in objdiff); proposed name `Unk0fb634_UpdateListScreen` as an alias in `include/game/unit_020fb634.h`.
- `src/game/unit_020ee904.c`: `func_020ee904`, `func_020ee958`, `Unk0ee904_Unk_0eeadc` in matching C with typed work structs (100% in objdiff); descriptive aliases `Unk0ee904_IsModeAvailable`, `Unk0ee904_SetupForState`, `Unk0ee904_ResetWork` in `include/game/unit_020ee904.h`.
- `src/game/unit_021250a8.c`: `func_021250a8`, `func_02125104`, `func_0212528c` (ImageBgDual3D task setup, message handler, activation) in matching C.
- `src/game/unit_02000c04.c`: `main` (ARM9 entry point and frame loop) in matching C.
- Matched `func_02126178` and `func_021261d8` in `src/game/unit_02126178.c` (100% in objdiff).
