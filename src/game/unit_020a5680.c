/* src/game/unit_020a5680.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176b14[];
/* decompiler-derived */
void Unk0a5680_Clear_data_02176b14(void)
{
  *data_02176b14 = 0;
}

extern u8 data_0213c3e0[];
/* Entry returned by func_020a5680. */
typedef struct Unk0a5680Entry {
    u8 pad_0000[0x14];
    s32 unk_0014;
    u8 pad_0018[0x8];
    u8 unk_0020[4];             /* +0x20 sub-block */
} Unk0a5680Entry;

Unk0a5680Entry *func_020a5680();
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int func_02008904();
int func_0206f24c();
int func_02044ec4();
int func_0204a244();
extern s8 data_0213c3d4[];
int func_020616c0();
int Unk0a5680_Unk_0a572c(u8 *p, u32 c);

int Unk0a5680_Unk_0a572c(u8 *p, u32 c)
{
    s32 k = FIELD(s8, p, 18);
    if (k == -1) {
        return func_02008904(FIELD(u32, p, 28), p + 32, 512, c);
    }
    return func_0206f24c(p + 32, FIELD(u32, p, 28), 1 << (k + 13), c);
}

int Unk0a5680_Unk_0a5778(u8 *p, int force)
{
    s8 k = data_0213c3d4[func_0204a244(func_02044ec4(FIELD(u32, p, 12)))];
    if (FIELD(s8, p, 18) == k && force == 0) {
        return 0;
    }
    FIELD(s8, p, 18) = k;
    Unk0a5680_Unk_0a572c(p, 4096);
    return 1;
}

s32 Unk0a5680_GetEntryUnk14(u32 a, u32 b)
{
    Unk0a5680Entry *e = func_020a5680(a, b);
    if (e != 0) {
        return e->unk_0014;
    }
    return -1;
}

u8 *Unk0a5680_GetEntrySub20(u32 a, u32 b)
{
    Unk0a5680Entry *e = func_020a5680(a, b);
    if (e != 0) {
        return e->unk_0020;
    }
    return 0;
}

/* decompiler-derived */
int Unk0a5680_Unk_0a5e78(int arg0)
{
  return (int)*(short *)(((int)data_0213c3e0) + arg0 * 2);
}

int Unk0a5680_Unk_0a5e28();
/* decompiler-derived */
void Unk0a5680_Unk_0a6150(void)
{
  int value;
  value = Unk0a5680_Unk_0a5e28();
  if (value == 0) {
    return;
  }
  *(u8 *)(value + 0x38) = 1;
  *(u8 *)(value + 0x39) = 0;
}


int func_020a1854();
int func_020a59f4();
/* decompiler-derived */
int Unk0a5680_Unk_0a5c14(u32 arg0,u32 arg1,u32 arg2)
{
  u32 value1;
  int value2;
  value1 = func_020a1854();
  value2 = func_020a59f4(value1,arg1,arg2);
  return value2 != 0;
}

int func_0205c41c();
int func_0205ca88();
int Unk0a5680_Unk_0a5e28(id)
    u32 id;
{
    u8 *e = (u8 *)func_020a5680(id);
    if (e == 0) {
        return 0;
    }
    return func_020616c0(e + 8);
}

/* decompiler-derived */
void Unk0a5680_Unk_0a611c(void)
{
  u32 *v1;
  int value;
  v1 = (u32 *)Unk0a5680_Unk_0a5e28();
  if (v1 == (u32 *)0x0) {
    return;
  }
  value = func_0205ca88(*v1);
  func_0205c41c(*v1,value + -1);
  *(u8 *)(v1 + 0xe) = 0;
}

int func_020a5e8c();
/* decompiler-derived */
void Unk0a5680_Unk_0a5fb0(void)
{
  func_020a5e8c(*data_02176b14);
}

int Unk0a5680_Unk_0a60fc(u32 id)
{
    u8 *e = (u8 *)Unk0a5680_Unk_0a5e28(id);
    if (e != 0 && e[56] != 0) {
        return 1;
    }
    return 0;
}
