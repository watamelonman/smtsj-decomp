/* Work-area sequence reconstructed from ARM field accesses and call order. */
#include "types.h"



/* Caller-owned work area; padding preserves the offsets used by the original TU. */
typedef struct Unk0edc78Work {
    s32 *owner;
    u8 pad_0004[0x54];
    u16 unk_0058;
    u8 pad_005a[0x4a];
    u32 unk_00a4;
    u8 pad_00a8[0x7324];
    s32 unk_73cc;
    s32 unk_73d0;
    u32 unk_73d4;
    s32 unk_73d8;
    u8 pad_73dc[0xa5];
    s8 state;
    u8 pad_7482[2];
    s32 ticks;
    u32 unk_7488;
    u32 unk_748c;
    u32 unk_7490;
} Unk0edc78Work;

int func_020edc78(Unk0edc78Work *work);
/* Forwards the caller-owned work area to the update routine; callback result is always zero. */
u32 Unk0edc78_Unk_0ee00c(Unk0edc78Work *work)
{
  func_020edc78(work);
  return 0;
}

/* Current-cell prefix; the halfword counts updates and wraps at 65536. */
typedef struct Unk0edc78Cell {
    u8 unk_0;
    u8 unk_1;
    u16 ticks;
} Unk0edc78Cell;

Unk0edc78Cell *Unk02f2a8_GetCurrentCell38e8(void);
u8 *Unk09a268_Unk_09c484(int index);
void Unk09a268_Unk_09a80c(Unk0edc78Cell *cell, int value);
void Unk09a268_Unk_09a830(Unk0edc78Cell *cell, int value);
void func_02052d7c(void *area, u32 value);
void Unk09a268_SetOnlyBit(Unk0edc78Cell *cell, int bit);
void Unk0a0ce4_Unk_0a0da4(int value);
/* Initializes current-cell flags from record 5 and starts the work-area operation. */
void Unk0edc78_Unk_0edf98(Unk0edc78Work *arg0)
{
  u8 *value1;
  Unk0edc78Cell *value2;
  value1 = Unk09a268_Unk_09c484(5);
  value2 = Unk02f2a8_GetCurrentCell38e8();
  Unk09a268_Unk_09a80c(value2,1);
  Unk09a268_Unk_09a830(value2,0);
  Unk09a268_SetOnlyBit(value2,value1[0x19]);
  value2->unk_1 = 1;
  value2->ticks = 0;
  Unk0a0ce4_Unk_0a0da4(arg0->unk_0058);
  func_02052d7c(arg0->pad_00a8,arg0->unk_00a4);
  arg0->unk_748c = 1;
  arg0->unk_7490 = 1;
}

void func_02052da0(Unk0edc78Cell *cell);
void Unk09a268_Unk_09a870(Unk0edc78Cell *cell, int value);
void func_0205257c(int value);
int func_02052728(void);
void ScanVisor_Unk_0a2acc(void);
void ScanVisor_Unk_0a2a8c(int index);
void ScanVisor_Unk_0a2b38(void);
void Unk095560_Unk_09615c(void);
void func_020396cc(void *area);
void Unk02f2a8_Unk_0343b4(void *area);
void Unk09974c_Unk_09974c(void *area);
void Unk11f2d0_Unk_11f2d0(void *area);
int func_020395f8(void *area, const void *data);
void ScanVisor_Unk_0a273c(int value);
void func_020525cc(int value);
void func_02058a90(void *area, int index);
int func_02053800(int first, int second);
void Unk0a4e48_Unk_0a4e9c(int value);
void func_0205e590(int value);
int func_020a4f3c(void);
extern const u8 data_02150dc4[];

/* Advances the caller-owned nine-state sequence, polling completion and counting
 * updates. Field accesses and ScanVisor calls establish the behavior; the wider
 * purpose of this sequence is unknown, so the original neutral name is retained. */
int func_020edc78(Unk0edc78Work *work)
{
    Unk0edc78Cell *cell = Unk02f2a8_GetCurrentCell38e8();
    int result = 0;
    int i;
    func_02052da0(cell);
    work->ticks++;
    cell->ticks++;
    switch (work->state) {
    case 0:
        if (work->ticks > 40) {
            Unk09a268_Unk_09a870(cell, 0);
            work->owner[5] = 2;
            work->owner[6] = 2;
            work->ticks = 0;
            work->state++;
        }
        break;
    case 1:
        if (work->ticks > 10) {
            func_0205257c(3);
            work->ticks = 0;
            work->state++;
        }
        break;
    case 2:
        if (func_02052728() == 0) {
            ScanVisor_Unk_0a2acc();
            for (i = 0; i < 7; i++) ScanVisor_Unk_0a2a8c(i);
            work->unk_73d8 = 0;
            ScanVisor_Unk_0a2b38();
            Unk095560_Unk_09615c();
            func_020396cc(work->pad_0004);
            Unk02f2a8_Unk_0343b4(work->pad_0004);
            Unk09974c_Unk_09974c((u8 *)work + 0x7550);
            Unk11f2d0_Unk_11f2d0((u8 *)work + 0x7598);
            work->ticks = 0;
            work->state++;
        }
        break;
    case 3:
        if (work->ticks > 2 && func_020395f8(work->pad_0004, data_02150dc4) == 1) {
            ScanVisor_Unk_0a273c(0);
            func_020525cc(3);
            Unk0a0ce4_Unk_0a0da4(46);
            work->ticks = 0;
            work->state++;
        }
        break;
    case 4:
        for (i = 0; i < 128; i++) func_02058a90(work->pad_00a8 + 0x2400, i);
        if (func_02052728() == 0) {
            work->ticks = 0;
            work->state++;
        }
        break;
    case 5:
        for (i = 0; i < 128; i++) func_02058a90(work->pad_00a8 + 0x2400, i);
        if (func_02053800(0, 3) == 1 || work->ticks > 300) {
            func_0205257c(3);
            Unk0a4e48_Unk_0a4e9c(2);
            func_0205e590(9);
            work->ticks = 0;
            work->state++;
        }
        break;
    case 6:
        for (i = 0; i < 128; i++) func_02058a90(work->pad_00a8 + 0x2400, i);
        if (func_020a4f3c() == 0 && func_02052728() == 0) {
            work->ticks = 0;
            work->state++;
        }
        break;
    case 7:
        work->unk_73d0 = 8;
        work->unk_73cc = 12;
        work->ticks = 0;
        work->state++;
        break;
    case 8:
        break;
    default:
        result = 1;
        break;
    }
    return result;
}
