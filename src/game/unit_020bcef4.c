/*
 * src/game/unit_020bcef4.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_020bd30c();
int func_020bd49c();
int func_020bd584();
int func_020bd614();

void func_020bd2fc(u32 arg0,u32 arg1);
void func_020bd388(u32 arg0,u32 *arg1);
void func_020bd470(u32 *arg0);
void func_020bd5c4(u32 arg0);
void func_020bd3e0(int arg0);
void func_020bd480(int *arg0,int arg1);

/* decompiler-derived */
void func_020bd2fc(u32 arg0,u32 arg1)
{
  func_020bd30c(arg0,arg1,0);
  return;
}

/* decompiler-derived */
void func_020bd388(u32 arg0,u32 *arg1)
{
  func_020bd584(arg0,*arg1);
  return;
}

/* decompiler-derived */
void func_020bd470(u32 *arg0)
{
  func_020bd614(*arg0);
  return;
}

/* decompiler-derived */
void func_020bd5c4(u32 arg0)
{
  func_020bd49c(arg0,2);
  return;
}

/* decompiler-derived */
void func_020bd3e0(int arg0)
{
  int tmp1;
  tmp1 = *(int *)(arg0 + 4) + 1;
  *(int *)(arg0 + 4) = tmp1;
  if (1 < tmp1) {
    *(u32 *)(arg0 + 4) = 1;
  }
  return;
}

/* decompiler-derived */
void func_020bd480(int *arg0,int arg1)
{
  *arg0 = arg1;
  if ((arg1 == 1 || arg1 == 4) || arg1 == 6) {
    arg0[1] = 1;
  }
  return;
}
