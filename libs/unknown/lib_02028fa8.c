/* 3ds Max texture-matrix constructors and their submission wrapper. The
 * delink relocations order the eight table entries at 0x0213d5a4 exactly like
 * pret/pokediamond arm9/asm/NNS_G3D_xsi.s (flag_, flagS_, flagR_, flagRS_,
 * flagT_, flagTS_, flagTR_, flagTRS_), and the bodies match the public
 * NitroSystem reconstruction in ctrl-cheeb-del/pokeheartgold:
 * https://github.com/ctrl-cheeb-del/pokeheartgold/blob/master/lib/NitroSystem/src/g3d_cgtool_3dsmax.c
 * https://github.com/ctrl-cheeb-del/pokeheartgold/blob/master/lib/NitroSystem/src/g3d_cgtool_3dsmax_texmtx.c
 * The symbol configuration is human-owned, so the linker names stay neutral
 * and the descriptive names live in the comments. */
#include "libs/unknown/lib_02028fa8.h"

/** Start a Q12 hardware division; collect the result before the next one. */
extern void func_02002298(s32 numerator, s32 denominator);
/** Wait for the outstanding hardware division and return its Q12 quotient. */
extern s32 func_02002204(void);
/** Submit count parameter words with the packed geometry opcode. */
extern void func_020252fc(u32 commands, const u32 *parameters, u32 count);
/** Texture-matrix constructor table indexed by the material's flag bits. */
extern void (*data_0213d5a4[8])(Unk0296b8Matrix *, const Unk0296b8Material *);

/** texmtxCalc_flagTS___3dsmax: rotation with unit scale and zero input
 * translation. Both texture dimensions must be nonzero so the aspect-ratio
 * divisions are defined; the caller owns the remaining matrix entries. */
void func_02028fa8(Unk0296b8Matrix *out, const Unk0296b8Material *srt)
{
    s32 width = srt->origWidth << 12;
    s32 height = srt->origHeight << 12;
    s32 x, y;

    func_02002298(height, width);
    out->m00 = srt->cosR;
    out->m11 = srt->cosR;
    out->m01 = (srt->sinR * func_02002204()) >> 12;
    func_02002298(width, height);
    x = -srt->origWidth << 11;
    y = -srt->origHeight << 11;
    out->m30 = (s32)(((s64)srt->cosR * x - (s64)srt->sinR * y) >> 8) +
               (srt->origWidth << 15);
    out->m31 = (s32)(((s64)srt->sinR * x + (s64)srt->cosR * y) >> 8) +
               (srt->origHeight << 15);
    out->m10 = (-srt->sinR * func_02002204()) >> 12;
}

/** texmtxCalc_flagTR___3dsmax: scale with rotation fixed to identity and zero
 * input translation. The texel dimensions are unsigned. */
void func_02029080(Unk0296b8Matrix *out, const Unk0296b8Material *srt)
{
    out->m00 = srt->scaleS;
    out->m11 = srt->scaleT;
    out->m01 = 0;
    out->m30 = ((4096 - srt->scaleS) * srt->origWidth) << 3;
    out->m31 = ((4096 - srt->scaleT) * srt->origHeight) << 3;
    out->m10 = 0;
}

/** texmtxCalc_flagTRS___3dsmax: scale, rotation and translation all disabled,
 * so the result is the identity scale with zero translation. */
void func_020290d0(Unk0296b8Matrix *out)
{
    out->m00 = 4096;
    out->m01 = 0;
    out->m10 = 0;
    out->m11 = 4096;
    out->m30 = 0;
    out->m31 = 0;
}

/** NNSi_G3dSendTexSRT3dsMax: dispatch on the low flag bits, build a texture
 * matrix, magnify its S and T axes, then submit 18 parameter words. */
void func_020290f4(Unk0296b8Material *material)
{
    struct {
        u32 commands;
        u32 mode;
        Unk0296b8Matrix matrix;
        u32 restoreMode;
    } packet;
    s32 zero = 0; /* keeps the shared zero live across the command choice */
    if (material->flags & 8) {
        packet.commands = 0x00101610;
    } else {
        packet.commands = 0x00101810;
    }
    packet.mode = 3;
    packet.restoreMode = 2;
    packet.matrix.m02 = packet.matrix.m03 = packet.matrix.m12 =
        packet.matrix.m13 = packet.matrix.m20 = packet.matrix.m21 =
        packet.matrix.m22 = packet.matrix.m23 = packet.matrix.m32 = zero;
    packet.matrix.m33 = 4096;
    data_0213d5a4[material->flags & 7](&packet.matrix, material);
    if (material->magW != 4096) {
        packet.matrix.m00 = (s32)(((s64)material->magW * packet.matrix.m00) >> 12);
        packet.matrix.m01 = (s32)(((s64)material->magW * packet.matrix.m01) >> 12);
        packet.matrix.m30 = (s32)(((s64)material->magW * packet.matrix.m30) >> 12);
    }
    if (material->magH != 4096) {
        packet.matrix.m10 = (s32)(((s64)material->magH * packet.matrix.m10) >> 12);
        packet.matrix.m11 = (s32)(((s64)material->magH * packet.matrix.m11) >> 12);
        packet.matrix.m31 = (s32)(((s64)material->magH * packet.matrix.m31) >> 12);
    }
    func_020252fc(packet.commands, (const u32 *)&packet + 1, 18);
}
