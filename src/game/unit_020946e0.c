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
  int value;
  value = Unk0946e0_GetAddr_data_02175d94();
  *arg0 = (int)*(short *)(value + 0x10);
}

/* decompiler-derived */
u32 Unk0946e0_Unk_0946e0(void)
{
  u32 value;
  value = func_02052ff0(0xc);
  func_02008848(value,0,0xc);
  return value;
}

/* decompiler-derived */
void Unk0946e0_Unk_094c50(int *arg0)
{
  short *v1;
  int value;
  v1 = (short *)Unk0946e0_GetAddr_data_02175d94();
  *arg0 = (int)*v1;
  value = Unk0946e0_GetAddr_data_02175d94();
  arg0[1] = (int)*(short *)(value + 2);
}

/* decompiler-derived */
void Unk0946e0_Unk_094a64(u32 arg0)
{
  int value;
  value = Unk0946e0_GetAddr_data_02175d94();
  func_02057678(arg0,*(u32 *)(value + 4),*(u32 *)(value + 8));
  func_02057628(arg0,0,0);
}



/* decompiler-derived */
void Unk0946e0_Unk_094704(u16 *arg0,u16 arg1,u16 arg2,u16 arg3,
                  short arg4)
{
  if (arg0 == (u16 *)0x0) {
    return;
  }
  *arg0 = arg1;
  arg0[1] = arg2;
  arg0[4] = arg3;
  arg0[5] = -arg4;
  arg0[2] = 0;
  arg0[3] = 0;
}


int func_02094750();
int func_020949e0();
int func_02094a90();
/* decompiler-derived */
void Unk0946e0_Unk_094958(void)
{
  int value;
  short *v2;
  short *v3;
  value = Unk044904_Get_data_0215ee98();
  func_02094750(*(u32 *)(value + 0x7870));
  v2 = (short *)Unk0946e0_GetAddr_data_02175d94();
  value = Unk044904_Get_data_0215ee98();
  v3 = (short *)Unk0946e0_Unk_0948fc(*(u32 *)(value + 0x7870));
  *(int *)(v2 + 2) = (int)*v2 + (int)*v3;
  value = Unk044904_Get_data_0215ee98();
  value = Unk0946e0_Unk_0948fc(*(u32 *)(value + 0x7870));
  *(int *)(v2 + 4) = (int)v2[1] + (int)*(short *)(value + 2);
  func_02094a90(0);
  func_020949e0(1);
  func_02094a90(2);
  func_020949e0(3);
  Unk0946e0_Unk_094a64(6);
}

int func_02061424();
int func_02094af8();
/* decompiler-derived */
void func_02094b98(int arg0)
{
  int tmp1;
  if (*(int *)(arg0 + 8) < 0) {
    *(u32 *)(arg0 + 8) = 0;
    Unk0946e0_Unk_094ae0((int *)arg0);
    return;
  }
  tmp1 = func_02094af8();
  if (tmp1 == 0) {
    return;
  }
  func_02061424(arg0);
}

int func_02094c74();
/* decompiler-derived */
void func_02094d64(int arg0)
{
  int tmp1;
  if (*(int *)(arg0 + 0x10) < 0) {
    *(u32 *)(arg0 + 0x10) = 0;
    Unk0946e0_Unk_094c50((int *)arg0);
    return;
  }
  tmp1 = func_02094c74();
  if (tmp1 == 0) {
    return;
  }
  func_02061424(arg0);
}
