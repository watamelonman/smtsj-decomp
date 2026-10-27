#include "libs/NitroSDK/sdk_02010f98.h"

/* Existing SDK providers: ARM7 request/acknowledge, the non-returning wait
 * loop, the unaligned-safe fill, the interrupt restore, and the two probes. */
extern void func_02011218(u32 value);
extern void func_02007e94(void);
extern void func_02008848(void *dst, int value, u32 size);
extern void func_02005ca0(void *arg);
extern void func_02007a6c(u32 state);
extern int func_02011010(void);

/* BSS globals owned by the surrounding SDK initialisation code. Only the
 * observed fields are exposed; the halfword at data_02155728 is the flag that
 * func_02011558 sets on the accepted value. */
typedef struct {
    u8 pad_00[4];
    u32 field_04;
} Unk10f98_Global;

typedef struct {
    u16 field_00;
} Unk11558_Flag;

extern Unk10f98_Global data_02155740;
extern Unk11558_Flag data_02155728;

/** Requests ARM7 operation 2 through func_02011218, then falls into
 * func_02007e94, which disables interrupts and invalidates the data cache
 * forever. The original never returns.
 */
void func_020115e0(void)
{
    func_02011218(2);
    func_02007e94();
}

/** Clears the word at data_02155740 + 4; no other state is touched. */
void func_020115f4(void)
{
    data_02155740.field_04 = 0;
}

/** Zero-fills 36 bytes at dst using func_02008848, whose unaligned-safe fill is
 * also used for the SDK message buffer; dst ownership stays with the caller.
 */
void func_02011694(void *dst)
{
    func_02008848(dst, 0, 36);
}

/** Reads the boot-status block at 0x027ffc30: the original materialises the
 * block base as a literal, loads byte +5 and isolates bit 0 with a shift pair.
 */
int func_02010ff8(void)
{
    const u8 *boot = (const u8 *)0x027ffc30;

    return (u32)(boot[5] << 31) >> 31;
}

/** If the word at state + 0 is zero, forwards the caller's argument to
 * func_02005ca0; then restores the interrupt state saved at state + 4. The
 * original keeps the forwarded argument in r0 across the test.
 */
void func_020111f4(void *arg, Unk111f4_State *state)
{
    if (state->unk_00 == 0)
        func_02005ca0(arg);
    func_02007a6c(state->irq_state);
}

/** Two-stage probe: func_02011010 must succeed and func_02010ff8 must report
 * clear. Any failure, including the first probe failing, returns zero.
 */
int func_02010fd0(void)
{
    if (func_02011010() != 0) {
        if (func_02010ff8() == 0)
            return 1;
    }
    return 0;
}

/** Masks the second argument to six bits. Only value & 63 == 1 is accepted,
 * setting data_02155728 to 1; any other value takes the non-returning wait
 * loop. The first argument is not read.
 */
void func_02011558(u32 unused, u32 value)
{
    if ((value & 63) == 1) {
        data_02155728.field_00 = 1;
        return;
    }
    func_02007e94();
}

/** Updates WAITCNT (0x04000204): clears bits 2-3 and copies value + 0 into
 * them, then clears bit 4 and copies value + 4 into it. The register is
 * volatile because the original performs two read-modify-write passes.
 */
void func_02011164(Unk11164_Value *value)
{
    volatile u16 *waitcnt = (volatile u16 *)0x04000204;

    *waitcnt = (value->unk_00 << 2) | (*waitcnt & ~12);
    *waitcnt = (value->unk_04 << 4) | (*waitcnt & ~16);
}
