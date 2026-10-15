/* src/game/unit_020ee6dc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void Unk0ee6dc_Nop_0ee8b8(void) { }

void func_020f7248(void);
/* forwards to `func_020f7248` */
void Unk0ee6dc_Thunk_020f7248(void) { func_020f7248(); }

int func_020f7210();
int func_020f82e0();
int func_020feed4();
/* decompiler-derived */
void Unk0ee6dc_Unk_0ee6dc(int arg0)
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

int func_020e8374();
int func_020f8264();
int func_020f8478();
int func_020fda58();
int func_020febe8();
/* decompiler-derived */
void Unk0ee6dc_Unk_0ee880(int arg0)
{
  u32 value;
  func_020febe8(1);
  func_020fda58(0);
  value = func_020e8374(*(u32 *)(arg0 + 0x44));
  func_020f8478(arg0 + 0x50,value);
  func_020f8264(arg0 + 0x50);
}
