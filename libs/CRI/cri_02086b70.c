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

/** Left/right halfword pair of the parsed player header. 0208706c copies six
 * of them as a unit, so the pair is a struct rather than two loose fields. */
typedef struct Cri02086b70Pair {
    s16 left;
    s16 right;
} Cri02086b70Pair;

/** Opaque eight-byte block. 0208706c copies it byte-wise when the parsed
 * format selects the eight-byte case, and its four halfwords become the
 * channel values written by 02086dc4 in the other case. */
typedef struct Cri02086b70Blob8 {
    u8 bytes[8];
} Cri02086b70Blob8;

/** Parsed 0x3c-byte block at +0x1e8 of the player. 0208706c fills it from a
 * 64-byte bitstream header and the fields at +0x34 can be dispatched as three
 * signed halfword outputs. */
typedef struct Cri02086b70Header {
    u32 unk_00;
    s32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u8 pad_10[0x0c];
    Cri02086b70Pair unk_1c[6];
    Cri02086b70Blob8 unk_34;
} Cri02086b70Header;

/** 64-byte header decoded by 0208706c. The bitstream layout is fixed; only the
 * fields consumed by the player are named. */
typedef struct Cri02086b70Block {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    s8 unk_03;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u8 pad_10[0x24 - 0x10];
    Cri02086b70Pair unk_24[6];
    u8 unk_3c;
    s8 unk_3d;
    u8 unk_3e[2];
} Cri02086b70Block;

/** Borrowed CRI player record. The volume/pan helpers use the two halfwords
 * near +0x20 and the embedded stream, while the lifetime helpers use the
 * handle slots at +0x1b0/+0x1b4 and clear the whole 0xa2c-byte record. The
 * tail models the parsed header and the two areas 02086f98 clears. */
typedef struct Cri02086b70Player {
    u8 pad_000[0x20];
    u16 unk_020;
    u16 unk_022;
    u8 pad_024[0x34 - 0x24];
    Cri02086b70Stream stream;
    void *unk_1b0;
    void *unk_1b4;
    u8 pad_1b8[0x1e8 - 0x1b8];
    Cri02086b70Header header;
    u8 unk_224[0x800];
    Cri02086b70Blob8 unk_a24;
} Cri02086b70Player;

/** Word shared by the getter/setter pair 02086c38/02086c28. */
extern u32 data_02175a04;
/** Library record whose +0xc slot is written by 02086e24. */
extern Cri02086b70Library data_02175a08;
/** Device record forwarded to func_02086c6c from 02086dc4. */
extern u8 data_02147614;
/** First four bytes of the staging buffer filled by 0208706c. */
extern u8 data_02175a1c[];
/** Payload start of the staging buffer filled by 0208706c. */
extern u8 data_02175a20[];

extern void func_0208995c(void *value);
extern void func_0208996c(void *value);
extern void func_0208997c(void);
extern void func_02089a2c(void);
extern void func_02089a8c(void *handle);
/** Reinitialises a bit reader over the caller-owned 0x81c-byte work area. */
extern void *func_02089a44(void *work, u32 size);
/** Reads `bits` bits from a finished bit-reader state. */
extern s32 func_0208a824(void *reader, s32 bits);
/** Parses an 0x8000-tagged block from `src` and optionally decompresses it. */
extern s32 func_0208a2fc(void *src, s32 size, u32 *outLen, void *dst);
/** Stream master-volume helper from the Nitro stream unit. */
extern void func_0202aba0(void *stream, s32 volume);
/** Stream per-channel volume helper from the Nitro stream unit. */
extern void func_0202ac0c(void *stream, s32 channel, s32 volume);
/** Stream per-channel pan helper from the Nitro stream unit. */
extern void func_0202ac60(void *stream, s32 channel, s32 pan);
extern void *func_020119c0(void *destination, int value, u32 size);
/** Decodes three channel values from a signed-byte stream. Left to the delink:
 * its four table addresses are unnamed, so the original raw literal-pool
 * constants cannot be reproduced without relocations. See the hard list in
 * docs/functions/libs-cri-cri-02086b70.md. */
extern s32 func_02086c6c(void *device, s32 command, void *a, void *b, void *c);
extern void func_02086f98(Cri02086b70Player *player);

/** Copies one eight-byte blob as four two-byte moves. The helper exists so the
 * inlined copy keeps the destination pointer in the register the original
 * uses; writing the loop at the call site produced the opposite assignment. */
static inline void Cri02086b70CopyBlob8(Cri02086b70Blob8 *dst, Cri02086b70Blob8 *src)
{
    u8 *d = dst->bytes;
    u8 *s = src->bytes;
    u32 n = 4;
    do {
        u8 lo = s[0];
        u8 hi = s[1];
        s += 2;
        d[0] = lo;
        d[1] = hi;
        d += 2;
    } while (--n != 0);
}

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

/** Initialises a caller-owned player record at `p` and a bit-reader work area
 * directly after its 0xa2c bytes. The return value is `p` on success and null
 * when the caller's budget `size` is insufficient or the work area cannot be
 * set up. The original aligns the record to 8 bytes before clearing it and
 * keeps an aligned self-pointer at +0x0. */
void *func_02086ea0(u8 *p, u32 size)
{
    u8 *base = (u8 *)(((u32)p + 7) & ~7u);
    u8 *sub;
    void *work;

    func_020119c0(base, 0, 0xa2c);
    sub = (u8 *)(((u32)(base + 0xa2c) + 7) & ~7u);
    if ((u32)sub + 0x1c + 0x800 < size) return 0;
    work = func_02089a44(sub, 0x81c);
    *(void **)(p + 0x1b4) = work;
    if (work == 0) return 0;
    *(u32 *)p = ((u32)p + 0x23) & ~31u;
    p[0x1e8] = 0;
    p[0x1e9] = 0;
    p[0x1ea] = 0;
    p[0x1eb] = 0;
    p[0x1ec] = 0;
    p[0x1ed] = 0;
    p[0x1ee] = 0;
    p[0x1ef] = 0;
    *(void **)(p + 0x1a4) = data_02175a08.unk_0c;
    p[0x1ab] = 16;
    p[0x1a8] = 1;
    return p;
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

/** Reinitialises the parsed header, the two 0x300-byte channel areas and the
 * 0x180-byte buffer at +0x0, then rebuilds the player's bit-reader work area
 * at +0x1b4 from the same 0x81c-byte allocation. */
void func_02086f98(Cri02086b70Player *player)
{
    void *handle = player->unk_1b4;
    func_020119c0((u8 *)player + 0x1b8, 0, 0x30);
    func_020119c0((u8 *)player + 0x1e8, 0, 0x3c);
    func_020119c0((u8 *)player + 0x224, 0, 0x100);
    func_020119c0((u8 *)player + 0x324, 0, 0x100);
    func_020119c0((u8 *)player + 0x424, 0, 0x300);
    func_020119c0(*(void **)player, 0, 0x180);
    func_020119c0((u8 *)player + 0x724, 0, 0x300);
    *((u8 *)player + 0x1a9) = 0;
    *(u32 *)((u8 *)player + 0x1ac) = 0;
    if (player->unk_1b4 != 0) {
        void *old = player->unk_1b4;
        player->unk_1b4 = 0;
        func_02089a8c(old);
        player->unk_1b4 = func_02089a44(handle, 0x81c);
    }
}

/** Reinitialises the player through func_02086f98 and then stores the caller's
 * word in the +0x1b0 slot. */
void func_02087054(Cri02086b70Player *player, void *value)
{
    func_02086f98(player);
    player->unk_1b0 = value;
}

/** Parses the next compressed block for the player. The bit reader first
 * yields the four-byte tag into data_02175a1c, func_0208a2fc returns the
 * payload length, the payload is read into data_02175a20, and the whole block
 * is decompressed into a 64-byte local header. The header's +0x3d type byte
 * then selects how the four channel halfwords at +0x34 are produced. */
void func_0208706c(Cri02086b70Player *p)
{
    void *reader;
    u8 *dst;
    u8 *end;
    Cri02086b70Header *h = &p->header;
    s32 type;

    if (p->unk_1b0 == 0) return;
    reader = p->unk_1b0;
    Cri02086b70Block b = {0};
    u32 len = 0;

    dst = data_02175a1c;
    end = data_02175a20;
    while (dst != end) *dst++ = func_0208a824(reader, 8);
    func_0208a2fc(data_02175a1c, 4, &len, 0);
    end += len;
    while (dst != end) *dst++ = func_0208a824(reader, 8);
    if (func_0208a2fc(data_02175a1c, 512, &len, &b) < 0) return;

    h->unk_04 = b.unk_03;
    h->unk_08 = b.unk_04;
    h->unk_0c = b.unk_08;
    h->unk_1c[0] = b.unk_24[0];
    h->unk_1c[1] = b.unk_24[1];
    h->unk_1c[2] = b.unk_24[2];
    h->unk_1c[3] = b.unk_24[3];
    h->unk_1c[4] = b.unk_24[4];
    h->unk_1c[5] = b.unk_24[5];
    h->unk_00 = 1;
    type = b.unk_3d;
    if (type >= 16) {
        *(u16 *)h->unk_34.bytes = 0;
        func_02086dc4(h->unk_34.bytes + 2, h->unk_34.bytes + 4, h->unk_34.bytes + 6);
        return;
    }
    if (type >= 8) {
        Cri02086b70CopyBlob8(&h->unk_34, &p->unk_a24);
        return;
    }
    h->unk_34.bytes[0] = 0;
    h->unk_34.bytes[1] = 0;
    h->unk_34.bytes[2] = 0;
    h->unk_34.bytes[3] = 0;
    h->unk_34.bytes[4] = 0;
    h->unk_34.bytes[5] = 0;
    h->unk_34.bytes[6] = 0;
    h->unk_34.bytes[7] = 0;
}
