/*
 * src/game/unit_02122e1c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct Unk122e1cWork {
    u8 unk_0000[0x14];
    u32 UnkField0014;
    u8 unk_0018[0x48];
    char UnkField0060;
} Unk122e1cWork;


int func_0205caa8();
int Unk0cb32c_Unk_0cb57c();

void Unk122e1c_SetUnkFields64_b0(void *obj, u32 a, u32 b);
void Unk122e1c_Unk_122f88(int arg0,int arg1,u32 arg2);
u32 Unk122e1c_Unk_122f94(int arg0,int arg1);
void Unk122e1c_Unk_122fa0(int arg0,int arg1,u32 arg2);
void Unk122e1c_Unk_12331c(Unk122e1cWork *work);
int Unk122e1c_Unk_122f54(Unk122e1cWork *work);
int Unk122e1c_Unk_122f68(Unk122e1cWork *work);
void Unk122e1c_Unk_12332c(Unk122e1cWork *work);

/* set +0x64 and +0xb0 */
void Unk122e1c_SetUnkFields64_b0(void *obj, u32 a, u32 b) {
    FIELD(u32, obj, 0x64) = a;
    FIELD(u32, obj, 0xb0) = b;
}

/* decompiler-derived */
void Unk122e1c_Unk_122f88(int arg0,int arg1,u32 arg2)
{
  *(u32 *)(arg0 + arg1 * 4 + 0x78) = arg2;
}

/* decompiler-derived */
u32 Unk122e1c_Unk_122f94(int arg0,int arg1)
{
  return *(u32 *)(arg0 + arg1 * 4 + 0x78);
}

/* decompiler-derived */
void Unk122e1c_Unk_122fa0(int arg0,int arg1,u32 arg2)
{
  *(u32 *)(arg0 + arg1 * 4 + 200) = arg2;
}

/* decompiler-derived */
void Unk122e1c_Unk_12331c(Unk122e1cWork *work)
{
  Unk0cb32c_Unk_0cb57c(work->UnkField0014);
}

/* decompiler-derived */
int Unk122e1c_Unk_122f54(Unk122e1cWork *work)
{
  return work->UnkField0060 == '\0';
}

/* decompiler-derived */
int Unk122e1c_Unk_122f68(Unk122e1cWork *work)
{
  return work->UnkField0060 == '\b';
}

/* decompiler-derived */
void Unk122e1c_Unk_12332c(Unk122e1cWork *work)
{
  func_0205caa8(work->UnkField0014,1);
}


int func_020fee98();
/* decompiler-derived */
void Unk122e1c_Unk_123024(int arg0)
{
  func_020fee98();
  *(u32 *)(arg0 + 0x114) = 0;
  *(u8 *)(arg0 + 0x61) = 0;
  *(u8 *)(arg0 + 0x60) = 1;
  return;
}


/* decompiler-derived */
void Unk122e1c_Unk_123048(int arg0)
{
  func_020fee98();
  *(u32 *)(arg0 + 0x114) = 0;
  *(u8 *)(arg0 + 0x61) = 0;
  *(u8 *)(arg0 + 0x60) = 2;
  return;
}


/* decompiler-derived */
void Unk122e1c_Unk_1232f8(int arg0)
{
  func_020fee98();
  *(u32 *)(arg0 + 0x114) = 0;
  *(u8 *)(arg0 + 0x61) = 0;
  *(u8 *)(arg0 + 0x60) = 6;
  return;
}

int func_020feec0();
/* decompiler-derived */
void Unk122e1c_Unk_1232c8(int arg0)
{
  func_020feec0();
  Unk0cb32c_Unk_0cb57c(*(u32 *)(arg0 + 0x14));
  *(u32 *)(arg0 + 0x114) = 0;
  *(u32 *)(arg0 + 0xb8) = 0xffffffa4;
  *(u32 *)(arg0 + 0x6c) = 0xffffffa4;
  *(u8 *)(arg0 + 0x60) = 0;
  return;
}



/* decompiler-derived */
void func_02122ff0(int arg0)
{
  func_020feec0();
  Unk0cb32c_Unk_0cb57c(*(u32 *)(arg0 + 0x10));
  *(int *)(arg0 + 0x114) = *(int *)(arg0 + 0x11c) + -1;
  *(u8 *)(arg0 + 0x61) = 0;
  *(u8 *)(arg0 + 0x60) = 3;
  return;
}


/* decompiler-derived */
void func_02123294(int arg0)
{
  func_020feec0();
  Unk0cb32c_Unk_0cb57c(*(u32 *)(arg0 + 0x14));
  *(int *)(arg0 + 0x114) = *(int *)(arg0 + 0x11c) + -1;
  *(u8 *)(arg0 + 0x61) = 0;
  *(u8 *)(arg0 + 0x60) = 7;
  return;
}

int func_02122fac();
/* decompiler-derived */
void func_0212306c(int arg0)
{
  int tmp1;
  tmp1 = 0;
  *(int *)(arg0 + 0x114) = *(int *)(arg0 + 0x11c) + -1;
  *(u8 *)(arg0 + 0x61) = 0;
  *(u8 *)(arg0 + 0x60) = 5;
  do {
    func_02122fac(arg0,tmp1,0);
    tmp1 = tmp1 + 1;
  } while (tmp1 < 6);
  return;
}
