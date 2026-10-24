#include "types.h"

/* Reads a value from the interpreter stack, counting back from its top. */
extern s32 func_0203ac00(s32 index);
/* Submits four words through the shared work record and returns success. */
extern s32 func_020b8b38(s32 code, s32 value, s32 argument2, s32 argument3);
/* Clears the interpreter result tag and stores the supplied result word. */
extern void Unk03aae8_Unk_03acf4(u32 result);

/* ARM evidence at 0x020b91a8: submit code 25 with stack value 0,
 * publish the submission result, and return 1 to the caller. */
s32 func_020b91a8(void)
{
    s32 value = func_0203ac00(0);
    Unk03aae8_Unk_03acf4(func_020b8b38(25, value, 0, 0));
    return 1;
}

/* ARM evidence at 0x020b91d4: submit code 26 with zero arguments,
 * publish the submission result, and return 1 to the caller. */
s32 func_020b91d4(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(26, 0, 0, 0));
    return 1;
}

/* ARM evidence at 0x020b91f8: submit code 27 with zero arguments,
 * publish the submission result, and return 1 to the caller. */
s32 func_020b91f8(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(27, 0, 0, 0));
    return 1;
}

/* ARM evidence at 0x020b921c: submit code 28 with zero arguments,
 * publish the submission result, and return 1 to the caller. */
s32 func_020b921c(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(28, 0, 0, 0));
    return 1;
}

/* ARM evidence at 0x020b9240: submit code 29 with stack value 0,
 * publish the submission result, and return 1 to the caller. */
s32 func_020b9240(void)
{
    s32 value = func_0203ac00(0);
    Unk03aae8_Unk_03acf4(func_020b8b38(29, value, 0, 0));
    return 1;
}

/* ARM evidence at 0x020b926c: submit code 30 with stack value 0,
 * publish the submission result, and return 1 to the caller. */
s32 func_020b926c(void)
{
    s32 value = func_0203ac00(0);
    Unk03aae8_Unk_03acf4(func_020b8b38(30, value, 0, 0));
    return 1;
}

/* ARM evidence at 0x020b9298: submit code 31 with stack value 0,
 * publish the submission result, and return 1 to the caller. */
s32 func_020b9298(void)
{
    s32 value = func_0203ac00(0);
    Unk03aae8_Unk_03acf4(func_020b8b38(31, value, 0, 0));
    return 1;
}

/* ARM evidence at 0x020b92c4: submit code 32 with stack value 0,
 * publish the submission result, and return 1 to the caller. */
s32 func_020b92c4(void)
{
    s32 value = func_0203ac00(0);
    Unk03aae8_Unk_03acf4(func_020b8b38(32, value, 0, 0));
    return 1;
}
