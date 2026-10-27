#ifndef LIBS_UNKNOWN_LIB_02090068_H
#define LIBS_UNKNOWN_LIB_02090068_H

#include "types.h"

typedef struct Lib02090068Stream Lib02090068Stream;
typedef void (*Lib02090068Method)(Lib02090068Stream *self);

/* Borrowed view of the stream wrapper used by the Mobiclip file reader.
 * `sdk_0208e1f0` fills offsets 0x0c, +4 and +8 in its initialiser at
 * 02090030; this unit only reads/writes +8, +0x0c and the open byte at +0x10.
 * The vtable pointer and the file context stay owned by the provider. */
struct Lib02090068Stream {
    Lib02090068Method *vtable_00;
    u32 base_04;
    u32 position_08;
    void *file_0c;
    u8 open_10;
};

/** Seek the wrapped file to `size` and record it as the current position.
 * Returns 1 on success, 0 when the seek failed. */
int func_02090068(Lib02090068Stream *stream, u32 size);

/** Read `size` bytes at the current position and advance it by `size`.
 * Returns 1 on success, 0 on a short/failed read. */
int func_020900b4(Lib02090068Stream *stream, void *buffer, u32 size);

/** Read the 0x200-byte block containing the current position into `buffer`
 * and return the byte offset of that position inside the block. The caller
 * must supply at least the rounded-up block size. Returns 0 on failure. */
int func_02090124(Lib02090068Stream *stream, void *buffer, u32 size);

/** Close the wrapped file when the open byte is set, then clear that byte. */
void func_020901a0(Lib02090068Stream *stream);

/** Dispatch through vtable slot 5, passing the object unchanged. */
void func_020901c8(Lib02090068Stream *stream);

/** Empty function; no inputs, return value or side effects. */
void func_020901dc(void);

#endif
