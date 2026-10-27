#include "libs/NitroSDK/sdk_020054d0.h"

/* Existing dispatcher: consumes a callback-table index in the range 0..7. */
extern void func_020056b8(unsigned int index);

/* Returns immediately; the original handler consists solely of bx lr. */
void func_020056b4(void)
{
}

/* Forwards callback-table index 0; evidenced by mov r0, #0 before the tail call. */
void func_02005740(void)
{
    func_020056b8(0);
}

/* Forwards callback-table index 1; evidenced by mov r0, #1 before the tail call. */
void func_02005750(void)
{
    func_020056b8(1);
}

/* Forwards callback-table index 2; evidenced by mov r0, #2 before the tail call. */
void func_02005760(void)
{
    func_020056b8(2);
}

/* Forwards callback-table index 3; evidenced by mov r0, #3 before the tail call. */
void func_02005770(void)
{
    func_020056b8(3);
}

/* Forwards callback-table index 4; evidenced by mov r0, #4 before the tail call. */
void func_02005780(void)
{
    func_020056b8(4);
}

/* Forwards callback-table index 5; evidenced by mov r0, #5 before the tail call. */
void func_02005790(void)
{
    func_020056b8(5);
}

/* Forwards callback-table index 6; evidenced by mov r0, #6 before the tail call. */
void func_020057a0(void)
{
    func_020056b8(6);
}

