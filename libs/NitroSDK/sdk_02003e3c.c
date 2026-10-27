#include "libs/NitroSDK/sdk_02003e3c.h"

extern void func_02005624(const void *source, volatile void *fifo);
extern void func_02005600(const void *source, volatile void *fifo);
extern void func_020087dc(const void *source, volatile void *destination);
extern void func_020087c0(const void *source, volatile void *destination);
extern void func_020043ac(volatile void *fifo);

/* G2x_SetBlendAlpha_: GX_g2.c packs plane masks and the two blend coefficients. */
void func_02003e3c(volatile u32 *control, u32 plane1, u32 plane2, s32 eva, s32 evb)
{
    *control = (plane1 | 0x40 | (plane2 << 8)) | ((eva | (evb << 8)) << 16);
}

/* G2x_SetBlendBrightness_: GX_g2.c selects brighten/darken from the signed level. */
void func_02003e58(volatile u16 *control, u32 planes, s32 brightness)
{
    if (brightness < 0) {
        control[0] = (u16)(planes | 0xc0);
        control[2] = (u16)-brightness;
    } else {
        control[0] = (u16)(planes | 0x80);
        control[2] = (u16)brightness;
    }
}

/* G3_LoadMtx44: FIFO opcode 0x16 and the 64-byte sender establish the matrix size. */
void func_02003e80(const s32 *matrix)
{
    *(volatile u32 *)0x04000400 = 0x16;
    func_02005624(matrix, (volatile void *)0x04000400);
}

/* G3_LoadMtx43: GX_g3imm.c emits opcode 0x17 followed by twelve matrix words. */
void func_02003e9c(const s32 *matrix)
{
    *(volatile u32 *)0x04000400 = 0x17;
    func_02005600(matrix, (volatile void *)0x04000400);
}

/* G3_MultMtx43: GX_g3imm.c emits opcode 0x19 followed by twelve matrix words. */
void func_02003eb8(const s32 *matrix)
{
    *(volatile u32 *)0x04000400 = 0x19;
    func_02005600(matrix, (volatile void *)0x04000400);
}

/* G3_MultMtx33: GX_g3imm.c emits opcode 0x1a followed by nine matrix words. */
void func_02003ed4(const s32 *matrix)
{
    *(volatile u32 *)0x04000400 = 0x1a;
    func_020087dc(matrix, (volatile void *)0x04000400);
}

/* G3X_ClearFifo: GX_g3x.c sends 128 no-ops and waits for GXSTAT busy to clear. */
void func_02004068(void)
{
    func_020043ac((volatile void *)0x04000400);
    while (*(volatile u32 *)0x04000600 & 0x08000000) {
    }
}

/* G3X_SetFogTable: the destination 0x04000360 is the 32-byte hardware fog table. */
void func_02004270(const u32 *table)
{
    func_020087c0(table, (volatile void *)0x04000360);
}
