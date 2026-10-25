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

## Hard list

None for M1-T568.

## Not done in M1-T569
- `Unk0d297c_FreeSlot`
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
- `Unk0d297c_FreeSlot`: hand-matched
- `Unk0d297c_Unk_0d3004`: hand-matched
- `Unk0d297c_Unk_0d3138`: hand-matched
- `Unk0d297c_PushU16`: hand-matched
