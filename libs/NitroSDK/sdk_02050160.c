#include "types.h"

extern s32 func_0200219c(s32 numerator, s32 denominator);

/* Counts decimal digits by unsigned division by ten; zero has zero digits.
 * Evidence: the reciprocal 0xcccccccd and high-product shift in the original. */
s32 func_02050160(u32 value)
{
    s32 count = 0;
    while (value != 0) {
        value /= 10;
        count++;
    }
    return count;
}

/* Interpolates signed endpoints with an integer fraction, clamping at either
 * end. Evidence: endpoint guards followed by signed division at 0x02050190. */
s32 func_02050190(s32 start, s32 end, s32 duration, s32 elapsed)
{
    if (duration == 0) return end;
    if (elapsed <= 0) return start;
    if (elapsed >= duration) return end;
    return start + (end - start) * elapsed / duration;
}

/* Uses the same endpoint guards with rounded Q12 multiplication and the SDK
 * fixed-point divider. Inputs and result retain the endpoints' units. */
s32 func_020501d0(s32 start, s32 end, s32 duration, s32 elapsed)
{
    if (duration == 0) return end;
    if (elapsed <= 0) return start;
    if (elapsed >= duration) return end;
    return start + func_0200219c((s32)(((s64)(end - start) * (elapsed << 12) + 2048) >> 12), duration << 12);
}
