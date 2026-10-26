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

/** MSL decimal mantissa helper. It receives the decimal state and a digit
 * count, leaves the count untouched, and returns a negative value when the
 * digit list cannot be used at that length (see its use in func_0201bb34). */
extern int func_0201ba78(MslDecimal *value, int digits);

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

/** Return the sign bit of `value` as an s32.
 * Evidence: the high word of the double argument is masked with 0x80000000.
 * The argument is spilled to the stack because the code inspects its
 * representation; aliasing the parameter is what produces the 16-byte save. */
s32 func_0201cf28(double value)
{
    return ((MslDoubleBits *)&value)->words[1] & 0x80000000;
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
