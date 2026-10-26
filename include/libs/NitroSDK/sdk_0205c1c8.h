#ifndef SDK_0205C1C8_H
#define SDK_0205C1C8_H

#include "types.h"

/** Borrowed resource prefix; only the table count at +12 is established. */
typedef struct {
    u32 unk_00[3];
    u32 count;
    u32 unk_10;
} Unk05c1c8_Header;

/** Borrowed 12-byte entry; offset is relative to the resource base. */
typedef struct {
    u32 unk_00;
    u32 offset;
    u32 count;
} Unk05c1c8_Entry;

/** Owned wrapper; a nonzero borrowed flag prevents releasing the resource. */
typedef struct {
    Unk05c1c8_Header *resource;
    Unk05c1c8_Entry *entries;
    void *tail;
    u32 borrowed;
} Unk05c1c8_Work;

/** Borrowed 40-byte record view; only the word at +4 is read here. */
typedef struct {
    u32 unk_00;
    u32 unk_04;
    u8 pad_08[32];
} Unk05c1c8_Record;

/** Opaque 320-byte allocation cleared by the paired initializer. */
typedef struct {
    u8 storage[320];
} Unk05c1c8_Buffer;

/** Copies two four-byte fields from readable source storage; output is caller-owned. */
u32 func_0205c258(const void *source, u32 *output);
/** Binds a wrapper to a valid resource and derives its table boundaries. */
void func_0205c288(Unk05c1c8_Work *work, Unk05c1c8_Header *resource);
/** Allocates a wrapper borrowing a resource that must outlive it. */
Unk05c1c8_Work *func_0205c328(Unk05c1c8_Header *resource);
/** Releases the wrapper and releases its resource only when owned. */
void func_0205c368(Unk05c1c8_Work *work);
/** Reads +4 of an entry's last record; index and nonzero count must be valid. */
u32 func_0205c390(const Unk05c1c8_Work *work, u32 index);
/** Allocates and clears a 320-byte buffer; caller owns the result. */
Unk05c1c8_Buffer *func_0205c3c0(void);
/** Releases a buffer allocated by the paired allocator. */
void func_0205c3dc(Unk05c1c8_Buffer *buffer);
/** Clears all 320 bytes of caller-provided writable buffer storage. */
void func_0205c3e8(Unk05c1c8_Buffer *buffer);

#endif
