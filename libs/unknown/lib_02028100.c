/* Maya texture matrix specializations; reference: pret/pokediamond,
 * arm9/asm/NNS_G3D_maya.s, texmtxCalc_flag_/flagS_/flagR_.
 * https://github.com/pret/pokediamond/blob/master/arm9/asm/NNS_G3D_maya.s */

/* NitroSystem texture SRT: Q12 scale and translation with sine/cosine at
 * offsets 0x20/0x22; width/height are texels at 0x2c/0x2e. Only these fields
 * are read, the leading material data is opaque to this unit. */
typedef struct {
    int prefix[6];
    int scaleS, scaleT;
    short sinR, cosR;
    int transS, transT;
    unsigned short width, height;
} TextureSRT;

/* Caller-owned 4x4 matrix; the Maya originals write only entries 0, 1, 4, 5,
 * 12 and 13 (column-major 4x3 hardware form). */
typedef struct {
    int m[16];
} TextureMatrix;

/* Start a Q12 hardware division; retrieve it before starting another one. */
extern void func_02002298(int numerator, int denominator);
/* Wait for the outstanding hardware division and return its Q12 quotient. */
extern int func_02002204(void);

/* Maya texmtxCalc_flag_: scale, rotation and translation (the full case). */
void func_02028100(TextureMatrix *out, const TextureSRT *srt)
{
    int width = srt->width << 12;
    int height = srt->height << 12;
    int sc, ss, ts, tc;
    func_02002298(height, width);
    ss = (int)(((long long)srt->scaleS * srt->sinR) >> 12);
    sc = (int)(((long long)srt->scaleS * srt->cosR) >> 12);
    ts = (int)(((long long)srt->scaleT * srt->sinR) >> 12);
    tc = (int)(((long long)srt->scaleT * srt->cosR) >> 12);
    out->m[0] = sc;
    out->m[5] = tc;
    out->m[1] = (-ts * func_02002204()) >> 12;
    func_02002298(width, height);
    out->m[12] = ((srt->width * (srt->scaleS - (ss + sc))) << 3)
                 - srt->width * (int)(((long long)srt->scaleS * srt->transS) >> 8);
    out->m[13] = srt->height * (int)(((long long)srt->scaleT * srt->transT) >> 8)
                 + (srt->height * (ts - tc - srt->scaleT + 8192U) << 3);
    out->m[4] = (ss * func_02002204()) >> 12;
}

/* Maya texmtxCalc_flagS_: scale and translation, keeping unit rotation. */
void func_02028208(TextureMatrix *out, const TextureSRT *srt)
{
    int width = srt->width << 12;
    int height = srt->height << 12;
    func_02002298(height, width);
    out->m[0] = srt->cosR;
    out->m[5] = srt->cosR;
    out->m[1] = (-srt->sinR * func_02002204()) >> 12;
    func_02002298(width, height);
    out->m[12] = (srt->width * (-(srt->sinR + srt->cosR) + 4096U) << 3)
                 - (srt->transS * srt->width << 4);
    out->m[13] = (srt->height * (srt->sinR - srt->cosR + 4096U) << 3)
                 + (srt->transT * srt->height << 4);
    out->m[4] = (srt->sinR * func_02002204()) >> 12;
}

/* Maya texmtxCalc_flagR_: rotation and translation, scale folded into the
 * translation terms only. */
void func_020282d8(TextureMatrix *out, const TextureSRT *srt)
{
    out->m[0] = srt->scaleS;
    out->m[5] = srt->scaleT;
    out->m[1] = 0;
    out->m[12] = srt->width * -((int)(((long long)srt->scaleS * srt->transS) >> 8));
    out->m[13] = srt->height * (int)(((long long)srt->scaleT * srt->transT) >> 8)
                 + (srt->height * (-2 * srt->scaleT + 8192) << 3);
    out->m[4] = 0;
}
