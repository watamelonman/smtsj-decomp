/* XSI texture-matrix variants. The ARM instruction streams match
 * pret/pokediamond arm9/asm/NNS_G3D_xsi.s (texmtxCalc_flagR_/RS_/T_/TS_):
 * https://github.com/pret/pokediamond/blob/master/arm9/asm/NNS_G3D_xsi.s
 * The C formulations follow the public NitroSystem reconstruction in
 * ctrl-cheeb-del/pokeheartgold lib/NitroSystem/src/g3d_cgtool_xsi_texmtx_sr.c
 * and g3d_cgtool_xsi_texmtx.c:
 * https://github.com/ctrl-cheeb-del/pokeheartgold/tree/master/lib/NitroSystem/src */
#include "libs/unknown/lib_02029470.h"

/** Start Q12 division; retrieve the result before starting another division. */
extern void func_02002298(s32 numerator, s32 denominator);
/** Wait for and return the outstanding Q12 hardware quotient. */
extern s32 func_02002204(void);

/** XSI flagR_ variant (`texmtxCalc_flagR___xsi`): scale/translate, no rotation. */
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

/** XSI flagRS_ variant (`texmtxCalc_flagRS___xsi`): translate with unit scale/rotation. */
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

/** XSI flagT_ variant (`texmtxCalc_flagT___xsi`): scale/rotate, no translation. */
void func_02029548(Unk0296b8Matrix *out, const Unk0296b8Material *srt)
{
    s32 width = srt->origWidth << 12;
    s32 height = srt->origHeight << 12;
    s32 scaleS, scaleT, sinR, cosR, ssin, tcos, scos;
    func_02002298(height, width);
    cosR = srt->cosR;
    scaleS = srt->scaleS;
    sinR = srt->sinR;
    scaleT = srt->scaleT;
    scos = (s32)(((s64)scaleS * cosR) >> 12);
    ssin = (s32)(((s64)scaleS * sinR) >> 12);
    tcos = (s32)(((s64)scaleT * cosR) >> 12);
    out->m00 = scos;
    out->m11 = tcos;
    out->m01 = ((s32)(((s64)scaleT * sinR) >> 12) * func_02002204()) >> 12;
    func_02002298(width, height);
    out->m30 = (srt->origWidth * ssin) << 4;
    out->m31 = (-srt->origHeight * (tcos - 4096)) << 4;
    out->m10 = (-ssin * func_02002204()) >> 12;
}

/** XSI flagTS_ variant (`texmtxCalc_flagTS___xsi`): rotate with unit scale/translation. */
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
