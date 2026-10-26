# game/unit_0211e6b8

## `func_0211e6b8`

ARM, address `0x0211e6b8`, size `0x5c4` (1476 bytes). The neutral
symbol is retained because the screen's identity is not established.

The callback receives a borrowed work-area pointer. State 4 returns immediately;
states 0 and 1 draw two images, while states 2 and 3 draw the list view.
Other states only run the common rendering setup and teardown. Evidence is the
calls to image helpers `func_0205c748`, `func_0205de40`, `func_0205e048`, and
text helpers `func_02060dd4` and `func_02059f70`.

The list uses 13-pixel row spacing. Its scroll thumb derives from image 14,
with height divided by `(total + 10) / 11`, clamped to at least four pixels;
the last page pins the thumb to the bottom. Two entry predicates gate optional
row images. Fields at +0x2e4 and +0x318 gate additional images and row text.
The work-area and temporary image/text layouts preserve the observed offsets
without assuming these unknown fields' wider purpose. Array and resource validity
are caller contracts, as in the original; no additional bounds checks are added.

Matching required separate loop counters for the image and text loops, and
expressing row positions as index multiplications so the compiler generates the
original induction variables. Standalone byte/relocation comparison matches all
1476 bytes. Full objdiff and image checksum are checked with the project gates.

## Hard list

None.
