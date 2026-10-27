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
typedef struct Unk051378Decoder Unk051378Decoder;

typedef struct Unk051378Work {
    u8 pad_00[0xc];
    u32 flags;
    u8 pad_10[0x14];
    u32 unk_24;
    u32 unk_28;
    u32 cursor;
    u8 pad_30[0x18];
    void *unk_48;
    Unk051378Decoder *unk_4c;
    void *chunk;
    u32 unk_54;
    u16 blocks;
    u8 state;
    char name[29];
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

/* Caller-owned streaming decoder; +4 is the SDK decoder context. */
struct Unk051378Decoder {
    u32 kind;
    u32 context[135];
};

extern void func_02007e94(void);
extern void func_02008a9c(const void *source, void *destination);
extern void func_02008b9c(const void *source, void *destination);
extern void func_02008c94(const void *source, void *destination);
extern void func_02008d00(const void *source, void *destination);
extern void func_02008dfc(void *context, void *destination, const u32 *header);
extern void func_02008e44(void *context, void *destination, const u32 *header);
extern void func_02008dd4(void *context, void *destination, const u32 *header);
extern int func_02008f40(void *context, const void *source, int size);
extern int func_020090c4(void *context, const void *source, int size);
extern int func_02008e8c(void *context, const void *source, int size);
extern void func_020059a8(u32 mask);
extern void func_0200ba60(int mode);
extern int func_0200c1b8(void *buffer, int size);
extern void *data_0215f038;

/* Initializes filesystem IRQ support and its allocated work buffer. Evidence:
 * the same provider is called first to size and then to install the buffer. */
void func_02051378(void)
{
    int size;
    func_020059a8(1);
    func_020059a8(0x40000);
    (void)*(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 1;
    func_0200ba60(3);
    size = func_0200c1b8(0, 0);
    data_0215f038 = func_02052fe0(size);
    func_0200c1b8(data_0215f038, size);
}

/* Dispatches whole-buffer decompression by the header's format nibble;
 * source and destination are borrowed for the synchronous provider call. */
void func_0205148c(const u32 *source, void *destination)
{
    switch ((int)(*source & 0xf0)) {
    case 0x10: func_02008a9c(source, destination); break;
    case 0x20: func_02008b9c(source, destination); break;
    case 0x30: func_02008c94(source, destination); break;
    case 0x80: func_02008d00(source, destination); break;
    default: func_02007e94(); break;
    }
}

/* Recognizes the four header format nibbles accepted by the dispatcher. */
int func_020514f4(u32 header)
{
    switch (*(int *)&header & 0xf0) {
    case 0x10: case 0x20: case 0x30: case 0x80: return 1;
    default: return 0;
    }
}

/* Initializes a caller-owned incremental decoder from the resource header. */
int func_02051548(Unk051378Decoder *decoder, void *destination, const u32 *header)
{
    decoder->kind = *header & 0xf0;
    switch (decoder->kind) {
    case 0x10: func_02008dfc(decoder->context, destination, header); break;
    case 0x20: func_02008e44(decoder->context, destination, header); break;
    case 0x30: func_02008dd4(decoder->context, destination, header); break;
    default: func_02007e94(); return 0;
    }
    return 1;
}

/* Supplies a borrowed input chunk and returns the decoder's remaining count. */
int func_020515ac(Unk051378Decoder *decoder, const void *source, int size)
{
    int result = 0;
    switch (decoder->kind) {
    case 0x10: result = func_02008f40(decoder->context, source, size); break;
    case 0x20: result = func_020090c4(decoder->context, source, size); break;
    case 0x30: result = func_02008e8c(decoder->context, source, size); break;
    default: func_02007e94(); break;
    }
    return result;
}

extern void func_02008848(void *destination, int value, u32 size);
extern char *func_02015450(const char *text, int character);
extern int func_02013c14(char *destination, u32 size, const char *format, const char *text);
extern const char data_021437d8[];
extern void *func_02052ff0(u32 size);
extern int func_0200bef4(Unk051378Work *work, void *destination, int size);

/* Opens a streaming resource and reserves incremental decoder storage when
 * its header is compressed. Buffer ownership follows func_020517f8. */
int func_020516dc(Unk051378Work *work, const char *path, void *buffer, int size)
{
    const char *name;
    int opened;
    func_02008848(work, 0, 120);
    func_0200ba88((Unk051378File *)work);
    work->state = 0;
    work->unk_48 = buffer;
    work->unk_4c = 0;
    work->chunk = 0;
    work->blocks = 0;
    name = func_02015450(path, '/');
    if (name == 0) name = path;
    else name++;
    func_02013c14(work->name, 28, data_021437d8, name);
    opened = func_02051410((Unk051378File *)work, path);
    if (opened) {
        func_0205147c((Unk051378File *)work, &work->unk_54, 0);
        if (func_020514f4(work->unk_54)) {
            if (size == 0) size = 5120;
            else if (size < 0) size = (func_0205143c(work) + 1023) & ~1023;
            work->blocks = size >> 10;
            if (work->blocks == 0) work->blocks = 1;
            work->unk_4c = func_02052ff0((work->blocks << 10) + 544);
            work->chunk = (u8 *)work->unk_4c + 544;
        } else {
            func_0200bf14((Unk051378File *)work, 0, 0);
        }
    }
    return opened;
}

/* Advances the stream state, reading bounded chunks and closing/releasing
 * decoder storage at completion. The destination remains caller-owned. */
int func_02051844(Unk051378Work *work, int size)
{
    int success = 1;
    switch (work->state) {
    case 0:
        if (work->unk_4c) {
            func_020517f8(work);
            func_02051548(work->unk_4c, work->unk_48, &work->unk_54);
            work->state = 1;
        } else if (size <= 0) {
            size = func_020517f8(work);
            if (func_0200bef4(work, work->unk_48, size) < 0) success = 0;
            else work->state = 3;
        } else {
            func_020517f8(work);
            work->state = 2;
        }
        break;
    case 2:
        if (work->cursor - work->unk_24 == work->unk_28 - work->unk_24) {
            work->state = 4;
            break;
        }
        if (func_0200bef4(work, (u8 *)work->unk_48 + (work->cursor - work->unk_24), size) < 0)
            success = 0;
        else work->state = 3;
        break;
    case 1:
        if (size < 0 || size > (work->blocks << 10)) size = work->blocks << 10;
        size = func_0200bf04((Unk051378File *)work, work->chunk, size);
        if (size < 0) success = 0;
        if (func_020515ac(work->unk_4c, work->chunk, size) == 0) work->state = 4;
        break;
    case 3:
        if (((work->flags & 1) ? success : 0) == 0) {
            if (work->cursor - work->unk_24 == work->unk_28 - work->unk_24) work->state = 4;
            else work->state = 2;
        }
        break;
    case 4:
        func_02051430((Unk051378File *)work);
        func_02053000(work->unk_4c);
        work->unk_4c = 0;
        return 0;
    }
    if (success) return 1;
    func_02007e94();
    return 0;
}
