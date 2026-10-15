/* src/game/unit_020979d8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0979d8Work {
    u8 pad_0000[0x34];
    u16 unk_0034;
} Unk0979d8Work;



int func_02096754();
/* decompiler-derived */
u8 Unk0979d8_Unk_098124(void)
{
  u8 value1;
  int value2;
  value2 = func_02096754();
  if (value2 == 0) {
    value1 = 0;
  }
  else {
    value1 = *(u8 *)(value2 + 0x38);
  }
  return value1;
}


/* decompiler-derived */
int Unk0979d8_Unk_09813c(void)
{
  int value;
  value = func_02096754();
  if (value == 0) {
    value = 0;
  }
  else {
    value = (int)*(short *)(value + 0x1e);
  }
  return value;
}


/* decompiler-derived */
int Unk0979d8_Unk_098154(void)
{
  int value;
  value = func_02096754();
  if (value == 0) {
    value = 0;
  }
  else {
    value = (int)*(short *)(value + 10);
  }
  return value;
}


/* decompiler-derived */
int Unk0979d8_Unk_09818c(void)
{
  int value;
  value = func_02096754();
  if (value == 0) {
    value = 0;
  }
  else {
    value = (int)*(short *)(value + 0x20);
  }
  return value;
}


/* decompiler-derived */
int Unk0979d8_Unk_0981a4(void)
{
  int value;
  value = func_02096754();
  if (value == 0) {
    value = 0;
  }
  else {
    value = (int)*(short *)(value + 0xc);
  }
  return value;
}

int func_02097b54();
/* decompiler-derived */
void Unk0979d8_Unk_09816c(u32 arg0,u32 arg1)
{
  int value;
  value = func_02096754();
  if (value == 0) {
    return;
  }
  func_02097b54(value,arg1);
}

int func_02097b84();
/* decompiler-derived */
void Unk0979d8_Unk_0981bc(u32 arg0,u32 arg1)
{
  int value;
  value = func_02096754();
  if (value == 0) {
    return;
  }
  func_02097b84(value,arg1);
}


int func_020979d8();
/* decompiler-derived */
u32 Unk0979d8_Unk_0979fc(Unk0979d8Work *arg0){
  if (arg0 != 0) {
    arg0->unk_0034 = 0;
    func_020979d8();
    return 1;
  }
  return 0;
}

int func_020970d4();
/* decompiler-derived */
void Unk0979d8_Unk_097f00(u32 arg0)
{
  func_020970d4();
  Unk0979d8_Unk_09816c(0,arg0);
  Unk0979d8_Unk_09816c(1,arg0);
  Unk0979d8_Unk_09816c(2,arg0);
}

int func_02097120();
/* decompiler-derived */
void Unk0979d8_Unk_097f34(u32 arg0)
{
  func_02097120();
  Unk0979d8_Unk_0981bc(0,arg0);
  Unk0979d8_Unk_0981bc(1,arg0);
  Unk0979d8_Unk_0981bc(2,arg0);
}


