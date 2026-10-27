#include "types.h"

/* Borrowed resource prefixes; signatures and offsets are evidenced by the loads
 * in 0204fd18, 0204fd4c, 0204fde0 and 0204fed8. No storage ownership is transferred. */
typedef struct ResourceHeader {
    u32 signature;
    u32 offset;
    u32 value;
    u32 count;
    u32 first;
    u32 entries[1];
} ResourceHeader;

extern u8 data_0215eedc[];
extern u32 func_0201f3e8(u32 numerator, u32 denominator);

/* Preserve the original explicit boolean signature test before accessing data. */
static inline _Bool valid_signature(const ResourceHeader *resource, u32 signature)
{
    if (resource->signature == signature) return 1;
    return 0;
}

/* Return a borrowed 50-byte slot for unsigned IDs 1..6, as shown by the MLA. */
void *func_0204fce8(u32 id)
{
    if (id < 1 || id >= 7) return 0;
    return data_0215eedc + (id - 1) * 50;
}

/* Read TBB1's word at +8; the original rejects null and other signatures. */
u32 func_0204fd18(const ResourceHeader *resource)
{
    if (resource == 0) return 0;
    if (valid_signature(resource, 0x31424254) == 0) return 0;
    return resource->value;
}

/* Resolve the index'th child of a TBB1 header. Evidence: the signature literal
 * at 0204fda8, the +8 bound and the +4 word-table origin in the original. The
 * table words are header-relative offsets; the returned child is borrowed. */
ResourceHeader *func_0204fd4c(const ResourceHeader *resource, u32 index)
{
    u32 offset;

    if (resource == 0) return 0;
    if (valid_signature(resource, 0x31424254) == 0) return 0;
    if ((_Bool)(index < resource->value) == 0) return 0;
    offset = ((const u32 *)((const u8 *)resource + resource->offset))[index];
    return (ResourceHeader *)((u8 *)resource + offset);
}

/* Select a borrowed TBL1 child; signature evidence is the original TBL1 literal. */
ResourceHeader *func_0204fdac(const ResourceHeader *resource, u32 index)
{
    ResourceHeader *child = func_0204fd4c(resource, index);
    if (child == 0) return child;
    if (valid_signature(child, 0x314c4254) == 0) return 0;
    return child;
}

/* Resolve TBL1's base-relative byte offset at +4 without taking ownership. */
void *func_0204fde0(const ResourceHeader *resource)
{
    if (resource == 0) return 0;
    if (valid_signature(resource, 0x314c4254) == 0) return 0;
    return (u8 *)resource + resource->offset;
}

/* Divide TBL1's +8 byte size by its nonzero +12 count (ARM divide helper). */
u32 func_0204fe18(const ResourceHeader *resource)
{
    if (resource == 0) return 0;
    if (valid_signature(resource, 0x314c4254) == 0) return 0;
    if (resource->count == 0) return 0;
    return func_0201f3e8(resource->value, resource->count);
}

/* Select a borrowed MTBL child; original literal and child load establish type. */
ResourceHeader *func_0204fe68(const ResourceHeader *resource, u32 index)
{
    ResourceHeader *child = func_0204fd4c(resource, index);
    if (child == 0) return child;
    if (valid_signature(child, 0x4c42544d) == 0) return 0;
    return child;
}

/* Convert an unsigned MTBL ID to an index, falling back to zero outside range.
 * The caller must supply a valid header; +12/+16 hold count/first in the original. */
u32 func_0204fe9c(const ResourceHeader *resource, u32 id)
{
    u32 index;
    if ((_Bool)(id >= resource->first) == 0) return 0;
    index = id - resource->first;
    if ((_Bool)(index < resource->count) == 0) return 0;
    return index;
}

/* Return a borrowed MTBL entry relative to +16; zero offsets mean absent.
 * Original +20 indexed load and +16 addition establish the offset origin. */
void *func_0204fed8(const ResourceHeader *resource, u32 id)
{
    u32 offset;
    if (resource == 0) return 0;
    if (valid_signature(resource, 0x4c42544d) == 0) return 0;
    offset = resource->entries[func_0204fe9c(resource, id)];
    if (offset == 0) return 0;
    return (u8 *)resource + 16 + offset;
}
