/*
 * src/game/unit_02096754.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
int Unk02e000_GetWorkArea(void);
void *Unk02e000_Thunk_0202e788(void);
int Unk096754_CountEntries(void);
void func_0209846c(u32 arg0, void *area);
int Unk096754_Unk_0970b4(void);
int Unk096754_Unk_0970c4(void);
int Unk096754_Unk_097100(void);
int Unk096754_Unk_097110(void);
void Unk096754_Unk_097204(u32 arg0);
int Unk096754_Unk_0969f0(void);
typedef struct Unk096754Area {
    u8 pad_0000[0x12];
    s16 unk_12;
    s16 unk_14;
    u8 pad_0016[0x6];
    s16 unk_1c;
    s16 unk_1e;
} Unk096754Area;
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int Unk02e000_GetAreaRecord(void);
int Unk096754_HasEntryId(int id);
/* At 0x02096754, the three signed bytes at work +0x354 gate the
 * area-record lookup for unsigned indices 0..2; other indices return zero. */
int Unk096754_GetAreaRecordIf(u32 i)
{
    u8 *base;
    s8 *t;
    int j;
    if (i >= 3) {
        return 0;
    }
    base = (u8 *)Unk02e000_GetWorkArea();
    t = (s8 *)(base + 852);
    for (j = 0; j < 3; j++) {
        if (t[j] >= 0 && i == j) {
            return Unk02e000_GetAreaRecord();
        }
    }
    return 0;
}
/* At 0x02096898, counts consecutive nonnegative signed entry indices at
 * work +0x348, stopping at the first negative byte or twelve entries. */
int Unk096754_CountEntries(void)
{
    u8 *base = (u8 *)Unk02e000_GetWorkArea();
    int n = 0;
    int j;
    for (j = 0; j < 12; j++) {
        if (FIELD(s8, base + j + 768, 72) < 0) {
            break;
        }
        n++;
    }
    return n;
}
/* Copies signed halfwords +0x12/+0x14 to +0x1c/+0x1e. The paired
 * loads/stores at 0x02096f0c support the existing CopyAreaPos name. */
void Unk096754_CopyAreaPos(void)
{
    Unk096754Area *a = (Unk096754Area *)Unk02e000_Thunk_0202e788();
    a->unk_1c = a->unk_12;
    a->unk_1e = a->unk_14;
}
/* Returns the signed area halfword at +0x1c; field semantics are unknown. */
int Unk096754_Unk_0970b4(void)
{
    Unk096754Area *area = (Unk096754Area *)Unk02e000_Thunk_0202e788();
    return area->unk_1c;
}
/* Returns the signed area halfword at +0x12; field semantics are unknown. */
int Unk096754_Unk_0970c4(void)
{
    Unk096754Area *area = (Unk096754Area *)Unk02e000_Thunk_0202e788();
    return area->unk_12;
}
/* Returns the signed area halfword at +0x1e; field semantics are unknown. */
int Unk096754_Unk_097100(void)
{
    Unk096754Area *area = (Unk096754Area *)Unk02e000_Thunk_0202e788();
    return area->unk_1e;
}
/* Returns the signed area halfword at +0x14; field semantics are unknown. */
int Unk096754_Unk_097110(void)
{
    Unk096754Area *area = (Unk096754Area *)Unk02e000_Thunk_0202e788();
    return area->unk_14;
}
/* Forwards arg0 and the borrowed current area to func_0209846c. */
void Unk096754_Unk_097204(u32 arg0)
{
  void *value;
  value = Unk02e000_Thunk_0202e788();
  func_0209846c(arg0,value);
}
/* Tests whether the entry count is below the unsigned byte at work +0x357. */
int Unk096754_Unk_0969f0(void)
{
  int value1;
  int value2;
  value1 = Unk02e000_GetWorkArea();
  value2 = Unk096754_CountEntries();
  return value2 < (int)(u32)*(u8 *)(value1 + 0x357);
}
int Unk02e000_HasField36(const void *entry);
/* At 0x02096a14, returns the first of twelve 0x3c-byte records whose
 * +0x36 predicate is false, or -1 when capacity or the scan rejects it. */
int Unk096754_Unk_096a14(void)
{
    int i;
    u8 *entry;
    if (Unk096754_Unk_0969f0() == 0) {
        return -1;
    }
    entry = (u8 *)Unk02e000_GetWorkArea() + 0x74;
    for (i = 0; i < 12; i++, entry += 0x3c) {
        if (Unk02e000_HasField36(entry) == 0) {
            return i;
        }
    }
    return -1;
}
/* At 0x02096a60, compares id with unsigned halfword +0xaa of each
 * record selected by the twelve signed indices at work +0x348. */
int Unk096754_HasEntryId(int id)
{
    u8 *base = (u8 *)Unk02e000_GetWorkArea();
    int j;
    for (j = 0; j < 12; j++) {
        s32 v = FIELD(s8, base + j + 768, 72);
        if (v >= 0 && id == FIELD(u16, base + v * 60, 170)) {
            return 1;
        }
    }
    return 0;
}
/* At 0x02096ab0, returns false for record +0xa8 values 1 and 7.
 * Signed indices outside 0..11 return true before any record load. */
int Unk096754_Unk_096ab0(int i)
{
    u8 *base = (u8 *)Unk02e000_GetWorkArea();
    u16 v;
    if (i < 0 || i >= 12) {
        return 1;
    }
    v = FIELD(u16, base + i * 60, 168);
    if (v == 1 || v == 7) {
        return 0;
    }
    return 1;
}
/* At 0x02096b44, requires available capacity and HasEntryId(id) != 1.
 * The capacity check short-circuits the ID lookup. */
int Unk096754_Unk_096b44(int id)
{
    if (Unk096754_Unk_0969f0() == 0) {
        return 0;
    }
    return Unk096754_HasEntryId(id) != 1;
}
/* Clears area +0x6c and restores the paired halfwords. The call to
 * CopyAreaPos and repeated copies at 0x02096f28 support the existing name. */
void Unk096754_ResetAreaPos(void)
{
    u8 *p = (u8 *)Unk02e000_Thunk_0202e788();
    FIELD(s16, p, 108) = 0;
    Unk096754_CopyAreaPos();
    FIELD(s16, p, 28) = FIELD(s16, p, 18);
    FIELD(s16, p, 30) = FIELD(s16, p, 20);
}
/* At 0x020970d4, clamps v against signed area +0x12 and then a lower
 * bound of one, storing +0x1c; the upper-bound branch takes precedence. */
void Unk096754_ClampField1c(int v)
{
    u8 *p = (u8 *)Unk02e000_Thunk_0202e788();
    s32 m = FIELD(s16, p, 18);
    if (v <= m) {
        if (v < 1) {
            v = 1;
        }
        m = v;
    }
    FIELD(s16, p, 28) = m;
}
/* At 0x02097120, clamps v against signed area +0x14 and then a lower
 * bound of one, storing +0x1e; the upper-bound branch takes precedence. */
void Unk096754_ClampField1e(int v)
{
    u8 *p = (u8 *)Unk02e000_Thunk_0202e788();
    s32 m = FIELD(s16, p, 20);
    if (v <= m) {
        if (v < 1) {
            v = 1;
        }
        m = v;
    }
    FIELD(s16, p, 30) = m;
}
typedef struct Unk096754Work {
    u8 pad_00[22];
    u8 unk_16;
    u8 unk_17;
    u8 unk_18;
    u8 unk_19;
    u8 unk_1a;
} Unk096754Work;
void func_02096c8c(void);
/* At 0x02097220, updates one of five area bytes and always refreshes
 * derived fields, even when the index is outside 0..4. */
void Unk096754_Unk_097220(int i, u8 v)
{
    Unk096754Work *w = (Unk096754Work *)Unk02e000_Thunk_0202e788();
    switch (i) {
    case 0:
        w->unk_16 = v;
        break;
    case 1:
        w->unk_17 = v;
        break;
    case 2:
        w->unk_18 = v;
        break;
    case 3:
        w->unk_19 = v;
        break;
    case 4:
        w->unk_1a = v;
        break;
    }
    func_02096c8c();
}
/* At 0x02096af4, finds the record index for an unsigned record ID;
 * negative list slots are skipped and absence returns -1. */
int func_02096af4(u32 id)
{
    u8 *base = (u8 *)Unk02e000_GetWorkArea();
    int j;
    for (j = 0; j < 12; j++) {
        int index = FIELD(s8, base + j + 768, 72);
        if (index >= 0) {
            u32 value = FIELD(u16, base + index * 60, 170);
            if (value == id) return index;
        }
    }
    return -1;
}
/* At 0x020968d4, fills negative list slots with later nonnegative
 * indices, preserving their order and marking moved slots -1. */
void func_020968d4(void)
{
    u8 *base = (u8 *)Unk02e000_GetWorkArea();
    int i;
    for (i = 0; i < 12; i++) {
        if (FIELD(s8, base + i + 768, 72) < 0) {
            int done = 1;
            int j;
            for (j = i + 1; j < 12; j++) {
                int index = FIELD(s8, base + j + 768, 72);
                if (index >= 0) {
                    FIELD(s8, base + i, 840) = index;
                    done = 0;
                    FIELD(s8, base + j, 840) = -1;
                    break;
                }
            }
            if (done) {
                return;
            }
        }
    }
}

/* At 0x02096958, removes a signed index in 0..11 from both lists,
 * clears the current record's +0x36 field, and compacts the longer list. */
int func_02096958(int index)
{
    u8 *base;
    int j;
    if (index >= 0 && index < 12) {
        FIELD(u16, (u8 *)Unk02e000_GetAreaRecord(), 54) = 0;
        base = (u8 *)Unk02e000_GetWorkArea();
        for (j = 0; j < 3; j++) {
            if (FIELD(s8, base + j + 768, 84) == index) {
                FIELD(s8, base + j, 852) = -1;
                break;
            }
        }
        for (j = 0; j < 12; j++) {
            int value = FIELD(s8, base + j + 768, 72);
            if (index == value) {
                FIELD(s8, base + j, 840) = -1;
                break;
            }
            if (value < 0) {
                break;
            }
        }
        func_020968d4();
        return 1;
    }
    return 0;
}

void Unk0986ac_Unk_098978(int id);
int Unk0986ac_Thunk_02098714(void);
void *Unk09974c_Unk_099c60(int id);
int func_0209714c(int id);

/* At 0x0209714c, searches +0x3e of four resolved area IDs; the
 * second ID also permits matches in three halfwords starting at +0x40. */
int func_0209714c(int id)
{
    u8 *area = (u8 *)Unk02e000_Thunk_0202e788();
    int i;
    int key;
    for (i = 0; i < 4; i++) {
        u8 *record;
        switch (i) {
        case 0: key = FIELD(u16, area, 0); break;
        case 1: key = FIELD(u16, area, 2); break;
        case 2: key = FIELD(u16, area, 4); break;
        case 3: key = FIELD(u16, area, 6); break;
        }
        if (key == 0) continue;
        record = (u8 *)Unk09974c_Unk_099c60(key);
        if (record == 0) continue;
        if (i == 1) {
            int j;
            for (j = 0; j < 3; j++) {
                if (id == ((u16 *)record)[j + 32]) return 1;
            }
        }
        if (FIELD(u16, record, 62) == id) return 1;
    }
    return 0;
}

/* At 0x02096f54, sums five observed predicate weights unless +0x6c
 * is 1 or 7; returns that percentage of signed +0x12, at least one. */
int func_02096f54(int enabled)
{
    int weight = 0;
    u8 *area = (u8 *)Unk02e000_Thunk_0202e788();
    u16 state = FIELD(u16, area, 108);
    if (state == 1 || state == 7) return 0;
    if (enabled) {
        Unk0986ac_Unk_098978(143);
        if (Unk0986ac_Thunk_02098714()) weight += 1;
        Unk0986ac_Unk_098978(157);
        if (Unk0986ac_Thunk_02098714()) weight += 3;
        Unk0986ac_Unk_098978(144);
        if (Unk0986ac_Thunk_02098714()) weight += 1;
        Unk0986ac_Unk_098978(158);
        if (Unk0986ac_Thunk_02098714()) weight += 3;
        if (func_0209714c(396)) weight += 3;
    }
    if (weight) {
        int value = FIELD(s16, area, 18) * weight / 100;
        if (value <= 0) value = 1;
        return value;
    }
    return 0;
}


/* At 0x0209701c, sums predicate weights when enabled, except for
 * unsigned area +0x6c values 1 and 7, which always return zero. */
int func_0209701c(int enabled)
{
    int weight = 0;
    u8 *area = (u8 *)Unk02e000_Thunk_0202e788();
    u16 state = FIELD(u16, area, 108);
    if (state == 1 || state == 7) return 0;
    if (enabled) {
        Unk0986ac_Unk_098978(159);
        if (Unk0986ac_Thunk_02098714()) weight += 3;
        Unk0986ac_Unk_098978(145);
        if (Unk0986ac_Thunk_02098714()) weight += 5;
        Unk0986ac_Unk_098978(160);
        if (Unk0986ac_Thunk_02098714()) weight += 1;
        Unk0986ac_Unk_098978(151);
        if (Unk0986ac_Thunk_02098714()) weight += 3;
        if (func_0209714c(397)) weight += 5;
    }
    return weight;
}
