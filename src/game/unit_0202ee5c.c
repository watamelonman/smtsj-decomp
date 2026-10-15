/* src/game/unit_0202ee5c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk02e000_GetWorkArea();
int Unk02e000_Unk_02e774();
u8 *Unk02e000_Thunk_0202e788();

typedef struct Unk02ee5cRec {
    u8 pad_0000[0xb];
    u8 flag_000b_0 : 1;
    u8 pad_000c[0x18];
} Unk02ee5cRec;                 /* 36 bytes; same table as unit_0202e000 (work+0x16FC, ids 1..491) */
int func_0202eec0(u32 id)
{
    if (id > 491) {
        return 0;
    }
    {
        Unk02ee5cRec *r = &((Unk02ee5cRec *)((u8 *)Unk02e000_Unk_02e774() + 0x16fc))[id - 1];
        return r->flag_000b_0 ? 1 : 0;
    }
}

int func_0202ef0c(void)
{
    u8 v = Unk02e000_Thunk_0202e788()[0x70];
    if (v >= 160) {
        return 5;
    }
    if (v <= 95) {
        return 4;
    }
    return 1;
}

/* decompiler-derived */
int Unk02ee5c_Unk_02f044(void)
{
  int value;
  value = Unk02e000_GetWorkArea();
  return value + 0x368;
}

int func_02008848();
/* decompiler-derived */
void Unk02ee5c_Unk_02f054(void)
{
  int value;
  value = Unk02ee5c_Unk_02f044();
  func_02008848(value,0,6);
  *(u8 *)(value + 1) = 100;
}
