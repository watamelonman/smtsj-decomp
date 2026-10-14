/*
 * src/game/unit_020bac80.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_0202ef0c();
int func_0203acf4();
int Unk03aae8_Unk_03ad14();
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
  value = Unk03aae8_Unk_03ad14();
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


int func_02049d80();
/* decompiler-derived */
u32 Unk0bac80_Unk_0bae34(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  func_02049d80(value,2);
  func_0203acf4();
  return 1;
}

int func_02049f24();
/* decompiler-derived */
u32 Unk0bac80_Unk_0bae64(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  func_02049f24(value,0);
  func_0203acf4();
  return 1;
}


/* decompiler-derived */
u32 Unk0bac80_Unk_0bae80(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  func_02049d80(value,0);
  func_0203acf4();
  return 1;
}


/* decompiler-derived */
u32 Unk0bac80_Unk_0baf6c(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  func_02049d80(value,1);
  func_0203acf4();
  return 1;
}


/* decompiler-derived */
u32 Unk0bac80_Unk_0baf88(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  func_02049f24(value,1);
  func_0203acf4();
  return 1;
}


/* decompiler-derived */
u32 Unk0bac80_Unk_0bb078(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  func_02049d80(value,3);
  func_0203acf4();
  return 1;
}


/* decompiler-derived */
u32 Unk0bac80_Unk_0bb094(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  func_02049d80(value,4);
  func_0203acf4();
  return 1;
}


/* decompiler-derived */
u32 Unk0bac80_Unk_0bb0b0(void)
{
  u32 value;
  value = Unk0bac80_Unk_0bae18();
  func_02049d80(value,5);
  func_0203acf4();
  return 1;
}



/* decompiler-derived */
u32 func_020bb0cc(void)
{
  u32 tmp1;
  tmp1 = Unk0bac80_Unk_0bae18();
  func_02049d80(tmp1,6);
  func_0203acf4();
  return 1;
}


/* decompiler-derived */
u32 func_020bb0e8(void)
{
  u32 tmp1;
  tmp1 = Unk0bac80_Unk_0bae18();
  func_02049d80(tmp1,7);
  func_0203acf4();
  return 1;
}

int func_0202e788();
int func_020bac80();
/* decompiler-derived */
void func_020bacf8(u32 arg0)
{
  int tmp1;
  tmp1 = func_0202e788();
  func_020bac80(arg0,*(u16 *)(tmp1 + 0x35c) + 1);
  return;
}


/* decompiler-derived */
void func_020bad1c(u32 arg0)
{
  int tmp1;
  tmp1 = func_0202e788();
  func_020bac80(arg0,*(u16 *)(tmp1 + 0x35c) - 1);
  return;
}

int func_0203ac00();
/* decompiler-derived */
u32 func_020bb104(void)
{
  int tmp1;
  int tmp2;
  tmp1 = func_0203ac00(0);
  if (tmp1 < 0xf) {
    tmp2 = func_0202e788();
    func_0203acf4(*(u16 *)(tmp2 + tmp1 * 2 + 0x386));
  }
  else {
    func_0203acf4(0);
  }
  return 1;
}
