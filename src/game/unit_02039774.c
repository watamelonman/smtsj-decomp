/* FLW0 work objects and their intrusive list; layouts follow ARM field accesses. */
#include "types.h"

/* Borrowed FLW0 header; signed counts at +0x14/+0x16 size owned arrays. */
typedef struct Unk039774Header {
    u8 reserved[8];
    s8 magic[4];
    u32 unknown_0c;
    s32 section_count;
    s16 count_14;
    s16 count_16;
    u8 unknown_18[8];
} Unk039774Header;

/* Section offsets are relative to the start of the borrowed header. */
typedef struct Unk039774Section {
    u32 kind;
    u32 unknown_04;
    s32 count;
    u32 offset;
} Unk039774Section;

/* A 32-byte source record; its zero-terminated name must fit in 24 bytes. */
typedef struct Unk039774Record {
    u8 name[24];
    u32 value;
    u32 unknown_1c;
} Unk039774Record;

/* The section view used by the constructor only reads the count at +8. */
typedef struct Unk039774Info {
    u32 unknown[2];
    s32 count;
} Unk039774Info;

/* Owns the three allocations at +0xd4..+0xdc; source sections are borrowed. */
typedef struct Unk039774Work {
    s8 name[24];
    u32 value;
    u32 unknown_1c;
    u8 flags[28];
    u32 slots[28];
    Unk039774Header *header;
    Unk039774Info *info;
    Unk039774Record *records;
    void *section1;
    void *section2;
    void *section4;
    s32 index;
    s32 unknown_c8;
    u32 unknown_cc;
    u32 unknown_d0;
    void *owned_d4;
    u32 *owned_d8;
    u32 *owned_dc;
    struct Unk039774Work *prev;
    struct Unk039774Work *next;
    u32 unknown_e8;
    u32 unknown_ec;
    u32 unknown_f0;
    u32 key;
} Unk039774Work;

/* List links and count are updated together; nodes must belong to this list. */
typedef struct Unk039774List {
    Unk039774Work *head;
    s32 count;
    Unk039774Work *tail;
} Unk039774List;
extern Unk039774List data_0215de28;
void *func_02052fe0(u32 size);
void func_02053000(void *allocation);
void func_02008848(void *destination, int value, u32 size);

/* Appends a node. Evidence for the name: tail/prev/next stores at +0xe0/+0xe4. */
void Unk039774_ListAppend(Unk039774Work *n)
{
    if (data_0215de28.tail == 0) {
        data_0215de28.head = n;
        data_0215de28.tail = n;
        n->prev = 0;
        n->next = 0;
    } else {
        n->prev = data_0215de28.tail;
        data_0215de28.tail->next = n;
        n->next = 0;
        data_0215de28.tail = n;
    }
    data_0215de28.count++;
}

/* Removes a member and clears its links; evidence: head/tail and neighbor stores. */
void Unk039774_ListRemove(Unk039774Work *n)
{
    if (data_0215de28.head == n) {
        data_0215de28.head = n->next;
    } else {
        n->prev->next = n->next;
    }
    if (data_0215de28.tail == n) {
        data_0215de28.tail = n->prev;
    } else {
        n->next->prev = n->prev;
    }
    n->prev = 0;
    n->next = 0;
    data_0215de28.count--;
}

/* Builds a 248-byte node from borrowed sections; index must be in info's range.
 * Evidence: allocation size, 32-byte record stride and signed header counts. */
Unk039774Work *func_02039828(Unk039774Header *header, Unk039774Info *info,
    Unk039774Record *records, void *section1, void *section2,
    void *section3, void *section4, s32 index)
{
    Unk039774Work *work;
    int i;
    if (header == 0 || info == 0 || records == 0 || section2 == 0) return 0;
    if (index < 0 || index >= info->count) return 0;
    work = func_02052fe0(sizeof(Unk039774Work));
    func_02008848(work, 0, sizeof(Unk039774Work));
    if (work == 0) return 0;
    i = 0;
    work->name[0] = records[index].name[0];
    while (work->name[i] != 0) {
        i++;
        work->name[i] = records[index].name[i];
    }
    work->value = records[index].value;
    work->unknown_1c = 0;
    for (i = 0; i < 28; i++) {
        work->flags[i] = 0;
        work->slots[i] = 0;
    }
    work->header = header;
    work->info = info;
    work->records = records;
    work->section1 = section1;
    work->section2 = section2;
    work->section4 = section4;
    work->index = index;
    work->unknown_c8 = -1;
    work->unknown_cc = 0;
    work->unknown_d0 = 0;
    work->owned_d8 = 0;
    work->owned_dc = 0;
    work->prev = 0;
    work->next = 0;
    work->unknown_e8 = 0;
    if (header->count_14 > 0) {
        work->owned_d8 = func_02052fe0(header->count_14 * 4);
        for (i = 0; i < header->count_14; i++) work->owned_d8[i] = 0;
    } else {
        work->owned_d8 = 0;
    }
    if (header->count_16 > 0) {
        work->owned_dc = func_02052fe0(header->count_16 * 4);
        for (i = 0; i < header->count_16; i++) work->owned_dc[i] = 0;
    } else {
        work->owned_dc = 0;
    }
    Unk039774_ListAppend(work);
    return work;
}

/* Validates the literal FLW0 signature and resolves section offsets, rejecting
 * unknown section kinds. Evidence: four signed-byte comparisons and kind switch. */
Unk039774Work *func_020399f4(Unk039774Header *header, s32 index)
{
    Unk039774Record *records = 0;
    void *section1 = 0;
    Unk039774Section *sections = (Unk039774Section *)(header + 1);
    void *section2 = 0;
    void *section3 = 0;
    void *section4 = 0;
    int i;
    int count;
    if (header->magic[0] != 'F' || header->magic[1] != 'L' ||
        header->magic[2] != 'W' || header->magic[3] != '0') return 0;
    count = header->section_count;
    for (i = 0; i < count; i++) {
        switch (sections[i].kind) {
        case 0: records = (Unk039774Record *)((u8 *)header + sections[i].offset); break;
        case 1: section1 = (u8 *)header + sections[i].offset; break;
        case 2: section2 = (u8 *)header + sections[i].offset; break;
        case 3:
            if (sections[i].count != 0) section3 = (u8 *)header + sections[i].offset;
            break;
        case 4: section4 = (u8 *)header + sections[i].offset; break;
        default: return 0;
        }
    }
    return func_02039828(header, (Unk039774Info *)sections, records, section1,
        section2, section3, section4, index);
}

/* Forwards the borrowed header with record index zero, as shown by the thunk. */
Unk039774Work *Unk039774_Unk_039b00(Unk039774Header *header)
{
    return func_020399f4(header, 0);
}

/* Releases each owned buffer, unlinks the node, then releases the node itself.
 * Evidence: null guards at +0xd8/+0xdc/+0xd4 and calls to the release helper. */
void Unk039774_Unk_039b10(Unk039774Work *work)
{
    if (work->owned_d8 != 0) {
        func_02053000(work->owned_d8);
        work->owned_d8 = 0;
    }
    if (work->owned_dc != 0) {
        func_02053000(work->owned_dc);
        work->owned_dc = 0;
    }
    if (work->owned_d4 != 0) {
        func_02053000(work->owned_d4);
        work->owned_d4 = 0;
    }
    Unk039774_ListRemove(work);
    func_02053000(work);
}

/* Releases members whose +0xf4 key matches; saves next before freeing each node. */
void Unk039774_Unk_039b74(u32 key)
{
    Unk039774Work *o = data_0215de28.head;
    Unk039774Work *next;
    if (o == 0) return;
    do {
        next = o->next;
        if (o->key == key) Unk039774_Unk_039b10(o);
        o = next;
    } while (o != 0);
}
