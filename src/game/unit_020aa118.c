/*
 * src/game/unit_020aa118.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_0204509c();
void func_020af8d8(void);

void Unk0aa118_Nop_0ae054(void);
void Unk0aa118_Thunk_020af8d8(void);
void Unk0aa118_Unk_0ab454(void);
int Unk0aa118_Unk_0ab4b8(void);

/* empty callback */
void Unk0aa118_Nop_0ae054(void) { }

/* forwards to `func_020af8d8` */
void Unk0aa118_Thunk_020af8d8(void) { func_020af8d8(); }

/* decompiler-derived */
void Unk0aa118_Unk_0ab454(void)
{
  int value;
  value = func_0204509c();
  *(u32 *)(value + 0x18) = 0;
}

/* decompiler-derived */
int Unk0aa118_Unk_0ab4b8(void)
{
  int value;
  value = func_0204509c();
  return *(int *)(value + 0x18) != 0;
}
