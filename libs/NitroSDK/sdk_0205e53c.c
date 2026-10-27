#include "types.h"

/* Provider-owned prefix at 0216b348; padding preserves only observed offsets.
 * No wrapper allocates or retains storage beyond this existing singleton. */
typedef struct Unk0205e53cState {
    u8 reserved00[0x94];
    void *provider;
    u32 saved;
    u8 reserved9c[0x2c];
    float value;
    u32 reservedcc;
    s32 status;
    s32 argument;
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
