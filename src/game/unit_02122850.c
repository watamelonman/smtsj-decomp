/* src/game/unit_02122850.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void func_02122960(void) { }


/* empty callback */
void func_02122964(void) { }

int Unk_LoadPalette_020de678();
/* decompiler-derived */
void func_02122968(u32 *arg0)
{
  Unk_LoadPalette_020de678(*arg0);
  return;
}

int func_020bc650();
/* decompiler-derived */
void func_0212292c(int arg0)
{
  int tmp1;
  if (*(int *)(arg0 + 4) == 0) {
    return;
  }
  tmp1 = func_020bc650(0xc);
  if (tmp1 == 0) {
    return;
  }
  Unk0bc1a8_Unk_0bc504(arg0,0);
  return;
}

extern u32 data_02176e80[];
int func_0205bb68();
int func_0205ddb4();
/* decompiler-derived */
void func_02122978(int *arg0)
{
  if (*arg0 != 0) {
    func_0205ddb4();
    *arg0 = 0;
  }
  func_0205bb68();
  *data_02176e80 = 0;
  return;
}
