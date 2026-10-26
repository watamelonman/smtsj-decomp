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

## M1-T972 verified functions

All eight match the delinked ARM object at 100%. Work pointers borrow writable
storage covering the fields described below. Names remain neutral except for the
existing layout loader, whose format strings identify its purpose.

- `CaveArea_Unk_0ed9e8` (0x020ed9e8, 48 bytes): adds 0.5f to the
  float at +0x128, resetting it to zero at 192.0f. Floating-point helper
  relocations establish the arithmetic and comparison.
- `CaveArea_Unk_0edb4c` (0x020edb4c, 72 bytes): compares area word +0xbc
  with signed byte +0x164. On equality, selects 50 or 51 using byte +0xa8;
  otherwise selects area +10 or +16. Forwards the narrowed u16 to the helper.
- `CaveArea_Unk_0ed364` (0x020ed364, 80 bytes): forwards handle +4 and
  buffer +0x80 with an area index. Normal area 5 maps to 8; alternate-set
  areas add 5. The loads and helper call establish this contract.
- `func_020eb7e0` (0x020eb7e0, 92 bytes): initializes descriptor size 360,
  enabled word 1, and six callback pointers from the original literal pool.
  Preserves word +8; requires 36 writable bytes.
- `func_020ec440` (0x020ec440, 104 bytes): invokes two state helpers,
  forwards two area-indexed handles and table values, loads the layout,
  and writes byte +0xca to zero and +0xc8 to four. Valid area indices must
  cover the external tables and work handle storage. Overlapping typed views
  expose the original +0x14/+0x18 loads with their shared eight-byte stride.
- `func_020ec4a8` (0x020ec4a8, 108 bytes): initializes two flag bytes and
  sixteen words in a stack record, sets flag 0x80 and word seven to the
  input, calls the provider with index 15, then passes (16, 0) to its helper.
  The provider borrows the record for the duration of the call.
- `func_020edad8` (0x020edad8, 116 bytes): zeroes a six-word stack record,
  fills its first word with the area selection used by `CaveArea_Unk_0ed364`
  plus one, then forwards the other two inputs and the borrowed record.
- `CaveArea_LoadAreaLayout` (0x020ed1d4, 152 bytes): formats a layout name
  using strings at data_02150d78/94/ac (Cave/Area and cave_privatearmy),
  allocates the buffer, submits the request at +0x68, and sets +0x124 to one.
  The request temporarily points to the stack-backed name during loading.

No hard-list entries remain for M1-T972. Existing bodies for four requested
functions already matched; four missing bodies were reconstructed from ARM
instructions. Exact object comparison is the acceptance oracle; the task card
exempts new behavioral tests.

## M1-T973 verified functions

All eight match the delinked ARM object at 100%. Work and draw-object pointers
borrow writable storage covering the fields named below; no ownership is
transferred.

- `func_020ed768` (0x020ed768, 152 bytes): borrows provider records through
  `func_0205e328(handle, 5, 0)` and `func_0205e318(handle, 43)`, copies work
  coordinates +0x90/+0x94 into their u16 fields, and submits frame
  `(int)work+0x88 - 1` with unit scale, layer 2, and work word +0x104.
- `func_020ecb88` (0x020ecb88, 156 bytes): draws handle +0xc when work byte
  +0xa8 is zero, otherwise handle +0x10; only byte states 2 and 3 at +0xc8
  draw, and both calls use unit scale, layer 6.
- `func_020eda38` (0x020eda38, 160 bytes): returns when the borrowed draw
  object's signed byte +0x40 is nonzero. Otherwise it fills a four-word record
  from the object, selects color 255, submits the row at y+1, then selects the
  caller color and submits the row at y at the given layer.
- `func_020ec28c` (0x020ec28c, 164 bytes): prioritizes device masks 64/128,
  then 32/16 only when `func_02117170` is true, then 1/2, returning selector
  0..5. Mask helpers are queried on device 0.
- `func_020eba60` (0x020eba60, 180 bytes): runs the +0x124 cleanup, releases
  work word +0x84, then releases and clears 23 handles starting at +0xc, word
  +8, and the two handles at +0/+4. Nine no-argument cleanups run before the
  global `data_02176de0` is cleared.
- `func_020ed290` (0x020ed290, 196 bytes): maps the area from
  `func_0211708c` and work byte +0xa8 to provider indices stored at +0x130 and
  +0x134, then forwards both to `Unk05b82c_Unk_0b82c`. Normal areas above 4
  clamp to the 5/6 pair; alternate areas collapse area 8 to index 1.
- `func_020ecf20` (0x020ecf20, 200 bytes): resets signed byte +0x164 to -1 and
  derives a selection index plus byte +0xa8 for mode 0 or 1; other modes do
  nothing further. Mode 0 maps areas to 1..6, optionally advances when
  `func_02117170` is true, and clears +0xa8; mode 1 maps areas 0..8 to 0..4.
  The scoped `opt_lifetimes off` pragma is required: with default lifetime
  splitting the compiler keeps `index` in caller-saved `ip`, while the original
  keeps one `r4` range whose zero initialization is scheduled after the area
  call (see DEC-023).
- `func_020edb94` (0x020edb94, 228 bytes): indexes paired +0/+4 coordinates
  from eight-byte table entries (seven normal, four alternate, rejecting larger
  indices), then selects handle slot 19, 20, or 21 and white, 0xff7b63ff, or
  white by `Unk02ee5c_GetTierFromField70` when the tier is 4, 5, or other.

No hard-list entries remain for M1-T973. Exact object comparison is the
acceptance oracle; the task card exempts behavioral tests.

## Not done in M1-T974
- `func_020ed800`
- `func_020ed8f4`
- `func_020ec330`
- `func_020ed634`
- `func_020ecfe8`
- `func_020ec514`
- `func_020ed3fc`
- `func_020eb83c`
