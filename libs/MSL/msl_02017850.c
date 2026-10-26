#include "libs/MSL/msl_02017850.h"

/** MSL double-precision routine; the thunks only forward to it. */
extern double func_02017058(double value);
/** MSL double-precision routine; the thunks only forward to it. */
extern double func_02017850(double value);
/** MSL double-precision routine; the thunks only forward to it. */
extern double func_020186d4(double value);
/** MSL double-precision routine; the thunks only forward to it. */
extern double func_020188ac(double value);

/** MSL heap operation: arena index, heap index and block pointer.
 * A negative heap index selects the arena's default heap, which is how the
 * free wrapper below reaches the allocator. */
extern s32 func_02007170(s32 arena, s32 heap, void *block);

/** MSL decimal mantissa increment helper. It adds one to the n-digit decimal
 * mantissa, carrying toward the most significant digit and bumping the
 * exponent on overflow. This routine is still delinked assembly (see the
 * function document), but func_0201bb34 calls it with the decimal state. */
extern void func_0201bae4(MslDecimal *value, int digits);

/** MSL exponent helper: returns the mantissa of `value` and stores the binary
 * exponent through `exponent` (frexp-style split). */
extern double func_0201b5cc(double value, int *exponent);

/** MSL exponent helper: rebuilds a double from a mantissa and binary exponent
 * (ldexp-style combine); it is the inverse of func_0201b5cc. */
extern double func_0201b688(double value, int exponent);

/** Forward a double to func_02017058.
 * Evidence: the body loads the target address and branches with the argument
 * registers untouched, and libs/CRI callers pass a double produced by _f2d. */
double func_0201ba48(double value)
{
    return func_02017058(value);
}

/** Forward a double to func_02017850.
 * Evidence: same untouched-register tail call; the caller in
 * libs/CRI/cri_0208aba0.c passes the result of _f2d. */
double func_0201ba54(double value)
{
    return func_02017850(value);
}

/** Forward a double to func_020186d4.
 * Evidence: same untouched-register tail call and a double argument at every
 * libs/CRI call site. */
double func_0201ba60(double value)
{
    return func_020186d4(value);
}

/** Forward a double to func_020188ac.
 * Evidence: same untouched-register tail call and a double argument at every
 * libs/CRI call site. */
double func_0201ba6c(double value)
{
    return func_020188ac(value);
}

/** Decide whether the decimal mantissa must round up at digit `digits`.
 * Evidence: the body compares the digit at that index with 5, scans the
 * following digits for a nonzero value when it is exactly 5, and otherwise
 * tests the previous digit's low bit, which is round-half-to-even. Returns 1
 * to increment the mantissa and -1 to round down; func_0201bb34 tests the
 * sign of this result. */
int func_0201ba78(MslDecimal *value, int digits)
{
    u8 *p = value->digits + digits;

    if (*p > 5)
        return 1;
    if (*p < 5)
        return -1;
    {
        u8 *end = value->digits + value->length;
        for (p++; p < end; p++) {
            if (*p != 0)
                return 1;
        }
    }
    if (value->digits[digits - 1] & 1)
        return 1;
    return -1;
}

/** Do nothing.
 * Evidence: the delinked body is a single `bx lr`, so the routine has no
 * observable effect; the name stays neutral because no caller identifies it. */
void func_0201bb30(void)
{
}

/** Clear the sign bit of a double in place.
 * Evidence: the body loads the high word of the first argument and masks it
 * with 0x7fffffff; the low word is returned unchanged. The name stays neutral
 * because no caller or string identifies the intended math entry point. */
double func_0201b3ec(double value)
{
    MslDoubleBits *bits = (MslDoubleBits *)&value;
    bits->words[1] &= 0x7fffffff;
    return value;
}

/** Copy the sign of `sign_source` onto `magnitude`.
 * Evidence: the body clears the high-word sign of the first double argument
 * and ORs in the high-word sign of the second, which is copysign semantics.
 * Both arguments are doubles at the ABI level (two core registers each). */
double func_0201b254(double magnitude, double sign_source)
{
    ((MslDoubleBits *)&magnitude)->words[1] =
        (((MslDoubleBits *)&magnitude)->words[1] & 0x7fffffff) |
        (((MslDoubleBits *)&sign_source)->words[1] & 0x80000000);
    return magnitude;
}

/** Set the digit count of a decimal value and propagate a rounding increment.
 * Evidence: the body stores the new count at +4, asks func_0201ba78 whether the
 * digit string is usable, and only then calls func_0201bae4 to increment the
 * mantissa. Both helpers use the same decimal state. The name stays neutral
 * because no caller or string identifies the public formatting entry point. */
void func_0201bb34(MslDecimal *value, int digits)
{
    int result;

    if (digits <= 0)
        return;
    if (digits >= value->length)
        return;

    result = func_0201ba78(value, digits);
    value->length = digits;
    if (result < 0)
        return;
    func_0201bae4(value, digits);
}

/** Parse the integer digit run at `text` into `value`, then decide the rounding
 * flag from the first discarded character. Evidence: the body copies at most
 * 32 characters minus '0' into digits[+5], stores the count at +4 and the
 * binary exponent at +2, then compares the next character with 5 and scans
 * following zeros before calling func_0201bae4. This is MSL's `__str2dec`
 * (the same routine is reconstructed under that name in the public MSL
 * sources), with the sign byte cleared first. */
void func_0201bdc4(MslDecimal *value, const s8 *text, s16 exponent)
{
    int i = 0;
    int c;

    value->exponent = exponent;
    value->sign = 0;
    while (i < 32 && *text != 0) {
        value->digits[i++] = *text++ - '0';
    }
    value->length = i;
    c = *text;
    if (c == 0)
        return;
    if (c < 5)
        return;
    if (c > 5)
        goto round;
    c = text[1];
    text++;
    if (c != 0) {
        do {
            if (c != '0')
                goto round;
            c = *++text;
        } while (c != 0);
    }
    if ((value->digits[i - 1] & 1) == 0)
        return;
round:
    func_0201bae4(value, value->length);
}

/** Add an integer to a double's binary exponent.
 * Evidence: the body splits the double with func_0201b5cc, adds the third
 * argument to the stored exponent, then rebuilds the double with
 * func_0201b688. The name stays neutral because no caller or string identifies
 * the public math entry point. */
double func_0201cfac(double value, int exponent_adjust)
{
    int exponent;

    value = func_0201b5cc(value, &exponent);
    exponent += exponent_adjust;
    return func_0201b688(value, exponent);
}

/** Population count of a 64-bit word. Evidence: the body is the standard
 * 64-bit SWAR sequence with the masks 0x55555555, 0x33333333 and 0x0f0f0f0f,
 * then adds the two halves and returns the low byte. The dtoa caller subtracts
 * the count from 53 to size the significant-digit run of a normalised
 * mantissa. The value is passed as one u64 so the ABI keeps it in r0/r1. */
int func_0201ce94(u64 value)
{
    value = value - ((value >> 1) & 0x5555555555555555ULL);
    value = (value & 0x3333333333333333ULL) +
            ((value >> 2) & 0x3333333333333333ULL);
    value = (value + (value >> 4)) & 0x0f0f0f0f0f0f0f0fULL;
    value = value + (value >> 8);
    value = value + (value >> 16);
    value = value + (value >> 32);
    return value & 0xff;
}

/** Return the sign bit of `value` as an s32.
 * Evidence: the high word of the double argument is masked with 0x80000000.
 * The argument is spilled to the stack because the code inspects its
 * representation; aliasing the parameter is what produces the 16-byte save. */
s32 func_0201cf28(double value)
{
    return ((MslDoubleBits *)&value)->words[1] & 0x80000000;
}

/** Classify a double by its IEEE-754 bit pattern. Evidence: the body masks the
 * high word with 0x7ff00000 and returns 3 for zero, 5 for a denormal, 2 for an
 * infinity, 1 for a NaN and 4 for a normal value; the mantissa/low-word tests
 * distinguish zero from denormal and infinity from NaN. Callers compare the
 * result with 1 and 2, matching the NaN/infinity checks in func_0201c648. */
int func_0201cf3c(double value)
{
    u32 exponent = ((u32 *)&value)[1] & 0x7ff00000;

    if (exponent == 0)
        goto zero;
    if (exponent != 0x7ff00000)
        goto normal;
    if ((((u32 *)&value)[1] & 0xfffff) != 0 || ((u32 *)&value)[0] != 0)
        return 1;
    return 2;
zero:
    if ((((u32 *)&value)[1] & 0xfffff) != 0 || ((u32 *)&value)[0] != 0)
        return 5;
    return 3;
normal:
    return 4;
}

/** Release `block` through MSL's arena allocator.
 * Evidence: forwards arena 0 and heap -1 to func_02007170, the MSL allocation
 * entry point; func_020117f0 calls it only for a non-null pointer and discards
 * the result, as free does. */
s32 func_0201cfd8(void *block)
{
    return func_02007170(0, -1, block);
}

/** Return the largest positive signed 32-bit value.
 * Evidence: the body complements 0x80000000, leaving 0x7fffffff. */
s32 func_0201e048(void)
{
    return 0x7fffffff;
}
