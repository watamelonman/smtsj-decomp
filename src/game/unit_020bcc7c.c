/* src/game/unit_020bcc7c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_020bce08();
int func_020bcd58(s32 *p)
{
    if (p[2] <= 0) {
        return 0;
    }
    p[2] = p[2] - (p[0] - 1);
    if (p[2] <= 0) {
        p[2] = 0;
    }
    p[4] = p[4] + (p[2] - p[3]);
    return 1;
}

/* decompiler-derived */
void Unk0bcc7c_Unk_0bcdf8(u32 arg0)
{
  func_020bce08(arg0,1);
}
