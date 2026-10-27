#include "types.h"

/* Borrowed state slot; the provider owns all forty bytes. */
typedef struct Unk0546d8State {
    u32 mode;
    u32 selector;
    union { u32 word; u8 dimensions[4]; } shape;
    u32 format;
    u8 reserved16;
    u8 flag;
    u16 value;
    u8 reserved20[20];
} Unk0546d8State;
extern u32 func_020557cc(const Unk0546d8State *state);
extern Unk0546d8State *func_0205410c(u32 index);
extern void func_02054120(Unk0546d8State *state, u32 mode);
extern void func_02054a98(u32 index, u32 a, u32 b, u32 c, u8 flag, u16 value);
void func_02054af0(u32 index, u32 a, u8 flag, u16 value);

/* G2_SetBG2Control256x16Affine: NitroSDK gx_bgcnt.h and MMIO 0x0400000c
 * establish the fields. Inputs are SDK encodings; preserve priority/mosaic. */
void func_020546d8(u32 size, u32 wrap, u32 screenBase, u32 charBase)
{
    volatile u16 *control = (volatile u16 *)0x0400000c;
    *control = (*control & 0x43) | (size << 14) | (charBase << 2) |
               (screenBase << 8) | (wrap << 13);
}

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

/* NitroSDK gx_bgcnt.h 16-bit bitmap control layout and MMIO 0x0400100c
 * establish these fields. Inputs fit SDK encodings; preserve priority/mosaic. */
void func_020548e0(u32 size, u32 wrap, u32 screenBase)
{
    volatile u16 *control = (volatile u16 *)0x0400100c;
    *control = (*control & 0x43) | (size << 14) | 132 |
               (screenBase << 8) | (wrap << 13);
}

/* NitroSDK gx_bgcnt.h 16-bit bitmap control layout and MMIO 0x0400000e
 * establish these fields. Inputs fit SDK encodings; preserve priority/mosaic. */
void func_02054908(u32 size, u32 wrap, u32 screenBase)
{
    volatile u16 *control = (volatile u16 *)0x0400000e;
    *control = (*control & 0x43) | (size << 14) | 132 |
               (screenBase << 8) | (wrap << 13);
}

/* NitroSDK gx_bgcnt.h 16-bit bitmap control layout and MMIO 0x0400000c
 * establish these fields. Inputs fit SDK encodings; preserve priority/mosaic. */
void func_02054930(u32 size, u32 wrap, u32 screenBase)
{
    volatile u16 *control = (volatile u16 *)0x0400000c;
    *control = (*control & 0x43) | (size << 14) | 132 |
               (screenBase << 8) | (wrap << 13);
}

/* Resets provider-owned slot zero to mode one; evidence: the two original
 * provider calls with index zero and mode one. No storage is retained. */
void func_02054a80(void)
{
    func_02054120(func_0205410c(0), 1);
}

/* Resets a borrowed indexed slot to mode two, then stores caller fields.
 * Evidence: original stores at +4/+8/+12/+17/+18 after 02054120. */
void func_02054a98(u32 index, u32 a, u32 b, u32 c, u8 flag, u16 value)
{
    Unk0546d8State *state = func_0205410c(index);
    func_02054120(state, 2);
    state->selector = a;
    state->shape.word = c;
    state->format = b;
    state->flag = flag;
    state->value = value;
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

/* Orders borrowed slot indices: modes 0/1 last, then flagged slots last,
 * then descending +18 value. Evidence: original unsigned mode comparisons
 * and byte/halfword loads. The provider must accept both indices. */
s32 func_02054ba4(const u32 *left, const u32 *right)
{
    Unk0546d8State *a = func_0205410c(*left);
    Unk0546d8State *b = func_0205410c(*right);
    if (a->mode <= 1) return 1;
    if (b->mode <= 1) return -1;
    if (a->flag != 0) return 1;
    if (b->flag != 0) return -1;
    return b->value - a->value;
}

/* Orders borrowed slot indices with modes 0/1 last, otherwise descending
 * provider size. Evidence: original calls 020557cc for right then left.
 * Both indices must be valid for the state provider. */
s32 func_02054c0c(const u32 *left, const u32 *right)
{
    Unk0546d8State *a = func_0205410c(*left);
    Unk0546d8State *b = func_0205410c(*right);
    u32 size;
    if (a->mode <= 1) return 1;
    if (b->mode <= 1) return -1;
    size = func_020557cc(b);
    return size - func_020557cc(a);
}
