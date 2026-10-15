/* src/game/unit_020efff4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0efff4Work {
    u8 pad_0000[0x8];
    s32 unk_0008;
} Unk0efff4Work;

void Unk0efff4_Nop_0f0260(void) { }

void func_020f7248(void);
/* forwards to `func_020f7248` */
void Unk0efff4_Thunk_020f7248(void) { func_020f7248(); }

extern u32 data_02176df8[];
int func_02008848();
int func_020f019c();
/* decompiler-derived */
void Unk0efff4_Unk_0f004c(u32 arg0)
{
  func_02008848(arg0,0,0x110);
  *data_02176df8 = arg0;
  func_020f019c(arg0);
}

int func_020f7210();
int func_020f82e0();
int func_020feed4();
/* decompiler-derived */
void Unk0efff4_Unk_0f0300(int arg0)
{
  int value;
  value = func_020f7210();
  if (value == 0) {
    return;
  }
  func_020f82e0(arg0 + 0x50);
  if (((Unk0efff4Work *)arg0)->unk_0008 != 10) {
    return;
  }
  func_020feed4();
}

