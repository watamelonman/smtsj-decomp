/*
 * src/game/unit_020f3db4.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int Unk02e000_Unk_02e774();
int func_02044428();
int func_02044534();
int Unk0f3db4_Unk_0f3ec8();

u32 Unk0f3db4_Unk_0f44a8(u32 arg0);
void Unk0f3db4_Unk_0f3dc8(void);
void Unk0f3db4_Unk_0f3dd8(void);
int Unk0f3db4_Unk_0f4528(u32 arg0);
void Unk0f3db4_Unk_0f4550(u8 *arg0);
int Unk0f3db4_Unk_0f3db4(void);
void Unk0f3db4_Unk_0f44d0(u8 *arg0,u8 arg1);
void Unk0f3db4_Unk_0f4490(u32 arg0,int arg1);

/* decompiler-derived */
u32 Unk0f3db4_Unk_0f44a8(u32 arg0)
{
  return arg0 & 3;
}

/* decompiler-derived */
void Unk0f3db4_Unk_0f3dc8(void)
{
  func_02044428(8);
}

/* decompiler-derived */
void Unk0f3db4_Unk_0f3dd8(void)
{
  func_02044534(8);
}

/* decompiler-derived */
int Unk0f3db4_Unk_0f4528(u32 arg0)
{
  return (arg0 & 4) != 0;
}

/* decompiler-derived */
void Unk0f3db4_Unk_0f4550(u8 *arg0)
{
  *arg0 = *arg0 | 4;
}

/* decompiler-derived */
int Unk0f3db4_Unk_0f3db4(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  return value + 0x5e52;
}

/* decompiler-derived */
void Unk0f3db4_Unk_0f44d0(u8 *arg0,u8 arg1)
{
  *arg0 = *arg0 & 4 | arg1;
}

/* decompiler-derived */
void Unk0f3db4_Unk_0f4490(u32 arg0,int arg1)
{
  int value;
  value = Unk0f3db4_Unk_0f3ec8();
  Unk0f3db4_Unk_0f44a8(*(u8 *)(value + arg1));
}



/* decompiler-derived */
void Unk0f3db4_Unk_0f4510(u32 arg0,int arg1)
{
  int value;
  value = Unk0f3db4_Unk_0f3ec8();
  Unk0f3db4_Unk_0f4528(*(u8 *)(value + arg1));
}




/* decompiler-derived */
u32 Unk0f3db4_Unk_0f3e6c(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 0x32;
  case 1:
    return 0x32;
  case 2:
    return 0x32;
  case 3:
    return 0x32;
  case 4:
    return 100;
  case 5:
    return 0x3c;
  default:
    return 0;
  }
}


/* decompiler-derived */
int Unk0f3db4_Unk_0f3ec8(u32 arg0)
{
  int value;
  value = Unk0f3db4_Unk_0f3db4();
  switch(arg0) {
  case 0:
    return value;
  case 1:
    return value + 0x32;
  case 2:
    return value + 100;
  case 3:
    return value + 0x96;
  case 4:
    return value + 200;
  case 5:
    return value + 300;
  default:
    return 0;
  }
}


/* decompiler-derived */
void Unk0f3db4_Unk_0f4674(int arg0,int arg1)
{
  u8 value1;
  int value2;
  int value3;
  value3 = 0;
  do {
    value1 = Unk0f3db4_Unk_0f44a8(*(u8 *)(arg1 + value3));
    *(u8 *)(arg0 + value3) = value1;
    value3 = value3 + 1;
  } while (value3 < 100);
  value3 = 0;
  do {
    value1 = Unk0f3db4_Unk_0f44a8(*(u8 *)(arg1 + value3 + 100));
    value2 = arg0 + value3;
    value3 = value3 + 1;
    *(u8 *)(value2 + 100) = value1;
  } while (value3 < 0x32);
  value3 = 0;
  do {
    value1 = Unk0f3db4_Unk_0f44a8(*(u8 *)(arg1 + value3 + 0x96));
    value2 = arg0 + value3;
    value3 = value3 + 1;
    *(u8 *)(value2 + 0x96) = value1;
  } while (value3 < 0x32);
  value3 = 0;
  do {
    value1 = Unk0f3db4_Unk_0f44a8(*(u8 *)(arg1 + value3 + 300));
    value2 = arg0 + value3;
    value3 = value3 + 1;
    *(u8 *)(value2 + 300) = value1;
  } while (value3 < 0x3c);
}

/* decompiler-derived */
void func_020f4538(u32 arg0,int arg1)
{
  int tmp1;
  tmp1 = Unk0f3db4_Unk_0f3ec8((u32)arg0);
  Unk0f3db4_Unk_0f4550((u8 *)tmp1 + arg1);
}
