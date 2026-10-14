/* src/game/unit_021124f0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* returns 1 */
int func_0211255c(void) { return 1; }

extern u8 data_0213cb24[];
/* decompiler-derived */
int func_0211259c(int arg0)
{
  return ((int)data_0213cb24) + arg0 * 8;
}

int func_0209a884();
/* decompiler-derived */
void func_02112538(void)
{
  int tmp1;
  tmp1 = GetGameState();
  if (tmp1 == 0) {
    return;
  }
  func_0209a884(tmp1 + 0x38e8,tmp1 + 4);
  return;
}

int func_0202e788();
int func_021124f0();
/* decompiler-derived */
u32 func_02112564(u32 arg0,u32 arg1)
{
  int tmp1;
  u32 tmp2;
  tmp2 = 0;
  tmp1 = func_0202e788();
  tmp1 = func_021124f0(*(u16 *)(tmp1 + 0x35c),arg0,arg1);
  if (tmp1 == 1) {
    tmp2 = 2;
  }
  return tmp2;
}

int func_02115bf4();
int func_02116f84();
/* decompiler-derived */
int func_021125ac(u32 arg0,u32 arg1,u32 arg2)
{
  int tmp1;
  int tmp2;
  tmp1 = func_02115bf4();
  tmp2 = func_02116f84(arg0,arg1,arg2);
  return tmp1 != 0 && tmp2 != 0;
}
