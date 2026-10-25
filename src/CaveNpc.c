/* CaveNpc callbacks reconstructed from the ARM9 instruction and data accesses. */
#include "types.h"



/* Layout follows halfword +0, state +4, signed countdown +12, and handles +44..56. */
typedef struct CaveNpcWork {
    u16 kind;
    u16 originalKind;
    s32 state;
    s32 offset;
    s8 countdown;
    u8 pad_000d[3];
    u32 active;
    struct {
        u32 field0;
        const char *path;
        u8 pad_001c[12];
        u32 field20;
    } request;
    void *resource;
    void *handle30;
    void *handle34;
    void *handle38;
} CaveNpcWork;

/* Caller-owned 24-byte records; only the final word is accessed here. */
typedef struct CaveNpcEntry {
    u8 pad_0000[20];
    u32 value;
} CaveNpcEntry;

/* Describes count records at a byte offset from the context base. */
typedef struct CaveNpcTable {
    u32 count;
    u32 offset;
} CaveNpcTable;

/* Non-null table and base must describe a writable record buffer. */
typedef struct CaveNpcContext {
    u8 pad_0000[12];
    u8 *base;
    CaveNpcTable *table;
} CaveNpcContext;

extern u8 data_02151180[];
void *func_0205ba98(u32 heap, u32 size, const void *source, u32 line);
void func_02061424(CaveNpcWork *work);
void func_0205c3dc(void *handle);
void func_0205c368(void *handle);
void func_0205ddb4(void *handle);
void func_0205bb68(void);
int func_0205b36c(void *request);
void Unk05ae50_Unk_05af3c(void *request);
void func_0205de30(void *handle, int index, void *resource);
void func_0205caa8(void *handle, int index);
void func_0205c704(void *handle);
void func_02057524(int mode);
void Unk0de678_GetPair(s8 *pair);
void func_02057eb8(int value);
void func_02057fd8(void);
void func_02057ddc(u32 color);
void func_0205c748(int screen, void *handle, int x, int y,
                  float sx, float sy, int rotation, float alpha, int priority);
void func_02057df8(void);
void func_02057e18(int value);
void func_020572d8(void);

/* +16 is the activation latch; setting it starts the +12 five-frame countdown. */
void CaveNpc_SetActive(CaveNpcWork *work, int active)
{
    if (active != 0) {
        if (work->active != 0) return;
        work->countdown = 5;
        work->active = 1;
    } else {
        work->active = 0;
    }
}

/* Releases the three observed handles before freeing the work; kind 604 bypasses them. */
void func_020ffebc(CaveNpcWork *work)
{
    if (work == 0) return;
    if (work->kind == 604) {
        func_02061424(work);
        return;
    }
    if (work->handle38 != 0) {
        func_0205c3dc(work->handle38);
        work->handle38 = 0;
    }
    if (work->handle34 != 0) {
        func_0205c368(work->handle34);
        work->handle34 = 0;
    }
    if (work->handle30 != 0) {
        func_0205ddb4(work->handle30);
        work->handle30 = 0;
    }
    func_0205bb68();
    work->resource = 0;
    func_02061424(work);
}

/* Empty callback: the original consists solely of a return. */
void CaveNpc_Nop_0fff3c(void) { }

/* Polls the +20 request, then advances state and updates the +56 handle each frame. */
void func_020fff40(CaveNpcWork *work)
{
    if (work->kind == 604) return;
    switch (work->state) {
    case 0:
        if (func_0205b36c(&work->request) == 0) return;
        Unk05ae50_Unk_05af3c(&work->request);
        func_0205de30(work->handle30, 0, work->resource);
        func_0205caa8(work->handle38, 0);
        work->state = 1;
        break;
    case 1:
        if (work->countdown > 0) --work->countdown;
        func_0205c704(work->handle38);
        break;
    }
}

/* Draws the +56 handle using signed pair offsets; +12 controls the active tint ramp. */
void func_020fffc8(CaveNpcWork *work)
{
    s8 pair[2];
    u8 shade;
    if (work->kind == 604) return;
    func_02057524(4);
    switch (work->state) {
    case 0:
        break;
    case 1:
        Unk0de678_GetPair(pair);
        func_02057eb8(-1);
        func_02057fd8();
        if (work->active != 0) {
            shade = 76;
            if (work->countdown > 0) shade = 76 + work->countdown * 179 / 5;
            func_02057ddc(((shade << 24) & 0xff000000) +
                         ((shade << 16) & 0x00ff0000) +
                         ((shade << 8) & 0x0000ff00) + 255);
        }
        func_0205c748(1, work->handle38, work->offset + pair[0], pair[1] + 8,
                      1.0f, 1.0f, 0, 1.0f, 0);
        func_02057df8();
        func_02057e18(31);
        break;
    }
    func_020572d8();
}

/* Lazily allocates +44; the original embeds the source/line pair data_02151180:286. */
void CaveNpc_Unk_1000d0(CaveNpcWork *work)
{
    if (work->resource != 0) return;
    work->resource = func_0205ba98(0x2000, 0x200, data_02151180, 0x11e);
}

/* View of the +8 position field shared by the update and drawing callbacks. */
typedef struct CaveNpcList {
    u8  pad_0000[8];
    s32 scrollY;                /* +0x08 */
} CaveNpcList;

/* Writes +8 using the observed 34/68 spacing; unsupported row/count pairs preserve it. */
void func_02100104(CaveNpcList *list, int row, u32 count)
{
    switch (count) {
    case 0:
        break;
    case 1:
        list->scrollY = 0;
        break;
    case 2:
        if (row == 0) {
            list->scrollY = -0x22;
        } else {
            list->scrollY = 0x22;
        }
        break;
    case 3:
        switch (row) {
        case 0:
            list->scrollY = -0x44;
            break;
        case 1:
            list->scrollY = 0;
            break;
        case 2:
            list->scrollY = 0x44;
            break;
        }
        break;
    case 4:
        switch (row) {
        case 0:
            list->scrollY = -0x44;
            break;
        case 1:
            list->scrollY = 0;
            break;
        case 2:
            list->scrollY = 0x44;
            break;
        case 3:
            list->scrollY = 0;
            break;
        }
        break;
    }
}

/* Clears +20 in each 24-byte record; table count and offset bound the caller-owned buffer. */
void func_021001cc(CaveNpcContext *context)
{
    CaveNpcTable *table = context->table;
    CaveNpcEntry *entry = (CaveNpcEntry *)(context->base + table->offset);
    u32 i;
    u32 count = table->count;
    for (i = 0; i < count; ++i, ++entry) entry->value = 0;
}

extern const char data_02151118[], data_02151128[], data_02151148[];
extern const char data_02151158[], data_0215116c[];
CaveNpcWork *func_020611dc(void (*update)(CaveNpcWork *),
                         void (*draw)(CaveNpcWork *), void (*release)(CaveNpcWork *),
                         void (*callback)(void), u32 size, u32 arg5, u32 arg6, u32 arg7);
void Unk02e000_Unk_02e0cc(void);
int func_02013c3c(char *buffer, const char *format, ...);
int func_020513d4(const char *path);
void func_0205ae60(void *request);
void func_0205b398(void *resource, void *request);
CaveNpcContext *func_0205dcd4(const char *path, int mode);
void *func_0205c2c4(const char *path);
void *func_0205c3c0(void *resource);
void func_0205c3fc(void *handle, void *data, void *resource);

/* Allocates 60-byte work and initializes kind-specific resources and callbacks.
 * Evidence: +0/+2 kind stores, formatted paths, and +44..56 handle setup.
 * Returns null on allocation failure; kind 604 bypasses resource initialization.
 */
CaveNpcWork *func_020ffd48(u16 kind, int row, u32 count)
{
    char path[64];
    char checkPath[64];
    CaveNpcWork *work = func_020611dc(func_020fff40, func_020fffc8, 0,
                                    CaveNpc_Nop_0fff3c, 60, 0, 0, 1);
    if (work != 0) {
        work->originalKind = kind;
        work->kind = kind;
        if (work->kind == 604) return work;
        CaveNpc_Unk_1000d0(work);
        Unk02e000_Unk_02e0cc();
        func_02013c3c(path, data_02151118, work->kind);
        func_02013c3c(checkPath, data_02151128, work->kind);
        if (func_020513d4(checkPath) == 0) {
            work->kind = 600;
            func_02013c3c(path, data_02151148, work->kind);
        }
        work->request.path = path;
        work->request.field20 = 0;
        func_0205ae60(&work->request);
        func_0205b398(work->resource, &work->request);
        func_02013c3c(path, data_02151158, work->kind);
        work->handle30 = func_0205dcd4(path, 0);
        func_021001cc(work->handle30);
        func_02013c3c(path, data_0215116c, work->kind);
        work->handle34 = func_0205c2c4(path);
        work->handle38 = func_0205c3c0(work->handle34);
        func_0205c3fc(work->handle38, work->handle30, work->handle34);
        func_02100104((CaveNpcList *)work, row, count);
        work->active = 0;
        work->countdown = 0;
        work->state = 0;
    }
    return work;
}
