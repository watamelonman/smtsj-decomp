# src/game/unit_0210a034.c

- `Unk10a034_Get_data_02176e38` (16 B): Returns the word at 0x02176e38; the original loads this global directly. Typed parameters and return values retain the raw word semantics; no higher-level purpose is inferred.
- `Unk10a034_Get_data_02176e3c` (16 B): Returns the first word at 0x02176e3c; the original loads this global directly. Typed parameters and return values retain the raw word semantics; no higher-level purpose is inferred.
- `Unk10a034_Unk_10af7c` (16 B): Returns the word at +4 from data_02176e3c, as observed in the original load. Typed parameters and return values retain the raw word semantics; no higher-level purpose is inferred.
- `Unk10a034_Get_data_02176e44` (16 B): Returns the word at 0x02176e44; the original loads this global directly. Typed parameters and return values retain the raw word semantics; no higher-level purpose is inferred.
- `Unk10a034_Clear_data_02176e38` (20 B): Clears the word at 0x02176e38; the original stores zero to this global. Typed parameters and return values retain the raw word semantics; no higher-level purpose is inferred.
- `Unk10a034_Unk_10a9a4` (20 B): Requires writable work: preserves arg1 at +0x10 and sets +8 to arg1 or, when arg2 is zero, 0x11. Evidence: original stores and conditional move at 0x0210a9a4. Typed parameters and return values retain the raw word semantics; no higher-level purpose is inferred.
- `Unk10a034_Clear_data_02176e44` (20 B): Clears the word at 0x02176e44; the original stores zero to this global. Typed parameters and return values retain the raw word semantics; no higher-level purpose is inferred.
- `Unk10a034_Unk_10b394` (20 B): Requires writable work: preserves arg1 at +0x10 and sets +8 to arg1 or, when arg2 is zero, 8. Evidence: original stores and conditional move at 0x0210b394. Typed parameters and return values retain the raw word semantics; no higher-level purpose is inferred.
- `Unk10a034_Unk_10a05c` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk10a034_Unk_10a074` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk10a034_Unk_10a0b4` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk10a034_Unk_10afc0` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk10a034_Unk_10b000` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk10a034_Unk_10b018` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk10a034_Unk_10b058` (24 B): decompiler-derived (Ghidra output, cleaned)
- `Unk10a034_Unk_10aeb0` (32 B): decompiler-derived (Ghidra output, cleaned)
- `Unk10a034_Unk_10b104`: decompiler-derived
- `Unk10a034_Unk_10af40`: decompiler-derived
- `Unk10a034_Unk_10af0c`: decompiler-derived

## Not done in M1-T763
- `func_0210a034`
- `Unk10a034_Unk_10a08c`
- `Unk10a034_Alloc`
- `Unk10a034_Unk_10b030`
- `Unk10a034_HasId`

## Not done in M1-T764
- `Unk10a034_GetEntry8`
- `Unk10a034_ClearById`
- `Unk10a034_Unk_10b484`
- `func_0210acac`
- `func_0210b42c`
- `func_0210ad00`
- `func_0210a0dc`
- `func_0210b080`
- `Unk10a034_Unk_10ac28`: decompiler-derived (struct cleanup)
- `Unk10a034_Unk_10a08c`: hand-matched
- `Unk10a034_HasId`: hand-matched
- `Unk10a034_ClearById`: hand-matched
- `Unk10a034_GetEntry8`: hand-matched
- `Unk10a034_Alloc`: hand-matched
- `Unk10a034_Unk_10b030`: hand-matched
- `Unk10a034_Unk_10b484`: hand-matched

## M1-T761 verification

The eight entries above use the original ARM loads/stores as naming and behavior evidence. Global accessors take no arguments. The two work setters borrow a writable `Unk10a034Work` and do not transfer ownership; only offsets +8 and +0x10 change. No hard functions remain for this card.
