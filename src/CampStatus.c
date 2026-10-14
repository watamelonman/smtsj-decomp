/*
 * src/CampStatus.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))



u32 func_020d3508(void *obj);
u32 func_020dcb5c(int arg0);

/* get u32 at +0x1c */
u32 func_020d3508(void *obj) { return FIELD(u32, obj, 0x1c); }

/* decompiler-derived */
u32 func_020dcb5c(int arg0)
{
  return *(u32 *)(arg0 + 0x7494);
}
