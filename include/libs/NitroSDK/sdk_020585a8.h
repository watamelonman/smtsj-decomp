#ifndef SDK_020585A8_H
#define SDK_020585A8_H

#include "types.h"

/** Three signed 20.12 components; callers pass vectors by address. */
typedef struct Unk0585a8Vector {
    s32 x;
    s32 y;
    s32 z;
} Unk0585a8Vector;

/** One 92-byte bound resource record; only the resource pointer is written here. */
typedef struct Unk0585a8Record {
    u8 unk_00[84];
    void *resource;
    u32 unk_58;
} Unk0585a8Record;

/** Caller-owned graphics work: 90 records followed by the source handle and two
 *  state blocks. The extent comes from the 90*92 stride and +0x2058/+0x2084 calls. */
typedef struct Unk0585a8Work {
    Unk0585a8Record records[90];
    void *source;
    u8 state_205c[0x28];
    u8 state_2084[1];
} Unk0585a8Work;

/** Borrowed resource dictionary header at resource + 8 (NNSG3dResDict layout). */
typedef struct Unk0585a8Dict {
    u8 revision;
    u8 count;
    u8 unk_02[4];
    u16 entryOffset;
} Unk0585a8Dict;

/** Borrowed resource: eight header bytes precede the embedded dictionary. */
typedef struct Unk0585a8Resource {
    u8 unk_00[8];
    Unk0585a8Dict dictionary;
} Unk0585a8Resource;

/** Dictionary entry table; records are `stride` bytes from `entries`. */
typedef struct Unk0585a8EntryTable {
    u16 stride;
    u16 unk_02;
    u8 entries[1];
} Unk0585a8EntryTable;

/** Bind every dictionary-indexed resource into the work records after setting up
 *  the work state and waiting for the display window. Caller supplies a work area
 *  created by func_02058528 and dictionary data with at most 90 entries. */
void func_020585a8(Unk0585a8Work *work);

/** Store five projection parameters and update the shared projection state.
 *  Evidence: the five integer arguments at the 02037864/020b7738 call sites. */
void func_020586d0(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4);

/** Build the three basis vectors and their 48-byte matrix from two axes.
 *  Evidence: callers pass two 12-byte vectors (02037848, 020b773c). */
void func_02058724(Unk0585a8Vector *xAxis, Unk0585a8Vector *zAxis);

#endif
