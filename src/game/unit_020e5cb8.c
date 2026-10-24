#include "types.h"

/* Partial caller-owned selection layout; six IDs precede the record key. */
typedef struct {
    u8 reserved00[0x28];
    u16 entries[6];
    u8 reserved34[2];
    u16 record;
    u8 reserved38;
    u8 category;
    u8 reserved3a;
    u8 selected;
} Selection;

/* Record view retains the original packed threshold field at offset 0x24. */
typedef struct {
    u8 reserved00[6];
    u16 kind;
    u8 reserved08[0x1c];
    u32 reserved24 : 7;
    u32 threshold : 7;
    u32 reservedBits : 18;
} Record;

/* Entry metadata uses byte 3 for weighting and byte 4 bits 2..3 for eligibility. */
typedef struct {
    u8 reserved00[3];
    u8 weight;
    u8 reserved04 : 2;
    u8 enabled : 2;
    u8 reservedBits : 4;
} Entry;

/* Borrowed record-specific exclusion list returned by the table accessor. */
typedef struct {
    u16 reserved00;
    u16 entries[3];
} Exclusions;

extern u32 func_02050074(int low, int high);
extern Record *func_020a1428(u16 record);
extern int Unk02e000_GetRecordUnk1c(u16 record);
extern void *Unk0986ac_Unk_098978(int id);
extern int Unk0986ac_Thunk_02098714(void *entry);
extern int Unk0e651c_Unk_0e666c(int id);
extern int Unk09974c_Unk_0998d8(u16 kind);
extern int Unk02ee5c_GetRecordFlagB(u16 record);
extern const u8 *Unk0e675c_Unk_0e684c(u8 category);
extern int Unk02e000_GetRecordUnk1e(u16 record);
extern int func_020e6a0c(void);
extern Exclusions *func_020e68f0(u16 id);
extern Entry *func_020e6874(u16 id);

/* Trials use record bits 7..13 and field 1c / 20; IDs 0xbb and 0x84
 * adjust the threshold and force success respectively (original call/data use). */
u32 func_020e5cb8(Selection *selection, int trials)
{
    Record *record = func_020a1428(selection->record);
    int value = Unk02e000_GetRecordUnk1c(selection->record);
    int boosted = Unk0986ac_Thunk_02098714(Unk0986ac_Unk_098978(0xbb));
    int forced = Unk0986ac_Thunk_02098714(Unk0986ac_Unk_098978(0x84));
    int i;
    for (i = 0; i < trials; i++) {
        u32 threshold = record->threshold + value / 20;
        if (forced) return 1;
        if (boosted) threshold = threshold * 150 / 100;
        if (func_02050074(1, 99) < threshold) return 1;
    }
    return 0;
}

/* Return success if any of trials draws in [1,99] is below threshold.
 * Nonpositive trial counts return zero without consuming random draws. */
u32 Unk0e5cb8_Unk_0e5d80(int trials, u32 threshold)
{
    int i;
    for (i = 0; i < trials; i++) {
        if (func_02050074(1, 99) < threshold) return 1;
    }
    return 0;
}

/* Flag 0x706 and the record kind gate category-based trials; only the
 * non-flag-B path writes selected, and only on success. */
u32 func_020e5dcc(Selection *selection, int trials)
{
    const u8 *thresholds;
    u32 result;
    if (!Unk0e651c_Unk_0e666c(0x706)) return 0;
    if (Unk09974c_Unk_0998d8(func_020a1428(selection->record)->kind)) return 0;
    if (!Unk02ee5c_GetRecordFlagB(selection->record)) {
        thresholds = Unk0e675c_Unk_0e684c(selection->category);
        result = Unk0e5cb8_Unk_0e5d80(trials,
            Unk02e000_GetRecordUnk1e(selection->record) < 100 ? thresholds[0] : thresholds[1]);
        if (result) selection->selected = 1;
        return result;
    }
    {
        u32 value = func_020e6a0c();
        value = (int)selection->category * (int)value;
        return Unk0e5cb8_Unk_0e5d80(trials, value);
    }
}

/* Select from six entry IDs, excluding the record's three IDs and entries
 * with zero bits 2..3. Weights are 15 minus entry byte 3; empty sets return 0xffff. */
u16 func_020e5e6c(Selection *selection)
{
    u16 candidates[6];
    u16 weights[6];
    Exclusions *excluded = func_020e68f0((u16)(selection->record + 0x19a));
    u8 count = 0;
    int i, j;
    int total;
    u32 draw;
    int index;
    for (i = 0; i < 6; i++) {
        u16 id = selection->entries[i];
        for (j = 0; j < 3; j++) {
            if (id == excluded->entries[j]) break;
        }
        if (j == 3 && func_020e6874(id)->enabled) {
            candidates[count] = selection->entries[i];
            count++;
        }
    }
    if (!count) return 0xffff;
    total = 0;
    for (i = 0; i < count; i++) {
        weights[i] = 15 - func_020e6874(candidates[i])->weight;
        total += weights[i];
    }
    draw = func_02050074(1, total - 1);
    total = 0;
    for (index = 0; index < count; index++) {
        total += weights[index];
        if (draw < total) break;
    }
    return candidates[index];
}
