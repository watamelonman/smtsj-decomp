/* Font selection, formatted measurement, and aligned text submission. */
#include "types.h"

/* Borrowed 12-byte record: source u/v and unsigned pixel extents at +4/+6. */
typedef struct { u16 u, v, height, extent; u8 tail[4]; } Glyph;
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

void func_02058e9c(u32 flags, int glyph, int x, int y, float scale, int unused, int style);
FontSlot *func_0205ad9c(int slot);
void func_0205a508(void *target, FontSlot *font, int *source, int *dest, int style);
void func_0205a0d8(void *target, u16 x, u16 y, int color);

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

/* Convert signed text bytes to offsets in the selected glyph run. The switch
 * constants and base adjustment are evidenced by the original instruction table. */
int func_020a9ac8(signed char character, int base)
{
    int glyph;
    switch (character) {
    case '+': return 10;
    case '-': return 11;
    case '/': return 12;
    case '*': glyph = 23; if (base) glyph -= base; return glyph;
    case '%': glyph = 24; if (base) glyph -= base; return glyph;
    case '=': glyph = 25; if (base) glyph -= base; return glyph;
    case '?': glyph = 26; if (base) glyph -= base; return glyph;
    case ' ': return 0;
    case 'h': glyph = 27; if (base) glyph -= base; return glyph;
    default: return character - '0';
    }
}

/* Signed cursor tests and converted byte arguments retain the original loads.
 * See DEC-009. */

/* Accumulate unsigned glyph widths from valid slot/glyph indices and NUL text,
 * optionally drawing non-space bytes.
 * Evidence: +4 glyph metric and calls to the sprite submission routine. */
int func_020a9bb4(int slot, int glyph, int x, int y, int style, const char *text, int draw)
{
    const signed char *cursor;
    int advance;
    int width;
    u32 flags;
    Glyph *run;
    Unk02e000_Unk_02e0cc();
    run = &func_0205ad8c()[slot].font->glyphs[glyph];
    cursor = (const signed char *)text;
    width = 0;
    flags = 1;
    if (*cursor) do {
        int index = func_020a9ac8((s8)*(const u8 *)cursor, glyph);
        advance = run[index].height;
        if (draw && *cursor != ' ') {
            func_02058e9c(flags, glyph + (index + (slot << 7)), x + width, y, 1.0f, 0, style);
            flags |= 0x40000000;
        }
        width += advance;
    } while (*++cursor);
    return width;
}

/* Copy glyph rectangles into a borrowed target; spaces clear the same rectangle.
 * Text must be NUL-terminated and select valid glyphs; coordinates are pixels.
 * Evidence: glyph halfwords supply source bounds, and 0205a0d8 writes zero pixels. */
void func_020a9c88(void *target, int slot, int glyph, int x, int y, int style, const char *text)
{
    FontSlot *font;
    Glyph *run;
    int width;
    const signed char *cursor;
    Glyph *entry;
    int dest[4];
    int source[4];
    int row;
    int column;
    Unk02e000_Unk_02e0cc();
    font = func_0205ad9c(slot);
    cursor = (const signed char *)text;
    run = &font->font->glyphs[glyph];
    width = 0;
    if (*cursor) do {
        entry = &run[func_020a9ac8((s8)*(const u8 *)cursor, glyph)];
        dest[0] = y;
        dest[1] = y + entry->extent;
        dest[2] = x + width;
        dest[3] = entry->height + dest[2];
        if (*cursor != ' ') {
            source[0] = entry->v;
            source[1] = entry->v + entry->extent;
            source[2] = entry->u;
            source[3] = entry->u + entry->height;
            func_0205a508(target, font, source, dest, style);
        } else {
            for (row = y; row < dest[1]; ++row) {
                for (column = dest[2]; column < dest[3]; ++column) {
                    func_0205a0d8(target, (u16)column, (u16)row, 0);
                }
            }
        }
        width += entry->height;
    } while (*++cursor);
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
