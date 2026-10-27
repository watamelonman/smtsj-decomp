/* Maya geometry-tool routines: the texture-SRT submission with its identity
 * specialization, and the joint-SRT submission. Sources consulted before
 * writing C: ntrtwl/NitroSystem, libraries/g3d/src/cgtool/maya.c, and the
 * pret/pokediamond listing arm9/asm/NNS_G3D_maya.s (same instruction sequence
 * for the texture routines). The joint sender differs from those public
 * sources and was reconstructed from the original instructions. Existing
 * func_ linker names are retained because symbols.txt is human-owned. */
#include "libs/unknown/lib_02028578.h"

/* Result flags from nnsys/g3d/anm.h. The low three bits are the texture
 * identity flags (scale-one, rotation-zero, translation-zero) and index the
 * matrix-constructor table; bit 3 selects load instead of multiply. */
#define MATANM_RESULTFLAG_TEXMTX_SET      0x08

#define JNTANM_RESULTFLAG_SCALE_ONE    0x00000001
#define JNTANM_RESULTFLAG_ROT_ZERO     0x00000002
#define JNTANM_RESULTFLAG_TRANS_ZERO   0x00000004
#define JNTANM_RESULTFLAG_SCALEEX0_ONE 0x00000008
#define JNTANM_RESULTFLAG_SCALEEX1_ONE 0x00000010

/* Geometry command ids and parameter counts (nnsys/g3d/gecom.h). */
#define G3OP_MTX_MULT_4x3         25
#define G3OP_MTX_MULT_3x3         26
#define G3OP_MTX_SCALE            27
#define G3OP_MTX_TRANS            28
#define G3OP_MTX_MULT_4x3_NPARAMS 12
#define G3OP_MTX_MULT_3x3_NPARAMS 9
#define G3OP_MTX_SCALE_NPARAMS    3
#define G3OP_MTX_TRANS_NPARAMS    3

/* Packed MTX_MODE / matrix-load / MTX_MODE command words. */
#define GX_TEXMTX_LOAD  0x00101610
#define GX_TEXMTX_MULT  0x00101810
/* Matrix-mode values carried between the packed commands. */
#define GX_MTXMODE_TEXTURE         3
#define GX_MTXMODE_POSITION_VECTOR 2

/* Texture-matrix constructors indexed by the material's three identity flags. */
extern void (*data_0213d584[8])(Unk0296b8Matrix *,
                                const Unk0296b8Material *);
/** Submit count parameter words with the packed geometry opcodes. */
extern void func_020252fc(u32 commands, const s32 *parameters, u32 count);

/* texmtxCalc_flagTRS_: every texture component is at its identity value, so
 * the matrix holds unit scale and zero off-diagonal/translation entries. */
void func_02028578(Unk0296b8Matrix *matrix)
{
    matrix->m00 = 4096;
    matrix->m01 = 0;
    matrix->m10 = 0;
    matrix->m11 = 4096;
    matrix->m30 = 0;
    matrix->m31 = 0;
}

/* NNSi_G3dSendTexSRTMaya: choose load or multiply from flag bit 3, let the
 * table entry selected by the low flag bits fill the six variable matrix
 * entries, then scale the S and T axes by the texel magnification before
 * submitting all 18 parameter words. */
void func_0202859c(const Unk0296b8Material *material)
{
    struct {
        u32 commands;
        u32 mode;
        Unk0296b8Matrix matrix;
        u32 restoreMode;
    } packet;
    s32 zero = 0; /* keeps the shared zero live across the command choice */

    if (material->flags & MATANM_RESULTFLAG_TEXMTX_SET) {
        packet.commands = GX_TEXMTX_LOAD;
    } else {
        packet.commands = GX_TEXMTX_MULT;
    }
    packet.mode = GX_MTXMODE_TEXTURE;
    packet.restoreMode = GX_MTXMODE_POSITION_VECTOR;
    packet.matrix.m02 = packet.matrix.m03 = packet.matrix.m12 =
        packet.matrix.m13 = packet.matrix.m20 = packet.matrix.m21 =
        packet.matrix.m22 = packet.matrix.m23 = packet.matrix.m32 = zero;
    packet.matrix.m33 = 4096;
    data_0213d584[material->flags & 7](&packet.matrix, material);
    if (material->magW != 4096) {
        packet.matrix.m00 =
            (s32)(((s64)material->magW * packet.matrix.m00) >> 12);
        packet.matrix.m01 =
            (s32)(((s64)material->magW * packet.matrix.m01) >> 12);
        packet.matrix.m30 =
            (s32)(((s64)material->magW * packet.matrix.m30) >> 12);
    }
    if (material->magH != 4096) {
        packet.matrix.m10 =
            (s32)(((s64)material->magH * packet.matrix.m10) >> 12);
        packet.matrix.m11 =
            (s32)(((s64)material->magH * packet.matrix.m11) >> 12);
        packet.matrix.m31 =
            (s32)(((s64)material->magH * packet.matrix.m31) >> 12);
    }
    func_020252fc(packet.commands, (const s32 *)&packet + 1, 18);
}

/* Maya joint-SRT sender: when neither extended scale is the identity, apply
 * the parent inverse scale to the translation and emit the extra scale. Then
 * emit the rotation (4x3 while the translation still has to be combined, 3x3
 * otherwise) and the remaining scale commands, so each component is sent at
 * most once. This is the newer sequence; the older public cgtool source is
 * the variant already matched as func_02027eec. */
void func_020286e4(const Unk028578JointResult *result)
{
    int trFlag = 0;
    /* Both extended scales share one identity test; the parent inverse scale
     * is applied only when neither of them is the identity. */
    u32 scaleExFlags = result->flag & (JNTANM_RESULTFLAG_SCALEEX0_ONE |
                                       JNTANM_RESULTFLAG_SCALEEX1_ONE);

    if (!scaleExFlags) {
        func_020252fc(G3OP_MTX_SCALE, (const s32 *)&result->scaleEx1,
                      G3OP_MTX_SCALE_NPARAMS);
    }

    if (!(result->flag & JNTANM_RESULTFLAG_TRANS_ZERO)) {
        if (scaleExFlags) {
            trFlag = 1;
        } else {
            s32 scaledTrans[3];

            scaledTrans[0] =
                (s32)(((s64)result->trans.x * result->scaleEx0.x) >> 12);
            scaledTrans[1] =
                (s32)(((s64)result->trans.y * result->scaleEx0.y) >> 12);
            scaledTrans[2] =
                (s32)(((s64)result->trans.z * result->scaleEx0.z) >> 12);
            func_020252fc(G3OP_MTX_TRANS, scaledTrans,
                          G3OP_MTX_TRANS_NPARAMS);
        }
    }

    if (!(result->flag & JNTANM_RESULTFLAG_ROT_ZERO)) {
        if (trFlag) {
            func_020252fc(G3OP_MTX_MULT_4x3, result->rot,
                          G3OP_MTX_MULT_4x3_NPARAMS);
        } else {
            func_020252fc(G3OP_MTX_MULT_3x3, result->rot,
                          G3OP_MTX_MULT_3x3_NPARAMS);
        }
    } else if (trFlag) {
        func_020252fc(G3OP_MTX_TRANS, (const s32 *)&result->trans,
                      G3OP_MTX_TRANS_NPARAMS);
    }

    if (!scaleExFlags) {
        func_020252fc(G3OP_MTX_SCALE, (const s32 *)&result->scaleEx0,
                      G3OP_MTX_SCALE_NPARAMS);
    }

    if (!(result->flag & JNTANM_RESULTFLAG_SCALE_ONE)) {
        func_020252fc(G3OP_MTX_SCALE, (const s32 *)&result->scale,
                      G3OP_MTX_SCALE_NPARAMS);
    }
}
