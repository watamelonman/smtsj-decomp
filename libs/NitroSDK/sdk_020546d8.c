#include "types.h"

/* Borrowed state slot; the provider owns all forty bytes. */
typedef struct Unk0546d8State Unk0546d8State;
extern Unk0546d8State *func_0205410c(u32 index);
extern void func_02054120(Unk0546d8State *state, u32 mode);
extern void func_02054a98(u32 index, u32 a, u32 b, u32 c, u8 flag, u16 value);
void func_02054af0(u32 index, u32 a, u8 flag, u16 value);

/* Updates BG control at 0x0400100e, preserving priority and mosaic bits.
 * Evidence: the original halfword load/store and mask 0x43. Inputs are
 * register field values: size (bits 14..15), wrap (13), screen base (8..12). */
void func_02054818(u32 size, u32 wrap, u32 screenBase)
{
    volatile u16 *control = (volatile u16 *)0x0400100e;
    *control = (*control & 0x43) | (size << 14) | 128 |
               (screenBase << 8) | (wrap << 13);
}

/* Updates BG control at 0x0400100c, preserving priority and mosaic bits.
 * Evidence: the original halfword load/store and mask 0x43. Inputs are
 * register field values: size (bits 14..15), wrap (13), screen base (8..12). */
void func_02054840(u32 size, u32 wrap, u32 screenBase)
{
    volatile u16 *control = (volatile u16 *)0x0400100c;
    *control = (*control & 0x43) | (size << 14) | 128 |
               (screenBase << 8) | (wrap << 13);
}

/* Updates BG control at 0x0400000e, preserving priority and mosaic bits.
 * Evidence: the original halfword load/store and mask 0x43. Inputs are
 * register field values: size (bits 14..15), wrap (13), screen base (8..12). */
void func_02054868(u32 size, u32 wrap, u32 screenBase)
{
    volatile u16 *control = (volatile u16 *)0x0400000e;
    *control = (*control & 0x43) | (size << 14) | 128 |
               (screenBase << 8) | (wrap << 13);
}

/* Updates BG control at 0x0400000c, preserving priority and mosaic bits.
 * Evidence: the original halfword load/store and mask 0x43. Inputs are
 * register field values: size (bits 14..15), wrap (13), screen base (8..12). */
void func_02054890(u32 size, u32 wrap, u32 screenBase)
{
    volatile u16 *control = (volatile u16 *)0x0400000c;
    *control = (*control & 0x43) | (size << 14) | 128 |
               (screenBase << 8) | (wrap << 13);
}

/* Updates BG control at 0x0400100e, preserving priority and mosaic bits.
 * Evidence: the original halfword load/store and mask 0x43. Inputs are
 * register field values: size (bits 14..15), wrap (13), screen base (8..12). */
void func_020548b8(u32 size, u32 wrap, u32 screenBase)
{
    volatile u16 *control = (volatile u16 *)0x0400100e;
    *control = (*control & 0x43) | (size << 14) | 132 |
               (screenBase << 8) | (wrap << 13);
}

/* Resets provider-owned slot zero to mode one; evidence: the two original
 * provider calls with index zero and mode one. No storage is retained. */
void func_02054a80(void)
{
    func_02054120(func_0205410c(0), 1);
}

/* Applies the original zero flag and value eight defaults to the indexed
 * provider-owned state slot. Evidence: constants in the original tail call. */
void func_02054ad8(u32 index)
{
    func_02054af0(index, 0, 0, 8);
}

/* Initializes mode two with two cleared words and caller-supplied trailing
 * fields; evidence: func_02054a98 stores these at slot +17 and +18.
 * The provider retains ownership of the indexed slot. */
void func_02054af0(u32 index, u32 a, u8 flag, u16 value)
{
    func_02054a98(index, a, 0, 0, flag, value);
}
