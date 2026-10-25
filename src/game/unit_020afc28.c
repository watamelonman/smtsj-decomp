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
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
typedef struct Unk0afc28Pos12 {
    u32 w[3];
} Unk0afc28Pos12;

typedef struct Unk0afc28Ptrs {
    u8 pad_00[0x64];
    u32 *e[10];
} Unk0afc28Ptrs;

int Unk0981dc_Unk_098324(int a, int b);
int func_02050074(int lower, int upper);
int Unk0afc28_Unk_0afd60(int a, int b);
Unk0afc28Ptrs *Unk044904_Get_data_0215ee98(void);
typedef struct Unk0afc28Pos Unk0afc28Pos;
Unk0afc28Pos *func_020982c0(int id);
int Unk0afc28_IsOrigin(Unk0afc28Pos *p);
/* Owns a three-word record at +0x24; earlier fields are unknown. */
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
 * Evidence: calls to 0204a67c and 020492ec; any nonzero flag negates. */
void Unk0afc28_Unk_0afdd0(const void *arg0, u32 arg1, int arg2)
{
  int tmp1;
  tmp1 = func_0204a67c(arg0, arg1);
  if (arg2 != 0) {
    tmp1 = -tmp1;
  }
  func_020492ec(arg1,tmp1);
  return;
}



/* decompiler-derived */
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
    u16 unk_0008;
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
