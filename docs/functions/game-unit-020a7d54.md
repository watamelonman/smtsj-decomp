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

## Hard list
- `Unk0a7d54_Unk_0a7e64`: decompiler-derived
- `Unk0a7d54_Unk_0a7d54`: decompiler-derived
- `Unk0a7d54_Unk_0a8b44`: decompiler-derived

## Not done in M1-T791
- `Unk0a7d54_IsField8Is3`
- `Unk0a7d54_Unk_0a84a4`
- `Unk0a7d54_Unk_0a8534`
- `Unk0a7d54_Unk_0a9390`
- `Unk0a7d54_Unk_0a7e8c`
- `Unk0a7d54_Unk_0a8c40`: decompiler-derived
- `Unk0a7d54_Unk_0a84cc`: decompiler-derived
- `Unk0a7d54_Unk_0a8500`: decompiler-derived

## Not done in M1-T792
- `Unk0a7d54_Unk_0a8ad0`
- `Unk0a7d54_AddSlot`
- `Unk0a7d54_Unk_0a93b8`
- `Unk0a7d54_FindByKey`
- `Unk0a7d54_Unk_0a8b70`
- `Unk0a7d54_Unk_0a8bac`: decompiler-derived
- `Unk0a7d54_Unk_0a916c`: decompiler-derived

## Not done in M1-T793
- `Unk0a7d54_Unk_0a8c04`
- `Unk0a7d54_Unk_0a8b00`
- `func_020a85ac`
- `func_020a7d80`
- `func_020a9218`
- `func_020a82f0`
- `Unk0a7d54_Unk_0a7e8c`: decompiler-derived (plain+fix cleanup)
- `Unk0a7d54_Unk_0a84a4`: hand-matched
- `Unk0a7d54_Unk_0a8534`: hand-matched
- `Unk0a7d54_FindByKey`: hand-matched
- `Unk0a7d54_HasField8`: hand-matched
- `Unk0a7d54_IsField8Is3`: hand-matched
- `Unk0a7d54_Unk_0a8ad0`: hand-matched
- `Unk0a7d54_Unk_0a8b00`: hand-matched
- `Unk0a7d54_Unk_0a8b70`: hand-matched
- `Unk0a7d54_Unk_0a8c04`: hand-matched
- `Unk0a7d54_AddSlot`: hand-matched
- `Unk0a7d54_Unk_0a9390`: hand-matched
- `Unk0a7d54_Unk_0a93b8`: hand-matched
