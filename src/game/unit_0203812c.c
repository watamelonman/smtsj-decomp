#include "types.h"

typedef struct Record {
    u8 unk_00[84];
    void *resource;
    u32 unk_58;
} Record;

typedef struct Work {
    Record records[90]; /* Fixed prefix ends at the source pointer, offset 0x2058. */
    void *source;
    u8 unk_205c[40];
    u8 unk_2084[1];
} Work;

typedef struct Header {
    u8 unk_00[7];
    u8 count;
} Header;

typedef struct InputRecord {
    u8 unk_00[32];
    s8 nameIndex;
    u8 unk_21[3];
} InputRecord;

typedef struct Input {
    Header *header;
    s8 (*names)[16];
    InputRecord *records;
} Input;

typedef struct Dictionary {
    u8 unk_00;
    u8 count;
    u8 unk_02[4];
    u16 entryOffset;
} Dictionary;

typedef struct Resource {
    u8 unk_00[8];
    Dictionary dictionary;
} Resource;

typedef struct EntryTable {
    u16 stride;
    u16 unk_02;
    u8 entries[1];
} EntryTable;

extern void func_02029b80(void *state);
extern void func_02029d90(void *state);
extern u32 func_02007a58(void);
extern s32 func_02052624(void);
extern void func_0202546c(void *source);
extern void func_02007a6c(u32 state);
extern void func_02007ad4(void);
extern Resource *func_02025b14(void *source);
extern u32 *func_020257ec(Dictionary *dictionary, const s8 *name);
extern void func_0202172c(Record *record, void *resource);

/* Dictionary entries contain offsets relative to their owning resource. */
static inline void *FindName(Resource *resource, const s8 *name)
{
    if (resource != 0) {
        u32 *entry = func_020257ec(&resource->dictionary, name);
        if (entry != 0) {
            return (u8 *)resource + *entry;
        }
    }
    return 0;
}

/* Bounds are stored in the embedded dictionary; each entry begins with an offset. */
static inline void *FindIndex(Resource *resource, u32 index)
{
    if (resource != 0) {
        Dictionary *dictionary = &resource->dictionary;
        u32 *entry;
        if (dictionary != 0 && index < resource->dictionary.count) {
            EntryTable *table = (EntryTable *)((u8 *)dictionary + resource->dictionary.entryOffset);
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

/* Bind named records and eight trailing dictionary entries. Evidence: 16-byte
 * name copies, dictionary offsets, and 92-byte destination stride in the original.
 * The caller must provide valid names and dictionary data and a count <= 82. */
void func_0203812c(Work *work, Input *input)
{
    Resource *resource;
    s32 i;
    u32 saved;
    func_02029b80(work->unk_205c);
    func_02029d90(work->unk_2084);
    saved = func_02007a58();
    if (func_02052624() < 31) {
        while ((s32)*(volatile u16 *)0x04000006 < 191 || (s32)*(volatile u16 *)0x04000006 > 213) {
        }
        func_0202546c(work->source);
    } else {
        func_0202546c(work->source);
    }
    func_02007a6c(saved);
    func_02007ad4();
    resource = func_02025b14(work->source);
    for (i = 1; i < input->header->count; i++) {
        s32 nameIndex = input->records[i].nameIndex;
        /* Word alignment preserves the original four-word clear. See DEC-008. */
        union { u32 words[4]; s8 bytes[16]; } name = {{0}};
        s32 j;
        void *bound;
        for (j = 0; j < 16; j++) {
            name.bytes[j] = input->names[nameIndex][j];
        }
        bound = FindName(resource, name.bytes);
        work->records[i].resource = bound;
        func_0202172c(&work->records[i], bound);
    }
    {
        u32 index;
        for (index = 0; index < 5; index++) {
            u32 destination = input->header->count + index;
            void *bound = FindIndex(resource, index);
            work->records[destination].resource = bound;
            func_0202172c(&work->records[destination], bound);
        }
    }
    {
        s32 destination = input->header->count + 5;
        work->records[destination].resource = FindIndex(resource, 5);
        func_0202172c(&work->records[destination], work->records[destination].resource);
    }
    {
        s32 destination = input->header->count + 6;
        work->records[destination].resource = FindIndex(resource, 6);
        func_0202172c(&work->records[destination], work->records[destination].resource);
    }
    {
        s32 destination = input->header->count + 7;
        work->records[destination].resource = FindIndex(resource, 7);
        func_0202172c(&work->records[destination], work->records[destination].resource);
    }
}
