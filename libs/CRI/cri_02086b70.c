/* Small CRI registry/accessor helpers from the translation unit that spans
 * 0x02086b70..0x02087268. Only fields established by the original ARM
 * instructions are exposed; all storage remains owned by the caller or by the
 * library globals declared below. */
#include "types.h"

/** Borrowed object prefix; 02086b70/02086b84 read the two halfwords at +0x1c
 * and +0x1e. The rest of the object is opaque here. */
typedef struct Cri02086b70Object {
    u8 pad_00[0x1c];
    u16 unk_1c;
    u16 unk_1e;
} Cri02086b70Object;

/** Library-global record beginning at data_02175a08. Offset +0xc is written
 * by 02086e24 and read by 02086f34; the +0x4 counter is bumped by 02086c50 and
 * the +0x10 refcount is maintained by 02086e4c/02086e7c. */
typedef struct Cri02086b70Library {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    void *unk_0c;
    s32 unk_10;
} Cri02086b70Library;

/** Embedded Nitro stream state at +0x34 of the player. The stream helpers keep
 * their own layout private (libs/unknown/lib_0202a890.c); this unit only needs
 * its address, so the body stays opaque. */
typedef struct Cri02086b70Stream {
    u8 opaque[0x17c];
} Cri02086b70Stream;

/** Borrowed CRI player record. The volume/pan helpers use the two halfwords
 * near +0x20 and the embedded stream, while the lifetime helpers use the
 * handle slots at +0x1b0/+0x1b4 and clear the whole 0xa2c-byte record. */
typedef struct Cri02086b70Player {
    u8 pad_000[0x20];
    u16 unk_020;
    u16 unk_022;
    u8 pad_024[0x34 - 0x24];
    Cri02086b70Stream stream;
    void *unk_1b0;
    void *unk_1b4;
    u8 pad_1b8[0xa2c - 0x1b8];
} Cri02086b70Player;

/** Word shared by the getter/setter pair 02086c38/02086c28. */
extern u32 data_02175a04;
/** Library record whose +0xc slot is written by 02086e24. */
extern Cri02086b70Library data_02175a08;
/** Device record forwarded to func_02086c6c from 02086dc4. */
extern u8 data_02147614;

extern void func_0208995c(void *value);
extern void func_0208996c(void *value);
extern void func_0208997c(void);
extern void func_02089a2c(void);
extern void func_02089a8c(void *handle);
/** Stream master-volume helper from the Nitro stream unit. */
extern void func_0202aba0(void *stream, s32 volume);
/** Stream per-channel volume helper from the Nitro stream unit. */
extern void func_0202ac0c(void *stream, s32 channel, s32 volume);
/** Stream per-channel pan helper from the Nitro stream unit. */
extern void func_0202ac60(void *stream, s32 channel, s32 pan);
extern void *func_020119c0(void *destination, int value, u32 size);
extern s32 func_02086c6c(void *device, s32 command, void *a, void *b, void *c);
extern void func_02086f98(Cri02086b70Player *player);

/** Returns half of the halfword at +0x1c of the object, or zero for a null
 * object. Callers at 020849dc and 02084ff4 pass the word loaded from their
 * own +0x20 slot, so the result is a derived rate/size value. */
u32 func_02086b70(const Cri02086b70Object *object)
{
    if (object == 0) return 0;
    return (u32)object->unk_1c >> 1;
}

/** Same as 02086b70 but for the second halfword at +0x1e (called from
 * 020849f8). */
u32 func_02086b84(const Cri02086b70Object *object)
{
    if (object == 0) return 0;
    return (u32)object->unk_1e >> 1;
}

/** Applies a volume to the player: records it in the halfword at +0x22, then
 * forwards it as the stream master volume and clears channel 0's volume trim.
 * The original returns the incoming halfword unchanged in r0. */
u16 func_02086b98(Cri02086b70Player *player, u16 volume)
{
    player->unk_022 = volume;
    func_0202aba0(&player->stream, volume);
    func_0202ac0c(&player->stream, 0, 0);
    return volume;
}

/** Maps a signed pan in -15..15 to the player value stored at +0x20 and to the
 * stream pan of channel 0. The extremes are pinned (0 -> centre 64, -15 -> 0,
 * 15 -> 127); the interior uses the linear 128/30 mapping seen as an integer
 * divide by 30 in the original. */
void func_02086bc8(Cri02086b70Player *player, s32 pan)
{
    s32 value;
    if (pan == 0) value = 64;
    else if (pan == -15) value = 0;
    else if (pan == 15) value = 127;
    else value = (pan + 15) * 128 / 30;
    player->unk_020 = value;
    func_0202ac60(&player->stream, 0, value);
}

/** Stores a word into the library global at data_02175a04. */
void func_02086c28(void *value)
{
    data_02175a04 = (u32)value;
}

/** Copies the library word to *value and returns 30. The caller at 02087550
 * supplies zero for the first argument and the destination in r1, so the
 * first parameter is not used by this implementation. */
s32 func_02086c38(s32 unused, u32 *value)
{
    *value = data_02175a04;
    return 30;
}

/** Increments the library record's +0x4 counter and reports success (the
 * original always returns zero). Called once before the first 02086c6c
 * dispatch to initialise the count. */
s32 func_02086c50(void)
{
    data_02175a08.unk_04++;
    return 0;
}

/** Forwards the value to the neighbouring setter at 02086c28; the original
 * is a single interworking tail call. */
void func_02086e18(void *value)
{
    func_02086c28(value);
}

/** Ensures the library counter is initialised, then dispatches command 6 with
 * three caller words to the device record at data_02147614. Always reports
 * success; the fifth argument travels on the stack, matching the original. */
s32 func_02086dc4(void *a, void *b, void *c)
{
    if (data_02175a08.unk_04 == 0) func_02086c50();
    func_02086c6c(&data_02147614, 6, a, b, c);
    return 0;
}

/** Stores a word into the library record's +0xc slot (02086e24). */
void func_02086e24(void *value)
{
    data_02175a08.unk_0c = value;
}

/** Forwards the value to func_0208995c, which stores it in its own global;
 * the original is a single interworking tail call. */
void func_02086e34(void *value)
{
    func_0208995c(value);
}

/** Forwards the value to func_0208996c, which stores it in its own global;
 * the original is a single interworking tail call. */
void func_02086e40(void *value)
{
    func_0208996c(value);
}

/** Takes a reference on the library record: when the +0x10 count is still zero
 * the provider is initialised first, then the count is incremented. */
void func_02086e4c(void)
{
    if (data_02175a08.unk_10 == 0) func_0208997c();
    data_02175a08.unk_10++;
}

/** Drops a reference on the library record and tears the provider down when
 * the count reaches zero. */
void func_02086e7c(void)
{
    if (--data_02175a08.unk_10 == 0) func_02089a2c();
}

/** Releases the player's handle at +0x1b4 (clearing the slot first, as the
 * original does) and then zeroes the whole 0xa2c-byte player record. */
void func_02086f60(Cri02086b70Player *player)
{
    void *handle = player->unk_1b4;
    if (handle != 0) {
        player->unk_1b4 = 0;
        func_02089a8c(handle);
    }
    func_020119c0(player, 0, 0xa2c);
}

/** Reinitialises the player through func_02086f98 and then stores the caller's
 * word in the +0x1b0 slot. */
void func_02087054(Cri02086b70Player *player, void *value)
{
    func_02086f98(player);
    player->unk_1b0 = value;
}
