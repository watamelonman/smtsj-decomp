/* src/game/unit_0206ea70.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Globals at 0x02170ccc. */
typedef struct Unk06ea70Table {
    u32 count;                  /* +0x00 (assumed) */
    u32 entry[1];               /* +0x04, variable length */
} Unk06ea70Table;

typedef struct Unk06ea70Globals {
    Unk06ea70Table *table;      /* +0x00 */
    u32 unk_04;                 /* +0x04 */
} Unk06ea70Globals;

extern Unk06ea70Globals data_02170ccc;



extern u32 data_02170cd4[];
extern u32 data_021457e8[];
u8 *Unk06ea70_GetBuf04Slot(int i);
/* Return the first nonzero slot selected by the 16-entry bit table, or slot zero when no selected entry exists. */
u32 Unk06ea70_FindByMask(u32 mask)
{
    int i;
    for (i = 0; i < 16; i++) {
        if ((mask & data_021457e8[i]) && data_02170cd4[i] != 0) {
            return data_02170cd4[i];
        }
    }
    return data_02170cd4[0];
}

int func_02053000(u32 address);
void Unk06ea70_Unk_06f4e4(void);

/* Clear the sixteen global entries and release both global allocations through the original cleanup sequence. */
void Unk06ea70_Unk_06eb54(void)
{
    int i;
    for (i = 0; i < 16; i++) {
        data_02170cd4[i] = 0;
    }
    func_02053000(data_02170ccc.table->count);
    data_02170ccc.table->count = 0;
    func_02053000((u32)data_02170ccc.table);
    data_02170ccc.table = 0;
    Unk06ea70_Unk_06f4e4();
}

/* Return -1 for an absent table or entry; otherwise borrow its buffer-04 slot. Caller supplies an in-range index. */
int Unk06ea70_Unk_06ebb8(int i)
{
    Unk06ea70Table *t = data_02170ccc.table;
    if (t == 0 || t->entry[i] == 0) {
        return -1;
    }
    return (int)Unk06ea70_GetBuf04Slot(i);
}

typedef struct Unk06ea70Bufs {
    u8 *buf_00;                 /* 512-byte slots */
    u8 *buf_04;                 /* 512-byte slots */
    s32 count;                 /* number of 512-byte slots */
    u32 mask_0c;
    u32 mask_10;
} Unk06ea70Bufs;

void func_02061424(u32 entry);
void Unk06ea70_SetMask0cBit(int i);
/* Release a nonzero table entry through func_02061424 and clear its slot. Caller supplies a valid table index. */
void Unk06ea70_ReleaseEntry(int i)
{
    if (data_02170ccc.table->entry[i] == 0) {
        return;
    }
    func_02061424(data_02170ccc.table->entry[i]);
    data_02170ccc.table->entry[i] = 0;
}

/* Store a nonzero entry and mark its slot in mask_0c (stores at 0x0206ec40, call at 0x0206ec44). Caller supplies a valid table index. */
void Unk06ea70_SetEntry(int i, u32 p)
{
    if (p == 0) {
        return;
    }
    data_02170ccc.table->entry[i] = p;
    Unk06ea70_SetMask0cBit(i);
}

/* Read table + 4 + i * 4, as at 0x0206ec58..0x0206ec5c. The table must be initialized and i must be in range. */
u32 Unk06ea70_GetTableEntry(int i)
{
    return data_02170ccc.table->entry[i];
}

/* Expand 256 packed RGB555 words into three caller-owned component arrays, with each five-bit component shifted left by 15. */
void Unk06ea70_Unk_06edf4(int *arg0,int *arg1,int *arg2,u16 *arg3)
{
  u32 value1;
  int value2;
  value2 = 0;
  do {
    value1 = (u32)*arg3;
    value2 = value2 + 1;
    *arg0 = (value1 & 0x1f) << 0xf;
    *arg1 = ((int)value1 >> 5 & 0x1fU) << 0xf;
    *arg2 = ((int)value1 >> 10 & 0x1fU) << 0xf;
    arg0 = arg0 + 1;
    arg1 = arg1 + 1;
    arg2 = arg2 + 1;
    arg3 = arg3 + 1;
  } while (value2 < 0x100);
}


/* Pass the state address at global +0x04 to func_02053000, then clear it (0x0206f4ec..0x0206f4fc). The helper ownership semantics remain unidentified. */
void Unk06ea70_Unk_06f4e4(void)
{
  func_02053000(data_02170ccc.unk_04);
  data_02170ccc.unk_04 = 0;
}

/* Set slot i in the word at buffer-state +0x0c (0x0206f634..0x0206f63c). Negative indices are ignored; other indices must be below 32. */
void Unk06ea70_SetMask0cBit(int i)
{
    if (i < 0) {
        return;
    }
    ((Unk06ea70Bufs *)data_02170ccc.unk_04)->mask_0c |= 1u << i;
}

/* Clear slot i in the word at buffer-state +0x0c (0x0206f65c..0x0206f66c). Negative indices are ignored; other indices must be below 32. */
void Unk06ea70_ClearMask0cBit(int i)
{
    if (i < 0) {
        return;
    }
    ((Unk06ea70Bufs *)data_02170ccc.unk_04)->mask_0c &= ~(1u << i);
}

/* Borrow a 512-byte slot from buffer-state +0x04: 0x0206f688..0x0206f690 loads that base and shifts i by nine. Negative i returns null; other indices must fit the allocation. */
u8 *Unk06ea70_GetBuf04Slot(int i)
{
    if (i < 0) {
        return 0;
    }
    return ((Unk06ea70Bufs *)data_02170ccc.unk_04)->buf_04 + i * 512;
}

/* Borrow a 512-byte slot from buffer-state +0x00: 0x0206f6ac..0x0206f6b4 loads that base and shifts i by nine. Negative i returns null; other indices must fit the allocation. */
u8 *Unk06ea70_GetBuf00Slot(int i)
{
    if (i < 0) {
        return 0;
    }
    return ((Unk06ea70Bufs *)data_02170ccc.unk_04)->buf_00 + i * 512;
}

/* Set slot i in the word at buffer-state +0x10 (0x0206f6d0..0x0206f6d8). Negative indices are ignored; other indices must be below 32. */
void Unk06ea70_SetMask10Bit(int i)
{
    if (i < 0) {
        return;
    }
    ((Unk06ea70Bufs *)data_02170ccc.unk_04)->mask_10 |= 1u << i;
}

void *func_02052fe0(u32 size);
void func_02008848(void *destination, int value, u32 size);
u8 *Unk05b540_Unk_05b7d0(void);
u32 func_02051610(const void *name);
u32 func_0205f2e4(u32 resource);
u32 func_0205f41c(u32 resource, u32 index);
extern const u8 data_02145828[];

/* Allocate and clear a state with count 512-byte slots, borrowing buffer04.
 * Evidence: 0206f460 allocates count*512+20 and marks each slot at +0x10.
 * The caller supplies a nonnegative count below 32 and a suitably sized buffer. */
void func_0206f460(int count, u8 *buffer04)
{
    int i;
    data_02170ccc.unk_04 = (u32)func_02052fe0(count * 512 + 20);
    func_02008848((void *)data_02170ccc.unk_04, 0, count * 512 + 20);
    ((Unk06ea70Bufs *)data_02170ccc.unk_04)->buf_00 = (u8 *)data_02170ccc.unk_04 + 20;
    ((Unk06ea70Bufs *)data_02170ccc.unk_04)->count = count;
    ((Unk06ea70Bufs *)data_02170ccc.unk_04)->buf_04 = buffer04;
    for (i = 0; i < ((Unk06ea70Bufs *)data_02170ccc.unk_04)->count; i++) {
        Unk06ea70_SetMask10Bit(i);
    }
}

/* Initialize the singleton table, six buffer slots and up to sixteen resources.
 * Evidence: 0206eab4 allocates 28 bytes and enumerates the resource named by
 * data_02145828 through 0205f2e4/0205f41c. Initialization requires no live state. */
void func_0206eab4(void)
{
    u32 count;
    u32 i;
    data_02170ccc.table = func_02052fe0(28);
    func_02008848(data_02170ccc.table, 0, 28);
    func_0206f460(6, Unk05b540_Unk_05b7d0());
    data_02170ccc.table->count = func_02051610(data_02145828);
    count = func_0205f2e4(data_02170ccc.table->count);
    if (count > 16) {
        count = 16;
    }
    for (i = 0; i < count; i++) {
        data_02170cd4[i] = func_0205f41c(data_02170ccc.table->count, i);
    }
}

void func_0205bccc(u32 *request, int mode, void *source, int count,
                   void *destination, int transfer);

/* Submit the contiguous span containing all dirty 512-byte slots, then clear
 * mask_10. Evidence: 0206f544 scans bits; 0206f5ac submits the first/last span.
 * Buffer state may be absent; otherwise both buffers cover count slots,
 * with count in 0..32. */
void func_0206f508(void)
{
    int first, last, i;
    u32 request[2];
    Unk06ea70Bufs *state = (Unk06ea70Bufs *)data_02170ccc.unk_04;
    if (state == 0) {
        return;
    }
    first = -1;
    last = -1;
    for (i = 0; i < state->count; i++) {
        if (state->mask_10 & (1u << i)) {
            if (first < 0) {
                first = i;
            }
            last = i;
        }
    }
    if (first == -1 && last == -1) {
        return;
    }
    /* Preserve the original post-scan singleton reload. See DEC-012. */
    state = (Unk06ea70Bufs *)*(volatile u32 *)&data_02170ccc.unk_04;
    func_0205bccc(request, 0,
        state->buf_00 + first * 512,
        last - first + 1,
        state->buf_04 + first * 512, 1);
    ((Unk06ea70Bufs *)data_02170ccc.unk_04)->mask_10 = 0;
}

void func_02008904(const void *source, void *destination, u32 bytes);
void func_02002298(int numerator, int denominator);
int func_02002204(void);

/* Palette transition storage: nine 256-element fixed-point component arrays
 * followed by the original eight control words (0x2400..0x241c). */
typedef struct Unk06ea70Transition {
    int red[256], green[256], blue[256];
    int targetRed[256], targetGreen[256], targetBlue[256];
    int deltaRed[256], deltaGreen[256], deltaBlue[256];
    u16 *source;
    u16 *target;
    int begin, end, tick;
    u32 mask;
    int slot, enabled;
} Unk06ea70Transition;

/* Install RGB555 colors immediately or prepare per-component increments.
 * Evidence: 0206ee6c copies 510 bytes; 0206eedc uses the hardware divider.
 * state has 2312 words; colors has 256 entries, with endpoints excluded
 * from the incremental update. Positive duration is measured in ticks and
 * must fit a signed 20.12 value. */
void func_0206ee3c(Unk06ea70Transition *state, int duration, u16 *colors)
{
    int i;
    int difference;
    s64 *divider = (s64 *)0x04000290;
    if (duration <= 0) {
        func_02008904(colors, Unk06ea70_GetBuf00Slot(state->slot), 510);
        Unk06ea70_SetMask10Bit(state->slot);
        Unk06ea70_Unk_06edf4(state->red, state->green, state->blue, colors);
        return;
    }
    Unk06ea70_Unk_06edf4(state->targetRed, state->targetGreen, state->targetBlue, colors);
    func_02002298(4096, 4096);
    i = 1;
    difference = state->targetRed[1] - state->red[1];
    do {
        divider[0] = (s64)((u64)(u32)difference << 32);
        divider[1] = (u32)(duration << 12);
        state->deltaRed[i] = func_02002204();
        divider[0] = (s64)((u64)(u32)(state->targetGreen[i] - state->green[i]) << 32);
        divider[1] = (u32)(duration << 12);
        state->deltaGreen[i] = func_02002204();
        divider[0] = (s64)((u64)(u32)(state->targetBlue[i] - state->blue[i]) << 32);
        divider[1] = (u32)(duration << 12);
        state->deltaBlue[i] = func_02002204();
        difference = state->targetRed[i + 1] - state->red[i + 1];
        i++;
    } while (i < 255);
}

/* Advance interior RGB555 entries by fixed-point component deltas, stopping
 * each component at a boundary or its destination's integer component.
 * Evidence: 0206ec94..0206edd0 clamps at 0/0xff000 and packs RGB555.
 * state covers 0x2420 bytes and its slot must be initialized. */
void func_0206ec68(Unk06ea70Transition *state)
{
    u16 *colors = (u16 *)Unk06ea70_GetBuf00Slot(state->slot);
    int i;
    for (i = 1; i < 255; i++) {
        int red = (state->red[i] += state->deltaRed[i]);
        int green, blue;
        if (red <= 0) {
            state->red[i] = 0;
            state->deltaRed[i] = 0;
            red = 0;
        } else if (red >= 0xff000) {
            state->red[i] = 0xff000;
            state->deltaRed[i] = 0;
            red = 255;
        } else {
            red >>= 12;
            if (red == state->targetRed[i] >> 12) {
                state->deltaRed[i] = 0;
            }
        }
        green = (state->green[i] += state->deltaGreen[i]);
        if (green <= 0) {
            state->green[i] = 0;
            state->deltaGreen[i] = 0;
            green = 0;
        } else if (green >= 0xff000) {
            state->green[i] = 0xff000;
            state->deltaGreen[i] = 0;
            green = 255;
        } else {
            green >>= 12;
            if (green == state->targetGreen[i] >> 12) {
                state->deltaGreen[i] = 0;
            }
        }
        blue = (state->blue[i] += state->deltaBlue[i]);
        if (blue <= 0) {
            state->blue[i] = 0;
            state->deltaBlue[i] = 0;
            blue = 0;
        } else if (blue >= 0xff000) {
            state->blue[i] = 0xff000;
            state->deltaBlue[i] = 0;
            blue = 255;
        } else {
            blue >>= 12;
            if (blue == state->targetBlue[i] >> 12) {
                state->deltaBlue[i] = 0;
            }
        }
        colors[i] = (red >> 3) | ((green >> 3) << 5) | ((blue >> 3) << 10);
    }
    Unk06ea70_SetMask10Bit(state->slot);
}

void func_020a5fc8(int slot, int value);

/* Drive the palette transition's warmup, blend interval and final release.
 * Evidence: 0206ef98 compares tick to begin/end, then 0206f084 releases
 * the table entry. The initialized state is borrowed until that release. */
void func_0206ef6c(Unk06ea70Transition *state)
{
    int tick = state->tick;
    if (tick < 7) {
        if (state->enabled) {
            func_0206ec68(state);
        }
    } else if (tick >= 7 && tick < state->begin) {
        /* Hold the initial palette until the blend interval begins. */
    } else if (tick >= state->begin && tick < state->end) {
        if (tick == state->begin) {
            func_020a5fc8(state->slot, 0);
            func_02008904(state->source, Unk06ea70_GetBuf00Slot(state->slot), 510);
            func_0206ee3c(state, state->end - state->begin, state->source);
        }
        if (state->begin != state->end) {
            func_0206ec68(state);
        }
    } else if (tick >= state->end) {
        func_020a5fc8(state->slot, 0);
        func_02008904(state->source, Unk06ea70_GetBuf00Slot(state->slot), 510);
        Unk06ea70_SetMask10Bit(state->slot);
        Unk06ea70_ReleaseEntry(state->slot);
        return;
    }
    state->tick++;
}

void func_02007e94(int condition);
Unk06ea70Transition *func_020611dc(void (*callback)(Unk06ea70Transition *),
    int a, int b, int c, u32 size, int priority, int d, int e);

/* Create or restart a slot's timed palette transition, retaining source colors.
 * Evidence: 0206f16c allocates 0x2420 bytes with callback 0206ef6c;
 * 0206f1b0 registers the resulting state in the slot table.
 * source has 256 colors and must remain valid through end; slot must index
 * initialized buffers. */
Unk06ea70Transition *func_0206f0a4(u16 *source, u32 mask, int slot, int begin, int end)
{
    Unk06ea70Transition *state;
    int valid = source != 0;
    if (!valid) {
        func_02007e94(valid);
        return 0;
    }
    state = (Unk06ea70Transition *)Unk06ea70_GetTableEntry(slot);
    if (state) {
        state->enabled = 0;
        state->mask = mask;
        state->source = source;
        state->begin = begin;
        state->end = end;
        state->tick = 0;
        state->slot = slot;
        state->target = (u16 *)Unk06ea70_FindByMask(mask);
        func_0206ee3c(state, state->enabled ? 7 : 0, state->target);
    } else {
        state = func_020611dc(func_0206ef6c, 0, 0, 0, 0x2420, 4, 0, 0);
        func_02008848(state, 0, 0x2420);
        state->enabled = 0;
        state->mask = mask;
        state->source = source;
        state->begin = begin;
        state->end = end;
        state->tick = 0;
        state->slot = slot;
        Unk06ea70_SetEntry(slot, (u32)state);
        state->target = (u16 *)Unk06ea70_FindByMask(mask);
        if (state->enabled) {
            Unk06ea70_Unk_06edf4(state->red, state->green, state->blue, state->source);
            func_0206ee3c(state, 7, state->target);
        } else {
            func_0206ee3c(state, 0, state->target);
        }
    }
    if (state->enabled) {
        func_02008904(state->source, Unk06ea70_GetBuf00Slot(state->slot), 512);
    }
    return state;
}
