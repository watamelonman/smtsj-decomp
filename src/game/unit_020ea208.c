/*
 * src/game/unit_020ea208.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct Unk0ea208Work {
    u8 unk_0000[0x1c4];
    u32 UnkField01c4;
    u32 UnkField01c8;
    u32 UnkField01cc;
    u8 UnkField01d0;
} Unk0ea208Work;


extern u32 data_02176ddc[];
int func_020572d8();
int func_02057eb8();
int Unk09974c_Unk_099bac();
int func_020cb044();
int func_020e8374();
int func_020e849c();
int Unk0e8228_Unk_0e8f38();

void Unk0ea208_Unk_0ead3c(void);
u32 Unk0ea208_Get_data_02176ddc(void);
void Unk0ea208_Unk_0eaca0(void);
u32 Unk0ea208_Unk_0ea72c(void);
void Unk0ea208_Unk_0ead4c(void);

/* decompiler-derived */
void Unk0ea208_Unk_0ead3c(void)
{
  Unk0e8228_Unk_0e8f38();
  func_020cb044();
}

/* decompiler-derived */
u32 Unk0ea208_Get_data_02176ddc(void)
{
  return *data_02176ddc;
}

/* decompiler-derived */
void Unk0ea208_Unk_0eaca0(void)
{
  func_02057eb8(0xffffffff);
  func_020572d8();
}

/* decompiler-derived */
u32 Unk0ea208_Unk_0ea72c(void)
{
  int value1;
  u32 value2;
  value1 = Unk0ea208_Get_data_02176ddc();
  if (value1 == 0) {
    value2 = 0;
  }
  else {
    value2 = *(u32 *)(value1 + 0x1d4);
  }
  return value2;
}

/* decompiler-derived */
void Unk0ea208_Unk_0ead4c(void)
{
  func_020e8374(8);
  func_020e849c();
  Unk09974c_Unk_099bac();
}



/* decompiler-derived */
void Unk0ea208_Unk_0eb308(Unk0ea208Work *work)
{
  work->UnkField01c4 = 1;
  work->UnkField01c8 = 0;
  work->UnkField01cc = 0;
  work->UnkField01d0 = 0;
}

int func_02057524();
int func_02057ddc();
int func_02057e18();
/* decompiler-derived */
void Unk0ea208_Unk_0eac80(void)
{
  func_02057e18(0x1f);
  func_02057ddc(0xffffffff);
  func_02057524(4);
}

int func_020ea85c();
/* decompiler-derived */
void Unk0ea208_Unk_0ead1c(void)
{
  int value;
  value = Unk0e8228_Unk_0e8f38();
  if (value == 0) {
    func_020ea85c();
    return;
  }
  func_020cb044();
}


/* decompiler-derived */
void Unk0ea208_Unk_0eae20(u32 *arg0)
{
  *arg0 = 0;
  arg0[1] = 0;
  arg0[4] = 0;
  arg0[5] = 0;
  arg0[6] = 0;
  arg0[7] = 0;
}



/* decompiler-derived */
int * func_020eb2cc(int arg0)
{
  int *v1;
  int tmp2;
  v1 = (int *)(arg0 + 0x70);
  tmp2 = 0;
  do {
    if (*v1 == 0) {
      return v1;
    }
    tmp2 = tmp2 + 1;
    v1 = v1 + 0xe;
  } while (tmp2 < 6);
  return (int *)0x0;
}

int func_020eb0a8();
/* decompiler-derived */
void func_020eb230(int arg0)
{
  int tmp1;
  int *v2;
  v2 = (int *)(arg0 + 0x70);
  tmp1 = 0;
  do {
    if (*v2 != 0) {
      func_020eb0a8(v2);
    }
    tmp1 = tmp1 + 1;
    v2 = v2 + 0xe;
  } while (tmp1 < 6);
  return;
}

int func_020445f4();
int func_0204fed8();
/* decompiler-derived */
u32 func_020eada8(void)
{
  int tmp1;
  u32 tmp2;
  tmp1 = Unk0ea208_Get_data_02176ddc();
  if (tmp1 == 0) {
    return 0;
  }
  if (*(int *)(tmp1 + 0x1cc) != 0) {
    tmp2 = func_020445f4(0x27,0);
    tmp2 = func_0204fed8(tmp2,3);
    return tmp2;
  }
  return 0;
}



/* decompiler-derived */
u32 func_020eade4(void)
{
  int tmp1;
  u32 tmp2;
  tmp1 = Unk0ea208_Get_data_02176ddc();
  if (tmp1 == 0) {
    return 0;
  }
  if (*(int *)(tmp1 + 0x1cc) != 0) {
    tmp2 = func_020445f4(0x27,2);
    tmp2 = func_0204fed8(tmp2,2);
    return tmp2;
  }
  return 0;
}

int func_020eb178();
/* decompiler-derived */
void func_020eb264(int arg0)
{
  int tmp1;
  int *v2;
  Unk0ea208_Unk_0eac80();
  v2 = (int *)(arg0 + 0x70);
  tmp1 = 0;
  do {
    if (*v2 != 0) {
      func_020eb178(v2);
    }
    tmp1 = tmp1 + 1;
    v2 = v2 + 0xe;
  } while (tmp1 < 6);
  Unk0ea208_Unk_0eaca0();
  return;
}


/* decompiler-derived */
void func_020eae40(u32 arg0,u32 arg1,u32 arg2,u32 arg3)
{
  Unk065e88_SetUnkFieldsc_10();
  Unk065e88_SetUnkField28(arg0,arg3);
  Unk065e88_SetUnkField24(arg0,10);
  Unk065e88_SetUnkField30(arg0,4);
  Unk065e88_SetUnkField3c(arg0,2);
  return;
}


