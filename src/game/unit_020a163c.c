#include "game/unit_020a163c.h"

/* ARM 0x020a1718: compare the first unsigned halfword of two records.
 * The subtraction promotes both values to int, giving a signed ordering. */
int Unk0a163c_Unk_0a1718(const u16 *left, const u16 *right)
{
    return *left - *right;
}

/* ARM 0x020a1728: return the size/count query for resource (19, 1).
 * The two calls establish the resource selection; its content is unknown. */
u32 Unk0a163c_Unk_0a1728(void)
{
    return func_0204fe18(func_020445d0(19, 1));
}

/* ARM 0x020a1814: return a borrowed entry from resource (18, 1).
 * Index validation and entry lifetime belong to the resource routines. */
void *Unk0a163c_Unk_0a1814(u32 index)
{
    return func_0204fed8(func_020445f4(18, 1), index);
}

/* ARM 0x020a1834: return a borrowed entry from resource (18, 0).
 * Index validation and entry lifetime belong to the resource routines. */
void *Unk0a163c_Unk_0a1834(u32 index)
{
    return func_0204fed8(func_020445f4(18, 0), index);
}

/* ARM 0x020a1ba0: add 500 to the caller's id, wrapping to 16 bits,
 * then forward the list and value to func_020a1b08. */
int Unk0a163c_Call_020a1b08(Unk0a163cList *list, u16 id, u32 value)
{
    return func_020a1b08(list, (u16)(id + 500), value);
}

/* ARM 0x020a21f8: set the state word to 1 before running the shared
 * callback. The caller retains ownership of the work object. */
int Unk0a163c_Unk_0a21f8(Unk0a163cWork *work)
{
    work->unk_000c = 1;
    return func_020a208c(work);
}

/* ARM 0x020a220c: forward the borrowed work object to the shared callback
 * and return its result without modifying the object first. */
int Unk0a163c_Thunk_020a208c(Unk0a163cWork *work)
{
    return func_020a208c(work);
}

/* ARM 0x020a22c8: add 500 to the id, wrapping to 16 bits, and return
 * the matching borrowed list entry (or the callee's null result). */
void *Unk0a163c_Call_020a2218(Unk0a163cList *list, u16 id)
{
    return func_020a2218(list, (u16)(id + 500));
}

/* ARM 0x020a1740: search resource (19, 1) by its leading halfword.
 * The original uses a 128-byte stack key and 128-byte resource stride. */
Unk0a163cRecord *func_020a1740(u16 id)
{
    Unk0a163cRecord key;
    void *resource = func_020445d0(19, 1);
    void *base = func_0204fde0(resource);
    u32 count = func_0204fe18(resource);
    key.id = id;
    return func_02011810(&key, base, count, 128, Unk0a163c_Unk_0a1718);
}

/* ARM 0x020a1798: map the signed record selector through two byte tables,
 * returning its magnitude via func_02011804 when it is negative. */
u16 Unk0a163c_Unk_0a1798(u16 id)
{
    s16 selector = func_020a1740(id)->unk_006a;
    if (selector < 0) return (u16)func_02011804(selector);
    selector = data_0213c258[selector];
    return data_0213c244[selector];
}

/* ARM 0x020a17d8: compare the record byte at +0x5a with the shared
 * record query; a negative selector at +0x6a returns true immediately. */
int Unk0a163c_Unk_0a17d8(u16 id)
{
    Unk0a163cRecord *record = func_020a1740(id);
    if (record->unk_006a < 0) return 1;
    return Unk02e000_GetRecordUnk1e(id) < record->unk_005a;
}

/* ARM 0x020a1ae0: run list cleanup, release its entry buffer, and clear
 * count and pointer. The list container stays owned by the caller. */
int Unk0a163c_Unk_0a1ae0(Unk0a163cList *list)
{
    func_020a1a24(list);
    func_02053000(list->entries);
    list->entries = 0;
    list->count = 0;
    return 1;
}

/* ARM 0x020a1b68: translate the record selector into a u16 list id.
 * Negative selectors use 500 minus the selector before insertion. */
int func_020a1b68(Unk0a163cList *list, u16 id, u32 value)
{
    u16 selector;
    s32 raw = func_020a1740(id)->unk_006a;
    if (raw < 0) selector = 500 - raw;
    else selector = raw;
    return func_020a1b08(list, selector, value);
}

/* ARM 0x020a2218: scan count entries of stride 0x3a0 for the leading
 * u16 id; return a borrowed entry, or null when no entry matches. */
Unk0a163cEntry *func_020a2218(Unk0a163cList *list, u16 id)
{
    u32 i;
    Unk0a163cEntry *entry;
    i = 0;
    if (i < list->count) {
        entry = list->entries;
        do {
            if (entry->id == id) return entry;
            i++;
            entry++;
        } while (i < list->count);
    }
    return 0;
}

/* ARM 0x020a22e0: create an output from a matching entry and negate
 * its metadata offsets into output +0xc/+0x10. Missing entries return null. */
Unk0a163cOutput *func_020a22e0(Unk0a163cList *list, u16 id, u32 value)
{
    Unk0a163cEntry *entry = func_020a2250(list, id);
    Unk0a163cOutput *output;
    if (entry == 0) return 0;
    output = func_02065fc0(entry->unk_0194, entry->unk_0190, value, 1, 0);
    output->unk_000c = -entry->unk_018c->unk_0002;
    output->unk_0010 = -entry->unk_018c->unk_0004;
    return output;
}

/* ARM 0x020a239c: obtain the object's borrowed view, construct an output,
 * forward the view argument, copy both coordinates, and finalize by flag. */
Unk0a163cOutput *func_020a239c(void *object, u32 argument, int flag)
{
    Unk0a163cOutput *view = func_0205f41c(object, argument);
    Unk0a163cOutput *output = func_0205adb4(0, &view->unk_000c);
    output->unk_000c = func_0205accc(view);
    output->unk_0010 = func_0205acd4(view);
    if (flag) func_0205b9a0(output);
    else func_0205b900(output);
    return output;
}

/* ARM 0x020a1854: map selectors -5..-1 to 0,4,3,2,1; nonnegative
 * selectors index the borrowed byte table. Other negatives are unspecified. */
int func_020a1854(u16 id)
{
    int result;
    s32 selector = func_020a1740(id)->unk_006a;
    if (selector < 0) {
        switch (selector) {
        case -5: result = 0; break;
        case -1: result = 1; break;
        case -2: result = 2; break;
        case -3: result = 3; break;
        case -4: result = 4; break;
        }
    } else result = data_0213c258[selector];
    return result;
}

/* ARM 0x020a19b4: allocate and zero count entries, marking each id
 * 0xffff. The caller owns the list and must eventually release its buffer. */
int func_020a19b4(Unk0a163cList *list, u32 count)
{
    u32 bytes = count * sizeof(Unk0a163cEntry);
    u32 i;
    list->count = count;
    list->entries = func_02052fe0(bytes);
    func_02008848(list->entries, 0, bytes);
    list->unk_0008 = 0;
    for (i = 0; i < list->count; i++) list->entries[i].id = 0xffff;
    return 1;
}

/* ARM 0x020a1b08: accept an existing id or populate the first unused
 * entry with id and value; return zero when all count entries are occupied. */
int func_020a1b08(Unk0a163cList *list, u16 id, u32 value)
{
    u32 i = 0;
    Unk0a163cEntry *entry;
    u32 count = list->count;
    if (i < count) {
        entry = list->entries;
        do {
            if (entry->id == id) return 1;
            if (entry->id == 0xffff) {
                entry->id = id;
                entry->unk_0008 = value;
                return 1;
            }
            i++;
            entry++;
        } while (i < count);
    }
    return 0;
}

/* ARM 0x020a1bb8: resolve the current entry's object when flag is set,
 * cache its view and adjusted count, and accumulate entries with value zero. */
int func_020a1bb8(Unk0a163cList *list, int flag)
{
    Unk0a163cEntry *entry = &list->entries[list->unk_0010];
    if (entry->id == 0xffff) return 0;
    if (flag) {
        entry->unk_0004 = func_020519e8(list->unk_0014);
        if (entry->unk_0004 == 0) return 0;
    }
    entry->unk_018c = (Unk0a163cMetadata *)func_0205f41c(entry->unk_0004, 0);
    entry->unk_0002 = func_0205f2e4(entry->unk_0004) - 3;
    if (entry->unk_0008 == 0) list->unk_0008 += entry->unk_0002;
    return 1;
}

/* ARM 0x020a1c50: format the current entry's resource name in 64 stack
 * bytes; request it when flagged, otherwise resolve it and cache its view. */
int func_020a1c50(Unk0a163cList *list, int flag)
{
    char name[64];
    Unk0a163cEntry *entry = &list->entries[list->unk_0010];
    if (entry->id == 0xffff) return 0;
    if (entry->id >= 500) func_02013c3c(name, data_0214cd28, entry->id - 500);
    else func_02013c3c(name, data_0214cd48, entry->id);
    if (flag) func_020516dc(list->unk_0014, name, 0, 0);
    else {
        entry->unk_0004 = func_02051610(name);
        func_020a1bb8(list, flag);
    }
    return 1;
}

/* ARM 0x020a2004: run two passes over the list using its shared cursor;
 * each callback receives flag zero and may update the list state. */
int func_020a2004(Unk0a163cList *list)
{
    for (list->unk_0010 = 0; list->unk_0010 < list->count; list->unk_0010++)
        func_020a1c50(list, 0);
    for (list->unk_0010 = 0; list->unk_0010 < list->count; list->unk_0010++)
        func_020a1d00(list, 0);
    return 1;
}

/* ARM 0x020a2250: first search the record's translated selector, then
 * fall back to its table-mapped id plus 500. Returned entries are borrowed. */
Unk0a163cEntry *func_020a2250(Unk0a163cList *list, u16 id)
{
    Unk0a163cRecord *record = func_020a1740(id);
    s32 selector = record->unk_006a;
    Unk0a163cEntry *entry;
    u16 fallback;
    if (selector < 0) fallback = 500 - selector;
    else fallback = selector;
    entry = func_020a2218(list, fallback);
    if (entry) return entry;
    selector = record->unk_006a;
    if (selector < 0) fallback = func_02011804(selector);
    else fallback = data_0213c244[data_0213c258[selector]];
    return Unk0a163c_Call_020a2218(list, fallback);
}

/* ARM 0x020a2334: construct an output from a matching borrowed entry,
 * forwarding mode/flags and negating its signed metadata coordinates. */
Unk0a163cOutput *func_020a2334(Unk0a163cList *list, u16 id, u32 value, int mode, u16 flags)
{
    Unk0a163cEntry *entry = func_020a2250(list, id);
    Unk0a163cOutput *output;
    if (entry == 0) return 0;
    output = func_02065fc0(entry->unk_0194, entry->unk_0190, value, mode, flags);
    output->unk_000c = -entry->unk_018c->unk_0002;
    output->unk_0010 = -entry->unk_018c->unk_0004;
    return output;
}

/* ARM 0x020a163c: sort the six nonzero halfwords of each resource
 * (19, 0) record in ascending order, discarding duplicates and padding zero. */
void func_020a163c(void)
{
    u16 sorted[6];
    void *resource = func_020445d0(19, 0);
    Unk0a163cSortRecord *record = func_0204fde0(resource);
    u32 count = func_0204fe18(resource);
    u32 i;
    for (i = 0; i < count; i++, record++) {
        int j;
        func_02008848(sorted, 0, sizeof(sorted));
        for (j = 0; j < 6; j++) {
            u32 value = record->slots[j];
            int k;
            if (value == 0) continue;
            for (k = 0; k < 6; k++) {
                u32 old = sorted[k];
                if (old == 0) { sorted[k] = value; break; }
                if (value == old) break;
                if (old > value) { sorted[k] = value; value = old; }
            }
        }
        func_02008904(sorted, record->slots, sizeof(sorted));
    }
}

/* ARM 0x020a18c8: clear capacity halfwords, then insert distinct resource
 * values in ascending order. A missing named resource returns zero. */
int func_020a18c8(u16 id, u16 *values, int capacity)
{
    char name[64];
    int i;
    Unk0a163cRecord *record;
    Unk0a163cValues *resource;
    int k;
    for (i = 0; i < capacity; i++) values[i] = 0;
    record = func_020a1740(id);
    if (record) {
        func_02013c3c(name, data_0214cd10, record->unk_006c);
        if (!func_020513d4(name)) return 0;
        resource = func_02051610(name);
        for (k = 0; k < resource->count; k++) {
            u32 value = resource->values[k];
            int j;
            for (j = 0; j < capacity; j++) {
                u32 old = values[j];
                if (old == 0) { values[j] = value; break; }
                if (value == old) break;
                if (value < old) { values[j] = value; value = old; }
            }
        }
        func_02053000(resource);
    }
    return 1;
}

/* ARM 0x020a1a24: release the counted shared allocations and each entry's
 * three owned objects; restore unused ids without freeing the list buffer. */
void func_020a1a24(Unk0a163cList *list)
{
    int count = list->unk_0008;
    int j;
    u32 i;
    for (j = 0; j < count; j++) func_0205bb68();
    list->unk_0008 = 0;
    for (i = 0; i < list->count; i++) {
        Unk0a163cEntry *entry = &list->entries[i];
        if (entry->unk_0194) {
            func_0205ddb4(entry->unk_0194);
            entry->unk_0194 = 0;
        }
        if (entry->unk_0190) {
            func_0205c368(entry->unk_0190);
            entry->unk_0190 = 0;
        }
        func_02053000(entry->unk_0004);
        entry->unk_0004 = 0;
        list->entries[i].id = 0xffff;
        list->entries[i].unk_0008 = 0;
    }
}

/* ARM 0x020a1d00: build current entry outputs from object views 3 onward,
 * format names from id/index, and link named container items to inline views.
 * The flag selects the two original output initialization routines. */
int func_020a1d00(Unk0a163cList *list, int flag)
{
    s32 x, y;
    Unk0a163cEntry *entry = &list->entries[list->unk_0010];
    int i;
    if (entry->id == 0xffff) return 0;
    for (i = 0; i < entry->unk_0002; i++) {
        Unk0a163cInline *output;
        int slot = i;
        if (i >= 4) slot = 0;
        if (entry->unk_0008) {
            Unk0a163cOutput *view;
            output = &entry->outputs[slot];
            view = func_0205f41c(entry->unk_0004, i + 3);
            output->vector = *(Unk0a163cVector *)((u8 *)view + 12);
            func_0205aa78(&output->vector, &x, &y, &output->unk_0028, &output->unk_002a);
            if (slot == 0) {
                output->x = ((s32 *)entry->unk_0008)[0];
                output->y = ((s32 *)entry->unk_0008)[1];
            }
            if (slot < 3) {
                entry->outputs[slot + 1].x = output->x + x;
                entry->outputs[slot + 1].y = output->y + y;
            }
            if (flag) func_0205b444(output, view);
            else func_0205b4c4(output, view);
            output->unk_000c = func_0205accc(view);
            output->unk_0010 = func_0205acd4(view);
        } else {
            output = (Unk0a163cInline *)func_020a239c(entry->unk_0004, i + 3, flag);
            entry->output_ptrs[slot] = output;
        }
        if (entry->id >= 500) {
            switch (i) {
            case 0: func_02013c3c(output->name, data_0214cd64, entry->id - 500); break;
            case 1: func_02013c3c(output->name, data_0214cd70, entry->id - 500); break;
            default: func_02013c3c(output->name, data_0214cd7c, entry->id - 500, i); break;
            }
        } else {
            switch (i) {
            case 0: func_02013c3c(output->name, data_0214cd8c, entry->id); break;
            case 1: func_02013c3c(output->name, data_0214cd94, entry->id); break;
            default: func_02013c3c(output->name, data_0214cd9c, entry->id, i); break;
            }
        }
        if (i == 0) func_02008904((void *)output->unk_0010, (u8 *)entry + 0x1a0, 512);
    }
    if (entry->unk_0008) {
        u32 j;
        Unk0a163cContainer *container = func_0205dd58(func_0205f41c(entry->unk_0004, 2), 0);
        entry->unk_0194 = container;
        for (j = 0; j < container->count; j++) {
            Unk0a163cItem *item = func_0205e33c(container, j);
            int k;
            for (k = 0; k < entry->unk_0002; k++) {
                if (func_020152cc(entry->outputs[k].name, item->name) == 0)
                    item->output = &entry->outputs[k];
            }
            container = entry->unk_0194;
        }
    } else entry->unk_0194 = func_0205dd58(func_0205f41c(entry->unk_0004, 2), 1);
    entry->unk_0190 = func_0205c328(func_0205f41c(entry->unk_0004, 1));
    return 1;
}

/* ARM 0x020a208c: advance resource loading through states 0..6 at +0xc.
 * Work must reference a full list object, including its loading context.
 * Completion waits for each entry's byte +0x59 (or inline +0x65) flags. */
int func_020a208c(Unk0a163cWork *work)
{
    Unk0a163cList *list = (Unk0a163cList *)work;
    switch (list->unk_000c) {
    case 0: return 1;
    case 6: return 1;
    case 1:
        list->unk_0010 = 0;
        list->unk_000c = 2;
        /* Fall through to request the first entry in this call. */
    case 2:
        if (list->unk_0010 >= list->count) list->unk_000c = 6;
        else if (func_020a1c50(list, 1)) list->unk_000c = 3;
        else list->unk_0010++;
        break;
    case 3:
        if (func_02051844(list->unk_0014, -1) == 0) {
            func_020a1bb8(list, 1);
            list->unk_000c = 4;
        }
        break;
    case 4:
        func_020a1d00(list, 1);
        list->unk_000c = 5;
        break;
    case 5:
        {
            Unk0a163cEntry *entry = &list->entries[list->unk_0010];
            int ready = 1;
            int i;
            for (i = 0; i < entry->unk_0002; i++) {
                if (entry->unk_0008) {
                    if (entry->outputs[i].ready == 0) ready = 0;
                } else {
                    Unk0a163cInline *object = entry->output_ptrs[i];
                    if (object->ready == 0) ready = 0;
                }
            }
            if (ready) {
                list->unk_0010++;
                list->unk_000c = 2;
            }
        }
        break;
    }
    return 0;
}
