#include "libs/unknown/lib_0205ee84.h"

/* Provider allocator/free pair used by the adjacent SDK translation units. */
extern void *func_02052fe0(u32 size);
extern void func_02053000(void *allocation);
/* MSL memset/copy helpers; the argument order follows the reconstructed MSL code. */
extern void func_02008848(void *destination, int value, u32 size);
extern void func_02008904(const void *source, void *destination, u32 size);

/* Provider-owned singleton. This translation unit observes the run flag at +4,
 * the start-up phase at +8 and the per-slot status word at +0xc; the adjacent
 * SDK translation unit also uses the 24-byte record array at +0x10/+0x14. */
typedef struct {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
} Unk05ee84Provider;
extern Unk05ee84Provider data_0216b428;

/* The provider's ready predicate; callers treat a zero result as "not ready". */
extern u32 func_0205ecd8(void);
/* Provider life-cycle steps shared with the adjacent SDK translation unit.
 * func_0205111c walks the 20-byte record for the given slot index. */
extern u32 func_02050df4(void);
extern u32 func_0205111c(u32 index);
extern u32 func_0205105c(void);
extern void func_02050e80(void);
extern void func_02050668(u32 index, u32 value);

/* Drives the provider start-up state machine once per frame, mirroring
 * func_0205ede8 in the SDK translation unit: phase 0 announces readiness,
 * phase 1 polls the run state for this slot, and the default arm shuts the
 * provider down. Returns 1 when the provider is unavailable or shutting down,
 * 0 while it is still starting. */
u32 func_0205ee84(u32 index)
{
    switch (data_0216b428.unk_08) {
    case 0:
        data_0216b428.unk_0c = 0;
        if (!func_0205ecd8())
            return 1;
        if (!func_02050df4())
            return 1;
        data_0216b428.unk_08 = 1;
        data_0216b428.unk_04 = 1;
        break;
    case 1:
        data_0216b428.unk_0c = func_0205111c(index);
        if (data_0216b428.unk_0c != 2)
            data_0216b428.unk_08 = 2;
        break;
    default:
        func_02050e80();
        data_0216b428.unk_04 = 0;
        return 1;
    }
    return 0;
}

/* Starts the provider for a slot through func_02050668 and its allocator
 * setup when `enabled` is nonzero, otherwise only tears down the run flag.
 * The SaveLoadTask callers pass a slot field plus a 0/1 flag and ignore the
 * result, which is 1 on every path. */
u32 func_0205ef20(u32 index, u32 enabled)
{
    data_0216b428.unk_0c = 0;
    if (!func_0205ecd8())
        return 1;

    func_02050668(index, 0);
    if (enabled) {
        data_0216b428.unk_0c = 0;
        if (!func_02050df4())
            return 1;

        data_0216b428.unk_04 = 1;
        data_0216b428.unk_0c = func_0205105c();
        data_0216b428.unk_04 = 0;
        func_02050e80();
    }
    return 1;
}

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

/* Writes one bit at the cursor. When the buffer is null the bit is dropped but
 * the cursor still advances; when the cursor is past the capacity the call
 * returns without advancing. func_0205f168 drives single bits through this. */
void func_0205f070(BitStream05ee84 *stream, u32 bit)
{
    u32 hasRoom;

    if (stream->buffer != 0) {
        hasRoom = stream->byteIndex < stream->capacity;

        if (!hasRoom)
            return;
        if (bit & 1)
            stream->buffer[stream->byteIndex] |= 1 << stream->bitIndex;
        else
            stream->buffer[stream->byteIndex] &= ~(1 << stream->bitIndex);
    }

    stream->bitIndex++;
    if (stream->bitIndex >= 8) {
        stream->bitIndex = 0;
        stream->byteIndex++;
    }
}

/* Reads one bit at the cursor. A null buffer reads as zero but still advances
 * the cursor; a cursor past the capacity returns zero without advancing.
 * func_0205f1a0 assembles fields from these single bits. */
u32 func_0205f0f8(BitStream05ee84 *stream)
{
    u32 value = 0;
    u32 hasRoom;
    u32 byte;

    if (stream->buffer != 0) {
        hasRoom = stream->byteIndex < stream->capacity;

        if (!hasRoom)
            return 0;
        byte = stream->buffer[stream->byteIndex];

        if (byte & (1 << stream->bitIndex))
            value = 1;
    }

    stream->bitIndex++;
    if (stream->bitIndex >= 8) {
        stream->bitIndex = 0;
        stream->byteIndex++;
    }
    return value;
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
