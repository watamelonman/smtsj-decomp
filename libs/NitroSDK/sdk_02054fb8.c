/* Background-priority wrappers; other functions remain in the delinked TU.
 * SDK evidence: https://github.com/ntrtwl/NitroSDK/blob/master/include/nitro/gx/gx_bgcnt.h
 * G2/G2S_SetBG0Priority through SetBG3Priority use this same register update.
 */
#include "libs/NitroSDK/sdk_02003bb4.h"

/* Sets sub engine BG3 priority, preserving the other control bits.
 * Evidence: G2S_SetBG3Priority in the SDK header cited above and
 * the original volatile halfword access to 0x0400100e. Caller supplies 0..3;
 * the original release implementation does not mask or validate the input. */
void func_0205520c(int priority)
{
    volatile u16 *control = (volatile u16 *)0x0400100e;
    *control = (u16)((*control & ~3) | priority);
}

/* Sets sub engine BG2 priority, preserving the other control bits.
 * Evidence: G2S_SetBG2Priority in the SDK header cited above and
 * the original volatile halfword access to 0x0400100c. Caller supplies 0..3;
 * the original release implementation does not mask or validate the input. */
void func_02055228(int priority)
{
    volatile u16 *control = (volatile u16 *)0x0400100c;
    *control = (u16)((*control & ~3) | priority);
}

/* Sets sub engine BG1 priority, preserving the other control bits.
 * Evidence: G2S_SetBG1Priority in the SDK header cited above and
 * the original volatile halfword access to 0x0400100a. Caller supplies 0..3;
 * the original release implementation does not mask or validate the input. */
void func_02055244(int priority)
{
    volatile u16 *control = (volatile u16 *)0x0400100a;
    *control = (u16)((*control & ~3) | priority);
}

/* Sets sub engine BG0 priority, preserving the other control bits.
 * Evidence: G2S_SetBG0Priority in the SDK header cited above and
 * the original volatile halfword access to 0x04001008. Caller supplies 0..3;
 * the original release implementation does not mask or validate the input. */
void func_02055260(int priority)
{
    volatile u16 *control = (volatile u16 *)0x04001008;
    *control = (u16)((*control & ~3) | priority);
}

/* Sets main engine BG3 priority, preserving the other control bits.
 * Evidence: G2_SetBG3Priority in the SDK header cited above and
 * the original volatile halfword access to 0x0400000e. Caller supplies 0..3;
 * the original release implementation does not mask or validate the input. */
void func_0205527c(int priority)
{
    volatile u16 *control = (volatile u16 *)0x0400000e;
    *control = (u16)((*control & ~3) | priority);
}

/* Sets main engine BG2 priority, preserving the other control bits.
 * Evidence: G2_SetBG2Priority in the SDK header cited above and
 * the original volatile halfword access to 0x0400000c. Caller supplies 0..3;
 * the original release implementation does not mask or validate the input. */
void func_02055298(int priority)
{
    volatile u16 *control = (volatile u16 *)0x0400000c;
    *control = (u16)((*control & ~3) | priority);
}

/* Sets main engine BG1 priority, preserving the other control bits.
 * Evidence: G2_SetBG1Priority in the SDK header cited above and
 * the original volatile halfword access to 0x0400000a. Caller supplies 0..3;
 * the original release implementation does not mask or validate the input. */
void func_020552b4(int priority)
{
    volatile u16 *control = (volatile u16 *)0x0400000a;
    *control = (u16)((*control & ~3) | priority);
}

/* Sets main engine BG0 priority, preserving the other control bits.
 * Evidence: G2_SetBG0Priority in the SDK header cited above and
 * the original volatile halfword access to 0x04000008. Caller supplies 0..3;
 * the original release implementation does not mask or validate the input. */
void func_020552d0(int priority)
{
    volatile u16 *control = (volatile u16 *)0x04000008;
    *control = (u16)((*control & ~3) | priority);
}

/* Borrowed callback tables; the original indexed loads establish one int argument.
 * Their providers retain ownership and callers must supply a valid table index. */
extern void (*data_02143ad0[])(int);
extern void (*data_02143af0[])(int);

/* Forwards value through data_02143ad0[index], as shown by the original
 * indexed load and indirect call; the table's higher-level role is unknown. */
void func_020552ec(int index, int value)
{
    data_02143ad0[index](value);
}

/* Enables mosaic for G2S BG3 when enable is nonzero; otherwise clears it.
 * Evidence: G2S_BG3Mosaic in the SDK header above and the original
 * volatile halfword access to 0x0400100e; all other control bits are preserved. */
void func_02055440(int enable)
{
    volatile u16 *control = (volatile u16 *)0x0400100e;
    if (enable) {
        *control |= 0x40;
    } else {
        *control &= ~0x40;
    }
}

/* Enables mosaic for G2S BG2 when enable is nonzero; otherwise clears it.
 * Evidence: G2S_BG2Mosaic in the SDK header above and the original
 * volatile halfword access to 0x0400100c; all other control bits are preserved. */
void func_0205546c(int enable)
{
    volatile u16 *control = (volatile u16 *)0x0400100c;
    if (enable) {
        *control |= 0x40;
    } else {
        *control &= ~0x40;
    }
}

/* Enables mosaic for G2S BG1 when enable is nonzero; otherwise clears it.
 * Evidence: G2S_BG1Mosaic in the SDK header above and the original
 * volatile halfword access to 0x0400100a; all other control bits are preserved. */
void func_02055498(int enable)
{
    volatile u16 *control = (volatile u16 *)0x0400100a;
    if (enable) {
        *control |= 0x40;
    } else {
        *control &= ~0x40;
    }
}

/* Enables mosaic for G2S BG0 when enable is nonzero; otherwise clears it.
 * Evidence: G2S_BG0Mosaic in the SDK header above and the original
 * volatile halfword access to 0x04001008; all other control bits are preserved. */
void func_020554c4(int enable)
{
    volatile u16 *control = (volatile u16 *)0x04001008;
    if (enable) {
        *control |= 0x40;
    } else {
        *control &= ~0x40;
    }
}

/* Enables mosaic for G2 BG3 when enable is nonzero; otherwise clears it.
 * Evidence: G2_BG3Mosaic in the SDK header above and the original
 * volatile halfword access to 0x0400000e; all other control bits are preserved. */
void func_020554f0(int enable)
{
    volatile u16 *control = (volatile u16 *)0x0400000e;
    if (enable) {
        *control |= 0x40;
    } else {
        *control &= ~0x40;
    }
}

/* Enables mosaic for G2 BG2 when enable is nonzero; otherwise clears it.
 * Evidence: G2_BG2Mosaic in the SDK header above and the original
 * volatile halfword access to 0x0400000c; all other control bits are preserved. */
void func_0205551c(int enable)
{
    volatile u16 *control = (volatile u16 *)0x0400000c;
    if (enable) {
        *control |= 0x40;
    } else {
        *control &= ~0x40;
    }
}

/* Forwards value through data_02143af0[index], as shown by the original
 * indexed load and indirect call; callers supply a valid provider-owned slot. */
void func_020555a0(int index, int value)
{
    data_02143af0[index](value);
}

extern void (*data_02143ab0[])(const struct Mtx22 *, s32, s32, s32, s32);

/* G2S_SetBG3Affine: NitroSDK g2.h and MMIO 0x04001030 identify this wrapper.
 * Matrix storage is borrowed Q12; center and position are integer pixels. */
void func_02055308(const struct Mtx22 *matrix, s32 centerX, s32 centerY, s32 x, s32 y)
{
    func_02003d8c(0x04001030, matrix, centerX, centerY, x, y);
}

/* G2S_SetBG2Affine: NitroSDK g2.h and MMIO 0x04001020 identify this wrapper.
 * Matrix storage is borrowed Q12; center and position are integer pixels. */
void func_02055348(const struct Mtx22 *matrix, s32 centerX, s32 centerY, s32 x, s32 y)
{
    func_02003d8c(0x04001020, matrix, centerX, centerY, x, y);
}

/* G2_SetBG3Affine: NitroSDK g2.h and MMIO 0x04000030 identify this wrapper.
 * Matrix storage is borrowed Q12; center and position are integer pixels. */
void func_02055388(const struct Mtx22 *matrix, s32 centerX, s32 centerY, s32 x, s32 y)
{
    func_02003d8c(0x04000030, matrix, centerX, centerY, x, y);
}

/* G2_SetBG2Affine: NitroSDK g2.h and MMIO 0x04000020 identify this wrapper.
 * Matrix storage is borrowed Q12; center and position are integer pixels. */
void func_020553c8(const struct Mtx22 *matrix, s32 centerX, s32 centerY, s32 x, s32 y)
{
    func_02003d8c(0x04000020, matrix, centerX, centerY, x, y);
}

/* Dispatches a borrowed affine matrix and pixel coordinates through the
 * provider-owned table at 0x02143ab0, if the caller's valid slot is nonnull.
 * Evidence: original indexed load, null test and five-argument indirect call. */
void func_02055408(int index, const struct Mtx22 *matrix, s32 centerX,
                   s32 centerY, s32 x, s32 y)
{
    if (data_02143ab0[index])
        data_02143ab0[index](matrix, centerX, centerY, x, y);
}

/* G2_BG1Mosaic: gx_bgcnt.h and MMIO 0x0400000a identify the enable bit.
 * Any nonzero enable sets mosaic; all other control bits are preserved. */
void func_02055548(int enable)
{
    volatile u16 *control = (volatile u16 *)0x0400000a;
    if (enable) {
        *control |= 0x40;
    } else {
        *control &= ~0x40;
    }
}

/* G2_BG0Mosaic: gx_bgcnt.h and MMIO 0x04000008 identify the enable bit.
 * Any nonzero enable sets mosaic; all other control bits are preserved. */
void func_02055574(int enable)
{
    volatile u16 *control = (volatile u16 *)0x04000008;
    if (enable) {
        *control |= 0x40;
    } else {
        *control &= ~0x40;
    }
}
