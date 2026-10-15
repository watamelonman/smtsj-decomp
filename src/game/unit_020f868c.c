/* src/game/unit_020f868c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0f868cWork {
    u8 pad_0000[0x120];
    u32 unk_0120;
} Unk0f868cWork;

int func_02052d7c();
int Unk118b04_Unk_118e50();
/* decompiler-derived */
void Unk0f868c_Unk_0f868c(int arg0)
{
  Unk118b04_Unk_118e50(0xb,1);
  func_02052d7c(arg0 + 0x124,((Unk0f868cWork *)arg0)->unk_0120);
}
