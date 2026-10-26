/* Record-bank and grid helpers matched against the original ARM code. */
#include "types.h"


#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_02008848(void *destination, int value, u32 size);
/* The +0x0c occupancy load in the original selects the first unused 16-byte record. */
int Unk0a6174_FindFree0c(u8 *p)
{
    int j;
    for (j = 0; j < 16; j++) {
        if (((u8 (*)[16])p)[j][12] == 0) {
            return j;
        }
    }
    return -1;
}

/* The +0x10d occupancy load scans the second bank of sixteen records. */
int Unk0a6174_FindFree10d(u8 *p)
{
    int j;
    for (j = 0; j < 16; j++) {
        if (((u8 (*)[16])p)[j][269] == 0) {
            return j;
        }
    }
    return -1;
}

/* Four-byte weighted entries; the selection routine consumes exactly eight. */
typedef struct Unk0a6174Slot {
    u8 pad_00[2];
    u8 weight;
    u8 pad_03;
} Unk0a6174Slot;
int func_02050074(int lower, int upper);

/* Select an entry using the eight byte weights; zero total weight returns null. */
Unk0a6174Slot *Unk0a6174_Unk_0a6548(Unk0a6174Slot *p)
{
    u32 sum = 0;
    u8 acc;
    u32 r;
    int i;
    for (i = 0; i < 8; i++) {
        sum += p[i].weight;
    }
    if ((s32)sum <= 0) {
        return 0;
    }
    acc = 0;
    r = (u32)func_02050074(1, 65535) % sum;
    for (i = 0; i < 8; i++) {
        acc += p[i].weight;
        if (r < acc) {
            return &p[i];
        }
    }
    return 0;
}

/* Original clear calls establish buffer sizes 0xe14 and 0x200; both must exist. */
void Unk0a6174_ClearBuffers(u8 *a, u8 *b)
{
    if (a == 0 || b == 0) {
        return;
    }
    func_02008848(a, 0, 0xe14);
    func_02008848(b, 0, 512);
}

/* Original shifted add computes an unchecked 16-byte record address. */
int Unk0a6174_Unk_0a6aac(int arg0,int arg1)
{
  return arg0 + arg1 * 0x10;
}

/* Original +0x100 and shifted add address the second record bank. */
int Unk0a6174_Unk_0a6ab4(int arg0,int arg1)
{
  return arg0 + 0x100 + arg1 * 0x10;
}

int Unk02f2a8_GridIndex45(u32 x, u32 y);
/* Original GridIndex45 call indexes two-byte cells; a null base returns zero. */
int Unk0a6174_Unk_0a6a88(int arg0,u32 arg1,u32 arg2)
{
  int value;
  if (arg0 != 0) {
    value = Unk02f2a8_GridIndex45(arg1,arg2);
    return arg0 + value * 2;
  }
  return 0;
}



/* Original stores at +0..+0xd fill a free first-bank record; index must be 0..15.
 * The occupancy byte at +0xc rejects an already occupied record without mutation. */
int func_020a61a0(u8 *base, u32 value, u32 a, s32 b,
                  u8 c, u8 d, s8 e, s8 f, int g, int index)
{
    u8 *record = base + index * 16;
    if (record[12] != 0) {
        return 0;
    }
    record[12] = 1;
    FIELD(u32, record, 0) = value;
    FIELD(u16, record, 4) = a;
    FIELD(u16, record, 6) = b;
    record[8] = c;
    record[9] = d;
    record[10] = e;
    record[11] = f;
    record[13] = g;
    return 1;
}


int Unk02f2a8_IsInGrid45x40(u32 x, u32 y);
int Unk094fe0_Call_020950b4(int id);

/* Original grid bounds call and signed occupancy byte reject invalid/used cells. */
int func_020a6280(u8 *grid, u32 x, u32 y, s8 kind, u8 index)
{
    u8 *cell;
    if (grid == 0) return 0;
    if (!Unk02f2a8_IsInGrid45x40(x, y)) return 0;
    cell = grid + Unk02f2a8_GridIndex45(x, y) * 2;
    if (*(s8 *)cell != 0) return 0;
    cell[0] = kind;
    cell[1] = index;
    return 1;
}

/* Eight four-byte entries use a nonzero halfword key and byte weight at +3. */
typedef struct Unk0a6174KeySlot {
    u16 key;
    u8 other;
    u8 weight;
} Unk0a6174KeySlot;

/* Original +0/+3 loads stop at the first zero key (at most eight entries).
 * The caller owns the entries; the cumulative byte weight wraps modulo 256. */
Unk0a6174KeySlot *func_020a63cc(Unk0a6174KeySlot *p)
{
    u32 sum = 0;
    u8 acc;
    u32 r;
    int i;
    for (i = 0; i < 8; i++) {
        if (p[i].key == 0) break;
        sum += p[i].weight;
    }
    if ((s32)sum <= 0) return 0;
    acc = 0;
    r = (u32)func_02050074(1, 65535) % sum;
    for (i = 0; i < 8; i++) {
        if (p[i].key == 0) break;
        acc += p[i].weight;
        if (r < acc) return &p[i];
    }
    return 0;
}

/* Original signed IDs at +12/+16 enable boolean provider checks when nonnegative. */
int func_020a6848(u8 *p)
{
    int result = 1;
    int expected;
    if (FIELD(s16, p, 12) > -1) {
        expected = FIELD(u16, p, 14) != 0;
        if (expected != Unk094fe0_Call_020950b4(FIELD(s16, p, 12))) result = 0;
    }
    if (FIELD(s16, p, 16) > -1) {
        expected = FIELD(u16, p, 18) != 0;
        if (expected != Unk094fe0_Call_020950b4(FIELD(s16, p, 16))) result = 0;
    }
    return result;
}

/* Original +16/+20 IDs gate checks; the stored result is normalized twice. */
int func_020a68b4(u8 *p)
{
    int result = 1;
    int expected;
    if (FIELD(s16, p, 16) > -1) {
        expected = FIELD(u16, p, 18) != 0;
        if (expected != Unk094fe0_Call_020950b4(FIELD(s16, p, 16))) result = 0;
    }
    if (FIELD(s16, p, 20) > -1) {
        expected = FIELD(u16, p, 22) != 0;
        if (expected != Unk094fe0_Call_020950b4(FIELD(s16, p, 20))) result = 0;
    }
    {
        u32 normalized = 0;
        if (result) normalized = 1;
        return normalized != 0;
    }
}

/* Original checks require at least one enabled ID as well as both comparisons. */
int func_020a6934(u8 *p)
{
    int enabled;
    int result;
    int expected;
    expected = 0;
    enabled = 0;
    result = 1;
    if (FIELD(s16, p, 16) > -1) {
        enabled = 1;
        if (FIELD(u16, p, 18) != 0) expected = 1;
        if (expected != Unk094fe0_Call_020950b4(FIELD(s16, p, 16))) result = 0;
    }
    if (FIELD(s16, p, 20) > -1) {
        enabled = 1;
        expected = FIELD(u16, p, 22) != 0;
        if (expected != Unk094fe0_Call_020950b4(FIELD(s16, p, 20))) result = 0;
    }
    {
        u32 normalized = 0;
        u32 present = 0;
        if (enabled) present = 1;
        if (present && result) normalized = 1;
        return normalized != 0;
    }
}

/* Original kind byte selects a 16-byte bank record to clear before clearing the cell.
 * Coordinates and the cell's bank index must be valid; buffers are borrowed. */
void func_020a6a08(u8 *grid, u8 *records, u32 x, u32 y)
{
    u8 *cell;
    if (grid == 0) return;
    cell = (u8 *)Unk0a6174_Unk_0a6a88((int)grid, x, y);
    switch (*(s8 *)cell) {
    case 1:
        func_02008848((void *)Unk0a6174_Unk_0a6aac((int)records, cell[1]), 0, 16);
        break;
    case 2:
        func_02008848((void *)Unk0a6174_Unk_0a6ab4((int)records, cell[1]), 0, 16);
        break;
    }
    func_02008848(cell, 0, 2);
}

/* Original occupancy/coordinate loads rebuild the grid from two banks of 16 records.
 * The caller provides a writable 0xe14-byte grid and a readable 0x200-byte bank. */
void func_020a7ca4(u8 *grid, u8 *records)
{
    int i;
    u8 *record;
    func_02008848(grid, 0, 0xe14);
    record = records;
    for (i = 0; i < 16; i++, record += 16) {
        if (record[12] != 0) func_020a6280(grid, record[10], record[11], 1, (u8)i);
    }
    {
        int j;
        u8 *second = records + 256;
        for (j = 0; j < 16; j++, second += 16) {
            if (second[13] != 0) func_020a6280(grid, second[11], second[12], 2, (u8)j);
        }
    }
}

/* Original +0x14/+0x16/+0x19/+0x1d byte tables select a one-based outcome.
 * Caller supplies at least 34 bytes; accumulation wraps at 256. */
u8 func_020a62ec(u8 *p, u32 count)
{
    u8 *weights;
    u32 sum;
    u8 i;
    u8 acc;
    u32 r;
    if (count > 5) count = 1;
    if (count <= 1) goto fallback;
    weights = p + 20;
    switch (count) {
    case 2: weights = p + 20; break;
    case 3: weights = p + 22; break;
    case 4: weights = p + 25; break;
    case 5: weights = p + 29; break;
    }
    sum = 0;
    for (i = 0; i < count; i++) sum += weights[i];
    if ((s32)sum <= 0) return 1;
    acc = 0;
    r = (u32)func_02050074(1, 65535) % sum;
    for (i = 0; i < count; i++) {
        acc += weights[i];
        if (r < acc) return (u8)(i + 1);
    }
fallback:
    return 1;
}

/* Original +0x14/+0x16/+0x19/+0x1d byte tables select a one-based outcome.
 * Caller supplies at least 34 bytes; accumulation wraps at 256. */
u8 func_020a6468(u8 *p, u32 count)
{
    u8 *weights;
    u32 sum;
    u8 i;
    u8 acc;
    u32 r;
    if (count > 5) count = 1;
    if (count <= 1) goto fallback;
    weights = p + 20;
    switch (count) {
    case 2: weights = p + 20; break;
    case 3: weights = p + 22; break;
    case 4: weights = p + 25; break;
    case 5: weights = p + 29; break;
    }
    sum = 0;
    for (i = 0; i < count; i++) sum += weights[i];
    if ((s32)sum <= 0) return 1;
    acc = 0;
    r = (u32)func_02050074(1, 65535) % sum;
    for (i = 0; i < count; i++) {
        acc += weights[i];
        if (r < acc) return (u8)(i + 1);
    }
fallback:
    return 1;
}

void func_0204c780(u32 x, u32 y);
void func_0204c698(int kind, u32 x, u32 y);
/* Original +8 provider table uses 84-byte entries and updates first-bank +13.
 * Both buffers are borrowed; records contains sixteen 16-byte entries. */
void func_020a7ae4(u8 *records, u8 *provider, int on)
{
    int i;
    if (provider == 0 || FIELD(void *, provider, 0) == 0) return;
    for (i = 0; i < 16; i++, records += 16) {
        if (records[12] != 0 && FIELD(s16, records, 4) > -1) {
            int old;
            int offset = FIELD(s16, records, 4) * 84;
            u8 *entry;
            if (records[13] != 0) old = 1;
            else old = 0;
            entry = FIELD(u8 *, provider, 8) + offset;
            records[13] = func_020a6848(entry);
            if (old == 1) {
                if (records[13] == 0 && on == 1) func_0204c780(records[10], records[11]);
            } else if (records[13] == 1 && FIELD(u32, records, 0) == 2 && on == 1) {
                int kind = 2;
                switch (records[9]) {
                case 1: break;
                case 3: kind = 21; break;
                case 5: kind = 22; break;
                }
                func_0204c698(kind, records[10], records[11]);
            }
        }
    }
}
/* Original second-bank occupancy +13 and state +14 select the two predicates.
 * Provider +8 references 88-byte entries; record IDs must index that table. */
void func_020a7bd0(u8 *records, u8 *provider, int on)
{
    int i;
    u8 *record;
    if (provider == 0 || FIELD(void *, provider, 0) == 0) return;
    record = records + 256;
    for (i = 0; i < 16; i++, record += 16) {
        if (record[13] != 0 && FIELD(s16, record, 4) > -1) {
            int offset = FIELD(s16, record, 4) * 88;
            u8 *entry = FIELD(u8 *, provider, 8) + offset;
            int old = record[14];
            old = old != 0;
            if (old == 1) {
                record[14] = func_020a68b4(entry);
                if (record[14] == 0 && on == 1) func_0204c780(record[11], record[12]);
            } else {
                record[14] = func_020a6934(entry);
                if (record[14] == 1 && FIELD(u32, record, 0) == 2 && on == 1)
                    func_0204c698(19, record[11], record[12]);
            }
        }
    }
}

/* These borrowed cell flags expose only instruction-established bit positions. */
typedef struct Unk0a6174Flags {
    u32 low : 6;
    u32 flag6 : 1;
    u32 flag7 : 1;
    u32 middle : 8;
    u32 region : 4;
    u32 high : 12;
} Unk0a6174Flags;
u8 *Unk038fbc_Unk_039160(u8 *provider, int x, int y);
u8 *Unk09a268_Unk_09c498(u32 id);
int func_020cafbc(u16 x, u16 y);
/* Keep absolute-value arithmetic inline for the bounded coordinate differences. */
static inline int Unk0a6174_Abs(int value)
{
    return value >= 0 ? value : -value;
}
/* Original kind byte, bits 6/7, radius-four occupancy and neighboring +12
 * metadata reject placement. Grid/provider buffers remain caller-owned.
 * See DEC-021 for the scoped strength-reduction setting. */
#pragma push
#pragma opt_strength_reduction off
int func_020a65c4(u8 *grid, u8 *provider, u8 *overlay, int x, int y, int kind)
{
    u8 *cell;
    int row, col;
    if (overlay != 0) cell = Unk038fbc_Unk_039160(overlay, x, y);
    else cell = Unk038fbc_Unk_039160(provider, x, y);
    if (cell == 0) return 0;
    if (cell[0] != 1) return 0;
    if (kind == 1) {
        if (FIELD(Unk0a6174Flags, cell, 4).flag6 == 0) return 0;
    } else if (kind == 2) {
        if (FIELD(Unk0a6174Flags, cell, 4).flag7 == 0) return 0;
    }
    for (row = y - 4; row <= y + 4; row++) {
        if (row < 0 || row >= 40) continue;
        for (col = x - 4; col <= x + 4; col++) {
            if (col < 0 || col >= 45) continue;
            if (Unk0a6174_Abs(x - col) + Unk0a6174_Abs(y - row) > 4) continue;
            cell = (u8 *)Unk0a6174_Unk_0a6a88((int)grid, col, row);
            if (*(s8 *)cell != 0) return 0;
        }
    }
    {
        int col, row;
        for (row = y - 1; row <= y + 1; row++) {
            if (row < 0 || row >= 40) continue;
            for (col = x - 1; col <= x + 1; col++) {
                if (col == x && row == y) continue;
                if (col < 0 || col >= 45) continue;
                cell = 0;
                if (overlay != 0) {
                    cell = Unk038fbc_Unk_039160(overlay, col, row);
                    if (cell != 0 && cell[0] == 0) cell = 0;
                }
                if (cell == 0) cell = Unk038fbc_Unk_039160(provider, col, row);
                if (cell != 0) {
                    cell = Unk09a268_Unk_09c498(cell[0]);
                    if (cell != 0 && FIELD(u32, cell, 12) == 2) return 0;
                }
            }
        }
    }
    if (func_020cafbc((u16)x, (u16)y) == 1) return 0;
    return 1;
}
#pragma pop

u32 func_0204fe18(void *header);
int Unk0e5fb8_Unk_0e62c8(u32 index);
int Unk0e5fb8_Unk_0e6348(u32 index);
void Unk0e5fb8_Unk_0e639c(u32 index, int value);
int func_020a6224(u8 *records, u32 value, u32 id, u16 a, u16 b,
                   u8 c, s8 x, s8 y, u8 state, int index);
/* Original 84-byte provider entries feed first-bank/grid insertion, capped at
 * 256 entries. Region zero also decrements the signed remaining count at +0xe10. */
void func_020a6ac0(u8 *grid, u8 *records, u8 *provider, u8 *map,
                   int id, u32 region, int filter)
{
    u32 count, i;
    u8 *entry;
    int value, state, slot;
    if (grid == 0) return;
    if (provider == 0) return;
    if (map == 0) return;
    count = func_0204fe18(FIELD(void *, provider, 4));
    if (count > 256) count = 256;
    if (region == 0) FIELD(s16, grid, 0xe10) = 16;
    for (i = 0; i < count; i++) {
        entry = FIELD(u8 *, provider, 8) + i * 84;
        if (id != FIELD(s16, entry, 0)) continue;
        value = Unk0e5fb8_Unk_0e62c8(i);
        if (value == 3) continue;
        if (region == 0) {
            FIELD(s16, grid, 0xe10)--;
            if (entry[4] == 0) goto insert;
        } else {
            u8 *cell = Unk038fbc_Unk_039160(map, entry[2], entry[3]);
            if (cell == 0) continue;
            if (region != FIELD(Unk0a6174Flags, cell, 4).region || filter != entry[4]) continue;
            goto insert;
        }
        continue;
insert:
        state = func_020a6848(entry);
        slot = Unk0a6174_FindFree0c(records);
        if (slot == -1) return;
        if (func_020a6280(grid, entry[2], entry[3], 1, (u8)slot)) {
            func_020a61a0(records, value, i, FIELD(s16, entry, 6),
                          entry[8], entry[5], (s8)entry[2], (s8)entry[3], state, slot);
        }
next:
        ;
    }
}
/* Original 88-byte entries feed the second bank, resetting per-entry provider
 * state before insertion. Grid requires writable counters through +0xe13. */
void func_020a6c98(u8 *grid, u8 *records, u8 *provider, u8 *map,
                   int id, u32 region, int filter)
{
    u32 count, i;
    u8 *entry;
    u8 state;
    int slot;
    if (grid == 0) return;
    if (provider == 0) return;
    if (map == 0) return;
    count = func_0204fe18(FIELD(void *, provider, 4));
    if (count > 256) count = 256;
    if (region == 0) FIELD(s16, grid, 0xe12) = 16;
    for (i = 0; i < count; i++) {
        int enabled;
        entry = FIELD(u8 *, provider, 8) + i * 88;
        if (id != FIELD(s16, entry, 0)) continue;
        enabled = 0;
        if (Unk0e5fb8_Unk_0e6348(i) != 3) enabled = 1;
        if (entry[7] == 1) enabled = 1;
        if (enabled != 1) continue;
        if (region == 0) {
            FIELD(s16, grid, 0xe12)--;
            if (entry[4] == 0) goto insert;
        } else {
            u8 *cell = Unk038fbc_Unk_039160(map, entry[2], entry[3]);
            if (cell == 0) continue;
            if (region != FIELD(Unk0a6174Flags, cell, 4).region || filter != entry[4]) continue;
            goto insert;
        }
        continue;
insert:
        Unk0e5fb8_Unk_0e639c(i, 0);
        state = func_020a68b4(entry);
        slot = Unk0a6174_FindFree10d(records);
        if (slot == -1) return;
        if (func_020a6280(grid, entry[2], entry[3], 2, (u8)slot)) {
            func_020a6224(records, 0, i, FIELD(u16, entry, 12),
                          FIELD(u16, entry, 14), entry[5], (s8)entry[2], (s8)entry[3], state, slot);
        }
next:
        ;
    }
}

int Unk0387bc_Unk_038cf8(u32 *work);
void Unk0387bc_Unk_038d58(u32 *work);
u8 *GetGameState(void);
u8 *Unk02e000_GetWorkArea(void);
u8 *Unk0387bc_GetEntry36(u32 *work, u32 id);
Unk0a6174KeySlot *Unk0387bc_GetEntry32(u32 *work, u32 id);
int func_02098740(int mode);
int func_02050088(int mode, int lower, int upper);
void func_020caea8(void);
void Unk0caea8_Unk_0caf48(void);
/* Original entry-36/entry-32 lookups select weighted records, then search the
 * map rectangle cyclically from a random cell. All work buffers are borrowed. */
void func_020a6e94(u8 *grid, u8 *records)
{
    u32 count;
    u8 *bounds, *table;
    int startx, x, y;
    int left, right, bottom, top;
    int limit;
    u8 i;
    u8 selected;
    Unk0a6174KeySlot *candidate, *entry;
    int slot;
    int starty;
    int inserted;
    if (grid == 0) return;
    u32 work[5] = {0};
    if (!Unk0387bc_Unk_038cf8(work)) return;
    bounds = FIELD(u8 *, GetGameState(), 0x240);
    if (bounds != 0) {
        left = bounds[8];
        top = bounds[9];
        right = left + bounds[10] - 1;
        bottom = top + bounds[11] - 1;
        count = (u8)func_02098740(1);
        if (count != 0) {
            table = Unk0387bc_GetEntry36(work, FIELD(u16, Unk02e000_GetWorkArea(), 0x35c));
            if (table != 0) {
                func_020caea8();
                limit = FIELD(u16, table + (count - 1) * 4, 2);
                if (FIELD(s16, grid, 0xe10) < limit) limit = FIELD(s16, grid, 0xe10);
                for (i = 0; i < limit; i++) {
                    selected = func_020a62ec(table, count);
                    candidate = Unk0387bc_GetEntry32(work, FIELD(u16, table + selected * 4, -4));
                    entry = func_020a63cc(candidate);
                    if (entry == 0) break;
                    slot = Unk0a6174_FindFree0c(records);
                    if (slot == -1) break;
                    startx = func_02050088(1, left, right);
                    starty = func_02050088(1, top, bottom);
                    y = starty;
                    x = startx;
                    inserted = 0;
                    do {
                        if (func_020a65c4(grid, GetGameState() + 0x240, 0, x, y, 1) == 1) {
                            inserted = func_020a6280(grid, x, y, 1, (u8)slot);
                            break;
                        }
                        x++;
                        if (right < x) { x = left; y++; }
                        if (bottom < y) y = top;
                    } while (startx != x || starty != y);
                    if (inserted == 1) {
                        s8 sx = x;
                        s8 sy = y;
                        func_020a61a0(records, 0, -1, entry->key, entry->other,
                                      selected, sx, sy, 1, slot);
                    }
                }
                Unk0caea8_Unk_0caf48();
            }
        }
    }
    Unk0387bc_Unk_038d58(work);
}
