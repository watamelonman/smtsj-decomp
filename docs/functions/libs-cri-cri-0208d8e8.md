# CRI unit 0208d8e8

This unit reconstructs ten CRI/ADX entry points from the delinked ARM code.
A search of the repository and of the known Nintendo DS CRI/ADX public
reconstructions (the pret/pokeplatinum and zeldaret trees, and the CRI-facing
parts of the NitroSDK already reconstructed here) did not locate matching
source, so every function is written from its instruction and relocation
evidence. The unit stays linked from the delink until a human marks it
`complete` in `config/arm9/delinks.txt`.

The surrounding CRI units identify the provider: `cri_0208d5ac.c` holds the
`RIFF` marker scanner and the ADX string helpers, and the two allocator thunks
here forward to the NitroSDK heap entry points already used elsewhere
(`func_02052ff0` is declared as an allocator and `func_02053000` as its free
counterpart in `libs/NitroSDK/sdk_0205e318.c` and `src/game/unit_020946e0.c`).
No module boundary changed.

| Function | Instruction evidence and contract | Match |
| --- | --- | --- |
| `func_0208d8e8` | Stores the word at `data_02149548 + 8` through the first optional output and the word at `data_02149548 + 0` through the second. Each store has its own `cmp`/`ldrne`/`strne` guard, so a null output is skipped (`0208d8e8..0208d910`). | 100% |
| `func_0208d910` | Offset-12/offset-4 sibling of `func_0208d8e8`: the first output receives `data_02149548 + 12` and the second `data_02149548 + 4`, again null-guarded (`0208d910..0208d938`). | 100% |
| `func_0208d938` | `ldr r0, =data_021750f4; mov r1, #0; str r1, [r0, #292]`: clears the word at `data_021750f4 + 0x124` (`0208d938..0208d94c`). | 100% |
| `func_0208d94c` | `ldr r0, =data_021750f4; ldr r0, [r0, #292]; bx lr`: returns the word at `data_021750f4 + 0x124`, the base that `func_0208d9bc` consumes as a u16 destination (`0208d94c..0208d95c`). | 100% |
| `func_0208d95c` | Copies `count` signed 16-bit samples into the mixer's circular destination. The write position starts as the u16 at object `+0x44` plus the u16 at `+0x34`, reduced once by the signed length at `+0x40`; each store advances it and an equality test wraps it to zero. A non-positive count returns first. Evidence: paired `ldrh` at `+0x44`/`+0x34`, `ldr` length at `+0x40`, `ldrsh`/`strh` sample pairs, and the `ldr r3,[r0,#64]`/`cmp`/`moveq` wrap (`0208d95c..0208d9bc`). | 100% |
| `func_0208d9bc` | Decodes `count` source samples into the stereo halves reported through the fourth argument. The two output words are the word at `data_021750f4 + 0x124` and that base plus `2 *` the length at `+0x40`; the second load is repeated because the first store could alias the global. Each half is `(3 * source[i] ± 2 * history[position]) >> 2`, clamped to `[-32768, 32767]`, and the circular position from `+0x44` is advanced and wrapped at the length then stored back. A non-positive count skips only the decode loop. Evidence: paired `ldrsh`/`strh`, the `cmp`/`movgt`/`cmp`/`movlt` clamp pair, and the `lsl #16`/`lsr #16` position wrap (`0208d9bc..0208daa0`). The caller at 02084384 passes the two output words to `func_0208636c`. | 100% |
| `func_0208daa0` | `ldr ip, =func_02052ff0; bx ip`: tail-forwards its word argument to the CRI heap allocator. `func_0208dad8` calls it with the byte count for a `0x58`-byte record array and stores the result at `data_02175ccc + 8` (`0208daa0..0208daac`). | 100% |
| `func_0208daac` | `ldr ip, =func_02053000; bx ip`: tail-forwards its pointer argument to the matching free entry point (`0208daac..0208dab8`). | 100% |
| `func_0208dab8` | Loads `data_02175ccc + 4`, returns when it is zero (`popeq`), and otherwise calls `func_020795d8` (the sound-system flush); `func_0208dad8` initialises that word to zero (`0208dab8..0208dad8`). | 100% |
| `func_0208dad8` | One-shot initialiser guarded by `data_02175ccc.unk_00`. It disables interrupts with `func_020059d8(1)`, builds a `length`-byte stack VLA of `(u8)(base + i)`, and hands `data_02175cdc`, the length and that buffer to `func_02079374`/`func_02079360` according to the third argument, recording 1/0 in `unk_04`. It publishes the alloc/free hooks in `unk_10`/`unk_14`, allocates two 0x58-byte records through `func_0208daa0`, clears `+4`, `+8`, `+0xc..+0xe`, `+0x50` and `+0x54` in each, sets `unk_00`, stores `1.0f` in `unk_18`, and restores the interrupt state. Both calls also carry 0 in r3, the fourth outgoing argument word. Evidence: the VLA frame (`rsb`/`bic`/`add sp`), the `smulbb 2, 0x58` allocation size, and the `strb`/`str` clear sequence (`0208dad8..0208dc78`). | 100% |

The two 16-byte pairs at `data_02149548` are read only as words by
`func_0208d8e8`/`func_0208d910`. The initialised data there is
`{0x3000, 0x100, data_02149658, data_02149558}`, i.e. two pointer/size pairs for
CRI work areas; the field names stay neutral because no caller establishes
individual names. The word at `data_021750f4 + 0x124` is likewise exposed only
through the clear/get pair and the mixer destination, so it is described rather
than named. `func_0208daa0`/`func_0208daac` keep neutral symbol names because
the allocator's public CRI name is not present in the image; their contract is
established by the allocator/free declarations and the size argument in
`func_0208dad8`.

## Match note

`func_0208d95c` is sensitive to source shape: writing the loop as a `for` with
`i = 0` in the declaration makes mwccarm 2.0/sp1p5 emit `mov r3, #0` where the
original has `mov r3, r5`, and a plain `for` also gains a top-of-loop bound
test. Declaring `i` without an initialiser, assigning `i = 0` after the
position wrap, and using a `while` at the bottom (`do { ... } while (i < count);`)
reproduces the original zero-copy and the rotated loop exactly. The guard is
still `count <= 0`, so the do/while body only runs for a positive count. See
DEC-036.

`func_0208d9bc` keeps the same loop rotation but needs the declaration order
`i`, `dest0`, `dest1`, `position`, `sample` plus a function-scoped
`opt_common_subs off`: with ordinary settings mwccarm assigns the four
loop-carried values to lr/r4/r5/r6 instead of the original r4/r5/r6/lr. See
DEC-037.

`func_0208dad8` uses two distinct loop counters (the byte-copy loop and the
record-clear loop). Reusing one counter makes mwccarm put the record index and
its strength-reduced 0x58 offset in the opposite registers; a separate `j` for
the record loop reproduces r1/r2. The common `mov r3, #0` before the mode
branch is the fourth outgoing argument word of the two
`func_02079374`/`func_02079360` calls, so both prototypes declare it and both
call sites pass 0. Letting propagation remove it drops the function below
100%. See DEC-037.

## Validation

The build and objdiff match gate report all ten C functions defined in
`libs/CRI/cri_0208d8e8.c` at 100%. The checksum gate reports all artifacts
byte-identical to the original. Anticheat passes, and all nine existing unit
tests pass. No new behavioural tests are required by this card: exact
instruction matching verifies each implementation.

## Hard list

None. All ten functions in the delinked range match at 100%.
