#ifndef SDK_0200454C_H
#define SDK_0200454C_H

#include "types.h"

/** Row-major 4x4 fixed-point matrix; all sixteen entries use twelve fractional bits. */
typedef struct Sdk0454cMatrix44 {
    u32 element[16];
} Sdk0454cMatrix44;

/** Multiply the current geometry matrix by an X rotation; inputs are sine/cosine in 20.12. */
void func_0200454c(u32 sine, u32 cosine);
/** Multiply the current geometry matrix by a Y rotation; inputs are sine/cosine in 20.12. */
void func_02004588(u32 sine, u32 cosine);
/** Multiply the current geometry matrix by a Z rotation; inputs are sine/cosine in 20.12. */
void func_020045c4(u32 sine, u32 cosine);
/** Select texture matrix mode and load sixteen caller-owned fixed-point entries. */
void func_02004600(const Sdk0454cMatrix44 *matrix);
/** Copy size bytes to the main palette at byte offset; source and size must be halfword aligned. */
void func_020046b4(const void *source, u32 offset, u32 size);
/** Copy size bytes to the sub palette at byte offset; source and size must be halfword aligned. */
void func_02004708(const void *source, u32 offset, u32 size);

#endif
