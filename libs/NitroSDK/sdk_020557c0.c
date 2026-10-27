#include "types.h"

extern void func_02004aec(const void *source, u32 offset, u32 size);
/* Borrowed background record; offsets come from the transfer/update instructions.
 * The provider owns both buffers and the record. */
typedef struct SDK557c0Record {
    u32 kind;
    u32 layout;
    u8 width, height;
    u8 reserved0a[2];
    u32 format;
    u8 flags;
    u8 reserved11[11];
    const void *map;
    u32 size;
    u8 *pixels;
} SDK557c0Record;

extern SDK557c0Record *func_0205410c(u32 index);
extern void func_02006c94(const void *source, u32 size);
extern void func_020046b4(const void *source, u32 offset, u32 size);
extern void func_02004708(const void *source, u32 offset, u32 size);
extern void func_02008848(void *destination, u32 value, u32 size);
extern void func_0205590c(u32 index, u32 slot, const void *source, u32 size);
extern const u32 data_0212e2ec[];
extern const u16 data_0212e310[], data_0212e328[];
extern void (*data_02143b70[])(const void *source, u32 offset, u32 size);
extern u32 func_020557cc(const void *record);
extern void func_0205589c(u32 index, const void *source, u32 size);
extern void func_020559a0(u32 engine, u32 slot, const void *source, u32 count);
extern void func_020559f8(u32 engine, u32 slot, const void *source, u32 count);
extern void func_02055ce4(s32 index);

/* Forwards caller-owned source bytes and destination offset to 02004aec;
 * evidence: the original tail call preserves all three argument registers. */
void func_020557c0(const void *source, u32 offset, u32 size)
{
    func_02004aec(source, offset, size);
}

/* Loads the selected record's derived byte count from caller-owned source.
 * Evidence: 02055874 calls record lookup, size helper, then 0205589c in order. */
void func_02055874(u32 index, const void *source)
{
    u32 size = func_020557cc(func_0205410c(index));
    func_0205589c(index, source, size);
}

/* Submits one 32-byte slot; 020559a0 shifts slot and count by five before
 * cache maintenance and the main/sub palette transfer providers. */
void func_02055990(u32 engine, u32 slot, const void *source)
{
    func_020559a0(engine, slot, source, 1);
}

/* Submits one 512-byte slot; 020559f8 shifts slot and count by nine and
 * selects normal or extended main/sub palette transfer providers. */
void func_020559e8(u32 engine, u32 slot, const void *source)
{
    func_020559f8(engine, slot, source, 1);
}

/* Accumulates low-byte flags in caller-owned record byte +0x10, as shown
 * by the original byte load, OR and byte store. No other bytes are changed. */
void func_02055ab0(void *record, u32 flags)
{
    ((u8 *)record)[0x10] |= flags;
}

/* Services all eight record indices in ascending order; 02055ce4 tests the
 * record's +0x20 pointer and dispatches according to its +0x10 flag byte. */
void func_02055d2c(void)
{
    s32 index;
    for (index = 0; index < 8; index++) {
        func_02055ce4(index);
    }
}

/* Maps zero to 32768 and any nonzero selector to 65536; evidence is the
 * original conditional immediates. The selector's wider meaning is unknown. */
u32 func_02055d84(u32 selector)
{
    return selector == 0 ? 32768 : 65536;
}

/* Maps zero to 32 and any nonzero selector to 64; evidence is the original
 * conditional immediates. The selector's wider meaning is unknown. */
u32 func_02055d94(u32 selector)
{
    return selector == 0 ? 32 : 64;
}

/* Returns the table stride for record kind, doubled for kinds 2/8 in format 1.
 * Evidence: table 0212e2ec and word loads at +0/+0xc. */
u32 func_020558dc(const SDK557c0Record *record)
{
    u32 kind = record->kind;
    u32 stride = data_0212e2ec[kind];
    if (kind == 2 || kind == 8) {
        if (record->format == 1) stride <<= 1;
    }
    return stride;
}

/* Flushes borrowed bytes before the indexed transfer, at destination offset zero.
 * Evidence: cache provider 02006c94 followed by table 02143b70 dispatch. */
void func_0205589c(u32 index, const void *source, u32 size)
{
    func_0205410c(index);
    func_02006c94(source, size);
    data_02143b70[index](source, 0, size);
}

/* Converts slot/count to 32-byte palette units and flushes before transfer.
 * Evidence: shifts by five and main/sub providers 020046b4/02004708. */
void func_020559a0(u32 engine, u32 slot, const void *source, u32 count)
{
    u32 size = count << 5;
    func_02006c94(source, size);
    if (engine == 0) func_020046b4(source, slot << 5, size);
    else func_02004708(source, slot << 5, size);
}

/* Uploads a nonempty active map and clears its dirty bit after submission.
 * Evidence: kind/+0x1c guards, 02055874 call, byte +0x10 mask. */
void func_02055ac0(u32 index)
{
    SDK557c0Record *record = func_0205410c(index);
    if (record->kind != 0 && record->map != 0) {
        func_02055874(index, record->map);
        record->flags &= ~1;
    }
}

/* Uploads active pixel storage at slot zero, then clears dirty bit two.
 * Evidence: +0x24 source, +0x20 size and 0205590c call. */
void func_02055afc(u32 index)
{
    SDK557c0Record *record = func_0205410c(index);
    if (record->kind != 0 && record->pixels != 0) {
        func_0205590c(index, 0, record->pixels, record->size);
        record->flags &= ~2;
    }
}

/* Clears existing caller/provider-owned pixels and marks them dirty.
 * Evidence: zero-fill provider 02008848 and flag helper with mask two. */
void func_02055cb0(u32 index)
{
    SDK557c0Record *record = func_0205410c(index);
    if (record->pixels == 0) return;
    func_02008848(record->pixels, 0, record->size);
    func_02055ab0(record, 2);
}

/* Selects a page from unsigned coordinates crossing the 32-unit boundaries.
 * Evidence: unsigned comparisons and layout-three special case in original. */
u32 func_02055d4c(u32 layout, u32 x, u32 y)
{
    u32 page = 0;
    if (x > 32) {
        if (y > 32) page = 3;
        else page = 1;
    } else if (y > 32) {
        page = 1;
        if (layout == 3) page = 2;
    }
    return page;
}

/* Writes a byte only inside the layout's table-defined rectangle.
 * Evidence: 0212e310 width, 0212e328 height, row-major STRB at pixels +0x24. */
void func_02055fcc(SDK557c0Record *record, u32 x, u32 y, u32 value)
{
    u32 layout = record->layout;
    u32 width = data_0212e310[layout];
    if (x < width && y < data_0212e328[layout])
        record->pixels[y * width + x] = value;
}
