# game/unit_020b12c8

## func_020b12c8 — 0x020b12c8, 448 bytes

Matching C implementation with typed unit, work-area and sort-record views.
The five arguments are an ID category (zero accepts any), query mode, descending
sort flag, permission to include units whose halfword at 0x1d8 is zero, and an
excluded ID. Returns a selected ID, or zero if no slot qualifies. The shared work
area returned by `Unk044904_Get_data_0215ee98` must exist.

Evidence: the original scans ten pointers beginning at work offset 0x64, rejects
units through `func_0204abd8(unit, 0)`, compares ID bits 16–23, and sorts twelve-byte
records with the existing signed-score comparators at 0x020b0d28/0x020b0d38.
Each record receives weight ten. Only records tied with the leading score enter
the random selection. The inclusive `roll <= weight` boundary and the final-record
fallback are preserved, including their original distribution. The getter is
called for each slot, as in the original.

The original symbol is retained: neither the query modes nor the broader gameplay
purpose is established by this local evidence. The ten-element array size comes
from the original loop bound, rather than a guessed capacity.

## func_020b1488 — 0x020b1488, 876 bytes

Not implemented in the submitted C; continues to link from the delinked object.
No descriptive rename is proposed.

Evidence: checks the shared work area for null, then requires an ID-category-one
unit passing `func_0204a968(unit, 0)`. Work bits one and zero force result codes
one and two. A second ten-slot scan selects category-one and category-two units
using query modes six and seven, and records whether a category-one unit returns
four from `func_0204a244`. The category-two comparison uses the category-one best
sum; its initial mode-seven/mode-six queries discard their results. These apparent
asymmetries were preserved in the candidate.

Remaining branches combine `func_020491cc` and `func_02049220`, rounded Q12
products, clamps from 4096 to 102400, work bits six/five, random rolls through
`func_02050074`, and entries 168/167 queried through the 0x02098978/0x0209896c
functions. Result codes range from zero to three. Their gameplay meanings remain
unproven.

### Hard list

- **func_020b1488**: reconstructed control flow, flag bitfields, scan register
  allocation and query ordering. Closest straightforward candidate was 892 bytes
  versus 876: each constant Q12 product emitted an extra zero-register setup and
  multiply-accumulate. The target uses `umull`, sign extension and one `mla`;
  mwccarm 2.0/sp1p5 emitted an additional `mla` with a zero high operand. Tried
  signed/unsigned 64-bit casts, reversing operands, inline multiplication helpers,
  separate product/rounding temporaries, and equivalent factored constants. None
  matched. A human can investigate this code-generation difference with
  `tools/decompme.py` using the original function; no scratch was uploaded.
