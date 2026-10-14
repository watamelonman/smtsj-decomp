/*
 * src/game/unit_020de678.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_021508d4[];
int func_02044428();
int func_02044534();
int Unk0e651c_Unk_0e666c();
void func_02124e04(void);

void Unk0de678_Nop_0df05c(void);
void Unk0de678_Nop_0df060(void);
void Unk0de678_Thunk_02124e04(void);
u32 Unk0de678_Get_data_021508d4(void);
void Unk0de678_Unk_0dea60(void);
void Unk0de678_Unk_0df598(void);
void Unk0de678_Unk_0df5a8(void);
void Unk0de678_Unk_0dee2c(int arg0);

/* empty callback */
void Unk0de678_Nop_0df05c(void) { }

/* empty callback */
void Unk0de678_Nop_0df060(void) { }

/* forwards to `func_02124e04` */
void Unk0de678_Thunk_02124e04(void) { func_02124e04(); }

/* decompiler-derived */
u32 Unk0de678_Get_data_021508d4(void)
{
  return *data_021508d4;
}

/* decompiler-derived */
void Unk0de678_Unk_0dea60(void)
{
  func_02044534(0x1f);
}

/* decompiler-derived */
void Unk0de678_Unk_0df598(void)
{
  func_02044428(0x20);
}

/* decompiler-derived */
void Unk0de678_Unk_0df5a8(void)
{
  func_02044534(0x20);
}

/* decompiler-derived */
void Unk0de678_Unk_0dee2c(int arg0)
{
  Unk0e651c_Unk_0e666c(arg0 + 0x5f1);
}



/* decompiler-derived */
void Unk0de678_Unk_0df584(void)
{
  *(u32 *)(((int)data_021508d4) + 0x2c) = 1;
}

int func_0205bb68();
int func_020a2414();
int func_020fc6a0();
/* decompiler-derived */
void Unk0de678_Unk_0df0a4(void)
{
  func_020a2414();
  func_02044534(0x1e);
  Unk065e88_Unk_065eac();
  Unk0de678_Unk_0df5a8();
  func_020fc6a0();
  func_0205bb68();
  Unk095560_Unk_096130();
}
