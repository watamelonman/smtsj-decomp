/*
 * src/game/unit_020de678.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_021508d4[];
int func_02044428();
int func_02044534();
int func_020e666c();
void func_02124e04(void);

void func_020df05c(void);
void func_020df060(void);
void func_020df578(void);
u32 func_020de950(void);
void func_020dea60(void);
void func_020df598(void);
void func_020df5a8(void);
void func_020dee2c(int arg0);

/* empty callback */
void func_020df05c(void) { }

/* empty callback */
void func_020df060(void) { }

/* forwards to `func_02124e04` */
void func_020df578(void) { func_02124e04(); }

/* decompiler-derived */
u32 func_020de950(void)
{
  return *data_021508d4;
}

/* decompiler-derived */
void func_020dea60(void)
{
  func_02044534(0x1f);
  return;
}

/* decompiler-derived */
void func_020df598(void)
{
  func_02044428(0x20);
  return;
}

/* decompiler-derived */
void func_020df5a8(void)
{
  func_02044534(0x20);
  return;
}

/* decompiler-derived */
void func_020dee2c(int arg0)
{
  func_020e666c(arg0 + 0x5f1);
  return;
}
