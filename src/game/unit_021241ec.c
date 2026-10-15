/*
 * src/game/unit_021241ec.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int Unk0fedd4_Unk_0fedd4();
int Unk0fedd4_Thunk_0205bb68();
int Unk0fedd4_Alloc();
int Unk0fedd4_Unk_0fee18();
int Unk0fedd4_SetUnk0c10();
int Unk0fedd4_SetUnk1c();
void func_02124338(void);

void Unk1241ec_Thunk_02124338(void);
void Unk1241ec_Unk_124214(void);
void Unk1241ec_Unk_1241ec(void);

/* forwards to `func_02124338` */
void Unk1241ec_Thunk_02124338(void) { func_02124338(); }

/* decompiler-derived */
void Unk1241ec_Unk_124214(void)
{
  Unk0fedd4_Unk_0fee18();
  Unk0fedd4_Thunk_0205bb68();
}

/* decompiler-derived */
void Unk1241ec_Unk_1241ec(void)
{
  Unk0fedd4_Unk_0fedd4();
  Unk0fedd4_Alloc(1);
  Unk0fedd4_SetUnk0c10(0,0x2b);
  Unk0fedd4_SetUnk1c(5);
}


extern u32 data_02176e84[];
int func_02061424();
int func_020cb3dc();
int Unk0cb32c_Unk_0cb4e4();
void Unk0fedd4_Unk_0fee38();
void Unk1241ec_Unk_124224(int x)
{
    Unk0fedd4_Unk_0fee38(Unk0cb32c_Unk_0cb4e4((u8)func_020cb3dc(), (u16)(x + 200)));
}

/* decompiler-derived */
void Unk1241ec_Unk_124258(void)
{
  if (*data_02176e84 == 0) {
    return;
  }
  func_02061424();
  *data_02176e84 = 0;
}

/* decompiler-derived */
void Unk1241ec_Unk_124284(u32 arg0)
{
  if (*data_02176e84 != 0) {
    *(u32 *)(*data_02176e84 + 0x28) = arg0;
  }
}

/* decompiler-derived */
void Unk1241ec_Unk_12429c(u32 arg0)
{
  if (*data_02176e84 != 0) {
    *(u32 *)(*data_02176e84 + 0x2c) = arg0;
  }
}

/* decompiler-derived */
void Unk1241ec_Unk_1242b4(u32 arg0)
{
  if (*data_02176e84 != 0) {
    *(u32 *)(*data_02176e84 + 0x30) = arg0;
  }
}

/* decompiler-derived */
void Unk1241ec_Unk_1242cc(u32 arg0)
{
  if (*data_02176e84 != 0) {
    *(u32 *)(*data_02176e84 + 0x34) = arg0;
  }
}

/* decompiler-derived */
void Unk1241ec_Unk_1242e4(u32 arg0)
{
  if (*data_02176e84 != 0) {
    *(u32 *)(*data_02176e84 + 0x38) = arg0;
  }
}
