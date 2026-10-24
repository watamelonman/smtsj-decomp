/* Layouts follow the halfword and signed-byte accesses in the original unit.
 * Only observed fields are represented; padding carries no inferred meaning. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
/* Borrowed table entry; packed selectors preserve the observed bit extraction. */
typedef struct Entry {
    u8 pad_00[32]; u16 unk_20; u16 unk_22;
    u16 unk_24, unk_26; u8 unk_28, unk_29; u8 unk_2a : 7; u8 flag_2a : 1;
    u8 pad_2b[4]; u8 unk_2f : 1; u8 flag_2f_1 : 1; u8 flags_2f : 6;
} Entry;
/* Default record view; signed values saturate at 99 in selector updates. */
typedef struct RecordA {
    u8 pad_00[12]; s8 unk_0c, unk_0d, unk_0e, unk_0f, unk_10;
    u8 pad_11; s16 unk_12, unk_14; u8 pad_16[6]; s16 unk_1c, unk_1e; u8 pad_20[76]; u16 unk_6c;
} RecordA;
/* Indexed record view; the two signed-byte groups are updated together. */
typedef struct RecordB {
    u8 pad_00[4]; s8 unk_04, unk_05, unk_06, unk_07, unk_08;
    u8 pad_09; s16 unk_0a, unk_0c; u8 pad_0e[10]; s8 unk_18, unk_19, unk_1a, unk_1b, unk_1c;
    u8 pad_1d; s16 unk_1e, unk_20; u8 pad_22[18]; u16 unk_34;
} RecordB;
/* Borrowed work area; exactly twelve signed slot IDs are visited. */
typedef struct Area { u8 pad_000[0x348]; s8 unk_348[12]; } Area;
/* Borrowed ID lookup result; only flag bit six of +0x28 is consumed. */
typedef struct Item { u8 pad_00[40]; u16 low_28 : 6; u16 unk_28 : 1; u16 high_28 : 9; } Item;
extern int func_020445d0(int kind, int index);
extern int *func_0204fde0(int handle);
extern RecordA *Unk02e000_Thunk_0202e788(void);
extern RecordB *Unk02e000_GetAreaRecord(int index);
extern Area *Unk02e000_GetWorkArea(void);
extern Entry *Unk09974c_Unk_099d14(int index);
extern int Unk09974c_IsKind1or14(Entry *entry);
extern void func_02099b10(int index, int value);
extern void func_02096c8c(void);
extern void func_0209786c(RecordB *record);
extern u32 func_02050074(int lower, int upper);
extern void Unk096754_Unk_097204(u16 *ids);
extern void Unk0979d8_CopyIds(RecordB *record, u16 *ids);
extern int Unk0981dc_Unk_098324(int kind, int value);
extern Item *func_020cb21c(int id);

/* Resolve the word behind resource (33, 3); the resource's meaning is unknown. */
int func_020e6a0c(void)
{
    return *func_0204fde0(func_020445d0(33, 3));
}

/* Increment selected signed-byte fields, capped at 99; return whether capped.
 * Selectors 81..85 and both layouts are evidenced by this function's accesses. */
int func_020e6a28(int index, Entry *entry)
{
    RecordA *a = 0;
    RecordB *b = 0;
    int capped;
    if (index < 0) {
        a = Unk02e000_Thunk_0202e788();
        if (a->unk_6c == 1 || a->unk_6c == 7) return 1;
    } else {
        b = Unk02e000_GetAreaRecord(index);
        if (!b) return 1;
        if (b->unk_34 == 1 || b->unk_34 == 7) return 1;
    }
    capped = 0;
    switch (entry->unk_20) {
    case 81:
        if (a) {
            if (a->unk_0c < 99) a->unk_0c++; else capped = 1;
        } else {
            if (b->unk_04 < 99) b->unk_04++; else capped = 1;
            if (b->unk_18 < 99) b->unk_18++; else capped = 1;
        }
        break;
    case 82:
        if (a) {
            if (a->unk_10 < 99) a->unk_10++; else capped = 1;
        } else {
            if (b->unk_08 < 99) b->unk_08++; else capped = 1;
            if (b->unk_1c < 99) b->unk_1c++; else capped = 1;
        }
        break;
    case 83:
        if (a) {
            if (a->unk_0d < 99) a->unk_0d++; else capped = 1;
        } else {
            if (b->unk_05 < 99) b->unk_05++; else capped = 1;
            if (b->unk_19 < 99) b->unk_19++; else capped = 1;
        }
        break;
    case 84:
        if (a) {
            if (a->unk_0e < 99) a->unk_0e++; else capped = 1;
        } else {
            if (b->unk_06 < 99) b->unk_06++; else capped = 1;
            if (b->unk_1a < 99) b->unk_1a++; else capped = 1;
        }
        break;
    case 85:
        if (a) {
            if (a->unk_0f < 99) a->unk_0f++; else capped = 1;
        } else {
            if (b->unk_07 < 99) b->unk_07++; else capped = 1;
            if (b->unk_1b < 99) b->unk_1b++; else capped = 1;
        }
        break;
    default: return 1;
    }
    if (a) func_02096c8c(); else func_0209786c(b);
    return capped;
}

/* Apply selectors 61/62 only on a random roll below 25 when mode is zero.
 * The six IDs and flag bit are directly evidenced by the original loop. */
int func_020e6c54(int index, Entry *entry, int mode)
{
    RecordA *a = 0;
    RecordB *b = 0;
    int valid;
    int i;
    int result;
    if (index < 0) a = Unk02e000_Thunk_0202e788();
    else {
        b = Unk02e000_GetAreaRecord(index);
        if (!b) return 1;
    }
    result = 1;
    switch (entry->unk_20) {
    case 61:
        if (mode == 0 && func_02050074(0, 99) < 25) {
            valid = 0;
            u16 ids[6];
            if (a) {
                Unk096754_Unk_097204(ids);
                if (Unk0981dc_Unk_098324(3, (s8)a->unk_6c)) valid = 1;
            } else {
                Unk0979d8_CopyIds(b, ids);
                if (Unk0981dc_Unk_098324(3, (s8)b->unk_34)) valid = 1;
            }
            if (!valid) break;
            {
                for (i = 0; i < 6; i++) {
                    Item *item = func_020cb21c(ids[i]);
                    if (item && item->unk_28) {
                        valid = 0;
                        break;
                    }
                }
            }
            if (valid) {
                if (a) a->unk_6c = 3; else b->unk_34 = 3;
                result = 0;
            }
        }
        break;
    case 62:
        if (mode == 0 && func_02050074(0, 99) < 25) {
            if (a) a->unk_1e /= 2; else b->unk_20 /= 2;
            result = 0;
        }
        break;
    }
    if (mode == 0) result = 0;
    return result;
}

/* Return the fixed +0x24 value, or a signed percentage of the supplied base. */
int func_020e6de4(Entry *entry, int base)
{
    if (entry->unk_24) return entry->unk_24;
    if (!entry->unk_28) return 0;
    return base * entry->unk_28 / 100;
}

/* Return the fixed +0x26 value, or a signed percentage of the supplied base. */
int func_020e6e20(Entry *entry, int base)
{
    if (entry->unk_26) return entry->unk_26;
    if (!entry->unk_29) return 0;
    return base * entry->unk_29 / 100;
}

/* Filter a nonzero value using the low seven bits of the entry selector. */
int func_020e6e5c(Entry *entry, int value)
{
    int selector = entry->unk_2a;
    int result = -1;
    if (selector && value) {
        if (selector == 12) {
            if (value != 1) result = value;
        } else if (selector == 13) {
            if (value == 2) result = value;
            if (value == 8) result = value;
        } else if (selector == 14) result = value;
        else if (value == selector) result = value;
    }
    return result;
}

/* Apply the entry's state and signed-halfword adjustments to one borrowed
 * record; return zero for an effective update. Evidence: state 1 revival,
 * state 7 exclusion, +0x2f bit one, and the original scaling/filter calls.
 * entry must be nonnull; negative indices select the default record. */
int func_020e6ebc(int index, Entry *entry)
{
    RecordA *a;
    RecordB *b;
    int result;
    int amount;
    if (entry->unk_22) return 1;
    a = 0;
    b = 0;
    if (index < 0) a = Unk02e000_Thunk_0202e788();
    else {
        b = Unk02e000_GetAreaRecord(index);
        if (!b) return 1;
        switch (entry->unk_20) {
        case 81: case 82: case 83: case 84: case 85:
            return 1;
        }
    }
    result = 1;
    if (Unk09974c_IsKind1or14(entry)) {
        if (a) {
            if (a->unk_6c == 1) {
                a->unk_6c = 0;
                a->unk_1c += func_020e6de4(entry, a->unk_12);
                if (a->unk_1c <= 0) a->unk_1c = 1;
                result = 0;
            }
        } else {
            if (b->unk_34 == 1) {
                b->unk_34 = 0;
                b->unk_1e += func_020e6de4(entry, b->unk_0a);
                if (b->unk_1e <= 0) b->unk_1e = 1;
                result = 0;
            }
        }
    } else {
        if (a) {
            if (a->unk_6c == 1) return result;
        } else {
            if (b->unk_34 == 1) return result;
        }
        if (entry->flag_2f_1) result = func_020e6a28(index, entry);
        if (a) {
            if (func_020e6e5c(entry, a->unk_6c) > 0) {
                result = 0;
                a->unk_6c = 0;
            }
            if (a->unk_6c != 7) {
                amount = func_020e6de4(entry, a->unk_12);
                if (amount && a->unk_1c < a->unk_12) {
                    a->unk_1c += amount;
                    result = 0;
                }
                amount = func_020e6e20(entry, a->unk_14);
                if (amount && a->unk_1e < a->unk_14) {
                    a->unk_1e += amount;
                    result = 0;
                }
                if (a->unk_1c > a->unk_12) a->unk_1c = a->unk_12;
                if (a->unk_1e > a->unk_14) a->unk_1e = a->unk_14;
            }
        } else {
            if (func_020e6e5c(entry, b->unk_34) > 0) {
                result = 0;
                b->unk_34 = 0;
            }
            if (b->unk_34 != 7) {
                amount = func_020e6de4(entry, b->unk_0a);
                if (amount && b->unk_1e < b->unk_0a) {
                    b->unk_1e += amount;
                    result = 0;
                }
                amount = func_020e6e20(entry, b->unk_0c);
                if (amount && b->unk_20 < b->unk_0c) {
                    b->unk_20 += amount;
                    result = 0;
                }
            }
            if (b->unk_1e > b->unk_0a) b->unk_1e = b->unk_0a;
            if (b->unk_20 > b->unk_0c) b->unk_20 = b->unk_0c;
        }
    }
    if (entry->flag_2f_1) result = func_020e6c54(index, entry, result);
    return result;
}

/* Test the default record and twelve area slots, marking the entry on success
 * unless its low +0x2f flag is set. Return zero for any successful test. */
int func_020e7194(int index)
{
    int found = 0;
    Entry *entry = Unk09974c_Unk_099d14(index);
    Area *area;
    int i;
    if (!entry) return 1;
    if (func_020e6ebc(-1, entry) == 0) found = 1;
    area = Unk02e000_GetWorkArea();
    for (i = 0; i < 12; i++) {
        int slot = area->unk_348[i];
        if (slot >= 0 && func_020e6ebc(slot, entry) == 0) found = 1;
    }
    if (found) {
        if (!(entry->unk_2f)) func_02099b10(index, 1);
        return 0;
    }
    return 1;
}

/* Test one record and mark the entry on success unless +0x2f bit zero is set. */
int func_020e7238(int record, int index)
{
    Entry *entry = Unk09974c_Unk_099d14(index);
    int result;
    if (!entry) return 1;
    result = func_020e6ebc(record, entry);
    if (result == 0 && !(entry->unk_2f)) func_02099b10(index, 1);
    return result;
}
