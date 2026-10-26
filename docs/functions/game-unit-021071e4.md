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

## M1-T859

All eight functions match at 100% in objdiff. Existing symbol names are retained;
behavior and offsets below are evidenced by the original ARM instructions and
relocation-backed calls. No broader UI purpose is inferred.

- `func_021072c0`: checks eligible categories for a current value below its
  paired limit. It checks the main record first, then area records bounded by
  `Unk096754_CountEntries`, stopping on the first qualifying record.
- `func_0210882c`: computes the selected record's three-column delta through
  `Unk1071e4_Unk_1087f4`, stores it at +0x60, compares against the area limit,
  stores eligibility at +0x5c and forwards the negated delta. The main-record
  getters execute in the original order; the final coordinate is signed 16-bit.
- `func_02108534`: forwards coordinates and opacity to the drawing provider,
  choosing kind 8 for category 1, otherwise kind 6 or 7 according to the flag.
  Both scale arguments are 1.0; the remaining provider arguments are 0 and 4.
- `func_021071e4`: obtains resource 17 in mode zero and visits its 24-byte
  records. For each, it insertion-sorts six unsigned halfwords at +12 into a
  cleared temporary array, discarding zeros and duplicates, then copies the
  twelve-byte result back. Resource storage remains owned by the provider.
- `func_02107ff4`: draws the main record and two index-zero labels, selecting
  the second label color from the tier and category. It draws the overlay only
  in state 6 with nonzero mode and selection zero.
- `func_02108128`: draws the signed-ID record indexed at work+index+0x3c.
  The caller must supply a valid list index. It enables the record according
  to the unsigned byte at +0x28, draws labels when opacity is at least 1.0,
  and draws the overlay in state 6 when mode is nonzero and selection=index+1.
- `func_0210792c`: handles state 5 input. Mode zero confirms all records;
  modes 1/2 first update selection, then confirm the selected record. Confirmation
  checks +0x5c, chooses the corresponding record operation and enters state 6;
  cancellation invokes the existing state-4 helper.
- `func_02108694`: dispatches message tags 0..4. Tag zero initializes state 1;
  tag one clears state and calls the owner operation; tag two enters state 4;
  tag three extracts payload bit-8 data, entering state 2 for value 1, otherwise
  extracts bit-2 data to select a mode, recomputes its value and enters state 5.
  Tag four is empty. The one-element initialized local preserves the original
  output-slot storage. Payload words are borrowed from the caller.

The descriptor now explicitly types its message callback with its second argument;
its six slot offsets and all existing initializer instructions are unchanged.
These are TU-local views, so no module boundary changes are introduced.
Validation: instruction comparison, objdiff match gate, project unit tests,
anticheat and full-image checksum. No new tests are required by this card.

### Hard list

None for M1-T859.

## M1-T860

Names remain neutral. Contracts below follow ARM loads, stores, and symbol-backed
calls in the original functions; no broader purpose is inferred.

- `func_02107a9c`: button masks 64/128 move the selected index by rows in a
  three-column list, with special handling for the main record and partial final
  rows. Masks 32/16 call the bounded index helper with -1/+1. Returns whether
  selection changed; counts no greater than one return zero.
- `func_0210743c` (not implemented; see hard list): allocates the resource and five animation handles, then orders
  signed record IDs with the three preferred IDs first. Initializes label handles,
  opacity values, selection, flags, and computed values. Resource addresses and
  allocation calls are evidenced by original relocations.
- `func_021076f0`: dispatches states 1, 2, 3, 6, and 7; advances opacity in half
  steps, polls animation completion, deducts the computed value from area+0x344,
  and recomputes eligibility. Updates five handles whenever state is nonzero.
- `func_02108290`: draws the category and signed halfword values. Below full
  opacity only the base is drawn. The first value uses a warning color below
  one fifth of its limit; positive values draw bars scaled to 30 pixels, with
  a minimum width of one. Callers provide valid nonzero limits for positive values.
- `func_02107c60`: draws main-record and three-column area-grid layers, labels,
  selection highlights, and state-six overlays. Grid positions use 81-pixel
  columns and 33-pixel rows; record opacity is selected in groups of four.

The extended work view remains local to the translation unit. The four float
opacity slots expose only offsets +0x48 through +0x54 seen in the instructions.
No module boundary changes are introduced. Tests are not required by this card;
instruction comparison and the project gates provide validation.

### Hard list

- `func_0210743c` remains supplied by the delink. A complete C candidate had
  the correct 524-byte size but measured 99.01% in objdiff. Standalone comparison
  showed different register allocation for the preferred-ID loop and its insertion
  counter. Tried shared/separate loop counters, signed-byte versus explicit-cast
  iteration, declaration ordering, and initialization order; none matched exactly.
  The candidate was omitted as required by the card. A human can open a scratch
  with `tools/decompme.py` for this function.

The other four functions match at 100%. Full-width drawing arguments are retained
at the call boundary, while the callee reads their low signed/unsigned halfwords;
this preserves the original main-record caller's untruncated getter results.
