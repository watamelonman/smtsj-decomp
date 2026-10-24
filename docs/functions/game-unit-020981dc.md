# game/unit_020981dc

All six M1-T205 functions match at 100% in objdiff. Names remain neutral:
record offsets and resource access establish behavior, but not gameplay meaning.
Local structures describe borrowed storage and only the fields accessed here.

- `Unk0981dc_Unk_0981dc` (24 bytes): forwards the area id to
  `Unk096754_GetAreaRecordIf`, returns its unsigned halfword at +0x36, or zero
  for a null result. Evidence: conditional `ldrh` at +54.
- `Unk0981dc_Unk_0981f4` (100 bytes): writes the supplied byte at +0x0e through
  +0x12 according to selectors 0 through 4. An existing area always triggers
  `func_0209786c`, including for an unsupported selector; an absent area does
  nothing. Evidence: five-way store jump table followed by the notification call.
- `Unk0981dc_Unk_098258` (104 bytes): reads the same selected bytes as signed
  values. Returns zero for absent areas or unsupported selectors. Evidence:
  five `ldrsb` return paths at +14 through +18.
- `func_020982c0` (100 bytes): obtains resource (1, 0), its data and signed
  entry count, then scans eight-byte entries for a matching signed first byte.
  Returns the first borrowed entry, or null for an absent resource or no match.
  Evidence: calls to `020445d0`, `0204fde0`, `0204fe18`, then `ldrsb` and an
  eight-byte cursor increment. The id parameter is compared without narrowing.
- `Unk0981dc_Unk_098324` (56 bytes): accepts a zero second id immediately;
  otherwise accepts only when the second entry's signed byte +1 exceeds the
  first's. Both lookups must succeed when the second id is nonzero. Evidence:
  two `020982c0` calls and signed `le` rejection after the byte comparison.
- `func_0209835c` (272 bytes): inspects exactly six halfword ids. Nonzero ids
  with nonnull `020cb21c` records whose +0x26 bits 6..10 equal 10 contribute
  ten times their +0x22/+0x23 bytes to two percentage factors, initially 100.
  Each input signed halfword is multiplied using unsigned 32-bit arithmetic
  and divided by 100; an unchanged result with factor above 100 is incremented.
  Zero remains zero and other results are clamped to 1..999. Evidence: six-pass
  loop, two `mla` instructions, unsigned division-by-100 sequences, signed clamp
  comparisons, and final halfword stores. The pair must be writable and ids
  must address six readable elements.

## Validation

The instruction comparison caught redundant return-value extension in the first
getter's ternary expression; a typed local with explicit branches reproduces the
original conditional load. All six definitions pass the objdiff match gate.
Anticheat, the nine repository unit tests, and the full image checksum also pass.
No new behavioral tests were required by the card; original machine code is the
matching oracle. The delink configuration remains human-owned.

## Hard list

None.
