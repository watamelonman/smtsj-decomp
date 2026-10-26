# CRI unit 0207c82c

All eight requested functions match at 100% in objdiff with mwccarm 2.0/sp1p5.
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
| `func_0207c978` | Null is accepted. Clears the handle at offset 4 before calling 0207a278 on its previous non-null value. Calls 0207ae14, clears the full 0xb4-byte record with 020119c0, then calls 0207ae20. Caller must supply a full writable record. | 100% |
| `func_0207c9b8` | LDRSB at offset 1 returns the signed state byte. Requires readable record. | 100% |
| `func_0207c9c0` | Stores argument at offset 8; tail-forwards handle at offset 4 and the argument to 02079ea0. Requires writable record and a handle valid for that callee. | 100% |
| `func_0207c9d4` | Stores argument at offset 38; tail-forwards handle and argument to 02079ec4. Same validity requirements as preceding helper. | 100% |
| `func_0207c9e8` | Loads offset-4 handle and tail-forwards to 02079f24. Requires readable record and valid handle. | 100% |
| `func_0207c9f8` | Calls 0207c82c, then writes byte 1 to offset 1. Requires writable record. | 100% |
| `func_0207ca10` | Calls 0207a96c on offset-4 handle, then writes zero to offset 1. Requires writable record and valid handle. | 100% |

No module boundary changed. The TU remains linked from the delink until a human
marks it complete. `func_0207c868` is outside this card and remains delinked.

Hard list: none of the eight requested functions.
