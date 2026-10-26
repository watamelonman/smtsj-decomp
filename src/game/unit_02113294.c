/* src/game/unit_02113294.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk113294Work {
    u32 unk_0000;
    s32 unk_0004;
    u8 unk_0008;
    u8 pad_0009[3];
    s32 unk_000c;
    u32 unk_0010;
    u8 pad_0014[0x8];
    u32 unk_001c;
    u32 unk_0020;
    u8 pad_0024[0x4];
    u32 unk_0028;
    u8 pad_002c[0xa4];
    u32 unk_00d0;
    u8 pad_00d4[4];
    u16 unk_00d8;
} Unk113294Work;

int Unk0a0ce4_Unk_0a0da4();
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
extern u32 data_02176e54[];
int func_02061f10();
int Unk113294_IsOtherId();
int Unk113294_AnyHi();
int Unk113294_AnyLo();
int Unk02e000_Thunk_0202e788();
void func_02008904();
void Unk02ee5c_Unk_02efa4();
typedef struct Unk113294Ids {
    u8 pad[216];
    u16 ids[16];
} Unk113294Ids;
/* Tests the observed conjunction: halfword +0xd8 and word +0xc are zero,
 * and word +4 is one. No broader state meaning is established. */
int Unk113294_Unk_113e90(const Unk113294Work *work)
{
    return work->unk_00d8 == 0 && work->unk_000c == 0 && work->unk_0004 == 1;
}

void Unk113294_Unk_113eb4(u8 *p)
{
    p[0] = 5;
    *data_02176e54 = 0;
    Unk0a0ce4_Unk_0a0da4(2);
}

/* decompiler-derived */
void Unk113294_Unk_1156c4(u8 *arg0)
{
  Unk0a0ce4_Unk_0a0da4(0xb);
  ((Unk113294Work *)arg0)->unk_00d0 = 0xffffffff;
  ((Unk113294Work *)arg0)->unk_001c = 3;
  *arg0 = 3;
}


/* decompiler-derived */
void Unk113294_Unk_115698(u8 *arg0)
{
  Unk0a0ce4_Unk_0a0da4(0xb);
  ((Unk113294Work *)arg0)->unk_00d0 = 0xffffffff;
  ((Unk113294Work *)arg0)->unk_001c = 2;
  *arg0 = 3;
}



/* get u32 at +0x20 */
/* Returns the word at +0x20, directly evidenced by the load at 0x02115650. */
u32 Unk113294_GetUnkField20(const Unk113294Work *work)
{
    return work->unk_0020;
}

int Unk113294_Unk_1150e8(u32 a, u32 b);
/* decompiler-derived */
/* Tail-calls the halfword lookup with fixed arguments (1, 53). */
int Unk113294_Unk_115110(void)
{
    return Unk113294_Unk_1150e8(1, 53);
}

void func_020655b4(int value);
void func_02065604(int value);
void func_02065bc0(void);
/* decompiler-derived */
/* Runs the three observed subsystem calls, passing 1 to the final two. */
void Unk113294_Unk_1156ec(void)
{
    func_02065bc0();
    func_02065604(1);
    func_020655b4(1);
}

void *func_020445f4(int group, u32 index);
u16 *func_0204fed8(void *resource, u32 index);
/* decompiler-derived */
/* Resolves resource group 42 at the first index, then its second index. */
u16 *Unk113294_Unk_1150c8(u32 index, u32 entry)
{
    return func_0204fed8(func_020445f4(42, index), entry);
}


/* decompiler-derived */
/* Looks up byte +8 plus one and the low halfword of word +0x10. */
int Unk113294_Unk_115124(const Unk113294Work *work)
{
    return Unk113294_Unk_1150e8(work->unk_0008 + 1, (u16)work->unk_0010);
}


int func_021144e4();
int func_02114588();
int func_02114604();
int func_021146a4();
int func_021148ec();
int func_02114a1c();
/* decompiler-derived */
void Unk113294_Unk_114488(char *arg0)
{
  if (*arg0 == '\0') {
    return;
  }
  if (*(int *)(arg0 + -4) != 6) {
    Unk_LoadPalette_020de678(((Unk113294Work *)arg0)->unk_0028);
  }
  func_021144e4(arg0);
  func_02114588(arg0);
  func_02114604(arg0);
  func_021146a4(arg0);
  func_021148ec(arg0);
  func_02114a1c(arg0);
  return;
}


int func_02061e98();
int func_02061f10();
int func_02063920();
int func_02063a30();
void Unk113294_Unk_11508c(u32 a, u32 b)
{
    func_02061f10(a, -1, 0, 0, func_0204fed8(func_020445f4(42, 0), b));
}

u16 *Unk113294_Unk_1150c8(u32 arg0, u32 arg1);
int Unk113294_Unk_115124(const Unk113294Work *work);
int Unk113294_Unk_115110(void);
typedef struct Unk113294Pair {
    u16 a;
    u16 b;
} Unk113294Pair;
int Unk113294_Unk_1150e8(u32 a, u32 b)
{
    u16 *q = Unk113294_Unk_1150c8(a, b);
    u32 v = q[0];
    if (v == 0xffff) {
        v = q[1] & 0xff;
    }
    return v;
}

void Unk113294_Unk_115144(u8 *p)
{
    Unk113294Pair t = {0, 0};
    t.a = Unk113294_Unk_115124((const Unk113294Work *)p);
    func_02061f10(FIELD(u32, p, 196), -1, 0, 0, &t);
}

/* decompiler-derived */
void Unk113294_Unk_11518c(u32 arg0)
{
  u32 tmp1;
  int tmp2;
  func_02061e98(arg0,0x10,1);
  func_02063920();
  tmp2 = 0;
  do {
    Unk113294_Unk_1150c8(0,tmp2 + 0x66U & 0xffff);
    tmp1 = func_02063a30();
    func_02061f10(arg0,0xffffffff,0,0,tmp1);
    tmp2 = tmp2 + 1;
  } while (tmp2 < 2);
  return;
}

extern u8 data_0215159c[];
/* IsOtherId is supported by the comparison at 0x021155d0: a nonzero id
 * qualifies only when it differs from the fixed (1,53) lookup result. */
int Unk113294_IsOtherId(u32 id)
{
    if (id == 0) {
        return 0;
    }
    return id != Unk113294_Unk_115110();
}

int Unk113294_AnyLo(Unk113294Ids *p)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (Unk113294_IsOtherId(p->ids[i]) != 0) {
            return 1;
        }
    }
    return 0;
}

int Unk113294_AnyHi(Unk113294Ids *p)
{
    int i;
    for (i = 8; i < 16; i++) {
        if (Unk113294_IsOtherId(p->ids[i]) != 0) {
            return 1;
        }
    }
    return 0;
}

void Unk113294_CopyIds(u8 *p)
{
    func_02008904(p + 232, (u8 *)Unk02e000_Thunk_0202e788() + 72, 16);
    func_02008904(p + 216, (u8 *)Unk02e000_Thunk_0202e788() + 90, 16);
    Unk02ee5c_Unk_02efa4();
}

int Unk113294_FindEmpty(Unk113294Ids *p)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (p->ids[i] == 0) {
            return i;
        }
    }
    return 7;
}

/* Returns zero for byte +8 values 0 and 1, and one for every other value. */
int Unk113294_Unk_115734(const Unk113294Work *work)
{
    switch (work->unk_0008) {
    case 0:
    case 1:
        return 0;
    }
    return 1;
}

/* decompiler-derived */
u32 Unk113294_Unk_115754(int arg0,int arg1,int arg2)
{
  return *(u32 *)(arg0 * 0xdc + data_0215159c + (arg1 * 0xb + arg2) * 4);
}

int Unk113294_Unk_11558c(Unk113294Ids *p)
{
    if (Unk113294_AnyHi(p) == 0) {
        return 1;
    }
    if (Unk113294_AnyLo(p) == 0) {
        return 2;
    }
    return 0;
}

int Unk113294_Unk_115778(int a, int b, int c)
{
    return ((float *)(data_0215159c + a * 220))[b * 11 + c] != 0.0f;
}
