/*
 * src/game/unit_02044904.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_0215ee98[];
int func_0206df10();
int func_02072200();
int func_0209d13c();

int Unk044904_GetConst1(void);
u32 Unk044904_Get_data_0215ee98(void);
u32 Unk044904_Unk_0459ec(void);
void Unk044904_Unk_045c98(void);
void Unk044904_Unk_044e90(int arg0);
int Unk044904_Unk_045fd4(void);
void Unk044904_Unk_044ea8(void);

/* returns 1 */
int Unk044904_GetConst1(void) { return 1; }

/* decompiler-derived */
u32 Unk044904_Get_data_0215ee98(void)
{
  return *data_0215ee98;
}

/* decompiler-derived */
u32 Unk044904_Unk_0459ec(void)
{
  int tmp1;
  tmp1 = Unk044904_Get_data_0215ee98();
  return *(u32 *)(tmp1 + 0x50);
}

/* decompiler-derived */
void Unk044904_Unk_045c98(void)
{
  func_0206df10();
  func_02072200();
  return;
}

/* decompiler-derived */
void Unk044904_Unk_044e90(int arg0)
{
  if (*data_0215ee98 == 0) {
    *data_0215ee98 = arg0;
  }
  return;
}

/* decompiler-derived */
int Unk044904_Unk_045fd4(void)
{
  int tmp1;
  tmp1 = func_0209d13c();
  return tmp1 != 0;
}

/* decompiler-derived */
void Unk044904_Unk_044ea8(void)
{
  if (*data_0215ee98 != 0) {
    *data_0215ee98 = 0;
  }
  return;
}
