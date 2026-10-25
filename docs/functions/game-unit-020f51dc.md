# game/unit_020f51dc — M1-T721 and M1-T722

All sixteen implemented functions match at 100%. Names are retained from the symbol map;
helper purposes remain uncertain, so no new descriptive symbols are introduced.
Evidence below is the original ARM instruction stream at each function address.

| Function | Contract and evidence |
| --- | --- |
| `Unk0f51dc_Unk_0f623c` | Calls `func_02057eb8(-1)`, then `func_020572d8()`. Evidence: MVN of zero followed by the two BLs. |
| `Unk0f51dc_Unk_0f5738` | Forwards signed coordinates to `func_020f6250(6, x, y, 17)`. Evidence: register shuffle and constants before the tail call; coordinate callers also appear in unit_020f09b4. |
| `Unk0f51dc_Unk_0f5dfc` | Same forwarding contract with selector 10. Evidence: constants 10 and 17 before the tail call. |
| `Unk0f51dc_Unk_0f5ab4` | Same forwarding contract with selector 17. Evidence: r0 is set to 17 and copied into r3 before the tail call. |
| `Unk0f51dc_Unk_0f621c` | Calls `func_02057e18(31)`, `func_02057ddc(-1)`, then `func_02057524(4)`. Evidence: three constant loads and ordered BLs. |
| `Unk0f51dc_Unk_0f57d4` | Forwards five arguments and appends `(0, 8, 0)` to `func_020f58bc`. Evidence: fifth argument loaded from the incoming stack and four outgoing stack stores. |
| `func_020f5754` | First argument indexes `Unk0ea208_GetArr58`; null returns immediately. The low five bits of word +0x24 provide the outgoing seventh argument, except kind 8 converts bits 12–16 through `Unk0f7eb4_Unk_0f7eb4`. Appends zero and byte +0x22 while forwarding the original five arguments. Evidence: LSL/LSR pairs, compare against 8, conditional branch over conversion, LDRB and outgoing stores. The record is borrowed. |
| `func_020f5ad4` | Zero alpha or zero shared handle returns immediately. Caller must provide a valid index into `data_0213c954`. Submits the selected entry through `func_0205de40` with mode 2, unit scales, zero extra value and order 16. For flag zero and index 2, replaces alpha with 0.84f. Evidence: `_feq`, shared-handle null check, indexed LDR, literal 0x3f570a3d and outgoing argument stores. |

## M1-T722

The eight functions below retain their neutral symbol-map names because the
instruction stream establishes submission mechanics, not their game-facing purpose.
All eight are 100% in objdiff; the existing eight functions remain 100%.
The two wrappers that forward the fifth argument now type it as `float`, matching
`func_020f58bc`'s `_feq` and `_fmul` use without changing their generated code.

| Function | Contract and evidence |
| --- | --- |
| `func_020f5800` | Zero alpha or missing GetField0 handle returns. Caller supplies a valid index into `data_0213c948`; submits the entry at order 16. Index 2 with flag zero multiplies alpha by 0.84, with an explicit alpha-equals-one case. Evidence: `_feq`, `_fmul`, literal 0x3f570a3d and indexed LDR. |
| `func_020f5e18` | Resolves the incoming index through `func_02044ec4`, reads its value with `func_0204a244` and fields 12–15 with `func_0204a67c`, then forwards to `func_020f5ec4`. Field 15 becomes a boolean; no calls beyond GetField0 occur when its handle is absent. Evidence: ordered BLs, constant field selectors and conditional moves. |
| `func_020f5d0c` | Requires a nonzero maximum. Submits entry 12 at the supplied coordinates, then entry 13 with position `(a*86)/maximum - ((maximum-b)*43)/maximum` and vertical scale `(float)((b*100)/maximum)/100.0f`. Evidence: integer division occurs before `_fflt` and `_fdiv`; orders are 16 and 18. |
| `func_020f5b68` | Returns for zero alpha, missing handle or missing borrowed Arr40 record. Submits entry 11, converted halfword +0x20 text, converted byte +0x2c icon and borrowed Arr24 data. Mode 2 brackets the Arr24 submission with color setup/reset. Evidence: LDRH +0x20, LDRB +0x2c, helper BLs and 0x5a5a5a00 literal. The Arr40 view exposes only those observed fields. |
| `func_020f51dc` | Mode zero or missing handle returns. Modes 2/3/4 derive width from percent times 120/125/136 divided by 100, use zero origin and scale `(width+66)/66.0f`; other nonzero modes use the supplied origin and unit scale. Submits entries 0, 1 and 2 between setup/reset calls. Evidence: compare chain, signed division sequences, `_fflt`/`_fdiv` and constants at each submission. |
| `func_020f58bc` | Zero alpha or missing handle returns. Submits entry 18 and flag-selected entry 19/20, converted icon, text value and borrowed Arr24 data. Alpha drives the observed byte-sized 0–31 setup value through unsigned float conversion followed by signed division. Mode 2 brackets Arr24 with color setup/reset. Evidence: selector branches, helper BLs and outgoing stack arguments. |
| `func_020f53d0` | Requires a valid `data_0213c93c` index. Group 0 selects Arr10 entries 0–2 directly; group 1 maps selectors 0,3,4,5,7,1,2,6 to entries 0,1,2,3,4,0,1,2. Each group resets color and submits the table entry. Groups 2–4 and other groups perform no submission. Index 2 sets color and optionally uses 0.84 alpha. Evidence: outer and inner ARM jump tables, ordered case bodies and shared table literal. |
| `func_020f5ec4` | Nonpositive percent or absent GetField4 handle returns. Shifts x by -20 and fades the base entry using percent/100 below 100; remaining submissions require percent >=100. Converts the low halfword of value to an icon and uses the full value to index `data_0213c960` (caller must provide a valid index). Submits borrowed GetField3c data and three values using separate zero/nonzero format strings, then entry 1 or a fourth string according to flag. Evidence: signed percent branches, byte-table LDRB, low-halfword extraction, format symbols `data_02150e38` through `data_02150e50`, and variadic outgoing argument stores only for nonzero values. |

Validation: all eight direct instruction comparisons passed; `match_gate.py`,
`anticheat.py`, all nine repository unit tests and `checksum.py` passed. The TU
remains linked from the original delink pending the human completeness change.

## Hard list

None.
