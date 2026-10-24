# game/unit_0206e4d8 — M1-T386

All eight requested functions match at 100% in objdiff. The C bodies already
matched in the starting worktree; this card verifies them and records their
contracts. Evidence below comes from the delinked ARM `.text` and relocations.
Integer address returns preserve the existing TU interface on the 32-bit target.
Table indices must identify valid slots; these helpers do not check bounds.
No domain meaning beyond these accesses is established, so neutral names remain.

| Function | Size | Contract and evidence |
| --- | ---: | --- |
| `Unk06e4d8_Get_data_02170cc8` | 16 | Returns the nullable borrowed work address: literal load of `data_02170cc8`, then word load. |
| `Unk06e4d8_Unk_06e4d8` | 24 | Returns slot address +0xbc; MLA uses index, stride 0x148 and `data_0216bac8`, then ADD 0xbc. |
| `Unk06e4d8_Unk_06e4f0` | 24 | Same table contract, ADD 0xdc. |
| `Unk06e4d8_Unk_06e508` | 24 | Same table contract, ADD 0xfc. |
| `Unk06e4d8_Unk_06e520` | 24 | Same table contract, ADD 0x11c. |
| `Unk06e4d8_Reset` | 28 | Requires non-null writable work. Clears word +0x08, byte +0x6c, word +0x68, then tail-calls `Unk06e4d8_Unk_06e814`. |
| `Unk06e4d8_Unk_06e680` | 36 | Passes the global word to `func_02061424`, then stores zero in the global. The original has no null check. Callee semantics remain unnamed. |
| `Unk06e4d8_GetFlag6c` | 44 | Returns 0 for absent work; otherwise calls the accessor again, reads byte +0x6c and returns normalized 0/1. Both calls are retained to match the original. |

## Hard list for M1-T386

None. All requested functions are identical; no scratch is needed.

## Other cards (pre-existing status)
Notes left by other cards that touch this TU; kept for reference.

## M1-T388

| Function | Size | Contract and evidence |
| --- | ---: | --- |
| `func_0206e8b0` | 348 | Configures the borrowed singleton from a slot. Returns if 06ea0c rejects the slot or the singleton is absent. Copies the slot block at +0xbc (32 bytes), using the duration at +0xd8. If active, replaces the first four block bytes with the current 20.12 channel integer parts, clears +0x60/+0x5c/+0x64, and enters state 2. Otherwise resets the counter, enters state 1, and initializes four channels from the block bytes. Stores the slot byte at +0x6d, sets the end frame to counter + duration, calls 0207112c with block and field addresses, and sets +0x68 to 2 for packed target RGB 0xffffff00, otherwise 1. Evidence: original ARM loads/stores and calls; effect purpose remains unknown, so the name stays neutral. |

The work layout now types the fourth channel at +0x38 and the slot byte at
+0x6d. A strided duration view preserves the original byte-stride multiply.
The instruction comparison matches all 348 bytes (including relocations).
Objdiff reports 100% for the target and all defined functions in this TU.
The full build/checksum and anticheat gates pass, as do all nine unit tests.

### Hard list for M1-T388
None.

## M1-T387
All eight card functions match at 100% (objdiff report). The checksum gate is byte-identical.
The work struct gained typed fields +0x00/+0x04 (frame thresholds), +0x0c (0x20-byte block),
+0x40/+0x44 (steps). +0x2c/+0x30/+0x34 are now `s32`: func_0206e6e4 needs `asr #12`.
`data_02170cc8` is now declared as `Unk06e4d8Work *`; all existing users are still 100%.

| Function | Size | Contract and evidence |
| --- | ---: | --- |
| `Unk06e4d8_Unk_06e538` | 104 | Creates the singleton. `func_020611dc` gets callback `func_0206e5bc` and size 0x70; the block is zeroed with `func_02008848`, stored in `data_02170cc8`, and +0x6c is set to 0. |
| `func_0206e5bc` | 180 | Per-frame callback (registered by 06e538). Jump table on byte +0x6c (0..5). State 1 waits until the counter +0x08 reaches +0x00. State 2 calls 06e6a4 until +0x04, then goes to state 3 if +0x68 == 1, otherwise Reset. State 3 returns without counting. State 4 calls func_0206e6e4 until +0x04 + 13, then state 5 calls Reset. Every state except 3 increments +0x08. |
| `Unk06e4d8_Unk_06e6a4` | 64 | Passes the +0x0c block and the addresses of +0x60/+0x5c/+0x64/+0x2c/+0x3c/+0x4c to `func_02070440` (callee unnamed). |
| `func_0206e6e4` | 172 | For each of the three 20.12 values: takes its integer part as an s16, steps it by `(s16)(step >> 12)` with the clamp `func_0206d950(&v, step, 255)`, and stores it back as `v << 12`. |
| `func_0206e790` | 132 | If the singleton exists, sets each step to `func_0200219c(0xff000 - value, 0xd000)`, then sets state 4. Each access reloads the global, as in the ROM. |
| `Unk06e4d8_Unk_06e814` | 64 | Fills the +0x0c block with 0 (`func_020086a0(0, p, 0x20)`) and zeroes the value/step words. |
| `Unk06e4d8_Unk_06e854` | 92 | If the singleton exists and +0x6c != 0, packs the three integer parts into bytes 3/2/1; otherwise returns -1. |
| `Unk06e4d8_Unk_06ea0c` | 56 | Returns 0 if i is beyond the count at `data_0216bac4`; otherwise returns whether word +0xd8 of `Unk06dddc_Unk_06e058(i)` is > 0. |

Names stay neutral. The sibling TU unit_020939f0 has the same shape (fade toward 0xff), but
nothing here names the effect.

### Hard list for M1-T387
None.

### M1-T387 validation

Retained the inherited matching implementations and gave the table-record accessor
an explicit integer index prototype. Rebuilt with the match gate: all 16 defined
functions in this TU are 100%, including the eight requested here. Checksum and
anticheat gates pass; the existing nine unit tests pass. No new behavioral tests
are required by this matching card; objdiff checks the original instructions.
