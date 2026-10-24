#include "types.h"

/* The dispatch table's valid indices are supplied by callers. */
typedef void (*TransferCallback)(const void *source, u32 size);
extern TransferCallback data_02143b10[];
extern void func_02055740(u32 engine, u32 first, u32 second, s32 eva, s32 evb);
extern void func_02004c0c(const void *source, u32 offset, u32 size);
extern void func_02004b4c(const void *source, u32 offset, u32 size);
extern void func_02004bac(const void *source, u32 offset, u32 size);

/* Register 0x0400101c identifies sub BG3 scroll; each coordinate wraps to 9 bits. */
void func_020555bc(u32 x, u32 y)
{
    *(volatile u32 *)0x0400101c = (x & 0x1ff) | ((y << 16) & (0x1ff << 16));
}

/* Register 0x04001018 identifies sub BG2 scroll; each coordinate wraps to 9 bits. */
void func_020555e4(u32 x, u32 y)
{
    *(volatile u32 *)0x04001018 = (x & 0x1ff) | ((y << 16) & (0x1ff << 16));
}

/* Original table load at 0x020556fc dispatches source and byte count without bounds checks. */
void func_020556fc(u32 index, const void *source, u32 size)
{
    data_02143b10[index](source, size);
}

/* BLDCNT addresses in the original select main for zero, sub for any nonzero engine. */
void func_0205571c(u32 engine)
{
    if (engine == 0)
        *(volatile u16 *)0x04000050 = 0;
    else
        *(volatile u16 *)0x04001050 = 0;
}

/* Original call to 02055740 uses complementary alpha weights and an empty first-plane mask. */
void func_0205577c(u32 engine, u32 second, s32 weight)
{
    func_02055740(engine, 0, second, weight, 16 - weight);
}

/* Original tail target 02004c0c takes a source, destination offset, and byte count. */
void func_0205579c(const void *source, u32 offset, u32 size)
{
    func_02004c0c(source, offset, size);
}

/* Original tail target 02004b4c takes a source, destination offset, and byte count. */
void func_020557a8(const void *source, u32 offset, u32 size)
{
    func_02004b4c(source, offset, size);
}

/* Original tail target 02004bac takes a source, destination offset, and byte count. */
void func_020557b4(const void *source, u32 offset, u32 size)
{
    func_02004bac(source, offset, size);
}
