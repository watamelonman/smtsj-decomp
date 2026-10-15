/* src/game/unit_020e78b8.c: matched functions. */
#include "types.h"

extern u32 data_02176cdc[];
extern u8 data_02150bf4[];
int func_020086a0();
int func_0205dcd4();
/* decompiler-derived; refs "Camp/Button/buttonhelp" */
void Unk0e78b8_Unk_0e7a30(u8 *arg0)
{
  u32 tmp1;
  *data_02176cdc = (u32)(arg0);
  *arg0 = 0;
  *(u32 *)(arg0 + 0x34) = 0x1a;
  *(u32 *)(arg0 + 0x38) = 0;
  *(u32 *)(arg0 + 0x3c) = 0;
  *(u32 *)(arg0 + 0x58) = 0;
  *(u32 *)(arg0 + 0x50) = 1;
  func_020086a0(0,arg0 + 4,0x10);
  func_020086a0(0,arg0 + 0x14,0x10);
  func_020086a0(0,arg0 + 0x24,0x10);

  func_020086a0(0,arg0 + 0x40,0x10);
  Unk05b82c_Unk_05b82c(0x41);
  tmp1 = func_0205dcd4(data_02150bf4,1);
  *(u32 *)(arg0 + 0x54) = tmp1;
}
