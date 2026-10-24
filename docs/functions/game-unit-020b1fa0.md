# game/unit_020b1fa0

All three functions match at 100% objdiff with the configured mwccarm compiler.
Existing `func_` symbols are retained because the precise gameplay purpose is not
established. Layouts are local borrowed views, not new engine boundaries.

## func_020b1fa0 — 0x020b1fa0, 236 bytes

Advances a five-phase callback using a signed phase byte and a counter at +4.
Phases 1 and 3 perform their transition once the counter exceeds eight; each
still increments the counter on that update. The +8 argument is passed to
`func_020fc734` and `Unk0979d8_AddField344`. Phase 4 releases the callback work
through `func_02061424` when `Unk0fc584_IsBelow64` becomes false.
The caller must supply the allocator-owned twelve-byte work block.
Evidence: switch table, +0/+4/+8 accesses, predicate calls and final release.

## func_020b208c — 0x020b208c, 116 bytes

Allocates twelve bytes with `func_020b1fa0` as callback, initializes phase and
counter to zero, and retains its integer argument at +8. Allocation failure
returns null before any initialization calls. Successful allocation invokes
`Unk09d060_Unk_09d170` and conditionally sets direction to one. Ownership passes
to the callback system, which eventually releases the block.
Evidence: callback literal, allocator arguments 12/4/0/0 and initialization stores.

## func_020b2100 — 0x020b2100, 700 bytes

Saves and clears sixteen record active bytes at table +0x10f with stride 16.
Scans the radius-three diamond around signed coordinates at work +0x364/+0x365,
clipping to 45 columns and 40 rows. A flagged grid entry is excluded unless
state +0x7494 permits it. Kind-2 cells resolve records; enabled records whose
selector query returns exactly one become active and make the result one.
Previously inactive records trigger the visor calls and state promotion to two.
Nonnegative record indices notify the indexed state helper. Matching area IDs
also issue event 19 and the coordinate update. An eligible 88-byte payload may
set state +0x7498 to its text at +24: the first character is tested against 48,
then subsequent characters against zero, up to 32 bytes.
Evidence: accessor calls, signed coordinate loads, loop bounds, state stores,
88-byte indexed payload addressing and signed character comparisons. All state
and accessor pointers must be valid; cell indices must address the sixteen
saved flags. The integer result indicates any qualifying active record.

The inner horizontal limit is computed once per row, preserving the original
loop structure and compiler register allocation.

## Hard list

None.
