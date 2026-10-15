# Naming conventions (Strange Journey decomp)

Names live in `config/arm9/symbols.txt`; C sources, docs and cards use the same names.
Every rename is checked by rebuilding: objdiff 100% for all matched functions, and a byte-identical ROM.

## Prefixes
- Module prefix = source file. A named file (`CampStatus.c`, from an assert string in the
  binary) gives `CampStatus_`. An unnamed TU `src/game/unit_0XXXXXXX.c` gives `UnkXXXXXX_`,
  i.e. the start address minus the leading `02`.
- Globals: `g` + PascalCase (`gGameState`). Other data keeps `data_<addr>` until understood.
- Structs: PascalCase. A per-file `<Module>Work` struct is the object passed as the first
  argument in that file; its layout comes only from observed field accesses.

## Hedging: how much each name claims
| Pattern | Means | Confidence |
|---|---|---|
| `<Mod>_Nop_<addr>` | empty function (table slot) | certain (behaviour) |
| `<Mod>_Thunk_<target>` | tail call to target, arguments passed through | certain |
| `<Mod>_Call_<target>` | calls target with constant arguments | certain |
| `<Mod>_GetUnkField<off>` / `SetUnkField<off>` / `ClearUnkField<off>` | reads/writes the field at that offset | certain about the access, purpose unknown |
| `<Mod>_GetConst<N>` | returns constant N | certain |
| `<Mod>_Get_/Set_/Clear_/IsSet_<data>` | trivial access to a global | certain |
| `<Mod>_Unk_<addr>` | matched, purpose not yet understood | none |
| `UnkField<off>`, `unk_<off>` | struct field with unknown meaning | none |
| Plain descriptive names (`SaveLoadTask_Draw`, `ExpGauge_Update`, `UniteEvent_HandleMessage`, `GetGameState`) | inferred from strings, callers and behaviour | medium: see the comment in the source |
| `Unk_<Verb>...` on library-range functions (`Unk_InterpolateLinear`) | behaviour guessed from a call site | low-medium |

## Struct field names
- Shared globals go in `include/*.h` (`GameState.h`, `Globals.h`). See `docs/structs.md`.
- Field names: `unk_XXXX` (offset in hex) or a real name when known. Padding: `pad_XXXX[N]`.
- Prefer `GameState *gs` / `ScanVisor *sv` over `int arg0` once the TU is converted.
- Do not invent shared structs from coincident offsets across unrelated files.

## Inferred so far
- `gGameState` (0x0215dd2c): pointer to the global game state. `GetGameState` returns it
  and has about 60 callers. Header: `include/GameState.h`.
- `Unk_InterpolateLinear` (0x0205eb20): (from, to, frames, frame) -> value. From the fades in `ExpGauge_Update`.
- `ExpGauge` (BattleShowingTask.c): EXP count-up state machine on the result screen.
- `SaveLoadTask` (SaveLoadTask.c): save/load screen object, draw routine at 0x020e1144.
- `UniteEvent` / `EventMsg` (UniteEvent.c): demon fusion event plus its message format
  (flags byte + optional values). It uses an inline `GetEventParam` helper.
