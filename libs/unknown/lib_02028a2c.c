/* Adapted from ntrtwl/NitroSystem libraries/g3d/src/cgtool/{si3d,3dsmax}.c.
 * Keep original linker names because symbol configuration is human-owned. */
#include "libs/unknown/lib_02028a2c.h"

#define FX32_SHIFT 12
#define FX32_ONE 4096

/** Begin an asynchronous Q12 ratio using the SDK division provider. */
extern void func_02002298(s32 numerator, s32 denominator);
/** Wait for the pending ratio and return its Q12 value. */
extern s32 func_02002204(void);
/** Submit count parameter words after the packed geometry command. */
extern void func_020252fc(u32 commands, const s32 *parameters, u32 count);

/** Caller-owned packet matrix in the geometry engine's 4x3 word order. */
typedef struct TextureMatrix43_028a2c {
    s32 _00, _01, _02;
    s32 _10, _11, _12;
    s32 _20, _21, _22;
    s32 _30, _31, _32;
} TextureMatrix43_028a2c;

/** SI3D texture SRT sender, identified by NitroSystem si3d.c's same function. */
void func_02028a2c (const MaterialAnimation028d00 * anm)
{
    struct {
        u32 cmd;
        u32 mode_tex;
        TextureMatrix43_028a2c m;
        u32 mode_pos_vec;
    } data;

    if (anm->flag & 8) {
        data.cmd = 0x00101710;
    } else {
        data.cmd = 0x00101910;
    }

    data.mode_tex = 3;
    data.mode_pos_vec = 2;

    data.m._01 = data.m._02 = data.m._10 = data.m._12 = data.m._20 =
    data.m._21 = data.m._22 = data.m._32 = 0;

    if (anm->flag & 4) {
        data.m._30 = 0;
        data.m._31 = 0;

        if (anm->flag & 1) {
            data.m._00 = FX32_ONE;
            data.m._11 = FX32_ONE;
        } else {
            data.m._00 = anm->scaleS;
            data.m._11 = anm->scaleT;
        }
    } else if (anm->flag & 1)   {
        data.m._30 = -(anm->transS << 4) * anm->origWidth;
        data.m._31 = -(anm->transT << 4) * anm->origHeight;
        data.m._00 = FX32_ONE;
        data.m._11 = FX32_ONE;
    } else {
        data.m._30 = -(s32)((s64)anm->scaleS * anm->transS >> (FX32_SHIFT - 4)) * anm->origWidth;
        data.m._31 = -(s32)((s64)anm->scaleT * anm->transT >> (FX32_SHIFT - 4)) * anm->origHeight;
        data.m._00 = anm->scaleS;
        data.m._11 = anm->scaleT;
    }

    if (anm->magW != FX32_ONE) {
        data.m._00 = (s32)((s64)anm->magW * data.m._00 >> FX32_SHIFT);
        data.m._30 = (s32)((s64)anm->magW * data.m._30 >> FX32_SHIFT);
    }

    if (anm->magH != FX32_ONE) {
        data.m._11 = (s32)((s64)anm->magH * data.m._11 >> FX32_SHIFT);
        data.m._31 = (s32)((s64)anm->magH * data.m._31 >> FX32_SHIFT);
    }

    func_020252fc(data.cmd, (const s32 *)&data + 1, 14);
}

/** General 3ds Max texture SRT, from NitroSystem 3dsmax.c texmtxCalc_flag_. */
void func_02028bf8 (TextureMatrix028d00 * m, const MaterialAnimation028d00 * anm)
{
    s32 p, q;
    s32 ss_sin, ss_cos, st_sin, st_cos;
    s32 tmpW, tmpH;

    tmpW = (s32)anm->origWidth << FX32_SHIFT;
    tmpH = (s32)anm->origHeight << FX32_SHIFT;
    func_02002298(tmpH, tmpW);

    ss_cos = (s32)((s64)anm->scaleS * anm->cosR >> FX32_SHIFT);
    ss_sin = (s32)((s64)anm->scaleS * anm->sinR >> FX32_SHIFT);
    st_cos = (s32)((s64)anm->scaleT * anm->cosR >> FX32_SHIFT);
    st_sin = (s32)((s64)anm->scaleT * anm->sinR >> FX32_SHIFT);

    m->_00 = ss_cos;
    m->_11 = st_cos;

    m->_01 = st_sin * func_02002204() >> FX32_SHIFT;
    func_02002298(tmpW, tmpH);

    p = (-anm->origWidth << (FX32_SHIFT - 1)) - anm->transS * anm->origWidth;
    q = (-anm->origHeight << (FX32_SHIFT - 1)) + anm->transT * anm->origHeight;

    m->_30 = (s32)(((s64)ss_cos * p - (s64)ss_sin * q) >> (FX32_SHIFT - 4)) +
             (anm->origWidth << (FX32_SHIFT - 1 + 4));

    m->_31 = (s32)(((s64)st_sin * p + (s64)st_cos * q) >> (FX32_SHIFT - 4)) +
             (anm->origHeight << (FX32_SHIFT - 1 + 4));

    m->_10 = -ss_sin * func_02002204() >> FX32_SHIFT;
}

