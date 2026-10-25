/*
 * src/game/unit_020de678.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_021508d4[];
int Unk044394_Unk_044428(u32 value);
int Unk044394_Unk_044534(u32 value);
int Unk0e651c_Unk_0e666c(int value);
void Unk124c5c_Unk_124e04(void);

void Unk065e88_Unk_065eac(void);
void Unk095560_Unk_096130(void);

void Unk0de678_Nop_0df05c(void);
void Unk0de678_Nop_0df060(void);
void Unk0de678_Thunk_02124e04(void);
u32 Unk0de678_Get_data_021508d4(void);
void Unk0de678_Unk_0dea60(void);
void Unk0de678_Unk_0df598(void);
void Unk0de678_Unk_0df5a8(void);
void Unk0de678_Unk_0dee2c(int arg0);

/* Target 0x020df05c is only bx lr; this callback has no side effects. */
void Unk0de678_Nop_0df05c(void) { }

/* Target 0x020df060 is only bx lr; this callback has no side effects. */
void Unk0de678_Nop_0df060(void) { }

/* The literal relocation at 0x020df580 identifies the tail-call target. */
void Unk0de678_Thunk_02124e04(void) { Unk124c5c_Unk_124e04(); }

/* Target 0x020de950 loads the first word at data_021508d4; its meaning is unknown. */
u32 Unk0de678_Get_data_021508d4(void)
{
  return *data_021508d4;
}

/* Target 0x020dea60 tail-calls Unk044394_Unk_044534 with selector 31. */
void Unk0de678_Unk_0dea60(void)
{
  Unk044394_Unk_044534(0x1f);
}

/* Target 0x020df598 tail-calls Unk044394_Unk_044428 with selector 32. */
void Unk0de678_Unk_0df598(void)
{
  Unk044394_Unk_044428(0x20);
}

/* Target 0x020df5a8 tail-calls Unk044394_Unk_044534 with selector 32. */
void Unk0de678_Unk_0df5a8(void)
{
  Unk044394_Unk_044534(0x20);
}

/* Target 0x020dee2c adds 0x5f1 before forwarding to Unk0e651c_Unk_0e666c. */
void Unk0de678_Unk_0dee2c(int arg0)
{
  Unk0e651c_Unk_0e666c(arg0 + 0x5f1);
}



/* At 0x020df584, sets the global word at offset 0x2c to one. */
void Unk0de678_Unk_0df584(void)
{
  *(u32 *)(((int)data_021508d4) + 0x2c) = 1;
}

int func_0205bb68(void);
int Unk0a23f4_Unk_0a2414(void);
int Unk0fc584_Unk_0fc6a0(void);
/* At 0x020df0a4, invokes the observed helper sequence with selector 30. */
void Unk0de678_Unk_0df0a4(void)
{
  Unk0a23f4_Unk_0a2414();
  Unk044394_Unk_044534(0x1e);
  Unk065e88_Unk_065eac();
  Unk0de678_Unk_0df5a8();
  Unk0fc584_Unk_0fc6a0();
  func_0205bb68();
  Unk095560_Unk_096130();
}


int Unk124c5c_Unk_124d54(void);
/* At 0x020de870, runs the eight-helper sequence only when global offset
 * 0xc8 is zero. No arguments; helper selector meanings remain unknown. */
void Unk0de678_Unk_0de870(void)
{
  if (*(int *)(((int)data_021508d4) + 200) != 0) {
    return;
  }
  Unk0a23f4_Unk_0a2414();
  Unk044394_Unk_044534(0x1e);
  Unk124c5c_Unk_124d54();
  Unk065e88_Unk_065eac();
  Unk0de678_Unk_0df5a8();
  Unk0fc584_Unk_0fc6a0();
  func_0205bb68();
  Unk095560_Unk_096130();
}

int Unk02e000_Unk_02e0cc(void);
int Unk05b82c_Unk_05b82c(int selector);
int Unk065e88_Unk_065e88(void);
int Unk0964f8_Unk_096508(void);
int Unk0a23f4_Unk_0a23f4(int selector);
int Unk0fc584_Unk_0fc674(int selector);
int Unk0fc584_Unk_0fc84c(int selector);
int func_020dec18(u32 value);
/* Borrowed 26-byte records; only the halfword at offset 10 is observed. */
typedef struct Unk0de678Rec {
    u8 pad_00[0xa];
    u16 unk_0a;
    u8 pad_0c[0xe];
} Unk0de678Rec;
/* At 0x020dea70, counts up to four leading records with nonzero offset-10 values.
 * The caller supplies four readable records. */
int Unk0de678_CountLeading(Unk0de678Rec *p)
{
    int n = 0;
    int i = 0;
    for (; i < 4; i++) {
        if (p[i].unk_0a == 0) {
            break;
        }
        n++;
    }
    return n;
}

/* At 0x020debf8, clears global offset 0xcc when the forwarded query succeeds. */
int Unk0de678_Unk_0debf8(u32 a)
{
    int r = func_020dec18(a);
    if (r != 0) {
        *(u32 *)(((int)data_021508d4) + 0xcc) = 0;
    }
    return r;
}

/* At 0x020df064, calls nine helpers in relocation order with the observed
 * selectors. No arguments; helper ownership stays external. */
void Unk0de678_Unk_0df064(void)
{
  Unk0964f8_Unk_096508();
  Unk0de678_Unk_0df598();
  Unk02e000_Unk_02e0cc();
  Unk05b82c_Unk_05b82c(0xc2);
  Unk0fc584_Unk_0fc674(1);
  Unk0fc584_Unk_0fc84c(0);
  Unk065e88_Unk_065e88();
  Unk044394_Unk_044428(0x1e);
  Unk0a23f4_Unk_0a23f4(2);
}

int Unk02d15c_Unk_02d8a8(int selector, u32 value, u32 argument);
int Unk02d15c_Unk_02da48(void);
int func_020cb3dc(void);
/* At 0x020dec94, queries with the supplied word and clears global offset
 * 0xcc on success; returns a normalized boolean. */
u32 Unk0de678_Unk_0dec94(u32 arg0)
{
  u32 value1;
  int value2;
  func_020cb3dc();
  value1 = Unk02d15c_Unk_02da48();
  value2 = Unk02d15c_Unk_02d8a8(1,value1,arg0);
  if (value2 != 0) {
    *(u32 *)(((int)data_021508d4) + 0xcc) = 0;
    return 1;
  }
  return 0;
}

void Unk0bc1a8_Unk_0bc9b4(u32 selector, u32 value);
void func_020df330(u32 value);
void Unk095560_Unk_0958a8(int a, int b);
/* At 0x020dedf8, copies the low bytes of global words 32/36 when offset
 * 16 is set, otherwise writes zeros. Caller supplies two writable bytes;
 * these two byte stores support the existing GetPair name. */
void Unk0de678_GetPair(u8 *out)
{
    if (FIELD(u32, data_021508d4, 16) != 0) {
        out[0] = FIELD(u32, data_021508d4, 32);
        out[1] = FIELD(u32, data_021508d4, 36);
        return;
    }
    out[0] = 0;
    out[1] = 0;
}

/* At 0x020df348, activates state 3 and stores the supplied word at offset 12. */
void Unk0de678_Unk_0df348(u32 a)
{
    FIELD(u32, data_021508d4, 4) = 1;
    func_020df330(3);
    FIELD(u32, data_021508d4, 12) = a;
}

/* At 0x020df4cc, records a low-byte value and a word, sets offset 16,
 * and resets offset 28. No ownership of external storage is transferred. */
void Unk0de678_Unk_0df4cc(u32 a, u32 b)
{
    FIELD(u32, data_021508d4, 16) = 1;
    FIELD(u8, data_021508d4, 24) = a;
    FIELD(u32, data_021508d4, 20) = b;
    FIELD(u32, data_021508d4, 28) = 0;
}

/* At 0x020df4f0, clears global words 32/36, forwards two zeros, then
 * clears offset 16. No arguments or transferred ownership. */
void Unk0de678_Unk_0df4f0(void)
{
    FIELD(u32, data_021508d4, 32) = 0;
    FIELD(u32, data_021508d4, 36) = 0;
    Unk095560_Unk_0958a8(0, 0);
    FIELD(u32, data_021508d4, 16) = 0;
}

/* At 0x020df330, sets global offset 4 and records the supplied state word. */
void func_020df330(u32 value)
{
    FIELD(u32, data_021508d4, 4) = 1;
    FIELD(u32, data_021508d4, 8) = value;
}

/* At 0x020deedc, calls selector 24 only when global offset 0xc8 is zero,
 * then always forwards selector 9 to the second helper. */
void func_020deedc(void)
{
    if (FIELD(u32, data_021508d4, 0xc8) == 0) {
        Unk0bc1a8_Unk_0bc9b4(24, 0);
    }
    Unk044394_Unk_044534(9);
}

/* Borrowed resource-22 entries have a leading key and a 28-byte stride;
 * remaining fields are deliberately opaque to these searches. */
typedef struct Unk0de678SearchRecord {
    u16 key;
    u8 pad_02[26];
} Unk0de678SearchRecord;
void *func_020445d0(u32 resource, u32 selector);
Unk0de678SearchRecord *func_0204fde0(void *resource);
u32 func_0204fe18(void *resource);
void func_0209db70(void *work, int value, int enabled, int selector);
void Unk0a0ce4_Unk_0a0da4(int selector);
void func_020df420(int a, int b, int c, int d, int e);
void func_0205e590(int selector);
extern u32 data_02150904[];

/* At 0x020de720, searches resource 22/4 by its leading halfword.
 * Returns borrowed storage for the first match, or null; key is compared
 * as a full word, as observed in the original cmp instruction. */
const Unk0de678SearchRecord *func_020de720(u32 key)
{
    void *resource = func_020445d0(22, 4);
    Unk0de678SearchRecord *record;
    u32 count;
    u32 i;
    if (resource == 0) return 0;
    record = func_0204fde0(resource);
    count = func_0204fe18(resource);
    for (i = 0; i < count; i++, record++) {
        if (record->key == key) return record;
    }
    return 0;
}

/* At 0x020de784, searches the same borrowed resource entries and returns
 * the first matching zero-based index, or -1 when absent. */
int func_020de784(u32 key)
{
    void *resource = func_020445d0(22, 4);
    Unk0de678SearchRecord *record;
    u32 count;
    u32 i;
    if (resource == 0) return -1;
    record = func_0204fde0(resource);
    count = func_0204fe18(resource);
    for (i = 0; i < count; i++, record++) {
        if (record->key == key) return i;
    }
    return -1;
}

/* At 0x020df520, sets global offset 40, forwards the argument to the
 * work area at data_02150904, and invokes the observed selector sequence. */
void func_020df520(int value)
{
    FIELD(u32, data_021508d4, 40) = 1;
    func_0209db70(data_02150904, value, 1, 0);
    Unk0a0ce4_Unk_0a0da4(8);
    func_020df420(1, 1, 2, 0, 3);
    func_0205e590(10);
}

int func_0202d170(void);
void func_0202d198(void);
int Unk02d15c_IsMode1Match(int selector);
int Unk02d15c_Unk_02d9f8(void);
int Unk02d15c_Unk_02d9a8(void);
void Unk124c5c_Thunk_02124e9c(void);
void Unk02cad4_SetupDisplayMode(int mode, int a, int b);
void func_02095f94(void);
void func_020dee40(void);
int func_0206552c(void);
int func_020961a0(void);
void Unk02f2a8_Unk_035440(u32 value);
void Unk02cad4_Unk_02cbdc(u32 value);
void func_020ded70(void);
void func_020deedc(void);
/* Callback work contains two state words and a saved provider selector. */
typedef struct Unk0de678Work { u32 state, phase, selector; } Unk0de678Work;
void func_020def0c(Unk0de678Work *work);
u32 Unk02cad4_GetUnk00(void);
u32 *func_020611dc(void (*a)(Unk0de678Work *), void (*b)(void), void (*c)(void),
                    void (*d)(void), int size, int enabled, int zero, int one);
void Unk0bc1a8_Unk_0bc928(int selector, int value, int zero);
void func_02057fd8(void);
void func_02057dcc(u32 a, u32 b, u32 c, u32 d);
void func_0205dee8(int mode, u32 value, float a, float b, int offset,
                  float x, float y, float c, float z, float d);

/* At 0x020dec18, scans the external iterator for selectors 1, 3, or the
 * queried selector. The incoming word is unused in the original. */
int func_020dec18(u32 value)
{
    int found = 0;
    int selector;
    func_020cb3dc();
    selector = Unk02d15c_Unk_02d9f8();
    while (func_0202d170()) {
        if (Unk02d15c_IsMode1Match(1)) { found = 1; break; }
        if (Unk02d15c_IsMode1Match(3)) { found = 1; break; }
        if (Unk02d15c_IsMode1Match(selector)) { found = 1; break; }
        func_0202d198();
    }
    return found;
}

/* At 0x020deb68, scans three selectors and clears offset 0xcc on success. */
int func_020deb68(void)
{
    int found = 0;
    int selector;
    func_020cb3dc();
    selector = Unk02d15c_Unk_02d9a8();
    while (func_0202d170()) {
        if (Unk02d15c_IsMode1Match(1)) { found = 1; break; }
        if (Unk02d15c_IsMode1Match(3)) { found = 1; break; }
        if (Unk02d15c_IsMode1Match(selector)) { found = 1; break; }
        func_0202d198();
    }
    if (found) FIELD(u32, data_021508d4, 0xcc) = 0;
    return found;
}

/* At 0x020de7e8, optionally clears 208 bytes of state, then initializes
 * external providers; the second flag enables the final selector-2 call. */
void func_020de7e8(int clear, int enable)
{
    if (clear) __builtin__clear(data_021508d4, 208);
    Unk0964f8_Unk_096508();
    Unk0de678_Unk_0df598();
    Unk02e000_Unk_02e0cc();
    Unk05b82c_Unk_05b82c(194);
    Unk0fc584_Unk_0fc674(1);
    Unk0fc584_Unk_0fc84c(0);
    Unk065e88_Unk_065e88();
    Unk124c5c_Thunk_02124e9c();
    Unk044394_Unk_044428(30);
    if (enable) Unk0a23f4_Unk_0a23f4(2);
}

/* At 0x020de8b0, optionally searches selector 40 before initializing
 * state and starting the observed display sequence. Returns the search flag. */
int func_020de8b0(int bypass)
{
    int found = 0;
    if (!bypass) {
        while (func_0202d170()) {
            if (Unk02d15c_IsMode1Match(40)) { found = 1; break; }
            func_0202d198();
        }
    }
    if (found) {
        Unk02cad4_SetupDisplayMode(2, 0, 0);
        func_020de7e8(1, 1);
        data_021508d4[0] = 1;
        func_02095f94();
        func_020dee40();
    } else {
        func_020de7e8(1, 0);
        data_021508d4[0] = 0;
    }
    return found;
}

/* At 0x020decd8, processes states 0/1 at offset 0xcc. Returns one only
 * when state 1 is waiting for the external completion query. */
int func_020decd8(void)
{
    u32 *state = data_021508d4;
    switch (FIELD(u32, state, 0xcc)) {
    case 0:
        if (!func_0206552c()) {
            func_02095f94();
            FIELD(u32, state, 0xcc) = 1;
        }
        break;
    case 1:
        if (FIELD(u32, state, 4)) {
            if (FIELD(u32, state, 8) == 3)
                Unk02f2a8_Unk_035440(FIELD(u32, state, 12));
            Unk02cad4_Unk_02cbdc(FIELD(u32, state, 8));
            return 0;
        }
        if (!func_020961a0()) return 1;
        if (FIELD(u32, state, 16)) func_020ded70();
        break;
    }
    return 0;
}

/* At 0x020dee40, creates a 12-byte callback work area, records the current
 * provider value, and enables selectors 9 and 24. Null allocation ends early. */
void func_020dee40(void)
{
    u32 *work = func_020611dc(func_020def0c, Unk0de678_Nop_0df05c,
        Unk0de678_Nop_0df060, func_020deedc, 12, 1, 0, 1);
    if (!work) return;
    work[0] = 0;
    work[1] = 0;
    work[2] = Unk02cad4_GetUnk00();
    FIELD(u32, data_021508d4, 8) = Unk02cad4_GetUnk00();
    Unk044394_Unk_044428(9);
    Unk0bc1a8_Unk_0bc928(24, 65535, 0);
}

/* At 0x020de678, supplies six packed four-channel color pairs and six
 * draw calls. Packed channel arithmetic supports the existing palette name. */
void Unk_LoadPalette_020de678(u32 value)
{
    int i, low, high, offset;
    func_02057fd8();
    i = 0; high = 0; offset = 0; low = 25;
    for (; i < 6; i++, low += 38, high += 38, offset += 32) {
        u32 a = ((u32)low << 24) + ((u32)low << 16) + ((u32)low << 8);
        u32 channel = high + 63;
        u32 b = (channel << 24) + (channel << 16) + (channel << 8);
        func_02057dcc(a + 255, b + 255, b + 255, a + 255);
        func_0205dee8(2, value, 0.0f, 0.0f, offset, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f);
    }
}

void Unk124c5c_Set_124d8c(int enabled, int kind);
void Unk124c5c_Set_124d6c(int first, int second);
void Unk124e68_Set(int mode, int step, int count);
void func_020fc584(int mode, int step, int count);

/* At 0x020df374, configures selector 31 and forwards the transition;
 * active global state routes optional transitions by the observed mode set. */
void func_020df374(int first, int second, int mode, int step, int count)
{
    Unk124c5c_Set_124d8c(0, 31);
    if (data_021508d4[0]) {
        Unk124c5c_Set_124d6c(first, 0);
        Unk124e68_Set(mode, step, count);
        if (second) {
            switch (mode) {
            case 0: case 1: case 3: func_020fc584(0, step, count); break;
            default: func_020fc584(1, step, count); break;
            }
        }
    } else {
        Unk124c5c_Set_124d6c(first, second);
        Unk124e68_Set(mode, step, count);
    }
}

/* At 0x020df420, enables the provider and forwards transitions using
 * selectors 2/3 when global state is active; arguments remain provider-owned. */
void func_020df420(int first, int second, int mode, int step, int count)
{
    Unk124c5c_Set_124d8c(1, 0);
    if (data_021508d4[0]) {
        Unk124c5c_Set_124d6c(first, 0);
        Unk124e68_Set(mode, step, count);
        if (second) {
            switch (mode) {
            case 0: case 1: case 3: func_020fc584(2, step, count); break;
            default: func_020fc584(3, step, count); break;
            }
        }
    } else {
        Unk124c5c_Set_124d6c(first, second);
        Unk124e68_Set(mode, step, count);
    }
}

int Unk095560_Unk_096484(void);
void func_02111494(void);
void Unk02dcfc_Unk_02de6c(void);
void Unk095560_Call_020773dc(void);
void Unk0fc584_SetField28bc(int value);
/* At 0x020df234, advances callback phases, restoring display providers at
 * phase 1 and returning to state 1 at phase 6. Caller owns writable work. */
void func_020df234(Unk0de678Work *work)
{
    switch (work->phase) {
    case 0:
        Unk0bc1a8_Unk_0bc9b4(24, 0);
        Unk0de678_Unk_0de870();
        work->phase++;
        break;
    case 1:
        if (!Unk095560_Unk_096484()) return;
        func_02111494();
        Unk02cad4_SetupDisplayMode(2, 0, 0);
        func_020de7e8(0, 1);
        Unk0964f8_Unk_096508();
        Unk02dcfc_Unk_02de6c();
        Unk095560_Call_020773dc();
        Unk0bc1a8_Unk_0bc928(24, 65535, 0);
        Unk0fc584_SetField28bc(1);
        func_020df374(1, 1, 0, 0, 0);
        work->phase++;
        break;
    case 6:
        work->state = 1;
        work->phase = 0;
        break;
    default:
        work->phase++;
        break;
    }
}

int Unk124c5c_IsKind31(void);
void func_0204870c(void *first, void *second);
int BattleTask_Unk_0481d4(void);
void Unk02dcfc_Unk_02ddf4(void);
extern u32 data_02150958[];
/* At 0x020df0cc, sequences seven callback phases. Global packed bits
 * 2..9 at offset 192 select the observed alternate exit. */
void func_020df0cc(Unk0de678Work *work)
{
    switch (work->phase) {
    case 0:
        if (!Unk124c5c_IsKind31()) return;
        work->phase++;
        break;
    case 1:
        Unk0bc1a8_Unk_0bc9b4(24, 0);
        Unk0de678_Unk_0df0a4();
        work->phase++;
        break;
    case 2:
        work->phase++;
        break;
    case 3:
        Unk124c5c_Set_124d8c(0, 0);
        func_0204870c(data_02150904, data_02150958);
        work->phase++;
        break;
    case 4:
        if (BattleTask_Unk_0481d4()) return;
        work->phase++;
        break;
    case 5:
        if ((FIELD(u32, data_021508d4, 192) << 22) >> 24 == 3) {
            FIELD(u32, data_021508d4, 200) = 1;
            Unk02cad4_Unk_02cbdc(4);
            return;
        }
        Unk02cad4_SetupDisplayMode(2, 0, 0);
        Unk124c5c_Set_124d8c(1, 31);
        Unk124e68_Set(0, 0, 3);
        work->phase++;
        break;
    case 6:
        Unk0de678_Unk_0df064();
        Unk0964f8_Unk_096508();
        Unk02dcfc_Unk_02ddf4();
        Unk095560_Call_020773dc();
        Unk0bc1a8_Unk_0bc928(24, 65535, 0);
        work->state = 0;
        work->phase = 0;
        break;
    }
}

int Unk0fc584_GetField28bc(void);
/* At 0x020def0c, drives the callback state machine and consumes global
 * pending transitions. The provider supplies a writable 12-byte work area. */
void func_020def0c(Unk0de678Work *work)
{
    switch (work->state) {
    case 0:
        work->state = 1;
        break;
    case 1:
        if (!Unk0fc584_GetField28bc()) Unk0fc584_SetField28bc(1);
        if (!func_020961a0() || FIELD(u32, data_021508d4, 4) == 1) {
            if (!FIELD(u32, data_021508d4, 4))
                FIELD(u32, data_021508d4, 8) = Unk02cad4_GetUnk00();
            work->selector = FIELD(u32, data_021508d4, 8);
            if (work->selector == 3)
                Unk02f2a8_Unk_035440(FIELD(u32, data_021508d4, 12));
            func_020df374(1, 1, 0, 0, 0);
            Unk02cad4_Unk_02cbdc(work->selector);
            work->state = 4;
            return;
        }
        if (FIELD(u32, data_021508d4, 16)) func_020ded70();
        if (FIELD(u32, data_021508d4, 40)) {
            FIELD(u32, data_021508d4, 40) = 0;
            work->state = 2;
        }
        if (FIELD(u32, data_021508d4, 44)) {
            FIELD(u32, data_021508d4, 44) = 0;
            Unk0fc584_SetField28bc(0);
            work->state = 3;
        }
        break;
    case 2:
        func_020df0cc(work);
        break;
    case 3:
        func_020df234(work);
        break;
    case 4:
        break;
    }
}

/* The by-value resource block has four 26-byte records plus ten opaque
 * trailing bytes, as established by the caller and stack argument offsets. */
typedef struct Unk0de678RecordBlock { Unk0de678Rec records[4]; u8 tail[10]; } Unk0de678RecordBlock;
void func_020fa8a8(int selector, const u32 *values, int mode);
/* At 0x020deaa0, forwards four offset-10 halfwords and a selection word;
 * the last populated slot chooses selector 10, 11, or 12. */
void func_020deaa0(int kind, Unk0de678RecordBlock records, u32 selection)
{
    u32 values[6] = {0, 0, 0, 0, 0, 0};
    int i;
    Unk0bc1a8_Unk_0bc928(23, kind, 0);
    for (i = 0; i < 4; i++) values[i] = records.records[i].unk_0a;
    values[4] = selection;
    if (values[3]) func_020fa8a8(12, values, 2);
    else if (values[2]) func_020fa8a8(11, values, 2);
    else func_020fa8a8(10, values, 2);
}

/* Resource-31 records have four signed keys and a 114-byte stride. */
typedef struct Unk0de678ResourceRecord { s16 keys[4]; u8 pad_08[106]; } Unk0de678ResourceRecord;
void func_020119c0(void *destination, int value, u32 size);
void func_020119a0(void *destination, const void *source, u32 size);
/* At 0x020de960, clears the caller's 114-byte output and searches resource
 * 31 backwards. Counts non-minus-one keys, then queries that many leading
 * keys and copies the first qualifying record; returns one on copy, zero when no record qualifies. */
int func_020de960(Unk0de678ResourceRecord *output, int selector)
{
    void *resource;
    int count;
    Unk0de678ResourceRecord *records;
    int i;
    int j;
    Unk044394_Unk_044428(31);
    func_020119c0(output, 0, 114);
    resource = func_020445d0(31, selector);
    count = func_0204fe18(resource);
    records = (Unk0de678ResourceRecord *)func_0204fde0(resource);
    for (i = count - 1; i >= 0; i--) {
        u8 populated = 0;
        int k;
        for (k = 0; k < 4; k++) {
            if (records[i].keys[k] != -1) populated++;
        }
        for (j = 0; j < populated; j++) {
            if (!Unk0e651c_Unk_0e666c(records[i].keys[j])) break;
            if (j == populated - 1) {
                func_020119a0(output, &records[i], 114);
                return 1;
            }
        }
    }
    return 0;
}
