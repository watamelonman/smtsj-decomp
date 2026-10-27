#ifndef LIB_020298BC_H
#define LIB_020298BC_H
#include "types.h"

/** Borrowed NitroSystem frame region; addresses and bounds are byte offsets.
 * The provider owns all five regions and the search arrays. */
typedef struct FrameTextureRegion {
    u32 head;
    u32 tail;
    int active;
    int is4x4Region;
    u16 plttIndexSlot;
    u16 padding;
    u32 baseAddr;
} FrameTextureRegion;

/** Returns the original failure sentinel without modifying allocator state. */
s32 func_020298bc(void);
/** Set the five normal-texture search indices; each must be in [0, 4]. */
void func_020298c4(int first, int second, int third, int fourth, int fifth);
/** Configure the frame manager and optionally install its default callbacks. */
void func_0202990c(u16 numSlot, int useAsDefault);
/** Empty every region and enable the configured number of texture slots. */
void func_02029994(void);
/** Reserve texture bytes and return a packed key, or zero on exhaustion. */
u32 func_02029a08(u32 szByte, int is4x4comp, u32 opt);
#endif
