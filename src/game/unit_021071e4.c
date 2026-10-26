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
    u8 pad_003d[11];
    float opacity[4];
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

u8 *Unk02e000_GetWorkArea(void);
u8 *Unk02e000_Thunk_0202e788(void);
int func_02098544(int mode);
void Unk0fc584_Unk_0fc84c(int value);
u8 *func_020445f4(int id, int mode);
void func_02063920(u8 *resource);
u8 *func_0204fed8(u8 *resource, int index);
void func_02057ddc(u32 color);
void func_020629c4(u32 handle);
void func_0205c3dc(u32 handle);
void func_0205c368(u32 handle);
void func_0205ddb4(u32 handle);
void func_0205bb68(void);
void Unk0c855c_Unk_0ca648(int id);
extern u32 data_02176e30;

/* Target compares the queried value against the signed work-area limit at +0x344. */
void func_02108a50(Unk1071e4Work *work)
{
    FIELD(s32, work, 96) = func_02098544(0);
    if (FIELD(s32, work, 96) == 0 || FIELD(s32, work, 96) > FIELD(s32, Unk02e000_GetWorkArea(), 836))
        FIELD(s32, work, 92) = 0;
    else
        FIELD(s32, work, 92) = 1;
    Unk0fc584_Unk_0fc84c(-FIELD(s32, work, 96));
}

/* Target obtains resource 30, selects the requested entry and forwards its derived value. */
void func_02108b40(u32 value, int index)
{
    u8 *resource = func_020445f4(30, 2);
    func_02063920(resource);
    func_02061f10(value, -1, 0, 0, func_02063a30(func_0204fed8(resource, index)));
}

/* Target clears category and restores a nonpositive signed field from its paired source. */
void func_021089f8(Unk1071e4Work *work)
{
    u8 *record;
    if (work->selected == 0) {
        record = Unk02e000_Thunk_0202e788();
        FIELD(u16, record, 108) = 0;
        if (FIELD(s16, record, 28) <= 0) FIELD(s16, record, 28) = FIELD(s16, record, 18);
    } else {
        record = Unk02e000_GetAreaRecord(FIELD(s8, (u8 *)work + work->selected, 59));
        FIELD(u16, record, 52) = 0;
        if (FIELD(s16, record, 30) <= 0) FIELD(s16, record, 30) = FIELD(s16, record, 10);
    }
}

/* Target tests the main category then nonnegative signed IDs in the work-area list. */
int func_02107374(void)
{
    u8 *area;
    int i;
    if (FIELD(u16, Unk02e000_Thunk_0202e788(), 108) != 0) return 1;
    area = Unk02e000_GetWorkArea();
    for (i = 0; i < FIELD(u8, area, 855); i++) {
        int id = FIELD(s8, area + i, 840);
        if (id >= 0 && FIELD(u16, Unk02e000_GetAreaRecord(id), 52) != 0) return 1;
    }
    return 0;
}

/* Target selects packed color constants by category and whether the flag equals one. */
void func_0210860c(int category, int flag)
{
    if (category == 5) {
        if (flag == 1) func_02057ddc(0x5a3129ff);
        else func_02057ddc(0xff7b63ff);
    } else if (category == 4) {
        if (flag == 1) func_02057ddc(0x18525aff);
        else func_02057ddc(0x39dccbff);
    } else {
        if (flag == 1) func_02057ddc(0x7b7b7bff);
        else func_02057ddc(0xffffffff);
    }
}

/* Target derives a category value from the selected record and checks the area limit. */
void func_02108960(Unk1071e4Work *work)
{
    u8 *record;
    if (work->selected == 0) {
        record = Unk02e000_Thunk_0202e788();
        FIELD(s32, work, 96) = func_02108928(FIELD(u16, record, 108), 0, FIELD(s16, record, 18));
    } else {
        record = Unk02e000_GetAreaRecord(FIELD(s8, (u8 *)work + work->selected, 59));
        FIELD(s32, work, 96) = func_02108928(FIELD(u16, record, 52), FIELD(u8, record, 56), FIELD(s16, record, 10));
    }
    if (FIELD(s32, work, 96) == 0 || FIELD(s32, work, 96) > FIELD(s32, Unk02e000_GetWorkArea(), 836))
        FIELD(s32, work, 92) = 0;
    else
        FIELD(s32, work, 92) = 1;
    Unk0fc584_Unk_0fc84c(-FIELD(s32, work, 96));
}

/* Target releases nonzero handles, drains five entries and clears the global owner. */
void func_02107648(Unk1071e4Work *work)
{
    int i;
    u32 j;
    func_020629c4(FIELD(u32, work, 56));
    func_020629c4(FIELD(u32, work, 52));
    for (i = 0; i < 5; i++) {
        if (work->handles[i] != 0) {
            func_0205c3dc(work->handles[i]);
            work->handles[i] = 0;
        }
    }
    if (FIELD(u32, work, 4) != 0) {
        func_0205c368(FIELD(u32, work, 4));
        FIELD(u32, work, 4) = 0;
    }
    if (FIELD(u32, work, 0) != 0) {
        func_0205ddb4(FIELD(u32, work, 0));
        FIELD(u32, work, 0) = 0;
    }
    for (j = 0; j < 5; j++) func_0205bb68();
    Unk0c855c_Unk_0ca648(2);
    data_02176e30 = 0;
}

/* Callback slots and size are evidenced by the initializer's relocation-backed stores. */
typedef struct Unk1071e4Descriptor {
    u32 size, enabled, reserved;
    void (*initialize)(Unk1071e4Work *work);
    void (*update)(Unk1071e4Work *work);
    void (*unused)(Unk1071e4Work *work);
    void (*draw)(Unk1071e4Work *work);
    void (*release)(Unk1071e4Work *work);
    void (*message)(Unk1071e4Work *work, u32 *message);
} Unk1071e4Descriptor;
void func_021076f0(Unk1071e4Work *work);
void func_0210792c(Unk1071e4Work *work);
void func_02107c60(Unk1071e4Work *work);
void func_02108694(Unk1071e4Work *work, u32 *message);

/* Target installs six callback slots, including a null slot; reserved +8 is untouched. */
void func_021073e4(Unk1071e4Descriptor *descriptor)
{
    descriptor->size = 104;
    descriptor->enabled = 1;
    descriptor->initialize = func_021076f0;
    descriptor->update = func_0210792c;
    descriptor->unused = 0;
    descriptor->draw = func_02107c60;
    descriptor->release = func_02107648;
    descriptor->message = func_02108694;
}

int Unk096754_Unk_0970b4(void);
int Unk096754_Unk_097100(void);
int Unk096754_Unk_0970c4(void);
s16 Unk096754_Unk_097110(void);
int Unk096754_CountEntries(void);
u8 *func_020445d0(int id, int mode);
u8 *func_0204fde0(u8 *resource);
u32 func_0204fe18(u8 *resource);
void func_02008848(void *dst, int value, u32 size);
void func_02008904(const void *src, void *dst, u32 size);
void func_0205de40(int mode, u32 handle, int kind, int x, int y, float a, float b, int zero, float alpha, int flags);
void func_02108290(Unk1071e4Work *work, int x, int y, float alpha, int category, int a, int b, int c, int d, int enabled);
void Unk0cb32c_Unk_0cb488(u32 handle, int x, int y, int index, int a, int b);
int Unk02ee5c_GetTierFromField70(void);
void func_02057df8(void);
void func_0205c748(int mode, u32 handle, int x, int y, float a, float b, int zero, float alpha, int flags);
u8 *func_020a1428(int id);
int func_02053800(int a, int button);
void Unk0a0ce4_Unk_0a0da4(int id);
int func_02107a9c(Unk1071e4Work *work);
void Unk124c5c_Set_124d6c(int a, int b);
void Unk124c5c_Set_124d8c(int a, int b);
void Unk0bc1a8_Unk_0bc504(Unk1071e4Work *work, int value);

/* Instruction evidence: checks category eligibility and paired current/limit values. */
int func_021072c0(void)
{
    int result = 0;
    u8 *record;
    int i;
    int value;
    if (Unk1071e4_IsNot1or7(FIELD(u16, Unk02e000_Thunk_0202e788(), 108))) {
        value = Unk096754_Unk_0970b4();
        {
            int limit = Unk096754_Unk_0970c4();
            if (value < limit || (value = Unk096754_Unk_097100(), limit = Unk096754_Unk_097110(), value < limit)) result = 1;
        }
    }
    if (!result) {
        for (i = 0; i < Unk096754_CountEntries(); i++) {
            record = Unk02e000_GetAreaRecord(i);
            if (Unk1071e4_IsNot1or7(FIELD(u16, record, 52))) {
                if (FIELD(s16, record, 30) < FIELD(s16, record, 10) || FIELD(s16, record, 32) < FIELD(s16, record, 12)) {
                    result = 1;
                    break;
                }
            }
        }
    }
    return result;
}

/* Instruction evidence: derives the selected record delta and applies the area limit. */
void func_0210882c(Unk1071e4Work *work)
{
    u8 *record;
    int a, b, c;
    if (work->selected == 0) {
        record = Unk02e000_Thunk_0202e788();
        a = Unk096754_Unk_0970b4();
        b = Unk096754_Unk_097100();
        c = Unk096754_Unk_0970c4();
        FIELD(s32, work, 96) = Unk1071e4_Unk_1087f4(FIELD(u16, record, 108), a, b, c, Unk096754_Unk_097110());
    } else {
        record = Unk02e000_GetAreaRecord(FIELD(s8, (u8 *)work + work->selected, 59));
        FIELD(s32, work, 96) = Unk1071e4_Unk_1087f4(FIELD(u16, record, 52), FIELD(s16, record, 30), FIELD(s16, record, 32), FIELD(s16, record, 10), FIELD(s16, record, 12));
    }
    if (FIELD(s32, work, 96) == 0 || FIELD(s32, work, 96) > FIELD(s32, Unk02e000_GetWorkArea(), 836)) FIELD(s32, work, 92) = 0;
    else FIELD(s32, work, 92) = 1;
    Unk0fc584_Unk_0fc84c(-FIELD(s32, work, 96));
}

/* The three target call sites select draw kinds 8, 6 and 7 from the supplied flags. */
void func_02108534(Unk1071e4Work *work, int x, int y, float alpha, u16 category, int flag)
{
    if (category == 1) func_0205de40(2, FIELD(u32, work, 0), 8, x, y, 1.0f, 1.0f, 0, alpha, 4);
    else if (flag) func_0205de40(2, FIELD(u32, work, 0), 6, x, y, 1.0f, 1.0f, 0, alpha, 4);
    else func_0205de40(2, FIELD(u32, work, 0), 7, x, y, 1.0f, 1.0f, 0, alpha, 4);
}

/* Resource 17 has 24-byte records; target sorts six nonzero halfwords uniquely. */
void func_021071e4(void)
{
    u8 *resource = func_020445d0(17, 0);
    u8 *record = func_0204fde0(resource);
    u32 count = func_0204fe18(resource);
    u32 i = 0;
    u16 sorted[6];
    int j;
    u32 value;
    int k;
    if (!count) return;
    do {
        func_02008848(sorted, 0, 12);
        for (j = 0; j < 6; j++) {
            value = ((u16 *)record)[j + 6];
            if (value == 0) continue;
            for (k = 0; k < 6; k++) {
                u16 old = sorted[k];
                if (old == 0) { sorted[k] = value; break; }
                if (value == old) break;
                if (old > value) { sorted[k] = value; value = old; }
            }
        }
        func_02008904(sorted, record + 12, 12);
        i++;
        record += 24;
    } while (i < count);
}

/* Target draws the main record, then conditionally draws its selected-state overlay. */
void func_02107ff4(Unk1071e4Work *work)
{
    u8 *record = Unk02e000_Thunk_0202e788();
    int a = Unk096754_Unk_0970b4();
    int b = Unk096754_Unk_097100();
    int c = Unk096754_Unk_0970c4();
    int d = Unk096754_Unk_097110();
    int tier;
    func_02108290(work, 0, 0, 1.0f, FIELD(u16, record, 108), a, b, c, d, 1);
    func_02057ddc(255);
    Unk0cb32c_Unk_0cb488(FIELD(u32, work, 56), 188, 13, 0, 8, 6);
    tier = Unk02ee5c_GetTierFromField70();
    record = Unk02e000_Thunk_0202e788();
    func_0210860c(tier, FIELD(u16, record, 108));
    Unk0cb32c_Unk_0cb488(FIELD(u32, work, 56), 188, 12, 0, 8, 6);
    func_02057df8();
    if (work->state != 6) return;
    if (work->handles[5] == 0) return;
    if (work->selected != 0) return;
    func_0205c748(2, work->handles[0], 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
}

/* Target draws the indexed signed-ID record; the fifth argument must index its list. */
void func_02108128(Unk1071e4Work *work, int x, int y, float alpha, u32 index)
{
    u8 *record = Unk02e000_GetAreaRecord(FIELD(s8, (u8 *)work + index, 60));
    u8 *entry = func_020a1428(FIELD(u16, record, 54));
    int enabled = 0;
    if (index < FIELD(u8, work, 40)) enabled = 1;
    func_02108290(work, x, y, alpha, FIELD(u16, record, 52), FIELD(s16, record, 30), FIELD(s16, record, 32), FIELD(s16, record, 10), FIELD(s16, record, 12), enabled);
    if (alpha >= 1.0f) {
        func_02057ddc(255);
        Unk0cb32c_Unk_0cb488(FIELD(u32, work, 56), x + 188, y + 13, index + 1, 8, 6);
        func_0210860c(FIELD(u8, entry, 5), FIELD(u16, record, 52));
        Unk0cb32c_Unk_0cb488(FIELD(u32, work, 56), x + 188, y + 12, index + 1, 8, 6);
        func_02057df8();
    }
    if (work->state != 6) return;
    if (work->handles[5] == 0) return;
    if (work->selected != index + 1) return;
    func_0205c748(2, work->handles[0], x, y, 1.0f, 1.0f, 0, 1.0f, 5);
}

/* Target handles confirmation/cancellation only in state 5, dispatching by mode +0x1c. */
void func_0210792c(Unk1071e4Work *work)
{
    if (work->state != 5) return;
    switch (work->handles[5]) {
    case 0:
        if (func_02053800(0, 1)) {
            if (FIELD(s32, work, 92)) {
                Unk0a0ce4_Unk_0a0da4(31);
                func_02108aa4(work);
                Unk1071e4_Unk_108b08(work, 1);
                work->state = 6;
            } else Unk0a0ce4_Unk_0a0da4(4);
        } else if (func_02053800(0, 2)) {
            Unk0a0ce4_Unk_0a0da4(2);
            Unk1071e4_Unk_107c34(work);
        }
        break;
    case 1:
    case 2:
        if (func_02107a9c(work)) {
            Unk0a0ce4_Unk_0a0da4(0);
            if (work->handles[5] == 1) func_0210882c(work);
            else func_02108960(work);
        } else if (func_02053800(0, 1)) {
            if (FIELD(s32, work, 92)) {
                Unk0a0ce4_Unk_0a0da4(31);
                if (work->handles[5] == 1) Unk1071e4_Unk_1088fc(work);
                else func_021089f8(work);
                Unk1071e4_Unk_108b08(work, 0);
                work->state = 6;
            } else Unk0a0ce4_Unk_0a0da4(4);
        } else if (func_02053800(0, 2)) {
            Unk0a0ce4_Unk_0a0da4(2);
            Unk1071e4_Unk_107c34(work);
        }
        break;
    }
}

/* Message tags and payload bits are evidenced by the target switch and bit tests. */
void func_02108694(Unk1071e4Work *work, u32 *message)
{
    int value[1] = {0};
    u32 *payload = message + 1;
    switch (message[0]) {
    case 0:
        Unk124c5c_Set_124d6c(0, 1);
        Unk124c5c_Set_124d8c(0, 31);
        work->handles[5] = 3;
        work->state = 1;
        FIELD(s32, work, 100) = 0;
        break;
    case 3:
        if (payload != 0) {
            int supplied = payload[4];
            if (FIELD(u8, payload, 0) & 8) value[0] = supplied;
        }
        if (value[0] == 1) {
            Unk124c5c_Set_124d8c(1, 0);
            work->state = 2;
            break;
        }
            if (payload != 0) {
            int supplied = payload[2];
            if (FIELD(u8, payload, 0) & 2) value[0] = supplied;
        }
        work->handles[5] = value[0];
        switch (work->handles[5]) {
        case 0: func_02108a50(work); break;
        case 1: func_0210882c(work); break;
        case 2: func_02108960(work); break;
        case 3: break;
        }
        func_020bc9f4(18, 0);
        FIELD(s32, work, 100) = 1;
        work->state = 5;
        break;
    case 2:
        FIELD(s32, work, 100) = 0;
        work->state = 4;
        break;
    case 1:
        work->state = 0;
        Unk0bc1a8_Unk_0bc504(work, 0);
        break;
    case 4: break;
    }
}

int func_02053824(int device, int button);
void func_02051b18(s32 *value, int delta, int minimum, int count, int mode);

/* Target button masks move selection through the three-column record list. */
int func_02107a9c(Unk1071e4Work *work)
{
    int old = FIELD(s32, work, 32);
    if (work->count <= 1) return 0;
    if (func_02053824(0, 64)) {
        if (FIELD(s32, work, 32) == 0) FIELD(s32, work, 32) = work->count - 1;
        else if (FIELD(s32, work, 32) <= 3) FIELD(s32, work, 32) = 0;
        else FIELD(s32, work, 32) -= 3;
    } else if (func_02053824(0, 128)) {
        int selected = FIELD(s32, work, 32);
        if (selected == 0) FIELD(s32, work, 32) = 1;
        else if (selected == work->count - 1) FIELD(s32, work, 32) = 0;
        else if (selected + 3 >= work->count) {
            switch ((work->count - 1) % 3) {
            case 0: FIELD(s32, work, 32) = 0; break;
            case 1: FIELD(s32, work, 32) = work->count - 1; break;
            case 2:
                if (selected == work->count - 2) FIELD(s32, work, 32) = 0;
                else FIELD(s32, work, 32) = work->count - 1;
                break;
            }
        } else FIELD(s32, work, 32) = selected + 3;
    } else if (func_02053824(0, 32)) {
        func_02051b18(&FIELD(s32, work, 32), -1, 0, work->count, 2);
    } else if (func_02053824(0, 16)) {
        func_02051b18(&FIELD(s32, work, 32), 1, 0, work->count, 2);
    }
    return old != FIELD(s32, work, 32);
}

int Unk124c5c_IsKind0(void);
int Unk124c5c_IsKind31(void);
void Unk0bc1a8_Unk_0bc9b4(int id, int value);
int Unk0cb32c_Unk_0cb58c(u32 handle);
void Unk0fc584_Unk_0fc86c(void);
int Unk0fc584_Unk_0fc7f4(void);
void func_0205c704(u32 handle);

/* Target state dispatch advances animations, deducts the computed value, and refreshes eligibility. */
void func_021076f0(Unk1071e4Work *work)
{
    int i;
    switch (work->state) {
    case 1:
        if (Unk124c5c_IsKind0()) {
            Unk1071e4_Unk_108b08(work, 3);
            work->state = 3;
        }
        break;
    case 2:
        if (Unk124c5c_IsKind31()) Unk0bc1a8_Unk_0bc9b4(19, 0);
        break;
    case 3:
        if (FIELD(s32, work, 88) < 8) {
            if (FIELD(s32, work, 88) == 0) work->opacity[0] += 0.5f;
            else work->opacity[FIELD(s32, work, 88) / 2] += 0.5f;
            FIELD(s32, work, 88)++;
        }
        if (Unk0cb32c_Unk_0cb58c(work->handles[3])) {
            Unk1071e4_Unk_108b08(work, 2);
            Unk1071e4_Unk_108b08(work, 4);
            for (i = 0; i < 4; i++) work->opacity[i] = 1.0f;
            func_020bc9f4(19, 0);
            work->state = 4;
        }
        break;
    case 6:
        if ((work->handles[5] == 0 && Unk0cb32c_Unk_0cb58c(work->handles[1])) ||
            (work->handles[5] != 0 && Unk0cb32c_Unk_0cb58c(work->handles[0]))) {
            u8 *area = Unk02e000_GetWorkArea();
            FIELD(s32, area, 836) -= FIELD(s32, work, 96);
            FIELD(s32, work, 96) = 0;
            Unk0fc584_Unk_0fc86c();
            work->state = 7;
        }
        break;
    case 7:
        if (!Unk0fc584_Unk_0fc7f4()) {
            switch (work->handles[5]) {
            case 0:
                func_02108a50(work);
                Unk1071e4_Unk_107c34(work);
                break;
            case 1:
                func_0210882c(work);
                if (func_021072c0()) work->state = 5;
                else Unk1071e4_Unk_107c34(work);
                break;
            case 2:
                func_02108960(work);
                if (func_02107374()) work->state = 5;
                else Unk1071e4_Unk_107c34(work);
                break;
            }
        }
        break;
    }
    if (work->state == 0) return;
    for (i = 0; i < 5; i++) func_0205c704(work->handles[i]);
}

int Unk0ddeb0_Unk_0ddfd8(u16 category);
u32 Unk0ca69c_Unk_0ca6a4(int id);
void func_02058e9c(int mode, u32 value, int x, int y, float alpha, int zero, int flags);
void func_020a9fd8(int mode, int x, int y, int kind, int zero, int flags, const void *format, int value);
u8 *func_0205e318(u32 handle, int index);
void func_0205e048(int mode, u32 handle, u8 *entry, int x, int y, float a, float b, int zero, float alpha, int flags, int enabled);
extern u8 data_0215127c[], data_02151280[];

/* Target draws category text and bars from the low halfwords of stack arguments.
 * Keep full-width caller arguments: the original caller stores untruncated getter results. */
void func_02108290(Unk1071e4Work *work, int x, int y, float alpha, int category, int a, int b, int c, int d, int enabled)
{
    int threshold;
    int current;
    u8 *bar;
    func_02108534(work, x, y, alpha, FIELD(u16, &category, 0), enabled);
    if (alpha < 1.0f) return;
    func_0205de40(2, FIELD(u32, work, 0), 5, x, y, 1.0f, 1.0f, 0, alpha, 5);
    func_02058e9c(1, Unk0ca69c_Unk_0ca6a4(Unk0ddeb0_Unk_0ddfd8(FIELD(u16, &category, 0))), x + 174, y + 10, alpha, 0, 5);
    threshold = FIELD(s16, &c, 0) / 5;
    current = FIELD(s16, &a, 0);
    if (current < threshold) func_02057ddc(0xef1821ff);
    func_020a9fd8(2, x + 245, y + 23, 2, 0, 6, data_0215127c, current);
    func_02057df8();
    func_020a9fd8(2, x + 245, y + 30, 2, 0, 6, data_02151280, FIELD(s16, &b, 0));
    if (current < threshold) bar = func_0205e318(FIELD(u32, work, 0), 12);
    else bar = func_0205e318(FIELD(u32, work, 0), 51);
    if (FIELD(s16, &a, 0) > 0) {
        FIELD(s16, bar, 12) = (int)(30.0f * ((float)FIELD(s16, &a, 0) / (float)FIELD(s16, &c, 0)));
        if (FIELD(s16, bar, 12) == 0) FIELD(s16, bar, 12) = 1;
        func_0205e048(2, FIELD(u32, work, 0), bar, x, y, 1.0f, 1.0f, 0, alpha, 5, 1);
    }
    bar = func_0205e318(FIELD(u32, work, 0), 13);
    if (FIELD(s16, &b, 0) > 0) {
        FIELD(s16, bar, 12) = (int)(30.0f * ((float)FIELD(s16, &b, 0) / (float)FIELD(s16, &d, 0)));
        if (FIELD(s16, bar, 12) == 0) FIELD(s16, bar, 12) = 1;
        func_0205e048(2, FIELD(u32, work, 0), bar, x, y, 1.0f, 1.0f, 0, alpha, 5, 1);
    }
}

void func_02057524(int mode);
void func_02057e58(int index, int a, int b);
void func_02057eb8(int mode);
void func_02057e18(int value);
int func_0205caa0(u32 handle);
void func_02060b60(int mode, u32 handle, int x, int y, int zero, int flags);
void func_0205c848(int mode, u32 handle, int x, int y, float a, float b, int zero, float alpha, int flags);
void func_02057fd8(void);
void func_020572d8(void);

/* Target draws the main record and three-column area grid, with selection and state overlays. */
void func_02107c60(Unk1071e4Work *work)
{
    int i;
    if (work->state == 0) return;
    func_02057524(4);
    func_02057e58(0, 5, 15);
    func_02057e58(1, 20, 15);
    func_02057e58(2, 35, 15);
    func_02057eb8(0);
    func_0205c748(2, work->handles[3], 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
    func_0205c748(2, work->handles[2], 0, 0, 1.0f, 1.0f, 0, 1.0f, 6);
    func_02057e18(31);
    if (func_0205caa0(work->handles[3]) > 1) {
        func_02057ddc(255);
        func_02060b60(1, FIELD(u32, work, 52), 22, FIELD(s32, (u8 *)work->handles[3], 24) - 1, 0, 6);
        func_02057df8();
        func_02060b60(1, FIELD(u32, work, 52), 22, FIELD(s32, (u8 *)work->handles[3], 24) - 2, 0, 8);
    }
    func_02057eb8(0);
    func_0205de40(2, FIELD(u32, work, 0), 10, 0, 0, 1.0f, 1.0f, 0, 1.0f, 3);
    func_0205de40(2, FIELD(u32, work, 0), 11, 0, 0, 1.0f, 1.0f, 0, 1.0f, 4);
    func_02107ff4(work);
    if (FIELD(s32, work, 100) && (work->selected == 0 || work->handles[5] == 0))
        func_0205c748(2, work->handles[4], 0, 0, 1.0f, 1.0f, 0, 1.0f, 6);
    for (i = 0; i < FIELD(u8, Unk02e000_GetWorkArea(), 855); i++) {
        int x, y;
        func_02057eb8(0);
        x = (i % 3) * 81;
        y = (i / 3) * 33;
        func_0205de40(2, FIELD(u32, work, 0), 9, x, y, 1.0f, 1.0f, 0, 1.0f, 3);
        if (i < work->count - 1) {
            if (FIELD(s32, work, 100) && (i + 1 == work->selected || work->handles[5] == 0))
                func_0205c848(2, work->handles[4], x - 162, y + 47, 1.0f, 1.0f, 0, 1.0f, 6);
            func_02108128(work, x - 162, y + 47, work->opacity[(i + 4) / 4 - 1], (u8)i);
        }
    }
    if (work->state == 6 && work->handles[5] == 0) {
        func_02057eb8(1);
        func_0205c748(2, work->handles[1], 0, 0, 1.0f, 1.0f, 0, 1.0f, 15);
    }
    func_02057df8();
    func_02057eb8(-1);
    func_02057fd8();
    func_020572d8();
}
