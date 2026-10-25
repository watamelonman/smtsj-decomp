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


/* Clears unsigned +0x34 and restores the borrowed record fields; NULL returns 0.
 * Evidence: STRH at 02097a10 and BL ResetFields at 02097a14. */
u32 Unk0979d8_Unk_0979fc(Unk0979d8Work *arg0)
{
  if (arg0 != 0) {
    arg0->unk_0034 = 0;
    Unk0979d8_ResetFields((u8 *)arg0);
    return 1;
  }
  return 0;
}

void Unk096754_ClampField1c(int value);
/* Clamps signed +0x1e using signed +0x0a as the upper bound; NULL returns 0.
 * Evidence: LDRSH/STRH at 02097b60..02097b7c. The lower bound of 1
 * applies only when v <= the upper bound, preserving nonpositive maxima. */
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

/* Clamps signed +0x20 against +0x0c, returning the stored signed halfword.
 * Evidence: 02097b90..02097bac; same bound ordering as ClampField1e.
 * NULL returns 0 without writing. */
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

/* Tests the six unsigned halfword IDs at +0x28; NULL returns false.
 * Evidence: LDRH, equality comparison and six-iteration loop at 02097bc4..02097be0.
 * The full-width id is compared without narrowing. */
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

/* Copies six IDs from borrowed record +0x28 to caller-owned out (six u16s).
 * Evidence: LDRH/STRH loop at 02097bf8..02097c10. NULL p leaves out untouched;
 * otherwise out must be writable. */
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

int func_020a1428(u16 id);
void func_02097c18(Unk0979d8Pair *out, Unk0979d8Pair *a, u8 *b);
u8 *Unk02e000_GetWorkArea(void);
u8 *Unk02e000_GetAreaRecord(int index);
u32 Unk0979d8_Unk_0979fc(Unk0979d8Work *arg0);
void Unk0979d8_ResetAreaEntries(void);
void Unk096754_ClampField1c(int value);
void Unk096754_ClampField1e(int value);
void Unk096754_ResetAreaPos(void);
/* Returns the indexed low 10 bits of a generated pair in a 20-pair local buffer.
 * Evidence: +0x36 lookup, pair builder and bit extraction at 02097d54..02097d94.
 * Caller must supply a valid record and index 0..19. */
int Unk0979d8_GetPairLo(u8 *p, int i)
{
    Unk0979d8Pair buf[20];
    func_02097c18(buf, (Unk0979d8Pair *)func_020a1428(FIELD(u16, p, 54)), p + 40);
    return buf[i].lo;
}

/* Returns the indexed high 6 bits of a generated pair; index must be 0..19.
 * Evidence: +0x36 lookup and high-bit extraction at 02097d98..02097dd8. */
int Unk0979d8_GetPairHi(u8 *p, int i)
{
    Unk0979d8Pair buf[20];
    func_02097c18(buf, (Unk0979d8Pair *)func_020a1428(FIELD(u16, p, 54)), p + 40);
    return buf[i].hi;
}

/* Resets up to twelve active records, stopping at a negative slot, then area slots.
 * Evidence: signed slot loads at +0x348 and reset calls at 02097ddc..02097e18. */
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

/* Clamps global +0x1c and active records +0x1e to value.
 * Evidence: global call, twelve-slot loop and record clamp at 02097e1c..02097e68. */
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

/* Clamps global +0x1e and active records +0x20 to value.
 * Evidence: global call, twelve-slot loop and record clamp at 02097e6c..02097eb8. */
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

/* Restores fields for three present area slots unless record state +0x34 is 1,
 * then resets area position. Evidence: +0x354 slots and calls at 02097ebc..02097efc. */
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

/* Forwards value to the global +0x1c clamp, then the +0x1e wrappers for
 * slots 0, 1, 2. Evidence: calls at 02097f08..02097f2c, with live r0
 * on the first call. Absent slots are ignored by the wrappers. */
void Unk0979d8_Unk_097f00(int arg0)
{
  Unk096754_ClampField1c(arg0);
  Unk0979d8_Unk_09816c(0,arg0);
  Unk0979d8_Unk_09816c(1,arg0);
  Unk0979d8_Unk_09816c(2,arg0);
}

void Unk096754_ClampField1e(int value);
/* Forwards value to the global +0x1e clamp, then the +0x20 wrappers for
 * slots 0, 1, 2. Evidence: calls at 02097f3c..02097f60, with live r0
 * on the first call. Absent slots are ignored by the wrappers. */
void Unk0979d8_Unk_097f34(int arg0)
{
  Unk096754_ClampField1e(arg0);
  Unk0979d8_Unk_0981bc(0,arg0);
  Unk0979d8_Unk_0981bc(1,arg0);
  Unk0979d8_Unk_0981bc(2,arg0);
}

/* Adds d to work-area signed +0x344 and bounds the result to 0..99999999.
 * Evidence: ADD/STR at 020980f8..020980fc, conditional bounds through
 * 02098114 and constant at 02098120. Returns the stored value. */
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

int Unk02e000_Unk_02e840(u8 *record);
int Unk0986ac_Unk_098978(int id);
int Unk0986ac_Thunk_02098714(int entry);

/* Returns an unknown score for a borrowed record; NULL and states 1/7
 * return zero. Evidence: state checks and weighted calls at 02097ad0..02097b4c. */
int func_02097ad0(u8 *record, int enabled)
{
    int score;
    if (record == 0) return 0;
    if (FIELD(u16, record, 52) == 1 || FIELD(u16, record, 52) == 7) return 0;
    score = 0;
    if (Unk02e000_Unk_02e840(record) && enabled) {
        if (Unk0986ac_Thunk_02098714(Unk0986ac_Unk_098978(160))) score++;
        if (Unk0986ac_Thunk_02098714(Unk0986ac_Unk_098978(151))) score += 3;
        if (Unk0979d8_HasId(record, 397)) score += 5;
    }
    return score;
}

u8 *Unk02e000_Thunk_0202e788(void);
int Unk096754_CountEntries(void);
/* Sums unsigned +0x38 across selected present records. Mode 0 includes
 * both the main byte +0x6e and active entries; 1 selects active entries;
 * 2 includes the main byte and three area slots. Other modes return zero.
 * Evidence: mode branches, LDRSB slot checks and LDRB at 02098050..020980e0. */
int func_02098050(int mode)
{
    int sum = 0;
    int count;
    s8 *slots;
    int i;
    if (mode == 0 || mode == 2) {
        sum += FIELD(u8, Unk02e000_Thunk_0202e788(), 110);
    }
    count = 0;
    slots = 0;
    switch (mode) {
    case 0:
    case 1:
        count = Unk096754_CountEntries();
        slots = (s8 *)(Unk02e000_GetWorkArea() + 840);
        break;
    case 2:
        count = 3;
        slots = (s8 *)(Unk02e000_GetWorkArea() + 852);
        break;
    }
    for (i = 0; i < count; i++) {
        if (slots[i] >= 0) {
            sum += FIELD(u8, Unk02e000_GetAreaRecord(slots[i]), 56);
        }
    }
    return sum;
}

/* Computes a minimum-one percentage of signed +0x0a when eligible.
 * Evidence: state exclusions, IDs 144/158/396 and signed division by 100
 * at 02097a20..02097acc. NULL, excluded states and zero weight return zero. */
int func_02097a20(u8 *record, int enabled)
{
    int score;
    if (record == 0) return 0;
    if (FIELD(u16, record, 52) == 1 || FIELD(u16, record, 52) == 7) return 0;
    score = 0;
    if (Unk02e000_Unk_02e840(record) && enabled) {
        if (Unk0986ac_Thunk_02098714(Unk0986ac_Unk_098978(144))) score++;
        if (Unk0986ac_Thunk_02098714(Unk0986ac_Unk_098978(158))) score += 3;
        if (Unk0979d8_HasId(record, 396)) score += 3;
    }
    if (score) {
        int value = FIELD(s16, record, 10) * score / 100;
        if (value <= 0) value = 1;
        return value;
    }
    return 0;
}

/* Averages unsigned +0x38 across present slots; modes 0/2 include global
 * +0x6e. Evidence: float accumulation/division at 02097f68..0209804c.
 * Empty selections preserve the original floating-point zero division. */
float func_02097f68(int mode)
{
    float sum = 0;
    float count = 0;
    int size;
    s8 *slots;
    int i;
    if (mode == 0 || mode == 2) {
        sum += FIELD(u8, Unk02e000_Thunk_0202e788(), 110);
        count += 1;
    }
    size = 0;
    slots = 0;
    switch (mode) {
    case 0:
    case 1:
        size = Unk096754_CountEntries();
        slots = (s8 *)(Unk02e000_GetWorkArea() + 840);
        break;
    case 2:
        size = 3;
        slots = (s8 *)(Unk02e000_GetWorkArea() + 852);
        break;
    }
    for (i = 0; i < size; i++) {
        if (slots[i] >= 0) {
            sum += FIELD(u8, Unk02e000_GetAreaRecord(slots[i]), 56);
            count += 1;
        }
    }
    return sum / count;
}

int func_02096548(u8 *ids, int index);
int Unk02f078_IsAllowed_02f190(int current, int candidate);
/* Copies nineteen packed pairs from metadata +0x3a, replaces permitted high
 * fields using the ID list, then halves/caps low fields with high field 5.
 * Evidence: three loops at 02097c38/02097c8c/02097cf0. Buffers are borrowed;
 * out must hold nineteen pairs and metadata must expose the source pairs. */
void func_02097c18(Unk0979d8Pair *out, Unk0979d8Pair *metadata, u8 *ids)
{
    int i;
    Unk0979d8Pair *src = metadata + 29;
    Unk0979d8Pair *p = out;
    int j;
    for (i = 0; i < 19; i++) {
        p->lo = src->lo;
        p->hi = src->hi;
        src++;
        p++;
    }
    p = out;
    for (j = 0; j < 19; j++) {
        int candidate = func_02096548(ids, j);
        if (Unk02f078_IsAllowed_02f190(p->hi, candidate)) {
            p->hi = (u16)candidate;
        }
        p++;
    }
    for (j = 0; j < 19; j++) {
        if (out->hi == 5) {
            out->lo = (u16)(out->lo >> 1);
            if (out->lo > 50) out->lo = 50;
        }
        out++;
    }
}
