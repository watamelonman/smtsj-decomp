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

## Other functions

Existing functions at 0x0211f43c, 0x0211f544, 0x0211f58c, 0x0211f5d4 and
0x0211f61c are outside this card. Their logic is unchanged; calls in
0x0211f43c now explicitly pass the already-loaded fields to satisfy the typed
helper declarations. All thirteen implemented functions still match at 100%.
The factory and remaining callbacks belong to M1-T394.

## Hard list

None for M1-T393.
