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

## Not done in M1-T254
- `Unk02dcfc_SetCode8`
- `Unk02dcfc_SetOwnerCode22`
- `Unk02dcfc_SetCode24`
- `Unk02dcfc_SetCode25`
- `Unk02dcfc_SetOwnerCode26`
- `Unk02dcfc_SetField64`
- `Unk02dcfc_SetField68`
- `Unk02dcfc_GetField70`
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
