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
int Unk0caea8_Unk_0cb044();
int Unk0e8228_Unk_0e8374();
int Unk0e8228_GetArr88Field20();
int Unk0e8228_Unk_0e8f38();

void Unk0ea208_Unk_0ead3c(void);
u32 Unk0ea208_Get_data_02176ddc(void);
void Unk0ea208_Unk_0eaca0(void);
u32 Unk0ea208_Unk_0ea72c(void);
void Unk0ea208_Unk_0ead4c(void);

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_02061f10();
void Unk0ea208_Unk_0ea390(int i, u32 x)
{
    if (i < 0) {
        return;
    }
    if (i >= 6) {
        return;
    }
    func_02061f10(FIELD(u32, Unk0ea208_Get_data_02176ddc() + i * 4, 36), -1, 0, 0, x);
}

u32 Unk0ea208_GetField0(void)
{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p == 0) {
        return 0;
    }
    if (FIELD(u32, p, 460) == 0) {
        return 0;
    }
    return FIELD(u32, p, 0);
}

u32 Unk0ea208_GetField4(void)
{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p == 0) {
        return 0;
    }
    if (FIELD(u32, p, 460) == 0) {
        return 0;
    }
    return FIELD(u32, p, 4);
}

u32 Unk0ea208_GetField8(void)
{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p == 0) {
        return 0;
    }
    if (FIELD(u32, p, 460) == 0) {
        return 0;
    }
    return FIELD(u32, p, 8);
}

u32 Unk0ea208_GetFieldC(void)
{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p == 0) {
        return 0;
    }
    if (FIELD(u32, p, 460) == 0) {
        return 0;
    }
    return FIELD(u32, p, 12);
}

u32 Unk0ea208_GetArr10(int i)
{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p == 0) {
        return 0;
    }
    if (FIELD(u32, p, 460) == 0) {
        return 0;
    }
    if (i < 0 || i >= 5) {
        return 0;
    }
    return FIELD(u32, p + i * 4, 16);
}

void Unk0ea208_ForEachSlot(u8 *p);
void func_020eb034();
void func_020ea744();
int Unk0e8228_Unk_0e8460();
int Unk0e8228_GetArr40();
int func_020445f4();
int func_0204fed8();
u32 Unk0ea208_GetArr24(int i)
{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p == 0) {
        return 0;
    }
    if (FIELD(u32, p, 460) == 0) {
        return 0;
    }
    if (i < 0 || i >= 6) {
        return 0;
    }
    return FIELD(u32, p + i * 4, 36);
}

u32 Unk0ea208_GetField3c(void)
{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p == 0) {
        return 0;
    }
    if (FIELD(u32, p, 460) == 0) {
        return 0;
    }
    return FIELD(u32, p, 60);
}

u32 Unk0ea208_GetArr40(int i)
{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p == 0) {
        return 0;
    }
    if (FIELD(u32, p, 460) == 0) {
        return 0;
    }
    if (i < 0 || i >= 6) {
        return 0;
    }
    return FIELD(u32, p + i * 4, 64);
}

u32 Unk0ea208_GetArr58(int i)
{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p == 0) {
        return 0;
    }
    if (FIELD(u32, p, 460) == 0) {
        return 0;
    }
    if (i < 0 || i >= 6) {
        return 0;
    }
    return FIELD(u32, p + i * 4, 88);
}

void Unk0ea208_Unk_0ea70c(void)
{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p != 0 && FIELD(u32, p, 460) != 0) {
        Unk0ea208_ForEachSlot((u8 *)p);
    }
}

/* decompiler-derived */
void Unk0ea208_Unk_0ead3c(void)
{
  Unk0e8228_Unk_0e8f38();
  Unk0caea8_Unk_0cb044();
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

void Unk0ea208_Unk_0ea828(void)
{
    int n = Unk0e8228_Unk_0e8460();
    int i;
    for (i = 0; i < n; i++) {
        func_020ea744(Unk0e8228_GetArr40(i));
    }
}

int Unk0ea208_Unk_0ea85c(void)
{
    return func_0204fed8(func_020445f4(39, 3), 1);
}

/* decompiler-derived */
void Unk0ea208_Unk_0ead4c(void)
{
  Unk0e8228_Unk_0e8374(8);
  Unk0e8228_GetArr88Field20();
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

int Unk0ea208_Unk_0ea85c();
/* decompiler-derived */
void Unk0ea208_Unk_0ead1c(void)
{
  int value;
  value = Unk0e8228_Unk_0e8f38();
  if (value == 0) {
    Unk0ea208_Unk_0ea85c();
    return;
  }
  Unk0caea8_Unk_0cb044();
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
int * Unk0ea208_Unk_0eb2cc(int arg0)
{
  int *v1;
  int value;
  v1 = (int *)(arg0 + 0x70);
  value = 0;
  do {
    if (*v1 == 0) {
      return v1;
    }
    value = value + 1;
    v1 = v1 + 0xe;
  } while (value < 6);
  return (int *)0x0;
}

int func_020eb0a8();
/* decompiler-derived */
void Unk0ea208_Unk_0eb230(int arg0)
{
  int value;
  int *v2;
  v2 = (int *)(arg0 + 0x70);
  value = 0;
  do {
    if (*v2 != 0) {
      func_020eb0a8(v2);
    }
    value = value + 1;
    v2 = v2 + 0xe;
  } while (value < 6);
}

int func_020445f4();
int func_0204fed8();
/* decompiler-derived */
u32 Unk0ea208_Unk_0eada8(void)
{
  int value1;
  u32 value2;
  value1 = Unk0ea208_Get_data_02176ddc();
  if (value1 == 0) {
    return 0;
  }
  if (*(int *)(value1 + 0x1cc) != 0) {
    value2 = func_020445f4(0x27,0);
    value2 = func_0204fed8(value2,3);
    return value2;
  }
  return 0;
}



/* decompiler-derived */
u32 Unk0ea208_Unk_0eade4(void)
{
  int value1;
  u32 value2;
  value1 = Unk0ea208_Get_data_02176ddc();
  if (value1 == 0) {
    return 0;
  }
  if (*(int *)(value1 + 0x1cc) != 0) {
    value2 = func_020445f4(0x27,2);
    value2 = func_0204fed8(value2,2);
    return value2;
  }
  return 0;
}

int func_020eb178();
/* decompiler-derived */
void Unk0ea208_Unk_0eb264(int arg0)
{
  int value;
  int *v2;
  Unk0ea208_Unk_0eac80();
  v2 = (int *)(arg0 + 0x70);
  value = 0;
  do {
    if (*v2 != 0) {
      func_020eb178(v2);
    }
    value = value + 1;
    v2 = v2 + 0xe;
  } while (value < 6);
  Unk0ea208_Unk_0eaca0();
}


/* decompiler-derived */
void Unk0ea208_Unk_0eae40(u32 arg0,u32 arg1,u32 arg2,u32 arg3)
{
  Unk065e88_SetUnkFieldsc_10();
  Unk065e88_SetUnkField28(arg0,arg3);
  Unk065e88_SetUnkField24(arg0,10);
  Unk065e88_SetUnkField30(arg0,4);
  Unk065e88_SetUnkField3c(arg0,2);
}

int func_0204a160();
int func_0204a190();
int func_0204a1b0();
int func_0204a1d0();
int func_0204a1e8();
int func_0204faf0();
int func_0204fcb0();
/* decompiler-derived */
void Unk0ea208_Unk_0ea878(u32 arg0)
{
  u32 tmp1;
  u32 tmp2;
  u32 tmp3;
  int tmp4;
  u32 tmp5;
  int tmp6;
  tmp1 = func_0204a1d0(arg0,1);
  tmp2 = func_0204a160(arg0,1);
  tmp3 = func_0204a1e8(arg0,1);
  tmp4 = func_0204a190(arg0,1);
  tmp5 = func_020445f4(0xe,1);
  tmp1 = func_0204fed8(tmp5,tmp1);
  func_0204fcb0(4,tmp1);
  tmp1 = func_020445f4(0xe,2);
  tmp1 = func_0204fed8(tmp1,tmp2);
  func_0204fcb0(5,tmp1);

  tmp1 = func_020445f4(0xe,3);
  tmp1 = func_0204fed8(tmp1,tmp3);
  func_0204fcb0(6,tmp1);
  tmp6 = func_0204a1b0(arg0,1);
  tmp1 = func_020445f4(0xe,0);
  if (tmp4 != tmp6) {
    func_0204faf0(3,tmp4);
    func_0204faf0(4,tmp6);
    func_0204fed8(tmp1,3);
    return;
  }
  func_0204faf0(3,tmp6);
  func_0204fed8(tmp1,2);
}

/* decompiler-derived */
void Unk0ea208_Unk_0ea984(u32 arg0)
{
  u32 tmp1;
  u32 tmp2;
  u32 tmp3;
  int tmp4;
  u32 tmp5;
  int tmp6;
  tmp1 = func_0204a1d0(arg0,0);
  tmp2 = func_0204a160(arg0,0);
  tmp3 = func_0204a1e8(arg0,0);
  tmp4 = func_0204a190(arg0,0);
  tmp5 = func_020445f4(0xe,1);
  tmp1 = func_0204fed8(tmp5,tmp1);
  func_0204fcb0(1,tmp1);
  tmp1 = func_020445f4(0xe,2);
  tmp1 = func_0204fed8(tmp1,tmp2);
  func_0204fcb0(2,tmp1);

  tmp1 = func_020445f4(0xe,3);
  tmp1 = func_0204fed8(tmp1,tmp3);
  func_0204fcb0(3,tmp1);
  tmp6 = func_0204a1b0(arg0,0);
  tmp1 = func_020445f4(0xe,0);
  if (tmp4 != tmp6) {
    func_0204faf0(1,tmp4);
    func_0204faf0(2,tmp6);
    func_0204fed8(tmp1,1);
    return;
  }
  func_0204faf0(1,tmp6);
  func_0204fed8(tmp1,0);
}

int Unk0ea208_Unk_0eac24(void)
{
    return func_0204fed8(func_020445f4(39, 4), 1);
}

void Unk0ea208_Unk_0eac40(u8 *p)
{
    func_02061f10(FIELD(u32, p, 60), -1, 0, 3, func_0204fed8(func_020445f4(39, 2), 1));
}

int Unk0e8228_GetArr40();
int func_02044ec4();
void Unk0a163c_Unk_0a1814();
void Unk0ea208_Unk_0ead64(void)
{
    u8 *q = (u8 *)func_02044ec4(Unk0e8228_GetArr40(Unk0e8228_Unk_0e8374(5)));
    if (((u32)(q[642] << 29) >> 31) != 0) {
        Unk0a163c_Unk_0a1814(0x17d);
        return;
    }
    Unk0a163c_Unk_0a1814(FIELD(u16, q, 472));
}

void Unk0ea208_ForEachSlot(u8 *p)
{
    int i;
    u8 *q = p + 112;
    for (i = 0; i < 6; i++) {
        func_020eb034(q);
        q += 56;
    }
}

/* decompiler-derived */
void Unk0ea208_Unk_0eb6cc(int arg0)
{
  if (((Unk0ea208Work *)arg0)->UnkField01c4 != 8) {
    return;
  }
  Unk0ea208_Unk_0eb264((int)arg0);
}
