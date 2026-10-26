#include "GameState.h"
#include "types.h"

void func_02118c6c(void);
/* The target is an unconditional tail branch to func_02118c6c; no arguments. */
void Unk09ee4c_Thunk_02118c6c(void) { func_02118c6c(); }

extern u8 data_0213c190[];
void func_0204f1f8(int v, u32 b, u32 c, u8 *d);
/* Target loads unsigned d[1], adds base, and clamps negative sums before the call.
 * d must address at least two bytes; b, c and d pass through unchanged. */
void Unk09ee4c_Call_0204f1f8(int base, u32 b, u32 c, u8 *d)
{
    int v = d[1] + base;
    if (v < 0) {
        v = 0;
    }
    func_0204f1f8(v, b, c, d);
}

/* Only the word at +0x64 is evidenced by Call_0204f68c. */
typedef struct Unk09ee4cObj {
    u8 pad_0000[0x64];
    u32 unk_64;
} Unk09ee4cObj;

void func_0204f68c(u32 a, u32 b, u32 *p);

/* Target forwards the address of the +0x64 word only when it is nonzero.
 * o must be valid, and the callee may modify that word. */
void Unk09ee4c_Call_0204f68c(u32 a, u32 b, Unk09ee4cObj *o)
{
    if (o->unk_64 == 0) {
        return;
    }
    func_0204f68c(a, b, &o->unk_64);
}

/* Target uses a multiply-add with stride 24 and data_0213c190 as its base.
 * Returns the address as a target-width integer; the caller supplies the index. */
int Unk09ee4c_Unk_0a03b8(int arg0)
{
    return arg0 * 0x18 + ((int)data_0213c190);
}

void ScanVisor_Unk_0a2ae8(u32 a, int b);
/* With a live game state, forwards arg0 and constant 2 to the visor helper,
 * then writes mode 0x14 at +0x73e8 (evidence: target call and stores). */
void Unk09ee4c_Unk_09ef50(u32 arg0)
{
    GameState *gs = GetGameState();
    if (gs == 0) {
        return;
    }
    ScanVisor_Unk_0a2ae8(arg0, 2);
    gs->unk_73e8 = 0x14;
}

/* Target clears +0x7400, sets root +0x5c, and selects mode 0x12.
 * A missing game state is accepted; a live state must have a valid root. */
void Unk09ee4c_Unk_09ee4c(void)
{
    GameState *gs = GetGameState();
    if (gs == 0) {
        return;
    }
    gs->unk_7400 = 0;
    gs->root->unk_5c = 1;
    gs->unk_73e8 = 0x12;
}

void Unk11f2d0_Unk_11f308(void *sub, u32 a);
/* Target passes the embedded +0x7598 object and arg0 to the helper before
 * selecting mode 0x15. A missing game state leaves everything untouched. */
void Unk09ee4c_Unk_09ef80(u32 arg0)
{
    GameState *gs = GetGameState();
    if (gs == 0) {
        return;
    }
    Unk11f2d0_Unk_11f308(gs->unk_7598, arg0);
    gs->unk_73e8 = 0x15;
}

typedef void (*Unk09ee4cCallback)(u32);
Unk09ee4cCallback *Unk1124f0_Unk_11259c(u32 id);
/* Invokes the descriptor callback if present, then records mode 22 and the ID.
 * Evidence: indirect call and state stores at +0x73e8 and +0x73ec. */
void Unk09ee4c_Unk_09efb4(u32 id)
{
    u8 *gs = (u8 *)GetGameState();
    void (**ent)(u32);
    if (gs == 0) {
        return;
    }
    ent = (void (**)(u32))Unk1124f0_Unk_11259c(id);
    if (ent[0] != 0) {
        ent[0](id);
    }
    FIELD(u32, gs + 28672, 1000) = 22;
    FIELD(u32, gs + 28672, 1004) = id;
}

/* A separate view records only the packed word evidenced by this accessor. */
typedef struct Unk09ee4cPackedState {
    u8 pad_0000[0x73c0];
    u32 unk_73c0;
} Unk09ee4cPackedState;

/* Target extracts bits 10..19 of the word at state +0x7000+0x3c0.
 * Returns zero when no state exists; the result is in the range 0..1023. */
u16 Unk09ee4c_GetField3c0Bits(void)
{
    Unk09ee4cPackedState *gs = (Unk09ee4cPackedState *)GetGameState();
    if (gs == 0) {
        return 0;
    }
    return (u16)((gs->unk_73c0 << 12) >> 22);
}

void *func_02044ec4(u32 id);
void *func_020a1740(u16 id);
int func_0209f550(int base, u32 id, u32 entry, u32 flag);
void Unk044904_ClearSlotsUnk1de(u32 id);
int func_0209f034(int base, u32 first, u32 second, u8 *record, u32 flag);
/* Accepts category 2 IDs and forwards the resource byte at +3 to f550.
 * Evidence: ID byte test and the +0x1d8 resource lookup. */
int Unk09ee4c_Unk_09f5d8(u32 a, u32 id)
{
    u8 *e;
    if (((id >> 16) & 0xff) != 2) {
        return -1;
    }
    e = (u8 *)func_02044ec4(id);
    e = (u8 *)func_020a1740(FIELD(u16, e + 256, 216));
    return func_0209f550(a, id, e[3], 0);
}

int func_020152cc(const void *text, const void *pattern);
extern u8 data_0214c9e4[];
void func_0204f188(int value, u32 id, u32 kind, u8 *record, u32 flag);
/* Submits a nonempty record, choosing its ID from the kind at +18.
 * Evidence: byte tests, pattern call, signed +16 adjustment and clamping.
 * The borrowed record contains at least 20 readable bytes. */
int func_0209f034(int base, u32 first, u32 second, u8 *record, u32 flag)
{
    int value;
    u32 kind;
    if (*(s8 *)record == 0) return -1;
    if (*(s8 *)record == 48) return -1;
    if (func_020152cc(record, data_0214c9e4) == 0) return -1;
    kind = FIELD(u16, record, 18);
    switch (kind) {
    case 3: case 4: case 5: first = second; break;
    }
    value = FIELD(s16, record, 16) + base;
    if (value < 0) value = 0;
    func_0204f188(value, first, kind, record, flag);
    return value;
}


/* Clears the ID slots, then submits four consecutive 22-byte records.
 * Evidence: loop bound, pointer stride and constant fifth argument. */
void Unk09ee4c_Unk_09fd14(u32 a, u8 *b)
{
    int j;
    Unk044904_ClearSlotsUnk1de(a);
    for (j = 0; j < 4; j++) {
        func_0209f034(0, a, a, b, 1);
        b += 22;
    }
}


/* Borrowed descriptor flag layout; target shifts establish bits 0/1/14/15.
 * No ownership or meaning for the remaining bits is inferred. */
typedef struct Unk09ee4cFlags {
    u32 bit0 : 1;
    u32 bit1 : 1;
    u32 unused : 12;
    u32 bit14 : 1;
    u32 bit15 : 1;
    u32 upper : 16;
} Unk09ee4cFlags;

void func_0204f364(int value, u32 id, int flag);
/* Adds the signed +0x192 adjustment and clamps at zero; bits 0 and 1 of
 * descriptor +16 select the forwarded flag (evidence: target shifts). */
void func_0209f298(int base, u32 id, u8 *descriptor, u8 *record)
{
    int value = base + FIELD(s16, record + 256, 146);
    Unk09ee4cFlags *bits = (Unk09ee4cFlags *)(descriptor + 16);
    if (value < 0) value = 0;
    if (bits->bit0 || bits->bit1)
        func_0204f364(value, id, 1);
    else
        func_0204f364(value, id, 0);
}

void func_0204f650(int base, u32 id, u32 value, u32 kind);
void func_0204f24c(int base, u32 id, u32 value, u32 kind, u32 slot, u32 flag);
/* Bits 14 and 15 at +132 enable the +112 and +116 submissions.
 * Evidence: target shifts and calls with kinds 21/22 and 1/3. */
void func_0209f480(int base, u32 id, u8 *record)
{
    Unk09ee4cFlags *bits;
    int slot;
    if (FIELD(Unk09ee4cFlags, record, 132).bit14) {
        func_0204f650(base, id, FIELD(u32, record, 112), 21);
        func_0204f24c(base, id, FIELD(u32, record, 112), 1, 0, 1);
    }
    bits = (Unk09ee4cFlags *)(record + 132);
    if (bits->bit15) {
        slot = 0;
        if (bits->bit14) {
            base += 4;
            slot = 1;
        }
        func_0204f650(base, id, FIELD(u32, record, 116), 22);
        func_0204f24c(base, id, FIELD(u32, record, 116), 3, slot, 1);
    }
}

u8 *Unk0aa118_Unk_0afb40(u32 entry);
void func_0204f520(int value, u32 id, u32 flag);
void func_0204a780(void *resource, u32 value);
/* Resolves an entry, submits four 22-byte records, and returns signed +0x190.
 * Evidence: lookup null check, loop stride, +0x192 adjustment and final load. */
int func_0209f550(int base, u32 id, u32 entry, u32 flag)
{
    u8 *record = Unk0aa118_Unk_0afb40(entry);
    int i;
    u8 *current;
    if (record == 0) return -1;
    current = record;
    for (i = 0; i < 4; i++) {
        func_0209f034(base, id, id, current, flag);
        current += 22;
    }
    func_0204f520(base + FIELD(s16, record + 256, 146), id, flag);
    func_0204a780(func_02044ec4(id), 12);
    return FIELD(s16, record + 256, 144);
}

u8 *Unk02e000_GetWorkArea(void);
/* Records the selected table index and signed coordinates, optionally stepping
 * by work-area direction 0..3; target table +16 selects this adjustment.
 * Evidence: work +0x364/+0x365 loads and state +0x747c/+0x7482 stores. */
void func_0209ee80(u32 index)
{
    u8 *gs = (u8 *)GetGameState();
    u8 *entry;
    s8 x, y;
    if (gs == 0) return;
    entry = (u8 *)Unk09ee4c_Unk_0a03b8(index);
    x = FIELD(s8, Unk02e000_GetWorkArea() + 768, 100);
    y = FIELD(s8, Unk02e000_GetWorkArea() + 768, 101);
    if (FIELD(u32, entry, 16) == 1) {
        switch (FIELD(u32, Unk02e000_GetWorkArea(), 856)) {
        case 0: y--; break;
        case 2: y++; break;
        case 3: x--; break;
        case 1: x++; break;
        }
    }
    FIELD(u32, gs + 28672, 1148) = index;
    FIELD(s8, gs + 28672, 1154) = x;
    FIELD(s8, gs + 28672, 1155) = y;
    ScanVisor_Unk_0a2ae8(index, 2);
    FIELD(u32, gs + 28672, 1000) = 19;
}

u8 *Unk044904_Unk_045080(void);
int func_020f8098(void *work, u32 kind, u32 id);
u8 *Unk044904_Get_data_0215ee98(void);
void *Unk044904_Unk_04502c(void);
void func_020449c4(void *work, u32 id);
void func_0204f3a4(int base, u32 id, u32 first, u32 second);
/* Target tests provider flags 19/12 before submitting category-2 records.
 * Evidence: provider +64 shifts, ID byte comparison, and helper calls.
 * Providers retain ownership of the borrowed work and flag storage. */
void func_020a02c0(u32 id, int base, u32 extra, u32 force)
{
    int blocked = 0;
    if (func_020f8098(Unk044904_Unk_045080(), 3, id) != 0)
        blocked = 1;
    else if (force != 0)
        blocked = 1;
    if (!blocked) {
        int submitted = 0;
        if ((FIELD(u32, Unk044904_Get_data_0215ee98(), 64) << 12) >> 31) {
            int result = Unk09ee4c_Unk_09f5d8(base, id);
            if (result >= 0) {
                base += result;
                submitted = 1;
            }
        }
        if (!submitted && extra != 0) {
            if (!((FIELD(u32, Unk044904_Get_data_0215ee98(), 64) << 19) >> 31) &&
                ((id >> 16) & 255) == 2) {
                int result = func_0209f550(base, id, 1, 1);
                if (result >= 0) base += result;
            }
        }
        {
            int flag = !submitted;
            func_0204f3a4(base, id, submitted ? 0 : 1, flag);
        }
    } else {
        func_020449c4(Unk044904_Unk_04502c(), id);
    }
}

/* Borrowed eight-byte entry; widths follow the target's shift extractions. */
typedef struct Unk09ee4cEntry {
    u32 value;
    u32 bit0 : 1;
    u32 bit1 : 1;
    u32 bit2 : 1;
    u32 bits34 : 2;
    u32 bit5 : 1;
    u32 bit6 : 1;
    u32 rest : 25;
} Unk09ee4cEntry;
/* Only the low category byte is interpreted by these dispatchers. */
typedef struct Unk09ee4cCategory {
    u32 category : 8;
    u32 remaining : 24;
} Unk09ee4cCategory;
void func_0204f59c(int base, u32 id, u32 value);
void func_0204f5e0(int base, u32 id, u32 value);
void func_0204f618(int base, u32 id, u32 value);
/* Increments resource byte +478 and submits the indexed eight-byte entry.
 * Evidence: byte increment, descriptor +132 category and entry flag shifts.
 * Caller supplies a valid descriptor and an in-range entry index. */
int func_0209f2e0(int base, u32 first, u32 second, u8 *descriptor, int index)
{
    Unk09ee4cEntry *entry = (Unk09ee4cEntry *)(descriptor + 12) + index;
    u8 *resource = func_02044ec4(second);
    int slot = resource[478]++;
    if (entry->bit2) {
        func_0204f24c(base, second, 0, 4, slot, 0);
        return 0;
    }
    switch (FIELD(Unk09ee4cCategory, descriptor, 132).category) {
    case 3:
        if (!entry->bits34) {
            func_0204f59c(base, second, entry->value);
            func_0204f24c(base, second, entry->value, 0, slot, entry->bit6 ? 1 : 0);
            goto flags;
        }
    case 8:
            func_0204f5e0(base, second, entry->value);
            func_0204f24c(base, second, entry->value, 2, slot, entry->bit6 ? 1 : 0);
        goto flags;
    case 9:
        func_0204f618(base, first, entry->value);
    default:
    flags:
        if (entry->bit1)
            func_0204f24c(base, second, 0, 7, slot, 0);
        else if (entry->bit0)
            func_0204f24c(base, second, 0, 5, slot, 0);
        break;
    }
    return 1;
}

void func_0204f6d8(int base, u32 id, void *record);
u32 func_0204aa18(void *resource);
void func_0204f158(int base, u32 first, u32 second, u32 value);

/* One 8-byte descriptor entry: an unsigned value followed by its flag word. */
typedef struct Unk09ee4cRecord {
    u32 value;
    u32 bits;
} Unk09ee4cRecord;

/* Bit view of Unk09ee4cRecord.bits; only the observed low bits are named. */
typedef struct Unk09ee4cBits {
    u32 bit0 : 1;
    u32 bit1 : 1;
    u32 bit2 : 1;
    u32 bits34 : 2;
    u32 bit5 : 1;
    u32 bit6 : 1;
    u32 rest : 25;
} Unk09ee4cBits;

/* Descriptor header: +8 is the signed entry count and +12 starts the entries. */
typedef struct Unk09ee4cDescriptor {
    u8 pad00[8];
    int count;
    Unk09ee4cRecord entries[64];
} Unk09ee4cDescriptor;

/* Dispatches each descriptor entry, advancing base by 20 per entry, then
 * optionally submits the +100 object. Evidence: category/flag shifts and calls.
 * Descriptor +8 is the signed entry count; storage must cover that count. */
void func_0209f0d8(int base, u32 id, Unk09ee4cDescriptor *descriptor, u32 suppress)
{
    int i;
    for (i = 0; i < descriptor->count; base += 20, i++) {
        Unk09ee4cBits *flags = (Unk09ee4cBits *)&descriptor->entries[i].bits;
        u32 kind = FIELD(Unk09ee4cCategory, descriptor, 132).category;
        if (flags->bit5) kind = 7;
        if (flags->bits34) kind = 8;
        if (kind == 5) {
            if ((FIELD(u32, descriptor, 132) << 9) >> 31) kind = 6;
        }
        switch (kind) {
        case 6:
            func_0204f650(base, id, descriptor->entries[i].value, 21);
            func_0204f24c(base, id, descriptor->entries[i].value, 1, i, 1);
            break;
        case 7:
            func_0204f650(base, id, descriptor->entries[i].value, 22);
            func_0204f24c(base, id, descriptor->entries[i].value, 3, i, 1);
            break;
        case 8:
            func_0204f5e0(base, id, descriptor->entries[i].value);
            func_0204f24c(base, id, descriptor->entries[i].value, 2, i, 1);
            break;
        }
    }
    if (suppress != 0) return;
    if (FIELD(u32, descriptor, 100) == 0) return;
    func_0204f6d8(base, id, (u8 *)descriptor + 100);
    if (FIELD(u32, descriptor, 100) == 1)
        func_0204f158(base, 60, 12, func_0204aa18(func_02044ec4(id)));
}
