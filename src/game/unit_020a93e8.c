#include "types.h"

/* The caller-owned handle is read at byte 0x14 by the original ARM code. */
typedef struct Unk0a93e8Work {
    u8 pad_0000[0x14];
    int handle;
} Unk0a93e8Work;

/* Draw packet: four clipping coordinates follow nine words of setup data. */
typedef struct Unk0a93e8Packet {
    u32 setup[9];
    int left, right, top, bottom;
    u32 tail;
} Unk0a93e8Packet;
void func_02058bf8(Unk0a93e8Packet *, u32, int, int, int, int, int);
void func_020574d4(void);
void *Unk02e000_GetAddr_data_02140ac8(void);
void func_02058f84(int, Unk0a93e8Packet *, void *);
void func_0205de40(int, int, int, int, int, float, float, int, float, int);
void func_02057eb8(int);
void func_02057dcc(int, u32, u32, int);
void func_02057d54(int, int, int, int, int, int);
void func_02057df8(void);

/* ARM 020a93e8: reject empty bounds, prepare a packet and submit it with
 * graphics register 0x04000440 set to mode 2 for the duration of submission. */
void func_020a93e8(int id, int x, int y, int top, int left, int bottom, int right, int a, int b, int c)
{
    Unk0a93e8Packet p;
    if (bottom - top <= 0) return;
    if (right - left <= 0) return;
    func_02058bf8(&p, 0x20001, x, y, a, b, c);
    p.left = left; p.right = right; p.top = top; p.bottom = bottom;
    func_020574d4();
    *(volatile u32 *)0x04000440 = 2;
    *(volatile u32 *)0x04000444 = 0;
    func_02058f84(id, &p, Unk02e000_GetAddr_data_02140ac8());
    *(volatile u32 *)0x04000448 = 1;
}

/* ARM 020a94bc: same packet submission with caller-supplied flags and bounds. */
void func_020a94bc(u32 flags, int id, int x, int y, int top, int left, int bottom, int right, int a, int b, int c)
{
    Unk0a93e8Packet p;
    if (bottom - top <= 0) return;
    if (right - left <= 0) return;
    func_02058bf8(&p, flags | 0x20001, x, y, a, b, c);
    p.left = left; p.right = right; p.top = top; p.bottom = bottom;
    func_020574d4();
    *(volatile u32 *)0x04000440 = 2;
    *(volatile u32 *)0x04000444 = 0;
    func_02058f84(id, &p, Unk02e000_GetAddr_data_02140ac8());
    *(volatile u32 *)0x04000448 = 1;
}

/* ARM 020a9588: submit paired handle entries 2 and 3 with opposing offsets;
 * the original uses level 9 as the unscaled endpoint. */
void func_020a9588(Unk0a93e8Work *w, int level)
{
    float sx = 1.0f;
    float sy = 1.0f;
    int offset = 0;
    if (level != 9) {
        sy = (float)((100 * level) / 9) / 100.0f;
        offset = ((9 - level) * 32) / 9;
    }
    func_02057eb8(2);
    func_0205de40(2, w->handle, 2, 0, offset, sx, sy, 0, 1.0f, 11);
    func_0205de40(2, w->handle, 3, 0, -offset, sx, sy, 0, 1.0f, 11);
    func_02057eb8(-1);
}

/* ARM 020a97b4: forward position and handle to entry 26 with unit scale. */
void func_020a97b4(Unk0a93e8Work *w, int x, int y)
{
    func_0205de40(2, w->handle, 26, x, y, 1.0f, 1.0f, 0, 1.0f, 14);
}

/* ARM 020a966c: wrap phase modulo 30 and submit the two clipped pieces
 * of entry 3072 beside the caller's position. */
void func_020a966c(Unk0a93e8Work *w, int x, int y, int phase)
{
    int r;
    int start, end;
    func_0205de40(2, w->handle, 14, x, y, 1.0f, 1.0f, 0, 1.0f, 14);
    r = phase % 30;
    start = r + 34;
    end = start + 30 - r;
    func_020a93e8(3072, x + 217, y + 87, 0, start, 27, end, 31, ((end - start) * 39) / 30, 14);
    start = r + 34;
    func_020a93e8(3072, x + 217, y + 87 + ((30 - r) * 39) / 30, 0, 34, 27, start, 31, ((start - 34) * 39) / 30, 14);
}

/* ARM 020a97fc: submit entries 5 and 7, adding two proportional spans
 * when amount is positive, then restore the drawing state. */
void func_020a97fc(Unk0a93e8Work *w, int amount)
{
    int width;
    float scale = 1.0f;
    func_0205de40(2, w->handle, 5, 0, 0, scale, scale, 0, 1.0f, 13);
    func_02057dcc(-1, 0xb9191d00, 0xb9191d00, -1);
    func_0205de40(2, w->handle, 7, 0, 0, scale, scale, 0, 1.0f, 13);
    if (amount > 0) {
        width = (amount * 80) / 140;
        func_02057d54(0, 53, 41, 1, width, 14);
        func_02057d54(0, 202, 41, 1, width, 14);
    }
    func_02057df8();
}

