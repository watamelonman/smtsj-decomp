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

#endif
