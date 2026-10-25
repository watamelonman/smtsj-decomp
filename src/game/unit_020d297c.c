/*
 * src/game/unit_020d297c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0d297cWork {
    u16 *data;
    s32 count;
    s32 capacity;
    s32 index;
    s32 unk_0010;
    u32 unk_0014;
    u32 unk_0018;
    u32 unk_001c;
    s32 unk_0020;
} Unk0d297cWork;


void Unk094fe0_SetUnkField9a0(u32 value);
u32 Unk094fe0_GetWorkUnkField9a0(void);
int Unk0e5fb8_Unk_0e6448(u32 index);
int Unk0e5fb8_Unk_0e64c8(u32 value);
void Unk0e651c_Unk_0e651c(u32 value, u32 mode);

int Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e6448(u32 index);
void Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e64c8(u32 value);
void Unk0d297c_Thunk_02095398(u32 value);
u32 Unk0d297c_Thunk_020953ac(void);
void Unk0d297c_Unk_0d2adc(u32 arg0);
/** Borrowed buffer view; +0x0c is the index used by the 0x020d32f8 accessor. */
typedef struct Unk0d297cBuffer {
    u16 *data;
    s32 unk_0004;
    s32 unk_0008;
    s32 index;
} Unk0d297cBuffer;

u16 Unk0d297c_Unk_0d32e8(const Unk0d297cBuffer *buffer, int index);
u16 *Unk0d297c_Unk_0d32f8(const Unk0d297cBuffer *buffer);

u32 func_0204fdac(u32 handle, int table);
u32 func_0204fe18(u32 table);
void *func_0204fde0(u32 table);
u32 func_0204459c(int index);
/** Borrowed 68-byte record view; only the index byte is interpreted here. */
typedef struct Unk0d297cEntry { u8 index; u8 rest[67]; } Unk0d297cEntry;
/** Search handle 28 table zero, normalizing indices outside 1..count to one (0x020d2eb0). */
int func_020d2eb0(u32 index)
{
    u32 table = func_0204fdac(func_0204459c(28), 0);
    u32 count = func_0204fe18(table);
    Unk0d297cEntry *entry;
    u32 i;
    if (!(index >= 1 && count >= index)) index = 1;
    entry = func_0204fde0(table);
    for (i = 0; i < count; i++, entry++) {
        if (entry->index == index) return (int)entry;
    }
    return 0;
}
int func_020d297c(u16 id);
/** Add 50 and truncate to a halfword before forwarding; see 0x020d2a8c. */
void Unk0d297c_Call_020d297c(u32 id)
{
    func_020d297c((u16)(id + 50));
}

/** Forward the table index unchanged (branch at 0x020d2b58).
 * The target saves r0 as the Get2BitsD80 index and returns its low pair (0..3).
 * Evidence: 0x020e6490 combines the bits; 0x020e6494 masks the result to u8. */
int Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e6448(u32 index) { return Unk0e5fb8_Unk_0e6448(index); }

/** Forward the caller value unchanged; target 0x020e64c8 accepts it in r0. */
void Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e64c8(u32 value) { Unk0e5fb8_Unk_0e64c8(value); }

/** Forward the value to the +0x9a0 setter, as shown by the target branch. */
void Unk0d297c_Thunk_02095398(u32 value) { Unk094fe0_SetUnkField9a0(value); }

/** Preserve the +0x9a0 getter result, as shown by the target branch. */
u32 Unk0d297c_Thunk_020953ac(void) { return Unk094fe0_GetWorkUnkField9a0(); }

/** Forward the caller value with mode zero, evidenced by mov r1, #0 at 0x020d2adc. */
void Unk0d297c_Unk_0d2adc(u32 arg0)
{
  Unk0e651c_Unk_0e651c(arg0,0);
}

/** Read a halfword without bounds checks; caller must supply a valid index (0x020d32e8). */
u16 Unk0d297c_Unk_0d32e8(const Unk0d297cBuffer *buffer, int index)
{
    return buffer->data[index];
}

/** Return the borrowed buffer address at the +0x0c index; caller guarantees validity. */
u16 *Unk0d297c_Unk_0d32f8(const Unk0d297cBuffer *buffer)
{
    return buffer->data + buffer->index;
}

/** Store the first two words and clear +0x0c/+0x10; +0x08 is preserved (0x020d3250). */
void Unk0d297c_Unk_0d3250(u32 *arg0,u32 arg1,u32 arg2)
{
  *arg0 = arg1;
  arg0[1] = arg2;
  arg0[3] = 0;
  arg0[4] = 0;
}


/** Read the halfword at the signed +0x04 index; caller guarantees validity (0x020d32ac). */
u16 Unk0d297c_Unk_0d32ac(const Unk0d297cBuffer *buffer)
{
  return buffer->data[buffer->unk_0004];
}


/** Clear words +0x04, +0x00, +0x0c and +0x10, preserving +0x08 (0x020d31e8). */
void Unk0d297c_Unk_0d31e8(u32 *arg0)
{
  arg0[1] = 0;
  *arg0 = 0;
  arg0[3] = 0;
  arg0[4] = 0;
}


/** Write without advancing +0x04 when signed index < +0x08; no lower bound check (0x020d3290). */
void Unk0d297c_Unk_0d3290(Unk0d297cBuffer *buffer, u16 value)
{
  if (buffer->unk_0004 < buffer->unk_0008) {
    buffer->data[buffer->unk_0004] = value;
  }
}

int func_02053000();
void Unk0d297c_FreeSlot(u32 *slot);
/** Release the leading slot, then release and clear +0x18; call order from 0x020d33ac. */
void Unk0d297c_Unk_0d33ac(Unk0d297cWork *work)
{
  Unk0d297c_FreeSlot((u32 *)work);
  func_02053000(work->unk_0018);
  work->unk_0018 = 0;
}


u32 func_0204459c(int index);
u32 func_0204fe68(u32 handle, int index);
u32 func_0204fed8(u32 table, u32 index);
/** Forward index through handle 29, table 0; call arguments at 0x020d2f18 establish the lookup chain. */
void Unk0d297c_Unk_0d2f18(u32 arg0)
{
  u32 value;
  value = func_0204459c(0x1d);
  value = func_0204fe68(value,0);
  func_0204fed8(value,arg0);
}


/** Forward index through handle 29, table 1; call arguments at 0x020d2f3c establish the lookup chain. */
void Unk0d297c_Unk_0d2f3c(u32 arg0)
{
  u32 value;
  value = func_0204459c(0x1d);
  value = func_0204fe68(value,1);
  func_0204fed8(value,arg0);
}


/** Forward index through handle 29, table 3; call arguments at 0x020d2f98 establish the lookup chain. */
void Unk0d297c_Unk_0d2f98(u32 arg0)
{
  u32 value;
  value = func_0204459c(0x1d);
  value = func_0204fe68(value,3);
  func_0204fed8(value,arg0);
}

void Unk02dcfc_SetField64(void);
int func_02095818(void);
void Unk0d297c_Unk_0d2aa4(u32 index);
void Unk0e651c_Unk_0e654c(int index);
void Unk0e651c_Unk_0e6560(int index);
/** Forward index to both setup helpers, then set field 64 unless query returns 1 (0x020d2b70). */
void Unk0d297c_Unk_0d2b70(u32 arg0)
{
  int value;
  Unk0e651c_Unk_0e654c(arg0);
  Unk0d297c_Unk_0d2aa4(arg0);
  value = func_02095818();
  if (value == 1) {
    return;
  }
  Unk02dcfc_SetField64();
}

void Unk094fe0_Call_02095370(u32 index, int mode);
void Unk0d297c_Unk_0d2aec(u32 index);
/** Forward index through three helpers (middle mode 1), then set field 64; order from 0x020d2c1c. */
void Unk0d297c_Unk_0d2c1c(u32 arg0)
{
  Unk0e651c_Unk_0e6560(arg0);
  Unk094fe0_Call_02095370(arg0,1);
  Unk0d297c_Unk_0d2aec(arg0);
  Unk02dcfc_SetField64();
}

extern u32 data_02176be0[];
/** Release the LoadMissionLog handle unconditionally, clear its slot, and return 1 (0x020d2e88). */
u32 Unk0d297c_Unk_0d2e88(void)
{
  func_02053000(*data_02176be0);
  *data_02176be0 = 0;
  return 1;
}


/** Read the next halfword only if signed index < capacity - 1 (0x020d32c0).
 * No lower bound check; caller guarantees valid storage and representable capacity - 1. */
u16 Unk0d297c_Unk_0d32c0(const Unk0d297cBuffer *buffer)
{
  if (buffer->unk_0004 < buffer->unk_0008 - 1) {
    return *(buffer->data + buffer->unk_0004 + 1);
  }
  return 0;
}


void func_02008848(u32 destination, int value, u32 byte_count);
/** Clear the +0x18 allocation for +0x20 words, then reset +0x1c (0x020d3330). */
void Unk0d297c_Unk_0d3330(Unk0d297cWork *arg0){
  func_02008848(arg0->unk_0018,0,arg0->unk_0020 << 2);
  arg0->unk_001c = 0;
  return;
}

u32 func_02052fe0(u32 byte_count);
/** Allocate capacity halfwords and clear indices +4/+0x0c/+0x10; evidence: 0x020d3200. */
void Unk0d297c_Unk_0d3200(u32 *arg0,int arg1)
{
  u32 tmp1;
  arg0[1] = 0;
  arg0[2] = arg1;
  tmp1 = func_02052fe0(arg1 << 1);
  *arg0 = tmp1;
  arg0[3] = 0;
  arg0[4] = 0;
  return;
}



int func_020d2eb0(u32 index);
/** Resolve mission-log table zero using record word +0x40; absent handle/record returns zero. */
u32 Unk0d297c_Unk_0d2fbc(u32 arg0)
{
  int tmp1;
  u32 tmp2;
  if (*data_02176be0 == 0) {
    return 0;
  }
  tmp1 = func_020d2eb0(arg0);
  if (tmp1 != 0) {
    tmp2 = func_0204fe68(*data_02176be0,0);
    tmp2 = func_0204fed8(tmp2,*(u32 *)(tmp1 + 0x40));
    return tmp2;
  }
  return 0;
}

u32 Unk09974c_Unk_099bac(u32 index);
u32 Unk0a163c_Unk_0a1814(u32 index);
int func_0204fb14(int index);
/** Dispatch selectors 1/3/4 to observed lookup helpers; other selectors return zero (0x020d3034). */
u32 Unk0d297c_Unk_0d3034(u32 arg0,u32 arg1)
{
  u16 tmp1;
  u32 tmp2;
  switch(arg0) {
  case 0:
    break;
  case 1:
    tmp2 = Unk09974c_Unk_099bac(arg1);
    return tmp2;
  case 2:
    return 0;
  case 3:
    tmp2 = Unk0a163c_Unk_0a1814(arg1);
    return tmp2;
  case 4:
    tmp1 = func_0204fb14(2);
    tmp2 = Unk0a163c_Unk_0a1814(tmp1);
    return tmp2;
  }
  return 0;
}

extern u8 data_02150680[];
int func_02051610();
/** Load Data/Event/Mission/MissionLog.mbb (data_02150680 string), store its handle, return 1. */
u32 Unk0d297c_LoadMissionLog(void)
{
  u32 tmp1;
  tmp1 = func_02051610(data_02150680);
  *data_02176be0 = tmp1;
  return 1;
}

/** Reset the leading buffer and extension; +0x20 defaults to 256 words (0x020d3308). */
void Unk0d297c_Unk_0d3308(Unk0d297cWork *arg0)
{
  Unk0d297c_Unk_0d31e8((u32 *)arg0);
  arg0->unk_0014 = 0;
  arg0->unk_0018 = 0;
  arg0->unk_001c = 0;
  arg0->unk_0020 = 0x100;
}

/** Allocate both buffers once, then clear extension storage; ownership evidenced at 0x020d3358. */
void Unk0d297c_Unk_0d3358(Unk0d297cWork *arg0, int arg1)
{
  u32 tmp1;
  if (arg0->unk_0014 == 0) {
    Unk0d297c_Unk_0d3200((u32 *)arg0, arg1);
    if (arg0->unk_0018 != 0) {
      func_02053000(arg0->unk_0018);
      arg0->unk_0018 = 0;
    }
    tmp1 = func_02052fe0(arg0->unk_0020 << 2);
    arg0->unk_0018 = tmp1;
    arg0->unk_0014 = 1;
  }
  Unk0d297c_Unk_0d3330(arg0);
}

void Unk0e5fb8_Unk_0e649c(u32 obj, int mode);

/** Forward index with mode 1 to both helpers and store +0x9a0 only when query is zero; 0x020d2aa4. */
void Unk0d297c_Unk_0d2aa4(u32 obj)
{
    if (Unk0e5fb8_Unk_0e6448(obj) != 0) {
        return;
    }
    Unk0e5fb8_Unk_0e649c(obj, 1);
    Unk0e651c_Unk_0e651c(obj, 1);
    Unk094fe0_SetUnkField9a0(obj);
}

/** Pass mode 2 only for a nonzero query result; cmp/popeq at 0x020d2af8-0x020d2afc establishes the guard. */
void Unk0d297c_Unk_0d2aec(u32 obj)
{
    if (Unk0e5fb8_Unk_0e6448(obj) == 0) {
        return;
    }
    Unk0e5fb8_Unk_0e649c(obj, 2);
}

int Unk0e651c_Unk_0e666c(u32 index);
/** Local borrowed halfword storage; signed count/capacity follow 0x020d3264. */
typedef struct Unk0d297cU16Vec {
    u16 *buf;
    int n;
    int cap;
} Unk0d297cU16Vec;
/** Resolve entry zero of table zero from the mission-log handle, or return zero (0x020d3004). */
int Unk0d297c_Unk_0d3004(void)
{
    int v;
    if (*data_02176be0 == 0) {
        return 0;
    }
    v = func_0204fe68(*data_02176be0, 0);
    return func_0204fed8(v, 0);
}

/** Query index 0x751; the literal and branch to 0x020e666c establish this contract. */
int Unk0d297c_Unk_0d3138(void)
{
    return Unk0e651c_Unk_0e666c(0x751);
}

/** Release a nonzero owned slot and clear it; load/guard/call/store at 0x020d322c establish ownership. */
void Unk0d297c_FreeSlot(u32 *slot)
{
    if (*slot == 0) {
        return;
    }
    func_02053000(*slot);
    *slot = 0;
}

/** Append one halfword and advance count if signed count < capacity; evidence: 0x020d3264.
 * Stores the low halfword of x. Caller supplies valid storage and a nonnegative
 * count; no lower bound check exists. */
void Unk0d297c_PushU16(Unk0d297cU16Vec *v, u32 x)
{
    if (v->n < v->cap) {
        v->buf[v->n] = x;
        v->n++;
    }
}

/** Borrowed lookup record prefix; byte +3 and five signed words are observed below. */
typedef struct Unk0d297cRecord {
    u8 unk_0000[3];
    u8 unk_0003 : 7;
    u8 unk_0003_high : 1;
    s32 unk_0004[5];
} Unk0d297cRecord;

/** Resolve table 2 of handle 29 using byte +3's low seven bits; null record returns zero.
 * Evidence: ldrb/lsl/lsr at 0x020d2f84 through 0x020d2f8c. */
u32 func_020d2f60(u32 index)
{
    Unk0d297cRecord *record = (Unk0d297cRecord *)func_020d2eb0(index);
    u32 table;
    if (record == 0) {
        return 0;
    }
    table = func_0204459c(29);
    table = func_0204fe68(table, 2);
    return func_0204fed8(table, record->unk_0003);
}

/** Select word 1..5 after byte-wrapped decrement; missing/out-of-range returns zero.
 * Negative words return one, others are queried at 0x020e666c; evidence: 0x020d2b10. */
int func_020d2b10(u32 index, u8 selector)
{
    Unk0d297cRecord *record;
    s32 value;
    selector = (u8)(selector - 1);
    if (selector >= 5) {
        return 0;
    }
    record = (Unk0d297cRecord *)func_020d2eb0(index);
    if (record == 0) {
        return 0;
    }
    value = record->unk_0004[selector];
    if (value < 0) {
        return 1;
    }
    return Unk0e651c_Unk_0e666c(value);
}

void Unk0e651c_SetBitChecked(u32 index, int value);
/** Update selected nonnegative record bit after query-dependent setup; selector wraps to 0..4 (0x020d2b98). */
void func_020d2b98(u32 index, u8 selector)
{
    int state;
    Unk0d297cRecord *record;
    s32 value;
    selector = (u8)(selector - 1);
    if (selector >= 5) return;
    state = Unk0e5fb8_Unk_0e6448(index);
    if (state != 0) {
        if (!(state != 1 && state != 2)) {
            Unk094fe0_SetUnkField9a0(index);
            if (Unk0e5fb8_Unk_0e64c8(index) == 0) Unk0e651c_Unk_0e651c(index, 2);
        }
    }
    record = (Unk0d297cRecord *)func_020d2eb0(index);
    if (record == 0) return;
    value = record->unk_0004[selector];
    if (value < 0) return;
    Unk0e651c_SetBitChecked(value, 1);
}
int Unk094fe0_Call_02095320(u32 index);
/** Return integer percent of flagged records whose index query succeeds; original has no zero-count guard. */
int func_020d30b0(void)
{
    int matched = 0;
    int total = 0;
    u32 table = func_0204fdac(func_0204459c(28), 0);
    u32 count = func_0204fe18(table);
    Unk0d297cRecord *record = func_0204fde0(table);
    u32 i;
    for (i = 0; i < count; i++, record = (Unk0d297cRecord *)((u8 *)record + 68)) {
        if (record->unk_0003_high) {
            total++;
            if (Unk094fe0_Call_02095320(*(u8 *)record)) matched++;
        }
    }
    return matched * 100 / total;
}
/** Borrowed selector result; halfword tag/index and word payload follow 0x020d315c..31c0. */
typedef struct Unk0d297cSelection { u16 tag; u16 index; u32 value; } Unk0d297cSelection;
u32 Unk0a163c_Unk_0a1728(void);
/** Validate a tagged lookup result with the original tag-specific bounds and payload tests (0x020d314c). */
int func_020d314c(const Unk0d297cSelection *selection)
{
    if (selection == 0) return 0;
    switch (selection->tag) {
    case 1:
        if (selection->index >= 0x5b5) return 0;
        return selection->value != 0;
    case 2: return selection->value != 0;
    case 3: return selection->index < Unk0a163c_Unk_0a1728();
    case 4: return 1;
    }
    return 0;
}

extern const char data_02150660[];
int func_02013c3c(char *destination, const char *format, ...);
int func_020513d4(const char *path);
void func_02052f58(int mode);
void func_02052f68(void);
int Unk02d15c_IsStatus1OrNeg(s16 index);
int Unk02d15c_IsStatus0OrNeg(s16 index);
void Unk095560_Unk_09596c(u32 index);
/** Borrowed file entry: word index plus two signed-halfword status arguments stored as words. */
typedef struct Unk0d297cFileEntry { u32 index; s32 first; s32 second; } Unk0d297cFileEntry;
/** Format the path at data_02150660 and apply entries passing both status checks; release loaded file (0x020d297c). */
int func_020d297c(u16 id)
{
    char path[64] = {0};
    u32 handle, table, count;
    Unk0d297cFileEntry *entry;
    u32 i;
    func_02013c3c(path, data_02150660, id);
    if (func_020513d4(path) == 0) return 1;
    func_02052f58(0);
    handle = func_02051610(path);
    func_02052f68();
    table = func_0204fdac(handle, 0);
    count = func_0204fe18(table);
    entry = func_0204fde0(table);
    for (i = 0; i < count; i++, entry++) {
        s16 first = (s16)entry->first;
        u32 index = entry->index;
        s16 second = (s16)entry->second;
        if (Unk02d15c_IsStatus1OrNeg(first) && Unk02d15c_IsStatus0OrNeg(second)) {
            Unk095560_Unk_09596c(index);
        }
        if (i == count - 1) break;
    }
    func_02053000(handle);
    return 1;
}

int func_02062268(const u16 *stream);
int func_0204f9fc(int token);
int func_0204f9d8(int token);
int func_0204f8c0(int token);

/** Copy a terminated halfword stream, replacing 0x8001 with zero and recording
 * section starts; calls and stores at 0x020d33cc..34dc establish the contract.
 * Caller supplies a valid terminated stream and writable work storage. */
void func_020d33cc(Unk0d297cWork *work, const u16 *stream)
{
    int token, position, i;
    Unk0d297c_Unk_0d3358(work, func_02062268(stream) + 1);
    token = stream[0];
    position = 0;
    ((s32 *)work->unk_0018)[0] = position;
    position++;
    while (!func_0204f9fc(token)) {
        if (!func_0204f9d8(token)) {
            Unk0d297c_PushU16((Unk0d297cU16Vec *)work, token);
            token = stream[position++];
        } else {
            if (token == 0x8001) {
                Unk0d297c_PushU16((Unk0d297cU16Vec *)work, 0);
                work->unk_001c++;
                ((s32 *)work->unk_0018)[work->unk_001c] = work->count;
            } else {
                Unk0d297c_PushU16((Unk0d297cU16Vec *)work, token);
            }
            token = func_0204f8c0(token);
            for (i = 0; i < token; i++, position++) {
                Unk0d297c_PushU16((Unk0d297cU16Vec *)work, stream[position]);
            }
            token = stream[position];
            position++;
        }
    }
    Unk0d297c_PushU16((Unk0d297cU16Vec *)work, 0);
}
