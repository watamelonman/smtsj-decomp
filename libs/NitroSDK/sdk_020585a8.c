#include "libs/NitroSDK/sdk_020585a8.h"
#include "libs/NitroSDK/sdk_020222d8.h"

/** Basis vectors and the 48-byte matrix produced from them. */
typedef struct Unk0585a8Basis {
    Unk0585a8Vector first;
    Unk0585a8Vector second;
    Unk0585a8Vector third;
    s32 matrix[12];
} Unk0585a8Basis;

/** Projection parameters saved by func_020586d0 (five words). */
typedef struct Unk0585a8Params {
    s32 p0;
    s32 p1;
    s32 p2;
    s32 p3;
    s32 p4;
} Unk0585a8Params;
extern Unk0585a8Params data_02168c24;
/** Camera basis and matrix workspace. */
extern Unk0585a8Basis data_02168c38;
/** Cached basis vectors consumed by the shared graphics state. */
extern Unk0585a8Vector data_02156f68;
extern Unk0585a8Vector data_02156f74;
extern Unk0585a8Vector data_02156f80;
/** Shared 48-byte matrix scratch and state block (flags at +0xfc). */
extern u8 data_02156d74[];
extern Unk0222d8State data_02156d28;
extern u32 data_02156d30;

extern void func_02029b80(void *state);
extern void func_02029d90(void *state);
extern u32 func_02007a58(void);
extern s32 func_02052624(void);
extern void func_0202546c(void *source);
extern void func_02007a6c(u32 state);
extern void func_02007ad4(void);
extern Unk0585a8Resource *func_02025b14(void *source);
extern void func_0202172c(Unk0585a8Record *record, void *resource);
extern void func_02007e94(void);
extern void func_02008904(const void *source, void *destination, u32 size);
extern void func_0200167c(Unk0585a8Vector *first, Unk0585a8Vector *second,
                          Unk0585a8Vector *third, s32 *matrix);
extern void func_02001e48(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5,
                          u32 *p6);

/** Resolve one dictionary entry by index. Entry offsets are relative to the
 *  resource base; index is unsigned byte-sized as in the original comparison. */
static inline void *FindIndex(Unk0585a8Resource *resource, u8 index)
{
    if (resource != 0) {
        Unk0585a8Dict *dictionary = &resource->dictionary;
        u32 *entry;
        if (dictionary != 0 && index < resource->dictionary.count) {
            Unk0585a8EntryTable *table =
                (Unk0585a8EntryTable *)((u8 *)dictionary + resource->dictionary.entryOffset);
            entry = (u32 *)(table->entries + table->stride * index);
        } else {
            entry = 0;
        }
        if (entry != 0) {
            return (u8 *)resource + *entry;
        }
    }
    return 0;
}

/** Sets up the two work state blocks, releases the previous resource, and binds
 *  each dictionary entry into the matching 92-byte record. The record stride and
 *  the 90-record bound are explicit (record 90 raises the SDK check). */
void func_020585a8(Unk0585a8Work *work)
{
    Unk0585a8Resource *resource;
    u32 saved;
    s32 i;

    func_02029b80(work->state_205c);
    func_02029d90(work->state_2084);
    saved = func_02007a58();
    if (func_02052624() < 31) {
        while ((s32)*(volatile u16 *)0x04000006 < 191 ||
               (s32)*(volatile u16 *)0x04000006 > 213) {
        }
        func_0202546c(work->source);
    } else {
        func_0202546c(work->source);
    }
    func_02007a6c(saved);
    func_02007ad4();
    resource = func_02025b14(work->source);
    for (i = 0; i < resource->dictionary.count; i++) {
        if (i == 90) func_02007e94();
        work->records[i].resource = FindIndex(resource, i);
        func_0202172c(&work->records[i], work->records[i].resource);
    }
}

/** Saves the five projection parameters and hands them, with the fixed 0x1000
 *  scale and the shared state pointer, to the projection builder; then
 *  invalidates the cached projection flags. */
void func_020586d0(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4)
{
    data_02168c24.p0 = p0;
    data_02168c24.p1 = p1;
    data_02168c24.p2 = p2;
    data_02168c24.p3 = p3;
    data_02168c24.p4 = p4;
    func_02001e48(data_02168c24.p0, data_02168c24.p1, data_02168c24.p2,
                  data_02168c24.p3, p4, 0x1000, &data_02156d30);
    data_02156d28.flags &= ~0x50;
}

/** Copies the two caller axes into the basis workspace, fills the middle axis
 *  with the fixed (0, 0x1000, 0) vector, caches the axes, builds the 48-byte
 *  matrix, invalidates the cached matrix flags, and stores the result. */
void func_02058724(Unk0585a8Vector *xAxis, Unk0585a8Vector *zAxis)
{
    /* 0x0212e398 is the unrelocated constant {0, 0x1000, 0} (the Y axis). */
    Unk0585a8Vector middle = *(const Unk0585a8Vector *)0x0212e398;
    u8 *base = (u8 *)&data_02168c38;

    func_02008904(xAxis, base, 12);
    func_02008904(zAxis, base + 12, 12);
    func_02008904(&middle, base + 24, 12);
    {
        /* Three adjacent cached axes; the walk preserves the store order.
         * See DEC-033. */
        Unk0585a8Vector *destination = &data_02156f68;
        *destination = *(Unk0585a8Vector *)base;
        destination += 1;
        *destination = *(Unk0585a8Vector *)(base + 24);
        destination += 1;
        *destination = *(Unk0585a8Vector *)(base + 12);
    }
    func_0200167c((Unk0585a8Vector *)base, (Unk0585a8Vector *)(base + 24),
                  (Unk0585a8Vector *)(base + 12), (s32 *)data_02156d74);
    data_02156d28.flags &= ~0xe8;
    func_02008904(data_02156d74, base + 36, 48);
}
