/* src/game/unit_0211fc20.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk11fc20Work {
    u8 pad_0000[0xc];
    u32 unk_000c;
    u32 unk_0010;
    u8 pad_0014[0x194];
    s32 unk_01a8;
} Unk11fc20Work;

extern u32 data_02176e7c[];
/* decompiler-derived */
void Unk11fc20_Clear_data_02176e7c(void)
{
  *data_02176e7c = 0;
}

int func_02061424();
/* decompiler-derived */
void Unk11fc20_Unk_11fc48(void)
{
  if (*data_02176e7c == 0) {
    return;
  }
  func_02061424();
}

int func_0211fcb0();
/* decompiler-derived */
void Unk11fc20_Unk_11fc20(void)
{
  int value;
  if (*data_02176e7c != 0) {
    return;
  }
  value = func_0211fcb0();
  *data_02176e7c = value;
}


#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_02057d54();
int func_0211fc68(void)
{
    u8 *p = (u8 *)*data_02176e7c;
    if (p == 0) {
        return 1;
    }
    return FIELD(int, p, 0) == 4;
}

/* decompiler-derived */
int Unk11fc20_Unk_120944(int arg0)
{
  int value1;
  int value2;
  value1 = 0;
  value2 = 0;
  do {
    value2 = value2 + 1;
    if (((Unk11fc20Work *)arg0)->unk_01a8 != 0) {
      value1 = value1 + 1;
    }
    arg0 = arg0 + 0x2c;
  } while (value2 < 0x20);
  return value1;
}


int func_02120bd4();
/* decompiler-derived */
void Unk11fc20_Unk_12143c(int arg0,int arg1,u32 arg2)
{
  func_02120bd4(4,0,((Unk11fc20Work *)arg0)->unk_000c,((Unk11fc20Work *)arg0)->unk_0010,0x3000,
                arg1 << 0xc,arg2,0,0);
  return;
}

int Unk0a0ce4_Unk_0a0da4();
/* decompiler-derived */
void Unk11fc20_Unk_11fd38(u32 *arg0)
{
  arg0[3] = 100;
  *arg0 = 0;
  arg0[6] = 0;
  arg0[7] = 1;
  arg0[10] = 0x40000;
  arg0[0xb] = 0xb8000;
  arg0[0x11] = 0x4000;
  Unk0a0ce4_Unk_0a0da4(8);
  return;
}


/* decompiler-derived */
void Unk11fc20_Unk_120b88(u32 arg0,u32 arg1,int arg2,int arg3,int arg4,
                  int arg5,u32 arg6,u32 arg7,u32 arg8)
{
  func_02120bd4(arg0,arg1,arg2 << 0xc,arg3 << 0xc,arg4 << 0xc,arg5 << 0xc,arg6,
                arg7,arg8);
  return;
}




/* decompiler-derived */
int * Unk11fc20_Unk_120a58(u32 arg0)
{
  int *v1;
  int tmp2;
  tmp2 = *data_02176e7c;
  switch(arg0) {
  case 0:
    break;
  case 1:
    v1 = (int *)(tmp2 + 0x48);
    tmp2 = 0;
    do {
      if (*v1 == 0) {
        return v1;
      }
      tmp2 = tmp2 + 1;
      v1 = v1 + 0xb;
    } while (tmp2 < 8);
    break;
  case 2:
    v1 = (int *)(tmp2 + 0x728);
    tmp2 = 0;
    do {
      if (*v1 == 0) {
        return v1;
      }
      tmp2 = tmp2 + 1;
      v1 = v1 + 0xb;
    } while (tmp2 < 0x10);
    break;
  case 3:
    v1 = (int *)(tmp2 + 0x1a8);
    tmp2 = 0;
    do {
      if (*v1 == 0) {
        return v1;
      }
      tmp2 = tmp2 + 1;
      v1 = v1 + 0xb;
    } while (tmp2 < 0x20);
    break;
  case 4:
    v1 = (int *)(tmp2 + 0x9e8);
    tmp2 = 0;
    do {
      if (*v1 == 0) {
        return v1;
      }
      tmp2 = tmp2 + 1;
      v1 = v1 + 0xb;
    } while (tmp2 < 0x80);
  }
  return (int *)0x0;
}

/* decompiler-derived */
u32 Unk11fc20_Unk_11fc94(void)
{
  u32 tmp1;
  if (*data_02176e7c == 0) {
    tmp1 = 0;
  }
  else {
    tmp1 = *(u32 *)(*data_02176e7c + 0x10);
  }
  return tmp1;
}

int func_02120650(u8 *p)
{
    int v = FIELD(int, p, 40) - 4096;
    FIELD(int, p, 40) = v;
    return v <= 8192;
}

int func_0212066c(u8 *p)
{
    int v;
    Unk0a0ce4_Unk_0a0da4(3);
    FIELD(u32, p, 64) = 0;
    v = FIELD(int, p, 68) - 4096;
    FIELD(int, p, 68) = v;
    if (v <= 4096) {
        FIELD(u32, p, 28) = 0;
        return 1;
    }
    FIELD(u32, p, 24) = 15;
    return 0;
}

void func_02120898(u32 a, int b, int c, u32 d, u32 e, u32 f)
{
    u8 *w = (u8 *)*data_02176e7c;
    func_02057d54(a, b + (FIELD(int, w, 4) + 64), c + FIELD(int, w, 8), d, e, f);
}
