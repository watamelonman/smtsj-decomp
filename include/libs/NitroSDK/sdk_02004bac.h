#ifndef SDK_02004BAC_H
#define SDK_02004BAC_H

#include "types.h"

/* GX_LoadBG3Scr, identified by pret/pokediamond arm9/lib/NitroSDK/src/GX_load2d.c
 * and the BG control register used by its getter. Uploads caller-owned data;
 * offset and size are bytes and must be aligned to 2 bytes. */
void func_02004bac(const void *src, u32 offset, u32 size);

/* GXS_LoadBG3Scr, identified by pret/pokediamond arm9/lib/NitroSDK/src/GX_load2d.c
 * and the BG control register used by its getter. Uploads caller-owned data;
 * offset and size are bytes and must be aligned to 2 bytes. */
void func_02004c0c(const void *src, u32 offset, u32 size);

/* GX_LoadBG0Char, identified by pret/pokediamond arm9/lib/NitroSDK/src/GX_load2d.c
 * and the BG control register used by its getter. Uploads caller-owned data;
 * offset and size are bytes and must be aligned to 4 bytes. */
void func_02004c6c(const void *src, u32 offset, u32 size);

/* GXS_LoadBG0Char, identified by pret/pokediamond arm9/lib/NitroSDK/src/GX_load2d.c
 * and the BG control register used by its getter. Uploads caller-owned data;
 * offset and size are bytes and must be aligned to 4 bytes. */
void func_02004ccc(const void *src, u32 offset, u32 size);

/* GX_LoadBG1Char, identified by pret/pokediamond arm9/lib/NitroSDK/src/GX_load2d.c
 * and the BG control register used by its getter. Uploads caller-owned data;
 * offset and size are bytes and must be aligned to 4 bytes. */
void func_02004d2c(const void *src, u32 offset, u32 size);

/* GXS_LoadBG1Char, identified by pret/pokediamond arm9/lib/NitroSDK/src/GX_load2d.c
 * and the BG control register used by its getter. Uploads caller-owned data;
 * offset and size are bytes and must be aligned to 4 bytes. */
void func_02004d8c(const void *src, u32 offset, u32 size);

#endif
