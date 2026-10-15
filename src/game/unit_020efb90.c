/* src/game/unit_020efb90.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0efb90Work {
    u8 pad_0000[0x8];
    s32 unk_0008;
    u8 pad_000c[0x40];
    u32 unk_004c;
} Unk0efb90Work;

void Unk0efb90_Nop_0efd18(void) { }

void func_020f7248(void);
/* forwards to `func_020f7248` */
void Unk0efb90_Thunk_020f7248(void) { func_020f7248(); }

int func_020f7210();
int func_020f82e0();
int func_020feed4();
/* decompiler-derived */
void Unk0efb90_Unk_0efb90(int arg0)
{
  int value;
  value = func_020f7210();
  if (value == 0) {
    return;
  }
  func_020f82e0(arg0 + 0x50);
  if (((Unk0efb90Work *)arg0)->unk_0008 != 10) {
    return;
  }
  func_020feed4();
}

int func_020e8374();
int func_020f8478();
int func_020fda58();
int func_020febe8();
/* decompiler-derived */
void Unk0efb90_Unk_0efce8(int arg0)
{
  u32 value;
  func_020febe8(1);
  func_020fda58(0);
  value = func_020e8374(((Unk0efb90Work *)arg0)->unk_004c);
  func_020f8478(arg0 + 0x50,value);
}
