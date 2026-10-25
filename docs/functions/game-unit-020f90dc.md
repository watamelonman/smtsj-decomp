# game/unit_020f90dc

M1-T751 implements the following ARM functions. Names remain neutral where the
observed field accesses do not establish a gameplay purpose. Local structures
model only the offsets used here; the entry descriptor stride is 24 bytes.

| Function | Observed behavior / evidence |
| --- | --- |
| `Unk0f90dc_Unk_0f90dc` | Compares a signed area halfword (30 for current area, 32 for an explicit area) against record byte 34. |
| `Unk0f90dc_Unk_0f9128` | Comparator subtracts byte 1 of two indirectly referenced entries. |
| `func_020f9140` | Registers six descriptors from `data_02150f38`, creates two shared handles and groups of five and ten handles. |
| `func_020f91fc` | Releases and clears both groups and shared handles, makes six cleanup calls, then releases fields 0x100 and 0x104. |
| `func_020f92bc` | Adds an ID to the halfword list at 0xf8 only if absent and below capacity at offset 8. Direct count accesses reproduce register allocation. |
| `func_020f9318` | Reads the selected entry's first byte, forwards it to two consumers and adds it to the unique list. Slot records have a 12-byte stride. |
| `Unk0f90dc_Nop_0f9ce4` | Empty callback, evidenced by the sole return instruction. |
| `Unk0f90dc_Unk_0fa4cc` | Calls group cleanup and frees/clears four owned allocations at 0x50, 0xf8, 0xec and 0xf4. |

## Hard list

None for M1-T751. Other functions in this translation unit remain delinked.
