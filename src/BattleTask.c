/* src/BattleTask.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0206e538();
int func_0206eab4();
int Unk071dc0_Unk_071de4();
int func_02093a1c();
/* decompiler-derived */
void BattleTask_Unk_04822c(void)
{
  func_0206e538();
  Unk071dc0_Unk_071de4();
  func_0206eab4();
  func_02093a1c();
}

int func_0206df10();
int Unk06e4d8_Unk_06e680();
int func_0206eb54();
int Unk071dc0_Unk_071e08();
int Unk071dc0_Unk_072200();
int Unk0939f0_Unk_093da4();
/* decompiler-derived */
void BattleTask_Unk_048244(void)
{
  func_0206df10();
  Unk071dc0_Unk_072200();
  func_0206eb54();
  Unk071dc0_Unk_071e08();
  Unk06e4d8_Unk_06e680();
  Unk0939f0_Unk_093da4();
}

extern u32 data_02143334[];
int func_02053048();
/* decompiler-derived */
int BattleTask_Unk_0481d4(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  if (value == 0) {
    if (*data_02143334 == 1) {
      func_02053048();
      *data_02143334 = 0;
    }
  }
  else {
    *data_02143334 = 1;
  }
  value = Unk044904_Get_data_0215ee98();
  return value != 0;
}

void func_02049c28();
int func_020484d0(u32 *a, u32 *b)
{
    s16 x = 256;
    s16 y = 256;
    struct { s16 v; s16 pad; } tx, ty;
    if (*a != 0) {
        func_02049c28(*a, &tx);
        x = tx.v;
    }
    if (*b != 0) {
        func_02049c28(*b, &ty);
        y = ty.v;
    }
    return x - y;
}
