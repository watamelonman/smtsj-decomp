# src/game/unit_0206ae94.c

## M1-T994: verified matching functions

All eight functions below match the original ARM instructions at 100% objdiff.
Evidence is the instruction stream at the listed addresses, not inferred game semantics.
Pointers must reference valid objects; no ownership is transferred.

| Function | Address / size | Contract and evidence |
| --- | --- | --- |
| `Unk06ae94_GetUnkField4c` | 0x0206c764 / 8 B | Returns the word at +0x4c, as shown by the single load. |
| `Unk06ae94_Unk_06aed4` | 0x0206aed4 / 24 B | Resolves `(2, id)` through `func_020445d0`, then forwards the handle to `func_0204fde0`. Callee meanings remain unknown. |
| `Unk06ae94_Unk_06aeec` | 0x0206aeec / 24 B | Resolves `(2, id)` through `func_020445d0`, then forwards the handle to `func_0204fe18`. Callee meanings remain unknown. |
| `Unk06ae94_SetPair` | 0x0206c8c8 / 24 B | Signed comparison clamps indices >= 2 to 1, then stores two words at +0x158/+0x15c with stride 8. Caller must supply a nonnegative index. |
| `Unk06ae94_Unk_06c8e0` | 0x0206c8e0 / 24 B | ORs bit 2 into +0x34; stores arg2 at +0x3c and arg1 at +0x40. Field meanings remain unknown. |
| `Unk06ae94_Unk_06ae94` | 0x0206ae94 / 32 B | Calls `func_02052d34` only when the input mask overlaps the word at `data_021457e0`. |
| `Unk06ae94_Unk_06aeb4` | 0x0206aeb4 / 32 B | Calls `func_02052d58` under the same mask condition. |
| `Unk06ae94_CompareU32` | 0x0206c0d4 / 32 B | Unsigned compare of two pointed-to words returns -1, 0, or 1. Carry/HI branches establish unsigned ordering. |

## Hard list

None for M1-T994. The existing bodies already matched; this task verifies them and
adds typed declarations and evidence-based contracts. Other task entries below are
retained as historical notes rather than M1-T994 acceptance results.

## M1-T995: verified matching functions

These seven functions match at 100% objdiff. Contracts below follow the original
ARM loads, stores and calls; provider semantics remain unknown.

| Function | Address / size | Contract and evidence |
| --- | --- | --- |
| `Unk06ae94_Unk_06c0b0` | 0x0206c0b0 / 36 B | Accepts a null address; otherwise clears the optional pointed-to word at +0x360, then calls `func_02061424`. The provider owns the object. |
| `Unk06ae94_Call_06c938` | 0x0206ca30 / 52 B | Forwards seven integer arguments, inserting a zero sixth argument. Stack loads/stores establish the argument order. |
| `Unk06ae94_Call_06c130` | 0x0206c0f4 / 60 B | Forwards eight integer arguments, inserting a zero seventh argument. |
| `Unk06ae94_Unk_06c8f8` | 0x0206c8f8 / 64 B | Queries provider indices 0 through 5; returns 1 on the first result overlapping 0x1fffe000, otherwise 0. |
| `Unk06ae94_Call_06af04` | 0x0206b0ac / 68 B | Forwards nine arguments, inserting a zero seventh argument. The original byte load establishes the seventh input's `u8` type. |
| `Unk06ae94_Unk_06d4e8` | 0x0206d4e8 / 100 B | Accepts null; otherwise releases 50 handles at +0x260, clears seven observed state words and the optional backlink at +0x250, then releases the object. |
| `Unk06ae94_Unk_06b8e4` | 0x0206b8e4 / 116 B | Transforms four borrowed 20-byte records using `func_02000f10`. Signed halfwords at offsets 0/2/4 widen to words and the results truncate back to halfwords. The matrix is borrowed. |

### M1-T995 hard list

- `func_0206ca64` (0x0206ca64 / 108 B): left undefined in C, retaining the
  delinked original. It reads the signed cursor at +0x258, returns if negative,
  and advances modulo 50 across null handles at +0x260 until reaching the stop
  cursor at +0x25c or a nonnull handle. A structured `while` loop using
  `i = (o->unk_258 + 1) % 50; o->unk_258 = i;` produces the exact size and
  register allocation, but schedules `lsr r1, lr, #31` before
  `smull r2, r4, ip, lr`; the original orders these two instructions oppositely.
  Objdiff reports 92.59%. Explicit quotient/subtraction forms change register
  allocation; separate increment/temporary forms retain the ordering difference.
  Scoped lifetime, propagation, common-subexpression, strength-reduction,
  loop-invariant, conditional and scheduling options did not resolve it.
  A human can use `tools/decompme.py` for further compiler investigation.

## M1-T996: verified matching functions

All eight functions below match the original ARM instructions at 100% objdiff
(verified with the linked objdiff report, which also resolves the ARM-to-Thumb
call in `func_0206d3b4`). Contracts follow the original loads, stores, table
lookups and calls; provider semantics remain unknown.

| Function | Address / size | Contract and evidence |
| --- | --- | --- |
| `Unk06ae94_Unk_06c854` | 0x0206c854 / 116 B | Resolves a provider entry from `(p[48], *(u32 *)(p + 4))`, masks its `+8` word with `0xfc0`, maps `0x40/0x80/0x100` to `8/5/3`, and forwards the shared global plus entry byte `+20` to `Unk0946e0_Unk_094704`. Null entry and zero mask return early. |
| `func_0206c6d8` | 0x0206c6d8 / 140 B | Adds three integer deltas to `+0x140/+0x144/+0x148`, scales four float slots at `+0x58` with stride 68, and scales the integer at `+0x360` through `_fflt`/`_fmul`/`_ffix`. Volatile parameters reproduce the original spilled argument reads. |
| `func_0206c130` | 0x0206c130 / 212 B | Allocates a 360-byte object through `func_020611dc` with `func_0206c204` as the update callback, clears it, fills fields from the nine arguments, sets a caller flag to 1, and writes two `-1` sentinels at `+0x15c/+0x164`. Returns the object. |
| `Unk06ae94_Unk_06c76c` | 0x0206c76c / 232 B | Null-tolerantly releases four handle arrays whose counts live at `+0xc/+0x10/+0x18/+0x14` (slots `+0x50/+0x90/+0x110/+0xd0`), then clears the counts, the owned pointer at `+0`, and the backlink. |
| `func_0206b958` | 0x0206b958 / 244 B | Initialises a 20-byte buffer through `func_0206bca8`, advances the positions at `+0x318/+0x120` by the 20.12 velocity at `+0x320`, and negates the velocity when the projected position leaves the `+-limit` at `+0x31c`, using the original rounded Q12 multiply. |
| `func_0206c938` | 0x0206c938 / 248 B | Allocates an 812-byte object through `func_020611dc` with `func_0206cad0` as the update callback, clears it, copies 308/12/176-byte argument blocks into `+0x64/+0x54/+0x198`, initialises the animation state through `func_02071068`, and mirrors the signed halfword at `+0x32a` into `+0x328`. Returns the object. |
| `func_0206bb84` | 0x0206bb84 / 292 B | Proceeds only when state `+0x1d8 == 1`; derives the angle at `+0xc` from `+-90 / (s32(+0x328) >> 12)` with quadrant offsets from `+0x124/+0x120`. When mode `+0x130 == 1` it derives `+0x4` the same way from `+0x124/+0x128`. |
| `func_0206d3b4` | 0x0206d3b4 / 308 B | Normalises `s16(+0x16e) - +0x344` into `[0,360)`, looks up two neighbouring entries in the sin table at `data_0212629c`, rotates `(offset + +0x348, 0, 0)` through `func_02000edc`/`func_02000f10`, applies the by-value three-angle record through `func_0206d268`, copies the result with `func_020086bc`, and stores it at `+0x120..+0x128`. |

### M1-T996 hard list

None. All eight bodies match at 100% objdiff. `func_0206d3b4` needs the
linked objdiff report (not standalone instruction comparison) because its call
to Thumb `func_02000edc` is an ARM-to-Thumb `blx` in the ROM.

## M1-T997: verified matching functions

Six functions match the original ARM instructions at 100% in the linked objdiff
report. Contracts follow the original loads, stores and calls; provider
semantics remain unknown where noted.

| Function | Address / size | Contract and evidence |
| --- | --- | --- |
| `func_0206b0f0` | 0x0206b0f0 / 320 B | Per-frame updater. The countdown at `+0x2b8` matching the word at `+0` clears itself, decrements the signed halfword at `+0x3b6`, and either releases through `Unk06ae94_Unk_06c0b0` or calls `func_0206fc24` when the countdown reaches zero. Otherwise it advances the animation through `Unk06fb70_Unk_06feb4`, calls `func_0206b958` when `+0x35c` is nonzero, clamps the byte at `+0x3b4` to 31, packs the shifted words at `+0x1e4/+0x1e8/+0x1ec` into the four spots at `+0x374/+0x388/+0x39c/+0x3b0`, emits a rectangle from the halfwords at `src+40/+42` through `func_020599c4`, and increments `+0x2b8`. |
| `func_0206cd30` | 0x0206cd30 / 420 B | Advances the three animation channel groups at `+0x198` through `func_020703b4`, `Unk06fb70_Unk_070500` and `Unk06fb70_Unk_07057c`, then walks the child ring from the signed cursor at `+0x258` to the end marker at `+0x25c`, wrapping with `% 50`. A nonnull child at `+0x260[i]` whose `+0x358` matches `+0x24c` receives `+0x340/+0x344` from the shifted words at `+0x4/+0x8`, an angle from `func_0200219c(+0x1ac << 12, 409600)`, a three-angle rotation through `func_0206d3b4`, and the deltas at `+0x54/+0x58/+0x5c`. |
| `func_0206ced4` | 0x0206ced4 / 364 B | Derives an angle either from the rotating global counter `data_0216b9bc * -45` (wrapping after eight steps) or from `func_02050088(1, 0, 8) * -45`, stores it at `+0x16e`, normalises `angle - +0x344` into `[0,360)`, and rotates `(offset + +0x348, 0, 0)` through `func_02000edc`/`func_02000f10`, storing the result at `+0x120..+0x128`. |
| `func_0206d54c` | 0x0206d54c / 320 B | Computes the unsigned ratio `value / scale` (mode 1 negates it, mode 2 takes the sign from `(s8)func_02050088(1,0,1)`) and converts the float to the original 20.12-style integer with the `+0.5/-0.5` away-from-zero bias. |
| `func_0206d68c` | 0x0206d68c / 360 B | Same signed conversion as `func_0206d54c`, but the numerator is `func_02050088(1, 0, value)` (a random value in `[0, value]`); modes 1 and 2 negate. Callers pass `(2, value, 100)` and add the result to 20.12 positions. |
| `func_0206d7f4` | 0x0206d7f4 / 348 B | Same signed conversion, with the numerator `func_02050088(1, low, high)` (a random value in `[low, high]`); modes 1 and 2 negate. |

### M1-T997 hard list

Both functions were left as the delinked original ARM; defining them in C moved
the rest of this TU's objdiff unit even when the bodies were otherwise exact.

- `func_0206ba4c` (0x0206ba4c / 312 B): takes the vector pointer plus a by-value
  three-angle record (`r1..r3`) and applies the X/Y/Z rotation helpers
  `func_02000ec0`/`edc`/`ef8`. The rotation pipeline, table indexing, matrix and
  result stores all match; only the initial vector copy differs. The ROM copies
  the three words with one `ldm rX,{r3,r4,ip}` plus three `str` instructions
  (four instructions, 312 B). C array or struct copies compile to either three
  `ldr` plus three `str` (six instructions, 320 B) or `ldm` plus `stm` (two
  instructions, 304 B). Array/struct/union/volatile/packed destinations,
  aggregate initialisers, pointer and temporary copies, all assignment and
  declaration orders, helper inlining, `restrict`, and the available
  optimisation levels did not produce the four-instruction form.
- `func_0206d268` (0x0206d268 / 332 B): identical three-rotation body taking the
  vector pointer and three angle fields, returning a pointer to the local
  result buffer. It has the same initial-copy blocker as `func_0206ba4c`: the
  ROM uses four instructions, while C copies give six or two. All later code
  matches once the copy length is accounted for. The existing `func_0206d3b4`
  caller continues to use the delinked original.

A human can open a decomp.me scratch with `tools/decompme.py` for the copy
codegen (`ldm` plus individual stores) if a different source idiom is desired.

## M1-T998: render constructor and axis angles

Two functions match the original ARM instructions at 100% in the linked objdiff
report. The remaining five stay as the delinked original ARM so the unit still
matches; they are listed in the hard list with the blockers observed.

| Function | Address / size | Contract and evidence |
| --- | --- | --- |
| `func_0206af04` | 0x0206af04 / 424 B | Allocates a 0x3bc-byte render object through `func_020611dc` with `func_0206b0f0` as updater and `func_0206b230` in the callback slot selected by the final countdown argument. Clears it, copies the 0x134-byte source block, copies either 0xb0 bytes from the alternate block or four bytes from its +0xa6 tail, seeds the colour/scale halfwords and words at +0x268..+0x2b4, stores owner/callback/link fields, and mirrors the signed countdown halfword from +0x3b8 to +0x3b6. Returns null only when allocation fails. |
| `func_0206b6e0` | 0x0206b6e0 / 516 B | For each nonzero axis angle, normalises it into `[0,360)`, converts it to the `data_0212629c` sine-pair index, and forwards the pair to `func_02004588` (Y), `func_0200454c` (X) or `func_020045c4` (Z). The inline normaliser reproduces the original signed remainder-by-360 sequence. |

### M1-T998 hard list

The following bodies were left undefined in C, so their delinked ARM remains in
the image. They are candidates for a human decomp.me scratch (`tools/decompme.py`)
or a later card.

- `func_0206b230` (0x0206b230 / 1200 B): hardware-register renderer
  (`0x04000444`, `0x04000448`, `0x0400046c`, `0x04000470`), provider dispatch
  through `0x0206e334`, angle rotation through `func_0206bb84`, `0x0206b6e0`
  and several `0x020045xx` helpers. No C form was committed because matching the
  long predicated/constant-pool sequence would require a source form that also
  preserves the original register allocation.
- `func_0206bca8` (0x0206bca8 / 1032 B): three-way motion state machine on
  `+0x35c`. A direct reconstruction compiled to 992 B at 80.4% direct objdiff:
  the state tests were laid out as `bne` chains instead of the original `beq`
  blocks, and the three angles at `+0x160..+0x168` loaded as three `ldr` rather
  than one `ldm`. Passing them as a by-value three-angle record is the next
  experiment.
- `func_0206c204` (0x0206c204 / 1236 B): per-frame spawner with four 16-slot
  handle tables at `+0x50/+0x90/+0xd0/+0x110` and a four-way jump table. It
  depends on the constructor wrapper and leaves a 0x274-byte stack frame; the
  original callback/stack layout was not reproduced.
- `func_0206cad0` (0x0206cad0 / 608 B): per-frame child spawner. It calls
  `func_0206ca64`, allocates through `Unk06ae94_Call_06af04`, seeds the child
  velocity/angle fields and calls `func_0206cd30`. A direct reconstruction
  compiled to 616 B at 92.3% direct objdiff; the control flow, spawn arguments
  and Q12 child updates matched, but the compiler assigned the loop count,
  cursor and child pointer to different registers than the original.
- `func_0206d040` (0x0206d040 / 552 B): orbit-angle updater plus child-ring
  walk. A direct reconstruction compiled to 536-540 B at 92.1-92.6% direct
  objdiff: the compiler ordered the local `vec0/vec1/vec2/matrix` arrays
  differently from the original stack slots, and cached the child pointer where
  the original reloads `work[+0x260 + i*4]` after each store. The rotation and
  modulo-50 walk themselves matched instruction-for-instruction.
