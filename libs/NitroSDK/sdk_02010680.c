#include "types.h"

/* Borrowed prefixes; offsets follow the original loads and stores. */
typedef struct Unk02010680Work {
    u8 prefix[0x18];
    void (*callbacks[17])(void *);
    u8 middle[0xf0];
    u32 word14c;
    u16 half150;
} Unk02010680Work;

typedef struct Unk02010680Global {
    u16 initialized;
    u16 padding;
    Unk02010680Work *work;
} Unk02010680Global;

extern Unk02010680Global data_02154c40;
extern void *data_02155720;
extern u32 func_02007a58(void);
extern void func_02007a6c(u32 state);
extern s32 func_02010bec(void *work);
extern s32 func_02010c84(void);

/* Stores a borrowed callback at work +0x18 + index*4 (0201068c).
 * The caller supplies a valid table index and keeps the callback alive. */
void func_02010680(u32 index, void (*callback)(void *))
{
    data_02154c40.work->callbacks[index] = callback;
}

/* Returns the provider-owned work pointer loaded from global +4 (020107a0). */
Unk02010680Work *func_0201079c(void)
{
    return data_02154c40.work;
}

/* Maps the global halfword to status zero when set, three when clear;
 * evidence is the LDRH and conditional MOV pair at 020107b0..020107bc. */
s32 func_020107ac(void)
{
    return data_02154c40.initialized ? 0 : 3;
}

/* Reads work +0x150 while interrupts are disabled; absent work returns zero.
 * The saved interrupt state is restored before returning (020108a8..020108c4). */
u32 func_020108a4(void)
{
    u32 state = func_02007a58();
    u32 result = data_02154c40.work ? data_02154c40.work->half150 : 0;
    func_02007a6c(state);
    return result;
}

/* Reads the word at work +0x14c under interrupt protection, then truncates
 * to 16 bits; evidence is LDR at 020108ec and shifts at 020108f4..020108f8. */
u16 func_020108d4(void)
{
    u32 state = func_02007a58();
    u32 result = data_02154c40.work ? data_02154c40.work->word14c : 0;
    func_02007a6c(state);
    return (u16)result;
}

/* Forwards caller-owned work to 02010bec; the original literal tail call
 * preserves that provider's result and ownership contract. */
s32 func_02010c34(void *work)
{
    return func_02010bec(work);
}

/* Returns the result of provider 02010c84 through the original tail call. */
s32 func_02010cbc(void)
{
    return func_02010c84();
}

/* Tests whether the provider pointer at 02155720 is present, matching the
 * LDR/CMP/conditional MOV sequence at 02010dd0..02010de0. */
s32 func_02010dd0(void)
{
    return data_02155720 != 0;
}
