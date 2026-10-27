#include "types.h"

extern void func_02004aec(const void *source, u32 offset, u32 size);
extern void *func_0205410c(u32 index);
extern u32 func_020557cc(const void *record);
extern void func_0205589c(u32 index, const void *source, u32 size);
extern void func_020559a0(u32 engine, u32 slot, const void *source, u32 count);
extern void func_020559f8(u32 engine, u32 slot, const void *source, u32 count);
extern void func_02055ce4(s32 index);

/* Forwards caller-owned source bytes and destination offset to 02004aec;
 * evidence: the original tail call preserves all three argument registers. */
void func_020557c0(const void *source, u32 offset, u32 size)
{
    func_02004aec(source, offset, size);
}

/* Loads the selected record's derived byte count from caller-owned source.
 * Evidence: 02055874 calls record lookup, size helper, then 0205589c in order. */
void func_02055874(u32 index, const void *source)
{
    u32 size = func_020557cc(func_0205410c(index));
    func_0205589c(index, source, size);
}

/* Submits one 32-byte slot; 020559a0 shifts slot and count by five before
 * cache maintenance and the main/sub palette transfer providers. */
void func_02055990(u32 engine, u32 slot, const void *source)
{
    func_020559a0(engine, slot, source, 1);
}

/* Submits one 512-byte slot; 020559f8 shifts slot and count by nine and
 * selects normal or extended main/sub palette transfer providers. */
void func_020559e8(u32 engine, u32 slot, const void *source)
{
    func_020559f8(engine, slot, source, 1);
}

/* Accumulates low-byte flags in caller-owned record byte +0x10, as shown
 * by the original byte load, OR and byte store. No other bytes are changed. */
void func_02055ab0(void *record, u32 flags)
{
    ((u8 *)record)[0x10] |= flags;
}

/* Services all eight record indices in ascending order; 02055ce4 tests the
 * record's +0x20 pointer and dispatches according to its +0x10 flag byte. */
void func_02055d2c(void)
{
    s32 index;
    for (index = 0; index < 8; index++) {
        func_02055ce4(index);
    }
}

/* Maps zero to 32768 and any nonzero selector to 65536; evidence is the
 * original conditional immediates. The selector's wider meaning is unknown. */
u32 func_02055d84(u32 selector)
{
    return selector == 0 ? 32768 : 65536;
}

/* Maps zero to 32 and any nonzero selector to 64; evidence is the original
 * conditional immediates. The selector's wider meaning is unknown. */
u32 func_02055d94(u32 selector)
{
    return selector == 0 ? 32 : 64;
}
