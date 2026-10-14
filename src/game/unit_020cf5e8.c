/*
 * src/game/unit_020cf5e8.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct Unk0cf5e8Work {
    u8 unk_0000[0xa0];
    s32 UnkField00a0;
    u8 unk_00a4[0xf0];
    s32 UnkField0194;
    u8 unk_0198[0xf0];
    s32 UnkField0288;
    s32 UnkField028c;
} Unk0cf5e8Work;


void Unk1241ec_Thunk_02124338(void);
void func_02124258(void);

void Unk0cf5e8_Nop_0cf62c(void);
void Unk0cf5e8_Nop_0d11e8(void);
void Unk0cf5e8_Nop_0d11ec(void);
void Unk0cf5e8_Thunk_02124258(void);
void Unk0cf5e8_Thunk_0212424c(void);
int Unk0cf5e8_Unk_0d139c(Unk0cf5e8Work *work);
int Unk0cf5e8_Unk_0d13fc(Unk0cf5e8Work *work);

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
int Unk0cf5e8_Unk_0d139c(Unk0cf5e8Work *work)
{
  return work->UnkField028c < work->UnkField0194;
}

/* decompiler-derived */
int Unk0cf5e8_Unk_0d13fc(Unk0cf5e8Work *work)
{
  return work->UnkField0288 < work->UnkField00a0;
}
