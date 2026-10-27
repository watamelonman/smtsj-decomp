#include "libs/unknown/lib_0205f1d8.h"

/* NitroSDK file helpers; the context size and the open/read/close split are
 * established by libs/NitroSDK/sdk_0205bbac.c, which uses the same trio. */
extern int func_02051410(Unk05f1d8File *file, const char *name);
extern void func_0205144c(Unk05f1d8File *file, void *buffer, u32 offset, u32 size);
extern void func_02051430(Unk05f1d8File *file);

/* Resolves an archive-relative path into a file locator. Evidence: func_02095a60
 * passes the resulting 12-byte record to func_0205f534, which uses its first two
 * words as func_0200bcf8's archive/file arguments and its third as the offset. */
extern int func_0200bc70(Unk05f1d8Locator *locator, const char *source);

/* Offset of entry `index` inside the resource payload: the data offset plus the
 * sizes of all preceding entries. Defined by the sibling card for this TU. */
extern u32 func_0205f3b0(Unk05f1d8Resource *resource, u32 index);

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
