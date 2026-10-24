#include "types.h"

/* Partial views: opaque regions retain the original work-area offsets. */
typedef struct {
    u8 pad_0000[7];
    u8 count;
} Unk03845c_Header;

/* Each 36-byte record supplies three signed IDs; -1 omits that channel. */
typedef struct {
    s8 slots[3];
    u8 pad_0003[33];
} Unk03845c_Record;

/* Borrowed resource pointers and embedded work; one-byte fields mark only
 * the start of opaque storage, whose complete extent is not established. */
typedef struct {
    u8 pad_0000[84];
    void *unk_0054;
    u8 pad_0058[904];
    Unk03845c_Header *header;
    u8 pad_03e4[4];
    Unk03845c_Record *records;
    u8 pad_03ec[44];
    u8 unk_0418[1];
    u8 pad_0419[7231];
    void *unk_2058;
    u8 unk_205c[40];
    u8 unk_2084[1056];
    u8 unk_24a4[1];
} Unk03845c_Work;

/* Resource-relative table metadata; offsets are byte distances. */
typedef struct {
    u8 pad_0000[8];
    u8 unk_0008;
    u8 count;
    u8 pad_000a[4];
    u16 offset;
} Unk03845c_Data;

void func_02029b80(void *);
void func_02029d90(void *);
int func_02007a58(void);
int func_02052624(void);
void func_0202546c(void *);
void func_02007a6c(int);
void func_02007ad4(void);
Unk03845c_Data *func_02025b14(void *);
void func_0202172c(Unk03845c_Work *);
int func_02058a64(void *);
void func_02058944(void *, int, void *, int, int, int, u8);
int func_02038538(Unk03845c_Work *, int, int, int, u8);

/* Bounds-check the relative-offset table before resolving its first entry. */
static inline u32 *Unk03845c_TableEntry(Unk03845c_Data *data, u32 index)
{
    u8 *table = &data->unk_0008;
    if (table != 0 && index < data->count)
        return (u32 *)(table + data->offset + 4 + index * 4);
    return 0;
}

/* A missing resource or table entry has no resolved address. */
static inline u32 *Unk03845c_Resolve(Unk03845c_Data *data)
{
    u32 *entry;
    if (data != 0) {
        entry = Unk03845c_TableEntry(data, 0);
        if (entry != 0)
            return (u32 *)((u8 *)data + *entry);
    }
    return 0;
}

/* Reset embedded work, synchronize using VCOUNT (0x04000006), and resolve
 * the first relative data entry. The entry remains owned by the resource. */
void func_0203845c(Unk03845c_Work *work)
{
    int saved;
    Unk03845c_Data *data;
    u32 *entry;
    func_02029b80(work->unk_205c);
    func_02029d90(work->unk_2084);
    saved = func_02007a58();
    if (func_02052624() < 31) {
        while ((int)*(volatile u16 *)0x04000006 < 191 ||
               (int)*(volatile u16 *)0x04000006 > 213) {
            /* Poll VCOUNT until the permitted transfer interval. */
        }
        func_0202546c(work->unk_2058);
    } else {
        func_0202546c(work->unk_2058);
    }
    func_02007a6c(saved);
    func_02007ad4();
    data = func_02025b14(work->unk_2058);
    entry = Unk03845c_Resolve(data);
    work->unk_0054 = entry;
    func_0202172c(work);
}

/* Allocate an entry from the embedded pool. Return -1 without submitting
 * when exhausted; otherwise return the allocated index. */
int func_02038538(Unk03845c_Work *work, int entry, int value, int channel, u8 enabled)
{
    int index = func_02058a64(work->unk_24a4);
    if (index == -1)
        return -1;
    func_02058944(work->unk_24a4, index, work->unk_0418, entry, value, channel, enabled);
    return index;
}

/* Submit three channel entries for each non-sentinel record, followed by
 * fixed entries. Record count is the unsigned byte at header offset 7. */
void func_020385a4(Unk03845c_Work *work)
{
    u32 i;
    u32 count = work->header->count;
    i = 0;
    if (i < count) {
        u32 offset = 0;
        do {
            Unk03845c_Record *record = (Unk03845c_Record *)((u8 *)work->records + offset);
            if (record->slots[0] != -1)
                func_02038538(work, i, record->slots[0], 0, 1);
            if (record->slots[1] != -1)
                func_02038538(work, i, record->slots[1], 1, 1);
            if (record->slots[2] != -1)
                func_02038538(work, i, record->slots[2], 2, 1);
            i++;
            count = work->header->count;
            offset += sizeof(Unk03845c_Record);
        } while (i < count);
    }
    func_02038538(work, count + 5, 5, 0, 1);
    func_02038538(work, count + 5, 5, 1, 1);
    func_02038538(work, count + 5, 5, 2, 1);
    u32 fixed_count = work->header->count;
    func_02038538(work, fixed_count + 6, 6, 0, 0);
    func_02038538(work, fixed_count + 6, 6, 1, 0);
    func_02038538(work, fixed_count + 6, 6, 2, 0);
    fixed_count = work->header->count;
    func_02038538(work, fixed_count + 7, 7, 0, 0);
    func_02038538(work, fixed_count + 7, 7, 1, 0);
    func_02038538(work, fixed_count + 7, 7, 2, 0);
}

/* Initialize all three channels for entry zero; the final byte enables each. */
void func_0203875c(Unk03845c_Work *work)
{
    func_02038538(work, 0, 0, 0, 1);
    func_02038538(work, 0, 0, 1, 1);
    func_02038538(work, 0, 0, 2, 1);
}

