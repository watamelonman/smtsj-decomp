#include "types.h"

/* Evidence: 020b8b18 stores selector as a halfword at shared-record +0x0c
 * and value as a word at +0x10. Selector meanings remain unidentified. */
extern void func_020b8b18(u32 selector, u32 value);

/* Reads a zero-based operand from the implicit current script context. */
extern s32 func_0203ac00(s32 index);

/* Evidence: original 0x020ba0a4 passes (1, 0) to 020b8b18 and returns 1.
 * No incoming arguments are consumed; the helper's result is ignored. */
s32 func_020ba0a4(void)
{
    func_020b8b18(1, 0);
    return 1;
}

/* Evidence: original 0x020ba0bc passes (2, 0) to 020b8b18 and returns 1.
 * No incoming arguments are consumed; the helper's result is ignored. */
s32 func_020ba0bc(void)
{
    func_020b8b18(2, 0);
    return 1;
}

/* Evidence: original 0x020ba0d4 passes (3, 0) to 020b8b18 and returns 1.
 * No incoming arguments are consumed; the helper's result is ignored. */
s32 func_020ba0d4(void)
{
    func_020b8b18(3, 0);
    return 1;
}

/* Evidence: original 0x020ba0ec passes (4, 0) to 020b8b18 and returns 1.
 * No incoming arguments are consumed; the helper's result is ignored. */
s32 func_020ba0ec(void)
{
    func_020b8b18(4, 0);
    return 1;
}

/* Evidence: original 0x020ba104 passes (5, 0) to 020b8b18 and returns 1.
 * No incoming arguments are consumed; the helper's result is ignored. */
s32 func_020ba104(void)
{
    func_020b8b18(5, 0);
    return 1;
}

/* Evidence: original 0x020ba11c passes (6, 0) to 020b8b18 and returns 1.
 * No incoming arguments are consumed; the helper's result is ignored. */
s32 func_020ba11c(void)
{
    func_020b8b18(6, 0);
    return 1;
}

/* Evidence: original 0x020ba1b4 passes (11, 0) to 020b8b18 and returns 1.
 * No incoming arguments are consumed; the helper's result is ignored. */
s32 func_020ba1b4(void)
{
    func_020b8b18(11, 0);
    return 1;
}

/* Evidence: original 0x020ba1cc passes (12, 0) to 020b8b18 and returns 1.
 * No incoming arguments are consumed; the helper's result is ignored. */
s32 func_020ba1cc(void)
{
    func_020b8b18(12, 0);
    return 1;
}

/* Evidence: ARM 0x020ba134 reads operand zero with 0203ac00, then
 * stores selector 7 and that full 32-bit value through 020b8b18.
 * Uses the implicit script context; returns completion 1. */
s32 func_020ba134(void)
{
    s32 value = func_0203ac00(0);
    func_020b8b18(7, value);
    return 1;
}

/* Evidence: ARM 0x020ba154 reads operand zero with 0203ac00, then
 * stores selector 8 and that full 32-bit value through 020b8b18.
 * Uses the implicit script context; returns completion 1. */
s32 func_020ba154(void)
{
    s32 value = func_0203ac00(0);
    func_020b8b18(8, value);
    return 1;
}

/* Evidence: ARM 0x020ba174 reads operand zero with 0203ac00, then
 * stores selector 9 and that full 32-bit value through 020b8b18.
 * Uses the implicit script context; returns completion 1. */
s32 func_020ba174(void)
{
    s32 value = func_0203ac00(0);
    func_020b8b18(9, value);
    return 1;
}

/* Evidence: ARM 0x020ba194 reads operand zero with 0203ac00, then
 * stores selector 10 and that full 32-bit value through 020b8b18.
 * Uses the implicit script context; returns completion 1. */
s32 func_020ba194(void)
{
    s32 value = func_0203ac00(0);
    func_020b8b18(10, value);
    return 1;
}

/* Evidence: ARM 0x020ba1e4 reads operand zero with 0203ac00, then
 * stores selector 13 and that full 32-bit value through 020b8b18.
 * Uses the implicit script context; returns completion 1. */
s32 func_020ba1e4(void)
{
    s32 value = func_0203ac00(0);
    func_020b8b18(13, value);
    return 1;
}

/* Evidence: ARM 0x020ba204 reads operand zero with 0203ac00, then
 * stores selector 14 and that full 32-bit value through 020b8b18.
 * Uses the implicit script context; returns completion 1. */
s32 func_020ba204(void)
{
    s32 value = func_0203ac00(0);
    func_020b8b18(14, value);
    return 1;
}

/* Evidence: ARM 0x020ba224 reads operand zero with 0203ac00, then
 * stores selector 15 and that full 32-bit value through 020b8b18.
 * Uses the implicit script context; returns completion 1. */
s32 func_020ba224(void)
{
    s32 value = func_0203ac00(0);
    func_020b8b18(15, value);
    return 1;
}

/* Evidence: ARM 0x020ba244 reads operand zero with 0203ac00, then
 * stores selector 16 and that full 32-bit value through 020b8b18.
 * Uses the implicit script context; returns completion 1. */
s32 func_020ba244(void)
{
    s32 value = func_0203ac00(0);
    func_020b8b18(16, value);
    return 1;
}
