# CRI unit 0207c82c

All nine reconstructed functions match at 100% in objdiff with mwccarm 2.0/sp1p5.
The record view is 0xb4 bytes, established by the clear in `func_0207c978`
and the allocation stride in `func_0207c868`. Padding has no inferred meaning.
Existing neutral symbols are retained: no evidence establishes CRI API names.
The forwarding helpers preserve the callee's r0; its semantic meaning is unknown.

A public-source search for Nintendo DS CRI code did not locate a matching
implementation. Reconstruction uses the delinked ARM instructions, not unrelated
SDK code. Evidence is in `build/asm/libs/CRI/cri_0207c82c.s` (generated).

| Function | Instruction evidence and contract | Match |
| --- | --- | --- |
| `func_0207c82c` | Writable record required. Clears words a0, 2c, 30, 34, 40, 44, a8, ac and byte 3; sets word 38 to 0x7fffffff and word 3c to -1. Preserves other fields. | 100% |
| `func_0207c868` | Scans signed byte 0 of four 0xb4-byte records at `data_02172dac`; returns null if occupied. Reads `sources[0]`, queries 020815b0/02081628/020816a0, halves the latter two with signed truncation, and creates a handle via 0207a1ac. Creation failure returns null. Registers callback 0207ccb0 with the record as context, stores value/count and copies count source pointers at offset 0c, resets state/counters, clears words 48/4c/58/5c, then marks byte 0 occupied. Caller supplies at least one readable source pointer and a count whose copied pointers fit the record. Neutral name retained because no public API identity is established. | 100% |
| `func_0207c978` | Null is accepted. Clears the handle at offset 4 before calling 0207a278 on its previous non-null value. Calls 0207ae14, clears the full 0xb4-byte record with 020119c0, then calls 0207ae20. Caller must supply a full writable record. | 100% |
| `func_0207c9b8` | LDRSB at offset 1 returns the signed state byte. Requires readable record. | 100% |
| `func_0207c9c0` | Stores argument at offset 8; tail-forwards handle at offset 4 and the argument to 02079ea0. Requires writable record and a handle valid for that callee. | 100% |
| `func_0207c9d4` | Stores argument at offset 38; tail-forwards handle and argument to 02079ec4. Same validity requirements as preceding helper. | 100% |
| `func_0207c9e8` | Loads offset-4 handle and tail-forwards to 02079f24. Requires readable record and valid handle. | 100% |
| `func_0207c9f8` | Calls 0207c82c, then writes byte 1 to offset 1. Requires writable record. | 100% |
| `func_0207ca10` | Calls 0207a96c on offset-4 handle, then writes zero to offset 1. Requires writable record and valid handle. | 100% |

No module boundary changed. The TU remains linked from the delink until a human
marks it complete. M2-T021 adds `func_0207c868`; the preceding eight entries
were reconstructed by M2-T020. A renewed public-source search for DS CRI/ADX
allocation code found no matching implementation. The standalone instruction and
relocation comparison and the full objdiff gate verify the allocation helper.

Hard list: none.
