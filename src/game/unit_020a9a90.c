/* Font selection, formatted measurement, and aligned text submission. */
#include "types.h"

/* Borrowed 12-byte record; only the unsigned +4 metric is accessed here. */
typedef struct { u8 unused[4]; u16 height; u8 tail[6]; } Glyph;
/* Resource-owned font view; glyph array begins at +0x54. */
typedef struct { u8 unused[0x54]; Glyph *glyphs; } Font;
/* Resource-owned 24-byte slot with a font pointer at +0x14. */
typedef struct { u8 unused[0x14]; Font *font; } FontSlot;
extern u8 data_0214d284[];
extern int data_0214d288[];
void Unk02e000_Unk_02e0cc(void);
FontSlot *func_0205ad8c(void);
int func_02013b94(char *buffer, u32 capacity, const char *format, void *args);
int func_020a9bb4(int slot, int glyph, int x, int y, int style, const char *text, int draw);
void func_020a9c88(void *target, int slot, int glyph, int x, int y, int style, const char *text);

/* Empty callback: the original body consists only of a return. */
void Unk0a9a90_Nop_0a9a90(void) { }

/* Read the selected 12-byte glyph record's +4 metric after resource setup. */
u16 Unk0a9a90_Unk_0a9a94(int slot, int glyph)
{
    FontSlot *slots;
    Unk02e000_Unk_02e0cc();
    slots = func_0205ad8c();
    return slots[slot].font->glyphs[glyph].height;
}

/* Variadic cursors below use the ARM stack argument layout. See DEC-008. */

/* Measure formatted text without drawing; 020a9bb4 accumulates glyph widths. */
int func_020a9e14(int mode, const char *format, ...)
{
    char buffer[32];
    void *args = (void *)(((u32)&format & ~3u) + 4);
    func_02013b94(buffer, sizeof(buffer), format, args);
    return func_020a9bb4(data_0214d288[mode], data_0214d284[mode], 0, 0, 0, buffer, 0);
}

/* Return the selected font metric; variadic ABI is retained from the original. */
int func_020a9e84(int mode, ...)
{
    return Unk0a9a90_Unk_0a9a94(data_0214d288[mode], data_0214d284[mode]);
}

/* Format into a bounded local buffer and submit text at caller coordinates. */
int func_020a9eb4(int mode, int x, int y, int style, const char *format, ...)
{
    char buffer[32];
    void *args = (void *)(((u32)&format & ~3u) + 4);
    func_02013b94(buffer, sizeof(buffer), format, args);
    return func_020a9bb4(data_0214d288[mode], data_0214d284[mode], x, y, style, buffer, 1);
}

/* Adjust borrowed pixel coordinates using measured width and the +4 font metric.
 * Alignment 3 also applies alignment 4's horizontal centering. */
void func_020a9f34(int mode, int *x, int *y, u32 align, int width, const char *text)
{
    int measured = func_020a9e14(mode, text);
    switch (align) {
    case 0: break;
    case 1: *x += (width - measured) / 2; break;
    case 2: *x += width - measured; break;
    case 3: *y -= func_020a9e84(mode, text) / 2;
    case 4: *x -= measured / 2; break;
    }
}

/* Format, align, and draw using the mode tables (callers include CampStatus). */
int func_020a9fd8(int mode, int x, int y, u32 align, int width, int style, const char *format, ...)
{
    char buffer[32];
    void *args = (void *)(((u32)&format & ~3u) + 4);
    func_02013b94(buffer, sizeof(buffer), format, args);
    func_020a9f34(mode, &x, &y, align, width, buffer);
    return func_020a9bb4(data_0214d288[mode], data_0214d284[mode], x, y, style, buffer, 1);
}

/* Submit aligned formatted text to a caller-owned target via 020a9c88. */
void func_020aa078(void *target, int mode, int x, int y, u32 align, int width, int style, const char *format, ...)
{
    char buffer[32];
    void *args = (void *)(((u32)&format & ~3u) + 4);
    func_02013b94(buffer, sizeof(buffer), format, args);
    func_020a9f34(mode, &x, &y, align, width, buffer);
    func_020a9c88(target, data_0214d288[mode], data_0214d284[mode], x, y, style, buffer);
}
