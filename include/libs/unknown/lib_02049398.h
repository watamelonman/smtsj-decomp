#ifndef LIB_02049398_H
#define LIB_02049398_H
#include "types.h"

/* Borrowed singleton prefix; only the resource slots read by this unit are exposed. */
typedef struct {
    u8 pad_0000[0x7994];
    void *unk_7994;
    u8 pad_7998[0xc];
    void *unk_79a4;
    void *unk_79a8;
} Unk049398State;

/* A 56-byte ordered record; the comparator reads only these leading words. */
typedef struct {
    u32 unk_00;
    u32 unk_04;
    u8 pad_08[0x30];
} Unk049398Record;

#define UNK049398_RECORD_CAPACITY 256

/* Caller-owned array whose first 0x3800 bytes are records; trailing counters are cleared
 * together with the array by func_020494f0. */
typedef struct {
    Unk049398Record records[UNK049398_RECORD_CAPACITY];
    u32 unk_3800;
    u32 unk_3804;
    u32 count;
} Unk049398List;

/* Returns MTBL group one's entry for id, retrying id zero when absent. */
void *func_02049398(u32 id);
/* Returns MTBL group two's entry for id, retrying id zero when absent. */
void *func_020493e0(u32 id);
/* Returns the group-zero entry only when id is within the table's inclusive bounds. */
void *func_02049428(u32 id);
/* Returns the clamped 38-byte record at index; the table must be nonempty. */
void *func_02049484(u32 index);
/* Adds the signed delta to the battle record selected by id. */
void func_020494d0(u32 id, s32 delta);
/* Clears the record array and its trailing words. */
void func_020494f0(Unk049398List *list);
/* Appends a copy of a record and returns 1, or 0 when the array is full. */
s32 func_0204951c(Unk049398List *list, const Unk049398Record *record);
/* Orders records by +4, then by +0 when the first comparison ties. */
s32 func_02049574(const Unk049398Record *a, const Unk049398Record *b);
/* Sorts the runs delimited by +0-word-1 records, then sorts the final run. */
void func_02049594(Unk049398List *list);

#endif
