/* Known-source comparison: pret/pokediamond, arm9/lib/NitroSDK/src/GX_load2d.c.
 * Retain configured symbols for compatibility with delink relocations. */
#include "types.h"

extern u32 data_0213ce44;
extern void func_02007fb0(u32 channel, const void *source, void *destination, u32 size);
extern void func_0200866c(const void *source, void *destination, u32 size);
extern void *func_0200391c(void);
extern void *func_02003950(void);
extern void *func_02003970(void);
extern void *func_020039a4(void);
extern void *func_020039c4(void);
extern void *func_02003a48(void);

/* SDK GXi_DmaCopy16 policy; destination remains an operand until dispatch. */
static inline void CopyScreen(u32 channel, const void *source, u32 destination,
                              u32 size)
{
    if (channel != (u32)-1 && size > 28) {
        func_02007fb0(channel, source, (void *)destination, size);
    } else {
        func_0200866c(source, (void *)destination, size);
    }
}

/* Copy size bytes to main BG0 screen memory at byte offset. Matches GX_LoadBG0Scr
 * in GX_load2d.c; the original calls 0200391c for the current mapping.
 * Source, offset and size require two-byte alignment and valid mapped ranges. */
void func_0200496c(const void *source, u32 offset, u32 size)
{
    u32 base = (u32)func_0200391c();
    CopyScreen(data_0213ce44, source, base + offset, size);
}

/* Copy size bytes to sub BG0 screen memory at byte offset. Matches GXS_LoadBG0Scr
 * in GX_load2d.c; the original calls 02003950 for the current mapping.
 * Source, offset and size require two-byte alignment and valid mapped ranges. */
void func_020049cc(const void *source, u32 offset, u32 size)
{
    u32 base = (u32)func_02003950();
    CopyScreen(data_0213ce44, source, base + offset, size);
}

/* Copy size bytes to main BG1 screen memory at byte offset. Matches GX_LoadBG1Scr
 * in GX_load2d.c; the original calls 02003970 for the current mapping.
 * Source, offset and size require two-byte alignment and valid mapped ranges. */
void func_02004a2c(const void *source, u32 offset, u32 size)
{
    u32 base = (u32)func_02003970();
    CopyScreen(data_0213ce44, source, base + offset, size);
}

/* Copy size bytes to sub BG1 screen memory at byte offset. Matches GXS_LoadBG1Scr
 * in GX_load2d.c; the original calls 020039a4 for the current mapping.
 * Source, offset and size require two-byte alignment and valid mapped ranges. */
void func_02004a8c(const void *source, u32 offset, u32 size)
{
    u32 base = (u32)func_020039a4();
    CopyScreen(data_0213ce44, source, base + offset, size);
}

/* Copy size bytes to main BG2 screen memory at byte offset. Matches GX_LoadBG2Scr
 * in GX_load2d.c; the original calls 020039c4 for the current mapping.
 * Source, offset and size require two-byte alignment and valid mapped ranges. */
void func_02004aec(const void *source, u32 offset, u32 size)
{
    u32 base = (u32)func_020039c4();
    CopyScreen(data_0213ce44, source, base + offset, size);
}

/* Copy size bytes to sub BG2 screen memory at byte offset. Matches GXS_LoadBG2Scr
 * in GX_load2d.c; the original calls 02003a48 for the current mapping.
 * Source, offset and size require two-byte alignment and valid mapped ranges. */
void func_02004b4c(const void *source, u32 offset, u32 size)
{
    u32 base = (u32)func_02003a48();
    CopyScreen(data_0213ce44, source, base + offset, size);
}
