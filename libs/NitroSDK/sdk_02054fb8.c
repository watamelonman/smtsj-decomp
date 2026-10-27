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

