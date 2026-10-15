/* src/game/unit_020ee6dc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0ee6dcWork {
    u8 pad_0000[0x8];
    s32 unk_0008;
    u8 pad_000c[0x38];
    u32 unk_0044;
} Unk0ee6dcWork;

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
  if (((Unk0ee6dcWork *)arg0)->unk_0008 != 10) {
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
  value = func_020e8374(((Unk0ee6dcWork *)arg0)->unk_0044);
  func_020f8478(arg0 + 0x50,value);
  func_020f8264(arg0 + 0x50);
}
