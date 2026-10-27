#ifndef LIB_0205F1D8_H
#define LIB_0205F1D8_H

#include "types.h"

/* Container magic at the start of every FBIN resource ("FBIN" in memory order).
 * Evidence: all three magic checks in lib_0205f1d8.c load this word, and
 * extract/files/Data/Effect/Skill2EffectData.bin begins with the same four bytes,
 * followed by the count/data-offset/size-table layout below. */
#define UNK05F1D8_MAGIC 0x4e494246

/* Header shared by an in-memory FBIN resource and its on-disk form. The size
 * table has `count` entries and is immediately followed (after alignment) by
 * the payload at byte offset `dataOffset`. */
typedef struct {
    u32 magic;      /* UNK05F1D8_MAGIC */
    u32 count;      /* number of entries in sizes[] */
    u32 dataOffset; /* byte offset from the header to the first entry's payload */
} Unk05f1d8Header;

/* In-memory resource: header, then the per-entry payload sizes. `sizes` is a
 * flexible array whose real length is `count` (the original accesses it through
 * pointer arithmetic, so one element is enough to describe the layout). */
typedef struct {
    u32 magic;
    u32 count;
    u32 dataOffset;
    u32 sizes[1];
} Unk05f1d8Resource;

/* NitroSDK file context used by func_02051410/func_0205144c/func_02051430.
 * The helpers write up to 0x48 bytes into it; the same size is proven by the
 * stack frames in this file and in libs/NitroSDK/sdk_0205bbac.c. */
typedef struct {
    u32 words[18];
} Unk05f1d8File;

/* Twelve-byte file locator filled in by func_0205f508: the first two words are
 * passed to func_0200bcf8 as the archive/file identity and the third is the
 * read offset. Evidence: func_0205f534 loads words +0/+4 into func_0200bcf8 and
 * passes word +8 as the func_0205144c seek offset. */
typedef struct {
    u32 archive;
    u32 file;
    u32 offset;
} Unk05f1d8Locator;

/* Caller-owned byte stream used by the two block copy helpers in this unit:
 * +0 is the storage, +4 its byte capacity, +8 the cursor and +0xc a status word
 * that the next copy clears. Evidence: func_0205f1d8 and func_0205f25c guard the
 * copy with those four words, and no other function in the unit touches them. */
typedef struct {
    u8 *buffer;
    u32 capacity;
    u32 offset;
    u32 unk_0c;
} Unk05f1d8Stream;

#endif
