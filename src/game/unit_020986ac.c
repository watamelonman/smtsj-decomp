/*
 * src/game/unit_020986ac.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int Unk02e000_Unk_02e774(void);
void Unk0986ac_SetFlagBit(int bit, int on);
int Unk0986ac_TestFlagBit(int bit);

void Unk0986ac_Nop_099230(void);
int Unk0986ac_Unk_098978(int arg0);
int Unk0986ac_Thunk_02098714(int bit);
void Unk0986ac_Unk_09894c(u32 arg0);
void Unk0986ac_Unk_09895c(u32 arg0);
int Unk0986ac_Unk_0986ac(void);
int Unk0986ac_Unk_0986c0(int arg0);

/* No-op callback: the original at 0x02099230 consists only of bx lr. */
void Unk0986ac_Nop_099230(void) { }

/* Convert an external id to a bit index by subtracting 111 (0x02098978).
 * Callers in BattleShowingTask.c pass the result to the flag-test wrapper. */
int Unk0986ac_Unk_098978(int arg0)
{
  return arg0 + -0x6f;
}

/* Preserve the bit-test result; 0x0209896c tail-calls TestFlagBit unchanged. */
int Unk0986ac_Thunk_02098714(int bit) { return Unk0986ac_TestFlagBit(bit); }

/* Set the indexed flag; 0x0209894c forwards bit and constant 1 to SetFlagBit.
 * The caller must supply an index within the borrowed flag storage. */
void Unk0986ac_Unk_09894c(u32 arg0)
{
  Unk0986ac_SetFlagBit(arg0,1);
}

/* Clear the indexed flag; 0x0209895c forwards bit and constant 0 to SetFlagBit.
 * The caller must supply an index within the borrowed flag storage. */
void Unk0986ac_Unk_09895c(u32 arg0)
{
  Unk0986ac_SetFlagBit(arg0,0);
}

/* Return a borrowed 32-bit address at base + 0x5c80; the two additions at
 * 0x020986ac establish the offset, but do not establish the storage size. */
int Unk0986ac_Unk_0986ac(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  return value + 0x5c80;
}

/* Locate the byte for a bit index in borrowed storage (0x020986c0 uses
 * arithmetic shift by three). Callers are responsible for index bounds. */
int Unk0986ac_Unk_0986c0(int arg0)
{
  int value;
  value = Unk0986ac_Unk_0986ac();
  return value + (arg0 >> 3);
}



int func_0204fed8();
void func_02061f10();
void Unk0986ac_SetFlagBit(int bit, int on)
{
    u8 *p = (u8 *)Unk0986ac_Unk_0986c0(bit);
    u8 m = 1 << (bit & 7);
    if (on) {
        *p |= m;
    } else {
        *p &= ~m;
    }
}

int Unk0986ac_TestFlagBit(int bit)
{
    u8 *p = (u8 *)Unk0986ac_Unk_0986c0(bit);
    return (*p & (u8)(1 << (bit & 7))) != 0;
}

/* decompiler-derived */
void Unk0986ac_Unk_098990(u8 arg0)
{
  int value;
  value = Unk0986ac_Unk_0986ac();
  *(u8 *)(value + 0xd) = arg0;
}

int Unk02e000_Unk_02e0cc();
int Unk05b82c_Unk_05b82c();
/* decompiler-derived */
u32 Unk0986ac_Unk_099300(void)
{
  Unk02e000_Unk_02e0cc();
  Unk05b82c_Unk_05b82c(0xbf);
  return 1;
}

int Unk09974c_Unk_099d78();
int Unk09974c_HasFlagsMid();
int Unk09974c_GetFlagsMidMinus1();
/* decompiler-derived */
u32 Unk0986ac_Unk_098918(void)
{
  int value1;
  int value2;
  u32 value3;
  value3 = 0;
  value1 = Unk09974c_Unk_099d78();
  if ((value1 != 0) && (value2 = Unk09974c_HasFlagsMid(), value2 != 0)) {
    value3 = Unk09974c_GetFlagsMidMinus1(value1);
  }
  return value3;
}

/* Read the unsigned byte at borrowed storage + 13; ldrb at 0x02098988
 * establishes width and offset, while its application meaning is unknown. */
u8 Unk0986ac_Unk_098980(void)
{
  int tmp1;
  tmp1 = Unk0986ac_Unk_0986ac();
  return *(u8 *)(tmp1 + 0xd);
}

void Unk0986ac_Unk_0989a4(int a, u8 *p, int c)
{
    func_02061f10(a, -1, 0, 0, func_0204fed8(FIELD(u32, p, 4), c));
}

typedef struct Unk0986acPair {
    s8 a;
    s8 b;
} Unk0986acPair;

u32 Unk0986ac_FindEmpty(const Unk0986acPair *t)
{
    u32 j;
    for (j = 0; j < 23; j++) {
        if (t[j].a == 0) {
            return j;
        }
    }
    return 23;
}

void Unk0986ac_Unk_098aa8(u8 *p)
{
    s32 n = FIELD(s32, p, 56);
    if (n <= 0) {
        FIELD(s32, p, 64) = 0;
        FIELD(u8, p, 68) = 0;
        return;
    }
    FIELD(s32, p, 64) = (FIELD(s32, p, 60) - 16) * n + 16;
    FIELD(u8, p, 68) = n * 31;
}

int Unk0986ac_IsMode012(u8 *p)
{
    u32 v = FIELD(u32, p, 44);
    int r = 0;
    switch (v) {
    case 0:
        return 1;
    case 1:
        return 1;
    case 2:
        r = 1;
        break;
    }
    return r;
}

void Unk0986ac_Unk_09911c();
void func_02099174();
int Unk0a23f4_Unk_0a246c();
void Unk0986ac_Unk_099234(u8 *p);
typedef struct Unk09911cHdr {
    u8 pad_00[16];
    s32 unk_10;
} Unk09911cHdr;
typedef struct Unk09911cState {
    Unk09911cHdr *hdr;
} Unk09911cState;
typedef struct Unk09911cObj {
    u8 pad_00[4];
    u32 unk_04;
    u8 pad_08[8];
    s32 unk_10;
    u8 pad_14[20];
    s32 unk_28;
    u8 pad_2c[12];
    s32 unk_38;
} Unk09911cObj;
void *GetGameState();
void Unk11f2d0_Unk_11f320();
int Unk09974c_Unk_0998d8();

void Unk0986ac_Unk_09911c(Unk09911cObj *p)
{
    Unk09911cState *gs = (Unk09911cState *)GetGameState();
    if (gs == 0) {
        return;
    }
    Unk11f2d0_Unk_11f320((u8 *)gs + 30104);
    Unk0986ac_Unk_0989a4(p->unk_10, (u8 *)p->unk_04, p->unk_28);
    if (p->unk_28 == 1 || gs->hdr->unk_10 == 1) {
        p->unk_38 = 1;
    } else {
        p->unk_38 = 0;
    }
}

void Unk0986ac_Unk_099234(u8 *p)
{
    FIELD(s32, p, 56) -= 1;
    Unk0986ac_Unk_098aa8(p);
    if (FIELD(s32, p, 56) > 0) {
        return;
    }
    FIELD(s32, p, 24) = 0;
    FIELD(s32, p, 40) = 0;
    FIELD(s32, p, 56) = 0;
    FIELD(s32, p, 64) = 0;
    FIELD(u8, p, 68) = 0;
}

void Unk0986ac_Unk_099274(u8 *p)
{
    FIELD(s32, p, 20) = FIELD(s32, p, 24);
    FIELD(s32, p, 24) = -1;
    switch (FIELD(s32, p, 20)) {
    case 2:
        Unk0986ac_Unk_09911c((void *)p);
        break;
    case 3:
        Unk0986ac_Nop_099230();
        break;
    }
}

void Unk0986ac_Unk_0992b0(u8 *p)
{
    switch (FIELD(u32, p, 20)) {
    case 0:
        break;
    case 1:
        if (Unk0a23f4_Unk_0a246c() == 1) {
            FIELD(s32, p, 24) = 2;
        }
        break;
    case 2:
        func_02099174(p);
        break;
    case 3:
        break;
    case 4:
        Unk0986ac_Unk_099234(p);
        break;
    }
}
