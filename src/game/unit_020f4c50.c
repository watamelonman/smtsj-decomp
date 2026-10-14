/* src/game/unit_020f4c50.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void func_020f4cf8(void) { }


/* empty callback */
void func_020f4d5c(void) { }


/* empty callback */
void func_020f4d60(void) { }


/* decompiler-derived */
void func_020f4cd4(u32 *arg0)
{
  *arg0 = 0x23;
  arg0[1] = 0;
  arg0[2] = 9;
  arg0[3] = 1;
  return;
}

int func_020d1d94();
int func_020d1e94();
int func_020ea630();
/* decompiler-derived */
void func_020f51b0(int arg0,int arg1)
{
  u32 tmp1;
  if (arg1 != 0) {
    tmp1 = func_020ea630(*(u32 *)(arg0 + 0x10));
    func_020d1d94(tmp1,0xffffffff);
    return;
  }
  func_020d1e94(1);
  return;
}
