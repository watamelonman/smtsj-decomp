/* src/game/unit_020cce38.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void Unk0cce38_Nop_0cce70(void) { }


/* empty callback */
void Unk0cce38_Nop_0cd46c(void) { }

int func_020cb754();
/* decompiler-derived */
void Unk0cce38_Unk_0cd45c(int arg0)
{
  func_020cb754(arg0 + 0x7c);
  return;
}

int func_020956c8();
int func_020bc9b4();
int func_020de870();
/* decompiler-derived */
void Unk0cce38_Unk_0cce74(void)
{
  int tmp1;
  tmp1 = Unk0de678_Get_data_021508d4();
  if (tmp1 == 0) {
    func_020bc9b4(0x11,0);
    Unk0cb32c_Unk_0cb344();
  }
  func_020de870();
  func_020956c8();
  return;
}

int func_02122ff0();
/* decompiler-derived */
void Unk0cce38_Unk_0cd430(u8 *arg0,u32 arg1)
{
  func_02122ff0(*(u32 *)(arg0 + 0x7c));
  *(u32 *)(arg0 + 0xb8) = arg1;
  arg0[2] = 1;
  *arg0 = 3;
  return;
}

extern u32 data_02176bc8[];
int ImageBg_Unk_0e5530();
int func_02122e1c();
/* decompiler-derived */
void Unk0cce38_Unk_0ccfac(int arg0)
{
  func_02122e1c(*(u32 *)(arg0 + 0x7c));
  *(u32 *)(arg0 + 0x7c) = 0;
  ImageBg_Unk_0e5530();
  Unk0de678_Unk_0dea60();
  *data_02176bc8 = 0;
  return;
}
