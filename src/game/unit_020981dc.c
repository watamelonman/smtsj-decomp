#include "types.h"

/* Borrowed area-record view; only fields accessed by this unit are described. */
typedef struct Unk0981dcArea {
    u8 pad_00[14];
    s8 unk_0e, unk_0f, unk_10, unk_11, unk_12;
    u8 pad_13[35];
    u16 unk_36;
} Unk0981dcArea;

/* Eight-byte entries in resource (1, 0); the first two bytes are signed. */
typedef struct Unk0981dcEntry {
    s8 unk_00, unk_01;
    u8 pad_02[6];
} Unk0981dcEntry;

/* Borrowed record returned by the id lookup; offsets follow the original loads. */
typedef struct Unk0981dcModifier {
    u8 pad_00[34];
    u8 unk_22, unk_23;
    u8 pad_24[2];
    u16 unk_26;
} Unk0981dcModifier;

typedef struct Unk0981dcPair {
    s16 unk_00, unk_02;
} Unk0981dcPair;

extern Unk0981dcArea *Unk096754_GetAreaRecordIf(u32 id);
extern void func_0209786c(void);
extern u32 func_020445d0(int kind, u32 id);
extern Unk0981dcEntry *func_0204fde0(u32 handle);
extern int func_0204fe18(u32 handle);
extern Unk0981dcModifier *func_020cb21c(u32 id);
Unk0981dcEntry *func_020982c0(int id);

/* Return area field +0x36, or zero when the requested area is unavailable. */
u16 Unk0981dc_Unk_0981dc(u32 id)
{
    Unk0981dcArea *area = Unk096754_GetAreaRecordIf(id);
    u16 value;
    if (area == 0) value = 0;
    else value = area->unk_36;
    return value;
}

/* Store a selected byte (selectors 0..4), then notify even for other selectors. */
void Unk0981dc_Unk_0981f4(u32 id, u32 selector, u8 value)
{
    Unk0981dcArea *area = Unk096754_GetAreaRecordIf(id);
    if (area != 0) {
        switch (selector) {
        case 0: area->unk_0e = value; break;
        case 1: area->unk_0f = value; break;
        case 2: area->unk_10 = value; break;
        case 3: area->unk_11 = value; break;
        case 4: area->unk_12 = value; break;
        }
        func_0209786c();
    }
}

/* Read a selected signed byte; absent records and selectors outside 0..4 yield zero. */
s8 Unk0981dc_Unk_098258(u32 id, int selector)
{
    Unk0981dcArea *area = Unk096754_GetAreaRecordIf(id);
    if (area == 0) return 0;
    switch (selector) {
    case 0: return area->unk_0e;
    case 1: return area->unk_0f;
    case 2: return area->unk_10;
    case 3: return area->unk_11;
    case 4: return area->unk_12;
    }
    return 0;
}

/* Find the first signed-byte id in resource (1, 0); return a borrowed entry or null. */
Unk0981dcEntry *func_020982c0(int id)
{
    u32 handle = func_020445d0(1, 0);
    Unk0981dcEntry *entry;
    int count;
    int i;
    if (handle == 0) return 0;
    entry = func_0204fde0(handle);
    count = func_0204fe18(handle);
    for (i = 0; i < count; i++, entry++) {
        if (entry->unk_00 == id) return entry;
    }
    return 0;
}

/* Accept a zero second id, otherwise require its entry byte +1 to exceed the first's.
 * Both nonzero ids must exist in resource (1, 0). */
int Unk0981dc_Unk_098324(int first, int second)
{
    if (second != 0) {
        Unk0981dcEntry *entry = func_020982c0(first);
        if (func_020982c0(second)->unk_01 <= entry->unk_01) return 0;
    }
    return 1;
}

/* Scale two signed halfwords using six optional ids. Type bits 6..10 equal to 10
 * contribute ten times bytes +0x22/+0x23; preserve zero and clamp others to 1..999. */
void func_0209835c(Unk0981dcPair *pair, const u16 *ids)
{
    u32 first = 100;
    u32 second = first;
    int i;
    for (i = 0; i < 6; i++) {
        if (ids[i] != 0) {
            Unk0981dcModifier *record = func_020cb21c(ids[i]);
            if (record != 0 && (((u32)record->unk_26 << 21) >> 27) == 10) {
                first += record->unk_22 * 10;
                second += record->unk_23 * 10;
            }
        }
    }
    {
        int value;
        if (pair->unk_00 == 0) value = 0;
        else {
            value = (pair->unk_00 * first) / 100;
            if (pair->unk_00 == value && first > 100) value++;
            if (value > 999) value = 999;
            else if (value < 1) value = 1;
        }
        pair->unk_00 = value;
        if (pair->unk_02 == 0) value = 0;
        else {
            value = (pair->unk_02 * second) / 100;
            if (pair->unk_02 == value && second > 100) value++;
            if (value > 999) value = 999;
            else if (value < 1) value = 1;
        }
        pair->unk_02 = value;
    }
}
