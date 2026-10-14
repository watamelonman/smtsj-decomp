/*
 * src/game/unit_021241ec.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_020fedd4();
int func_020fede4();
int func_020fedf0();
int func_020fee18();
int func_020fee68();
int func_020fee84();
void func_02124338(void);

void func_0212424c(void);
void func_02124214(void);
void func_021241ec(void);

/* forwards to `func_02124338` */
void func_0212424c(void) { func_02124338(); }

/* decompiler-derived */
void func_02124214(void)
{
  func_020fee18();
  func_020fede4();
  return;
}

/* decompiler-derived */
void func_021241ec(void)
{
  func_020fedd4();
  func_020fedf0(1);
  func_020fee68(0,0x2b);
  func_020fee84(5);
  return;
}
