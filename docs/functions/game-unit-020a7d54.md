# src/game/unit_020a7d54.c

## M1-T790 — verified at 100% objdiff

All pointers are borrowed. `Unk0a7d54Fields` models only the fields used by
these routines; padding carries no inferred meaning. Evidence below is the
original ARM instruction stream at each address, rather than guessed gameplay
semantics. Neutral names are retained where field purpose is unknown.

- `Unk0a7d54_SetUnkField8` (020a9164, 8 B): stores the second argument
  at +8 (`str r1, [r0, #8]`). Requires a non-null object. This direct field
  access supports the existing descriptive name.
- `Unk0a7d54_Unk_0a9158` (12 B): writes one to word +4 of a non-null object.
- `Unk0a7d54_Unk_0a7eb8` (16 B): writes one to byte +13 and the supplied
  value to word +28. Requires a non-null entry.
- `Unk0a7d54_Unk_0a8648` (16 B): returns word +4, or zero for null.
- `Unk0a7d54_Unk_0a9204` (20 B): returns whether word +32 is nonzero,
  normalized to 0/1. Requires a non-null object.
- `Unk0a7d54_Unk_0a8594` (24 B): forwards owner and key to `FindByKey`;
  passes the resulting entry to `Unk0a7d54_Unk_0a7e8c` when found.
  The two calls and intervening null check establish this behavior.
- `Unk0a7d54_Unk_0a7ec8` (32 B): forwards owner/key to `FindByKey`, saving
  the third argument across the call; applies `Unk0a7d54_Unk_0a7eb8` to
  the returned entry and saved value when found. Missing keys do nothing.
- `Unk0a7d54_HasField8` (020a8608, 32 B): returns zero for null, otherwise
  tests word +8 and normalizes to 0/1. The `ldr [r0, #8]` and conditional
  moves support the existing descriptive name.

No M1-T790 functions remain on the hard list. The pre-existing candidates
already had the expected instruction shapes; the two wrappers needed explicit
argument forwarding to express the original register flow correctly in C.

## M1-T791 — verified at 100% objdiff

These routines share the borrowed `Unk0a7d54Entry` view (40-byte stride) and the
`Unk0a7d54Work` view whose 32-entry table starts at +0x48. Offsets are taken from
the loads/stores in the original instructions; unknown fields keep neutral names.

- `Unk0a7d54_Unk_0a7d54` (020a7d54, 44 B): scans the 32 entry slots for the
  first one whose word +0 is zero and returns it; returns null when all are
  occupied. The `add #0x48`, `add #0x28` per iteration and `cmp #0x20` establish
  the stride and bound.
- `Unk0a7d54_Unk_0a7e64` (020a7e64, 40 B): clears the entry's lifecycle words in
  the original store order: +4, +0, byte +12, +20, +24, +28, +32, then +8.
  Word +16 is not cleared.
- `Unk0a7d54_Unk_0a7e8c` (020a7e8c, 44 B): if word +8 is nonzero, passes it to
  02061424, clears +8, then resets the entry through `Unk0a7d54_Unk_0a7e64`.
  The `ldr [r4, #8]` / `bl` / zero stores establish the sequence.
- `Unk0a7d54_IsField8Is3` (020a8628, 32 B): null-safe predicate; returns true
  only when entry word +8 equals 3. The `ldr [r0, #8]`, `cmp #3` and `movcc`
  sequence supports the name.
- `Unk0a7d54_Unk_0a84a4` (020a84a4, 40 B): walks all 32 entries from work+0x48
  and releases each with `Unk0a7d54_Unk_0a7e8c`.
- `Unk0a7d54_Unk_0a8534` (020a8534, 40 B): identical 32-slot release walk as
  020a84a4; the two functions are emitted separately, so both are kept.
- `Unk0a7d54_Unk_0a8b44` (020a8b44, 44 B): ignores null entries; when
  `Unk0a7d54_IsField8Is3` is true, sets word +8 to 4 and clears word +16.
  The `bl 020a8628` and `str #4` sequence establishes the transition.
- `Unk0a7d54_Unk_0a9390` (020a9390, 40 B): while entry word +0x1c is positive,
  releases one unit through 0205bb68 and decrements it. Non-positive counters
  return immediately, as shown by the `cmp #0` / `pople`.

## M1-T792 — verified at 100% objdiff

The work header view was extended with the words these routines touch: state
+8, predicate +0x20 and the +0x44 word; the gaps keep neutral padding. The
entry stride remains 0x28 and the table starts at work+0x48.

- `Unk0a7d54_Unk_0a8c40` (020a8c40, 44 B): calls 020a0ce4's 020a0dd8 with id
  0x1d and, when it returns nonzero, calls 020a0da4 with 0x52 before
  forwarding the work object to `Unk0a7d54_Unk_0a8b70`. The `mov r0,#29`,
  `mov r0,#82` and the final `bl` in the original establish both constants
  and the forwarding.
- `Unk0a7d54_Unk_0a8ad0` (020a8ad0, 48 B): requires a non-null work pointer
  and nonzero state word +8, then calls 02057e18(31) and 02057ddc(-1) and
  hands the work object to `Unk0a7d54_Unk_0a8500`. The `ldrne [r4,#8]` /
  `cmpne #0` / `popeq` guard and the two BLs support it.
- `Unk0a7d54_AddSlot` (020a91d4, 48 B): sets the activity flag at +0x20 and
  stores the argument in the first zero word of the eight-word array at
  +0x24. The `str #1` to +0x20, the `[r0 + ip*4 + 0x24]` STREQ and the
  `cmp ip,#8` bound are the evidence; a full array leaves the flag set.
- `Unk0a7d54_Unk_0a93b8` (020a93b8, 48 B): caches entry word +0x1c as a signed
  count, returns when it is non-positive, and runs `Unk0a7d54_Unk_0a9390`
  once per count unit. The `ldr r4,[r6,#28]` / `pople` / `cmp r5,r4` sequence
  shows the cached count and loop bound.
- `Unk0a7d54_Unk_0a84cc` (020a84cc, 52 B): walks all 32 entry slots from
  work+0x48 and forwards each occupied entry (word +0 nonzero) to 020a7ee8.
  The LDR/CMP at the loop head, the 0x28 pointer step and `cmp #0x20` bound
  establish the visit condition and stride.
- `Unk0a7d54_Unk_0a8500` (020a8500, 52 B): the same 32-slot occupied-entry walk
  as 020a84cc, but forwards to 020a82f0. The original emits two separate loops,
  so both functions are kept.
- `Unk0a7d54_FindByKey` (020a855c, 56 B): scans the 32 slots for the first
  occupied entry whose byte +12 equals the key and returns the entry pointer;
  returns null when none matches. The `ldrb [r0,#12]` / `cmp r2,r1` and the
  `mov r0,#0` after the bounded loop are the evidence; the return type is now
  `Unk0a7d54Entry *` to match that use.
- `Unk0a7d54_Unk_0a8b70` (020a8b70, 60 B): requires state word +8 nonzero,
  clears word +0x44, then either sets +8 to 11 when the +0x20 predicate is
  true or continues through 020a8bac. The `str` to +0x44, the call to
  `Unk0a7d54_Unk_0a9204` and the `movne #11` / `strne` support it.

## Hard list
None for M1-T792. All eight functions above are at 100% objdiff with the same
instruction bytes as the delinked original.

## Later tasks
M1-T793 owns the remaining large functions (`func_020a7d80`,
`func_020a7ee8`, `func_020a82f0`, `func_020a85ac`, `func_020a8658`,
`func_020a8c6c`, `func_020a8e5c`, `func_020a9218`); they stay as delinked
original code until that card matches them and are not claimed here.
