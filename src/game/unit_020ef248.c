/* src/game/unit_020ef248.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void Unk0ef248_Nop_0ef4b4(void) { }

void func_020f7248(void);
/* forwards to `func_020f7248` */
void Unk0ef248_Thunk_020f7248(void) { func_020f7248(); }

extern u32 data_02176df0[];
int func_02008848();
int func_020ef3f0();
/* decompiler-derived */
void Unk0ef248_Unk_0ef2a0(u32 arg0)
{
  func_02008848(arg0,0,0x10c);
  *data_02176df0 = arg0;
  func_020ef3f0(arg0);
}

int func_020f7210();
int func_020f82e0();
int func_020feed4();
/* decompiler-derived */
void Unk0ef248_Unk_0ef548(int arg0)
{
  int value;
  value = func_020f7210();
  if (value == 0) {
    return;
  }
  func_020f82e0(arg0 + 0x50);
  if (*(int *)(arg0 + 8) != 10) {
    return;
  }
  func_020feed4();
}

int func_02044ec4();
int func_020e8c80();
int func_020f7d14();
int func_020f7e48();
/* decompiler-derived */
void Unk0ef248_Unk_0ef878(void)
{
  int value;
  value = *data_02176df0;
  func_020e8c80();
  func_02044ec4();
  func_020f7d14(*(u32 *)(value + 4));
  func_020f7e48(*(u32 *)(value + 0x40),0,1);
}

