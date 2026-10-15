/* src/game/unit_020caea8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0202b730();
/* decompiler-derived */
void Unk0caea8_Unk_0caf78(void)
{
  func_0202b730(0x400);
}


/* decompiler-derived */
void Unk0caea8_Unk_0caf88(void)
{
  func_0202b730(0);
}

int func_020445f4();
int func_0204fed8();
/* decompiler-derived */
void Unk0caea8_Unk_0cb044(u32 arg0)
{
  u32 value;
  value = func_020445f4(10,0);
  func_0204fed8(value,arg0);
}


/* decompiler-derived */
void Unk0caea8_Unk_0cb064(u32 arg0)
{
  u32 value;
  value = func_020445f4(10,1);
  func_0204fed8(value,arg0);
}

int Unk0a0ce4_Unk_0a0d30();
/* decompiler-derived */
void Unk0caea8_Unk_0caf98(u32 arg0)
{
  func_0202b730(0x400);
  Unk0a0ce4_Unk_0a0d30(arg0);
  func_0202b730(0);
}

extern u32 data_02176bc0[];
int func_02053000();
/* decompiler-derived */
u32 Unk0caea8_Unk_0caf48(void)
{
  if (*data_02176bc0 != 0) {
    func_02053000();
    *data_02176bc0 = 0;
  }
  return 1;
}
