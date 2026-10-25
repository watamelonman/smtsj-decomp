#include "types.h"

/* Signed coordinate pair; passed by value using the original aggregate ABI. */
typedef struct Unk0b1ab8Pair {
    s16 x;
    s16 y;
} Unk0b1ab8Pair;

/* Partial work layout established by stores in 020b1ab8 and its callers. */
typedef struct Unk0b1ab8Work {
    u8 kind;
    u8 unk_01;
    u8 variant;
    u8 unk_03;
    u32 unk_04;
    u32 unk_08;
    u32 value;
    u32 unk_10;
    int mode;
    Unk0b1ab8Pair position;
} Unk0b1ab8Work;

extern const s16 data_0213c42c[];
extern const s16 data_0213c42e[];
Unk0b1ab8Work *func_020b1ab8(Unk0b1ab8Pair position, int mode, u8 direction);
void func_020b1bc4(Unk0b1ab8Pair *position, u32 direction);

void func_020b17f4(Unk0b1ab8Work *work);
void func_020b1884(Unk0b1ab8Work *work);
Unk0b1ab8Work *func_020611dc(void (*update)(Unk0b1ab8Work *),
                           void (*draw)(Unk0b1ab8Work *),
                           void (*third)(Unk0b1ab8Work *),
                           void (*fourth)(Unk0b1ab8Work *),
                           u32 size, u32 category, u16 priority, u32 flags);
void Unk09d060_Unk_09d170(void *child);

/* Neutral 020b1ab8: allocates 28 bytes with the two adjacent callbacks,
 * registers successful work, and initializes the fields those callbacks use.
 * Returns null on allocation failure. Priority truncates 10-direction to u16. */
Unk0b1ab8Work *func_020b1ab8(Unk0b1ab8Pair position, int mode, u8 direction)
{
    Unk0b1ab8Work *work = func_020611dc(func_020b17f4, func_020b1884,
                                      0, 0, 28, 4, (u16)(10 - direction), 0);
    if (work) {
        Unk09d060_Unk_09d170(work);
        work->unk_01 = 0;
        work->unk_04 = 0;
        work->unk_08 = 0;
        work->position = position;
        work->mode = mode;
        work->kind = 4;
        work->value = 0;
        work->unk_10 = 0;
        work->variant = 0;
        work->unk_03 = direction;
    }
    return work;
}

/* Neutral 020b1b68: creates kind 4 work with the supplied value and byte variant.
 * The original requires the allocator to succeed; mode is selected by nonzero flag. */
void func_020b1b68(u32 value, Unk0b1ab8Pair position, u32 variant, int flag, u32 direction)
{
    Unk0b1ab8Work *work = func_020b1ab8(position, flag ? 7 : 6, (u8)direction);
    work->kind = 4;
    work->value = value;
    work->variant = variant;
}

/* Neutral 020b1bc4: adds the signed pair selected by direction modulo five.
 * Separate interleaved table symbols preserve the two original halfword loads. */
void func_020b1bc4(Unk0b1ab8Pair *position, u32 direction)
{
    u32 index = (direction % 5) * 2;
    int dx = data_0213c42c[index];
    int dy = data_0213c42e[index];
    int x = position->x;
    position->x = x + dx;
    position->y += dy;
}

/* Neutral 020b1c18: offsets a copy of position then creates variant 3 work. */
void func_020b1c18(u32 value, Unk0b1ab8Pair position, u32 direction, int flag)
{
    func_020b1bc4(&position, direction);
    func_020b1b68(value, position, 3, flag, (u8)direction);
}

/* Neutral 020b1c7c: offsets a copy of position then creates variant 4 work. */
void func_020b1c7c(u32 value, Unk0b1ab8Pair position, u32 direction, int flag)
{
    func_020b1bc4(&position, direction);
    func_020b1b68(value, position, 4, flag, (u8)direction);
}

/* Neutral 020b1ce0: offsets a copy of position then creates variant 1 work. */
void func_020b1ce0(u32 value, Unk0b1ab8Pair position, u32 direction, int flag)
{
    func_020b1bc4(&position, direction);
    func_020b1b68(value, position, 1, flag, (u8)direction);
}

/* Neutral 020b1da8: offsets position and creates kind 5 work with value 3.
 * As in the original, creation must succeed before the fields are written. */
void func_020b1da8(Unk0b1ab8Pair position, u32 direction, int flag)
{
    Unk0b1ab8Work *work;
    func_020b1bc4(&position, direction);
    work = func_020b1ab8(position, flag ? 7 : 6, (u8)direction);
    work->kind = 5;
    work->value = 3;
}

/* Neutral 020b1e74: offsets position and creates kind 7 work with value 2.
 * As in the original, creation must succeed before the fields are written. */
void func_020b1e74(Unk0b1ab8Pair position, u32 direction, int flag)
{
    Unk0b1ab8Work *work;
    func_020b1bc4(&position, direction);
    work = func_020b1ab8(position, flag ? 7 : 6, (u8)direction);
    work->kind = 7;
    work->value = 2;
}

/* Neutral 020b1ed4: creates kind 8 with value one after offsetting the pair.
 * A zero final argument also subtracts 12 from y; creation must succeed. */
void func_020b1ed4(Unk0b1ab8Pair position, u32 direction, int flag, int keep_y)
{
    Unk0b1ab8Work *work;
    func_020b1bc4(&position, direction);
    if (!keep_y)
        position.y -= 12;
    work = func_020b1ab8(position, flag ? 7 : 6, (u8)direction);
    work->kind = 8;
    work->value = 1;
}

/* Neutral 020b1f48: offsets position and creates kind 9 work.
 * As in the original, creation must succeed before the kind is written. */
void func_020b1f48(Unk0b1ab8Pair position, u32 direction, int flag)
{
    Unk0b1ab8Work *work;
    func_020b1bc4(&position, direction);
    work = func_020b1ab8(position, flag ? 7 : 6, (u8)direction);
    work->kind = 9;
}

/* Neutral 020b1d44: offsets the copied pair and forwards variant 2.
 * Evidence: the call sequence matches the adjacent variant wrappers. */
void func_020b1d44(u32 value, Unk0b1ab8Pair position, u32 direction, int flag)
{
    func_020b1bc4(&position, direction);
    func_020b1b68(value, position, 2, flag, (u8)direction);
}

/* Neutral 020b1e08: offsets the copied pair, subtracts 12 from y, and
 * creates kind 6 with value zero; creation must succeed before the stores. */
void func_020b1e08(Unk0b1ab8Pair position, u32 direction, int flag)
{
    Unk0b1ab8Work *work;
    func_020b1bc4(&position, direction);
    position.y -= 12;
    work = func_020b1ab8(position, flag ? 7 : 6, (u8)direction);
    work->kind = 6;
    work->value = 0;
}
