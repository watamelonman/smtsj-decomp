#include "types.h"

/** Borrowed provider prefix; counters and dispatch word follow observed loads. */
typedef struct Unk0208325cState {
    u32 unk_000;
    u32 unk_004;
    u32 unk_008;
    u32 unk_00c;
    u32 unk_010;
    u32 unk_014;
    u32 unk_018;
    u32 unk_01c;
    u32 unk_020;
    u8 padding_024[0x240];
    void *unk_264;
    u32 unk_268;
    u32 unk_26c;
    u32 unk_270;
} Unk0208325cState;

extern Unk0208325cState data_021746e4;
extern Unk0208325cState data_02174740;
extern s32 func_0208a988(void);
extern void func_020821e0(void);
extern void func_020821f0(void);
extern void func_02082544(void (*callback)(void *context, void *message), void *context);

/** Borrowed callback slots and the word reset by the mode-two path. */
typedef struct Unk0208325cCallbacks {
    void (*unk_000)(void *context);
    void *unk_004;
    void (*unk_008)(void *context);
    void *unk_00c;
    u32 unk_010;
} Unk0208325cCallbacks;

extern Unk0208325cCallbacks data_02174700;
extern u32 data_02174714;
extern u8 data_021748e4[];
extern void func_02007ad4(void);
extern void func_020064e0(void *thread);
extern u32 func_020059d8(u32 mask);
extern u32 func_020059a8(u32 mask);
extern void func_0208390c(void);
extern u32 func_02083820(void);
extern u32 func_02083708(void), func_02083860(void);
extern void func_02083848(void), func_02083870(void), func_02083930(void);

/** Dispatch on the provider's +0x20 word. Mode two calls its callback,
 * clears 02174700 +0x10 and passes 021748e4 to the thread provider. */
void func_0208325c(void)
{
    u32 mode = data_02174740.unk_020;
    if (mode <= 1) {
        func_02007ad4();
    } else if (mode == 2) {
        func_0208390c();
        data_02174700.unk_010 = 0;
        func_020064e0(data_021748e4);
        func_02007ad4();
    }
}

/** On the first nesting entry save hardware IE (04000210) and disable
 * IRQ bit zero through the existing provider; increment the +8 counter. */
void func_020832d0(void)
{
    if (data_021746e4.unk_008 == 0) {
        u32 saved = *(volatile u32 *)0x04000210;
        func_020059d8(1);
        data_02174714 = saved;
    }
    data_021746e4.unk_008++;
}

/** Decrement the +8 nesting counter and enable IRQ bit zero when it reaches
 * zero. Entries must be balanced by the caller; no underflow check exists. */
void func_0208331c(void)
{
    if (--data_021746e4.unk_008 == 0) {
        func_020059a8(1);
    }
}

/** Normalize the existing +0x0c accessor result to a zero-or-one word. */
u32 func_02083708(void)
{
    return func_02083820() != 0;
}

/** Increment the provider-owned +0x0c word with unsigned wraparound. */
void func_02083830(void)
{
    data_021746e4.unk_00c++;
}

/** Decrement the provider-owned +0x0c word with unsigned wraparound. */
void func_02083848(void)
{
    data_021746e4.unk_00c--;
}

/** Invoke the optional callback at 02174700 with its borrowed +4 context. */
void func_0208390c(void)
{
    if (data_02174700.unk_000 != 0) {
        data_02174700.unk_000(data_02174700.unk_004);
    }
}

/** Invoke the independent optional +8 callback with its borrowed +0x0c
 * context. Neither callback dispatcher retains or releases the context. */
void func_02083930(void)
{
    if (data_02174700.unk_008 != 0) {
        data_02174700.unk_008(data_02174700.unk_00c);
    }
}

/** Forward the result of the mode dispatcher, identified by the literal at
 * 020832b4; this wrapper retains no state. */
s32 func_020832ac(void)
{
    return func_0208a988();
}

/** Invoke the provider's entry helper (literal at 020832c0), with no arguments. */
void func_020832b8(void)
{
    func_020821e0();
}

/** Invoke the paired provider exit helper (literal at 020832cc). */
void func_020832c4(void)
{
    func_020821f0();
}

/** Forward a borrowed callback/context pair. The literal at 02083498 selects
 * func_02082544, which stores these in 02173ff4. func_02082220/func_0208228c
 * read the pair and invoke callback(context, data_021742cc).
 * The provider retains the pair; the caller must keep the context valid. */
void func_02083490(void (*callback)(void *context, void *message), void *context)
{
    func_02082544(callback, context);
}

/** Read the provider-owned word at 021746e4 + 0x0c (LDR at 02083824). */
u32 func_02083820(void)
{
    return data_021746e4.unk_00c;
}

/** Read the independent provider-owned word at 02174740 + 0x0c
 * (LDR at 02083864); no ownership transfers. */
u32 func_02083860(void)
{
    return data_02174740.unk_00c;
}

/** Set the shared word to one, as established by STR at 02083878. */
void func_02083870(void)
{
    data_02174740.unk_00c = 1;
}

/** Clear the shared word, as established by STR at 0208388c. */
void func_02083884(void)
{
    data_02174740.unk_00c = 0;
}

extern u8 data_02174824[], data_02174764[];
extern void func_02006428(u32 ticks);
extern void func_0200654c(void *thread, u32 value);
extern void func_02082618(void), func_02082628(void), func_02082648(void);
extern s32 func_02082668(void);
extern void func_02082718(void), func_02082748(void);
extern void func_0208a978(u32 mode), func_0208a9e0(void);

/** Run the +8 worker while enabled, yielding after each provider update.
 * Thread choice and completion word follow loads at 02083360..020833a8. */
void func_02083344(void)
{
    while (data_02174740.unk_008 == 1) {
        if (data_02174740.unk_014 == 1)
            func_020064e0(data_02174740.unk_264);
        else
            func_020064e0(data_02174824);
        func_02082618();
        func_02082628();
        data_02174740.unk_268++;
        func_02006428(0);
    }
    func_02083870();
}

/** Run the +0x10 worker and mark +0x14 complete after its enable word changes. */
void func_020833b8(void)
{
    while (data_02174740.unk_010 == 1) {
        func_020064e0(data_02174740.unk_264);
        func_02082648();
        data_02174740.unk_26c++;
        func_02006428(0);
    }
    data_02174740.unk_014 = 1;
}

/** Poll the provider while +0 is enabled; latch and dispatch the second
 * callback under the paired entry/exit helpers when polling returns zero. */
void func_02083410(void)
{
    while (data_02174740.unk_000 == 1) {
        if (func_02082668() == 0) {
            func_020821e0();
            if (data_02174700.unk_010 == 0) {
                data_02174700.unk_010 = 1;
                func_02083930();
            }
            func_020821f0();
            func_02006428(0);
        }
        data_02174740.unk_270++;
    }
    data_02174740.unk_004 = 1;
}

/** Stop workers only on the final balanced reference release. Each completion
 * word is rechecked after the SDK thread wait, preserving provider ownership. */
u32 func_02083720(void)
{
    if (!func_02083708()) return 0;
    func_02083848();
    if (func_02083820() == 0) {
        data_02174740.unk_000 = 0;
        func_0200654c(data_021748e4, 0);
        while (data_02174740.unk_004 == 0) func_020064e0(data_021748e4);
        data_02174740.unk_010 = 0;
        func_0200654c(data_02174824, 0);
        while (data_02174740.unk_014 == 0) func_020064e0(data_02174824);
        data_02174740.unk_008 = 0;
        func_0200654c(data_02174764, 0);
        while (func_02083860() == 0) func_020064e0(data_02174764);
        func_02082748();
        data_02174740.unk_020 = 1;
        func_0208a978(1);
    }
    return 1;
}

/** For an active mode above one, dispatch the latched callback and wait for
 * the primary thread; the original returns zero on every path. */
u32 func_02083898(void)
{
    if (func_02083820() == 0) return 0;
    if (data_02174740.unk_020 <= 1) return 0;
    if (func_02083860() != 0) return 0;
    if (data_02174700.unk_010 == 0) {
        data_02174700.unk_010 = 1;
        func_02083930();
    }
    func_0208a9e0();
    func_020064e0(data_02174764);
    return 0;
}

/** Caller-owned nine-word thread configuration, copied before thread creation.
 * Stack pointers/sizes and priorities follow 020835e4..020836a8. */
typedef struct Unk0208325cConfig {
    u32 priority[3];
    u8 *stack[3];
    u32 size[3];
} Unk0208325cConfig;
extern Unk0208325cConfig data_0217471c;
extern u32 data_02152284[];
extern u32 data_02147068;
extern char data_0214709c[], data_021470dc[];
extern void func_02082220(const char *message);
extern void func_0208256c(void (*callback)(void), void *context);
extern void func_0208257c(void (*callback)(void), void *context);
extern s32 func_02085410(const char *name, u32 *value);
extern void func_0200621c(void *thread, void (*entry)(void), void *arg,
                          void *stackTop, u32 stackSize, u32 priority);

/** Initialize provider workers on the first reference. Null configuration reports
 * the original diagnostic; storage and stacks remain provider/caller owned. */
void func_0208350c(const Unk0208325cConfig *config)
{
    /* The original performs this otherwise unused literal-pool read. */
    u32 ignored = *(volatile const u32 *)0x0212ec78;
    u32 priority;
    u8 *stackTop;
    u32 stackSize;
    if (config == 0) {
        func_02082220(data_0214709c);
        return;
    }
    func_02083830();
    if (func_02083820() != 1) return;
    data_02174740.unk_264 = (void *)data_02152284[1];
    if (data_02174740.unk_020 != 2) data_02174740.unk_020 = 2;
    func_02082718();
    func_0208256c(func_020832d0, 0);
    func_0208257c(func_0208331c, 0);
    if (func_02085410(data_021470dc, &priority) == 0)
        data_02147068 = priority;
    else
        data_02147068 = 15;
    data_0217471c = *config;
    data_02174740.unk_018 = 0;
    data_02174740.unk_01c = 0;
    data_02174740.unk_008 = 1;
    func_02083884();
    stackSize = config->size[0];
    stackTop = config->stack[0];
    stackTop = (u8 *)(((u32)stackTop + 3) & ~3);
    func_0200621c(data_02174764, func_02083344, 0,
        (void *)((u32)stackTop + stackSize), stackSize, data_0217471c.priority[0]);
    data_02174740.unk_010 = 1;
    data_02174740.unk_014 = 0;
    func_0200621c(data_02174824, func_020833b8, 0,
        (u8 *)((((u32)config->stack[1] + 3) & ~3) + config->size[1]),
        config->size[1], data_0217471c.priority[1]);
    if (data_02174740.unk_020 == 2) {
        data_02174740.unk_000 = 1;
        data_02174740.unk_004 = 0;
        func_0200621c(data_021748e4, func_02083410, 0,
            (u8 *)((((u32)config->stack[2] + 3) & ~3) + config->size[2]),
            config->size[2], data_0217471c.priority[2]);
    } else {
        data_02174740.unk_000 = 0;
        data_02174740.unk_004 = 1;
    }
}

