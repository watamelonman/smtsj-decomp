#include "types.h"

/* Borrowed views: only fields read by this drawing callback are exposed. */
typedef struct Animation0fb858 {
    u8 pad_00[0x18];
    s32 offset;
} Animation0fb858;
typedef struct Text0fb858 {
    u32 handle;
} Text0fb858;
typedef struct Work0fb858 {
    s32 state;
    u8 list[0x24];
    s32 current;
    s32 pending;
    Text0fb858 *rows;
    Text0fb858 *caption;
    u16 first;
    u8 pad_3a[2];
    s32 count;
    Animation0fb858 *intro[3];
    Animation0fb858 *more;
    s32 has_more;
    u32 resource;
} Work0fb858;
/* A copied 24-byte draw descriptor; signed coordinates are adjusted in pixels. */
typedef struct Clip0fb858 {
    u8 pad_00[10];
    s16 y;
    s16 unk_0c;
    s16 height;
    u8 pad_10[8];
} Clip0fb858;
extern const u8 data_0213c988[];
void func_02057524(u32 mode);
void func_02057534(void);
void func_0205c748(int screen, Animation0fb858 *anim, int x, int y,
    float sx, float sy, int rotation, float alpha, int layer);
void func_0205de40(int screen, u32 resource, int id, int x, int y,
    float sx, float sy, int rotation, float alpha, int layer);
void func_0205dee8(int screen, u32 resource, int id, int x, int y,
    float sx, float sy, int rotation, float alpha, int layer);
const Clip0fb858 *func_0205e318(u32 resource, int id);
void func_02008904(const void *source, void *dest, u32 size);
void func_0205e048(int screen, u32 resource, Clip0fb858 *clip, int x, int y,
    float sx, float sy, int rotation, float alpha, int layer, int extra);
void func_02057df8(void);
void func_02057e18(u32 alpha);
void func_02057ddc(u32 color);
void func_02057fd8(void);
void func_02060dd4(void *out, Text0fb858 *text, int a, int row, int count);
void func_02059f70(u32 handle, int mode, int x, int y, const void *options,
    int flags, int layer);
s32 Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e6448(s32 id);

/* Draw the paged-list work block without changing it. Evidence: the constructor
 * func_020fbde4 installs this callback alongside the list updater func_020fb634.
 * Descriptors are copied before clipping; all resource handles remain borrowed. */
void func_020fb858(Work0fb858 *work)
{
    Clip0fb858 intro_clip;
    s32 text[4];
    Clip0fb858 clip;
    func_02057524(4);
    switch (work->state) {
    case 0:
        return;
    case 3:
        func_0205c748(2, work->intro[2], 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        /* fallthrough */
    case 2:
        func_0205c748(2, work->intro[1], 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        /* fallthrough */
    case 1:
        func_0205c748(2, work->intro[0], 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        func_0205de40(2, work->resource, 23, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        func_02008904(func_0205e318(work->resource, 59), &intro_clip, 24);
        intro_clip.height += work->intro[0]->offset;
        if (intro_clip.height != 0) {
            func_0205e048(2, work->resource, &intro_clip, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5, 0);
        }
        break;
    default: {
        u32 i;
        for (i = 0; i < 5; i++) {
            func_0205de40(2, work->resource, data_0213c988[i], 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        }
        if (work->state == 4) {
            s32 row;
            s32 y;
            s32 shadow_y;
            func_02057df8();
            func_02057e18(31);
            y = 51;
            shadow_y = 52;
            for (row = 0; row < 10; row++) {
                func_02060dd4(text, work->rows, 0, row, 25);
                func_02057df8();
                func_02059f70(work->rows->handle, 1, 12, y, text, 0, 9);
                func_02057ddc(255);
                func_02059f70(work->rows->handle, 1, 12, shadow_y, text, 0, 9);
                y += 13;
                shadow_y += 13;
            }
            func_02057df8();
        }
        if (work->has_more != 0) {
            func_0205c748(2, work->more, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        }
        func_02008904(func_0205e318(work->resource, 56), &clip, 24);
        {
            s32 pages = (work->count + 9) / 10;
            if (pages > 1) {
                s32 height = clip.height / pages;
                clip.y += height * ((work->first + 9) / 10);
                clip.height = height;
            }
        }
        func_0205e048(2, work->resource, &clip, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5, 0);
        func_02057e18(31);
        func_02057ddc(0x39f7efff);
        func_02060dd4(text, work->caption, 0, 0, 25);
        func_02059f70(work->caption->handle, 1, 12, 36, text, 0, 9);
        func_02057df8();
        if (Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e6448(work->current) == 2) {
            func_02057fd8();
            func_02057ddc(0xca6a68ff);
            func_0205dee8(2, work->resource, 19, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
            func_02057df8();
        }
        break;
    }
    }
    func_02057534();
}
