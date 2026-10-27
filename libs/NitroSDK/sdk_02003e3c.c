#include "libs/NitroSDK/sdk_02003e3c.h"

extern void func_02005624(const void *source, volatile void *fifo);
extern void func_02005600(const void *source, volatile void *fifo);
extern void func_020087dc(const void *source, volatile void *destination);
extern void func_020087c0(const void *source, volatile void *destination);
extern void func_020043ac(volatile void *fifo);

/* Stack-level readback and the remaining G3X helpers, declared up front because
 * the init routines below call code that is defined later in this unit. */
extern s32 func_0200434c(u32 *level);
extern s32 func_0200437c(u32 *level);
extern void func_02004090(void);
extern void func_02004128(void);
extern void func_020042ac(void);
/* MI_DmaFill32Async: the null callback/argument pair matches the original call
 * shape for a blocking fill issued on a DMA channel. */
extern void func_0200801c(u32 dma, void *destination, u32 value, u32 size,
                          u32 callback, u32 arg);
extern void func_02007ec0(u32 dma, void *destination, u32 value, u32 size);
extern void func_020086a0(u32 value, void *destination, u32 size);
/* GXi_DmaId: the channel chosen by GX_Init (see sdk_020026a0.c). */
extern u32 data_0213ce44;
/* Orthographic matrix provider. It writes all sixteen words of the caller's
 * Q12 matrix, including the W scale at index 15. */
extern void func_02001f94(s32 top, s32 bottom, s32 left, s32 right,
                          s32 nearPlane, s32 farPlane, s32 scale, s32 *matrix);

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

/* G3X_Init in pret/pokediamond GX_g3x.c: drain the FIFO, wait for the geometry
 * engine, clear the 3D display registers and stack state, then install the
 * default edge/fog tables and identity polygon/texture attributes. The extra
 * halfword store at 0x04000356 is the 16-bit clear-image offset. Every address
 * and mask below matches the delinked instruction stream. */
void func_02003ef0(void)
{
    func_02004068();
    *(volatile u32 *)0x04000504 = 0;
    while (*(volatile u32 *)0x04000600 & 0x08000000) {
    }
    *(volatile u16 *)0x04000060 = 0;
    *(volatile u32 *)0x04000600 = 0;
    *(volatile u32 *)0x04000010 = 0;
    *(volatile u16 *)0x04000060 |= 0x2000;
    *(volatile u16 *)0x04000060 |= 0x1000;
    *(volatile u16 *)0x04000060 &= ~0x3002;
    *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 0x10);
    /* 0xcffb is the 16-bit form of ~0x3004: clear DISP3DCNT bits 2, 12 and 13. */
    *(volatile u16 *)0x04000060 &= 0xcffb;
    *(volatile u32 *)0x04000600 |= 0x8000;
    *(volatile u32 *)0x04000600 =
        (*(volatile u32 *)0x04000600 & ~0xc0000000) | 0x80000000;
    func_02004090();
    *(volatile u32 *)0x04000350 = 0;
    *(volatile u16 *)0x04000354 = 0x7fff;
    *(volatile u16 *)0x04000356 = 0;
    *(volatile u32 *)0x04000358 = 0;
    *(volatile u16 *)0x0400035c = 0;
    *(volatile u16 *)0x04000008 &= ~3;
    func_020042ac();
    *(volatile u32 *)0x040004a4 = 0x1f0080;
    *(volatile u32 *)0x040004a8 = 0;
    *(volatile u32 *)0x040004ac = 0;
}

/* G3X_ResetMtxStack in pret/pokediamond GX_g3x.c: wait for the engine, select
 * both matrix stacks, reset the stack contents through the shared helper and
 * restore the default polygon/texture attributes. */
void func_02003ffc(void)
{
    while (*(volatile u32 *)0x04000600 & 0x08000000) {
    }
    *(volatile u32 *)0x04000600 |= 0x8000;
    *(volatile u16 *)0x04000060 |= 0x2000;
    *(volatile u16 *)0x04000060 |= 0x1000;
    func_02004128();
    *(volatile u32 *)0x040004a4 = 0x1f0080;
    *(volatile u32 *)0x040004a8 = 0;
    *(volatile u32 *)0x040004ac = 0;
}

/* G3X_ClearFifo: GX_g3x.c sends 128 no-ops and waits for GXSTAT busy to clear. */
void func_02004068(void)
{
    func_020043ac((volatile void *)0x04000400);
    while (*(volatile u32 *)0x04000600 & 0x08000000) {
    }
}

/* G3X_InitMtxStack in pret/pokediamond GX_g3x.c: read both stack levels, then
 * pop each stack back through the matrix-mode port. The loops retry while the
 * shared readback reports the stack busy. */
void func_02004090(void)
{
    u32 pvLevel, pjLevel;

    *(volatile u32 *)0x04000600 |= 0x8000;
    while (func_0200434c(&pvLevel)) {
    }
    while (func_0200437c(&pjLevel)) {
    }
    *(volatile u32 *)0x04000440 = 3;
    *(volatile u32 *)0x04000454 = 0;
    *(volatile u32 *)0x04000440 = 0;
    if (pjLevel)
        *(volatile u32 *)0x04000448 = pjLevel;
    *(volatile u32 *)0x04000454 = 0;
    *(volatile u32 *)0x04000440 = 2;
    *(volatile u32 *)0x04000448 = pvLevel;
    *(volatile u32 *)0x04000454 = 0;
}

/* G3X_ResetMtxStack_2 in pret/pokediamond GX_g3x.c: same stack unwind as the
 * init routine, but leaves the polygon/texture attribute writes to its caller
 * (func_02003ffc restores those). */
void func_02004128(void)
{
    u32 pvLevel, pjLevel;

    *(volatile u32 *)0x04000600 |= 0x8000;
    while (func_0200434c(&pvLevel)) {
    }
    while (func_0200437c(&pjLevel)) {
    }
    *(volatile u32 *)0x04000440 = 3;
    *(volatile u32 *)0x04000454 = 0;
    *(volatile u32 *)0x04000440 = 0;
    if (pjLevel)
        *(volatile u32 *)0x04000448 = pjLevel;
    *(volatile u32 *)0x04000440 = 2;
    *(volatile u32 *)0x04000448 = pvLevel;
    *(volatile u32 *)0x04000454 = 0;
}

/* G3X_SetFogTable: the destination 0x04000360 is the 32-byte hardware fog table. */
void func_02004270(const u32 *table)
{
    func_020087c0(table, (volatile void *)0x04000360);
}

/* G3X_SetFog: GX_g3x.c identifies fog mode, slope and offset register fields. */
void func_020041b8(u32 enable, u32 alphaMode, u32 slope, s32 offset)
{
    if (enable) {
        *(volatile u16 *)0x0400035c = (u16)offset;
        *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3f40) |
            ((slope << 8) | (alphaMode << 6) | 0x80));
    } else {
        *(volatile u16 *)0x04000060 = (u16)(*(volatile u16 *)0x04000060 & (u16)~0x3080);
    }
}

extern void func_0200881c(const volatile void *source, void *destination);

/* G3X_GetClipMtx in GX_g3x.c: busy hardware leaves caller storage untouched. */
s32 func_02004210(s32 *matrix)
{
    if (*(volatile u32 *)0x04000600 & 0x08000000)
        return -1;
    func_0200881c((const volatile void *)0x04000640, matrix);
    return 0;
}

/* G3X_GetVectorMtx in GX_g3x.c: copy nine words only when geometry is idle. */
s32 func_02004240(s32 *matrix)
{
    if (*(volatile u32 *)0x04000600 & 0x08000000)
        return -1;
    func_020087dc((const void *)0x04000680, matrix);
    return 0;
}

/* G3X_SetClearColor in GX_g3x.c identifies color, alpha, polygon ID and fog fields. */
void func_02004284(u32 color, u32 alpha, u32 depth, u32 polygonId, u32 fog)
{
    u32 value = color | (alpha << 16) | (polygonId << 24);
    if (fog)
        value |= 0x8000;
    *(volatile u32 *)0x04000350 = value;
    *(volatile u16 *)0x04000354 = (u16)depth;
}

/* G3X_InitTable in pret/pokediamond GX_g3x.c: wipe the edge-color and fog
 * tables through DMA when GX_Init selected a channel, otherwise through the CPU
 * clear helper, then reset the thirty-two shininess entries. The shininess
 * register is a single port, so all thirty-two stores target the same address. */
void func_020042ac(void)
{
    s32 i;

    if (data_0213ce44 != (u32)-1) {
        func_0200801c(data_0213ce44, (void *)0x04000330, 0, 0x10, 0, 0);
        func_02007ec0(data_0213ce44, (void *)0x04000360, 0, 0x60);
    } else {
        func_020086a0(0, (void *)0x04000330, 0x10);
        func_020086a0(0, (void *)0x04000360, 0x60);
    }
    for (i = 0; i < 0x20; i++)
        *(volatile u32 *)0x040004d0 = 0;
}

/* G3X_GetMtxStackLevelPV in GX_g3x.c: do not write the level while stack is busy. */
s32 func_0200434c(u32 *level)
{
    if (*(volatile u32 *)0x04000600 & 0x4000)
        return -1;
    *level = (*(volatile u32 *)0x04000600 & 0x1f00) >> 8;
    return 0;
}

/* G3X_GetMtxStackLevelPJ in GX_g3x.c: projection stack has a single level bit. */
s32 func_0200437c(u32 *level)
{
    if (*(volatile u32 *)0x04000600 & 0x4000)
        return -1;
    *level = (*(volatile u32 *)0x04000600 & 0x2000) >> 13;
    return 0;
}

extern void func_02001e48(s32 fovSin, s32 fovCos, s32 aspect, s32 nearPlane,
                         s32 farPlane, s32 scale, s32 *matrix);
extern void func_0200167c(const s32 *position, const s32 *up,
                         const s32 *target, s32 *matrix);

/* PerspectiveW wrapper: GX_g3_util.c and provider 02001e48 establish Q12
 * sine/cosine, aspect, clip distances and W scale; null output uses stack storage. */
void func_02004440(s32 fovSin, s32 fovCos, s32 aspect, s32 nearPlane,
                   s32 farPlane, s32 scale, u32 draw, s32 *matrix)
{
    s32 local[16];
    if (!matrix)
        matrix = local;
    func_02001e48(fovSin, fovCos, aspect, nearPlane, farPlane, scale, matrix);
    if (draw) {
        *(volatile u32 *)0x04000440 = 0;
        func_02003e80(matrix);
    }
}

/* Ortho wrapper: provider 02001f94 computes a Q12 orthographic matrix whose
 * W scale sits at word 15 and whose off-diagonal zeros match G3i_OrthoW_ in
 * pret/pokediamond GX_g3_util.c. Arguments are top, bottom, left, right, near,
 * far and scale; the caller may pass null output to use stack storage. Nonzero
 * draw selects projection mode zero (G3_MTX_LOAD_4x4) and uploads the matrix.
 * Right/left, top/bottom and far/near differences must be nonzero. */
void func_0200449c(s32 top, s32 bottom, s32 left, s32 right, s32 nearPlane,
                   s32 farPlane, s32 scale, u32 draw, s32 *matrix)
{
    s32 local[16];

    if (!matrix)
        matrix = local;
    func_02001f94(top, bottom, left, right, nearPlane, farPlane, scale, matrix);
    if (draw) {
        *(volatile u32 *)0x04000440 = 0;
        func_02003e80(matrix);
    }
}

/* G3_LookAt in GX_g3_util.c: optionally load the constructed view matrix into GX. */
void func_02004500(const s32 *position, const s32 *up, const s32 *target,
                   u32 draw, s32 *matrix)
{
    s32 local[12];
    if (!matrix)
        matrix = local;
    func_0200167c(position, up, target, matrix);
    if (draw) {
        *(volatile u32 *)0x04000440 = 2;
        func_02003e9c(matrix);
    }
}
