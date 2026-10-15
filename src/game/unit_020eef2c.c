/* src/game/unit_020eef2c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0eef2cWork {
    u8 pad_0000[0x4];
    s32 unk_0004;
} Unk0eef2cWork;




/* empty callback */
void Unk0eef2c_Nop_0eef80(void) { }


/* empty callback */
void Unk0eef2c_Nop_0ef06c(void) { }

int func_02057df8();
int func_02057e18();
/* decompiler-derived */
void Unk0eef2c_Unk_0ef070(Unk0eef2cWork *arg0){
  if (arg0->unk_0004 == 1) {
    return;
  }
  func_02057e18(0x1f);
  func_02057df8();
  return;
}


/* decompiler-derived */
void Unk0eef2c_Unk_0eef58(u32 *arg0)
{
  *arg0 = 0x21;
  arg0[1] = 1;
  arg0[2] = 0;
  arg0[3] = 0;
  arg0[4] = 0xffffff0f;
  arg0[5] = 0;
  return;
}

extern u32 data_02176dec[];
int func_02008848();
/* decompiler-derived */
void func_020eef2c(u32 arg0)
{
  func_02008848(arg0,0,0x18);
  *data_02176dec = arg0;
  Unk0eef2c_Unk_0eef58((u32 *)arg0);
}
