# game/unit_0211d520 — M1-T729

All eight functions match the delinked ARM object at 100% objdiff. Field names
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

The two work structs are local views of the same object. Their offsets come from
loads/stores; handles remain opaque words. The unit remains linked from the
original delink pending human completion marking, as required by the card.

## Hard list

None for M1-T729. Functions assigned to other cards remain outside this change.
