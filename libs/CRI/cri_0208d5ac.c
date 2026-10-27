#include "types.h"

/* Start of the CRI/ADX string and formatted-output helpers below. The global at
 * data_02149544 follows data_0214953c, whose bytes begin with "RIFF"; 0x02013bfc
 * is the library's vsprintf. */

extern u32 data_02149544;
extern const char data_0214953c[];

extern s32 func_02011a00(const void *first, const void *second, u32 size);
extern void func_020119a0(void *destination, const void *source, u32 size);
extern char *func_02015134(char *destination, const char *source);
extern char *func_020151fc(char *destination, const char *source, u32 count);
extern char *func_0201524c(char *destination, const char *source);
extern char *func_0201527c(char *destination, const char *source, u32 count);
extern s32 func_02013bfc(char *buffer, const char *format, void *args);

/** Scans `size` bytes of `data` for the four-byte "RIFF" marker beginning at
 * data_0214953c, comparing at every byte offset with func_02011a00 (memcmp).
 * Writes the matched byte offset through `offset` and returns 0; when no match
 * exists writes 0 and returns -1. The candidate offset is saturated at
 * 0x7fffffff, matching the original's clamp. Evidence: data_0214953c starts
 * "RIFF", the scan stops at size - 3, and both callers pass a stack u16 as the
 * output. */
s32 func_0208d5ac(const u8 *data, s32 size, u16 *offset)
{
    s32 i;
    s32 found = 0x7fffffff;

    for (i = 0; i < size - 3; i++) {
        if (func_02011a00(data + i, data_0214953c, 4) == 0) {
            found = i < 0x7fffffff ? i : 0x7fffffff;
            break;
        }
    }
    if (found != 0x7fffffff) {
        *offset = found;
        return 0;
    }
    *offset = 0;
    return -1;
}

/* These entry points intentionally do nothing: each original is BX LR.
 * No argument, result or object layout is established by these instructions. */

/** Returns without side effects; original ARM instruction at 0x0208d62c is BX LR. */
void func_0208d62c(void)
{
    return;
}

/** Returns without side effects; original ARM instruction at 0x0208d630 is BX LR. */
void func_0208d630(void)
{
    return;
}

/** Returns without side effects; original ARM instruction at 0x0208d634 is BX LR. */
void func_0208d634(void)
{
    return;
}

/** Returns without side effects; original ARM instruction at 0x0208d638 is BX LR. */
void func_0208d638(void)
{
    return;
}

/** Returns without side effects; original ARM instruction at 0x0208d63c is BX LR. */
void func_0208d63c(void)
{
    return;
}

/** Returns without side effects; original ARM instruction at 0x0208d640 is BX LR. */
void func_0208d640(void)
{
    return;
}

/** Returns without side effects; original ARM instruction at 0x0208d644 is BX LR. */
void func_0208d644(void)
{
    return;
}

/** Returns zero: the original sets r0 to 0 at 0x0208d648 before BX LR. */
s32 func_0208d648(void)
{
    return 0;
}

/** Returns without side effects; original ARM instruction at 0x0208d650 is BX LR. */
void func_0208d650(void)
{
    return;
}

/** Returns without side effects; original ARM instruction at 0x0208d654 is BX LR. */
void func_0208d654(void)
{
    return;
}

/** Returns without side effects; original ARM instruction at 0x0208d658 is BX LR. */
void func_0208d658(void)
{
    return;
}

/** Returns without side effects; original ARM instruction at 0x0208d65c is BX LR. */
void func_0208d65c(void)
{
    return;
}

/** Returns without side effects; original ARM instruction at 0x0208d660 is BX LR. */
void func_0208d660(void)
{
    return;
}

/** Returns without side effects; original ARM instruction at 0x0208d664 is BX LR. */
void func_0208d664(void)
{
    return;
}

/** Returns without side effects; original ARM instruction at 0x0208d668 is BX LR. */
void func_0208d668(void)
{
    return;
}

/** Returns without side effects; original ARM instruction at 0x0208d66c is BX LR. */
void func_0208d66c(void)
{
    return;
}

/** Returns without side effects; original ARM instruction at 0x0208d670 is BX LR. */
void func_0208d670(void)
{
    return;
}

/** Stores the fixed value 0x0212eddc in the global at data_02149544 and returns
 * it. Evidence: the original loads the value before the global's address (so r0
 * is also the result) and stores it (0x0208d674..0x0208d688). The neighbouring
 * data at 0x0214953c begins with the bytes "RIFF". */
u32 func_0208d674(void)
{
    return data_02149544 = 0x0212eddc;
}

/** Forwards to func_02015134 (strcpy) with the caller's destination and source;
 * the second argument is not forwarded. Evidence: the original moves r2 to r1
 * before the tail call (0x0208d68c..0x0208d698). */
char *func_0208d68c(char *destination, u32 size, const char *source)
{
    return func_02015134(destination, source);
}

/** Forwards to func_020151fc (strncpy); the second argument is not forwarded.
 * Evidence: r2->r1 and r3->r2 before the tail call (0x0208d69c..0x0208d6ac). */
char *func_0208d69c(char *destination, u32 size, const char *source, u32 count)
{
    return func_020151fc(destination, source, count);
}

/** Forwards to func_0201524c (strcat); the second argument is not forwarded.
 * Evidence: the original moves r2 to r1 before the tail call
 * (0x0208d6b0..0x0208d6bc). */
char *func_0208d6b0(char *destination, u32 size, const char *source)
{
    return func_0201524c(destination, source);
}

/** Forwards to func_0201527c (strncat); the second argument is not forwarded.
 * Evidence: r2->r1 and r3->r2 before the tail call (0x0208d6c0..0x0208d6d0). */
char *func_0208d6c0(char *destination, u32 size, const char *source, u32 count)
{
    return func_0201527c(destination, source, count);
}

/** Unbounded formatted output: forwards the third fixed argument as the format
 * and the following words as the argument list to func_02013bfc (vsprintf).
 * Evidence: the varargs prologue rounds &format and adds one word, the standard
 * AAPCS layout used by the MSL sprintf at 0x02013c3c (0x0208d6d4..0x0208d6f4). */
s32 func_0208d6d4(char *buffer, u32 size, const char *format, ...)
{
    void *args = (void *)(((u32)&format & ~3u) + sizeof(format));
    return func_02013bfc(buffer, format, args);
}

/** Formatted output from an existing argument list. Forwards the destination,
 * the third fixed argument (format) and the argument list; the second argument
 * is not forwarded. Evidence: r2->r1 and r3->r2 before the tail call
 * (0x0208d6fc..0x0208d70c). */
s32 func_0208d6fc(char *buffer, u32 size, const char *format, void *args)
{
    return func_02013bfc(buffer, format, args);
}

/** Resamples a 16-bit mono block from `srcLength` to `dstLength` samples by
 * linearly blending the region that the two lengths share: an output shorter
 * than the input crossfades the head with the tail, and an output longer than
 * the input crossfades the overlap before copying the remainder. Equal lengths
 * are a plain func_020119a0 (memcpy) of dstLength * 2 bytes. Each blended value
 * is clamped to the signed 16-bit range. Evidence: all accesses are LDRSH/STRH,
 * every blended sample is two signed _s32_div_f divisions of the form
 * (m - i) * x / m and i * y / m, and the equal-length path passes dstLength * 2
 * to func_020119a0 (0x0208d710..0x0208d8e4). */
void func_0208d710(s16 *src, s32 srcLength, s16 *dst, s32 dstLength)
{
    s32 i;
    s32 n;
    s32 m;

    if (srcLength < dstLength) {
        n = dstLength - srcLength;
        m = srcLength - n;
        for (i = 0; i < n; i++)
            dst[i] = src[i];
        for (i = 0; i < m; i++) {
            s16 first = ((m - i) * src[n + i]) / m;
            s16 second = (i * src[i]) / m;
            s32 value = first + second;
            if (value > 32767)
                value = 32767;
            else if (value < -32768)
                value = -32768;
            dst[n + i] = value;
        }
        for (i = 0; i < n; i++)
            dst[srcLength + i] = src[m + i];
        return;
    }
    if (srcLength == dstLength) {
        func_020119a0(dst, src, dstLength * 2);
        return;
    }
    if (srcLength > dstLength) {
        n = srcLength - dstLength;
        for (i = 0; i < dstLength; i++) {
            s16 first = (src[i] * (dstLength - i)) / dstLength;
            s16 second = (i * src[n + i]) / dstLength;
            s32 value = first + second;
            if (value > 32767)
                value = 32767;
            else if (value < -32768)
                value = -32768;
            dst[i] = value;
        }
    }
}
