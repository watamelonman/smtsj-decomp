/* Area-record helpers; offsets are evidenced by the original ARM accesses. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0979d8Work {
    u8 pad_0000[0x34];
    u16 unk_0034;
} Unk0979d8Work;



/* Returns a borrowed area record, or NULL when the indexed slot is absent. */
u8 *Unk096754_GetAreaRecordIf(u32 index);
int Unk0979d8_ClampField1e(u8 *record, int value);
int Unk0979d8_ClampField20(u8 *record, int value);

/* Restores +0x1e/+0x20 from +0x0a/+0x0c; ARM 020979e4..020979f0
 * establishes the copies. NULL returns 0; a restored record returns 1. */
int Unk0979d8_ResetFields(u8 *record)
{
    if (record == 0) {
        return 0;
    }
    FIELD(s16, record, 0x1e) = FIELD(s16, record, 0x0a);
    FIELD(s16, record, 0x20) = FIELD(s16, record, 0x0c);
    return 1;
}

/* Reads the indexed record's unsigned byte at +0x38, or 0 if absent.
 * Evidence: BL 02096754 and LDRB at 02098134; field meaning is unknown. */
u8 Unk0979d8_Unk_098124(u32 index)
{
    u8 *record = Unk096754_GetAreaRecordIf(index);
    u8 value;
    if (record == 0) {
        value = 0;
    } else {
        value = FIELD(u8, record, 0x38);
    }
    return value;
}

/* Reads signed +0x1e, or 0 for an absent indexed record.
 * Evidence: BL 02096754 and LDRSH at 0209814c. */
int Unk0979d8_Unk_09813c(u32 index)
{
    u8 *record = Unk096754_GetAreaRecordIf(index);
    return record == 0 ? 0 : FIELD(s16, record, 0x1e);
}

/* Reads signed +0x0a, or 0 for an absent indexed record.
 * Evidence: BL 02096754 and LDRSH at 02098164. */
int Unk0979d8_Unk_098154(u32 index)
{
    u8 *record = Unk096754_GetAreaRecordIf(index);
    return record == 0 ? 0 : FIELD(s16, record, 0x0a);
}

/* Reads signed +0x20, or 0 for an absent indexed record.
 * Evidence: BL 02096754 and LDRSH at 0209819c. */
int Unk0979d8_Unk_09818c(u32 index)
{
    u8 *record = Unk096754_GetAreaRecordIf(index);
    return record == 0 ? 0 : FIELD(s16, record, 0x20);
}

/* Reads signed +0x0c, or 0 for an absent indexed record.
 * Evidence: BL 02096754 and LDRSH at 020981b4. */
int Unk0979d8_Unk_0981a4(u32 index)
{
    u8 *record = Unk096754_GetAreaRecordIf(index);
    return record == 0 ? 0 : FIELD(s16, record, 0x0c);
}

/* For a present indexed record, forwards value to the +0x1e clamp.
 * Evidence: 02098170 preserves r1 across lookup, then BL 02097b54.
 * An absent record is left untouched. */
void Unk0979d8_Unk_09816c(u32 index, int value)
{
    u8 *record = Unk096754_GetAreaRecordIf(index);
    if (record == 0) {
        return;
    }
    Unk0979d8_ClampField1e(record, value);
}

/* For a present indexed record, forwards value to the +0x20 clamp.
 * Evidence: 020981c0 preserves r1 across lookup, then BL 02097b84.
 * An absent record is left untouched. */
void Unk0979d8_Unk_0981bc(u32 index, int value)
{
    u8 *record = Unk096754_GetAreaRecordIf(index);
    if (record == 0) {
        return;
    }
    Unk0979d8_ClampField20(record, value);
}


/* decompiler-derived */
u32 Unk0979d8_Unk_0979fc(Unk0979d8Work *arg0){
  if (arg0 != 0) {
    arg0->unk_0034 = 0;
    Unk0979d8_ResetFields((u8 *)arg0);
    return 1;
  }
  return 0;
}

int Unk096754_ClampField1c();
int Unk0979d8_ClampField1e(u8 *p, int v)
{
    s32 m;
    if (p == 0) {
        return 0;
    }
    m = FIELD(s16, p, 10);
    if (v <= m) {
        if (v < 1) {
            v = 1;
        }
        m = v;
    }
    FIELD(s16, p, 30) = m;
    return FIELD(s16, p, 30);
}

int Unk0979d8_ClampField20(u8 *p, int v)
{
    s32 m;
    if (p == 0) {
        return 0;
    }
    m = FIELD(s16, p, 12);
    if (v <= m) {
        if (v < 1) {
            v = 1;
        }
        m = v;
    }
    FIELD(s16, p, 32) = m;
    return FIELD(s16, p, 32);
}

int Unk0979d8_HasId(u8 *p, int id)
{
    int j;
    if (p == 0) {
        return 0;
    }
    for (j = 0; j < 6; j++) {
        if (id == ((u16 *)(p + 40))[j]) {
            return 1;
        }
    }
    return 0;
}

void Unk0979d8_CopyIds(u8 *p, u16 *out)
{
    int j;
    if (p == 0) {
        return;
    }
    for (j = 0; j < 6; j++) {
        out[j] = ((u16 *)(p + 40))[j];
    }
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
typedef struct Unk0979d8Pair {
    u16 lo : 10;
    u16 hi : 6;
} Unk0979d8Pair;

int func_020a1428();
void func_02097c18(Unk0979d8Pair *out, int a, u8 *b);
int Unk02e000_GetWorkArea();
int Unk02e000_GetAreaRecord();
u32 Unk0979d8_Unk_0979fc(Unk0979d8Work *arg0);
void Unk0979d8_ResetAreaEntries(void);
int Unk096754_ClampField1c();
int Unk096754_ClampField1e();
void Unk096754_ResetAreaPos(void);
int Unk0979d8_GetPairLo(u8 *p, int i)
{
    Unk0979d8Pair buf[20];
    func_02097c18(buf, func_020a1428(FIELD(u16, p, 54)), p + 40);
    return buf[i].lo;
}

int Unk0979d8_GetPairHi(u8 *p, int i)
{
    Unk0979d8Pair buf[20];
    func_02097c18(buf, func_020a1428(FIELD(u16, p, 54)), p + 40);
    return buf[i].hi;
}

void Unk0979d8_ResetAllEntries(void)
{
    u8 *w = (u8 *)Unk02e000_GetWorkArea();
    int j;
    for (j = 0; j < 12; j++) {
        s32 k = FIELD(s8, w + j + 768, 72);
        if (k < 0) {
            break;
        }
        Unk0979d8_Unk_0979fc((Unk0979d8Work *)Unk02e000_GetAreaRecord(k));
    }
    Unk0979d8_ResetAreaEntries();
}

void Unk0979d8_ClampAllField1e(int v)
{
    u8 *w;
    int j;
    Unk096754_ClampField1c(v);
    w = (u8 *)Unk02e000_GetWorkArea();
    for (j = 0; j < 12; j++) {
        s32 k = FIELD(s8, w + j + 768, 72);
        if (k < 0) {
            return;
        }
        Unk0979d8_ClampField1e(w + 116 + k * 60, v);
    }
}

void Unk0979d8_ClampAllField20(int v)
{
    u8 *w;
    int j;
    Unk096754_ClampField1e(v);
    w = (u8 *)Unk02e000_GetWorkArea();
    for (j = 0; j < 12; j++) {
        s32 k = FIELD(s8, w + j + 768, 72);
        if (k < 0) {
            return;
        }
        Unk0979d8_ClampField20(w + 116 + k * 60, v);
    }
}

void Unk0979d8_ResetAreaEntries(void)
{
    s8 *t = (s8 *)((u8 *)Unk02e000_GetWorkArea() + 852);
    int j;
    for (j = 0; j < 3; j++) {
        if (t[j] >= 0) {
            u8 *r = (u8 *)Unk02e000_GetAreaRecord(t[j]);
            if (FIELD(u16, r, 52) != 1) {
                Unk0979d8_ResetFields(r);
            }
        }
    }
    Unk096754_ResetAreaPos();
}

/* decompiler-derived */
void Unk0979d8_Unk_097f00(u32 arg0)
{
  Unk096754_ClampField1c();
  Unk0979d8_Unk_09816c(0,arg0);
  Unk0979d8_Unk_09816c(1,arg0);
  Unk0979d8_Unk_09816c(2,arg0);
}

int Unk096754_ClampField1e();
/* decompiler-derived */
void Unk0979d8_Unk_097f34(u32 arg0)
{
  Unk096754_ClampField1e();
  Unk0979d8_Unk_0981bc(0,arg0);
  Unk0979d8_Unk_0981bc(1,arg0);
  Unk0979d8_Unk_0981bc(2,arg0);
}

s32 Unk0979d8_AddField344(s32 d)
{
    u8 *w = (u8 *)Unk02e000_GetWorkArea();
    FIELD(s32, w, 836) += d;
    if (FIELD(s32, w, 836) < 0) {
        FIELD(s32, w, 836) = 0;
    }
    if (FIELD(s32, w, 836) >= 99999999) {
        FIELD(s32, w, 836) = 99999999;
    }
    return FIELD(s32, w, 836);
}
