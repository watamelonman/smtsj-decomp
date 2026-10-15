/* src/game/unit_020cd470.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0cd470Work {
    u8 pad_0000[0xc0];
    s32 unk_00c0;
} Unk0cd470Work;




/* empty callback */
void Unk0cd470_Nop_0cd508(void) { }

int func_020572d8();
int func_02057524();
/* decompiler-derived */
void Unk0cd470_Unk_0cd470(Unk0cd470Work *arg0){
  if (arg0->unk_00c0 == 0) {
    return;
  }
  func_02057524(4);
  func_020572d8();
  return;
}

int Unk095560_Unk_0956c8();
int Unk0bc1a8_Unk_0bc9b4();
int Unk0de678_Unk_0de870();
void func_020cb3dc();
void Unk095560_Unk_095a2c();
int func_020de8b0();
void Unk0cb32c_Unk_0cb32c();
void Unk0bc1a8_Unk_0bc928();
void Unk0cd470_Enter(void)
{
    func_020cb3dc();
    Unk095560_Unk_095a2c();
    if (func_020de8b0(0) != 0) {
        return;
    }
    Unk0cb32c_Unk_0cb32c();
    Unk0bc1a8_Unk_0bc928(18, 0xffff, 0);
}

/* decompiler-derived */
void Unk0cd470_Unk_0cd50c(void)
{
  int tmp1;
  tmp1 = Unk0de678_Get_data_021508d4();
  if (tmp1 == 0) {
    Unk0bc1a8_Unk_0bc9b4(0x12,0);
    Unk0cb32c_Unk_0cb344();
  }
  Unk0de678_Unk_0de870();
  Unk095560_Unk_0956c8();
  return;
}
