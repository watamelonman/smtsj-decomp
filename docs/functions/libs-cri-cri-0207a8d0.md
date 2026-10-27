# CRI unit 0207a8d0

This card reconstructs eight small entry points in the CRI translation unit that
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

## Hard list

None for this card. All eight functions are reconstructed in C. The rest of the
translation unit is scheduled by the follow-up cards; it has not been given up
on here.
