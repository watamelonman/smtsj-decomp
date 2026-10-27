#include "libs/unknown/lib_0205fb4c.h"

extern void func_0205fb0c(void);
extern void func_020629c4(void);
extern Unk05fb4cWork *func_020611dc(void (*callback)(void), u32 a, u32 b, void (*release)(void), u32 size, u32 kind, u32 c, u32 d);
extern void Unk0d297c_Unk_0d31e8(void *slot, u32 value);
extern void func_02008848(void *dst, u32 value, u32 bytes);
extern void func_02055194(u32 device, u32 enable);
extern u32 func_0205a18c(void *pixels, u16 x, u16 y);
extern void func_021260d8(void *surface, u32 x, u32 y, u32 color);
extern u32 func_02061970(u32 font);

/* Initializes the 204-byte work allocated by 020611dc; field roles beyond
 * font/device are deliberately neutral (stores at 0205fba0..0205fbf4). */
Unk05fb4cWork *func_0205fb4c(u32 device, u32 value, u32 font)
{
    Unk05fb4cWork *work = func_020611dc(func_0205fb0c, 0, 0, func_020629c4, 204, 5, 0, 1);
    if (work) {
        work->state = 0;
        work->device = device;
        work->unkac = value;
        work->font = font;
        work->unk08 = 0;
        work->unk10 = 0;
        work->unk3c = 0;
        Unk0d297c_Unk_0d31e8(work->slot, 0);
        work->color = 1;
        work->unk40 = 0;
        work->unk48 = 0;
        work->unk0c = 0;
        work->unk4e = 4;
        work->unk4c = 0;
        func_0205fc10(work, 0);
        func_02008848(work->surface, 0, 28);
    }
    return work;
}

/* Device selection is evidenced by the load at 0205fc14 and provider's GX
 * display-register accesses; the second argument remains caller supplied. */
void func_0205fc10(Unk05fb4cWork *work, u32 enable)
{
    func_02055194(work->device, enable);
}

/* Source bounds and destination origins are borrowed for this synchronous
 * pixel copy; the sample provider takes 16-bit coordinates. */
void func_0205fc20(Unk05fb4cWork *work, const Unk05fb4cRect *dst, const Unk05fb4cRect *src, void *pixels, u32 color)
{
    u32 width = src->right - src->left;
    u32 height = src->bottom - src->top;
    u32 y, x;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            u32 sample = func_0205a18c(pixels, (u16)(src->left + x), (u16)(src->top + y));
            if (sample) sample = color;
            func_021260d8(work->surface, dst->left + x, dst->top + y, sample);
        }
    }
}

/* Font row height comes from 02061970's byte-one metric; output storage
 * belongs to the caller and endpoints are exclusive. */
void func_0205fccc(Unk05fb4cWork *work, Unk05fb4cRect *rect, u32 row, u32 x, u32 width)
{
    u32 height = func_02061970(work->font);
    rect->left = x;
    rect->top = row * height;
    rect->right = rect->left + width;
    rect->bottom = rect->top + height;
}
