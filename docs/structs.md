# Known global / shared structs

Layouts are taken only from matched C. Names are hedged (`unk_*`) until a use site
makes the meaning clear. Confidence: **certain** = offset+type observed in matching
code; **medium** = role guessed from callers/strings; **none** = placeholder.

## `GameState` — `include/GameState.h`

| Symbol | Addr | Notes |
|---|---|---|
| `gGameState` | BSS `0x0215dd2c` | Pointer to the live `GameState`. Returned by `GetGameState` (~60 callers). |
| `GameState` | (heap/static) | Pointed-to object; size at least `0x759C`. |
| `GameStateRoot` | `GameState.root` | Sub-object at `*gGameState`; fields at +4, +0xC, +0x14, +0x18, +0x5C. |

Important field groups (all **certain** on offset/type, **none–medium** on meaning):

| Offset | Field | Role (guess) | Conf |
|---|---|---|---|
| +0x0000 | `root` | pointer to `GameStateRoot` | certain |
| +0x38E8 | `unk_38e8` | sub-object base passed to `func_0209a884` | certain |
| +0x73CC | `unk_73cc` | mode / transition word | medium |
| +0x73D0 | `unk_73d0` | companion of `unk_73cc` | medium |
| +0x73D8 / +0x73E4 | `unk_73d8` / `unk_73e4` | flags around mode changes | medium |
| +0x73E8 | `unk_73e8` | mode id written by many screen changers | medium |
| +0x73F4..F8 | `unk_73f4`..`unk_73f8` | three `u16` args for a mode | medium |
| +0x7400 | `unk_7400` | cleared on one transition | none |
| +0x7430..38 | `unk_7430`..`unk_7438` | triple passed into `func_02052d7c` | medium |
| +0x7480 | `unk_7480` | `u8` argument stashed by a mode changer | none |
| +0x74F4 | `unk_74f4` | read by `GameState_GetUnkField74f4` | none |
| +0x7550 | `unk_7550` | sub-object for `Unk09974c_*` | certain (base) |
| +0x7598 | `unk_7598` | sub-object for `Unk11f2d0_*` | certain (base) |

Consumers rewritten to use the struct (no raw casts):  
`unit_0202f2a8.c`, `unit_0209e72c.c`, `unit_0209e96c.c`, `unit_0209ee4c.c`,
`unit_0209e418.c`, `unit_0209d42c.c`, `unit_021124f0.c`.

## Other frequent globals — `include/Globals.h`

Scalar BSS words still named `data_<addr>` in `symbols.txt` (rename later when meaning
is known). Declared in `Globals.h` for shared use:

`data_0215dd24` (next to `gGameState`), `data_0215ee98`, `data_02176e24`,
`data_02176e7c`, `data_02176274`, and other `data_02176*` flags.  
`data_02140ac8[]` is a data-section table whose address is returned by
`Unk02e000_GetAddr_data_02140ac8`.

## Per-file `*Work` structs

Many TUs still carry a local `<Module>Work` built from that file's field accesses
(`unk_XXXX` / older `UnkFieldXXXX`). Shared offsets like +4/+8/+0xC across files are
**not** merged into one shared header: they are almost certainly different object
types that happen to have a field there. Merge only when call-graph / type evidence
shows they are the same.

## Work-struct expansion (2026-10-15)

Raw `*(T*)(arg0+off)` / `FIELD` on the primary object was converted to
`((<Mod>Work *)arg0)->unk_XXXX` (or a named field) in the files below. Layouts
come only from matched accesses; names stay hedged unless a prior accessor
already had a real name (`ScanVisor.rangeA`, `Worker.owner`, etc.).

Shared globals stay in `GameState.h` / `Globals.h`. Per-TU Work structs stay
per-file unless call-graph evidence shows they are the same object (CampStatus's
`unk_7494` is **not** merged into `GameState` without that evidence).

Converted this pass (46 sources; 414 matched funcs rechecked at 100%):
- `src/BattleShowingTask.c`
- `src/CampStatus.c`
- `src/CaveArea.c`
- `src/CaveNpc.c`
- `src/ImageBgDual3D.c`
- `src/SaveLoadTask.c`
- `src/ScanVisor.c`
- `src/StaffRoll.c`
- `src/game/unit_0202dcfc.c`
- `src/game/unit_02039774.c`
- `src/game/unit_02039bb4.c`
- `src/game/unit_0205ae50.c`
- `src/game/unit_0206ae94.c`
- `src/game/unit_0206e4d8.c`
- `src/game/unit_020939f0.c`
- `src/game/unit_02094fe0.c`
- `src/game/unit_020aa118.c`
- `src/game/unit_020c855c.c`
- `src/game/unit_020cce38.c`
- `src/game/unit_020cd6ec.c`
- `src/game/unit_020cf5e8.c`
- `src/game/unit_020e1648.c`
- `src/game/unit_020e7290.c`
- `src/game/unit_020e7ac4.c`
- `src/game/unit_020edc78.c`
- `src/game/unit_020ee6dc.c`
- `src/game/unit_020ef248.c`
- `src/game/unit_020efb90.c`
- `src/game/unit_020efff4.c`
- `src/game/unit_020f09b4.c`
- `src/game/unit_020f470c.c`
- `src/game/unit_020f81a4.c`
- `src/game/unit_020f8448.c`
- `src/game/unit_020f868c.c`
- `src/game/unit_020fd9f0.c`
- `src/game/unit_02100208.c`
- `src/game/unit_0210947c.c`
- `src/game/unit_02109dcc.c`
- `src/game/unit_0210a034.c`
- `src/game/unit_02113294.c`
- `src/game/unit_02116598.c`
- `src/game/unit_0211d120.c`
- `src/game/unit_0211ec7c.c`
- `src/game/unit_0211f2d0.c`
- `src/game/unit_0211fc20.c`
- `src/game/unit_02122e1c.c`

Remaining raw primary-arg sites: ~28 (overlap/unaligned or codegen-sensitive).
Other bases (`value`, `tmp1`, …) still use offset casts where the pointer is a
transient local, not the file Work object.

## Structs added with pass-2 matches

| Struct | File | Notes |
|---|---|---|
| `StaffRollWork` (+`StaffRollCmd`) | StaffRoll.c | `scrollY` +0xDC (starts 0x1F0), `firstTextCmd` +0xE4, `cmds`/`cmdCount` +0x2FC/+0x300 — medium |
| `CaveNpcList` | CaveNpc.c | `scrollY` +8, set per row/visible count; separate from `CaveNpcWork` (different object) — medium |
| `YdmFile` / `YdmHeader` | unit_020392f8.c | YDM dungeon file header counts at +6/+7/+8 and section pointers — medium (from `Data/Dungeon/Ydm/*` strings) |
| `Unk0f7eb4Work.bfData/mbbData` | unit_020f7eb4.c | +0x74/+0x78 loaded `Data/Battle/Event/%s.bf/.mbb` — medium |
| `Unk0b6570Work.model` | unit_020b6570.c | +0x208C title model set (titleModel.*) — medium |
| `Unk10fe28Work` | unit_0210fe28.c | config screen object; fields +0x18..+0x54 hedged — none |
| `MissionInfo.stage` | unit_02095560.c | +0x50 of `func_0202dc44` result — low |
| `Unk112aa0Step` | WIP branch only | mode/step bytes, `menuId` +0x14 |
