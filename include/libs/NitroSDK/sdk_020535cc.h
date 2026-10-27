#ifndef SDK_020535CC_H
#define SDK_020535CC_H

#include "types.h"

/* Tests held input bits; device must index the provider's five records. */
int func_020537b8(int device, u32 mask);
/* Tests complemented input bits; device must be in 0..4. */
int func_020537dc(int device, u32 mask);
/* Tests newly pressed input bits; device must be in 0..4. */
int func_02053800(int device, u32 mask);
/* Sets the countdown reload word consumed by the state updater. */
void func_020539cc(u32 value);
/* Returns the provider's current state word without transferring ownership. */
u32 func_02053bc8(void);
/* Sets the first dispatch flag; the updater acts when it equals one. */
void func_02053bd8(u32 value);
/* Sets the second dispatch flag; the updater acts when it equals one. */
void func_02053be8(u32 value);
/* Sets the callback dispatch flag; the updater acts when it equals one. */
void func_02053bf8(u32 value);

#endif
