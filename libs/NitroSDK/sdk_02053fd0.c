#include "types.h"

/* Provider-owned state: the halfword gates uploads and the word selects mode. */
typedef struct UploadState {
    u16 dirty;
    u16 padding;
    int mode;
} UploadState;

/* Caller-owned 40-byte record; only its first word is interpreted here. */
typedef struct WorkRecord {
    u32 value;
    u32 rest[9];
} WorkRecord;

/* Caller-owned bank description, with at most two offset/size pairs. */
typedef struct BankRegions {
    u32 count;
    struct Region { u32 offset, size; } regions[2];
} BankRegions;

extern UploadState data_02143a88;
extern u8 data_02160820[];
extern WorkRecord data_02160e20[];
extern void func_02006c94(const void *source, u32 size);
extern void func_020046b4(const void *source, u32 offset, u32 size);
extern void func_02004708(const void *source, u32 offset, u32 size);
extern void func_0200870c(u32 value, void *destination, u32 size);
extern void func_02008848(void *destination, u32 value, u32 size);
extern void func_02054ad8(int mode);
extern void func_0205589c(int mode, const void *source, u32 size);
extern void func_0205590c(int mode, u32 offset, const void *source, u32 size);
extern u32 func_0200387c(void);
extern u32 func_020038dc(void);
/* Still provided by the delink: see the function document hard list. */
extern void func_02053ffc(void);
void func_020540a0(void);
void func_020540cc(void);

/* Resets the upload buffer before changing mode; mode eight omits setup.
 * Evidence: ordered calls and the comparison at 0x02053fe0. */
void func_02053fd0(int mode)
{
    func_020540a0();
    data_02143a88.mode = mode;
    if (mode != 8) {
        func_02054ad8(mode);
    }
}

/* Uploads the fixed source and pending buffer only for dirty, active modes.
 * Evidence: halfword/word guards and BL order at 0x02054058. */
void func_02054058(void)
{
    if (!data_02143a88.dirty || data_02143a88.mode == 8) return;
    func_02053ffc();
    func_0205590c(data_02143a88.mode, 0, (const void *)0x0212ce60, 0x13c0);
    func_020540cc();
}

/* Clears the provider-owned 1536-byte staging buffer and marks it dirty.
 * Evidence: fill arguments and STRH at 0x020540bc. */
void func_020540a0(void)
{
    func_0200870c(0, data_02160820, 1536);
    data_02143a88.dirty = 1;
}

/* Transfers pending staging bytes for active modes, then clears dirty.
 * Evidence: guards and provider arguments at 0x020540cc..0x020540fc. */
void func_020540cc(void)
{
    if (!data_02143a88.dirty || data_02143a88.mode == 8) return;
    func_0205589c(data_02143a88.mode, data_02160820, 1536);
    data_02143a88.dirty = 0;
}

/* Returns a borrowed 40-byte record; the caller must provide a valid index.
 * Evidence: MLA by forty at 0x02054114. */
WorkRecord *func_0205410c(int index)
{
    return &data_02160e20[index];
}

/* Initializes caller-owned storage and installs its first word after clearing.
 * Evidence: 40-byte fill followed by STR at 0x02054138. */
void func_02054120(WorkRecord *record, u32 value)
{
    func_02008848(record, 0, 40);
    record->value = value;
}

/* Builds bank offset/size pairs in KiB from provider masks. Evidence: masks
 * 0x70/0x0f for selector zero, 0x184 otherwise, and the eight-byte stores.
 * The destination must hold a count and two region pairs. */
void func_02054140(BankRegions *banks, int selector)
{
    u32 mask;
    struct Region *region;
    if (selector == 0) {
        mask = func_0200387c();
        banks->count = 0;
        if (mask & 0x70) {
            region = &banks->regions[banks->count];
            banks->count++;
            region->offset = 0;
            region->size = 0;
            if (mask & 0x10) region->size += 64;
            if (mask & 0x20) region->size += 16;
            if (mask & 0x40) region->size += 16;
        }
        if (mask & 0xf) {
            region = &banks->regions[banks->count];
            banks->count++;
            region->offset = 0;
            region->size = 0;
            if (banks->count == 2) region->offset = 128;
            if (mask & 1) region->size += 128;
            if (mask & 2) region->size += 128;
            if (mask & 4) region->size += 128;
            if (mask & 8) region->size += 128;
        }
    } else {
        mask = func_020038dc();
        banks->count = 0;
        region = &banks->regions[banks->count];
        banks->count++;
        region->offset = 0;
        region->size = 0;
        if (mask & 4) region->size += 128;
        if (mask & 0x80) region->size += 32;
        if (mask & 0x100) region->size += 16;
    }
}
