/*
 * src/game/unit_020a7d54.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_020a7e8c();
int func_020a855c();

void func_020a9164(void *obj, u32 value);
void func_020a9158(int arg0);
void func_020a7eb8(int arg0,u32 arg1);
u32 func_020a8648(int arg0);
int func_020a9204(int arg0);
void func_020a8594(void);
void func_020a7ec8(u32 arg0,u32 arg1,u32 arg2);

/* set u32 at +0x8 */
void func_020a9164(void *obj, u32 value) { FIELD(u32, obj, 0x8) = value; }

/* decompiler-derived */
void func_020a9158(int arg0)
{
  *(u32 *)(arg0 + 4) = 1;
  return;
}

/* decompiler-derived */
void func_020a7eb8(int arg0,u32 arg1)
{
  *(u8 *)(arg0 + 0xd) = 1;
  *(u32 *)(arg0 + 0x1c) = arg1;
  return;
}

/* decompiler-derived */
u32 func_020a8648(int arg0)
{
  u32 tmp1;
  if (arg0 == 0) {
    tmp1 = 0;
  }
  else {
    tmp1 = *(u32 *)(arg0 + 4);
  }
  return tmp1;
}

/* decompiler-derived */
int func_020a9204(int arg0)
{
  return *(int *)(arg0 + 0x20) != 0;
}

/* decompiler-derived */
void func_020a8594(void)
{
  int tmp1;
  tmp1 = func_020a855c();
  if (tmp1 == 0) {
    return;
  }
  func_020a7e8c();
  return;
}

/* decompiler-derived */
void func_020a7ec8(u32 arg0,u32 arg1,u32 arg2)
{
  int tmp1;
  tmp1 = func_020a855c();
  if (tmp1 == 0) {
    return;
  }
  func_020a7eb8(tmp1,arg2);
  return;
}
