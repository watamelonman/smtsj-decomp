/* src/game/unit_0211ec7c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void Unk11ec7c_Nop_11ef08(void) { }

int func_0202e0cc();
int func_0205b82c();
/* decompiler-derived */
u32 Unk11ec7c_Unk_11efec(void)
{
  func_0202e0cc();
  func_0205b82c(0xd2);
  return 1;
}

int func_0205dde4();
int func_0211eda0();
/* decompiler-derived */
void Unk11ec7c_Unk_11ee8c(int arg0)
{
  func_0205dde4(*(u32 *)(arg0 + 4));
  func_0211eda0(*(u32 *)(arg0 + 8));
  return;
}


/* decompiler-derived */
void Unk11ec7c_Unk_11ef0c(int arg0)
{
  u32 tmp1;
  tmp1 = *(int *)(arg0 + 0x18) + 1;
  *(u32 *)(arg0 + 0x18) = tmp1;
  if (*(u32 *)(arg0 + 0x14) < tmp1) {
    *(u32 *)(arg0 + 0x10) = 3;
  }
  return;
}

int func_0211ee10();
/* decompiler-derived */
void Unk11ec7c_Unk_11ef2c(int arg0)
{
  *(int *)(arg0 + 0x1c) = *(int *)(arg0 + 0x1c) + -1;
  func_0211ee10(arg0,0);
  if (0 < *(int *)(arg0 + 0x1c)) {
    return;
  }
  *(u32 *)(arg0 + 0x10) = 0;
  *(u32 *)(arg0 + 0x14) = 0;
  *(u32 *)(arg0 + 0x18) = 0;
  *(u32 *)(arg0 + 0x1c) = 0;
  *(u16 *)(arg0 + 0x24) = 0;
  *(u32 *)(arg0 + 0x20) = 0;
  return;
}


int func_02044534();
int func_02053000();
/* decompiler-derived */
void func_0211ec7c(int arg0)
{
  func_02053000(*(u32 *)(arg0 + 0x26c));
  *(u32 *)(arg0 + 0x26c) = 0;
  func_02053000(*(u32 *)(arg0 + 0xa8));
  *(u32 *)(arg0 + 0xa8) = 0;
  func_02053000(*(u32 *)(arg0 + 0xb0));
  *(u32 *)(arg0 + 0xb0) = 0;
  if (*(int *)(arg0 + 0x274) == 0) {
    return;
  }
  func_02044534(0x24);
  return;
}

extern u8 data_02151fb4[];
int func_02008848();
int func_0205dcd4();
int func_020629ac();
/* decompiler-derived */
void func_0211f004(int *arg0)
{
  int tmp1;
  if (*arg0 == 1) {
    return;
  }
  func_02008848(arg0,0,0x28);
  *arg0 = 1;
  arg0[3] = 0;
  arg0[4] = 0;
  func_0202e0cc();
  tmp1 = func_0205dcd4(((int)data_02151fb4),1);
  arg0[1] = tmp1;
  tmp1 = func_020629ac(5,1,1,1);
  arg0[2] = tmp1;
  return;
}
