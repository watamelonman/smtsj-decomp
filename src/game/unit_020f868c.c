#include "types.h"

/* Only fields accessed by this unit are described; gaps retain original offsets. */
typedef struct Unk0f868cObject {
    u8 pad_0000[0x80];
    s32 unk_0080;
    u8 pad_0084[8];
    s32 unk_008c;
} Unk0f868cObject;

/* The two embedded buffers are opaque to this unit. */
typedef struct Unk0f868cWork {
    Unk0f868cObject *object;
    u8 pad_0004[0x11c];
    u32 unk_0120;
    u8 unk_0124[0x78];
    u32 unk_019c;
    u8 unk_01a0[0x72a0];
    s32 unk_7440;
    u8 pad_7444[0x3d];
    s8 state;
    s8 unk_7482;
    s8 unk_7483;
    s32 ticks;
} Unk0f868cWork;

/* Work-area fields observed at the call to func_02034b7c. */
typedef struct Unk0f868cArea {
    u8 pad_0000[0x358];
    u32 unk_0358;
    u16 unk_035c;
} Unk0f868cArea;

void func_02052d7c(void *buffer, u32 value);
void func_02052da0(void);
int func_02052728(void);
void Unk118b04_Unk_118e50(int selector, int value);
Unk0f868cArea *Unk02e000_GetWorkArea(void);
void func_02034b7c(int a, int b, int c, u32 d, int e, int f, int g, int h);
void Unk0a0ce4_Unk_0a0da4(int value);

/* Selects (11, 1), then passes the embedded buffer and its preceding word
 * to func_02052d7c; neither callee's meaning is established here. */
void Unk0f868c_Unk_0f868c(Unk0f868cWork *work)
{
    Unk118b04_Unk_118e50(11, 1);
    func_02052d7c(work->unk_0124, work->unk_0120);
}

/* Advances the four-state sequence, rounding scaled ticks to nearest (ties away from zero)
 * before adjusting the object's fields. Returns completion only in state 3
 * when the word at 0x7440 equals one; unknown states still advance ticks. */
int func_020f86b0(Unk0f868cWork *work)
{
    int result = 0;
    work->ticks++;
    switch (work->state) {
    case 0:
        func_02052da0();
        if (work->ticks > 10) {
            Unk0f868cArea *area = Unk02e000_GetWorkArea();
            Unk0f868cArea *other = Unk02e000_GetWorkArea();
            func_02034b7c(area->unk_035c - 1, work->unk_7482,
                         work->unk_7483, other->unk_0358, 3, 1, 0, 1);
            Unk0a0ce4_Unk_0a0da4(47);
            work->ticks = 0;
            work->state++;
        }
        break;
    case 1:
        work->object->unk_0080 -= (int)(0.15f * work->ticks > 0.0f
            ? 0.5f + 4096.0f * (0.15f * work->ticks)
            : 4096.0f * (0.15f * work->ticks) - 0.5f);
        work->object->unk_008c += (int)((float)work->ticks > 0.0f
            ? 0.5f + 4096.0f * work->ticks
            : 4096.0f * work->ticks - 0.5f);
        if (func_02052728() == 0) {
            work->ticks = 0;
            work->state++;
        }
        break;
    case 2:
        if (func_02052728() == 1) {
            func_02052d7c(work->unk_01a0, work->unk_019c);
            work->ticks = 0;
            work->state++;
        }
        break;
    case 3:
        if (work->ticks < 15) {
            int remaining = 15 - work->ticks;
            work->object->unk_008c += (int)(0.5f * remaining > 0.0f
                ? 0.5f + 4096.0f * (0.5f * remaining)
                : 4096.0f * (0.5f * remaining) - 0.5f);
        }
        func_02052da0();
        if (work->unk_7440 == 1)
            result = 1;
        break;
    }
    return result;
}
