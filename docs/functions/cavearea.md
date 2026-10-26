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
  and returns its provider record, consumed by `func_020eb83c`. The table
  pointer agrees with the callee's C definition.
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

## M1-T974 verified functions

Seven functions match at 100% in full-TU objdiff. Contracts follow the ARM
loads, stores, calls, and literals at the function addresses; original neutral
symbols are retained. Provider storage is borrowed during draw/selection calls.

- `func_020ed800` (244 bytes): reads the signed count at +0xb0 and selection
  at +0xbc, stopping at signed byte +0x164. Draws the selected marker from
  eight-byte coordinate entries in `data_0213c7a4`, then invokes `func_020edb94`.
- `func_020ed8f4` (244 bytes): identical traversal using `data_0213c760`.
  Both marker functions require storage covering +0x164 and valid table indices.
- `func_020ec330` (272 bytes): state 3 dispatches input selectors 0..5 to
  selection changes, cancellation, or area loading. State 9 chooses state 8
  when +0x12c is nonzero, otherwise submits the selected provider result and
  enters state 11. The second `func_020ec4a8` argument is observed but unused.
- `func_020ed634` (308 bytes): updates a caller-owned sixteen-byte motion
  record. Position decreases by 0.5; the timer decreases by 0.48 above 8 and
  by 1 otherwise. Position/timer thresholds derive integer extents. Signed
  conversions truncate; literal thresholds are 80, 96, 8, and 24.
- `func_020ecfe8` (448 bytes): consumes a kind word followed by a borrowed
  payload. Kind 3 initializes state 0 using payload words +8/+12/+16, or
  completes states 10, 17, and 11. Kind 1 forwards to the provider with zero.
  In state 10, payload flag 8 enables its optional result at +16. Payloads must
  cover the fields accessed for their active state.
- `func_020ed3fc` (528 bytes): obtains mutable provider span/frame records
  for frames 40, 38, and 39, writes halfword extents from float +0x98, and
  submits four draws. The frame-39 extents become zero above 31. Retains
  separate signed/unsigned conversions as established by the runtime calls.
- `func_020eb83c` (548 bytes): creates three parent resources, 23 row
  handles, and nine text entries, then initializes selection, animation and
  state fields through +0x164. Its use of `CaveArea_Unk_0eda18` establishes
  that helper's provider-record return contract; correcting the declaration
  preserves its existing matching machine code.

Behavioral tests are exempt on this card. Object comparison is the acceptance
oracle; full checksum confirms the image still uses the original delinked TU.
No protected configuration or symbol files were changed.

## M1-T974 hard list

- `func_020ec514` (496 bytes): left in the original delink. A readable C
  candidate reproduced both alternate/normal row branches, fixed-point scroll,
  selected-row overlays, sentinel-row providers, and label submissions, but
  full-TU objdiff measured 96%. Standalone comparison showed register allocation
  differences: the row accumulator used r6/r7 instead of r8, the y coordinate
  used r8 instead of r7, and the hoisted white color used r5 instead of r6.
  Tried separate loop guards and do/while layout, local scope/declaration
  ordering, explicit color locals, register hints, and scoped lifetime options.
  None matched, so the candidate was removed. A human can use
  `tools/decompme.py` for a scratch; no public upload was performed.

## M1-T975 verified functions

All three C definitions individually match the delinked ARM object at 100%
(764, 1156 and 1892 bytes respectively). The missing `func_020ec704` definition
was added and verified directly in the compiled object during attempt 2.
Names stay neutral:
callbacks are reached through the six-entry descriptor at 0x020eb824 and no
string, data-table, or caller evidence supports a stronger description.

- `func_020ecc24` (764 bytes): render callback that returns immediately in
  state 0 or 12. Otherwise it configures four row ranges and two background
  strips using the shifted indices at +0x130/+0x134, submits frame 19 at float
  +0x128 offset by -192 and again unshifted, submits frame 18 at the origin,
  then dispatches marker rendering to `func_020ed800` or `func_020ed8f4`
  according to byte +0xa8. `CaveAreaWork` storage must cover those fields.
- `func_020ec704` (1156 bytes): render callback. States 16..18 draw the layout
  object at +0x50 from its origin words +0x14/+0x18 through `func_020eda38`,
  using width entries at +0x138/+0x14c/+0x158 and color 0x26fffcff; states
  7..11 and 16..18 also submit the frame indexed from handle +4. The shared
  tail submits the +0x104-scaled overlay, provider spans/frame, the handle
  pair at +0x14/+0x18 for the current area, and handles +0x44/+0x48. The
  still-delinked row renderer `func_020ec514` is called with the area index.
  Work storage must include the indexed width arrays and live borrowed provider
  objects at +0x50/+0x84. See DEC-025: propagation/common-subexpression settings
  preserve the branch setup and three conditional byte-state comparisons.
  Initial readable C measured 91.30%; indexed array expressions and scoped
  settings reached 99.76%, then local declaration order restored r4/r5 and 100%.
- `func_020ebb14` (1892 bytes): 22-state callback dispatcher. State 1 seeds the
  per-area rows and selects handle +0xc/+0x10 with the table at data_0213c814;
  states 5..8 and 16/18 animate the +0x104/+0x110 floats and row offsets;
  state 12 builds a 16-word request with `func_020bcacc`; states 13..15 drive
  the layout load; states 20/19 handle the reverse transition; state 21
  finishes with a float equality check. The +0x114 scroll uses the explicit
  `func_0200219c` multiply/divide helper observed in the original. Every path
  except the state-21 early return ends in the common animation and 23-handle
  update tail.

No hard-list entries were added for M1-T975. Behavioral tests are exempt on
this card; object comparison is the acceptance oracle and the full checksum
confirms the image still uses the original delinked TU.
