#include "types.h"

/* Table entries 0-7 are BG scroll setters; callers supply the index. */
typedef void (*ScrollSetter)(u32 x, u32 y);
extern ScrollSetter data_02143b10[];
extern void func_02055740(u32 engine, u32 first, u32 second, s32 eva, s32 evb);
extern void func_02003e3c(u32 reg, u32 first, u32 second, s32 eva, s32 evb);
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

/* Register 0x04001014 identifies sub BG1 scroll; each coordinate wraps to 9 bits. */
void func_0205560c(u32 x, u32 y)
{
    *(volatile u32 *)0x04001014 = (x & 0x1ff) | ((y << 16) & (0x1ff << 16));
}

/* Register 0x04001010 identifies sub BG0 scroll; each coordinate wraps to 9 bits. */
void func_02055634(u32 x, u32 y)
{
    *(volatile u32 *)0x04001010 = (x & 0x1ff) | ((y << 16) & (0x1ff << 16));
}

/* Register 0x0400001c identifies main BG3 scroll; each coordinate wraps to 9 bits. */
void func_0205565c(u32 x, u32 y)
{
    *(volatile u32 *)0x0400001c = (x & 0x1ff) | ((y << 16) & (0x1ff << 16));
}

/* Register 0x04000018 identifies main BG2 scroll; each coordinate wraps to 9 bits. */
void func_02055684(u32 x, u32 y)
{
    *(volatile u32 *)0x04000018 = (x & 0x1ff) | ((y << 16) & (0x1ff << 16));
}

/* Register 0x04000014 identifies main BG1 scroll; each coordinate wraps to 9 bits. */
void func_020556ac(u32 x, u32 y)
{
    *(volatile u32 *)0x04000014 = (x & 0x1ff) | ((y << 16) & (0x1ff << 16));
}

/* Register 0x04000010 identifies main BG0 scroll; each coordinate wraps to 9 bits. */
void func_020556d4(u32 x, u32 y)
{
    *(volatile u32 *)0x04000010 = (x & 0x1ff) | ((y << 16) & (0x1ff << 16));
}

/* Dispatches two BG scroll coordinates to data_02143b10[index]. Entries 0-7 are the
 * main/sub BG0-3 scroll setters, so index selects the background and x/y are its
 * coordinates. There is no bounds check. (Table: config/arm9/relocs.txt 0x02143b10;
 * caller func_02055058 passes (index, 0, 0) at 0x02055148.) */
void func_020556fc(u32 index, u32 x, u32 y)
{
    data_02143b10[index](x, y);
}

/* BLDCNT addresses in the original select main for zero, sub for any nonzero engine. */
void func_0205571c(u32 engine)
{
    if (engine == 0)
        *(volatile u16 *)0x04000050 = 0;
    else
        *(volatile u16 *)0x04001050 = 0;
}

/* Applies blend settings to the main BLDCNT (0x04000050) when engine is zero and to the
 * sub BLDCNT (0x04001050) otherwise; the four remaining arguments go to 02003e3c. */
void func_02055740(u32 engine, u32 first, u32 second, s32 eva, s32 evb)
{
    if (engine == 0)
        func_02003e3c(0x04000050, first, second, eva, evb);
    else
        func_02003e3c(0x04001050, first, second, eva, evb);
}

/* Original call to 02055740 uses complementary alpha weights and an empty first-plane mask. */
void func_0205577c(u32 engine, u32 second, s32 weight)
{
    func_02055740(engine, 0, second, weight, 16 - weight);
}

/* Forwards source, destination offset and size to 02004c0c, which copies size bytes
 * from source to base + offset. */
void func_0205579c(const void *source, u32 offset, u32 size)
{
    func_02004c0c(source, offset, size);
}

/* Forwards source, destination offset and size to 02004b4c, which copies size bytes
 * from source to base + offset. */
void func_020557a8(const void *source, u32 offset, u32 size)
{
    func_02004b4c(source, offset, size);
}

/* Forwards source, destination offset and size to 02004bac, which copies size bytes
 * from source to base + offset. */
void func_020557b4(const void *source, u32 offset, u32 size)
{
    func_02004bac(source, offset, size);
}
