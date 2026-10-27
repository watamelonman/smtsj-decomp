#ifndef SDK_0205DE1C_H
#define SDK_0205DE1C_H
#include "types.h"

/** Borrowed provider prefix; the mode word is observed at +24. */
typedef struct { u8 pad_00[24]; u32 mode; } Unk05de1cProvider;
/** Borrowed object prefix; provider and auxiliary storage stay caller-owned. */
typedef struct {
    u8 pad_00[12]; u32 auxiliary; u8 pad_10[32];
    Unk05de1cProvider *provider; u32 auxiliaryData[1];
} Unk05de1cObject;
/** Caller-owned 24-byte record consumed by the submission helper. */
typedef struct {
    u32 objectIndex, entryIndex;
    s16 x, y, width, height;
    union {
        u32 flags;
        struct { u32 flipX:1, flipY:1, rest:24, special:1, tail:5; } bits;
    };
    u32 depth;
} Unk05de1cRecord;
/** Borrowed range: byte offset is relative to the record array. */
typedef struct { u32 count, offset; } Unk05de1cRange;
/** Borrowed table prefix; indices must refer to valid objects and ranges. */
typedef struct {
    u32 unk_00; Unk05de1cObject **objects; u32 unk_08;
    Unk05de1cRecord *records; Unk05de1cRange *ranges;
} Unk05de1cTable;
/** Caller-owned submission packet; dimensions and trailing scales are provider units. */
typedef struct {
    u32 flags; s32 x, y; float scaleX, scaleY; u32 angle, depth;
    s32 width, height; u8 pad_24[16]; u16 repeatX, repeatY;
} Unk05de1cPacket;
/** Resolves an indexed object's provider; table storage must outlive the call. */
int func_0205de1c(Unk05de1cTable *table, u32 index);
/** Rebinds an indexed object's borrowed provider. */
void func_0205de30(Unk05de1cTable *table, u32 index, Unk05de1cProvider *provider);
/** Submits a range in ascending order with conditional state reset. */
void func_0205de40(u32 flags, Unk05de1cTable *table, u32 index, s32 x, s32 y, float sx, float sy, s32 angle, float alpha, u32 depth);
/** Submits a range in ascending order without requesting a state reset. */
void func_0205dee8(u32 flags, Unk05de1cTable *table, u32 index, s32 x, s32 y, float sx, float sy, s32 angle, float alpha, u32 depth);
/** Resets state and submits a range in descending order. */
void func_0205df90(u32 flags, Unk05de1cTable *table, u32 index, s32 x, s32 y, float sx, float sy, s32 angle, float alpha, u32 depth);
/** Builds a packet from a record and submits it; all inputs are borrowed. */
void func_0205e048(u32 flags, Unk05de1cTable *table, Unk05de1cRecord *record, s32 x, s32 y, float sx, float sy, s32 angle, float alpha, u32 depth, int reset);
/** Temporarily binds the object's auxiliary data, submits, then restores the provider. */
void func_0205e2bc(Unk05de1cObject *object, u32 index, Unk05de1cPacket *packet);
#endif
