/* XSI texture matrix formulas: pret/pokediamond arm9/asm/NNS_G3D_xsi.s,
 * texmtxCalc_flag_ and texmtxCalc_flagS_. Linker names remain unchanged.
 * https://github.com/pret/pokediamond/blob/master/arm9/asm/NNS_G3D_xsi.s */

/** Borrowed material prefix: Q12 scale, rotation and translation; texel dimensions. */
typedef struct {
    int prefix[6];
    int scaleS, scaleT;
    short sinR, cosR;
    int transS, transT;
    unsigned short width, height;
} TextureSRT;

/** Caller-owned 4x4 matrix; only entries 0, 1, 4, 5, 12 and 13 are written. */
typedef struct {
    int m[16];
} TextureMatrix;

/** Start a Q12 hardware division; collect the result before the next division. */
extern void func_02002298(int numerator, int denominator);
/** Wait for the outstanding hardware division and return its Q12 quotient. */
extern int func_02002204(void);

/** XSI texmtxCalc_flag_: apply scale, rotation and translation (source above).
 * Dimensions must be nonzero; fixed-point products must fit their intermediates. */
void func_0202923c(TextureMatrix *out, const TextureSRT *srt)
{
    int width = srt->width << 12;
    int height = srt->height << 12;
    int ss, tc, st, sine, cosine, scale, sc;
    long long a, b;
    int tx, ty;
    func_02002298(height, width);
    cosine = srt->cosR;
    scale = srt->scaleS;
    sine = srt->sinR;
    sc = (int)(((long long)scale * cosine) >> 12);
    st = srt->scaleT;
    out->m[0] = sc;
    ss = (int)(((long long)scale * sine) >> 12);
    tc = (int)(((long long)st * cosine) >> 12);
    out->m[5] = tc;
    out->m[1] = ((int)(((long long)st * sine) >> 12) * func_02002204()) >> 12;
    func_02002298(width, height);
    a = ((long long)srt->transS * srt->cosR + (long long)srt->transT * srt->sinR) >> 12;
    b = ((long long)srt->transS * srt->sinR - (long long)srt->transT * srt->cosR) >> 12;
    ty = tc + (int)((b * srt->scaleT) >> 12) - 4096;
    tx = ss - (int)((a * srt->scaleS) >> 12);
    out->m[12] = (srt->width * tx) << 4;
    out->m[13] = (-srt->height * ty) << 4;
    out->m[4] = (-ss * func_02002204()) >> 12;
}

/** XSI texmtxCalc_flagS_: unit-scale variant (source above).
 * Caller supplies nonzero dimensions and representable fixed-point arithmetic. */
void func_02029390(TextureMatrix *out, const TextureSRT *srt)
{
    int width = srt->width << 12;
    int height = srt->height << 12;
    int tx, ty;
    func_02002298(height, width);
    out->m[0] = srt->cosR;
    out->m[5] = srt->cosR;
    out->m[1] = (srt->sinR * func_02002204()) >> 12;
    func_02002298(width, height);
    tx = srt->sinR - (int)(((long long)srt->transS * srt->cosR + (long long)srt->transT * srt->sinR) >> 12);
    ty = (int)(((long long)srt->transS * srt->sinR - (long long)srt->transT * srt->cosR) >> 12);
    out->m[12] = (srt->width * tx) << 4;
    out->m[13] = (-srt->height * (srt->cosR + ty - 4096)) << 4;
    out->m[4] = (-srt->sinR * func_02002204()) >> 12;
}
