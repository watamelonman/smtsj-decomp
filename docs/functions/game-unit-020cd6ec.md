# game/unit_020cd6ec — M1-T657 / M1-T658

All fourteen implemented functions match at 100% in objdiff. Parameters use a borrowed state
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

| `func_020ce33c` | Recreates the counted items from IDs at +0x2a + 26*i. ID 604 selects the shifted index/count pair. Passes +0xe8 to the handle, restores the low 16 bits of +0xa4, and sets +0xf4. |
| `func_020cdd14` | Three-step substate sequence: wait for slot 19, configure helper modes, wait for kind 0, restore the +0xa4 selection, and enter state 4. |
| `func_020cdbe0` | Five-step substate sequence: configure handle/helper modes, poll readiness, request slot 19, wait for its completion, restore selection +0xc0 plus 10, and enter state 5. |
| `func_020ce3f0` | Borrows a message with a word kind and an inline 68-byte payload. Kind 1 calls 020bc504; kind 3 acts only in state 6. Payload bit 3 supplies the index; absent data defaults to zero. Index 100 deactivates all counted items and exits through state 2; other indices select a record and enter state 8. Indices follow the sender's original validity contract. |
| `func_020cde1c` | Handles input only in states 4 and 5. Uses the controls at +0x94/+0xb0, tests masks 64/128/1024/2048/1/2, dispatches selections and sends slot-19 payloads. Tests the handle's +0xc8 slot table before committing the selection at +4. Payload initialization clears two flag bytes and sixteen words while preserving alignment padding. |
| `func_020cd778` | Advances states 0..13 using handle readiness and record-helper completion. States 3/8 pass the 114-byte record block at +0x20 by value to 020deaa0, followed by the selected index. State 6 updates item activity; states 9/10 invoke the substate handlers. After dispatch, a non-null handle receives +0xa4 and either +0xc0 or +0xdc (state 13). |

The added layout views are private to this translation unit. Record stride (26),
payload size (68), and by-value block alignment (two bytes) come from the original
loads, stores, and argument-copy loops. No higher-level feature names are inferred.
The zero-index record call assigns +0xec in its argument expression to preserve
the original ordering relative to the outgoing argument copy.

Validation uses the original ARM instructions and objdiff relocation-aware
comparison; no new behavioral tests are required by the card. The match gate,
anticheat gate, nine existing unit tests, and full-image checksum all pass.

## Hard list

None.
