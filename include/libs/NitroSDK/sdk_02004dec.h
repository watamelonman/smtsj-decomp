#ifndef SDK_02004DEC_H
#define SDK_02004DEC_H

#include "types.h"

/** GX_LoadBG2Char equivalent (pret/pokediamond GX_load2d.c): offset and size are bytes. */
void func_02004dec(const void *src, u32 offset, u32 size);
/** GXS_LoadBG2Char equivalent (pret/pokediamond GX_load2d.c): uploads to the sub engine. */
void func_02004e4c(const void *src, u32 offset, u32 size);
/** GX_LoadBG3Char equivalent (pret/pokediamond GX_load2d.c): offset and size are bytes. */
void func_02004eac(const void *src, u32 offset, u32 size);
/** GXS_LoadBG3Char equivalent (pret/pokediamond GX_load2d.c): uploads to the sub engine. */
void func_02004f0c(const void *src, u32 offset, u32 size);
/** GX_BeginLoadBGExtPltt equivalent (pret/pokediamond GX_load2d.c): saves and resets the palette bank. */
void func_02004f6c(void);

#endif
