# src/CaveArea.c

## M1-T971 verified functions

All eight functions match the delinked ARM object at 100%. Contracts below follow
instructions at the named original addresses; neutral names are retained where
no semantic evidence supports a stronger name. Pointer inputs require valid,
writable storage covering the accessed fields.

- `CaveArea_Unk_0ed354` (0x020ed354, 16 bytes): calls `func_0205bb68`
  twice without preparing arguments. No semantic claim is made about the helper.
- `CaveArea_Unk_0ec278` (0x020ec278, 20 bytes): writes byte 2 at work
  offset 0xc8 and word 1 at offset 0x160. Takes a typed partial work layout.
- `CaveArea_Unk_0ed3b4` (0x020ed3b4, 24 bytes): clears words 0 and 2,
  writes 16 to word 3, and preserves word 1 of a four-word record.
- `CaveArea_Unk_0eda18` (0x020eda18, 32 bytes): obtains table (0x25, 0)
  through `func_020445f4`, passes it and the input index to `func_0204fed8`,
  and discards the result. The table pointer agrees with the callee's C definition.
- `CaveArea_Unk_0ed26c` (0x020ed26c, 36 bytes): returns immediately if
  work word 0x124 is zero; otherwise calls `func_0205bb68` and clears the word.
- `CaveArea_InitParams` (0x020ed60c, 40 bytes): initializes three float
  slots to 96, 8, and 0, then writes integer 16 at byte offset 12. The buffer
  requires 16 writable bytes; the final slot is an integer, not a float.
- `CaveArea_AllocBuf` (0x020ed1a8, 44 bytes): calls `func_0205ba98` with
  size 0x4000, alignment 0x200, `data_02150d6c`, and line 0x5a1, storing
  the returned handle at work offset 0x80. These arguments support the existing
  allocation name; allocator ownership policy remains outside this helper.
- `CaveArea_Unk_0ed3cc` (0x020ed3cc, 48 bytes): adds 0.6f to a float
  and clears it when the result is at least 32.0f. ARM relocations to `_fadd`
  and `_fgeq` establish floating-point arithmetic and comparison.

No hard-list entries remain for M1-T971. The source already contained matching
bodies; this task adds explicit parameter contracts and evidence comments while
preserving their generated instructions. No behavioral tests were added because
the card exempts them and exact object comparison is the acceptance oracle.

## Not done in M1-T972
- `CaveArea_Unk_0ed9e8`
- `CaveArea_Unk_0edb4c`
- `CaveArea_Unk_0ed364`
- `func_020eb7e0`
- `func_020ec440`
- `func_020ec4a8`
- `func_020edad8`
- `CaveArea_LoadAreaLayout`

## Not done in M1-T973
- `func_020ed768`
- `func_020ecb88`
- `func_020eda38`
- `func_020ec28c`
- `func_020eba60`
- `func_020ed290`
- `func_020ecf20`
- `func_020edb94`

## Not done in M1-T974
- `func_020ed800`
- `func_020ed8f4`
- `func_020ec330`
- `func_020ed634`
- `func_020ecfe8`
- `func_020ec514`
- `func_020ed3fc`
- `func_020eb83c`
