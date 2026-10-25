#include "GameState.h"
#include "types.h"

void func_02008848(void *dst, int value, u32 size);
/* External singleton layout follows the observed 32-byte name stride.
 * Direct typed updates preserve the original alias behavior; see DEC-018. */
typedef struct Unk09d42cStorage {
    char names[64][32];
    s32 count;
    s32 cursor;
    s32 phase;
    u8 rest[0x78];
} Unk09d42cStorage;
extern Unk09d42cStorage data_02176278;
#define STORAGE ((u8 *)&data_02176278)
/* Clears the singleton storage: the original passes data_02176278 and 0x884
 * bytes to the fill helper, supporting the Init name. */
void Unk09d42c_Init_data_02176278(void)
{
    func_02008848(STORAGE, 0, 0x884);
}

/* Resets the word at +0x808 and compares signed words at +0x800/+0x804.
 * The singleton must contain its full 0x884-byte storage. */
int Unk09d42c_Unk_09d4bc(void)
{
    *(int *)(STORAGE + 0x808) = 0;
    return *(int *)(STORAGE + 0x800) > *(int *)(STORAGE + 0x804);
}

/* Converts the sentinel 0xff to zero; all other signed inputs pass through. */
int Unk09d42c_Unk_09d600(int arg0)
{
    if (arg0 == 0xff) {
        arg0 = 0;
    }
    return arg0;
}

/* Tests equality of the singleton words at +0x800 and +0x804. */
int Unk09d42c_Unk_09d4e0(void)
{
    return *(int *)(((int)STORAGE) + 0x800) == *(int *)(((int)STORAGE) + 0x804);
}

u32 Unk02e000_GetWorkArea(void);
u32 func_0203611c(u32 a, u32 b);

int func_020445d0(int group, int table);
void *func_0204fde0(int table);
u32 func_0204fe18(int table);
void func_02052da0(u8 *state);
u32 *Unk02f2a8_GetCell38e8(int x, int y);
int Unk09a268_Unk_09a844(void);
int Unk1124f0_Unk_11259c(int index);
/* Maps zero to one and, when enabled, IDs 62..64 to 65..67. These
 * explicit ID comparisons in the original support the MapId name; the result
 * is truncated to a byte for other inputs. */
u8 Unk09d42c_MapId(int a, int b)
{
    if (a == 0) {
        return 1;
    }
    if (b != 0) {
        switch (a) {
        case 62:
            return 65;
        case 63:
            return 66;
        case 64:
            return 67;
        }
    }
    return a;
}

/* Borrows an entry from resource group 9, table 0 (evidence: helper arguments
 * and two-byte stride). Invalid signed indices return the table base. */
u8 *Unk09d42c_GetTable0Entry(int i)
{
    int t = func_020445d0(9, 0);
    u8 *base = (u8 *)func_0204fde0(t);
    if (i < 0 || (u32)i >= (u32)func_0204fe18(t)) {
        return base;
    }
    return base + i * 2;
}

/* Borrows group 9/table 1 storage (lookup arguments in the original).
 * Signed invalid indices return its base; valid entries have 106-byte stride. */
u8 *Unk09d42c_GetTable1Entry(int i)
{
    int t = func_020445d0(9, 1);
    u8 *base = (u8 *)func_0204fde0(t);
    if (i < 0 || (u32)i >= (u32)func_0204fe18(t)) {
        return base;
    }
    return base + i * 106;
}

/* Borrows group 9/table 2 storage (lookup arguments in the original).
 * Signed invalid indices return its base; valid entries have 24-byte stride. */
u8 *Unk09d42c_GetTable2Entry(int i)
{
    int t = func_020445d0(9, 2);
    u8 *base = (u8 *)func_0204fde0(t);
    if (i < 0 || (u32)i >= (u32)func_0204fe18(t)) {
        return base;
    }
    return base + i * 24;
}

typedef struct Unk09d42cList {
    char names[64][32];         /* count from the +0x800 count offset */
    s32 count;
} Unk09d42cList;
typedef struct Unk09d42cMap {
    u16 flag;
    u16 key;
    u16 val;
} Unk09d42cMap;
extern char data_0214c9cc[];
int func_020152cc(const char *a, const char *b);
void func_02013c3c(char *dst, const char *format, ...);
int Unk0e651c_Unk_0e666c(u16 flag);

/* Scans borrowed six-byte records in group 9/table 4, returning the first
 * value whose key equals id and whose flag helper succeeds, or id if absent. */
u16 Unk09d42c_Unk_09d73c(u16 id)
{
    int tab = func_020445d0(9, 4);
    Unk09d42cMap *e = (Unk09d42cMap *)func_0204fde0(tab);
    u32 n = func_0204fe18(tab);
    u32 i;
    for (i = 0; i < n; i++, e++) {
        if (e->key == id && Unk0e651c_Unk_0e666c(e->flag) != 0) {
            return e->val;
        }
    }
    return id;
}

/* Borrows group 9/table 3 storage (lookup arguments in the original).
 * Signed invalid indices return its base; valid entries have 52-byte stride. */
u8 *Unk09d42c_GetTable3Entry(int i)
{
    int t = func_020445d0(9, 3);
    u8 *base = (u8 *)func_0204fde0(t);
    if (i < 0 || (u32)i >= (u32)func_0204fe18(t)) {
        return base;
    }
    return base + i * 52;
}

/* Updates the supplied state, increments the cell halfword at +2 using signed
 * coordinates at state +0x7482/+0x7483, and tests the helper result for one.
 * State and its selected cell must exist; the halfword increment wraps. */
int Unk09d42c_Unk_09df70(u8 *p)
{
    int r = 0;
    u8 *cell;
    func_02052da0(p);
    cell = (u8 *)Unk02f2a8_GetCell38e8(FIELD(s8, p + 29696, 130), FIELD(s8, p + 29696, 131));
    FIELD(u16, cell, 2) += 1;
    if (Unk09a268_Unk_09a844() == 1) {
        r = 1;
    }
    return r;
}

int Unk0a23f4_Unk_0a246c(void);
void ScanVisor_Unk_0a2b18(void);
int Unk0a23f4_Unk_0a2448(void);

/* Borrowed state prefix exposing only the phase word observed in the original.
 * The caller retains ownership and must supply storage through +0x73f3. */
typedef struct Unk09d42cPhaseState {
    u8 prefix[0x73f0];
    u32 phase;
} Unk09d42cPhaseState;

/* Dispatches the supplied state's +0x73f0 phase. Phase zero advances after
 * the first predicate returns one and the action runs; phase one returns
 * whether the second predicate is zero. Other phases return zero. */
int func_0209e020(Unk09d42cPhaseState *state)
{
    int result = 0;
    switch (state->phase) {
    case 0:
        if (Unk0a23f4_Unk_0a246c() == 1) {
            ScanVisor_Unk_0a2b18();
            state->phase = state->phase + 1;
        }
        break;
    case 1:
        if (Unk0a23f4_Unk_0a2448() == 0) {
            result = 1;
        }
        break;
    }
    return result;
}

/* Calls the optional second callback in the eight-byte record selected by
 * state +0x73ec; an absent callback succeeds with one. State/record must exist. */
int Unk09d42c_Unk_09e080(u8 *p)
{
    int r = 1;
    int (**ent)(void) = (int (**)(void))Unk1124f0_Unk_11259c(FIELD(u32, p + 28672, 1004));
    if (ent[1] != 0) {
        r = ent[1]();
    }
    return r;
}

/* Returns one when no game state exists or its signed +0x73e8 word is -1. */
int Unk09d42c_Unk_09e274(void)
{
    u8 *gs = (u8 *)GetGameState();
    if (gs == 0) {
        return 1;
    }
    return FIELD(s32, gs + 28672, 1000) == -1;
}

/* Resolves arg0 through work-area +0x358, stores the result at root +0x18,
 * sets root +0x14 to four and state +0x73e8 to one. Null state is ignored;
 * a present state must have a root and a valid work area. */
void Unk09d42c_Unk_09e2f4(u32 arg0)
{
    GameState *gs = GetGameState();
    u32 v;
    if (gs == 0) {
        return;
    }
    v = func_0203611c(*(u32 *)(Unk02e000_GetWorkArea() + 0x358), arg0);
    gs->root->unk_18 = v;
    gs->root->unk_14 = 4;
    gs->unk_73e8 = 1;
}

/* Resolves arg0 through work-area +0x358, stores the result at root +0x18,
 * sets root +0x14 to two, and clears root +0xc and state +0x73e8. Null state
 * is ignored; a present state must have a root and a valid work area. */
void Unk09d42c_Unk_09e2a4(u32 arg0)
{
    GameState *gs = GetGameState();
    u32 v;
    if (gs == 0) {
        return;
    }
    v = func_0203611c(*(u32 *)(Unk02e000_GetWorkArea() + 0x358), arg0);
    gs->root->unk_18 = v;
    gs->root->unk_14 = 2;
    gs->root->unk_0c = 0;
    gs->unk_73e8 = 0;
}

/* Borrowed 24-byte resource record; flags are observed as individual bits. */
typedef struct Unk09d42cRecord {
    unsigned short bit0:1, bit1:1, bit2:1, other:13;
    u8 id;
    u8 value;
    u16 words[6];
    s8 text[8];
} Unk09d42cRecord;
/* Caller-owned 84-byte work record, with only observed fields named. */
typedef struct Unk09d42cWork {
    u32 words[6];
    u16 id;
    u16 pad_1a;
    u32 flags;
    u8 mapped;
    u8 pad_21[3];
    u32 stamp;
    u32 value;
    u32 scale[2];
    char text[9];
    u8 pad_3d[23];
} Unk09d42cWork;
void func_02008904(const void *src, void *dst, u32 size);
void func_0209d964(Unk09d42cWork *work, const Unk09d42cRecord *record, int mode);
u16 func_0209d7f4(Unk09d42cRecord *record, u16 id, int mode);
u32 Unk03e43c_Unk_03fa28(void);
void func_02034b7c(u32 a, u32 b, u32 c, u32 d, int e, int f, int g, int h);
void Unk044394_Unk_044428(int group);
void Unk044394_Unk_044534(int group);
void func_0209db70(void *work, u32 arg, u32 id, u32 value);

/* Submits the four inputs with fixed request options, then sets state mode two.
 * A missing global state suppresses the request. */
void func_0209e33c(u32 a, u32 b, u32 c, u32 d)
{
    GameState *state = GetGameState();
    if (state == 0) return;
    func_02034b7c(a, b, c, d, 3, 1, 0, 0);
    state->unk_73e8 = 2;
}

/* Appends a formatted name only if none of the existing 32-byte slots compare
 * equal. Caller must ensure remaining capacity and a valid source string. */
void func_0209d44c(const char *name)
{
    int i;
    char *entry = (char *)STORAGE;
    int count = ((Unk09d42cList *)STORAGE)->count;
    for (i = 0; i < count; i++, entry += 32) {
        if (func_020152cc(entry, name) == 0) return;
    }
    func_02013c3c(((Unk09d42cList *)STORAGE)->names[count], data_0214c9cc, name);
    data_02176278.count++;
}

/* Advances phase zero after the predicate succeeds; phase one succeeds when
 * state +0x73cc becomes two. The state and its root must exist. */
int func_0209dfb0(GameState *state)
{
    int result = 0;
    switch (((Unk09d42cPhaseState *)state)->phase) {
    case 0:
        if (Unk0a23f4_Unk_0a246c() == 1) {
            state->unk_73cc = 5;
            state->root->unk_04 = 0;
            ((Unk09d42cPhaseState *)state)->phase++;
        }
        break;
    case 1:
        if (state->unk_73cc == 2) result = 1;
        break;
    }
    return result;
}

/* Initializes the state sub-work using work-area ID and state +0x7494, bracketed
 * by group-nine provider calls; missing global state has no effect. */
void func_0209e3a8(u32 arg)
{
    GameState *state = GetGameState();
    if (state == 0) return;
    state->unk_73cc = 7;
    state->root->unk_04 = 0;
    Unk044394_Unk_044428(9);
    func_0209db70((u8 *)state + 0x7330, arg,
        FIELD(u16, Unk02e000_GetWorkArea() + 0x300, 0x5c),
        FIELD(u32, state, 0x7494));
    Unk044394_Unk_044534(9);
    state->unk_73e8 = 3;
}

/* Copies six halfwords and the bounded text, then maps the byte fields and
 * propagates three flag bits. Both borrowed records must be valid. */
void func_0209d964(Unk09d42cWork *work, const Unk09d42cRecord *record, int mode)
{
    int i;
    for (i = 0; i < 6; i++) work->words[i] = record->words[i];
    if (record->text[0] == '0') work->text[0] = 0;
    else {
        func_02008904(record->text, work->text, 8);
    }
    work->text[8] = 0;
    work->mapped = Unk09d42c_MapId(record->id, mode);
    work->value = Unk09d42c_Unk_09d600(record->value);
    work->flags |= 0x4000;
    if (record->bit0) work->flags = (work->flags & ~1) | 1;
    if (record->bit1) work->flags |= 2;
    if (record->bit2) work->flags |= 0x60;
}

/* Clears caller-owned work, resolves a resource record, and records provider
 * time/value after applying the record. Scale units are the observed 4096. */
void func_0209da38(Unk09d42cWork *work, u16 id, int mode, int map)
{
    Unk09d42cRecord record;
    int i;
    func_02008848(work, 0, 84);
    for (i = 0; i < 6; i++) work->words[i] = 0;
    work->scale[0] = 4096;
    work->scale[1] = 4096;
    if (Unk0e651c_Unk_0e666c(0x709) == 0) id = 7;
    work->id = func_0209d7f4(&record, Unk09d42c_Unk_09d73c(id), mode);
    func_0209d964(work, &record, map);
    work->flags |= 0x10;
    work->stamp = Unk03e43c_Unk_03fa28();
}

/* Clears work and copies table-two's record with fixed ID/value bytes 55/16;
 * the caller supplies valid work storage and a resource index. */
void func_0209dadc(Unk09d42cWork *work, int id)
{
    Unk09d42cRecord record;
    int i;
    func_02008848(work, 0, 84);
    for (i = 0; i < 6; i++) work->words[i] = 0;
    work->scale[0] = 4096;
    work->scale[1] = 4096;
    func_02008904(Unk09d42c_GetTable2Entry(id), &record, 24);
    record.id = 55;
    record.value = 16;
    work->id = id;
    func_0209d964(work, &record, 0);
    work->flags |= 0x10;
    work->stamp = Unk03e43c_Unk_03fa28();
}

/* Singleton view: 64 name slots followed by count, cursor, and request phase.
 * Storage is externally owned and must hold the full 0x884 bytes. */
typedef struct Unk09d42cQueue {
    char names[64][32];
    int count;
    int cursor;
    int phase;
} Unk09d42cQueue;
extern char data_0214c9d0[];
extern u8 data_02176a84[];
void func_020516dc(void *request, const char *path, int mode, int flags);
int func_02051844(void *request, int flags);
void *func_020519e8(void *request);
u32 func_0206dafc(const char *name);
void func_0206f778(u32 id, void *buffer);
void func_02053000(void *buffer);

/* Drives the queued-name request: start, poll, then consume/free the returned
 * buffer and advance the cursor. Phase three marks an exhausted queue. */
void func_0209d500(void)
{
    char path[128];

    switch (data_02176278.phase) {
    case 0:
        if (((Unk09d42cQueue *)STORAGE)->count <= data_02176278.cursor) {
            data_02176278.phase = 3;
            return;
        }
        func_02013c3c(path, data_0214c9d0, ((Unk09d42cQueue *)STORAGE)->names[data_02176278.cursor]);
        func_020516dc(data_02176a84, path, 0, 0);
        data_02176278.phase = 1;
    case 1:
        if (func_02051844(data_02176a84, -1) != 0) return;
        data_02176278.phase = 2;
        break;
    case 2: {
        char *name = ((Unk09d42cQueue *)STORAGE)->names[data_02176278.cursor];
        void *buffer = func_020519e8(data_02176a84);
        func_0206f778(func_0206dafc(name), buffer);
        func_02053000(buffer);
        data_02176278.phase = 0;
        data_02176278.cursor++;
        break;
    }
    }
}
