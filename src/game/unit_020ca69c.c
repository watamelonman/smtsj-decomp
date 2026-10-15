/* src/game/unit_020ca69c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
int Unk0ca69c_Unk_0ca69c(int arg0)
{
  return arg0 + 0x6200;
}


/* decompiler-derived */
int Unk0ca69c_Unk_0ca6a4(int arg0)
{
  return (arg0 + 0xc5) * 0x80;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int func_020ca6b0();
int func_020cab28();
int func_020cae84(u8 *p)
{
    if (FIELD(s8, p + 29696, 128) == 1) {
        return func_020ca6b0(p);
    }
    return func_020cab28(p);
}
