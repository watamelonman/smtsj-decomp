/* src/game/unit_0204bb9c.c: matched functions. */
#include "types.h"

typedef struct Unk04bb9cCtx {
    u8 pad_0000[0xa14];
    u32 unk_0a14;
} Unk04bb9cCtx;

extern Unk04bb9cCtx *data_0215eea4;

void func_0204ca04(u32 value)
{
    if (data_0215eea4 != 0) {
        data_0215eea4->unk_0a14 = value;
    }
}
