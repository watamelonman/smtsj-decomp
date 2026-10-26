# game/unit_020edc78

All three functions match at 100% in objdiff. Names remain neutral because the
assembly establishes behavior but does not establish the sequence's game-level purpose.
The work area is caller-owned; its modeled fields follow the original ARM offsets.

- `func_020edc78` (800 bytes): updates the current cell, increments its wrapping
  16-bit counter and the work-area signed counter, then dispatches on the signed
  byte at `0x7481`. States 0 and 1 wait more than 40 and 10 updates. State 2 waits
  for completion, resets seven ScanVisor entries and several embedded areas.
  State 3 waits more than two updates and loads `data_02150dc4`, then starts the
  next operation. States 4–6 process 128 entries per update and poll completion;
  state 5 also advances after more than 300 updates. Each transition resets
  the work counter. State 7 sets fields `0x73d0` and `0x73cc` to 8 and 12; state 8
  waits. Other states return 1; states 0–8 return 0. Evidence: original switch,
  counter comparisons, field stores, and ScanVisor call targets.
- `Unk0edc78_Unk_0edf98` (116 bytes): initializes current-cell flags using byte
  `0x19` of record 5, clears its counter, passes work field `0x58` to the operation
  helper, initializes the embedded area at `0xa8` with field `0xa4`, and sets
  fields `0x748c` and `0x7490` to 1. Evidence: record lookup and original stores.
- `Unk0edc78_Unk_0ee00c` (16 bytes): forwards its work pointer to
  `func_020edc78` and always returns zero, discarding the sequence result.
  Evidence: original direct call and unconditional zero return.

## Hard list

None. No omitted functions or assembly replacements.
