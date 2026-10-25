# src/game/unit_0209d42c.c

## M1-T706 — verified matching functions

All eight functions below report 100% in objdiff against the delinked original.
The implementations already existed in this worktree; this task verifies them and
adds explicit helper parameter types and behavior contracts. Evidence below is
from the original ARM instructions and relocations in
`build/delinks/src/game/unit_0209d42c.o`.

| Function | Size | Evidence and contract |
| --- | ---: | --- |
| `Unk09d42c_Unk_09d600` | 12 | Compares the signed input with 0xff and conditionally replaces it with zero; other inputs pass through. Neutral name retained. |
| `Unk09d42c_Init_data_02176278` | 32 | Passes the singleton address, zero, and 0x884 bytes to `func_02008848`. This storage clear supports the Init name. |
| `Unk09d42c_Unk_09d4e0` | 32 | Loads singleton words at +0x800/+0x804 and returns their equality as zero or one. Neutral name retained. |
| `Unk09d42c_Unk_09d4bc` | 36 | Clears singleton +0x808, then returns signed +0x800 > +0x804. Neutral name retained. |
| `Unk09d42c_Unk_09e080` | 48 | Reads state +0x73ec, looks up an eight-byte record through `Unk1124f0_Unk_11259c`, and invokes its +4 callback when present; otherwise returns one. State and selected record must exist. Neutral name retained. |
| `Unk09d42c_Unk_09e274` | 48 | Calls `GetGameState`; returns one for null or a signed -1 at +0x73e8, zero otherwise. Neutral name retained. |
| `Unk09d42c_Unk_09df70` | 64 | Calls `func_02052da0` with the state, loads signed bytes at +0x7482/+0x7483 for `Unk02f2a8_GetCell38e8`, and increments the returned cell's +2 halfword modulo 65536. Returns whether `Unk09a268_Unk_09a844` equals one. State and selected cell must exist. Neutral name retained. |
| `Unk09d42c_GetTable0Entry` | 72 | Calls resource lookup with (9, 0), obtains base and count, and returns base for negative/out-of-range indices or base + index * 2 otherwise. The lookup arguments and stride support the table-entry name. Returned storage is borrowed. |

No new behavioral tests: this card sets `tests_required = false`; original-object
comparison is the acceptance test. No hard functions remain for M1-T706.

## M1-T707 — verified matching functions

All eight functions report 100% against the original delinked object. Seven
implementations were already present; this card adds `func_0209e020`, types the
flag predicate parameter, and documents the contracts. Evidence is the original
ARM instructions and relocations in `build/delinks/src/game/unit_0209d42c.o`.

| Function | Size | Evidence and contract |
| --- | ---: | --- |
| `Unk09d42c_Unk_09e2f4` | 72 | Null state returns immediately. Resolves the input through work-area +0x358 and `func_0203611c`, writes root +0x18, sets root +0x14 to 4 and state +0x73e8 to 1. Present state requires valid root/work storage. Neutral name retained. |
| `Unk09d42c_GetTable1Entry` | 76 | Resource arguments (9, 1) and 106-byte stride support the name. Negative/out-of-range indices return the borrowed table base. |
| `Unk09d42c_GetTable2Entry` | 76 | Resource arguments (9, 2) and 24-byte stride support the name. Negative/out-of-range indices return the borrowed table base. |
| `Unk09d42c_GetTable3Entry` | 76 | Resource arguments (9, 3) and 52-byte stride support the name. Negative/out-of-range indices return the borrowed table base. |
| `Unk09d42c_MapId` | 80 | Explicit comparisons map zero to one and, for nonzero second argument, 62/63/64 to 65/66/67. Other inputs return their low byte. These ID substitutions support the name. |
| `Unk09d42c_Unk_09e2a4` | 80 | Null state returns immediately. Resolves the input through work-area +0x358 and `func_0203611c`, writes root +0x18, sets root +0x14 to 2, clears root +0xc and state +0x73e8. Present state requires valid root/work storage. Neutral name retained. |
| `func_0209e020` | 96 | Dispatches state word +0x73f0. At zero, predicate `Unk0a23f4_Unk_0a246c` returning 1 invokes `ScanVisor_Unk_0a2b18` then increments that word. At one, returns whether `Unk0a23f4_Unk_0a2448` is zero; otherwise returns zero. State must exist; neutral name retained. |
| `Unk09d42c_Unk_09d73c` | 108 | Scans group 9/table 4 six-byte records: flag/key/value halfwords. Returns the first matching key's value when the flag predicate succeeds, otherwise the input ID. Storage is borrowed. Neutral name retained. |

No new behavioral tests (`tests_required = false`); original-object comparison
checks every instruction and relocation. No hard functions remain for M1-T707.

## M1-T708 — verified matching functions

All eight additions report 100% objdiff, and all 16 earlier functions in this
unit retain 100%. Evidence is the original ARM instructions and relocations.
Original symbol names are retained because the higher-level purpose is unknown.
The singleton now has a typed declaration so stores followed by reloads preserve
the original alias behavior across provider calls. Record/work layouts are
private borrowed views; no ownership crosses the module boundary.

| Function | Size | Evidence and contract |
| --- | ---: | --- |
| `func_0209e33c` | 108 | Null global state exits. Forwards four words to `func_02034b7c` with trailing options 3/1/0/0, then sets state +0x73e8 to 2. |
| `func_0209d44c` | 112 | Compares existing 32-byte names with the input; an equal name exits. Formats a new slot with `data_0214c9cc`, then increments +0x800 count. Caller ensures space and a valid string; the original has no capacity check. |
| `func_0209dfb0` | 112 | Dispatches +0x73f0. Phase zero waits for predicate result 1, writes +0x73cc = 5 and root +4 = 0, then increments phase. Phase one returns whether +0x73cc is 2. Other phases return zero. State/root must exist. |
| `func_0209e3a8` | 112 | Null global state exits. Writes +0x73cc = 7 and root +4 = 0; brackets `func_0209db70` with group-9 provider calls. Passes state +0x7330, input word, work-area +0x35c halfword, and state +0x7494 word. Finishes with +0x73e8 = 3. |
| `func_0209d964` | 212 | Copies six halfwords to words, copies eight text bytes unless the leading signed byte is ASCII zero, and always terminates work text at +0x3c. Maps ID/value bytes, sets flag 0x4000, and propagates source bits 0/1/2 to destination masks 1/2/0x60. Both records must exist. |
| `func_0209da38` | 164 | Clears 84 bytes and six words, sets two scales to 4096, substitutes ID 7 when flag 0x709 fails, resolves/maps a local 24-byte record, applies it, sets flag 0x10, and saves the provider result at +0x24. Work is caller-owned. |
| `func_0209dadc` | 148 | Clears 84-byte work and initializes scales, copies a table-two record, overrides bytes +2/+3 with 55/16, stores the input's low halfword at +0x18, applies the record with mapping off, sets flag 0x10, and saves the provider result. |
| `func_0209d500` | 256 | Singleton +0x808 dispatches request phases. Zero formats a 128-byte path for the current name or marks exhaustion with phase 3, then falls through to polling. One polls with -1 and advances to phase 2 on zero. Two retrieves the buffer, resolves the current name, consumes/frees it, clears phase, and increments cursor +0x804. |

Validation: anticheat, nine repository unit tests, match gate, and full-image
checksum pass. No new behavioral tests (`tests_required = false`); comparison
against the original object checks instructions and relocations. No hard
functions remain for M1-T708.

## M1-T709 — verified matching functions

All four functions report 100% objdiff, and all 24 earlier functions retain
100%. Evidence is the original ARM instructions and relocations in
`build/delinks/src/game/unit_0209d42c.o`. Original neutral symbol names are
retained because the higher-level purposes are not established. Record and work
views remain private; providers retain ownership of resource and cell storage.

| Function | Size | Evidence and contract |
| --- | ---: | --- |
| `func_0209de58` | 280 | Loads signed coordinates at state +0x7482/+0x7483, looks up map table 11 using entry byte +1, and increments cell halfword +2. Predicate success updates cell flags, cycles byte +1 modulo eight, clears the halfword, and writes the element's low eight-bit field and state phase byte through `Unk0e651c_Set2Bits`. State, selected cell, map element and provider record 23 must exist. Returns one only on success. |
| `func_0209d7f4` | 368 | Uses table-one bytes +2/+3/+4 as category weights, then selects an ID from four-byte ID/weight pairs at +6/+66/+86 with counts 15/5/5. Copies the selected 24-byte table-two record and fills zero ID/value bytes from table one or table zero. Returns the selected halfword ID. Borrowed tables must exist and supply valid nonzero weight totals for the random helper's inclusive range. |
| `func_0209e0b0` | 452 | Dispatches signed mode -1 through 22 at state +0x73e8. Mode -1 returns immediately; other modes poll root/state fields or the observed helper calls, wait, or complete immediately. Completion result exactly one sets mode/callback words to -1, clears phase +0x73f0, and clears 28 bytes at +0x7478. State/root and mode-specific subobjects must exist. |
| `func_0209db70` | 744 | Clears 84 bytes, initializes scales to 4096, and fills work from a 52-byte table-three record. Zero source ID/value bytes use table-zero defaults; six halfwords become words, fixed eight-/sixteen-byte strings use leading ASCII-zero suppression, and individual source flag bits map to work flags. Copies four extra halfwords and marks their presence. A nonzero source scale invokes `func_0200219c` with scale shifted by 12 and denominator 409600. Caller owns valid 84-byte work; tables are borrowed. |

Matching refinements: four-byte typed weight records preserve the original
indexed halfword loads; explicit staged weight sums preserve evaluation order.
The cell predicate takes its selected cell as an argument, as confirmed by its
implementation in `src/game/unit_0209a268.c`. The map element's low field is an
eight-bit unsigned bitfield, matching the original paired shifts. Table-three
and work flag bitfields preserve the observed source reloads and destination
read/modify/write sequences without assembly.

Validation: all 28 compiled functions in this unit match at 100%; anticheat,
repository unit tests, full build, and full-image checksum pass. No new behavioral
tests (`tests_required = false`); original-object comparison verifies every
instruction and relocation. No hard functions remain for M1-T709.
