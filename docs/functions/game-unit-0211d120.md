# game/unit_0211d120

All seven functions match at 100% objdiff. Names follow the configured symbols;
behavior descriptions below describe observed data flow without assigning a
broader gameplay purpose. Layouts are local views, not shared object definitions.

| Function | Evidence and contract |
| --- | --- |
| `func_0211d120` | Writes size 176 and mode 1, preserves +8, and installs the five literal callback addresses at +12..+32 with a null at +24. Caller supplies writable descriptor storage. |
| `Unk11d120_Init` | Stores the borrowed work pointer in `data_02176e74`, then tail-calls `func_02008848` with zero and 176. The actual allocation must cover 176 bytes despite the smaller local field view. |
| `Unk11d120_Unk_11d198` | Calls both setup routines with 1. A nonzero +4 word selects record lookup, slot 6 ID, slot 7 record byte +2, and command 8; zero forwards the ID to `func_02065b10`. The entry and lookup result must be valid. |
| `func_0211d200` | State 0 waits for two predicates, increments the signed queue index, then dispatches the next entry or enters state 1 and calls `func_02065c30`. State 1 waits before task completion. Other states do nothing. |
| `Unk11d120_Unk_11d288` | Frees the allocation at work +4 through `func_02053000`, then nulls that pointer. The cleanup callback owns this allocation. |
| `func_0211d2a4` | First lookup selects an alternate record, whose ID predicate and eligibility determine the result. Only a null first lookup uses the original record: bit 0 gates eligibility and bits 1..15 supply an optional ID predicate. Returns zero for exclusion. Non-null lookup results are borrowed. |
| `func_0211d338` | Counts requested entries in six-byte input records (nonzero ID, flag bits 2/3), allocates eight bytes per entry, and fills ID/dispatch pairs. Returns the initialized token without creating a task when both count and special mode are zero. Special mode begins at index -1 and sends command 11 plus value 83; ordinary mode dispatches entry zero. The task owns the new queue; input remains borrowed. |

The packed bitfields reproduce the original extraction instructions and preserve
independent reads in the counting loop. The zero index assignment occurs only
on the nonempty queue path, as in the original; task initialization supplies the
remaining initial state. No domain-specific descriptive names are inferred.

## Validation

`tools/hand/cmp.py` verified all seven instruction sequences against the original.
The objdiff match gate, build, checksum, unittest suite, and anticheat gate were
run locally. No new behavioral tests are required by this matching-only card.

## Hard list

None.
