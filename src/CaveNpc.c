/* src/CaveNpc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct CaveNpcWork {
    u8 pad_0000[0x2c];
    s32 unk_002c;
} CaveNpcWork;

void CaveNpc_Nop_0fff3c(void) { }

extern u8 data_02151180[];
int func_0205ba98();
/* decompiler-derived */
void CaveNpc_Unk_1000d0(int arg0)
{
  u32 tmp1;
  if (((CaveNpcWork *)arg0)->unk_002c != 0) {
    return;
  }
  tmp1 = func_0205ba98(0x2000,0x200,((int)data_02151180),0x11e);
  ((CaveNpcWork *)arg0)->unk_002c = tmp1;
  return;
}
