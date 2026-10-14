/*
 * src/game/unit_02094fe0.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 data_02175dac[];
void func_0202e8cc(void);

void func_02095000(void);
int func_02095004(int arg0);
u32 func_020953bc(void *obj);
void func_02094fe0(void);
int func_02094fec(int arg0);

/* empty callback */
void func_02095000(void) { }

/* decompiler-derived */
int func_02095004(int arg0)
{
  return arg0 + 0x990;
}

/* get u32 at +0x9a0 */
u32 func_020953bc(void *obj) { return FIELD(u32, obj, 0x9a0); }

/* forwards to `func_0202e8cc` */
void func_02094fe0(void) { func_0202e8cc(); }

/* decompiler-derived */
int func_02094fec(int arg0)
{
  return arg0 * 0x1c + ((int)data_02175dac);
}
