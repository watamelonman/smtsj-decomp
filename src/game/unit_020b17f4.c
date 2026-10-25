#include "types.h"

/* Local callback object; offsets are established by the two ARM callbacks. */
typedef struct Unk0b17f4Work {
    u8 unk_00;
    s8 unk_01;
    u8 unk_02;
    u8 unk_03;
    s32 unk_04; /* Frames in the current state. */
    s32 unk_08; /* Total elapsed frames. */
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    s16 unk_18;
    s16 unk_1a;
} Unk0b17f4Work;

void func_02061424(Unk0b17f4Work *work);
int func_0205eae0(int from, int to, int duration, int frame);
int BattleTask_Unk_0481d4(void);
void func_02057eb8(int value);
void func_02057fd8(void);
void func_02057e18(int value);
void func_02057dcc(u32 a, u32 b, u32 c, u32 d);
void func_020580ec(int value);
void func_02057524(u32 value);
void func_02057534(void);
void Unk02e000_Unk_02e0cc(void);
u32 func_02059c70(u32 resource, int mode);
void func_02058e9c(u32 screen, u32 resource, int x, int y, float scale, int a, int b);
void func_02058c3c(u32 screen, u32 resource, int x, int y, float scale, int a, int b);
void func_020a9fd8(u32 mode, int x, int y, u32 align, int width, u32 size, const char *format, ...);
extern u32 data_0213c444[][2];
extern u32 data_0213c440[][2];
extern const char data_0214fefc[];

/* Advance both frame counters; states 0/1 last 8/24 frames, and states 2/3
 * invoke the external completion callback after eight frames. */
void func_020b17f4(Unk0b17f4Work *work)
{
    work->unk_04++;
    work->unk_08++;
    switch (work->unk_01) {
    case 0:
        if (work->unk_04 >= 8) {
            work->unk_01 = 1;
            work->unk_04 = 0;
        }
        break;
    case 1:
        if (work->unk_04 >= 24) {
            work->unk_01 = 2;
            work->unk_04 = 0;
        }
        break;
    case 2:
    case 3:
        if (work->unk_04 >= 8)
            func_02061424(work);
        break;
    }
}

/* Draw the state-dependent entry with interpolated opacity and vertical offset.
 * The resource and numeric paths follow the dispatch at 020b1980; their game
 * meaning is unknown, so fields and exported symbols retain neutral names. */
void func_020b1884(Unk0b17f4Work *work)
{
    int offset;
    int alpha = 0;
    switch (work->unk_01) {
    case 0: alpha = (u8)func_0205eae0(0, 31, 8, work->unk_04); break;
    case 1: alpha = 31; break;
    case 2: alpha = (u8)func_0205eae0(31, 0, 8, work->unk_04); break;
    }
    if (alpha != 0) {
        int x = work->unk_18;
        int y = work->unk_1a;
        offset = func_0205eae0(1, -16, 40, work->unk_08);
        if (BattleTask_Unk_0481d4())
            func_02057eb8(1);
        else
            func_02057eb8(2);
        if ((u32)alpha < 31)
            func_02057fd8();
        func_02057e18(alpha);
        func_02057dcc(data_0213c440[work->unk_02][0], data_0213c440[work->unk_02][0],
                      data_0213c444[work->unk_02][0], data_0213c444[work->unk_02][0]);
        func_020580ec(0);
        func_02057524(work->unk_14);
        switch (work->unk_00) {
        case 0: case 1: case 2: case 3: break;
        case 4:
            func_020a9fd8(work->unk_10, x, y + offset, 3, 1, work->unk_03 + 5, data_0214fefc, work->unk_0c);
            break;
        case 5: case 6: case 7: case 8: {
            int resource;
            u32 halfWidth;
            Unk02e000_Unk_02e0cc();
            resource = work->unk_0c;
            halfWidth = func_02059c70(resource + 0x6c00, 2) >> 1;
            if (x - (int)halfWidth < 0)
                x = halfWidth;
            else if (x + (int)halfWidth > 256)
                x = 256 - halfWidth;
            func_02058e9c(0x05000001, resource + 0x6c00, x, y + offset, 1.0f, 0, work->unk_03 + 5);
            break;
        }
        case 9:
            Unk02e000_Unk_02e0cc();
            func_02058c3c(0x05000001, 215, x, y + offset, 1.0f, 0, work->unk_03 + 5);
            break;
        }
        func_020580ec(1);
        func_02057534();
        func_02057eb8(-1);
    }
}
