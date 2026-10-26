#include "libs/NitroSDK/sdk_02058370.h"

extern u32 func_02003730(void);
extern u32 func_02003744(void);
extern u32 func_02003804(void);
extern u32 func_02003818(void);
extern u32 func_02003758(void);
extern u32 func_0200377c(void);
extern u32 func_0200382c(void);
extern u32 func_02003854(void);
extern u32 func_020037a0(void);
extern u32 func_020037b4(void);
extern u32 func_020037c8(void);
extern u32 func_020037dc(void);
extern u32 func_020037f0(void);
extern void func_020032fc(u32 mask);
extern void func_0200870c(u32 value, void *destination, u32 bytes);
extern u32 func_020038bc(void);
extern u32 func_020038cc(void);
extern void *func_02051610(const void *source);
extern void func_02029bc0(void *state);
extern void func_02029dac(void *state);
extern void func_020256a4(void *resource);
extern void func_020516d0(void *resource);

/** Evidence: thirteen calls to the neighboring SDK bank-release helpers. */
void func_02058370(void)
{
    func_02003730();
    func_02003744();
    func_02003804();
    func_02003818();
    func_02003758();
    func_0200377c();
    func_0200382c();
    func_02003854();
    func_020037a0();
    func_020037b4();
    func_020037c8();
    func_020037dc();
    func_020037f0();
}

/** Evidence: LCDC VRAM, main/sub OAM and palette addresses in the original. */
void func_020583ac(void)
{
    func_02058370();
    func_020032fc(0x1ff);
    func_0200870c(0, (void *)0x06800000, 0xa4000);
    func_020037f0();
    func_0200870c(0xc0, (void *)0x07000000, 0x400);
    func_0200870c(0, (void *)0x05000000, 0x400);
    func_0200870c(0xc0, (void *)0x07000400, 0x400);
    func_0200870c(0, (void *)0x05000400, 0x400);
}

/** Eight-byte bank descriptors observed at 0212e350; storage belongs to the provider. */
typedef struct {
    u32 mask;
    u32 bytes;
} Unk058370Bank;
extern u8 data_0215f05c[];
extern void func_020222d8(void);
extern void func_0202990c(u32 count);
extern void func_02029c00(u32 paletteBytes, int enabled);

/* See DEC-032: retain the original address and temporary allocation. */
#pragma push
#pragma opt_propagation off
/** Evidence: nine mask/capacity records at 0212e350; sum the selected capacities. */
u32 func_02058420(u32 mask)
{
    const Unk058370Bank *banks;
    u32 total;
    int i;
    i = 9;
    banks = (const Unk058370Bank *)0x0212e350;
    --i;
    total = 0;
    do {
        if (mask & banks[i].mask) total += banks[i].bytes;
    } while (--i >= 0);
    return total;
}
#pragma pop

/* See DEC-032: retain the original address and temporary allocation. */
#pragma push
#pragma opt_propagation off
/** Evidence: GXSTAT FIFO mode bits, singleton +20, and geometry allocator calls. */
int func_020584d4(u32 count, u32 paletteBytes)
{
    u32 status;
    u8 *state;
    volatile u32 *gxstat;
    func_020222d8();
    gxstat = (volatile u32 *)0x04000600;
    state = data_0215f05c;
    status = *gxstat;
    *gxstat = (status & ~0xc0000000) | 0x80000000;
    state[20] = 1;
    func_0202990c(count);
    func_02029c00(paletteBytes, 1);
    return 1;
}

#pragma pop

/** Evidence: SDK texture-bank masks; A-D count individually, E/F/G add 64/16/16 KiB. */
int func_02058458(void)
{
    u16 count = 0;
    u32 mask = func_020038bc();
    u32 palette;
    if (mask & 1) count++;
    if (mask & 2) count++;
    if (mask & 4) count++;
    if (mask & 8) count++;
    palette = 0;
    mask = func_020038cc();
    if (mask & 16) palette += 64;
    if (mask & 32) palette += 16;
    if (mask & 64) palette += 16;
    return func_020584d4(count, palette << 10);
}

/** Evidence: provider result stored at work +2058; work retains the handle until release. */
int func_02058528(Unk058370Work *work, const void *source)
{
    work->resource = func_02051610(source);
    return 1;
}

/** Evidence: state blocks +205c/+2084 are finalized before the +2058 handle is released. */
int func_02058548(Unk058370Work *work)
{
    if (!work->resource) return 0;
    func_02029bc0(work->state_205c);
    func_02029dac(work->state_2084);
    func_020256a4(work->resource);
    func_020516d0(work->resource);
    work->resource = 0;
    return 1;
}
