# src/game/unit_020d297c.c

## M1-T567

All eight functions are implemented in C. Evidence is the ARM disassembly at the
addresses below; unknown domain meanings retain the existing neutral names.
The wrappers preserve arguments and results across their tail branches.

| Function | Address / size | Contract and evidence |
| --- | --- | --- |
| `Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e6448` | `0x020d2b58` / 12 B | Tail branch to `Unk0e5fb8_Unk_0e6448(u32 index)`; forwards the caller's table index unchanged in r0. Returns the low two-bit value (0..3). At `0x020e644c` the target saves the index and at `0x020e6454` passes it in r1 to `Get2BitsD80`. The original leaves the low two-bit value (0..3) in r0 (`orr`/`and #255` at `0x020e6490`/`0x020e6494`), which is a two-bit value rather than a predicate. The existing callee definition incorrectly declares void: callers at `0x020d2ab0` and `0x020d2af8` compare its r0 result; that out-of-scope definition needs a matching int return contract. |
| `Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e64c8` | `0x020d2b64` / 12 B | Tail branch to `Unk0e5fb8_Unk_0e64c8`; forwards the caller's u32 value in r0. |
| `Unk0d297c_Thunk_02095398` | `0x020d3098` / 12 B | Tail branch to the +0x9a0 setter at `0x02095398`; forwards the u32 value. |
| `Unk0d297c_Thunk_020953ac` | `0x020d30a4` / 12 B | Tail branch to the +0x9a0 getter at `0x020953ac`; returns its u32 result. |
| `Unk0d297c_Unk_0d2adc` | `0x020d2adc` / 16 B | Sets r1 to zero and branches to `Unk0e651c_Unk_0e651c`, preserving the caller's r0 value. |
| `Unk0d297c_Unk_0d32e8` | `0x020d32e8` / 16 B | Loads buffer pointer at +0 and reads a halfword at caller index times two. No bounds check; caller supplies a valid index. |
| `Unk0d297c_Unk_0d32f8` | `0x020d32f8` / 16 B | Loads buffer pointer at +0 and index at +0x0c; returns their sum with index scaled by two. Result is borrowed; caller guarantees validity. |
| `Unk0d297c_Unk_0d3138` | `0x020d3138` / 20 B | Loads literal `0x751` into r0 and tail branches to `Unk0e651c_Unk_0e666c`; preserves the query result. |

The local `Unk0d297cBuffer` view records only the observed pointer and index
layout. It introduces no shared module boundary or allocation ownership change.
No new tests are required by this card; objdiff checks the emitted instructions.

## M1-T568

All eight targets match at 100% objdiff. Contracts follow the original ARM
instructions; unknown domain meanings retain neutral names. Existing bodies
already matched on entry; this card adds typed buffer access and evidence comments.

| Function | Address / size | Contract and evidence |
| --- | --- | --- |
| `Unk0d297c_Unk_0d3250` | `0x020d3250` / 20 B | Stores caller words at +0/+4, clears +0x0c/+0x10, preserves +8. Caller provides five writable words. |
| `Unk0d297c_Unk_0d32ac` | `0x020d32ac` / 20 B | Reads a halfword through the pointer at +0 using signed index at +4. Caller guarantees a valid address; no bounds check. |
| `Unk0d297c_Call_020d297c` | `0x020d2a8c` / 24 B | Adds 50, truncates to u16 via shifts, tail calls func_020d297c. Unsigned input preserves ARM wrapping arithmetic. |
| `Unk0d297c_Unk_0d31e8` | `0x020d31e8` / 24 B | Clears +4, +0, +0x0c, +0x10 in that order; preserves +8. Caller provides five writable words. |
| `Unk0d297c_Unk_0d3290` | `0x020d3290` / 28 B | Signed comparison of +4 and +8 gates a halfword write through +0. Does not advance index or check negative values; caller guarantees valid storage. |
| `Unk0d297c_Unk_0d33ac` | `0x020d33ac` / 32 B | Passes work's leading slot to FreeSlot, calls func_02053000 with +0x18, then clears +0x18. The second release is unconditional. |
| `Unk0d297c_Unk_0d2aec` | `0x020d2aec` / 36 B | Queries Unk0e5fb8_Unk_0e6448; nonzero result calls Unk0e5fb8_Unk_0e649c with original argument and mode 2. |
| `Unk0d297c_LoadMissionLog` | `0x020d2e64` / 36 B | String at data_02150680 identifies Data/Event/Mission/MissionLog.mbb. Calls func_02051610, stores returned handle in data_02176be0, returns 1 without checking it. |

No tests are required by this matching card; objdiff verifies emitted code.
The borrowed buffer layout is local, with no shared boundary change.

## M1-T569

All eight targets match at 100% objdiff. Existing bodies already matched on
entry; this card makes register-carried arguments explicit, types the next-element
buffer view, and records the original instruction contracts. Unknown domain
meanings retain neutral names.

| Function | Address / size | Contract and evidence |
| --- | --- | --- |
| `Unk0d297c_Unk_0d2f18` | `0x020d2f18` / 36 B | Gets handle 29, selects table 0, forwards caller index to func_0204fed8; ignores result. Original mov/bl chain fixes the indices and order. |
| `Unk0d297c_Unk_0d2f3c` | `0x020d2f3c` / 36 B | Same lookup chain with table 1; caller index survives in r4 until the final call. |
| `Unk0d297c_Unk_0d2f98` | `0x020d2f98` / 36 B | Same lookup chain with table 3; result is ignored. |
| `Unk0d297c_FreeSlot` | `0x020d322c` / 36 B | Loads the owned allocation from the caller's writable slot, returns if zero, otherwise passes it to func_02053000 and clears the slot. The original ldr leaves the allocation in r0 for the release call; C now passes it explicitly. |
| `Unk0d297c_Unk_0d2b70` | `0x020d2b70` / 40 B | Forwards caller index to Unk0e651c_Unk_0e654c and Unk0d297c_Unk_0d2aa4, queries func_02095818, calls Unk02dcfc_SetField64 unless result equals 1. The first call consumes the original r0; its explicit argument agrees with the callee's index contract. |
| `Unk0d297c_Unk_0d2c1c` | `0x020d2c1c` / 40 B | Calls Unk0e651c_Unk_0e6560(index), Unk094fe0_Call_02095370(index, 1), Unk0d297c_Unk_0d2aec(index), then Unk02dcfc_SetField64. Original r4 saves index across all calls. |
| `Unk0d297c_Unk_0d2e88` | `0x020d2e88` / 40 B | Unconditionally releases the handle stored by LoadMissionLog in data_02176be0, clears it, returns 1. No zero guard or error query appears. |
| `Unk0d297c_Unk_0d32c0` | `0x020d32c0` / 40 B | Signed comparison index (+4) < capacity (+8) - 1 gates the halfword read at data (+0) + index * 2 + 2. Returns zero otherwise; does not advance index. Caller guarantees valid storage, lower bound, and representable capacity - 1. |

No new tests are required by this card; objdiff checks emitted instructions.
The buffer view remains local, with no module boundary change.

## Hard list

None for M1-T568 or M1-T569.

## M1-T570

All eight targets match at 100% objdiff. The instruction addresses below establish
contracts; unknown record meanings retain neutral names. No module boundary changes.
The original instructions and objdiff serve as the acceptance oracle; no new tests
are required by the card.

| Function | Address / size | Contract and evidence |
| --- | --- | --- |
| `Unk0d297c_Unk_0d3308` | `0x020d3308` / 40 B | Calls leading-buffer reset, clears extension words +0x14/+0x18/+0x1c and sets +0x20 to 256. Takes a writable work pointer. |
| `Unk0d297c_Unk_0d3330` | `0x020d3330` / 40 B | Calls 0x02008848 with allocation +0x18, zero fill and +0x20 shifted left two bytes; clears +0x1c. Caller provides valid allocated storage. |
| `Unk0d297c_Unk_0d3200` | `0x020d3200` / 44 B | Stores signed halfword capacity at +8, clears +4, allocates capacity shifted left one bytes, stores allocation at +0, clears +0x0c/+0x10. |
| `Unk0d297c_PushU16` | `0x020d3264` / 44 B | Signed count +4 < capacity +8 gates halfword store at data[count] and count increment. The store and increment support the existing descriptive name. Caller guarantees storage and nonnegative count. |
| `Unk0d297c_Unk_0d3004` | `0x020d3004` / 48 B | Returns zero for absent mission-log handle; otherwise resolves table zero, entry zero through 0x0204fe68 and 0x0204fed8. |
| `Unk0d297c_Unk_0d2aa4` | `0x020d2aa4` / 56 B | For zero query result, forwards index with mode 1 to 0x020e649c and 0x020e651c, then stores it through +0x9a0 setter. Nonzero query returns immediately. |
| `func_020d2f60` | `0x020d2f60` / 56 B | Looks up caller index through 0x020d2eb0; null returns zero. Otherwise resolves handle 29, table 2, entry selected by low seven bits of record byte +3. Local byte bitfield preserves original lsl/lsr extraction. |
| `func_020d2b10` | `0x020d2b10` / 72 B | Decrements selector modulo 256; values >=5 return zero. Null lookup returns zero. Reads signed word at +4 + selector*4: negative returns one, otherwise queries 0x020e666c with the word. |

Hard list for M1-T570: none.

## M1-T571

All eight targets match at 100% objdiff. Neutral names are retained because the
instructions establish mechanics rather than domain meanings. Local borrowed
views describe only observed offsets; ownership and module boundaries are unchanged.

| Function | Address / size | Contract and evidence |
| --- | --- | --- |
| `Unk0d297c_Unk_0d2fbc` | `0x020d2fbc` / 72 B | Returns zero for absent mission-log handle or record; otherwise resolves table zero using record word +0x40. Loads and calls at 0x020d2fc0..2ff8 establish the lookup chain. |
| `Unk0d297c_Unk_0d3358` | `0x020d3358` / 84 B | Writable work pointer and signed halfword capacity. If +0x14 is zero, initializes leading buffer, releases any old +0x18 allocation, allocates +0x20 words and sets +0x14. Always clears extension storage afterward. The release receives the loaded allocation in r0. |
| `Unk0d297c_Unk_0d3034` | `0x020d3034` / 100 B | Unsigned selector dispatches 1 to 0x02099bac, 3 to 0x020a1814, and 4 through query 2 at 0x0204fb14 with u16 truncation. Other selectors return zero; jump table and shifts establish the contract. |
| `func_020d2eb0` | `0x020d2eb0` / 104 B | Searches handle 28 table zero, comparing each 68-byte record's first byte with caller index. Index outside 1..count becomes one. Returns borrowed record address or zero. Original cmp/cmpcs preserves the inclusive range check. |
| `func_020d2b98` | `0x020d2b98` / 132 B | Decrements u8 selector with wrapping; values >=5 return. Query states 1/2 store index at +0x9a0 and call 0x020e64c8; a zero result forwards mode 2. Looks up the record and sets its selected nonnegative word through 0x020e66a4. Original comparison after 0x020e64c8 proves its return is consumed. |
| `func_020d30b0` | `0x020d30b0` / 136 B | Counts handle 28 records with byte +3 high bit set, and how many pass the index query at 0x02095320. Returns matched * 100 / total using signed division. No zero-total guard exists in the original. |
| `func_020d314c` | `0x020d314c` / 156 B | Null returns zero. Halfword tag 1 requires index <0x5b5 and nonzero payload; tag 2 requires nonzero payload; tag 3 compares index with 0x020a1728; tag 4 returns one; others zero. Literal at 0x020d31e4 supplies the bound. |
| `func_020d297c` | `0x020d297c` / 272 B | Formats u16 id into a zeroed 64-byte path using data_02150660. Missing path returns one. Loads the file with allocation-mode setup/restore, visits 12-byte entries, truncates their two status words to s16, and forwards index to 0x0209596c only if both status queries pass. Stops at the last entry, releases the file, returns one. Calls and stride at 0x020d29b8..2a78 establish behavior. |

Validation: match gate passed all 53 C definitions in the changed unit; checksum
reported all artifacts byte-identical; anticheat passed; all nine unit tests passed.
No new tests are required by this card; objdiff checks the original instructions.
Hard list for M1-T571: none.

## M1-T572

| Function | Address / size | Contract and evidence |
| --- | --- | --- |
| `func_020d33cc` | `0x020d33cc` / 280 B | Copies a terminated halfword stream into the work buffer. Calls 0x02062268 and 0x020d3358 to prepare capacity, clears the first section offset, and queries tokens through 0x0204f9fc/0x0204f9d8. Replaces token 0x8001 with zero and records the resulting count at the next section offset. Other command tokens copy the argument count returned by 0x0204f8c0. Appends a final zero. Caller supplies a valid terminated stream; original has no extra bounds or section-capacity checks. |
| `func_020d2c44` | `0x020d2c44` / 544 B | Remains linked from the original delink. The attempted C resolves the mission-log stream after 0x0210af40 setup, emits `[1, 0]` if absent, filters sections using 0x8075 selector queries at 0x020d2b10, unpacks words between 0xffff and 0xfffe, and records 0x8001 boundaries. No guessed domain name was introduced. |

The work view now types the previously opaque leading five words at the offsets
observed in the buffer helpers. PushU16 accepts a word and stores its low halfword,
matching the original unmasked argument forwarding. Both are local changes;
module boundaries and ownership are unchanged.

### Hard list for M1-T572

- `func_020d2c44`: attempted structured token dispatch, separate signed argument
  counts and high-byte temporaries, and alternate packed-word loop forms. The
  closest standalone comparison had the exact 544-byte size and control flow,
  but five instructions differed in the packed-word loop: the compiler loaded
  the packed word into r2 rather than r1 and scheduled its high-byte extraction
  differently. Declaration order and byte/word typing variations did not resolve
  these differences. The nonmatching body was removed; a human can open a
  decomp.me scratch with `tools/decompme.py`. No new assembly stub is necessary:
  this incomplete TU continues to link from the original delink.

No new tests are required by this card; the original bytes and objdiff are the
acceptance oracle for the retained implementation.

Validation: match gate passed all 56 checked definitions; checksum reported all
artifacts byte-identical; anticheat passed; all nine unit tests passed.
