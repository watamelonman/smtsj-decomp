# sdk_0204fce8 resource helpers

M2-T153 reconstructed eight ARM functions and M2-T154 adds the shared TBB1
child resolver `func_0204fd4c`; all nine match the delinked original at 100% in
objdiff. The TU remains linked from the delink pending human completion of the
split configuration. No new tests are required by the cards; the original object
provides the instruction-level acceptance reference.

An initial public-source search for NitroSDK resource/MTBL helpers did not
identify a matching implementation. Reconstruction uses the original ARM loads,
constants, branches and relocations. The neighboring `sdk_0204ff30.c` independently
checks the same MTBL signature and count/first offsets. The path's SDK label is
not sufficient evidence to assign SDK API names, so original neutral symbols remain.

All resource pointers and returned entries are borrowed. Headers and tables must
contain enough storage for their declared offsets/counts. Unsigned indices and
IDs follow the original unsigned comparisons.

| Function | Contract and original evidence | Match |
| --- | --- | --- |
| `func_0204fce8` | IDs 1..6 return 50-byte slots in `data_0215eedc`; other IDs return null. Evidence: unsigned bounds, subtract-one and multiply-accumulate by 50. | 100% |
| `func_0204fd18` | Null or non-TBB1 returns zero; otherwise reads header +8. Evidence: signature `0x31424254` and load at +8. | 100% |
| `func_0204fd4c` | Resolves the index'th child of a TBB1 header. Null or non-TBB1 returns null; the index must be below the +8 word, the +4 offset points at the header-relative word table, and the selected word is added to the header. Returns a borrowed child header. Evidence: signature literal at 0204fda8 (`0x31424254`), `ldr [r0,#8]` bound, `ldr [r0,#4]` table origin, indexed load and base addition. | 100% |
| `func_0204fdac` | Calls existing child resolver `func_0204fd4c`, then rejects null or non-TBL1 children. Evidence: call relocation and `0x314c4254`. | 100% |
| `func_0204fde0` | Null or non-TBL1 returns null; otherwise returns header plus the byte offset at +4. Evidence: guarded load and base addition. | 100% |
| `func_0204fe18` | Null, non-TBL1 or zero count returns zero; otherwise divides the +8 value by +12 count. Evidence: loads into r0/r1 and call to unsigned divide helper `func_0201f3e8`. | 100% |
| `func_0204fe68` | Calls existing child resolver, then rejects null or non-MTBL children. Evidence: call relocation and `0x4c42544d`. | 100% |
| `func_0204fe9c` | Requires a valid header; subtracts first ID at +16, returning zero below first or when the result reaches count at +12. Zero is both a valid index and the fallback. Evidence: two unsigned boolean comparisons. | 100% |
| `func_0204fed8` | Null or non-MTBL returns null; otherwise converts ID using `0204fe9c`, reads offset from +20 plus four times index, and returns header+16+offset unless offset is zero. Evidence: indexed load, zero guard and +16 addition. | 100% |

## Remaining functions / hard list

None of the nine functions in this TU remain hard. The TBB1 child resolver
`func_0204fd4c` is now defined here rather than borrowed from the delink.
