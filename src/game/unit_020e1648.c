/*
 * src/game/unit_020e1648.c: matched functions (see docs/functions/game-unit-020e1648.md).
 * Field meanings are not known yet, so layouts are modelled with typed structs and guessed
 * sizes; functions that are still decompiler-derived are marked at their definitions.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))


/* One 8-byte entry of the record table at work->unk_00d2; entry count is guessed. */
typedef struct Unk0e1648Slot {
    u16 unk_0000;
    u16 unk_0002;
    u16 unk_0004;
    u16 pad_0006;
} Unk0e1648Slot;

/* 32-bit handle table at +0xc of the object; the entry count is guessed. */
typedef struct Unk0e1648Table {
    u8 pad_0000[0xc];
    u32 unk_000c[32];
} Unk0e1648Table;

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0e1648Work {
    u8 pad_0000[0x4];
    u16 unk_0004;
    u16 unk_0006;
    u8 pad_0008[0x60];
    u32 unk_0068;
    u8 pad_006c[0x10];
    s32 unk_007c;
    u8 pad_0080[0x50];
    u16 unk_00d0;
    Unk0e1648Slot unk_00d2[441]; /* 441 eight-byte entries fill the 0xdce-byte gap. */
    u8 pad_0e9a[6];
    u32 unk_0ea0;
    u8 pad_0ea4[0x1c];
    s32 unk_0ec0;
    u8 pad_0ec4[0x20];
    u32 unk_0ee4;
} Unk0e1648Work;

extern u32 data_02176c78[];
void Unk0e7ac4_Unk_0e8014(u32 arg0);
void Unk0e7ac4_Unk_0e8030(u32 arg0);

u32 Unk0e1648_Unk_0e5240(Unk0e1648Table *table, int index);
u32 Unk0e1648_Get_data_02176c78(void);
Unk0e1648Slot *Unk0e1648_Unk_0e2da0(Unk0e1648Work *work);
void Unk0e1648_Unk_0e2cb0(Unk0e1648Work *work);
void Unk0e1648_Unk_0e5434(void);
int Unk0e1648_Unk_0e1648(void);
int Unk0e1648_Unk_0e2c90(Unk0e1648Work *work,Unk0e1648Work *other);

typedef struct Unk0e1648Obj {
    u8 pad_0000[0xeec];
    u8 unk_0eec;
} Unk0e1648Obj;

/*
 * Reports whether the byte at +0xeec is still in use. Both the initialiser
 * (Unk0e1648_Unk_0e16f0) and the teardown path (Unk0e1648_Unk_0e2f54) store
 * 0xff there, so 0xff is the "cleared" marker and any other value means set.
 */
int Unk0e1648_IsUnkeecSet(Unk0e1648Obj *o)
{
    return o->unk_0eec != 0xff;
}

/*
 * Reads entry `index` of the Unk0e1648Table handle array. The 0e51cc/0e51f4/
 * 0e5214 helpers all use this to fetch the handle they pass to the
 * 0205c41c/0205caa8/0205c6ec functions.
 */
u32 Unk0e1648_Unk_0e5240(Unk0e1648Table *table,int index)
{
  return table->unk_000c[index];
}

/*
 * Returns word 0 of the global state block data_02176c78. Word 1 of the same
 * block is treated as a pointer by Unk0e1648_Unk_0e1664, so this is the plain
 * first-word accessor.
 */
u32 Unk0e1648_Get_data_02176c78(void)
{
  return *data_02176c78;
}

/*
 * Returns the Unk0e1648Slot selected by work->unk_007c. Callers read its
 * unk_0002/unk_0004 fields; Unk0e1648_Unk_0e2d80, for example, passes
 * unk_0002 to func_020f3de8.
 */
Unk0e1648Slot *Unk0e1648_Unk_0e2da0(Unk0e1648Work *work)
{
  return &work->unk_00d2[work->unk_007c];
}

/*
 * Flips the boolean stored at work->unk_0ec0: zero becomes one and any non-zero
 * value becomes zero.
 */
void Unk0e1648_Unk_0e2cb0(Unk0e1648Work *work)
{
  work->unk_0ec0 = (u32)(work->unk_0ec0 == 0);
}

/*
 * Forwards zero to both Unk0e7ac4_Unk_0e8014 and Unk0e7ac4_Unk_0e8030, i.e. it
 * clears/resets those two subsystems in sequence.
 */
void Unk0e1648_Unk_0e5434(void)
{
  Unk0e7ac4_Unk_0e8014(0);
  Unk0e7ac4_Unk_0e8030(0);
}

/*
 * Returns 1 when word 1 of data_02176c78 is null, else 0. Unk0e1648_Unk_0e1664
 * uses this as a guard before dereferencing that word.
 */
int Unk0e1648_Unk_0e1648(void)
{
  return data_02176c78[1] == 0;
}

int Unk09974c_GetEntryUnk08();
u32 Unk0e1648_Unk_0e1664(void)
{
    if (Unk0e1648_Unk_0e1648() != 0) {
        return 0;
    }
    return FIELD(u32, FIELD(u8 *, data_02176c78, 4), 88);
}

/*
 * Lexicographic comparison of two work objects. Returns the difference of the
 * unk_0006 words, or, when those are equal, the difference of the unk_0004
 * words. A zero result therefore means both keys match.
 */
int Unk0e1648_Unk_0e2c90(Unk0e1648Work *work,Unk0e1648Work *other)
{
  int value;
  value = (u32)work->unk_0006 - (u32)other->unk_0006;
  if (value == 0) {
    value = (u32)work->unk_0004 - (u32)other->unk_0004;
  }
  return value;
}


int func_020f3de8();
/* decompiler-derived */
void Unk0e1648_Unk_0e2d80(int arg0)
{
  func_020f3de8(((Unk0e1648Work *)arg0)->unk_0068,
                  *(u16 *)(arg0 + ((Unk0e1648Work *)arg0)->unk_007c * 8 + 0xd4));
}

int func_0209993c();
/* decompiler-derived */
int Unk0e1648_Unk_0e4f34(u32 arg0,int arg1)
{
  int value;
  value = func_0209993c();
  if (99 < value + arg1) {
    arg1 = 99 - value;
  }
  return arg1;
}

int func_020445f4();
int func_0204fed8();
/* decompiler-derived */
void Unk0e1648_Unk_0e50c8(u32 arg0)
{
  u32 value;
  value = func_020445f4(0x1e,3);
  func_0204fed8(value,arg0);
}

int Unk09974c_GetEntryUnk08();
/* decompiler-derived */
int Unk0e1648_Unk_0e3f5c(int arg0)
{
  int value;
  value = Unk09974c_GetEntryUnk08(*(u16 *)(arg0 + ((Unk0e1648Work *)arg0)->unk_007c * 8 + 0xd6));
  return value == 4;
}


/* decompiler-derived */
u32 Unk0e1648_Unk_0e4fd0(int arg0,u32 arg1)
{
  int value;
  if ((arg0 == 4) && (value = func_0209993c(arg1), 0 < value)) {
    return 1;
  }
  return 0;
}


void Unk0e1648_Unk_0e5090(u32 arg0,u32 arg1);
int func_020e544c();
/* decompiler-derived */
void Unk0e1648_Unk_0e533c(int arg0)
{
  int tmp1;
  tmp1 = func_020e544c();
  if (tmp1 != 0) {
    Unk0e1648_Unk_0e5090(((Unk0e1648Work *)arg0)->unk_0ea0,2);
    return;
  }
  Unk0e1648_Unk_0e5090(((Unk0e1648Work *)arg0)->unk_0ea0,3);
  return;
}


extern u8 data_02176c80[];
int Unk02e000_Unk_02e0cc();
int Unk0fc584_Unk_0fc84c();
/* decompiler-derived */
void Unk0e1648_Unk_0e16f0(u8 *arg0)
{
  *(u8 **)(((int)data_02176c80) + 4) = arg0;
  Unk02e000_Unk_02e0cc();
  Unk0fc584_Unk_0fc84c(0);
  ((Unk0e1648Work *)arg0)->unk_0ee4 = 0;
  arg0[1] = 0;
  *arg0 = 1;
  arg0[0xeec] = 0xff;
  return;
}


int func_0204faf0();
int func_020e49cc();
int Unk0e1648_Unk_0e2d28(u8 *p)
{
    u16 *e;
    if (FIELD(u32, p, 104) != 1) {
        return 0;
    }
    e = (u16 *)func_020f3de8(1, FIELD(u16, p + FIELD(u32, p, 124) * 8, 212));
    return Unk09974c_GetEntryUnk08(*e) == 4;
}

void Unk0e1648_Unk_0e51cc(u32 arg0, u32 arg1);
int Unk09974c_Unk_09a1e4();
void func_020e3174();
int Unk0f3db4_Unk_0f4510();
void func_020e5394();
int Unk0e1648_Unk_0e2db0(u16 *p)
{
    int a = func_0209993c(p[0]);
    int b = p[1];
    if (Unk09974c_Unk_09a1e4(p[0]) != 0) {
        return 0;
    }
    return b > a ? 1 : 2;
}

int Unk0e1648_IsId177to179(int x)
{
    switch (x) {
    case 177:
    case 178:
    case 179:
        return 1;
    }
    return 0;
}

void Unk0e1648_Unk_0e2f54(u8 *p)
{
    if (p[3820] == 255) {
        return;
    }
    func_020e3174(p);
    Unk0e1648_Unk_0e51cc((u32)p, 0);
    p[3820] = 255;
}

/* decompiler-derived */
void Unk0e1648_Unk_0e4964(u32 arg0)
{
  u32 tmp1;
  u32 tmp2;
  tmp1 = Unk09974c_GetEntryUnk08();
  tmp2 = 0;
  switch(tmp1) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    goto LAB_020e499c;
  case 4:
LAB_020e499c:
    tmp2 = func_020e49cc(6,arg0);
    break;
  case 5:
    goto LAB_020e49b0;
  case 6:
LAB_020e49b0:
    tmp2 = func_020e49cc(7,arg0);
  }
  func_0204faf0(1,tmp2);
  return;
}

extern u8 data_0213c674[];
int func_0205caa8();
/* decompiler-derived */
void Unk0e1648_Unk_0e51f4(u32 arg0,int arg1)
{
  u32 tmp1;
  tmp1 = Unk0e1648_Unk_0e5240((Unk0e1648Table *)arg0, arg1);
  func_0205caa8(tmp1,*(u32 *)(data_0213c674 + arg1 * 4));
}

int func_0205c41c();
/* decompiler-derived */
void Unk0e1648_Unk_0e51cc(u32 arg0,u32 arg1)
{
  u32 tmp1;
  tmp1 = Unk0e1648_Unk_0e5240((Unk0e1648Table *)arg0, arg1);
  func_0205c41c(tmp1,0);
  Unk0e1648_Unk_0e51f4(arg0,arg1);
}

int func_0205c6ec();
/* decompiler-derived */
void Unk0e1648_Unk_0e5214(u32 arg0,u32 arg1)
{
  u32 tmp1;
  tmp1 = Unk0e1648_Unk_0e5240((Unk0e1648Table *)arg0, arg1);
  func_0205c41c(tmp1,0);
  Unk0e1648_Unk_0e5240((Unk0e1648Table *)arg0, arg1);
  func_0205c6ec();
}

int func_02061f10();
int func_02063920();
int func_02063a30();
/* decompiler-derived */
void Unk0e1648_Unk_0e5090(u32 arg0,u32 arg1)
{
  u32 tmp1;
  func_02063920();
  Unk0e1648_Unk_0e50c8(arg1);
  tmp1 = func_02063a30();
  func_02061f10(arg0,0xffffffff,0,0,tmp1);
}

int Unk0f3db4_Unk_0f4448();
/* decompiler-derived */
void Unk0e1648_Unk_0e48a8(int arg0,u32 arg1)
{
  u16 tmp1;
  int tmp2;
  tmp2 = Unk0f3db4_Unk_0f4448(arg1);
  if (tmp2 < 1) {
    return;
  }
  tmp2 = func_020e49cc(3,arg1);
  if (tmp2 != 0) {
    return;
  }
  *(short *)(arg0 + (u32)((Unk0e1648Work *)arg0)->unk_00d0 * 8 + 0xd6) = (short)arg1;
  tmp1 = func_020e49cc(4,arg1);
  *(u16 *)(arg0 + (u32)((Unk0e1648Work *)arg0)->unk_00d0 * 8 + 0xd8) = tmp1;
  ((Unk0e1648Work *)arg0)->unk_00d0 = ((Unk0e1648Work *)arg0)->unk_00d0 + 1;
}

int Unk0e1648_Unk_0e4c64(u8 *p, u32 x)
{
    if (((u8 *)func_020f3de8(FIELD(u32, p, 104)))[3] == 0) {
        return 0;
    }
    return Unk0f3db4_Unk_0f4510(FIELD(u32, p, 104), x) != 0;
}

typedef struct Unk0e1648Ent {
    u16 a;
    u16 b;
} Unk0e1648Ent;
typedef struct Unk0e1648Rec {
    u16 id;
    u8 pad_02;
    u8 unk_03;
    u8 pad_04[6];
    Unk0e1648Ent ents[3];
} Unk0e1648Rec;

int Unk0e1648_Unk_0e4f54(Unk0e1648Rec *p)
{
    int m = 0;
    int r;
    int i;
    int c;
    if (p->unk_03 != 0) {
        m = 1;
    } else {
        for (i = 0; i < 3; i++) {
            if (p->ents[i].a != 0 && m < p->ents[i].b) {
                m = p->ents[i].b;
            }
        }
    }
    if (m <= 0) {
        r = 99;
    } else {
        r = 99 / m;
    }
    c = Unk0e1648_Unk_0e4f34(p->id, 99);
    if (r > c) {
        r = c;
    }
    return r;
}

void Unk0e1648_Unk_0e536c(u8 *p)
{
    FIELD(u32, p, 3816) = 1;
    FIELD(u32, p, 3776) = FIELD(u32, p, 3780);
    func_020e5394(p);
    p[0] = 7;
}
