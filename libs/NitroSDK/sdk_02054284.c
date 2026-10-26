#include "types.h"

/* Sort comparator for the free-block array used by func_02054294: the original
 * func_02054294 passes this address to the MSL sort routine (func_02013c68)
 * with element size 8, and the body returns the difference of the two blocks'
 * first words (their start offsets). Callers must pass two valid 8-byte
 * records. */
int func_02054284(const void *a, const void *b)
{
    return *(const u32 *)a - *(const u32 *)b;
}

/* NitroSDK GX register wrappers. Evidence: public NitroSDK
 * include/nitro/gx/gx_bgcnt.h, compared with the original ARM instructions and
 * the MMIO literal at each symbol. Callers supply unshifted SDK field values;
 * priority (bits 0-1) and mosaic (bit 6) are preserved and no range checks are
 * performed. */

/* G2S_SetBG3ControlText: gx_bgcnt.h and original MMIO 0x0400100e establish
 * this sub-engine BG3 setter. screenSize/colorMode/screenBase/charBase are
 * unshifted SDK fields; the 16-bit register write truncates the result. */
void func_02054424(u32 screenSize, u32 colorMode, u32 screenBase, u32 charBase)
{
    *(volatile u16 *)0x0400100e = (u16)((*(volatile u16 *)0x0400100e & 0x43)
        | (screenSize << 14) | (colorMode << 7)
        | (screenBase << 8) | (charBase << 2));
}

/* G2S_SetBG2ControlText: gx_bgcnt.h and original MMIO 0x0400100c establish
 * this sub-engine BG2 setter. Parameters and contract match func_02054424. */
void func_02054450(u32 screenSize, u32 colorMode, u32 screenBase, u32 charBase)
{
    *(volatile u16 *)0x0400100c = (u16)((*(volatile u16 *)0x0400100c & 0x43)
        | (screenSize << 14) | (colorMode << 7)
        | (screenBase << 8) | (charBase << 2));
}

/* G2S_SetBG1Control: gx_bgcnt.h and original MMIO 0x0400100a establish this
 * sub-engine BG1 setter. The fifth argument selects the extended-palette slot
 * (bit 13), which is why this wrapper has one more parameter than the BG2/BG3
 * text setters above. */
void func_0205447c(u32 screenSize, u32 colorMode, u32 screenBase, u32 charBase,
                   u32 bgExtPltt)
{
    *(volatile u16 *)0x0400100a = (u16)((*(volatile u16 *)0x0400100a & 0x43)
        | (screenSize << 14) | (colorMode << 7)
        | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}
