#ifndef MSL_02017850_H
#define MSL_02017850_H

#include "types.h"

/** MSL double-precision math entry points.
 *
 * The four thunks below forward a double argument unchanged to a routine in
 * this library; callers in libs/CRI pass the result of _f2d, so the argument
 * and result are doubles. The remaining helpers expose the MSL free path and
 * an integer bound. */

/** Forward a double argument to func_02017058. */
double func_0201ba48(double value);

/** Forward a double argument to func_02017850. */
double func_0201ba54(double value);

/** Forward a double argument to func_020186d4. */
double func_0201ba60(double value);

/** Forward a double argument to func_020188ac. */
double func_0201ba6c(double value);

/** No-op helper; its whole body is a return. */
void func_0201bb30(void);

/** Return the sign bit (0x80000000) of the high word of a double. */
s32 func_0201cf28(double value);

/** Release a heap block through MSL's allocator (arena 0, heap -1). */
s32 func_0201cfd8(void *block);

/** Return the largest positive signed 32-bit value (0x7fffffff). */
s32 func_0201e048(void);

#endif
