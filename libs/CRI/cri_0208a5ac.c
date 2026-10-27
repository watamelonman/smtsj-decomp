#include "libs/CRI/cri_0208a5ac.h"

/** Refills the shift register from the source buffer.
 *
 * Called when fewer than four bytes are left, so the register never holds more
 * than 32 bits: `needed` is the number of whole bytes that fit until the
 * register is full, clamped to the bytes the current buffer still has. The
 * source is asked for the remainder of the current buffer first; the bytes
 * already handed out are released and the unread tail is returned so the next
 * request can continue where this one stopped. Each arm appends through a
 * cursor/register pair so a whole arm costs one load and one store. */
void func_0208a5ac(CriBitStream *stream)
{
    s32 needed;

    needed = (32 - stream->count) / 8;
    if (stream->remaining < 4) {
        CriBitStreamChunk part;
        CriBitStreamChunk rest;

        part = stream->buffer;
        if (part.size != 0) {
            func_0208a7b0(&part, part.size - stream->remaining, &part, &rest);
            stream->source->vtable->release(stream->source, 0, &part);
            stream->source->vtable->unread(stream->source, 1, &rest);
        }
        stream->source->vtable->request(stream->source, 1, stream->requestBytes,
            &stream->buffer);
        stream->cursor = stream->buffer.data;
        stream->remaining = stream->buffer.size;
    }
    if (needed >= stream->remaining)
        needed = stream->remaining;

    if (needed == 3) {
        const u8 *p = stream->cursor;
        s32 w = stream->bits;

        w = (w << 8) | p[0];
        w = (w << 8) | p[1];
        w = (w << 8) | p[2];
        stream->cursor = p + 3;
        stream->bits = w;
        stream->count += 24;
        stream->remaining -= 3;
        return;
    }
    if (needed == 2) {
        const u8 *p = stream->cursor;
        s32 w = stream->bits;

        w = (w << 8) | p[0];
        w = (w << 8) | p[1];
        stream->cursor = p + 2;
        stream->bits = w;
        stream->count += 16;
        stream->remaining -= 2;
        return;
    }
    if (needed == 1) {
        const u8 *p = stream->cursor;
        s32 w = stream->bits;

        w = (w << 8) | *p;
        stream->cursor = p + 1;
        stream->bits = w;
        stream->count += 8;
        stream->remaining -= 1;
        return;
    }
    if (needed == 4) {
        const u8 *p = stream->cursor;
        s32 w = stream->bits;

        w = (w << 8) | p[0];
        w = (w << 8) | p[1];
        w = (w << 8) | p[2];
        w = (w << 8) | p[3];
        stream->cursor = p + 4;
        stream->bits = w;
        stream->count += 32;
        stream->remaining -= 4;
    }
}

/** Carves `bytes` off the front of `source` into `part` and leaves the tail in
 * `rest`. `part` may alias `source` (func_0208a5ac passes the same record to
 * both), which is why the original copies both words with one `stm` before it
 * clamps the size. `rest->data` is null when nothing is left, so a zero-length
 * record never points into the buffer it no longer owns. */
void func_0208a7b0(const CriBitStreamChunk *source, s32 bytes,
    CriBitStreamChunk *part, CriBitStreamChunk *rest)
{
    *part = *source;
    rest->size = part->size;
    if (part->size > bytes)
        part->size = bytes;
    rest->size -= part->size;
    rest->data = rest->size == 0 ? 0 : part->data + part->size;
}

/** Reports whether `bits` bits are available, refilling once from the source.
 * Callers use it to check a header before parsing it. */
s32 func_0208a7f4(CriBitStream *stream, s32 bits)
{
    if (stream->count < bits)
        func_0208a5ac(stream);
    if (bits > stream->count)
        return 0;
    return 1;
}

/** Reports how many bits have been returned to callers so far; the reader also
 * uses it to align a stream to the next byte boundary. */
s32 func_0208a890(CriBitStream *stream)
{
    return stream->consumed;
}

/** Reports end of stream: the source is at its end, the register is empty and
 * the current buffer has no unread bytes left. */
s32 func_0208a898(CriBitStream *stream)
{
    if (stream->source->vtable->atEnd(stream->source, 1) == 0
        && stream->count == 0
        && stream->remaining == 0)
        return 1;
    return 0;
}

