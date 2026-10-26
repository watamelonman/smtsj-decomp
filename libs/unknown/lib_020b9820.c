/* Script request wrappers; evidence: argument reads through func_0203ac00,
 * request fields stored by func_020b8b38, and result store at 0203acf4. */
#include "types.h"

/* Reads a signed 32-bit operand from the current script context. */
extern s32 func_0203ac00(s32 index);
/* Submits four request words and returns a Boolean result. */
extern s32 func_020b8b38(s32 request, s32 first, s32 second, s32 third);
/* Writes the implicit script result; no explicit context is passed. */
extern void Unk03aae8_Unk_03acf4(s32 result);

/* At 020b9820: submit request 61 with operands 0 and 1,
 * publish its result, and return script completion status 1. */
s32 func_020b9820(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(61, first, second, 0));
    return 1;
}

/* At 020b9858: submit request 62 with operands 0 and 1,
 * publish its result, and return script completion status 1. */
s32 func_020b9858(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(62, first, second, 0));
    return 1;
}

/* At 020b9890: submit request 63 with operands 0 and 1,
 * publish its result, and return script completion status 1. */
s32 func_020b9890(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(63, first, second, 0));
    return 1;
}

/* At 020b98c8: submit request 64 with operands 0 and 1,
 * publish its result, and return script completion status 1. */
s32 func_020b98c8(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(64, first, second, 0));
    return 1;
}

/* At 020b9900: submit request 65 with operands 0 and 1,
 * publish its result, and return script completion status 1. */
s32 func_020b9900(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(65, first, second, 0));
    return 1;
}

/* At 020b9938: submit request 66 with operands 0 and 1,
 * publish its result, and return script completion status 1. */
s32 func_020b9938(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(66, first, second, 0));
    return 1;
}

/* At 020b99a8: submit request 68 with operand 0,
 * publish its result, and return script completion status 1. */
s32 func_020b99a8(void)
{
    s32 first = func_0203ac00(0);
    Unk03aae8_Unk_03acf4(func_020b8b38(68, first, 0, 0));
    return 1;
}

/* At 020b99d4: submit request 69 with operand 0,
 * publish its result, and return script completion status 1. */
s32 func_020b99d4(void)
{
    s32 first = func_0203ac00(0);
    Unk03aae8_Unk_03acf4(func_020b8b38(69, first, 0, 0));
    return 1;
}

