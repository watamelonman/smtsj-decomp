/* src/game/unit_0206a224.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk06a224Work {
    u8 pad_0000[0x440];
    u32 unk_0440;
    u32 unk_0444;
    u32 unk_0448;
    u32 unk_044c;
} Unk06a224Work;



void func_020d6cac(void);
u32 Unk0986ac_Unk_098978(void);
void Unk0986ac_Thunk_02098714(u32 a);
void Unk06a224_Unk_06a9fc(void)
{
    Unk0986ac_Thunk_02098714(Unk0986ac_Unk_098978());
}

/* forwards to `func_020d6cac` */
void Unk06a224_Thunk_020d6cac(void) { func_020d6cac(); }

/* Globals block at 0x0216b9b0; fields named by their accessors. */
typedef struct Unk06a224Globals {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Unk06a224Globals;

extern Unk06a224Globals data_0216b9b0;

u32 Unk06a224_Unk_06a224(void)
{
    return data_0216b9b0.unk_08;
}

u32 Unk06a224_GetUnk00(void)
{
    return data_0216b9b0.unk_00;
}

void Unk06a224_Unk_06a244(u32 arg0)
{
    data_0216b9b0.unk_08 = arg0;
}

void Unk06a224_SetUnk00(u32 arg0)
{
    data_0216b9b0.unk_00 = arg0;
}


int func_020537b8();
typedef struct Unk06a224Slot {
    u16 id;
    u16 pad_0002;
} Unk06a224Slot;
s16 Unk06a224_CountUsedSlots(void)
{
    s16 n = 0;
    int i;
    for (i = 0; i < 489; i++) {
        if (FIELD(Unk06a224Slot *, data_0216b9b0.unk_04, 0x408)[i].id != 0) {
            n++;
        }
    }
    return n;
}

int Unk06a224_Unk_06a374(u8 *o)
{
    if (FIELD(s16, o, 0x154) % 2 != 0) {
        return 1;
    }
    return FIELD(s16, o, 0x156) > 0;
}

int Unk06a224_Unk_06a3a4(u8 *o)
{
    s16 a = FIELD(s16, o, 0x154);
    if (a % 2 == 0) {
        if (a < FIELD(s16, o, 0x158) - 1) {
            return 1;
        }
    } else if (FIELD(s16, o, 0x156) + 24 < FIELD(s16, o, 0x158)) {
        return 1;
    }
    return 0;
}

typedef struct Unk06a224Ctl {
    u8 pad_0000[348];
    u16 *slots[4]; /* count guessed; only the +348 offset is confirmed */
} Unk06a224Ctl;
void func_02099b10();
void func_02067d54();
s16 Unk06a224_CountUsedSlots(void);

void Unk06a224_Unk_06a998(Unk06a224Ctl *c, int i)
{
    u8 *p = (u8 *)c;
    if (c->slots[i] != 0) {
        func_02099b10(*c->slots[i], 1);
    }
    {
        c->slots[i] = 0;
        FIELD(u16, p + 0x100, 84) = 0;
        FIELD(u16, p + 0x100, 86) = 0;
        func_02067d54(p);
        FIELD(s16, p + 0x100, 88) = Unk06a224_CountUsedSlots();
        FIELD(s16, p + 0x100, 88)++;
    }
}

/* decompiler-derived */
void Unk06a224_Unk_06ae28(Unk06a224Work *arg0){
  int tmp1;
  tmp1 = func_020537b8(0,0x40);
  if (tmp1 != 0) {
    arg0->unk_0440 = 1;
  }
  tmp1 = func_020537b8(0,0x80);
  if (tmp1 != 0) {
    arg0->unk_0444 = 1;
  }
  tmp1 = func_020537b8(0,0x20);
  if (tmp1 != 0) {
    arg0->unk_0448 = 1;
  }
  tmp1 = func_020537b8(0,0x10);
  if (tmp1 != 0) {
    arg0->unk_044c = 1;
  }
  return;
}

