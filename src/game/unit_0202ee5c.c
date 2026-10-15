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
int Unk02e000_Unk_02e774(void);
int Unk0e651c_Unk_0e666c();
u8 *Unk02e000_Thunk_0202e788(void);
typedef struct Unk02e000Ent2 {
    u8 pad[11];
    u8 unk_0b_b0 : 1;
    u8 unk_0b_rest : 7;
    u8 pad2[19];
    u8 unk_1f_b0 : 1;
    u8 unk_1f_b1 : 1;
    u8 unk_1f_hi : 6;
    u8 pad3[4];
} Unk02e000Ent2;
#define ENT2(i) ((Unk02e000Ent2 *)((u8 *)Unk02e000_Unk_02e774() + 0x16fc) + ((i) - 1))

int func_0202ee5c(u32 id, int v)
{
    Unk02e000Ent2 *e;
    if (id > 491) {
        return 0;
    }
    e = ENT2(id);
    e->unk_0b_b0 = (u8)(v != 0);
    return 1;
}

int Unk02ee5c_GetRecordFlagB(u32 id)
{
    if (id > 491) {
        return 0;
    }
    {
        Unk02ee5cRec *r = &((Unk02ee5cRec *)((u8 *)Unk02e000_Unk_02e774() + 0x16fc))[id - 1];
        return r->flag_000b_0 ? 1 : 0;
    }
}

int Unk02ee5c_GetTierFromField70(void)
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

void func_0202ef34(int d)
{
    u8 *w;
    s16 v;
    if (Unk0e651c_Unk_0e666c(0x404) != 0) {
        return;
    }
    if (Unk0e651c_Unk_0e666c(0x405) != 0) {
        return;
    }
    if (Unk0e651c_Unk_0e666c(0x406) != 0) {
        return;
    }
    w = Unk02e000_Thunk_0202e788();
    v = w[112] + d;
    if (v > 255) {
        v = 255;
    }
    if (v < 0) {
        v = 0;
    }
    w[112] = v;
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
