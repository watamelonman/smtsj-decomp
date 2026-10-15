/* src/game/unit_02109dcc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk109dccWork {
    u8 pad_0000[0x10];
    s32 unk_0010;
} Unk109dccWork;

int func_0205c3dc();
/* decompiler-derived */
void Unk109dcc_Unk_109f70(int arg0)
{
  if (((Unk109dccWork *)arg0)->unk_0010 == 0) {
    return;
  }
  func_0205c3dc();
  ((Unk109dccWork *)arg0)->unk_0010 = 0;
  return;
}

int func_0205c704();
int func_02061424();
/* decompiler-derived */
void Unk109dcc_Unk_109dcc(int arg0)
{
  func_0205c704(((Unk109dccWork *)arg0)->unk_0010);
  if (**(int **)(arg0 + 4) != 0) {
    return;
  }
  func_02061424(arg0);
  return;
}
