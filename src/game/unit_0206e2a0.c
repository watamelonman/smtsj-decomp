/* src/game/unit_0206e2a0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u8 data_0216bac8[];
/* decompiler-derived */
int Unk06e2a0_Unk_06e2a0(int arg0)
{
  return arg0 * 0x148 + ((int)data_0216bac8) + 0x2c;
}

extern u32 data_0216bac4[];
extern u8 data_0216bafc[];
int func_020086bc();
u32 func_0206e39c(int i, int j)
{
    if ((s32)data_0216bac4[0] - 1 - i < 0) {
        return 0;
    }
    return *(u32 *)(data_0216bafc + i * 328 + j * 24);
}

void func_0206e3d8(int i, void *dst)
{
    if ((s32)data_0216bac4[0] - 1 - i < 0) {
        return;
    }
    func_020086bc(dst, data_0216bac8 + i * 328 + 188, 32);
}
