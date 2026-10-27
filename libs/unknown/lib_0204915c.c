#include "libs/unknown/lib_0204915c.h"

extern Unk04915cState *data_0215eea0;
/* Resource providers return borrowed entries and table storage. */
extern void *func_0204fdac(void *resource, u32 index);
extern u32 func_0204fe18(void *entry);
extern s16 *func_0204fde0(void *entry);
extern void *func_0204fe68(void *resource, u32 index);
extern void *func_0204fed8(void *entry, s32 index);
extern s32 func_02011804(s32 value);
/* Setup providers consume numeric channel/range arguments observed in ARM calls. */
extern void func_0206d97c(s32 channel, s32 value);
extern void func_0206daa8(void);
extern void func_02057e58(s32 channel, s32 start, s32 count);

/* ARM 0204915c: bit 15 suppresses the fixed three-channel setup sequence. */
void func_0204915c(const Unk04915cInput *input)
{
    if (input->unk_0040_bit15) return;
    func_0206d97c(0, 40);
    func_0206daa8();
    func_02057e58(0, 40, 7);
    func_02057e58(1, 47, 1);
    func_02057e58(2, 48, 10);
}

/* ARM 020491b4: returns the borrowed singleton slot at +0x7990. */
void *func_020491b4(void)
{
    return data_0215eea0->unk_7990;
}

/* ARM 020491cc: biases by 30, clamps to table zero's bounds, reads a signed halfword.
 * The resource must contain at least one entry. */
s32 func_020491cc(s32 index)
{
    void *entry = func_0204fdac(data_0215eea0->unk_7998, 0);
    u32 count = func_0204fe18(entry);
    s16 *values = func_0204fde0(entry);
    index += 30;
    if (index < 0) index = 0;
    if ((u32)index >= count) index = count - 1;
    return values[index];
}

/* ARM 02049220: limits the signed input's magnitude, biases by 60 and clamps
 * into nonempty table one. The caller supplies a nonnegative magnitude limit. */
s32 func_02049220(s32 index, s32 limit)
{
    void *entry = func_0204fdac(data_0215eea0->unk_7998, 1);
    u32 count = func_0204fe18(entry);
    s16 *values = func_0204fde0(entry);
    if (func_02011804(index) > limit) {
        if (index < 0) limit = -limit;
        index = limit;
    }
    index += 60;
    if (index < 0) index = 0;
    if ((u32)index >= count) index = count - 1;
    return values[index];
}

/* ARM 02049298: applies the same bias/clamp as 020491cc to nonempty table two. */
s32 func_02049298(s32 index)
{
    void *entry = func_0204fdac(data_0215eea0->unk_7998, 2);
    u32 count = func_0204fe18(entry);
    s16 *values = func_0204fde0(entry);
    index += 30;
    if (index < 0) index = 0;
    if ((u32)index >= count) index = count - 1;
    return values[index];
}

/* ARM 020492ec: selects a clamped six-byte row in nonempty table three.
 * Column codes 12..14 address the three signed halfwords in that row. */
s32 func_020492ec(s32 column, s32 row)
{
    void *entry = func_0204fdac(data_0215eea0->unk_7998, 3);
    u32 count = func_0204fe18(entry);
    s16 *values = func_0204fde0(entry);
    row += 4;
    if (row < 0) row = 0;
    if ((u32)row >= count) row = count - 1;
    values = (s16 *)((u8 *)values + row * 6);
    return values[column - 12];
}

/* ARM 02049350: looks up a borrowed item, falling back to item zero on null. */
void *func_02049350(s32 index)
{
    void *entry = func_0204fe68(data_0215eea0->unk_7994, 0);
    void *result = func_0204fed8(entry, index);
    if (result != 0) return result;
    return func_0204fed8(entry, 0);
}
