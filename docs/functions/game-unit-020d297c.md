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

## Hard list
- `Unk0d297c_Unk_0d3250`: decompiler-derived
- `Unk0d297c_Unk_0d32ac`: decompiler-derived
- `Unk0d297c_Unk_0d31e8`: decompiler-derived
- `Unk0d297c_Unk_0d3290`: decompiler-derived
- `Unk0d297c_Unk_0d33ac`: decompiler-derived

## Not done in M1-T568
- `Unk0d297c_Call_020d297c`
- `Unk0d297c_Unk_0d2aec`
- `Unk0d297c_LoadMissionLog`
- `Unk0d297c_Unk_0d2f18`: decompiler-derived
- `Unk0d297c_Unk_0d2f3c`: decompiler-derived
- `Unk0d297c_Unk_0d2f98`: decompiler-derived
- `Unk0d297c_Unk_0d2b70`: decompiler-derived
- `Unk0d297c_Unk_0d2c1c`: decompiler-derived
- `Unk0d297c_Unk_0d2e88`: decompiler-derived
- `Unk0d297c_Unk_0d32c0`: decompiler-derived

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
- `Unk0d297c_LoadMissionLog`: decompiler-derived (plain cleanup)
- `Unk0d297c_Unk_0d3308`: decompiler-derived (struct+fix cleanup)
- `Unk0d297c_Unk_0d3358`: decompiler-derived (struct+fix cleanup)
- `Unk0d297c_Unk_0d2aa4`: hand-matched
- `Unk0d297c_Unk_0d2aec`: hand-matched
- `Unk0d297c_FreeSlot`: hand-matched
- `Unk0d297c_Call_020d297c`: hand-matched
- `Unk0d297c_Unk_0d3004`: hand-matched
- `Unk0d297c_Unk_0d3138`: hand-matched
- `Unk0d297c_PushU16`: hand-matched
