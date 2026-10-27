#ifndef SDK_0205DACC_H
#define SDK_0205DACC_H

#include "types.h"

/** Loaded resource; the entry count is at +0x10, +0x14 signals a following group,
 *  and the variable-length entry records start at +0x18. */
typedef struct {
    u32 unk_00[4];
    u32 count;
    u32 groupCount;
    u8 entries[1];
} Unk05dacc_Resource;

/** Named entry inside a resource; the name is matched and +0x30 receives the bound output. */
typedef struct {
    u32 unk_00[4];
    char name[32];
    void *output;
    u8 unk_34[0x24];
    u8 ready;
} Unk05dacc_Item;

/** Loaded registry entry; the name used for matching starts at +0x2c and +0x58 marks readiness. */
typedef struct {
    u8 unk_00[0x2c];
    char name[1];
    u8 unk_2d[0x2b];
    u8 ready;
} Unk05dacc_RegistryEntry;

/** Second-level table bound by func_0205dc0c; records are 8 bytes from +0x14. */
typedef struct {
    u32 unk_00[3];
    u32 count;
    u32 unk_10;
    u8 entries[1];
} Unk05dacc_Group;

/** Runtime wrapper; a nonzero borrowed flag prevents releasing the resource. */
typedef struct {
    Unk05dacc_Resource *resource;
    Unk05dacc_Item **items;
    u32 count;
    Unk05dacc_Group *group;
    u8 *groupBegin;
    u8 *groupEnd;
    u32 borrowed;
} Unk05dacc_Handle;

/** Reads a record's id and follows its 4-byte offset into caller storage. */
u32 func_0205db5c(const void *record, u32 *offset);
/** Appends an entry pointer to the wrapper table; caller guarantees capacity. */
void func_0205dbf0(Unk05dacc_Handle *handle, Unk05dacc_Item *item);
/** Binds a wrapper to a group and derives its 8-byte record range. */
void func_0205dc0c(Unk05dacc_Handle *handle, Unk05dacc_Group *group);
/** Resolves one named entry against the loaded registry; returns one on a match. */
int func_0205db8c(Unk05dacc_Item *item);
/** Builds a .gtsh path, loads the resource and wraps it with ownership. */
Unk05dacc_Handle *func_0205dcd4(const char *name, u32 mode);
/** Wraps an already-loaded resource without taking ownership. */
Unk05dacc_Handle *func_0205dd58(Unk05dacc_Resource *resource, u32 mode);
/** Releases the resource only when owned, then the table and wrapper. */
void func_0205ddb4(Unk05dacc_Handle *handle);
/** Resolves every entry in the wrapper table through func_0205db8c. */
void func_0205dde4(Unk05dacc_Handle *handle);

/* Implemented in the remainder of this translation unit. */
/** Builds a prefixed path with a .cmp probe and caller suffix fallback. */
int func_0205dacc(char *output, const char *name, const char *suffix);
/** Parses the resource tables into the wrapper; records points at the resource header. */
void func_0205dc28(Unk05dacc_Handle *handle, u8 *records, u32 mode);

#endif
