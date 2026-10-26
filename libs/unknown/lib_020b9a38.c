#include "types.h"

/* Read an indexed operand from the current script context. */
extern s32 func_0203ac00(u32 index);
/* Submit four words to the current work record and return its boolean result. */
extern s32 func_020b8b38(s32 code, s32 first, s32 second, s32 fourth);
/* Store the result in the current script context; ownership stays with the runtime. */
extern void Unk03aae8_Unk_03acf4(s32 result);

/* ARM evidence at 020b9a38: submit code 71 with operands 0/1 and zero,
 * publish the result through 0203acf4, and return completion status 1. */
s32 func_020b9a38(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(71, first, second, 0));
    return 1;
}

/* ARM evidence at 020b9a70: submit code 72 with operands 0/1 and zero,
 * publish the result through 0203acf4, and return completion status 1. */
s32 func_020b9a70(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(72, first, second, 0));
    return 1;
}

/* ARM evidence at 020b9aa8: submit code 73 with operands 0/1 and zero,
 * publish the result through 0203acf4, and return completion status 1. */
s32 func_020b9aa8(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(73, first, second, 0));
    return 1;
}

/* ARM evidence at 020b9ae0: submit code 74 with operands 0/1 and zero,
 * publish the result through 0203acf4, and return completion status 1. */
s32 func_020b9ae0(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(74, first, second, 0));
    return 1;
}

/* ARM evidence at 020b9b18: submit code 75 with operands 0/1/2,
 * publish the result through 0203acf4, and return completion status 1. */
s32 func_020b9b18(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    s32 third = func_0203ac00(2);
    Unk03aae8_Unk_03acf4(func_020b8b38(75, first, second, third));
    return 1;
}

/* ARM evidence at 020b9b5c: submit code 76 with operands 0/1 and zero,
 * publish the result through 0203acf4, and return completion status 1. */
s32 func_020b9b5c(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(76, first, second, 0));
    return 1;
}

/* ARM evidence at 020b9b94: submit code 77 with operands 0/1 and zero,
 * publish the result through 0203acf4, and return completion status 1. */
s32 func_020b9b94(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(77, first, second, 0));
    return 1;
}

/* ARM evidence at 020b9bcc: submit code 78 with operands 0/1 and zero,
 * publish the result through 0203acf4, and return completion status 1. */
s32 func_020b9bcc(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(78, first, second, 0));
    return 1;
}

/* ARM evidence at 020b9c04: submit code 79 with operands 0/1 and zero,
 * publish the result through 0203acf4, and return completion status 1. */
s32 func_020b9c04(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(79, first, second, 0));
    return 1;
}

