/*
 * src/game/unit_02118b04.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_02151b28[];
int func_0202e228();
void func_0206146c(void);
void func_02118974(void);

void func_02118b20(void);
void func_02118b14(void);
void func_02118b24(void);
void func_02118b04(u32 arg0);
void func_02118b78(u32 arg0);
int func_02118b90(int arg0,int arg1);
u32 func_02118e74(int arg0);

/* empty callback */
void func_02118b20(void) { }

/* forwards to `func_02118974` */
void func_02118b14(void) { func_02118974(); }

/* forwards to `func_0206146c` */
void func_02118b24(void) { func_0206146c(); }

/* decompiler-derived */
void func_02118b04(u32 arg0)
{
  *data_02151b28 = arg0;
  return;
}

/* decompiler-derived */
void func_02118b78(u32 arg0)
{
  u32 tmp1;
  tmp1 = func_0202e228();
  func_02118b90(tmp1,arg0);
  return;
}

/* decompiler-derived */
int func_02118b90(int arg0,int arg1)
{
  return (*(u8 *)(arg0 + arg1 + 0x94) & 1) != 0;
}

/* decompiler-derived */
u32 func_02118e74(int arg0)
{
  int tmp1;
  tmp1 = func_0202e228();
  return *(u32 *)(tmp1 + arg0 * 4 + 0x14);
}
