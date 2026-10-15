/* src/BattleTask.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0206e538();
int func_0206eab4();
int func_02071de4();
int func_02093a1c();
/* decompiler-derived */
void func_0204822c(void)
{
  func_0206e538();
  func_02071de4();
  func_0206eab4();
  func_02093a1c();
  return;
}

int func_0206df10();
int func_0206e680();
int func_0206eb54();
int func_02071e08();
int func_02072200();
int func_02093da4();
/* decompiler-derived */
void func_02048244(void)
{
  func_0206df10();
  func_02072200();
  func_0206eb54();
  func_02071e08();
  func_0206e680();
  func_02093da4();
  return;
}

extern u32 data_02143334[];
int func_02053048();
/* decompiler-derived */
int func_020481d4(void)
{
  int tmp1;
  tmp1 = Unk044904_Get_data_0215ee98();
  if (tmp1 == 0) {
    if (*data_02143334 == 1) {
      func_02053048();
      *data_02143334 = 0;
    }
  }
  else {
    *data_02143334 = 1;
  }
  tmp1 = Unk044904_Get_data_0215ee98();
  return tmp1 != 0;
}

