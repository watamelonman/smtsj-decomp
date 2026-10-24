#include "types.h"

/* Partial views: only fields accessed by this unit have established offsets. */
typedef struct Unk0466a4Item {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    s32 unk_14;
} Unk0466a4Item;
typedef struct Unk0466a4Work {
    u32 unk_00;
    u8 pad_04[0x1de];
    u16 unk_1e2;
} Unk0466a4Work;
typedef struct Unk0466a4Global {
    u8 pad_00[0x40];
    u32 unk_40;
    u8 pad_44[0x20];
    Unk0466a4Work *unk_64[10];
} Unk0466a4Global;
typedef struct Unk0466a4Record {
    u8 pad_00[0x22];
    u8 unk_22;
} Unk0466a4Record;
typedef struct Unk0466a4Flags {
    u8 pad_00[0x2f];
    u8 unk_2f;
} Unk0466a4Flags;

void Unk044904_Unk_044fd8(void);
Unk0466a4Item *Unk0aa118_PeekItem(void);
u32 Unk044904_Unk_045080(void);
int func_020f8098(u32 value, int mode, u32 key);
Unk0466a4Work *func_02044ec4(u32 key);
void func_0204a780(Unk0466a4Work *work, int value);
void func_020451d8(void);
int func_020aa964(Unk0466a4Item *item);
int func_020b081c(int mode);
int func_0204a7f4(Unk0466a4Work *work, int value);
int func_0204abd8(Unk0466a4Work *work, int value);
int func_020b0a5c(Unk0466a4Work *work);
int func_020b0adc(Unk0466a4Work *work);
void func_0204f0d4(void);
void func_0204f59c(int mode, u32 key, int value);
void func_0204f5e0(int mode, u32 key, int value);
void func_0204f24c(int mode, u32 key, int value, int kind, int zero, int one);
void func_0204f364(int mode, u32 key, int value);
int func_0204ab58(Unk0466a4Work *work, int value);
Unk0466a4Global *Unk044904_Get_data_0215ee98(void);
void func_020a02c0(u32 key, int a, int b, int flag);
Unk0466a4Record *func_020cb1a0(u32 key);
void func_02049fec(Unk0466a4Work *work, int mode, int value);
Unk0466a4Flags *Unk09974c_Unk_099d14(u32 key);
void func_02099b10(u32 key, int value);
void Unk044904_ForEachSlot_04a694(void);
void ScanVisor_Unk_0a29c4(int slot);
void func_020b801c(u32 key);

/* Checks the current item; status is changed only for missing or rejected items.
 * The output must point to a writable halfword. Purpose beyond this is unknown. */
u32 Unk0466a4_Unk_0466a4(u16 *status)
{
    Unk0466a4Item *item;
    Unk044904_Unk_044fd8();
    item = Unk0aa118_PeekItem();
    if (item == 0) {
        *status = 2;
    } else if (func_020f8098(Unk044904_Unk_045080(), 1, item->unk_00) != 0) {
        *status = 3;
    }
    return 2;
}

/* Processes the current item and its work record, then refreshes its slot.
 * The current item and resolved work record must exist; status is writable. */
u32 func_020466e8(u16 *status)
{
    Unk0466a4Item *item;
    Unk0466a4Work *work;
    int result;
    int first;
    int second;
    Unk044904_Unk_044fd8();
    item = Unk0aa118_PeekItem();
    work = func_02044ec4(item->unk_00);
    if (work != 0) {
        func_0204a780(work, 5);
        item->unk_14 = -1;
    }
    func_020451d8();
    result = func_020aa964(item);
    if (result > 0 && !func_020b081c(1) && !func_020b081c(2)
        && !func_0204a7f4(work, 13)
        && !(((work->unk_00 >> 16) & 255) == 2 && item->unk_08 == 4)
        && !func_0204abd8(work, 0)) {
        first = func_020b0a5c(work);
        second = func_020b0adc(work);
        if (first != 0 || second != 0) {
            func_0204f0d4();
            if (first != 0) {
                func_0204f59c(0, work->unk_00, first);
                func_0204f24c(0, work->unk_00, first, 0, 0, 1);
                func_0204f364(0, work->unk_00, 0);
                if (func_0204ab58(work, first)) {
                    first = ((Unk044904_Get_data_0215ee98()->unk_40 << 20) >> 31)
                        && func_020b081c(2) ? 1 : 0;
                    func_0204f0d4();
                    func_020a02c0(work->unk_00, 0, 0, first);
                }
            }
            if (second != 0) {
                func_0204f5e0(0, work->unk_00, second);
                func_0204f24c(0, work->unk_00, second, 2, 0, 1);
            }
        }
    }
    func_020451d8();
    if (result < 0) {
        *status = 2;
        return 1;
    }
    if (result == 0) return 1;
    if (result == 1) {
        switch (item->unk_08) {
        case 1:
        case 2:
            work->unk_1e2++;
            break;
        case 6:
            func_02049fec(work, 1, -func_020cb1a0(item->unk_0c)->unk_22);
            work->unk_1e2++;
            break;
        case 5:
            result = item->unk_0c;
            if (!((u32)Unk09974c_Unk_099d14(result)->unk_2f << 31 >> 31))
                func_02099b10(result, 1);
            break;
        }
    }
    Unk044904_ForEachSlot_04a694();
    if (((work->unk_00 >> 16) & 255) == 1) {
        int i;
        for (i = 0; i < 10; i++) {
            if (work == Unk044904_Get_data_0215ee98()->unk_64[i]) {
                ScanVisor_Unk_0a29c4(i);
                break;
            }
        }
    } else if (((item->unk_00 >> 16) & 255) == 2) {
        func_020b801c(item->unk_00);
    }
    return 1;
}
