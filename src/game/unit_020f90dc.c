#include "types.h"

/* Layouts describe only accesses observed in this unit. */
typedef struct Entry { u8 id; u8 order; } Entry;
typedef struct Area { u8 pad[30]; s16 unk_001e; s16 unk_0020; } Area;
typedef struct Record { u8 pad[34]; u8 unk_0022; } Record;
typedef struct Slot { u32 unk_0000; void *unk_0004; u32 unk_0008; } Slot;
typedef struct Unk0f90dcWork {
    u8 pad_0000[8]; u32 capacity;
    u8 pad_000c[20]; int slot;
    u8 pad_0024[44]; Slot *unk_0050;
    u8 pad_0054[20]; int selection;
    u8 pad_006c[128]; Entry **entries;
    u8 pad_00f0[4]; void *unk_00f4; u16 *ids; int count;
    void *unk_0100; void *unk_0104; void *unk_0108; void *unk_010c;
    void *unk_0110[5]; void *unk_0124[10];
    u8 pad_014c[4]; void *unk_0150;
} Unk0f90dcWork;

Record *func_020cb1a0(u32 id);
Area *Unk02e000_Thunk_0202e788(void);
Area *Unk02e000_GetAreaRecord(int area);
void Unk02e000_Unk_02e0cc(void);
void func_0205ad2c(u32 value);
void Unk05b82c_CreateEntry(const void *entry);
void *func_0205dcd4(const void *data, int mode);
void *func_0205c2c4(const void *data);
void *func_0205c3c0(void);
void func_0205c3fc(void *handle, void *a, void *b);
void func_0205c3dc(void *handle);
void func_0205ddb4(void *handle);
void func_0205c368(void *handle);
void func_0205bb68(void);
void func_020629c4(void *handle);
void Unk0fbc74_Unk_0fbcd4(void *handle, u32 id);
void Unk02f2a8_SetField6138(void *handle, u32 id);
void Unk0d297c_Unk_0d2e88(void);
void func_02053000(void *allocation);
extern u32 data_02150ed0;
extern u8 data_02150f38[];
extern u8 data_02150fc8[];
extern u8 data_02150fd4[];

/* Compare the signed area field with record byte 34; negative areas use the current area. */
int Unk0f90dc_Unk_0f90dc(int area, u32 id)
{
    Record *record;
    int value;
    int result = 0;
    record = func_020cb1a0(id);
    if (area < 0) value = Unk02e000_Thunk_0202e788()->unk_001e;
    else value = Unk02e000_GetAreaRecord(area)->unk_0020;
    if (value >= record->unk_0022) result = 1;
    return result;
}

/* Compare indirect entries by their unsigned byte at offset one. */
int Unk0f90dc_Unk_0f9128(const Entry *const *a, const Entry *const *b)
{
    return (u32)(*a)->order - (u32)(*b)->order;
}

/* Initialize the two handle groups using the shared six 24-byte descriptors. */
void func_020f9140(Unk0f90dcWork *work)
{
    int i;
    u8 *entry;
    Unk02e000_Unk_02e0cc();
    func_0205ad2c(data_02150ed0);
    entry = data_02150f38;
    for (i = 0; (u32)i < 6; i++, entry += 24) Unk05b82c_CreateEntry(entry);
    work->unk_0108 = func_0205dcd4(data_02150fc8, 1);
    work->unk_010c = func_0205c2c4(data_02150fd4);
    for (i = 0; i < 5; i++) {
        work->unk_0110[i] = func_0205c3c0();
        func_0205c3fc(work->unk_0110[i], work->unk_0108, work->unk_010c);
    }
    for (i = 0; i < 10; i++) {
        work->unk_0124[i] = func_0205c3c0();
        func_0205c3fc(work->unk_0124[i], work->unk_0108, work->unk_010c);
    }
    Unk02e000_Unk_02e0cc();
}

/* Release non-null group handles and clear their ownership fields. */
void func_020f91fc(Unk0f90dcWork *work)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (work->unk_0110[i]) { func_0205c3dc(work->unk_0110[i]); work->unk_0110[i] = 0; }
    }
    for (i = 0; i < 10; i++) {
        if (work->unk_0124[i]) { func_0205c3dc(work->unk_0124[i]); work->unk_0124[i] = 0; }
    }
    if (work->unk_0108) { func_0205ddb4(work->unk_0108); work->unk_0108 = 0; }
    if (work->unk_010c) { func_0205c368(work->unk_010c); work->unk_010c = 0; }
    for (i = 0; (u32)i < 6; i++) func_0205bb68();
    func_020629c4(work->unk_0100);
    func_020629c4(work->unk_0104);
}

/* Append an absent ID only while the caller-provided capacity permits it. */
void func_020f92bc(Unk0f90dcWork *work, u32 id)
{
    int i;
    if ((u32)work->count >= work->capacity) return;
    for (i = 0; i < work->count; i++) if (id == work->ids[i]) return;
    work->ids[work->count] = id;
    work->count++;
}

/* Propagate the selected entry's ID to both consumers and the unique-ID list. */
void func_020f9318(Unk0f90dcWork *work)
{
    int selection = work->selection;
    Unk0fbc74_Unk_0fbcd4(work->unk_0150, work->entries[selection]->id);
    func_020f92bc(work, work->entries[selection]->id);
    Unk02f2a8_SetField6138(work->unk_0050[work->slot].unk_0004, work->entries[selection]->id);
}

/* The original callback returns without side effects. */
void Unk0f90dc_Nop_0f9ce4(void) { }

/* Release the groups before freeing the four owned allocations. */
void Unk0f90dc_Unk_0fa4cc(Unk0f90dcWork *work)
{
    func_020f91fc(work);
    Unk0d297c_Unk_0d2e88();
    func_02053000(work->unk_0050); work->unk_0050 = 0;
    func_02053000(work->ids); work->ids = 0;
    func_02053000(work->entries); work->entries = 0;
    func_02053000(work->unk_00f4); work->unk_00f4 = 0;
}
