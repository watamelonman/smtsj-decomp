#ifndef GUARD_LIBS_NITROSDK_SDK_02050160_H
#define GUARD_LIBS_NITROSDK_SDK_02050160_H

#include "types.h"

/* Decimal digit count; zero has zero digits. */
s32 func_02050160(u32 value);

/* Integer linear interpolation start..end over duration units, clamped. */
s32 func_02050190(s32 start, s32 end, s32 duration, s32 elapsed);

/* Fixed-point (20.12) variant of the same clamp-and-interpolate contract. */
s32 func_020501d0(s32 start, s32 end, s32 duration, s32 elapsed);

/* 2D cubic Bezier evaluation. This symbol is still supplied by the delinked
 * original (see docs/functions/libs-nitrosdk-sdk-02050160.md); the prototype
 * is here so callers do not rely on implicit declarations. */
void func_02050224(s32 *out, const s32 *in, s32 t);

#endif
