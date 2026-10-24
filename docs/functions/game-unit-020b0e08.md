# game/unit_020b0e08 — M1-T337

All three functions match at 100% objdiff. Existing neutral symbols are retained:
the instruction evidence establishes selection mechanics, but not the game-level
meaning of the objects or query values. No module boundaries change.

The singleton getter supplies a borrowed manager with ten object pointers at
+0x64. Each object starts with a packed ID; bits 16–23 must be nonzero and
must equal the filter unless the filter is zero. A null manager returns zero.
Object pointers must remain valid during the calls. Local candidate records
contain a signed query, the packed ID, and an unsigned weight.

| Function | Contract and evidence from original ARM instructions |
| --- | --- |
| `func_020b0e08` (292 bytes) | Excludes objects whose `func_0204abd8(object, 0)` result is nonzero; assigns every remaining ID weight 100 and selects one. Returns zero when none qualify. The query field is unused on this path. |
| `func_020b0f2c` (536 bytes) | Excludes nonzero `func_0204a9ec` results and objects with byte +0x282 bit 2 set. Records `func_02049d80(object, 0)`, sorts descending through `Unk0b0b5c_Unk_0b0d28`, and retains at most three. Weights become 60/30/10 for three and 80/20 for two (80 for one). No candidates delegates to `func_020b0e08(filter)`. |
| `func_020b1144` (388 bytes) | Applies the baseline predicate and +0x282 bit-2 exclusion. Keeps only objects tied for the smallest signed mode-zero query, each at weight 100. The original calls the query separately for both comparisons and again on insertion; this call sequence is preserved. No candidates delegates to the baseline selector. |

Selection calls `func_02050074(0, totalWeight - 1)`, then compares the result
with each weight using **less than or equal**, subtracting weights as it advances.
If the scan is exhausted, it returns the last candidate. This preserves the
original boundary behavior rather than assuming a conventional weighted draw.
See DEC-008 for the shared selection exit.

No new tests are required by this card: original instruction comparison,
objdiff, and the image checksum provide the acceptance checks.

## Hard list

None.
