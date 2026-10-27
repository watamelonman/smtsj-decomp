#include "libs/NitroSDK/sdk_02005a08.h"

/* func_02005a34 and func_02005a68 remain linked from the delink: their original
 * literals referenced linker-defined values that the delink did not preserve.
 * See DEC-034 and docs/functions/libs-nitrosdk-sdk-02005a08.md. */

/* External SDK entry points retain the delink's symbol names. */
extern void WaitByLoop(u32 count);
extern s32 func_02007a58(void);
extern s32 func_02007a6c(s32 state);
extern s32 func_02007a84(void);
extern s32 func_02007a98(s32 state);
extern u32 func_02008a94(u32 data, volatile u32 *dest);

/* Register views used by the interrupt-mask helper. */
#define REG_OS_IME (*(volatile u16 *)0x04000208)
#define REG_OS_IF (*(volatile u32 *)0x04000214)

/** The shared lock word is polled while another processor owns it. */
static inline void OSi_WaitByLoop(void)
{
    WaitByLoop(0x1000 / 4);
}

/* OS_ResetRequestIrqMask in pret/pokediamond's OS_interrupt.c: returns the
 * previous request flags and writes mask while interrupts are disabled. */
u32 func_02005a08(u32 mask)
{
    u16 regIme = REG_OS_IME;
    u32 regIf;

    REG_OS_IME = 0;
    regIf = REG_OS_IF;
    REG_OS_IF = mask;
    /* Volatile reload of IME after the IF write reproduces the target's
     * instruction sequence before IME is restored. */
    (void)REG_OS_IME;
    REG_OS_IME = regIme;
    return regIf;
}

/* OSi_DoLockByWord in pret/pokediamond's OS_spinLock.c: retries the
 * compare-and-swap attempt, yielding to the other processor between tries. */
s32 func_02005b34(u16 lockId, OSLockWord *lockp, void (*ctrlFuncp)(void), s32 disableFiq)
{
    s32 lastLockFlag;

    while ((lastLockFlag = func_02005c14(lockId, lockp, ctrlFuncp, disableFiq)) > 0) {
        OSi_WaitByLoop();
    }
    return lastLockFlag;
}

/* OS_TryLockByWord in pret/pokediamond's OS_spinLock.c: despite the "try"
 * name, the target forwards to OSi_DoLockByWord (func_02005b34) with
 * disableFiq = 0, so it retries and yields while a competing owner holds the
 * lock instead of returning immediately. */
s32 func_02005b80(u16 lockId, OSLockWord *lockp, void (*ctrlFuncp)(void))
{
    return func_02005b34(lockId, lockp, ctrlFuncp, 0);
}

/* OSi_DoUnlockByWord in pret/pokediamond's OS_spinLock.c: rejects a mismatched
 * owner, then clears the owner and flag around the optional bus callback. */
s32 func_02005b90(u16 lockId, OSLockWord *lockp, void (*ctrlFuncp)(void), s32 disableFiq)
{
    s32 lastIntrMode;

    if (lockId != lockp->ownerID) {
        return -2;
    }

    lastIntrMode = disableFiq ? func_02007a84() : func_02007a58();
    lockp->ownerID = 0;
    if (ctrlFuncp != 0) {
        ctrlFuncp();
    }
    lockp->lockFlag = 0;
    if (disableFiq) {
        (void)func_02007a98(lastIntrMode);
    } else {
        (void)func_02007a6c(lastIntrMode);
    }
    return 0;
}

/* OS_UnlockByWord in pret/pokediamond's OS_spinLock.c: unlocks with IRQ-only
 * masking, leaving FIQ enabled. */
s32 func_02005c04(u16 lockId, OSLockWord *lockp, void (*ctrlFuncp)(void))
{
    return func_02005b90(lockId, lockp, ctrlFuncp, 0);
}

/* OSi_DoTryLockByWord in pret/pokediamond's OS_spinLock.c: one swap of the
 * lock word; on success it records the owner and runs the bus callback. */
s32 func_02005c14(u16 lockId, OSLockWord *lockp, void (*ctrlFuncp)(void), s32 disableFiq)
{
    s32 lastIntrMode = disableFiq ? func_02007a84() : func_02007a58();
    s32 lastLockFlag = (s32)func_02008a94(lockId, &lockp->lockFlag);

    if (lastLockFlag == 0) {
        if (ctrlFuncp != 0) {
            ctrlFuncp();
        }
        lockp->ownerID = lockId;
    }

    if (disableFiq) {
        (void)func_02007a98(lastIntrMode);
    } else {
        (void)func_02007a6c(lastIntrMode);
    }
    return lastLockFlag;
}
