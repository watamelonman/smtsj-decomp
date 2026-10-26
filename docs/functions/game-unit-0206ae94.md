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

`Unk06ae94_Unk_06c76c` remains an existing decompiler-derived body outside this card.

## Not done in M1-T996
- `Unk06ae94_Unk_06c854`
- `func_0206c6d8`
- `func_0206c130`
- `func_0206b958`
- `func_0206c938`
- `func_0206bb84`
- `func_0206d3b4`

## Not done in M1-T997
- `func_0206ba4c`
- `func_0206b0f0`
- `func_0206d54c`
- `func_0206d268`
- `func_0206d7f4`
- `func_0206d68c`
- `func_0206ced4`
- `func_0206cd30`
- `Unk06ae94_Unk_06aed4`: hand-matched
- `Unk06ae94_Unk_06aeec`: hand-matched
- `Unk06ae94_SetPair`: hand-matched
- `Unk06ae94_Call_06af04`: hand-matched
- `Unk06ae94_Unk_06c0b0`: hand-matched
- `Unk06ae94_CompareU32`: hand-matched
- `Unk06ae94_Call_06c130`: hand-matched
- `Unk06ae94_Unk_06c8f8`: hand-matched
- `Unk06ae94_Call_06c938`: hand-matched
- `Unk06ae94_Unk_06b8e4`: hand-matched
- `Unk06ae94_Unk_06c854`: hand-matched
- `Unk06ae94_Unk_06d4e8`: hand-matched
