# game/unit_020387bc — M1-T468 / M1-T469 / M1-T470

All sixteen task functions match the delinked ARM original at 100% objdiff.
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

## M1-T469

The eight existing bodies also match the original instructions exactly. Helper
arguments are now explicit, including passing the entry returned by
`func_0204fdac` to `func_0204fde0`; the original preserves that entry in r0.
Neutral names are retained because resource identities are not established.

| Function | Evidence and contract |
| --- | --- |
| `Unk0387bc_Unk_0387bc` | `0x020387bc`, 100 bytes: clears a 64-byte stack buffer, initializes it using `data_02141f98[2]`, applies the input source, then returns `func_02051610(buffer)`. The helpers must consume the temporary within the call. |
| `Unk0387bc_Unk_03883c` | `0x0203883c`, 76 bytes: calls `func_0205ad2c` with global word 0, stores the second and third arguments into work words 0 and 1, calls `Unk05b82c_CreateEntry`, then copies halfwords at work-word-5 offsets 40/42 into argument 2 offsets 4/6. All accessed storage must be valid. |
| `Unk0387bc_Unk_038c74` | `0x02038c74`, 72 bytes: creates a handle from `data_02142024`, then stores it, its index-0 entry, and the derived entry value into three writable words. Null output or failed creation returns 0 without writes; success returns 1. |
| `Unk0387bc_Unk_038cf8` | `0x02038cf8`, 96 bytes: uses `data_02142034` and writes five words: handle followed by entry/derived pairs for indices 1 then 0. Same null/failure return contract as `038c74`. |
| `Unk0387bc_Unk_038df8` | `0x02038df8`, 72 bytes: repeats the three-word initialization contract using `data_02142048` and index 0. |
| `Unk0387bc_Unk_038e7c` | `0x02038e7c`, 96 bytes: repeats the five-word initialization contract using `data_02142054`, indices 1 then 0. |
| `Unk0387bc_Unk_038edc` | `0x02038edc`, 60 bytes: returns 0 for null output or zero handle. Otherwise passes the handle to `func_020516d0`, clears all 20 caller-owned descriptor bytes and returns 1. |
| `Unk0387bc_Unk_038f7c` | `0x02038f7c`, 64 bytes: uses `data_02142064` to create a handle and stores it and `func_0204fe68(handle, 0)` into two writable words. Null output or failed creation returns 0 without writes; success returns 1. |

## Validation

Use `python3 tools/match_gate.py` for instruction and relocation matching;
`python3 tools/checksum.py` verifies the original linked image. No new behavioral
tests are required by the card: the delinked instructions are the acceptance oracle.

## Hard list

None. Both M1-T470 functions now match at 100%; the TU remains linked from the delink until human completion approval.

## M1-T470

The original neutral `func_` symbols are retained because resource identities are
unknown. Private typed views preserve observed alignment and caller ownership;
no shared module boundary changes are introduced.

| Function | Evidence and contract |
| --- | --- |
| `func_02038888` | `0x02038888`, 172 bytes, 100%: returns 0 for null output; obtains resource 36/index 0, checks the unsigned record index against `func_0204fe18`, and copies a 40-byte halfword-aligned record to output offset 512 when selector is 1, otherwise offset 0. Returns 1 after copying, 0 for an invalid index. Output must cover the selected destination. |
| `func_02038934` | `0x02038934`, 832 bytes, 100%: opens `data_02141ffc`, checks the unsigned primary index, selects four signed byte indices using section 0, 1, or 2 depending on mode/variant, and copies 24/32/40-byte records from sections 3/4/5. Byte 22 of the selected 24-byte record chooses the first pair-list section after adding 6; sections 11 and 10 supply the other lists. Each list count is capped at 60. Output is caller-owned, at least 512 bytes; embedded selection indices must be valid for the resource. Returns 0 for null output, failed open, or invalid primary index, otherwise 1. Every successfully opened handle is released. |

The cleanup call at `0x02038c58` passes `data_02142010` in r1. Its callee
`Unk0387bc_Unk_038820` does not read that argument; its typed signature now
records this observed context argument without changing its instructions.
The record-copy temporary pointers and declaration order preserve the original
register allocation. No behavioral tests were added (`tests_required = false`);
the original instructions and objdiff relocations provide the matching oracle.
