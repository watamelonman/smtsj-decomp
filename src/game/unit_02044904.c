/*
 * src/game/unit_02044904.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_0215ee98[];
int func_0206df10();
int Unk071dc0_Unk_072200();
int Unk09d060_Unk_09d13c();

int Unk044904_GetConst1(void);
u32 Unk044904_Get_data_0215ee98(void);
u32 Unk044904_Unk_0459ec(void);
void Unk044904_Unk_045c98(void);
void Unk044904_Unk_044e90(int arg0);
int Unk044904_Unk_045fd4(void);
void Unk044904_Unk_044ea8(void);

typedef struct Unk044904Rec {
    u8 pad_0000[0x8];
    u16 unk_08;
} Unk044904Rec;

Unk044904Rec *func_02044948(u32 a, u32 b);

typedef struct Unk044904Entry {
    u16 id;
    u8 pad_0002[10];
} Unk044904Entry;

Unk044904Entry *Unk044904_FindById(Unk044904Entry *tbl, u16 key)
{
    u32 i;
    Unk044904Entry *e;
    for (i = 0; i < FIELD(u32, tbl, 0x60); i++) {
        e = &tbl[i];
        if (key == e->id) {
            return &tbl[i];
        }
    }
    return 0;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
u32 Unk044904_Get_data_0215ee98(void);
void func_02008848();
int func_02049a84();
void func_0204a8cc();

Unk044904Rec *func_02044948(u32 a, u32 key)
{
    u8 *p = (u8 *)a;
    u32 n = FIELD(u32, p, 96);
    u32 i;
    u8 *e;
    typedef struct Unk044904Slot { u16 id; u8 pad[10]; } Unk044904Slot;
    for (i = 0; i < n; i++) {
        if (key == ((Unk044904Slot *)p)[i].id) {
            return (Unk044904Rec *)(p + i * 12);
        }
    }
    if (n >= 8) {
        return 0;
    }
    e = p + n * 12;
    func_02008848(e, 0, 12);
    FIELD(u16, e, 0) = key;
    FIELD(u32, p, 96)++;
    return (Unk044904Rec *)e;
}

void Unk044904_AddRecUnk08(u32 a, u32 b, int n)
{
    Unk044904Rec *r = func_02044948(a, b);
    r->unk_08 += n;
}

typedef struct Unk044904Obj {
    u32 unk_0000;               /* bits 16-23 tested as "active" */
    u8 pad_0004[0x1da];
    u8 unk_01de;
} Unk044904Obj;

typedef struct Unk044904Mgr {
    u8 pad_0000[0x40];
    u32 pad_0040_0 : 10;
    u32 flag_0040_10 : 1;
    u32 pad_0040_11 : 4;
    u32 flag_0040_15 : 1;
    u32 flag_0040_16 : 1;
    u32 pad_0040_17 : 1;
    u32 flag_0040_18 : 1;
    u8 pad_0044[0xc];
    u32 unk_0050;
    u32 unk_0054;
    u8 pad_0058[0xc];
    Unk044904Obj *slots[10];    /* +0x64 */
} Unk044904Mgr;

#define UNK044904_MGR() ((Unk044904Mgr *)Unk044904_Get_data_0215ee98())
void func_0204a780();
void func_0204a694();
void Unk0bc1a8_Unk_0bc928();
Unk044904Obj *Unk044904_GetSlot(int i)
{
    Unk044904Mgr *m = UNK044904_MGR();
    if (m == 0) {
        return 0;
    }
    if (i < 0) {
        return 0;
    }
    if (i >= 4) {
        return 0;
    }
    return m->slots[i];
}

void Unk044904_Unk_04527c(void)
{
    int i;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = UNK044904_MGR()->slots[i];
        if (o != 0 && (o->unk_0000 >> 16 & 0xff)) {
            func_0204a780(o, 11);
        }
    }
}

void Unk044904_ClearSlotsUnk1de(void)
{
    int i;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = UNK044904_MGR()->slots[i];
        if (o != 0) {
            o->unk_01de = 0;
        }
    }
}

void Unk044904_ForEachSlot_04a694(void)
{
    int i;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = UNK044904_MGR()->slots[i];
        if (o != 0) {
            func_0204a694(o);
        }
    }
}

Unk044904Obj *Unk044904_FindInactiveSlot(void)
{
    int i;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = UNK044904_MGR()->slots[i];
        if (o != 0 && (o->unk_0000 >> 16 & 0xff) == 0) {
            return o;
        }
    }
    return 0;
}

void Unk044904_Unk_0459fc(void)
{
    if (UNK044904_MGR()->flag_0040_10) {
        return;
    }
    UNK044904_MGR()->unk_0050 = 1;
    UNK044904_MGR()->unk_0054 = 0;
}

int Unk044904_GetFlag18(void)
{
    return UNK044904_MGR()->flag_0040_18 ? 1 : 0;
}

void Unk044904_Unk_045c58(int x)
{
    if (x != 1) {
        return;
    }
    Unk0bc1a8_Unk_0bc928(26, 0xffff, 0);
}

/* returns 1 */
int Unk044904_GetConst1(void) { return 1; }

/* decompiler-derived */
u32 Unk044904_Get_data_0215ee98(void)
{
  return *data_0215ee98;
}

/* decompiler-derived */
u32 Unk044904_Unk_0459ec(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  return *(u32 *)(value + 0x50);
}

/* decompiler-derived */
void Unk044904_Unk_045c98(void)
{
  func_0206df10();
  Unk071dc0_Unk_072200();
}

/* decompiler-derived */
void Unk044904_Unk_044e90(int arg0)
{
  if (*data_0215ee98 == 0) {
    *data_0215ee98 = arg0;
  }
}

/* decompiler-derived */
int Unk044904_Unk_045fd4(void)
{
  int value;
  value = Unk09d060_Unk_09d13c();
  return value != 0;
}

/* decompiler-derived */
void Unk044904_Unk_044ea8(void)
{
  if (*data_0215ee98 != 0) {
    *data_0215ee98 = 0;
  }
}



int func_02044f4c(u32 k)
{
    typedef struct Unk044904Objs { u8 pad[100]; u32 objs[10]; } Unk044904Objs;
    u8 *t = (u8 *)Unk044904_Get_data_0215ee98();
    int i;
    if (t == 0) {
        return 0;
    }
    for (i = 0; i < 10; i++) {
        u32 o = ((Unk044904Objs *)t)->objs[i];
        if (o != 0 && func_02049a84(o, k) != 0) {
            return i;
        }
    }
    return -1;
}

/* decompiler-derived */
int Unk044904_Unk_044fd8(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x379c;
  }
  return value;
}


/* decompiler-derived */
int Unk044904_Unk_044ff4(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x3fb0;
  }
  return value;
}


/* decompiler-derived */
int Unk044904_Unk_045010(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x77bc;
  }
  return value;
}


/* decompiler-derived */
int Unk044904_Unk_04502c(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x372c;
  }
  return value;
}


/* decompiler-derived */
int Unk044904_Unk_045048(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x7804;
  }
  return value;
}


/* decompiler-derived */
int Unk044904_Unk_045064(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x7874;
  }
  return value;
}


/* decompiler-derived */
int Unk044904_Unk_045080(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x78e4;
  }
  return value;
}


/* decompiler-derived */
int Unk044904_Unk_04509c(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x7970;
  }
  return value;
}


int Unk0bc1a8_IsSlotEmpty();
void func_020453dc(void)
{
    typedef struct Unk044904Objs { u8 pad[100]; u32 objs[10]; } Unk044904Objs;
    int i;
    int one = 1;
    for (i = 0; i < 10; i++) {
        u8 *o = (u8 *)((Unk044904Objs *)Unk044904_Get_data_0215ee98())->objs[i];
        if (o != 0 && ((FIELD(u32, o, 0) >> 16) & 0xff) != 0) {
            func_0204a8cc(o, one);
        }
    }
    FIELD(u32, Unk044904_Get_data_0215ee98(), 88) = 0;
}

/* decompiler-derived */
int Unk044904_Unk_045c7c(void)
{
  int value;
  value = Unk0bc1a8_IsSlotEmpty(0x1a);
  return value == 0;
}

int func_020452c4();
int Unk0aa118_SortRemaining();
void func_02045bd0();
void func_020456d8();
void func_020455cc();
int Unk044904_Unk_046468(s16 *st)
{
    Unk044904Mgr *m = UNK044904_MGR();
    FIELD(u16, m, 0x38)++;
    FIELD(u32, m, 0x40) &= ~0x10000;
    st[0] = 2;
    return 1;
}

int Unk044904_Unk_04661c(s16 *st)
{
    if (st[1] == 1) {
        st[0] = 2;
    } else {
        func_02045bd0(0);
    }
    return 2;
}

int Unk044904_Unk_046644(void)
{
    if (UNK044904_MGR()->flag_0040_16 && Unk044904_Unk_045460(1) != 0) {
        return 2;
    }
    func_020456d8(0);
    func_020455cc(2);
    return 1;
}

/* decompiler-derived */
u32 Unk044904_Unk_046688(void)
{
  func_020452c4();
  Unk044904_Unk_044fd8();
  Unk0aa118_SortRemaining();
  Unk044904_Unk_045c98();
  return 1;
}


/* decompiler-derived */
int Unk044904_Unk_045460(int arg0)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  return arg0 == *(int *)(value + 0x5c);
}

int func_02045ca8();
/* decompiler-derived */
u32 Unk044904_Unk_046448(u16 *arg0)
{
  int value;
  value = func_02045ca8();
  if (value != 0) {
    *arg0 = 2;
  }
  return 1;
}


int func_020450b8();
int func_02045138();
void Unk044904_Unk_04527c();
int Unk0aa118_Clear814();
int func_020f8098();
/* decompiler-derived */
u32 Unk044904_Unk_046108(u16 *arg0)
{
  u32 value1;
  int value2;
  Unk044904_Unk_044fd8();
  Unk0aa118_Clear814();
  func_02045138();
  Unk044904_Unk_04527c();
  func_020450b8();
  value1 = Unk044904_Unk_045080();
  value2 = func_020f8098(value1,0,0);
  if (value2 != 0) {
    *arg0 = 2;
  }
  return 2;
}


int Unk0a5680_Unk_0a5c14();
/* decompiler-derived */
u32 Unk044904_Unk_04599c(u32 *arg0)
{
  int value1;
  u32 value2;
  int value3;
  value2 = 0;
  value3 = 0;
  do {
    if ((*arg0 != 0) &&
       (value1 = Unk0a5680_Unk_0a5c14(*arg0 & 0xffff,arg0[1],arg0[2]), value1 != 0)) {
      value2 = 1;
    }
    value3 = value3 + 1;
    arg0 = arg0 + 3;
  } while (value3 < 6);
  return value2;
}

extern u8 data_02142b4c[];
extern u8 data_02142b64[];
int func_02013c3c();
int func_020513d4();
int func_020a1740();
/* Builds "Data/Enemy/AI/ai_%s.bf" for an enemy; falls back to ai_scr_test.bf if missing. */
void Unk044904_BuildEnemyAiPath(u32 arg0,u32 arg1)
{
  int tmp1;
  tmp1 = func_020a1740(arg1);
  if (tmp1 != 0) {
    func_02013c3c(arg0,data_02142b4c,tmp1 + 0x6c);
    tmp1 = func_020513d4(arg0);
    if (tmp1 != 0) {
      return;
    }
  }
  func_02013c3c(arg0,data_02142b64);
}
