#include "types.h"

/* Partial work layout from the word accesses in 020e747c and 020e7734..020e78b0. */
typedef struct Unk0e7290Work {
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    u32 unk_000c;
    u32 unk_0010;
    u8 pad_0014[0x78];
    void *unk_008c;
    s32 *unk_0090;
    u8 records[0x170];
    u32 unk_0204;
} Unk0e7290Work;

/* Each successive flag is 0x5c bytes after the first flag at work + 0xed. */
typedef struct Unk0e7290FlagView {
    u8 pad_0000[0xed];
    u8 unk_00ed;
} Unk0e7290FlagView;

/* Resource 0x22's signed stride is read at +0xc by 020e77a8. */
typedef struct Unk0e7290Resource {
    u8 pad_0000[0xc];
    s32 unk_000c;
} Unk0e7290Resource;

/* Byte-aligned template preserves the source object's copy alignment. */
typedef struct Unk0e7290Path { char bytes[64]; } Unk0e7290Path;
/* Four words are copied together from each entry at +0xc. */
typedef struct Unk0e7290Bounds { u32 words[4]; } Unk0e7290Bounds;
/* Resource entries expose only the bounds used here. */
typedef struct Unk0e7290Entry { u8 pad[12]; Unk0e7290Bounds bounds; } Unk0e7290Entry;
/* Record stride and field offsets come from 020e736c. */
typedef struct Unk0e7290Record {
    s32 x, y; u32 unk_8, unk_c, unk_10, unk_14;
    Unk0e7290Bounds bounds;
    s16 unk_28, unk_2a;
    u8 pad[0x30];
} Unk0e7290Record;
extern const Unk0e7290Path data_0213c6e0;
extern const char data_02150be0[], data_02150be8[];
extern const s16 data_0213c6d0[][2];
u32 func_02015118(const char *path);
void func_0201524c(char *path, const char *suffix);
int func_020513d4(const char *path);
void func_020516dc(void *request, const char *path, u32 a, u32 b);
void *func_02051610(const char *path);
void *func_020519e8(void *request);
int func_02051844(void *request, s32 index);
Unk0e7290Entry *func_0205f41c(void *resource, u32 index);
void func_0205aa78(Unk0e7290Bounds *bounds, s32 *x, s32 *y, s16 *a, s16 *b);
void func_0205b444(Unk0e7290Record *record, Unk0e7290Entry *entry);
void func_0205b4c4(Unk0e7290Record *record, Unk0e7290Entry *entry);
u32 func_0205accc(Unk0e7290Entry *entry);
u32 func_0205acd4(Unk0e7290Entry *entry);
void func_02057e18(u32 value);
void func_020580ec(u32 value);
int Unk06e4d8_GetFlag6c(void);
u32 Unk06e4d8_Unk_06e854(void);
void func_02057ddc(u32 value);
void func_02057524(u32 value);
void func_02058d04(void *record, u32 mode, s32 x, s32 y, float scale, u32 a, u32 b, u32 c);
void func_02057534(void);
void func_02057df8(void);
Unk0e7290Work *func_020611dc(void (*update)(Unk0e7290Work *),
    void (*draw)(Unk0e7290Work *), u32 a, void (*clear)(void), u32 size, u32 b, u32 c, u32 d);

extern Unk0e7290Work *data_02176cd8;
extern const char data_02150bf0[];
void func_02061424(Unk0e7290Work *work);
void func_02053000(void *value);
Unk0e7290Resource *func_020445d0(u32 resource, u32 index);
s32 func_0204fde0(void);
void func_02013c3c(char *dest, const char *format, ...);
void func_020e7290(Unk0e7290Work *work, u32 value);
void func_020e736c(Unk0e7290Work *work, u32 value);

/* Clear the global pointer; the sole store at 020e764c supports the existing name. */
void Unk0e7290_Clear_data_02176cd8(void)
{
    data_02176cd8 = 0;
}

/* Forward the active work to 02061424 only in states 0 and 5; report acceptance. */
u32 Unk0e7290_Unk_0e7734(void)
{
    Unk0e7290Work *work = data_02176cd8;
    if (work == 0) {
        return 0;
    }
    if (work->unk_0010 == 5 || work->unk_0010 == 0) {
        func_02061424(work);
        return 1;
    }
    return 0;
}

/* Format into caller-owned storage, clamping the signed index to at least one.
 * The resource stride and base query are observed at 020e77bc..020e77e4. */
void Unk0e7290_Unk_0e77a8(char *dest, s32 index)
{
    Unk0e7290Resource *resource = func_020445d0(0x22, 0);
    s32 base = func_0204fde0();
    if (index < 1) {
        index = 1;
    }
    func_02013c3c(dest, data_02150bf0, resource->unk_000c * (index - 1) + base);
}

/* Require all four byte flags before releasing +0x8c and moving +0xc to +8.
 * The caller owns work; the four flags occur at +0xed with stride 0x5c. */
u32 Unk0e7290_Unk_0e747c(Unk0e7290Work *work)
{
    Unk0e7290FlagView *flags;
    int ready;
    int count;
    u8 *cursor;
    count = 0;
    ready = 1;
    cursor = (u8 *)work;
    do {
        flags = (Unk0e7290FlagView *)cursor;
        count++;
        cursor += 0x5c;
        if (flags->unk_00ed == 0) {
            ready = 0;
        }
    } while (count < 4);
    if (ready) {
        func_02053000(work->unk_008c);
        work->unk_008c = 0;
        work->unk_0008 = work->unk_000c;
        work->unk_000c = 0;
        return 1;
    }
    return 0;
}

/* Store the pair at +0 and +4 if active; these stores support the existing Set name. */
void Unk0e7290_Set_0e7770(u32 a, u32 b)
{
    if (data_02176cd8 != 0) {
        data_02176cd8->unk_0000 = a;
        data_02176cd8->unk_0004 = b;
    }
}

/* Store the caller's word at +0x204 only when the global work exists. */
void Unk0e7290_Unk_0e7790(u32 value)
{
    if (data_02176cd8 != 0) {
        data_02176cd8->unk_0204 = value;
    }
}

/* Accept a pending value only in states 0 and 5, clearing +8 and the state word. */
int Unk0e7290_Unk_0e77f0(u32 value)
{
    u32 state;
    if (data_02176cd8 == 0) {
        return 0;
    }
    state = data_02176cd8->unk_0010;
    if (state != 5 && state != 0) {
        return 0;
    }
    data_02176cd8->unk_0008 = 0;
    data_02176cd8->unk_000c = value;
    data_02176cd8->unk_0010 = 0;
    return 1;
}

/* Accept a value in states 0 and 5, run three work helpers, then force state 5.
 * Reload the global between calls because those helpers may change it. */
int func_020e7840(u32 value)
{
    u32 state;
    if (data_02176cd8 == 0) {
        return 0;
    }
    state = data_02176cd8->unk_0010;
    if (state != 5 && state != 0) {
        return 0;
    }
    data_02176cd8->unk_000c = value;
    func_020e7290(data_02176cd8, 0);
    func_020e736c(data_02176cd8, 0);
    Unk0e7290_Unk_0e747c(data_02176cd8);
    data_02176cd8->unk_0010 = 5;
    return 1;
}

/* Advance the pending-resource sequence; states and helper order are evidenced
 * by the switch at 020e74f4. The caller supplies a live work object. */
void func_020e74e0(Unk0e7290Work *work)
{
    if (work->unk_000c == 0) return;
    switch (work->unk_0010) {
    case 0:
    case 1:
        func_020e7290(work, 1);
        work->unk_0010 = 2;
        break;
    case 2:
        if (func_02051844((u8 *)work + 0x14, -1) == 0)
            work->unk_0010 = 3;
        break;
    case 3:
        func_020e736c(work, 1);
        work->unk_0010 = 4;
        break;
    case 4:
        if (Unk0e7290_Unk_0e747c(work)) work->unk_0010 = 5;
        break;
    }
}

/* Draw four records only when +8 is active; the signed coordinate table and
 * render calls at 020e75dc establish the coordinate and scale contracts. */
void func_020e7570(Unk0e7290Work *work)
{
    int i;
    u8 *record;
    if (work->unk_0008 == 0) return;
    func_02057e18(31);
    func_020580ec(0);
    if (Unk06e4d8_GetFlag6c()) func_02057ddc(Unk06e4d8_Unk_06e854());
    else func_02057ddc(work->unk_0204);
    func_02057524(0);
    record = work->records;
    for (i = 0; i < 4; i++, record += 0x5c)
        func_02058d04(record, 0, work->unk_0000 + data_0213c6d0[i][0],
            work->unk_0004 + data_0213c6d0[i][1], 1.0f, 0, 0, 1);
    func_02057534();
    func_02057df8();
    func_020580ec(1);
}

/* Build a resource path in 64 bytes; 020e72d0..020e7320 shows the fallback
 * index of one. The original template and suffixes determine path contents. */
void func_020e7290(Unk0e7290Work *work, u32 value)
{
    Unk0e7290Path path = data_0213c6e0;
    u32 length = func_02015118(path.bytes);
    Unk0e7290_Unk_0e77a8(path.bytes + length, data_02176cd8->unk_000c);
    func_0201524c(path.bytes, data_02150be0);
    if (func_020513d4(path.bytes) == 0) {
        Unk0e7290_Unk_0e77a8(path.bytes + length, 1);
        func_0201524c(path.bytes, data_02150be8);
    }
    if (value) func_020516dc((u8 *)work + 0x14, path.bytes, 0, 0);
    else work->unk_008c = func_02051610(path.bytes);
}

/* Initialize four 0x5c-byte records from resource entries; 020e73a8..020e7448
 * supplies the copied bounds and chained coordinates. Work must be live. */
void func_020e736c(Unk0e7290Work *work, u32 value)
{
    u32 i;
    Unk0e7290Entry *entry;
    Unk0e7290Record *record;
    u8 *cursor;
    s32 x, y;
    if (!work->unk_008c) work->unk_008c = func_020519e8((u8 *)work + 0x14);
    cursor = (u8 *)work;
    record = (Unk0e7290Record *)work->records;
    for (i = 0; i < 4; i++, record++, cursor += 0x5c) {
        entry = func_0205f41c(work->unk_008c, i);
        record->bounds = entry->bounds;
        func_0205aa78(&record->bounds, &x, &y, &record->unk_28, &record->unk_2a);
        if (i == 0) {
            record->x = work->unk_0090[0];
            record->y = work->unk_0090[1];
        }
        if (i < 3) {
            *(s32 *)(cursor + 0xf0) = record->x + x;
            *(s32 *)(cursor + 0xf4) = record->y + y;
        }
        if (value) func_0205b444(record, entry);
        else func_0205b4c4(record, entry);
        record->unk_c = func_0205accc(entry);
        record->unk_10 = func_0205acd4(entry);
    }
}

/* Allocate the 0x208-byte callback work and optionally load its initial value;
 * callback addresses and initialization stores are observed at 020e7658. */
void func_020e7658(s32 *position, u32 value)
{
    data_02176cd8 = func_020611dc(func_020e74e0, func_020e7570, 0,
        Unk0e7290_Clear_data_02176cd8, 0x208, 0, 0, 1);
    data_02176cd8->unk_0090 = position;
    data_02176cd8->unk_0010 = 5;
    data_02176cd8->unk_0008 = 0;
    data_02176cd8->unk_000c = 0;
    data_02176cd8->unk_0204 = -1;
    if (value) {
        data_02176cd8->unk_000c = value;
        func_020e7290(data_02176cd8, 0);
        func_020e736c(data_02176cd8, 0);
        Unk0e7290_Unk_0e747c(data_02176cd8);
        data_02176cd8->unk_0010 = 5;
    }
    Unk0e7290_Set_0e7770(0, 0);
}
