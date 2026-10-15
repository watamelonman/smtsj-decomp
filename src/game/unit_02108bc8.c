/* src/game/unit_02108bc8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176e34[];
int func_02053000();
int Unk0a163c_Unk_0a1814();
int func_02063a30();
void func_02061f10();
u32 func_02052fe0();
void Unk108bc8_Unk_108bc8(u32 a, u32 b)
{
    func_02061f10(a, -1, 0, 0, func_02063a30(Unk0a163c_Unk_0a1814(b)));
}

u32 Unk108bc8_GetSize(void)
{
    return 0x5bfc;
}

void Unk108bc8_Alloc(void)
{
    if (*data_02176e34 != 0) {
        return;
    }
    *data_02176e34 = func_02052fe0(0x5ffc);
}

/* decompiler-derived */
void Unk108bc8_Unk_108c3c(void)
{
  func_02053000(*data_02176e34);
  *data_02176e34 = 0;
}

void Unk108bc8_Alloc();
/* decompiler-derived */
int Unk108bc8_Unk_108c60(void)
{
  if (*data_02176e34 == 0) {
    Unk108bc8_Alloc();
  }
  return *data_02176e34;
}

u32 Unk108bc8_GetHead(void)
{
    if (*data_02176e34 != 0) {
        return *(u16 *)*data_02176e34;
    }
    return 0;
}
