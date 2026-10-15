/* src/game/unit_020cce38.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0cce38Work {
    u8 pad_0000[0x7c];
    u32 unk_007c;
    u8 pad_0080[0x38];
    u32 unk_00b8;
} Unk0cce38Work;

void Unk0cce38_Nop_0cce70(void) { }


/* empty callback */
void Unk0cce38_Nop_0cd46c(void) { }

int Unk0cb32c_Unk_0cb754();
/* decompiler-derived */
void Unk0cce38_Unk_0cd45c(int arg0)
{
  Unk0cb32c_Unk_0cb754(arg0 + 0x7c);
  return;
}

int Unk095560_Unk_0956c8();
int Unk0bc1a8_Unk_0bc9b4();
int Unk0de678_Unk_0de870();
/* decompiler-derived */
void Unk0cce38_Unk_0cce74(void)
{
  int tmp1;
  tmp1 = Unk0de678_Get_data_021508d4();
  if (tmp1 == 0) {
    Unk0bc1a8_Unk_0bc9b4(0x11,0);
    Unk0cb32c_Unk_0cb344();
  }
  Unk0de678_Unk_0de870();
  Unk095560_Unk_0956c8();
  return;
}

int Unk122e1c_Unk_122ff0();
/* decompiler-derived */
void Unk0cce38_Unk_0cd430(u8 *arg0,u32 arg1)
{
  Unk122e1c_Unk_122ff0(((Unk0cce38Work *)arg0)->unk_007c);
  ((Unk0cce38Work *)arg0)->unk_00b8 = arg1;
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
  func_02122e1c(((Unk0cce38Work *)arg0)->unk_007c);
  ((Unk0cce38Work *)arg0)->unk_007c = 0;
  ImageBg_Unk_0e5530();
  Unk0de678_Unk_0dea60();
  *data_02176bc8 = 0;
  return;
}

