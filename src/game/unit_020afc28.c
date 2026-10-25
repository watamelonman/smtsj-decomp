/* Layouts below describe only fields observed in this translation unit. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0afc28Work {
    u8 pad_0000[0x20];
    s32 unk_0020;
} Unk0afc28Work;


/* Add a signed delta to field +0x20; the caller owns the work area. */
void Unk0afc28_Unk_0afc28(Unk0afc28Work *arg0, int arg1){
  arg0->unk_0020 = arg0->unk_0020 + arg1;
  return;
}

int func_020492ec(u32 selector, int value);
int func_0204a67c(const void *work, u32 selector);
typedef struct Unk0afc28Pos12 {
    u32 w[3];
} Unk0afc28Pos12;

typedef struct Unk0afc28Ptrs {
    u8 pad_00[0x40];
    u32 unk_0040;
    u8 pad_0044[0x20];
    u32 *e[10];
    u8 unk_008c[1];
} Unk0afc28Ptrs;

int Unk0981dc_Unk_098324(int a, int b);
int func_02050074(int lower, int upper);
int Unk0afc28_Unk_0afd60(int a, int b);
Unk0afc28Ptrs *Unk044904_Get_data_0215ee98(void);
typedef struct Unk0afc28Pos Unk0afc28Pos;
Unk0afc28Pos *func_020982c0(int id);
int Unk0afc28_IsOrigin(Unk0afc28Pos *p);
/* Borrowed work view with a three-word record at +0x24. */
typedef struct Unk0afc28RecordWork {
    u8 pad_0000[0x24];
    Unk0afc28Pos12 unk_0024;
} Unk0afc28RecordWork;

/* Copy the record unless its nonzero current ID fails the pair predicate.
 * Evidence: +0x24 word test, signed low-byte call, then a 12-byte copy. */
void Unk0afc28_Unk_0afc38(Unk0afc28RecordWork *p, const Unk0afc28Pos12 *src)
{
    u32 cur = p->unk_0024.w[0];
    if (cur != 0 && Unk0981dc_Unk_098324((s8)src->w[0], (s8)cur) == 0) {
        return;
    }
    p->unk_0024 = *src;
}

/* Query the work/selector pair and forward its optionally negated result.
 * Evidence: calls to 0204a67c and 020492ec; any nonzero flag negates.
 * Return the forwarded result, consumed by the fixed-point calculations. */
int Unk0afc28_Unk_0afdd0(const void *arg0, u32 arg1, int arg2)
{
  int tmp1;
  tmp1 = func_0204a67c(arg0, arg1);
  if (arg2 != 0) {
    tmp1 = -tmp1;
  }
  return func_020492ec(arg1,tmp1);
}


/* Map selectors 0..7 to 8..15, otherwise 26; evidence: jump-table returns. */
u32 Unk0afc28_Unk_0afcd4(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 8;
  case 1:
    return 9;
  case 2:
    return 10;
  case 3:
    return 0xb;
  case 4:
    return 0xc;
  case 5:
    return 0xd;
  case 6:
    return 0xe;
  case 7:
    return 0xf;
  default:
    return 0x1a;
  }
}

struct Unk0afc28Pos {
    u8 pad_0000[0x4];
    s8 x;                       /* +0x04 */
    s8 unk_0005;
    s8 y;                       /* +0x06 */
};

/* Return the signed byte at +5 of the record for the signed low-byte ID.
 * The lookup must succeed: the original dereferences it without a null check. */
int func_020afd48(int id)
{
    return func_020982c0((s8)id)->unk_0005;
}

/* Card alias RandSpread: centre a random value from (0, 2*a*b) and divide
 * by 100, truncating toward zero. Evidence: 02050074 call and signed division.
 * Products must fit s32. Preserve the canonical neutral symbol name. */
int Unk0afc28_Unk_0afd60(int a, int b)
{
    int n = a * b * 2;
    return (func_02050074(0, n) - n / 2) / 100;
}

/* For a <= c, use a random value plus one; otherwise add the scaled spread
 * to a. Clamp either result to at least one; arithmetic must fit s32. */
int Unk0afc28_Unk_0afd98(int a, int b, int c)
{
    int r;
    if (a <= c) {
        r = func_02050074(0, c - 1) + 1;
    } else {
        r = Unk0afc28_Unk_0afd60(a, b);
        r += a;
    }
    if (r <= 0) {
        r = 1;
    }
    return r;
}

/* Count nonnull entries whose bits 16..23 equal id; evidence for CountById
 * is the ten-pointer scan and extracted ID comparison. Storage is borrowed. */
int Unk0afc28_CountById(u32 id)
{
    Unk0afc28Ptrs *g = (Unk0afc28Ptrs *)Unk044904_Get_data_0215ee98();
    int n = 0;
    int j;
    for (j = 0; j < 10; j++) {
        u32 *e = g->e[j];
        if (e != 0 && id == ((e[0] >> 16) & 0xff)) {
            n++;
        }
    }
    return n;
}

/* Evidence for IsOrigin: signed coordinate bytes +4 and +6 are both tested
 * against zero. Return -1 for the origin, zero otherwise; p is borrowed. */
int Unk0afc28_IsOrigin(Unk0afc28Pos *p)
{
    if (p->x == 0 && p->y == 0) {
        return -1;
    }
    return 0;
}

/* Output layout evidenced by word stores +0/+4 and halfword stores +8/+10. */
typedef struct Unk0afc28Result {
    u32 unk_0000;
    u32 unk_0004;
    s16 unk_0008;
    u16 unk_000a;
} Unk0afc28Result;

/* Look up c's signed low byte; leave output untouched if absent (return 0).
 * Otherwise store c, a, b and the origin predicate and return 1. */
int Unk0afc28_Unk_0b0930(Unk0afc28Result *p, u32 a, u16 b, u32 c)
{
    Unk0afc28Pos *r = (Unk0afc28Pos *)func_020982c0((s8)c);
    if (r == 0) {
        return 0;
    }
    p->unk_0000 = c;
    p->unk_0004 = a;
    p->unk_000a = b;
    p->unk_0008 = Unk0afc28_IsOrigin(r);
    return 1;
}

/* Each slot has an ID and a signed accumulated value, from +0x30 accesses. */
typedef struct Unk0afc28Slot {
    u32 id;
    int value;
} Unk0afc28Slot;
typedef struct Unk0afc28SlotWork {
    u8 pad_0000[0x30];
    Unk0afc28Slot slots[10];
} Unk0afc28SlotWork;

/* Accumulate in the first empty or matching slot; return whether it existed.
 * Evidence: paired word loads/stores, ten-slot bound, and nonzero old ID test. */
int func_020afc80(Unk0afc28SlotWork *work, u32 id, int delta)
{
    int found = 0;
    Unk0afc28Slot *slot = work->slots;
    int i = 0;
    for (; i < 10; i++, slot++) {
        u32 old = slot->id;
        if (old == 0 || old == id) {
            slot->id = id;
            if (old != 0) found = 1;
            slot->value += delta;
            break;
        }
    }
    return found;
}

u32 func_02049d80(const void *work, u32 selector);
int func_0204a968(const void *work, int selector);
int func_0204aa98(const void *work);
int func_0204abd8(const void *work, int selector);
int func_0204a7f4(const void *work, int selector);
int func_020b071c(int value, int flag, int selector);

/* Compare a random 0..99 draw with 5*(query(a,7)+10)/(query(b,7)+10),
 * clamped to 1..50. Evidence: unsigned division and unsigned clamp branches. */
int func_020afdf8(const void *a, const void *b)
{
    u32 chance = 5;
    chance *= func_02049d80(a, 7) + 10;
    chance /= func_02049d80(b, 7) + 10;
    if (chance < 1) chance = 1;
    if (chance > 50) chance = 50;
    return (u32)func_02050074(0, 99) < chance;
}

/* Only value 1 is eligible. Accept a nonzero +0x8c selector-one query;
 * otherwise flag must be set and kind must be 1/7 or selector zero nonzero.
 * Evidence: original comparisons and provider calls; storage is borrowed. */
int func_020b06a0(int value, int flag)
{
    Unk0afc28Ptrs *g;
    if (value != 1) return 0;
    g = Unk044904_Get_data_0215ee98();
    if (func_0204a968(g->unk_008c, 1) == 0) {
        if (flag != 0) {
            int kind = func_0204aa98(g->unk_008c);
            if (kind == 1 || kind == 7) return 1;
            if (func_0204abd8(g->unk_008c, 0) == 0) return 0;
        } else {
            return 0;
        }
    }
    return 1;
}

/* Invert the initial predicate except when global bit 10 is clear and it
 * succeeds: that path delegates to 0b06a0 with flag zero. */
int func_020b07c4(int value)
{
    int result = func_020b071c(value, 0, -1);
    Unk0afc28Ptrs *g = Unk044904_Get_data_0215ee98();
    if ((g->unk_0040 << 21) >> 31 == 0) {
        if (result != 0) return func_020b06a0(value, 0);
    } else {
        if (result != 0) return 0;
    }
    return 1;
}

/* Same instruction-observed dispatch as 0b07c4, passing flag one to both
 * predicates; the provider's bit 10 suppresses the second query. */
int func_020b081c(int value)
{
    int result = func_020b071c(value, 1, -1);
    Unk0afc28Ptrs *g = Unk044904_Get_data_0215ee98();
    if ((g->unk_0040 << 21) >> 31 == 0) {
        if (result != 0) return func_020b06a0(value, 1);
    } else {
        if (result != 0) return 0;
    }
    return 1;
}

/* Borrowed layout: the original reads a halfword at +0x17a. */
typedef struct Unk0afc28ScaleRecord {
    u8 pad_0000[10];
    u16 unk_000a;
} Unk0afc28ScaleRecord;
typedef struct Unk0afc28ScaleWork {
    u8 pad_0000[0x170];
    Unk0afc28ScaleRecord record;
} Unk0afc28ScaleWork;

/* For kind 3, scale selector 17 by the +0x17a halfword, optionally doubling,
 * divide by 100, add five and spread, then clamp to one. Other kinds return 0. */
int func_020b0a5c(Unk0afc28ScaleWork *work)
{
    Unk0afc28ScaleRecord *record;
    int scale;
    int result;
    if (func_0204aa98(work) != 3) return 0;
    record = &work->record;
    scale = func_02049d80(work, 17);
    if (func_0204a7f4(work, 0) != 0) scale *= 2;
    result = record->unk_000a * scale / 100 + 5;
    result += Unk0afc28_Unk_0afd60(result, 10);
    if (result <= 0) result = 1;
    return result;
}

/* Kind-nine counterpart of 0b0a5c, halving before spread; evidence: kind
 * comparison, selector 23 and signed divide by two. Work remains borrowed. */
int func_020b0adc(Unk0afc28ScaleWork *work)
{
    Unk0afc28ScaleRecord *record;
    int scale;
    int result;
    if (func_0204aa98(work) != 9) return 0;
    record = &work->record;
    scale = func_02049d80(work, 23);
    if (func_0204a7f4(work, 0) != 0) scale *= 2;
    result = (record->unk_000a * scale / 100 + 5) / 2;
    result += Unk0afc28_Unk_0afd60(result, 10);
    if (result <= 0) result = 1;
    return result;
}

/* Count matching ten-slot IDs without selector-one state; when flag is set,
 * also exclude selector-zero state and kinds 1/7. Third argument is unused
 * in the original; evidence: the loop never reads incoming r2. */
int func_020b071c(int value, int flag, int selector)
{
    Unk0afc28Ptrs *g = Unk044904_Get_data_0215ee98();
    int n = 0;
    int i;
    for (i = 0; i < 10; i++) {
        u32 *entry = g->e[i];
        if (entry != 0 && value == ((entry[0] >> 16) & 255)) {
            if (func_0204a968(entry, 1) == 0) {
                if (flag != 0) {
                    if (func_0204abd8(entry, 0) == 0) {
                        int kind = func_0204aa98(entry);
                        if (kind != 1 && kind != 7) n++;
                    }
                } else n++;
            }
        }
    }
    return n;
}

/* Borrowed provider view: only the byte used by the packed result is known. */
typedef struct Unk0afc28PackedWork {
    u8 pad_0000[0x1dc];
    u8 unk_01dc;
} Unk0afc28PackedWork;
Unk0afc28PackedWork *func_02044ec4(u32 id);
/* Pack capped selector-six percentage in bits 10..25, provider byte in
 * bits 2..9 and bit zero. Evidence: shifts, ORs and the 0xffff cap.
 * Missing provider returns zero; products must fit signed 32 bits. */
u32 func_020b0874(u32 id, int percent)
{
    Unk0afc28PackedWork *work = func_02044ec4(id);
    int value;
    Unk0afc28Ptrs *g;
    if (work == 0) return 0;
    value = func_02049d80(work, 6);
    value += func_02050074(0, 10) - 5;
    if (value < 0) value = 0;
    g = Unk044904_Get_data_0215ee98();
    if ((g->unk_0040 << 21) >> 31 == 0 && ((id >> 16) & 255) == 1)
        value += 3;
    value *= percent;
    value /= 100;
    if (value > 65535) value = 65535;
    return ((u32)work->unk_01dc << 2) | ((u32)(u16)value << 10) | 1;
}

/* Round a signed 20.12 product to nearest, as in each SMULL/add/shift chain. */
static inline int Unk0afc28_Mul(int a, int b)
{
    return (s32)(((s64)a * b + 0x800) >> 12);
}

int func_0200219c(int numerator, int denominator);
int func_020491cc(int delta);
int func_02049220(int delta, int scale);
int func_0204a230(const void *work);
int func_0204a120(const void *work, int selector);

/* Combine selector multipliers in 20.12 units, with +0x282 bit two applying
 * factor 0x119a. Evidence: provider selectors 13/12 and rounded products.
 * Inputs are borrowed; the final result is in integer units. */
int func_020affc8(const void *a, const void *b, int base, int factor, u32 selector)
{
    int left = Unk0afc28_Unk_0afdd0(b, 13, 0);
    int right = Unk0afc28_Unk_0afdd0(a, 12, 0);
    int ratio = func_0200219c(func_02049d80(b, Unk0afc28_Unk_0afcd4(selector)) << 12, 100 << 12);
    factor = Unk0afc28_Mul(factor, Unk0afc28_Mul(right, left));
    factor = Unk0afc28_Mul(factor, ratio);
    if ((u32)(FIELD(u8, a, 0x282) << 29) >> 31)
        factor = (s32)(((s64)factor * 0x119aLL + 0x800) >> 12);
    return Unk0afc28_Mul(base << 12, factor) >> 12;
}

/* Calculate from selectors 3 and 5 and supplied level, then spread/clamp.
 * Evidence: provider calls and the 4*level/10 term; arithmetic must fit s32. */
int func_020b00c0(const void *a, const void *b, int level, int factor, u32 selector)
{
    int stat = func_02049d80(a, 3);
    int value = func_020491cc(stat - func_02049d80(b, 5));
    value = (s32)(((s64)factor * value + 0x800) >> 12);
    value = Unk0afc28_Mul(value, func_02049220(level - func_0204a230(b), 60));
    level = stat + level * 4 / 10 + 5;
    value = func_020affc8(a, b, level, value, selector);
    return Unk0afc28_Unk_0afd98(value, 10, 3);
}

/* Selector-four variant: use twice the source stat minus target stat/level.
 * Evidence: selector 4 calls and the 8*source/10 term; inputs are borrowed. */
int func_020b017c(const void *a, const void *b, int factor, u32 selector)
{
    int stat = func_02049d80(a, 4);
    int other = func_02049d80(b, 4);
    int value = func_020491cc(stat - other);
    value = (s32)(((s64)factor * value + 0x800) >> 12);
    value = Unk0afc28_Mul(value, func_02049220(stat * 2 - (other + func_0204a230(b)), 60));
    value = func_020affc8(a, b, stat + stat * 8 / 10 + 5, value, selector);
    return Unk0afc28_Unk_0afd98(value, 10, 3);
}

/* Inspect the record at +0x170: absent/negative/one states return zero.
 * Coordinate-zero records compare y to state; others compare a random draw
 * with a selector-based ratio plus ten times state. Evidence: signed loads,
 * signed division, SMLABB and unsigned final comparison. */
int func_020b0974(const void *work)
{
    const Unk0afc28Result *record = (const Unk0afc28Result *)((const u8 *)work + 0x170);
    Unk0afc28Pos *pos;
    int denom;
    u32 chance;
    if (record->unk_0000 == 0) return 0;
    if ((s16)record->unk_0008 < 0) return 0;
    if ((s16)record->unk_0008 == 1) return 0;
    pos = func_020982c0((s8)record->unk_0000);
    if (pos->x == 0) {
        if (pos->y != 0) {
            if (pos->y < (s16)record->unk_0008) return 1;
        }
    } else {
        denom = (int)(func_02049d80(work, 2) * 6) / 10;
        chance = (pos->x * (int)func_02049d80(work, 7) + 10) / (denom + 15);
        chance += (s16)record->unk_0008 * 10;
        if ((u32)func_02050074(0, 99) < chance) return 1;
    }
    return 0;
}
