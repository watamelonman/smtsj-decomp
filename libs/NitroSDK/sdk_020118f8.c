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

/* Borrowed SDK ASCII character-class table (digit bit is 8). */
extern const u16 data_0212b01c[];
/** MSL flag values stored in the one-byte justification field. */
enum justification_options { left_justification, right_justification, zero_fill };
/** Plus takes precedence over a space while parsing sign flags. */
enum sign_options { only_minus, sign_always, space_holder };
/** Target MSL length codes; C99 integer modifiers occupy values six to eight. */
enum argument_options {
    normal_argument,
    char_argument,
    short_argument,
    long_argument,
    long_long_argument,
    wchar_argument,
    intmax_argument,
    size_argument,
    ptrdiff_argument,
    long_double_argument
};
/** Caller-owned 16-byte parse result; conversion 0xff denotes invalid input. */
typedef struct {
    unsigned char justification_options;
    unsigned char sign_options;
    unsigned char precision_specified;
    unsigned char alternate_form;
    unsigned char argument_options;
    unsigned char conversion_char;
    int field_width;
    int precision;
} print_format;
/** Parses one printf conversion; MSL parse_format (doldecomp/melee src/MSL/printf.c)
 * and the original flag/width
 * stores establish its role. Argument cursor and 16-byte result are caller-owned;
 * Signed byte reads preserve the original handling of non-ASCII input.
 * Returns the first byte after the conversion and marks invalid formats 0xff. */
const s8* func_02011af0(const s8* format_string, int **arg,
                                print_format* format)
{
    print_format f;
    const s8* s = format_string;
    int c;
    int flag_found;
    f.justification_options = right_justification;
    f.sign_options = only_minus;
    f.precision_specified = 0;
    f.alternate_form = 0;
    f.argument_options = normal_argument;
    f.field_width = 0;
    f.precision = 0;
    if ((c = *++s) == '%') {
        f.conversion_char = c;
        *format = f;
        return (s + 1);
    }
    for (;;) {
        flag_found = 1;
        switch (c) {
        case '-':
            f.justification_options = left_justification;
            break;
        case '+':
            f.sign_options = sign_always;
            break;
        case ' ':
            if (f.sign_options != sign_always) {
                f.sign_options = space_holder;
            }
            break;
        case '#':
            f.alternate_form = 1;
            break;
        case '0':
            if (f.justification_options != left_justification) {
                f.justification_options = zero_fill;
            }
            break;
        default:
            flag_found = 0;
            break;
        }
        if (flag_found) {
            c = *++s;
        } else {
            break;
        }
    }
    if (c == '*') {
        if ((f.field_width = (*arg += 1)[-1]) < 0) {
            f.justification_options = left_justification;
            f.field_width = -f.field_width;
        }
        c = *++s;
    } else {
        while ((c < 0 || c >= 128 ? 0 : data_0212b01c[c] & 8)) {
            f.field_width = (f.field_width * 10) + (c - '0');
            c = *++s;
        }
    }
    if (f.field_width > 509) {
        f.conversion_char = 0xFF;
        *format = f;
        return (s + 1);
    }
    if (c == '.') {
        f.precision_specified = 1;
        if ((c = *++s) == '*') {
            if ((f.precision = (*arg += 1)[-1]) < 0) {
                f.precision_specified = 0;
            }
            c = *++s;
        } else {
            while ((c < 0 || c >= 128 ? 0 : data_0212b01c[c] & 8)) {
                f.precision = (f.precision * 10) + (c - '0');
                c = *++s;
            }
        }
    }
    flag_found = 1;
    switch (c) {
    case 'h':
        f.argument_options = short_argument;
        if (s[1] == 'h') {
            f.argument_options = char_argument;
            c = *++s;
        }
        break;
    case 'l':
        f.argument_options = long_argument;
        if (s[1] == 'l') {
            f.argument_options = long_long_argument;
            c = *++s;
        }
        break;
    case 'L':
        f.argument_options = long_double_argument;
        break;
    case 'j':
        f.argument_options = intmax_argument;
        break;
    case 't':
        f.argument_options = ptrdiff_argument;
        break;
    case 'z':
        f.argument_options = size_argument;
        break;
    default:
        flag_found = 0;
        break;
    }
    if (flag_found) {
        c = *++s;
    }
    f.conversion_char = c;
    switch (c) {
    case 'd':
    case 'i':
    case 'u':
    case 'o':
    case 'x':
    case 'X':
        if (f.argument_options == long_double_argument) {
            f.conversion_char = 0xFF;
            break;
        }
        if (!f.precision_specified) {
            f.precision = 1;
        } else if (f.justification_options == zero_fill) {
            f.justification_options = right_justification;
        }
        break;
    case 'F':
    case 'f':
        if (f.argument_options == short_argument ||
            f.argument_options == intmax_argument ||
            f.argument_options == size_argument ||
            f.argument_options == ptrdiff_argument ||
            f.argument_options == long_long_argument)
        {
            f.conversion_char = 0xFF;
            break;
        }
        if (!f.precision_specified) {
            f.precision = 6;
        }
        break;
    case 'a':
    case 'A':
        if (!f.precision_specified) f.precision = 13;
        if (f.argument_options == short_argument ||
            f.argument_options == intmax_argument ||
            f.argument_options == size_argument ||
            f.argument_options == ptrdiff_argument ||
            f.argument_options == long_long_argument ||
            f.argument_options == char_argument) f.conversion_char = 0xFF;
        break;
    case 'g':
    case 'G':
        if (!f.precision) {
            f.precision = 1;
        }
    case 'e':
    case 'E':
        if (f.argument_options == short_argument ||
            f.argument_options == intmax_argument ||
            f.argument_options == size_argument ||
            f.argument_options == ptrdiff_argument ||
            f.argument_options == long_long_argument ||
            f.argument_options == char_argument)
        {
            f.conversion_char = 0xFF;
            break;
        }
        if (!f.precision_specified) {
            f.precision = 6;
        }
        break;
    case 'p':
        f.conversion_char = 'x';
        f.alternate_form = 1;
        f.argument_options = long_argument;
        f.precision = 8;
        break;
    case 'c':
        if (f.argument_options == long_argument) {
            f.argument_options = wchar_argument;
        } else {
            if (f.precision_specified || f.argument_options != normal_argument)
            {
                f.conversion_char = 0xFF;
            }
        }
        break;
    case 's':
        if (f.argument_options == long_argument) {
            f.argument_options = wchar_argument;
        } else {
            if (f.argument_options != normal_argument) {
                f.conversion_char = 0xFF;
            }
        }
        break;
    case 'n':
        if (f.argument_options == long_double_argument) {
            f.conversion_char = 0xFF;
        }
        break;
    default:
        f.conversion_char = 0xFF;
        break;
    }
    *format = f;
    return (s + 1);
}
