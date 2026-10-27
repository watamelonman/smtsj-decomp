#ifndef LIB_0205FB4C_H
#define LIB_0205FB4C_H
#include "types.h"

/* Caller-owned rectangle; endpoints use the provider's integer pixel units. */
typedef struct Unk05fb4cRect { u32 top, bottom, left, right; } Unk05fb4cRect;
/* Borrowed 204-byte object view, limited to instruction-observed fields. */
typedef struct Unk05fb4cWork {
    u32 state, flags, unk08, unk0c, unk10;
    u8 slot[20];
    u32 font, color;
    u8 pad30[5];
    s8 spacing;
    u8 pad36;
    s8 limit, line;
    u8 pad39[3];
    u32 unk3c;
    u8 unk40, pad41[7];
    u32 unk48;
    u16 unk4c, unk4e;
    u8 pad50[88];
    u32 device, unkac;
    u8 surface[28];
} Unk05fb4cWork;
/* Allocates and initializes provider-owned text work; null propagates failure. */
Unk05fb4cWork *func_0205fb4c(u32 device, u32 value, u32 font);
/* Forwards the object's device and the caller's enable argument unchanged. */
void func_0205fc10(Unk05fb4cWork *work, u32 enable);
/* Copies a glyph rectangle to the object's surface, replacing nonzero samples. */
void func_0205fc20(Unk05fb4cWork *work, const Unk05fb4cRect *dst, const Unk05fb4cRect *src, void *pixels, u32 color);
/* Produces a destination rectangle using the font's row height. */
void func_0205fccc(Unk05fb4cWork *work, Unk05fb4cRect *rect, u32 row, u32 x, u32 width);
#endif
