/* src/game/unit_020f470c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void Unk0f470c_Nop_0f4874(void) { }

void func_020f7248(void);
/* forwards to `func_020f7248` */
void Unk0f470c_Thunk_020f7248(void) { func_020f7248(); }

int func_020f7210();
int func_020f82e0();
/* decompiler-derived */
void Unk0f470c_Unk_0f4908(int arg0)
{
  int value;
  value = func_020f7210();
  if (value == 0) {
    return;
  }
  func_020f82e0(arg0 + 0x54);
}

extern u32 data_02176e00[];
int func_02008848();
int func_020f4790();
/* decompiler-derived */
void Unk0f470c_Unk_0f4764(u32 arg0)
{
  func_02008848(arg0,0,0xf8);
  *data_02176e00 = arg0;
  func_020f4790(arg0);
}

int Unk0d1c98_Unk_0d1d94();
int func_020ea630();
int func_020f4b80();
/* decompiler-derived */
void Unk0f470c_Unk_0f4c20(u32 arg0)
{
  int value1;
  u32 value2;
  value1 = Unk0e8228_Unk_0e8bac();
  if (value1 == 0) {
    return;
  }
  func_020f4b80(arg0);
  value2 = func_020ea630(8);
  Unk0d1c98_Unk_0d1d94(value2,0xffffffff);
}



int func_020e8424();
int func_020ea70c();
int func_020ea744();
int func_020ea828();
/* decompiler-derived */
void Unk0f470c_Unk_0f4958(int arg0)
{
  u32 value;
  value = Unk0f8448_GetUnkField10(arg0 + 0x54);
  func_020ea70c();
  if (*(int *)(arg0 + 0x50) != 0) {
    func_020ea828();
    return;
  }
  func_020e8424(value);
  func_020ea744();
}

int func_020f7d14();
int func_020f7de4();
int func_020f7e48();
/* decompiler-derived */
void Unk0f470c_Unk_0f4b44(void)
{
  int value;
  value = *data_02176e00;
  Unk0e8228_Unk_0e8b94();
  func_020f7e48(*(u32 *)(value + 4),0,5);
  func_020f7d14(*(u32 *)(value + 4));
  func_020f7de4(*(u32 *)(value + 0x40),0);
}

int func_02044ec4();
int func_020e82c8();
int func_020e8c80();
int func_020e8d38();
/* decompiler-derived */
void Unk0f470c_Unk_0f4ac0(void)
{
  u32 value1;
  int value2;
  int value3;
  int value4;
  value1 = Unk0f8448_GetUnkField10();
  value4 = *data_02176e00;
  func_020e8c80();
  value2 = func_02044ec4();
  value1 = func_020e8424(value1);
  value3 = Unk0e8228_Unk_0e8bac();
  if (value3 != 0) {
    value2 = Unk044904_Unk_045048();
    *(u32 *)(value2 + 0x40) = value1;
    func_020e82c8();
    return;
  }
  value2 = func_020e8d38(value2,value2 + 0x1e8,value1,*(u32 *)(value4 + 0x28));
  if (value2 != 0) {
    Unk0e8228_Unk_0e8d18(0);
  }
  func_020f7e48(*(u32 *)(value4 + 0x40),0,8);
}
