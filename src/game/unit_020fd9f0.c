/* src/game/unit_020fd9f0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0fd9f0Work {
    u8 pad_0000[0xc];
    u32 unk_000c;
    u8 pad_0010[0x4];
    u32 unk_0014;
    u8 pad_0018[0xc];
    s32 unk_0024;
    u32 unk_0028;
    u32 unk_002c;
    u32 unk_0030;
    u32 unk_0034;
    u32 unk_0038;
    u32 unk_003c;
    u32 unk_0040;
} Unk0fd9f0Work;

void Unk0fd9f0_Unk_0fdc0c(int arg0)
{
  ((Unk0fd9f0Work *)arg0)->unk_0014 = 0xffffffff;
  return;
}

extern u32 data_02176e20[];
/* decompiler-derived */
u32 Unk0fd9f0_Get_data_02176e20(void)
{
  return *data_02176e20;
}

int func_020572d8();
int func_02057eb8();
/* decompiler-derived */
void Unk0fd9f0_Unk_0fe2b0(void)
{
  func_02057eb8(0xffffffff);
  func_020572d8();
  return;
}

int func_02061424();
/* decompiler-derived */
void Unk0fd9f0_Unk_0fda14(void)
{
  int tmp1;
  tmp1 = Unk0fd9f0_Get_data_02176e20();
  if (tmp1 == 0) {
    return;
  }
  func_02061424();
  return;
}

int func_020fdb14();
/* decompiler-derived */
void Unk0fd9f0_Unk_0fd9f0(void)
{
  int tmp1;
  u32 tmp2;
  tmp1 = Unk0fd9f0_Get_data_02176e20();
  if (tmp1 != 0) {
    return;
  }
  tmp2 = func_020fdb14();
  *data_02176e20 = tmp2;
  return;
}


/* decompiler-derived */
void Unk0fd9f0_Unk_0fe33c(int arg0)
{
  if (((Unk0fd9f0Work *)arg0)->unk_0024 == 0) {
    return;
  }
  func_02061424();
  ((Unk0fd9f0Work *)arg0)->unk_0024 = 0;
  return;
}



/* decompiler-derived */
void Unk0fd9f0_Unk_0fdb80(int arg0)
{
  ((Unk0fd9f0Work *)arg0)->unk_000c = 0xffffffe5;
  ((Unk0fd9f0Work *)arg0)->unk_0014 = 1;
  ((Unk0fd9f0Work *)arg0)->unk_0028 = 1;
  ((Unk0fd9f0Work *)arg0)->unk_002c = 1;
  ((Unk0fd9f0Work *)arg0)->unk_0030 = 0;
  ((Unk0fd9f0Work *)arg0)->unk_0034 = 0;
  ((Unk0fd9f0Work *)arg0)->unk_0038 = 0;
  ((Unk0fd9f0Work *)arg0)->unk_003c = 0;
  ((Unk0fd9f0Work *)arg0)->unk_0024 = 0;
  ((Unk0fd9f0Work *)arg0)->unk_0040 = 0;
  return;
}

int func_02057524();
int func_02057ddc();
int func_02057e18();
int func_02057e58();
/* decompiler-derived */
void Unk0fd9f0_Unk_0fe278(void)
{
  func_02057e18(0x1f);
  func_02057ddc(0xffffffff);
  func_02057e58(2,0x30,10);
  func_02057eb8(2);
  func_02057524(4);
  return;
}

extern u8 data_021510b8[];
extern u8 data_021510cc[];
extern u8 data_021510e0[];
int func_0205c2c4();
int func_0205dcd4();
/* Loads Battle/battle_help and battle_talk layouts (medium). */
void Unk0fd9f0_LoadBattleHelpTalk(u32 *arg0)
{
  u32 tmp1;
  Unk05b82c_Unk_05b82c(0xd5);
  Unk05b82c_Unk_05b82c(0xd6);
  tmp1 = func_0205dcd4(data_021510b8,1);
  *arg0 = tmp1;
  tmp1 = func_0205dcd4(data_021510cc,1);
  arg0[7] = tmp1;
  tmp1 = func_0205c2c4(data_021510e0);
  arg0[8] = tmp1;
}

int func_0205bb68();
int func_0205c368();
int func_0205ddb4();
/* decompiler-derived */
void func_020fdc18(int *arg0)
{
  Unk0fd9f0_Unk_0fe33c((int)arg0);
  if (arg0[8] != 0) {
    func_0205c368();
    arg0[8] = 0;
  }
  if (*arg0 != 0) {
    func_0205ddb4();
    *arg0 = 0;
  }
  if (arg0[7] != 0) {
    func_0205ddb4();
    arg0[7] = 0;
  }
  func_0205bb68();
  func_0205bb68();
  *data_02176e20 = 0;
}
