# unit_0202dcfc

- `Unk0202dcfc_InitWorker`: initialise a `Worker` (store owner at 0x40, clear state, init sub-object at 0x4C via `ScanVisor_ResetBits`, zero the 16-entry table at 0x74).
## M1-T253 — verified at 100% objdiff

Evidence is the delinked ARM instructions at each address below. Worker pointers
are borrowed. Direct worker setters require a non-null pointer. These accessors
retain the existing symbol names; field names describe offsets or existing usage,
without assigning an unproven gameplay meaning.

| Function | Address | Contract and evidence |
| --- | --- | --- |
| `Unk02dcfc_Thunk_Unk095560_GetManagerAlias` | `0x0202dd1c` | Literal load and `bx` forward to `Unk095560_GetManagerAlias`; returns its borrowed pointer unchanged. |
| `Unk02dcfc_Unk_02df00` | `0x0202df00` | Stores code 21 at worker +0x18 and the full 32-bit argument at +0x1c. Neutral name retained because purpose is unknown. |
| `Unk02dcfc_Unk_02de58` | `0x0202de58` | Stores code 12 at worker +0x18 and one at +0x54. Neutral name retained because purpose is unknown. |
| `Unk02dcfc_GetState` | `0x0202dd84` | Gets manager +0x44, or zero for no manager; initializer clears this state word. |
| `Unk02dcfc_GetTimer` | `0x0202de28` | Gets manager +0x48, or one for no manager; initializer clears this timer word. |
| `Unk02dcfc_GetField54` | `0x0202de40` | Gets manager +0x54, or zero for no manager; field meaning remains unknown. |
| `Unk02dcfc_GetField58` | `0x0202de98` | Gets manager +0x58, or zero for no manager; field meaning remains unknown. |
| `Unk02dcfc_SetCode7` | `0x0202df10` | Stores seven at manager +0x18 if present; called by unit_0203be10. |

No hard functions remain for M1-T253. The existing implementations already
matched; this task types the two direct worker parameters and documents the
verified instruction contracts. No module boundary changes were needed.

## M1-T254: verified at 100% objdiff

"Manager" is the borrowed pointer from `Unk02dcfc_Thunk_Unk095560_GetManagerAlias`;
"owner worker" is the `Worker *` at +0xE8 of the object returned by
`Unk03aae8_Unk_03ad14`. Code values stored at +0x18 have no known meaning yet.

| Function | Address | Contract and evidence |
| --- | --- | --- |
| `Unk02dcfc_SetCode8` | `0x0202df28` | Stores 8 at manager +0x18 if a manager exists. |
| `Unk02dcfc_SetOwnerCode22` | `0x0202df40` | Stores 22 at owner worker +0x18 with no null check, so the worker must exist. |
| `Unk02dcfc_SetCode24` | `0x0202df58` | Stores 24 at manager +0x18 if a manager exists. |
| `Unk02dcfc_SetCode25` | `0x0202df70` | Stores 25 at manager +0x18 if a manager exists. |
| `Unk02dcfc_SetOwnerCode26` | `0x0202df88` | Stores 26 at owner worker +0x18 with no null check, so the worker must exist. |
| `Unk02dcfc_SetField64` | `0x0202dfa0` | Stores 1 at manager +0x64 if a manager exists; `InitWorker` clears it. |
| `Unk02dcfc_SetField68` | `0x0202dfb8` | Stores 1 at manager +0x68 if a manager exists; `InitWorker` clears it. |
| `Unk02dcfc_GetField70` | `0x0202dfd0` | Returns manager +0x70, or 0 if no manager; `Unk02dcfc_SetField70` writes it. |

All eight already matched once M1-T253 landed. This task adds the per-function
comments and doc entries. Nothing was hard; no names changed.

## Other
- `Unk02dcfc_Unk_02dd9c`: decompiler-derived

## Not done in M1-T255
- `Unk02dcfc_SetField70`
- `Unk02dcfc_ResetWorker`
- `Unk02dcfc_HasField50`
- `Unk02dcfc_Unk_02deb0`
- `Unk02dcfc_Unk_02de6c`
- `Unk02dcfc_Unk_02ded4`
- `Unk02dcfc_Unk_02ddf4`
- `Unk02dcfc_ResetWorker`: hand-matched
- `Unk02dcfc_Unk_02ddf4`: hand-matched
- `Unk02dcfc_Unk_02de6c`: hand-matched
- `Unk02dcfc_Unk_02deb0`: hand-matched
- `Unk02dcfc_Unk_02ded4`: hand-matched
- `Unk02dcfc_SetCode8`: hand-matched
- `Unk02dcfc_SetOwnerCode22`: hand-matched
- `Unk02dcfc_SetCode24`: hand-matched
- `Unk02dcfc_SetCode25`: hand-matched
- `Unk02dcfc_SetOwnerCode26`: hand-matched
- `Unk02dcfc_SetField64`: hand-matched
- `Unk02dcfc_SetField68`: hand-matched
- `Unk02dcfc_GetField70`: hand-matched
- `Unk02dcfc_SetField70`: hand-matched
- `Unk02dcfc_HasField50`: hand-matched
