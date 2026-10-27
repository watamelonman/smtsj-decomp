#include "types.h"

/* Start of the CRI/ADX string and formatted-output helpers below. The global at
 * data_02149544 follows data_0214953c, whose bytes begin with "RIFF"; 0x02013bfc
 * is the library's vsprintf. */

extern u32 data_02149544;

extern char *func_02015134(char *destination, const char *source);
extern char *func_020151fc(char *destination, const char *source, u32 count);
extern char *func_0201524c(char *destination, const char *source);
extern char *func_0201527c(char *destination, const char *source, u32 count);
extern s32 func_02013bfc(char *buffer, const char *format, void *args);

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
