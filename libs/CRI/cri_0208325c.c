#include "types.h"

/** Borrowed provider prefix; counters and dispatch word follow observed loads. */
typedef struct Unk0208325cState {
    u32 unk_000[2];
    u32 unk_008;
    u32 unk_00c;
    u32 unk_010[4];
    u32 unk_020;
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
