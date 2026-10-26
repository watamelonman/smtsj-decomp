#include "libs/NitroSDK/sdk_0205c1c8.h"

extern void func_02008904(const void *source, void *destination, u32 size);
extern void func_02008848(void *destination, int value, u32 size);
extern void *func_02052fe0(u32 size);
extern void func_02053000(void *allocation);
extern void func_020516d0(void *resource);

extern const char data_02143c08[];
extern const char data_02143c10[];
extern const char *func_0205ad6c(void);
extern char *func_02015134(char *destination, const char *source);
extern char *func_0201524c(char *destination, const char *source);
extern int func_020519f0(u32 *result, const char *path);
extern Unk05c1c8_Header *func_02051610(const char *path);

/** The original sets +12 to one so this wrapper borrows its resource. */
Unk05c1c8_Work *func_0205c328(Unk05c1c8_Header *resource)
{
    Unk05c1c8_Work *work = func_02052fe0(sizeof(Unk05c1c8_Work));
    func_02008848(work, 0, sizeof(Unk05c1c8_Work));
    work->resource = resource;
    work->borrowed = 1;
    func_0205c288(work, resource);
    return work;
}

/** The original ownership flag gates resource release before wrapper release. */
void func_0205c368(Unk05c1c8_Work *work)
{
    if (work->borrowed == 0)
        func_020516d0(work->resource);
    func_02053000(work);
}

/** The original uses entry +4 as byte offset and +8 as a 40-byte record count. */
u32 func_0205c390(const Unk05c1c8_Work *work, u32 index)
{
    const Unk05c1c8_Entry *entry = &work->entries[index];
    const Unk05c1c8_Record *records = (const Unk05c1c8_Record *)((const u8 *)work->resource + entry->offset);
    return records[entry->count - 1].unk_04;
}

/** The original allocates exactly 320 bytes then calls the paired clear helper. */
Unk05c1c8_Buffer *func_0205c3c0(void)
{
    Unk05c1c8_Buffer *buffer = func_02052fe0(sizeof(Unk05c1c8_Buffer));
    func_0205c3e8(buffer);
    return buffer;
}

/** Original tail call delegates buffer ownership to the existing deallocator. */
void func_0205c3dc(Unk05c1c8_Buffer *buffer)
{
    func_02053000(buffer);
}

/** Original tail call fills exactly 320 writable bytes with zero. */
void func_0205c3e8(Unk05c1c8_Buffer *buffer)
{
    func_02008848(buffer, 0, sizeof(Unk05c1c8_Buffer));
}

/** Original copies establish two unaligned-readable words, without format evidence. */
u32 func_0205c258(const void *source, u32 *output)
{
    u32 first;
    func_02008904(source, &first, 4);
    func_02008904((const u8 *)source + 4, output, 4);
    return first;
}


/** Original .cmp string and existence probe select a compressed or fallback path.
 * Caller provides enough output storage for the prefix, name and either suffix.
 */
int func_0205c1c8(char *output, const char *name, const char *suffix)
{
    u32 result[2];
    int compressed = 1;
    func_02015134(output, func_0205ad6c());
    func_0201524c(output, name);
    func_0201524c(output, data_02143c08);
    if (func_020519f0(result, output) == 0) {
        func_02015134(output, func_0205ad6c());
        func_0201524c(output, name);
        func_0201524c(output, suffix);
        compressed = 0;
    }
    return compressed;
}

/** Original .gtan suffix and zero ownership flag establish an owned resource wrapper.
 * Name plus prefix and suffix must fit the original 64-byte path buffer.
 */
Unk05c1c8_Work *func_0205c2c4(const char *name)
{
    char path[64];
    Unk05c1c8_Work *work = func_02052fe0(sizeof(Unk05c1c8_Work));
    Unk05c1c8_Header *resource;
    func_02008848(work, 0, sizeof(Unk05c1c8_Work));
    func_0205c1c8(path, name, data_02143c10);
    resource = func_02051610(path);
    work->resource = resource;
    work->borrowed = 0;
    func_0205c288(work, resource);
    return work;
}
