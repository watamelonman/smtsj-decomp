/* Maya texture matrix specializations; reference: pret/pokediamond,
 * arm9/asm/NNS_G3D_maya.s, texmtxCalc_flagRS_/T_/TS_/TR_.
 * https://github.com/pret/pokediamond/blob/master/arm9/asm/NNS_G3D_maya.s */

/* Partial NitroSystem material result: Q12 scale/translation and sine/cosine;
 * width/height are texels. The first 24 bytes are not accessed here. */
typedef struct {
    int prefix[6];
    int scaleS, scaleT;
    short sinR, cosR;
    int transS, transT;
    unsigned short width, height;
} TextureSRT;

/* Caller-owned 4x4 matrix; only entries 0, 1, 4, 5, 12, 13 are written.
 * See the Maya reference above for the hardware texture-coordinate units. */
typedef struct {
    int m[16];
} TextureMatrix;

/* Start a Q12 hardware division; retrieve it before starting another one. */
extern void func_02002298(int numerator, int denominator);
/* Wait for the outstanding hardware division and return its Q12 quotient. */
extern int func_02002204(void);

/* Maya texmtxCalc_flagRS_: identity scale/rotation, translated in texels. */
void func_02028354(TextureMatrix *out, const TextureSRT *srt)
{
    out->m[0] = 4096;
    out->m[5] = 4096;
    out->m[1] = 0;
    out->m[12] = (-(srt->transS * srt->width)) << 4;
    out->m[13] = (srt->transT * srt->height) << 4;
    out->m[4] = 0;
}

/* Maya texmtxCalc_flagT_: scale/rotation about the texture center, no translation. */
void func_0202839c(TextureMatrix *out, const TextureSRT *srt)
{
    int width = srt->width << 12;
    int height = srt->height << 12;
    int ss, sc, ts, tc;
    func_02002298(height, width);
    ss = (int)(((long long)srt->scaleS * srt->sinR) >> 12);
    sc = (int)(((long long)srt->scaleS * srt->cosR) >> 12);
    ts = (int)(((long long)srt->scaleT * srt->sinR) >> 12);
    tc = (int)(((long long)srt->scaleT * srt->cosR) >> 12);
    out->m[0] = sc;
    out->m[5] = tc;
    out->m[1] = (-ts * func_02002204()) >> 12;
    func_02002298(width, height);
    out->m[12] = (srt->width * (srt->scaleS - (ss + sc))) << 3;
    out->m[13] = (srt->height * (ts - tc - srt->scaleT + 8192)) << 3;
    out->m[4] = (ss * func_02002204()) >> 12;
}

/* Maya texmtxCalc_flagTS_: unit scale and no translation, retaining rotation. */
void func_0202847c(TextureMatrix *out, const TextureSRT *srt)
{
    int width = srt->width << 12;
    int height = srt->height << 12;
    func_02002298(height, width);
    out->m[0] = srt->cosR;
    out->m[5] = srt->cosR;
    out->m[1] = (-srt->sinR * func_02002204()) >> 12;
    func_02002298(width, height);
    out->m[12] = (srt->width * (-(srt->sinR + srt->cosR) + 4096U)) << 3;
    out->m[13] = (srt->height * (srt->sinR - srt->cosR + 4096)) << 3;
    out->m[4] = (srt->sinR * func_02002204()) >> 12;
}

/* Maya texmtxCalc_flagTR_: scale only, with Maya's vertical-origin correction. */
void func_02028534(TextureMatrix *out, const TextureSRT *srt)
{
    out->m[0] = srt->scaleS;
    out->m[5] = srt->scaleT;
    out->m[1] = 0;
    out->m[12] = 0;
    out->m[13] = (srt->height * (-(srt->scaleT << 1) + 8192U)) << 3;
    out->m[4] = 0;
}
