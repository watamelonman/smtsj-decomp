/*
 * src/game/unit_020cf5e8.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

void Unk1241ec_Thunk_02124338(void);
void func_02124258(void);

void Unk0cf5e8_Nop_0cf62c(void);
void Unk0cf5e8_Nop_0d11e8(void);
void Unk0cf5e8_Nop_0d11ec(void);
void Unk0cf5e8_Thunk_02124258(void);
void Unk0cf5e8_Thunk_0212424c(void);
int Unk0cf5e8_Unk_0d139c(int arg0);
int Unk0cf5e8_Unk_0d13fc(int arg0);

/* empty callback */
void Unk0cf5e8_Nop_0cf62c(void) { }

/* empty callback */
void Unk0cf5e8_Nop_0d11e8(void) { }

/* empty callback */
void Unk0cf5e8_Nop_0d11ec(void) { }

/* forwards to `func_02124258` */
void Unk0cf5e8_Thunk_02124258(void) { func_02124258(); }

/* forwards to `Unk1241ec_Thunk_02124338` */
void Unk0cf5e8_Thunk_0212424c(void) { Unk1241ec_Thunk_02124338(); }

/* decompiler-derived */
int Unk0cf5e8_Unk_0d139c(int arg0)
{
  return *(int *)(arg0 + 0x28c) < *(int *)(arg0 + 0x194);
}

/* decompiler-derived */
int Unk0cf5e8_Unk_0d13fc(int arg0)
{
  return *(int *)(arg0 + 0x288) < *(int *)(arg0 + 0xa0);
}
