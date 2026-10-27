#ifndef SDK_02005A08_H
#define SDK_02005A08_H

#include "types.h"

/** Borrowed spin-lock word: owner and extension follow the original stores. */
typedef volatile struct OSLockWord {
    u32 lockFlag;
    u16 ownerID;
    u16 extension;
} OSLockWord;

/** OS_ResetRequestIrqMask equivalent: returns REG_IF and writes the request mask. */
u32 func_02005a08(u32 mask);
/** OS_SetIrqStackChecker equivalent: still delinked; see the TU hard list. */
void func_02005a34(void);
/** OS_InitLock equivalent: still delinked; see the TU hard list. */
void func_02005a68(void);
/** OSi_DoLockByWord equivalent: retries a lock until it succeeds or returns <= 0. */
s32 func_02005b34(u16 lockId, OSLockWord *lockp, void (*ctrlFuncp)(void), s32 disableFiq);
/** OS_TryLockByWord equivalent: tries the shared lock with IRQ-only masking. */
s32 func_02005b80(u16 lockId, OSLockWord *lockp, void (*ctrlFuncp)(void));
/** OSi_DoUnlockByWord equivalent: clears a lock owned by lockId. */
s32 func_02005b90(u16 lockId, OSLockWord *lockp, void (*ctrlFuncp)(void), s32 disableFiq);
/** OS_UnlockByWord equivalent: unlocks with IRQ-only masking. */
s32 func_02005c04(u16 lockId, OSLockWord *lockp, void (*ctrlFuncp)(void));
/** OSi_DoTryLockByWord equivalent: one compare-and-swap attempt on the lock word. */
s32 func_02005c14(u16 lockId, OSLockWord *lockp, void (*ctrlFuncp)(void), s32 disableFiq);

#endif
