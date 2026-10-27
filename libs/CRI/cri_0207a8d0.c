/* Partial CRI codec work-area view. The offsets come from the original ARM
 * loads and stores in this translation unit (0x0207a8d0..0x0207adc4); the
 * remaining bytes stay opaque until another function establishes them. */
#include "types.h"

typedef struct Cri0207a8d0Work {
    u32 unk_000;
    u32 unk_004;    /* state word read by 0207a8e4 and reset by 0207a96c */
    void *unk_008;  /* object handed to the release helper at 0207a96c */
    u8 pad_00c[0x84];
    u32 unk_090;    /* result word returned by 0207a9bc */
    u32 unk_094;    /* result word returned by 0207a9b4 */
    u8 pad_098[0x14];
    u32 unk_0ac;    /* boolean flag written by 0207a8d0 */
} Cri0207a8d0Work;

/* Releases the object stored at offset 8; the helper is defined in the
 * neighbouring CRI unit at 0x0208095c and owns the object during teardown. */
extern void func_0208095c(void *object);

/** Stores the caller's truth value as the work-area flag at offset 0xac. The
 * original compares r1 with zero and materialises either 0 or 1 (0207a8d0:
 * `cmp r1,#0; moveq r1,#0; movne r1,#1; str r1,[r0,#172]`). The work area is
 * caller-owned; the function stores but takes no ownership. */
void func_0207a8d0(Cri0207a8d0Work *self, s32 value)
{
    if (value == 0) {
        self->unk_0ac = 0;
    } else {
        self->unk_0ac = 1;
    }
}

/** Returns the work-area state word at offset 4 (0207a8e4: `ldr r0,[r0,#4]`).
 * The word is written by 0207a958 and 0207a96c and consumed by the state
 * machine in the neighbouring routines. */
u32 func_0207a8e4(Cri0207a8d0Work *self)
{
    return self->unk_004;
}

/** Starts the state machine by moving a zero state word to 1. The original
 * loads offset 4, and only predicated on equality stores 1 back
 * (`0207a958..0207a968`: `moveq r1,#1; streq r1,[r0,#4]`), so an already
 * non-zero state is left untouched. */
void func_0207a958(Cri0207a8d0Work *self)
{
    if (self->unk_004 == 0) self->unk_004 = 1;
}

/** Releases the offset-8 object and returns the work area to state zero. The
 * original loads offset 8 first, calls func_0208095c, then stores zero at
 * offset 4 (`0207a96c..0207a984`). The work area stays caller-owned. */
void func_0207a96c(Cri0207a8d0Work *self)
{
    func_0208095c(self->unk_008);
    self->unk_004 = 0;
}

/** Returns the result word at offset 0x94 (0207a9b4: `ldr r0,[r0,#148]`).
 * The word is cleared by 0207a94c and filled by the decode paths. */
u32 func_0207a9b4(Cri0207a8d0Work *self)
{
    return self->unk_094;
}

/** Returns the result word at offset 0x90 (0207a9bc: `ldr r0,[r0,#144]`).
 * The word is cleared by 0207a944 and filled by the decode paths. */
u32 func_0207a9bc(Cri0207a8d0Work *self)
{
    return self->unk_090;
}

/** Copies `count` signed halfwords from `source` to `destination`. The original
 * is a signed halfword post-increment loop that exits immediately for
 * non-positive counts and runs do-while otherwise (`0207ab50..0207ab6c`:
 * `cmp r2,#0; bxle lr; ldrsh r3,[r1],#2; ...; bgt`). Both buffers are
 * caller-owned and must hold `count` halfwords. */
void func_0207ab50(s16 *destination, const s16 *source, s32 count)
{
    while (count > 0) {
        *destination++ = *source++;
        count--;
    }
}

/** Shifts one halfword row left: copies `count` halfwords from `base + start`
 * onto `base`. The original tail-calls func_0207ab50 with the base in r0, the
 * offset source in r1 and the count moved from r3 into r2 (`0207aba8:
 * `add r1,r0,r1,lsl #1; mov r2,r3; bx ip`); the width argument is not used by
 * this half of the paired shift helper. `base` is caller-owned and must hold
 * `start + count` halfwords. */
void func_0207aba8(s16 *base, s32 start, s32 width, s32 count)
{
    func_0207ab50(base, base + start, count);
}
