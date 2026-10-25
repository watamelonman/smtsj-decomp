#include "types.h"

/* Borrowed layout views; padding denotes fields unused by these routines. */
typedef struct Unk1218d0Object {
    u32 unk_000;
    u8 pad_004[36];
    u8 *unk_028;
    u32 unk_02c;
    u8 pad_030[8];
    u32 unk_038;
    u8 pad_03c[308];
    u32 unk_170;
    u8 pad_174[24];
    u16 unk_18c[6];
    u8 unk_198[32];
    u16 unk_1b8[6];
    u8 pad_1c4[20];
    u16 unk_1d8;
    u16 unk_1da;
    u8 pad_1dc;
    u8 unk_1dd;
    u8 pad_1de[164];
    u8 unk_282;
    u8 pad_283[17];
    u8 unk_294[76];
} Unk1218d0Object;

/* Manager prefix owns three borrowed slot pointers and an embedded object. */
typedef struct Unk1218d0Manager {
    u8 pad_000[60];
    u16 unk_03c;
    u8 pad_03e[42];
    Unk1218d0Object *unk_068[3];
    u8 pad_074[24];
    Unk1218d0Object unk_08c;
    Unk1218d0Object unk_36c[1]; /* Array bound is unknown; indexed by area ID. */
} Unk1218d0Manager;

/* Persistent work view; saved IDs are halfwords and empty area indices are -1. */
typedef struct Unk1218d0Work {
    u16 ids[4];
    u8 pad_008[10];
    s16 unk_012, unk_014;
    s8 unk_016, unk_017, unk_018, unk_019, unk_01a;
    u8 pad_01b;
    u16 unk_01c;
    u16 unk_01e;
    u8 pad_020[40];
    u8 unk_048;
    u8 pad_049[35];
    u16 unk_06c;
    u8 unk_06e;
    u8 pad_06f[741];
    s8 unk_354[3];
} Unk1218d0Work;

/* Borrowed saved-area view; signed loads distinguish stats from stored IDs. */
typedef struct Unk1218d0Record {
    u8 pad_00[10];
    s16 unk_0a, unk_0c;
    s8 unk_0e, unk_0f, unk_10, unk_11, unk_12;
    u8 pad_13[11];
    u16 unk_1e;
    u16 unk_20;
    u8 pad_22[18];
    u16 unk_34;
    u16 unk_36;
    u8 unk_38;
} Unk1218d0Record;

/* Lookup result packs category, counter index and flags into two halfwords. */
typedef struct Unk1218d0Entry {
    u8 pad_00[38];
    union {
        u16 raw;
        struct { u16 low : 2; u16 unused : 3; u16 valid : 1; u16 category : 5; u16 index : 5; } bits;
    } unk_26;
    u16 unk_28 : 4;
    u16 unused_28 : 12;
} Unk1218d0Entry;

/* Lookup byte bits zero/one independently permit saving/initializing an ID. */
typedef struct Unk1218d0Flags {
    u8 pad_00[3];
    u8 unk_03 : 1;
    u8 unk_03_bit1 : 1;
    u8 unused_03 : 6;
} Unk1218d0Flags;

Unk1218d0Entry *func_020cb21c(u32 id);
Unk1218d0Manager *Unk044904_Get_data_0215ee98(void);
Unk1218d0Object *Unk044904_FindInactiveSlot(void);
Unk1218d0Work *Unk02e000_Thunk_0202e788(void);
Unk1218d0Work *Unk02e000_GetWorkArea(void);
Unk1218d0Record *Unk02e000_GetAreaRecord(int index);
Unk1218d0Flags *func_020982c0(s8 id);
void func_0204ae84(void *work);
void func_0204a884(Unk1218d0Object *object);
int Unk02ee5c_GetTierFromField70(void);
void func_021219d0(u32 *field, Unk1218d0Work *work);
void func_02096c8c(void);
void func_0209786c(Unk1218d0Record *record);
int func_02122494(Unk1218d0Object *object, u32 id, u32 value, int mode);
/* Borrowed definition prefix exposes byte +5 and state fields +0x0a–0x12. */
typedef struct {
    u16 id; u8 pad_02[3]; u8 unk_05; u8 pad_06[4];
    u16 unk_0a; u8 unk_0c, unk_0d, unk_0e, unk_0f, unk_10, pad_11;
    u16 unk_12;
} Unk1218d0Definition;
/* Source table fields are read at the widths present in the original loads. */
typedef struct {
    u16 id; u8 unk_02, pad_03; u32 unk_04, unk_08;
    u16 unk_0c, unk_0e, unk_10, unk_12, unk_14;
    u16 unk_16; u8 unk_18, unk_19, unk_1a, unk_1b, unk_1c, pad_1d;
    u16 unk_1e;
} Unk1218d0Source;
/* Nineteen used entries occupy a 40-byte lookup output buffer. */
typedef struct { u16 low : 10; u16 high : 6; } Unk1218d0Packed;
/* Twelve-byte statistic entries preserve signed saved values. */
typedef struct { s32 current, limit, extra; } Unk1218d0Stat;
/* State copies are exactly 24 bytes, including their observed padding. */
typedef struct {
    u32 unk_00; s16 unk_04; u8 unk_06, unk_07; u32 unk_08;
    u8 unk_0c, pad_0d; u16 unk_0e; u32 unk_10; u16 unk_14, unk_16;
} Unk1218d0State;
/* The pair and trailing halfwords are cleared together as 52 bytes. */
typedef struct { Unk1218d0State first, second; s16 value; u16 pad; } Unk1218d0States;
/* Borrowed view begins at object +0x2c; it is not an allocation size. */
typedef struct {
    Unk1218d0Stat stats[27]; u8 pad_144[20];
    Unk1218d0States states; u16 ids[6];
} Unk1218d0Fields;
Unk1218d0Source *func_020a1740(u32 id);
Unk1218d0Definition *func_020a1428(u32 id);
u8 *Unk0a163c_Unk_0a1814(u32 id);
int Unk0a163c_Unk_0a17d8(u32 id);
void func_02122258(u32 *fields, Unk1218d0Definition *definition, Unk1218d0Source *source);

/* Accumulate category counters from six IDs; evidence: packed fields at +38/+40. */
void func_021218d0(Unk1218d0Object *object)
{
    int i;
    for (i = 0; i < 6; i++) {
        Unk1218d0Entry *entry;
        if (object->unk_18c[i] == 0) continue;
        entry = func_020cb21c(object->unk_18c[i]);
        if (entry == 0) continue;
        if (entry->unk_26.bits.category == 5) {
            switch (entry->unk_28) {
            case 0: break;
            case 5:
                object->unk_198[entry->unk_26.bits.index]++;
                break;
            case 6:
                object->unk_198[entry->unk_26.bits.index] += 2;
                break;
            }
        }
    }
}

/* Latch bit zero when any of six referenced entries has nonzero low flag bits. */
void func_02121970(Unk1218d0Object *object)
{
    u16 *ids = object->unk_1b8;
    int i;
    for (i = 0; i < 6; i++) {
        Unk1218d0Entry *entry;
        if (ids[i] == 0) continue;
        entry = func_020cb21c(ids[i]);
        if (entry == 0) continue;
        if (entry->unk_26.bits.low != 0) {
            object->unk_282 = (object->unk_282 & ~1) | 1;
            return;
        }
    }
}

/* Initialize the manager's embedded object from the persistent work area. */
int func_02121d2c(void)
{
    Unk1218d0Manager *manager = Unk044904_Get_data_0215ee98();
    func_0204ae84(manager->unk_08c.unk_294);
    func_0204a884(&manager->unk_08c);
    manager->unk_08c.unk_000 = 0x10000;
    manager->unk_08c.unk_028 = &Unk02e000_Thunk_0202e788()->unk_048;
    manager->unk_08c.unk_1dd = Unk02ee5c_GetTierFromField70();
    func_021219d0(&manager->unk_08c.unk_02c, Unk02e000_Thunk_0202e788());
    func_02121970(&manager->unk_08c);
    return 1;
}

/* Copy the embedded object's selected values back; validate the signed byte ID first. */
int func_02121d84(void)
{
    Unk1218d0Manager *manager;
    Unk1218d0Work *work = Unk02e000_Thunk_0202e788();
    manager = Unk044904_Get_data_0215ee98();
    int id;
    Unk1218d0Flags *flags;
    work->unk_06c = 0;
    id = manager->unk_08c.unk_170;
    flags = func_020982c0((s8)id);
    if (flags != 0 && flags->unk_03) work->unk_06c = id;
    work->unk_01c = manager->unk_08c.unk_02c;
    work->unk_01e = manager->unk_08c.unk_038;
    func_02096c8c();
    return 1;
}

/* Save a non-null object's values into its one-based area record; return success. */
int func_02122188(Unk1218d0Object *object)
{
    Unk1218d0Record *record;
    int id;
    Unk1218d0Flags *flags;
    if (object == 0) return 0;
    record = Unk02e000_GetAreaRecord((u16)object->unk_000 - 1);
    record->unk_34 = 0;
    id = object->unk_170;
    flags = func_020982c0((s8)id);
    if (flags != 0 && flags->unk_03) record->unk_34 = id;
    record->unk_1e = object->unk_02c;
    record->unk_20 = object->unk_038;
    func_0209786c(record);
    return 1;
}

/* Store three zero-based area indices, using -1 for an unoccupied manager slot. */
void func_02122200(void)
{
    Unk1218d0Manager *manager = Unk044904_Get_data_0215ee98();
    Unk1218d0Work *work = Unk02e000_GetWorkArea();
    int i;
    for (i = 0; i < 3; i++) {
        if (manager->unk_068[i] == 0) work->unk_354[i] = -1;
        else work->unk_354[i] = (u16)manager->unk_068[i]->unk_000 - 1;
    }
}

/* Allocate an inactive slot and assign the next counter ID with bit 17 set. */
u32 Unk1218d0_Unk_122544(u32 value, int mode)
{
    Unk1218d0Manager *manager = Unk044904_Get_data_0215ee98();
    Unk1218d0Object *object = Unk044904_FindInactiveSlot();
    u32 id = manager->unk_03c | 0x20000;
    manager->unk_03c++;
    func_02122494(object, id, value, mode);
    func_02121970(object);
    return id;
}

/* Reinitialize an existing slot with its current ID and mode -1, then refresh flags. */
u32 Unk1218d0_Unk_122590(u32 value, Unk1218d0Object *object)
{
    func_02122494(object, object->unk_000, value, -1);
    func_02121970(object);
    return object->unk_000;
}

void func_02121de4(u32 *fields, Unk1218d0Record *record, Unk1218d0Definition *definition);
int func_020e6948(u32 id, u32 entry);

/* Rebuild the indexed area slot and discard IDs rejected by either lookup.
 * Evidence: 736-byte slots at manager +0x36c and six IDs at object +0x1b8. */
int func_02122074(int index)
{
    Unk1218d0Record *record = Unk02e000_GetAreaRecord(index);
    Unk1218d0Manager *manager = Unk044904_Get_data_0215ee98();
    Unk1218d0Object *object = &manager->unk_36c[index];
    Unk1218d0Definition *definition;
    int i;
    func_0204ae84(object->unk_294);
    func_0204a884(object);
    definition = func_020a1428(record->unk_36);
    object->unk_000 = (((u32)(u16)(index + 1) << 16) >> 16) | 0x10000;
    object->unk_1d8 = record->unk_36;
    object->unk_028 = Unk0a163c_Unk_0a1814(record->unk_36);
    object->unk_1dd = definition->unk_05;
    func_02121de4(&object->unk_02c, record, definition);
    for (i = 0; i < 6; i++) {
        Unk1218d0Entry *entry;
        if (object->unk_1b8[i] == 0) continue;
        if (!func_020e6948(object->unk_1d8, object->unk_1b8[i])) object->unk_1b8[i] = 0;
        entry = func_020cb21c(object->unk_1b8[i]);
        if (entry == 0) continue;
        if (!entry->unk_26.bits.valid) object->unk_1b8[i] = 0;
    }
    func_02121970(object);
    return 1;
}

void func_020a18c8(u32 id, u16 *ids, int count);
void func_02097c18(Unk1218d0Packed *packed, Unk1218d0Definition *definition, u16 *ids);
void func_02008848(void *destination, int value, u32 size);

/* Populate 27 statistic triples and two state records from an ID definition.
 * Evidence: switch indices, table load widths, and the final 24-byte copy.
 * The supplied fields storage must include both states and the six-ID array. */
void func_02122258(u32 *storage, Unk1218d0Definition *definition, Unk1218d0Source *source)
{
    Unk1218d0Fields *fields = (Unk1218d0Fields *)storage;
    Unk1218d0Packed packed[20];
    int i;
    Unk1218d0Stat *stat;
    Unk1218d0States *state;
    func_020a18c8(source->id, fields->ids, 6);
    func_02097c18(packed, definition, fields->ids);
    for (i = 0, stat = fields->stats; i < 27; i++, stat++) {
        switch (i) {
        case 0: stat->current = source->unk_04; stat->limit = source->unk_04; break;
        case 1: stat->current = source->unk_08; stat->limit = source->unk_08; break;
        case 2: stat->current = source->unk_02; stat->limit = source->unk_02; break;
        case 3: stat->current = source->unk_0c; stat->limit = 999; break;
        case 4: stat->current = source->unk_14; stat->limit = 999; break;
        case 5: stat->current = source->unk_0e; stat->limit = 999; break;
        case 6: stat->current = source->unk_10; stat->limit = 999; break;
        case 7: stat->current = source->unk_12; stat->limit = 999; break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
            stat->current = packed[i - 8].low;
            stat->limit = 300;
            stat->extra = packed[i - 8].high;
            break;
        }
    }
    func_021218d0((Unk1218d0Object *)fields);
    state = &fields->states;
    func_02008848(state, 0, 52);
    state->first.unk_00 = source->unk_18;
    state->first.unk_06 = source->unk_19;
    state->first.unk_04 = source->unk_0c * 2;
    state->first.unk_08 = source->unk_1a;
    state->first.unk_07 = source->unk_1b;
    state->first.unk_0c = source->unk_1c;
    state->first.unk_10 = ((u32)source->unk_16 << 23) >> 28;
    state->first.unk_14 = ((u32)source->unk_16 << 20) >> 29;
    state->first.unk_16 = ((u32)source->unk_16 << 17) >> 29;
    state->first.unk_0e = source->unk_1e;
    state->second = state->first;
    state->value = source->unk_0e * 2;
}

void Unk0979d8_CopyIds(Unk1218d0Record *record, u16 *ids);
void Unk0afc28_Unk_0b0930(void *destination, int index, u32 amount, int id);
/* Populate the same statistic/state layout from a saved area record.
 * Evidence: signed saved fields, definition +0x0a packed flags, and +0x34 ID.
 * A valid flagged saved ID also initializes the record at fields +0x144. */
void func_02121de4(u32 *storage, Unk1218d0Record *record, Unk1218d0Definition *definition)
{
    Unk1218d0Fields *fields = (Unk1218d0Fields *)storage;
    Unk1218d0Packed packed[20];
    int i;
    Unk1218d0Stat *stat;
    Unk1218d0States *state;
    Unk0979d8_CopyIds(record, fields->ids);
    func_02097c18(packed, definition, fields->ids);
    for (i = 0, stat = fields->stats; i < 27; i++, stat++) {
        switch (i) {
        case 0: stat->current = (s16)record->unk_1e; stat->limit = record->unk_0a; break;
        case 1: stat->current = (s16)record->unk_20; stat->limit = record->unk_0c; break;
        case 2: stat->current = record->unk_38; stat->limit = 99; break;
        case 3: stat->current = record->unk_0e; stat->limit = 99; break;
        case 4: stat->current = record->unk_12; stat->limit = 99; break;
        case 5: stat->current = record->unk_0f; stat->limit = 99; break;
        case 6: stat->current = record->unk_10; stat->limit = 99; break;
        case 7: stat->current = record->unk_11; stat->limit = 99; break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
            stat->current = packed[i - 8].low;
            stat->limit = 300;
            stat->extra = packed[i - 8].high;
            break;
        }
    }
    func_021218d0((Unk1218d0Object *)fields);
    state = &fields->states;
    func_02008848(state, 0, 52);
    state->first.unk_00 = definition->unk_0c;
    state->first.unk_06 = definition->unk_0d;
    state->first.unk_04 = record->unk_0e * 2;
    state->first.unk_08 = definition->unk_0e;
    state->first.unk_07 = definition->unk_0f;
    state->first.unk_0c = definition->unk_10;
    state->first.unk_10 = ((u32)definition->unk_0a << 27) >> 28;
    state->first.unk_14 = ((u32)definition->unk_0a << 24) >> 29;
    state->first.unk_16 = ((u32)definition->unk_0a << 21) >> 29;
    state->first.unk_0e = definition->unk_12;
    state->second = state->first;
    state->value = record->unk_0f * 2;
    {
        int id = record->unk_34;
        Unk1218d0Flags *flags;
        u16 amount;
        if (id == 0) return;
        flags = func_020982c0((s8)id);
        if (flags == 0) return;
        if (!flags->unk_03_bit1) return;
        amount = id == 3 ? 50 : 25;
        Unk0afc28_Unk_0b0930(fields->pad_144, 0, amount, id);
    }
}

/* Borrowed item view: packed fields follow the original shifts at +4/+8. */
typedef struct {
    u32 unk_00;
    struct { u32 low : 10; u32 middle : 10; u32 high : 12; } unk_04;
    struct { u8 low : 4; u8 high : 4; } unk_08;
    u8 unk_09, unk_0a, unk_0b, unk_0c, unk_0d; u16 unk_0e;
} Unk1218d0Item;
void func_02097340(Unk1218d0Packed *packed);
void Unk096754_Unk_097204(u16 *ids);
Unk1218d0Item *Unk09974c_Unk_099c60(u32 id);
/* Initialize statistic triples from persistent work and merge four item records.
 * Evidence: four halfword IDs, packed item fields, and signed saved-stat loads.
 * Lookup failures leave the corresponding cleared state unchanged. */
void func_021219d0(u32 *storage, Unk1218d0Work *work)
{
    Unk1218d0Fields *fields = (Unk1218d0Fields *)storage;
    Unk1218d0Packed packed[20];
    int i;
    Unk1218d0Stat *stat;
    Unk1218d0States *state;
    func_02097340(packed);
    for (i = 0, stat = fields->stats; i < 27; i++, stat++) {
        switch (i) {
        case 0: stat->current = (s16)work->unk_01c; stat->limit = work->unk_012; break;
        case 1: stat->current = (s16)work->unk_01e; stat->limit = work->unk_014; break;
        case 2: stat->current = work->unk_06e; stat->limit = 99; break;
        case 3: stat->current = work->unk_016; stat->limit = 99; break;
        case 4: stat->current = work->unk_01a; stat->limit = 99; break;
        case 5: stat->current = work->unk_017; stat->limit = 99; break;
        case 6: stat->current = work->unk_018; stat->limit = 99; break;
        case 7: stat->current = work->unk_019; stat->limit = 99; break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
            stat->current = packed[i - 8].low;
            stat->limit = 300;
            stat->extra = packed[i - 8].high;
            break;
        }
    }
    state = &fields->states;
    func_02008848(state, 0, 52);
    Unk096754_Unk_097204(fields->ids);
    for (i = 0; i < 4; i++) {
        u16 id;
        Unk1218d0Item *item;
        switch (i) {
        case 0: id = work->ids[0]; break;
        case 1: id = work->ids[1]; break;
        case 2: id = work->ids[2]; break;
        case 3: id = work->ids[3]; break;
        }
        if (id == 0) continue;
        item = Unk09974c_Unk_099c60(id);
        if (item == 0) continue;
        switch (i) {
        case 0:
            state->first.unk_00 = item->unk_04.high;
            state->first.unk_04 = item->unk_04.low;
            state->first.unk_06 = item->unk_0a;
            state->first.unk_08 = item->unk_0b;
            state->first.unk_07 = item->unk_0c;
            state->first.unk_0c = item->unk_0d;
            state->first.unk_10 = item->unk_09;
            state->first.unk_14 = item->unk_08.low;
            state->first.unk_16 = item->unk_08.high;
            state->first.unk_0e = item->unk_0e;
            break;
        case 1:
            state->second.unk_00 = item->unk_04.high;
            state->second.unk_04 = item->unk_04.low;
            state->second.unk_06 = item->unk_0a;
            state->second.unk_08 = item->unk_0b;
            state->second.unk_07 = item->unk_0c;
            state->second.unk_0c = item->unk_0d;
            state->second.unk_10 = item->unk_09;
            state->second.unk_14 = item->unk_08.low;
            state->second.unk_16 = item->unk_08.high;
            state->second.unk_0e = item->unk_0e;
            break;
        }
        state->value += item->unk_04.middle;
    }
    func_021218d0((Unk1218d0Object *)fields);
    {
        int id = work->unk_06c;
        Unk1218d0Flags *flags;
        u16 amount;
        if (id == 0) return;
        flags = func_020982c0((s8)id);
        if (flags == 0) return;
        if (!flags->unk_03_bit1) return;
        amount = id == 3 ? 50 : 25;
        Unk0afc28_Unk_0b0930(fields->pad_144, 0, amount, id);
    }
}

/* Initialize a supplied slot from both ID lookup records; null lookups return 0.
 * Evidence: ID halfwords at +0x1d8/+0x1da and lookup byte +5. */
int func_02122494(Unk1218d0Object *object, u32 id, u32 value, int mode)
{
    Unk1218d0Source *source;
    Unk1218d0Definition *definition;
    if (object == 0) return 0;
    source = func_020a1740(value);
    definition = func_020a1428(value);
    if (source == 0) return 0;
    if (definition == 0) return 0;
    func_0204ae84(object->unk_294);
    func_0204a884(object);
    object->unk_000 = id;
    object->unk_1d8 = value;
    object->unk_1da = mode;
    object->unk_028 = Unk0a163c_Unk_0a1814(object->unk_1d8);
    object->unk_1dd = definition->unk_05;
    func_02122258(&object->unk_02c, definition, source);
    if (Unk0a163c_Unk_0a17d8(value)) object->unk_282 |= 4;
    return 1;
}
