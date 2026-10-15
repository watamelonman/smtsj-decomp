/*
 * src/game/unit_020e1648.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct Unk0e1648Work {
    u8 unk_0000[0x4];
    u16 UnkField0004;
    u16 UnkField0006;
    u8 unk_0008[0xeb8];
    s32 UnkField0ec0;
} Unk0e1648Work;


extern u32 data_02176c78[];
int func_020e8014();
int func_020e8030();

u32 Unk0e1648_Unk_0e5240(int arg0,int arg1);
u32 Unk0e1648_Get_data_02176c78(void);
int Unk0e1648_Unk_0e2da0(int arg0);
void Unk0e1648_Unk_0e2cb0(Unk0e1648Work *work);
void Unk0e1648_Unk_0e5434(void);
int Unk0e1648_Unk_0e1648(void);
int Unk0e1648_Unk_0e2c90(Unk0e1648Work *work,int arg1);

/* decompiler-derived */
u32 Unk0e1648_Unk_0e5240(int arg0,int arg1)
{
  return *(u32 *)(arg0 + arg1 * 4 + 0xc);
}

/* decompiler-derived */
u32 Unk0e1648_Get_data_02176c78(void)
{
  return *data_02176c78;
}

/* decompiler-derived */
int Unk0e1648_Unk_0e2da0(int arg0)
{
  return arg0 + 0xd2 + *(int *)(arg0 + 0x7c) * 8;
}

/* decompiler-derived */
void Unk0e1648_Unk_0e2cb0(Unk0e1648Work *work)
{
  work->UnkField0ec0 = (u32)(work->UnkField0ec0 == 0);
}

/* decompiler-derived */
void Unk0e1648_Unk_0e5434(void)
{
  func_020e8014(0);
  func_020e8030(0);
}

/* decompiler-derived */
int Unk0e1648_Unk_0e1648(void)
{
  return *(int *)(((int)data_02176c78) + 4) == 0;
}

/* decompiler-derived */
int Unk0e1648_Unk_0e2c90(Unk0e1648Work *work,int arg1)
{
  int value;
  value = (u32)work->UnkField0006 - (u32)*(u16 *)(arg1 + 6);
  if (value == 0) {
    value = (u32)work->UnkField0004 - (u32)*(u16 *)(arg1 + 4);
  }
  return value;
}


int func_020f3de8();
/* decompiler-derived */
void Unk0e1648_Unk_0e2d80(int arg0)
{
  func_020f3de8(*(u32 *)(arg0 + 0x68),
                  *(u16 *)(arg0 + *(int *)(arg0 + 0x7c) * 8 + 0xd4));
}

int func_0209993c();
/* decompiler-derived */
int Unk0e1648_Unk_0e4f34(u32 arg0,int arg1)
{
  int value;
  value = func_0209993c();
  if (99 < value + arg1) {
    arg1 = 99 - value;
  }
  return arg1;
}

int func_020445f4();
int func_0204fed8();
/* decompiler-derived */
void Unk0e1648_Unk_0e50c8(u32 arg0)
{
  u32 value;
  value = func_020445f4(0x1e,3);
  func_0204fed8(value,arg0);
}

int func_020998c0();
/* decompiler-derived */
int Unk0e1648_Unk_0e3f5c(int arg0)
{
  int value;
  value = func_020998c0(*(u16 *)(arg0 + *(int *)(arg0 + 0x7c) * 8 + 0xd6));
  return value == 4;
}


/* decompiler-derived */
u32 Unk0e1648_Unk_0e4fd0(int arg0,u32 arg1)
{
  int value;
  if ((arg0 == 4) && (value = func_0209993c(arg1), 0 < value)) {
    return 1;
  }
  return 0;
}


int func_020e5090();
int func_020e544c();
/* decompiler-derived */
void func_020e533c(int arg0)
{
  int tmp1;
  tmp1 = func_020e544c();
  if (tmp1 != 0) {
    func_020e5090(*(u32 *)(arg0 + 0xea0),2);
    return;
  }
  func_020e5090(*(u32 *)(arg0 + 0xea0),3);
  return;
}


extern u8 data_02176c80[];
int func_0202e0cc();
int func_020fc84c();
/* decompiler-derived */
void func_020e16f0(u8 *arg0)
{
  *(u8 **)(((int)data_02176c80) + 4) = arg0;
  func_0202e0cc();
  func_020fc84c(0);
  *(u32 *)(arg0 + 0xee4) = 0;
  arg0[1] = 0;
  *arg0 = 1;
  arg0[0xeec] = 0xff;
  return;
}


int func_0204faf0();
int func_020e49cc();
/* decompiler-derived */
void func_020e4964(u32 arg0)
{
  u32 tmp1;
  u32 tmp2;
  tmp1 = func_020998c0();
  tmp2 = 0;
  switch(tmp1) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    goto LAB_020e499c;
  case 4:
LAB_020e499c:
    tmp2 = func_020e49cc(6,arg0);
    break;
  case 5:
    goto LAB_020e49b0;
  case 6:
LAB_020e49b0:
    tmp2 = func_020e49cc(7,arg0);
  }
  func_0204faf0(1,tmp2);
  return;
}
