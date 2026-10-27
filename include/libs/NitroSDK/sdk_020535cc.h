#ifndef SDK_020535CC_H
#define SDK_020535CC_H

#include "types.h"

/* Clears the five input records and installs default auto-repeat timing. */
void func_020535cc(void);
/* Samples the key registers and advances the per-key auto-repeat state. */
void func_02053640(void);
/* Tests held input bits; device must index the provider's five records. */
int func_020537b8(int device, u32 mask);
/* Tests complemented input bits; device must be in 0..4. */
int func_020537dc(int device, u32 mask);
/* Tests newly pressed input bits; device must be in 0..4. */
int func_02053800(int device, u32 mask);
/* Tests auto-repeat input bits; device must be in 0..4. */
int func_02053824(int device, u32 mask);
/* Maps a one-hot key bit to its 0-based index, or -1 when not tracked. */
int func_02053848(u32 key);
/* Sets one device/key first-fire delay and repeat interval; 0 on bad key. */
int func_020538dc(u8 device, u16 key, u16 delay, u16 interval);
/* Sets the delay and interval for every tracked key on all five records. */
void func_02053924(u16 delay, u16 interval);
/* Resets the state block to state 3 and clears its pending slots. */
void func_0205397c(void);
/* Advances the state machine; returns 1 on the countdown-armed frame. */
int func_020539dc(void);
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
