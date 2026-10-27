# CRI unit 0207a8d0

The preceding card reconstructed eight small entry points in the CRI translation unit that
spans 0x0207a8d0..0x0207adc4. The repository and the known public CRI/ADX
Nintendo DS reconstructions were searched first; no matching public source was
found, so the functions are written from their delinked ARM instruction
evidence. The unit stays linked from the delink until a human marks it
`complete` in `config/arm9/delinks.txt`; the remaining functions of the unit
belong to the follow-up cards.

The private work-area view in `libs/CRI/cri_0207a8d0.c` exposes only offsets
established by these instructions: the state word at 4, the released object
pointer at 8, the result words at 0x90/0x94 and the boolean flag at 0xac.
`func_0207a96c` is called from `func_0207ca10` with the offset-4 handle of the
CRI work record in `libs/CRI/cri_0207c82c.c`, which confirms that offset 8 here
belongs to a released child object. No string or caller evidence names the
individual entry points, so the linker-visible names stay neutral.

## Evidence and interpretation

| Function | Original evidence and behavior | Match |
| --- | --- | --- |
| `func_0207a8d0` | Stores the normalized truth value at offset 0xac (`str r1,[r0,#172]`). The original materialises zero first (`cmp r1,#0; moveq r1,#0; movne r1,#1`), so the equality-first `if`/`else` form is used; the ternary form emits the two moves in the opposite order. | 100% |
| `func_0207a8e4` | `ldr r0,[r0,#4]`: returns the state word at offset 4. | 100% |
| `func_0207a958` | Loads offset 4 and stores 1 back only through the equality predicate (`cmp r1,#0; moveq r1,#1; streq r1,[r0,#4]`), leaving non-zero states untouched. | 100% |
| `func_0207a96c` | Releases the offset-8 object with `func_0208095c` and then clears offset 4 (`ldr r0,[r4,#8]; bl; mov r0,#0; str r0,[r4,#4]`). The state clear follows the release call. | 100% |
| `func_0207a9b4` | `ldr r0,[r0,#148]`: returns the result word at offset 0x94. | 100% |
| `func_0207a9bc` | `ldr r0,[r0,#144]`: returns the result word at offset 0x90. | 100% |
| `func_0207ab50` | Signed halfword copy (`ldrsh r3,[r1],#2; strh r3,[r0],#2`). A non-positive count exits before the loop, and the remaining loop is a do-while (`sub r2,#1; cmp r2,#0; bgt`). | 100% |
| `func_0207aba8` | Tail-calls `func_0207ab50` with r0 unchanged, r1 set to `r0 + r1*2` and r2 moved from r3 (`ldr ip,=func_0207ab50; mov r2,r3; add r1,r0,r1,lsl #1; bx ip`). It shifts one halfword row left, copying from `base + start` onto `base`; the third argument is unused by this half of the pair. | 100% |

## Validation

The build and objdiff match gate passed: all eight reconstructed functions report
100%. The checksum gate reports all artifacts byte-identical to the original.
Anticheat passed, and all nine existing unit tests passed. No new behavioral
tests are required by this card: exact instruction matching verifies each
implementation.

## M2-T351

A public-source search for CRI ADX Nintendo DS implementations surfaced audio
format decoders, including [libadx](https://github.com/sega-dreamcast/libadx),
but no matching middleware work-state implementation. Reconstruction therefore
uses the delinked ARM object. Names remain neutral because the offsets and
provider calls establish operations, but do not identify CRI API names.

| Function | Original evidence and behavior | Match |
| --- | --- | --- |
| `func_0207a988` | State 3 alone calls child provider 02080988, then clears +0x8c and state. | 100% |
| `func_0207ab70` | Two calls to the existing halfword copy helper, with the second row displaced by the width. Both rows are borrowed. | 100% |
| `func_0207a9c4` | Calls 020808d4 with child, input, count, output + 2*offset and zero, then 0208093c. | Omitted; see hard list |
| `func_0207aa04` | Calls 02080908 with twice the count and two rows separated by +0x64 halfwords, then 0208093c. | 100% |
| `func_0207a8ec` | Stores input +0x48, divides size by signed +0xf or (+0xd / 8) * +0xe according to mode +0x98, then resets progress/results. | Omitted; see hard list |
| `func_0207ac9c` | State 1 waits for child status 0, invokes +0x78 callback and setup, enters state 2; status 3 then triggers result extraction, child notification, +0x80 callback and state 3. | 100% |
| `func_0207ad3c` | Mode 0 calls 0207ac9c, mode 10 calls 02079f0c; optional +0xe8 callback is dispatched afterward. | 100% |
| `func_0207ad7c` | Computes delta from +0x94 minus +0xe0, adds INT_MAX on negative delta, calls +0xe8 with context +0xec and +0xe * (2 * +0x90), then updates +0xe0. | 100% |

The private view now also exposes the instruction-established format bytes,
input/output pointers, row indices and callbacks used by these functions.
Callback contexts and all buffers remain borrowed. The callback at +0xe8
must be present when 0207ad7c is called directly; 0207ad3c checks it first.

## Hard list

- `func_0207a9c4`: reached 75%. Child preservation, arguments, calls and
  stack shape match, but the compiler schedules zero argument materialization
  before the output-base and index loads. Tried separate pointer/index locals,
  a combined output local and register-qualified locals without resolving it.
  Leave linked from the delink; a human can create a decomp.me scratch.
- `func_0207a8ec`: reached 96.30%. Duplicating the input store in both mode
  branches produced the original load/compare/store sequence. Separate result
  assignments produced the original store order. The remaining difference is
  a missing second `mov r0,#0` between +0x74 and +0x90 clears. Tried shared
  reset inlining and alternate word interpretations; no unsupported type is
  retained. Leave linked from the delink for a human scratch.

M2-T351 adds six matching definitions; the two hard functions remain absent.

Validation for M2-T351: match passed for all 14 retained C definitions
(the preceding eight plus six additions). The build, anticheat, all nine
unit tests and byte-identical artifact checksum passed. The eight-function
card target remains incomplete because of the two hard-list entries.


## M2-T352

The public-source search for CRI middleware implementations found format tools
such as [CriCodecs](https://github.com/Youjose/CriCodecs), but no matching child
request/result implementation. Both functions are reconstructed from the original
ARM instructions, retaining neutral linker names because no API-name evidence
was found.

| Function | Original evidence and behavior | Match |
| --- | --- | --- |
| `func_0207aa4c` (260 bytes) | Divides input count +0x4c by +0x50, rounds requested rows +0x70 using width +0x58, calculates padding and capacity bounds from +0x60/+0x68/+0x6c, then submits the minimum bound through 0207aa04 when +0x50 is two or 0207a9c4 otherwise. | 100% |
| `func_0207abbc` (224 bytes) | Gets completed count through 0208099c, converts it using width +0x58 and divisor +0x50, subtracts padding when the requested bound is reached, stores results at +0x90/+0x94, and shifts one or two rows when offset plus output reaches +0x40. | 100% |

The new private fields at +0x40/+0x44 and +0x50/+0x54/+0x58 are signed words,
matching the original signed divisions and comparisons. Divisors must be nonzero;
all arithmetic, buffer ranges and callback/provider lifetimes retain the original
caller contracts. Declaration order and quotient reuse preserve the compiler's
allocation and scheduling; see DEC-039. This card adds no hard-list entries and
leaves the two earlier M2-T351 omissions unchanged.

Validation: both new functions and all retained C definitions pass the match gate.
The full build, anticheat, all nine unit tests and original-image checksum pass.
No new tests are required by this card; exact object matching verifies the new C.
