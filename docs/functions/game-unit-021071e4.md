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

## M1-T858

All eight functions match the original at 100% in objdiff. Names remain neutral;
contracts below follow target instructions and relocation-backed calls.

- `func_02108a50`: queries mode zero, stores the signed result at +0x60,
  sets +0x5c when it is nonzero and no greater than the area limit at +0x344,
  and forwards its negation to `Unk0fc584_Unk_0fc84c`.
- `func_02108b40`: obtains resource 30 in mode 2, calls its preparation routine,
  selects the supplied index, and forwards the derived result as argument five
  to `func_02061f10`, with the other arguments value,-1,0,0.
- `func_021073e4`: initializes descriptor size 104, enabled 1, and six callback
  slots at +0x0c through +0x20. Slot three is null; +8 remains untouched.
  Callback identities come from the original ABS32 relocations.
- `func_021089f8`: clears the selected record category. If its signed current
  field is nonpositive, restores it from the paired source field. Selection zero
  uses the main record (+0x6c, +0x1c, +0x12); other selections use area records
  (+0x34, +0x1e, +0x0a) through signed IDs at work+selection+0x3b.
- `func_02107374`: returns one for a nonzero main category or any nonzero
  category among the nonnegative signed IDs in area+0x348. The unsigned byte
  at area+0x357 bounds the search; otherwise returns zero.
- `func_0210860c`: selects the original packed color constants for categories
  5, 4, and other, distinguishing flag equal to one from all other values.
- `func_02108960`: derives the selected record's category value through
  `func_02108928`, stores it at +0x60, then applies the same limit check and
  negation forwarding as `func_02108a50`. The stored value is reloaded as in
  the original instructions.
- `func_02107648`: releases handles at +0x38 and +0x34, releases and clears
  five nonzero handles starting at +8, then releases and clears +4 and +0.
  It calls the drain routine five times, invokes the final operation with 2,
  and clears `data_02176e30`.

The descriptor and existing work view are local to this translation unit; no
module boundary changes are introduced. Accesses beyond the work prefix use
explicit typed offset views, preserving the original signedness and widths.
Tests are not required by this card; objdiff verifies the compiled instructions.

### Hard list

None for M1-T858.

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
