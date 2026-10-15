/*
 * src/game/unit_0203e43c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 data_0215e85e[];
int Unk02e000_GetWorkArea();
int Unk03e43c_Div10Clamp16();
void func_0203fa84(void);
int func_0205410c();

void Unk03e43c_Thunk_0203fa84(void);
int Unk03e43c_Unk_03f2ac(int arg0);
void Unk03e43c_Unk_03fa28(void);
void Unk03e43c_Unk_03f2bc(void);
void Unk03e43c_Unk_03fa3c(char arg0);

typedef struct Unk03e43cTimer {
    u8 pad_0000[0x58];
    u16 count;                  /* +0x58 */
} Unk03e43cTimer;

extern u8 data_0215e85c[];
void Unk03e43c_CopyEntry32(u8 *src, int idx)
{
    int i;
    for (i = 0; i < 32; i += 2) {
        data_0215e85c[idx * 32 + i + 2] = src[i];
        data_0215e85c[idx * 32 + i + 3] = src[i + 1];
    }
}

void Unk03e43c_MergeTable(u8 *src)
{
    int i;
    for (i = 0; i < 512; i += 2) {
        if (src[i] != 0 || src[i + 1] != 0) {
            data_0215e85c[i + 2] = src[i];
            data_0215e85c[i + 3] = src[i + 1];
        }
    }
}

void func_02020f8c();
void func_02008848();
int func_0202092c();
void func_020211d8();
void func_0204b6d0();
void func_02043450();
extern u8 data_0215ee60[];
void Unk03e43c_ClearTable(void)
{
    func_02020f8c();
    func_02008848(data_0215e85e, 0, 512);
    *(u16 *)data_0215e85c = 0;
}

void Unk03e43c_Unk_03e894(u8 *o, int b, int c, int d)
{
    func_020211d8(o, func_0202092c(c, (u16)d), b);
    FIELD(u16, o, 0x58) = 0;
}

/* Counts down; returns 1 once the counter is already 0. */
int Unk03e43c_CountDown(Unk03e43cTimer *t)
{
    if (t->count == 0) {
        return 1;
    }
    t->count--;
    return 0;
}

int Unk03e43c_Div10Clamp16(int x)
{
    int r = x / 10;
    if (r >= 16) {
        r = -1;
    }
    return r;
}

void Unk03e43c_AdvanceCounter360(void)
{
    u8 *w = (u8 *)Unk02e000_GetWorkArea();
    s32 v = ++w[0x360];
    if (v >= 160) {
        w[0x360] -= 160;
    }
}

/* forwards to `func_0203fa84` */
void Unk03e43c_Thunk_0203fa84(void) { func_0203fa84(); }

/* decompiler-derived */
int Unk03e43c_Unk_03f2ac(int arg0)
{
  return ((int)data_0215e85e) + arg0;
}

/* decompiler-derived */
void Unk03e43c_Unk_03fa28(void)
{
  int value;
  value = Unk02e000_GetWorkArea();
  Unk03e43c_Div10Clamp16(*(u8 *)(value + 0x360));
}

/* decompiler-derived */
void Unk03e43c_Unk_03f2bc(void)
{
  int value;
  value = func_0205410c();
  *(u8 *)(value + 0x10) = *(u8 *)(value + 0x10) | 2;
}

/* decompiler-derived */
void Unk03e43c_Unk_03fa3c(char arg0)
{
  int value;
  value = Unk02e000_GetWorkArea();
  *(char *)(value + 0x360) = arg0 * '\n';
}


int func_02020974();
int func_02051610();
int func_020516d0();
/* decompiler-derived */
int Unk03e43c_Unk_03e5a4(u32 arg0,u32 arg1)
{
  int value1;
  int value2;
  value1 = func_02051610(arg1);
  if (value1 != 0) {
    value2 = func_02020974(value1,arg0);
    if (value2 != 0) {
      return value1;
    }
    func_020516d0(value1);
  }
  return 0;
}

int func_020207d0();
/* decompiler-derived */
int Unk03e43c_Unk_03e5dc(u32 arg0,u32 arg1)
{
  int value1;
  int value2;
  value1 = func_02051610(arg1);
  if (value1 != 0) {
    value2 = func_020207d0(value1,arg0);
    if (value2 != 0) {
      return value1;
    }
    func_020516d0(value1);
  }
  return 0;
}

int func_02020ac0();
/* decompiler-derived */
int Unk03e43c_Unk_03e614(u32 arg0,u32 arg1)
{
  int value1;
  int value2;
  value1 = func_02051610(arg1);
  if (value1 != 0) {
    value2 = func_02020ac0(value1,arg0);
    if (value2 != 0) {
      return value1;
    }
    func_020516d0(value1);
  }
  return 0;
}

int func_02020a74();
/* decompiler-derived */
int Unk03e43c_Unk_03e64c(u32 arg0,u32 arg1)
{
  int value1;
  int value2;
  value1 = func_02051610(arg1);
  if (value1 != 0) {
    value2 = func_02020a74(value1,arg0);
    if (value2 != 0) {
      return value1;
    }
    func_020516d0(value1);
  }
  return 0;
}

extern u8 data_0215e85c[];
/* decompiler-derived */
void Unk03e43c_Unk_03e794(int arg0,int arg1)
{
  int value1;
  int value2;
  int value3;
  value2 = 0;
  value3 = ((int)data_0215e85c) + arg1 * 0x20;
  do {
    value1 = arg0 + value2;
    value2 = value2 + 2;
    *(u8 *)(value3 + 2) = *(u8 *)(value1 + 0x28);
    *(u8 *)(value3 + 3) = *(u8 *)(value1 + 0x29);
    value3 = value3 + 2;
  } while (value2 < 0x20);
}




int GameState_GetBody();
void Unk03e43c_SetMode30(int mode)
{
    FIELD(s32, data_0215ee60, 0x30) = mode;
    if (mode == 1 && FIELD(u32, data_0215ee60, 0x34) == 0) {
        func_0204b6d0();
    }
}

void Unk03e43c_UpdatePos18(u8 *o)
{
    s16 x = FIELD(s16, o, 0x18);
    s16 y = FIELD(s16, o, 0x1a);
    func_02043450(o + 0x18, o + 0x1a, FIELD(u32, o, 0x28dc));
    if (FIELD(s16, o, 0x18) != x || FIELD(s16, o, 0x1a) != y) {
        FIELD(u32, o, 0x04) = 1;
    }
}

/* decompiler-derived */
void Unk03e43c_Unk_0434b0(short *arg0,short *arg1)
{
  int value;
  if (0xb0 < *arg0) {
    *arg0 = 0xb0;
  }
  if (0x70 < *arg1) {
    *arg1 = 0x70;
  }
  value = GameState_GetBody();
  if ((int)*arg0 < (int)((*(u8 *)(*(int *)(value + 0x354) + 10) - 10) * -8)) {
    value = GameState_GetBody();
    *arg0 = (*(u8 *)(*(int *)(value + 0x354) + 10) - 10) * -8;
  }
  value = GameState_GetBody();
  if ((int)*arg1 < (int)((*(u8 *)(*(int *)(value + 0x354) + 0xb) - 10) * -8)) {
    value = GameState_GetBody();
    *arg1 = (*(u8 *)(*(int *)(value + 0x354) + 0xb) - 10) * -8;
    return;
  }
}

int func_02056cc0();
/* decompiler-derived */
void Unk03e43c_Call_02056cc0(void)
{
  func_02056cc0(1,0,data_0215e85e);
}
