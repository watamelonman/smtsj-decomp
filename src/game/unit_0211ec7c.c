/* src/game/unit_0211ec7c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk11ec7cWork {
    u8 pad_0000[0x4];
    u32 unk_0004;
    u32 unk_0008;
    u8 pad_000c[0x4];
    u32 unk_0010;
    u32 unk_0014;
    s32 unk_0018;
    s32 unk_001c;
    u32 unk_0020;
    u16 unk_0024;
    u8 pad_0026[0x82];
    u32 unk_00a8;
    u8 pad_00ac[0x4];
    u32 unk_00b0;
    u8 pad_00b4[0x1b8];
    u32 unk_026c;
    u8 pad_0270[0x4];
    s32 unk_0274;
} Unk11ec7cWork;

void Unk11ec7c_Nop_11ef08(void) { }

int Unk02e000_Unk_02e0cc();
int Unk05b82c_Unk_05b82c();
/* decompiler-derived */
u32 Unk11ec7c_Unk_11efec(void)
{
  Unk02e000_Unk_02e0cc();
  Unk05b82c_Unk_05b82c(0xd2);
  return 1;
}

int func_0205dde4();
int func_0211eda0();
/* decompiler-derived */
void Unk11ec7c_Unk_11ee8c(int arg0)
{
  func_0205dde4(((Unk11ec7cWork *)arg0)->unk_0004);
  func_0211eda0(((Unk11ec7cWork *)arg0)->unk_0008);
  return;
}


/* decompiler-derived */
void Unk11ec7c_Unk_11ef0c(int arg0)
{
  u32 tmp1;
  tmp1 = ((Unk11ec7cWork *)arg0)->unk_0018 + 1;
  ((Unk11ec7cWork *)arg0)->unk_0018 = tmp1;
  if (((Unk11ec7cWork *)arg0)->unk_0014 < tmp1) {
    ((Unk11ec7cWork *)arg0)->unk_0010 = 3;
  }
  return;
}

int func_0211ee10();
/* decompiler-derived */
void Unk11ec7c_Unk_11ef2c(int arg0)
{
  ((Unk11ec7cWork *)arg0)->unk_001c = ((Unk11ec7cWork *)arg0)->unk_001c + -1;
  func_0211ee10(arg0,0);
  if (0 < ((Unk11ec7cWork *)arg0)->unk_001c) {
    return;
  }
  ((Unk11ec7cWork *)arg0)->unk_0010 = 0;
  ((Unk11ec7cWork *)arg0)->unk_0014 = 0;
  ((Unk11ec7cWork *)arg0)->unk_0018 = 0;
  ((Unk11ec7cWork *)arg0)->unk_001c = 0;
  ((Unk11ec7cWork *)arg0)->unk_0024 = 0;
  ((Unk11ec7cWork *)arg0)->unk_0020 = 0;
  return;
}


int func_02044534();
int func_02053000();
/* decompiler-derived */
void Unk11ec7c_Unk_11ec7c(int arg0)
{
  func_02053000(((Unk11ec7cWork *)arg0)->unk_026c);
  ((Unk11ec7cWork *)arg0)->unk_026c = 0;
  func_02053000(((Unk11ec7cWork *)arg0)->unk_00a8);
  ((Unk11ec7cWork *)arg0)->unk_00a8 = 0;
  func_02053000(((Unk11ec7cWork *)arg0)->unk_00b0);
  ((Unk11ec7cWork *)arg0)->unk_00b0 = 0;
  if (((Unk11ec7cWork *)arg0)->unk_0274 == 0) {
    return;
  }
  func_02044534(0x24);
  return;
}

extern u8 data_02151fb4[];
int func_02008848();
int func_0205dcd4();
int func_020629ac();
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void Unk11ec7c_Unk_11ee8c(int arg0);
void Unk11ec7c_Nop_11ef08(void);
void Unk11ec7c_Unk_11ef0c(int arg0);
void Unk11ec7c_Unk_11ef2c(int arg0);
void func_0211eea8();
void Unk11ec7c_ApplyNext(u8 *p);
void Unk11ec7c_Dispatch(u8 *p);
void Unk11ec7c_ApplyNext(u8 *p)
{
    FIELD(int, p, 12) = FIELD(int, p, 16);
    FIELD(int, p, 16) = -1;
    switch (FIELD(int, p, 12)) {
    case 1:
        Unk11ec7c_Unk_11ee8c((int)p);
        return;
    case 2:
        Unk11ec7c_Nop_11ef08();
        return;
    }
}

void Unk11ec7c_Dispatch(u8 *p)
{
    switch (FIELD(u32, p, 12)) {
    case 0:
        break;
    case 1:
        func_0211eea8(p);
        break;
    case 2:
        Unk11ec7c_Unk_11ef0c((int)p);
        break;
    case 3:
        Unk11ec7c_Unk_11ef2c((int)p);
        break;
    }
}

/* decompiler-derived */
void Unk11ec7c_Unk_11f004(int *arg0)
{
  int tmp1;
  if (*arg0 == 1) {
    return;
  }
  func_02008848(arg0,0,0x28);
  *arg0 = 1;
  arg0[3] = 0;
  arg0[4] = 0;
  Unk02e000_Unk_02e0cc();
  tmp1 = func_0205dcd4(((int)data_02151fb4),1);
  arg0[1] = tmp1;
  tmp1 = func_020629ac(5,1,1,1);
  arg0[2] = tmp1;
  return;
}

void Unk11ec7c_Update(u8 *p)
{
    if (FIELD(u32, p, 0) == 0) {
        return;
    }
    if (FIELD(int, p, 16) != -1) {
        Unk11ec7c_ApplyNext(p);
    }
    Unk11ec7c_Dispatch(p);
}
