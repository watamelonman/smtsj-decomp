#ifndef LIBS_CRI_CRI_0208A5AC_H
#define LIBS_CRI_CRI_0208A5AC_H

#include "types.h"

/** Borrowed byte range handed between the bit reader and its source.
 *
 * The original passes these two-word records on the stack: a reader/writer of
 * the record copies both words with one `stm`, so the layout is exactly
 * {pointer, byte count}. `size` counts bytes, never bits. */
typedef struct CriBitStreamChunk {
    const u8 *data;
    s32 size;
} CriBitStreamChunk;

/** Bit reader source; its layout is private to the provider. */
typedef struct CriBitStreamSource CriBitStreamSource;

/** The source's dispatch table. Only the four entries this unit calls are
 * named; the first six entries are never touched here.
 *
 * Evidence for the offsets is the original `ldr r3, [r3, #N]` before each
 * `blx r3` (0x18, 0x1c, 0x20, 0x24). `kind` is the literal 0 or 1 the reader
 * supplies: 0 for the already-consumed prefix, 1 for the live buffer. */
typedef struct CriBitStreamSourceVtable {
    void *unk_00[6];
    void (*request)(CriBitStreamSource *self, s32 kind, s32 size,
        CriBitStreamChunk *buffer);
    void (*unread)(CriBitStreamSource *self, s32 kind, CriBitStreamChunk *part);
    void (*release)(CriBitStreamSource *self, s32 kind, CriBitStreamChunk *part);
    s32 (*atEnd)(CriBitStreamSource *self, s32 kind);
} CriBitStreamSourceVtable;

struct CriBitStreamSource {
    const CriBitStreamSourceVtable *vtable;
};

/** MSB-first bit reader over a byte source.
 *
 * Offsets come from the instructions in 0208a5ac..0208a978:
 * +0x04 source, +0x08 the shift register, +0x0c its valid bit count, +0x10 the
 * total bits consumed (returned by func_0208a890), +0x18 the byte count asked
 * from the source, +0x1c/+0x20 the buffer the source granted, +0x24 how many of
 * its bytes are still unread and +0x28 the read cursor. Bytes are appended to
 * the register big-endian (`bits << 8 | byte`), so the register holds the most
 * recent whole bytes in its low end. */
typedef struct CriBitStream {
    void *unk_000;      /* never read by this unit; prefix of the caller's state */
    CriBitStreamSource *source;
    s32 bits;
    s32 count;
    s32 consumed;
    u8 pad_014[4];
    s32 requestBytes;
    CriBitStreamChunk buffer;
    s32 remaining;
    const u8 *cursor;
} CriBitStream;

/* Reader entry points; see libs/CRI/cri_0208a5ac.c for the contracts.

 * func_0208a824 and func_0208a8d4 are still supplied by the delinked object:
 * their reconstruction is left on the hard list documented in
 * docs/functions/libs-cri-cri-0208a5ac.md. */
void func_0208a5ac(CriBitStream *stream);
s32 func_0208a7f4(CriBitStream *stream, s32 bits);
s32 func_0208a824(CriBitStream *stream, s32 bits);
s32 func_0208a890(CriBitStream *stream);
s32 func_0208a898(CriBitStream *stream);
s32 func_0208a8d4(CriBitStream *stream);
void func_0208a7b0(const CriBitStreamChunk *source, s32 bytes,
    CriBitStreamChunk *part, CriBitStreamChunk *rest);

#endif
