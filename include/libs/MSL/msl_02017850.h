#ifndef MSL_02017850_H
#define MSL_02017850_H

#include "types.h"

/** MSL double-precision math entry points.
 *
 * The four forwarding functions below pass a double argument unchanged to a
 * routine in this library; callers in libs/CRI pass the result of _f2d, so the
 * argument and result are doubles. The remaining helpers expose the MSL free
 * path, sign/exponent operations and an integer bound. */

/** Bit view of a double, so sign and exponent helpers can test words without
 * converting the value (the ARM ABI passes the low word in r0 and the high
 * word in r1). */
typedef union MslDoubleBits {
    double value;
    u32 words[2];
} MslDoubleBits;

/** Decimal value used by the MSL dtoa helpers: a sign byte and pad byte, a
 * signed decimal exponent at +2, a digit count at +4 and the decimal digits at
 * +5. The sign is stored as the first byte only (the MSL text parser clears it
 * with a byte store); the count is one byte, so the digit buffer never exceeds
 * 255 entries. */
typedef struct MslDecimal {
    u8 sign;
    u8 pad;
    s16 exponent;
    u8 length;
    u8 digits[256];
} MslDecimal;

/** Forward a double argument to func_02017058. */
double func_0201ba48(double value);

/** Forward a double argument to func_02017850. */
double func_0201ba54(double value);

/** Forward a double argument to func_020186d4. */
double func_0201ba60(double value);

/** Forward a double argument to func_020188ac. */
double func_0201ba6c(double value);

/** Decide whether the decimal value must round up at digit `digits`: the digit
 * itself, the trailing digits, and the previous digit's parity (round-half to
 * even). Returns 1 to round up and -1 to leave the value unchanged. */
int func_0201ba78(MslDecimal *value, int digits);

/** Parse integer digits into `value`, store the binary exponent, and set the
 * round-up flag for the first discarded character (MSL `__str2dec`). */
void func_0201bdc4(MslDecimal *value, const s8 *text, s16 exponent);

/** Population count of a 64-bit word (0..64), used to measure how many
 * significant bits a normalised double mantissa has. */
int func_0201ce94(u64 value);

/** Classify a double by its IEEE bit pattern: 1 NaN, 2 infinity, 3 zero,
 * 4 normal, 5 denormal (MSL `__dclass` semantics). */
int func_0201cf3c(double value);

/** No-op helper; its whole body is a return. */
void func_0201bb30(void);

/** Clear the sign bit of a double and return it. */
double func_0201b3ec(double value);

/** Copy the sign of the second double onto the first. */
double func_0201b254(double magnitude, double sign_source);

/** Set a decimal digit count and propagate the rounding increment. */
void func_0201bb34(MslDecimal *value, int digits);

/** Add an integer to a double's binary exponent. */
double func_0201cfac(double value, int exponent_adjust);

/** Return the sign bit (0x80000000) of the high word of a double. */
s32 func_0201cf28(double value);

/** Release a heap block through MSL's allocator (arena 0, heap -1). */
s32 func_0201cfd8(void *block);

/** Return the largest positive signed 32-bit value (0x7fffffff). */
s32 func_0201e048(void);

/** Borrowed formatting request. Only the signed precision at offset two is
 * observed by __num2dec; callers retain ownership of the request. */
typedef struct MslDecimalFormat {
    u8 style;
    u8 pad;
    s16 digits;
} MslDecimalFormat;

/** Split a double into a fraction and binary exponent; nonfinite inputs and
 * signed zero pass through with exponent zero. The exponent output is required. */
double func_0201b5cc(double value, int *exponent);

/** Compare numeric decimal magnitudes, ignoring signs and trailing zeros.
 * Both inputs must contain at least a leading digit, including for zero. */
int func_0201c1e4(const MslDecimal *left, const MslDecimal *right);

/** Return whether the left numeric decimal magnitude is smaller; input signs
 * are ignored, and both inputs must have a valid leading digit. */
int func_0201c2c4(const MslDecimal *left, const MslDecimal *right);

/** Format a double to ASCII decimal digits at at most 32 digits of precision.
 * Request and output are borrowed; special markers pass through unchanged. */
void func_0201c7c8(const MslDecimalFormat *format, double number, MslDecimal *value);

#endif
