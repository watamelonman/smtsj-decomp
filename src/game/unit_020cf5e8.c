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
    u8 step;
    u8 pad_0009[3];
    u32 unk_000c;
    u32 handles[4];
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
    s32 unk_0298;
    u8 pad_029c[0xc0];
    u32 unk_035c;
    u32 unk_0360;
    u32 unk_0364;
    u32 unk_0368;
    u32 slots[6];
} Unk0cf5e8Work;

void Unk1241ec_Thunk_02124338(void);
void Unk1241ec_Unk_124258(void);
void Unk1241ec_Unk_124214(void);

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
/** Enter the unit through the provider sequence at 0x020cf5e8; skip setup when busy. */
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


u8 *func_020f3de8(u32 resource, u32 index);
u32 func_020f3f2c(u32 id);
/** Resolve the first bank's current eight-byte record, submit its payload at 0x16,
 * then advance word 0x288. Evidence: halfword loads at 0x020d1414; work is borrowed.
 */
void Unk0cf5e8_Unk_0d1414(Unk0cf5e8Work *work)
{
    u32 resource = func_020f3f2c(FIELD(u16, (u8 *)work + work->unk_0288 * 8, 0xa8));
    u8 *record = func_020f3de8(resource, FIELD(u16, (u8 *)work + work->unk_0288 * 8, 0xa6));
    Unk0de678_Unk_0dec94(record + 0x16);
    work->unk_0288++;
}

/** Resolve the second bank's current eight-byte record and advance word 0x28c.
 * Evidence: halfword loads at 0x19a/0x19c in 0x020d13b4; work is borrowed.
 */
void Unk0cf5e8_Unk_0d13b4(Unk0cf5e8Work *work)
{
    u32 resource = func_020f3f2c(FIELD(u16, (u8 *)work + work->unk_028c * 8, 0x19c));
    u8 *record = func_020f3de8(resource, FIELD(u16, (u8 *)work + work->unk_028c * 8, 0x19a));
    Unk0de678_Unk_0dec94(record + 0x16);
    work->unk_028c++;
}

int func_020cb5b4(u32 value, void *field);
void func_020d0ff4(Unk0cf5e8Work *work);
void func_020d10ac(Unk0cf5e8Work *work);
/** Dispatch provider results 1/2 to callbacks and 3 to the saved state.
 * Evidence: comparisons at 0x020d0960; work must include the field at offset 8.
 */
void Unk0cf5e8_Unk_0d0960(Unk0cf5e8Work *work, u32 value)
{
    int result = func_020cb5b4(value, (u8 *)work + 8);
    if (result == 1) {
        func_020d0ff4(work);
        return;
    }
    if (result == 2) {
        func_020d10ac(work);
        return;
    }
    if (result != 3) {
        return;
    }
    func_020d1360(work, work->unk_0004);
}

/** Fill six borrowed slots and publish them to handle 0x20; loops at 0x020d1908. */
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

int Unk0f3db4_Unk_0f4448(s32 index);
int func_020e49cc(s32 kind, s32 index);
/** Check the signed half-open index range; present entries must pass provider 3.
 * Evidence: bounds and short circuit at 0x020d16f8. Empty ranges succeed.
 */
int func_020d16f8(s32 first, s32 end)
{
    for (; first < end; first++) {
        if (Unk0f3db4_Unk_0f4448(first) != 0) {
            if (func_020e49cc(3, first) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void Unk122e1c_Unk_122f88(u32 handle, s32 slot, s32 enabled);
int func_020d1958(Unk0cf5e8Work *work);
/** Publish whether halfword 0x2e is nonzero for slot 3, optionally refresh,
 * then update. Evidence: calls at 0x020d185c; borrowed work spans word 0x298.
 */
void func_020d185c(Unk0cf5e8Work *work)
{
    Unk122e1c_Unk_122f88(work->unk_0020, 3, FIELD(u16, work, 0x2e) != 0);
    if (FIELD(s32, work, 0x298) == 1) {
        func_020d18a0(work);
    }
    func_020d1958(work);
}

int Unk0e651c_Unk_0e666c(u32 id);
void Unk1241ec_Unk_124224(u32 value);
/** Forward the low halfword of word 0x2b0, replacing 2 with 50 when query
 * 0x73a is zero. Evidence: shifts and branches at 0x020d19d4; work is borrowed.
 */
void func_020d19d4(Unk0cf5e8Work *work)
{
    u16 value = FIELD(u32, work, 0x2b0);
    if (value == 2 && Unk0e651c_Unk_0e666c(0x73a) == 0) {
        Unk1241ec_Unk_124224(50);
        return;
    }
    Unk1241ec_Unk_124224(value);
}

int func_020d14cc(s32 index);
void Unk122e1c_Unk_122fa0(u32 handle, s32 slot, s32 value);
/** Refresh six slot flags and values; ARM calls at 0x020d18a0 establish order.
 * The borrowed work must include all six slots at 0x36c. */
void func_020d18a0(Unk0cf5e8Work *work)
{
    int i;
    for (i = 0; i < 6; i++) {
        Unk122e1c_Unk_122fa0(work->unk_0020, i, func_020d14cc(i) == 0);
    }
    for (i = 0; i < 6; i++) {
        Unk122e1c_SetSlot(work->unk_0020, i, work->slots[i]);
    }
}

/** Query both ranges, optionally publish individual failures, then publish and
 * return their union. Evidence: calls/loads at 0x020d1958; work is borrowed. */
int func_020d1958(Unk0cf5e8Work *work)
{
    int failed = 0;
    int mode = work->unk_0298 == 2;
    int i;
    for (i = 0; i < 2; i++) {
        int slotFailed = 0;
        if (func_020d174c(i) == 0) {
            failed = 1;
            slotFailed = 1;
        }
        if (mode) Unk122e1c_Unk_122fa0(work->unk_0020, i, slotFailed);
    }
    Unk122e1c_Unk_122f88(work->unk_0020, 1, failed);
    return failed;
}


void Unk124c5c_Set_124d6c(s32 a, s32 b);
void Unk124c5c_Set_124d8c(s32 a, s32 b);
int Unk124c5c_IsKind31(void);
void func_02124ce8(s32 value);
int func_020523a8(void);
void Unk0d1a18_Unk_0d1aa4(void);
void func_020d1a18(void);
void Unk0fc584_SetDir(s32 value);
void Unk122e1c_Unk_12306c(u32 handle);
int Unk122e1c_Unk_122f68(u32 handle);
void func_02124c5c(void);
/** Advance the five-step provider sequence and finally enter state 17.
 * Evidence: byte 8 switch at 0x020d03c0; work is borrowed. */
void func_020d03c0(Unk0cf5e8Work *work)
{
    switch (work->step) {
    case 0:
        Unk124c5c_Set_124d6c(0,1);
        Unk124c5c_Set_124d8c(1,0);
        work->step++;
        break;
    case 1:
        if (Unk124c5c_IsKind31()) {
            Unk0cf5e8_Thunk_02124258();
            func_02124ce8(3);
            work->step++;
        }
        break;
    case 2:
        if (func_020523a8() != 1) {
            Unk0d1a18_Unk_0d1aa4();
            func_020d1a18();
            work->step++;
        }
        break;
    case 3:
        Unk0fc584_SetDir(1);
        Unk124c5c_Set_124d8c(0,31);
        work->step++;
        break;
    case 4:
        work->step = 0;
        func_020d1360(work,17);
        break;
    }
}

/** Advance byte 8 through five provider stages, finally entering state 4.
 * Evidence: switch and polling calls at 0x020d02c0; work is borrowed. */
void func_020d02c0(Unk0cf5e8Work *work)
{
    switch (work->step) {
    case 0:
        Unk0fc584_SetDir(0);
        Unk122e1c_Unk_12306c(work->unk_0020);
        Unk124c5c_Set_124d6c(0,1);
        Unk124c5c_Set_124d8c(1,0);
        work->step++;
        break;
    case 1:
        if (Unk124c5c_IsKind31()) {
            Unk0bc1a8_Unk_0bc9b4(3,0);
            work->step++;
        }
        break;
    case 2:
        work->step++;
        break;
    case 3:
        if (func_020523a8() != 1) {
            func_020d19d4(work);
            Unk0cf5e8_Thunk_0212424c();
            Unk124c5c_Set_124d8c(0,31);
            work->step++;
        }
        break;
    case 4:
        if (Unk122e1c_Unk_122f68(work->unk_0020)) {
            func_02124ce8(1);
            func_02124c5c();
            work->step = 0;
            func_020d1360(work,4);
        }
        break;
    }
}

int Unk0de678_CountLeading(const void *records);
void func_020ffebc(u32 handle);
void Unk0fd268_Unk_0fd3ac(void);
void ImageBg_Unk_0e5530(void);
void func_02122e1c(u32 handle);
void Unk0f3db4_Unk_0f3dd8(void);
void Unk0de678_Unk_0dea60(void);
void func_0205bb68(void);
extern u32 data_02176bd8;
/** Release indexed handles and providers, then clear the global word.
 * Evidence: ordered calls at 0x020cf8e8; work and record storage are borrowed. */
void func_020cf8e8(Unk0cf5e8Work *work)
{
    int i;
    Unk1241ec_Unk_124258();
    Unk0bc1a8_Unk_0bc9b4(10,0);
    for (i = 0; i < Unk0de678_CountLeading((u8 *)work + 36); i++) {
        if (work->handles[i]) {
            func_020ffebc(work->handles[i]);
            work->handles[i] = 0;
        }
    }
    Unk0fd268_Unk_0fd3ac();
    ImageBg_Unk_0e5530();
    func_02122e1c(work->unk_0020);
    work->unk_0020 = 0;
    Unk044394_Unk_044534(7);
    Unk044394_Unk_044534(11);
    Unk0f3db4_Unk_0f3dd8();
    Unk0de678_Unk_0dea60();
    for (i = 0; (u32)i < 4; i++) func_0205bb68();
    data_02176bd8 = 0;
}

/** Clear word 0x364, release indexed handles, and perform the exit provider
 * sequence. Evidence: ordered calls at 0x020d0ff4; work is borrowed. */
void func_020d0ff4(Unk0cf5e8Work *work)
{
    int i;
    work->unk_0364 = 0;
    Unk1241ec_Unk_124258();
    Unk0bc1a8_Unk_0bc9b4(10,0);
    for (i = 0; i < Unk0de678_CountLeading((u8 *)work + 36); i++) {
        if (work->handles[i]) {
            func_020ffebc(work->handles[i]);
            work->handles[i] = 0;
        }
    }
    func_02122e1c(work->unk_0020);
    work->unk_0020 = 0;
    Unk0fd268_Unk_0fd3ac();
    ImageBg_Unk_0e5530();
    Unk044394_Unk_044534(7);
    Unk044394_Unk_044534(11);
    Unk1241ec_Unk_124214();
    Unk122a78_Unk_122aa0();
    Unk0f3db4_Unk_0f3dd8();
    for (i = 0; (u32)i < 4; i++) func_0205bb68();
    Unk0de678_Unk_0de870();
}

/** Borrowed callback descriptor; offsets follow stores at 0x020cf668. */
typedef struct Unk0cf5e8Callbacks {
    u32 size;
    u32 flags;
    u32 unk_08;
    void (*callbacks[6])(void);
} Unk0cf5e8Callbacks;
void func_020cf9a0(void);
void func_020d09b4(void);
void func_020d11f0(void);
/** Initialize size, flags and six callbacks, preserving word 8.
 * Evidence: stores and symbol literals at 0x020cf668; descriptor is borrowed. */
void func_020cf668(Unk0cf5e8Callbacks *descriptor)
{
    descriptor->size = 900;
    descriptor->flags = 0;
    descriptor->callbacks[0] = func_020cf9a0;
    descriptor->callbacks[1] = func_020d09b4;
    descriptor->callbacks[2] = Unk0cf5e8_Nop_0d11e8;
    descriptor->callbacks[3] = Unk0cf5e8_Nop_0d11ec;
    descriptor->callbacks[4] = (void (*)(void))func_020cf8e8;
    descriptor->callbacks[5] = func_020d11f0;
}

/** Require every provider range selected by index 0/1 to succeed; other indices
 * succeed. Evidence: immediate bounds and branches at 0x020d174c. */
int func_020d174c(s32 index)
{
    switch (index) {
    case 0:
        if (!func_020d16f8(211,260)) return 0;
        if (!func_020d16f8(261,310)) return 0;
        if (!func_020d16f8(311,360)) return 0;
        if (!func_020d16f8(361,410)) return 0;
        if (!func_020d16f8(51,110)) return 0;
        break;
    case 1:
        if (!func_020d16f8(901,1120)) return 0;
        if (!func_020d16f8(1121,1340)) return 0;
        break;
    }
    return 1;
}
