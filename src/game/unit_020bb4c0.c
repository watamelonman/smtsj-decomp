/* src/game/unit_020bb4c0.c: script command handlers that read borrowed records and select
 * from a three-entry table. Each handler reads its arguments with func_0203ac00 and publishes
 * a result with Unk03aae8_Unk_03acf4; all return command status 1. */
#include "types.h"

/* Script argument reader; returns the word at the requested argument index. */
u32 func_0203ac00(u32 index);
/* Publishes the command result; the stored word is interpreted as signed. */
void Unk03aae8_Unk_03acf4(u32 value);

/* Record returned by func_020a1428; only the bytes read by this unit are named. */
typedef struct Unk0bb4c0ByteRecord {
    u8 pad_00[2];
    u8 unk_02;                  /* +0x02: a byte value forwarded to the script */
    u8 pad_03[0x5f];
    u8 unk_62;                  /* +0x62: byte published with base 205 */
    u8 unk_63;                  /* +0x63: byte published with base 205 */
} Unk0bb4c0ByteRecord;

Unk0bb4c0ByteRecord *Unk0bb2b0_Thunk_020a1428(u32 id);

/* Record returned by func_020a1740: three 6-byte weighted entries at +0x48 and a word at +0x60. */
typedef struct Unk0bb4c0Entry {
    u16 unk_00;                 /* +0x00: nonzero marks the entry as present */
    u16 unk_02;                 /* +0x02: amount used in the selection step */
    u16 unk_04;                 /* +0x04: nonzero disables the entry */
} Unk0bb4c0Entry;

typedef struct Unk0bb4c0Record {
    u8 pad_000[0x48];
    Unk0bb4c0Entry entries[3];  /* +0x48: three 6-byte entries */
    u8 pad_05a[6];
    u32 unk_060;                /* +0x60: word forwarded to the script */
} Unk0bb4c0Record;

Unk0bb4c0Record *Unk0bb2b0_Thunk_020a1740(u32 id);

/* Nonzero when the record condition checked inside the callee holds; the condition's meaning
 * is not established. */
int Unk0a163c_Unk_0a17d8(u32 id);
/* Inclusive random number in [first, last]. */
int func_02050074(int first, int last);

/* Publishes record byte +0x62 plus the fixed message base 205 (0xCD). */
u32 func_020bb4c0(void)
{
    u16 id = func_0203ac00(0);
    Unk0bb4c0ByteRecord *record = Unk0bb2b0_Thunk_020a1428(id);
    Unk03aae8_Unk_03acf4(record->unk_62 + 205);
    return 1;
}

/* Publishes record byte +0x63 plus the fixed message base 205 (0xCD). */
u32 func_020bb4ec(void)
{
    u16 id = func_0203ac00(0);
    Unk0bb4c0ByteRecord *record = Unk0bb2b0_Thunk_020a1428(id);
    Unk03aae8_Unk_03acf4(record->unk_63 + 205);
    return 1;
}

/* Publishes record byte +0x02. */
u32 func_020bb518(void)
{
    u16 id = func_0203ac00(0);
    Unk0bb4c0ByteRecord *record = Unk0bb2b0_Thunk_020a1428(id);
    Unk03aae8_Unk_03acf4(record->unk_02);
    return 1;
}

/* Publishes the word at record +0x60. */
u32 func_020bb540(void)
{
    u16 id = func_0203ac00(0);
    Unk0bb4c0Record *record = Unk0bb2b0_Thunk_020a1740(id);
    Unk03aae8_Unk_03acf4(record->unk_060);
    return 1;
}

/* Publishes 1 when Unk0a163c_Unk_0a17d8 reports the id as available, otherwise 0. */
u32 func_020bb568(void)
{
    u16 id = func_0203ac00(0);
    if (Unk0a163c_Unk_0a17d8(id) != 0) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Publishes the key of a present entry (nonzero key, zero disable field). The first pass adds
 * the first entry's +0x02 amount for every present entry; when that total is zero it publishes
 * -1. Otherwise it draws a random value in [0, total], subtracts the +0x02 amount of each
 * present entry in order, and publishes the key of the first entry that makes the value
 * non-positive. */
u32 func_020bb5a4(void)
{
    u16 id = func_0203ac00(0);
    Unk0bb4c0Record *record = Unk0bb2b0_Thunk_020a1740(id);
    Unk0bb4c0Entry *entries = record->entries;
    int total = 0;
    int pick = -1;
    u32 i;

    for (i = 0; i < 3; i++) {
        if (entries[i].unk_00 != 0) {
            if (entries[i].unk_04 == 0) {
                pick = entries[i].unk_00;
                total += entries[0].unk_02;
            }
        }
    }
    if (total == 0) {
        Unk03aae8_Unk_03acf4(-1);
    } else {
        int value = func_02050074(0, total);
        u32 j;
        for (j = 0; j < 3; j++) {
            if (entries[j].unk_00 != 0 && entries[j].unk_04 == 0) {
                value -= entries[j].unk_02;
                if (value <= 0) {
                    pick = entries[j].unk_00;
                    break;
                }
            }
        }
        Unk03aae8_Unk_03acf4(pick);
    }
    return 1;
}

/* Publishes the key of the present entry (nonzero key, zero disable field) with the smallest
 * weight, or -1 when no entry is present. */
u32 func_020bb67c(void)
{
    u16 id = func_0203ac00(0);
    Unk0bb4c0Record *record = Unk0bb2b0_Thunk_020a1740(id);
    Unk0bb4c0Entry *entry = record->entries;
    int best = -1;
    u32 limit = 100;
    u32 i;

    for (i = 0; i < 3; i++, entry++) {
        if (entry->unk_00 != 0 && entry->unk_04 == 0) {
            if (entry->unk_02 < limit) {
                limit = entry->unk_02;
                best = entry->unk_00;
            }
        }
    }
    Unk03aae8_Unk_03acf4(best);
    return 1;
}
