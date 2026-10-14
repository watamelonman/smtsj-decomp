/*
 * src/game/unit_02122e1c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_0205caa8();
int Unk0cb32c_Unk_0cb57c();

void Unk122e1c_SetUnkFields64_b0(void *obj, u32 a, u32 b);
void Unk122e1c_Unk_122f88(int arg0,int arg1,u32 arg2);
u32 Unk122e1c_Unk_122f94(int arg0,int arg1);
void Unk122e1c_Unk_122fa0(int arg0,int arg1,u32 arg2);
void Unk122e1c_Unk_12331c(int arg0);
int Unk122e1c_Unk_122f54(int arg0);
int Unk122e1c_Unk_122f68(int arg0);
void Unk122e1c_Unk_12332c(int arg0);

/* set +0x64 and +0xb0 */
void Unk122e1c_SetUnkFields64_b0(void *obj, u32 a, u32 b) {
    FIELD(u32, obj, 0x64) = a;
    FIELD(u32, obj, 0xb0) = b;
}

/* decompiler-derived */
void Unk122e1c_Unk_122f88(int arg0,int arg1,u32 arg2)
{
  *(u32 *)(arg0 + arg1 * 4 + 0x78) = arg2;
  return;
}

/* decompiler-derived */
u32 Unk122e1c_Unk_122f94(int arg0,int arg1)
{
  return *(u32 *)(arg0 + arg1 * 4 + 0x78);
}

/* decompiler-derived */
void Unk122e1c_Unk_122fa0(int arg0,int arg1,u32 arg2)
{
  *(u32 *)(arg0 + arg1 * 4 + 200) = arg2;
  return;
}

/* decompiler-derived */
void Unk122e1c_Unk_12331c(int arg0)
{
  Unk0cb32c_Unk_0cb57c(*(u32 *)(arg0 + 0x14));
  return;
}

/* decompiler-derived */
int Unk122e1c_Unk_122f54(int arg0)
{
  return *(char *)(arg0 + 0x60) == '\0';
}

/* decompiler-derived */
int Unk122e1c_Unk_122f68(int arg0)
{
  return *(char *)(arg0 + 0x60) == '\b';
}

/* decompiler-derived */
void Unk122e1c_Unk_12332c(int arg0)
{
  func_0205caa8(*(u32 *)(arg0 + 0x14),1);
  return;
}
