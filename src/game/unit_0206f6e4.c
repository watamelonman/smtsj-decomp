#include "types.h"

extern char *func_02015450(const char *text, int character);
extern u8 Unk06dddc_Unk_06e06c(const char *name);
extern s8 *func_02051610(const char *path);
extern void func_02007e94(void);
extern u32 func_0206dafc(const char *name);
extern void func_02053000(void *allocation);
u32 func_0206f778(u32 slot, s8 *file);

/* Loads a VER resource into a slot, or returns its existing slot / 255 on failure.
 * UniteEvent_LoadEffects supplies Data/Effect paths; the exact format is otherwise unknown.
 * The successful file buffer is owned here and released after conversion. */
u32 func_0206f6e4(s8 *path)
{
    char *name = func_02015450((char *)path, '/');
    int slot = Unk06dddc_Unk_06e06c(name + 1);
    if (slot == 255) {
        s8 *file = func_02051610((char *)path);
        u32 valid;
        if (file == 0) {
            return 255;
        }
        valid = file[0] == 'V' && file[1] == 'E' && file[2] == 'R';
        if (!valid) {
            func_02007e94();
            return 255;
        }
        slot = func_0206dafc(name + 1);
        slot = func_0206f778(slot, file);
        func_02053000(file);
    }
    return slot;
}

/* Borrowed on-disk header: count controls records starting at byte 484. */
typedef struct Unk06f6e4File {
    s8 signature[4];
    u8 version[2];
    u8 pad_006[6];
    s32 count_00c;
    volatile s32 count_010; /* Preserve original count reloads; see DEC-008. */
    u8 block_014[144];
    u8 block_0a4[320];
    u8 records[1]; /* Variable length; stride depends on version. */
} Unk06f6e4File;

/* Historical and current record views; only fields touched by conversion are named. */
typedef struct Unk06f6e4Copy {
    u32 words[77];
} Unk06f6e4Copy;
typedef struct Unk06f6e4Old {
    char name[32];
    u8 block_020[308];
    u8 block_154[166];
    u8 flags[2];
    char tail[32];
    u32 value_21c;
} Unk06f6e4Old;
typedef struct Unk06f6e4Record {
    char name[32];
    u8 block_020[300];
    u32 handle_14c;
    u8 pad_150[4];
    u8 block_154[166];
    u8 flags[6];
    u32 value_200;
    char tail[32];
    u32 value_224;
} Unk06f6e4Record;
extern void *func_02052fe0(u32 size);
extern void func_02008848(void *dest, u32 value, u32 size);
extern void func_020086a0(u32 value, void *dest, u32 size);
extern void func_020086bc(const void *source, void *dest, u32 size);
extern void func_02015134(char *dest, const char *source);
extern u32 func_02071efc(const char *name);
extern void func_0206de10(u32 slot, Unk06f6e4Record *records, s32 count);
extern void func_0206de7c(u32 slot, const void *block, s32 count);
extern void Unk06dddc_Unk_06dee8(u32 slot, const void *block);
extern void Unk06e2a0_CopyEntryBc(u32 slot, const void *block);
extern void Unk06e2a0_CopyEntryDc(u32 slot, const void *block);
extern void Unk06e2a0_CopyEntryFc(u32 slot, const void *block);
extern void Unk06e2a0_CopyEntry11c(u32 slot, const void *block);

/* Converts VER records into 552-byte runtime records and installs their blocks.
 * Version bytes at +4/+5 select the 544-byte legacy layout or current layout.
 * Caller supplies a complete buffer with at most 16 records and a valid slot.
 * file remains borrowed; the temporary 16-record allocation is released here. */
u32 func_0206f778(u32 slot, s8 *file)
{
    s8 version[2] = {0, 0};
    u32 block_bc[8], block_dc[8], block_fc[8], block_11c[8];
    Unk06f6e4Old old[16];
    u32 extended = 0;
    Unk06f6e4Record *records;
    Unk06f6e4File *header = (Unk06f6e4File *)file;
    s32 i;
    Unk06f6e4Old *source;
    Unk06f6e4Record *dest;
    u32 valid;
    records = func_02052fe0(8832);
    func_02008848(records, 0, 8832);
    valid = header->signature[0] == 'V' && header->signature[1] == 'E' && header->signature[2] == 'R';
    if (!valid) {
        func_02007e94();
        return 255;
    }
    version[0] = header->version[0];
    version[1] = header->version[1];
    if (version[0] - '0' >= 1 && version[1] - '0' >= 1) extended = 1;
    if (version[0] - '0' >= 1 && version[1] - '0' >= 2) {
        func_020086bc(header->records, records, header->count_010 * 552);
        func_020086bc((u8 *)header + (header->count_010 * 552 + 484), block_bc, 32);
        if (extended) {
            func_020086bc((u8 *)header + (header->count_010 * 552 + 492), block_dc, 32);
            func_020086bc((u8 *)header + (header->count_010 * 552 + 500), block_fc, 32);
            func_020086bc((u8 *)header + (header->count_010 * 552 + 508), block_11c, 32);
        }
    } else {
        func_020086a0(0, old, 8704);
        func_020086bc(header->records, old, header->count_010 * 544);
        for (i = 0; i < header->count_010; i++) {
            source = &old[i];
            dest = &records[i];
            dest->value_224 = source->value_21c;
            func_02015134(dest->name, source->name);
            /* Aggregate assignment preserves the original 308-byte copy. */
            *(Unk06f6e4Copy *)dest->block_020 = *(Unk06f6e4Copy *)source->block_020;
            func_02015134(dest->tail, source->tail);
            func_020086bc(source->block_154, dest->block_154, 168);
            dest->flags[2] = dest->flags[0];
            dest->flags[3] = dest->flags[1];
            dest->flags[4] = 0;
            dest->flags[5] = 0;
            dest->value_200 = 0;
            if ((version[0] - '0' == 1 && version[1] - '0' == 0) || version[0] - '0' == 0) {
                dest->flags[0] = 0;
                dest->flags[1] = 0;
                dest->flags[2] = 0;
                dest->flags[3] = 0;
            }
        }
        func_020086bc((u8 *)header + (header->count_010 * 544 + 484), block_bc, 32);
        if (extended) {
            func_020086bc((u8 *)header + (header->count_010 * 544 + 492), block_dc, 32);
            func_020086bc((u8 *)header + (header->count_010 * 544 + 500), block_fc, 32);
            func_020086bc((u8 *)header + (header->count_010 * 544 + 508), block_11c, 32);
        }
    }
    if (!extended) {
        func_020086a0(0, block_dc, 32);
        ((u8 *)block_dc)[0] = 255;
        ((u8 *)block_dc)[1] = 255;
        ((u8 *)block_dc)[2] = 255;
        func_020086a0(0, block_fc, 32);
        ((u8 *)block_fc)[0] = 255;
        ((u8 *)block_fc)[1] = 255;
        ((u8 *)block_fc)[2] = 255;
        func_020086a0(0, block_11c, 32);
        ((u8 *)block_11c)[0] = 255;
        ((u8 *)block_11c)[1] = 255;
        ((u8 *)block_11c)[2] = 255;
    }
    {
        s32 j;
        Unk06f6e4Record *entry;
        for (j = 0; j < header->count_010; j++) {
            entry = &records[j];
            entry->handle_14c = func_02071efc(entry->tail);
        }
    }
    func_0206de10(slot, records, header->count_010);
    func_0206de7c(slot, header->block_0a4, header->count_00c);
    Unk06dddc_Unk_06dee8(slot, header->block_014);
    Unk06e2a0_CopyEntryBc(slot, block_bc);
    Unk06e2a0_CopyEntryDc(slot, block_dc);
    Unk06e2a0_CopyEntryFc(slot, block_fc);
    Unk06e2a0_CopyEntry11c(slot, block_11c);
    func_02053000(records);
    return slot;
}
