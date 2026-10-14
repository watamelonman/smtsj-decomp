/*
 * src/BattleShowingTask.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_02176e70[];
int func_020a0d30();
int func_02119658();

void func_0211982c(void);
void func_02119830(void);
void func_0211984c(void);
void func_02119850(void);
u32 func_02119854(void *obj);
void func_02119834(void);
void func_021196e0(u32 *arg0);
u32 func_0211c230(int arg0);

/* empty callback */
void func_0211982c(void) { }

/* empty callback */
void func_02119830(void) { }

/* empty callback */
void func_0211984c(void) { }

/* empty callback */
void func_02119850(void) { }

/* get u32 at +0x28 */
u32 func_02119854(void *obj) { return FIELD(u32, obj, 0x28); }

/* decompiler-derived */
void func_02119834(void)
{
  u32 tmp1;
  tmp1 = func_02119658();
  *data_02176e70 = tmp1;
  return;
}

/* decompiler-derived */
void func_021196e0(u32 *arg0)
{
  *arg0 = 0;
  arg0[1] = 0;
  func_020a0d30(1);
  return;
}

/* decompiler-derived */
u32 func_0211c230(int arg0)
{
  u32 tmp1;
  if (*(int *)(arg0 + 0xc) < *(int *)(arg0 + 8)) {
    tmp1 = *(u32 *)(*(int *)(arg0 + 4) + *(int *)(arg0 + 0xc) * 4);
  }
  else {
    tmp1 = 0;
  }
  return tmp1;
}
