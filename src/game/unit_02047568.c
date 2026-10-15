/* src/game/unit_02047568.c: matched functions. */
#include "types.h"

extern u8 data_0215ee9c[];
int func_02052728();
int func_020614b0();
int func_02061698();
/* decompiler-derived */
u32 func_02047590(void)
{
  int tmp1;
  tmp1 = func_02052728();
  if (tmp1 != 0) {
    return 0;
  }
  tmp1 = func_02061698(data_0215ee9c);
  if (tmp1 == 0) {
    func_020614b0(data_0215ee9c);
    return 1;
  }
  return 0;
}
