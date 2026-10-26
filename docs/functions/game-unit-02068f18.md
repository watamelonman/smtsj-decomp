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

## M1-T744

All eight requested bodies match. Existing `func_` symbols are retained
because renaming the protected symbol map is outside this card's scope. Names
for metadata fields describe instruction-established access patterns only.
All layout views borrow storage; they introduce no ownership boundary.

| Function | Contract and evidence |
| --- | --- |
| `func_02068f78` | Initializes six output records to 255, then fills nonzero source IDs unless source halfword +54 equals the excluded ID. Copies metadata byte +3 through the six-byte table at work +168; the last match among fifteen category bytes at +160 supplies output byte +3. |
| `func_02069a00` | Writes the selected ID to work +1022, searches eight-byte bonus rows through +156 with count +192, and updates signed stat bytes +4,+8,+5,+6,+7 using base bytes twenty bytes later and metadata byte +10. Calls the existing saturating sum helper for each stat. |
| `func_0206970c` | Filters six source IDs against metadata low two flag bits and category mask bits from target metadata halfword +8. Excludes IDs already in the target, builds six zero-initialized sortable records, sorts with CompareKeyAsc, copies all six halfwords to output, and returns the selected count. Shift/narrowing order follows the original ARM operations. |
| `func_020698e0` | Checks metadata level against global byte +110 unless feature 1024 bypasses it; records that result at work +1016. For each supplied ID, checks the first matching active slot using shared count +855 and signed slot mapping +840. A zero result from 02096ab0 rejects selection. An ID already in the work must occur in the supplied list. |
| `func_02069f50` | Draws indexed resources 86, twelve alternating 87/88 rows at 22-pixel intervals, 84, a proportional indicator, then 85 and the widget at +268. Evidence: resource pointer +944, signed scroll/extent halfwords +342/+344, and rendering calls. Keeps the original unsigned division and extent minimum of 24, including its denominator behavior. |
| `func_02069b24` | Uses two variable-length halfword scratch arrays to choose distinct source IDs whose metadata bits 2..3 equal one, excludes existing IDs, merges selections, randomly removes overflow beyond six, and compacts nonzero IDs into the target. Source halfwords +2..+8 and six target slots establish the bounds; RNG wrapper 02050074 inserts a zero minimum and receives stream 1. |
| `func_020690d0` | Combines two six-ID candidate lists. Builds a temporary copy of the target (60 bytes), optionally replacing its ID with the fifth argument, and calls 0206970c for both sources into two 18-byte records. If both selections are empty it builds twelve records with 02068f78 and sorts them descending with CompareKeyDesc, then fills only the first empty target slot with a distinct, marked, nonzero ID other than 0xffff. Otherwise it builds both candidate halves with 0206902c and sorts ascending with CompareKeyAsc, filling successive empty target slots with distinct nonzero IDs. Evidence: 596 bytes, the two comparator literals, the 0xffff literal, and the five-slot bound. |
| `func_02069324` | Extends candidate construction to the selected 28-byte row at work +148. Allocates an 18-byte candidate array and a 24-byte record array per signed count byte +851, releasing both with 02053000. For each nonzero row ID it resolves an active unit slot through 02096ab0/020a1428; an active slot supplies the unit ID, level, and a 0206970c selection, while the metadata-default path also copies twelve bytes at +46. If no candidate selected IDs, it rebuilds six records per row entry with 02068f78, sorts descending, and fills the first eligible slot; otherwise it builds records with 0206902c, sorts ascending, and fills up to five slots. Evidence: 1000-byte size, 28-byte row stride, 18/24-byte allocations, the twelve-byte copy, both comparator literals, and the 0xffff literal. |

## Validation

Standalone original instruction/relocation comparisons match all eight new
bodies. The full objdiff gate reports all fifteen definitions in this unit at
100%, including the eight M1-T743 bodies. Build, anticheat, all project tool
tests, and checksum pass; checksum reports every artifact byte-identical to the
original. No tests were added because the card does not require them and
original code comparison supplies the relevant acceptance check.

## Hard list

None for this unit. `func_02069324` is sensitive to index and declaration
placement: mwcc strength-reduces `records + index * 6` into a byte pointer unless
the ascending selection loop uses its own index and the record sorting uses
block-local slot/candidate variables, while its first loop index must be
declared first. Those constraints are code-generation details from the original
instruction stream, not extra storage or ownership.

