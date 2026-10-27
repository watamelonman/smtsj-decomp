#include "types.h"

/* NitroSDK file context. The helpers initialized here write through +0x1c and
 * func_0200bc70 reserves the same 0x48-byte frame, so the layout is opaque. */
typedef struct Unk051378File {
    u32 words[18];
} Unk051378File;

/* Streaming work object touched by func_020517f8. The +0x24/+0x28 span and
 * +0x48 buffer field are established by func_02051844, which is the only
 * caller: it compares its cursor at +0x2c against that same span and reads
 * through the buffer func_020517f8 installs at +0x48. */
typedef struct Unk051378Work {
    u8 pad_00[0x24];
    u32 unk_24;
    u32 unk_28;
    u8 pad_2c[0x1c];
    void *unk_48;
    u32 unk_4c;
    u8 pad_50[4];
    u32 unk_54;
} Unk051378Work;

extern void func_0200ba88(Unk051378File *file);
extern int func_0200bd68(Unk051378File *file, const char *path);
extern int func_0200bdb0(Unk051378File *file);
extern int func_0200bf14(Unk051378File *file, u32 offset, u32 origin);
extern int func_0200bf04(Unk051378File *file, void *buffer, u32 size);
extern void *func_02052fe0(u32 size);
extern void func_02053000(void *allocation);

/* Probes whether `path` can be opened: initializes a stack file context, opens
 * it, closes it again when the open succeeded and returns that success flag.
 * Evidence: the open helper parses '/' and '\\' from its second argument, and
 * callers such as func_0208df48 use the result purely as an existence test. */
int func_020513d4(const char *path)
{
    Unk051378File file;
    int opened;

    func_0200ba88(&file);
    opened = func_0200bd68(&file, path);
    if (opened != 0)
        func_0200bdb0(&file);
    return opened;
}

/* Initializes a file context and opens `path` in it. Returns the open helper's
 * success flag; the context storage belongs to the caller. */
int func_02051410(Unk051378File *file, const char *path)
{
    func_0200ba88(file);
    return func_0200bd68(file, path);
}

/* Closes a file context. Kept as a tail-call wrapper so callers own the
 * context's lifetime, as in lib_0205f1d8.c. */
void func_02051430(Unk051378File *file)
{
    func_0200bdb0(file);
}

/* Returns the byte span between the work's end (+0x28) and base (+0x24)
 * fields; func_02051844 uses it as the total length of the stream. */
u32 func_0205143c(Unk051378Work *work)
{
    return work->unk_28 - work->unk_24;
}

/* Seeks `file` to `offset` measured from the start (`origin` 0) and reads
 * `size` bytes into `buffer`. Evidence: func_0205bbac calls it with 0 to load
 * the whole resource after sizing it with func_0205143c. */
void func_0205144c(Unk051378File *file, void *buffer, u32 offset, u32 size)
{
    func_0200bf14(file, offset, 0);
    func_0200bf04(file, buffer, size);
}

/* Reads one 32-bit word at `offset`; evidence: func_0205f5f0 shifts the result
 * right by 8 and the tail call passes the constant 4 as the read size. */
void func_0205147c(Unk051378File *file, void *buffer, u32 offset)
{
    func_0205144c(file, buffer, offset, 4);
}

/* Releases an allocation through func_02053000. Evidence: the other NitroSDK
 * units pair func_02052fe0 allocations with this call (sdk_0205c1c8.c). */
void func_020516d0(void *allocation)
{
    func_02053000(allocation);
}

/* Installs the stream's read buffer at +0x48 and returns its size, or returns 0
 * when the buffer already exists. The size is the +0x54 field in 256-byte units
 * when the +0x4c file object is present, otherwise the +0x24/+0x28 span.
 * Evidence: func_02051844 allocates through this call before reading and later
 * passes the returned size to func_02051548/func_020515ac. */
u32 func_020517f8(Unk051378Work *work)
{
    u32 size;

    if (work->unk_48 == 0) {
        if (work->unk_4c != 0)
            size = work->unk_54 >> 8;
        else
            size = func_0205143c(work);
        work->unk_48 = func_02052fe0(size);
        return size;
    }
    return 0;
}
