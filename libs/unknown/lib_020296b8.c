#include "libs/unknown/lib_020296b8.h"

/** Dispatch indexed by the three texture identity flags; writes a 4x4 matrix. */
extern void (*data_0213d5c4[8])(Unk0296b8Matrix *, const Unk0296b8Material *);
/** Submit count parameter words with packed geometry opcodes. */
extern void func_020252fc(u32 commands, const u32 *parameters, u32 count);

/* Scale-only matrix construction: offsets agree with NNSG3dMatAnmResult. */
void func_020296b8(Unk0296b8Matrix *matrix, const Unk0296b8Material *material)
{
    matrix->m00 = material->scaleS;
    matrix->m11 = material->scaleT;
    matrix->m01 = 0;
    matrix->m30 = 0;
    matrix->m31 = (-material->origHeight * (material->scaleT - 4096)) << 4;
    matrix->m10 = 0;
}

/* Identity variant of the preceding scale-only constructor. */
void func_020296f8(Unk0296b8Matrix *matrix)
{
    matrix->m00 = 4096;
    matrix->m01 = 0;
    matrix->m10 = 0;
    matrix->m11 = 4096;
    matrix->m30 = 0;
    matrix->m31 = 0;
}

/* NNSG3dMatAnmResult flag/field layout and MTX_MODE/LOAD/MULT opcodes
 * identify texture matrix submission; see the function documentation for sources. */
void func_0202971c(Unk0296b8Material *material)
{
    struct {
        u32 commands;
        u32 mode;
        Unk0296b8Matrix matrix;
        u32 restoreMode;
    } packet;
    if (material->flags & 8) {
        packet.commands = 0x00101610;
    } else {
        packet.commands = 0x00101810;
    }
    packet.mode = 3;
    packet.restoreMode = 2;
    packet.matrix.m33 = 4096;
    packet.matrix.m32 = 0;
    packet.matrix.m23 = 0;
    packet.matrix.m22 = 0;
    packet.matrix.m21 = 0;
    packet.matrix.m20 = 0;
    packet.matrix.m13 = 0;
    packet.matrix.m12 = 0;
    packet.matrix.m03 = 0;
    packet.matrix.m02 = 0;
    if (material->flags & 1) {
        material->scaleT = 4096;
        material->scaleS = 4096;
    }
    if (material->flags & 2) {
        material->cosR = 4096;
        material->sinR = 0;
    }
    if (material->flags & 4) {
        material->transT = 0;
        material->transS = 0;
    }
    data_0213d5c4[material->flags & 7](&packet.matrix, material);
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

/* Constant-result leaf; its higher-level purpose is not established. */
s32 func_020298a4(void) { return 0; }
/* Constant-result leaf; its higher-level purpose is not established. */
s32 func_020298ac(void) { return -1; }
/* Constant-result leaf; its higher-level purpose is not established. */
s32 func_020298b4(void) { return 0; }
