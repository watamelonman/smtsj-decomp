# game/unit_020b23bc

The existing `func_` symbols are retained because the domain purpose is not
established. Work and cell views are borrowed; their backing allocations belong
to the caller. The cell storage is an opaque span, not an inferred element count.

## func_020b23bc — matched

- Address: `0x020b23bc`; size: 84 bytes; ARM.
- Contract: accepts a work pointer with cell storage at `+0x5508` and signed
  coordinates at `+0x7482/+0x7483`. Returns 0 without changing work unless the
  selected cell's signed tag equals 2. For tag 2, clears `+0x7480`, calls
  `func_02034dd0()` and `Unk118b04_Unk_118e50(7, 1)`, then returns 1.
- Evidence: coordinate loads and call to `Unk0a6174_Unk_0a6a88`, comparison of
  the returned cell's first byte, and the subsequent store/calls in the original.
- Validation: standalone relocation-aware byte comparison and objdiff: 100%.

## func_020b2410 — hard list, original retained

- Address: `0x020b2410`; size: 1236 bytes; ARM.
- Observed contract: work-pointer state dispatcher returning a completion flag.
  Reads signed state at `+0x7481` (states 0..5 and 100), coordinates at
  `+0x7482/+0x7483`, and a timer at `+0x7484`. Looks up the current cell and
  its associated record, controls image callbacks and dialogue-like callbacks,
  updates the record, and writes the root's second word on completion.
  These operations alone do not establish a safe descriptive function name.
- Attempt: translated the complete dispatcher with typed work, 88-byte entry,
  associated-record, area and root views. The candidate had the exact target
  size and reached **98.71% objdiff**. The remaining differences were two
  image-load/branch instruction-order pairs: at `0x020b24e8` and `0x020b2894`
  the original loads the image halfword before branching; the direct C candidate
  branches first and then loads it. The other instructions matched.
- Tried direct nested conditionals, explicit image/index/predicate locals,
  signed and unsigned local types, inline selection helpers with reordered
  arguments, a switch predicate, inverted branches, and halfword casts. Locals
  moved the load ahead of the comparison and changed register allocation;
  direct conditionals retained the two scheduling differences.
- The nonmatching definition is omitted. This DS project retains the delinked
  original automatically for omitted functions; no `INCLUDE_ASM` is added.
  A human can create a scratch with
  `python3 tools/decompme.py scratch func_020b2410 --write /tmp/unit020b2410`.
