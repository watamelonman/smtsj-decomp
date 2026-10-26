#include "types.h"

/* Layout is local to this callback; gaps preserve the observed ARM field offsets. */
typedef struct Unk11e6b8Work {
    u32 state;
    u32 unk_0004;
    s32 count;
    u32 unk_000c;
    s32 first;
    u32 unk_0014;
    s32 selected;
    u8 pad_001c[0x8c];
    void **entries;
    s32 total;
    u8 pad_00b0[0x1c8];
    void *images;
    u8 pad_027c[12];
    void *palette;
    u32 unk_028c;
    void *unk_0290;
    u32 unk_0294;
    void *unk_0298;
    void *unk_029c;
    void *unk_02a0;
    void *unk_02a4;
    void *rows[11]; /* Space before the next observed field, not an inferred capacity. */
    void **unk_02d4;
    void **unk_02d8;
    void **unk_02dc;
    u32 unk_02e0;
    s32 unk_02e4;
    u8 pad_02e8[44];
    s32 unk_0314;
    s32 unk_0318;
} Unk11e6b8Work;

/* Borrowed image metadata is copied into this 24-byte mutable stack view. */
typedef struct Unk11e6b8Image {
    s16 unk_0000[5];
    s16 y;
    s16 unk_000c;
    s16 height;
    s16 unk_0010[4];
} Unk11e6b8Image;

/* Text helper output occupies four words; units of unknown fields are unproven. */
typedef struct Unk11e6b8Rect {
    s32 unk_0000, unk_0004, unk_0008, unk_000c;
} Unk11e6b8Rect;

extern const u16 data_02151d14[];
extern void func_020580ec(s32 enabled);
extern void func_02057524(s32 value);
extern void Unk_LoadPalette_020de678(void *palette);
extern void func_02057534(void);
extern void func_02057df8(void);
extern void func_02057e18(s32 value);
extern void func_02057ddc(u32 value);
extern void func_0205c748(s32 layer, void *image, s32 x, s32 y, float sx, float sy, s32 rotation,
                          float alpha, s32 flags);
extern void func_0205de40(s32 layer, void *images, s32 index, s32 x, s32 y, float sx, float sy,
                          s32 rotation, float alpha, s32 flags);
extern void *func_0205e318(void *images, s32 index);
extern void func_02008904(const void *src, void *dst, u32 bytes);
extern void func_0205e048(s32 layer, void *images, Unk11e6b8Image *image, s32 x, s32 y, float sx,
                          float sy, s32 rotation, float alpha, s32 flags, s32 extra);
extern s32 Unk118b04_Unk_118b78(void *entry);
extern s32 Unk118b04_Unk_118ba8(void *entry);
extern void func_02060dd4(Unk11e6b8Rect *rect, void **text, s32 a, s32 b, s32 c);
extern void func_02059f70(void *text, u32 flags, s32 x, s32 y, Unk11e6b8Rect *rect, s32 a, s32 b);

/* Draws the state-dependent list UI; evidence: image calls at 0205de40,
 * text calls at 02059f70, 13-pixel row spacing and proportional scroll thumb.
 * Borrows a valid work area and its resources for the duration of the draw.
 * The screen's identity is unknown, so retain the original neutral symbol. */
void func_0211e6b8(Unk11e6b8Work *w)
{
    Unk11e6b8Image image;
    Unk11e6b8Rect rect;
    Unk11e6b8Rect rowRect;
    s32 i;
    void *entry;
    s32 first;
    s32 y;
    if (w->state == 4)
        return;
    func_020580ec(0);
    func_02057524(0);
    Unk_LoadPalette_020de678(w->palette);
    func_02057534();
    func_02057df8();
    func_02057e18(31);
    switch (w->state) {
    case 0:
    case 1:
        func_0205c748(2, w->unk_0298, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        func_0205c748(2, w->unk_0290, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        break;
    case 2:
    case 3:
        first = w->first;
        for (u32 j = 0; j < 2; j++)
            func_0205de40(2, w->images, data_02151d14[j], 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        func_02057ddc(0xffffff);
        func_0205de40(2, w->images, 4, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        func_02057df8();
        func_02008904(func_0205e318(w->images, 14), &image, 24);
        {
            s32 thumb;
            s32 height;
            s32 total = w->total;
            s32 pages = (total + 10) / 11;
            if (pages > 1) {
                height = image.height;
                thumb = height / pages;
                if (thumb < 4)
                    thumb = 4;
                if (first + 11 >= total)
                    image.y += height - thumb;
                else {
                    s32 offset = height * first / total;
                    if (offset + thumb > height)
                        offset = height - thumb;
                    image.y += offset;
                }
                image.height = thumb;
            }
        }
        func_0205e048(2, w->images, &image, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5, 0);
        func_0205c748(2, w->unk_0298, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        y = (w->selected - w->first) * 13;
        func_0205de40(2, w->images, 12, 0, y, 1.0f, 1.0f, 0, 1.0f, 5);
        func_0205c748(2, w->unk_029c, 0, y, 1.0f, 1.0f, 0, 1.0f, 5);
        for (i = 0; i < w->count; i++) {
            entry = w->entries[first + i];
            func_0205de40(2, w->images, 7, 0, i * 13, 1.0f, 1.0f, 0, 1.0f, 5);
            if (Unk118b04_Unk_118b78(entry)) {
                func_0205de40(2, w->images, 6, 0, i * 13, 1.0f, 1.0f, 0, 1.0f, 5);
                if (Unk118b04_Unk_118ba8(entry)) {
                    func_0205de40(2, w->images, 10, 0, i * 13, 1.0f, 1.0f, 0, 1.0f, 5);
                    func_0205c748(2, w->rows[i], 0, i * 13, 1.0f, 1.0f, 0, 1.0f, 5);
                }
            }
        }
        if (w->unk_02e4 >= 0)
            func_0205c748(2, w->unk_02a0, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        if (w->unk_02e4 <= 0)
            func_0205c748(2, w->unk_02a4, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        func_02057e18(31);
        func_02060dd4(&rect, w->unk_02dc, 0, 0, 10);
        func_02059f70(*w->unk_02dc, 1, 3, -2, &rect, 0, 10);
        func_02060dd4(&rect, w->unk_02d4, 0, 0, 10);
        rect.unk_000c = rect.unk_0008 + w->unk_0314;
        func_02059f70(*w->unk_02d4, 0x1000001, 184, 9, &rect, 0, 10);
        if (w->unk_0318 == 0) {
            for (s32 j = 0; j < w->count; j++) {
                func_02060dd4(&rowRect, w->unk_02d8, 0, j, 22);
                func_02059f70(*w->unk_02d8, 1, 37, 24 + j * 13, &rowRect, 0, 10);
            }
        }
        break;
    }
    func_020580ec(1);
}
