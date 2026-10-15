/*
 * unit_02065e88: small accessors for a game object whose fields are written
 * from many systems (callers in 0x020a7..., 0x020b7..., 0x020fe...).
 * Field meanings are not known yet; offsets are named by position.
 */
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned long long u64;
typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
typedef unsigned int u32;

typedef struct GameObj {
    u32 unk00;
    u32 pairA;      /* 0x04: first of a pair set together */
    u32 pairB;      /* 0x08: second of the pair */
    u32 unk0C[5];
    u32 field20;    /* 0x20 */
    u32 field24;    /* 0x24 */
    u32 field28;    /* 0x28 */
    u32 field2C;    /* 0x2C */
    u32 field30;    /* 0x30 */
    u32 field34;    /* 0x34 */
} GameObj;

void func_02065fc0(u32 a, u32 b, u32 c, int d, u32 e);
void Unk065e88_Call_02065fc0(u32 a, u32 b, u32 c, u32 d)
{
    func_02065fc0(a, b, c, 3, d);
}

/* Stores both halves of the 0x04/0x08 pair. */
void Unk065e88_SetPair04(GameObj *obj, u32 a, u32 b) {
    obj->pairA = a;
    obj->pairB = b;
}

/* Setters for single fields. */
void Unk065e88_SetUnkField20(GameObj *obj, u32 value) { obj->field20 = value; }
void Unk065e88_SetUnkField28(GameObj *obj, u32 value) { obj->field28 = value; }
void Unk065e88_SetUnkField24(GameObj *obj, u32 value) { obj->field24 = value; }
void Unk065e88_SetUnkField2C(GameObj *obj, u32 value) { obj->field2C = value; }
void Unk065e88_SetUnkField30(GameObj *obj, u32 value) { obj->field30 = value; }
void Unk065e88_SetUnkField34(GameObj *obj, u32 value) { obj->field34 = value; }

typedef struct Unk065e88Flag {
    u8 pad_0000[0x3a];
    u8 unk_003a;
} Unk065e88Flag;

void Unk065e88_SetFlag3a(Unk065e88Flag *o, int on)
{
    o->unk_003a = on != 0;
}

extern u8 data_0214544c[];
extern u8 data_02144e44[];
u32 *func_020663d8(int i)
{
    if (i == 0) {
        return (u32 *)data_0214544c;
    }
    if (i == 1) {
        return (u32 *)data_02144e44;
    }
    /* no return for other i: the ROM falls through with i still in r0 */
}

int func_020663f8(int i)
{
    int n = 0;
    switch (i) {
    case 0:
        n = 193;
        break;
    case 1:
        n = 193;
        break;
    }
    return n;
}

u32 *func_0206641c(int i, int n)
{
    n--;
    if (n >= func_020663f8(i) - 1) {
        n = 0;
    }
    return func_020663d8(i) + n;
}

/* Empty callback (no callers; likely a function-table entry). */
void Unk065e88_Nop_066c90(void) { }



/* set u32 at +0x3c */
void Unk065e88_SetUnkField3c(void *obj, u32 value) { FIELD(u32, obj, 0x3c) = value; }


/* set +0xc and +0x10 */
void Unk065e88_SetUnkFieldsc_10(void *obj, u32 a, u32 b) {
    FIELD(u32, obj, 0xc) = a;
    FIELD(u32, obj, 0x10) = b;
}

int func_020684c0();
int func_020a1428();
/* decompiler-derived */
void Unk065e88_Unk_068554(void)
{
  func_020a1428();
  func_020684c0();
}

int func_0205bb68();
/* decompiler-derived */
void Unk065e88_Unk_065eac(void)
{
  func_0205bb68();
  func_0205bb68();
  func_0205bb68();
}

int Unk05ae50_Unk_05af2c();
int func_020617c8();
/* decompiler-derived */
void Unk065e88_Unk_0663bc(u32 arg0,u32 arg1)
{
  Unk05ae50_Unk_05af2c(arg1);
  func_020617c8(arg0);
}



/* decompiler-derived */
int Unk065e88_Unk_06644c(u16 *arg0,u16 *arg1)
{
  int value;
  value = (u32)arg0[1] - (u32)arg1[1];
  if (value == 0) {
    value = (u32)*arg0 - (u32)*arg1;
  }
  return value;
}

int Unk02e000_Unk_02e0cc();
int Unk05b82c_Unk_05b82c();
/* decompiler-derived */
void Unk065e88_Unk_065e88(void)
{
  Unk02e000_Unk_02e0cc();
  Unk05b82c_Unk_05b82c(0xbc);
  Unk05b82c_Unk_05b82c(0xbd);
  Unk05b82c_Unk_05b82c(0xbe);
}

int func_0205c3dc();
/* decompiler-derived */
void Unk065e88_Unk_066258(int *arg0)
{
  if (*arg0 == 0) {
    return;
  }
  func_0205c3dc();
  *arg0 = 0;
}

int func_020445d0();
int func_0204fde0();
int func_0204fe18();
/* decompiler-derived */
void Unk065e88_Unk_067d30(u32 arg0,u32 arg1,u16 *arg2)
{
  u16 value1;
  u32 value2;
  value2 = func_020445d0();
  value1 = func_0204fe18();
  *arg2 = value1;
  func_0204fde0(value2);
}


extern u8 data_0216b9a8[];
int func_02008848();
int func_020629ac();
int func_02063a6c();
/* decompiler-derived */
void Unk065e88_Unk_065f30(int *arg0)
{
  int value;
  func_02008848(arg0,0,0x78);
  value = func_020629ac(5,4,1,1);
  *arg0 = value;
  if (value == 0) {
    return;
  }
  value = func_020629ac(4,1,1,1);
  arg0[1] = value;
  if (value == 0) {
    return;
  }
  arg0[3] = 0;
  arg0[2] = 0;
  arg0[0x13] = 0;
  func_02063a6c(arg0);
  *(int **)(((int)data_0216b9a8) + 4) = arg0;
}


