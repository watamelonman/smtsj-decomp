# src/game/unit_0210a034.c

- `Unk10a034_Get_data_02176e38` (16 B): Returns the word at 0x02176e38; the original loads this global directly. Typed parameters and return values retain the raw word semantics; no higher-level purpose is inferred.
- `Unk10a034_Get_data_02176e3c` (16 B): Returns the first word at 0x02176e3c; the original loads this global directly. Typed parameters and return values retain the raw word semantics; no higher-level purpose is inferred.
- `Unk10a034_Unk_10af7c` (16 B): Returns the word at +4 from data_02176e3c, as observed in the original load. Typed parameters and return values retain the raw word semantics; no higher-level purpose is inferred.
- `Unk10a034_Get_data_02176e44` (16 B): Returns the word at 0x02176e44; the original loads this global directly. Typed parameters and return values retain the raw word semantics; no higher-level purpose is inferred.
- `Unk10a034_Clear_data_02176e38` (20 B): Clears the word at 0x02176e38; the original stores zero to this global. Typed parameters and return values retain the raw word semantics; no higher-level purpose is inferred.
- `Unk10a034_Unk_10a9a4` (20 B): Requires writable work: preserves arg1 at +0x10 and sets +8 to arg1 or, when arg2 is zero, 0x11. Evidence: original stores and conditional move at 0x0210a9a4. Typed parameters and return values retain the raw word semantics; no higher-level purpose is inferred.
- `Unk10a034_Clear_data_02176e44` (20 B): Clears the word at 0x02176e44; the original stores zero to this global. Typed parameters and return values retain the raw word semantics; no higher-level purpose is inferred.
- `Unk10a034_Unk_10b394` (20 B): Requires writable work: preserves arg1 at +0x10 and sets +8 to arg1 or, when arg2 is zero, 8. Evidence: original stores and conditional move at 0x0210b394. Typed parameters and return values retain the raw word semantics; no higher-level purpose is inferred.
- `Unk10a034_Unk_10a05c` (24 B): **100% objdiff**. Passes the borrowed work from `data_02176e38` to `func_02061424` when nonzero. Evidence: getter and conditional call at 0x0210a060–0x0210a06c.
- `Unk10a034_Unk_10a074` (24 B): **100% objdiff**. Copies the borrowed global work word at +0x10 to +8 when present. Evidence: conditional load/store at 0x0210a080–0x0210a084.
- `Unk10a034_Unk_10a0b4` (24 B): **100% objdiff**. Returns the global work word at +0x18, or 1 when absent. Evidence: conditional move/load at 0x0210a0c0–0x0210a0c4.
- `Unk10a034_Unk_10afc0` (24 B): **100% objdiff**. Returns the borrowed address at the `Unk10a034_Unk_10af7c` result +0x18, or zero when absent. Evidence: conditional move/add at 0x0210afcc–0x0210afd0.
- `Unk10a034_Unk_10b000` (24 B): **100% objdiff**. Passes the borrowed work from `data_02176e44` to `func_02061424` when nonzero. Evidence: getter and conditional call at 0x0210b004–0x0210b010.
- `Unk10a034_Unk_10b018` (24 B): **100% objdiff**. Copies the borrowed second global work word at +0x10 to +8 when present. Evidence: conditional load/store at 0x0210b024–0x0210b028.
- `Unk10a034_Unk_10b058` (24 B): **100% objdiff**. Returns the unsigned byte at +2 in the record from `func_020a1740(id)`, multiplied by 300. The provider must return a readable record. Evidence: call, byte load, and multiply at 0x0210b05c–0x0210b068.
- `Unk10a034_Unk_10aeb0` (32 B): **100% objdiff**. Clears twelve words at offsets +0x2c + 12*i (0 <= i < 12) of borrowed writable storage. The base must be word-aligned and readable/writable through +0xb3. Evidence: counted str/add loop at 0x0210aeb0–0x0210aecc.
- `Unk10a034_Unk_10b104` (32 B): **100% objdiff**. Initializes seven writable words with two caller values and five zeros. Evidence: stores at 0x0210b104–0x0210b11c and the caller’s 28-byte allocation.
- `Unk10a034_Unk_10af40` (44 B): **100% objdiff**. When the ID changes, stores it at data_02176e3c and caches func_020d2eb0(id) in the next word. Evidence: comparison, store, and call at 0x0210af4c–0x0210af60.
- `Unk10a034_Unk_10af0c` (52 B): **100% objdiff**. Passes the borrowed work halfword at +0xb4 to provider slot 7, invokes provider ID 22 with value -1, and sets the linked work word at +0x18 to 28. Evidence: calls and stores at 0x0210af0c–0x0210af38. The work and its +4 link must be valid.

- `func_0210a034` (40 B): **100% objdiff**. Calls func_0210a0dc with both caller words when data_02176e38 is zero and stores the result there. Evidence: guarded call/store at 0x0210a034–0x0210a054.
- `Unk10a034_Unk_10a08c` (40 B): **100% objdiff**. Returns true when global work is absent or its +8 word equals 18. Evidence: conditional return and comparison at 0x0210a094–0x0210a0ac.
- `Unk10a034_Alloc` (40 B): **100% objdiff**. Calls func_0210b080 with both caller words when data_02176e44 is zero and stores the result. Allocation naming is supported by the provider requesting 28 bytes via func_020611dc.
- `Unk10a034_Unk_10b030` (40 B): **100% objdiff**. Returns true when second global work is absent or its +8 word equals 10. Evidence: conditional return and comparison at 0x0210b038–0x0210b050.
- `Unk10a034_HasId` (44 B): **100% objdiff**. Tests the four borrowed halfword IDs at +0xc8 against the caller word. Evidence for the name: indexed halfword load/comparison loop at 0x0210aee0–0x0210aefc.

## M1-T761 verification

The eight entries above use the original ARM loads/stores as naming and behavior evidence. Global accessors take no arguments. The two work setters borrow a writable `Unk10a034Work` and do not transfer ownership; only offsets +8 and +0x10 change. No hard functions remain for this card.

## M1-T762 verification

All eight requested functions match at 100% in the generated objdiff report. Neutral names retain the instruction-established contracts without guessing subsystem purpose. Existing source bodies were refined rather than creating a duplicate TU. No new tests were added (`tests_required = false`); original-object comparison verifies the instruction sequences. Build, anticheat, nine repository tests, match, and byte-identical checksum gates pass. No hard functions remain for this card.

## M1-T763 verification

The TU already existed from earlier cards; its seven existing requested bodies were retained and the missing guarded creator was added. Provider declarations now specify the observed arguments, including the ID retained in r0 across the cache update. All eight requested functions match 100%; no hard functions remain. Original-object comparison supplies acceptance coverage (`tests_required = false`), without adding behavioral tests that duplicate the instructions.

## M1-T764 verification

- `Unk10a034_GetEntry8` (52 B): **100% objdiff**. Returns a borrowed eight-byte entry at global work +0x20 + 8*i for indices 0..3, or zero for an invalid index or absent work. Naming evidence: bounds checks and shifted-index addition at 0x0210af8c.
- `Unk10a034_ClearById` (60 B): **100% objdiff**. Clears +8 in the first used twelve-byte entry with a matching halfword ID. Borrows twelve writable entries at +0x24. Naming evidence: comparison and zero store at 0x0210ae98.
- `Unk10a034_Unk_10b484` (76 B): **100% objdiff**. Returns zero when work +0x18 is clear; otherwise reads the linked descriptor. Kind 2 returns its +0x1c word; kind 3 scales the provider record selected by its +0x1a ID; other kinds return zero. Evidence: original descriptor cases at 0x0210b484.
- `func_0210acac` (84 B): **100% objdiff**. Scans twelve entries at +0x24 for a used, unmarked entry with the requested +2 halfword. Optionally sets its +8 word and returns its ID; exhaustion returns zero. Evidence: loads, comparisons, and conditional store at 0x0210acac.
- `func_0210b42c` (88 B): **100% objdiff**. Clears work +0x18, then sets it for linked descriptor kind 2 or for kind 3 when the ID provider returns zero. Kind 1 and other kinds leave it clear. Both borrowed objects must exist. Evidence: descriptor switch at 0x0210b42c.
- `func_0210ad00` (100 B): **100% objdiff**. Counts used, unmarked entries of the requested kind whose IDs are absent from the four-ID list. Evidence: twelve-entry loop and HasId call at 0x0210ad00.
- `func_0210a0dc` (112 B): **100% objdiff**. Requests 216 bytes from func_020611dc with update callback func_0210a1d8, global-clear cleanup, and arguments 3/0/1. Initializes successful allocations with both caller words; returns zero on failure. Evidence: original allocator call and initialization at 0x0210a0dc.
- `func_0210b080` (112 B): **100% objdiff**. Requests 28 bytes with update callback func_0210b124, second-global cleanup, and arguments 3/0/1. Initializes seven words after successful allocation and returns zero on failure. Evidence: original allocator call and initialization at 0x0210b080.

The existing TU and three already matching requested bodies were retained. Original-object comparison provides acceptance coverage (`tests_required = false`). No hard functions remain for this card. The unrelated decompiler-derived `Unk10a034_Unk_10ac28` remains outside this card.

## M1-T765 verification

- `func_0210a160` (120 B): **100% objdiff**. Initializes the 216-byte work: two caller words, five cleared words, a state of 1, zeroed selection fields and ID arrays, then calls `Unk10a034_Unk_10ac28`. Evidence: stores and initializer call at 0x0210a160.
- `Unk10a034_Unk_10ac28` (132 B): **100% objdiff**. Fills twelve borrowed twelve-byte entries from area IDs, provider kinds, and record byte +2. Evidence: area +0x36 and record +2 loads at 0x0210ac48–0x0210ac90.
- `func_0210b3a8` (132 B): **100% objdiff**. Applies the linked descriptor by kind: kind 1 submits an ID/value pair, kind 2 adds a signed amount, kind 3 selects an entry or adds its scaled value. The work and descriptor are borrowed. Evidence: descriptor switch at 0x0210b3a8.
- `func_0210ab60` (200 B): **100% objdiff**. Applies up to four linked eight-byte entries; kinds 1–3 use entry fields, kind 4 uses the work's selected IDs. Evidence: stride-eight loop and provider calls at 0x0210ab60.
- `func_0210ad64` (288 B): **100% objdiff**. Publishes the current five-slot page of selected IDs and labels, resetting an out-of-range page counter. Evidence: twelve-entry filter, five-slot paging, and label calls at 0x0210ad64.
- `func_0210a9b8` (424 B): **100% objdiff**. Validates four linked eight-byte slots against area/record providers and returns the accepted count, -1 on rejection, and -2 when the ID is already listed. Evidence: slot table and provider calls at 0x0210a9b8–0x0210ab28.
- `func_0210b124` (624 B): **100% objdiff**. Runs the 28-byte work state machine over states 0–10, driving descriptor application and provider notifications. Evidence: switch table at 0x0210b124–0x0210b390.
- `func_0210a1d8` (1996 B): **100% objdiff**. Runs the 216-byte work state machine over states 0–18, covering slot validation, paging, descriptor application, and provider callbacks. Evidence: switch table at 0x0210a1d8–0x0210a96c.

The three previously untyped provider declarations gained observed return values (`func_0209993c`, `Unk02e000_GetWorkArea`) and the two state machines share the existing borrowed `Unk10a034Work` layout. No hard functions remain for this card.
