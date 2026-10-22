/*
 * src/game/unit_0203e43c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 data_0215e85e[];
int Unk02e000_GetWorkArea();
int Unk03e43c_Div10Clamp16();
void func_0203fa84(void);
int func_0205410c();

void Unk03e43c_Thunk_0203fa84(void);
u8 *Unk03e43c_Unk_03f2ac(int offset);
int Unk03e43c_Unk_03fa28(void);
void Unk03e43c_Unk_03f2bc(void);
void Unk03e43c_Unk_03fa3c(u8 value);

typedef struct Unk03e43cTimer {
    u8 pad_0000[0x58];
    u16 count;                  /* +0x58 */
} Unk03e43cTimer;

extern u8 data_0215e85c[];
void Unk03e43c_CopyEntry32(u8 *src, int idx)
{
    int i;
    for (i = 0; i < 32; i += 2) {
        data_0215e85c[idx * 32 + i + 2] = src[i];
        data_0215e85c[idx * 32 + i + 3] = src[i + 1];
    }
}

void Unk03e43c_MergeTable(u8 *src)
{
    int i;
    for (i = 0; i < 512; i += 2) {
        if (src[i] != 0 || src[i + 1] != 0) {
            data_0215e85c[i + 2] = src[i];
            data_0215e85c[i + 3] = src[i + 1];
        }
    }
}

void func_02020f8c();
void func_02008848();
int func_0202092c();
void func_020211d8();
void func_0204b6d0();
void Unk03e43c_Unk_043450();
extern u8 data_0215ee60[];
void Unk03e43c_ClearTable(void)
{
    func_02020f8c();
    func_02008848(data_0215e85e, 0, 512);
    *(u16 *)data_0215e85c = 0;
}

void Unk03e43c_Unk_03e894(u8 *o, int b, int c, int d)
{
    func_020211d8(o, func_0202092c(c, (u16)d), b);
    FIELD(u16, o, 0x58) = 0;
}

/*
 * Decrements the 16-bit countdown at +0x58 of `t` when it is nonzero and
 * returns 1 once the counter has already reached zero (so callers can stop).
 */
int Unk03e43c_CountDown(Unk03e43cTimer *t)
{
    if (t->count == 0) {
        return 1;
    }
    t->count--;
    return 0;
}

/*
 * Maps a 0..159 counter to a 0..15 table slot by dividing by 10. Quotients
 * that would not fit in four bits (>= 16) return the -1 sentinel.
 */
int Unk03e43c_Div10Clamp16(int x)
{
    int r = x / 10;
    if (r >= 16) {
        r = -1;
    }
    return r;
}

void Unk03e43c_AdvanceCounter360(void)
{
    u8 *w = (u8 *)Unk02e000_GetWorkArea();
    s32 v = ++w[0x360];
    if (v >= 160) {
        w[0x360] -= 160;
    }
}

/* Forwards to `func_0203fa84` (tail call in the original). */
void Unk03e43c_Thunk_0203fa84(void) { func_0203fa84(); }

/*
 * Returns a byte pointer `offset` bytes into the shared table at data_0215e85e.
 * Unk03e43c_Unk_044194 treats the result as a u16 array.
 */
u8 *Unk03e43c_Unk_03f2ac(int offset)
{
  return data_0215e85e + offset;
}

/*
 * Returns the work-area counter at +0x360 mapped through Unk03e43c_Div10Clamp16
 * (a 0..15 table slot, or -1 when the counter is out of range).
 */
int Unk03e43c_Unk_03fa28(void)
{
  u8 *work = (u8 *)Unk02e000_GetWorkArea();
  return Unk03e43c_Div10Clamp16(work[0x360]);
}

/* Sets bit 1 of the byte at +0x10 in the object returned by func_0205410c. */
void Unk03e43c_Unk_03f2bc(void)
{
  u8 *p = (u8 *)func_0205410c();
  p[0x10] |= 2;
}

/* Stores `value * 10` in the work-area counter byte at +0x360 (inverse of /10). */
void Unk03e43c_Unk_03fa3c(u8 value)
{
  u8 *work = (u8 *)Unk02e000_GetWorkArea();
  work[0x360] = value * 10;
}


int func_02020974();
int func_02051610();
int func_020516d0();
/* decompiler-derived */
int Unk03e43c_Unk_03e5a4(u32 arg0,u32 arg1)
{
  int value1;
  int value2;
  value1 = func_02051610(arg1);
  if (value1 != 0) {
    value2 = func_02020974(value1,arg0);
    if (value2 != 0) {
      return value1;
    }
    func_020516d0(value1);
  }
  return 0;
}

int func_020207d0();
/* decompiler-derived */
int Unk03e43c_Unk_03e5dc(u32 arg0,u32 arg1)
{
  int value1;
  int value2;
  value1 = func_02051610(arg1);
  if (value1 != 0) {
    value2 = func_020207d0(value1,arg0);
    if (value2 != 0) {
      return value1;
    }
    func_020516d0(value1);
  }
  return 0;
}

int func_02020ac0();
/* decompiler-derived */
int Unk03e43c_Unk_03e614(u32 arg0,u32 arg1)
{
  int value1;
  int value2;
  value1 = func_02051610(arg1);
  if (value1 != 0) {
    value2 = func_02020ac0(value1,arg0);
    if (value2 != 0) {
      return value1;
    }
    func_020516d0(value1);
  }
  return 0;
}

int func_02020a74();
/* decompiler-derived */
int Unk03e43c_Unk_03e64c(u32 arg0,u32 arg1)
{
  int value1;
  int value2;
  value1 = func_02051610(arg1);
  if (value1 != 0) {
    value2 = func_02020a74(value1,arg0);
    if (value2 != 0) {
      return value1;
    }
    func_020516d0(value1);
  }
  return 0;
}

extern u8 data_0215e85c[];
/* decompiler-derived */
void Unk03e43c_Unk_03e794(int arg0,int arg1)
{
  int value1;
  int value2;
  int value3;
  value2 = 0;
  value3 = ((int)data_0215e85c) + arg1 * 0x20;
  do {
    value1 = arg0 + value2;
    value2 = value2 + 2;
    *(u8 *)(value3 + 2) = *(u8 *)(value1 + 0x28);
    *(u8 *)(value3 + 3) = *(u8 *)(value1 + 0x29);
    value3 = value3 + 2;
  } while (value2 < 0x20);
}




int GameState_GetBody();
void Unk03e43c_SetMode30(int mode)
{
    FIELD(s32, data_0215ee60, 0x30) = mode;
    if (mode == 1 && FIELD(u32, data_0215ee60, 0x34) == 0) {
        func_0204b6d0();
    }
}

void Unk03e43c_UpdatePos18(u8 *o)
{
    s16 x = FIELD(s16, o, 0x18);
    s16 y = FIELD(s16, o, 0x1a);
    Unk03e43c_Unk_043450(o + 0x18, o + 0x1a, FIELD(u32, o, 0x28dc));
    if (FIELD(s16, o, 0x18) != x || FIELD(s16, o, 0x1a) != y) {
        FIELD(u32, o, 0x04) = 1;
    }
}

/* decompiler-derived */
void Unk03e43c_Unk_0434b0(short *arg0,short *arg1)
{
  int value;
  if (0xb0 < *arg0) {
    *arg0 = 0xb0;
  }
  if (0x70 < *arg1) {
    *arg1 = 0x70;
  }
  value = GameState_GetBody();
  if ((int)*arg0 < (int)((*(u8 *)(*(int *)(value + 0x354) + 10) - 10) * -8)) {
    value = GameState_GetBody();
    *arg0 = (*(u8 *)(*(int *)(value + 0x354) + 10) - 10) * -8;
  }
  value = GameState_GetBody();
  if ((int)*arg1 < (int)((*(u8 *)(*(int *)(value + 0x354) + 0xb) - 10) * -8)) {
    value = GameState_GetBody();
    *arg1 = (*(u8 *)(*(int *)(value + 0x354) + 0xb) - 10) * -8;
    return;
  }
}

int func_02056cc0(int mode, int index, u8 *table);
/*
 * Registers the 512-byte table at data_0215e85e with func_02056cc0, passing the
 * (1, 0, table) arguments seen in the original.
 */
void Unk03e43c_Call_02056cc0(void)
{
  func_02056cc0(1,0,data_0215e85e);
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif

typedef struct Unk03e43cEnt { u8 pad[4]; u16 unk_04; u8 pad2[2]; } Unk03e43cEnt;
typedef struct Unk03e43cTab { u16 n; u8 pad[10]; Unk03e43cEnt *ents; } Unk03e43cTab;
int Unk03e43c_Unk_03e8cc(u8 *p)
{
    Unk03e43cTab *q = FIELD(Unk03e43cTab *, p, 28);
    u32 sum = 0;
    u32 i;
    for (i = 0; i < q->n; i++) {
        sum += q->ents[i].unk_04;
    }
    if (FIELD(u16, p, 88) >= sum) {
        return 1;
    }
    FIELD(u16, p, 88)++;
    return 0;
}

void Unk03e43c_Unk_03f234(s16 *a, s16 *b, int x, int y)
{
    int v = *a;
    int d = x - v;
    if (d < 0) {
        d = -d;
    }
    if (d > 256) {
        if (v < x) {
            *a += 512;
        } else if (v > x) {
            *a -= 512;
        }
    }
    v = *b;
    d = y - v;
    if (d < 0) {
        d = -d;
    }
    if (d > 128) {
        if (v < y) {
            *b += 256;
        } else if (v > y) {
            *b -= 256;
        }
    }
}

void func_020629c4();
int GameState_GetUnkField74f4();
int GameState_GetUnkField74f6();
int Unk02f078_TestFlag380();
void Unk04bb9c_SetCtxUnka14();
void Unk03e43c_Unk_044194(u8 *p);
void Unk03e43c_MergeTable(u8 *src);
void Unk03e43c_Call_02056cc0(void);

void Unk03e43c_Unk_041ce4(u8 *p)
{
    func_020516d0(FIELD(u32, p, 12));
    func_020516d0(FIELD(u32, p + 0x2000, 2228));
    func_020516d0(FIELD(u32, p + 0x2000, 2232));
    func_020516d0(FIELD(u32, p + 0x2000, 2236));
    if (FIELD(s32, data_0215ee60, 48) == 1) {
        func_0204b6d0();
    }
    func_020629c4(FIELD(u32, p + 0x2000, 2444));
    if (FIELD(u32, p + 0x2000, 2444) != 0) {
        FIELD(u32, p + 0x2000, 2444) = 0;
    }
    FIELD(u32, data_0215ee60, 48) = 0;
    FIELD(u32, data_0215ee60, 52) = 0;
}

void Unk03e43c_Unk_043450(s16 *x, s16 *y)
{
    u8 *w = (u8 *)Unk02e000_GetWorkArea();
    *x = 128 - ((s8)(FIELD(s8, w + 0x300, 100) - GameState_GetUnkField74f4()) << 3);
    w = (u8 *)Unk02e000_GetWorkArea();
    *y = 96 - ((s8)(FIELD(s8, w + 0x300, 101) - GameState_GetUnkField74f6()) << 3);
}

int Unk03e43c_Unk_043560(void)
{
    int n = 0;
    int i;
    for (i = 0; i < 37; i++) {
        if (Unk02f078_TestFlag380(i) != 0) {
            n++;
        }
    }
    if (n > 20) {
        return 48;
    }
    if (n > 16) {
        return 24;
    }
    if (n > 12) {
        return 23;
    }
    if (n > 8) {
        return 22;
    }
    if (n > 4) {
        return 21;
    }
    return 20;
}

void Unk03e43c_Unk_044194(u8 *p)
{
    u16 *t;
    int i;
    for (i = 0; i < 7; i++) {
        FIELD(u8, p + i + 0x2000, 2434) = 0;
    }
    t = (u16 *)Unk03e43c_Unk_03f2ac(0);
    for (i = 0; i <= 3; i++) {
        t[i + 1] = 0x73f5;
    }
    Unk03e43c_MergeTable((u8 *)t);
    Unk03e43c_Call_02056cc0();
}

void Unk03e43c_Unk_0441ec(void)
{
    FIELD(u8, FIELD(u8 *, data_0215ee60, 52) + 0x2000, 2438) = 0;
    FIELD(u8, FIELD(u8 *, data_0215ee60, 52) + 0x2000, 2439) = 0;
    FIELD(u32, FIELD(u8 *, data_0215ee60, 52) + 0x2000, 2252) = 0;
    Unk03e43c_Unk_044194(FIELD(u8 *, data_0215ee60, 52));
    Unk04bb9c_SetCtxUnka14(-1);
    FIELD(u8, FIELD(u8 *, data_0215ee60, 52) + 0x2000, 2275) = 0;
    FIELD(u32, FIELD(u8 *, data_0215ee60, 52), 4) = 0;
    FIELD(u32, FIELD(u8 *, data_0215ee60, 52), 16) = 0;
    FIELD(u32, FIELD(u8 *, data_0215ee60, 52) + 0x2000, 2244) = 0;
}
