#include "libs/MSL/msl_02012aa4.h"

/** Shared output state for the MSL formatted-output engine.
 * `position` counts the bytes emitted so far and never exceeds `size`, because
 * the write callback clips each request to the remaining capacity. */
typedef struct MslOutBuffer {
    char *buffer;
    u32 size;
    u32 position;
} MslOutBuffer;

/** Reader state for the MSL formatted-input engine. `input` is the current
 * cursor and `atEnd` records that the cursor reached the terminator. */
typedef struct MslInBuffer {
    const s8 *input;
    s32 atEnd;
} MslInBuffer;

/** Byte copy used throughout the MSL runtime (memcpy). */
extern void *func_020119a0(void *destination, const void *source, u32 length);

/** The MSL formatted-output engine; args points at the first variadic word.
 * The callback receives this module's output state, a byte range and returns
 * nonzero on success. */
extern s32 func_0201332c(s32 (*write)(MslOutBuffer *, const void *, u32),
                         MslOutBuffer *state, const char *format, void *args);

/** The MSL formatted-input engine; args points at the first variadic word.
 * The trailing mode argument selects the scanner variant; vsscanf passes 0. */
extern s32 func_020142c4(s32 (*read)(MslInBuffer *, s32), MslInBuffer *state,
                         const char *format, void *args, s32 mode);

/** Character/seek callback used by the MSL scanner. */
extern s32 func_02015018(MslInBuffer *state, s32 operation);

/** Bounded write callback: append `length` bytes from `source` to the state's
 * buffer, clipping to the remaining capacity, then advance the position.
 * Returns 1 unconditionally, because the formatter only needs to know that the
 * sink accepted the request; the null-buffer guard lives in func_02013b94.
 * Evidence: the formatter calls this with the state and a byte range, and every
 * path returns the constant 1. */
s32 func_02013b50(MslOutBuffer *state, const void *source, u32 length)
{
    if (state->position + length > state->size)
        length = state->size - state->position;
    func_020119a0(state->buffer + state->position, source, length);
    state->position += length;
    return 1;
}

/** vsnprintf core: format into `buffer`, always NUL-terminating when the buffer
 * is non-null and `size` permits (an exactly full buffer keeps its last byte
 * for the terminator). Returns the formatter's result, which may exceed `size`.
 * Evidence: func_02013bfc forwards size -1, while func_02013c14/func_02013c3c
 * share this argument layout and clamp behaviour. */
s32 func_02013b94(char *buffer, u32 size, const char *format, void *args)
{
    MslOutBuffer state;
    s32 result;

    state.buffer = buffer;
    state.size = size;
    state.position = 0;
    result = func_0201332c(func_02013b50, &state, format, args);

    if (buffer != 0) {
        if (result < size)
            buffer[result] = 0;
        else if (size != 0)
            *(buffer + size - 1) = 0;
    }
    return result;
}

/** vsprintf: format with no size limit.
 * Evidence: tail-calls func_02013b94 with size -1, the MSL vsnprintf contract. */
s32 func_02013bfc(char *buffer, const char *format, void *args)
{
    return func_02013b94(buffer, -1, format, args);
}

/** snprintf: bounded formatted output.
 * The pushed register block and rounded address of the last named argument
 * identify the standard AAPCS varargs prologue used by MSL. */
s32 func_02013c14(char *buffer, u32 size, const char *format, ...)
{
    void *args = (void *)(((u32)&format & ~3u) + sizeof(format));
    return func_02013b94(buffer, size, format, args);
}

/** sprintf: unbounded formatted output.
 * Evidence: same varargs prologue as snprintf, with size forced to -1. */
s32 func_02013c3c(char *buffer, const char *format, ...)
{
    void *args = (void *)(((u32)&format & ~3u) + sizeof(format));
    return func_02013b94(buffer, -1, format, args);
}

/** vsscanf core: scan `input` according to `format` and store the converted
 * values through `args`. Returns -1 for a null or empty input, like MSL.
 * Evidence: func_020150f0 forwards its varargs here, and every caller passes a
 * string to scan rather than a stream. */
s32 func_0201509c(const s8 *input, const char *format, void *args)
{
    MslInBuffer state;

    state.input = input;
    if (input == 0 || *input == 0)
        return -1;
    state.atEnd = 0;
    return func_020142c4(func_02015018, &state, format, args, 0);
}

/** sscanf: formatted input from a string.
 * Evidence: forwards the caller's format and varargs to func_0201509c, whose
 * first check rejects a null or empty input string before scanning. */
s32 func_020150f0(const s8 *input, const char *format, ...)
{
    void *args = (void *)(((u32)&format & ~3u) + sizeof(format));
    return func_0201509c(input, format, args);
}

/** strlen: count bytes up to, but not including, the NUL terminator. */
s32 func_02015118(const char *string)
{
    const s8 *cursor = (const s8 *)string;
    s32 length = -1;
    do {
        length++;
    } while (*cursor++ != 0);
    return length;
}

/** strncpy: copy at most `count` bytes from `source` to `destination`.
 * The NUL terminator is copied when it occurs within `count`; otherwise the
 * rest of the destination range is zero-filled. Returns `destination`.
 * Evidence: the byte-at-a-time copy-then-pad sequence is the Standard C
 * contract, and the padding loop writes exactly the remaining count. */
s8 *func_020151fc(s8 *destination, const s8 *source, u32 count)
{
    s8 *dst = destination;

    if (count != 0) {
        do {
            if ((*dst++ = *source++) == 0) {
                while (--count != 0)
                    *dst++ = 0;
                return destination;
            }
        } while (--count != 0);
    }
    return destination;
}

/** strcat: find the destination terminator, then copy the source onto it.
 * The return value is the untouched destination pointer, as in Standard C. */
s8 *func_0201524c(s8 *destination, const s8 *source)
{
    s8 *cursor = destination;

    while (*cursor++ != 0) {
        ;
    }
    cursor--;
    while ((*cursor++ = *source++) != 0) {
        ;
    }
    return destination;
}

/** strncat: append at most `count` bytes from `source` to the destination and
 * always NUL-terminate the result. Returns `destination`.
 * Evidence: after locating the destination terminator it copies while the
 * source is non-empty and count remains, then stores one NUL. */
s8 *func_0201527c(s8 *destination, const s8 *source, u32 count)
{
    s8 *s = destination;

    while (*s++ != 0) {
        ;
    }
    s--;
    if (count != 0) {
        do {
            if ((*s++ = *source++) == 0) {
                s--;
                break;
            }
        } while (--count != 0);
    }
    *s = 0;
    return destination;
}

/** strncmp: compare up to count bytes, stopping at a mismatch or both NULs.
 * Returns the signed difference of the first differing unsigned byte pair. */
s32 func_020153e0(const char *left, const char *right, u32 count)
{
    u8 a;
    u8 b;

    if (count != 0) {
        do {
            b = (u8)*right++;
            a = (u8)*left++;
            if (a != b) {
                return a - b;
            }
            if (a == 0) {
                break;
            }
        } while (--count != 0);
    }
    return 0;
}

/** strchr: find the first occurrence of `character` in `string`.
 * A zero character matches the terminator; otherwise a missing character
 * returns null. Evidence: the loop tests the loaded byte for zero before
 * comparing it, and the zero-character case returns the terminator pointer. */
s8 *func_02015414(const s8 *string, int character)
{
    s8 c;

    character = (s8)character;
    while ((c = *string++) != 0) {
        if (c == character)
            return (s8 *)string - 1;
    }
    if (character != 0)
        return 0;
    return (s8 *)string - 1;
}

/** strrchr: find the last occurrence of `character` in `string`.
 * A zero character matches the terminator; otherwise a missing character
 * returns null. Evidence: the pointer advances past each byte while a separate
 * result slot keeps the most recent match. */
s8 *func_02015450(const s8 *string, int character)
{
    s8 *found = 0;
    s8 c;
    s8 *p;

    character = (s8)character;
    p = (s8 *)string + 1;
    c = string[0];
    while (c != 0) {
        if (c == character)
            found = p - 1;
        c = *p++;
    }
    if (found != 0)
        return found;
    if (character != 0)
        return 0;
    return p - 1;
}

/** strstr: find the first occurrence of `substring` in `string`.
 * An empty substring matches at the start, a missing substring returns null,
 * and comparison stops as soon as the candidate cannot contain the substring.
 * Evidence: the inner loop walks both strings in lockstep and only reports a
 * match when the substring cursor lands on its terminator. */
u8 *func_02015498(const u8 *string, const u8 *substring)
{
    const u8 *p = string;
    const u8 *next;
    u8 first;
    u8 c;

    if (substring == 0 || *substring == 0)
        return (u8 *)p;
    first = *substring;
    next = p + 1;
    c = *p;
    while (c != 0) {
        if (c == first) {
            const u8 *a = next;
            const u8 *b = substring + 1;
            u8 ca, cb;

            do {
                cb = *b++;
                ca = *a++;
            } while (ca == cb && ca != 0);
            if (cb == 0)
                return (u8 *)(next - 1);
        }
        c = *next++;
    }
    return 0;
}
