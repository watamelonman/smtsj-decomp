/*
 * src/game/unit_020cf5e8.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))


/** Partial work layout; padding preserves the offsets observed in ARM loads/stores. */
typedef struct Unk0cf5e8Work {
    u32 unk_0000;
    u32 unk_0004;
    u8 pad_0008[0x4];
    u32 unk_000c;
    u8 pad_0010[0x10];
    u32 unk_0020;
    u8 pad_0024[0x7c];
    s32 unk_00a0;
    u8 pad_00a4[0xf0];
    s32 unk_0194;
    u8 pad_0198[0xf0];
    s32 unk_0288;
    s32 unk_028c;
    u32 unk_0290;
    u32 unk_0294;
    u8 pad_0298[0xc4];
    u32 unk_035c;
} Unk0cf5e8Work;

void Unk1241ec_Thunk_02124338(void);
void Unk1241ec_Unk_124258(void);

void Unk0cf5e8_Nop_0cf62c(void);
void Unk0cf5e8_Nop_0d11e8(void);
void Unk0cf5e8_Nop_0d11ec(void);
void Unk0cf5e8_Thunk_02124258(void);
void Unk0cf5e8_Thunk_0212424c(void);
int Unk0cf5e8_Unk_0d139c(Unk0cf5e8Work *work);
int Unk0cf5e8_Unk_0d13fc(Unk0cf5e8Work *work);

void func_020cb3dc();
void Unk095560_Unk_095a2c();
int func_020de8b0();
void Unk0bc1a8_Unk_0bc928();
void Unk044394_Unk_044428();
void Unk122a78_Unk_122a78();
void Unk1241ec_Unk_1241ec();
u32 func_020f4560();
void Unk122e1c_SetSlot();
typedef struct Unk0cf5e8Slots {
    u8 pad_000[0x20];
    u32 h;
    u8 pad_024[0x348];
    u32 slot[6];
} Unk0cf5e8Slots;
void Unk0cf5e8_Enter(void)
{
    func_020cb3dc();
    Unk095560_Unk_095a2c();
    if (func_020de8b0(0) != 0) {
        return;
    }
    Unk044394_Unk_044428(30);
    Unk122a78_Unk_122a78();
    Unk1241ec_Unk_1241ec();
    Unk0bc1a8_Unk_0bc928(21, 0xffff, 0);
}

/** Return without side effects; the original at 0x020cf62c is only BX LR. */
void Unk0cf5e8_Nop_0cf62c(void) { }

/** Return without side effects; the original at 0x020d11e8 is only BX LR. */
void Unk0cf5e8_Nop_0d11e8(void) { }

/** Return without side effects; the original at 0x020d11ec is only BX LR. */
void Unk0cf5e8_Nop_0d11ec(void) { }

/** Tail-forwards to Unk1241ec_Unk_124258 (0x02124258) via the literal-pool
 * ldr ip,[pc]; bx ip branch; incoming registers pass through. The local (void)
 * prototype mirrors the target's current declaration.
 */
void Unk0cf5e8_Thunk_02124258(void) { Unk1241ec_Unk_124258(); }

/** Tail-forwards to Unk1241ec_Thunk_02124338 (0x0212424c) via the literal-pool
 * ldr ip,[pc]; bx ip branch; incoming registers pass through. The local (void)
 * prototype mirrors the target's current declaration.
 */
void Unk0cf5e8_Thunk_0212424c(void) { Unk1241ec_Thunk_02124338(); }

/** Return 0/1 for signed word[0x28c] < word[0x194] on a valid work block.
 * Evidence: LDR offsets and MOVLT/MOVGE at 0x020d139c; field roles are unknown.
 */
int Unk0cf5e8_Unk_0d139c(Unk0cf5e8Work *work)
{
  return work->unk_028c < work->unk_0194;
}

/** Return 0/1 for signed word[0x288] < word[0xa0] on a valid work block.
 * Evidence: LDR offsets and MOVLT/MOVGE at 0x020d13fc; field roles are unknown.
 */
int Unk0cf5e8_Unk_0d13fc(Unk0cf5e8Work *work)
{
  return work->unk_0288 < work->unk_00a0;
}


extern u8 data_02150648[];
int Unk0de678_Unk_0dec94(const void *data);
/** Partial object view preserving the predicate fields observed in the original. */
typedef struct Unk0cf5e8Obj {
    u8 pad_0000[0x98];
    s32 unk_0098;
    s32 unk_009c;
    u8 pad_00a0[0x1f0];
    s32 unk_0290;
    s32 unk_0294;
} Unk0cf5e8Obj;

/** Return 0/1 for word[0x9c] == 1 and word[0x290] == 0 on a valid object.
 * Evidence: CMP and conditional LDR/CMPEQ at 0x020d1454; field roles are unknown.
 */
int Unk0cf5e8_Unk_0d1454(Unk0cf5e8Obj *o)
{
    return o->unk_009c == 1 && o->unk_0290 == 0;
}

/** Pass the external data to the provider, then set work word 0x0290.
 * Evidence: BL followed by STR at 0x020d1470; work must span that word.
 */
void Unk0cf5e8_Unk_0d1470(Unk0cf5e8Work *work)
{
    Unk0de678_Unk_0dec94(data_02150648);
    work->unk_0290 = 1;
}

extern u8 data_02150654[];
/** Test words 0x98 and 0x294 on a valid borrowed object.
 * Evidence: CMP/LDREQ/CMPEQ at 0x020d1490 require values 1 and 0.
 */
int Unk0cf5e8_Unk_0d1490(Unk0cf5e8Obj *o)
{
    return o->unk_0098 == 1 && o->unk_0294 == 0;
}

/** Pass the external data to the provider, then set work word 0x0294.
 * Evidence: BL followed by STR at 0x020d14ac; work must span that word.
 */
void Unk0cf5e8_Unk_0d14ac(Unk0cf5e8Work *work)
{
    Unk0de678_Unk_0dec94(data_02150654);
    work->unk_0294 = 1;
}

int Unk0a0ce4_Unk_0a0da4();
void func_020d1360(Unk0cf5e8Work *work, s32 state);
/** Call provider with 5, set word 4 to 4, transition to 20, then store word 12.
 * Evidence: ordered calls and stores at 0x020d0f94; work is borrowed.
 */
void Unk0cf5e8_Unk_0d0f94(Unk0cf5e8Work *work, u32 value)
{
    Unk0a0ce4_Unk_0a0da4(5);
    work->unk_0004 = 4;
    func_020d1360(work, 20);
    work->unk_000c = value;
}

int Unk122e1c_Unk_123294();
/** Call the handle provider, store word 0x35c, set word 4, then transition to 3.
 * Evidence: ordered calls and stores at 0x020d0fc4; work is borrowed.
 */
void Unk0cf5e8_Unk_0d0fc4(Unk0cf5e8Work *work, u32 value)
{
    Unk122e1c_Unk_123294(work->unk_0020);
    work->unk_035c = value;
    work->unk_0004 = 1;
    func_020d1360(work, 3);
}

int func_020d174c(s32 index);
/** Require nonzero provider results for indices 0 and 1, stopping on failure.
 * Evidence: loop bound and conditional return at 0x020d182c.
 */
u32 Unk0cf5e8_Unk_0d182c(void)
{
  int tmp1;
  int tmp2;
  tmp2 = 0;
  do {
    tmp1 = func_020d174c(tmp2);
    if (tmp1 == 0) {
      return 0;
    }
    tmp2 = tmp2 + 1;
  } while (tmp2 < 2);
  return 1;
}

int Unk044394_Unk_044534();
int Unk095560_Unk_0956c8();
int Unk0bc1a8_Unk_0bc9b4();
int Unk0de678_Unk_0de870();
int Unk122a78_Unk_122aa0();
/** Conditionally call four providers, then always call the final two.
 * Evidence: conditional branch and ordered BLs at 0x020cf630.
 */
void Unk0cf5e8_Unk_0cf630(void)
{
  int tmp1;
  tmp1 = Unk0de678_Get_data_021508d4();
  if (tmp1 == 0) {
    Unk0bc1a8_Unk_0bc9b4(0x15,0);
    Unk1241ec_Unk_124214();
    Unk122a78_Unk_122aa0();
    Unk044394_Unk_044534(0x1e);
  }
  Unk0de678_Unk_0de870();
  Unk095560_Unk_0956c8();
  return;
}


int func_020f3de8();
int func_020f3f2c();
/* decompiler-derived */
void Unk0cf5e8_Unk_0d1414(int arg0)
{
  u32 tmp1;
  int tmp2;
  tmp1 = func_020f3f2c(*(u16 *)(arg0 + ((Unk0cf5e8Work *)arg0)->unk_0288 * 8 + 0xa8));
  tmp2 = func_020f3de8(tmp1,*(u16 *)(arg0 + ((Unk0cf5e8Work *)arg0)->unk_0288 * 8 + 0xa6));
  Unk0de678_Unk_0dec94((const void *)(tmp2 + 0x16));
  ((Unk0cf5e8Work *)arg0)->unk_0288 = ((Unk0cf5e8Work *)arg0)->unk_0288 + 1;
  return;
}


/* decompiler-derived */
void Unk0cf5e8_Unk_0d13b4(int arg0)
{
  u32 tmp1;
  int tmp2;
  tmp1 = func_020f3f2c(*(u16 *)(arg0 + ((Unk0cf5e8Work *)arg0)->unk_028c * 8 + 0x19c));
  tmp2 = func_020f3de8(tmp1,*(u16 *)(arg0 + ((Unk0cf5e8Work *)arg0)->unk_028c * 8 + 0x19a));
  Unk0de678_Unk_0dec94((const void *)(tmp2 + 0x16));
  ((Unk0cf5e8Work *)arg0)->unk_028c = ((Unk0cf5e8Work *)arg0)->unk_028c + 1;
  return;
}

int func_020cb5b4();
int func_020d0ff4();
int func_020d10ac();
/* decompiler-derived */
void Unk0cf5e8_Unk_0d0960(int arg0,u32 arg1)
{
  int tmp1;
  tmp1 = func_020cb5b4(arg1,arg0 + 8);
  if (tmp1 == 1) {
    func_020d0ff4(arg0);
    return;
  }
  if (tmp1 == 2) {
    func_020d10ac(arg0);
    return;
  }
  if (tmp1 != 3) {
    return;
  }
  func_020d1360((Unk0cf5e8Work *)arg0,((Unk0cf5e8Work *)arg0)->unk_0004);
  return;
}

void Unk0cf5e8_InitSlots(Unk0cf5e8Slots *p)
{
    int j;
    for (j = 0; j < 6; j++) {
        p->slot[j] = func_020f4560(j);
    }
    for (j = 0; j < 6; j++) {
        Unk122e1c_SetSlot(p->h, j, p->slot[j]);
    }
}

void func_020d18a0(Unk0cf5e8Work *work);
void Unk122e1c_ClearSlots(u32 handle);

/** Perform state-dependent provider calls before storing the requested state.
 * Evidence: switch comparisons at 0x020d1360 select 10, 13 and 21; the final
 * STR writes word zero. The borrowed work must contain the handle at 0x20.
 */
void func_020d1360(Unk0cf5e8Work *work, s32 state)
{
    switch (state) {
    case 10:
        func_020d18a0(work);
        break;
    case 13:
    case 21:
        Unk122e1c_ClearSlots(work->unk_0020);
        break;
    }
    work->unk_0000 = state;
}
