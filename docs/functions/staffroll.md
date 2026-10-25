# src/StaffRoll.c

## M1-T640 — verified 100% objdiff

Names follow the existing symbol map. Neutral names remain where the purpose of
fields or constants is unknown. Evidence below is the original ARM code at each
listed address; record pointers are borrowed and must point to writable storage
for setters, or readable aligned storage for queries.

| Function | Original evidence and contract |
| --- | --- |
| `StaffRoll_Nop_117cf4` | 0x02117CF4: immediate return, no arguments or effects. The Nop name is supported by that instruction. |
| `StaffRoll_Nop_117cf8` | 0x02117CF8: immediate return, no arguments or effects; same evidence for Nop. |
| `StaffRoll_Unk_117cfc` | 0x02117CFC: reads the first halfword and returns it only if it is 0x8082; otherwise zero. Requires a non-null aligned halfword pointer. |
| `StaffRoll_Unk_117d18` | 0x02117D18: passes work +0x304 to `func_0204fed8`, returns zero for null, otherwise calls the preceding marker query. |
| `StaffRoll_Unk_117d38` | 0x02117D38: calls the marker query and maps 0x8082 to 0x739CD6FF, returning -1 otherwise. The meaning of the packed constant is unconfirmed. |
| `StaffRoll_Tick` | 0x02118174: increments unsigned +0xB4, compares against unsigned +0xC4, and on reaching the limit sets +0xAC to 1 and resets +0xB4. This counter advance supports the existing Tick name. |
| `StaffRoll_Unk_11825c` | 0x0211825C: clears record words +4, +8 and +12, preserving +0. Requires at least 16 writable bytes. |
| `func_02118270` | 0x02118270: scans 32 records of stride 16 starting at work +0xF8. Returns the first record whose +4 word is zero, or null when none qualify. Requires readable records through work +0x2F7. |

The search bound and stride come directly from the original loop. The typed slot
view describes only these observed words; its first word has no inferred purpose.
The existing dispatcher now explicitly forwards its work pointer to the typed
`StaffRoll_Tick` parameter, preserving its original call instructions.

Hard list for M1-T640: none. All eight functions match; no scratch is needed.



## M1-T641 — verified 100% objdiff

The existing symbol names are retained. These contracts follow the original ARM
loads, comparisons, calls, and stores at the named addresses. Work and slot
pointers are borrowed; modifying functions require writable storage.

| Function | Original evidence and contract |
| --- | --- |
| `StaffRoll_Update` | 0x021184D8 dispatches word +0: state 0 sets 1, state 1 advances the handlers, and state 2 calls `func_02061424`. This supports the existing Update name. |
| `StaffRoll_Unk_118490` | 0x02118490 increments +8, calls all three handlers, and sets +0 to 2 only when every return is nonzero. |
| `StaffRoll_Unk_1182a4` | 0x021182A4 scans 32 slots at +0xF8 with stride 16; clears active slots when their signed +8 plus 16 is less than work +0xE0. |
| `func_02118208` | 0x02118208 skips an initial halfword marker 0x8082, passes the remaining text to `func_02061f10`, then sets slot +4 to 1 and stores its two signed arguments at +8 and +12. Requires a readable aligned text stream and a writable 16-byte slot. |
| `StaffRoll_Unk_1181a0` | 0x021181A0 dispatches +0xAC states 0..4, tests unsigned +0xB8 against +8, and returns 1 only for state 4. |
| `func_02118424` | 0x02118424 dispatches +0xD0 states 0..2. Unsigned frame thresholds are +0xD4 and the wrapping sum +0xD4 + +0xD8; state 1 calls `func_021182f0`, and state 2 returns 1. |
| `func_02118518` | 0x02118518 does nothing for zero +0xCC; otherwise issues the observed drawing calls with dimensions 256 by 192, uses the low byte of +0xCC, and restores settings 0 and 31. |
| `func_02117d5c` | 0x02117D5C returns zero for line zero; otherwise calls the marker query twice and chooses command +12, +16, or +8 for marker pairs (0x8082,0), (0,0), or (0,0x8082), adding 16. Other pairs use spacing zero plus 16. Command index must address a readable 20-byte command. |

The line argument supplied to `StaffRoll_Unk_117d18` is retained in its typed
signature because the original spacing helper supplies it in r1, although the
query itself does not read it. No additional interpretation of that argument is
assumed. Moving spacing initialization after the queries preserves the original
register allocation without changing behavior.

Hard list for M1-T641: none. All eight functions match; no scratch is needed.

## M1-T642 — verified 100% objdiff

Existing neutral symbols are retained. Evidence is the original ARM instructions
at each address. Work, slot, image, and resource views are borrowed; callers must
provide readable storage and writable fields for each observed store.

| Function | Original evidence and contract |
| --- | --- |
| `func_02117dd8` | 0x02117DD8 dispatches +0x10 states 0..2. Unsigned frame thresholds +0x14 and wrapping +0x14 + +0x18 start handler 26 and stop it; state 2 returns 1. |
| `func_021180e4` | 0x021180E4 advances unsigned +0xB4 and derives +0xCC with unsigned division by nonzero +0xC0. At +0xC8 it increments +0xB0, selects state 3 for counts below 10 or state 4 otherwise, and clears +0xB4. |
| `func_02117e5c` | 0x02117E5C constructs a 64-byte path from `Data/Tex/`, the name pointer at +4 of indexed 24-byte table records, and `.gfnt`. The existence query guards loading into resource storage +0x24. Index and combined path length must be valid for that table and buffer. |
| `func_02118584` | 0x02118584 scans 32 slots at +0xF8, stride 16. Active slots are drawn at signed slot +8 minus work +0xE0 minus the screen offset (0 or 288), when y +16 is nonnegative and y <192. Slot +12 supplies opacity; the original draw arguments are flags 0x01000001, x=128, 0, and 2. |
| `func_02117ef4` | 0x02117EF4 resolves resource +0x24, copies four words from resource +12 to indexed image +24, passes image halfwords +40/+42 as outputs, and stores two helper results at image +12/+16. The image index must be 0..3 and its pointer writable. |
| `func_02118784` | 0x02118784 releases and clears all 32 slot handles, releases the signed +12 count of resources, clears that count, calls the observed teardown helpers, releases +4, and clears global data_02176e6c. |
| `StaffRoll_Unk_118620` | 0x02118620 configures drawing, draws image pointers +0x9C/+0xA0 only in state +0xAC=2, then invokes the overlay and slot handler with screen 0 before finalizing drawing. |
| `StaffRoll_Unk_1186cc` | 0x021186CC performs the corresponding drawing sequence using image pointers +0xA4/+0xA8 and screen 1. Positions come from the original external data records. |

The partial work view now exposes resource storage, four image pointers, and 32
slots at their observed offsets. Four metadata words remain an opaque aggregate
to preserve the original copy without inventing field meanings. No module
boundary changes or new dependencies are introduced. Matching and checksum
comparison provide the behavioral regression checks for these assembly targets;
no new unit tests were required by the card.

Hard list for M1-T642: none. All eight functions match; no scratch is needed.

## M1-T643

Existing neutral symbols are retained. All views are borrowed. Original ARM
instructions at the listed addresses provide the contracts below.

| Function | Evidence and result |
| --- | --- |
| `func_021182f0` | **100%**. Derives viewport +0xE0 using unsigned frame progress and nonzero +0xD8, retires old slots, and queues at most one line inside the 480-line lookahead. Advances through type-4 commands, records exhaustion at +0xF4, and advances spacing and line index. Command and text indexes must be valid. |
| `func_0211882c` | **100%**. Parses 20-byte commands; types 1..3 clamp timing arguments, type 4 records the first text command and accumulates spacing from 496. Requires cmdCount readable entries. The pre-existing draft already matched and now has its contract documented. |
| `func_02118974` | **100%**. Preserves an existing global owner, otherwise allocates 776 bytes with four callbacks; returns on failure. Loads resources 43/44, allocates four images using 20-byte records and 32 text handles, initializes viewport fields, and parses the commands. |
| `func_02117f94` | Left linked from the original. Reconstructed all four asynchronous image-load states, readiness byte +89, and unsigned duration computation. Comparison reached 94.10%; the initial two table lookups allocate different registers and schedule multiplication differently. Declaration order, expression order, intermediate pointers/indexes, and signedness variants did not produce an exact match. The unmatched implementation was removed. |

Hard list for M1-T643: `func_02117f94` (336 bytes). A human can create a
`nds_arm9` scratch with tools/decompme.py; no scratch was uploaded here.
The remaining three functions are verified by objdiff; no unit tests were
required for these instruction-matching targets.
