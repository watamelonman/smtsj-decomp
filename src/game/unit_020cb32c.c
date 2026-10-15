/*
 * src/game/unit_020cb32c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_0205e484();
int func_020cb3dc();
void Unk0cb32c_Unk_0cb4e4(u32 arg0,u32 arg1);
int Unk0cb32c_Unk_0cb564();
int func_02122a78();
int Unk122a78_Unk_122aa0();
int Unk1241ec_Unk_1241ec();
int Unk1241ec_Unk_124214();
int Unk1241ec_Thunk_02124338();
int Unk1241ec_Unk_124258();

void Unk0cb32c_Nop_0cba74(void);
void Unk0cb32c_Nop_0cccc0(void);
void Unk0cb32c_Unk_0cb35c(u32 arg0);
void Unk0cb32c_Unk_0cb57c(u32 arg0);
u32 Unk0cb32c_Unk_0cb32c(void);
u32 Unk0cb32c_Unk_0cb344(void);
void Unk0cb32c_Unk_0cb54c(void);

/* empty callback */
void Unk0cb32c_Nop_0cba74(void) { }

/* empty callback */
void Unk0cb32c_Nop_0cccc0(void) { }

/* decompiler-derived */
void Unk0cb32c_Unk_0cb35c(u32 arg0)
{
  func_0205e484(arg0,0x1e);
}

/* decompiler-derived */
void Unk0cb32c_Unk_0cb57c(u32 arg0)
{
  Unk0cb32c_Unk_0cb564(arg0,0);
}

/* decompiler-derived */
u32 Unk0cb32c_Unk_0cb32c(void)
{
  func_02122a78();
  Unk1241ec_Thunk_02124338();
  Unk1241ec_Unk_1241ec();
  return 1;
}

/* decompiler-derived */
u32 Unk0cb32c_Unk_0cb344(void)
{
  Unk1241ec_Unk_124214();
  Unk1241ec_Unk_124258();
  Unk122a78_Unk_122aa0();
  return 1;
}

/* decompiler-derived */
void Unk0cb32c_Unk_0cb54c(void)
{
  u8 value;
  value = func_020cb3dc();
  Unk0cb32c_Unk_0cb4e4(value,0);
}


int func_020cca80();
/* decompiler-derived */
void Unk0cb32c_Unk_0ccaa8(int *arg0,int arg1)
{
  if (arg1 == 2) {
    func_020cca80();
  }
  *arg0 = arg1;
}

int Unk095560_Unk_0956c8();
int Unk0bc1a8_Unk_0bc9b4();
int Unk0de678_Unk_0de870();
/* decompiler-derived */
void Unk0cb32c_Unk_0cba78(void)
{
  int value;
  value = Unk0de678_Get_data_021508d4();
  if (value == 0) {
    Unk0bc1a8_Unk_0bc9b4(0xf,0);
    Unk0cb32c_Unk_0cb344();
  }
  Unk0de678_Unk_0de870();
  Unk095560_Unk_0956c8();
}


int func_02122e1c();
/* decompiler-derived */
void Unk0cb32c_Unk_0cb754(u32 *arg0)
{
  Unk0bc1a8_Unk_0bc9b4(10,0);
  func_02122e1c(*arg0);
  *arg0 = 0;
  ImageBg_Unk_0e5530();
  Unk0fd268_Unk_0fd3ac();
  Unk0cb32c_Unk_0cb344();
  Unk0de678_Unk_0de870();
}


/* decompiler-derived */
u32 Unk0cb32c_Unk_0cb440(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 6;
  case 1:
    return 8;
  case 2:
    return 7;
  case 3:
    return 9;
  case 4:
    return 5;
  default:
    return arg0;
  }
}

int func_02059f70();
int func_02060dd4();
/* decompiler-derived */
void Unk0cb32c_Unk_0cb488(u32 *arg0,u32 arg1,u32 arg2,u32 arg3,
                  u32 arg4,u32 arg5)
{
  u8 auStack_24 [16];
  u32 uStack_14;
  uStack_14 = arg3;
  func_02060dd4(auStack_24,arg0,0,arg3,arg4);
  func_02059f70(*arg0,0,arg1,arg2,auStack_24,0,arg5);
}

int func_020445f4();
int func_0204fed8();
/* decompiler-derived */
void Unk0cb32c_Unk_0cb4e4(u32 arg0,u32 arg1)
{
  u32 tmp1;
  tmp1 = func_020445f4(0x1e,arg0);
  func_0204fed8(tmp1,arg1);
}

int func_020a0da4();
/* decompiler-derived */
void Unk0cb32c_Unk_0ccac8(int arg0,u32 arg1)
{
  func_020a0da4(5);
  *(u32 *)(arg0 + 8) = 4;
  Unk0cb32c_Unk_0ccaa8((int *)arg0, (int)0xd);
  *(u32 *)(arg0 + 0xc) = arg1;
}

/* decompiler-derived */
void Unk0cb32c_Unk_0ccaf8(int arg0,u32 arg1)
{
  Unk122e1c_Unk_123294(*(u32 *)(arg0 + 0x94));
  *(u32 *)(arg0 + 0xd8) = arg1;
  *(u32 *)(arg0 + 8) = 1;
  Unk0cb32c_Unk_0ccaa8((int *)arg0, (int)3);
}

int func_0205c41c();
int func_0205c6ec();
/* decompiler-derived */
int Unk0cb32c_Unk_0cb564(u32 arg0)
{
  func_0205c41c();
  func_0205c6ec(arg0);
}
