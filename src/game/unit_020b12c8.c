#include "types.h"

/* Only the fields accessed by this unit are known. */
typedef struct Unit12c8 {
    u32 id;
    u8 pad_004[0x1d4];
    u16 unk_1d8;
} Unit12c8;

/* Borrowed work-area view: the slot array starts at 0x64 and contains ten pointers. */
typedef struct Work12c8 {
    u8 pad_000[0x64];
    Unit12c8 *units[10];
} Work12c8;

/* Sort records keep the query result, returned ID and selection weight together. */
typedef struct Candidate12c8 {
    int score;
    u32 id;
    u32 weight;
} Candidate12c8;

extern Work12c8 *Unk044904_Get_data_0215ee98(void);
extern int func_0204abd8(Unit12c8 *unit, int mode);
extern int func_02049d80(Unit12c8 *unit, int mode);
extern void func_02013c68(void *base, u32 count, u32 size, int (*compare)(int *, int *));
extern int Unk0b0b5c_Unk_0b0d28(int *a, int *b);
extern int Unk0b0b5c_Unk_0b0d38(int *a, int *b);
extern u32 func_02050074(int low, int high);

/* Filter the ten unit slots, sort by the selected query, and choose among tied
 * leading scores using their weights. The shared work area must exist; kind zero
 * accepts all ID categories, and mode is forwarded to the query unchanged.
 * Returns zero when no unit qualifies. The original inclusive weight test is kept. */
u32 func_020b12c8(int kind, int mode, int descending, int allowZero, u32 excluded)
{
    Candidate12c8 candidates[10];
    u32 count = 0;
    int i;
    Unit12c8 *unit;
    Candidate12c8 *out = candidates;
    u32 tied;
    int score;
    u32 roll;
    for (i = 0; i < 10; i++) {
        unit = Unk044904_Get_data_0215ee98()->units[i];
        if (unit == 0) continue;
        if (func_0204abd8(unit, 0) != 0) continue;
        if (unit->id == excluded) continue;
        if (!allowZero && unit->unk_1d8 == 0) continue;
        if (kind != 0 && kind != ((unit->id >> 16) & 255)) continue;
        out->score = func_02049d80(unit, mode);
        out->id = unit->id;
        count++;
        out->weight = 10;
        out++;
    }
    if (count != 0) {
        if (descending) func_02013c68(candidates, count, 12, Unk0b0b5c_Unk_0b0d28);
        else func_02013c68(candidates, count, 12, Unk0b0b5c_Unk_0b0d38);
        tied = 1;
        score = candidates[0].score;
        for (u32 j = 1; j < count; j++) {
            if (score != candidates[j].score) break;
            tied++;
        }
        u32 k;
        u32 total = 0;
        for (k = 0; k < tied; k++) total += candidates[k].weight;
        roll = func_02050074(0, total - 1);
        u32 j;
        for (j = 0; j < tied; j++) {
            if (roll <= candidates[j].weight) goto selected;
            roll -= candidates[j].weight;
        }
        j = tied - 1;
selected:
        return candidates[j].id;
    }
    return 0;
}

