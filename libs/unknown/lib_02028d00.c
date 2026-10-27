/* Adapted from ntrtwl/NitroSystem libraries/g3d/src/cgtool/3dsmax.c,
 * revision d636fb5d2b212e8736f09859fff447be2bd0ac85.
 * Original linker names are retained because symbols.txt is human-owned. */
#include "libs/unknown/lib_02028d00.h"

#define FX32_SHIFT 12
#define FX32_ONE 4096

/** Start the SDK asynchronous fixed-point ratio; operands share Q12 units. */
extern void func_02002298(s32 numerator, s32 denominator);
/** Wait for and return the pending SDK division in Q12 units. */
extern s32 func_02002204(void);

/** Compute unit scale texture SRT; source: NitroSystem 3dsmax.c texmtxCalc_flagS_. */
void func_02028d00 (TextureMatrix028d00 * m, const MaterialAnimation028d00 * anm)
{
    s32 p, q;
    s32 tmpW, tmpH;

    tmpW = (s32)anm->origWidth << FX32_SHIFT;
    tmpH = (s32)anm->origHeight << FX32_SHIFT;
    func_02002298(tmpH, tmpW);

    m->_00 = anm->cosR;
    m->_11 = anm->cosR;

    m->_01 = anm->sinR * func_02002204() >> FX32_SHIFT;
    func_02002298(tmpW, tmpH);

    p = (-anm->origWidth << (FX32_SHIFT - 1)) - anm->transS * anm->origWidth;
    q = (-anm->origHeight << (FX32_SHIFT - 1)) + anm->transT * anm->origHeight;

    m->_30 = (s32)(((s64)anm->cosR * p - (s64)anm->sinR * q) >> (FX32_SHIFT - 4)) +
             (anm->origWidth << (FX32_SHIFT - 1 + 4));

    m->_31 = (s32)(((s64)anm->sinR * p + (s64)anm->cosR * q) >> (FX32_SHIFT - 4)) +
             (anm->origHeight << (FX32_SHIFT - 1 + 4));

    m->_10 = -anm->sinR * func_02002204() >> FX32_SHIFT;
}

/** Compute zero rotation texture SRT; source: NitroSystem 3dsmax.c texmtxCalc_flagR_. */
void func_02028de8 (TextureMatrix028d00 * m, const MaterialAnimation028d00 * anm)
{
    s32 p, q;

    m->_00 = anm->scaleS;
    m->_11 = anm->scaleT;

    m->_01 = 0;

    p = (-anm->origWidth << (FX32_SHIFT - 1)) - anm->transS * anm->origWidth;
    q = (-anm->origHeight << (FX32_SHIFT - 1)) + anm->transT * anm->origHeight;

    m->_30 = (s32)(((s64)anm->scaleS * p) >> (FX32_SHIFT - 4)) +
             (anm->origWidth << (FX32_SHIFT - 1 + 4));

    m->_31 = (s32)(((s64)anm->scaleT * q) >> (FX32_SHIFT - 4)) +
             (anm->origHeight << (FX32_SHIFT - 1 + 4));

    m->_10 = 0;
}

/** Compute unit scale and zero rotation texture SRT; source: NitroSystem 3dsmax.c texmtxCalc_flagRS_. */
void func_02028e68 (TextureMatrix028d00 * m, const MaterialAnimation028d00 * anm)
{
    m->_00 = FX32_ONE;
    m->_11 = FX32_ONE;

    m->_01 = 0;

    m->_30 = (-anm->transS * anm->origWidth) << 4;
    m->_31 = (anm->transT * anm->origHeight) << 4;

    m->_10 = 0;
}

/** Compute zero translation texture SRT; source: NitroSystem 3dsmax.c texmtxCalc_flagT_. */
void func_02028eb0 (TextureMatrix028d00 * m, const MaterialAnimation028d00 * anm)
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

    p = (-anm->origWidth << (FX32_SHIFT - 1));
    q = (-anm->origHeight << (FX32_SHIFT - 1));

    m->_30 = (s32)(((s64)ss_cos * p - (s64)ss_sin * q) >> (FX32_SHIFT - 4)) +
             (anm->origWidth << (FX32_SHIFT - 1 + 4));

    m->_31 = (s32)(((s64)st_sin * p + (s64)st_cos * q) >> (FX32_SHIFT - 4)) +
             (anm->origHeight << (FX32_SHIFT - 1 + 4));

    m->_10 = -ss_sin * func_02002204() >> FX32_SHIFT;
}

