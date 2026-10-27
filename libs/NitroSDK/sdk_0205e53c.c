#include "types.h"

/* Provider-owned prefix at 0216b348; padding preserves only observed offsets.
 * No wrapper allocates or retains storage beyond this existing singleton. */
typedef struct Unk0205e53cState {
    u8 reserved00[0x94];
    void *provider;
    u32 saved;
    u8 reserved9c[8];
    u8 enabled;
    u8 level;
    u8 reserveda6[2];
    void *slots[8];
    float value;
    u32 reservedcc;
    s32 status;
    s32 argument;
    s32 busy;
} Unk0205e53cState;

extern Unk0205e53cState data_0216b348;
extern void func_0208e084(s32 index, s32 argument);
extern void func_0208e0e8(s32 index, s32 argument);
extern s32 func_0208e13c(s32 index);
extern void func_0208e1ac(float value);
extern u32 func_0202b914(void *provider);
extern void func_0202b960(void *provider, u32 saved);
extern s32 func_0205e6c0(s32 request, s32 argument);

/* Selects one of two providers for slot zero, forwarding argument unchanged.
 * Evidence: CMP r0 and the two BL targets at 0205e560..0205e57c. */
void func_0205e560(s32 select, s32 argument)
{
    if (select) {
        func_0208e084(0, argument);
    } else {
        func_0208e0e8(0, argument);
    }
}

/* Queries provider slot zero; the original tail call loads r0 with zero. */
s32 func_0205e580(void)
{
    return func_0208e13c(0);
}

/* Returns the signed status word at singleton +0xd0 (LDR at 0205e5b8). */
s32 func_0205e5b4(void)
{
    return data_0216b348.status;
}

/* Stores the caller's float at +0xc8 before forwarding it. Evidence: STR at
 * 0205e5cc and float comparisons in the provider at 0208e1ac. */
void func_0205e5c4(float value)
{
    data_0216b348.value = value;
    func_0208e1ac(value);
}

/* Returns the stored float without the provider's clamping; LDR at 0205e5e0
 * reads exactly the word written by func_0205e5c4. */
float func_0205e5dc(void)
{
    return data_0216b348.value;
}

/* Saves the provider's returned word at +0x98; evidence is the BL and STR
 * at 0205e648/0205e650. The provider pointer remains borrowed. */
void func_0205e63c(void)
{
    data_0216b348.saved = func_0202b914(data_0216b348.provider);
}

/* Forwards the borrowed provider and saved word (+0x94/+0x98) to the paired
 * provider routine, matching the two loads at 0205e664/0205e668. */
void func_0205e65c(void)
{
    func_0202b960(data_0216b348.provider, data_0216b348.saved);
}

/* Supplies singleton +0xd4 as the request's second argument. Evidence: LDR
 * r1 at 0205e6b0 and the tail call; the provider returns a slot or -1. */
s32 func_0205e6a8(s32 request)
{
    return func_0205e6c0(request, data_0216b348.argument);
}

extern void func_0208e008(s32 index, s32 argument);
extern void func_0202ba34(void *provider);
extern s32 func_0202baf8(void *request, void *provider);
extern s32 func_0202a110(s32 index, s32 argument);
extern void func_0202a0c4(void **slot, u32 value);
extern void func_0202a184(void **slot, u32 level, s32 duration);
extern void func_0202c588(void **slot, s32 a, s32 b, s32 c, s32 argument, s32 request);
extern void *data_0216b3f0[8];

/* Selects the slot-zero provider with a zero argument; CMP/BL at 0205e540. */
void func_0205e53c(s32 select)
{
    if (select) {
        func_0208e084(0, 0);
    } else {
        func_0208e0e8(0, 0);
    }
}

/* Forwards argument to slot zero, then marks status -1; STR at 0205e5a8. */
void func_0205e590(s32 argument)
{
    func_0208e008(0, argument);
    data_0216b348.status = -1;
}

/* Refuses requests while busy; otherwise resets the provider before the
 * request and again after success. Evidence: BL sequence at 0205e610..e630. */
s32 func_0205e5ec(void *request)
{
    Unk0205e53cState *state = &data_0216b348;
    if (state->busy) {
        return 0;
    }
    func_0202ba34(state->provider);
    if (!func_0202baf8(request, state->provider)) {
        return 0;
    }
    func_0202ba34(state->provider);
    return 1;
}

/* Finds the first empty borrowed slot at +0xa8, returning -1 if all eight
 * are occupied; evidence: LDR/CMP loop at 0205e680..e698. */
s32 func_0205e678(void)
{
    s32 i;
    for (i = 0; i < 8; i++) {
        if (!data_0216b348.slots[i]) {
            return i;
        }
    }
    return -1;
}

/* Reverses the two provider arguments and converts a positive result to one;
 * evidence: MOV sequence and MOVGT/MOVLE at 0205e744..e75c. */
s32 func_0205e740(s32 argument, s32 index)
{
    return func_0202a110(index, argument) > 0;
}

/* Valid indices are 0..7; clamp the unsigned value to the literal limit before
 * forwarding the borrowed slot address (0205e768..e788). */
void func_0205e764(s32 index, u32 value)
{
    if (index < 0 || index >= 8) {
        return;
    }
    if (value > 0xffff) {
        value = 0xffff;
    }
    func_0202a0c4(&data_0216b3f0[index], value);
}

/* Index eight applies the clamped level to all eight handles; other indices
 * must address caller-validated storage. Evidence: CMP #8 and loop at e7b0. */
void func_0205e79c(s32 index, u32 level, s32 duration)
{
    s32 i;
    if (level > 127) {
        level = 127;
    }
    if (index == 8) {
        for (i = 0; i < 8; i++) {
            func_0202a184(&data_0216b3f0[i], level, duration);
        }
    } else {
        func_0202a184(&data_0216b3f0[index], level, duration);
    }
}

/* Requires enabled state and an empty slot; submits with three -1 defaults,
 * applies the stored level, and returns the slot. Evidence: e6c0..e738. */
s32 func_0205e6c0(s32 request, s32 argument)
{
    Unk0205e53cState *state = &data_0216b348;
    s32 slot;
    if (!state->enabled) {
        return -1;
    }
    slot = func_0205e678();
    if (slot == -1) {
        return -1;
    }
    func_0202c588(&data_0216b3f0[slot], -1, -1, -1, argument, request);
    func_0205e79c(slot, state->level, 0);
    return slot;
}
