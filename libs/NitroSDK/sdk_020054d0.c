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

/* Borrowed state offsets follow the cleanup loads/stores at 020054d0/020055bc. */
typedef struct SDK054d0State {
    unsigned int reserved0;
    unsigned int field04;
    unsigned char *base;
    unsigned int bank;
    unsigned int reserved10;
    void *resource;
    unsigned int field18;
    unsigned int field1c;
} SDK054d0State;
extern SDK054d0State data_021521dc;
extern int data_0213ce44;
extern void func_02008178(int handle);
extern void func_0200303c(void *resource);
extern void func_02003214(unsigned int bank);
extern void func_020080e0(int handle, void *destination, const void *source,
                         unsigned int size, unsigned int option, unsigned int callback);
extern void func_020086bc(void *destination, const void *source, unsigned int size);

/* Release the optional handle and resource, then clear state; evidenced by calls and stores. */
void func_020054d0(void)
{
    if (data_0213ce44 != -1) func_02008178(data_0213ce44);
    func_0200303c(data_021521dc.resource);
    data_021521dc.field1c = 0;
    data_021521dc.field18 = 0;
    data_021521dc.field04 = 0;
    data_021521dc.resource = 0;
}

/* Read from the borrowed base plus byte offset; the original selects a handle provider or copy. */
void func_02005550(void *destination, unsigned int offset, unsigned int size)
{
    unsigned char *base = data_021521dc.base;
    if (data_0213ce44 != -1)
        func_020080e0(data_0213ce44, destination, base + offset, size, 0, 0);
    else
        func_020086bc(destination, base + offset, size);
}

/* Release the optional handle and bank, clearing borrowed base/bank slots (original +8/+12). */
void func_020055bc(void)
{
    if (data_0213ce44 != -1) func_02008178(data_0213ce44);
    func_02003214(data_021521dc.bank);
    data_021521dc.bank = 0;
    data_021521dc.base = 0;
}

/* Twelve-byte IRQ records follow public NitroSDK OSIrqCallbackInfo; storage is borrowed. */
typedef struct SDK054d0Callback {
    void (*function)(void *);
    unsigned int enabled;
    void *argument;
} SDK054d0Callback;

extern SDK054d0Callback data_021521fc[8];
extern SDK054d0Callback data_0215222c[4];
extern void (*data_027e0000[22])(void);

/* OS_SetIrqFunction from pret/pokediamond: register IRQ handlers, DMA/timers through callbacks. */
void func_020057d8(unsigned int mask, void (*function)(void))
{
    int i;
    SDK054d0Callback *info;
    for (i = 0; i < 22; i++) {
        if (mask & 1) {
            info = 0;
            if (8 <= i && i <= 11) info = &data_021521fc[i - 8];
            else if (3 <= i && i <= 6) info = &data_021521fc[i + 1];
            else data_027e0000[i] = function;
            if (info) {
                info->function = (void (*)(void *))function;
                info->argument = 0;
                info->enabled = 1;
            }
        }
        mask >>= 1;
    }
}

/* OSi_EnterDmaCallback in pret/pokediamond: preserve whether the DMA IRQ was already enabled. */
void func_020058ec(unsigned int channel, void (*callback)(void *), void *argument)
{
    unsigned int mask = 1U << (channel + 8);
    data_021521fc[channel].function = callback;
    data_021521fc[channel].argument = argument;
    data_021521fc[channel].enabled = func_020059a8(mask) & mask;
}

/* OSi_EnterTimerCallback in pret/pokediamond: enable a timer IRQ and retain its callback. */
void func_02005934(unsigned int timer, void (*callback)(void *), void *argument)
{
    unsigned int mask = 1U << (timer + 3);
    data_0215222c[timer].function = callback;
    data_0215222c[timer].argument = argument;
    (void)func_020059a8(mask);
    data_0215222c[timer].enabled = 1;
}
