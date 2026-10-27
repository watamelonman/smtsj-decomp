#ifndef SDK_02005238_H
#define SDK_02005238_H

#include "types.h"

/** GXS_EndLoadBGExtPltt equivalent: waits for DMA and restores the saved sub-engine BG extended palette bank. */
void func_02005238(void);
/** GXS_BeginLoadOBJExtPltt equivalent: saves the sub-engine object extended palette bank. */
void func_02005278(void);
/** GXS_LoadOBJExtPltt equivalent: uploads to the fixed 0x068a0000 sub-engine object extended palette block. */
void func_02005290(const void *src, u32 offset, u32 size);
/** GXS_EndLoadOBJExtPltt equivalent: waits for DMA and restores the saved sub-engine object extended palette bank. */
void func_020052f4(void);
/** GX_BeginLoadTex equivalent: saves the texture bank and programs the texture VRAM block bases. */
void func_02005334(void);
/** GX_LoadTex equivalent: uploads texture data across the one- or two-block VRAM window. */
void func_02005390(const void *src, u32 offset, u32 size);

#endif
