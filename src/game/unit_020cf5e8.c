/*
 * src/game/unit_020cf5e8.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

void func_0212424c(void);
void func_02124258(void);

void func_020cf62c(void);
void func_020d11e8(void);
void func_020d11ec(void);
void func_020d11d0(void);
void func_020d11dc(void);
int func_020d139c(int arg0);
int func_020d13fc(int arg0);

/* empty callback */
void func_020cf62c(void) { }

/* empty callback */
void func_020d11e8(void) { }

/* empty callback */
void func_020d11ec(void) { }

/* forwards to `func_02124258` */
void func_020d11d0(void) { func_02124258(); }

/* forwards to `func_0212424c` */
void func_020d11dc(void) { func_0212424c(); }

/* decompiler-derived */
int func_020d139c(int arg0)
{
  return *(int *)(arg0 + 0x28c) < *(int *)(arg0 + 0x194);
}

/* decompiler-derived */
int func_020d13fc(int arg0)
{
  return *(int *)(arg0 + 0x288) < *(int *)(arg0 + 0xa0);
}
