#ifndef SDK_020054D0_H
#define SDK_020054D0_H

/** Returns immediately; the original handler consists solely of bx lr. */
void func_020056b4(void);
/** Forwards callback-table index 0; evidenced by mov r0, #0 before the tail call. */
void func_02005740(void);
/** Forwards callback-table index 1; evidenced by mov r0, #1 before the tail call. */
void func_02005750(void);
/** Forwards callback-table index 2; evidenced by mov r0, #2 before the tail call. */
void func_02005760(void);
/** Forwards callback-table index 3; evidenced by mov r0, #3 before the tail call. */
void func_02005770(void);
/** Forwards callback-table index 4; evidenced by mov r0, #4 before the tail call. */
void func_02005780(void);
/** Forwards callback-table index 5; evidenced by mov r0, #5 before the tail call. */
void func_02005790(void);
/** Forwards callback-table index 6; evidenced by mov r0, #6 before the tail call. */
void func_020057a0(void);

/** Dispatch timer callback slot 7; the original passes this index to the dispatcher. */
void func_020057b0(void);
/** Clear both borrowed IRQ thread-queue links, as in NitroSDK OS_InitIrqTable. */
void func_020057c0(void);
/** Replace IE while IME is disabled; return the previous interrupt-enable mask. */
unsigned int func_0200597c(unsigned int mask);
/** Enable the requested IE bits while preserving IME; return the previous IE. */
unsigned int func_020059a8(unsigned int mask);
/** Disable the requested IE bits while preserving IME; return the previous IE. */
unsigned int func_020059d8(unsigned int mask);

/** GX_EndLoadTex: wait for the pending texture upload on GXi_DmaId, restore the
 * saved texture bank mask and clear the LCDC bases, size and saved bank. */
void func_020054d0(void);
/** GX_LoadTexPltt: copy size bytes from caller-owned source into the borrowed
 * palette LCDC block at state +8 plus byte offset; the configured GXi_DmaId
 * selects the DMA copy provider. */
void func_02005550(const void *source, unsigned int offset, unsigned int size);
/** GX_EndLoadTexPltt: wait for the pending palette upload on GXi_DmaId, restore
 * the saved palette bank at +12 and clear its bank/LCDC block slots. */
void func_020055bc(void);
/** Register handlers for mask bits 0..21; DMA/timer slots retain callbacks without ownership. */
void func_020057d8(unsigned int mask, void (*function)(void));
/** Register DMA channel 0..3 and its borrowed argument, preserving the previous IRQ enable bit. */
void func_020058ec(unsigned int channel, void (*callback)(void *), void *argument);
/** Register timer 0..3 and its borrowed argument, enabling its IRQ until dispatch. */
void func_02005934(unsigned int timer, void (*callback)(void *), void *argument);

/** Argument-free IRQ entry point; registration retains provider ownership. */
typedef void (*SDK054d0IrqFunction)(void);

/** Return the borrowed handler for the lowest selected IRQ bit 0..21, or null. */
SDK054d0IrqFunction func_02005860(unsigned int mask);

#endif
