#include "types.h"

/* Borrowed primary record; only fields evidenced by this unit are exposed. */
typedef struct {
    u8 pad00[0x12];
    s16 value12;
    u8 pad14[5];
    s8 value19;
    u8 pad1a[0x52];
    u16 state;
} Primary;

/* Borrowed secondary record; state is at +0x34 rather than +0x6c. */
typedef struct {
    u8 pad00[0xa];
    s16 value0a;
    u8 pad0c[5];
    s8 value11;
    u8 pad12[0x22];
    u16 state;
} Secondary;

/* Borrowed context fields cleared by phase zero. */
typedef struct {
    u8 pad00[0x34];
    int value34;
    int value38;
} Context;

/* Per-slot values have an eight-byte stride in func_020fb128. */
typedef struct {
    int active;
    int value;
} Slot;

/* Tail view keeps the original 0x7000 base used for stores. */
typedef struct {
    u8 pad000[0x480];
    s8 pending;
    s8 phase;
    u8 pad482[2];
    int repeats;
    u8 pad488[0x20];
    Slot slots[4];
    u8 pad4c8[0x24];
    int done;
} WorkTail;

/* Borrowed work view: signed phase bytes retain their original widths. */
typedef struct {
    Context *context;
    u8 pad04[0x6ffc];
    WorkTail tail;
} Work;

Primary *Unk02e000_Thunk_0202e788(void);
Secondary *Unk02e000_Unk_02e7c0(int index);
int Unk02f2a8_Unk_0366dc(int value);
void ScanVisor_Unk_0a379c(int index, int state);
void func_020fd0c8(int value);
int Unk0981dc_Unk_098324(int state, int previous);
int Unk09727c_GetPairHi(int index);
int Unk09727c_GetPairLo(int index);
int Unk0979d8_GetPairHi(Secondary *record, int index);
int Unk0979d8_GetPairLo(Secondary *record, int index);
u32 func_0203675c(int high, int low, int value);
u32 func_020368e8(int high, int low, int value);
u32 func_02050074(int low, int high);
void func_02035008(int value);
void func_02065bc0(void);
int func_020654cc(void);
void func_0204faf0(int index, int value);
void Unk095560_Unk_095778(int value);
void func_0206569c(void);
int func_02065cd0(void);
void func_02065c30(void);
int func_02030494(Context *context);
void func_02034f44(void);

/* Original +0xfb128: update four slots from present records whose state is not 1. */
void func_020fb128(Work *work)
{
    int i;
    for (i = 0; i < 4; i++) {
        int value;
        if (i == 0) {
            Primary *record = Unk02e000_Thunk_0202e788();
            if (record == 0 || record->state == 1) continue;
            value = record->value12;
            if (record->state == 2) record->state = 0;
        } else {
            Secondary *record = Unk02e000_Unk_02e7c0(i - 1);
            if (record == 0 || record->state == 1) continue;
            value = record->value0a;
            if (record->state == 2) record->state = 0;
        }
        value = Unk02f2a8_Unk_0366dc(value);
        work->tail.slots[i].active = 1;
        work->tail.slots[i].value -= value;
        ScanVisor_Unk_0a379c(i, 3);
    }
}

/* Original +0xfb1d0: reset the external mode, mark borrowed work complete, and return 1. */
int func_020fb1d0(Work *work)
{
    func_020fd0c8(0);
    work->tail.done = 1;
    return 1;
}

/* Original +0xfb1f0: use pair 9 and a random threshold to change eligible records to state 3. */
void func_020fb1f0(void)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (i == 0) {
            Primary *record = Unk02e000_Thunk_0202e788();
            if (record != 0 && Unk0981dc_Unk_098324(3, (s8)record->state) == 1) {
                int high = Unk09727c_GetPairHi(9);
                int low = Unk09727c_GetPairLo(9);
                u32 threshold = func_0203675c(high, low, record->value19);
                if (func_02050074(1, 100) < threshold) {
                    record->state = 3;
                    ScanVisor_Unk_0a379c(i, 3);
                }
            }
        } else {
            Secondary *record = Unk02e000_Unk_02e7c0(i - 1);
            if (record != 0 && Unk0981dc_Unk_098324(3, (s8)record->state) == 1) {
                int high = Unk0979d8_GetPairHi(record, 9);
                int low = Unk0979d8_GetPairLo(record, 9);
                u32 threshold = func_0203675c(high, low, record->value11);
                if (func_02050074(1, 100) < threshold) {
                    record->state = 3;
                    ScanVisor_Unk_0a379c(i, 3);
                }
            }
        }
    }
}

/* Original +0xfb31c: unconditional success callback, with no work ownership. */
int Unk0fb128_GetConst1(void) { return 1; }

/* Original +0xfb324: advance phases 0..6 on borrowed non-null work/context; return completion. */
int func_020fb324(Work *work)
{
    int result = 0;
    switch (work->tail.phase) {
    case 0:
        work->context->value38 = 0;
        work->context->value34 = 0;
        func_02035008(1);
        func_02065bc0();
        work->tail.phase++;
        break;
    case 1:
        if (func_020654cc() == 1) {
            func_0204faf0(1, work->tail.repeats = 3);
            Unk095560_Unk_095778(36);
            func_0206569c();
            work->tail.phase++;
        }
        break;
    case 2:
        if (func_02065cd0() == 1) {
            func_02035008(0);
            func_02065c30();
            work->tail.phase++;
        }
        break;
    case 3:
        if (func_020654cc() == 1) {
            if (func_02030494(work->context) == 1) {
                func_02034f44();
            } else {
                func_02065bc0();
                work->tail.phase++;
            }
        }
        break;
    case 4:
        if (func_020654cc() == 1) {
            if (--work->tail.repeats > 0) {
                func_0204faf0(1, work->tail.repeats);
                Unk095560_Unk_095778(37);
                func_0206569c();
                work->tail.phase = 2;
            } else {
                Unk02e000_Thunk_0202e788()->state = 0;
                Unk095560_Unk_095778(38);
                func_0206569c();
                work->tail.phase++;
            }
        }
        break;
    case 5:
        if (func_02065cd0() == 1) {
            func_02065c30();
            work->tail.phase++;
        }
        break;
    case 6:
        if (func_020654cc() == 1) result = 1;
        break;
    default:
        result = 1;
        break;
    }
    return result;
}

/* Original +0xfb504: use pair 8 to set state 2; primary success also sets pending. */
void func_020fb504(Work *work)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (i == 0) {
            Primary *record = Unk02e000_Thunk_0202e788();
            if (record != 0 && Unk0981dc_Unk_098324(2, (s8)record->state) == 1) {
                int high = Unk09727c_GetPairHi(8);
                int low = Unk09727c_GetPairLo(8);
                u32 threshold = func_020368e8(high, low, record->value19);
                if (func_02050074(1, 100) < threshold) {
                    record->state = 2;
                    work->tail.pending = 1;
                }
            }
        } else {
            Secondary *record = Unk02e000_Unk_02e7c0(i - 1);
            if (record != 0 && Unk0981dc_Unk_098324(2, (s8)record->state) == 1) {
                int high = Unk0979d8_GetPairHi(record, 8);
                int low = Unk0979d8_GetPairLo(record, 8);
                u32 threshold = func_020368e8(high, low, record->value11);
                if (func_02050074(1, 100) < threshold) record->state = 2;
            }
        }
    }
}

/* Original +0xfb614: return success unless pending is exactly 1; then return the phase result. */
int Unk0fb128_Unk_0fb614(Work *work)
{
    if (work->tail.pending != 1) return 1;
    return func_020fb324(work);
}
