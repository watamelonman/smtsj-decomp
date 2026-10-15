/* src/game/unit_020ef248.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0ef248Work {
    u8 pad_0000[0x8];
    s32 unk_0008;
} Unk0ef248Work;

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
  if (((Unk0ef248Work *)arg0)->unk_0008 != 10) {
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

/* decompiler-derived */
void func_020ef8ac(void)
{
  u32 tmp1;
  tmp1 = Unk0f8448_GetUnkField10();
  Unk0e8228_Unk_0e8d90(*(u32 *)(*data_02176df0 + 0x44),tmp1);
}
