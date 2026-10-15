/* src/game/unit_02122850.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk122850Work {
    u8 pad_0000[0x4];
    s32 unk_0004;
} Unk122850Work;




/* empty callback */
void Unk122850_Nop_122960(void) { }


/* empty callback */
void Unk122850_Nop_122964(void) { }

int Unk_LoadPalette_020de678();
/* decompiler-derived */
void Unk122850_Unk_122968(u32 *arg0)
{
  Unk_LoadPalette_020de678(*arg0);
}

int func_020bc650();
/* decompiler-derived */
void Unk122850_Unk_12292c(Unk122850Work *arg0){
  int value;
  if (arg0->unk_0004 == 0) {
    return;
  }
  value = func_020bc650(0xc);
  if (value == 0) {
    return;
  }
  Unk0bc1a8_Unk_0bc504(arg0,0);
}

extern u32 data_02176e80[];
int func_0205bb68();
int func_0205ddb4();
/* decompiler-derived */
void Unk122850_Unk_122978(int *arg0)
{
  if (*arg0 != 0) {
    func_0205ddb4();
    *arg0 = 0;
  }
  func_0205bb68();
  *data_02176e80 = 0;
}

