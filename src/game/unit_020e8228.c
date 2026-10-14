/*
 * src/game/unit_020e8228.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 data_02150c30[];
extern u32 data_02176ce0[];
void func_02045c38(void);
int func_02057524();
void func_02057534(void);
int func_02057eb8();
int func_02099d14();
int func_020a29a0();
int func_020e8374();
int func_020e849c();
int func_020e8d90();
int func_020e8e8c();
int func_020e9c00();

void func_020e93d4(void);
void func_020e8e60(void);
void func_020e8f68(void);
void func_020e8cd8(void);
void func_020e8e50(void);
void func_020e8e6c(void);
void func_020e8e7c(void);
void func_020e8eac(int arg0);
u32 func_020e9038(void);
void func_020e8398(void);
int func_020e8460(void);
int func_020e8474(void);
int func_020e8488(void);
void func_020e9c94(u32 arg0,u32 arg1);
u32 func_020e84e4(void);
void func_020e84fc(void);

/* empty callback */
void func_020e93d4(void) { }

/* forwards to `func_02057534` */
void func_020e8e60(void) { func_02057534(); }

/* forwards to `func_02045c38` */
void func_020e8f68(void) { func_02045c38(); }

/* decompiler-derived */
void func_020e8cd8(void)
{
  func_020a29a0(0xffffffff);
  return;
}

/* decompiler-derived */
void func_020e8e50(void)
{
  func_02057524(4);
  return;
}

/* decompiler-derived */
void func_020e8e6c(void)
{
  func_02057eb8(2);
  return;
}

/* decompiler-derived */
void func_020e8e7c(void)
{
  func_02057eb8(0xffffffff);
  return;
}

/* decompiler-derived */
void func_020e8eac(int arg0)
{
  func_020e8e8c(arg0 + 8);
  return;
}

/* decompiler-derived */
u32 func_020e9038(void)
{
  return *data_02176ce0;
}

/* decompiler-derived */
void func_020e8398(void)
{
  func_020e8d90(7,0xffffffff);
  return;
}

/* decompiler-derived */
int func_020e8460(void)
{
  return *(int *)(((int)data_02150c30) + 0x2c) + 1;
}

/* decompiler-derived */
int func_020e8474(void)
{
  return *(int *)(((int)data_02150c30) + 0x34) + 1;
}

/* decompiler-derived */
int func_020e8488(void)
{
  return *(int *)(((int)data_02150c30) + 0x3c) + 1;
}

/* decompiler-derived */
void func_020e9c94(u32 arg0,u32 arg1)
{
  func_020e9c00(arg0,2,arg1);
  return;
}

/* decompiler-derived */
u32 func_020e84e4(void)
{
  int tmp1;
  u32 tmp2;
  tmp1 = func_020e9038();
  if (tmp1 == 0) {
    tmp2 = 0;
  }
  else {
    tmp2 = *(u32 *)(tmp1 + 0x178);
  }
  return tmp2;
}

/* decompiler-derived */
void func_020e84fc(void)
{
  func_020e8374(8);
  func_020e849c();
  func_02099d14();
  return;
}
