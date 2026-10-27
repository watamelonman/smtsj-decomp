/* Partial CRI codec work-area view. The offsets come from the original ARM
 * loads and stores in this translation unit (0x0207a8d0..0x0207adc4); the
 * remaining bytes stay opaque until another function establishes them. */
#include "types.h"

typedef struct Cri0207a8d0Work {
    u32 unk_000;
    u32 unk_004;    /* state word read by 0207a8e4 and reset by 0207a96c */
    void *unk_008;  /* object handed to the release helper at 0207a96c */
    u8 unk_00c;
    s8 unk_00d, unk_00e, unk_00f;
    u8 pad_010[0x38];
    void *unk_048;
    s32 unk_04c;
    u8 pad_050[0xc];
    s16 *unk_05c;
    s32 unk_060, unk_064, unk_068, unk_06c, unk_070;
    s32 unk_074;
    void (*unk_078)(void *, s32 *, s32 *, s32 *);
    void *unk_07c;
    void (*unk_080)(void *, u32, u32);
    void *unk_084;
    u32 unk_088, unk_08c;
    u32 unk_090;    /* result word returned by 0207a9bc */
    u32 unk_094;    /* result word returned by 0207a9b4 */
    s16 unk_098;
    u8 pad_09a[0x12];
    u32 unk_0ac;    /* boolean flag written by 0207a8d0 */
    u8 pad_0b0[0x30];
    s32 unk_0e0;
    u32 unk_0e4;
    void (*unk_0e8)(void *, s32, s32);
    void *unk_0ec;
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

/* Provider signatures follow the register arguments in the original calls;
 * child and buffer storage remain borrowed. */
extern void func_02080988(void *child);
extern void func_02080908(void *child, void *input, s32 count, s16 *left, s16 *right);
extern void func_0208093c(void *child);
extern s32 func_020808cc(void *child);
extern void func_020809b8(void *child);
extern void func_0207aa4c(Cri0207a8d0Work *self);
extern void func_0207abbc(Cri0207a8d0Work *self);
extern void func_02079f0c(Cri0207a8d0Work *self);
void func_0207ad7c(Cri0207a8d0Work *self);

/** Clears the completed state and +0x8c word after notifying the child.
 * Evidence: 0207a988 checks state 3 before calling 02080988. */
void func_0207a988(Cri0207a8d0Work *self)
{
    if (self->unk_004 != 3) return;
    func_02080988(self->unk_008);
    self->unk_08c = 0;
    self->unk_004 = 0;
}

/** Copies both caller-owned rows; 0207ab70 makes two halfword-copy calls
 * separated by the supplied width, using the same start and count. */
void func_0207ab70(s16 *base, s32 start, s32 width, s32 count)
{
    func_0207ab50(base, base + start, count);
    func_0207ab50(base + width, base + (width + start), count);
}

/** Supplies two output rows and twice the count to the child. The original
 * 0207aa04 offsets the second row by +0x64 signed halfwords. */
void func_0207aa04(Cri0207a8d0Work *self, s32 count)
{
    s16 *output = self->unk_05c + self->unk_068;
    void *child = self->unk_008;
    func_02080908(child, self->unk_048, count * 2, output, output + self->unk_064);
    func_0208093c(child);
}

/** Advances states 1 and 2 using the child status and borrowed callbacks.
 * Evidence: 0207ac9c calls +0x78 before setup and +0x80 on completion;
 * each callback context and work area must remain live throughout the call. */
void func_0207ac9c(Cri0207a8d0Work *self)
{
    if (self->unk_004 == 1 && func_020808cc(self->unk_008) == 0) {
        self->unk_078(self->unk_07c, &self->unk_068, &self->unk_06c, &self->unk_070);
        func_0207aa4c(self);
        self->unk_004 = 2;
    }
    if (self->unk_004 != 2) return;
    func_020809b8(self->unk_008);
    if (func_020808cc(self->unk_008) != 3) return;
    func_0207abbc(self);
    func_02080988(self->unk_008);
    self->unk_080(self->unk_084, self->unk_094, self->unk_090);
    self->unk_004 = 3;
}

/** Dispatches the +0x98 mode (0 or 10), then the optional progress callback;
 * evidence is the comparisons and +0xe8 null check at 0207ad3c. */
void func_0207ad3c(Cri0207a8d0Work *self)
{
    if (self->unk_098 == 0) func_0207ac9c(self);
    else if (self->unk_098 == 10) func_02079f0c(self);
    if (self->unk_0e8) func_0207ad7c(self);
}

/** Reports progress since +0xe0 and updates that word after the callback.
 * 0207ad7c adds the signed maximum when the delta is negative, and computes
 * the third callback argument from +0x90 halfwords and format byte +0xe. */
void func_0207ad7c(Cri0207a8d0Work *self)
{
    s32 previous = self->unk_0e0;
    s32 current = self->unk_094;
    s32 count = self->unk_090;
    s32 delta = current - previous;
    if (delta < 0) delta = (0x7fffffff - previous) + current;
    self->unk_0e8(self->unk_0ec, delta, self->unk_00e * (count * 2));
    self->unk_0e0 = self->unk_094;
}
