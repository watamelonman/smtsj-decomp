/* Joint scale and SRT submission variants from NitroSystem's G3D cgtool.
 * Sources: ntrtwl/NitroSystem, libraries/g3d/src/cgtool/basic.c and maya.c.
 * The basic entry is NNSi_G3dGetJointScaleBasic; the other two implement the
 * Maya scaling rule (NNSi_G3dSendJointSRTMaya / NNSi_G3dGetJointScaleMaya).
 * The existing func_ linker names are retained: symbols.txt is human-owned. */
#include "libs/unknown/lib_02027eac.h"

/* Result flags from nnsys/g3d/anm.h. */
#define JNTANM_RESULTFLAG_SCALE_ONE    0x00000001
#define JNTANM_RESULTFLAG_ROT_ZERO     0x00000002
#define JNTANM_RESULTFLAG_TRANS_ZERO   0x00000004
#define JNTANM_RESULTFLAG_SCALEEX0_ONE 0x00000008
#define JNTANM_RESULTFLAG_SCALEEX1_ONE 0x00000010
#define JNTANM_RESULTFLAG_MAYA_SSC     0x00000020

/* SRT and node-descriptor flags from nnsys/g3d/binres/res_struct.h. */
#define SRTFLAG_SCALE_ONE            0x00000004
#define NODEDESC_FLAG_MAYASSC_APPLY  0x01
#define NODEDESC_FLAG_MAYASSC_PARENT 0x02

/* Geometry command ids and parameter counts used by the Maya sender. */
#define G3OP_MTX_MULT_4x3 25
#define G3OP_MTX_MULT_3x3 26
#define G3OP_MTX_SCALE    27
#define G3OP_MTX_TRANS    28
#define G3OP_MTX_MULT_4x3_NPARAMS 12
#define G3OP_MTX_MULT_3x3_NPARAMS 9
#define G3OP_MTX_SCALE_NPARAMS    3
#define G3OP_MTX_TRANS_NPARAMS    3

/* Shared render state; only the identity bitset at 0xc4 is touched here. */
typedef struct Unk027eacRenderState {
    u8 pad_0000[0xc4];
    u32 isScaleCacheOne[8];
} Unk027eacRenderState;

extern Unk027eacRenderState *data_02156f8c;
/* The global scale cache stores a 24-byte scale/inverse pair per node. The
 * delinked symbols for the inverse words are 24 bytes apart per node; these
 * views keep the original per-word relocations instead of folding +12 into the
 * parent-cache base. Entry 0 of each view aliases one word of the first pair. */
typedef struct Unk027eacInvView {
    Unk027eacVec inv;
    s32 pad[3];
} Unk027eacInvView;
extern Unk027eacInvView data_02157d9c[];
extern Unk027eacInvView data_02157da0[];
extern Unk027eacInvView data_02157da4[];
/** Geometry command submission: command id, parameter block, word count. */
extern void func_020252fc(u32 command, const s32 *parameters, u32 count);

/** Set or copy the local scale and mark both extended scales as identity. */
void func_02027eac(Unk027eacJointResult *result, const s32 *scale,
                   const u8 *command, u32 srtflag)
{
    (void)command;
    if (srtflag & SRTFLAG_SCALE_ONE) {
        result->flag |= JNTANM_RESULTFLAG_SCALE_ONE;
    } else {
        result->scale.x = scale[0];
        result->scale.y = scale[1];
        result->scale.z = scale[2];
    }

    result->flag |= JNTANM_RESULTFLAG_SCALEEX0_ONE |
                    JNTANM_RESULTFLAG_SCALEEX1_ONE;
}

/** Emit the Maya nonidentity pieces: optional translation, rotation, scale. */
void func_02027eec(const Unk027eacJointResult *result)
{
    int trFlag = 0;

    if (!(result->flag & JNTANM_RESULTFLAG_TRANS_ZERO)) {
        trFlag = 1;
    }

    if ((result->flag & JNTANM_RESULTFLAG_MAYA_SSC) &&
        !(result->flag & JNTANM_RESULTFLAG_SCALEEX0_ONE)) {
        if (trFlag) {
            func_020252fc(G3OP_MTX_TRANS, (const s32 *)&result->trans,
                          G3OP_MTX_TRANS_NPARAMS);
            trFlag = 0;
        }
        func_020252fc(G3OP_MTX_SCALE, (const s32 *)&result->scaleEx0,
                      G3OP_MTX_SCALE_NPARAMS);
    }

    if (!(result->flag & JNTANM_RESULTFLAG_ROT_ZERO)) {
        if (trFlag) {
            func_020252fc(G3OP_MTX_MULT_4x3, (const s32 *)&result->rot[0],
                          G3OP_MTX_MULT_4x3_NPARAMS);
        } else {
            func_020252fc(G3OP_MTX_MULT_3x3, (const s32 *)&result->rot[0],
                          G3OP_MTX_MULT_3x3_NPARAMS);
        }
    } else {
        if (trFlag) {
            func_020252fc(G3OP_MTX_TRANS, (const s32 *)&result->trans,
                          G3OP_MTX_TRANS_NPARAMS);
        }
    }

    if (!(result->flag & JNTANM_RESULTFLAG_SCALE_ONE)) {
        func_020252fc(G3OP_MTX_SCALE, (const s32 *)&result->scale,
                      G3OP_MTX_SCALE_NPARAMS);
    }
}

/** Set, clear or test one identity-scale bit for the supplied node index. */
static inline void BitVecSet(u32 *vec, u32 idx)
{
    vec[idx >> 5] |= 1U << (idx & 31);
}

/** Clear one identity-scale bit for the supplied node index. */
static inline void BitVecReset(u32 *vec, u32 idx)
{
    vec[idx >> 5] &= ~(1U << (idx & 31));
}

/** Test one identity-scale bit for the supplied node index. */
static inline int BitVecCheck(const u32 *vec, u32 idx)
{
    return (vec[idx >> 5] & (1U << (idx & 31))) != 0;
}

/** Combine a Maya local scale with the parent inverse scale and identity bits. */
void func_02027fb0(Unk027eacJointResult *result, const s32 *scale,
                   const u8 *command, u32 srtflag)
{
    u32 nodeID;
    u32 parentID;
    u8 opFlag = command[3];

    if (srtflag & SRTFLAG_SCALE_ONE) {
        result->flag |= JNTANM_RESULTFLAG_SCALE_ONE;

        if (opFlag & NODEDESC_FLAG_MAYASSC_PARENT) {
            nodeID = command[1];
            BitVecSet(data_02156f8c->isScaleCacheOne, nodeID);
        }
    } else {
        result->scale.x = scale[0];
        result->scale.y = scale[1];
        result->scale.z = scale[2];

        if (opFlag & NODEDESC_FLAG_MAYASSC_PARENT) {
            nodeID = command[1];

            BitVecReset(data_02156f8c->isScaleCacheOne, nodeID);

            data_02157d9c[nodeID].inv.x = scale[3];
            data_02157da0[nodeID].inv.x = scale[4];
            data_02157da4[nodeID].inv.x = scale[5];
        }
    }

    if (opFlag & NODEDESC_FLAG_MAYASSC_APPLY) {
        parentID = command[2];
        result->flag |= JNTANM_RESULTFLAG_MAYA_SSC;

        if (BitVecCheck(data_02156f8c->isScaleCacheOne, parentID)) {
            result->flag |= JNTANM_RESULTFLAG_SCALEEX0_ONE;
        } else {
            result->scaleEx0 = data_02157d9c[parentID].inv;
        }
    }

    result->flag |= JNTANM_RESULTFLAG_SCALEEX1_ONE;
}
