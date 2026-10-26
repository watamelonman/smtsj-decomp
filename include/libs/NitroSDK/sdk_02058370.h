#ifndef SDK_02058370_H
#define SDK_02058370_H
#include "types.h"

/** Borrowed resource state; only offsets established by the original code are exposed. */
typedef struct {
    u8 pad_0000[0x2058];
    void *resource;
    u8 state_205c[0x28];
    u8 state_2084[1];
} Unk058370Work;

/** Reset all thirteen VRAM bank assignments; allocation state belongs to the SDK. */
void func_02058370(void);
/** Clear VRAM, OAM and palette memory after releasing bank assignments. */
void func_020583ac(void);
/** Sum table capacities for selected bank bits (bits 0 through 8). */
u32 func_02058420(u32 mask);
/** Initialize geometry allocation from currently assigned texture banks. */
int func_02058458(void);
/** Initialize geometry state using a texture-bank count and palette bytes. */
int func_020584d4(u32 count, u32 paletteBytes);
/** Store the provider-created resource in caller-owned work. */
int func_02058528(Unk058370Work *work, const void *source);
/** Release an existing resource and its two associated state blocks; return zero if absent. */
int func_02058548(Unk058370Work *work);
#endif
