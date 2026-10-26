/* XSI texture-matrix variants, identified against pret/pokediamond's
 * arm9/asm/NNS_G3D_xsi.s (texmtxCalc_flagR_/RS_/T_/TS_).
 * https://github.com/pret/pokediamond/blob/master/arm9/asm/NNS_G3D_xsi.s */
#include "libs/unknown/lib_02029470.h"

/** Start Q12 division; retrieve the result before starting another division. */
extern void func_02002298(s32 numerator, s32 denominator);
/** Wait for and return the outstanding Q12 hardware quotient. */
extern s32 func_02002204(void);

/** XSI flagR_ variant (source above): scale/translate without rotation. */
void func_02029470(Unk0296b8Matrix *out, const Unk0296b8Material *srt)
{
    s32 tx, ty;
    out->m00 = srt->scaleS;
    out->m11 = srt->scaleT;
    out->m01 = 0;
    tx = (s32)(((s64)srt->transS * srt->scaleS) >> 12);
    ty = (s32)(((s64)-srt->transT * srt->scaleT) >> 12);
    out->m30 = (srt->origWidth * -tx) << 4;
    out->m31 = (-srt->origHeight * (srt->scaleT + ty - 4096)) << 4;
    out->m10 = 0;
}

/** XSI flagRS_ variant (source above): translate with identity scale/rotation. */
void func_020294f4(Unk0296b8Matrix *out, const Unk0296b8Material *srt)
{
    s32 tx, ty;
    out->m00 = 4096;
    out->m11 = 4096;
    out->m01 = 0;
    tx = -srt->transS;
    ty = -srt->transT;
    out->m30 = (srt->origWidth * tx) << 4;
    out->m31 = (-srt->origHeight * ty) << 4;
    out->m10 = 0;
}

/** XSI flagT_ variant (source above): scale/rotate without translation. */
void func_02029548(Unk0296b8Matrix *out, const Unk0296b8Material *srt)
{
    s32 width = srt->origWidth << 12;
    s32 height = srt->origHeight << 12;
    s32 ss, tc, st, sine, cosine, scale, sc;
    func_02002298(height, width);
    cosine = srt->cosR;
    scale = srt->scaleS;
    sine = srt->sinR;
    st = srt->scaleT;
    sc = (s32)(((s64)scale * cosine) >> 12);
    out->m00 = sc;
    ss = (s32)(((s64)scale * sine) >> 12);
    tc = (s32)(((s64)st * cosine) >> 12);
    out->m11 = tc;
    out->m01 = ((s32)(((s64)st * sine) >> 12) * func_02002204()) >> 12;
    func_02002298(width, height);
    out->m30 = (srt->origWidth * ss) << 4;
    out->m31 = (-srt->origHeight * (tc - 4096)) << 4;
    out->m10 = (-ss * func_02002204()) >> 12;
}

/** XSI flagTS_ variant (source above): rotate with identity scale/translation. */
void func_02029614(Unk0296b8Matrix *out, const Unk0296b8Material *srt)
{
    s32 width = srt->origWidth << 12;
    s32 height = srt->origHeight << 12;
    func_02002298(height, width);
    out->m00 = srt->cosR;
    out->m11 = srt->cosR;
    out->m01 = (srt->sinR * func_02002204()) >> 12;
    func_02002298(width, height);
    out->m30 = (srt->origWidth * srt->sinR) << 4;
    out->m31 = (-srt->origHeight * (srt->cosR - 4096)) << 4;
    out->m10 = (-srt->sinR * func_02002204()) >> 12;
}
