# libs/NitroSDK/sdk_020587fc

The task's SDK path is retained. Public-source searches for NitroSDK/NNS
resource and animation pool code did not identify a matching implementation.
The implementation is reconstructed from ARM instructions; names remain the
original neutral linker symbols because a specific SDK identity is unproven.
No module boundary or linker configuration changes are needed.

The original object is the test oracle (all six functions initially absent from
C). No new behavioral tests are required by this card. Matching checks cover
instruction selection, field offsets, call targets, branches and constants.

| Function | Instruction evidence and caller contract |
| --- | --- |
| `func_020587fc` | Computes a 48-byte global record at `data_02168cc8`, calls `func_02029b80`, then calls `func_02029d90` on offset 40. Caller supplies a valid index; global extent is unknown. |
| `func_02058824` | Uses the same stride and offset with `func_02029bc0` and `func_02029dac`. Caller supplies a valid index. |
| `func_02058854` | Clears 3072 bytes, explicitly zeros pointer/flag fields in 128 records of 24 bytes, then clears pointers at offsets 3072, 3076 and 3080. Caller supplies 3084 writable bytes. |
| `func_0205889c` | Loads through `func_02051610` and stores into the slot selected by 0, 1 or 2. Other selectors do nothing. Source ownership follows that external helper. |
| `func_020588ec` | Calls `func_020516d0` only for a non-null selected slot. Invalid selectors do nothing; stored pointers are not cleared. |
| `func_02058944` | Selects a resource with `func_02025b64`, populates a 24-byte record, obtains allocation size from `func_0202162c`, allocates through `func_02052fe0`, then invokes `func_0202168c` and `func_020218a0`. Source records have stride 92 with a pointer at offset 84. Pool/source indices must be valid and slot must be 0..2; the original has no defined resource for other slots. |

## Hard list

None.

Validation: objdiff reports 100% for each of the six functions. The teardown
wrapper's integer address calculation is explained in DEC-009. Full build and
checksum, anticheat, and the nine repository unit tests pass.
