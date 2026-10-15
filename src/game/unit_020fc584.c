/* src/game/unit_020fc584.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0fc584Work {
    u8 pad_0000[0x8];
    u32 unk_0008;
} Unk0fc584Work;

extern u32 data_02176e14[];
/* decompiler-derived */
u32 Unk0fc584_Get_data_02176e14(void)
{
  return *data_02176e14;
}

int func_020572d8();
int func_02057eb8();
/* decompiler-derived */
void Unk0fc584_Unk_0fcfd0(void)
{
  func_02057eb8(0xffffffff);
  func_020572d8();
}

int func_02061424();
/* decompiler-derived */
void Unk0fc584_Unk_0fc6a0(void)
{
  int value;
  value = Unk0fc584_Get_data_02176e14();
  if (value == 0) {
    return;
  }
  func_02061424();
}


/* decompiler-derived */
u32 Unk0fc584_Unk_0fc894(void)
{
  u32 *v1;
  u32 value;
  v1 = (u32 *)Unk0fc584_Get_data_02176e14();
  if (v1 == (u32 *)0x0) {
    value = 0;
  }
  else {
    value = *v1;
  }
  return value;
}


/* decompiler-derived */
void Unk0fc584_Unk_0fc84c(u32 arg0)
{
  int value;
  value = Unk0fc584_Get_data_02176e14();
  if (value != 0) {
    *(u32 *)(value + 0x2c) = arg0;
    *(u32 *)(value + 0x30) = 1;
  }
}

int func_02057524();
int func_02057ddc();
int func_02057e18();
/* decompiler-derived */
void Unk0fc584_Unk_0fcfb0(void)
{
  func_02057e18(0x1f);
  func_02057ddc(0xffffffff);
  func_02057524(4);
}


int func_020fc6e4();
/* decompiler-derived */
void Unk0fc584_Unk_0fc824(void)
{
  int value;
  value = func_020fc6e4();
  if (value == 0) {
    return;
  }
  value = Unk0fc584_Get_data_02176e14();
  *(u32 *)(value + 0x28) = 0;
  *(u32 *)(value + 0x20) = *(u32 *)(value + 0x24);
}

int func_020fc8bc();
/* decompiler-derived */
void Unk0fc584_Unk_0fc674(u32 arg0)
{
  int value1;
  u32 value2;
  value1 = Unk0fc584_Get_data_02176e14();
  if (value1 != 0) {
    return;
  }
  value2 = func_020fc8bc(arg0);
  *data_02176e14 = value2;
}


int func_0205bb68();
int func_0205ddb4();
/* decompiler-derived */
void Unk0fc584_Unk_0fc9fc(int *arg0)
{
  if (*arg0 == 0) {
    if (arg0[2] != 0) {
      func_0205ddb4();
      arg0[2] = 0;
    }
    func_0205bb68();
  }
  else {
    if (arg0[2] != 0) {
      func_0205ddb4();
      arg0[2] = 0;
    }
    func_0205bb68();
  }
  *data_02176e14 = 0;
}

extern u8 data_02151058[];
extern u8 data_0215106c[];
int func_0205dcd4();
/* Loads battle_money (arg1 != 0) or cave_moneywindow layout (medium). */
void Unk0fc584_LoadMoneyWindow(int arg0,int arg1)
{
  u32 tmp1;
  if (arg1 == 0) {
    Unk05b82c_Unk_05b82c(0xda);
    tmp1 = func_0205dcd4(data_02151058,1);
    ((Unk0fc584Work *)arg0)->unk_0008 = tmp1;
    return;
  }
  Unk05b82c_Unk_05b82c(0x59);
  tmp1 = func_0205dcd4(data_0215106c,1);
  ((Unk0fc584Work *)arg0)->unk_0008 = tmp1;
}

int func_020fc734();
int func_020fc86c();
/* decompiler-derived */
void Unk0fc584_Unk_0fc7b8(u32 arg0)
{
  int tmp1;
  int *v2;
  tmp1 = func_020fc6e4();
  if (tmp1 == 0) {
    return;
  }
  v2 = (int *)Unk0fc584_Get_data_02176e14();
  if (*v2 == 1) {
    Unk0fc584_Unk_0fc84c((u32)arg0);
    func_020fc86c();
    return;
  }
  func_020fc734(arg0);
}
