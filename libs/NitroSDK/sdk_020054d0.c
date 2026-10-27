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

/* Borrowed GX texture load state at data_021521dc. Names follow pret/pokediamond
 * GX_load3d.c; sdk_02005238.c's TexLoadState confirms the +4/+20/+24/+28 slots
 * written by GX_BeginLoadTex, and GX_LoadTexPltt/GX_EndLoadTexPltt supply the
 * palette LCDC block at +8 and saved palette bank at +12. */
typedef struct SDK054d0GXState {
    unsigned int reserved0;
    unsigned int lcdcBlk1;
    unsigned int texPlttLcdcBlk;
    unsigned int texPltt;
    unsigned int reserved10;
    unsigned int tex;
    unsigned int lcdcBlk2;
    unsigned int szBlk1;
} SDK054d0GXState;
extern SDK054d0GXState data_021521dc;
extern int data_0213ce44;
extern void func_02008178(unsigned int dma);
extern void func_0200303c(unsigned int bank);
extern void func_02003214(unsigned int bank);
extern void func_020080e0(unsigned int dma, const void *source, void *destination,
                         unsigned int size, void *callback, void *argument);
extern void func_020086bc(const void *source, void *destination, unsigned int size);

/* GX_EndLoadTex in pret/pokediamond GX_load3d.c: wait for the pending texture
 * upload on GXi_DmaId (data_0213ce44), restore the saved texture bank mask,
 * then clear the two LCDC bases, the first-block size and the saved bank. */
void func_020054d0(void)
{
    if (data_0213ce44 != -1) func_02008178(data_0213ce44);
    func_0200303c(data_021521dc.tex);
    data_021521dc.szBlk1 = 0;
    data_021521dc.lcdcBlk2 = 0;
    data_021521dc.lcdcBlk1 = 0;
    data_021521dc.tex = 0;
}

/* GX_LoadTexPltt in pret/pokediamond GX_load3d.c: copy size bytes from
 * caller-owned source into the borrowed palette LCDC block at state +8 plus
 * byte offset. A configured GXi_DmaId (data_0213ce44) selects the DMA copy
 * provider; otherwise the synchronous copy provider is used. */
void func_02005550(const void *source, unsigned int offset, unsigned int size)
{
    void *destination = (void *)(data_021521dc.texPlttLcdcBlk + offset);
    if (data_0213ce44 != -1)
        func_020080e0(data_0213ce44, source, destination, size, 0, 0);
    else
        func_020086bc(source, destination, size);
}

/* GX_EndLoadTexPltt in pret/pokediamond GX_load3d.c: wait for the pending
 * palette upload on GXi_DmaId (data_0213ce44), restore the saved palette bank
 * mask at +12, then clear the saved bank and palette LCDC block. */
void func_020055bc(void)
{
    if (data_0213ce44 != -1) func_02008178(data_0213ce44);
    func_02003214(data_021521dc.texPltt);
    data_021521dc.texPltt = 0;
    data_021521dc.texPlttLcdcBlk = 0;
}

/* Twelve-byte IRQ records follow public NitroSDK OSIrqCallbackInfo; storage is borrowed. */
typedef struct SDK054d0Callback {
    void (*function)(void *);
    unsigned int enabled;
    void *argument;
} SDK054d0Callback;

extern SDK054d0Callback data_021521fc[8];
/* Alias of records 4..7 of data_021521fc (OSIrqCallbackInfo layout); the timer
 * half of the eight-record table, referenced by the original as its own symbol. */
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

/* OS_GetIrqFunction in pret/pokediamond OS_interrupt.c: return the handler
 * for the lowest selected IRQ among bits 0..21, including DMA/timer callbacks. */
SDK054d0IrqFunction func_02005860(unsigned int mask)
{
    int i = 0;
    void (**function)(void) = &data_027e0000[0];
    do {
        if (mask & 1) {
            if (8 <= i && i <= 11) {
                i = i - 8;
                return (void (*)(void))data_021521fc[i].function;
            } else if (3 <= i && i <= 6) {
                i++;
                return (void (*)(void))data_021521fc[i].function;
            }
            return *function;
        }
        mask >>= 1;
        function++;
        i++;
    } while (i < 22);
    return 0;
}
