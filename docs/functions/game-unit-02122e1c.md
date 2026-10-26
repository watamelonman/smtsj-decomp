# src/game/unit_02122e1c.c

The eight M1-T747 functions match the original ARM instructions at 100% objdiff.
Offsets below are byte offsets within a borrowed work object. Indexed accesses
require caller-validated indices into the backing storage; these routines do not
check bounds. Field and callee semantics remain unknown, so neutral names stay.

- `Unk122e1c_SetUnkFields64_b0` (0x02122f7c, 12 B): writes its second and third arguments to +0x64 and +0xb0. Evidence: two `str` instructions with those offsets. The descriptive name describes only these observed stores.
- `Unk122e1c_Unk_122f88` (12 B): writes a word to +0x78 + index*4. Evidence: shifted-index `add`, then `str` at +0x78.
- `Unk122e1c_Unk_122f94` (12 B): reads a word from +0x78 + index*4. Evidence: shifted-index `add`, then `ldr` at +0x78.
- `Unk122e1c_Unk_122fa0` (12 B): writes a word to +0xc8 + index*4. Evidence: shifted-index `add`, then `str` at +0xc8.
- `Unk122e1c_Unk_12331c` (16 B): forwards the readable work word at +0x14 to `Unk0cb32c_Unk_0cb57c`, discarding its return value. Evidence: `ldr r0, [r0, #0x14]` and indirect tail call with an absolute callee relocation.
- `Unk122e1c_Unk_122f54` (20 B): returns 1 iff the byte at +0x60 is zero, otherwise 0. Evidence: `ldrb`, comparison with zero, conditional 1/0 moves.
- `Unk122e1c_Unk_122f68` (20 B): returns 1 iff the byte at +0x60 is eight, otherwise 0. Evidence: `ldrb`, comparison with eight, conditional 1/0 moves.
- `Unk122e1c_Unk_12332c` (20 B): forwards the readable work word at +0x14 and constant 1 to `func_0205caa8`, discarding its return value. Evidence: field load, `mov r1, #1`, and indirect tail call with an absolute callee relocation.

## M1-T748

All eight functions below match at 100% objdiff. Work pointers borrow writable
storage; indexed accesses require sufficient backing storage unless stated otherwise.
Names remain neutral where the instructions do not establish a higher-level purpose.

- `func_0212351c` (24 B): writes 0 for a zero value, otherwise 1, to +0x78 + index*4. Evidence: conditional moves and indexed store at 0212351c. Separate branch stores preserve the original compiler scheduling.
- `Unk122e1c_ClearSlots` (32 B): clears six slot words at +0xf8. Evidence: six-iteration indexed store loop at 02122fd0.
- `Unk122e1c_Unk_1241cc` (32 B): forwards the indexed word at +0x10 and the corresponding word from data_0213cd7c to func_0205caa8. Evidence: indexed loads and tail call at 021241cc. Both indices must be valid.
- `Unk122e1c_SetSlot` (36 B): writes one of six slots at +0xf8; null pointers and indices outside [0, 6) are ignored. Evidence: pointer and signed range checks at 02122fac.
- `Unk122e1c_Unk_123024` (36 B): calls Unk0fedd4_SetState1, clears +0x114/+0x61, and writes 1 to +0x60. Evidence: calls and stores at 02123024.
- `Unk122e1c_Unk_123048` (36 B): same observed stores with 2 at +0x60. Evidence: 02123048.
- `Unk122e1c_Unk_1232f8` (36 B): same observed stores with 6 at +0x60. Evidence: 021232f8.
- `Unk122e1c_Unk_1232c8` (48 B): calls Unk0fedd4_SetState0 and Unk0cb32c_Unk_0cb57c with +0x14, clears +0x114/+0x60, and stores -92 at +0xb8/+0x6c. Evidence: 021232c8 calls and stores.

No M1-T747 or M1-T748 functions remain on the hard list.


## M1-T749

All eight functions match the original ARM instructions at 100% objdiff. Names
remain neutral: provider calls and field accesses establish the operations below,
but not their higher-level purpose. Layout views borrow existing storage. The
counted arrays require valid counts and the resource table requires corresponding
entries; no new ownership boundary is introduced.

- `Unk122e1c_Unk_122ff0` (52 B): calls the state-zero provider and the +0x10 provider, sets +0x114 to +0x11c minus one, clears +0x61, and sets +0x60 to 3. Evidence: calls and stores at 02122ff0.
- `Unk122e1c_Unk_123294` (52 B): equivalent transition using +0x14 and state 7. Evidence: calls and stores at 02123294.
- `Unk122e1c_Unk_123534` (56 B): forwards two handles at +0xe0 with the low byte of +4 and identifiers 110/111. Evidence: indexed loads and byte masking at 02123534.
- `Unk122e1c_Unk_12306c` (72 B): sets the same countdown, clears +0x61, enters state 5, and clears six slots through the checked setter. Evidence: stores and six-iteration call loop at 0212306c.
- `func_021230b4` (120 B): writes -92 to +0xb8, clears +0xc0/+0xc4, forwards the counted handles at +0x34, resets the +0x10 provider, and clears six slots. Evidence: calls, loop bounds at +0xb4, and stores at 021230b4.
- `func_02123340` (160 B): calls the state-one provider, initializes +0x6c/+0x70/+0x74, initializes each counted +0x18 resource with table words and its final provider index, resets the +0x10 provider, and enters state 8. Evidence: calls, table relocation, and stores at 02123340. +0x70 receives count times 15; +0x74 receives 0x3f800000.
- `func_02122e1c` (312 B): calls release providers for six +0xe0 handles and the counted +0x94 handles, conditionally clears them, releases the +0x5c resource and seventeen +0x10 resources, then releases +0x58/+0x54/+0x0c/+0x08 and the work allocation. Returns 1, also for null. Evidence: provider calls and conditional clears at 02122e1c. The work pointer is consumed.
- `func_021233e0` (316 B): initializes both counted resource groups using table entries at indices 2 and 9, sets their final provider indices, initializes the observed timing words, forwards the two leading handles, and clears +0x114/+0x61/+0x60. Evidence: table relocation, calls, and stores at 021233e0. Timing words receive count times 15 and 0x3f800000, without assuming a semantic type for the latter.

Hard list: none for M1-T749. Validation uses instruction comparison and the
project match/checksum gates; no behavioral test harness is required by this card.

## M1-T750

All four functions match at 100% objdiff, and all 24 earlier functions in this TU
remain at 100%. The existing source file is extended rather than recreated.
Original symbol names are retained because the instructions establish behavior
without establishing higher-level names. No assembly replacements are needed.

- `func_0212312c` (360 B): stores its third argument at +0x110, configures the counted +0xe0 handles with provider identifiers selected by mode and `func_020cb3dc`, initializes +0xc8 flags for the default mode, writes mode times 15 at +0xbc, notifies the +0x10 provider, and enters state 4. Evidence: switch branches, provider calls, and stores at 0212312c. Counts must fit six handles and flags; unsupported provider results return after the initial +0x110 store.
- `func_0212356c` (328 B): advances a caller-owned phase byte through setup, waiting for state 8, polling the input provider/buttons, and waiting for state 8 again after cancellation. Returns -1 while pending, 1 on an enabled selection, and 0 after cancellation completes. Evidence: four-way switch, calls, +0xc8 flag lookup and final byte store at 0212356c. The input view exposes only the index word at +0x10; that index must fit the flag array.
- `func_021236b4` (1300 B): increments the leading signed counter with a reset above 65535, advances states 1–7 and their phase/countdown fields, and updates seventeen +0x10 handles and the +0x5c handle on every call. Evidence: switch table, signed division/remainder calls, post-increment/decrement comparisons, float addition, and final update loop at 021236b4. Division occurs before multiplication as in the original; +0x118/+0x11c must be nonzero whenever used as divisors. +0x74/+0xc4 are now typed as floats, supported by float addition and their draw-provider use; earlier 0x3f800000 stores are expressed as 1.0f with identical instructions.
- `func_02123bc8` (1540 B): returns immediately for state zero; otherwise submits the two counted groups, clip entries, leading handles, labels, and optional slot decorations in the original order, then restores provider state. Evidence: draw-provider calls, entry-halfword stores at +0xe, group bounds at +0x68/+0xb4 and flags at +0x78/+0xc8/+0xf8 at 02123bc8. Returned entry 15 is borrowed and writable. The additional label submission occurs after either flag branch; the nonzero branch resets provider state and the zero branch selects color 0x808080ff.

The expanded private work view exposes previously padded flags and timing words;
provider ownership and module boundaries remain unchanged. Separate loop variables
and switch forms preserve original compiler allocation and count reloads.

Hard list: none for M1-T750.

Validation: `python3 tools/match_gate.py` reports all 28 C functions at 100%;
`python3 tools/checksum.py` reports all artifacts byte-identical;
`python3 tools/anticheat.py` passes; the unittest suite passes all nine tests.
No new behavioral tests are required by the card; original-instruction comparison
is the acceptance oracle.
