/*
 * src/game/unit_020946e0.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 data_02175d94[];
int func_02008848();
int func_02052ff0();
void func_02053000(void);
int func_02057628();
int func_02057678();

int Unk0946e0_Unk_0948fc(int arg0);
void Unk0946e0_Thunk_02053000(void);
u32 Unk0946e0_GetAddr_data_02175d94(void);
void Unk0946e0_Unk_094ae0(int *arg0);
u32 Unk0946e0_Unk_0946e0(void);
void Unk0946e0_Unk_094c50(int *arg0);
void Unk0946e0_Unk_094a64(u32 arg0);

/* decompiler-derived */
int Unk0946e0_Unk_0948fc(int arg0)
{
  return arg0 + 4;
}

/* forwards to `func_02053000` */
void Unk0946e0_Thunk_02053000(void) { func_02053000(); }

/* decompiler-derived */
u32 Unk0946e0_GetAddr_data_02175d94(void)
{
  return ((int)data_02175d94);
}

/* decompiler-derived */
void Unk0946e0_Unk_094ae0(int *arg0)
{
  int tmp1;
  tmp1 = Unk0946e0_GetAddr_data_02175d94();
  *arg0 = (int)*(short *)(tmp1 + 0x10);
  return;
}

/* decompiler-derived */
u32 Unk0946e0_Unk_0946e0(void)
{
  u32 tmp1;
  tmp1 = func_02052ff0(0xc);
  func_02008848(tmp1,0,0xc);
  return tmp1;
}

/* decompiler-derived */
void Unk0946e0_Unk_094c50(int *arg0)
{
  short *v1;
  int tmp2;
  v1 = (short *)Unk0946e0_GetAddr_data_02175d94();
  *arg0 = (int)*v1;
  tmp2 = Unk0946e0_GetAddr_data_02175d94();
  arg0[1] = (int)*(short *)(tmp2 + 2);
  return;
}

/* decompiler-derived */
void Unk0946e0_Unk_094a64(u32 arg0)
{
  int tmp1;
  tmp1 = Unk0946e0_GetAddr_data_02175d94();
  func_02057678(arg0,*(u32 *)(tmp1 + 4),*(u32 *)(tmp1 + 8));
  func_02057628(arg0,0,0);
  return;
}
