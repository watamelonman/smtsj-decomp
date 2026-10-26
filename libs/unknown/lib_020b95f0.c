/* Script request wrappers; operand reads, request submission, and result stores
 * are evidenced by calls to 0203ac00, 020b8b38, and 0203acf4. */
#include "types.h"

/* Reads a signed operand from the implicit script context by index. */
extern s32 func_0203ac00(s32 index);
/* Submits request words through the shared request provider. */
extern s32 func_020b8b38(s32 request, s32 first, s32 second, s32 third);
/* Publishes a result in the implicit script context. */
extern void Unk03aae8_Unk_03acf4(s32 result);

/* ARM evidence at 0x020b95f0: submit request 51 with operand 0,
 * publish the provider result, and return script completion status 1. */
s32 func_020b95f0(void)
{
    s32 first = func_0203ac00(0);
    Unk03aae8_Unk_03acf4(func_020b8b38(51, first, 0, 0));
    return 1;
}

/* ARM evidence at 0x020b961c: submit request 52 with operands 0 and 1,
 * publish the provider result, and return script completion status 1. */
s32 func_020b961c(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(52, first, second, 0));
    return 1;
}

/* ARM evidence at 0x020b9654: submit request 53 with operands 0 and 1,
 * publish the provider result, and return script completion status 1. */
s32 func_020b9654(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(53, first, second, 0));
    return 1;
}

/* ARM evidence at 0x020b968c: submit request 54 with operands 0 and 1,
 * publish the provider result, and return script completion status 1. */
s32 func_020b968c(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(54, first, second, 0));
    return 1;
}

/* ARM evidence at 0x020b96c4: submit request 55 with operands 0 and 1,
 * publish the provider result, and return script completion status 1. */
s32 func_020b96c4(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(55, first, second, 0));
    return 1;
}

/* ARM evidence at 0x020b96fc: submit request 56 with operands 0 and 1,
 * publish the provider result, and return script completion status 1. */
s32 func_020b96fc(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(56, first, second, 0));
    return 1;
}

/* ARM evidence at 0x020b9778: submit request 58 with operands 0 and 1,
 * publish the provider result, and return script completion status 1. */
s32 func_020b9778(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(58, first, second, 0));
    return 1;
}

/* ARM evidence at 0x020b97b0: submit request 59 with operands 0 and 1,
 * publish the provider result, and return script completion status 1. */
s32 func_020b97b0(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);
    Unk03aae8_Unk_03acf4(func_020b8b38(59, first, second, 0));
    return 1;
}

