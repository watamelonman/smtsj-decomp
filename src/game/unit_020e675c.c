#include "types.h"

/* Table selectors return a handle consumed by the base/count accessors. */
extern void *func_020445d0(u32 group, u32 table);
extern void *func_0204fde0(void *handle);
extern u32 func_0204fe18(void *handle);
extern void *func_02011810(const void *key, const void *base, u32 count,
                          u32 size, int (*compare)(const void *, const void *));

/* Compare leading unsigned byte keys; 020e679c passes this to 02011810. */
int Unk0e675c_Unk_0e675c(const void *left, const void *right)
{
    return (u32)*(const u8 *)left - (u32)*(const u8 *)right;
}

/* Compare leading unsigned halfword keys; 020e67f4 supplies aligned records. */
int Unk0e675c_Unk_0e676c(const void *left, const void *right)
{
    return (u32)*(const u16 *)left - (u32)*(const u16 *)right;
}

/* Compare leading unsigned halfwords for the six-byte records in 020e6874. */
int Unk0e675c_Unk_0e677c(const void *left, const void *right)
{
    return (u32)*(const u16 *)left - (u32)*(const u16 *)right;
}

/* Compare leading unsigned halfwords for the twelve-byte records in 020e68f0. */
int Unk0e675c_Unk_0e678c(const void *left, const void *right)
{
    return (u32)*(const u16 *)left - (u32)*(const u16 *)right;
}

/* Search group 0x21/table 0 by its leading byte; return a borrowed record or NULL.
 * Evidence: the original call to 02011810 uses stride 0x10 and the byte comparator. */
void *func_020e679c(u32 id)
{
    u8 key[0x10];
    void *handle = func_020445d0(0x21, 0);
    void *base = func_0204fde0(handle);
    u32 count = func_0204fe18(handle);
    key[0] = id;
    return func_02011810(key, base, count, sizeof(key), Unk0e675c_Unk_0e675c);
}

/* Search group 0x21/table 1 by its leading halfword; return a borrowed record
 * or NULL. The original stride is 0x34; only the leading key is compared. */
void *func_020e67f4(u32 id)
{
    u16 key[0x34 / sizeof(u16)];
    void *handle = func_020445d0(0x21, 1);
    void *base = func_0204fde0(handle);
    u32 count = func_0204fe18(handle);
    key[0] = id;
    return func_02011810(key, base, count, sizeof(key), Unk0e675c_Unk_0e676c);
}

/* Return a borrowed word in group 0x21/table 2; unsigned indices clamp to five.
 * Evidence: the original adds the clamped index shifted left by two to the base. */
u32 *Unk0e675c_Unk_0e684c(u32 index)
{
    u32 *base;
    void *handle;
    if (index > 5) {
        index = 5;
    }
    handle = func_020445d0(0x21, 2);
    base = func_0204fde0(handle);
    return base + index;
}

/* Return the count for group 0x17/table 2 after establishing its base accessor.
 * Evidence: 0204fe18's result remains in r0 at the original return. */
u32 Unk0e675c_Unk_0e68cc(void)
{
    void *handle = func_020445d0(0x17, 2);
    func_0204fde0(handle);
    return func_0204fe18(handle);
}
