# game/unit_0211d520 — M1-T729 / M1-T730

All fifteen functions match the delinked ARM object at 100% objdiff. Field names
remain neutral where the assembly establishes an offset but no semantic identity.
Helper names below are existing relocation symbols, not new inferred names.

| Function | Bytes | Behavior and evidence from the delink |
| --- | ---: | --- |
| `Unk11d520_Unk_11da60` | 16 | Loads the index at +0x18 and returns that word from the table pointer at +0xa8. The caller must supply a valid index. |
| `Unk11d520_Unk_11d520` | 32 | Passes the resource at +0x26c and argument 3 to `func_0204fe68`, then returns `func_0204fed8` with the resulting table and argument 2. Callers consume its return value. |
| `Unk11d520_Unk_11d838` | 32 | Same resource lookup with fixed group 4. Its return is consumed by `func_0211da70`. |
| `Unk11d520_Unk_11d858` | 44 | Looks up group 0 of +0x270, replacing a zero result with the address of `data_02151d18`. |
| `Unk11d520_Unk_11dde8` | 44 | Loads the indexed handle at +0x28c for `func_0205c408(handle, value)`, reloads it, and calls `func_0205c6e0`. Index must be valid. |
| `Unk11d520_AddUniqueId` | 68 | Scans halfword IDs beginning at +0xb4 using the signed count at +0x268; returns on equality, otherwise stores the truncated ID and increments the count. This scan/store supports the existing descriptive symbol. The caller supplies capacity; the routine has no bounds check. |
| `func_0211da70` | 232 | Gets and records the selected ID. For signed IDs >=128, resolves a key and, when nonnegative, fills slots 1 and 2 through `func_0204fcb0`. Both branches choose resource group 2 or 3 via `Unk118b04_Unk_118b78`, then pass the result to `func_02061f10` with handle +0x2e0 and arguments -1, 0, 0. The upper branch uses entry 128, the lower branch the ID. |
| `func_0211d6fc` | 248 | Releases and clears +0x288 conditionally, then releases +0x2dc, +0x2d4, +0x2d8, +0x2e0 unconditionally. Walks 18 handles at +0x28c and two pairs at +0x278/+0x280, conditionally releasing and clearing each. Calls `func_0205bb68` once before the releases and 16 times afterward. |

The two work structs in `include/game/unit_0211d520.h` are borrowed views of the same object. Their offsets come from
loads/stores; handles remain opaque words. The unit remains linked from the
original delink pending human completion marking, as required by the card.

## M1-T730 functions

All seven entries below report 100% in `tools/match_gate.py`. Names retain the
original neutral symbols because the calls establish display behavior without
proving the identity of the screen.

| Function | Bytes | Behavior and evidence from the delink |
| --- | ---: | --- |
| `func_0211db58` | 284 | Resolves the group title through resource +0x26c, group 5. Frees and rebuilds +0xa8 and +0xb0 arrays from `func_02119460` / `func_0211955c`, fills flags with 1, configures at most eleven visible entries, then refreshes widths and selected text. Requires a valid initialized work area. |
| `func_0211dc74` | 372 | Dispatches on the borrowed state word. State 0 disables owner input, creates display handles, rebuilds the group, initializes slot 10 when absent, and submits request word 1 with presence bit 1 before starting transition 3. State 1 clears a separate request and passes it to `Unk0bc1a8_Unk_0bc514`. Other states do nothing. Stack requests are consumed during the provider calls. |
| `func_0211e0ec` | 372 | Polls masks 512/256 for direction and wrapped group changes in 0..6, refreshes selection on list movement, and handles cancel mask 2 by starting transition 3 and storing state 3. Group changes disable owner input and store delay 2 at +0x318. Requires initialized list/cursor views and handles. |
| `func_0211d540` | 444 | Allocates handles from external descriptors, walking sixteen 24-byte records at `data_02151dd8`. Creates four text handles, initializes the +0x2dc text using resource group 5 entry 10, creates eighteen +0x28c handles, binds indices 0/2 to the second descriptor pair and others to the first, then creates +0x288. The work area owns the resulting handles until `func_0211d6fc`. |
| `func_0211d884` | 476 | Clears text accumulation and resolves visible entry strings. IDs below 128 use group 0/1 according to `Unk118b04_Unk_118b78`; larger IDs use entry 128 and optionally key/resource-36 strings. Records widths at +0x2e8 and submits accumulated text to +0x2d8. The original assumes at least one visible entry and valid array indices. See DEC-019 for conditional code generation. |
| `func_0211de14` | 728 | Updates cursor/list state, waits for transition or handle readiness, and advances states 0→1→2. Starts indexed handle animations using the three halfword indices at `data_0213cd1c`, then refreshes handles 2..17. State 2 waits for three text handles before decrementing the nonzero delay and enabling input at zero. State 3 tears down slot 10 and display handles, stores state 4, and clears flag 2 on recorded halfword IDs. State 4 tears down the owner slot. |
| `func_0211e260` | 1112 | Draws layer-2 images and text with state-specific paths; state 4 returns immediately. States 0/1 draw the initial image. States 2/3 draw either group-zero entry images or the alternate selected-entry layout. Uses width-adjusted text rectangles, selected/unselected colors, and ten detail rows at y=49+13×row. Borrows live work resources; drawing calls establish screen coordinates, while unknown rectangle fields remain neutral. |

The request view intentionally clears only two flag bytes and sixteen words,
leaving its two alignment bytes untouched, exactly as the original loops do.
The rectangle view exposes only the four output words used by the text provider.
All fifteen functions now have C implementations. The unit continues to link
from the delink until a human marks it complete. No completion configuration
was changed.

## Hard list

None for M1-T729 or M1-T730.
