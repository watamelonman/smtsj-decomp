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



int func_0204fed8(u32 handle, int index);
void func_02061f10(int handle, int arg1, int arg2, int arg3, int value);
/* Set or clear the indexed bit in borrowed storage; 0x020986d4 uses
 * bit & 7 as the mask shift. Caller must enforce storage bounds. */
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

/* Test one bit in borrowed flag storage; the mask at 0x02098714 uses
 * bit & 7. The caller must provide an in-range storage index. */
int Unk0986ac_TestFlagBit(int bit)
{
    u8 *p = (u8 *)Unk0986ac_Unk_0986c0(bit);
    return (*p & (u8)(1 << (bit & 7))) != 0;
}

/* Store the supplied byte in borrowed storage + 13; strb at 0x02098990
 * establishes the width and offset, but not the byte's application meaning. */
void Unk0986ac_Unk_098990(u8 arg0)
{
  int value;
  value = Unk0986ac_Unk_0986ac();
  *(u8 *)(value + 0xd) = arg0;
}

void Unk02e000_Unk_02e0cc(void);
void Unk05b82c_Unk_05b82c(int id);
/* Call the two external operations in order, passing 191 to the second,
 * then return 1; call relocations at 0x02099300 establish this contract. */
u32 Unk0986ac_Unk_099300(void)
{
  Unk02e000_Unk_02e0cc();
  Unk05b82c_Unk_05b82c(0xbf);
  return 1;
}

/* Borrowed record prefix shared with unit_0209974c; +4 bits 8..11
 * encode the optional value tested by the external flag helpers. */
typedef struct Unk09974cFlags {
  u8 pad_0000[0x4];
  u16 unk_04_lo : 8;
  u16 unk_04_mid : 4;
  u16 unk_04_hi : 4;
} Unk09974cFlags;

void *Unk09974c_Unk_099d78(int id);
int Unk09974c_HasFlagsMid(Unk09974cFlags *record);
int Unk09974c_GetFlagsMidMinus1(Unk09974cFlags *record);
/* Look up the supplied id and decode its optional middle flag field, or
 * return zero for an absent record/field. At 0x02098920 incoming r0 is the
 * lookup id; 0x0209892c passes the returned record onward in r0. The caller
 * at 0x020c3090 loads the id from its table before invoking this function.
 * The returned record is borrowed and is never retained or modified. */
u32 Unk0986ac_Unk_098918(int id)
{
  Unk09974cFlags *record;
  u32 value = 0;
  record = Unk09974c_Unk_099d78(id);
  if (record != 0 && Unk09974c_HasFlagsMid(record) != 0) {
    value = Unk09974c_GetFlagsMidMinus1(record);
  }
  return value;
}

/* Read the unsigned byte at borrowed storage + 13; ldrb at 0x02098988
 * establishes width and offset, while its application meaning is unknown. */
u8 Unk0986ac_Unk_098980(void)
{
  int tmp1;
  tmp1 = Unk0986ac_Unk_0986ac();
  return *(u8 *)(tmp1 + 0xd);
}

/* Borrow p through offset 4 to obtain the lookup handle; 0x020989a4 passes
 * the lookup result as the fifth argument with fixed arguments -1, 0, 0. */
void Unk0986ac_Unk_0989a4(int a, u8 *p, int c)
{
    func_02061f10(a, -1, 0, 0, func_0204fed8(FIELD(u32, p, 4), c));
}

/* Borrowed two-byte table entry; only the first signed byte is examined. */
typedef struct Unk0986acPair {
    s8 a;
    s8 b;
} Unk0986acPair;

/* Find the first zero first-byte among 23 borrowed entries, or return 23.
 * The stride-two signed loads and zero comparison at 0x020989dc support the name. */
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

/* Update borrowed fields +64 and +68 from signed fields +56 and +60;
 * 0x02098aa8 clears both outputs for nonpositive +56 and truncates +68 to a byte.
 * The caller supplies aligned storage through +68 and representable arithmetic. */
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

/* Return whether the borrowed selector at +44 equals 0, 1, or 2.
 * The three explicit comparisons at 0x02098ae0 support the predicate name. */
int Unk0986ac_IsMode012(u8 *p, int arg1, int arg2)
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

struct Unk09911cObj;
void Unk0986ac_Unk_09911c(struct Unk09911cObj *p);
void func_02099174(u8 *p);
int Unk0a23f4_Unk_0a246c(void);
void Unk0986ac_Unk_099234(u8 *p);
/* Borrowed header prefix; only signed selector +16 is observed. */
typedef struct Unk09911cHdr {
    u8 pad_00[16];
    s32 unk_10;
} Unk09911cHdr;
/* Borrowed state prefix whose first word points to the header. */
typedef struct Unk09911cState {
    Unk09911cHdr *hdr;
} Unk09911cState;
/* Borrowed object fields observed by 0x0209911c, through signed word +56. */
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
void *GetGameState(void);
void Unk11f2d0_Unk_11f320(void *p);
int Unk09974c_Unk_0998d8(int id);

/* With a live game state, call the operation on state +30104, forward
 * object fields +16/+4/+40, then set +56 if object +40 or header +16 is 1.
 * Loads and call relocations at 0x0209911c establish these borrowed views. */
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

/* Decrement signed word +56 and recompute outputs; when nonpositive, clear
 * words +24/+40/+56/+64 and byte +68 (0x02099234). Caller supplies aligned
 * borrowed storage through +68 and a decrement representable as signed int. */
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

/* Consume pending selector +24 into +20, reset +24 to -1, and dispatch
 * selectors 2 and 3; stores and branches at 0x02099274 define this transition.
 * The borrowed object must satisfy the selected handler contract. */
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

/* Dispatch borrowed selector +20: 1 may queue 2 at +24 when the external
 * predicate returns exactly 1; 2 and 4 invoke their handlers. The jump table
 * at 0x020992b0 establishes these cases; other selectors have no effect. */
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

int func_0209a158(int id);
/* Preserve the original loop-entry comparisons. See DEC-014. */
#pragma push
#pragma opt_propagation off

/* Scan ids 111..210 for a matching middle field and an enabled external
 * predicate; 0x02098860 returns one on the first such record. Records are borrowed. */
int func_02098860(int field)
{
    int result = 0;
    int id;
    id = 111;
    while (id <= 210) {
        Unk09974cFlags *record = Unk09974c_Unk_099d78(id);
        if (record != 0 && Unk09974c_GetFlagsMidMinus1(record) == field) {
            if (Unk09974c_Unk_0998d8(id) != 0) {
                result = 1;
                break;
            }
        }
        id++;
    }
    return result;
}

/* Scan the same borrowed id range; 0x020988bc returns zero on the first
 * matching middle field whose func_0209a158 predicate is false, otherwise one. */
int func_020988bc(int field)
{
    int result = 1;
    int id;
    id = 111;
    while (id <= 210) {
        Unk09974cFlags *record = Unk09974c_Unk_099d78(id);
        if (record != 0 && Unk09974c_GetFlagsMidMinus1(record) == field) {
            if (func_0209a158(id) == 0) {
                result = 0;
                break;
            }
        }
        id++;
    }
    return result;
}

/* Return the largest high nibble at +4 among borrowed records for ids
 * 111..210 matching the middle field and external predicate; 0x02098740
 * loads the halfword and shifts bits 12..15. Zero also covers no match. */
int func_02098740(int field)
{
    int result = 0;
    int id;
    id = 111;
    while (id <= 210) {
        Unk09974cFlags *record = Unk09974c_Unk_099d78(id);
        if (record != 0 && Unk09974c_GetFlagsMidMinus1(record) == field &&
            Unk09974c_Unk_0998d8(id) != 0) {
            if (result < record->unk_04_hi) {
                result = record->unk_04_hi;
            }
        }
        id++;
    }
    return result;
}

#pragma pop

/* Borrowed 72-byte selector state, laid out by loads/stores at 0x02099318. */
typedef struct Unk0986acWork {
    s32 unk_00;
    u8 *unk_04;
    s32 *unk_08;
    s32 unk_0c, unk_10, unk_14, unk_18, unk_1c, unk_20, unk_24;
    s32 unk_28, unk_2c, unk_30, unk_34, unk_38, unk_3c, unk_40;
    u8 unk_44;
    s8 unk_45, unk_46;
    u8 pad_47;
} Unk0986acWork;
void func_02008848(void *p, int value, u32 size);
int func_020629ac(int a, int b, int c, int d);
int func_02059c70(int id, int kind);
int func_0202d170(void);
int func_0202d710(Unk0986acWork *p, int x, int y);
void func_0202d198(void);
void Unk0a0ce4_Unk_0a0da4(int id);
int func_02098a08(u8 *p, int index);
int func_02098b14(Unk0986acWork *p, int x, int y);
int func_02098b9c(Unk0986acWork *p, int x, int y);
int func_02098fec(Unk0986acWork *p, int x, int y);
u8 *Unk02e000_GetWorkArea(void);
int func_0209bf00(int x, int y, int direction, int adjacent);
u8 *Unk02f2a8_Unk_034970(u8 *p, int x, int y);
u8 *Unk09a268_Unk_09c4a8(u8 *p, int x, int y);

/* Initialize borrowed state and allocate its handle; the initial word is read
 * before the null comparison at 0x02099318, so p must be readable. */
void func_02099318(Unk0986acWork *p, u8 *record, s32 *source, int arg3)
{
    if (p->unk_00 == 1 || p == 0 || source == 0) return;
    func_02008848(p, 0, 72);
    p->unk_00 = 1;
    p->unk_04 = record;
    p->unk_08 = source;
    p->unk_0c = arg3;
    p->unk_14 = 0;
    p->unk_18 = 0;
    p->unk_1c = -1;
    p->unk_20 = -1;
    p->unk_28 = 0;
    p->unk_34 = 0;
    p->unk_2c = -1;
    p->unk_10 = func_020629ac(5, 1, 1, 1);
    if (*source == 0) p->unk_18 = -1;
}

/* Derive a value from the first empty entry, clamped to indices 5..19;
 * constants 0x5f80/0x5f81 and stride 10 are observed at 0x02098a08. */
int func_02098a08(u8 *p, int index)
{
    u32 n = Unk0986ac_FindEmpty((void *)func_0204fed8(FIELD(u32, p, 4), index));
    int a;
    if (n <= 5) {
        a = func_02059c70(0x5f80, 2);
        return a + func_02059c70(0x5f81, 2) + 32;
    }
    if (n >= 19) {
        a = func_02059c70(0x5f80, 2);
        return a + func_02059c70(0x5f81, 2) + 172;
    }
    a = func_02059c70(0x5f80, 2);
    return a + func_02059c70(0x5f81, 2) + 32 + (n - 5) * 10;
}

/* Queue selector 2 when the external operation succeeds; observed fields and
 * calls at 0x02098b14 require a live borrowed state and record. */
int func_02098b14(Unk0986acWork *p, int x, int y)
{
    while (func_0202d170() != 0) {
        if (func_0202d710(p, x, y) == 1) {
            p->unk_18 = 2;
            p->unk_1c = 0;
            p->unk_3c = func_02098a08(p->unk_04, p->unk_28);
            p->unk_30 = Unk0986ac_IsMode012((u8 *)p, 1, 0);
            return 1;
        }
        func_0202d198();
    }
    return 0;
}

/* Advance the borrowed count and output fields, queueing selector 3 at the
 * threshold; branch/load evidence is the original 0x02099174 routine. */
void func_02099174(u8 *raw)
{
    Unk0986acWork *p = (void *)raw;
    Unk09911cState *gs = GetGameState();
    if (gs == 0) return;
    if (p->unk_38 == 0) {
        if (gs->hdr->unk_10 == 1) p->unk_38 = 1;
        else {
            Unk0986ac_Unk_098aa8(raw);
            return;
        }
    }
    if (p->unk_38 == 1 && p->unk_30 == 1) {
        Unk0a0ce4_Unk_0a0da4(14);
        p->unk_30 = 0;
    }
    if (p->unk_38 == 1) p->unk_34 = 1;
    p->unk_38++;
    Unk0986ac_Unk_098aa8(raw);
    if (p->unk_38 < 1) return;
    p->unk_18 = 3;
    p->unk_38 = 1;
    p->unk_40 = p->unk_3c;
    p->unk_44 = 31;
}

/* Preserve loop-entry checks as in the preceding record scans. See DEC-014. */
#pragma push
#pragma opt_propagation off
/* Search ids 111..210 for a matching middle field and high nibble; selectors
 * 0/1/4 accept a nibble >= value, others require equality (0x020987ac). */
int func_020987ac(int field, int value)
{
    int result = 0;
    int at_least = 0;
    int id;
    switch (field) {
    case 0: case 1: case 4: at_least = 1; break;
    case 2: case 3: case 5: break;
    }
    id = 111;
    while (id <= 210) {
        Unk09974cFlags *record = Unk09974c_Unk_099d78(id);
        if (record != 0 && field == Unk09974c_GetFlagsMidMinus1(record) &&
            Unk09974c_Unk_0998d8(id) != 0) {
            if (at_least) {
                if (value <= record->unk_04_hi) { result = 1; break; }
            } else if (value == record->unk_04_hi) { result = 1; break; }
        }
        id++;
    }
    return result;
}
#pragma pop

/* Probe the current and adjacent coordinates, retaining borrowed coordinates
 * and record selector on success; direction dispatch is at 0x02098fec. */
int func_02098fec(Unk0986acWork *p, int x, int y)
{
    int found = 0;
    u8 *record;
    if (func_0209bf00(x, y, FIELD(int, Unk02e000_GetWorkArea(), 856), found) == 1) {
        p->unk_30 = Unk0986ac_IsMode012((u8 *)p, 0, 0);
        found = 1;
    } else {
        switch (FIELD(u32, Unk02e000_GetWorkArea(), 856)) {
        case 1: x++; break;
        case 2: y++; break;
        case 3: x--; break;
        case 0: y--; break;
        }
        if (func_0209bf00(x, y, FIELD(int, Unk02e000_GetWorkArea(), 856), 1) == 1) {
            p->unk_30 = Unk0986ac_IsMode012((u8 *)p, 0, 1);
            found = 1;
        }
    }
    if (found != 1) return 0;
    record = Unk09a268_Unk_09c4a8(Unk02f2a8_Unk_034970((u8 *)GetGameState() + 4, x, y), x, y);
    p->unk_18 = 2;
    p->unk_1c = 3;
    p->unk_28 = FIELD(int, record, 16);
    p->unk_45 = x;
    p->unk_46 = y;
    p->unk_3c = func_02098a08(p->unk_04, FIELD(int, record, 16));
    return 1;
}

/* Run pending/current state handlers then probe coordinates for selectors 0..2;
 * selector 4 queues teardown. The jump table at 0x020993a8 defines the cases. */
void func_020993a8(Unk0986acWork *p)
{
    int x, y, result;
    if (p->unk_00 == 0) return;
    if (p->unk_18 != -1) Unk0986ac_Unk_099274((u8 *)p);
    Unk0986ac_Unk_0992b0((u8 *)p);
    switch (p->unk_2c) {
    case 0: case 1: case 2:
        if (p->unk_14 == 3) return;
        x = FIELD(s8, Unk02e000_GetWorkArea() + 768, 100);
        y = FIELD(s8, Unk02e000_GetWorkArea() + 768, 101);
        result = func_02098b14(p, x, y);
        if (result == 0) result = func_02098b9c(p, x, y);
        if (result == 0) func_02098fec(p, x, y);
        p->unk_2c = -1;
        break;
    case 3: break;
    case 4:
        p->unk_20 = p->unk_1c;
        p->unk_1c = -1;
        p->unk_18 = 4;
        p->unk_34 = 0;
        p->unk_2c = -1;
        break;
    }
}
