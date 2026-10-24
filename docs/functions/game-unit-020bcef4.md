# src/game/unit_020bcef4.c

## M1-T434: eight matched functions

All eight entries below match at 100% with the configured mwccarm compiler.
Evidence is the original ARM code in the delinked object; no higher-level
meaning is inferred for the neutral symbols. All pointer views are borrowed.

| Function | Size | Evidence and contract |
| --- | ---: | --- |
| `Unk0bcef4_Unk_0bd2fc` | 16 B | 020bd2fc..020bd308 calls `func_020bd30c` with the original two arguments and a zero third argument. Address arguments must satisfy the callee. |
| `Unk0bcef4_Unk_0bd388` | 16 B | 020bd388..020bd394 loads the readable word at argument 1 and forwards it as the count to `Unk0bcef4_Unk_0bd584`. |
| `Unk0bcef4_Unk_0bd470` | 16 B | 020bd470..020bd47c loads the readable first word and forwards it to `Unk0bd5f0_Unk_0bd614`. |
| `Unk0bcef4_Unk_0bd5c4` | 16 B | 020bd5c4..020bd5d0 forwards the record address to `func_020bd49c` with mode 2. |
| `Unk0bcef4_Unk_0bd3e0` | 28 B | 020bd3e0..020bd3f8 increments the writable signed word at +4 and caps values above 1 at 1. The `gt` condition establishes signed comparison. |
| `func_020bd3fc` | 28 B | 020bd3fc..020bd414 increments the writable signed word at +4, then takes its signed remainder modulo 2. The sign correction before the shifts establishes signed remainder, including negative inputs. |
| `Unk0bcef4_Unk_0bd480` | 28 B | 020bd480..020bd498 writes the supplied state into word 0; for states 1, 4, and 6 it also writes 1 into word 1, otherwise preserving word 1. Requires two writable words. |
| `Unk0bcef4_IsState015` | 28 B | 020bd5d4..020bd5ec reads the first word and returns exactly 1 for states 1, 0, or 5, otherwise 0. These comparisons support the existing descriptive name. |

The modulo routine needs a separate increment and compound remainder assignment:
a single `(field + 1) % 2` expression computes the same result but allocates the
sum to r1 rather than the original r3. The two statements reproduce the original
instructions without explicit register control.

Validation: `python3 tools/match_gate.py`, `python3 tools/checksum.py`,
`python3 tools/anticheat.py`, and the full Python unittest discovery suite.

## M1-T435: eight matched functions

All eight functions below match at 100% in objdiff. The evidence is their original
ARM instructions; the names remain neutral because no higher-level purpose is proven.
All storage is borrowed. Record indices must be within the caller's allocation.

| Function | Size | Evidence and contract |
| --- | ---: | --- |
| `Unk0bcef4_Unk_0bcef4` | 32 B | Stores arguments into words 0, 1 and 6; clears words 2 through 5. Requires seven writable words. |
| `Unk0bcef4_Unk_0bd368` | 32 B | Subtracts selection start (+8) from selected (+16), multiplies by 12 and tail-forwards the record to `Unk0bd5f0_Unk_0bd5f0`. |
| `func_020bd54c` | 56 B | Disabled writes counter 1. Enabled writes counter 0 except mode 2, which writes counter and state 2. Requires a writable 12-byte record. |
| `func_020bd034` | 60 B | Signed count/span comparison leaves short lists unchanged; otherwise adds selected minus start to start and caps it at count minus span. Always returns 1. |
| `Unk0bcef4_Unk_0bd584` | 64 B | Unsigned count controls a 12-byte-stride loop calling `func_020bd398`; returns the last nonzero-result index or unsigned -1. |
| `func_020bd398` | 72 B | Mode at +8 selects the cap-at-one, signed modulo-two, or two-stage helper. Only the last helper's return is forwarded; other modes return 0. |
| `func_020bd418` | 88 B | State 1 increments counter, caps at 1 and changes state to 2. Other states increment counter, cap at 2 and return completion 1 when that cap is reached; otherwise returns 0. |
| `func_020bd30c` | 92 B | Selects a 12-byte record by selected minus start; a zero third argument requires `Unk0bcef4_IsState015` success. On success applies mode 2 through `Unk0bcef4_Unk_0bd5c4` and returns 1, otherwise 0. |

The private record view adds state and mode words to the existing counter view;
the selection view describes the seven signed words used by the offset arithmetic.
No module boundary changes are needed. The dispatcher is defined after its callees
to avoid the documented objdiff same-unit call scoring artifact (standalone instruction
comparison was already identical before reordering).

Validation: match gate (all defined functions at 100%), checksum, anticheat and
Python unittest discovery. No new tests are required by this matching card: original
instruction comparison checks the implementations directly.

### Hard list
None for M1-T435.

## M1-T436: seven matched functions

Original ARM instruction comparison establishes the behavior below. Names remain
neutral; records and selection views are borrowed, with caller-provided capacity.

| Function | Size | Evidence and contract |
| --- | ---: | --- |
| `Unk0bcef4_Unk_0bd29c` | 96 B | 020bd29c loops over the signed count at argument 1, advancing records by 12 bytes; calls the state helper with (1,0) and counter helper with 0. Returns 1. Count pointer must remain readable. |
| `func_020bcfc4` | 112 B | 020bcfc4 clamps the index to 0..count-1, saves the previous selected index, and adjusts start if selection lies outside the visible span. Requires seven writable words. |
| `func_020bd110` | 152 B | 020bd110 subtracts previous start from start and copies counter words in overlap-safe direction; out-of-span source positions use the disabled counter helper. Records cover the visible span. |
| `func_020bd070` | 160 B | 020bd070 maps input values 0..3 to states (4,1,6,7) when enabled and (3,0,5,7) otherwise. Other values preserve state. Writes mode 1 or 0; enabled calls the counter helper. |
| `func_020bcf14` | 176 B | 020bcf14 replaces count, decrements selected/start within loops bounded by old count, then caps selected to the span. Requires writable selection storage. |
| `func_020bd49c` | 176 B | 020bd49c writes mode. Mode 0 calls 0205ea18 with (21,31,2,counter,1), narrows to a byte and stores 1 minus signed quotient by 31. Mode 1 clears counter and maps state 2 to 1. Mode 2 sets state 1 through 020bd480 then clears counter. |
| `func_020bd1a8` | 244 B | 020bd1a8 initializes span records, shifts counters through 020bd110, then enables the selected relative record or resets all counters. Optional values points to span readable signed words. Returns 1. |

The mode-zero quotient uses a separate compound division assignment to reproduce
the original register allocation, as with the earlier modulo helper. No new tests
are required by this card; instruction comparison provides the behavior check.

### Hard list
None for M1-T436.
