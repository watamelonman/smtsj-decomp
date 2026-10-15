/* src/game/unit_020df5b8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



u32 func_020445d0();
void func_0204fe18();
u8 *func_0204fde0();
u8 *Unk0df5b8_GetEntry42(int i)
{
    u32 r = func_020445d0(32, 0);
    func_0204fe18(r);
    return func_0204fde0(r) + i * 42;
}

/* empty callback */
void Unk0df5b8_Nop_0df668(void) { }

int func_02008904();
int Unk108bc8_Unk_108c60();
/* decompiler-derived */
void Unk0df5b8_Unk_0df684(u32 arg0,u32 arg1,u32 arg2)
{
  u32 value;
  value = Unk108bc8_Unk_108c60();
  func_02008904(arg0,value,arg2);
}
