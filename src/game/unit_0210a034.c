/*
 * src/game/unit_0210a034.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))


/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk10a034Work {
    u8 pad_0000[0x4];
    s32 unk_0004;
    u32 unk_0008;
    u8 pad_000c[0x4];
    u32 unk_0010;
    u8 pad_0014[0x10];
    u16 unk_0024;
    u8 pad_0026[0x6];
    u32 unk_002c;
    u8 pad_0030[0x84];
    u16 unk_00b4;
} Unk10a034Work;

extern u32 data_02176e38[];
extern u32 data_02176e3c[];
extern u32 data_02176e44[];
int func_02061424();
int func_020a1740();

u32 Unk10a034_Get_data_02176e38(void);
u32 Unk10a034_Get_data_02176e3c(void);
u32 Unk10a034_Unk_10af7c(void);
u32 Unk10a034_Get_data_02176e44(void);
void Unk10a034_Clear_data_02176e38(void);
void Unk10a034_Unk_10a9a4(Unk10a034Work *work,u32 arg1,int arg2);
void Unk10a034_Clear_data_02176e44(void);
void Unk10a034_Unk_10b394(Unk10a034Work *work,u32 arg1,int arg2);
void Unk10a034_Unk_10a05c(void);
void Unk10a034_Unk_10a074(void);
u32 Unk10a034_Unk_10a0b4(void);
int Unk10a034_Unk_10afc0(void);
void Unk10a034_Unk_10b000(void);
void Unk10a034_Unk_10b018(void);
int Unk10a034_Unk_10b058(u32 id);
void Unk10a034_Unk_10aeb0(int arg0);

/* decompiler-derived */
u32 Unk10a034_Get_data_02176e38(void)
{
  return *data_02176e38;
}

/* decompiler-derived */
u32 Unk10a034_Get_data_02176e3c(void)
{
  return *data_02176e3c;
}

/* decompiler-derived */
u32 Unk10a034_Unk_10af7c(void)
{
  return *(u32 *)(((int)data_02176e3c) + 4);
}

/* decompiler-derived */
u32 Unk10a034_Get_data_02176e44(void)
{
  return *data_02176e44;
}

/* decompiler-derived */
void Unk10a034_Clear_data_02176e38(void)
{
  *data_02176e38 = 0;
}

/* decompiler-derived */
void Unk10a034_Unk_10a9a4(Unk10a034Work *work,u32 arg1,int arg2)
{
  work->unk_0010 = arg1;
  if (arg2 == 0) {
    arg1 = 0x11;
  }
  work->unk_0008 = arg1;
}

/* decompiler-derived */
void Unk10a034_Clear_data_02176e44(void)
{
  *data_02176e44 = 0;
}

/* decompiler-derived */
void Unk10a034_Unk_10b394(Unk10a034Work *work,u32 arg1,int arg2)
{
  work->unk_0010 = arg1;
  if (arg2 == 0) {
    arg1 = 8;
  }
  work->unk_0008 = arg1;
}

/* decompiler-derived */
void Unk10a034_Unk_10a05c(void)
{
  int value;
  value = Unk10a034_Get_data_02176e38();
  if (value == 0) {
    return;
  }
  func_02061424();
}

/* decompiler-derived */
void Unk10a034_Unk_10a074(void)
{
  int value;
  value = Unk10a034_Get_data_02176e38();
  if (value != 0) {
    *(u32 *)(value + 8) = *(u32 *)(value + 0x10);
  }
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
typedef struct Unk10a034Ent {
    u16 id;
    u16 pad;
    u32 used;
    u32 val;
} Unk10a034Ent;
typedef struct Unk10a034Obj {
    u8 pad[200];
    u16 ids[4];
} Unk10a034Obj;
int Unk10a034_Unk_10a08c(void)
{
    u32 p = Unk10a034_Get_data_02176e38();
    if (p == 0) {
        return 1;
    }
    return FIELD(u32, p, 8) == 18;
}

/* decompiler-derived */
u32 Unk10a034_Unk_10a0b4(void)
{
  int value1;
  u32 value2;
  value1 = Unk10a034_Get_data_02176e38();
  if (value1 == 0) {
    value2 = 1;
  }
  else {
    value2 = *(u32 *)(value1 + 0x18);
  }
  return value2;
}

/* decompiler-derived */
int Unk10a034_Unk_10afc0(void)
{
  int value;
  value = Unk10a034_Unk_10af7c();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x18;
  }
  return value;
}

/* decompiler-derived */
void Unk10a034_Unk_10b000(void)
{
  int value;
  value = Unk10a034_Get_data_02176e44();
  if (value == 0) {
    return;
  }
  func_02061424();
}

/* decompiler-derived */
void Unk10a034_Unk_10b018(void)
{
  int value;
  value = Unk10a034_Get_data_02176e44();
  if (value != 0) {
    *(u32 *)(value + 8) = *(u32 *)(value + 0x10);
  }
}

/* decompiler-derived */
int Unk10a034_Unk_10b058(u32 id)
{
  int value;
  value = func_020a1740(id);
  return (u32)*(u8 *)(value + 2) * 300;
}

/* decompiler-derived */
void Unk10a034_Unk_10aeb0(int arg0)
{
  int value;
  value = 0;
  do {
    value = value + 1;
    ((Unk10a034Work *)arg0)->unk_002c = 0;
    arg0 = arg0 + 0xc;
  } while (value < 0xc);
}



/* decompiler-derived */
void Unk10a034_Unk_10b104(u32 *arg0,u32 arg1,u32 arg2)
{
  *arg0 = arg1;
  arg0[1] = arg2;
  arg0[2] = 0;
  arg0[3] = 0;
  arg0[4] = 0;
  arg0[5] = 0;
  arg0[6] = 0;
  return;
}

int func_020d2eb0();
/* decompiler-derived */
void Unk10a034_Unk_10af40(int arg0)
{
  int tmp1;
  if (*data_02176e3c == arg0) {
    return;
  }
  *data_02176e3c = arg0;
  tmp1 = func_020d2eb0();
  data_02176e3c[1] = tmp1;
  return;
}

int func_0204faf0();
int func_02065864();
int Unk0d297c_Unk_0d2f98();
/* decompiler-derived */
void Unk10a034_Unk_10af0c(int arg0)
{
  u32 tmp1;
  func_0204faf0(7,((Unk10a034Work *)arg0)->unk_00b4);
  tmp1 = Unk0d297c_Unk_0d2f98(0x16);
  func_02065864(tmp1,0xffffffff);
  *(u32 *)(((Unk10a034Work *)arg0)->unk_0004 + 0x18) = 0x1c;
  return;
}

int Unk02e000_GetAreaRecord();
int Unk02e000_HasField36();
int Unk096754_Unk_096ab0();
int func_020a1428();
/* decompiler-derived */
void Unk10a034_Unk_10ac28(int arg0)
{
  int tmp1;
  int tmp2;
  int tmp3;
  u16 *v4;
  tmp3 = 0;
  v4 = (u16 *)(arg0 + 0x24);
  do {
    tmp1 = Unk02e000_GetAreaRecord(tmp3);
    tmp2 = Unk02e000_HasField36();
    if (tmp2 == 0) {
      *(u32 *)(v4 + 2) = 0;
    }
    else {
      tmp2 = Unk096754_Unk_096ab0(tmp3);
      if (tmp2 == 0) {
        *(u32 *)(v4 + 2) = 0;
      }
      else {
        *(u32 *)(v4 + 2) = 1;
        *(u32 *)(v4 + 4) = 0;
        *v4 = *(u16 *)(tmp1 + 0x36);
        tmp1 = func_020a1428(((Unk10a034Work *)arg0)->unk_0024);
        v4[1] = (u16)*(u8 *)(tmp1 + 2);
      }
    }
    tmp3 = tmp3 + 1;
    v4 = v4 + 6;
    arg0 = arg0 + 0xc;
  } while (tmp3 < 0xc);
}

int Unk10a034_HasId(Unk10a034Obj *p, u32 x)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (x == p->ids[i]) {
            return 1;
        }
    }
    return 0;
}

void Unk10a034_ClearById(u8 *p, u32 id)
{
    int i;
    Unk10a034Ent *e = (Unk10a034Ent *)(p + 36);
    for (i = 0; i < 12; i++) {
        if (e->used != 0 && e->id == id) {
            e->val = 0;
            return;
        }
        e++;
    }
}

u32 func_0210b080();
u32 Unk10a034_GetEntry8(int i)
{
    u32 p;
    if (i < 0 || i >= 4) {
        return 0;
    }
    p = Unk10a034_Unk_10af7c();
    return p == 0 ? 0 : p + 32 + i * 8;
}

void Unk10a034_Alloc(u32 a, u32 b)
{
    if (*data_02176e44 != 0) {
        return;
    }
    *data_02176e44 = func_0210b080(a, b);
}

int Unk10a034_Unk_10b030(void)
{
    u32 p = Unk10a034_Get_data_02176e44();
    if (p == 0) {
        return 1;
    }
    return FIELD(u32, p, 8) == 10;
}
