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
