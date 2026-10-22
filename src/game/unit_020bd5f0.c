/* src/game/unit_020bd5f0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0bd5f0Work {
    u8 pad_0000[0x150];
    u32 unk_0150;
    u32 unk_0154;
    u32 unk_0158;
    u32 unk_015c;
} Unk0bd5f0Work;



extern u8 data_0213c4d4[];
int func_02057ddc();
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int Unk02e000_GetWorkArea();
/* Non-zero only for an object whose state word at +8 is 2 and whose value at +4 is at least 2
   (the caller compares the result as a predicate). */
int Unk0bd5f0_Unk_0bd5f0(s32 *p)
{
    if (p[2] == 2 && p[1] >= 2) {
        return 1;
    }
    return 0;
}

/* Forwards the word at data_0213c4d4[index] to func_02057ddc (which copies it into four
   consecutive words of data_02168b24) and always reports 0. */
u32 Unk0bd5f0_Unk_0bd614(int arg0)
{
  func_02057ddc(*(u32 *)(((int)data_0213c4d4) + arg0 * 4));
  return 0;
}

int func_020c8008();
int Unk02e000_GetWorkArea();
void *Unk09974c_Unk_099d78(u32 id);
int Unk09974c_Unk_0998d8(u32 id);
int Unk09974c_HasFlagsMid(void *f);
void CampStatus_Unk_0dde3c(void *obj, u32 a, u32 b, const u32 *ids, u32 n);
void Unk0ddeb0_Unk_0ddeb0(void *obj, int a, int b, int c, int d, int e);
void func_020c72a4(void *obj, u32 a, u32 b);
/* Returns the first matching signed-byte entry at +0x348, or the count at +0x357.
   i indexes the caller-owned three-entry mapping at +0x354. */
int Unk0bd5f0_Unk_0c1870(int i)
{
    u8 *w = (u8 *)Unk02e000_GetWorkArea();
    int j;
    for (j = 0; j < FIELD(u8, w, 855); j++) {
        if (FIELD(s8, w + j + 768, 72) == FIELD(s8, w + i + 768, 84)) {
            break;
        }
    }
    return j;
}

/* For a nonnegative signed mapping at +0x348+i, tests the mapped 60-byte
   record: true when its +0xa8 halfword is 1 or its signed +0x92 halfword is <= 0. */
int Unk0bd5f0_Unk_0c1918(int i)
{
    u8 *w = (u8 *)Unk02e000_GetWorkArea();
    s32 k = FIELD(s8, w + i + 768, 72);
    u8 *e;
    if (k >= 0) {
        e = w + k * 60;
        if (FIELD(u16, e, 168) == 1 || FIELD(s16, e, 146) <= 0) {
            return 1;
        }
    }
    return 0;
}

/* Tail-calls func_020c8008 with all four arguments zero. */
void Unk0bd5f0_Unk_0c1ad8(void)
{
  func_020c8008(0,0,0,0);
}

extern u32 data_02176bb0[];
int func_020c1b94();
/* Calls func_020c1b94 on the object stored in data_02176bb0 when that pointer is non-null. */
void Unk0bd5f0_Unk_0c20f0(void)
{
  if (*data_02176bb0 == 0) {
    return;
  }
  func_020c1b94();
}


/* Lexicographic ordering of two 16-bit key pairs: compares the word at +2 first and, when those
   are equal, the word at +0. Returns a negative, zero or positive difference. */
int Unk0bd5f0_Unk_0c7588(u16 *arg0,u16 *arg1)
{
  int value;
  value = (u32)arg0[1] - (u32)arg1[1];
  if (value == 0) {
    value = (u32)*arg0 - (u32)*arg1;
  }
  return value;
}




/* Orders accepted ids before unaccepted ids, then compares the second halfword
   and finally the id. Each argument borrows a readable pair of halfwords. */
int Unk0bd5f0_Unk_0c75a8(u16 *arg0,u16 *arg1)
{
  int tmp1;
  int tmp2;
  tmp1 = Unk09974c_Unk_0998d8(*arg0);
  tmp2 = Unk09974c_Unk_0998d8(*arg1);
  if ((tmp1 != 0) && (tmp2 == 0)) {
    return -1;
  }
  if ((tmp1 == 0) && (tmp2 != 0)) {
    return 1;
  }
  tmp1 = (u32)arg0[1] - (u32)arg1[1];
  if (tmp1 == 0) {
    tmp1 = (u32)*arg0 - (u32)*arg1;
  }
  return tmp1;
}


int func_020537b8(u32 port, u32 mask);
/* decompiler-derived */
void Unk0bd5f0_Unk_0c2050(Unk0bd5f0Work *arg0){
  int tmp1;
  tmp1 = func_020537b8(0,0x40);
  if (tmp1 != 0) {
    arg0->unk_0150 = 1;
  }
  tmp1 = func_020537b8(0,0x80);
  if (tmp1 != 0) {
    arg0->unk_0154 = 1;
  }
  tmp1 = func_020537b8(0,0x20);
  if (tmp1 != 0) {
    arg0->unk_0158 = 1;
  }
  tmp1 = func_020537b8(0,0x10);
  if (tmp1 != 0) {
    arg0->unk_015c = 1;
  }
  return;
}

typedef struct Unk0bd5f0Ctx {
    s32 unk_0000; /* state word: 20, 22 or 24 seen */
    s32 unk_0004;
    u8 pad_0008[0xf8];
    void *unk_0100; /* passed to Unk0ddeb0_Unk_0ddeb0 */
    u8 pad_0104[0x4];
    void *unk_0108; /* passed to CampStatus_Unk_0dde3c */
    u8 pad_010c[0x8];
    s32 unk_0114;
    s32 unk_0118;
    s32 unk_011c;
    s32 unk_0120;
    u8 pad_0124[0x94];
    u32 unk_01b8;
} Unk0bd5f0Ctx;

/* Object passed to Unk0bd5f0_Unk_0c8510. Kept separate from Unk0bd5f0Ctx: its -110
   write lands at +0x114 where Unk0bd5f0Ctx has it at +0x118. */
typedef struct Unk0bd5f0Obj {
    s32 unk_0000;
    s32 unk_0004;
    u8 pad_0008[0xf8];
    void *unk_0100; /* passed to func_020c72a4 */
    u8 pad_0104[0xc];
    u8 unk_0110;
    u8 pad_0111[0x3];
    s32 unk_0114;
} Unk0bd5f0Obj;

extern Unk0bd5f0Ctx *data_02176bb4;

/* Returns true only when both func_020537b8 queries (group 0, masks 0x40 and
   0x80) are clear; the second query is skipped when the first is set. */
int Unk0bd5f0_Unk_0c20bc(void)
{
    if (func_020537b8(0, 64) != 0) {
        return 0;
    }
    return func_020537b8(0, 128) == 0;
}

/* Searches ids 111..210 inclusive for an accepted id whose record passes
   Unk09974c_HasFlagsMid. Evidence for the name: the bounded id loop and
   calls to Unk09974c_Unk_099d78, Unk09974c_Unk_0998d8 and HasFlagsMid. */
int Unk0bd5f0_AnyIdWithFlagsMid(void)
{
    u32 id;
    for (id = 111; id <= 210; id++) {
        void *r = Unk09974c_Unk_099d78(id);
        if (Unk09974c_Unk_0998d8(id) != 0 && Unk09974c_HasFlagsMid(r) != 0) {
            return 1;
        }
    }
    return 0;
}

/* Searches ids 111..210 inclusive for an accepted id whose record fails
   Unk09974c_HasFlagsMid. Evidence for the name: the bounded id loop and
   the negated HasFlagsMid result after Unk09974c_Unk_0998d8 accepts the id. */
int Unk0bd5f0_AnyIdWithoutFlagsMid(void)
{
    u32 id;
    for (id = 111; id <= 210; id++) {
        void *r = Unk09974c_Unk_099d78(id);
        if (Unk09974c_Unk_0998d8(id) != 0 && Unk09974c_HasFlagsMid(r) == 0) {
            return 1;
        }
    }
    return 0;
}

/* For a live global context, forwards its unk_0108 object and the four
   caller-supplied arguments to CampStatus_Unk_0dde3c; a null context is a no-op. */
void Unk0bd5f0_Unk_0c7f70(u32 a, u32 b, const u32 *ids, u32 n)
{
    if (data_02176bb4 == 0) {
        return;
    }
    CampStatus_Unk_0dde3c(data_02176bb4->unk_0108, a, b, ids, n);
}

/* For a live global context, sets the first two words to 20 and 22, the
   word at +0x118 to -110, and the words at +0x120 and +0x11c to zero. */
void Unk0bd5f0_Unk_0c7fbc(void)
{
    if (data_02176bb4 == 0) {
        return;
    }
    data_02176bb4->unk_0000 = 20;
    data_02176bb4->unk_0004 = 22;
    data_02176bb4->unk_0118 = -110;
    data_02176bb4->unk_0120 = 0;
    data_02176bb4->unk_011c = 0;
}

/* For a live global context, passes its +0x100 word and +0x114 word plus
   three to Unk0ddeb0_Unk_0ddeb0, followed by constants -2, 0, 12 and 10. */
void Unk0bd5f0_Unk_0c842c(void)
{
    Unk0bd5f0Ctx *c = data_02176bb4;
    if (c == 0) {
        return;
    }
    Unk0ddeb0_Unk_0ddeb0(c->unk_0100, c->unk_0114 + 3, -2, 0, 12, 10);
}

/* Tests the global context's first word for 22 or 24, returning false for
   a null context. Evidence for the name: the two equality comparisons in this function
   and the state-word writes in Unk0bd5f0_Unk_0c7fbc. */
int Unk0bd5f0_IsState22or24(void)
{
    s32 v;
    if (data_02176bb4 == 0) {
        return 0;
    }
    v = data_02176bb4->unk_0000;
    return v == 22 || v == 24;
}

/* Marks the context object in data_02176bb4 by setting the word at +0x1b8 to 1. */
void Unk0bd5f0_SetCtxUnk1b8(void)
{
    data_02176bb4->unk_01b8 = 1;
}

/* Reads p->unk_0100 and p->unk_0110 and passes them with zero to func_020c72a4,
   then writes unk_0000 = 20, unk_0004 = b and unk_0114 = -110. */
void Unk0bd5f0_Unk_0c8510(Unk0bd5f0Obj *p, s32 b)
{
    func_020c72a4(p->unk_0100, p->unk_0110, 0);
    p->unk_0000 = 20;
    p->unk_0004 = b;
    p->unk_0114 = -110;
}

/* Membership test for the special ids 5, 6, 8 and 22. */
int Unk0bd5f0_IsSpecialId(int id)
{
    if (id == 8 || id == 5 || id == 6 || id == 22) {
        return 1;
    }
    return 0;
}

/* Returns whether the signed byte at offset 0x348 + index in the shared work area is
   non-negative. The explicit u32 arithmetic reproduces the original addressing (See DEC-002). */
int func_020c1968(int idx)
{
    s8 *flags = (s8 *)((u32)Unk02e000_GetWorkArea() + (u32)idx + 0x300);
    return flags[0x48] >= 0;
}

/* Callback addresses are stored here without invoking them; their full calling
   contracts are not established by these descriptor initializers. */
typedef struct Unk0bd5f0Descriptor {
    u32 size;
    u32 kind;
    u32 unk_0008;
    void (*unk_000c)(void *);
    void (*unk_0010)(void *);
    u32 unk_0014;
    void (*unk_0018)(void *);
    void (*unk_001c)(void *);
    void (*unk_0020)(void *);
} Unk0bd5f0Descriptor;

extern void func_020bf240(void *);
extern void func_020bda18(void *);
extern void func_020bfddc(void *);
extern void func_020c0c5c(void *);
extern void func_020c0d48(void *);
extern void func_020c5094(void *);
extern void func_020c25d0(void *);
extern void func_020c5dc0(void *);
extern void func_020c67a0(void *);
extern void func_020c6888(void *);

/* Initializes a 352-byte, kind-zero callback descriptor, preserving +8. */
void func_020bd9c4(Unk0bd5f0Descriptor *p)
{
    p->size = 352;
    p->kind = 0;
    p->unk_000c = func_020bf240;
    p->unk_0010 = func_020bda18;
    p->unk_0014 = 0;
    p->unk_0018 = func_020bfddc;
    p->unk_001c = func_020c0c5c;
    p->unk_0020 = func_020c0d48;
}

/* Initializes a 448-byte, kind-three callback descriptor, preserving +8. */
void func_020c2578(Unk0bd5f0Descriptor *p)
{
    p->size = 448;
    p->kind = 3;
    p->unk_000c = func_020c5094;
    p->unk_0010 = func_020c25d0;
    p->unk_0014 = 0;
    p->unk_0018 = func_020c5dc0;
    p->unk_001c = func_020c67a0;
    p->unk_0020 = func_020c6888;
}

extern u32 *func_020445f4(u32 group, u32 selector);
extern void func_02063920(void);
extern u32 func_0204fed8(u32 *table, u32 index);
extern u32 func_02063a30(u32 value);
extern void func_02061f10(void *obj, int a, int b, int c, u32 value);

/* Uses group 12 and the supplied selector; only indices below table word +12
   are converted and forwarded to obj. The table and obj are borrowed. */
void func_020c72a4(void *obj, u32 selector, u32 index)
{
    u32 *table = func_020445f4(12, selector);
    if (index >= table[3]) return;
    func_02063920();
    func_02061f10(obj, -1, 0, 0, func_02063a30(func_0204fed8(table, index)));
}

extern void func_020c7304(void *obj);
extern void func_020bcfc4(void *obj, u32 value);
extern void Unk0a0ce4_Unk_0a0da4(u32 value);

/* Pops the byte-sized selection stack at +0x124 after func_020c7304, restores
   its value through +0x44, updates the +0x108 object and signals value 2.
   Requires a populated stack and readable entries starting at +0x128. */
void func_020c84c0(u8 *obj)
{
    func_020c7304(obj);
    FIELD(u8, obj, 292)--;
    func_020bcfc4(obj + 68, FIELD(u32, obj + FIELD(u8, obj, 292) * 4, 296));
    func_020c72a4(FIELD(void *, obj, 264), FIELD(u8, obj, 272),
                  (u8)(FIELD(u32, obj, 84) + 100));
    Unk0a0ce4_Unk_0a0da4(2);
}
