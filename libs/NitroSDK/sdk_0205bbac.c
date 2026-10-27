#include "types.h"

/*
 * The six functions in this translation unit fall into two clusters:
 *  - func_0205bbac/func_0205bccc submit a 32- or 512-byte-granular transfer,
 *    either through the blocking file helper or through the shared queue.
 *  - func_0205bcf8..func_0205be68 manage a 1024-entry command object whose
 *    header starts at +0x2000. The original stack frame in func_0205bbac
 *    proves the blocking context is 0x48 bytes; func_0205bcf8 clears the
 *    whole object with the literal 0x2e20.
 */

/** One 36-byte queue record, matching the shared func_0205b234 layout. */
typedef struct {
    u32 transfer[6];
    u32 unk_18;
    void *callback;
    void *argument;
} Unk05bbacTransfer;

/** Opaque 0x48-byte context owned by the func_020514xx file helpers. */
typedef struct {
    u32 words[18];
} Unk05bbacContext;

/** Eight-byte command entry; the header callback packs width/height/format. */
typedef struct {
    u32 data;
    u32 width : 11;
    u32 height : 11;
    u32 format : 4;
    u32 ready : 1;
    u32 unk_1b : 5;
} Unk05bbacEntry;

/** Command object: 1024 entries, then the header used by the helpers. */
typedef struct {
    Unk05bbacEntry entries[1024];
    u32 count;
    u32 offset;
    u32 begin;
    u32 end;
    void (*copy)(const void *source, u32 offset, u32 size);
    u32 (*size)(u32 format, u32 width, u32 height);
    u32 align;
    u8 pad_201c[0x2e20 - 0x201c];
} Unk05bbacWork;

extern void func_02008848(void *destination, int value, u32 size);
extern void func_0205b234(void *transfer, void *callback, void *argument);
extern int func_02051410(void *context, int mode);
extern u32 func_0205143c(void *context);
extern void func_0205144c(void *context, void *buffer, int mode, u32 size);
extern void func_02051430(void *context);
extern void *func_02052fe0(u32 size);
extern void func_02053000(void *buffer);
extern void func_02006c94(void *address, u32 size);
extern void func_0200551c(void);
extern void func_02005550(void *source, void *destination, u32 size);
extern void func_020055bc(void);
extern void func_02007e94(void);

/*
 * Transfer `count` units to `destination` and report the request.
 * `queued` selects the func_0205b234 queue instead of the blocking file path;
 * `blockSize` selects 32-byte units or 512-byte units. The blocking path
 * waits for the 191..213 VCOUNT window before starting the DMA helper and
 * leaves `request` with the destination and unit count. Returns 1 on success
 * and 0 when the blocking context cannot be opened.
 */
int func_0205bbac(u32 *request, int mode, void *source, int count, void *destination,
                  u8 queued, u8 blockSize)
{
    u32 unit;

    if (blockSize == 0) unit = 32;
    else unit = 512;

    if (queued == 0) {
        Unk05bbacContext context;
        void *buffer;
        u32 size;
        if (func_02051410(&context, mode) != 0) {
            size = func_0205143c(&context);
            buffer = func_02052fe0(size);
            func_0205144c(&context, buffer, 0, size);
            func_02051430(&context);
        } else {
            return 0;
        }
        while ((int)*(volatile u16 *)0x04000006 < 191 ||
               (int)*(volatile u16 *)0x04000006 > 213) {
        }
        func_0200551c();
        size = unit * count;
        func_02006c94(buffer, size);
        func_02005550(buffer, destination, size);
        func_020055bc();
        func_02053000(buffer);
    } else {
        Unk05bbacTransfer transfer;
        u32 size;
        func_02008848(&transfer, 0, 36);
        size = unit * count;
        transfer.transfer[0] = 0;
        transfer.transfer[3] = (u32)source;
        transfer.transfer[4] = (u32)destination;
        transfer.transfer[5] = size;
        func_0205b234(&transfer, 0, 0);
    }
    request[0] = (u32)destination;
    request[1] = count;
    return 1;
}

/*
 * Caller-facing wrapper: the only caller (func_0206f508) declares this void
 * and passes a 512-byte slot span, so the constant block size is 512 units.
 */
void func_0205bccc(u32 *request, int mode, void *source, int count, void *destination,
                   u8 queued)
{
    func_0205bbac(request, mode, source, count, destination, queued, 1);
}

/*
 * Clear the command object and seed its header. `begin`/`length` describe
 * the byte window, `align` is the byte alignment, `copy` moves data to an
 * entry offset and `size` maps format/width/height to a byte count.
 */
void func_0205bcf8(Unk05bbacWork *work, u32 begin, u32 length, u32 align,
                   void (*copy)(const void *source, u32 offset, u32 size),
                   u32 (*size)(u32 format, u32 width, u32 height))
{
    func_02008848(work, 0, 0x2e20);
    work->copy = copy;
    work->size = size;
    work->begin = begin;
    work->end = begin + length;
    work->align = align;
    work->offset = work->begin;
}

/*
 * Reserve the next command index when a slot remains and the transfer fits
 * in the byte window. Returns -1 on overflow; func_02007e94 reports the
 * full-object condition and is not expected to return.
 */
int func_0205bd4c(Unk05bbacWork *work, u32 format, u32 width, u32 height)
{
    u32 size = work->size(format, width, height);
    u32 index;

    index = work->count;
    if (index >= 1024) {
        func_02007e94();
        return -1;
    }
    if (work->offset + size > work->end) index = -1;
    return index;
}

/*
 * Pack width/height/format into entry `index`. Appending at the header count
 * also records the current byte offset, advances it (with alignment) and
 * increments the count; other indices only rewrite the packed fields.
 */
Unk05bbacEntry *func_0205bda4(Unk05bbacWork *work, int index, u32 format, u32 width,
                              u32 height)
{
    Unk05bbacEntry *entry = &work->entries[index];
    u32 size;

    entry->width = width;
    entry->height = height;
    entry->format = format;
    if (work->count == (u32)index) {
        size = work->size(format, width, height);
        entry->data = work->offset;
        work->offset += size;
        if (work->align != 0) {
            work->offset = (work->offset + (work->align - 1)) & ~(work->align - 1);
        }
        work->count++;
    }
    return entry;
}

/*
 * Reserve and fill one entry for `source`, flush the source range, copy it
 * through the header callback and mark the entry ready. Returns the entry
 * index, or 0 when no slot/window is available.
 */
int func_0205be68(Unk05bbacWork *work, void *source, u32 format, u32 width, u32 height)
{
    Unk05bbacEntry *entry;
    int index = func_0205bd4c(work, format, width, height);
    u32 size;

    if (index < 0) return 0;
    entry = func_0205bda4(work, index, format, width, height);
    entry->ready = 0;
    size = work->size(format, width, height);
    func_02006c94(source, size);
    work->copy(source, entry->data, size);
    entry->ready = 1;
    return index;
}
