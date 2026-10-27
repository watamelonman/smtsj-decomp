#ifndef LIB_02049620_H
#define LIB_02049620_H
#include "types.h"

/* A 0x38-byte event-queue record. The +0 word is the kind that the queue scan
 * dispatches on, +4 is an unsigned scheduling value read by the consumer in
 * unit_020469d8, and +0x14 holds the NUL-terminated name handed to func_0209d44c
 * (which formats 32-byte name slots). Only the observed fields are named. */
typedef struct Unk049620Record {
    u32 kind;
    u32 unk_04;
    u8 pad_08[8];
    u8 unk_10;
    u8 pad_11[3];
    char name[0x24];
} Unk049620Record;

#define UNK049620_RECORD_CAPACITY 256

/* Caller-owned queue: 256 records followed by the cursor (index) and the live
 * record count. Both counters are unsigned in the original compares. */
typedef struct Unk049620List {
    Unk049620Record records[UNK049620_RECORD_CAPACITY];
    u32 index;
    u32 unk_3804;
    u32 count;
} Unk049620List;

/* A 12-byte slot cleared by func_0204976c; only the leading word is written
 * separately, so the remaining bytes are opaque to this unit. */
typedef struct Unk049620Slot12 {
    u32 unk_00;
    u8 pad_04[8];
} Unk049620Slot12;

/* A 6-byte slot cleared by func_020497d0/func_020497bc. */
typedef struct Unk049620Slot6 {
    u8 bytes[6];
} Unk049620Slot6;

/* Scans from the cursor; stops at a word-1 record and registers word-2 names. */
void func_020496d0(Unk049620List *list);
/* Returns the record at the cursor, or null when the cursor is at the end. */
Unk049620Record *func_02049724(Unk049620List *list);
/* Advances the cursor; stores the count and returns 0 when it ran past the end. */
s32 func_02049744(Unk049620List *list);
/* Zeroes count 12-byte slots starting at base, newest first. */
void func_0204976c(Unk049620Slot12 *base, s32 count);
/* Zeroes one 12-byte slot. */
void func_020497ac(Unk049620Slot12 *base);
/* Zeroes one 6-byte slot. */
void func_020497bc(Unk049620Slot6 *base);
/* Zeroes count 6-byte slots starting at base, newest first. */
void func_020497d0(Unk049620Slot6 *base, s32 count);
/* Zeroes one 6-byte slot. */
void func_020497fc(Unk049620Slot6 *base);

#endif
