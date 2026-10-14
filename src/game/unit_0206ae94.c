/*
 * src/game/unit_0206ae94.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_021457e0[];
int func_02052d34();
int func_02052d58();

u32 Unk06ae94_GetUnkField4c(void *obj);
void Unk06ae94_Unk_06c8e0(int arg0,u32 arg1,u32 arg2);
void Unk06ae94_Unk_06ae94(u32 arg0);
void Unk06ae94_Unk_06aeb4(u32 arg0);

/* get u32 at +0x4c */
u32 Unk06ae94_GetUnkField4c(void *obj) { return FIELD(u32, obj, 0x4c); }

/* decompiler-derived */
void Unk06ae94_Unk_06c8e0(int arg0,u32 arg1,u32 arg2)
{
  *(u32 *)(arg0 + 0x34) = *(u32 *)(arg0 + 0x34) | 4;
  *(u32 *)(arg0 + 0x3c) = arg2;
  *(u32 *)(arg0 + 0x40) = arg1;
  return;
}

/* decompiler-derived */
void Unk06ae94_Unk_06ae94(u32 arg0)
{
  if ((*data_021457e0 & arg0) == 0) {
    return;
  }
  func_02052d34();
  return;
}

/* decompiler-derived */
void Unk06ae94_Unk_06aeb4(u32 arg0)
{
  if ((*data_021457e0 & arg0) == 0) {
    return;
  }
  func_02052d58();
  return;
}
