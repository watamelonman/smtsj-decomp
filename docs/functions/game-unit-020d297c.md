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

## Pending later cards
- `Unk0d297c_Unk_0d3330`: decompiler-derived
- `Unk0d297c_Unk_0d3200`: decompiler-derived

## Not done in M1-T570
- `Unk0d297c_Unk_0d3308`
- `Unk0d297c_PushU16`
- `Unk0d297c_Unk_0d3004`
- `Unk0d297c_Unk_0d2aa4`
- `func_020d2f60`
- `func_020d2b10`

## Not done in M1-T572
- `func_020d33cc`
- `func_020d2c44`
- `Unk0d297c_Unk_0d2fbc`: decompiler-derived
- `Unk0d297c_Unk_0d3034`: decompiler-derived

## Not done in M1-T571
- `Unk0d297c_Unk_0d3358`
- `func_020d2eb0`
- `func_020d2b98`
- `func_020d30b0`
- `func_020d314c`
- `func_020d297c`
- `Unk0d297c_Unk_0d3308`: decompiler-derived (struct+fix cleanup)
- `Unk0d297c_Unk_0d3358`: decompiler-derived (struct+fix cleanup)
- `Unk0d297c_Unk_0d2aa4`: hand-matched
- `Unk0d297c_Unk_0d3004`: hand-matched
- `Unk0d297c_Unk_0d3138`: hand-matched
- `Unk0d297c_PushU16`: hand-matched
