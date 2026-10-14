/*
 * src/game/unit_0202f078.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_02008848();
int Unk02e000_Unk_02e774();
int func_0202e788();

u8 Unk02f078_Unk_02f0d8(void);
u8 Unk02f078_Unk_02f220(void);
int Unk02f078_Unk_02f078(void);
void Unk02f078_Unk_02f0b0(u8 arg0);
void Unk02f078_Unk_02f0c4(void);
void Unk02f078_Unk_02f20c(u8 arg0);
int Unk02f078_Unk_02f0e8(void);
void Unk02f078_Unk_02f08c(void);

/* decompiler-derived */
u8 Unk02f078_Unk_02f0d8(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  return *(u8 *)(value + 2);
}

/* decompiler-derived */
u8 Unk02f078_Unk_02f220(void)
{
  int value;
  value = func_0202e788();
  return *(u8 *)(value + 0x361);
}

/* decompiler-derived */
int Unk02f078_Unk_02f078(void)
{
  int value;
  value = func_0202e788();
  return value + 0x36e;
}

/* decompiler-derived */
void Unk02f078_Unk_02f0b0(u8 arg0)
{
  int value;
  value = Unk02e000_Unk_02e774();
  *(u8 *)(value + 2) = arg0;
}

/* decompiler-derived */
void Unk02f078_Unk_02f0c4(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  *(u8 *)(value + 2) = 0;
}

/* decompiler-derived */
void Unk02f078_Unk_02f20c(u8 arg0)
{
  int value;
  value = func_0202e788();
  *(u8 *)(value + 0x361) = arg0;
}

/* decompiler-derived */
int Unk02f078_Unk_02f0e8(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  return *(char *)(value + 2) != '\0';
}

/* decompiler-derived */
void Unk02f078_Unk_02f08c(void)
{
  int value;
  value = Unk02f078_Unk_02f078();
  func_02008848(value,0,6);
  *(u8 *)(value + 1) = 100;
}
