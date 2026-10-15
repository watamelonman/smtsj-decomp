/* src/game/unit_020fb128.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* returns 1 */
int Unk0fb128_GetConst1(void) { return 1; }

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_020fd0c8();
int func_020fb324();
int func_020fb614(u8 *p)
{
    if (FIELD(s8, p, 0x7400 + 128) != 1) {
        return 1;
    }
    return func_020fb324(p);
}
