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

extern s32 func_0207a750(void *provider);
extern s32 func_0207a770(void *provider);
extern s32 func_0207a778(void *provider);
extern s32 func_0207a780(void *provider, s32 index);
extern void func_0207e7d4(void);
extern void func_0207e7e0(void);
extern void func_0207d9ac(void *slot, s32 a, s32 b, s32 c, void *provider);
extern void *func_0207da90(s32 a, s32 b, s32 c, void *provider);
extern u32 data_0217307c[];
extern s32 data_02145ed8[];
extern u32 data_02173094[250];

/** Return zero for a null state, otherwise query its borrowed +4 provider. */
s32 func_0207d800(const Unk0207d7e0 *state)
{
    if (state == 0) return 0;
    return func_0207a750(state->provider);
}

/** Query +4 only when its status is positive and the state byte +1 is 2 or 3. */
s32 func_0207d83c(const Unk0207d7e0 *state)
{
    if (func_0207a770(state->provider) > 0) {
        if ((u8)(s8)(((const s8 *)state)[1] - 2) <= 1)
            return func_0207a778(state->provider);
    }
    return 0;
}

/** Forward the index under the same byte/status guard; otherwise return -128. */
s32 func_0207d884(const Unk0207d7e0 *state, s32 index)
{
    if (func_0207a770(state->provider) > 0) {
        if ((u8)(s8)(((const s8 *)state)[1] - 2) <= 1)
            return func_0207a780(state->provider, index);
    }
    return -128;
}

/** First reference clears the provider-owned 1000-byte slot pool; always return one. */
s32 func_0207d904(void)
{
    if (++data_0217307c[3] == 1) __builtin__clear(data_02173094, sizeof(data_02173094));
    return 1;
}

/** Last reference clears the same pool; callers must balance reference acquisition. */
void func_0207d95c(void)
{
    if (--data_0217307c[3] == 0) __builtin__clear(data_02173094, sizeof(data_02173094));
}

/* See DEC-038: preserve the original per-iteration slot multiplication. */
#pragma push
#pragma opt_strength_reduction off
/** Borrow the first unused 100-byte slot in the configured range and initialize it. */
void *func_0207db2c(s32 a, s32 b, s32 c, void *provider)
{
    u8 *slot = 0;
    s32 count = data_02145ed8[0];
    s32 i = 0;
    s32 index;
    if (count > 0) {
        index = data_02145ed8[1];
        do {
            slot = (u8 *)data_02173094 + index * 100;
            if (*(s8 *)slot == 0) break;
            i++;
            index++;
        } while (i < count);
    }
    if (i == count) return 0;
    func_0207d9ac(slot, a, b, c, provider);
    slot[3] = 0;
    return slot;
}

#pragma pop

/** Choose the slot range by the caller's 0x100 threshold, forwarding its provider. */
void *func_0207dbec(void *provider, s32 selector)
{
    if (selector < 0x100) return func_0207da90(0, 0, 0, provider);
    return func_0207db2c(0, 0, 0, provider);
}

/** Hold the existing provider guard around range selection; return the borrowed slot. */
void *func_0207dbc0(void *provider, s32 selector)
{
    void *result;
    func_0207e7d4();
    result = func_0207dbec(provider, selector);
    func_0207e7e0();
    return result;
}
