/** Signed 20.12 values used by NitroSDK matrix operations. */
typedef signed int fx32;
/** Signed 4.12 values stored in the SDK trigonometric table. */
typedef signed short fx16;
/** Interleaved sine/cosine pairs; see NitroSDK include/nitro/fx/fx_trig.h.
 * ROM address 0x0212629c must be named before this TU is linked from C. */
extern const fx16 FX_SinCosTable_[];

/** Four signed 20.12 elements, stored row by row for the SDK matrix helpers. */
typedef struct Unk02052dfcMatrix {
    fx32 m00, m01, m10, m11;
} Unk02052dfcMatrix;

/** Initialize the destination from signed 20.12 sine/cosine values. */
#pragma thumb on
extern void func_02000d78(Unk02052dfcMatrix *dst, fx32 sine, fx32 cosine);
#pragma thumb off
/** Scale matrix rows by signed 20.12 factors; source may equal destination. */
extern void func_02000d84(const Unk02052dfcMatrix *src,
                         Unk02052dfcMatrix *dst, fx32 x, fx32 y);

/** Build rotation then reciprocal scale; evidenced by the table loads and
 * calls to rotation (02000d78) and row scaling (02000d84). Angle is a nonnegative
 * 16-bit turn index in an int; scales are nonzero signed 20.12 values.
 * Indexing follows NitroSDK include/nitro/fx/fx_trig.h (FX_SinIdx/FX_CosIdx). */
void func_02052dfc(Unk02052dfcMatrix *dst, int angle, fx32 scale_x, fx32 scale_y)
{
    const fx16 *table = FX_SinCosTable_;
    fx32 inverse_x;
    fx32 inverse_y;
    func_02000d78(dst, table[(angle >> 4) * 2], table[(angle >> 4) * 2 + 1]);
    inverse_x = 0x1000000 / scale_x;
    inverse_y = 0x1000000 / scale_y;
    func_02000d84(dst, dst, inverse_x, inverse_y);
}
