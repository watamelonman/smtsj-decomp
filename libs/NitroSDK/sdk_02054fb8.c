/* Background-priority wrappers; other functions remain in the delinked TU.
 * SDK evidence: https://github.com/ntrtwl/NitroSDK/blob/master/include/nitro/gx/gx_bgcnt.h
 * G2/G2S_SetBG0Priority through SetBG3Priority use this same register update.
 */
#include "types.h"

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
