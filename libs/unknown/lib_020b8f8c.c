/* Script wrappers; the original symbols are retained for delink matching. */
#include "types.h"

/* Read one word from the active script's argument list. */
extern s32 func_0203ac00(s32 index);
/* Submit four words through the shared worker; returns a Boolean result. */
extern s32 func_020b8b38(s32 selector, s32 argument, s32 third, s32 fourth);
/* Store the implicit script result and clear its associated byte flag. */
extern void Unk03aae8_Unk_03acf4(s32 result);

/* ARM evidence at 0x020b8f8c: submit selector 12 with script argument zero,
 * publish the worker result, and return command completion (1). */
s32 func_020b8f8c(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(12, func_0203ac00(0), 0, 0));
    return 1;
}

/* ARM evidence at 0x020b8fb8: submit selector 13 with script argument zero,
 * publish the worker result, and return command completion (1). */
s32 func_020b8fb8(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(13, func_0203ac00(0), 0, 0));
    return 1;
}

/* ARM evidence at 0x020b8fe4: submit selector 15 with script argument zero,
 * publish the worker result, and return command completion (1). */
s32 func_020b8fe4(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(15, func_0203ac00(0), 0, 0));
    return 1;
}

/* ARM evidence at 0x020b9010: submit selector 16 with script argument zero,
 * publish the worker result, and return command completion (1). */
s32 func_020b9010(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(16, func_0203ac00(0), 0, 0));
    return 1;
}

/* ARM evidence at 0x020b903c: submit selector 17 with script argument zero,
 * publish the worker result, and return command completion (1). */
s32 func_020b903c(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(17, func_0203ac00(0), 0, 0));
    return 1;
}

/* ARM evidence at 0x020b9068: submit selector 18 with script argument zero,
 * publish the worker result, and return command completion (1). */
s32 func_020b9068(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(18, func_0203ac00(0), 0, 0));
    return 1;
}

/* ARM evidence at 0x020b9094: read arguments in index order, submit
 * selector 19 with both words, publish the result, and return completion (1). */
s32 func_020b9094(void)
{
    s32 first = func_0203ac00(0);
    s32 second = func_0203ac00(1);

    Unk03aae8_Unk_03acf4(func_020b8b38(19, first, second, 0));
    return 1;
}

/* ARM evidence at 0x020b90cc: submit selector 20 with script argument zero,
 * publish the worker result, and return command completion (1). */
s32 func_020b90cc(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(20, func_0203ac00(0), 0, 0));
    return 1;
}

/* ARM evidence at 0x020b90f8: submit selector 21 with script argument zero,
 * publish the worker result, and return command completion (1). */
s32 func_020b90f8(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(21, func_0203ac00(0), 0, 0));
    return 1;
}

/* ARM evidence at 0x020b9124: submit selector 22 with script argument zero,
 * publish the worker result, and return command completion (1). */
s32 func_020b9124(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(22, func_0203ac00(0), 0, 0));
    return 1;
}

/* ARM evidence at 0x020b9150: submit selector 23 with script argument zero,
 * publish the worker result, and return command completion (1). */
s32 func_020b9150(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(23, func_0203ac00(0), 0, 0));
    return 1;
}

/* ARM evidence at 0x020b917c: submit selector 24 with script argument zero,
 * publish the worker result, and return command completion (1). */
s32 func_020b917c(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(24, func_0203ac00(0), 0, 0));
    return 1;
}

