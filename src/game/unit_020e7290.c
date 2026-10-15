/* src/game/unit_020e7290.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176cd8[];
/* decompiler-derived */
void func_020e7644(void)
{
  *data_02176cd8 = 0;
  return;
}

int func_02061424();
/* decompiler-derived */
u32 func_020e7734(void)
{
  int tmp1;
  tmp1 = *data_02176cd8;
  if (tmp1 == 0) {
    return 0;
  }
  if (*(int *)(tmp1 + 0x10) == 5 || *(int *)(tmp1 + 0x10) == 0) {
    func_02061424(tmp1);
    return 1;
  }
  return 0;
}

extern u8 data_02150bf0[];
int func_02013c3c();
int func_020445d0();
int func_0204fde0();
/* decompiler-derived */
void func_020e77a8(u32 arg0,int arg1)
{
  int tmp1;
  int tmp2;
  tmp1 = func_020445d0(0x22,0);
  tmp2 = func_0204fde0();
  if (arg1 < 1) {
    arg1 = 1;
  }
  func_02013c3c(arg0,((int)data_02150bf0),*(int *)(tmp1 + 0xc) * (arg1 + -1) + tmp2);
  return;
}

int func_02053000();
/* decompiler-derived */
u32 func_020e747c(int arg0)
{
  char *v1;
  int v2;
  int tmp3;
  int tmp4;
  tmp3 = 0;
  v2 = 1;
  tmp4 = arg0;
  do {
    v1 = (char *)(tmp4 + 0xed);
    tmp3 = tmp3 + 1;
    tmp4 = tmp4 + 0x5c;
    if (*v1 == '\0') {
      v2 = 0;
    }
  } while (tmp3 < 4);
  if (v2) {
    func_02053000(*(u32 *)(arg0 + 0x8c));
    *(u32 *)(arg0 + 0x8c) = 0;
    *(u32 *)(arg0 + 8) = *(u32 *)(arg0 + 0xc);
    *(u32 *)(arg0 + 0xc) = 0;
    return 1;
  }
  return 0;
}

