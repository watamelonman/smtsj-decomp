/* src/game/unit_020cd6ec.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0cd6ecWork {
    u8 pad_0000[0x8];
    u32 unk_0008;
    u8 pad_000c[0x10];
    u32 unk_001c;
    u8 pad_0020[0xd0];
    u32 unk_00f0;
} Unk0cd6ecWork;

int func_020cb5b4();
void func_020ce2d8();
void func_020ce33c();
void func_020cddd0(u8 *p, u32 a)
{
    int r = func_020cb5b4(a, p + 1);
    if (r == 1) {
        func_020ce2d8(p);
    } else if (r == 2) {
        func_020ce33c(p);
    } else if (r == 3) {
        p[0] = p[2];
    }
}

void Unk0cd6ec_Nop_0ce3ec(void) { }

int Unk0a0ce4_Unk_0a0da4();
/* decompiler-derived */
void Unk0cd6ec_Unk_0ce280(u8 *arg0,u32 arg1)
{
  Unk0a0ce4_Unk_0a0da4(5);
  arg0[2] = 4;
  *arg0 = 0xc;
  ((Unk0cd6ecWork *)arg0)->unk_0008 = arg1;
}

int Unk122e1c_Unk_123294();
/* decompiler-derived */
void Unk0cd6ec_Unk_0ce2ac(u8 *arg0,u32 arg1)
{
  Unk122e1c_Unk_123294(((Unk0cd6ecWork *)arg0)->unk_001c);
  ((Unk0cd6ecWork *)arg0)->unk_00f0 = arg1;
  arg0[2] = 1;
  *arg0 = 3;
}
