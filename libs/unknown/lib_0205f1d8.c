#include "libs/unknown/lib_0205f1d8.h"

/* NitroSDK file helpers; the context size and the open/read/close split are
 * established by libs/NitroSDK/sdk_0205bbac.c, which uses the same trio. */
extern void func_0200ba88(Unk05f1d8File *file);
extern int func_0200bcf8(Unk05f1d8File *file, u32 archive, u32 fileId);
extern int func_02051410(Unk05f1d8File *file, const char *name);
extern void func_0205144c(Unk05f1d8File *file, void *buffer, u32 offset, u32 size);
extern void func_0205147c(Unk05f1d8File *file, void *buffer, u32 offset);
extern void func_0205148c(void *buffer, u32 argument);
extern void func_02051430(Unk05f1d8File *file);
extern void func_02008904(void *destination, const void *source, u32 size);
extern void *func_02052fe0(u32 size);
extern void func_02053000(void *allocation);

/* Resolves an archive-relative path into a file locator. Evidence: func_02095a60
 * passes the resulting 12-byte record to func_0205f534, which uses its first two
 * words as func_0200bcf8's archive/file arguments and its third as the offset. */
extern int func_0200bc70(Unk05f1d8Locator *locator, const char *source);

/* Offset of entry `index` inside the resource payload: the data offset plus the
 * sizes of all preceding entries. Forward declaration for func_0205f41c; the
 * definition sits below the size accessors. */
extern u32 func_0205f3b0(Unk05f1d8Resource *resource, u32 index);

/* Appends `size` bytes from `source` to the stream and returns 1. A set status
 * word at +0xc starts a new block: it is cleared and the cursor is advanced by
 * one reserved byte. A null source returns 0; a null storage pointer skips the
 * copy (and the capacity check) but still advances the cursor by `size`; a
 * block that would pass the capacity returns 0 without copying. */
u32 func_0205f1d8(Unk05f1d8Stream *stream, const void *source, u32 size)
{
    u32 valid;

    if (source == 0)
        return 0;
    if (stream->unk_0c != 0) {
        stream->unk_0c = 0;
        stream->offset++;
    }
    if (stream->buffer != 0) {
        valid = stream->offset + size <= stream->capacity;
        if (valid == 0)
            return 0;
        func_02008904(stream->buffer + stream->offset, source, size);
    }
    stream->offset += size;
    return 1;
}

/* Reads `size` bytes from the stream into `destination` and returns 1. It uses
 * the same status-word and capacity rules as func_0205f1d8: a set status word
 * is cleared and reserves one cursor byte, a null destination returns 0, and a
 * null storage pointer skips the copy but still advances the cursor. */
u32 func_0205f25c(Unk05f1d8Stream *stream, void *destination, u32 size)
{
    u32 valid;

    if (destination == 0)
        return 0;
    if (stream->unk_0c != 0) {
        stream->unk_0c = 0;
        stream->offset++;
    }
    if (stream->buffer != 0) {
        valid = stream->offset + size <= stream->capacity;
        if (valid == 0)
            return 0;
        func_02008904(destination, stream->buffer + stream->offset, size);
    }
    stream->offset += size;
    return 1;
}

/* Number of entries in an FBIN resource, or 0 when the pointer is null or does
 * not carry the FBIN magic. Callers use it as the loop bound for indexed
 * lookups (ImageBgDual3D, unit_0206ea70, unit_020aa118). */
u32 func_0205f2e4(Unk05f1d8Resource *resource)
{
    u32 valid;

    if (resource == 0)
        return 0;
    valid = resource->magic == UNK05F1D8_MAGIC;
    if (valid == 0)
        return 0;
    return resource->count;
}

/* Byte offset of the first entry's payload, or 0 for an invalid resource.
 * func_0205f460 returns it after reading just the 12-byte header from disk, so
 * an initial load can reserve the whole header/size-table block. */
u32 func_0205f318(Unk05f1d8Resource *resource)
{
    if (resource == 0)
        return 0;
    if (resource->magic == UNK05F1D8_MAGIC)
        return resource->dataOffset;
    return 0;
}

/* Start of the per-entry size table, or null for an invalid resource.
 * func_0205f374 indexes the returned table after a count check. */
u32 *func_0205f340(Unk05f1d8Resource *resource)
{
    u32 valid;

    if (resource == 0)
        return 0;
    valid = resource->magic == UNK05F1D8_MAGIC;
    if (valid == 0)
        return 0;
    return resource->sizes;
}

/* Payload size of entry `index`, or 0 when the resource is invalid or the index
 * is not below the entry count. The bounds test is unsigned, so negative indices
 * also fail. */
u32 func_0205f374(Unk05f1d8Resource *resource, u32 index)
{
    u32 *sizes;
    u32 valid;

    sizes = func_0205f340(resource);
    if (sizes == 0)
        return 0;
    valid = resource->count > index;
    if (valid == 0)
        return 0;
    return sizes[index];
}

/* Byte offset of entry `index` inside the fully loaded resource's payload:
 * the header's data offset plus the sizes of all preceding entries. Returns 0
 * for an invalid resource or an out-of-range index. func_0205f41c adds this to
 * the resource base; func_0205f5f0 and func_0205f668 seek to it on disk. */
u32 func_0205f3b0(Unk05f1d8Resource *resource, u32 index)
{
    u32 *sizes;
    u32 sum;
    u32 i;
    u32 valid;

    sizes = func_0205f340(resource);
    if (sizes == 0)
        return 0;
    valid = resource->count > index;
    if (valid == 0)
        return 0;
    sum = 0;
    for (i = 0; i < index; i++)
        sum += sizes[i];
    return sum + func_0205f318(resource);
}

/* Pointer to entry `index`'s payload inside a fully loaded resource, or null for
 * an invalid resource. The original does not range-check `index`; callers such
 * as ImageBgDual3D and unit_020a163c iterate below func_0205f2e4's count. */
u8 *func_0205f41c(Unk05f1d8Resource *resource, u32 index)
{
    u32 valid;

    if (resource == 0)
        return 0;
    valid = resource->magic == UNK05F1D8_MAGIC;
    if (valid == 0)
        return 0;
    return (u8 *)resource + func_0205f3b0(resource, index);
}

/* Reads only the 12-byte FBIN header of `name` and returns its data offset, or 0
 * when the file cannot be opened. unit_02044394 uses the result as the size of
 * the cached header block. */
u32 func_0205f460(const char *name)
{
    Unk05f1d8File file;
    Unk05f1d8Header header;

    if (func_02051410(&file, name) == 0)
        return 0;
    func_0205144c(&file, &header, 0, sizeof(header));
    func_02051430(&file);
    return func_0205f318((Unk05f1d8Resource *)&header);
}

/* Reads `size` bytes from offset 0 of `name` into `buffer`; returns 0 only when
 * the file cannot be opened and 1 after the read. unit_02044394 uses it to cache
 * the header block whose length came from func_0205f460. */
u32 func_0205f4b0(const char *name, void *buffer, u32 size)
{
    Unk05f1d8File file;

    if (func_02051410(&file, name) == 0)
        return 0;
    func_0205144c(&file, buffer, 0, size);
    func_02051430(&file);
    return 1;
}

/* Fills the 12-byte locator from `source`: clears the offset at +8 and resolves
 * the archive/file identity through func_0200bc70, returning its success flag.
 * func_02095a60 uses the locator with func_0205f534/func_0205f590/func_0205f668. */
int func_0205f508(Unk05f1d8Locator *locator, const char *source)
{
    if (locator == 0)
        return 0;
    if (source == 0)
        return 0;
    locator->offset = 0;
    return func_0200bc70(locator, source);
}

/* Opens the file named by `locator`, reads only the 12-byte FBIN header and
 * returns its data offset (the header plus size-table length), or 0 when the
 * locator cannot be opened. func_02095a60 passes the result to func_0205f590
 * as the size of the block to load. */
u32 func_0205f534(Unk05f1d8Locator *locator)
{
    Unk05f1d8File file;
    Unk05f1d8Header header;

    func_0200ba88(&file);
    if (func_0200bcf8(&file, locator->archive, locator->file) == 0)
        return 0;
    func_0205144c(&file, &header, locator->offset, sizeof(header));
    func_02051430(&file);
    return func_0205f318((Unk05f1d8Resource *)&header);
}

/* Reads `size` bytes from the locator's current offset into `buffer` and
 * returns 1; a failed open returns 0. func_02095a60 loads the header block
 * that func_0205f534 sized. */
u32 func_0205f590(Unk05f1d8Locator *locator, void *buffer, u32 size)
{
    Unk05f1d8File file;

    func_0200ba88(&file);
    if (func_0200bcf8(&file, locator->archive, locator->file) == 0)
        return 0;
    func_0205144c(&file, buffer, locator->offset, size);
    func_02051430(&file);
    return 1;
}

/* Reads the first four bytes of entry `index` at the locator's offset plus
 * func_0205f3b0's entry offset and returns the word shifted right by 8, or 0
 * when the locator cannot be opened. The caller in unit_02095a60 discards the
 * result, so the shifted field has no independently proven meaning and the
 * function keeps a neutral name. */
u32 func_0205f5f0(Unk05f1d8Locator *locator, Unk05f1d8Resource *resource,
                  u32 index)
{
    Unk05f1d8File file;
    u32 word;
    u32 value;

    func_0200ba88(&file);
    if (func_0200bcf8(&file, locator->archive, locator->file) == 0)
        return 0;
    func_0205147c(&file, &word,
                  locator->offset + func_0205f3b0(resource, index));
    value = word >> 8;
    func_02051430(&file);
    return value;
}

/* Loads entry `index` into a buffer allocated with func_0205f374's entry size,
 * passes it to func_0205148c together with `argument` (the caller's output
 * allocation; func_0205148c dispatches on the block's format byte), frees the
 * temporary buffer and returns 1; a failed open returns 0. func_02095a60 uses
 * it to materialise the selected entry. */
u32 func_0205f668(Unk05f1d8Locator *locator, Unk05f1d8Resource *resource,
                  u32 index, u32 argument)
{
    Unk05f1d8File file;
    u32 entryOffset;
    u32 fileOffset;
    u32 readOffset;
    u32 size;
    void *buffer;

    func_0200ba88(&file);
    if (func_0200bcf8(&file, locator->archive, locator->file) == 0)
        return 0;
    entryOffset = func_0205f3b0(resource, index);
    fileOffset = locator->offset;
    readOffset = fileOffset + entryOffset;
    size = func_0205f374(resource, index);
    buffer = func_02052fe0(size);
    func_0205144c(&file, buffer, readOffset, size);
    func_02051430(&file);
    func_0205148c(buffer, argument);
    func_02053000(buffer);
    return 1;
}
