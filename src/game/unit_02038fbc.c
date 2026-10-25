/* Resource-backed grid and element-table helpers. */
#include "types.h"

/* Serialized resource header; only the observed bytes are named. */
typedef struct Unk038fbcHeader {
    u8 pad_0000[8];
    u8 originX;    /* +8: subtracted from absolute x */
    u8 originY;    /* +9: subtracted from absolute y */
    u8 width;      /* +10 */
    u8 height;     /* +11 */
    u8 counts[32]; /* +12: entries per kind; size guessed to match owner->tables */
} Unk038fbcHeader;

/* Loaded-resource owner; 0x8c bytes as cleared by Unk038fbc_Unk_039138. */
typedef struct Unk038fbcOwner {
    Unk038fbcHeader *header; /* +0: backing resource */
    u8 *aux;                 /* +4 */
    u8 *grid;                /* +8: width*height records of eight bytes */
    u8 *tables[32];          /* +12: per-kind element arrays, (0x8c - 12) / 4 */
} Unk038fbcOwner;

void func_02008848(void *destination, int value, u32 size);
void func_020516d0(void *resource);
u32 Unk038fbc_Unk_039248(u32 kind);

/* Release the backing resource and clear all 0x8c bytes; a null owner is allowed. */
void Unk038fbc_Unk_039138(Unk038fbcOwner *owner)
{
    if (owner == 0) {
        return;
    }
    func_020516d0(owner->header);
    func_02008848(owner, 0, sizeof(Unk038fbcOwner));
}

/* Partial node layout: the getter only observes the word at offset eight. */
typedef struct Unk038fbcNode {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Unk038fbcNode;

/* Return the word at node offset eight, or zero for a null node (ldr +8). */
u32 Unk038fbc_GetNodeUnk08(Unk038fbcNode *node)
{
    if (node != 0) {
        return node->unk_08;
    }
    return 0;
}

/* Return the grid cell count (header width times height), or zero without a resource. */
int Unk038fbc_Unk_0391d8(Unk038fbcOwner *owner)
{
    Unk038fbcHeader *header;
    if (owner == 0) {
        return 0;
    }
    header = owner->header;
    if (header != 0) {
        return (int)(short)(u16)header->width * (int)(short)(u16)header->height;
    }
    return 0;
}

/* Release a loaded resource, clear the header/aux pointers, and report success. */
u32 Unk038fbc_Unk_038fbc(Unk038fbcOwner *owner)
{
    if (owner == 0) {
        return 0;
    }
    if (owner->header != 0) {
        func_020516d0(owner->header);
        func_02008848(owner, 0, 8);
        return 1;
    }
    return 0;
}

/* Translate absolute coordinates by the header origin; reject out-of-grid cells. */
u8 *Unk038fbc_Unk_039160(Unk038fbcOwner *owner, int x, int y)
{
    Unk038fbcHeader *header;
    int dx, dy;
    if (owner == 0) {
        return 0;
    }
    header = owner->header;
    if (header != 0) {
        dx = x - header->originX;
        dy = y - header->originY;
        if (dx >= 0 && dx < header->width && dy >= 0 && dy < header->height) {
            return owner->grid + (header->width * dy + dx) * 8;
        }
    }
    return 0;
}

/* Select a table entry by kind and index; the header count for the kind bounds the index. */
u8 *Unk038fbc_GetElement(Unk038fbcOwner *owner, u32 kind, u32 index)
{
    if (owner == 0) {
        return 0;
    }
    if (owner->header->counts[kind] <= index) {
        return 0;
    }
    {
        u8 *table = owner->tables[kind];
        return table + index * Unk038fbc_Unk_039248(kind);
    }
}

/* Return the serialized element stride for kinds 0..12 (the kinds with known
 * table layouts), or zero for unknown kinds. */
u32 Unk038fbc_Unk_039248(u32 kind)
{
    switch (kind) {
    case 0:
        return 0x20;
    case 1:
        return 4;
    case 2:
        return 8;
    case 3:
        return 4;
    case 4:
        return 4;
    case 5:
        return 8;
    case 6:
        return 4;
    case 7:
        return 4;
    case 8:
        return 8;
    case 9:
        return 8;
    case 10:
        return 8;
    case 11:
        return 4;
    case 12:
        return 4;
    default:
        return 0;
    }
}
