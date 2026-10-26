/* Sortable records and work-area helpers from unit_02068f18. */
#include "types.h"

/* Orders four-byte records by descending primary byte, ascending category,
 * then ascending ID; evidence: byte +2/+3 and halfword +0 comparisons. */
int Unk068f18_CompareKeyAsc(u8 *a, u8 *b)
{
    int d = b[2] - a[2];
    if (d == 0) {
        d = a[3] - b[3];
    }
    if (d == 0) {
        d = *(u16 *)a - *(u16 *)b;
    }
    return d;
}

/* Reverses CompareKeyAsc, including its ID tie-break; both inputs must
 * contain an aligned halfword followed by two key bytes. */
int Unk068f18_CompareKeyDesc(u8 *a, u8 *b)
{
    int d = a[2] - b[2];
    if (d == 0) {
        d = b[3] - a[3];
    }
    if (d == 0) {
        d = *(u16 *)b - *(u16 *)a;
    }
    return d;
}

/* Partial borrowed work view: six ID slots start at offset 40. */
typedef struct Unk068f18Ids {
    u8 pad_0000[40];
    u16 ids[6];
} Unk068f18Ids;

/* Merges six nonzero source IDs into six destination slots without duplicates;
 * the original stops each search at the first matching or empty slot. */
void Unk068f18_Unk_069888(Unk068f18Ids *p, u16 *src)
{
    int i;
    int j;
    for (i = 0; i < 6; i++) {
        u16 v = src[i];
        if (v == 0) {
            continue;
        }
        for (j = 0; j < 6; j++) {
            if (v == p->ids[j]) {
                break;
            }
            if (p->ids[j] == 0) {
                p->ids[j] = v;
                break;
            }
        }
    }
}

/* Selects the smaller sum after signed-byte conversion of the first sum,
 * converts a selected second sum likewise, then caps the result at 99. */
int Unk068f18_Unk_069afc(int arg0,int arg1,int arg2,int arg3)
{
  int value;
  value = (arg0 + arg2) * 0x1000000 >> 0x18;
  if (arg1 + arg3 < value) {
    value = (arg1 + arg3) * 0x1000000 >> 0x18;
  }
  if (99 < value) {
    value = 99;
  }
  return value;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
/* Returns the shared borrowed work storage used by the slot-index table. */
u8 *Unk02e000_GetWorkArea(void);

/* Searches the active signed-byte slot table at work +0x348 for a record
 * whose halfword +54 equals key; returns its slot or -1 when absent. */
int Unk068f18_Unk_06a1a8(u8 *p, int key)
{
    int r;
    u8 *w;
    s8 i;
    if (p[178] == 0) {
        return -1;
    }
    r = -1;
    w = (u8 *)Unk02e000_GetWorkArea();
    for (i = 0; i < p[178]; i++) {
        s8 k = FIELD(s8, w + i + 0x300, 72);
        if (k >= 0 && key == FIELD(u16, FIELD(u8 *, p + k * 4, 288), 54)) {
            r = k;
            break;
        }
    }
    return r;
}

/* Fills size bytes of caller-owned destination storage. */
void func_02008848(void *dst, int value, u32 size);
/* Resolves the caller-owned link coordinate pair in place. */
void CampStatus_GetLinkUnk14(int *link);
/* Prepares the rendering state required before resource submission. */
void func_02057df8(void);
/* Submits a resource with coordinates and floating-point scale. */
void func_02058e9c(int screen, u32 resource, int x, int y, float scale, int a, int b);

/* Four-byte sortable entry; ID is halfword aligned. */
typedef struct Unk068f18Record {
    u16 id;
    u8 key;
    u8 category;
} Unk068f18Record;

/* Builds six sortable records; +0xa8 supplies six-byte entries and +0xa0
 * supplies the fifteen category keys, as evidenced by the original loads. */
void func_0206902c(u8 *work, Unk068f18Record *records, u16 *source)
{
    int i;
    func_02008848(records, 0, 24);
    for (i = 0; i < 6; i++) {
        if (source[i + 3] != 0) {
            u8 j;
            records[i].id = source[i + 3];
            records[i].key = FIELD(u8 *, work, 168)[source[i + 3] * 6 + 3];
            for (j = 0; j < 15; j++) {
                if (FIELD(u8 *, work, 160)[j] == FIELD(u8 *, work, 168)[source[i + 3] * 6 + 2]) {
                    records[i].category = j;
                }
            }
        }
    }
}

/* Returns the 60-tick triangular alpha used by unit_02090e60 draw calls;
 * callers supply the shared ticker, and each half-cycle spans 30 ticks. */
float func_02069ec8(s32 phase)
{
    float result = 1.0f;
    int tick = phase % 60;
    if (tick < 30) {
        result -= 0.025f * tick;
    } else {
        result = 0.25f + 0.025f * (tick - 30);
    }
    return result;
}

/* Resolves the link at +1000, adjusts its coordinates, and submits resource
 * 0x1801. Evidence: CampStatus_GetLinkUnk14 and func_02058e9c calls. */
void func_0206a124(u8 *work)
{
    CampStatus_GetLinkUnk14(&FIELD(int, work, 1000));
    if (FIELD(int, work, 1000) >= 145 && FIELD(int, work, 1000) <= 152) {
        FIELD(int, work, 1004) += 8;
    }
    if (FIELD(int, work, 1000) > 256 || FIELD(int, work, 1000) <= 0) {
        FIELD(int, work, 1004) = 1;
    }
    func_02057df8();
    func_02058e9c(1, 0x1801, FIELD(int, work, 1000), FIELD(int, work, 1004), 1.0f, 0, 10);
}

/* Borrowed layouts expose only fields established by ARM loads/stores. */
typedef struct Unk068f18Metadata {
    u16 unk_00;
    u8 category;
    u8 key;
    u8 flags : 2;
    u8 flagsMiddle : 2;
    u8 flagsUpper : 4;
    u8 unk_05;
} Unk068f18Metadata;
/* Borrowed 60-byte unit prefix; six IDs precede its own ID and level. */
typedef struct Unk068f18Unit {
    u8 pad_00[40];
    u16 ids[6];
    u16 unk_34;
    u16 id;
    u8 level;
    u8 pad_39[3];
} Unk068f18Unit;
/* Eight-byte bonus row: ID followed by byte-sized increments. */
typedef struct Unk068f18Bonus {
    u16 id;
    u8 values[6];
} Unk068f18Bonus;
/* Borrowed metadata prefix; the mask controls category eligibility. */
typedef struct Unk068f18Info {
    u16 id;
    u8 unk_02;
    u8 level;
    u8 pad_04[4];
    u16 mask;
    u8 bonus;
} Unk068f18Info;
/* Caller-owned work prefix. Pointers borrow provider storage; thirteen
 * pointer slots fit before the observed scroll fields, not a capacity claim. */
typedef struct Unk068f18Work {
    u8 pad_00[132];
    Unk068f18Info *info;
    u8 pad_88[20];
    Unk068f18Bonus *bonuses;
    u8 *categories;
    u8 pad_a4[4];
    Unk068f18Metadata *metadata;
    u8 pad_ac[20];
    u16 bonusCount;
    u8 pad_c2[74];
    u32 *widget;
    u8 pad_110[16];
    Unk068f18Unit *units[13];
    u16 unk_154;
    s16 scroll;
    s16 extent;
    u8 pad_15a[598];
    void *resource;
    u8 pad_3b4[68];
    int allowed;
    u16 unk_3fc;
    u16 selected;
} Unk068f18Work;
/* Signed current/base byte groups are separated by twenty bytes. */
typedef struct Unk068f18Stats {
    u8 pad_00[4];
    s8 current[5];
    u8 pad_09[15];
    s8 base[5];
} Unk068f18Stats;

/* Builds six records unless source ID equals excluded; unfilled bytes stay
 * 255. Metadata stride six and fifteen category comparisons are ARM evidence. */
void func_02068f78(Unk068f18Work *work, Unk068f18Record *records, Unk068f18Unit *source, int excluded)
{
    int i;
    func_02008848(records, 255, 24);
    if (excluded == source->id) {
        return;
    }
    for (i = 0; i < 6; i++) {
        if (source->ids[i] != 0) {
            u8 j;
            records[i].id = source->ids[i];
            records[i].key = work->metadata[source->ids[i]].key;
            for (j = 0; j < 15; j++) {
                if (work->categories[j] == work->metadata[source->ids[i]].category) {
                    records[i].category = j;
                }
            }
        }
    }
}

/* Applies the matching eight-byte bonus row to five signed stats. The
 * original helper caps each updated stat at base plus info byte +10 and 99. */
void func_02069a00(Unk068f18Work *work, Unk068f18Stats *stats, int id)
{
    int i;
    work->selected = id;
    for (i = 0; i < work->bonusCount; i++) {
        if (id == work->bonuses[i].id) {
            stats->current[0] = Unk068f18_Unk_069afc(stats->current[0], stats->base[0], work->bonuses[i].values[0], work->info->bonus);
            stats->current[4] = Unk068f18_Unk_069afc(stats->current[4], stats->base[4], work->bonuses[i].values[1], work->info->bonus);
            stats->current[1] = Unk068f18_Unk_069afc(stats->current[1], stats->base[1], work->bonuses[i].values[2], work->info->bonus);
            stats->current[2] = Unk068f18_Unk_069afc(stats->current[2], stats->base[2], work->bonuses[i].values[3], work->info->bonus);
            stats->current[3] = Unk068f18_Unk_069afc(stats->current[3], stats->base[3], work->bonuses[i].values[4], work->info->bonus);
            return;
        }
    }
}

/* Returns borrowed per-ID metadata; fields used here follow ROM accesses. */
Unk068f18Info *func_020a1428(int id);
/* Sorts count records of stride bytes using the supplied comparator. */
void func_02013c68(void *records, int count, int stride, int (*compare)(u8 *, u8 *));

/* Selects source IDs allowed by target metadata and absent from target's six
 * slots, sorts six temporary records, and returns the selected count. */
u16 func_0206970c(Unk068f18Work *work, Unk068f18Unit *target, Unk068f18Unit *source, u16 *output)
{
    Unk068f18Info *info = func_020a1428(target->id);
    u16 count = 0;
    Unk068f18Record records[6];
    int i;
    func_02008848(records, 0, 24);
    for (i = 0; i < 6; i++) {
        int id = source->ids[i];
        if (id != 0) {
            if (work->metadata[id].flags != 0 &&
                (((int)(((u32)info->mask << 16) >> 17)) >> (u16)(work->metadata[id].category - 1) & 1) != 0) {
                int j;
                for (j = 0; j < 6; j++) {
                    if (target->ids[j] == source->ids[i]) break;
                }
                if (j == 6) {
                    u8 k;
                    records[count].id = id;
                    records[count].key = work->metadata[source->ids[i]].key;
                    for (k = 0; k < 15; k++) {
                        if (work->categories[k] == work->metadata[source->ids[i]].category) {
                            records[count].category = k;
                        }
                    }
                    count++;
                }
            }
        }
    }
    func_02013c68(records, 6, 4, Unk068f18_CompareKeyAsc);
    for (i = 0; i < 6; i++) output[i] = records[i].id;
    return count;
}

/* Queries a global feature bit used to bypass the level restriction. */
int Unk0e651c_Unk_0e666c(int flag);
/* Borrows the global state whose byte +110 is the current level limit. */
u8 *Unk02e000_Thunk_0202e788(void);
/* Tests an active unit index; zero prevents selection here. */
int Unk096754_Unk_096ab0(int index);

typedef struct Unk068f18Shared {
    u8 pad_00[840];
    s8 slots[15];
    u8 count;
} Unk068f18Shared;

/* Checks the candidate level, active-unit restriction, and duplicate ID rule.
 * Writes +1016 for the level result; IDs contains count halfwords. */
int func_020698e0(Unk068f18Work *work, u16 *ids, int count, int id)
{
    int i;
    int j;
    Unk068f18Shared *shared = (Unk068f18Shared *)Unk02e000_GetWorkArea();
    Unk068f18Info *info = func_020a1428(id);

    if (Unk0e651c_Unk_0e666c(1024) == 0) {
        if (info->level > Unk02e000_Thunk_0202e788()[110]) {
            work->allowed = 0;
            return 0;
        }
    }
    work->allowed = 1;
    for (i = 0; i < count; i++) {

        for (j = 0; j < shared->count; j++) {
            int slot = shared->slots[j];
            if (ids[i] == work->units[slot]->id) {
                if (Unk096754_Unk_096ab0(slot) == 0) return 0;
                break;
            }
        }
    }
    if (Unk068f18_Unk_06a1a8((u8 *)work, id) >= 0) {
        for (i = 0; i < count; i++) {
            if (id == ids[i]) return 1;
        }
        return 0;
    }
    return 1;
}

/* Selects the rendering state used by the scrollbar and overlay. */
void func_02057fd8(void);
/* Submits an indexed resource with scale, depth, and draw mode. */
void func_0205dee8(int screen, void *resource, int index, int x, int y,
    float scaleX, float scaleY, int depth, float alpha, int mode);
/* Draws a solid rectangle; coordinates and dimensions use integer pixels. */
void func_02058f10(int screen, int color, int x, int y, int width, int height, int mode);
/* Submits the borrowed widget's existing contents. */
void func_02067c88(u32 *widget);

/* Draws resource indices 84..88, twelve alternating rows, and a proportional
 * scroll indicator. Evidence: resource +944 and extent/scroll +344/+342. */
void func_02069f50(Unk068f18Work *work)
{
    int i;
    u32 extent;
    u32 height;
    u32 offset;
    func_02057fd8();
    func_02057df8();
    func_0205dee8(2, work->resource, 86, 0, 0, 1.0f, 1.0f, 0, 1.0f, 2);
    func_02057df8();
    for (i = 0; i < 12; i++) {
        if (i % 2 == 0) {
            func_0205dee8(2, work->resource, 87, 0, (i / 2) * 22, 1.0f, 1.0f, 0, 1.0f, 2);
        } else {
            func_0205dee8(2, work->resource, 88, 0, (i / 2) * 22, 1.0f, 1.0f, 0, 1.0f, 2);
        }
    }
    func_0205dee8(2, work->resource, 84, 0, 0, 1.0f, 1.0f, 0, 1.0f, 2);
    func_02057fd8();
    extent = work->extent;
    if (extent < 24) extent = 24;
    height = ((0x18000 / extent) * 123) >> 12;
    offset = (((work->scroll / 2) << 12) / (extent / 2 - 12));
    func_02058f10(2, 0x1500, 0, ((123 - height) * offset) >> 12, 2, height, 3);
    func_02057fd8();
    func_0205dee8(2, work->resource, 85, 0, 0, 1.0f, 1.0f, 0, 1.0f, 10);
    func_02067c88(work->widget);
}

/* Selects RNG stream and maximum; the wrapper supplies a zero minimum. */
int func_02050074(int stream, int maximum);
/* Initializes size bytes of destination to the supplied halfword value. */
void func_02008644(int value, void *destination, u32 size);

/* Randomly chooses distinct flagged IDs from a four-ID source row, merges
 * them with existing slots, and randomly removes overflow beyond six slots.
 * Scratch arrays have count and count+6 halfwords, matching the ROM's VLAs.
 * Source supplies five halfwords (the first is ignored); metadata must cover
 * every nonzero ID. Existing IDs are a contiguous nonzero prefix. */
void func_02069b24(Unk068f18Work *work, Unk068f18Unit *target, u16 *source, u8 count)
{
    int existing = 0;
    int duplicates;
    int sourceCount = 0;
    int eligible = 0;
    u16 chosen[count];
    int capacity = count + 6;
    u16 merged[capacity];
    u8 indices[15];
    u8 *next;
    int i;
    int j;
    int picked;
    int total;
    int mergeIndex;
    int outputIndex;
    int used;
    func_02008644(0, chosen, count * 2);
    func_02008644(0, merged, capacity * 2);
    func_02008848(indices, 0, 15);
    func_020a1428(target->id);
    for (; existing < 6; existing++) {
        if (target->ids[existing] == 0) break;
    }
    for (; sourceCount < 4; sourceCount++) {
        if (source[sourceCount + 1] == 0) break;
    }
    next = indices;
    for (i = 0; i < 4; i++) {
        int id = source[i + 1];
        if (id != 0 && work->metadata[id].flagsMiddle == 1) {
            for (j = 0; j < existing; j++) {
                if (target->ids[j] == source[i + 1]) break;
            }
            if (j < existing) {
                sourceCount--;
                continue;
            }
            *next++ = i;
            eligible++;
        }
    }
    duplicates = 0;
    for (i = 0; i < eligible; i++) {
        for (j = i + 1; j < eligible; j++) {
            if (source[indices[i] + 1] == source[indices[j] + 1]) break;
        }
        if (j < eligible) duplicates++;
    }
    total = sourceCount - duplicates;
    if (eligible == 0) return;
    if (count > total) count = total;
    picked = 0;
    eligible--;
    while (picked < count) {
        int index = func_02050074(1, eligible);
        for (j = 0; j < count; j++) {
            if (chosen[j] == source[indices[index] + 1]) break;
        }
        if (j == count) chosen[picked++] = source[indices[index] + 1];
    }
    total = existing + count;
    mergeIndex = 0;
    used = 0;
    for (; mergeIndex < total; mergeIndex++) {
        if (mergeIndex < existing) merged[used++] = target->ids[mergeIndex];
        else {
            int id = chosen[mergeIndex - existing];
            if (id != 0) merged[used++] = id;
        }
    }
    if (used > 6) {
        int excess = used - 6;
        int removed = 0;
        while (removed < excess) {
            int index = func_02050074(1, used - 1);
            if (merged[index] != 0) {
                merged[index] = 0;
                removed++;
            }
        }
    }
    outputIndex = 0;
    used = 0;
    for (; outputIndex < total; outputIndex++) {
        int id = merged[outputIndex];
        if (id != 0) target->ids[used++] = id;
    }
}

/* Copies size bytes between caller-owned nonoverlapping records. */
void func_02008904(const void *source, void *destination, u32 size);
/* Copies halfword-aligned data; size is measured in bytes. */
void func_0200866c(const void *source, void *destination, u32 size);
/* Allocates owned scratch storage, released with func_02053000. */
void *func_02052fe0(u32 size);
/* Releases storage allocated by func_02052fe0. */
void func_02053000(void *storage);
/* Queries whether the metadata default record may supply candidate IDs. */
int Unk02e000_GetRecordFlag1(int id);

/* Eighteen-byte intermediate row: source identity, count, level, six IDs.
 * These offsets follow the stores before calls to 0206970c and 0206902c. */
typedef struct Unk068f18Candidates {
    u16 id;
    u16 count;
    u8 level;
    u8 pad_05;
    u16 ids[6];
} Unk068f18Candidates;

/* Combines two six-ID candidate lists into target's first five slots.
 * ARM calls establish ascending selection and a single descending fallback;
 * the optional ID changes only the temporary target used for filtering. */
void func_020690d0(Unk068f18Work *work, Unk068f18Unit *target,
    Unk068f18Unit *first, Unk068f18Unit *second, u16 id)
{
    Unk068f18Candidates candidates[2];
    Unk068f18Record records[12];
    Unk068f18Unit temporary;
    func_02008848(candidates, 0, 36);
    candidates[0].id = first->id;
    candidates[1].id = second->id;
    candidates[0].level = first->level;
    candidates[1].level = second->level;
    func_02008904(target, &temporary, 60);
    if (id != 0) temporary.id = id;
    candidates[0].count = func_0206970c(work, &temporary, first, candidates[0].ids);
    candidates[1].count = func_0206970c(work, &temporary, second, candidates[1].ids);
    if (candidates[0].count == 0 && candidates[1].count == 0) {
        func_02068f78(work, records, first, target->id);
        func_02068f78(work, records + 6, second, target->id);
        func_02013c68(records, 12, 4, Unk068f18_CompareKeyDesc);
        int slot = 0;
        int j;
        int candidate = 0;
        while (slot < 5) {
            if (target->ids[slot] == 0 && records[candidate].id != 0 && records[candidate].id != 65535) {
                for (j = 0; j < slot; j++) {
                    if (target->ids[j] == records[candidate].id || work->metadata[records[candidate].id].flags == 0) break;
                }
                if (j == slot) {
                    target->ids[slot] = records[candidate].id;
                    return;
                }
                candidate++;
            } else slot++;
        }
    } else {
        func_0206902c((u8 *)work, records, (u16 *)&candidates[0]);
        func_0206902c((u8 *)work, records + 6, (u16 *)&candidates[1]);
        func_02013c68(records, 12, 4, Unk068f18_CompareKeyAsc);
        int slot = 0;
        int j;
        int candidate = 0;
        while (slot < 5) {
            if (target->ids[slot] == 0 && records[candidate].id != 0) {
                for (j = 0; j < slot; j++) {
                    if (target->ids[j] == records[candidate].id) break;
                }
                if (j == slot) target->ids[slot++] = records[candidate].id;
                candidate++;
            } else slot++;
        }
    }
}

/* Borrowed 28-byte row; source IDs start at halfword +2. */
typedef struct Unk068f18Row {
    u16 unk_00;
    u16 ids[13];
} Unk068f18Row;

/* Builds candidates for the selected 28-byte row at work +148, using active
 * units or metadata defaults (+46), then fills the target's first five slots.
 * Scratch ownership ends here on both selection paths. Work +851 is the
 * signed source count, as established by the original signed-byte loads. */
void func_02069324(Unk068f18Work *work, Unk068f18Unit *target, int row)
{
    /* Declaring the first loop index before the allocated pointers preserves
     * the original register split between the record base and cursor. */
    int i;
    Unk068f18Candidates *candidates = func_02052fe0(FIELD(s8, work, 851) * 18);
    Unk068f18Record *records = func_02052fe0(FIELD(s8, work, 851) * 24);
    Unk068f18Unit temporary;
    int count;
    func_02008848(candidates, 0, FIELD(s8, work, 851) * 18);
    func_02008848(&temporary, 0, 60);
    for (i = 0; i < FIELD(s8, work, 851); i++) {
        if (((Unk068f18Row *)FIELD(void *, work, 148))[row].ids[i] != 0) {
            int index = Unk068f18_Unk_06a1a8((u8 *)work, ((Unk068f18Row *)FIELD(void *, work, 148))[row].ids[i]);
            Unk068f18Info *info = func_020a1428(((Unk068f18Row *)FIELD(void *, work, 148))[row].ids[i]);
            if (index >= 0) {
                candidates[i].id = work->units[index]->id;
                candidates[i].level = work->units[index]->level;
                candidates[i].count = func_0206970c(work, target, work->units[index], candidates[i].ids);
            } else if (Unk02e000_GetRecordFlag1(info->id) != 0) {
                candidates[i].id = info->id;
                candidates[i].level = info->level;
                func_0200866c((u8 *)info + 46, temporary.ids, 12);
                candidates[i].count = func_0206970c(work, target, &temporary, candidates[i].ids);
            }
        }
    }
    count = 0;
    for (i = 0; i < FIELD(s8, work, 851); i++) {
        if (candidates[i].count != 0) count++;
    }
    if (count <= 0) {
        for (i = 0; i < FIELD(s8, work, 851); i++) {
            if (((Unk068f18Row *)FIELD(void *, work, 148))[row].ids[i] != 0) {
                int index = Unk068f18_Unk_06a1a8((u8 *)work, ((Unk068f18Row *)FIELD(void *, work, 148))[row].ids[i]);
                if (index >= 0) func_02068f78(work, records + i * 6, work->units[index], target->id);
            }
        }
        func_02013c68(records, FIELD(s8, work, 851) * 6, 4, Unk068f18_CompareKeyDesc);
        int slot = 0;
        int j;
        int candidate = 0;
        while (slot < 5) {
            if (target->ids[slot] == 0 && records[candidate].id != 0 && records[candidate].id != 65535) {
                for (j = 0; j < slot; j++) {
                    if (target->ids[j] == records[candidate].id || work->metadata[records[candidate].id].flags == 0) break;
                }
                if (j == slot) {
                    target->ids[slot] = records[candidate].id;
                    goto cleanup;
                }
                candidate++;
            } else slot++;
        }
    } else {
        func_02008848(records, 0, FIELD(s8, work, 851) * 24);
        /* Separate index keeps the record offset in a register while the
         * candidate cursor advances as a pointer, matching the original. */
        int k;
        for (k = 0; k < FIELD(s8, work, 851); k++) {
            func_0206902c((u8 *)work, records + k * 6, (u16 *)&candidates[k]);
        }
        func_02013c68(records, FIELD(s8, work, 851) * 6, 4, Unk068f18_CompareKeyAsc);
        int slot = 0;
        int j;
        int candidate = 0;
        while (slot < 5) {
            if (target->ids[slot] == 0 && records[candidate].id != 0) {
                for (j = 0; j < slot; j++) {
                    if (target->ids[j] == records[candidate].id) break;
                }
                if (j == slot) target->ids[slot++] = records[candidate].id;
                candidate++;
            } else slot++;
        }
    }
cleanup:
    func_02053000(records);
    func_02053000(candidates);
}
