#include "libs/MSL/msl_02012aa4.h"

/** The MSL formatted-output engine; args points at the first variadic word. */
extern s32 func_02013b94(char *buffer, s32 size, const char *format, void *args);
/** The MSL formatted-input engine; args points at the first variadic word. */
extern s32 func_0201509c(const char *input, const char *format, void *args);

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

/** sscanf: formatted input from a string.
 * Evidence: forwards the caller's format and varargs to func_0201509c, whose
 * first check rejects a null or empty input string before scanning. */
s32 func_020150f0(const char *input, const char *format, ...)
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
