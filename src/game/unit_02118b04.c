/*
 * src/game/unit_02118b04.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_02151b28[];
int func_0202e228();
void func_0206146c(void);
void func_02118974(void);

void Unk118b04_Nop_118b20(void);
void Unk118b04_Thunk_02118974(void);
void Unk118b04_Thunk_0206146c(void);
void Unk118b04_Set_data_02151b28(u32 arg0);
void Unk118b04_Unk_118b78(u32 arg0);
int Unk118b04_Unk_118b90(int arg0,int arg1);
u32 Unk118b04_Unk_118e74(int arg0);

/* empty callback */
void Unk118b04_Nop_118b20(void) { }

/* forwards to `func_02118974` */
void Unk118b04_Thunk_02118974(void) { func_02118974(); }

/* forwards to `func_0206146c` */
void Unk118b04_Thunk_0206146c(void) { func_0206146c(); }

/* decompiler-derived */
void Unk118b04_Set_data_02151b28(u32 arg0)
{
  *data_02151b28 = arg0;
}

/* decompiler-derived */
void Unk118b04_Unk_118b78(u32 arg0)
{
  u32 value;
  value = func_0202e228();
  Unk118b04_Unk_118b90(value,arg0);
}

/* decompiler-derived */
int Unk118b04_Unk_118b90(int arg0,int arg1)
{
  return (*(u8 *)(arg0 + arg1 + 0x94) & 1) != 0;
}

/* decompiler-derived */
u32 Unk118b04_Unk_118e74(int arg0)
{
  int value;
  value = func_0202e228();
  return *(u32 *)(value + arg0 * 4 + 0x14);
}



/* decompiler-derived */
int func_02118ba8(int arg0)
{
  int tmp1;
  tmp1 = func_0202e228();
  return (*(u8 *)(tmp1 + arg0 + 0x94) & 2) != 0;
}


/* decompiler-derived */
void func_02118e50(int arg0,int arg1)
{
  int tmp1;
  tmp1 = func_0202e228();
  *(int *)(tmp1 + 0x14 + arg0 * 4) = *(int *)(tmp1 + 0x14 + arg0 * 4) + arg1;
  return;
}

int func_02008848();
int func_02008904();
/* decompiler-derived */
void func_02119434(u32 arg0,u32 arg1)
{
  func_02008904(arg1,arg0,0x170);
  func_02008848(arg0,0,0xf);
  return;
}

