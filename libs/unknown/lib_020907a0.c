/* Borrowed buffer slices reconstructed from ARM loads/stores at 020907a0–020909c8. */
#include "types.h"

/* Layout belongs to the original library; callers retain backing-buffer ownership. */
typedef struct Unk0907a0State {
    u8 *cached_00;
    u8 *cached_04;
    u8 *cached_08;
    u32 remaining_0c;
    u8 *next_10;
    u32 remaining_14;
    u8 *next_18;
    u32 unk_1c;
    u8 *cached_20;
} Unk0907a0State;

extern Unk0907a0State data_02175d68;
extern const u8 data_02134d90[];
extern const u8 data_02132c90[];
extern const u8 data_0213b9f8[];
extern const u8 data_0213b878[];

/* ARM 02008768 copies size bytes in words; both buffers must be word aligned. */
extern void func_02008768(const void *source, void *destination, u32 size);

/* ARM literal at 020907a8: required byte count for the cached slice at offset 08. */
u32 func_020907a0(void)
{
    return 0x659c;
}

/* ARM immediate at 020907ac: return the library's fixed 9600-byte requirement. */
u32 func_020907ac(void)
{
    return 9600;
}

/* ARM stores at 020907b4: borrow a word-aligned buffer, round capacity down,
 * and invalidate its cached slice. The caller keeps the buffer alive. */
void func_020907b4(u8 *buffer, u32 size)
{
    data_02175d68.next_18 = buffer;
    data_02175d68.remaining_14 = size & ~3;
    data_02175d68.cached_08 = 0;
}

/* ARM stores at 020907d4: reset the first borrowed arena and its three caches.
 * The caller supplies word-aligned storage and retains its ownership. */
void func_020907d4(u8 *buffer, u32 size)
{
    data_02175d68.next_10 = buffer;
    data_02175d68.remaining_0c = size & ~3;
    data_02175d68.cached_04 = 0;
    data_02175d68.cached_00 = 0;
    data_02175d68.cached_20 = 0;
}

/* ARM 020907fc: lazily copy 0x659c bytes into the borrowed arena and cache
 * that slice; insufficient capacity returns the immutable original data. */
const u8 *func_020907fc(void)
{
    if (data_02175d68.cached_08 == 0) {
        if (data_02175d68.remaining_14 >= 0x659c) {
            data_02175d68.cached_08 = data_02175d68.next_18;
            func_02008768(data_02134d90, data_02175d68.next_18, 0x659c);
            data_02175d68.next_18 += 0x659c;
            data_02175d68.remaining_14 -= 0x659c;
        } else {
            return data_02134d90;
        }
    }
    return data_02175d68.cached_08;
}

/* ARM 02090878: lazily copy 0x2100 bytes into the borrowed arena and cache
 * that slice; insufficient capacity returns the immutable original data. */
const u8 *func_02090878(void)
{
    if (data_02175d68.cached_04 == 0) {
        if (data_02175d68.remaining_0c >= 0x2100) {
            data_02175d68.cached_04 = data_02175d68.next_10;
            func_02008768(data_02132c90, data_02175d68.next_10, 0x2100);
            data_02175d68.next_10 += 0x2100;
            data_02175d68.remaining_0c -= 0x2100;
        } else {
            return data_02132c90;
        }
    }
    return data_02175d68.cached_04;
}

/* ARM 020908e8: lazily copy 0x300 bytes into the borrowed arena and cache
 * that slice; insufficient capacity returns the immutable original data. */
const u8 *func_020908e8(void)
{
    if (data_02175d68.cached_00 == 0) {
        if (data_02175d68.remaining_0c >= 0x300) {
            data_02175d68.cached_00 = data_02175d68.next_10;
            func_02008768(data_0213b9f8, data_02175d68.next_10, 0x300);
            data_02175d68.next_10 += 0x300;
            data_02175d68.remaining_0c -= 0x300;
        } else {
            return data_0213b9f8;
        }
    }
    return data_02175d68.cached_00;
}

/* ARM 02090958: lazily copy 0x180 bytes into the borrowed arena and cache
 * that slice; insufficient capacity returns the immutable original data. */
const u8 *func_02090958(void)
{
    if (data_02175d68.cached_20 == 0) {
        if (data_02175d68.remaining_0c >= 0x180) {
            data_02175d68.cached_20 = data_02175d68.next_10;
            func_02008768(data_0213b878, data_02175d68.next_10, 0x180);
            data_02175d68.next_10 += 0x180;
            data_02175d68.remaining_0c -= 0x180;
        } else {
            return data_0213b878;
        }
    }
    return data_02175d68.cached_20;
}
