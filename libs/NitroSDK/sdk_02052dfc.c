typedef signed int fx32;
typedef signed short fx16;

/** Four signed 20.12 elements, stored row by row for the SDK matrix helpers. */
typedef struct Unk02052dfcMatrix {
    fx32 m00, m01, m10, m11;
} Unk02052dfcMatrix;

#pragma thumb on
extern void func_02000d78(Unk02052dfcMatrix *dst, fx32 sine, fx32 cosine);
#pragma thumb off
extern void func_02000d84(const Unk02052dfcMatrix *src,
                         Unk02052dfcMatrix *dst, fx32 x, fx32 y);

/** Build rotation then reciprocal scale; evidenced by the table loads and
 * calls to rotation (02000d78) and row scaling (02000d84). Angle is a nonnegative
 * 16-bit turn index in an int; scales are nonzero signed 20.12 values.
 * The sine/cosine table is ROM data at 0212629c, without a configured symbol. */
void func_02052dfc(Unk02052dfcMatrix *dst, int angle, fx32 scale_x, fx32 scale_y)
{
    const fx16 *table = (const fx16 *)0x0212629c;
    fx32 inverse_x;
    fx32 inverse_y;
    func_02000d78(dst, table[(angle >> 4) * 2], table[(angle >> 4) * 2 + 1]);
    inverse_x = 0x1000000 / scale_x;
    inverse_y = 0x1000000 / scale_y;
    func_02000d84(dst, dst, inverse_x, inverse_y);
}
