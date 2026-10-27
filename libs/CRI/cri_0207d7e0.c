#include "types.h"

/** Borrowed prefix: wrappers read only the provider pointer at +4. */
typedef struct Unk0207d7e0 {
    u32 unk_00;
    void *provider;
} Unk0207d7e0;

extern s32 func_0207a740(void *provider);
extern s32 func_0207a748(void *provider);
extern s32 func_0207a760(void *provider);
extern s32 func_0207a768(void *provider);
extern void func_0207a78c(void *provider);
extern void func_0207a7bc(void *provider);

/** Forward the borrowed +4 provider to the signed-halfword reader at 0207a740. */
s32 func_0207d7e0(const Unk0207d7e0 *state)
{
    return func_0207a740(state->provider);
}

/** Forward the borrowed +4 provider to the word reader at 0207a748. */
s32 func_0207d7f0(const Unk0207d7e0 *state)
{
    return func_0207a748(state->provider);
}

/** Forward the borrowed +4 provider to the word reader at 0207a760. */
s32 func_0207d81c(const Unk0207d7e0 *state)
{
    return func_0207a760(state->provider);
}

/** Forward the borrowed +4 provider to the word reader at 0207a768. */
s32 func_0207d82c(const Unk0207d7e0 *state)
{
    return func_0207a768(state->provider);
}

/** Return borrowed storage at +0x60; 0207d8d4 establishes the byte offset. */
void *func_0207d8d4(void *state)
{
    return (u8 *)state + 0x60;
}

/** Forward the borrowed +4 provider to 0207a78c, which updates provider fields. */
void func_0207d8dc(const Unk0207d7e0 *state)
{
    func_0207a78c(state->provider);
}

/** Forward the borrowed +4 provider to 0207a7bc, which submits provider fields. */
void func_0207d8ec(const Unk0207d7e0 *state)
{
    func_0207a7bc(state->provider);
}

/** Read the word at +0xb0; the caller must supply at least 0xb4 bytes. */
u32 func_0207d8fc(const void *state)
{
    return *(const u32 *)((const u8 *)state + 0xb0);
}
