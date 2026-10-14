/*
 * src/game/unit_020f8448.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

void func_020bcc7c(void);
void func_020bccec(void);

u32 func_020f8448(void *obj);
u32 func_020f8450(void *obj);
u32 func_020f8458(void *obj);
u32 func_020f8460(void *obj);
void func_020f84a8(void);
void func_020f84b4(void);
int func_020f8468(int arg0);

/* get u32 at +0x10 */
u32 func_020f8448(void *obj) { return FIELD(u32, obj, 0x10); }

/* get u32 at +0x0 */
u32 func_020f8450(void *obj) { return FIELD(u32, obj, 0x0); }

/* get u32 at +0x4 */
u32 func_020f8458(void *obj) { return FIELD(u32, obj, 0x4); }

/* get u32 at +0x8 */
u32 func_020f8460(void *obj) { return FIELD(u32, obj, 0x8); }

/* forwards to `func_020bcc7c` */
void func_020f84a8(void) { func_020bcc7c(); }

/* forwards to `func_020bccec` */
void func_020f84b4(void) { func_020bccec(); }

/* decompiler-derived */
int func_020f8468(int arg0)
{
  return *(int *)(arg0 + 0x10) - *(int *)(arg0 + 8);
}
