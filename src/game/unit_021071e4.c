#include "types.h"

/* Partial work layout: offsets are established by the target loads and stores. */
typedef struct Unk1071e4Work {
    u8 pad_0000[8];
    u32 handles[6];
    u32 selected;
    s32 count;
    u8 pad_0028;
    u8 state;
    u8 pad_002a[18];
    s8 records[1];
} Unk1071e4Work;

void func_020bc9f4(int id, int value);
void func_020bcacc(int id, int value);
void Unk096754_CopyAreaPos(Unk1071e4Work *work);
u8 *Unk02e000_GetAreaRecord(int index);
void Unk0979d8_ResetFields(u8 *record);
void Unk096754_ResetAreaPos(void);
u32 Unk0979d8_Unk_0979fc(u8 *record);
void func_0205c41c(u32 handle, int value);
void func_0205caa8(u32 handle, u32 value);
extern u32 data_0213c9ac[];
u8 *Unk09727c_GetAreaSub48(void);
u32 func_02063a30(u8 *sub);
void func_02061f10(u32 value, int index, int a, int b, u32 result);
int Unk1071e4_IsNot1or7(int value);

/* Target calls reset IDs 19 and 18, then writes state byte +0x29 to 4. */
void Unk1071e4_Unk_107c34(Unk1071e4Work *work)
{
    func_020bc9f4(19, 0);
    func_020bcacc(18, 0);
    work->state = 4;
}

/* Target uses the category predicate to gate a three-column coordinate delta. */
int Unk1071e4_Unk_1087f4(int category, int x, int y, int otherX, s16 otherY)
{
    if (Unk1071e4_IsNot1or7(category)) {
        return (otherX - x) + (otherY - y) * 3;
    }
    return 0;
}

/* Target chooses the position copy for index zero; other indices select signed record IDs. */
void Unk1071e4_Unk_1088fc(Unk1071e4Work *work)
{
    if (work->selected == 0) {
        Unk096754_CopyAreaPos(work);
        return;
    }
    Unk0979d8_ResetFields(Unk02e000_GetAreaRecord(FIELD(s8, (u8 *)work + work->selected, 59)));
}

/* Target maps categories 0/1/7 to 0/(offset+300)/200 and all others to 100. */
int func_02108928(int category, int unused, int offset)
{
    if (category == 0) return 0;
    switch (category) {
    case 1: return offset + 300;
    case 7: return 200;
    default: return 100;
    }
}

/* Target resets area position, then visits count-1 signed record IDs at +0x3c. */
void func_02108aa4(Unk1071e4Work *work)
{
    int i;
    Unk096754_ResetAreaPos();
    for (i = 0; i < work->count - 1; i++) {
        Unk0979d8_Unk_0979fc(Unk02e000_GetAreaRecord(work->records[i]));
    }
}

/* Target indexes handles at +8 and a parallel global table; caller supplies a valid index. */
void Unk1071e4_Unk_108b08(Unk1071e4Work *work, int index)
{
    func_0205c41c(work->handles[index], 0);
    func_0205caa8(work->handles[index], data_0213c9ac[index]);
}

/* Target forwards the area subrecord query result as the fifth argument, with index -1. */
void Unk1071e4_Unk_108b94(u32 value)
{
    func_02061f10(value, -1, 0, 0, func_02063a30(Unk09727c_GetAreaSub48()));
}

/* Comparisons in the target establish that only categories 1 and 7 return false. */
int Unk1071e4_IsNot1or7(int value)
{
    switch (value) {
    case 1:
    case 7:
        return 0;
    }
    return 1;
}
