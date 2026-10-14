/*
 * src/game/unit_0209a268.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_0209a48c();
int func_0209a4a0();
int func_0209bb68();
int func_0209c484();

void Unk09a268_Nop_09b3c8(void);
void Unk09a268_Unk_09a7fc(u32 arg0);
void Unk09a268_Unk_09a820(u32 arg0);
void Unk09a268_Unk_09c498(void);
void Unk09a268_Unk_09a80c(u32 arg0,u32 arg1);
void Unk09a268_Unk_09a830(u32 arg0,u32 arg1);
void Unk09a268_Unk_09a870(u32 arg0,u32 arg1);

/* empty callback */
void Unk09a268_Nop_09b3c8(void) { }

/* decompiler-derived */
void Unk09a268_Unk_09a7fc(u32 arg0)
{
  func_0209a48c(arg0,3);
}

/* decompiler-derived */
void Unk09a268_Unk_09a820(u32 arg0)
{
  func_0209a48c(arg0,4);
}

/* decompiler-derived */
void Unk09a268_Unk_09c498(void)
{
  func_0209bb68();
  func_0209c484();
}

/* decompiler-derived */
void Unk09a268_Unk_09a80c(u32 arg0,u32 arg1)
{
  func_0209a4a0(arg0,3,arg1);
}

/* decompiler-derived */
void Unk09a268_Unk_09a830(u32 arg0,u32 arg1)
{
  func_0209a4a0(arg0,4,arg1);
}

/* decompiler-derived */
void Unk09a268_Unk_09a870(u32 arg0,u32 arg1)
{
  func_0209a4a0(arg0,5,arg1);
}
