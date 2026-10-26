#include "libs/NitroSDK/sdk_0200500c.h"

/* External SDK entry points retain the delink's symbol names. */
extern u32 data_0213ce44;
extern void func_02002e90(s32 bank);
extern void func_02002f90(s32 bank);
extern u32 func_0200358c(void);
extern u32 func_02003600(void);
extern void func_020080e0(u32 dma, const void *src, void *dest, u32 size,
                          void *callback, void *arg);
extern void func_02008178(u32 dma);
extern void func_020086bc(const void *src, void *dest, u32 size);

/* Partial view of the shared GX load state; the first three words hold the
 * sub-BG extended palette bank and the object extended palette selection. */
typedef struct GXLoadState {
    s32 sub_bg_ext_pltt;
    u32 obj_ext_pltt_lcdc;
    s32 obj_ext_pltt;
    u32 bg_ext_pltt_offset;
    u32 bg_ext_pltt_lcdc;
    s32 bg_ext_pltt;
} GXLoadState;

extern GXLoadState data_021521c0;

/* GX_LoadBGExtPltt in pret/pokediamond's GX_load2d.c: uploads to the current
 * BG extended palette LCDC block, accounting for the bank's stored offset. */
void func_0200500c(const void *src, u32 offset, u32 size)
{
    void *dest = (void *)(data_021521c0.bg_ext_pltt_lcdc + offset -
                          data_021521c0.bg_ext_pltt_offset);
    if (data_0213ce44 != (u32)-1) {
        func_020080e0(data_0213ce44, src, dest, size, 0, 0);
    } else {
        func_020086bc(src, dest, size);
    }
}

/* GX_EndLoadBGExtPltt in pret/pokediamond's GX_load2d.c: waits for the upload
 * and restores the BG extended palette bank saved by the matching begin call. */
void func_0200507c(void)
{
    if (data_0213ce44 != (u32)-1) {
        func_02008178(data_0213ce44);
    }
    func_02002e90(data_021521c0.bg_ext_pltt);
    data_021521c0.bg_ext_pltt = 0;
    data_021521c0.bg_ext_pltt_lcdc = 0;
    data_021521c0.bg_ext_pltt_offset = 0;
}

/* GX_BeginLoadOBJExtPltt in pret/pokediamond's GX_load2d.c: saves the object
 * extended palette bank and selects its LCDC block for the next upload. */
void func_020050c4(void)
{
    data_021521c0.obj_ext_pltt = func_0200358c();
    switch (data_021521c0.obj_ext_pltt) {
    case 0:
        break;
    case 0x40:
        data_021521c0.obj_ext_pltt_lcdc = 0x06894000;
        break;
    case 0x20:
        data_021521c0.obj_ext_pltt_lcdc = 0x06890000;
        break;
    }
}

/* GX_LoadOBJExtPltt in pret/pokediamond's GX_load2d.c: uploads to the object
 * extended palette LCDC block selected by the matching begin call. */
void func_0200510c(const void *src, u32 offset, u32 size)
{
    void *dest = (void *)(data_021521c0.obj_ext_pltt_lcdc + offset);
    if (data_0213ce44 != (u32)-1) {
        func_020080e0(data_0213ce44, src, dest, size, 0, 0);
    } else {
        func_020086bc(src, dest, size);
    }
}

/* GX_EndLoadOBJExtPltt in pret/pokediamond's GX_load2d.c: waits for the upload
 * and restores the object extended palette bank saved by the begin call. */
void func_02005178(void)
{
    if (data_0213ce44 != (u32)-1) {
        func_02008178(data_0213ce44);
    }
    func_02002f90(data_021521c0.obj_ext_pltt);
    data_021521c0.obj_ext_pltt = 0;
    data_021521c0.obj_ext_pltt_lcdc = 0;
}

/* GXS_BeginLoadBGExtPltt in pret/pokediamond's GX_load2d.c: saves the sub
 * engine's BG extended palette bank for the matching end call. */
void func_020051bc(void)
{
    data_021521c0.sub_bg_ext_pltt = func_02003600();
}

/* GXS_LoadBGExtPltt in pret/pokediamond's GX_load2d.c: uploads to the fixed
 * sub-engine BG extended palette block at 0x06898000 plus the byte offset. */
void func_020051d4(const void *src, u32 offset, u32 size)
{
    if (data_0213ce44 != (u32)-1) {
        func_020080e0(data_0213ce44, src, (void *)(0x06898000 + offset), size, 0, 0);
    } else {
        func_020086bc(src, (void *)(0x06898000 + offset), size);
    }
}
