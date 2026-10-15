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

Unk0a5680Entry *func_020a5680(u32 a, u32 b);
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

int func_020a5e28();
/* decompiler-derived */
void Unk0a5680_Unk_0a6150(void)
{
  int value;
  value = func_020a5e28();
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
/* decompiler-derived */
void Unk0a5680_Unk_0a611c(void)
{
  u32 *v1;
  int value;
  v1 = (u32 *)func_020a5e28();
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
