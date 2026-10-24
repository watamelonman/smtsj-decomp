# game/unit_020f0510

All five functions match the original ARM instructions (100% objdiff). Names
remain neutral: control flow and field offsets establish behavior, but do not
establish the game concepts represented by the handles or record fields.
Layouts are local borrowed views, with padding only for observed offsets.

- `func_020f0510(u32 unused, s32 index)` (164 bytes): returns whether an
  indexed action may proceed. Index zero in global state 3 succeeds immediately;
  the global predicate otherwise rejects. An absent indexed record succeeds.
  For a present record, byte +0x22 is a threshold; an additional enabled check
  uses its halfword +0x20. The first incoming argument is unused. Evidence:
  conditional returns and loads at +0x28, +0x22 and +0x20 in the original.
- `func_020f05b4(void *object)` (240 bytes): obtains the object's field +0x10
  and relative index. Field zero with global state 3 dispatches handle updates,
  with separate paths selected by `Unk0e8228_IsField4One`; other inputs pass the
  indexed record to `func_020f7578`. Evidence: original call sequence and the
  constants 30, 1, 2, 3 and 7. The object must support the field/index accessors.
- `Unk0f0510_Unk_0f06a4(void)` (44 bytes): forwards global field +4 to
  `func_020f7d14`, then global field +0x40 to `func_020f7e48` with arguments
  0 and 1. Evidence: original two loads and calls. Global state must exist.
- `Unk0f0510_Unk_0f06d0(void *object)` (36 bytes): forwards the object's
  field +0x10 and global field +0x44 to `Unk0e8228_Unk_0e8d90`. Evidence:
  original accessor call followed by the global handle load. Both borrowed
  objects must exist; the previously implicit object argument is now explicit.
- `func_020f06f4(void *object)` (136 bytes): accepts only global states 9 and
  10. Relative index zero with an enabled global predicate forwards the global
  value through `Unk0ea208_Unk_0ea878`. Otherwise it forwards record halfword
  +0x20 (or zero when absent) to two consumers, then notifies through
  `Unk0fedd4_Unk_0fee38`. Evidence: original state comparisons, record loads,
  and shared final call. The object must support the relative-index accessor.

## Hard list

None.
