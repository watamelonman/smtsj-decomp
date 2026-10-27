#include "libs/MSL/msl_0201703c.h"

/** Count 16-bit code units before the terminator; the caller owns readable storage.
 * Evidence: halfword loads and a zero-terminated scan identify wcslen semantics. */
unsigned int func_0201703c(const unsigned short *text)
{
    unsigned int count = -1;
    do { count++; } while (*text++ != 0);
    return count;
}

