/* src/game/unit_020a23f4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


void func_020fd428(void);
/* forwards to `func_020fd428` */
void func_020a2504(void) { func_020fd428(); }

void func_020fd450(void);
/* forwards to `func_020fd450` */
void func_020a2588(void) { func_020fd450(); }

int func_02061424();
/* decompiler-derived */
void func_020a2414(void)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  func_02061424();
  return;
}

extern u32 data_02176b04[];
/* decompiler-derived */
int func_020a242c(void)
{
  return *data_02176b04 != 0;
}

int func_020a2d0c();
/* decompiler-derived */
void func_020a23f4(u32 arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 != 0) {
    return;
  }
  func_020a2d0c(arg0);
  return;
}

