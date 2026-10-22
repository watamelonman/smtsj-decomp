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
    u32 field0C;    /* 0x0C */
    u32 field10;    /* 0x10 */
    u32 unk14[3];
    u32 field20;    /* 0x20 */
    u32 field24;    /* 0x24 */
    u32 field28;    /* 0x28 */
    u32 field2C;    /* 0x2C */
    u32 field30;    /* 0x30 */
    u32 field34;    /* 0x34 */
    u32 unk38;
    u32 field3C;    /* 0x3C */
} GameObj;

void func_02065fc0(u32 a, u32 b, u32 c, int d, u32 e);
/* At 02065fac, forwards three words and inserts mode 3 before the fourth. */
void Unk065e88_Call_02065fc0(u32 a, u32 b, u32 c, u32 d)
{
    func_02065fc0(a, b, c, 3, d);
}

/*
 * Stores both words of the 0x04/0x08 pair. The two are always written together,
 * so they are kept adjacent in GameObj; callers use the pair as one record.
 */
void Unk065e88_SetPair04(GameObj *obj, u32 a, u32 b) {
    obj->pairA = a;
    obj->pairB = b;
}

/* Stores value in the unknown u32 at +0x20. */
void Unk065e88_SetUnkField20(GameObj *obj, u32 value) { obj->field20 = value; }

/* Stores value in the unknown u32 at +0x28. */
void Unk065e88_SetUnkField28(GameObj *obj, u32 value) { obj->field28 = value; }

/* Stores value in the unknown u32 at +0x24. */
void Unk065e88_SetUnkField24(GameObj *obj, u32 value) { obj->field24 = value; }

/* Stores value in the unknown u32 at +0x2C. */
void Unk065e88_SetUnkField2C(GameObj *obj, u32 value) { obj->field2C = value; }

/* Stores value in the unknown u32 at +0x30. */
void Unk065e88_SetUnkField30(GameObj *obj, u32 value) { obj->field30 = value; }

/* Stores value in the unknown u32 at +0x34. */
void Unk065e88_SetUnkField34(GameObj *obj, u32 value) { obj->field34 = value; }

typedef struct Unk065e88Flag {
    u8 pad_0000[0x3a];
    u8 unk_003a;
} Unk065e88Flag;

/* At 020662b8, cmp/movne/moveq normalize any nonzero input to byte 1. */
void Unk065e88_SetFlag3a(Unk065e88Flag *o, int on)
{
    o->unk_003a = on != 0;
}

extern u8 data_0214544c[];
extern u8 data_02144e44[];
/* At 020663d8, selectors 0 and 1 load the two literal table addresses.
 * Other selectors retain their incoming r0 value and are not valid tables. */
u32 *Unk065e88_GetTable(int i)
{
    if (i == 0) {
        return (u32 *)data_0214544c;
    }
    if (i == 1) {
        return (u32 *)data_02144e44;
    }
    return (u32 *)i;
}

/* At 020663f8, selectors 0 and 1 each have 193 words; others have none.
 * The two return constants and GetTableEntry indexing support the table name. */
int Unk065e88_GetTableCount(int i)
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

/* At 0206641c, converts a one-based index to a word offset in GetTable.
 * Offsets >= count - 1 select word zero; negative offsets are not clamped.
 * Callers must supply selector 0 or 1 and an index valid for the table. */
u32 *Unk065e88_GetTableEntry(int i, int n)
{
    n--;
    if (n >= Unk065e88_GetTableCount(i) - 1) {
        n = 0;
    }
    return Unk065e88_GetTable(i) + n;
}

/*
 * Empty callback (a bare return, 4 bytes). It has no direct callers but its address
 * is stored in a callback table by Unk065e88_Unk_06646c, so the body stays empty.
 */
void Unk065e88_Nop_066c90(void) { }



/* At 020662cc, stores one word at +0x3c; the field meaning is unknown. */
void Unk065e88_SetUnkField3c(GameObj *obj, u32 value)
{
    obj->field3C = value;
}

/* At 02066284, stores the two words at +0x0c and +0x10 in that order. */
void Unk065e88_SetUnkFieldsc_10(GameObj *obj, u32 a, u32 b)
{
    obj->field0C = a;
    obj->field10 = b;
}

typedef struct Unit020a1418Entry Unit020a1418Entry;
int func_020684c0(const void *record);
Unit020a1418Entry *func_020a1428(u16 id);
/* At 02068554, passes the resource-19 lookup result directly to 020684c0.
 * The caller must supply an id whose lookup produces a valid record. */
int Unk065e88_Unk_068554(u16 id)
{
    return func_020684c0(func_020a1428(id));
}

void func_0205bb68(void);
/* At 02065eac, invokes 0205bb68 three times without setting arguments. */
void Unk065e88_Unk_065eac(void)
{
    func_0205bb68();
    func_0205bb68();
    func_0205bb68();
}

/* This entry receives a word in r0 even though its current callee ignores it. */
void Unk05ae50_Unk_05af2c(u32 value);
void func_020617c8(u32 value);
/* At 020663bc, forwards arg1 to 0205af2c, then saved arg0 to 020617c8. */
void Unk065e88_Unk_0663bc(u32 arg0, u32 arg1)
{
    Unk05ae50_Unk_05af2c(arg1);
    func_020617c8(arg0);
}



/* At 0206644c, compares two readable halfword pairs by second word, then
 * first word on ties. Returns the signed difference, not a normalized sign. */
int Unk065e88_Unk_06644c(const u16 *arg0, const u16 *arg1)
{
  int value;
  value = (u32)arg0[1] - (u32)arg1[1];
  if (value == 0) {
    value = (u32)*arg0 - (u32)*arg1;
  }
  return value;
}

void Unk02e000_Unk_02e0cc(void);
void Unk05b82c_Unk_05b82c(int id);
/* At 02065e88, calls 0202e0cc, then submits ids 188, 189 and 190 to
 * 0205b82c in that order. No broader initialization purpose is established. */
void Unk065e88_Unk_065e88(void)
{
  Unk02e000_Unk_02e0cc();
  Unk05b82c_Unk_05b82c(0xbc);
  Unk05b82c_Unk_05b82c(0xbd);
  Unk05b82c_Unk_05b82c(0xbe);
}

void func_0205c3dc(u32 handle);
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_02095818();
void func_02063b80();
void func_020640c0();
void func_0206541c();
void func_02065438();
void func_02063b08();
void func_02063b4c();
void func_0205c704();
int func_0205ca88();
int func_0205caa0();

void Unk065e88_Unk_065ec0(u32 *p)
{
    p[0] = 120;
    func_02095818();
    p[1] = 4;
    FIELD(u16, p, 8) = 100;
    p[3] = (u32)func_02063b80;
    p[4] = (u32)func_020640c0;
    p[5] = (u32)func_0206541c;
    p[6] = (u32)func_02065438;
    p[7] = (u32)func_02063b08;
    p[8] = (u32)func_02063b4c;
}

/* At 02066258, forwards a nonzero handle to 0205c3dc and clears its slot.
 * The caller owns a writable slot; zero requires no call. */
void Unk065e88_Unk_066258(u32 *arg0)
{
  if (*arg0 == 0) {
    return;
  }
  func_0205c3dc(*arg0);
  *arg0 = 0;
}

typedef struct Unk065e88Resource Unk065e88Resource;
Unk065e88Resource *func_020445d0(u32 arg0, u32 arg1);
void *func_0204fde0(Unk065e88Resource *resource);
u32 func_0204fe18(Unk065e88Resource *resource);
/* At 02067d30, forwards both inputs to 020445d0, writes the low halfword
 * of 0204fe18(resource) to the caller-owned output, then calls 0204fde0. */
void Unk065e88_Unk_067d30(u32 arg0,u32 arg1,u16 *arg2)
{
  u16 value1;
  Unk065e88Resource *value2;
  value2 = func_020445d0(arg0, arg1);
  value1 = func_0204fe18(value2);
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

/* Partial readable record layout established by the loads at 02068564. */
typedef struct Unk065e88Obj24 {
    u8 pad_0000[0x24];
    u32 pad_0024_0 : 28;
    u32 flag_0024_28 : 1;
    u8 pad_0028[2];
    u16 unk_002a;
} Unk065e88Obj24;

void func_02072238(s32 *object);
int Unk0e651c_Unk_0e666c(u32 id);
int func_020684c0(const void *record);
void Unk065e88_Unk_066078(u8 *p)
{
    if (p[56] != 0) {
        func_0205c704(FIELD(u32, p, 0));
    }
    if (p[57] == 0) {
        return;
    }
    {
        int n = func_0205ca88(FIELD(u32, p, 0));
        if (func_0205caa0(FIELD(u32, p, 0)) >= n - 1) {
            p[56] = 0;
            p[57] = 0;
        }
    }
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_020667d0();
void Unk065e88_Nop_066c90();
void func_02066c94();
void func_02066d30();
void func_020664c4();
void func_02063920();
int func_020445f4();
int func_0204fed8();
int func_02063a30();
void func_02061f10();

void Unk065e88_Unk_06646c(u32 *p)
{
    p[0] = 1104;
    p[1] = 4;
    p[3] = 0;
    p[4] = (u32)func_020667d0;
    p[5] = (u32)Unk065e88_Nop_066c90;
    p[6] = (u32)func_02066c94;
    p[7] = (u32)func_02066d30;
    p[8] = (u32)func_020664c4;
}

/* At 020672b4, stores the mode word, then optionally dispatches mode 1
 * to 02072238 or sets a word at +0x220 (mode 2) / +0x2f0 (mode 4).
 * Those stores and dispatch establish the name; o must cover the selected field. */
void Unk065e88_SetMode(s32 *o, s32 v, int notify)
{
    o[0] = v;
    if (notify == 0) {
        return;
    }
    switch (o[0]) {
    case 1:
        func_02072238(o);
        break;
    case 2:
        FIELD(u32, o, 0x220) = 1;
        break;
    case 4:
        FIELD(u32, o, 0x2f0) = 1;
        break;
    }
}

void Unk065e88_Unk_0672fc(u8 *p, int a, u32 n)
{
    int r;
    int h;
    u32 i;
    func_02063920();
    h = func_020445f4(12, a);
    for (i = 0; i < n; i++) {
        r = func_02063a30(func_0204fed8(h, i));
    }
    func_02061f10(FIELD(u32, p, 264), -1, 0, 0, r);
}

/* At 02068564, rejects bit 28 at +0x24, then requires either a zero id
 * at +0x2a or a nonzero 020e666c result, and a nonzero 020684c0 result.
 * The caller supplies a readable record; the returned predicate is 0 or 1. */
int Unk065e88_Unk_068564(Unk065e88Obj24 *o)
{
    if (!o->flag_0024_28 && (o->unk_002a == 0 || Unk0e651c_Unk_0e666c(o->unk_002a) != 0) && func_020684c0(o) != 0) {
        return 1;
    }
    return 0;
}
