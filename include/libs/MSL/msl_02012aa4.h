#ifndef MSL_02012AA4_H
#define MSL_02012AA4_H

#include "types.h"

/** Format a string into a caller buffer of unlimited logical size.
 * The variadic contract matches vsnprintf; func_02013b94 does the formatting. */
s32 func_02013bfc(char *buffer, const char *format, void *args);

/** Bounded formatted output. Extra arguments follow the normal AAPCS varargs
 * layout; see func_02013b94 for the formatter contract. */
s32 func_02013c14(char *buffer, u32 size, const char *format, ...);

/** Unbounded formatted output. Extra arguments follow the normal AAPCS varargs
 * layout; see func_02013b94 for the formatter contract. */
s32 func_02013c3c(char *buffer, const char *format, ...);

/** Scan a string according to format. Extra arguments follow the normal AAPCS
 * varargs layout; see func_0201509c for the scanner contract. */
s32 func_020150f0(const char *input, const char *format, ...);

/** Length of a NUL-terminated string, excluding the terminator. */
s32 func_02015118(const char *string);

/** Append a NUL-terminated string to another, returning the destination.
 * The MSL build uses signed bytes for the string primitives. */
s8 *func_0201524c(s8 *destination, const s8 *source);

/** Compare at most count bytes; returns the signed difference of the first
 * differing unsigned byte pair, or zero when they are equal. */
s32 func_020153e0(const char *left, const char *right, u32 count);

#endif
