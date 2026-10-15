/* src/game/unit_020fd268.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0fd268Work {
    u8 pad_0000[0x8];
    u32 unk_0008;
    u32 unk_000c;
    u32 unk_0010;
    u8 pad_0014[0x8];
    u32 unk_001c;
    u8 pad_0020[0x4];
    u32 unk_0024;
    u32 unk_0028;
    u32 unk_002c;
    u32 unk_0030;
    u32 unk_0034;
} Unk0fd268Work;



extern u32 data_02176e1c[];
/* decompiler-derived */
u32 Unk0fd268_Get_data_02176e1c(void)
{
  return *data_02176e1c;
}

int func_02061424();
/* decompiler-derived */
void Unk0fd268_Unk_0fd3ac(void)
{
  int value;
  value = Unk0fd268_Get_data_02176e1c();
  if (value == 0) {
    return;
  }
  func_02061424();
}


/* decompiler-derived */
void Unk0fd268_Unk_0fd47c(void)
{
  int value;
  value = Unk0fd268_Get_data_02176e1c();
  if (value != 0) {
    *(u32 *)(value + 0x2c) = 0;
  }
}


/* decompiler-derived */
void Unk0fd268_Unk_0fd494(u32 arg0,u32 arg1)
{
  int value;
  value = Unk0fd268_Get_data_02176e1c();
  if (value != 0) {
    *(u32 *)(value + 0x30) = arg0;
    *(u32 *)(value + 0x34) = arg1;
  }
}

int func_020fd4c4();
/* decompiler-derived */
void Unk0fd268_Unk_0fd380(u32 arg0)
{
  int value1;
  u32 value2;
  value1 = Unk0fd268_Get_data_02176e1c();
  if (value1 != 0) {
    return;
  }
  value2 = func_020fd4c4(arg0);
  *data_02176e1c = value2;
}


extern u8 data_021510a4[];
int Unk05b82c_Unk_05b82c();
int func_0205dcd4();
/* decompiler-derived */
void Unk0fd268_Unk_0fd574(u32 *arg0)
{
  u32 tmp1;
  Unk05b82c_Unk_05b82c(0xd);
  Unk05b82c_Unk_05b82c(0xe);
  tmp1 = func_0205dcd4(((int)data_021510a4),1);
  *arg0 = tmp1;
  return;
}


/* decompiler-derived */
void Unk0fd268_Unk_0fd540(Unk0fd268Work *arg0, u32 arg1){
  arg0->unk_0008 = 0xffffffaf;
  arg0->unk_000c = 0;
  arg0->unk_0010 = 0;
  arg0->unk_001c = arg1;
  arg0->unk_0024 = 0;
  arg0->unk_0028 = 0;
  arg0->unk_002c = 1;
  arg0->unk_0030 = 0;
  arg0->unk_0034 = 0;
  return;
}


/* decompiler-derived */
void Unk0fd268_Unk_0fd3f0(int arg0)
{
  int tmp1;
  tmp1 = Unk0fd268_Get_data_02176e1c();
  if (tmp1 == 0) {
    return;
  }
  if (arg0 == 0) {
    *(u32 *)(tmp1 + 8) = 0xffffffaf;
    *(u32 *)(tmp1 + 0x10) = 0;
    return;
  }
  *(u32 *)(tmp1 + 8) = 0;
  return;
}
