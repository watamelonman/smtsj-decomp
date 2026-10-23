#include "types.h"

/* Only the state word and the three sub-block boundaries are known here. */
typedef struct Unk039520Work {
    u8 pad_0000[12];
    u32 state;
    u8 pad_0010[976];
    u8 unk_03e0[56];
    u8 unk_0418[0x208c];
    u8 unk_24a4[0xc0c];
} Unk039520Work;

u32 Unk05b540_Unk_05b7c0(void);
void Unk05b540_Unk_05b7ec(void);
void func_020587fc(void);
s32 func_02037dd4(Unk039520Work *work, void *context);
void func_0203812c(void *block, void *entries);
void func_0203845c(void *block);
s32 func_02037ec4(Unk039520Work *work, void *context);
void func_020385a4(Unk039520Work *work);
void func_0203875c(Unk039520Work *work);
void func_0205bb68(void);
void func_02058824(void);
void func_02058a1c(void *block, s32 index);
void func_020588ec(void *block, s32 index);
void func_02008848(void *destination, s32 value, u32 size);
void func_02058548(void *block);

/* Advance the five-state sequence using the +0x3e0 entries; null inputs finish immediately.
 * The state word and calls are evidenced by the original instructions at 02039520. */
s32 func_02039520(Unk039520Work *work, void *context)
{
    s32 done;
    if (work == 0) return 1;
    if (context == 0) return 1;
    done = 0;
    switch (work->state) {
    case 0:
        Unk05b540_Unk_05b7c0();
        func_020587fc();
        Unk05b540_Unk_05b7ec();
        work->state++;
    case 1:
        if (func_02037dd4(work, context)) work->state++;
        break;
    case 2:
        func_0203812c(work->unk_0418, work->unk_03e0);
        work->state++;
        break;
    case 3:
        if (func_02037ec4(work, context)) work->state++;
        break;
    case 4:
        func_020385a4(work);
        work->state = done;
        done = 1;
        break;
    }
    return done;
}

/* Advance the alternate five-state sequence; null inputs finish immediately.
 * The alternate +0x418 setup/finalization calls are evidenced at 020395f8. */
s32 func_020395f8(Unk039520Work *work, void *context)
{
    s32 done;
    if (work == 0) return 1;
    if (context == 0) return 1;
    done = 0;
    switch (work->state) {
    case 0:
        Unk05b540_Unk_05b7c0();
        func_020587fc();
        Unk05b540_Unk_05b7ec();
        work->state++;
    case 1:
        if (func_02037dd4(work, context)) work->state++;
        break;
    case 2:
        func_0203845c(work->unk_0418);
        work->state++;
        break;
    case 3:
        if (func_02037ec4(work, context)) work->state++;
        break;
    case 4:
        func_0203875c(work);
        work->state = done;
        done = 1;
        break;
    }
    return done;
}

/* Release 128 indexed items and three groups, then clear both owned sub-blocks.
 * Counts and extents come from the loop, calls and clear sizes at 020396cc;
 * a null work pointer is accepted. */
void func_020396cc(Unk039520Work *work)
{
    s32 i;
    if (work == 0) return;
    func_0205bb68();
    Unk05b540_Unk_05b7c0();
    func_02058824();
    for (i = 0; i < 128; i++) func_02058a1c(work->unk_24a4, i);
    func_020588ec(work->unk_24a4, 0);
    func_020588ec(work->unk_24a4, 1);
    func_020588ec(work->unk_24a4, 2);
    func_02008848(work->unk_24a4, 0, sizeof(work->unk_24a4));
    func_02058548(work->unk_0418);
    func_02008848(work->unk_0418, 0, sizeof(work->unk_0418));
}
