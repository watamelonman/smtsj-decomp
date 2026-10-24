# game/unit_020de37c

Both ARM functions retain their neutral original symbols because the particular
UI element and record meaning have not been established by callers or strings.
The local record view names only the two accessed bytes and borrows its storage.
No module boundary changes are introduced.

## func_020de37c — 0x020de37c, 120 bytes

Submits entries 0x2100 and 0x2101 at the incoming integer coordinates, using
scale 1.0, zero flags and order 9. The second submission uses layer argument
0x1002 rather than 2. Evidence: the original constants and two calls to
func_02058e9c. The coordinate units are those expected by that callee.
Standalone comparison matches all instructions and relocations.

## func_020de3f4 — 0x020de3f4, 644 bytes

Uses the indexed record's +0x1e value and the borrowed metadata bytes +0x5a
and +0x5b to submit a segmented bar. Each value is shifted by 12, divided
by 10, multiplied by 6, and shifted back; preserve that integer rounding
rather than replacing it with a single percentage expression. Bounds narrow
to unsigned 16-bit and segment widths to signed 16-bit, as in the original.
A nonpositive amount emits nothing. A second +0x1e query of at least 100
selects the 60-unit full bar and overlay; other values emit threshold markers
and positive segment widths with entries 0x2102–0x2105. Index must be valid
for both record accessors. Evidence: original byte loads, arithmetic and
width-bearing calls to func_02058f10. Standalone comparison matches all
instructions and relocations after preserving local allocation order and
sharing the full-bar left coordinate.

## Hard list

None.
