/*
 * src/game/unit_020bac80.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_0202ef0c();
int func_0203acf4();
int func_0203ad14();
int Unk044904_Get_data_0215ee98();
void func_02044ec4(void);
int func_0204fdac();

void Unk0bac80_Thunk_02044ec4(void);
u32 Unk0bac80_Unk_0badc0(void);
u32 Unk0bac80_Unk_0bae08(void);
int Unk0bac80_Unk_0bae18(void);
u32 Unk0bac80_Unk_0bae50(void);
u32 Unk0bac80_Unk_0bb298(void);
void Unk0bac80_Unk_0badd0(u32 arg0);
void Unk0bac80_Unk_0badec(u32 arg0);

/* forwards to `func_02044ec4` */
void Unk0bac80_Thunk_02044ec4(void) { func_02044ec4(); }

/* decompiler-derived */
u32 Unk0bac80_Unk_0badc0(void)
{
  int value;
  value = func_0203ad14();
  return *(u32 *)(value + 0xe8);
}

/* decompiler-derived */
u32 Unk0bac80_Unk_0bae08(void)
{
  int value;
  value = Unk0bac80_Unk_0badc0();
  return *(u32 *)(value + 0x68);
}

/* decompiler-derived */
int Unk0bac80_Unk_0bae18(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  return value + 0x8c;
}

/* decompiler-derived */
u32 Unk0bac80_Unk_0bae50(void)
{
  func_0202ef0c();
  func_0203acf4();
  return 1;
}

/* decompiler-derived */
u32 Unk0bac80_Unk_0bb298(void)
{
  int value;
  value = Unk0bac80_Unk_0badc0();
  func_0203acf4(*(u32 *)(value + 0x40));
  return 1;
}

/* decompiler-derived */
void Unk0bac80_Unk_0badd0(u32 arg0)
{
  int value;
  value = Unk0bac80_Unk_0badc0();
  func_0204fdac(*(u32 *)(value + 0x54),arg0);
}

/* decompiler-derived */
void Unk0bac80_Unk_0badec(u32 arg0)
{
  int value;
  value = Unk0bac80_Unk_0badc0();
  func_0204fdac(*(u32 *)(value + 0x60),arg0);
}
