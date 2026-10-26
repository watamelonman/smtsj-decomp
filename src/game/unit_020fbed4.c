#include "types.h"

/* Each entry has a 96-byte stride; only the trailing control fields are known. */
typedef struct Entry0fbed4 {
    u8 unk_00[0x5a];
    u16 unk_5a;
    u8 unk_5c;
    u8 flag;
    u8 pad_5e[2];
} Entry0fbed4;

/* Only fields accessed by this unit are exposed; handle ownership stays with work. */
typedef struct Handle0fbed4 {
    u8 unk_00[0x2c];
    s32 unk_2c;
    u8 unk_30[7];
    u8 unk_37;
} Handle0fbed4;

/* Resource descriptor returned by the id-6 lookup; offset 0x24 supplies the buffer. */
typedef struct Descriptor0fbed4 {
    s32 available;
    u8 unk_04[0x20];
    void *buffer;
} Descriptor0fbed4;

/* Private layout follows the word and halfword accesses in this unit. */
typedef struct Work0fbed4 {
    s32 frame;
    s32 state;
    void *buffer;
    void *resource;
    Entry0fbed4 entries[108];
    s32 unk_2890[5];
    void *unk_28a4;
    void *unk_28a8;
    void *unk_28ac;
    Handle0fbed4 *handle;
    s16 offset;
    u8 pad_28b6[2];
    s32 unk_28b8;
    s32 ready;
} Work0fbed4;

/* Callback slots retain their observed offsets, including the unused word at 8. */
typedef struct Callbacks0fbed4 {
    s32 size;
    s32 flags;
    s32 unk_08;
    void (*update)(Work0fbed4 *);
    void (*nop)(void);
    void (*draw)(Work0fbed4 *);
    void (*unk_18)(Work0fbed4 *);
    void (*cleanup)(Work0fbed4 *);
    void (*event)(Work0fbed4 *, const s32 *);
} Callbacks0fbed4;

extern Work0fbed4 *data_02176e10;
void func_020fc180(Work0fbed4 *work);
void func_020fc238(Work0fbed4 *work);
void func_020fc3a0(Work0fbed4 *work);
void func_020fc408(Work0fbed4 *work, const s32 *event);
void Unk0fbed4_Nop_0fc17c(void);
void func_020516d0(void *resource);
void func_020629c4(void *handle);
s32 Unk0cb32c_Unk_0cb54c(void);
void func_0205fc10(void *handle, s32 value);
s32 func_020a4f3c(void);
void func_020bc9f4(s32 id, s32 value);
void Unk0bc1a8_Unk_0bc504(Work0fbed4 *work, s32 value);
void Unk0a4e48_Unk_0a4e9c(s32 value);
void func_0203f960(void *buffer, s32 x, s32 y, s32 width, s32 height, s32 value);

/* Register callbacks and the 0x28c0-byte work size; the stores establish slot roles. */
void func_020fc124(Callbacks0fbed4 *callbacks)
{
    callbacks->size = 0x28c0;
    callbacks->flags = 4;
    callbacks->update = func_020fc180;
    callbacks->nop = Unk0fbed4_Nop_0fc17c;
    callbacks->draw = func_020fc238;
    callbacks->unk_18 = 0;
    callbacks->cleanup = func_020fc3a0;
    callbacks->event = func_020fc408;
}

/* Empty callback: the original consists solely of the return instruction. */
void Unk0fbed4_Nop_0fc17c(void) { }

/* Wait for readiness, configure the first-frame handle, and advance the state counter. */
void func_020fc180(Work0fbed4 *work)
{
    switch (work->state) {
    case 0:
        if (work->ready == 0) return;
        if (work->frame == 0 && work->unk_28b8 == 0 && Unk0cb32c_Unk_0cb54c()) {
            func_0205fc10(work->handle, 1);
            work->handle->unk_2c = 189;
            work->handle->unk_37 = 5;
        }
        if (func_020a4f3c() == 0) work->state = 1;
        break;
    case 1:
        break;
    case 2:
        if (func_020a4f3c() == 0) work->state = 1;
        break;
    }
    work->frame++;
}

/* Release the four resources and optional handle, then clear the global work pointer. */
void func_020fc3a0(Work0fbed4 *work)
{
    func_020516d0(work->resource);
    func_020516d0(work->unk_28a4);
    func_020516d0(work->unk_28a8);
    func_020516d0(work->unk_28ac);
    func_020629c4(work->handle);
    if (work->handle != 0) work->handle = 0;
    data_02176e10 = 0;
}

/* Dispatch event words 0 through 4; event 1 clears readiness and event 4 requests state 2. */
void func_020fc408(Work0fbed4 *work, const s32 *event)
{
    switch (*event) {
    case 0:
        func_020bc9f4(24, 0);
        break;
    case 1:
        data_02176e10->ready = 0;
        Unk0bc1a8_Unk_0bc504(work, 0);
        break;
    case 2:
    case 3:
        break;
    case 4:
        work->state = 2;
        Unk0a4e48_Unk_0a4e9c(2);
        break;
    }
}

/* Draw spaced horizontal and vertical lines, using value 66 on every fifth line. */
void func_020fc474(Work0fbed4 *work)
{
    s32 coordinate, index;
    for (coordinate = -4, index = -1; coordinate < 256; coordinate += 8, index++) {
        if (index % 5 == 0) func_0203f960(work->buffer, coordinate, 0, 1, 192, 66);
        else func_0203f960(work->buffer, coordinate, 0, 1, 192, 46);
    }
    for (coordinate = -4, index = -1; coordinate < 192; coordinate += 8, index++) {
        if (index % 5 == 0) func_0203f960(work->buffer, 0, coordinate, 256, 1, 66);
        else func_0203f960(work->buffer, 0, coordinate, 256, 1, 46);
    }
}

void func_0203e93c(s32 screen, s32 x, s32 y, s32 *settings, void *entry);

/* Draw six wrapping entries and fixed entries, advancing the signed offset each frame. */
void func_020fc238(Work0fbed4 *work)
{
    s32 i, position;
    if (work->ready == 0) return;
    for (i = 0, position = -160; i < 6; i++, position += 64) {
        s32 index = i + 15;
        s16 y;
        if (index > 17) index -= 6;
        /* Retain the work-relative flag view; see DEC-008. */
        ((Work0fbed4 *)((u8 *)work + index * 96))->entries[0].flag = 2;
        y = work->offset + position;
        if (y > 224) y -= 384;
        if (y + 32 >= 0 || y - 32 <= 192) {
            func_0203e93c(1, 128, y, work->unk_2890, (u8 *)work + 0x10 + index * 96);
        }
    }
    work->offset++;
    if (work->offset > 384) work->offset = 0;
    func_0203e93c(1, 128, 96, work->unk_2890, (u8 *)work + 0x430);
    func_0203e93c(1, 128, 96, work->unk_2890, (u8 *)work + 0xd0);
    func_0203e93c(1, 192, 96, work->unk_2890, (u8 *)work + 0xd0);
    func_0203e93c(1, 256, 96, work->unk_2890, (u8 *)work + 0xd0);
    func_0203e93c(1, 320, 96, work->unk_2890, (u8 *)work + 0xd0);
}

extern const char data_02150fe0[], data_02151000[], data_02151020[];
extern const char data_02151030[], data_0215103c[], data_0215104c[];
void func_020a4e48(s32 value);
void Unk0a4e48_Nop_0a4f38(s32 a, s32 b);
Descriptor0fbed4 *func_0205410c(s32 id);
void func_02008848(void *buffer, s32 value, u32 size);
void *func_02051610(const char *path);
void func_020559e8(s32 a, s32 b, void *resource);
void Unk03e43c_Unk_03f2bc(s32 value);
void Unk03e43c_ClearTable(void);
void func_0203e43c(s32 screen, const char *a, const char *b, s32 *settings,
    void **a4, void **a8, void **ac, s32 *out9c, s32 *outa0);
void Unk03e43c_Unk_03e894(Entry0fbed4 *entry, s32 a, s32 b, s32 index);
void *func_0203e6f0(const char *a, const char *b, s32 value);
void Unk03e43c_Unk_03e794(void *entry, u8 index);
void Unk03e43c_Call_02056cc0(void);
void *func_02060014(s32 value);

/* Initialize resources and 76 entries, draw the initial three entries, and publish the work. */
void func_020fbed4(Work0fbed4 *work)
{
    void *resource;
    Descriptor0fbed4 *descriptor;
    void *palette;
    s32 i;
    s32 y;
    data_02176e10 = 0;
    work->frame = 0;
    work->state = 0;
    work->offset = 0;
    work->unk_28b8 = 0;
    func_020a4e48(0);
    Unk0a4e48_Nop_0a4f38(1, 1);
    Unk0a4e48_Unk_0a4e9c(0);
    descriptor = func_0205410c(6);
    if (descriptor->available != 0) {
        work->buffer = descriptor->buffer;
        func_02008848(work->buffer, 0, 0xc000);
        resource = func_02051610(data_02150fe0);
        func_020559e8(1, 0, resource);
        func_020516d0(resource);
        work->resource = func_02051610(data_02151000);
        func_020fc474(work);
        Unk03e43c_Unk_03f2bc(6);
    }
    Unk03e43c_ClearTable();
    work->unk_2890[0] = 0xc00;
    work->unk_2890[1] = 0x100;
    work->unk_2890[2] = 184;
    func_0203e43c(1, data_02151020, data_02151030, work->unk_2890,
        &work->unk_28a4, &work->unk_28a8, &work->unk_28ac,
        &work->unk_2890[3], &work->unk_2890[4]);
    for (i = 0; i < 76; i++) {
        work->entries[i].unk_5a = 0;
        work->entries[i].unk_5c = 0;
        work->entries[i].flag = 1;
        Unk03e43c_Unk_03e894(&work->entries[i], work->unk_2890[3], work->unk_2890[4], i);
    }
    palette = func_0203e6f0(data_0215103c, data_0215104c, 0);
    for (i = 0; i < 16; i++) {
        Unk03e43c_Unk_03e794((u8 *)palette + i * 32, (u8)i);
    }
    func_020516d0(palette);
    Unk03e43c_Call_02056cc0();
    for (i = 0, y = 32; i < 3; i++, y += 64) {
        s32 index = i + 12;
        /* Retain the work-relative flag view; see DEC-008. */
        ((Work0fbed4 *)((u8 *)work + index * 96))->entries[0].flag = 2;
        func_0203e93c(1, 128, y, work->unk_2890, &work->entries[index]);
    }
    work->handle = func_02060014(0);
    work->ready = 0;
    data_02176e10 = work;
}
