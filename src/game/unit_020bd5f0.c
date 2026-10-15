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
/* decompiler-derived */
u32 Unk0bd5f0_Unk_0bd614(int arg0)
{
  func_02057ddc(*(u32 *)(((int)data_0213c4d4) + arg0 * 4));
  return 0;
}

int func_020c8008();
/* decompiler-derived */
void Unk0bd5f0_Unk_0c1ad8(void)
{
  func_020c8008(0,0,0,0);
}

extern u32 data_02176bb0[];
int func_020c1b94();
/* decompiler-derived */
void Unk0bd5f0_Unk_0c20f0(void)
{
  if (*data_02176bb0 == 0) {
    return;
  }
  func_020c1b94();
}


/* decompiler-derived */
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

