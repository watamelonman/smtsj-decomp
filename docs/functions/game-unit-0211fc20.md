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


## M1-T837

All eight requested functions report 100% in objdiff. The pre-existing
`Unk11fc20_Unk_120a58` body was retained and verified. The other seven bodies
are added in C; no functions from this card remain on the hard list.
Names remain those in the symbol configuration because the broader scene purpose
is not established. Evidence below is the original ARM instruction stream.

| Function | Evidence and contract |
| --- | --- |
| `func_02120cb4` | 02120cb4: increments slot +36, invokes 02120d7c for kind 3, integrates acceleration and velocity, then clears slots beyond the extent-expanded 128 by 192 bounds. Requires a valid 44-byte slot; coordinates are 20.12. |
| `Unk11fc20_Unk_120a58` | 02120a58: scans the global work pools at +72, +1832, +424 and +2536 for selectors 1, 2, 3 and 4, with bounds 8, 16, 32 and 128 respectively. Returns the first inactive borrowed slot or null; selector 0 and invalid selectors return null. Requires initialized global work. |
| `func_02120bd4` | 02120bd4: rejects kind 4 above Y=0xa0000, obtains a free slot, and initializes all eleven words. The signed 64-bit angle product uses 0xb60b60b60b with rounding 0x80000000000 and shift 44, followed by a 16-bit wrap and shift 4. Read-only interleaved signed halfwords at 0212629c supply cosine/sine; speed products shift by 12 and Y velocity is negated. Angle is 20.12 degrees; coordinates, extent, speed and accelerations are 20.12. Exhausted pools produce no writes. |
| `func_02120970` | 02120970: signed quotient/remainder by 10 split work +16 into two groups of rectangles through 02120898. Tens advance X by 5; units advance X by 3 and use the second row only if tens are positive. Requires valid work. |
| `func_021212f4` | 021212f4: inactive slots return immediately. Converts center-minus-extent to pixel coordinates and twice the extent to dimensions; kinds 0–4 select the original five colors. Kind 4 adjusts dimensions and origin during phases 0–7 and 16–23 of its signed 32-tick remainder. Requires valid slot storage. |
| `func_0211fd7c` | 0211fd7c: inactive slots return; extent grows by 4096 every 46 calls until at least 16384. Provider 020537b8 masks 32/16/64/128 determine movement, using 12288 per axis or diagonal scale 0x21f0. Clamps center by extent and submits kind 1 on mask 1. Requires valid slot storage. |
| `func_021206a8` | 021206a8: state 4 returns before provider setup. States 0 and 3 submit transition rectangles using signed `(transition << 6) / 100`; other states draw the counter and four pools in selector order 1/2/3/4. Draws the slot at +28 when the signed countdown remainder modulo 4 is below 2. Requires the full 0x1fe8-byte work storage. |
| `func_0212034c` (deferred; see hard list) | 0212034c: dispatches states 0–4, applies transition decay `value * 90 / 100`, invokes 0211ff14 during state 1 and starts state 2 after tick 880 when pool 3 is empty. Updates all four pools, resolves pool-4/player collisions through 0212066c, then pool-3/pool-1 collisions through 02120650, maintaining work +16. Requires full work storage. |

The private slot/full-work views expose only observed fields and pool boundaries;
provider ownership and module boundaries are unchanged. Separate traversal scopes
retain the original register lifetimes. The trig table is declared const because
these routines only read it; this also preserves the original load scheduling.
No new tests are required by the card: original instructions and objdiff are the
acceptance oracle. Validation includes the full build, unit suite, anticheat,
match gate and image checksum.

## M1-T838

Both requested functions report 100% in objdiff. Names retain the configured
neutral symbols: instruction evidence establishes behavior but not the scene's
broader purpose. No functions from this card remain on the hard list.

| Function | Evidence and contract |
| --- | --- |
| `func_0211ff14` | 0211ff14–02120348: signed switch on work +20 submits two kind-3 requests at ticks 30, 200, 360, 480, 600, 720, 840 and 880. Coordinates, extents, angles, speeds and accelerations follow the original immediate operands and the existing pixel/fixed-point provider contracts. Requires initialized full work storage. |
| `func_02120d7c` | 02120d7c–021212f0: dispatches slot +8 subtypes 1–8 using elapsed ticks at +36 and pixel coordinates derived from +12/+16. Implements timed paired requests, velocity decay, aimed fans, radial requests, randomized acceleration, sine-modulated angles and side-dependent requests. Unknown/zero subtypes have no effects. Requires a valid 44-byte slot; stored positions, velocity and acceleration use 20.12 units. Trig conversion uses the same rounded signed 64-bit arithmetic and read-only interleaved halfword table as 02120bd4. |

No new tests are required by this card; the delinked instructions and objdiff
are the acceptance oracle. No module boundary or provider ownership changes.

### Hard list: `func_0212034c`

The existing controller implementation was removed after the match gate reported
99.97409%. It remains linked from the delinked original, as this project's
unmatched-function mechanism; this TU does not use `INCLUDE_ASM` stubs.
Its observed behavior remains recorded above for a future matching attempt.

The sole instruction difference reported by objdiff is the call to
`Unk11fc20_Unk_120650`: both objects have the same `R_ARM_PC24` relocation
and addend -8. The original's contiguous text section places the callee eight
bytes after a destination inside the controller; objdiff assigns the call an
internal branch destination at 2600. The compiler's separate function sections
do not have that destination. Attempts with `constpool` and file-level IPA
pragmas did not resolve the mismatch and were reverted. A separate experiment
with an explicitly defined code section also retained separate function sections.
A human can investigate the section-layout discrepancy with a decomp.me scratch
using `tools/decompme.py`; no protected configuration or tooling was changed.
