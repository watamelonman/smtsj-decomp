/* src/game/unit_020cce38.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0cce38Work {
    u8 pad_0000[0x4];
    u32 unk_0004;
    u8 pad_0008[0x74];
    u32 unk_007c;
    u8 pad_0080[0x38];
    u32 unk_00b8;
    u32 unk_00bc;
    u32 unk_00c0;
} Unk0cce38Work;

void func_020cb3dc();
void Unk095560_Unk_095a2c();
int func_020de8b0();
void Unk0cb32c_Unk_0cb32c();
void Unk0bc1a8_Unk_0bc928();
void Unk0cce38_Enter(void)
{
    func_020cb3dc();
    Unk095560_Unk_095a2c();
    if (func_020de8b0(0) != 0) {
        return;
    }
    Unk0cb32c_Unk_0cb32c();
    Unk0bc1a8_Unk_0bc928(17, 0xffff, 0);
}

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

int func_020525cc();
int func_02052634();
int func_020de960();
int func_020dea70();
int func_02122abc();
/* decompiler-derived */
void Unk0cce38_Unk_0ccefc(u8 *arg0)
{
  u32 tmp1;
  func_020de960(arg0 + 8,0);
  ImageBg_Unk_0e54d4(arg0[0x10]);
  func_02122abc(((Unk0cce38Work *)arg0)->unk_007c);
  Unk0bcef4_Unk_0bcef4(arg0 + 0x80,5,5,1);
  tmp1 = func_020dea70(arg0 + 8);
  Unk0bcef4_Unk_0bcef4(arg0 + 0x9c,tmp1,tmp1,1);
  *data_02176bc8 = (u32)(arg0);
  func_02052634(1,0,0x1f);
  func_020525cc(0);
  ((Unk0cce38Work *)arg0)->unk_00b8 = 8;
  *arg0 = 0;
  arg0[2] = 2;
  arg0[1] = 0;
  ((Unk0cce38Work *)arg0)->unk_00bc = 0;
  ((Unk0cce38Work *)arg0)->unk_00c0 = 1;
  ((Unk0cce38Work *)arg0)->unk_0004 = 1;
  Unk0cb32c_Unk_0cb35c(arg0[0x11]);
}
