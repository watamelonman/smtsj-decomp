#include "types.h"

/* Layout follows the word accesses in func_02111400; slot 8 is untouched. */
typedef struct Unk111400Work {
    u32 size;
    u32 enabled;
    u32 unk_08;
    void (*callback_0c)(void);
    void (*callback_10)(void);
    void (*callback_14)(void);
    u32 unk_18;
    void (*callback_1c)(void);
    void (*callback_20)(void);
} Unk111400Work;

extern void func_0211030c(void), func_02110658(void), func_02110fc8(void);
extern void Unk10fe28_Unk_1113e0(void), func_021100c0(void);
extern u8 data_02151560[], data_02151584[];
extern u16 data_02151580;
extern u32 data_02176e4c[2];
extern u32 func_02051610(const void *);
extern void func_0208f020(void), func_0208f038(void);
extern void func_0201fba8(void), func_0208dc78(void);
extern void func_0208f044(const void *, u32, u32);
extern int func_02013c3c(char *, const void *, ...);
extern void *func_020445d0(u32, u32);
extern void *func_0204fde0(void *);
extern u32 func_0204fe18(void *);
extern void *func_02011810(void *, const void *, u32, u32,
                         int (*)(const u16 *, const u16 *));
extern void func_02008848(void *, int, u32);
extern void func_02008644(int, void *, u32);
/* Borrowed record view: field offsets come from the pack/unpack instructions. */
typedef struct Unk111400Record {
    u32 unk_00;
    s8 first[5];
    u8 pad_09[15];
    s8 second[5];
    u8 pad_1d[7];
    u32 value;
    u16 entries[6];
    u16 unk_34;
    u16 key;
    u8 level;
    u8 pad_39[3];
} Unk111400Record;
extern void func_02111ac4(void *, Unk111400Record *);
extern void func_02111fb4(void *, u32, const void *, u32);
extern void func_02061c28(u32, u32, const void *);

/* Installs the callbacks identified by the original's five symbol relocations. */
void func_02111400(Unk111400Work *work)
{
    work->size = 0x60;
    work->enabled = 1;
    work->callback_0c = func_0211030c;
    work->callback_10 = func_02110658;
    work->callback_14 = func_02110fc8;
    work->unk_18 = 0;
    work->callback_1c = Unk10fe28_Unk_1113e0;
    work->callback_20 = func_021100c0;
}

/* Stores the resource lookup result in the observed word at offset 0x18. */
void Unk111400_Unk_111458(Unk111400Work *work)
{
    work->unk_18 = func_02051610(data_02151560);
}

/* Saves the three arguments in the original shared word/halfword slots. */
void Unk111400_Unk_111474(u32 first, u16 second, u32 third)
{
    u32 *words = data_02176e4c;
    u16 *half = &data_02151580;
    words[0] = first;
    *half = second;
    words[1] = third;
}

/* Brackets the three-argument operation with the original setup and teardown calls. */
u32 Unk111400_Unk_111508(const void *first, u32 second, u32 third)
{
    func_0208f020();
    func_0208f044(first, second, third);
    func_0208f038();
    func_0201fba8();
    func_0208dc78();
    return 0;
}

/* Formats the saved first argument into a 16-byte buffer before dispatch. */
u32 func_02111494(void)
{
    char buffer[16] = {0};
    func_02013c3c(buffer, data_02151584, data_02176e4c[0]);
    Unk111400_Unk_111508(buffer, data_02151580, data_02176e4c[1]);
    return 0;
}

/* Encodes a 24-byte value and submits a terminated 32-halfword buffer. */
void func_02111540(u32 first, Unk111400Record *second)
{
    u8 value[24];
    u16 *buffer;
    func_02008848(value, 0, sizeof(value));
    u32 length = 33;
    u16 storage[length];
    buffer = storage;
    func_02008644(0, buffer, 66);
    func_02111ac4(value, second);
    func_02111fb4(buffer, 32, value, sizeof(value));
    buffer[32] = 0;
    func_02061c28(1, first, buffer);
}

/* Compares the unsigned leading halfwords; callers provide readable halfwords. */
int Unk111400_Unk_112254(const u16 *first, const u16 *second)
{
    return (u32)*first - (u32)*second;
}

/* Searches the resource's 24-byte records using a halfword key comparator. */
void *func_02112264(u16 key)
{
    u8 record[24];
    void *resource = func_020445d0(17, 0);
    void *records = func_0204fde0(resource);
    u32 count = func_0204fe18(resource);
    *(u16 *)record = key;
    return func_02011810(record, records, count, 24, Unk111400_Unk_112254);
}

extern int func_02050088(u32 stream, int low, int high);
extern void func_0211199c(u8 *bytes, int count, u32 seed, int reverse);

/* Bit-stream storage is owned by the provider; only its leading buffer is observed. */
typedef struct Unk111400Bits { u8 *buffer; } Unk111400Bits;
extern Unk111400Bits *func_0205efc8(u32 bytes);
extern void func_0205f168(Unk111400Bits *, u32 value, u32 bits);
extern void func_0205f05c(Unk111400Bits *, void *);
extern void func_0205f038(Unk111400Bits *);
extern void func_0205f044(Unk111400Bits *, const void *);
extern u32 func_0205f1a0(Unk111400Bits *, u32 bits);
extern u32 func_020b8144(u32 key, u32 level);
extern int func_020e6948(u32 key, u32 entry);

/* Packs the instruction-observed fields, then masks, permutes and checksums them.
 * output must hold 24 bytes; record is borrowed and remains unchanged. */
void func_02111ac4(void *output, Unk111400Record *record)
{
    u8 *bytes = output;
    Unk111400Bits *bits = func_0205efc8(24);
    int i;
    u8 seed, sum;
    func_0205f168(bits, record->first[0], 7);
    func_0205f168(bits, record->first[1], 7);
    func_0205f168(bits, record->first[2], 7);
    func_0205f168(bits, record->first[3], 7);
    func_0205f168(bits, record->first[4], 7);
    func_0205f168(bits, record->second[0], 7);
    func_0205f168(bits, record->second[1], 7);
    func_0205f168(bits, record->second[2], 7);
    func_0205f168(bits, record->second[3], 7);
    func_0205f168(bits, record->second[4], 7);
    func_0205f168(bits, record->value, 32);
    for (i = 0; i < 6; i++) func_0205f168(bits, record->entries[i], 9);
    func_0205f168(bits, record->level, 7);
    func_0205f168(bits, record->key, 9);
    func_0205f05c(bits, bytes);
    func_0205f038(bits);
    seed = func_02050088(0, 0, 255);
    for (i = 0; i < 22; i++) bytes[i] ^= seed;
    func_0211199c(bytes, 22, seed, 0);
    bytes[22] = seed;
    sum = 0;
    for (i = 0; i < 23; i++) sum += bytes[i];
    bytes[23] = sum;
}

/* Rejects out-of-range record fields and entries unsupported by the key provider.
 * The borrowed record must contain all 60 bytes; returns a boolean validity flag. */
int func_02111e18(Unk111400Record *record)
{
    int i;
    if (record->key >= 0x1eb) return 0;
    if (record->first[0] < 0 || record->first[0] > 99) return 0;
    if (record->first[1] < 0 || record->first[1] > 99) return 0;
    if (record->first[2] < 0 || record->first[2] > 99) return 0;
    if (record->first[3] < 0 || record->first[3] > 99) return 0;
    if (record->first[4] < 0 || record->first[4] > 99) return 0;
    if (record->second[0] < 0 || record->second[0] > 99) return 0;
    if (record->second[1] < 0 || record->second[1] > 99) return 0;
    if (record->second[2] < 0 || record->second[2] > 99) return 0;
    if (record->second[3] < 0 || record->second[3] > 99) return 0;
    if (record->second[4] < 0 || record->second[4] > 99) return 0;
    if (record->value > func_020b8144(record->key, record->level)) return 0;
    if (record->level > 99) return 0;
    for (i = 0; i < 6; i++) {
        if (record->entries[i] != 0 && !func_020e6948(record->key, record->entries[i])) return 0;
    }
    return 1;
}

/* Checks the checksum nibble and decodes the packed fields before validation.
 * input holds 24 bytes; record receives 60 bytes and may change on failure.
 * The original returns without releasing the bit stream on validation failure. */
int func_02111c54(Unk111400Record *record, const u8 *input)
{
    u8 sum = 0;
    int i;
    Unk111400Bits *bits;
    u8 *bytes;
    u8 seed;
    for (i = 0; i < 23; i++) sum += input[i];
    if ((u8)(input[23] & 0xf0) != (u8)(sum & 0xf0)) return 0;
    func_02008848(record, 0, 60);
    bits = func_0205efc8(24);
    func_0205f044(bits, input);
    bytes = bits->buffer;
    seed = bytes[22];
    func_0211199c(bytes, 22, seed, 1);
    for (i = 0; i < 22; i++) bytes[i] ^= seed;
    record->first[0] = func_0205f1a0(bits, 7);
    record->first[1] = func_0205f1a0(bits, 7);
    record->first[2] = func_0205f1a0(bits, 7);
    record->first[3] = func_0205f1a0(bits, 7);
    record->first[4] = func_0205f1a0(bits, 7);
    record->second[0] = func_0205f1a0(bits, 7);
    record->second[1] = func_0205f1a0(bits, 7);
    record->second[2] = func_0205f1a0(bits, 7);
    record->second[3] = func_0205f1a0(bits, 7);
    record->second[4] = func_0205f1a0(bits, 7);
    record->value = func_0205f1a0(bits, 32);
    for (i = 0; i < 6; i++) record->entries[i] = func_0205f1a0(bits, 9);
    record->level = func_0205f1a0(bits, 7);
    record->key = func_0205f1a0(bits, 9);
    if (!func_02111e18(record)) return 0;
    func_0205f038(bits);
    return 1;
}

extern void *func_02052fe0(u32 bytes);
extern void func_02053000(void *allocation);
extern void func_02008904(const void *source, void *dest, u32 bytes);
extern u16 data_0213caa4[64];

/* Encodes groups of three bytes using the relocated data_0213caa4 table.
 * size must be positive; count must hold four indices per padded three-byte group.
 * output holds count halfwords; input holds size bytes and remains unchanged. */
void func_02111fb4(void *output, u32 count, const void *input, u32 size)
{
    u16 *dest = output;
    u32 remainder = size % 3;
    u32 padded;
    u8 *bytes, *indices, *src, *idx;
    u32 i;
    if (remainder) padded = size + (3 - remainder);
    else padded = size;
    bytes = func_02052fe0(padded);
    func_02008904(input, bytes, size);
    for (; size < padded; size++) bytes[size] = func_02050088(0, 0, 255);
    indices = func_02052fe0(count);
    func_02008848(indices, 0, 4);
    src = bytes;
    idx = indices;
    do {
        idx[0] = (src[0] & 0xfc) >> 2;
        idx[1] = ((src[0] & 3) << 4) + ((src[1] & 0xf0) >> 4);
        idx[2] = ((src[1] & 15) << 2) + ((src[2] & 0xc0) >> 6);
        idx[3] = src[2] & 0x3f;
        if ((padded -= 3) == 0) break;
        src += 3;
        idx += 4;
    } while (1);
    for (i = 0; i < count; i++) {
        if (indices[i] < 64) dest[i] = data_0213caa4[indices[i]];
    }
    func_02053000(bytes);
    func_02053000(indices);
}

/* Reverses the encoding established by the data_0213caa4 table relocation.
 * size must be positive; input holds count halfwords, including complete groups
 * of four for the rounded-up byte size. output holds size bytes. */
void func_02112110(void *output, u32 size, const u16 *input, u32 count)
{
    u32 remainder = size % 3;
    u32 padded;
    u8 *bytes, *indices, *dest, *src;
    u32 i;
    u8 j;
    if (remainder) padded = size + (3 - remainder);
    else padded = size;
    bytes = func_02052fe0(padded);
    func_02008848(bytes, 0, 4);
    indices = func_02052fe0(count);
    for (i = 0; i < count; i++) {
        indices[i] = 255;
        for (j = 0; j < 64; j++) {
            if (input[i] == data_0213caa4[j]) indices[i] = j;
        }
    }
    dest = bytes;
    src = indices;
    do {
        dest[0] = ((src[0] & 0x3f) << 2) + ((src[1] & 0x30) >> 4);
        dest[1] = ((src[1] & 15) << 4) + ((src[2] & 0x3c) >> 2);
        dest[2] = ((src[2] & 3) << 6) + (src[3] & 0x3f);
        if ((padded -= 3) == 0) break;
        src += 4;
        dest += 3;
    } while (1);
    func_02008904(bytes, output, size);
    func_02053000(indices);
    func_02053000(bytes);
}
