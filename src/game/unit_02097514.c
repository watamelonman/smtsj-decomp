#include "types.h"

/** Borrowed 60-byte area record; signed limits follow the ARM loads. */
typedef struct Area {
    s16 base[2]; s8 stats[5]; u8 pad9;
    s16 current[2]; s8 values[5]; u8 pad19;
    s16 zero[2]; s8 saved[5]; u8 pad29;
    s16 limit[2]; u8 pad34[2]; u32 word36; u16 ids[6];
    u8 pad52[2]; u16 id; u8 kind; u8 pad57; u8 index; u8 pad59;
} Area;
/** Serialized record view; byte order is established by the three copy paths. */
typedef struct Record {
    u8 kind; u8 a,b,c,d,e; u8 f,g,h,i,j; u8 pad11;
    u16 base[2]; u16 ids[6]; u8 pad28[4]; u32 word;
} Record;
/** Resource view containing the source fields read in mode zero. */
typedef struct Resource {
    u8 pad0[3]; u8 kind; u8 pad4[16]; u16 base[2]; u8 pad24[2];
    u8 stats[5]; u8 pad31[15]; u16 ids[6];
} Resource;
/** Only the level-like byte at offset 91 is known. */
typedef struct Meta { u8 pad[91]; u8 value; } Meta;
/** Shared area index list; negative bytes mark free entries. */
typedef struct Work { u8 pad[840]; s8 indices[12]; } Work;
/** Six halfwords are passed by value to the adjustment helper. */
typedef struct Six { u16 v[6]; } Six;
Area *Unk02e000_GetAreaRecord(int index);
Work *Unk02e000_GetWorkArea(void);
void func_02008848(void *dst, int value, u32 size);
void func_02008904(const void *src, void *dst, u32 size);
void func_02007e94(void);
void Unk02e000_SetRecordFlag1f_1(u16 id, int value);
int Unk02e000_GetRecordUnk1e(u16 id);
void Unk02e000_SetRecordUnk1e(u16 id, int value);
Meta *func_020a1740(u16 id);
Resource *func_020a1428(u16 id);
int Unk02e000_SetRecord(u32 id, Record *out);
int Unk02e000_SetSlot40(int slot, Record *out);
void func_020b8804(Six *out, u16 id);
void func_020b89c4(u8 kind, s16 *values, Six data);
void func_0209835c(s16 *values, u16 *ids);
void func_0209786c(Area *area);

/** Initializes a borrowed area record from resource, record, or slot data (mode 0..2).
 * The three source layouts and field copies are evidenced by the original ARM loads. */
void func_02097514(int index, int id, int slot, int mode)
{
    Record record, stored;
    Area *area = Unk02e000_GetAreaRecord(index);
    /* Keep this shared byte read after the record query, matching ARM call order. */
    volatile Meta *meta;
    s8 *indices;
    int i;
    if (!area) return;
    func_02008848(area, 0, 60);
    area->id = id;
    area->index = index;
    indices = Unk02e000_GetWorkArea()->indices;
    for (i = 0; i < 12; i++) {
        if (indices[i] < 0) { indices[i] = index; break; }
    }
    Unk02e000_SetRecordFlag1f_1((u16)id, 1);
    meta = func_020a1740((u16)id);
    {
        int value = Unk02e000_GetRecordUnk1e((u16)id);
        int next = meta->value;
        if (value < next) Unk02e000_SetRecordUnk1e((u16)id, next);
    }
    switch (mode) {
    case 0: {
        Resource *src = func_020a1428((u16)id);
        area->kind = src->kind;
        area->base[0] = src->base[0]; area->base[1] = src->base[1];
        area->stats[0] = src->stats[0]; area->stats[1] = src->stats[1];
        area->stats[2] = src->stats[2]; area->stats[3] = src->stats[3]; area->stats[4] = src->stats[4];
        area->zero[0] = 0; area->zero[1] = 0;
        area->saved[0] = src->stats[0]; area->saved[1] = src->stats[1];
        area->saved[2] = src->stats[2]; area->saved[3] = src->stats[3]; area->saved[4] = src->stats[4];
        for (i = 0; i < 6; i++) area->ids[i] = src->ids[i];
        break;
    }
    case 1:
        Unk02e000_SetRecord((u16)id, &record);
        area->kind = record.kind;
        area->base[0] = record.base[0]; area->base[1] = record.base[1];
        area->stats[0] = record.a; area->stats[1] = record.c; area->stats[2] = record.d; area->stats[3] = record.e; area->stats[4] = record.b;
        area->zero[0] = 0; area->zero[1] = 0;
        area->saved[0] = record.f; area->saved[1] = record.h; area->saved[2] = record.i; area->saved[3] = record.j; area->saved[4] = record.g;
        for (i = 0; i < 6; i++) area->ids[i] = record.ids[i];
        area->word36 = record.word;
        break;
    case 2:
        Unk02e000_SetSlot40(slot, &stored);
        area->kind = stored.kind;
        area->base[0] = stored.base[0]; area->base[1] = stored.base[1];
        area->stats[0] = stored.a; area->stats[1] = stored.c; area->stats[2] = stored.d; area->stats[3] = stored.e; area->stats[4] = stored.b;
        area->zero[0] = 0; area->zero[1] = 0;
        area->saved[0] = stored.f; area->saved[1] = stored.h; area->saved[2] = stored.i; area->saved[3] = stored.j; area->saved[4] = stored.g;
        for (i = 0; i < 6; i++) area->ids[i] = stored.ids[i];
        area->word36 = stored.word;
        break;
    }
    func_0209786c(area);
    area->limit[0] = area->current[0]; area->limit[1] = area->current[1];
}

/** Forwards an index and ID with no slot; mode 2 invokes the original assertion helper. */
void Unk097514_Unk_0977f0(int index, int id, int mode)
{
    if (mode == 2) func_02007e94();
    func_02097514(index, id, -1, mode);
}

/** Recomputes the derived record, clamps five signed bytes to 1..99, and caps two limits.
 * Field widths and clamping bounds come directly from the original ARM instructions. */
void func_0209786c(Area *area)
{
    Six copy, data;
    if (!area) return;
    func_02008904(area, area->current, 10);
    if (area->values[0] <= 0) area->values[0] = 1;
    if (area->values[1] <= 0) area->values[1] = 1;
    if (area->values[2] <= 0) area->values[2] = 1;
    if (area->values[3] <= 0) area->values[3] = 1;
    if (area->values[4] <= 0) area->values[4] = 1;
    if (area->values[0] > 99) area->values[0] = 99;
    if (area->values[1] > 99) area->values[1] = 99;
    if (area->values[2] > 99) area->values[2] = 99;
    if (area->values[3] > 99) area->values[3] = 99;
    if (area->values[4] > 99) area->values[4] = 99;
    func_020b8804(&data, area->id);
    copy.v[0] = data.v[0]; copy.v[1] = data.v[1]; copy.v[2] = data.v[2];
    copy.v[3] = data.v[3]; copy.v[4] = data.v[4]; copy.v[5] = data.v[5];
    func_020b89c4(area->kind, area->current, copy);
    func_0209835c(area->current, area->ids);
    if (area->limit[0] > area->current[0]) area->limit[0] = area->current[0];
    if (area->limit[1] > area->current[1]) area->limit[1] = area->current[1];
}
