/*
 * src/game/unit_020d297c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0d297cWork {
    u8 pad_0000[0x18];
    u32 unk_0018;
    u32 unk_001c;
    s32 unk_0020;
} Unk0d297cWork;


void func_02095398(void);
void func_020953ac(void);
void Unk0e5fb8_Unk_0e6448(void);
void Unk0e5fb8_Unk_0e64c8(void);
int Unk0e651c_Unk_0e651c();

void Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e6448(void);
void Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e64c8(void);
void Unk0d297c_Thunk_02095398(void);
void Unk0d297c_Thunk_020953ac(void);
void Unk0d297c_Unk_0d2adc(u32 arg0);
u16 Unk0d297c_Unk_0d32e8(int *arg0,int arg1);
int Unk0d297c_Unk_0d32f8(int *arg0);

/* forwards to `Unk0e5fb8_Unk_0e6448` */
void Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e6448(void) { Unk0e5fb8_Unk_0e6448(); }

/* forwards to `Unk0e5fb8_Unk_0e64c8` */
void Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e64c8(void) { Unk0e5fb8_Unk_0e64c8(); }

/* forwards to `func_02095398` */
void Unk0d297c_Thunk_02095398(void) { func_02095398(); }

/* forwards to `func_020953ac` */
void Unk0d297c_Thunk_020953ac(void) { func_020953ac(); }

/* decompiler-derived */
void Unk0d297c_Unk_0d2adc(u32 arg0)
{
  Unk0e651c_Unk_0e651c(arg0,0);
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



/* decompiler-derived */
void Unk0d297c_Unk_0d3250(u32 *arg0,u32 arg1,u32 arg2)
{
  *arg0 = arg1;
  arg0[1] = arg2;
  arg0[3] = 0;
  arg0[4] = 0;
}


/* decompiler-derived */
u16 Unk0d297c_Unk_0d32ac(int *arg0)
{
  return *(u16 *)(*arg0 + arg0[1] * 2);
}


/* decompiler-derived */
void Unk0d297c_Unk_0d31e8(u32 *arg0)
{
  arg0[1] = 0;
  *arg0 = 0;
  arg0[3] = 0;
  arg0[4] = 0;
}


/* decompiler-derived */
void Unk0d297c_Unk_0d3290(int *arg0,u16 arg1)
{
  if (arg0[1] < arg0[2]) {
    *(u16 *)(*arg0 + arg0[1] * 2) = arg1;
  }
}

int func_02053000();
int func_020d322c();
/* decompiler-derived */
void Unk0d297c_Unk_0d33ac(Unk0d297cWork *work)
{
  func_020d322c();
  func_02053000(work->unk_0018);
  work->unk_0018 = 0;
}


int func_0204459c();
int func_0204fe68();
int func_0204fed8();
/* decompiler-derived */
void Unk0d297c_Unk_0d2f18(u32 arg0)
{
  u32 value;
  value = func_0204459c(0x1d);
  value = func_0204fe68(value,0);
  func_0204fed8(value,arg0);
}


/* decompiler-derived */
void Unk0d297c_Unk_0d2f3c(u32 arg0)
{
  u32 value;
  value = func_0204459c(0x1d);
  value = func_0204fe68(value,1);
  func_0204fed8(value,arg0);
}


/* decompiler-derived */
void Unk0d297c_Unk_0d2f98(u32 arg0)
{
  u32 value;
  value = func_0204459c(0x1d);
  value = func_0204fe68(value,3);
  func_0204fed8(value,arg0);
}

int func_0202dfa0();
int func_02095818();
int func_020d2aa4();
/* decompiler-derived */
void Unk0d297c_Unk_0d2b70(u32 arg0)
{
  int value;
  Unk0e651c_Unk_0e654c();
  func_020d2aa4(arg0);
  value = func_02095818();
  if (value == 1) {
    return;
  }
  func_0202dfa0();
}

int func_02095350();
int func_020d2aec();
/* decompiler-derived */
void Unk0d297c_Unk_0d2c1c(u32 arg0)
{
  Unk0e651c_Unk_0e6560();
  func_02095350(arg0,1);
  func_020d2aec(arg0);
  func_0202dfa0();
}

extern u32 data_02176be0[];
/* decompiler-derived */
u32 Unk0d297c_Unk_0d2e88(void)
{
  func_02053000(*data_02176be0);
  *data_02176be0 = 0;
  return 1;
}


/* decompiler-derived */
u16 Unk0d297c_Unk_0d32c0(int *arg0)
{
  if (arg0[1] < arg0[2] + -1) {
    return *(u16 *)(*arg0 + arg0[1] * 2 + 2);
  }
  return 0;
}


int func_02008848();
/* decompiler-derived */
void Unk0d297c_Unk_0d3330(Unk0d297cWork *arg0){
  func_02008848(arg0->unk_0018,0,arg0->unk_0020 << 2);
  arg0->unk_001c = 0;
  return;
}

int func_02052fe0();
/* decompiler-derived */
void Unk0d297c_Unk_0d3200(u32 *arg0,int arg1)
{
  u32 tmp1;
  arg0[1] = 0;
  arg0[2] = arg1;
  tmp1 = func_02052fe0(arg1 << 1);
  *arg0 = tmp1;
  arg0[3] = 0;
  arg0[4] = 0;
  return;
}



int func_020d2eb0();
/* decompiler-derived */
u32 Unk0d297c_Unk_0d2fbc(u32 arg0)
{
  int tmp1;
  u32 tmp2;
  if (*data_02176be0 == 0) {
    return 0;
  }
  tmp1 = func_020d2eb0(arg0);
  if (tmp1 != 0) {
    tmp2 = func_0204fe68(*data_02176be0,0);
    tmp2 = func_0204fed8(tmp2,*(u32 *)(tmp1 + 0x40));
    return tmp2;
  }
  return 0;
}

int func_0204fb14();
/* decompiler-derived */
u32 Unk0d297c_Unk_0d3034(u32 arg0,u32 arg1)
{
  u16 tmp1;
  u32 tmp2;
  switch(arg0) {
  case 0:
    break;
  case 1:
    tmp2 = Unk09974c_Unk_099bac(arg1);
    return tmp2;
  case 2:
    return 0;
  case 3:
    tmp2 = Unk0a163c_Unk_0a1814(arg1);
    return tmp2;
  case 4:
    tmp1 = func_0204fb14(2);
    tmp2 = Unk0a163c_Unk_0a1814(tmp1);
    return tmp2;
  }
  return 0;
}
