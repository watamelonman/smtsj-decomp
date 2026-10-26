#include "types.h"

/* The callee stores four integer fields at offsets 0x20..0x2c and returns
 * whether func_0204e9d8 accepted them (see its ARM body at 0x020b8b38). */
extern int func_020b8b38(int id, int arg1, int arg2, int arg3);
/* ARM body at 0x0203acf4 clears the current state's byte 0x3b and stores
 * the supplied result in its word at 0xa8. */
extern void Unk03aae8_Unk_03acf4(int result);

/* ARM evidence at 0x020b9eec: submit ID 95 with zero arguments, publish
 * the helper's result, and return 1 independently of that result. */
int func_020b9eec(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(95, 0, 0, 0));
    return 1;
}

/* ARM evidence at 0x020b9f10: submit ID 96 with zero arguments, publish
 * the helper's result, and return 1 independently of that result. */
int func_020b9f10(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(96, 0, 0, 0));
    return 1;
}

/* ARM evidence at 0x020b9f34: submit ID 97 with zero arguments, publish
 * the helper's result, and return 1 independently of that result. */
int func_020b9f34(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(97, 0, 0, 0));
    return 1;
}

/* ARM evidence at 0x020b9f58: submit ID 98 with zero arguments, publish
 * the helper's result, and return 1 independently of that result. */
int func_020b9f58(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(98, 0, 0, 0));
    return 1;
}

/* ARM evidence at 0x020b9f7c: submit ID 99 with zero arguments, publish
 * the helper's result, and return 1 independently of that result. */
int func_020b9f7c(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(99, 0, 0, 0));
    return 1;
}

/* ARM evidence at 0x020b9fa0: submit ID 100 with zero arguments, publish
 * the helper's result, and return 1 independently of that result. */
int func_020b9fa0(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(100, 0, 0, 0));
    return 1;
}

/* ARM evidence at 0x020b9fc4: submit ID 101 with zero arguments, publish
 * the helper's result, and return 1 independently of that result. */
int func_020b9fc4(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(101, 0, 0, 0));
    return 1;
}

/* ARM evidence at 0x020b9fe8: submit ID 102 with zero arguments, publish
 * the helper's result, and return 1 independently of that result. */
int func_020b9fe8(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(102, 0, 0, 0));
    return 1;
}
