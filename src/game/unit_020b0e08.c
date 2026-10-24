#include "types.h"

/* Borrowed object view: only the packed ID and eligibility flag are established. */
typedef struct CandidateObject {
    u32 id;
    u8 pad_004[638];
    u8 flags_282;
} CandidateObject;

/* Borrowed singleton view; the original scans exactly ten pointer slots. */
typedef struct CandidateManager {
    u8 pad_000[100];
    CandidateObject *objects[10];
} CandidateManager;

/* Stack-only sort record; the comparator reads the first signed word. */
typedef struct Candidate {
    int value;
    u32 id;
    u32 weight;
} Candidate;

extern CandidateManager *Unk044904_Get_data_0215ee98(void);
extern int func_0204abd8(CandidateObject *object, int mode);
extern int func_0204a9ec(CandidateObject *object);
extern int func_02049d80(CandidateObject *object, int mode);
extern u32 func_02050074(u32 lower, u32 upper);
extern int Unk0b0b5c_Unk_0b0d28(const void *a, const void *b);
extern void func_02013c68(void *base, u32 count, u32 size,
                         int (*compare)(const void *, const void *));

/* Select an ID from eligible objects with equal weights; zero accepts any ID class.
 * The manager has ten slots; no candidates returns zero or uses the baseline selector. */
u32 func_020b0e08(u32 filter)
{
    Candidate entries[10];
    CandidateManager *manager = Unk044904_Get_data_0215ee98();
    u32 count;
    int i;
    if (manager == 0) {
        return 0;
    }
    count = 0;
    for (i = 0; i < 10; i++) {
        CandidateObject *object = manager->objects[i];
        u32 kind;
        if (object == 0) continue;
        kind = (object->id >> 16) & 255;
        if (kind == 0) continue;
        if (filter != 0 && filter != kind) continue;
        if (func_0204abd8(object, 0) != 0) continue;
        entries[count].id = object->id;
        entries[count].weight = 100;
        count++;
    }
    if (count != 0) {
        u32 j;
        u32 total = 0;
        u32 k;
        u32 roll;
        for (j = 0; j < count; j++) {
            total += entries[j].weight;
        }
        roll = func_02050074(0, total - 1);
        for (k = 0; k < count; k++) {
            if (roll <= entries[k].weight) {
                goto selected;
            }
            roll -= entries[k].weight;
        }
        k = count - 1;
/* See DEC-008: successful and exhausted scans share the indexed return. */
selected:
        return entries[k].id;
    }
    return 0;
}
/* Rank eligible objects by the mode-zero query and weight the first three 60/30/10 (or 80/20).
 * The manager has ten slots; no candidates returns zero or uses the baseline selector. */
u32 func_020b0f2c(u32 filter)
{
    Candidate entries[10];
    CandidateManager *manager = Unk044904_Get_data_0215ee98();
    u32 count;
    int i;
    if (manager == 0) {
        return 0;
    }
    count = 0;
    for (i = 0; i < 10; i++) {
        CandidateObject *object = manager->objects[i];
        u32 kind;
        if (object == 0) continue;
        kind = (object->id >> 16) & 255;
        if (kind == 0) continue;
        if (filter != 0 && filter != kind) continue;
        if (func_0204a9ec(object) != 0) continue;
        if (((u32)object->flags_282 << 29) >> 31) continue;
        entries[count].id = object->id;
        entries[count].weight = 100;
        entries[count].value = func_02049d80(object, 0);
        count++;
    }
    if (count == 0) return func_020b0e08(filter);
    func_02013c68(entries, count, sizeof(Candidate), Unk0b0b5c_Unk_0b0d28);
    if (count > 3) count = 3;
    {
        u32 j;
        for (j = 0; j < count; j++) {
            if (j == 0) {
                if (count >= 3) entries[j].weight *= 60;
                else entries[j].weight *= 80;
            } else if (j == 1) {
                if (count >= 3) entries[j].weight *= 30;
                else entries[j].weight *= 20;
            } else {
                entries[j].weight *= 10;
            }
            entries[j].weight /= 100;
        }
    }
    if (count != 0) {
        u32 j;
        u32 total = 0;
        u32 k;
        u32 roll;
        for (j = 0; j < count; j++) {
            total += entries[j].weight;
        }
        roll = func_02050074(0, total - 1);
        for (k = 0; k < count; k++) {
            if (roll <= entries[k].weight) {
                goto selected;
            }
            roll -= entries[k].weight;
        }
        k = count - 1;
/* See DEC-008: successful and exhausted scans share the indexed return. */
selected:
        return entries[k].id;
    }
    return 0;
}
/* Select equally among eligible objects with the lowest mode-zero query value.
 * The manager has ten slots; no candidates returns zero or uses the baseline selector. */
u32 func_020b1144(u32 filter)
{
    Candidate entries[10];
    CandidateManager *manager = Unk044904_Get_data_0215ee98();
    u32 count;
    int i;
    if (manager == 0) {
        return 0;
    }
    count = 0;
    for (i = 0; i < 10; i++) {
        CandidateObject *object = manager->objects[i];
        u32 kind;
        if (object == 0) continue;
        kind = (object->id >> 16) & 255;
        if (kind == 0) continue;
        if (filter != 0 && filter != kind) continue;
        if (func_0204abd8(object, 0) != 0) continue;
        if (((u32)object->flags_282 << 29) >> 31) continue;
        if (count != 0) {
            if (entries[0].value < func_02049d80(object, 0)) continue;
            if (entries[0].value > func_02049d80(object, 0)) count = 0;
        }
        entries[count].id = object->id;
        entries[count].weight = 100;
        entries[count].value = func_02049d80(object, 0);
        count++;
    }
    if (count == 0) return func_020b0e08(filter);
    {
        u32 j;
        u32 total = 0;
        u32 k;
        u32 roll;
        for (j = 0; j < count; j++) {
            total += entries[j].weight;
        }
        roll = func_02050074(0, total - 1);
        for (k = 0; k < count; k++) {
            if (roll <= entries[k].weight) {
                goto selected;
            }
            roll -= entries[k].weight;
        }
        k = count - 1;
/* See DEC-008: successful and exhausted scans share the indexed return. */
selected:
        return entries[k].id;
    }
}
