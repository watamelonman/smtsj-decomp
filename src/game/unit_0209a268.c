/*
 * src/game/unit_0209a268.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct Unk09a268Work {
    u8 unk_0000[0xc];
    u32 UnkField000c;
    u8 unk_0010[0x1c];
    s32 UnkField002c;
} Unk09a268Work;


int func_0209a48c(u32 p, int bit);
void Unk09a268_SetBit();
int func_0209bb68();
int Unk09a268_Unk_09c484();

void Unk09a268_Nop_09b3c8(void);
void Unk09a268_Unk_09a7fc(u32 arg0);
void Unk09a268_Unk_09a820(u32 arg0);
void Unk09a268_Unk_09c498(void);
void Unk09a268_Unk_09a80c(u32 arg0,u32 arg1);
void Unk09a268_Unk_09a830(u32 arg0,u32 arg1);
void Unk09a268_Unk_09a870(u32 arg0,u32 arg1);

typedef struct Unk09a268Ent {
    s32 *val;
    u32 pad_04;
    u32 id;
    u32 pad_0c;
    u32 sub;
    u32 pad_14;
} Unk09a268Ent;

int func_02058af8();
int func_0209a3ec();
void func_02058b14();
void func_02058a1c();
u8 *Unk038fbc_Unk_039160(u32 h, u32 a, u32 b);
int Unk09a268_Unk_09a3a0(u8 *w, u32 id, u32 sub)
{
    int j;
    for (j = 0; j < 128; j++) {
        if (((Unk09a268Ent *)((u8 *)w + 164 + 9216))[j].id == id && ((Unk09a268Ent *)((u8 *)w + 164 + 9216))[j].sub == sub) {
            return func_02058af8((u8 *)w + 164 + 9216, j);
        }
    }
    return 1;
}

void Unk09a268_Unk_09a458(u8 *w, u32 a, u32 b, u32 c, u8 d, u32 e)
{
    int i = func_0209a3ec(w, a, b, c, d);
    func_02058b14(w + 164 + 9216, i, e);
}

/* Sets bit `bit` of the byte at `p` when `on` is 1, otherwise clears it. */
void Unk09a268_SetBit(u32 p, int bit, int on)
{
    if (on == 1) {
        *(u8 *)p |= 1 << bit;
    } else {
        *(u8 *)p &= ~(1 << bit);
    }
}

int Unk09a268_FindEntry(u8 *w, u32 id, u32 sub)
{
    int j;
    for (j = 0; j < 128; j++) {
        if (((Unk09a268Ent *)((u8 *)w + 164 + 9216))[j].id == id && ((Unk09a268Ent *)((u8 *)w + 164 + 9216))[j].sub == sub) {
            return j;
        }
    }
    return -1;
}

u8 Unk09a268_Unk_09a77c(u32 p)
{
    u8 r = 0;
    u8 j;
    for (j = 0; j < 3; j++) {
        if (func_0209a48c(p, j) == 1) {
            r = j;
            break;
        }
    }
    return r;
}

void Unk09a268_SetOnlyBit(u32 p, u32 v)
{
    u32 j;
    for (j = 0; j < 3; j++) {
        Unk09a268_SetBit(p, j, v == j ? 1 : 0);
    }
}

/* Reads a single bit of the byte at `p`. Callers use bits 0-2 to select one of the
 * three state values and bits 3-5 for the flag setters (Unk09a268_Unk_09a80c/a830/a870). */
int func_0209a48c(u32 p, int bit)
{
    return (*(u8 *)p & (1 << bit)) != 0;
}

/* empty callback */
void Unk09a268_Nop_09b3c8(void) { }

/* Tests the bit-3 flag of the state byte at `p`; the result is discarded. */
void Unk09a268_Unk_09a7fc(u32 p)
{
  func_0209a48c(p,3);
}

/* Tests the bit-4 flag of the state byte at `p`; the result is discarded. */
void Unk09a268_Unk_09a820(u32 p)
{
  func_0209a48c(p,4);
}

typedef struct Unk09a268Ctx {
    u8 pad_0000[0x2c];
    u32 unk_002c;
    u32 unk_0030;
    u32 unk_0034;
    u32 unk_0038;
} Unk09a268Ctx;

extern Unk09a268Ctx *data_02176270;

/* Returns the context's +0x34 word, or 0 when the global context is absent. */
u32 func_0209b720(void)
{
    if (data_02176270 == 0) {
        return 0;
    }
    return data_02176270->unk_0034;
}

/* Stores value at +0x38 of the global context when one is allocated. */
void Unk09a268_SetCtxUnk38(u32 value)
{
    if (data_02176270 != 0) {
        data_02176270->unk_0038 = value;
    }
}

/* Runs the func_0209bb68 and Unk09a268_Unk_09c484 steps in sequence, discarding their results. */
void Unk09a268_Unk_09c498(void)
{
  func_0209bb68();
  Unk09a268_Unk_09c484();
}

/* Sets or clears the bit-3 flag of the state byte at `p` (`on` == 1 sets). */
void Unk09a268_Unk_09a80c(u32 p,u32 on)
{
  Unk09a268_SetBit(p,3,on);
}

/* Sets or clears the bit-4 flag of the state byte at `p` (`on` == 1 sets). */
void Unk09a268_Unk_09a830(u32 p,u32 on)
{
  Unk09a268_SetBit(p,4,on);
}

/* Sets or clears the bit-5 flag of the state byte at `p` (`on` == 1 sets). */
void Unk09a268_Unk_09a870(u32 p,u32 on)
{
  Unk09a268_SetBit(p,5,on);
}


extern u8 data_0213be64[];
/* decompiler-derived: address of the 0x1c-byte record at `arg0` in table data_0213be64. */
int Unk09a268_Unk_09c484(int arg0)
{
  return arg0 * 0x1c + ((int)data_0213be64);
}

int GameState_GetBody();
/* Returns bit 5 of the state byte at `arg0` when GameState body +0x3e0 is nonzero, else 1. */
u32 Unk09a268_Unk_09a844(u32 arg0)
{
  int value1;
  u32 value2;
  value1 = GameState_GetBody();
  if (*(int *)(value1 + 0x3e0) != 0) {
    value2 = func_0209a48c(arg0,5);
    return value2;
  }
  return 1;
}

int func_02057524();
int func_02057534();
typedef struct Unk09ae60Ops {
    u32 size;
    u32 unk_04;
    u32 unk_08;
    void (*fn_0c)();
    void (*fn_10)();
    void (*fn_14)();
    void (*fn_18)();
    void (*fn_1c)();
    void (*fn_20)();
} Unk09ae60Ops;
int func_02058a64();
void Unk09a268_Unk_09b3cc(Unk09a268Work *work);
void func_02058944();
void func_0209b1d4();
void func_0209b3f8();
void func_0209b5d8();
void func_0209aebc();

void Unk09a268_Unk_09ae60(Unk09ae60Ops *o)
{
    o->size = 60;
    o->unk_04 = 0;
    o->fn_0c = func_0209b1d4;
    o->fn_10 = Unk09a268_Nop_09b3c8;
    o->fn_14 = Unk09a268_Unk_09b3cc;
    o->fn_18 = func_0209b3f8;
    o->fn_1c = func_0209b5d8;
    o->fn_20 = func_0209aebc;
}

/* decompiler-derived: reloads the palette from the work's +0xc field when +0x2c is zero. */
void Unk09a268_Unk_09b3cc(Unk09a268Work *work)
{
  func_02057524(0);
  if (work->UnkField002c == 0) {
    Unk_LoadPalette_020de678(work->UnkField000c);
  }
  func_02057534();
}


int Unk0bc1a8_IsSlotEmpty();
/* Stores a and b at +0x2c/+0x30 of the global context when one is allocated. */
void Unk09a268_SetCtxUnk2c30(u32 a, u32 b)
{
    if (data_02176270 != 0) {
        data_02176270->unk_002c = a;
        data_02176270->unk_0030 = b;
    }
}

/* decompiler-derived */
u32 Unk09a268_Unk_09bb38(void)
{
  int value;
  value = Unk0bc1a8_IsSlotEmpty(0);
  if ((value != 0) && (value = Unk0bc1a8_IsSlotEmpty(9), value != 0)) {
    return 1;
  }
  return 0;
}


int Unk02f2a8_GetCurrentCell38e8();
void Unk09a268_SetOnlyBit();
int func_0209c548();
/* decompiler-derived */
void Unk09a268_Unk_09cb10(u32 arg0)
{
  int value1;
  int value2;
  value1 = Unk09a268_Unk_09c484(5);
  value2 = Unk02f2a8_GetCurrentCell38e8();
  Unk09a268_Unk_09a80c(value2,1);
  Unk09a268_Unk_09a830(value2,0);
  Unk09a268_SetOnlyBit(value2,*(u8 *)(value1 + 0x19));
  *(u8 *)(value2 + 1) = 1;
  *(u16 *)(value2 + 2) = 0;
  func_0209c548(arg0);
}

u8 *GetGameState(void);     /* GameState *, see include/GameState.h */
u32 Unk02f2a8_Unk_034970(void *table, u32 a, u32 b);
u8 *Unk038fbc_Unk_039160(u32 h, u32 a, u32 b);

/* Byte +0x1B of the record for (a, b), or 0 when absent. */
u8 Unk09a268_Unk_09beb0(u32 a, u32 b)
{
    u8 ret = 0;
    u8 *e = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(GetGameState() + 4, a, b), a, b);
    if (e != 0) {
        ret = ((u8 *)Unk09a268_Unk_09c484(func_0209bb68(*e)))[0x1b];
    }
    return ret;
}

int Unk09a268_Unk_09c4a8(u32 h, u32 a, u32 b)
{
    int r;
    u8 *e;
    if (h == 0) {
        return 0;
    }
    r = 0;
    e = Unk038fbc_Unk_039160(h, a, b);
    if (e != 0) {
        r = func_0209bb68(*e);
    }
    return Unk09a268_Unk_09c484(r);
}

/* Returns 1 when `p` is non-null and its first byte equals 1, else 0. */
int Unk09a268_IsType1(const u8 *p)
{
    if (p == 0) {
        return 0;
    }
    return *p == 1;
}
