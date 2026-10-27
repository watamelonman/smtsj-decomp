#ifndef LIB_0205EE84_H
#define LIB_0205EE84_H
#include "types.h"

/* Bit-stream state. The delinked object shows a 16-byte header whose word at +0
 * points at byte storage, +4 is the byte capacity, +8 the current byte and +0xc
 * the current bit (0..7). func_0205efc8 allocates the header and payload as one
 * block, so the buffer points 16 bytes past the same allocation. */
typedef struct BitStream05ee84 {
    u8 *buffer;
    u32 capacity;
    u32 byteIndex;
    u32 bitIndex;
} BitStream05ee84;

/* Allocates a zeroed stream of `bytes` payload bytes; caller owns the result. */
BitStream05ee84 *func_0205efc8(u32 bytes);
/* Wraps caller-owned byte storage in a fresh zeroed 16-byte stream header. */
BitStream05ee84 *func_0205f004(u8 *buffer, u32 bytes);
/* Returns the provider state word at +0xc, or 3 while the provider is inactive. */
u32 func_0205efa8(void);
/* Releases a stream created by func_0205efc8 or func_0205f004. */
void func_0205f038(BitStream05ee84 *stream);
/* Copies the whole payload into the stream buffer; source is borrowed. */
void func_0205f044(BitStream05ee84 *stream, const void *source);
/* Copies the whole payload out of the stream buffer; destination is caller-owned. */
void func_0205f05c(BitStream05ee84 *stream, void *destination);
/* Writes the low `bits` bits of value, least significant bit first. */
void func_0205f168(BitStream05ee84 *stream, u32 value, u32 bits);
/* Reads `bits` bits least significant bit first, returning them in the low bits. */
u32 func_0205f1a0(BitStream05ee84 *stream, u32 bits);

#endif
