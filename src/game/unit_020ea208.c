/*
 * src/game/unit_020ea208.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_02176ddc[];
int func_020572d8();
int func_02057eb8();
int func_02099bac();
int func_020cb044();
int func_020e8374();
int func_020e849c();
int Unk0e8228_Unk_0e8f38();

void Unk0ea208_Unk_0ead3c(void);
u32 Unk0ea208_Get_data_02176ddc(void);
void Unk0ea208_Unk_0eaca0(void);
u32 Unk0ea208_Unk_0ea72c(void);
void Unk0ea208_Unk_0ead4c(void);

/* decompiler-derived */
void Unk0ea208_Unk_0ead3c(void)
{
  Unk0e8228_Unk_0e8f38();
  func_020cb044();
}

/* decompiler-derived */
u32 Unk0ea208_Get_data_02176ddc(void)
{
  return *data_02176ddc;
}

/* decompiler-derived */
void Unk0ea208_Unk_0eaca0(void)
{
  func_02057eb8(0xffffffff);
  func_020572d8();
}

/* decompiler-derived */
u32 Unk0ea208_Unk_0ea72c(void)
{
  int value1;
  u32 value2;
  value1 = Unk0ea208_Get_data_02176ddc();
  if (value1 == 0) {
    value2 = 0;
  }
  else {
    value2 = *(u32 *)(value1 + 0x1d4);
  }
  return value2;
}

/* decompiler-derived */
void Unk0ea208_Unk_0ead4c(void)
{
  func_020e8374(8);
  func_020e849c();
  func_02099bac();
}
