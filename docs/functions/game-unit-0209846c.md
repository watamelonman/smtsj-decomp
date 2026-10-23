# game/unit_0209846c

Both functions retain their original neutral symbols: the accessed offsets establish
mechanics, but do not establish gameplay names. Layout padding represents unknown
fields, not executable data. No module boundary changes were needed.

## func_0209846c

- Signature: `void func_0209846c(u16 *output, const Unk09846cArea *area)`.
- Reads four unsigned halfword IDs at area offsets 0, 2, 4, and 6; resolves each
  nonzero ID through `Unk09974c_Unk_099c60`, skipping null records.
- For slot 1 only, appends nonzero record fields at 0x40, 0x42, and 0x44.
  For every slot, then appends the nonzero field at 0x3e. Stops at six writes.
  The caller owns an output buffer of at least six halfwords; unwritten elements
  are preserved. No count is returned.
- Evidence: ARM loads, loop bounds, and stores at 0x0209846c–0x02098543;
  `Unk096754_Unk_097204` forwards the area getter result as the second argument.
- Validation: exact relocated instruction comparison and objdiff, 100% (216 bytes).

## func_02098544

- Signature: `int func_02098544(int scale)`.
- Reads the global work block and current area. Sums positive signed-halfword
  deficits (area 0x12 minus 0x1c and 0x14 minus 0x1e; entry 0x0a minus 0x1e
  and 0x0c minus 0x20). The second sum has weight three.
- Work entries have stride 0x3c starting at 0x74. The byte at 0x357 bounds
  iteration over signed indices starting at 0x348. Negative indices and null
  computed entry pointers are skipped; valid indices are a caller/state invariant.
- Entry status 1 contributes 300, status 7 contributes 200, and other nonzero
  statuses contribute 100. Area status at 0x6c follows the same rule except
  status 1 contributes nothing. Positive `scale` applies a percentage using
  signed integer arithmetic; nonpositive values leave the sum unscaled.
  The upper result limit is 99,999,999. Arithmetic assumes game-state values
  whose intermediate signed products and sums are representable.
- Evidence: field loads, status branches, and arithmetic at
  0x02098544–0x020986ab. Gameplay interpretation remains unresolved.
- Validation: exact relocated instruction comparison and objdiff, 100% (360 bytes).

## Hard list

None.
