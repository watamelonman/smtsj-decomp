# game/unit_0211f2d0 — M1-T393

All eight card functions match at 100% in objdiff. Evidence below refers to
ARM instructions in the delinked original, not inferred gameplay meanings.
The existing C bodies already matched; this card adds typed record views,
helper prototypes and behavior contracts without changing their instructions.
Records are borrowed, word aligned, and non-null unless explicitly stated.

| Function | Evidence and contract |
| --- | --- |
| `Unk11f2d0_Unk_11f2d0` | 0x0211f2d0–0x0211f304: if word 0 is nonzero, pass words +4 and +8 to 0x0205ddb4 and 0x020629c4, respectively, then clear all 0x28 bytes through 0x02008848. An inactive record is untouched. |
| `Unk11f2d0_Unk_11f308` | 0x0211f308–0x0211f31c: when word 0 is nonzero, store the supplied word at +0x14 and then store 1 at +0x10. |
| `Unk11f2d0_Unk_11f320` | 0x0211f320–0x0211f330: when word 0 is nonzero, store 3 at +0x10. |
| `Unk11f2d0_IsFieldCSet` | 0x0211f334–0x0211f350: return 0 for null, otherwise normalize word +0xC to 0 or 1. The existing name is supported directly by that load and comparison. |
| `Unk11f2d0_Unk_11f354` | 0x0211f354–0x0211f378: when the pointer at data_02176e78 is zero, call 0x0211f3c8 and store its result there. The factory allocates and initializes work at 0x0211f3c8–0x0211f428. |
| `Unk11f2d0_Unk_11f37c` | 0x0211f37c–0x0211f398: if the singleton is present, forward its address in r0 to 0x02061424. No local clearing of the global occurs. |
| `Unk11f2d0_IsState7` | 0x0211f39c–0x0211f3c4: return 1 for an absent singleton, otherwise return whether its first word is 7. BattleShowingTask calls this between the 0x0211f354 and 0x0211f37c wrappers; no more specific state meaning is assumed. |
| `Unk11f2d0_Unk_11f664` | 0x0211f664–0x0211f678: set words +0/+4/+8 to 0/11/0, and halfword +0xC to zero. Bytes after +0xD remain untouched. |

The 0x28-byte record and singleton prefix are separate views: the former's
+0xC query reads a word, whereas singleton initialization writes a halfword.
No module boundary changes or new public header are needed.

## M1-T394

All eight functions below match at 100% in objdiff. Addresses refer to the
original ARM instructions. Work pointers are borrowed, aligned and non-null;
slot creation follows the original contract that the factory returns a valid object.
Neutral names are retained because the field accesses do not establish gameplay roles.

| Function | Evidence and contract |
| --- | --- |
| `Unk11f2d0_Unk_11f544` | 0x0211f544–0x0211f588: if +0x24 is zero, create from +0x14/+0x1C with mode 1, store the result, select index 0 through its first word, then call 0x0205c6e0. |
| `Unk11f2d0_Unk_11f58c` | 0x0211f58c–0x0211f5d0: same creation contract for +0x28, selecting index 1. |
| `Unk11f2d0_Unk_11f5d4` | 0x0211f5d4–0x0211f618: same creation contract for +0x2C, selecting index 2. |
| `Unk11f2d0_Unk_11f61c` | 0x0211f61c–0x0211f660: create +0x30 from +0x18/+0x20 with mode 0, select index 0 and start through the first word. Existing slots are untouched. |
| `func_0211f3c8` | 0x0211f3c8–0x0211f438: allocate 0x34 bytes with alignment argument 4 and four callback addresses; return zero on allocation failure, otherwise initialize the prefix and resources and return the allocation. |
| `func_0211f67c` | 0x0211f67c–0x0211f700: forward five words from data_0213cd2c to 0x0205b82c; load three resources with mode 1 into +0x10/+0x14/+0x18 and two contexts into +0x1C/+0x20. |
| `Unk11f2d0_Unk_11f43c` | 0x0211f43c–0x0211f540: release nonzero slots +0x24/+0x28/+0x2C/+0x30, contexts +0x1C/+0x20 and resources +0x10/+0x14/+0x18 in that order, clearing each; call 0x0205bb68 five times and clear the singleton. |
| `func_0211f704` | 0x0211f704–0x0211f890: dispatch states 0–7. Decrement signed word countdowns before transitions with delays 2/8/20/30; state 5 decrements a signed halfword initialized to 600 and checks mask 0xC03 through 0x02053800. Timeout or input enters state 6 with delay 11, then state 7. States 7 and out-of-range values do nothing. |

The factory callback signatures describe only the work pointer observed here;
no module boundary changes or new public header are needed.

## Hard list

None for M1-T393 or M1-T394.
