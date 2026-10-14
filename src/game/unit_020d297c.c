/*
 * src/game/unit_020d297c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

void func_02095398(void);
void func_020953ac(void);
void Unk0e5fb8_Unk_0e6448(void);
void Unk0e5fb8_Unk_0e64c8(void);
int func_020e651c();

void Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e6448(void);
void Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e64c8(void);
void Unk0d297c_Thunk_02095398(void);
void Unk0d297c_Thunk_020953ac(void);
void Unk0d297c_Unk_0d2adc(u32 arg0);
u16 Unk0d297c_Unk_0d32e8(int *arg0,int arg1);
int Unk0d297c_Unk_0d32f8(int *arg0);

/* forwards to `Unk0e5fb8_Unk_0e6448` */
void Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e6448(void) { Unk0e5fb8_Unk_0e6448(); }

/* forwards to `Unk0e5fb8_Unk_0e64c8` */
void Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e64c8(void) { Unk0e5fb8_Unk_0e64c8(); }

/* forwards to `func_02095398` */
void Unk0d297c_Thunk_02095398(void) { func_02095398(); }

/* forwards to `func_020953ac` */
void Unk0d297c_Thunk_020953ac(void) { func_020953ac(); }

/* decompiler-derived */
void Unk0d297c_Unk_0d2adc(u32 arg0)
{
  func_020e651c(arg0,0);
}

/* decompiler-derived */
u16 Unk0d297c_Unk_0d32e8(int *arg0,int arg1)
{
  return *(u16 *)(*arg0 + arg1 * 2);
}

/* decompiler-derived */
int Unk0d297c_Unk_0d32f8(int *arg0)
{
  return *arg0 + arg0[3] * 2;
}
