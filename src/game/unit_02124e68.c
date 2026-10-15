/* src/game/unit_02124e68.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



typedef struct Unk124e68Obj {
    u32 unk_00;
    u8 pad[0x14];
    u8 unk_18;
    u8 unk_19;
    u8 unk_1a;
} Unk124e68Obj;
extern Unk124e68Obj *data_02176e88;
void func_02124e68(u32 a, u32 b, u32 c)
{
    data_02176e88->unk_00 = a;
    data_02176e88->unk_18 = b;
    data_02176e88->unk_19 = c;
    data_02176e88->unk_1a = 0;
}

/* empty callback */
void Unk124e68_Nop_124f48(void) { }

int func_02057524();
int func_02057534();
int func_02125024();
/* decompiler-derived */
void Unk124e68_Unk_124fbc(u32 *arg0)
{
  if (arg0[3] == 0) {
    return;
  }
  func_02057524(arg0[5]);
  func_02125024(*arg0,*(u8 *)(arg0 + 2),0x16);
  func_02057534();
}


/* decompiler-derived */
void Unk124e68_Unk_124ff0(u32 *arg0)
{
  if (arg0[4] == 0) {
    return;
  }
  func_02057524(arg0[5]);
  func_02125024(*arg0,*(u8 *)(arg0 + 2),0x16);
  func_02057534();
}
