# game/unit_020efb90

All seven M1-T173 functions match the original ARM code at 100% objdiff.
Names remain the configured symbols; semantic roles beyond the observed operations
are not established. Work pointers borrow writable storage; the list subobject
starts at +0x50 and its complete size is unknown.

| Function | Observed behavior and contract |
| --- | --- |
| `Unk0efb90_Nop_0efd18` | Returns immediately; the single ARM return instruction establishes the empty callback shape. |
| `Unk0efb90_Thunk_020f7248` | Calls `func_020f7248` without arguments; the branch relocation establishes the forwarding target. |
| `Unk0efb90_Unk_0efb90` | Requires a valid work pointer. When the enable query succeeds, updates the +0x50 list and invokes `Unk0fedd4_SetState2` if +8 is 10. |
| `Unk0efb90_Unk_0efce8` | Requires a valid work pointer. Sets the two external controls to 1 and 0, resolves the +0x4c selector and initializes the embedded list. |
| `func_020efd1c` | Ignores the context pointer. If the second argument is zero, codes 0, 2, 3, 4, 5, 6 and 8 invoke `Unk100208_Unk_100208(4)`; all other codes return. The original jump table establishes the accepted codes. |
| `func_020efd64` | Ignores context and returns a boolean. Mode 1 requires query 0x707, global flag bit 3 clear and query 0x0e8bc4 true. Mode 2 requires flag bit 2 clear and query 0x0e8be8 true. Other modes return 1. The borrowed global must be valid. |
| `func_020efbc0` | Requires a valid work/list. Reads both list queries even in state 1, which then returns. Otherwise submits each row at y=25+15*i. Negative initial x gets +24 and decreases by 8 each row; submitted x is capped at zero. Entry 1/2 selects kind 1, entry 3/4 kind 2, and other entries kind 0. Entries 1/4 also request the additional mark. External setup/teardown calls surround the walk. |

The local work/global layouts describe only accessed offsets. Loop temporaries
are declared before the index to preserve the original compiler's register
allocation; no semantic dependence on their declaration order is intended.

Validation: standalone instruction/relocation comparison, objdiff match gate,
anticheat, all nine Python tests, and the original-image checksum gate pass.
No hard functions remain for this card.
