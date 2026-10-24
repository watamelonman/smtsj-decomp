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
} Unk0b1ab8Work;

extern const s16 data_0213c42c[];
extern const s16 data_0213c42e[];
Unk0b1ab8Work *func_020b1ab8(Unk0b1ab8Pair position, int mode, u8 direction);
void func_020b1bc4(Unk0b1ab8Pair *position, u32 direction);

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

/* Neutral 020b1f48: offsets position and creates kind 9 work.
 * As in the original, creation must succeed before the kind is written. */
void func_020b1f48(Unk0b1ab8Pair position, u32 direction, int flag)
{
    Unk0b1ab8Work *work;
    func_020b1bc4(&position, direction);
    work = func_020b1ab8(position, flag ? 7 : 6, (u8)direction);
    work->kind = 9;
}
