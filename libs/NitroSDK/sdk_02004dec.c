#include "libs/NitroSDK/sdk_02004dec.h"

/* External SDK entry points retain the delink's symbol names. */
extern u8 *func_02003c5c(void);
extern u8 *func_02003cac(void);
extern u8 *func_02003cec(void);
extern u8 *func_02003d44(void);
extern s32 func_02003568(void);
extern void func_02007f40(u32 dma, const void *src, void *dst, u32 size);
extern void func_020086bc(const void *src, void *dst, u32 size);
extern u32 data_0213ce44;

/* Partial view of the shared GX load state; the first three words belong to
 * other upload paths. Offsets follow the stores in func_02004f6c. */
typedef struct GXLoadState {
    u32 other_load_state[3];
    u32 bg_palette_offset;
    u32 bg_palette_base;
    s32 bg_palette_bank;
} GXLoadState;

extern GXLoadState data_021521c0;

/* GX_LoadBG2Char in pret/pokediamond's GX_load2d.c; copies character data
 * using DMA above 48 bytes when a DMA channel is configured. */
void func_02004dec(const void *src, u32 offset, u32 size)
{
    u8 *base = func_02003c5c();
    if (data_0213ce44 != (u32)-1 && size > 48) {
        func_02007f40(data_0213ce44, src, base + offset, size);
    } else {
        func_020086bc(src, base + offset, size);
    }
}

/* GXS_LoadBG2Char in pret/pokediamond's GX_load2d.c; same byte-range
 * contract as the main-engine upload, with the sub-engine BG2 base. */
void func_02004e4c(const void *src, u32 offset, u32 size)
{
    u8 *base = func_02003cac();
    if (data_0213ce44 != (u32)-1 && size > 48) {
        func_02007f40(data_0213ce44, src, base + offset, size);
    } else {
        func_020086bc(src, base + offset, size);
    }
}

/* GX_LoadBG3Char in pret/pokediamond's GX_load2d.c; uploads a byte range
 * to the current main-engine BG3 character base. */
void func_02004eac(const void *src, u32 offset, u32 size)
{
    u8 *base = func_02003cec();
    if (data_0213ce44 != (u32)-1 && size > 48) {
        func_02007f40(data_0213ce44, src, base + offset, size);
    } else {
        func_020086bc(src, base + offset, size);
    }
}

/* GXS_LoadBG3Char in pret/pokediamond's GX_load2d.c; uploads a byte range
 * to the current sub-engine BG3 character base. */
void func_02004f0c(const void *src, u32 offset, u32 size)
{
    u8 *base = func_02003d44();
    if (data_0213ce44 != (u32)-1 && size > 48) {
        func_02007f40(data_0213ce44, src, base + offset, size);
    } else {
        func_020086bc(src, base + offset, size);
    }
}

/* GX_BeginLoadBGExtPltt in pret/pokediamond's GX_load2d.c: preserve the
 * old bank selection and select its LCDC address for subsequent uploads. */
void func_02004f6c(void)
{
    data_021521c0.bg_palette_bank = func_02003568();
    switch (data_021521c0.bg_palette_bank) {
    case 0:
        break;
    case 0x10:
        data_021521c0.bg_palette_base = 0x06880000;
        data_021521c0.bg_palette_offset = 0;
        break;
    case 0x40:
        data_021521c0.bg_palette_base = 0x06894000;
        data_021521c0.bg_palette_offset = 0x4000;
        break;
    case 0x20:
    case 0x60:
        data_021521c0.bg_palette_base = 0x06890000;
        data_021521c0.bg_palette_offset = 0;
        break;
    }
}
