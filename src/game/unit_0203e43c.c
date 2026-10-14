/*
 * src/game/unit_0203e43c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 data_0215e85e[];
int func_0202e788();
int func_0203fa08();
void func_0203fa84(void);
int func_0205410c();

void Unk03e43c_Thunk_0203fa84(void);
int Unk03e43c_Unk_03f2ac(int arg0);
void Unk03e43c_Unk_03fa28(void);
void Unk03e43c_Unk_03f2bc(void);
void Unk03e43c_Unk_03fa3c(char arg0);

/* forwards to `func_0203fa84` */
void Unk03e43c_Thunk_0203fa84(void) { func_0203fa84(); }

/* decompiler-derived */
int Unk03e43c_Unk_03f2ac(int arg0)
{
  return ((int)data_0215e85e) + arg0;
}

/* decompiler-derived */
void Unk03e43c_Unk_03fa28(void)
{
  int value;
  value = func_0202e788();
  func_0203fa08(*(u8 *)(value + 0x360));
}

/* decompiler-derived */
void Unk03e43c_Unk_03f2bc(void)
{
  int value;
  value = func_0205410c();
  *(u8 *)(value + 0x10) = *(u8 *)(value + 0x10) | 2;
}

/* decompiler-derived */
void Unk03e43c_Unk_03fa3c(char arg0)
{
  int value;
  value = func_0202e788();
  *(char *)(value + 0x360) = arg0 * '\n';
}
