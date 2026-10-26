# game/unit_0211fc20

The M1-T835 functions are implemented in ARM C. Layouts describe only the
accessed fields; unknown fields retain neutral names. Evidence is the delinked
ARM instruction stream at the function addresses below. The global pointer is
external, so its storage remains owned by the original image.

| Function | Evidence and contract |
| --- | --- |
| `Unk11fc20_Unk_11fc20` | 0211fc20: null-checks `data_02176e7c`, calls 0211fcb0 and stores the result. |
| `Unk11fc20_Unk_11fc48` | 0211fc48: calls 02061424 only for non-null global work. |
| `Unk11fc20_IsState4` | 0211fc68: returns true for absent work or first word equal to 4. |
| `Unk11fc20_Unk_11fc94` | 0211fc94: returns work offset 16, or zero if absent. |
| `Unk11fc20_Clear_data_02176e7c` | 0211fd24: stores zero to the global pointer without a release call. |
| `Unk11fc20_Unk_120650` | 02120650: subtracts 4096 from signed offset 40 and returns whether it is at most 8192. Requires valid work. |
| `Unk11fc20_Unk_12066c` | 0212066c: calls 020a0da4 with 3, clears offset 64, subtracts 4096 from offset 68; at most 4096 clears offset 28 and returns 1, otherwise sets offset 24 to 15 and returns 0. Requires valid work. |
| `Unk11fc20_Unk_120944` | 02120944: counts nonzero words at offset 424 with stride 44 over 32 entries. Requires valid work. |

No module boundary changes. Existing C helpers outside this card are retained. Remaining undefined functions
in this delink unit remain supplied by the original object, per the task card.

## M1-T836

Evidence: delinked ARM instructions at the addresses encoded in the names.

| Function | Evidence and contract |
| --- | --- |
| `Unk11fc20_Unk_12143c` | Reads work +12/+16, submits kind 4 with 0x3000 and a shifted pixel input to 02120bd4. |
| `Unk11fc20_Unk_11fd38` | Initializes offsets 0, 12, 24, 28, 40, 44, 68 and tail-calls 020a0da4(8). |
| `Unk11fc20_Unk_120898` | Adds global +4/+8 and a 64-pixel X bias; forwards six inputs to 02057d54. |
| `Unk11fc20_Unk_120b88` | Shifts four coordinates by 12; forwards remaining inputs unchanged to 02120bd4. |
| `func_02120b30` | Shifts all seven coordinate inputs by 12 before calling 02120bd4. |
| `func_021208dc` | Strict square overlap: centers +12/+16, half-width +40; touching edges return false. |
| `func_02121478` | Calls 020024f8 with negative Y delta and X delta to global +44/+40; unsigned multiply by 0x1680000, rounding and shifts produce the offset for 0212143c (Unk11fc20_Unk_12143c). |
| `func_0211fcb0` | Allocates 0x1fe8 bytes through 020611dc with callbacks 0212034c, 021206a8, 0211fd24; null returns zero, success publishes and initializes the work. |

Six M1-T836 functions match at 100%; two remain supplied by the delinked object.
No tests were added because this card explicitly sets `tests_required = false`;
the original instruction stream and objdiff provide the exact acceptance oracle.

## Hard list

- `func_021208dc`: the strict-overlap C implementation measured 95.19%.
  Instructions and size matched in shape, but register allocation differed.
  Tried reordered extent temporaries and all 720 permutations of the six source
  loads without finding an exact match. Omitted the body; use a decomp.me scratch
  to investigate allocation with the original 104-byte function.
- `func_02121478`: the delta/angle/scaling wrapper measured 83.42%.
  The 64-bit C product emitted extra MLA instructions (120 bytes versus 104).
  Tried signed/unsigned operand types, literal suffixes, and an inline multiply
  helper; none produced the original UMULL chain. Omitted the body; use a
  decomp.me scratch to investigate the compiler multiplication idiom.

