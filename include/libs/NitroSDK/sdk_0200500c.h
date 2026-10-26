#ifndef SDK_0200500C_H
#define SDK_0200500C_H

#include "types.h"

/** GX_LoadBGExtPltt equivalent (pret/pokediamond GX_load2d.c): offset and size are bytes. */
void func_0200500c(const void *src, u32 offset, u32 size);
/** GX_EndLoadBGExtPltt equivalent: waits for DMA and restores the saved BG extended palette bank. */
void func_0200507c(void);
/** GX_BeginLoadOBJExtPltt equivalent: saves the object extended palette bank and selects its LCDC block. */
void func_020050c4(void);
/** GX_LoadOBJExtPltt equivalent: uploads to the selected object extended palette LCDC block. */
void func_0200510c(const void *src, u32 offset, u32 size);
/** GX_EndLoadOBJExtPltt equivalent: waits for DMA and restores the saved object extended palette bank. */
void func_02005178(void);
/** GXS_BeginLoadBGExtPltt equivalent: saves the sub-engine BG extended palette bank. */
void func_020051bc(void);
/** GXS_LoadBGExtPltt equivalent: uploads to the sub-engine BG extended palette block. */
void func_020051d4(const void *src, u32 offset, u32 size);

#endif
