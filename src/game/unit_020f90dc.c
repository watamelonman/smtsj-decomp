#include "types.h"

/* Layouts describe only accesses observed in this unit. */
typedef struct Entry { u8 id; u8 order; u8 unk_0002; u8 group : 7; u8 flag : 1; u8 pad_0004[64]; } Entry;
typedef struct Area { u8 pad[30]; s16 unk_001e; s16 unk_0020; } Area;
typedef struct Record { u8 pad[34]; u8 unk_0022; } Record;
typedef struct Slot { u32 unk_0000; void *unk_0004; u32 unk_0008; } Slot;
typedef struct Unk0f90dcWork {
    u32 unk_0000; Entry *source; u32 capacity;
    u32 unk_000c; u8 pad_0010[16]; int slot;
    u8 pad_0024[44]; Slot *unk_0050;
    int slots; int visible; u32 unk_005c; int first; u32 unk_0064; int selection;
    u8 pad_006c[128]; Entry **entries;
    int total; int *unk_00f4; u16 *ids; int count;
    void *unk_0100; void *unk_0104; void *unk_0108; void *unk_010c;
    void *unk_0110[5]; void *unk_0124[10];
    int unk_014c; void *unk_0150; int unk_0154;
} Unk0f90dcWork;

Record *func_020cb1a0(u32 id);
Area *Unk02e000_Thunk_0202e788(void);
Area *Unk02e000_GetAreaRecord(int area);
void Unk02e000_Unk_02e0cc(void);
void func_0205ad2c(u32 value);
void Unk05b82c_CreateEntry(const void *entry);
void *func_0205dcd4(const void *data, int mode);
void *func_0205c2c4(const void *data);
void *func_0205c3c0(void);
void func_0205c3fc(void *handle, void *a, void *b);
void func_0205c3dc(void *handle);
void func_0205ddb4(void *handle);
void func_0205c368(void *handle);
void func_0205bb68(void);
void func_020629c4(void *handle);
void Unk0fbc74_Unk_0fbcd4(void *handle, u32 id);
void Unk02f2a8_SetField6138(void *handle, u32 id);
void Unk0d297c_Unk_0d2e88(void);
void func_02053000(void *allocation);
extern u32 data_02150ed0;
extern u8 data_02150f38[];
extern u8 data_02150fc8[];
extern u8 data_02150fd4[];

/* Compare the signed area field with record byte 34; negative areas use the current area. */
int Unk0f90dc_Unk_0f90dc(int area, u32 id)
{
    Record *record;
    int value;
    int result = 0;
    record = func_020cb1a0(id);
    if (area < 0) value = Unk02e000_Thunk_0202e788()->unk_001e;
    else value = Unk02e000_GetAreaRecord(area)->unk_0020;
    if (value >= record->unk_0022) result = 1;
    return result;
}

/* Compare indirect entries by their unsigned byte at offset one. */
int Unk0f90dc_Unk_0f9128(const Entry *const *a, const Entry *const *b)
{
    return (u32)(*a)->order - (u32)(*b)->order;
}

/* Initialize the two handle groups using the shared six 24-byte descriptors. */
void func_020f9140(Unk0f90dcWork *work)
{
    int i;
    u8 *entry;
    Unk02e000_Unk_02e0cc();
    func_0205ad2c(data_02150ed0);
    entry = data_02150f38;
    for (i = 0; (u32)i < 6; i++, entry += 24) Unk05b82c_CreateEntry(entry);
    work->unk_0108 = func_0205dcd4(data_02150fc8, 1);
    work->unk_010c = func_0205c2c4(data_02150fd4);
    for (i = 0; i < 5; i++) {
        work->unk_0110[i] = func_0205c3c0();
        func_0205c3fc(work->unk_0110[i], work->unk_0108, work->unk_010c);
    }
    for (i = 0; i < 10; i++) {
        work->unk_0124[i] = func_0205c3c0();
        func_0205c3fc(work->unk_0124[i], work->unk_0108, work->unk_010c);
    }
    Unk02e000_Unk_02e0cc();
}

/* Release non-null group handles and clear their ownership fields. */
void func_020f91fc(Unk0f90dcWork *work)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (work->unk_0110[i]) { func_0205c3dc(work->unk_0110[i]); work->unk_0110[i] = 0; }
    }
    for (i = 0; i < 10; i++) {
        if (work->unk_0124[i]) { func_0205c3dc(work->unk_0124[i]); work->unk_0124[i] = 0; }
    }
    if (work->unk_0108) { func_0205ddb4(work->unk_0108); work->unk_0108 = 0; }
    if (work->unk_010c) { func_0205c368(work->unk_010c); work->unk_010c = 0; }
    for (i = 0; (u32)i < 6; i++) func_0205bb68();
    func_020629c4(work->unk_0100);
    func_020629c4(work->unk_0104);
}

/* Append an absent ID only while the caller-provided capacity permits it. */
void func_020f92bc(Unk0f90dcWork *work, u32 id)
{
    int i;
    if ((u32)work->count >= work->capacity) return;
    for (i = 0; i < work->count; i++) if (id == work->ids[i]) return;
    work->ids[work->count] = id;
    work->count++;
}

/* Propagate the selected entry's ID to both consumers and the unique-ID list. */
void func_020f9318(Unk0f90dcWork *work)
{
    int selection = work->selection;
    Unk0fbc74_Unk_0fbcd4(work->unk_0150, work->entries[selection]->id);
    func_020f92bc(work, work->entries[selection]->id);
    Unk02f2a8_SetField6138(work->unk_0050[work->slot].unk_0004, work->entries[selection]->id);
}

/* The original callback returns without side effects. */
void Unk0f90dc_Nop_0f9ce4(void) { }

/* Release the groups before freeing the four owned allocations. */
void Unk0f90dc_Unk_0fa4cc(Unk0f90dcWork *work)
{
    func_020f91fc(work);
    Unk0d297c_Unk_0d2e88();
    func_02053000(work->unk_0050); work->unk_0050 = 0;
    func_02053000(work->ids); work->ids = 0;
    func_02053000(work->entries); work->entries = 0;
    func_02053000(work->unk_00f4); work->unk_00f4 = 0;
}

void func_02063920(Unk0f90dcWork *work);
void *func_0204fed8(u32 source, u32 id);
void *func_02063a30(void *data);
int Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e64c8(u32 id);
void func_0205c408(void *handle, int mode);
void func_0205c6e0(void *handle);
void func_02061f10(void *handle, int index, int x, int y, void *data);

/* Refresh visible entry handles from byte-zero IDs and mark the text handle dirty.
 * Evidence: entry ID reads, mode mapping 0/1/2 to 1/2/3, and byte 0x40 write.
 * The caller must provide a nonempty visible range, as in the original.
 */
void func_020f9374(Unk0f90dcWork *work)
{
    int first = work->first;
    int i;
    void *data;
    func_02063920(work);
    for (i = 0; i < work->visible; i++) {
        Entry *entry = work->entries[first + i];
        int mode;
        int state;
        data = func_02063a30(func_0204fed8(work->unk_000c, entry->id));
        state = Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e64c8(entry->id);
        mode = 1;
        switch (state) {
        case 1: mode = 2; break;
        case 2: mode = 3; break;
        }
        func_0205c408(work->unk_0124[i], mode);
        func_0205c6e0(work->unk_0124[i]);
    }
    func_02061f10(work->unk_0100, -1, 0, 0, data);
    ((u8 *)work->unk_0100)[0x40] = 1;
}

int Unk02f2a8_GetSlot_02f2dc(void *slot);
int Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e6448(u32 id);
void *func_02052fe0(u32 size);
void func_02013c68(void *base, int count, int size, int (*compare)(const Entry *const *, const Entry *const *));
void Unk0bcef4_Unk_0bcef4(void *list, int visible, int total, int step);
void func_020bcfc4(void *list, int index);
void Unk0bcef4_Unk_0bd29c(void *state, void *list);
void func_020bd1a8(void *state, void *list, int *flags, int mode);

/* The high group bit belongs to a separate flag. */
static inline int EntryGroup(const Entry *entry) { return entry->group; }

/* Rebuild the selected slot's eligible entry list, sort by byte one, and
 * restore its saved ID selection. Evidence: 68-byte source stride, low-seven
 * group bits, predicate calls, and the existing byte-one comparator.
 */
int func_020f9434(Unk0f90dcWork *work)
{
    int slot;
    int saved;
    int i, n;
    int visible;
    work->total = 0;
    slot = (int)work->unk_0050[work->slot].unk_0004;
    saved = Unk02f2a8_GetSlot_02f2dc((void *)slot);
    func_02053000(work->entries); work->entries = 0;
    func_02053000(work->unk_00f4); work->unk_00f4 = 0;
    for (int i = 0; (u32)i < work->capacity; i++) {
        if (slot == EntryGroup(&work->source[i]) &&
            Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e6448(work->source[i].id))
            work->total++;
    }
    if (work->total == 0) return 0;
    work->entries = func_02052fe0(work->total * 4);
    work->unk_00f4 = func_02052fe0(work->total * 4);
    n = 0;
    for (int i = 0; (u32)i < work->capacity; i++) {
        if (slot == EntryGroup(&work->source[i]) &&
            Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e6448(work->source[i].id)) {
            work->entries[n] = &work->source[i];
            n++;
        }
    }
    func_02013c68(work->entries, work->total, 4, Unk0f90dc_Unk_0f9128);
    visible = 10;
    if (work->total < 10) visible = work->total;
    for (i = 0; i < work->total; i++) work->unk_00f4[i] = 1;
    Unk0bcef4_Unk_0bcef4(&work->visible, visible, work->total, 1);
    if (saved >= 0) {
        for (i = 0; i < work->total; i++) {
            if (saved == work->entries[i]->id) {
                func_020bcfc4(&work->visible, i);
                break;
            }
        }
    }
    Unk0bcef4_Unk_0bd29c((u8 *)work + 0x74, &work->visible);
    func_020bd1a8((u8 *)work + 0x74, &work->visible, work->unk_00f4, 1);
    func_020f9374(work);
    func_020f9318(work);
    return 1;
}

int func_020bce08(void *list, int mode);
void Unk0a0ce4_Unk_0a0da4(int id);
int func_02053800(int device, int mask);
int func_02053824(int device, int mask);
int func_020bcc7c(void *list);
int func_020bccec(void *list);
int Unk0fbc74_Unk_0fbd30(void *handle);
int Unk0fbc74_Unk_0fbd74(void *handle);
void Unk0bc1a8_SetFlag4Inv(Unk0f90dcWork *work, int flag);
void Unk0d297c_Thunk_02095398(u32 id);
void func_0205257c(int mode);
void func_0205e560(int mode, int frames);

/* Dispatch list movement, slot changes and confirmation from input masks.
 * Evidence: list helper calls, masks 0x200/0x100/2/1, and selected ID forwarding.
 */
void func_020f9b4c(Unk0f90dcWork *work)
{
    int first = work->first;
    if (func_020bce08(&work->visible, 1)) {
        int current = work->first;
        Unk0a0ce4_Unk_0a0da4(0);
        if (current != first) func_020f9374(work);
        func_020f9318(work);
        func_020bd1a8((u8 *)work + 0x74, &work->visible, work->unk_00f4, 1);
        return;
    }
    if (func_02053800(0, 0x200)) {
        if (func_020bcc7c((u8 *)work + 0x10)) {
            work->unk_014c = -6;
            func_020f9434(work);
            Unk0a0ce4_Unk_0a0da4(11);
        } else Unk0a0ce4_Unk_0a0da4(4);
        return;
    }
    if (func_02053800(0, 0x100)) {
        if (func_020bccec((u8 *)work + 0x10)) {
            work->unk_014c = 6;
            func_020f9434(work);
            Unk0a0ce4_Unk_0a0da4(11);
        } else Unk0a0ce4_Unk_0a0da4(4);
        return;
    }
    if (func_02053824(0, 2)) {
        if (Unk0fbc74_Unk_0fbd30(work->unk_0150)) {
            Unk0a0ce4_Unk_0a0da4(2);
            Unk0bc1a8_SetFlag4Inv(work, 0);
            Unk0d297c_Thunk_02095398(work->entries[work->selection]->id);
            work->unk_0000 = 4;
            func_0205257c(0);
            if (work->unk_0154) func_0205e560(1, 10);
        }
        return;
    }
    if (func_02053800(0, 1)) {
        if (Unk0fbc74_Unk_0fbd74(work->unk_0150)) Unk0a0ce4_Unk_0a0da4(7);
    }
}

void func_02057df8(void);
void func_02057ddc(u32 color);
void func_0205dee8(int layer, void *handle, int image, int x, int y,
                    float sx, float sy, int rotation, float alpha, int priority);
void func_0205c748(int layer, void *handle, int x, int y, float sx, float sy,
                    int rotation, float alpha, int priority);

/* Draw slot images at 80-pixel intervals, distinguishing the active slot and
 * optional markers. Evidence: image indices 11/12 and 14..16, slot stride 12.
 * Coordinates are pixels; handles remain borrowed from work.
 */
void func_020f9ce8(Unk0f90dcWork *work, int x, int y, int markers)
{
    int selected = work->slot;
    int i;
    int dx;
    for (i = 0; i < work->slots; i++) {
        int type = (int)work->unk_0050[i].unk_0004;
        int image = type == 1 ? 14 : 15;
        dx = i * 80;
        switch (type) {
        case 1: image = 14; break;
        case 2: image = 15; break;
        case 3: image = 16; break;
        }
        func_02057df8();
        if (selected == i) {
            func_0205dee8(2, work->unk_0108, 12, x + dx, y, 1.0f, 1.0f, 0, 1.0f, 5);
            func_02057ddc(0xa5e7ffff);
            func_0205dee8(2, work->unk_0108, image, x + dx, y, 1.0f, 1.0f, 0, 1.0f, 5);
        } else {
            func_0205dee8(2, work->unk_0108, 11, x + dx, y, 1.0f, 1.0f, 0, 1.0f, 5);
            func_02057ddc(0x394a7bff);
            func_0205dee8(2, work->unk_0108, image, x + dx, y, 1.0f, 1.0f, 0, 1.0f, 5);
            if (markers && work->unk_0050[i].unk_0008) {
                func_02057ddc(0xa5e7ffff);
                func_0205c748(2, work->unk_0110[(int)work->unk_0050[i].unk_0004], x + dx, 0, 1.0f, 1.0f, 0, 1.0f, 6);
            }
        }
    }
    func_02057df8();
}

/* Message storage mirrors the two flag bytes and sixteen payload words used
 * by the provider; padding has no contract and is not initialized. */
typedef struct Message { u8 flags[2]; u8 pad[2]; int words[16]; } Message;
/* Clear presence and payload while leaving alignment bytes untouched. */
static inline void ClearMessage(Message *message)
{
    int i;
    for (i = 0; i < 2; i++) message->flags[i] = 0;
    for (i = 0; i < 16; i++) message->words[i] = 0;
}
void Unk0bcef4_Unk_0bd388(void *state, void *list);
int func_02052728(void);
int func_0205c704(void *handle);
int Unk0fbc74_Unk_0fbdc4(void *handle);
void Unk0d297c_Unk_0d2adc(u32 id);
void Unk1241ec_Unk_124258(void);
u32 Unk0bc1a8_GetHeaderWord(Unk0f90dcWork *work);
void Unk0bc1a8_Unk_0bc9b4(u32 header, Message *message);

/* Advance the six-state handle sequence and emit completion messages.
 * Evidence: state word at zero, handle animation checks, and ID-list drain.
 */
void func_020f9900(Unk0f90dcWork *work)
{
    int i;
    Message message;
    if (work->unk_014c > 0) work->unk_014c--;
    else if (work->unk_014c < 0) work->unk_014c++;
    Unk0bcef4_Unk_0bd388((u8 *)work + 0x74, &work->visible);
    Unk0bcef4_Unk_0bd388((u8 *)work + 0x2c, (u8 *)work + 0x10);
    switch (work->unk_0000) {
    case 0:
        if (!func_02052728()) {
            work->unk_0000 = 1;
            func_0205c408(work->unk_0110[0], 7);
            func_0205c6e0(work->unk_0110[0]);
        }
        break;
    case 1:
        if (!func_0205c704(work->unk_0110[0])) {
            func_0205c408(work->unk_0110[4], 8);
            func_0205c6e0(work->unk_0110[4]);
            work->unk_0000 = 2;
        }
        break;
    case 2:
        if (!func_0205c704(work->unk_0110[4])) {
            work->unk_0000 = 3;
            Unk0bc1a8_SetFlag4Inv(work, 1);
            func_0205c408(work->unk_0110[0], 0);
            func_0205c6e0(work->unk_0110[0]);
            for (i = 0; i < 3; i++) {
                func_0205c408(work->unk_0110[i + 1], i + 9);
                func_0205c6e0(work->unk_0110[i + 1]);
            }
        }
        break;
    case 3:
        func_0205c704(work->unk_0110[0]);
        for (i = 0; i < 3; i++) func_0205c704(work->unk_0110[i + 1]);
        for (i = 0; i < 10; i++) func_0205c704(work->unk_0124[i]);
        break;
    case 4:
        if (func_02052728()) break;
        if (!Unk0fbc74_Unk_0fbdc4(work->unk_0150)) break;
        work->unk_0150 = 0;
        work->unk_0000 = 5;
        for (i = 0; i < work->count; i++) Unk0d297c_Unk_0d2adc(work->ids[i]);
        /* Completion also runs on later state-five updates. */
    case 5:
        Unk1241ec_Unk_124258();
        ClearMessage(&message);
        Unk0bc1a8_Unk_0bc9b4(Unk0bc1a8_GetHeaderWord(work), &message);
        Unk0bc1a8_Unk_0bc9b4(10, &message);
        break;
    }
}

/* The message header selects a callback; its payload uses presence bits. */
typedef struct CallbackMessage { u32 kind; Message payload; } CallbackMessage;
/* Return presence separately so callers can preserve their own defaults. */
static inline int MessageWord(Message *message, int index, int *out)
{
    int value;
    if (!message) return 0;
    value = message->words[index];
    if (message->flags[index / 8] & (1 << (index % 8))) {
        *out = value;
        return 1;
    }
    return 0;
}
int Unk0d297c_Thunk_020953ac(void);
void Unk0bc1a8_Unk_0bc928(int slot, u32 header, Message *message);
void func_020e7f44(int a, int b, int c, int d);
void func_020bcbc4(int slot, Message *message);
void *func_020fbde4(void *a, void *b, int c, int d);
void func_020525cc(int mode);
int func_0205e580(void);
void Unk0bc1a8_Unk_0bc514(Unk0f90dcWork *work, int mode, Message *message);

/* Initialize handles and restore a requested entry on callback kind zero;
 * kind one requests closure. Presence bits 7, 8 and 4 supply optional values.
 */
void func_020f9644(Unk0f90dcWork *work, CallbackMessage *callback)
{
    Message *args = &callback->payload;
    switch (callback->kind) {
    case 0: {
        int a, b, value;
        int i;
        Message message;
        Unk0bc1a8_SetFlag4Inv(work, 0);
        a = 0; b = 0;
        if (MessageWord(args, 7, &value)) a = value;
        if (MessageWord(args, 8, &value)) b = value;
        if (!MessageWord(args, 4, &value)) value = Unk0d297c_Thunk_020953ac();
        func_020f9140(work);
        ClearMessage(&message);
        Unk0bc1a8_Unk_0bc928(10, Unk0bc1a8_GetHeaderWord(work), &message);
        func_020e7f44(0, 0, 11, 12);
        message.words[1] = 1;
        message.flags[0] |= 2;
        func_020bcbc4(10, &message);
        work->unk_0150 = func_020fbde4(work->unk_0108, work->unk_010c, a, b);
        func_020bcfc4((u8 *)work + 0x10, 0);
        if (value >= 0) {
            for (i = 0; (u32)i < work->capacity; i++) {
                if (value == work->source[i].id) {
                    int j;
                    for (j = 0; j < work->slots; j++) {
                        if ((int)work->unk_0050[j].unk_0004 == work->source[i].group) {
                            func_020bcfc4((u8 *)work + 0x10, j);
                            Unk02f2a8_SetField6138(work->unk_0050[j].unk_0004, value);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        func_020f9434(work);
        work->unk_0000 = 0;
        func_020525cc(0);
        work->unk_0154 = 0;
        if (func_0205e580()) {
            work->unk_0154 = 1;
            func_0205e560(0, 10);
        }
        break;
    }
    case 1: {
        Message message;
        ClearMessage(&message);
        Unk0bc1a8_Unk_0bc514(work, 1, &message);
        break;
    }
    case 2: case 3: case 4: break;
    }
}
