# `game/unit_02090e60.c` functions

Translation unit `.text` range: `0x02090e60` .. `0x020939f0` (Nintendo DS ARM9).
Only `func_020934c8` is currently written in C and matches the delinked original;
the other four remain linked from the original delink object.

## Matched

### `func_020934c8` — 0x020934c8, 240 bytes (100%)

Clears `unk_0353` unconditionally, calls `Unk090e60_Unk_0937a0` with the byte
selected by `unk_02f4` from `unk_0354`, then refreshes twelve `unk_040c`
pointers when `unk_039c != unk_03a0`. It clears their flags and enables entries
below `unk_0398` whose record predicate returns nonzero. Finally, **`unk_03e0`**
gates `Unk06a224_Unk_06adc0(14)` and is cleared before that call; `unk_0353`
does not gate it. No interpretation of helper id 14 is assumed.
Evidence: loads, stores, loop bound and calls in `0x020934c8..0x020935b8`.

All accessed fields now have typed struct members, including the signed byte
at `+0x3e0`. The `unk_0354` array extent is guessed from the next observed
field at `+0x398`. The work parameter and the builder's work parameter are
struct pointers; the builder's group parameter is `u8`. Standalone comparison
and gatecheck both retain the exact match after these changes.

## Hard list (not matched in this attempt)

### `func_020935b8` — 0x020935b8, 488 bytes

Builds the entry display block at `+0xcc`: copies 12 bytes of entry metadata from
the record returned by `func_020a1428`, copies 12 bytes of label data, then
optionally updates the list and forwards the selected pointer to
`func_02069b24`. Closest C reconstruction was 496 bytes vs. 488. The remaining
difference is mwcc register allocation at function entry: the original keeps
`work` in `r4`, `arg1` in `r5` and `arg2` in `r7`, while every C spelling tried
(parameter types, local declaration order, aliases) keeps `arg2` in `r4` and
shifts the whole body. Recommend a decomp.me scratch
(`python3 tools/decompme.py --platform nds_arm9 ...`) to settle the allocation.

### `Unk090e60_Unk_0937a0` — 0x020937a0, 592 bytes

Rebuilds the three list panels (the `+0x114`, `+0x118`, `+0x110`/`+0x11c`
groups): starts a draw list (`func_02063920`), optionally selects each of the 12
entries, calls `func_02061f10` for every panel, and at the end filters the 12
entries against the work area's record ids (`+0x348`/`+0x120`) plus
`Unk02e000_GetRecordFlag1`. Closest C reconstruction was 612 bytes vs. 592. The
original spills the `list` argument to `[sp,#4]` and keeps the loop result in
`r6`; mwcc kept the argument in `r9` in our version, changing the loop register
assignment. Needs a scratch to fix the spill/colouring.

### `Unk090e60_Unk_092624` — 0x02092624, 3748 bytes

Per-state drawing routine for the same screen (state word `+0x390`, 3748
bytes; one jump table). It issues many multi-argument draw calls whose stack
payloads include float `1.0` constants. Ghidra's C collapses those calls to four
arguments with expression arguments, so it compiled to 2344 bytes vs. 3748 —
roughly 350 instructions of stack-argument setup were lost. Reconstructing it
requires reading each call site's `r0-r3` and stack stores from the disassembly
and writing the real prototypes first; the case-by-case follow-up below reconstructs the initial call and shared states.

### `func_02090e60` — 0x02090e60, 6084 bytes

Main per-frame state machine for this screen: 112 branches, one switch over
`+0x390` with cases 0..12 (several share blocks through `goto`), 220 calls and
five local stack arrays used to build event/menu payloads. Ghidra's export is
usable as a skeleton but, like `Unk090e60_Unk_092624`, drops long call-argument
payloads and local variable reuse (e.g. `unaff_r6`, `DAT_` constants); the
generated C is far shorter than the target and would need a case-by-case
disassembly pass. Recommended decomp.me scratch per case, starting with the
`+0x390` dispatch.

## Attempt 2: disassembly-led case trials

These are incomplete experiments, excluded from the production TU. They do
not claim whole-function matches. Both trials used typed padded work structs
and mwcc 2.0/sp1p5 through `tools/hand/cmp.py`, then inspected the generated
object with `arm-none-eabi-objdump -dr`.

### `Unk090e60_Unk_092624`

Reconstructed entry guards (`+0x2f0 != 0`, null `+0x3b0`), initial helper
sequence, and the complete shared states 3/4/7 at `0x02093454..0x020934a0`.
Reading the stack stores at `0x02092664..0x02092684` gives this trial prototype:

```c
void func_0205dee8(int, void *, int, int, int,
                  float, float, int, float, int);
void func_02057d54(int, int, int, int, int, int);
```

The initial call is
`func_0205dee8(1, w->unk_03b0, 1, 0, 0, 1.0f, 1.0f, 0, 1.0f, 2)`.
Its generated setup reproduces the target's six outgoing stack stores in
order, including the three `0x3f800000` constants. This fixes the earlier
four-argument export problem for this call. The shared state block is:

```c
func_02067c88(w->unk_010c);
func_02057524(6);
func_02057fd8();
func_02057e18(24);
func_02057d54(0, 0, 0, 256, 192, 21);
func_02057e18(31);
func_02057534();
```

The partial function compiled to 232 bytes versus 3748; its outgoing frame is
24 bytes versus the target's 76, and the reduced switch folds into comparisons.
The initial call sequence itself agrees, but the absent list loops and states
prevent matching the frame, saved registers and jump table. Next scratch work:
reconstruct states 0/5/6/11 at `0x020926dc`, then states 1/2 at `0x020931f0`,
retaining the recovered full call signatures. Remains on the hard list.

### `func_02090e60`

Reconstructed entry initialization, busy guard, decrement at `+0x43c`, work-area
call and group lookup. Wrote and compiled complete states 5 and 6
(`0x02091df4..0x02091e5c`, `0x02091ec8..0x02091f1c`) and shared states 3/4
(`0x02091e5c..0x02091ec8`). Recovered these trial signatures from the register
arguments at those sites:

```c
void Unk06a224_Unk_06ab64(void *payload);
void Unk118b04_Unk_118e50(int, int);
int func_02118da0(u16);
void func_02118d34(u16, int);
void func_0205e590(int);
```

States 5/6 initialize signed `+0x3f0` from `+0x102` when negative, forwarding
`&work->unk_00cc` to `Unk06a224_Unk_06ab64`, then increment byte `+0x3e7` and
clamp its **stored byte value** to 16. State 5 also clears the CampStatus flag.
States 3/4 clear that flag, call `Unk06a224_Unk_06aa0c`, store -1 at `+0x3f0`,
call `Unk118b04_Unk_118e50(16, 1)`, conditionally call
`func_02118d34(work->unk_02f6, 1)`, set state 7 and call `func_0205e590(0)`.

The partial function compiled to 312 bytes versus 6084. It saves only r4/lr
and has no local frame, versus the target's r3-r11/lr and 272-byte frame.
The unused group/work-area results are optimized away because their consumers
are in missing states. Consequently these isolated cases cannot settle whole
function register allocation. The next scratch must add state 0's branches
at `0x02090f00` and the payload-building states 7/8 before tuning allocation.
Remains on the hard list; no incomplete case implementation was installed.
- `Unk090e60_Unk_0937a0`: rebuilds the four text lists from +0x39c slots and the group ids
- `Unk090e60_Unk_092624`: per-frame draw: frame, scroll bar, row lists, group ids, 24-slot grid by state +0x390
