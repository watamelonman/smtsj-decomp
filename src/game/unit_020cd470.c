/* src/game/unit_020cd470.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void func_020cd508(void) { }

int func_020572d8();
int func_02057524();
/* decompiler-derived */
void func_020cd470(int arg0)
{
  if (*(int *)(arg0 + 0xc0) == 0) {
    return;
  }
  func_02057524(4);
  func_020572d8();
  return;
}

int func_020956c8();
int func_020bc9b4();
int func_020de870();
/* decompiler-derived */
void func_020cd50c(void)
{
  int tmp1;
  tmp1 = Unk0de678_Get_data_021508d4();
  if (tmp1 == 0) {
    func_020bc9b4(0x12,0);
    Unk0cb32c_Unk_0cb344();
  }
  func_020de870();
  func_020956c8();
  return;
}
