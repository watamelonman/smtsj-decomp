/*
 * src/game/unit_020fedd4.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_0205b82c();
void func_0205bb68(void);
void func_020feef0(void);

void Unk0fedd4_Thunk_0205bb68(void);
void Unk0fedd4_Thunk_020feef0(void);
void Unk0fedd4_Unk_0fedd4(void);

/* forwards to `func_0205bb68` */
void Unk0fedd4_Thunk_0205bb68(void) { func_0205bb68(); }

/* forwards to `func_020feef0` */
void Unk0fedd4_Thunk_020feef0(void) { func_020feef0(); }

/* decompiler-derived */
void Unk0fedd4_Unk_0fedd4(void)
{
  func_0205b82c(0xd1);
}
