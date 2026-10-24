#ifndef LIB_02049998_H
#define LIB_02049998_H
#include "types.h"

/* Halfword allocation follows the original ldrh/strh accesses at offset four. */
typedef struct Unk049998Status {
    s8 unk_00[3];
    u8 pad_03;
    u16 unk_04_0 : 2;
    u16 unk_04_2 : 2;
    u16 unk_04_4 : 2;
    u16 unk_04_6 : 2;
    u16 unk_04_8 : 2;
    u16 unk_04_10 : 3;
    u16 unk_04_13 : 3;
} Unk049998Status;

/* Only the leading handle and signed counter are observed by these helpers. */
typedef struct Unk049998Counter {
    void *unk_00;
    u32 unk_04;
    s16 unk_08;
} Unk049998Counter;

/* Word-sized fields preserve the packed record accesses at +0x18. */
typedef struct Unk049998Record {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08[4];
    u32 unk_18_0 : 1;
    u32 unk_18_1 : 1;
    u32 unk_18_2 : 8;
    u32 unk_18_10 : 22;
} Unk049998Record;

/* Opaque prefix belongs to the caller; the two observed records start at +0x248. */
typedef struct Unk049998Work {
    u8 pad_000[0x248];
    Unk049998Record unk_248;
    Unk049998Record unk_264;
} Unk049998Work;

/* Clears two transient fields and decrements three nonzero packed counters. */
int func_02049998(Unk049998Status *status);
/* Increments the signed counter only when nonnegative and the handle exists. */
int func_02049a58(Unk049998Counter *counter);
/* Compares the borrowed leading handle with the supplied pointer. */
int func_02049a84(const Unk049998Counter *counter, const void *handle);
/* Copies the first record over the second and clears the first record's low flag. */
void func_02049a98(Unk049998Work *work);
/* Sets the first record's low flag and replaces its first 24 bytes. */
void func_02049ac0(Unk049998Work *work, const void *source);
/* Stores the low eight bits of value and a normalized boolean in the first record. */
void func_02049aec(Unk049998Work *work, int value, int enabled);
/* Tests the second record's flags and tagged word; requires tag 0xfffe. */
int func_02049b24(const Unk049998Work *work);
/* Tests index 0..7 of the second record's byte when its low flag is set. */
int func_02049b7c(const Unk049998Work *work, int bit);
#endif
