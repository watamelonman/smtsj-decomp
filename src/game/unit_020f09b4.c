/* src/game/unit_020f09b4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0f09b4Work {
    u8 pad_0000[0x8];
    s32 unk_0008;
    u8 pad_000c[0x40];
    u32 unk_004c;
} Unk0f09b4Work;

void Unk0f09b4_Nop_0f0b94(void) { }

void func_020f7248(void);
/* forwards to `func_020f7248` */
void Unk0f09b4_Thunk_020f7248(void) { func_020f7248(); }

int func_020f7210();
int func_020f82e0();
int func_020feed4();
/* decompiler-derived */
void Unk0f09b4_Unk_0f09b4(int arg0)
{
  int value;
  value = func_020f7210();
  if (value == 0) {
    return;
  }
  func_020f82e0(arg0 + 0x50);
  if (((Unk0f09b4Work *)arg0)->unk_0008 != 10) {
    return;
  }
  func_020feed4();
}

int func_020e8374();
int func_020f8478();
int func_020fda58();
int Unk0feba0_Unk_0febe8();
/* decompiler-derived */
void Unk0f09b4_Unk_0f0b64(int arg0)
{
  u32 value;
  Unk0feba0_Unk_0febe8(1);
  func_020fda58(0);
  value = func_020e8374(((Unk0f09b4Work *)arg0)->unk_004c);
  func_020f8478(arg0 + 0x50,value);
}
