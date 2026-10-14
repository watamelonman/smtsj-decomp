/*
 * src/game/unit_0210a034.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct Unk10a034Work {
    u8 unk_0000[0x8];
    u32 UnkField0008;
    u8 unk_000c[0x4];
    u32 UnkField0010;
} Unk10a034Work;


extern u32 data_02176e38[];
extern u32 data_02176e3c[];
extern u32 data_02176e44[];
int func_02061424();
int func_020a1740();

u32 Unk10a034_Get_data_02176e38(void);
u32 Unk10a034_Get_data_02176e3c(void);
u32 Unk10a034_Unk_10af7c(void);
u32 Unk10a034_Get_data_02176e44(void);
void Unk10a034_Clear_data_02176e38(void);
void Unk10a034_Unk_10a9a4(Unk10a034Work *work,u32 arg1,int arg2);
void Unk10a034_Clear_data_02176e44(void);
void Unk10a034_Unk_10b394(Unk10a034Work *work,u32 arg1,int arg2);
void Unk10a034_Unk_10a05c(void);
void Unk10a034_Unk_10a074(void);
u32 Unk10a034_Unk_10a0b4(void);
int Unk10a034_Unk_10afc0(void);
void Unk10a034_Unk_10b000(void);
void Unk10a034_Unk_10b018(void);
int Unk10a034_Unk_10b058(void);
void Unk10a034_Unk_10aeb0(int arg0);

/* decompiler-derived */
u32 Unk10a034_Get_data_02176e38(void)
{
  return *data_02176e38;
}

/* decompiler-derived */
u32 Unk10a034_Get_data_02176e3c(void)
{
  return *data_02176e3c;
}

/* decompiler-derived */
u32 Unk10a034_Unk_10af7c(void)
{
  return *(u32 *)(((int)data_02176e3c) + 4);
}

/* decompiler-derived */
u32 Unk10a034_Get_data_02176e44(void)
{
  return *data_02176e44;
}

/* decompiler-derived */
void Unk10a034_Clear_data_02176e38(void)
{
  *data_02176e38 = 0;
}

/* decompiler-derived */
void Unk10a034_Unk_10a9a4(Unk10a034Work *work,u32 arg1,int arg2)
{
  work->UnkField0010 = arg1;
  if (arg2 == 0) {
    arg1 = 0x11;
  }
  work->UnkField0008 = arg1;
}

/* decompiler-derived */
void Unk10a034_Clear_data_02176e44(void)
{
  *data_02176e44 = 0;
}

/* decompiler-derived */
void Unk10a034_Unk_10b394(Unk10a034Work *work,u32 arg1,int arg2)
{
  work->UnkField0010 = arg1;
  if (arg2 == 0) {
    arg1 = 8;
  }
  work->UnkField0008 = arg1;
}

/* decompiler-derived */
void Unk10a034_Unk_10a05c(void)
{
  int value;
  value = Unk10a034_Get_data_02176e38();
  if (value == 0) {
    return;
  }
  func_02061424();
}

/* decompiler-derived */
void Unk10a034_Unk_10a074(void)
{
  int value;
  value = Unk10a034_Get_data_02176e38();
  if (value != 0) {
    *(u32 *)(value + 8) = *(u32 *)(value + 0x10);
  }
}

/* decompiler-derived */
u32 Unk10a034_Unk_10a0b4(void)
{
  int value1;
  u32 value2;
  value1 = Unk10a034_Get_data_02176e38();
  if (value1 == 0) {
    value2 = 1;
  }
  else {
    value2 = *(u32 *)(value1 + 0x18);
  }
  return value2;
}

/* decompiler-derived */
int Unk10a034_Unk_10afc0(void)
{
  int value;
  value = Unk10a034_Unk_10af7c();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x18;
  }
  return value;
}

/* decompiler-derived */
void Unk10a034_Unk_10b000(void)
{
  int value;
  value = Unk10a034_Get_data_02176e44();
  if (value == 0) {
    return;
  }
  func_02061424();
}

/* decompiler-derived */
void Unk10a034_Unk_10b018(void)
{
  int value;
  value = Unk10a034_Get_data_02176e44();
  if (value != 0) {
    *(u32 *)(value + 8) = *(u32 *)(value + 0x10);
  }
}

/* decompiler-derived */
int Unk10a034_Unk_10b058(void)
{
  int value;
  value = func_020a1740();
  return (u32)*(u8 *)(value + 2) * 300;
}

/* decompiler-derived */
void Unk10a034_Unk_10aeb0(int arg0)
{
  int value;
  value = 0;
  do {
    value = value + 1;
    *(u32 *)(arg0 + 0x2c) = 0;
    arg0 = arg0 + 0xc;
  } while (value < 0xc);
}
