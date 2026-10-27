#include "types.h"

/** Borrowed provider state; only the word at +0x0c is established here. */
typedef struct Unk0208325cState {
    u32 unk_000[3];
    u32 unk_00c;
} Unk0208325cState;

extern Unk0208325cState data_021746e4;
extern Unk0208325cState data_02174740;
extern s32 func_0208a988(void);
extern void func_020821e0(void);
extern void func_020821f0(void);
extern void func_02082544(void (*callback)(void *), void *context);

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

/** Forward a borrowed callback/context pair. The destination at 02083498
 * stores these in 02173ff4, read and called by 0208211c as callback(context).
 * The provider retains the pair; the caller must keep the context valid. */
void func_02083490(void (*callback)(void *), void *context)
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
