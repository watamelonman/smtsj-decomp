/* src/game/unit_020cb0d0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0cb0d0Work {
    u8 pad_0000[0x20];
    u16 unk_0020;
} Unk0cb0d0Work;




/* decompiler-derived */
int Unk0cb0d0_Unk_0cb190(Unk0cb0d0Work *arg0, int arg1){
  return (u32)arg0->unk_0020 - (u32)((Unk0cb0d0Work *)arg1)->unk_0020;
}

int func_020445d0();
int func_0204fde0();
int func_0204fe18();
/* decompiler-derived */
void Unk0cb0d0_Unk_0cb1f8(void)
{
  u32 tmp1;
  tmp1 = func_020445d0(0xb,0);
  func_0204fde0();
  func_0204fe18(tmp1);
  return;
}

int func_020cb1a0();
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif

int func_020cb274(u8 *p)
{
    u32 k = ((u32)FIELD(u16, p, 50) << 16) >> 28;
    if (k == 14 || k == 1) {
        u8 b = p[35];
        if (b == 3 || b == 7) {
            return 1;
        }
    }
    return 0;
}

int func_020cb2ec(s32 x)
{
    return x > 0x15e;
}

/* decompiler-derived */
u32 Unk0cb0d0_Unk_0cb304(void)
{
  int tmp1;
  tmp1 = func_020cb1a0();
  if ((tmp1 != 0) && (*(char *)(tmp1 + 0x23) == '\a')) {
    return 1;
  }
  return 0;
}
