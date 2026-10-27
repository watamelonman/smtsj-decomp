# libs/NitroSDK/sdk_02000800.c

NitroSDK 4.2 boot code at the start of ARM9 `.text`. The original source is
public: this range is the entry/startup portion of
[`crt0.c` in pret/pokediamond](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/crt0.c)
(`arm9/lib/NitroSDK/src/`). The delinked symbols are kept neutral because this
unit has no callers that establish different names; the public names are cited
only as evidence for each body.

Two functions are matched in C. The rest are hand-written CP15/stack assembly
in the public source; they remain supplied by the delinked object. No inline
assembly, stubs, or byte blobs were added.

## Entry — 0x02000800, 340 bytes

`_start` in pret/pokediamond `crt0.c`. It disables IME, waits for VCOUNT to
reach zero, calls the CP15 setup function (0x02000ab0), switches through SVC,
IRQ, and system modes while building the three stacks from the DTCM autoload
base, clears DTCM, the palettes and OAM through the fill helper at 0x02000954,
decompresses the autoload block, runs the autoload list, zeroes the static BSS
and flushes those cache lines, stores the print-buffer pointer and IRQ vector,
calls `_fp_init`, 0x02000b98, and `__call_static_initializers`, then jumps to
`main`.

**Hard:** the body is assembly-only in the public source and uses CP15
`mrc`/`mcr` together with direct `sp`/`CPSR` manipulation. C cannot emit those
instructions without inline assembly, which this project forbids. The closest
C cannot preserve the hand-written multi-mode stack setup or the CP15 cache
sequence, so the delinked original is retained.

## func_02000954 — 0x02000954, 28 bytes

`INITi_CpuClear32`: fills `size` bytes at `destp` with the 32-bit `data` value.

**Hard:** although the algorithm is a simple fill loop, the original is the
hand-written assembly helper from `crt0.c`. Its end pointer lives in `r12` and
its control flow is the explicit `cmp; blt body; b done; body: stmia; done: blt`
shape. Under mwccarm 2.0/sp1p5 every C spelling tried (`while`, `for`,
`do/while`, pointer-end versus count, `volatile`, and explicit `goto` forms)
puts the end in `r2`, uses `bxlt lr`, and emits `str` rather than `stmia`; the
closest candidate matches only the final `bx lr` of the seven instructions.
The function remains delinked rather than being committed below 100%.

## func_02000970 — 0x02000970, 172 bytes

`MIi_UncompressBackward`: backwards LZ-style decompression of the block whose
two-word trailer sits before `bottom`. It reads the compressed length and
destination offset from that trailer, walks source and destination backwards,
expands literal and back-reference runs, then cleans and invalidates the
destination cache lines.

**Hard:** the final cache maintenance is CP15 `mcr` only, and the surrounding
register-level LZ loop is assembly in the public source. C cannot reproduce the
CP15 instructions without inline assembly.

## func_02000a1c — 0x02000a1c, 144 bytes

`do_autoload`: walks the autoload records in `_start_ModuleParams`. Each record
is `{destination, copy size, BSS size}`; the helper copies the image bytes from
the autoload data cursor, zero-fills the requested BSS tail, cleans and
invalidates the cache lines for the record, and advances to the next record
before tail-calling the autoload-done hook (0x02000aac).

**Hard:** the per-record cache maintenance is CP15 `mcr`, so the matching body
is assembly in the public source.

## AutoloadCallback — 0x02000aac, 4 bytes

Post-autoload hook, `_start_AutoloadDoneCallback` in the public source. The
entire original body is `bx lr`; the empty C body matches it, so the hook has
typed `void` parameters (none), no result, and no side effects.

## func_02000ab0 — 0x02000ab0, 232 bytes

`init_cp15`: the startup CP15 setup. It disables the caches/TCM/protection unit,
invalidates both caches and the write buffer, programs the eight protection
regions, sizes ITCM/DTCM, sets the cache/write-buffer bits and access
permissions, then re-enables the caches, TCMs, exception vectors and protection
unit with the `0x0005707d` mask.

**Hard:** every meaningful instruction is a CP15 `mrc`/`mcr`; C cannot express
them without inline assembly.

## func_02000b98 — 0x02000b98, 4 bytes

No-op helper called from `Entry` between `_fp_init` and
`__call_static_initializers`. The original body is only `bx lr`; the empty C
body matches it with typed `void` parameters and no side effects.

## Validation and hard list

The match gate verifies both retained C definitions at 100% objdiff; the
anticheat gate sees no assembly, `INCLUDE_ASM`, or byte blobs, and the full
image checksum still uses the delinked original for the unmatched functions
until a human marks the unit complete.

Hard functions for a human decomp.me scratch (`tools/decompme.py`,
`nds_arm9`):

- `Entry` (340 B): CP15 and multi-mode stack assembly.
- `func_02000954` (28 B): hand-written `INITi_CpuClear32` register/branch shape.
- `func_02000970` (172 B): `MIi_UncompressBackward`, CP15 cache maintenance.
- `func_02000a1c` (144 B): `do_autoload`, CP15 cache maintenance.
- `func_02000ab0` (232 B): `init_cp15`, all CP15 register accesses.
