# game/unit_020d1ee8

All five functions match at 100% with the configured mwccarm compiler.
Original symbol names are retained to agree with the human-owned symbol map.
Their broader gameplay purpose is not established; descriptions below are limited
to observed calls, constants and field accesses in the original ARM code.

The private owner view has a map at +0x240, a readiness word at +0x7440,
signed mode/phase/x/y bytes at +0x7480..+0x7483, and timer/choice words at
+0x7484/+0x7488. The slot-byte array starts at +0x34. Cell word +4 contains
a four-bit, one-based slot selector at bits 16..19. Element word +0 supplies
an eight-bit index. These are borrowed views, with no allocation or ownership
transfer. Padding and array extents describe only the offsets required here.

## func_020d1ee8 — 268 bytes

Advances the mode-zero interaction through readiness, message completion and
final readiness. On phase zero, raises the selected element's two-bit state to
at least one and submits message 20. Returns one on completion or an unknown
phase, otherwise zero. Evidence: calls to Get2Bits/Set2Bits and the phase-byte
updates at 0x020d1ee8..0x020d1fec. Requires a valid owner and selected cell/element.

## func_020d1ff4 — 1992 bytes

Runs the alternate interaction through phases -1, 0..12 and 100. Checks bits
0x72b/0x73d and 0x72c/0x73e for initial messages, chooses prompts 0x15..0x19
from slot-four mode and the selected slot value, and maps the answer to a new
slot value or cancellation. Subsequent phases update the current-cell flags
and timer, submit the transition, raise the element state to three, and wait
for message completion. Phase 100 resets the transition and resumes at phase
eight. Returns one on completion or an unrecognized phase. Evidence: the
original switch, constants and calls at 0x020d1ff4..0x020d27a4. Requires valid
owner/map data; a cell's slot selector must address the owner's slot array.

## func_020d27bc — 264 bytes

Queries the root's current coordinates. Returns zero for a missing cell, a
kind other than 0x24, or slot four having neither value one nor value two.
Otherwise raises the element state to at least two, invokes the scan-visor
helper, and refreshes matching-area coordinates when the state changes;
returns one. Evidence: kind comparison and two-bit operations at
0x020d27bc..0x020d28bc. Coordinates are explicitly narrowed to signed 16-bit
for the refresh call, as in the original.

## func_020d28c4 — 148 bytes

Looks up the owner's selected cell and element. For kind 0x24, sets mode to
one when slot four has value one or two, otherwise zero, then calls
func_02065bc0 and returns one. Other kinds return zero. Evidence: comparisons
and mode-byte writes at 0x020d28c4..0x020d2954. The element lookup is retained
although its result is unused. Requires a valid selected cell.

## func_020d2958 — 36 bytes

Dispatches to func_020d1ee8 for mode zero, otherwise func_020d1ff4, forwarding
the owner and result. Evidence: signed byte load at +0x7480 and the two calls
at 0x020d2958..0x020d2978.

## Hard list

None.
