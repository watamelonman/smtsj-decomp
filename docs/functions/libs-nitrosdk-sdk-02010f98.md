# NitroSDK unit 02010f98

Public-source lookup: the unit was checked against the NitroSDK OS/PXI shapes already
documented in this repository (the neighbouring `sdk_020116a8` message pump, the
`OS_InitIrqTable`/interrupt-restore helpers and the PXI tag wrappers in `sdk_0200d380`).
The two functions in this card are the cartridge (CTRDG) paths from the public NitroSDK
sources: `CTRDG_IsExisting` in `libraries/ctrdg/src/ctrdg.c` and
`CTRDGi_InitModuleInfo` in `libraries/ctrdg/src/ctrdg_proc.c`. Existing `func_` linker
names are retained because `config/arm9/symbols.txt` is human-owned.

The functions operate on borrowed state: `Unk111f4_State` holds a test word at +0 and the CPSR
image restored at +4; `Unk11164_Value` and `Unk1111c_Value` supply/read the two EXMEMCNT fields;
`Unk11198_State` holds the polling status and saved CPSR; `Unk11608_Work` describes the worker
block at `data_02155820`; the BSS views at `data_02155724`, `data_02155728`,
`data_02155740` and `data_02155908` expose only the words the original touches. The CTRDG
module-info record is the SystemWork block at `0x027ffc30`, the cartridge header is
`0x08000000`, the module-id image is `0x0801fffe`, and the one-time pause register is
`0x04000300` bit 0.

The PXI constants mirror `libs/NitroSDK/sdk_0200d380.c`, which drives the same
`func_0200a324` / `func_0200a47c` / `func_0200a430` / `func_0200a4a0` wrappers:
`func_0200a4a0` returns 0 on success, processor id 1 is the ARM7, and the numeric tags 13 and 17
are the FIFO tags this unit registers in `func_020112b0` (their firmware-side meaning is not in
the checked-in sources, so they are not renamed). `func_0200720c(mask, value)` is the CP15 c5
(access-permission) read-modify-write helper: it clears `mask` bits and ORs in `value`, so
`0xf000` selects bits 12-15 and the `0x1000` / `0x5000` arguments set those bits directly.

| Function | Evidence and contract | Result |
| --- | --- | --- |
| `func_02010f98` | Clears the 32-bit word at `data_02155728` with `CpuSet(&zero, &data_02155728, 0x05000001)` (one 32-bit fill word), then stores `func_02005d6c()` in the halfword at `data_02155724 + 6`, which is inside the cleared word. The lock-id getter is the same one documented for `OS_GetLockID` in `sdk_020026a0`. | 100% |
| `func_02010fd0` | Returns 1 only when `func_02011010` returns nonzero and `func_02010ff8` returns zero. Both the failed first probe and a set second probe return 0. | 100% |
| `func_02010ff8` | Materialises `0x027ffc30` as a literal, loads byte +5 and isolates bit 0 with a `lsl #31` / `lsr #31` pair. | 100% |
| `func_02011010` | Public `CTRDG_IsExisting`: rejects module id `0xffff` and a latched pull-out, locks with the halfword at `data_02155724 + 6`, saves the ROM cycle, then compares the module info with the header at `0x08000000` (module id +0xbe for `isRomCode == 0x96`, `0x0801fffe` otherwise, plus `gameCode` +0xac for AGB modules). A mismatch sets `detectPullOut` (info +5 bit 1) and returns 0; the lock and ROM cycle are restored either way. | 100% |
| `func_0201111c` | Six volatile EXMEMCNT (`0x04000204`) accesses: exports `(EXMEMCNT & 12) >> 2` to +0 and `(EXMEMCNT & 16) >> 4` to +4, then forces bits 2-3 to 3 and clears bit 4 while preserving every other register bit. Matches the public `CTRDGi_ChangeLatestAccessCycle`. | 100% |
| `func_02011164` | Two EXMEMCNT read-modify-writes: bits 2-3 receive `value->unk_00`, then bit 4 receives `value->unk_04`; the other register bits are preserved. Matches the public `CTRDGi_RestoreAccessCycle`. | 100% |
| `func_02011198` | Polling lock loop. Saves interrupts, stores `func_02005d64((void *)0x027fffe8) & 0x40` at state +0 and the CPSR image at +4. A set 0x40 or a zero `func_02005cac(arg)` return ends it; otherwise interrupts are restored, `WaitByLoop(1)` yields and the loop repeats. Matches the public `CTRDGi_LockByProcessor`. | 100% |
| `func_020111f4` | Tests the word at state +0; when zero, forwards the caller's first argument unchanged to `func_02005ca0`. Then restores the CPSR image at state +4 through `func_02007a6c`. Matches the public `CTRDGi_UnlockByProcessor`. | 100% |
| `func_02011218` | PXI tag-13 request. `func_0200a4a0(13, value, 0)` returns 0 on success (-1 when the FIFO is busy, -2 on error); while it returns nonzero the loop yields through `WaitByLoop(1)` and retries until the send succeeds. Matches the public `CTRDGi_SendtoPxi`. | 100% |
| `func_02011268` | Stores the caller word at `data_02155724 + 0` and restores interrupts. When the boot probe `func_02010fd0()` fails, `func_0200720c(0xf000, ...)` read-modify-writes CP15 c5 (access-permission register), replacing bits 12-15 with `0x5000` for a null state or `0x1000` otherwise. | 100% |
| `func_020112b0` | One-time PXI/ARM7 setup guarded by `data_02155740 + 8`: sets the guard, calls `func_02010f98` to clear the tag word and record a fresh lock id, clears the +0xc accepted flag, calls `func_0200a324`, waits for tag 13 in `func_0200a47c`, and installs the tag-13 callbacks `func_02011558` and `func_02011584` (with `func_02011364` between them). After that it clears the +0x18 callback slot, starts the worker through `func_02011608(&data_02155820)`, installs the tag-17 callback `func_020115f4`, and finally calls `func_02011268(0)`. | 100% |
| `func_02011364` | Public `CTRDGi_InitModuleInfo`: one-time guard at `data_02155740 + 0`; pauses unless `0x04000300` bit 0 is set; saves IE/IME; locks the cartridge; switches EXMEMCNT to the ARM9 and lowers the ROM cycle; invalidates and DMAs header bytes +0x80..+0xbf; copies the id fields into `0x027ffc30` when `0x027fff9b` is set or `0x027fff9a` is clear; copies the BIOS Nintendo logo (`0xffff0020`, 0x9c bytes); flushes; sends the CTRDG init command with the header-buffer address; waits for `data_02155728` halfword 0 to become 1; restores IME/IE. | Not matched (hard list) |
| `func_02011558` | Masks the second argument with 63; only the value 1 sets the halfword at `data_02155728` to 1. Every other value enters the non-returning `func_02007e94` loop. The first argument is not read. | 100% |
| `func_02011584` | Tag-17 callback. Masks the value to six bits; only 17 is accepted, and any other value enters the non-returning `func_02007e94` loop. For 17, a nonzero +0xc flag returns immediately; the optional +0x18 int-returning callback runs and a nonzero result enters the non-returning `func_020115e0` ARM7 request. The +0xc flag is then set. | 100% |
| `func_020115e0` | Requests ARM7 operation 2 through `func_02011218`, then falls into `func_02007e94`, whose loop disables interrupts and invalidates the data cache forever. The original never returns. | 100% |
| `func_020115f4` | Loads `data_02155740` and stores zero at +4; no other state is touched. | 100% |
| `func_02011608` | Worker bootstrap under `data_02155908` as the once-only pointer: stores the work pointer, zero-fills the 36-byte buffers at work +0xc4 and `data_0215590c`, clears work +0xc0, registers `func_020116a8` with a 1024-byte stack at priority 20 through `func_0200621c`, starts it with `func_020064e0`, then restores interrupts. | 100% |
| `func_02011694` | Tail-calls `func_02008848(dst, 0, 36)`, the unaligned-safe fill also used for the SDK's 36-byte message buffer. `dst` remains caller-owned. | 100% |

## Hard list

| Function | Best result | What was tried |
| --- | --- | --- |
| `func_02011364` | 98.32% for the clean reconstruction (98.62% with a `u8` temporary that adds an instruction); not linked from C, the delinked original still supplies it | Reconstructed the exact public `CTRDGi_InitModuleInfo` body (guards, IE/IME save, CTRDG lock, EXMEMCNT priority, DMA of header +0x80, module-info copy, BIOS logo copy, CTRDG PXI command and the `subpInitialized` wait) using the same helper mapping as the rest of the unit. objdiff matches every instruction except the one-time guard block: mwcc 2.0/sp1p5 `-O4,p` emits the `data_02155740 + 0` store after the pause-register `tst`, while the original has `ldrh` then `str` then `tst`. Tried explicit statement orderings, `u8`/`u16`/`u32`/`int` temporaries, volatile and non-volatile forms, `goto` loop shapes (which did fix both the copy loop and the completion-wait loop), a scoped `#pragma optimize_for_size on`, and space/speed helper inlining; all compiler versions 2.0/base through sp2p4 show the same scheduling, and space mode fixes the guard order but changes the epilogue and loop layout. Keep this function from the delink so the image and checksum stay original; a decomp.me scratch (`tools/decompme.py`, platform `nds_arm9`) can focus on the guard-block scheduling. |
