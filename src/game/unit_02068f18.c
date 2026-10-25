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
