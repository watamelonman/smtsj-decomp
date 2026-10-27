#include "libs/NitroSDK/sdk_02010f98.h"

/* External SDK providers: the non-returning wait loop, the unaligned-safe
 * fill, the interrupt save/restore pair, the PXI FIFO entry points and the
 * CpuSet/wait helpers. The Thumb WaitByLoop/CpuSet calls become blx after the
 * linker resolves the interworking relocations. */
extern void func_02007e94(void);
extern void func_02008848(void *dst, int value, u32 size);
extern void func_02005ca0(void *arg);
extern void func_02007a6c(u32 state);
extern void CpuSet(const void *src, void *dest, u32 control);
extern s32 func_02005d6c(void);
extern u32 func_02005d64(const void *p);
extern s32 func_02005cac(void *p);
extern u32 func_02007a58(void);
extern void func_0200720c(u32 mask, u32 value);
extern void WaitByLoop(u32 count);
extern s32 func_0200a4a0(u32 tag, u32 data, u32 error);
extern s32 func_0200a47c(u32 tag, u32 processor);
extern void func_0200a430(u32 tag, Unk10f98_PxiCallback callback);
extern void func_0200a324(void);
extern void func_02011364(void);
extern void func_020116a8(void *work);
extern void func_0200621c(void *thread, void (*entry)(void *), void *arg,
                          void *stack, u32 stack_size, u32 priority);
extern void func_020064e0(void *thread);

/* BSS globals owned by the surrounding SDK initialisation code. Only the
 * observed fields are exposed; data_02155724 and data_02155728 overlap the
 * halfword written by func_02010f98, and data_02155908 holds the worker
 * pointer that func_020116a8 later polls. */
extern Unk10f98_Boot data_02155724;
extern Unk11558_Flag data_02155728;
extern Unk10f98_Global data_02155740;
extern Unk11608_Work data_02155820;
extern Unk11608_Work *data_02155908;
extern u8 data_0215590c[];
extern u8 data_02155d30[];

/* PXI FIFO service wrappers shared with libs/NitroSDK/sdk_0200d380.c: there
 * func_0200a324 initializes the FIFO, func_0200a47c polls a tag for a
 * processor, func_0200a430 registers a handler and func_0200a4a0 sends a tag
 * (returning 0 on success). Tags 13 and 17 are the FIFO tags this unit
 * registers in func_020112b0; their firmware-side meaning is not present in
 * the checked-in sources, so they stay numeric. The ARM7 processor id is the
 * same PXI_PROC_ARM7 value used by sdk_0200d380.c. */
#define PXI_FIFO_TAG_13 13
#define PXI_FIFO_TAG_17 17
#define PXI_PROC_ARM7 1

/* func_0200720c read-modify-writes CP15 c5 (the access-permission register):
 * it clears the bits in its mask argument and ORs in its value argument. The
 * 0xf000 mask below selects bits 12-15 of that register. */
#define CP15_C5_PERM_MASK 0xf000

/* Cartridge (CTRDG) addresses and fields, taken from the public NitroSDK
 * headers (include/nitro/hw/common/mmap_shared.h, ctrdg_common.h,
 * ioreg_MI.h and ioreg_OS.h). The CTRDG code in this unit is the same code as
 * NitroSDK libraries/ctrdg/src/ctrdg.c (CTRDG_IsExisting) and ctrdg_proc.c
 * (CTRDGi_InitModuleInfo), so these names document the hardware they touch
 * even though the link-time symbols stay neutral. */
#define HW_CTRDG_ROM 0x08000000u
#define HW_CTRDG_MODULE_INFO_BUF 0x027ffc30u
#define HW_CTRDG_MODULE_ID_IMAGE (HW_CTRDG_ROM + 0x1fffeu)
#define CTRDG_IS_ROM_CODE 0x96u


/** Clears the 32-bit flag word at data_02155728 with a one-word CpuSet fill,
 * then stores the next lock id returned by func_02005d6c in the halfword at
 * data_02155724 + 6. That halfword is the upper half of the cleared word.
 */
void func_02010f98(void)
{
    u32 zero = 0;

    CpuSet(&zero, &data_02155728, 0x05000001);
    data_02155724.field_06 = func_02005d6c();
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

/** Reads the boot-status block at 0x027ffc30: the original materialises the
 * block base as a literal, loads byte +5 and isolates bit 0 with a shift pair.
 */
int func_02010ff8(void)
{
    const u8 *boot = (const u8 *)0x027ffc30;

    return (u32)(boot[5] << 31) >> 31;
}

/** Cartridge-presence probe. This is the public CTRDG_IsExisting body from
 * NitroSDK libraries/ctrdg/src/ctrdg.c: the module info at 0x027ffc30 is
 * compared with the cartridge header at 0x08000000 (module id at +0xbe for
 * ROM code, the 0x0801fffe module-id image otherwise, plus the game code for
 * AGB cartridges). A mismatch latches detectPullOut (byte +5 bit 1) and makes
 * the probe return 0. The lock id used here is the halfword at data_02155724
 * + 6, which is the same CTRDGi_Work.lockID read by func_02011364.
 */
int func_02011010(void)
{
    int retval = 1;
    Unk11198_State lockInfo;
    Unk1111c_Value rc;
    Unk10f98_ModuleInfo *cip = (Unk10f98_ModuleInfo *)HW_CTRDG_MODULE_INFO_BUF;
    Unk10f98_CtrdgHeader *chp = (Unk10f98_CtrdgHeader *)HW_CTRDG_ROM;

    if (cip->moduleID == 0xffff)
        return 0;
    if (cip->detectPullOut == 1)
        return 0;

    func_02011198((void *)(u32)data_02155724.field_06, &lockInfo);
    func_0201111c(&rc);

    if ((chp->isRomCode == CTRDG_IS_ROM_CODE && cip->moduleID != chp->moduleID) ||
        (chp->isRomCode != CTRDG_IS_ROM_CODE &&
         cip->moduleID != *(u16 *)HW_CTRDG_MODULE_ID_IMAGE) ||
        (cip->gameCode != chp->gameCode && cip->isAgbCartridge)) {
        cip->detectPullOut = 1;
        retval = 0;
    }

    func_02011164((Unk11164_Value *)&rc);
    func_020111f4((void *)(u32)data_02155724.field_06, (Unk111f4_State *)&lockInfo);
    return retval;
}

/** Mirrors the EXMEMCNT fields into out, then forces bits 2-3 to 3 and clears
 * bit 4. Each read is a separate volatile load, as in the original.
 */
void func_0201111c(Unk1111c_Value *out)
{
    volatile u16 *waitcnt = (volatile u16 *)0x04000204;

    out->field_00 = (*waitcnt & 12) >> 2;
    out->field_04 = (*waitcnt & 16) >> 4;
    *waitcnt = (*waitcnt & ~12) | 12;
    *waitcnt = *waitcnt & ~16;
}

/** Updates EXMEMCNT (0x04000204): clears bits 2-3 and copies value + 0 into
 * them, then clears bit 4 and copies value + 4 into it. The register is
 * volatile because the original performs two read-modify-write passes.
 */
void func_02011164(Unk11164_Value *value)
{
    volatile u16 *waitcnt = (volatile u16 *)0x04000204;

    *waitcnt = (value->unk_00 << 2) | (*waitcnt & ~12);
    *waitcnt = (value->unk_04 << 4) | (*waitcnt & ~16);
}

/** Wait loop: after saving interrupts, stores the status word from
 * func_02005d64(0x027fffe8) at state + 0 and the CPSR image at state + 4. A
 * set bit 0x40 or a rejected func_02005cac probe ends the loop; otherwise the
 * saved interrupts are restored, WaitByLoop yields and the loop retries.
 */
void func_02011198(void *arg, Unk11198_State *state)
{
    for (;;) {
        state->field_04 = func_02007a58();
        state->field_00 = func_02005d64((const void *)0x027fffe8) & 64;
        if (state->field_00 != 0)
            return;
        if (func_02005cac(arg) == 0)
            return;
        func_02007a6c(state->field_04);
        WaitByLoop(1);
    }
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

/** Sends PXI FIFO tag 13 with the caller's value. func_0200a4a0 returns 0 on
 * success (-1 when the FIFO is busy, -2 on error); while it returns nonzero,
 * yield through WaitByLoop(1) and retry until the send succeeds.
 */
void func_02011218(u32 value)
{
    if (func_0200a4a0(PXI_FIFO_TAG_13, value, 0) == 0)
        return;
    do {
        WaitByLoop(1);
    } while (func_0200a4a0(PXI_FIFO_TAG_13, value, 0) != 0);
}

/** Stores the caller's state word at data_02155724 + 0 and, when the boot probe
 * func_02010fd0 fails, read-modify-writes CP15 c5 through func_0200720c: the
 * 0xf000 mask selects bits 12-15, written as 0x5000 for a null state or 0x1000
 * otherwise.
 */
void func_02011268(u32 state)
{
    u32 irq = func_02007a58();

    data_02155724.field_00 = state;
    if (func_02010fd0() == 0)
        func_0200720c(CP15_C5_PERM_MASK, state != 0 ? 0x1000 : 0x5000);
    func_02007a6c(irq);
}

/** One-time PXI/ARM7 setup guarded by data_02155740 + 8: sets the guard, calls
 * func_02010f98 to clear the tag word and record a fresh lock id, clears the
 * +0xc accepted flag, calls func_0200a324, waits for tag 13 availability and
 * installs the tag-13 handlers. After installing them it clears the +0x18
 * callback slot, starts the worker through func_02011608 and finally installs
 * the tag-17 handler.
 */
void func_020112b0(void)
{
    if (data_02155740.field_08 != 0)
        return;
    data_02155740.field_08 = 1;
    func_02010f98();
    data_02155740.field_0c = 0;
    func_0200a324();
    while (func_0200a47c(PXI_FIFO_TAG_13, PXI_PROC_ARM7) == 0) { }
    func_0200a430(PXI_FIFO_TAG_13, (Unk10f98_PxiCallback)func_02011558);
    func_02011364();
    func_0200a430(PXI_FIFO_TAG_13, 0);
    func_0200a430(PXI_FIFO_TAG_13, (Unk10f98_PxiCallback)func_02011584);
    data_02155740.callback = 0;
    func_02011608(&data_02155820);
    func_0200a430(PXI_FIFO_TAG_17, (Unk10f98_PxiCallback)func_020115f4);
    func_02011268(0);
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

/** Tag-17 callback: masks the value to six bits and only 17 is accepted; any
 * other value enters the non-returning wait loop. For 17, an already-accepted
 * +0xc flag skips the work, the optional +0x18 probe runs, and a nonzero probe
 * result enters the non-returning ARM7 loop. Finally +0xc is set.
 */
void func_02011584(u32 unused, u32 value)
{
    int result;

    if ((value & 63) == PXI_FIFO_TAG_17) {
        if (data_02155740.field_0c != 0)
            return;
        result = 0;
        if (data_02155740.callback != 0)
            result = data_02155740.callback();
        if (result != 0)
            func_020115e0();
        data_02155740.field_0c = 1;
    } else {
        func_02007e94();
    }
}

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

/** Initializes the worker block once (data_02155908 acts as the once-only
 * pointer): zero-fills the 36-byte buffers at work + 0xc4 and data_0215590c,
 * clears the word at work + 0xc0, registers func_020116a8 with a 1024-byte
 * stack at priority 20, and starts the worker before restoring interrupts.
 */
void func_02011608(Unk11608_Work *work)
{
    u32 irq = func_02007a58();

    if (data_02155908 == 0) {
        data_02155908 = work;
        func_02011694(work->field_c4);
        func_02011694(data_0215590c);
        work->field_c0 = 0;
        func_0200621c(work, func_020116a8, work, data_02155d30, 1024, 20);
        func_020064e0(work);
    }
    func_02007a6c(irq);
}

/** Zero-fills 36 bytes at dst using func_02008848, whose unaligned-safe fill is
 * also used for the SDK message buffer; dst ownership stays with the caller.
 */
void func_02011694(void *dst)
{
    func_02008848(dst, 0, 36);
}
