# src/game/unit_02068f18.c

All eight M1-T743 functions have matching readable C. Offsets below are evidence
from the delinked ARM instructions; work views borrow storage from callers.

| Function | Contract and evidence |
| --- | --- |
| `Unk068f18_Unk_069afc` | Computes two sums, narrows the first to signed byte before comparing with the second, narrows the selected second sum, and caps at 99. Evidence: shifts by 24 and signed conditional comparison. |
| `Unk068f18_CompareKeyAsc` | Compares four-byte entries: descending byte +2, ascending byte +3, ascending halfword +0. Existing symbol retained; these loads and subtractions establish the key ordering. |
| `Unk068f18_CompareKeyDesc` | Reverses all three comparison keys using the opposite subtraction operands. Inputs require halfword alignment. |
| `Unk068f18_Unk_069888` | Merges six source IDs into six slots at +40, ignoring zero IDs and stopping at the first duplicate or empty slot. Evidence: two six-iteration loops and halfword stores. |
| `Unk068f18_Unk_06a1a8` | Searches the signed-byte slot mapping at shared work +0x348, bounded by input byte +178. Nonnegative slots index pointers at +288; record halfword +54 is compared to the key. Returns slot or -1. |
| `func_0206a124` | Resolves the link at +1000 through `CampStatus_GetLinkUnk14`, adds eight to +1004 for links 145..152, sets +1004 to one for links outside 1..256, and submits resource 0x1801 through `func_02058e9c`. |
| `func_02069ec8` | Produces triangular alpha from signed phase modulo 60, falling from 1 by 0.025 per tick for the first 30 ticks and rising from 0.25 thereafter. Evidence: float literal 0x3ccccccd and alpha argument use in `unit_02090e60.c`. Negative phases retain C signed-remainder semantics. |
| `func_0206902c` | Clears six four-byte output entries, fills nonzero IDs from source halfwords +6..+16, copies byte +3 from six-byte metadata entries through work +168, and searches fifteen category bytes through work +160 against metadata byte +2. The last matching category wins. A typed output record prevents byte-store aliasing from changing index allocation. |

## Validation

Standalone instruction and relocation comparison matches the original for all
three newly implemented bodies. The objdiff gate verifies all eight definitions.
No module boundary changes or new dependencies were needed.

## Hard list

None.
