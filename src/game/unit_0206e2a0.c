#include "types.h"

/* Six 24-byte records occupy entry offsets 0x2c through 0xbb. */
typedef struct EntrySub {
    u32 unk_00;
    u32 key;
    u32 unk_08;
    u8 pad_0c[12];
} EntrySub;

typedef struct Entry {
    u8 pad_00[44];
    EntrySub sub[6];
    u8 block_bc[32];
    u8 block_dc[32];
    u8 block_fc[32];
    u8 block_11c[32];
    u8 pad_13c[12];
} Entry;

/* Alternate linker labels refer to fields within the first 328-byte entry. */
typedef struct EntrySub34View {
    u32 value;
    u8 pad_04[20];
} EntrySub34View;
typedef struct Entry34View {
    EntrySub34View sub[6];
    u8 pad_90[184];
} Entry34View;

extern Entry data_0216bac8[];
extern u32 data_0216bac4[];
extern Entry34View data_0216bafc[];
extern void func_020086bc(void *dst, const void *src, u32 size);

/* Returns the six-record region at +0x2c; caller supplies a valid entry index. */
EntrySub *Unk06e2a0_Unk_06e2a0(int index)
{
    return data_0216bac8[index].sub;
}

/* Searches six +0x30 keys and returns the corresponding +0x34 word, or zero.
 * The key's meaning is unknown; the original symbol is retained. */
u32 func_0206e2b8(int index, u32 key)
{
    u32 result = 0;
    int j;
    if ((s32)data_0216bac4[0] - 1 - index < 0) {
        return result;
    }
    for (j = 0; j < 6; j++) {
        if (key == data_0216bac8[index].sub[j].key) {
            result = data_0216bafc[index].sub[j].value;
            break;
        }
    }
    return result;
}

/* Returns the first record whose +0x04 key matches, or null; key semantics
 * are unknown, so the original symbol is retained. */
EntrySub *func_0206e334(int index, u32 key)
{
    int j;
    Entry *cursor;
    Entry *entry;
    if ((s32)data_0216bac4[0] - 1 - index < 0) {
        return 0;
    }
    entry = &data_0216bac8[index];
    /* Keep the entry base for the result while the key view advances 24 bytes. */
    cursor = entry;
    for (j = 0; j < 6; j++, cursor = (Entry *)((u8 *)cursor + sizeof(EntrySub))) {
        if (key == cursor->sub[0].key) {
            return &entry->sub[j];
        }
    }
    return 0;
}

/* Reads the +0x34 word of a caller-validated subindex (0..5).
 * Name evidence: the original loads entry + 0x34 + subindex * 24. */
u32 Unk06e2a0_GetEntrySubUnk34(int index, int subindex)
{
    if ((s32)data_0216bac4[0] - 1 - index < 0) {
        return 0;
    }
    return data_0216bafc[index].sub[subindex].value;
}

/* Copies 32 bytes from entry +0xbc; original call arguments establish the name.
 * Destination must hold 32 bytes; rejected entry indices leave it untouched. */
void Unk06e2a0_CopyEntryBc(int index, void *dst)
{
    if ((s32)data_0216bac4[0] - 1 - index < 0) {
        return;
    }
    func_020086bc(dst, data_0216bac8[index].block_bc, 32);
}

/* Copies 32 bytes from entry +0xdc, evidenced by the original copy call.
 * Destination must hold 32 bytes; rejected entry indices leave it untouched. */
void Unk06e2a0_CopyEntryDc(int index, void *dst)
{
    if ((s32)data_0216bac4[0] - 1 - index < 0) {
        return;
    }
    func_020086bc(dst, data_0216bac8[index].block_dc, 32);
}

/* Copies 32 bytes from entry +0xfc, evidenced by the original copy call.
 * Destination must hold 32 bytes; rejected entry indices leave it untouched. */
void Unk06e2a0_CopyEntryFc(int index, void *dst)
{
    if ((s32)data_0216bac4[0] - 1 - index < 0) {
        return;
    }
    func_020086bc(dst, data_0216bac8[index].block_fc, 32);
}

/* Copies 32 bytes from entry +0x11c, evidenced by the original copy call.
 * Destination must hold 32 bytes; rejected entry indices leave it untouched. */
void Unk06e2a0_CopyEntry11c(int index, void *dst)
{
    if ((s32)data_0216bac4[0] - 1 - index < 0) {
        return;
    }
    func_020086bc(dst, data_0216bac8[index].block_11c, 32);
}
