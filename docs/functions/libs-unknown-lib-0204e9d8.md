# libs/unknown/lib_0204e9d8

The original `func_` symbols remain because the human-owned symbol configuration
requires them. Descriptions below are based on the delinked ARM instructions,
not guessed SDK identities. The TU remains linked from its delinked object.

## Source search

Public-source searches for the neighbouring provider address and Pokémon battle
target selection found no matching implementation. The observed ten singleton
slots at +0x64, ID group byte at bits 16..23, callbacks in the neighbouring
0204d1bc unit and calls into 020b0xxx/020cb1a0 suggest game-side selection logic,
not a standalone NitroSDK routine. No public-source attribution is claimed.

## func_0204e9d8 — 12 bytes — 100%

Forwards a borrowed request pointer and unsigned ID to `func_0204d938`. The
provider's entry reads four request words; this wrapper does not inspect them
or retain storage. The compiled C emits the original interworking tail thunk.

## func_0204e9e4 — 200 bytes — deferred

Collects IDs from ten singleton object slots, skipping null objects and objects
for which `func_0204a9ec` returns nonzero. Group zero accepts all groups; other
values filter ID bits 16..23. The two-argument callback receives the borrowed
object and signed argument. A nonzero fifth parameter accepts zero callback
results; zero accepts nonzero results. A missing singleton returns zero.
Output storage must accommodate all accepted IDs, up to ten.

Trial C reached 97.80% with the same instruction sequence and branch structure.
The compiler allocated count/index/object to r6/r4/r5, versus original r4/r5/r6.
Tried nested conditions and early continues, for/do loops, explicit increments,
local declaration ordering, signed/unsigned counts, register hints and scoped
optimizer settings. None resolved the allocation. The C definition is omitted;
the original delink remains the provider.

## func_0204eaac — 264 bytes — deferred

Uses the same ten-slot, active-object and group filters, retaining tied extrema
of a signed callback result. Maximum search starts at zero; minimum search at
0x7fffffff. Equal values append an ID; a strictly better value resets the count
and starts a new tied set. A missing singleton returns zero. Output storage
must accommodate up to ten IDs.

Trial C reached 98.33%. Count/index/object had the same register permutation as
0204e9e4; the bound, callback, parameters, stack slots and branch layout matched.
The source-shape and optimizer trials listed above did not resolve this. The C
definition is omitted and the original delink remains the provider.

## func_0204ebb4 — 276 bytes — 100%

Derives a group from request mode at +8 and the input ID. Mode one swaps groups
one and two, with other groups producing zero. Mode six looks up the request's
+12 argument using `func_020cb1a0`: bits 5..8 of its +0x24 word select either
the input group (values 2..4), the swapped group (0, 1, 5, 6), or zero (others).
An absent entry uses the swapped group. Passes the low flags byte as selector
mode and inverted flag bits 15/14 as the fourth/fifth arguments to 0204ecc8.
Provider entry storage and the request are borrowed.

## func_0204ecc8 — 924 bytes — 100%

Dispatches modes 1..23. Modes 1/2 use direct providers; 3..6 collect extrema;
7..10 and 13..23 collect callback-filtered candidates. Mode 11 selects the
supplied ID; mode 12 uses the group/ID provider. Empty or unsupported selection
falls back to `func_020b0e08`. Otherwise `func_02050074(0, count - 1)` chooses a
candidate. The fourth/fifth arguments are unused in this original function.
The original stack has a six-ID candidate array, even though the collectors
scan ten slots; callers/data must constrain accepted candidates accordingly.
No bounds expansion or behavioural change was introduced.

## Hard list

- `func_0204e9e4`: 97.80%; count/index/object register allocation. Human scratch:
  `tools/decompme.py`, platform `nds_arm9`.
- `func_0204eaac`: 98.33%; same allocation issue. Human scratch:
  `tools/decompme.py`, platform `nds_arm9`.
