/*
 * src/game/unit_020cf5e8.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))


/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0cf5e8Work {
    u8 pad_0000[0x4];
    u32 unk_0004;
    u8 pad_0008[0x4];
    u32 unk_000c;
    u8 pad_0010[0x10];
    u32 unk_0020;
    u8 pad_0024[0x7c];
    s32 unk_00a0;
    u8 pad_00a4[0xf0];
    s32 unk_0194;
    u8 pad_0198[0xf0];
    s32 unk_0288;
    s32 unk_028c;
    u32 unk_0290;
    u32 unk_0294;
    u8 pad_0298[0xc4];
    u32 unk_035c;
} Unk0cf5e8Work;

void Unk1241ec_Thunk_02124338(void);
void Unk1241ec_Unk_124258(void);

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

/* forwards to `Unk1241ec_Unk_124258` */
void Unk0cf5e8_Thunk_02124258(void) { Unk1241ec_Unk_124258(); }

/* forwards to `Unk1241ec_Thunk_02124338` */
void Unk0cf5e8_Thunk_0212424c(void) { Unk1241ec_Thunk_02124338(); }

/* decompiler-derived */
int Unk0cf5e8_Unk_0d139c(Unk0cf5e8Work *work)
{
  return work->unk_028c < work->unk_0194;
}

/* decompiler-derived */
int Unk0cf5e8_Unk_0d13fc(Unk0cf5e8Work *work)
{
  return work->unk_0288 < work->unk_00a0;
}


extern u8 data_02150648[];
int Unk0de678_Unk_0dec94();
typedef struct Unk0cf5e8Obj {
    u8 pad_0000[0x98];
    s32 unk_0098;
    s32 unk_009c;
    u8 pad_00a0[0x1f0];
    s32 unk_0290;
    s32 unk_0294;
} Unk0cf5e8Obj;

int Unk0cf5e8_Unk_0d1454(Unk0cf5e8Obj *o)
{
    return o->unk_009c == 1 && o->unk_0290 == 0;
}

/* decompiler-derived */
void Unk0cf5e8_Unk_0d1470(int arg0)
{
  Unk0de678_Unk_0dec94(((int)data_02150648));
  ((Unk0cf5e8Work *)arg0)->unk_0290 = 1;
  return;
}

extern u8 data_02150654[];
int Unk0cf5e8_Unk_0d1490(Unk0cf5e8Obj *o)
{
    return o->unk_0098 == 1 && o->unk_0294 == 0;
}

/* decompiler-derived */
void Unk0cf5e8_Unk_0d14ac(int arg0)
{
  Unk0de678_Unk_0dec94(((int)data_02150654));
  ((Unk0cf5e8Work *)arg0)->unk_0294 = 1;
  return;
}

int Unk0a0ce4_Unk_0a0da4();
int func_020d1360();
/* decompiler-derived */
void Unk0cf5e8_Unk_0d0f94(int arg0,u32 arg1)
{
  Unk0a0ce4_Unk_0a0da4(5);
  ((Unk0cf5e8Work *)arg0)->unk_0004 = 4;
  func_020d1360(arg0,0x14);
  ((Unk0cf5e8Work *)arg0)->unk_000c = arg1;
  return;
}

int Unk122e1c_Unk_123294();
/* decompiler-derived */
void Unk0cf5e8_Unk_0d0fc4(int arg0,u32 arg1)
{
  Unk122e1c_Unk_123294(((Unk0cf5e8Work *)arg0)->unk_0020);
  ((Unk0cf5e8Work *)arg0)->unk_035c = arg1;
  ((Unk0cf5e8Work *)arg0)->unk_0004 = 1;
  func_020d1360(arg0,3);
  return;
}

int func_020d174c();
/* decompiler-derived */
u32 Unk0cf5e8_Unk_0d182c(void)
{
  int tmp1;
  int tmp2;
  tmp2 = 0;
  do {
    tmp1 = func_020d174c(tmp2);
    if (tmp1 == 0) {
      return 0;
    }
    tmp2 = tmp2 + 1;
  } while (tmp2 < 2);
  return 1;
}

int func_02044534();
int Unk095560_Unk_0956c8();
int Unk0bc1a8_Unk_0bc9b4();
int Unk0de678_Unk_0de870();
int Unk122a78_Unk_122aa0();
/* decompiler-derived */
void Unk0cf5e8_Unk_0cf630(void)
{
  int tmp1;
  tmp1 = Unk0de678_Get_data_021508d4();
  if (tmp1 == 0) {
    Unk0bc1a8_Unk_0bc9b4(0x15,0);
    Unk1241ec_Unk_124214();
    Unk122a78_Unk_122aa0();
    func_02044534(0x1e);
  }
  Unk0de678_Unk_0de870();
  Unk095560_Unk_0956c8();
  return;
}


int func_020f3de8();
int func_020f3f2c();
/* decompiler-derived */
void Unk0cf5e8_Unk_0d1414(int arg0)
{
  u32 tmp1;
  int tmp2;
  tmp1 = func_020f3f2c(*(u16 *)(arg0 + ((Unk0cf5e8Work *)arg0)->unk_0288 * 8 + 0xa8));
  tmp2 = func_020f3de8(tmp1,*(u16 *)(arg0 + ((Unk0cf5e8Work *)arg0)->unk_0288 * 8 + 0xa6));
  Unk0de678_Unk_0dec94(tmp2 + 0x16);
  ((Unk0cf5e8Work *)arg0)->unk_0288 = ((Unk0cf5e8Work *)arg0)->unk_0288 + 1;
  return;
}


/* decompiler-derived */
void Unk0cf5e8_Unk_0d13b4(int arg0)
{
  u32 tmp1;
  int tmp2;
  tmp1 = func_020f3f2c(*(u16 *)(arg0 + ((Unk0cf5e8Work *)arg0)->unk_028c * 8 + 0x19c));
  tmp2 = func_020f3de8(tmp1,*(u16 *)(arg0 + ((Unk0cf5e8Work *)arg0)->unk_028c * 8 + 0x19a));
  Unk0de678_Unk_0dec94(tmp2 + 0x16);
  ((Unk0cf5e8Work *)arg0)->unk_028c = ((Unk0cf5e8Work *)arg0)->unk_028c + 1;
  return;
}

int func_020cb5b4();
int func_020d0ff4();
int func_020d10ac();
/* decompiler-derived */
void Unk0cf5e8_Unk_0d0960(int arg0,u32 arg1)
{
  int tmp1;
  tmp1 = func_020cb5b4(arg1,arg0 + 8);
  if (tmp1 == 1) {
    func_020d0ff4(arg0);
    return;
  }
  if (tmp1 == 2) {
    func_020d10ac(arg0);
    return;
  }
  if (tmp1 != 3) {
    return;
  }
  func_020d1360(arg0,((Unk0cf5e8Work *)arg0)->unk_0004);
  return;
}

