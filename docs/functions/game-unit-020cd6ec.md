# game/unit_020cd6ec — M1-T657

All eight functions match at 100% in objdiff. Parameters use a borrowed state
view whose offsets agree with the initialization in `func_020cd594`.
The item-array extent is inferred from the adjacent handle at +0x1c;
iteration follows the original repeated record-count query, without caching it.
Names remain neutral because the higher-level purpose is not established.

| Function | Evidence and contract |
| --- | --- |
| `func_020cd6ec` | 020cd6ec releases each non-null counted item through 020ffebc, clears its slot, runs the global cleanup helpers, releases and clears the handle, and clears data_02176bcc. The initializer 020cd594 creates these items and installs that global. |
| `Unk0cd6ec_Unk_0cddd0` | 020cddd0 passes the +1 substate byte to 020cb5b4; results 1/2 invoke 020ce2d8/020ce33c and result 3 copies saved state +2 to state +0. Other results leave state unchanged. |
| `Unk0cd6ec_Unk_0ce280` | 020ce280 requests helper mode 5, sets saved state 4 and current state 12, and stores the supplied word at +8. |
| `Unk0cd6ec_Unk_0ce2ac` | 020ce2ac passes the +0x1c handle to 02123294, stores the supplied word at +0xf0, and sets saved/current state to 1/3. |
| `func_020ce2d8` | 020ce2d8 releases non-null counted items and clears their slots, passes the handle address to 020cb754, and clears +0xf4. |
| `func_020ce3e0` | The original loads +0xf4 and compares it with zero but returns on both paths. This is a void callback, consistent with its installation by 020cd594, rather than a value-returning predicate. |
| `Unk0cd6ec_Nop_0ce3ec` | The original consists solely of a return; the callback has no observable effect. |
| `func_020ce500` | 020ce500 normalizes the results of 021072c0 and 02107374, writes them to handle indices 1 and 2 using 02122fa0, and writes their logical union to index 0. |

Validation uses the original ARM instructions and objdiff relocation-aware
comparison; no new behavioral tests are required by the card.

## Hard list

None.
