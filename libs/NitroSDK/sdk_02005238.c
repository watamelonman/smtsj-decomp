#include "libs/NitroSDK/sdk_02005238.h"

/* External SDK entry points retain the delink's symbol names. */
extern s32 data_0213ce44;
extern void func_02008178(u32 dma);
extern void func_02003434(s32 bank);
extern void func_020034b4(s32 bank);
extern void func_020080e0(u32 dma, const void *src, void *dest, u32 size,
                          void *callback, void *arg);
extern void func_020086bc(const void *src, void *dest, u32 size);
extern void func_02007f40(u32 dma, const void *src, void *dest, u32 size);
extern u32 func_020035b0(void);
extern u32 func_02003628(void);

/* Partial view of the GX load state at data_021521c0. Only the sub-engine
 * extended palette bank slots are observed in this unit (offsets 0 and 24). */
typedef struct GXLoadState {
    s32 sub_bg_ext_pltt;
    u32 pad_04;
    u32 pad_08;
    u32 pad_0c;
    u32 pad_10;
    u32 pad_14;
    s32 sub_obj_ext_pltt;
} GXLoadState;

extern GXLoadState data_021521c0;

/* Texture upload state at data_021521dc: the two LCDC block bases, the block
 * size and the saved bank mask follow the original stores at +4/+24/+28/+20. */
typedef struct TexLoadState {
    u32 pad_00;
    u32 lcdc_blk1;
    u32 pad_08;
    u32 pad_0c;
    u32 pad_10;
    s32 tex;
    u32 lcdc_blk2;
    u32 sz_blk1;
} TexLoadState;

extern TexLoadState data_021521dc;

/* One entry of the SDK texture start-address table: LCDC block bases and the
 * first-block size, all in 4 KiB units (shifted left by 12 at use). */
typedef struct TexStartAddr {
    u16 blk1;
    u16 blk2;
    u16 sz_blk1;
} TexStartAddr;

/* pret/pokediamond GX_load3d.c sTexStartAddrTable; values verified against the
 * ROM table at 0x0212a3b0. The original object references its three columns as
 * absolute literals because the table was internal to the SDK object, so this
 * private copy keeps the same 16 records of three 16-bit fields. */
static const TexStartAddr sTexStartAddrTable[16] = { // forge:data-ok NitroSDK table, ROM 0x0212a3b0
    {0, 0, 0},
    {0x06800000 >> 12, 0, 0},
    {0x06820000 >> 12, 0, 0},
    {0x06800000 >> 12, 0, 0},
    {0x06840000 >> 12, 0, 0},
    {0x06800000 >> 12, 0x06840000 >> 12, 0x00020000 >> 12},
    {0x06820000 >> 12, 0, 0},
    {0x06800000 >> 12, 0, 0},
    {0x06860000 >> 12, 0, 0},
    {0x06800000 >> 12, 0x06860000 >> 12, 0x00020000 >> 12},
    {0x06820000 >> 12, 0x06860000 >> 12, 0x00020000 >> 12},
    {0x06800000 >> 12, 0x06860000 >> 12, 0x00040000 >> 12},
    {0x06840000 >> 12, 0, 0},
    {0x06800000 >> 12, 0x06840000 >> 12, 0x00020000 >> 12},
    {0x06820000 >> 12, 0, 0},
    {0x06800000 >> 12, 0, 0},
};

/* GXS_EndLoadBGExtPltt: waits for the upload channel when configured, restores
 * the sub-engine BG extended palette bank and clears the saved slot. */
void func_02005238(void)
{
    if (data_0213ce44 != -1) {
        func_02008178((u32)data_0213ce44);
    }
    func_02003434(data_021521c0.sub_bg_ext_pltt);
    data_021521c0.sub_bg_ext_pltt = 0;
}

/* GXS_BeginLoadOBJExtPltt: saves the sub-engine object extended palette bank
 * for the matching end call. */
void func_02005278(void)
{
    data_021521c0.sub_obj_ext_pltt = (s32)func_02003628();
}

/* GXS_LoadOBJExtPltt: uploads `size` bytes from `src` to the fixed sub-engine
 * object extended palette block at 0x068a0000 plus the byte offset, using the
 * configured DMA channel or the CPU word copy when the channel is -1. */
void func_02005290(const void *src, u32 offset, u32 size)
{
    if (data_0213ce44 != -1) {
        func_020080e0((u32)data_0213ce44, src,
                      (void *)(0x068a0000 + offset), size, 0, 0);
    } else {
        func_020086bc(src, (void *)(0x068a0000 + offset), size);
    }
}

/* GXS_EndLoadOBJExtPltt: waits for the upload channel when configured, restores
 * the sub-engine object extended palette bank and clears the saved slot. */
void func_020052f4(void)
{
    if (data_0213ce44 != -1) {
        func_02008178((u32)data_0213ce44);
    }
    func_020034b4(data_021521c0.sub_obj_ext_pltt);
    data_021521c0.sub_obj_ext_pltt = 0;
}

/* GX_BeginLoadTex: resets the texture VRAM banks and programs the LCDC block
 * bases and first-block size from the start-address table entry for the
 * previous bank mask. */
void func_02005334(void)
{
    u32 temp = func_020035b0();

    data_021521dc.tex = (s32)temp;
    data_021521dc.lcdc_blk1 = (u32)(sTexStartAddrTable[temp].blk1 << 12);
    data_021521dc.lcdc_blk2 = (u32)(sTexStartAddrTable[temp].blk2 << 12);
    data_021521dc.sz_blk1 = (u32)(sTexStartAddrTable[temp].sz_blk1 << 12);
}

/* GX_LoadTex: uploads texture data, splitting the transfer at the end of the
 * first VRAM block when the destination range crosses into the second block. */
void func_02005390(const void *src, u32 offset, u32 size)
{
    void *dest;
    void *dest2;
    u32 first;

    if (data_021521dc.lcdc_blk2 == 0) {
        dest = (void *)(data_021521dc.lcdc_blk1 + offset);
    } else {
        if (offset + size < data_021521dc.sz_blk1) {
            dest = (void *)(data_021521dc.lcdc_blk1 + offset);
        } else if (offset >= data_021521dc.sz_blk1) {
            dest = (void *)(data_021521dc.lcdc_blk2 + offset -
                            data_021521dc.sz_blk1);
        } else {
            dest2 = (void *)data_021521dc.lcdc_blk2;
            first = data_021521dc.sz_blk1 - offset;
            dest = (void *)(data_021521dc.lcdc_blk1 + offset);
            if (data_0213ce44 != -1 && first > 48) {
                func_02007f40((u32)data_0213ce44, src, dest, first);
            } else {
                func_020086bc(src, dest, first);
            }
            if (data_0213ce44 != -1) {
                func_020080e0((u32)data_0213ce44, (const u8 *)src + first,
                              dest2, size - first, 0, 0);
            } else {
                func_020086bc((const u8 *)src + first, dest2, size - first);
            }
            return;
        }
    }
    if (data_0213ce44 != -1) {
        func_020080e0((u32)data_0213ce44, src, dest, size, 0, 0);
    } else {
        func_020086bc(src, dest, size);
    }
}
