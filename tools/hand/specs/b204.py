PRE = r'''s32 Unk02e000_GetRecordUnk1e(u32 id);
void func_0203f394(void *a, void *b, int x, int y, int sx, int sy, u16 width, int height);
'''

F3DC4 = r'''/* Draws the 60-pixel record gauge at (x, y): the record count and the two
 * record thresholds (+0x5a, +0x5b) are scaled from 0..100 to 0..60 in 12-bit
 * fixed point. A count of 100 or more draws the full bar; otherwise a tick
 * marks each reached threshold and the three segments are drawn from
 * different source rows. */
void func_020b3dc4(u32 id, void *dst, void *src, u32 x, s32 y)
{
    Unk0b28e4IconRecord *record = func_020a1740(id);
    s32 len = (Unk02e000_GetRecordUnk1e(id) * 0x1000 / 10 * 6) >> 12;
    u16 first = (record->unk_5a * 0x1000 / 10 * 6) >> 12;
    u16 second = (record->unk_5b * 0x1000 / 10 * 6) >> 12;
    s16 a;
    s16 b;
    s16 c;

    if (len <= 0) {
        return;
    }
    if (Unk02e000_GetRecordUnk1e(id) >= 100) {
        func_0203f394(dst, src, x, y - 2, 192, 128, 60, 6);
        return;
    }
    if (len >= first) {
        a = first - 1;
        func_0203f394(dst, src, x + first - 1, y, 192, 8, 1, 3);
    } else {
        a = len;
    }
    if (len >= second) {
        b = second - first - 1;
        func_0203f394(dst, src, x + second - 1, y, 192, 8, 1, 3);
    } else {
        b = len - first;
    }
    c = len - second;
    if (a > 0) {
        func_0203f394(dst, src, x, y, 128, 0, a, 3);
    }
    if (b > 0) {
        func_0203f394(dst, src, x + first, y, 128, 8, b, 3);
    }
    if (c > 0) {
        func_0203f394(dst, src, x + second, y, 192, 0, c, 3);
    }
}'''

SPECS = [('src/game/unit_020b28e4.c', [('func_020b3dc4', F3DC4)], PRE)]
