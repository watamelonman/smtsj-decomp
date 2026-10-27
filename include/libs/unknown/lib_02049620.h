#ifndef LIB_02049620_H
#define LIB_02049620_H
#include "types.h"

/* A 0x38-byte event-queue record. The +0 word is the kind that the queue scan
 * dispatches on (signed in the original switch), +4 is an unsigned scheduling
 * value read by the consumer in unit_020469d8, and +0x14 holds the
 * NUL-terminated name handed to func_0209d44c (which formats 32-byte name
 * slots). Only the observed fields are named. */
typedef struct Unk049620Record {
    s32 kind;
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

/* A 3-axis state updated by func_0204980c. The axes are signed and the packed
 * halfword at +4 holds the independently updated fields b0..b6; their widths
 * (2,2,2,2,2,3,3) are what the original's lsl/lsr masks encode. Bitfields are
 * laid out LSB first on ARM, so b0 is bits 0..1 and b6 is bits 13..15. */
typedef struct Unk04980cState {
    s8 axis[3];
    u8 pad_03;
    u16 b0 : 2;
    u16 b1 : 2;
    u16 b2 : 2;
    u16 b3 : 2;
    u16 b4 : 2;
    u16 b5 : 3;
    u16 b6 : 3;
} Unk04980cState;

/* Normalizes the queued records before the consumer runs. */
void func_02049620(Unk049620List *list);
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
/* Applies a 3-axis update and merges the nonzero packed flags into the state. */
void func_0204980c(Unk04980cState *state, Unk04980cState *update);

#endif
