#include "libs/NitroSDK/sdk_02004bac.h"

extern u32 data_0213ce44;
extern void *func_02003abc(void);
extern void *func_02003b40(void);
extern void *func_02003bb4(void);
extern void *func_02003be8(void);
extern void *func_02003c08(void);
extern void *func_02003c3c(void);
extern void func_02007fb0(u32 dma, const void *src, void *dest, u32 size);
extern void func_02007f40(u32 dma, const void *src, void *dest, u32 size);
extern void func_0200866c(const void *src, void *dest, u32 size);
extern void func_020086bc(const void *src, void *dest, u32 size);

/* GX_LoadBG3Scr, identified by pret/pokediamond arm9/lib/NitroSDK/src/GX_load2d.c
 * and the BG control register used by its getter. Uploads caller-owned data;
 * offset and size are bytes and must be aligned to 2 bytes. */
void func_02004bac(const void *src, u32 offset, u32 size)
{
    u32 base = (u32)func_02003abc();
    if (data_0213ce44 != (u32)-1 && size > 28) {
        func_02007fb0(data_0213ce44, src, (void *)(base + offset), size);
    } else {
        func_0200866c(src, (void *)(base + offset), size);
    }
}

/* GXS_LoadBG3Scr, identified by pret/pokediamond arm9/lib/NitroSDK/src/GX_load2d.c
 * and the BG control register used by its getter. Uploads caller-owned data;
 * offset and size are bytes and must be aligned to 2 bytes. */
void func_02004c0c(const void *src, u32 offset, u32 size)
{
    u32 base = (u32)func_02003b40();
    if (data_0213ce44 != (u32)-1 && size > 28) {
        func_02007fb0(data_0213ce44, src, (void *)(base + offset), size);
    } else {
        func_0200866c(src, (void *)(base + offset), size);
    }
}

/* GX_LoadBG0Char, identified by pret/pokediamond arm9/lib/NitroSDK/src/GX_load2d.c
 * and the BG control register used by its getter. Uploads caller-owned data;
 * offset and size are bytes and must be aligned to 4 bytes. */
void func_02004c6c(const void *src, u32 offset, u32 size)
{
    u32 base = (u32)func_02003bb4();
    if (data_0213ce44 != (u32)-1 && size > 48) {
        func_02007f40(data_0213ce44, src, (void *)(base + offset), size);
    } else {
        func_020086bc(src, (void *)(base + offset), size);
    }
}

/* GXS_LoadBG0Char, identified by pret/pokediamond arm9/lib/NitroSDK/src/GX_load2d.c
 * and the BG control register used by its getter. Uploads caller-owned data;
 * offset and size are bytes and must be aligned to 4 bytes. */
void func_02004ccc(const void *src, u32 offset, u32 size)
{
    u32 base = (u32)func_02003be8();
    if (data_0213ce44 != (u32)-1 && size > 48) {
        func_02007f40(data_0213ce44, src, (void *)(base + offset), size);
    } else {
        func_020086bc(src, (void *)(base + offset), size);
    }
}

/* GX_LoadBG1Char, identified by pret/pokediamond arm9/lib/NitroSDK/src/GX_load2d.c
 * and the BG control register used by its getter. Uploads caller-owned data;
 * offset and size are bytes and must be aligned to 4 bytes. */
void func_02004d2c(const void *src, u32 offset, u32 size)
{
    u32 base = (u32)func_02003c08();
    if (data_0213ce44 != (u32)-1 && size > 48) {
        func_02007f40(data_0213ce44, src, (void *)(base + offset), size);
    } else {
        func_020086bc(src, (void *)(base + offset), size);
    }
}

/* GXS_LoadBG1Char, identified by pret/pokediamond arm9/lib/NitroSDK/src/GX_load2d.c
 * and the BG control register used by its getter. Uploads caller-owned data;
 * offset and size are bytes and must be aligned to 4 bytes. */
void func_02004d8c(const void *src, u32 offset, u32 size)
{
    u32 base = (u32)func_02003c3c();
    if (data_0213ce44 != (u32)-1 && size > 48) {
        func_02007f40(data_0213ce44, src, (void *)(base + offset), size);
    } else {
        func_020086bc(src, (void *)(base + offset), size);
    }
}
