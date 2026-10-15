/* src/game/unit_020a50d4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


/* Globals at 0x02176b08. */
typedef struct Unk0a50d4Globals {
    u8 pad_0000[0x6];
    s8 unk_06;
    u8 pad_0007;
    u32 unk_08;
} Unk0a50d4Globals;

extern Unk0a50d4Globals data_02176b08;

u32 Unk0a50d4_Unk_0a50d4(void)
{
    return data_02176b08.unk_08;
}

s8 Unk0a50d4_GetUnk06(void)
{
    return data_02176b08.unk_06;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int func_02002954();
int func_020a5124();
int func_020a5490();
int func_020a50f4(void)
{
    s32 v = func_02002954(0x0400106c);
    if (v == 16) {
        return 1;
    }
    return v == -16;
}

int func_020a5648(u8 *p)
{
    switch (FIELD(s8, p + 29696, 128)) {
    case 0:
        return func_020a5124(p);
    case 1:
        return func_020a5490(p);
    }
    return 1;
}
