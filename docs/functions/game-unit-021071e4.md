# src/game/unit_021071e4.c

## M1-T857

All names are retained from the symbol table. Behavior below is evidenced by
ARM instructions in the original target functions; no broader purpose is inferred.

- `Unk1071e4_IsNot1or7`: returns zero for categories 1 and 7, one otherwise;
  evidenced by the two comparisons and separate constant return blocks.
- `Unk1071e4_Unk_107c34`: calls the two external setters with IDs 19 and 18,
  then stores state 4 at work offset 0x29.
- `Unk1071e4_Unk_1087f4`: passes its category to the predicate; when true,
  returns `(otherX-x) + 3*(otherY-y)`. The fifth argument is signed 16-bit.
- `Unk1071e4_Unk_1088fc`: copies area position for selected index zero;
  otherwise reads a signed record ID at work+selected+0x3b and resets that record.
- `func_02108928`: maps category 0 to zero, 1 to third argument plus 300,
  7 to 200, and all other categories to 100. The second argument is unused.
- `func_02108aa4`: resets area position, then visits count-1 signed IDs starting
  at offset 0x3c through the area-record accessor and record operation.
- `Unk1071e4_Unk_108b08`: indexes handles at offset 8 and a parallel global
  table, calling two operations. Index validity is a caller responsibility.
- `Unk1071e4_Unk_108b94`: queries the area subrecord and forwards its derived
  result as the fifth argument to the final call; other arguments are value,-1,0,0.

The work type describes only accessed offsets. Signed record IDs and the signed
count follow `ldrsb` and signed loop branches respectively. Typed external
declarations preserve the observed argument contracts.

### Hard list

None for M1-T857.

## Not done in M1-T858
- `func_02108a50`
- `func_02108b40`
- `func_021073e4`
- `func_021089f8`
- `func_02107374`
- `func_0210860c`
- `func_02108960`
- `func_02107648`

## Not done in M1-T859
- `func_021072c0`
- `func_0210882c`
- `func_02108534`
- `func_021071e4`
- `func_02107ff4`
- `func_02108694`
- `func_02108128`
- `func_0210792c`

## Not done in M1-T860
- `func_02107a9c`
- `func_0210743c`
- `func_021076f0`
- `func_02108290`
- `func_02107c60`
