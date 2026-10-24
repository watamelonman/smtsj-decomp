/* Script request wrappers; evidence: the ARM calls at each entry below. */
#include "types.h"

/* Returns the request result; the meaning of each request ID is unresolved. */
extern s32 func_020b8b38(s32 request, s32 arg1, s32 arg2, s32 arg3);
/* Reads an operand from the current script; index is zero-based. */
extern s32 func_0203ac00(s32 index);
/* Stores a result in the implicit current script context. */
extern void Unk03aae8_Unk_03acf4(s32 value);

/* ARM 0x020ba474: submits request 107, publishes its result, and returns completion 1.
 * All three request arguments are zero; no explicit input is consumed. */
s32 func_020ba474(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(107, 0, 0, 0));
    return 1;
}

/* ARM 0x020ba498: submits request 108, publishes its result, and returns completion 1.
 * All three request arguments are zero; no explicit input is consumed. */
s32 func_020ba498(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(108, 0, 0, 0));
    return 1;
}

/* ARM 0x020ba4bc: submits request 109, publishes its result, and returns completion 1.
 * Operand zero supplies the first request argument; the other two are zero. */
s32 func_020ba4bc(void)
{
    s32 value = func_0203ac00(0);
    Unk03aae8_Unk_03acf4(func_020b8b38(109, value, 0, 0));
    return 1;
}

/* ARM 0x020ba514: submits request 111, publishes its result, and returns completion 1.
 * All three request arguments are zero; no explicit input is consumed. */
s32 func_020ba514(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(111, 0, 0, 0));
    return 1;
}

/* ARM 0x020ba538: submits request 112, publishes its result, and returns completion 1.
 * All three request arguments are zero; no explicit input is consumed. */
s32 func_020ba538(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(112, 0, 0, 0));
    return 1;
}

/* ARM 0x020ba5b4: submits request 115, publishes its result, and returns completion 1.
 * All three request arguments are zero; no explicit input is consumed. */
s32 func_020ba5b4(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(115, 0, 0, 0));
    return 1;
}

/* ARM 0x020ba5d8: submits request 116, publishes its result, and returns completion 1.
 * All three request arguments are zero; no explicit input is consumed. */
s32 func_020ba5d8(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(116, 0, 0, 0));
    return 1;
}

/* ARM 0x020ba5fc: submits request 117, publishes its result, and returns completion 1.
 * All three request arguments are zero; no explicit input is consumed. */
s32 func_020ba5fc(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(117, 0, 0, 0));
    return 1;
}

