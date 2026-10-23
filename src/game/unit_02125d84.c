#include "types.h"

/* Sixteen-byte records: coordinates and packed shape precede the backing storage. */
typedef struct Unit125d84Record {
    u32 shape;
    u16 x, y;
    u32 unk08;
    u16 *pixels;
} Unit125d84Record;

/* Partial owner layout, established by loads in the cleanup and drawing helpers. */
typedef struct Unit125d84 {
    int count;
    void *unk04;
    int format;
    u32 unk0c;
    Unit125d84Record *records;
    void *buffer;
    u32 buffer_size;
} Unit125d84;

extern s8 data_0213ce10[];
extern s8 data_0213ce1c[];
void func_02056cac(void *resource);
void func_02053000(void *allocation);
void func_02008644(u16 value, void *destination, u32 size);
int func_02125d84(u32 shape);
int func_02125da8(u32 shape);
Unit125d84Record *func_02125fa8(Unit125d84 *owner, u32 x, u32 y);
void func_02126038(u16 *tile, u32 x, u32 y, u32 value);
void func_0212608c(u16 *tile, u32 x, u32 y, u32 value);

/* Release the repeated resource, then both owned allocations; count is reloaded after calls. */
void Unk125d84_Unk_125f0c(Unit125d84 *owner)
{
    int i = 0;
    while (i < owner->count) {
        func_02056cac(owner->unk04);
        i++;
    }
    func_02053000(owner->buffer);
    owner->buffer = 0;
    func_02053000(owner->records);
    owner->records = 0;
}

/* Write a record-relative pixel; record lookup and 8x8 tile arithmetic are assembly evidence. */
void func_021260d8(Unit125d84 *owner, u32 x, u32 y, u32 value)
{
    u16 *pixels;
    Unit125d84Record *record = func_02125fa8(owner, x, y);
    u32 width;
    u32 offset;
    if (!record) return;
    x -= record->x;
    y -= record->y;
    width = func_02125d84(record->shape);
    func_02125da8(record->shape);
    offset = ((y >> 3) * (width >> 3) + (x >> 3));
    offset *= (owner->format == 4 ? 64 : 32);
    pixels = record->pixels;
    offset &= ~1u;
    if (owner->format == 4)
        func_0212608c((u16 *)((u8 *)pixels + offset), x, y, value);
    else
        func_02126038((u16 *)((u8 *)pixels + offset), x, y, value);
}

/* Return the first record containing the unsigned coordinates, excluding its far edges. */
Unit125d84Record *func_02125fa8(Unit125d84 *owner, u32 x, u32 y)
{
    int i;
    for (i = 0; i < owner->count; i++) {
        Unit125d84Record *record = &owner->records[i];
        if (x >= record->x && y >= record->y &&
            record->x + func_02125d84(record->shape) > x &&
            record->y + func_02125da8(record->shape) > y)
            return record;
    }
    return 0;
}

/* Fill the backing buffer with a repeated byte (format 4) or repeated nibble. */
void func_02125f60(Unit125d84 *owner, u32 value) { u16 pattern; if(owner->format==4) { pattern = value & 255; pattern = pattern | (pattern << 8); } else { value &= 15; pattern = (value << 12) | (value << 8) | (value << 4) | value; } func_02008644((u16)pattern,owner->buffer,owner->buffer_size); }

/* Replace a nibble in an 8x8 tile; caller supplies a value fitting four bits. */
void func_02126038(u16 *tile,u32 x,u32 y,u32 value) { u32 index; u16 mask; u16 bits; x &= 7; index = ((x & 4) != 0); index += (y & 7) * 2; x = (x & 3) * 4; tile += index; mask = (u16)(15 << x); bits = (u16)(value << x); *tile = (*tile & ~mask) | bits; }

/* Replace the low nibble of a byte slot; caller supplies a value fitting four bits. */
void func_0212608c(u16 *tile, u32 x, u32 y, u32 value)
{
    u32 index = (y & 7) * 4 + ((x & 7) >> 1);
    u16 mask, bits;
    x = (x & 1) * 8;
    mask = 15 << x;
    bits = value << x;
    tile[index] = (tile[index] & (u16)~mask) | bits;
}

/* First signed extent table indexed by shape bits 14..15 and 30..31. */
int func_02125d84(u32 shape) { int low = shape & 0xc000; u32 high = shape & 0xc0000000; low >>= 14; high >>= 30; return data_0213ce10[(low << 2) | high]; }

/* Second signed extent table with the same packed shape index as the first. */
int func_02125da8(u32 shape)
{
    int low = shape & 0xc000;
    u32 high = (shape & 0xc0000000);
    low >>= 14;
    high >>= 30;
    return data_0213ce1c[(low << 2) | high];
}
