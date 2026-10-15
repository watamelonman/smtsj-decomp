/*
 * src/game/unit_020aa118.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))


/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0aa118Work {
    u8 pad_0000[0x4];
    s32 unk_0004;
    u8 pad_0008[0x10];
    s32 unk_0018;
    u32 unk_001c;
} Unk0aa118Work;

int Unk044904_Unk_04509c();
void func_020af8d8(void);

void Unk0aa118_Nop_0ae054(void);
void Unk0aa118_Thunk_020af8d8(void);
void Unk0aa118_Unk_0ab454(void);
int Unk0aa118_Unk_0ab4b8(void);

/* empty callback */
void Unk0aa118_Nop_0ae054(void) { }

/* forwards to `func_020af8d8` */
void Unk0aa118_Thunk_020af8d8(void) { func_020af8d8(); }

/* decompiler-derived */
void Unk0aa118_Unk_0ab454(void)
{
  int value;
  value = Unk044904_Unk_04509c();
  *(u32 *)(value + 0x18) = 0;
}

/* decompiler-derived */
int Unk0aa118_Unk_0ab4b8(void)
{
  int value;
  value = Unk044904_Unk_04509c();
  return *(int *)(value + 0x18) != 0;
}


int func_02008848();
int func_02052fe0();
/* decompiler-derived */
u32 * Unk0aa118_Unk_0afb64(u32 arg0)
{
  u32 *v1;
  v1 = (u32 *)func_02052fe0(0x94);
  func_02008848(v1,0,0x94);
  *v1 = arg0;
  return v1;
}


int func_0204fde0();
int func_020af780();
int func_020af7f8();
/* decompiler-derived */
void Unk0aa118_Unk_0af824(void)
{
  u8 *v1;
  v1 = (u8 *)func_020af780();
  if (v1 != (u8 *)0x0) {
    func_020af7f8(*v1,v1[1]);
    func_0204fde0();
    return;
  }
  func_020af7f8(0,0);
  func_0204fde0();
}



/* decompiler-derived */
u32 Unk0aa118_Unk_0afb90(int arg0)
{
  u32 value;
  value = func_02052fe0(0x90);
  func_02008848(value,0,0x90);
  if (((Unk0aa118Work *)arg0)->unk_0018 == 0) {
    ((Unk0aa118Work *)arg0)->unk_0018 = value;
  }
  else {
    **(u32 **)(arg0 + 0x1c) = value;
  }
  ((Unk0aa118Work *)arg0)->unk_001c = value;
  ((Unk0aa118Work *)arg0)->unk_0004 = ((Unk0aa118Work *)arg0)->unk_0004 + 1;
  return value;
}

int func_0204a0e8();
int func_0204a244();
int func_020b0310();
/* decompiler-derived */
u32 Unk0aa118_Unk_0ab4f4(u32 arg0,u32 arg1,u32 arg2,int arg3)
{
  int value1;
  u32 value2;
  if (arg3 == 3) {
    return 1;
  }
  value1 = func_0204a244(arg2);
  if ((value1 == 2) && (value1 = func_0204a0e8(arg2,400), value1 != 0)) {
    return 0;
  }
  value2 = func_020b0310(arg0,arg1,arg2);
  return value2;
}

int func_02044ec4();
int func_0204abd8();
int func_0204f108();
int func_0209fd64();
int func_020ab62c();
int func_020ab8f8();
int func_020af9f4();
int func_020afbdc();
int func_020b0930();
int func_020cb084();
/* decompiler-derived */
void func_020acb74(u32 arg0,u32 arg1,u32 arg2)
{
  u32 *v1;
  int tmp2;
  u32 tmp3;
  int tmp4;
  u32 tmp5;
  v1 = (u32 *)func_02044ec4(arg2);
  tmp2 = func_0204abd8(v1,0);
  if (tmp2 == 0) {
    tmp2 = func_020cb084(arg1);
    if (tmp2 != 0) {
      func_0204f108(0,0x20,tmp2,0);
    }
    tmp2 = (int)Unk0aa118_Unk_0afb64(arg0);
    tmp5 = arg0 >> 0x10 & 0xff;
    if (tmp5 == 1) {
      tmp3 = 2;
    }
    else if (tmp5 == 2) {
      tmp3 = 1;
    }
    else {
      tmp3 = 0;
    }
    tmp3 = func_020af9f4(tmp3,arg1,0);
    *(u32 *)(tmp2 + 0x10) = tmp3;
    if (tmp5 == 1) {
      tmp3 = 2;
    }
    else if (tmp5 == 2) {
      tmp3 = 1;
    }
    else {
      tmp3 = 0;
    }
    tmp3 = func_020af9f4(tmp3,arg1,1);
    *(u32 *)(tmp2 + 0x14) = tmp3;
    *(u32 *)(tmp2 + 8) = *(u32 *)(tmp2 + 8) | 0x10;
    tmp4 = Unk0aa118_Unk_0afb90(tmp2);
    *(u32 *)(tmp4 + 0x84) = *(u32 *)(tmp4 + 0x84) & 0xffffff00 | 4;
    *(u32 *)(tmp4 + 4) = *v1;
    func_020b0930(tmp4 + 100,arg0,0,1);
    func_020ab62c(tmp4,arg0,0xffffffff);
    *(u32 *)(tmp4 + 0x84) = *(u32 *)(tmp4 + 0x84) | 0x1000;
    func_020ab8f8(tmp2);
    func_0209fd64(tmp2);
    func_020afbdc(tmp2);
    return;
  }
}
