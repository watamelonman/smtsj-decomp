#include "types.h"

/* Borrowed record views: gaps are fields not accessed by this unit. */
typedef struct Entry {
    u8 pad0[0x22];
    u8 cost;
    u8 pad23[3];
    u16 kind;
    u16 variant : 4;
    u16 variant_rest : 12;
    u8 pad2a[8];
    u16 effect : 12;
    u16 selector : 4;
    u8 pad34[9];
    u8 amount;
} Entry;
typedef struct MainRecord {
    u8 pad0[0x12];
    s16 maximum;
    u8 pad14[6];
    s8 scale;
    u8 pad1b;
    s16 current;
    s16 resource;
    u8 pad20[0x4c];
    u16 status;
    u8 level;
} MainRecord;
typedef struct AreaRecord {
    u8 pad0[10];
    s16 maximum;
    u8 padc[6];
    s8 scale;
    u8 pad13[11];
    s16 current;
    s16 resource;
    u8 pad22[6];
    u16 entries[6];
    u16 status;
    u8 pad36[2];
    u8 level;
} AreaRecord;
typedef struct Work {
    u8 pad0[0x348];
    s8 slots[12];
} Work;
MainRecord *Unk02e000_Thunk_0202e788(void);
AreaRecord *Unk02e000_GetAreaRecord(int index);
Work *Unk02e000_GetWorkArea(void);
Entry *func_020cb1a0(int id);
Entry *func_020cb21c(int id);
int Unk0cb0d0_Unk_0cb274(Entry *entry);
void Unk096754_Unk_097204(u16 *entries);
void func_02008904(const void *source, void *destination, u32 size);
int func_020b0b5c(int value, int maximum, int level, int scale, int multiplier);
int func_020b0bd4(int value, int maximum, int multiplier);
extern const u16 data_02150ec8[];

/* Computes an entry's amount for a borrowed target; six equipped entries adjust
 * the multiplier (kind 19, variant 5 or 6). Negative target selects the main record. */
int func_020f8bc8(Entry *entry, int maximum, int target)
{
    int i;
    int level, scale;
    int count;
    u16 entries[6];
    int result;
    if (entry->effect == 0 && entry->amount == 0)
        return 0;
    count = 0;
    for (i = 0; i < 6; i++) entries[i] = 0;
    if (target < 0) {
        MainRecord *record = Unk02e000_Thunk_0202e788();
        level = record->level;
        scale = record->scale;
        Unk096754_Unk_097204(entries);
    } else {
        AreaRecord *record = Unk02e000_GetAreaRecord(target);
        if (record == 0) return 0;
        level = record->level;
        scale = record->scale;
        func_02008904(record->entries, entries, 12);
    }
    for (i = 0; i < 6; i++) {
        if (entries[i] != 0) {
            Entry *equipped = func_020cb21c(entries[i]);
            if (equipped != 0 && ((u32)equipped->kind << 16) >> 27 == 19) {
                switch (equipped->variant) {
                case 5: count++; break;
                case 6: count += 2; break;
                }
            }
        }
    }
    result = 0;
    if (entry->effect) {
        int multiplier = data_02150ec8[count];
        result = func_020b0b5c(entry->effect,
                             maximum, level, scale, multiplier);
    } else if (entry->amount != 0) {
        result = func_020b0bd4(entry->amount, maximum, data_02150ec8[count]);
    }
    return result;
}

/* Returns the compatible nonzero status or -1; the packed effect's upper nibble
 * selects exact matching or the special rules for selectors 12 through 14. */
int func_020f8d44(Entry *entry, int status)
{
    int selector = entry->selector;
    int result = -1;
    if (selector != 0 && status != 0) {
        if (selector == 12) {
            if (status != 1) result = status;
        } else if (selector == 13) {
            if (status == 2) result = status;
            if (status == 8) result = status;
        } else if (selector == 14) {
            result = status;
        } else if (status == selector) result = status;
    }
    return result;
}

/* Deducts the entry's byte cost from the selected record, clamping at zero. */
void func_020f8da4(int target, Entry *entry)
{
    if (target < 0) {
        MainRecord *record = Unk02e000_Thunk_0202e788();
        record->resource -= entry->cost;
        if (record->resource < 0) record->resource = 0;
    } else {
        AreaRecord *record = Unk02e000_GetAreaRecord(target);
        record->resource -= entry->cost;
        if (record->resource < 0) record->resource = 0;
    }
}

/* Applies status and amount changes; returns zero if a change occurred.
 * Negative target selects the main record; a missing area record returns one. */
int func_020f8e04(int source, int target, Entry *entry)
{
    MainRecord *main = 0;
    AreaRecord *area = 0;
    int result;
    if (target < 0) main = Unk02e000_Thunk_0202e788();
    else {
        area = Unk02e000_GetAreaRecord(target);
        if (area == 0) return 1;
    }
    result = 1;
    if (Unk0cb0d0_Unk_0cb274(entry)) {
        if (main != 0) {
            if (main->status == 1) {
                main->status = 0;
                main->current += func_020f8bc8(entry, main->maximum, source);
                if (main->current <= 0) main->current = result;
                result = 0;
            }
        } else {
            if (area->status == 1) {
                area->status = 0;
                area->current += func_020f8bc8(entry, area->maximum, source);
                if (area->current <= 0) area->current = result;
                result = 0;
            }
        }
    } else {
        if (main != 0) {
            if (main->status == 1) return result;
        } else if (area->status == 1) return result;
        if (main != 0) {
            if (func_020f8d44(entry, main->status) > 0) {
                result = 0;
                main->status = result;
            }
            if (main->status != 7) {
                int amount = func_020f8bc8(entry, main->maximum, source);
                if (amount != 0) {
                    if (main->current < main->maximum) {
                        main->current += amount;
                        result = 0;
                    }
                }
                if (main->current > main->maximum) main->current = main->maximum;
            }
        } else {
            if (func_020f8d44(entry, area->status) > 0) {
                result = 0;
                area->status = result;
            }
            if (area->status != 7) {
                int amount = func_020f8bc8(entry, area->maximum, source);
                if (amount != 0) {
                    if (area->current < area->maximum) {
                        area->current += amount;
                        result = 0;
                    }
                }
                if (area->current > area->maximum) area->current = area->maximum;
            }
        }
    }
    return result;
}

/* Applies an entry to the main record and every occupied slot; charges once
 * when at least one target changes. Work-area slots are signed record indices. */
int func_020f8ff4(int source, int id)
{
    int changed = 0;
    Entry *entry = func_020cb1a0(id);
    Work *work;
    int i;
    if (entry == 0) return 1;
    if (func_020f8e04(source, -1, entry) == 0) changed = 1;
    work = Unk02e000_GetWorkArea();
    for (i = 0; i < 12; i++) {
        if (work->slots[i] >= 0 && func_020f8e04(source, work->slots[i], entry) == 0)
            changed = 1;
    }
    if (!changed) return 1;
    func_020f8da4(source, entry);
    return 0;
}

/* Applies the looked-up entry to one target and charges the source only on change. */
int func_020f9090(int source, int target, int id)
{
    Entry *entry = func_020cb1a0(id);
    int result;
    if (entry == 0) return 1;
    result = func_020f8e04(source, target, entry);
    if (result == 0) func_020f8da4(source, entry);
    return result;
}
