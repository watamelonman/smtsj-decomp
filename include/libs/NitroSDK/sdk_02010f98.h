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

/** View of the word at data_02155724 plus the halfword at +6. The halfword
 * overlaps data_02155728 +2, which func_02010f98 writes after clearing the
 * 32-bit flag word at data_02155728. */
typedef struct {
    u32 field_00;
    u16 field_04;
    u16 field_06;
} Unk10f98_Boot;

/** Word at data_02155728: +0 is the flag func_02011558 sets and func_02011364
 * polls as subpInitialized, +2 is the cartridge lock id passed to the
 * lock/unlock pair. func_02010f98 clears the whole word. */
typedef struct {
    volatile u16 field_00;
    u16 lock_id;
} Unk11558_Flag;

/** Cartridge header layout used by HW_CTRDG_ROM (0x08000000) and by the
 * 0xc0-byte copy at data_02155760. Offsets are taken from the public
 * CTRDGHeader in NitroSDK (libraries/ctrdg/include/ctrdg_common.h): gameCode
 * +0xac, isRomCode +0xb2, exLsiID +0xb5 and moduleID +0xbe. */
typedef struct {
    u32 startAddress;
    u8 nintendoLogo[0x9c];
    u8 titleName[12];
    u32 gameCode;
    u16 makerCode;
    u8 isRomCode;
    u8 machineCode;
    u8 deviceType;
    u8 exLsiID[3];
    u8 reserved[4];
    u8 softVersion;
    u8 complement;
    u16 moduleID;
} Unk10f98_CtrdgHeader;

/** Cartridge module info at HW_CTRDG_MODULE_INFO_BUF (0x027ffc30), matching
 * the public CTRDGModuleInfo. Byte +5 holds isAgbCartridge in bit 0 and
 * detectPullOut in bit 1; the module check sets the latter on a mismatch. */
typedef struct {
    u16 moduleID;
    u8 exLsiID[3];
    u8 isAgbCartridge : 1;
    u8 detectPullOut : 1;
    u8 : 0;
    u16 makerCode;
    u32 gameCode;
} Unk10f98_ModuleInfo;

/** EXMEMCNT readback: +0 receives bits 2-3 and +4 receives bit 4. */
typedef struct {
    u32 field_00;
    u32 field_04;
} Unk1111c_Value;

/** Borrowed wait-loop state: +0 holds the extracted status mask and +4 holds
 * the CPSR image captured for the next iteration. */
typedef struct {
    u32 field_00;
    u32 field_04;
} Unk11198_State;

/** Borrowed 0xE8-byte worker/thread object initialized by func_02011608; +0xc0
 * is a word slot and +0xc4 is the 36-byte message buffer passed to
 * func_02011694. */
typedef struct {
    u8 pad_00[0xc0];
    u32 field_c0;
    u8 field_c4[36];
} Unk11608_Work;

/** PXI callback shape registered by func_020112b0; the callbacks in this unit
 * read only the second word, but the ARM7 FIFO passes three. */
typedef void (*Unk10f98_PxiCallback)(u32, u32, s32);

/** Borrowed global at data_02155740: +8 is the once-only guard, +0xc is the
 * accepted-callback flag and +0x18 is the optional int-returning probe. */
typedef struct {
    u32 field_00;
    u32 field_04;
    u32 field_08;
    u32 field_0c;
    u32 field_10;
    u32 field_14;
    int (*callback)(void);
} Unk10f98_Global;

/** Requests ARM7 operation 2 and then enters the non-returning wait loop. */
void func_020115e0(void);

/** Clears the word at data_02155740 + 4. */
void func_020115f4(void);

/** Zero-fills the caller-owned 36-byte block through the unaligned-safe fill. */
void func_02011694(void *dst);

/** Returns bit 0 of the boot-status byte at 0x027ffc30 + 5. */
int func_02010ff8(void);

/** Cartridge-presence probe; matches the public CTRDG_IsExisting. Returns 0
 * for the all-ones module id, a latched pull-out, or a header mismatch, and
 * latches detectPullOut on the mismatch. */
int func_02011010(void);

/** Forwards the caller's first argument to func_02005ca0 when state + 0 is
 * zero, then restores the interrupt state stored at state + 4. */
void func_020111f4(void *arg, Unk111f4_State *state);

/** Returns 1 only when func_02011010 succeeds and func_02010ff8 is clear. */
int func_02010fd0(void);

/** Accepts value & 63 == 1 by setting data_02155728 to 1; every other value
 * enters the non-returning wait loop. The first argument is unused. */
void func_02011558(u32 unused, u32 value);

/** Replaces EXMEMCNT (0x04000204) bits 2-3 from value + 0 and bit 4 from
 * value + 4; the remaining register bits are preserved. */
void func_02011164(Unk11164_Value *value);

/** Clears the 32-bit flag at data_02155728 through CpuSet and stores the next
 * lock id (func_02005d6c) at data_02155724 + 6. */
void func_02010f98(void);

/** Reads EXMEMCNT bits 2-3 and bit 4 into out, then forces bits 2-3 to 3 and
 * clears bit 4, leaving the other wait-state fields untouched. */
void func_0201111c(Unk1111c_Value *out);

/** Polls the shared work area until func_02005d64 reports bit 0x40 or
 * func_02005cac rejects the argument; each pass re-saves interrupts. */
void func_02011198(void *arg, Unk11198_State *state);

/** Sends PXI FIFO tag 13; returns when func_0200a4a0 reports 0 (success).
 * While it reports nonzero (FIFO busy/error), yields through WaitByLoop(1)
 * and retries until the send succeeds. */
void func_02011218(u32 value);

/** Stores the caller's state word at data_02155724 and, unless the boot probe
 * already succeeded, read-modify-writes CP15 c5 bits 12-15 through
 * func_0200720c (0x5000 for a null state, 0x1000 otherwise). */
void func_02011268(u32 state);

/** One-time PXI/ARM7 setup: installs tag 13 handlers, starts the message worker
 * and leaves the interrupt state restored. */
void func_020112b0(void);

/** One-time cartridge module-info init; matches the public
 * CTRDGi_InitModuleInfo: reads the cartridge header, copies its id fields into
 * the shared module-info buffer and tells the ARM7 through the CTRDG FIFO.
 * The C body is deferred on the hard list; the delinked original supplies this
 * symbol until it is matched. */
void func_02011364(void);

/** Handles tag-17 callbacks once: ignores an already-accepted +0xc flag, runs
 * the optional +0x18 probe and sets the accepted flag at +0xc. */
void func_02011584(u32 unused, u32 value);

/** Initializes the borrowed work block once, registers func_020116a8 as the
 * worker entry and zero-fills the message buffers before releasing interrupts. */
void func_02011608(Unk11608_Work *work);

#endif
