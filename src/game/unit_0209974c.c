/*
 * src/game/unit_0209974c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct Unk09974cWork {
    u8 unk_0000[0x20];
    u16 UnkField0020;
} Unk09974cWork;


int func_0209993c();

int Unk09974c_Unk_099860(u16 *arg0,u16 *arg1);
int Unk09974c_Unk_099870(u16 *arg0,u16 *arg1);
int Unk09974c_Unk_099880(Unk09974cWork *work,int arg1);
int Unk09974c_Unk_099890(u16 *arg0,u16 *arg1);
int Unk09974c_Unk_0998a0(u16 *arg0,u16 *arg1);
int Unk09974c_Unk_0998b0(u16 *arg0,u16 *arg1);
int Unk09974c_Unk_0998d8(void);

/* decompiler-derived */
int Unk09974c_Unk_099860(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

/* decompiler-derived */
int Unk09974c_Unk_099870(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

/* decompiler-derived */
int Unk09974c_Unk_099880(Unk09974cWork *work,int arg1)
{
  return (u32)work->UnkField0020 - (u32)*(u16 *)(arg1 + 0x20);
}

/* decompiler-derived */
int Unk09974c_Unk_099890(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

/* decompiler-derived */
int Unk09974c_Unk_0998a0(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

/* decompiler-derived */
int Unk09974c_Unk_0998b0(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

/* decompiler-derived */
int Unk09974c_Unk_0998d8(void)
{
  int value;
  value = func_0209993c();
  return 0 < value;
}


int func_020445f4();
int func_0204fed8();
/* decompiler-derived */
u32 Unk09974c_Unk_099bac(int arg0)
{
  u32 value;
  if (arg0 != 0) {
    value = func_020445f4(6,0);
    value = func_0204fed8(value,arg0);
    return value;
  }
  return 0;
}


/* decompiler-derived */
u32 Unk09974c_Unk_099bd4(int arg0)
{
  u32 value;
  if (arg0 != 0) {
    value = func_020445f4(7,0);
    value = func_0204fed8(value,arg0);
    return value;
  }
  return 0;
}

int func_02008848();
int func_020629c4();
/* decompiler-derived */
void Unk09974c_Unk_09974c(int *arg0)
{
  if (*arg0 == 0) {
    return;
  }
  func_020629c4(arg0[4]);
  arg0[4] = 0;
  func_02008848(arg0,0,0x48);
}

