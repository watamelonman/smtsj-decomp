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
u8 *Unk0aa118_Unk_0af8d8(int a, u32 id, int c);

void Unk0aa118_Nop_0ae054(void);
u8 *Unk0aa118_Thunk_020af8d8(int a, u32 id, int c);
void Unk0aa118_Unk_0ab454(void);
int Unk0aa118_Unk_0ab4b8(void);

typedef struct Unk0aa118List {
    u32 item[0x20];             /* +0x00 */
    u32 pos;                    /* +0x80 */
    u32 count;                  /* +0x84 */
} Unk0aa118List;

void func_02013c68();
void func_020aa130();
void Unk0aa118_Clear814(void *p)
{
    func_02008848(p, 0, 0x814);
}

int Unk0aa118_CompareItems(u32 **a, u32 **b)
{
    if ((*b)[5] == (*a)[5]) {
        if ((*a)[0] == (*b)[0]) {
            return 0;
        }
        return (*a)[0] > (*b)[0] ? 1 : -1;
    }
    return (*b)[5] > (*a)[5] ? 1 : -1;
}

void Unk0aa118_SortRemaining(Unk0aa118List *l)
{
    func_02013c68(&l->item[l->pos], l->count - l->pos, 4, Unk0aa118_CompareItems);
}

u32 Unk0aa118_PeekItem(Unk0aa118List *l)
{
    if (l->pos >= l->count) {
        return 0;
    }
    return l->item[l->pos];
}

int Unk0aa118_Advance(Unk0aa118List *l)
{
    l->pos++;
    func_020aa130(l);
    if (l->pos >= l->count) {
        l->pos = l->count;
        return 0;
    }
    return 1;
}

void func_020aa4f4();
void func_020ae1e8();
extern u8 data_02176b18[];
int Unk044904_Get_data_0215ee98();
int func_020b081c();
int func_0204add4();
void func_0204a7b4();
extern u32 data_0214d2f4[];
extern u8 data_0214d398[];
int func_020152cc();
int func_020491b4();
int func_0205f2e4();
int func_0205f41c();
int func_0204fd18();
int func_0204fdac();
int func_0204fe18();
int func_02099d14();
extern u8 data_0214fef8[];
extern u32 data_0214d380[];
int func_0204fde0(int t);
u8 *Unk0aa118_FindRecord(u32 id);
int Unk0aa118_Unk_0af7cc(u32 i);
int Unk0aa118_Unk_0af7f8(u32 a, u32 b);
int Unk0aa118_Unk_0af824(u32 id);
u8 *Unk0aa118_Unk_0af8d8(int a, u32 id, int c);
typedef struct Unk0aa118Ptrs {
    u8 pad_00[0x64];
    u32 *e[10];
} Unk0aa118Ptrs;
void Unk0aa118_Unk_0ab34c(void)
{
    func_020aa4f4(2, 0, 0, 0);
    func_020ae1e8(data_02176b18);
}

/* empty callback */
void Unk0aa118_Nop_0ae054(void) { }

/* forwards to `Unk0aa118_Unk_0af8d8` */
u8 *Unk0aa118_Thunk_020af8d8(int a, u32 id, int c) { return Unk0aa118_Unk_0af8d8(a, id, c); }

/* decompiler-derived */
void Unk0aa118_Unk_0ab454(void)
{
  int value;
  value = Unk044904_Unk_04509c();
  *(u32 *)(value + 0x18) = 0;
}

void Unk0aa118_AddUniqueId(u32 x)
{
    u32 *t = (u32 *)Unk044904_Unk_04509c();
    s32 j;
    s32 n = t[6];
    if (n >= 6) {
        return;
    }
    for (j = 0; j < n; j++) {
        if (x == t[j]) {
            return;
        }
    }
    t[n] = x;
    t[6]++;
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


/* decompiler-derived */
/* returns the table base for the record found by Unk0aa118_FindRecord (or for record 0,0) */
int Unk0aa118_Unk_0af824(u32 id)
{
    u8 *v = Unk0aa118_FindRecord(id);
    if (v != 0) {
        return func_0204fde0(Unk0aa118_Unk_0af7f8(v[0], v[1]));
    }
    return func_0204fde0(Unk0aa118_Unk_0af7f8(0, 0));
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
void Unk0aa118_Unk_0ab8f8();
int func_020af9f4();
int func_020afbdc();
int Unk0afc28_Unk_0b0930();
int Unk0caea8_GetInRange();
void Unk0aa118_Unk_0ab8f8(u32 p)
{
    u32 v = FIELD(u32, Unk044904_Get_data_0215ee98(), 64);
    if (((v << 20) >> 31) == 0) {
        return;
    }
    if (func_020b081c(2) != 0) {
        FIELD(u32, p, 8) |= 8;
    }
}

u8 Unk0aa118_Unk_0ab930(u8 *p, u32 id)
{
    switch (func_0204add4(id)) {
    case 4:
        return p[58];
    case 1:
        return p[59];
    case 5:
        return p[60];
    }
    return 0;
}

void Unk0aa118_Unk_0acb28(void)
{
    Unk0aa118Ptrs *g = (Unk0aa118Ptrs *)Unk044904_Get_data_0215ee98();
    int j;
    for (j = 0; j < 10; j++) {
        u32 *e = g->e[j];
        if (e != 0 && ((e[0] >> 16) & 0xff) != 0) {
            func_0204a7b4(e, 2);
        }
    }
}

/* decompiler-derived */
void Unk0aa118_Unk_0acb74(u32 arg0,u32 arg1,u32 arg2)
{
  u32 *v1;
  int tmp2;
  u32 tmp3;
  int tmp4;
  u32 tmp5;
  v1 = (u32 *)func_02044ec4(arg2);
  tmp2 = func_0204abd8(v1,0);
  if (tmp2 == 0) {
    tmp2 = Unk0caea8_GetInRange(arg1);
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
    Unk0afc28_Unk_0b0930(tmp4 + 100,arg0,0,1);
    func_020ab62c(tmp4,arg0,0xffffffff);
    *(u32 *)(tmp4 + 0x84) = *(u32 *)(tmp4 + 0x84) | 0x1000;
    Unk0aa118_Unk_0ab8f8(tmp2);
    func_0209fd64(tmp2);
    func_020afbdc(tmp2);
    return;
  }
}

u32 Unk0aa118_GetTableD2f4(int k, int i)
{
    int b = 0;
    switch (k) {
    case 1:
        break;
    case 2:
        b = 3;
        break;
    case 3:
        b = 6;
        break;
    }
    return data_0214d2f4[b + (i - 1)];
}

u8 *Unk0aa118_FindRecord(u32 id)
{
    u8 *e = data_0214d398;
    u32 j;
    for (j = 0; j < 0x146; j++, e += 34) {
        if (func_020152cc(id, e + 2) == 0) {
            return e;
        }
    }
    return 0;
}

int Unk0aa118_Unk_0af7cc(u32 i)
{
    int t = func_020491b4(i);
    if (i >= (u32)func_0205f2e4(t)) {
        i = 0;
    }
    return func_0205f41c(t, i);
}

int Unk0aa118_Unk_0af7f8(u32 a, u32 b)
{
    int t = Unk0aa118_Unk_0af7cc(a);
    if (b >= (u32)func_0204fd18(t)) {
        b = 0;
    }
    return func_0204fdac(t, b);
}

u8 *Unk0aa118_Unk_0af8d8(int a, u32 id, int c)
{
    u8 *base = (u8 *)Unk0aa118_Unk_0af824(id);
    int k = 0;
    if (a == 1) {
        k = 1;
    }
    if (c != 0) {
        k = 1 - k;
    }
    return base + k * 412;
}

u8 *Unk0aa118_Unk_0afa60(int a, u32 id, int c)
{
    u32 e = func_02099d14(id);
    if (e != 0) {
        if (func_020152cc(e, data_0214fef8) == 0) {
            return 0;
        }
        return Unk0aa118_Unk_0af8d8(a, e, c);
    }
    return 0;
}

u8 *Unk0aa118_Unk_0afab0(u32 x)
{
    int t = Unk0aa118_Unk_0af7f8(39, 0);
    int k = 0;
    u8 *base = (u8 *)func_0204fde0(t);
    u32 n = func_0204fe18(t);
    if (((x >> 16) & 0xff) == 1) {
        k += n >> 1;
    }
    return base + k * 22;
}

u8 *Unk0aa118_Unk_0afaf8(u32 x)
{
    int t = Unk0aa118_Unk_0af7f8(0, 0);
    int k = 0;
    u8 *base = (u8 *)func_0204fde0(t);
    u32 n = func_0204fe18(t);
    if (((x >> 16) & 0xff) == 1) {
        k += n >> 1;
    }
    return base + k * 22;
}

int Unk0aa118_Unk_0afb40(int i)
{
    if (i == 0) {
        return 0;
    }
    return Unk0aa118_Unk_0af824(data_0214d380[i]);
}
