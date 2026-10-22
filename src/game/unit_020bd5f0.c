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
int Unk09974c_Unk_099d78();
int Unk09974c_Unk_0998d8();
int Unk09974c_HasFlagsMid();
void func_020dde3c();
void Unk0ddeb0_Unk_0ddeb0();
void func_020c72a4();
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




/* decompiler-derived */
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


int func_020537b8();
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
    u8 pad_0000[0x1b8];
    u32 unk_01b8;
} Unk0bd5f0Ctx;

extern Unk0bd5f0Ctx *data_02176bb4;

int Unk0bd5f0_Unk_0c20bc(void)
{
    if (func_020537b8(0, 64) != 0) {
        return 0;
    }
    return func_020537b8(0, 128) == 0;
}

int Unk0bd5f0_AnyIdWithFlagsMid(void)
{
    u32 id;
    for (id = 111; id <= 210; id++) {
        int r = Unk09974c_Unk_099d78(id);
        if (Unk09974c_Unk_0998d8(id) != 0 && Unk09974c_HasFlagsMid(r) != 0) {
            return 1;
        }
    }
    return 0;
}

int Unk0bd5f0_AnyIdWithoutFlagsMid(void)
{
    u32 id;
    for (id = 111; id <= 210; id++) {
        int r = Unk09974c_Unk_099d78(id);
        if (Unk09974c_Unk_0998d8(id) != 0 && Unk09974c_HasFlagsMid(r) == 0) {
            return 1;
        }
    }
    return 0;
}

void Unk0bd5f0_Unk_0c7f70(u32 a, u32 b, u32 c, u32 d)
{
    if (data_02176bb4 == 0) {
        return;
    }
    func_020dde3c(FIELD(u32, data_02176bb4, 264), a, b, c, d);
}

void Unk0bd5f0_Unk_0c7fbc(void)
{
    if (data_02176bb4 == 0) {
        return;
    }
    FIELD(s32, data_02176bb4, 0) = 20;
    FIELD(s32, data_02176bb4, 4) = 22;
    FIELD(s32, data_02176bb4, 280) = -110;
    FIELD(s32, data_02176bb4, 288) = 0;
    FIELD(s32, data_02176bb4, 284) = 0;
}

void Unk0bd5f0_Unk_0c842c(void)
{
    u8 *c = (u8 *)data_02176bb4;
    if (c == 0) {
        return;
    }
    Unk0ddeb0_Unk_0ddeb0(FIELD(u32, c, 256), FIELD(s32, c, 276) + 3, -2, 0, 12, 10);
}

int Unk0bd5f0_IsState22or24(void)
{
    s32 v;
    if (data_02176bb4 == 0) {
        return 0;
    }
    v = FIELD(s32, data_02176bb4, 0);
    return v == 22 || v == 24;
}

/* Marks the context object in data_02176bb4 by setting the word at +0x1b8 to 1. */
void Unk0bd5f0_SetCtxUnk1b8(void)
{
    data_02176bb4->unk_01b8 = 1;
}

void Unk0bd5f0_Unk_0c8510(s32 *p, s32 b)
{
    func_020c72a4(p[64], FIELD(u8, p, 272), 0);
    p[0] = 20;
    p[1] = b;
    p[69] = -110;
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
