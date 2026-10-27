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


/* Timer callback slot 7 follows slots 0..6 in the original dispatcher table. */
void func_020057b0(void)
{
    func_020056b8(7);
}

extern unsigned int data_027e0060[2];

/* OS_InitIrqTable in pret/pokediamond: clear both IRQ thread-queue links. */
void func_020057c0(void)
{
    data_027e0060[1] = 0;
    data_027e0060[0] = 0;
}

/* OS_SetIrqMask in pret/pokediamond: return old IE, replacing it under IME=0. */
unsigned int func_0200597c(unsigned int mask)
{
    unsigned short ime = *(volatile unsigned short *)0x04000208;
    *(volatile unsigned short *)0x04000208 = 0;
    unsigned int previous = *(volatile unsigned int *)0x04000210;
    *(volatile unsigned int *)0x04000210 = mask;
    (void)*(volatile unsigned short *)0x04000208;
    *(volatile unsigned short *)0x04000208 = ime;
    return previous;
}

/* OS_EnableIrqMask in pret/pokediamond: add IE bits with IME temporarily zero. */
unsigned int func_020059a8(unsigned int mask)
{
    unsigned short ime = *(volatile unsigned short *)0x04000208;
    *(volatile unsigned short *)0x04000208 = 0;
    unsigned int previous = *(volatile unsigned int *)0x04000210;
    *(volatile unsigned int *)0x04000210 = previous | mask;
    (void)*(volatile unsigned short *)0x04000208;
    *(volatile unsigned short *)0x04000208 = ime;
    return previous;
}

/* OS_DisableIrqMask in pret/pokediamond: remove IE bits while preserving IME. */
unsigned int func_020059d8(unsigned int mask)
{
    unsigned short ime = *(volatile unsigned short *)0x04000208;
    *(volatile unsigned short *)0x04000208 = 0;
    unsigned int previous = *(volatile unsigned int *)0x04000210;
    *(volatile unsigned int *)0x04000210 = previous & ~mask;
    (void)*(volatile unsigned short *)0x04000208;
    *(volatile unsigned short *)0x04000208 = ime;
    return previous;
}
