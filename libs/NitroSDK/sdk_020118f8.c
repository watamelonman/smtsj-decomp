#include "types.h"

/** Borrowed locale prefix: the conversion table is selected at offset eight. */
typedef struct {
    void *prefix[2];
    struct {
        int (*mbtowc)(u16 *, const char *, u32);
        int (*wctomb)(char *, u16);
    } *codeset;
} Locale118f8;
extern Locale118f8 data_0213cff4;
extern void *func_020151fc(void *destination, const void *source, u32 size);
void func_02011a40(void *destination, int value, u32 size);

/** Single-byte wctomb: the inverse byte conversion and locale table in
 * sdk_020116a8 establish the encoding; null output reports no shift state. */
int func_020118f8(char *destination, u16 value)
{
    if (destination == 0)
        return 0;
    *destination = value;
    return 1;
}

/** Dispatches wctomb through the second entry of the active locale table. */
int func_0201190c(char *destination, u16 value)
{
    return data_0213cff4.codeset->wctomb(destination, value);
}

/** Converts wide text using the locale thunk above. The original permits a
 * terminator at the byte limit; callers must reserve its storage separately. */
u32 func_02011928(char *destination, const u16 *source, u32 limit)
{
    u32 count = 0;
    char buffer[4];
    int size;
    if (destination == 0 || source == 0)
        return 0;
    do {
        if (*source == 0) {
            destination[count] = 0;
            break;
        }
        size = func_0201190c(buffer, *source++);
        if (count + size > limit)
            break;
        func_020151fc(destination + count, buffer, size);
        count += size;
    } while (count <= limit);
    return count;
}

/** Byte copy returning the original destination; signed byte loads match the
 * original memcpy loop (also called by the MSL buffer writer). */
void *func_020119a0(void *destination, const void *source, u32 size)
{
    s8 *out = destination;
    const s8 *in = source;
    if (size != 0) {
        do { *out++ = *in++; } while (--size != 0);
    }
    return destination;
}

/** memset wrapper: returns caller storage after invoking the fill provider. */
void *func_020119c0(void *destination, int value, u32 size)
{
    func_02011a40(destination, value, size);
    return destination;
}

/** Searches unsigned bytes for the low byte of value, returning a borrowed
 * pointer to its first occurrence or null after size bytes. */
void *func_020119d4(const void *source, int value, u32 size)
{
    const u8 *p = source;
    u32 byte = (u8)value;
    if (size != 0) {
        do {
            if (*p++ == byte)
                return (void *)(p - 1);
        } while (--size != 0);
    }
    return 0;
}

/** Compares unsigned bytes, returning only -1, zero or +1; the CRI signature
 * scanner calls this routine to compare four-byte resource identifiers. */
int func_02011a00(const void *first, const void *second, u32 size)
{
    const u8 *a = first;
    const u8 *b = second;
    if (size != 0) {
        do {
            if (*a++ != *b++)
                return a[-1] < b[-1] ? -1 : 1;
        } while (--size != 0);
    }
    return 0;
}

/** Fills caller-owned bytes, aligning large writes before eight-word blocks;
 * its memset wrapper above establishes the value/length contract. */
void func_02011a40(void *destination, int value, u32 size)
{
    u8 *p = destination;
    u32 word = (u8)value;
    u32 count;
    if (size >= 32) {
        count = -(u32)p & 3;
        if (count != 0) {
            size -= count;
            do { *p++ = word; } while (--count != 0);
        }
        if (word != 0)
            word |= (word << 24) | (word << 16) | (word << 8);
        count = size >> 5;
        if (count != 0) {
            do {
                ((u32 *)p)[0] = word;
                ((u32 *)p)[1] = word;
                ((u32 *)p)[2] = word;
                ((u32 *)p)[3] = word;
                ((u32 *)p)[4] = word;
                ((u32 *)p)[5] = word;
                ((u32 *)p)[6] = word;
                ((u32 *)p)[7] = word;
                p += 32;
            } while (--count != 0);
        }
        count = (size & 31) >> 2;
        if (count != 0) {
            do {
                *(u32 *)p = word;
                p += 4;
            } while (--count != 0);
        }
        size &= 3;
    }
    if (size != 0) {
        do { *p++ = word; } while (--size != 0);
    }
}
