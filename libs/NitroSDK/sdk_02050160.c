#include "types.h"

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
