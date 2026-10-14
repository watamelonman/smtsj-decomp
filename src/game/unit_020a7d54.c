/*
 * src/game/unit_020a7d54.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_020a7e8c();
int func_020a855c();

void Unk0a7d54_SetUnkField8(void *obj, u32 value);
void Unk0a7d54_Unk_0a9158(int arg0);
void Unk0a7d54_Unk_0a7eb8(int arg0,u32 arg1);
u32 Unk0a7d54_Unk_0a8648(int arg0);
int Unk0a7d54_Unk_0a9204(int arg0);
void Unk0a7d54_Unk_0a8594(void);
void Unk0a7d54_Unk_0a7ec8(u32 arg0,u32 arg1,u32 arg2);

/* set u32 at +0x8 */
void Unk0a7d54_SetUnkField8(void *obj, u32 value) { FIELD(u32, obj, 0x8) = value; }

/* decompiler-derived */
void Unk0a7d54_Unk_0a9158(int arg0)
{
  *(u32 *)(arg0 + 4) = 1;
}

/* decompiler-derived */
void Unk0a7d54_Unk_0a7eb8(int arg0,u32 arg1)
{
  *(u8 *)(arg0 + 0xd) = 1;
  *(u32 *)(arg0 + 0x1c) = arg1;
}

/* decompiler-derived */
u32 Unk0a7d54_Unk_0a8648(int arg0)
{
  u32 value;
  if (arg0 == 0) {
    value = 0;
  }
  else {
    value = *(u32 *)(arg0 + 4);
  }
  return value;
}

/* decompiler-derived */
int Unk0a7d54_Unk_0a9204(int arg0)
{
  return *(int *)(arg0 + 0x20) != 0;
}

/* decompiler-derived */
void Unk0a7d54_Unk_0a8594(void)
{
  int value;
  value = func_020a855c();
  if (value == 0) {
    return;
  }
  func_020a7e8c();
}

/* decompiler-derived */
void Unk0a7d54_Unk_0a7ec8(u32 arg0,u32 arg1,u32 arg2)
{
  int value;
  value = func_020a855c();
  if (value == 0) {
    return;
  }
  Unk0a7d54_Unk_0a7eb8(value,arg2);
}
