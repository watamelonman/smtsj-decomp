#ifndef SDK_02010F98_H
#define SDK_02010F98_H

#include "types.h"

/** Borrowed interrupt-state record: +0 is a nonzero test word and +4 is the
 * CPSR image that func_020111f4 restores. The caller owns the storage. */
typedef struct {
    u32 unk_00;
    u32 irq_state;
} Unk111f4_State;

/** Borrowed two-word value consumed by the WAITCNT update; only bit 0 of each
 * word is copied into the register (bits 2-3 and bit 4 respectively). */
typedef struct {
    u32 unk_00;
    u32 unk_04;
} Unk11164_Value;

/** Requests ARM7 operation 2 and then enters the non-returning wait loop. */
void func_020115e0(void);

/** Clears the word at data_02155740 + 4. */
void func_020115f4(void);

/** Zero-fills the caller-owned 36-byte block through the unaligned-safe fill. */
void func_02011694(void *dst);

/** Returns bit 0 of the boot-status byte at 0x027ffc30 + 5. */
int func_02010ff8(void);

/** Forwards the caller's first argument to func_02005ca0 when state + 0 is
 * zero, then restores the interrupt state stored at state + 4. */
void func_020111f4(void *arg, Unk111f4_State *state);

/** Returns 1 only when func_02011010 succeeds and func_02010ff8 is clear. */
int func_02010fd0(void);

/** Accepts value & 63 == 1 by setting data_02155728 to 1; every other value
 * enters the non-returning wait loop. The first argument is unused. */
void func_02011558(u32 unused, u32 value);

/** Replaces WAITCNT (0x04000204) bits 2-3 from value + 0 and bit 4 from
 * value + 4; the remaining register bits are preserved. */
void func_02011164(Unk11164_Value *value);

#endif
