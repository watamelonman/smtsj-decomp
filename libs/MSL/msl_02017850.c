#include "libs/MSL/msl_02017850.h"

/** MSL double-precision routine; the thunks only forward to it. */
extern double func_02017058(double value);
/** MSL double-precision routine; the thunks only forward to it. */
extern double func_02017850(double value);
/** MSL double-precision routine; the thunks only forward to it. */
extern double func_020186d4(double value);
/** MSL double-precision routine; the thunks only forward to it. */
extern double func_020188ac(double value);

/** MSL heap operation: arena index, heap index and block pointer.
 * A negative heap index selects the arena's default heap, which is how the
 * free wrapper below reaches the allocator. */
extern s32 func_02007170(s32 arena, s32 heap, void *block);

/** Forward a double to func_02017058.
 * Evidence: the body loads the target address and branches with the argument
 * registers untouched, and libs/CRI callers pass a double produced by _f2d. */
double func_0201ba48(double value)
{
    return func_02017058(value);
}

/** Forward a double to func_02017850.
 * Evidence: same untouched-register tail call; the caller in
 * libs/CRI/cri_0208aba0.c passes the result of _f2d. */
double func_0201ba54(double value)
{
    return func_02017850(value);
}

/** Forward a double to func_020186d4.
 * Evidence: same untouched-register tail call and a double argument at every
 * libs/CRI call site. */
double func_0201ba60(double value)
{
    return func_020186d4(value);
}

/** Forward a double to func_020188ac.
 * Evidence: same untouched-register tail call and a double argument at every
 * libs/CRI call site. */
double func_0201ba6c(double value)
{
    return func_020188ac(value);
}

/** Do nothing.
 * Evidence: the delinked body is a single `bx lr`, so the routine has no
 * observable effect; the name stays neutral because no caller identifies it. */
void func_0201bb30(void)
{
}

/** Reinterpret a double as its two 32-bit words for bit tests. */
typedef union MslDoubleBits {
    double value;
    u32 words[2];
} MslDoubleBits;

/** Return the sign bit of `value` as an s32.
 * Evidence: the high word of the double argument is masked with 0x80000000.
 * The argument is spilled to the stack because the code inspects its
 * representation; aliasing the parameter is what produces the 16-byte save. */
s32 func_0201cf28(double value)
{
    return ((MslDoubleBits *)&value)->words[1] & 0x80000000;
}

/** Release `block` through MSL's arena allocator.
 * Evidence: forwards arena 0 and heap -1 to func_02007170, the MSL allocation
 * entry point; func_020117f0 calls it only for a non-null pointer and discards
 * the result, as free does. */
s32 func_0201cfd8(void *block)
{
    return func_02007170(0, -1, block);
}

/** Return the largest positive signed 32-bit value.
 * Evidence: the body complements 0x80000000, leaving 0x7fffffff. */
s32 func_0201e048(void)
{
    return 0x7fffffff;
}
