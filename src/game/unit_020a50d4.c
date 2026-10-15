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

s8 func_020a50e4(void)
{
    return data_02176b08.unk_06;
}
