#include "types.h"

/* Layouts reflect the strides and field offsets in this TU's ARM instructions. */
typedef struct Unk0587fcGlobal {
    u8 unk_00[40];
    u8 unk_28[8];
} Unk0587fcGlobal;

/* Source table stride is 92 bytes; offset 84 holds the helper input pointer. */
typedef struct Unk0587fcSource {
    u8 unk_00[84];
    void *unk_54;
    u32 unk_58;
} Unk0587fcSource;

/* One 24-byte pool entry; byte flags occupy offsets 20 and 21. */
typedef struct Unk0587fcRecord {
    void *unk_00;
    Unk0587fcSource *unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    u8 unk_14;
    u8 unk_15;
    u8 pad_16[2];
} Unk0587fcRecord;

/* Caller-owned storage for exactly 128 entries and three resource pointers. */
typedef struct Unk0587fcWork {
    Unk0587fcRecord records[128];
    void *unk_c00;
    void *unk_c04;
    void *unk_c08;
} Unk0587fcWork;

extern Unk0587fcGlobal data_02168cc8[];
extern void func_02029b80(Unk0587fcGlobal *record);
extern void func_02029d90(void *field);
extern void func_02029bc0(Unk0587fcGlobal *record);
extern void func_02029dac(void *field);
extern void func_02008848(void *dest, int value, u32 size);
extern void *func_02051610(const void *source);
extern void func_020516d0(void *resource);
extern void *func_02025b64(void *resource, s32 index);
extern u32 func_0202162c(void *resource, void *source);
extern void *func_02052fe0(u32 size);
extern void func_0202168c(void *dest, void *resource, void *source, int flags);
extern void func_020218a0(Unk0587fcSource *source, void *object);

/* Calls paired setup helpers on a 48-byte global record and its offset-40 field. */
void func_020587fc(s32 index)
{
    Unk0587fcGlobal *record = &data_02168cc8[index];
    func_02029b80(record);
    func_02029d90(record->unk_28);
}

/* Calls the corresponding teardown helpers; index must name a valid global record. */
void func_02058824(s32 index)
{
    /* See DEC-009: retain the original integer-address calculation here. */
    u32 offset = index * sizeof(Unk0587fcGlobal);
    func_02029bc0((Unk0587fcGlobal *)((u32)data_02168cc8 + offset));
    func_02029dac(((Unk0587fcGlobal *)((u8 *)data_02168cc8 + offset))->unk_28);
}

/* Clears the 128-record pool and its three resource slots (ARM offsets 0xc00..0xc08). */
void func_02058854(Unk0587fcWork *work)
{
    s32 i;
    func_02008848(work, 0, 3072);
    for (i = 0; i < 128; i++) {
        work->records[i].unk_00 = 0;
        work->records[i].unk_14 = 0;
    }
    work->unk_c00 = 0;
    work->unk_c04 = 0;
    work->unk_c08 = 0;
}

/* Loads into the selected slot; selectors outside 0..2 leave the work unchanged. */
void func_0205889c(Unk0587fcWork *work, const void *source, s32 slot)
{
    if (slot == 0) work->unk_c00 = func_02051610(source);
    else if (slot == 1) work->unk_c04 = func_02051610(source);
    else if (slot == 2) work->unk_c08 = func_02051610(source);
}

/* Releases a non-null selected resource; the original leaves the stored pointer intact. */
void func_020588ec(Unk0587fcWork *work, s32 slot)
{
    if (slot == 0) {
        if (work->unk_c00) func_020516d0(work->unk_c00);
    } else if (slot == 1) {
        if (work->unk_c04) func_020516d0(work->unk_c04);
    } else if (slot == 2) {
        if (work->unk_c08) func_020516d0(work->unk_c08);
    }
}

/* Builds a pool entry using a selected resource and a 92-byte source record.
 * Caller supplies valid pool/source indices and a slot in 0..2, as in the ARM code. */
void func_02058944(Unk0587fcWork *work, s32 index, Unk0587fcSource *source, s32 source_index, s32 resource_index, s32 slot, u8 flag)
{
    void *resource;
    if (slot == 0) resource = func_02025b64(work->unk_c00, resource_index);
    else if (slot == 1) resource = func_02025b64(work->unk_c04, resource_index);
    else if (slot == 2) resource = func_02025b64(work->unk_c08, resource_index);
    work->records[index].unk_08 = source_index;
    work->records[index].unk_0c = resource_index;
    work->records[index].unk_04 = source;
    work->records[index].unk_14 = flag;
    work->records[index].unk_15 = 0;
    work->records[index].unk_10 = slot;
    work->records[index].unk_00 = func_02052fe0(func_0202162c(resource, source[source_index].unk_54));
    func_0202168c(work->records[index].unk_00, resource, source[source_index].unk_54, 0);
    func_020218a0(&source[source_index], work->records[index].unk_00);
}
