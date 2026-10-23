# game/unit_020387bc — M1-T468

All eight task functions match the delinked ARM original at 100% objdiff.
The existing C bodies already matched; this task preserves them and adds typed
helper declarations and contracts. No module boundary changes are needed.

| Function | Evidence and contract |
| --- | --- |
| `Unk0387bc_Unk_038820` | At `0x02038820` (28 bytes), returns 0 for a zero handle; otherwise calls `func_020516d0(handle)` and returns 1. The helper's ownership semantics remain unknown, so the neutral name is retained. |
| `Unk0387bc_GetEntry32` | At `0x02038d94` (48 bytes), checks a nullable descriptor, obtains the count with `func_0204fe18(p[1])`, and returns `p[2] + index * 32` only when the unsigned index is below that count. Returns a borrowed entry or null; the stride and indexed access support the existing name. |
| `Unk0387bc_GetEntry32b` | At `0x02038f18` (48 bytes), repeats the same word-1 count, word-2 base, unsigned bound and 32-byte stride contract. Storage remains owned by the caller. |
| `Unk0387bc_GetEntry36` | At `0x02038dc4` (52 bytes), uses descriptor word 3 as the count-helper input and word 4 as the base, returning a borrowed entry at unsigned index times 36. Null descriptor or index at/above count returns null. The stride supports the existing name. |
| `Unk0387bc_GetEntry36b` | At `0x02038f48` (52 bytes), repeats the word-3 count, word-4 base and 36-byte stride contract of `GetEntry36`, including null and unsigned bounds checks. |
| `Unk0387bc_Unk_038cbc` | At `0x02038cbc` (60 bytes), requires a nonnull descriptor and nonzero first word, passes that word to `func_020516d0`, then calls `func_02008848(descriptor, 0, 12)` and returns 1. Failed checks return 0 without modifying storage. Caller supplies at least 12 writable bytes; resource meaning is unknown. |
| `Unk0387bc_Unk_038d58` | At `0x02038d58` (60 bytes), has the same checks and calls as `038cbc`, but clears 20 bytes. Caller supplies at least 20 writable bytes. Neutral name retained because resource meaning is unknown. |
| `Unk0387bc_Unk_038e40` | At `0x02038e40` (60 bytes), repeats the 12-byte clearing contract of `038cbc`, including returning 0 without clearing a null descriptor or zero first word. Neutral name retained. |

## Validation

Use `python3 tools/match_gate.py` for instruction and relocation matching;
`python3 tools/checksum.py` verifies the original linked image. No new behavioral
tests are required by the card: the delinked instructions are the acceptance oracle.

## Hard list

None for M1-T468. Other functions already present in this translation unit are
outside this card; `func_02038888` and `func_02038934` remain supplied by the delink.
