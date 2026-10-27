#include "types.h"
#include "libs/NitroSDK/sdk_02050160.h"

/* The SDK fixed-point divide helper. func_0200219c(num, den) returns
 * (num << 12) / den; it starts the hardware divider at 0x04000280 through
 * func_02002298 and reads DIV_RESULT at 0x040002a0 in func_02002204. */
extern s32 func_0200219c(s32 numerator, s32 denominator);

/* Counts the decimal digits produced by repeated unsigned division by ten.
 * Evidence: the original loads the reciprocal 0xcccccccd into r2, keeps the
 * high product of value * reciprocal in r0, shifts it right by three to form
 * value / 10, and increments the counter until the quotient is zero. */
s32 func_02050160(u32 value)
{
    s32 count = 0;
    while (value != 0) {
        value /= 10;
        count++;
    }
    return count;
}

/* Linearly interpolates from start to end over duration units, clamping at
 * both endpoints; a zero duration returns the end value.
 * Evidence: the guards return end for duration == 0, start for elapsed <= 0
 * and end for elapsed >= duration, then the body multiplies end - start by
 * elapsed and divides by duration before adding start. */
s32 func_02050190(s32 start, s32 end, s32 duration, s32 elapsed)
{
    s32 span;
    if (duration == 0) return end;
    if (elapsed <= 0) return start;
    if (elapsed >= duration) return end;
    span = end - start;
    span = span * elapsed / duration;
    return span + start;
}

/* Same clamp-and-interpolate contract as func_02050190, but the multiply is
 * done in 20.12 and the divide goes through the SDK helper, so the ratio is
 * rounded instead of truncated.
 * Evidence: 0x020501d0..0x02050224: rsb/compare guards identical to
 * func_02050190, then sub r12,r1,r4 (span), lsl r0,r3,#12 (elapsed << 12),
 * smull/adds #0x800/adc/lsr #12/orr (FX_MUL), lsl r1,r2,#12 (duration << 12)
 * and bl func_0200219c before add r0,r0,r4. Reusing the span local for the
 * scaled numerator is what makes mwccarm put the span in r12 and the smull
 * low word in r1, as in the original. */
s32 func_020501d0(s32 start, s32 end, s32 duration, s32 elapsed)
{
    if (duration == 0) return end;
    if (elapsed <= 0) return start;
    if (elapsed < duration) {
        s32 span = end - start;
        s32 result;

        span = (s32)(((s64)span * (elapsed << 12) + 2048) >> 12);
        result = func_0200219c(span, duration << 12);
        return result + start;
    }
    return end;
}
