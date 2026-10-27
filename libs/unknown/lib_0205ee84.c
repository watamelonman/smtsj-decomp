#include "libs/unknown/lib_0205ee84.h"

/* Provider allocator/free pair used by the adjacent SDK translation units. */
extern void *func_02052fe0(u32 size);
extern void func_02053000(void *allocation);
/* MSL memset/copy helpers; the argument order follows the reconstructed MSL code. */
extern void func_02008848(void *destination, int value, u32 size);
extern void func_02008904(const void *source, void *destination, u32 size);

/* Provider-owned singleton; this file only observes the word at +0xc. */
typedef struct {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
} Unk05ee84Provider;
extern Unk05ee84Provider data_0216b428;

/* The provider's ready predicate; callers treat a zero result as "not ready". */
extern u32 func_0205ecd8(void);

/* Single-bit writer/reader neighbours in this translation unit. They are matched by
 * a separate card and remain extern so both views share one implementation. */
extern void func_0205f070(BitStream05ee84 *stream, u32 value);
extern u32 func_0205f0f8(BitStream05ee84 *stream);

/* Releases the whole stream block; the allocation is the 16-byte header itself.
 * The original tail-dispatches, so ownership passes to the provider allocator. */
void func_0205f038(BitStream05ee84 *stream)
{
    func_02053000(stream);
}

/* Copies the stream payload into caller storage. Evidence: the original loads the
 * two words at +0/+4 as the copy source and length, and func_02111ac4 uses it to
 * publish an encoded record. */
void func_0205f05c(BitStream05ee84 *stream, void *destination)
{
    func_02008904(stream->buffer, destination, stream->capacity);
}

/* Copies caller storage into the stream payload. Evidence: func_02111c54 uses it to
 * install the 24-byte encoded record before decoding bits from the buffer. */
void func_0205f044(BitStream05ee84 *stream, const void *source)
{
    func_02008904(source, stream->buffer, stream->capacity);
}

/* Reports the provider's state word once the provider is ready, otherwise the
 * literal 3 that callers treat as "not available". */
u32 func_0205efa8(void)
{
    if (func_0205ecd8())
        return data_0216b428.unk_0c;
    return 3;
}

/* Allocates the 16-byte header and the payload as one zeroed block. A zero-byte
 * request keeps the buffer null while still returning a usable header; the
 * paired free in this file releases the same pointer. */
BitStream05ee84 *func_0205efc8(u32 bytes)
{
    BitStream05ee84 *stream = func_02052fe0(bytes + 16);

    func_02008848(stream, 0, bytes + 16);
    stream->buffer = bytes ? (u8 *)stream + 16 : 0;
    stream->capacity = bytes;
    return stream;
}

/* Creates a zeroed header over borrowed storage of the given capacity. The
 * allocator only reserves the header, so the caller keeps ownership of buffer. */
BitStream05ee84 *func_0205f004(u8 *buffer, u32 bytes)
{
    BitStream05ee84 *stream = func_02052fe0(16);

    func_02008848(stream, 0, 16);
    stream->buffer = buffer;
    stream->capacity = bytes;
    return stream;
}

/* Writes the low `bits` bits of value starting at the current position, least
 * significant bit first. func_02111ac4 packs record fields through this entry
 * point; a zero bit count writes nothing. */
void func_0205f168(BitStream05ee84 *stream, u32 value, u32 bits)
{
    u32 i;

    for (i = 0; i < bits; i++) {
        func_0205f070(stream, value);
        value >>= 1;
    }
}

/* Reads `bits` bits from the current position, least significant bit first, and
 * returns them in the low bits of the result. func_02111c54 unpacks record fields
 * through this entry point; a zero bit count returns zero. */
u32 func_0205f1a0(BitStream05ee84 *stream, u32 bits)
{
    u32 value = 0;
    u32 i;

    for (i = 0; i < bits; i++)
        value |= func_0205f0f8(stream) << i;
    return value;
}
