/* src/game/unit_02047568.c: matched functions. */
#include "types.h"

extern u8 data_0215ee9c[];
int func_02052728();
int func_020614b0();
int func_02061698();
/* decompiler-derived */
u32 Unk047568_Unk_047590(void)
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

int func_0205e4f8();
void func_02045480();
void func_02048ed8();
int func_02047718(void)
{
    if (func_02052728() != 0) {
        return 0;
    }
    if (func_0205e4f8(-1) != 0) {
        return 0;
    }
    func_02045480();
    func_02048ed8();
    return 1;
}
