#include "libs/NitroSDK/sdk_0205dacc.h"

extern void func_02008904(const void *source, void *destination, u32 size);
extern void func_02008848(void *destination, int value, u32 size);
extern void *func_02052fe0(u32 size);
extern void func_02053000(void *allocation);
extern void func_020516d0(void *resource);
extern Unk05dacc_Resource *func_02051610(const char *path);
extern int func_020152cc(const char *left, const char *right);
extern u32 func_0205aa68(void);
extern void *func_0205a99c(u32 index);

extern const char data_02143c20[];

/** Reads the record id and copies the following word into caller storage. */
u32 func_0205db5c(const void *record, u32 *offset)
{
    u32 id;
    func_02008904(record, &id, 4);
    func_02008904((const u8 *)record + 4, offset, 4);
    return id;
}

/** Appends the entry and advances the count; the table is sized by the resource. */
void func_0205dbf0(Unk05dacc_Handle *handle, Unk05dacc_Item *item)
{
    handle->items[handle->count] = item;
    handle->count = handle->count + 1;
}

/** The original binds the group first and derives both byte pointers from +0x14. */
void func_0205dc0c(Unk05dacc_Handle *handle, Unk05dacc_Group *group)
{
    u32 count;

    handle->group = group;
    count = group->count;
    handle->groupBegin = group->entries;
    handle->groupEnd = group->entries + count * 8;
}

/** Scans the loaded registry and installs the first ready entry with a matching name. */
int func_0205db8c(Unk05dacc_Item *item)
{
    u32 i;

    for (i = 0; i < func_0205aa68(); i++) {
        Unk05dacc_RegistryEntry *entry = func_0205a99c(i);
        if (entry->ready != 0 && func_020152cc(entry->name, item->name) == 0) {
            item->output = entry;
            return 1;
        }
    }
    return 0;
}

/** Loads the named resource; the wrapper owns it because +0x18 stays zero. */
Unk05dacc_Handle *func_0205dcd4(const char *name, u32 mode)
{
    char path[64];
    Unk05dacc_Resource *resource;
    Unk05dacc_Handle *handle;

    func_0205dacc(path, name, data_02143c20);
    resource = func_02051610(path);
    handle = func_02052fe0(sizeof(Unk05dacc_Handle));
    func_02008848(handle, 0, sizeof(Unk05dacc_Handle));
    handle->resource = resource;
    handle->borrowed = 0;
    handle->items = func_02052fe0(handle->resource->count * 4);
    func_0205dc28(handle, resource, mode);
    return handle;
}

/** The original sets +0x18 to one so this wrapper borrows its resource. */
Unk05dacc_Handle *func_0205dd58(Unk05dacc_Resource *resource, u32 mode)
{
    Unk05dacc_Handle *handle = func_02052fe0(sizeof(Unk05dacc_Handle));
    func_02008848(handle, 0, sizeof(Unk05dacc_Handle));
    handle->resource = resource;
    handle->borrowed = 1;
    handle->items = func_02052fe0(handle->resource->count * 4);
    func_0205dc28(handle, resource, mode);
    return handle;
}

/** The original ownership flag gates resource release before table and wrapper release. */
void func_0205ddb4(Unk05dacc_Handle *handle)
{
    if (handle->borrowed == 0)
        func_020516d0(handle->resource);
    func_02053000(handle->items);
    func_02053000(handle);
}

/** Resolves each table entry in order; entries already bound are simply rewritten. */
void func_0205dde4(Unk05dacc_Handle *handle)
{
    u32 i;

    for (i = 0; i < handle->count; i++)
        func_0205db8c(handle->items[i]);
}
