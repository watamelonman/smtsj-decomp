/* Work state and resource operations for this unit. */
#include "types.h"

/* Private work view: callers own the storage; setup and teardown own its ten handles. */
typedef struct Unk10fe28Work {
    u32 unk_0000;
    s32 unk_0004;
    u32 unk_0008;
    s32 unk_000c;
    u32 unk_0010;
    u32 unk_0014;
    u32 unk_0018;
    u32 unk_001c;
    u32 unk_0020;
    u32 unk_0024;
    u32 unk_0028[10];
    u32 unk_0050;
    u32 unk_0054;
    u8  unk_0058[8];
} Unk10fe28Work;

/* Two flag bytes plus sixteen payload words; padding is intentionally untouched. */
typedef struct Unk10fe28Message {
    u8 flags[2];
    u32 words[16];
} Unk10fe28Message;

/* Event payload: a flag byte owns the optional word at +0x10. */
typedef struct Unk10fe28Payload {
    u8 flags;
    u8 pad_0001[15];
    u32 value;
} Unk10fe28Payload;

/* Incoming event word followed by its payload; the handler advances past +0. */
typedef struct Unk10fe28Event {
    u32 type;
    Unk10fe28Payload payload;
} Unk10fe28Event;

/* Four per-column alphas copied from the fixed table at data_0213ca94. */
typedef struct Unk10fe28Alphas {
    float v[4];
} Unk10fe28Alphas;

/* Borrowed entry header: +0x0c empty flag and +0x18 the value drawn on the cursor. */
typedef struct Unk10fe28Entry {
    u8 pad_0000[12];
    u32 unk_000c;
    u32 unk_0010;
    u32 unk_0014;
    u32 unk_0018;
} Unk10fe28Entry;

/* Reset the message flags and payload without clearing the alignment bytes. */
static inline void Unk10fe28_ClearMessage(Unk10fe28Message *m)
{
    int i;
    for (i = 0; i < 2; i++) {
        m->flags[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        m->words[i] = 0;
    }
}

/* Publish the optional +0x10 word only when flag bit 3 marks it valid. */
static inline int Unk10fe28_Payload(Unk10fe28Payload *p, void *out)
{
    u32 value;
    if (p == 0) return 0;
    value = p->value;
    if (p->flags & 8) {
        *(u32 *)out = value;
        return 1;
    }
    return 0;
}

u32 func_0204fe68(u32 handle, int index);
u32 func_0204fed8(u32 handle, u32 index);
/* Resolve resource group 1 at +0x18 and return the entry indexed by +0x08;
 * func_021100c0/func_02110658 pass that entry as the +0x54 argument of
 * func_02061f10. */
u32 Unk10fe28_Unk_10fe28(Unk10fe28Work *w)
{
    u32 group = func_0204fe68(w->unk_0018, 1);
    return func_0204fed8(group, w->unk_0008);
}

void func_02053000(u32 handle);
void func_0210ff80(Unk10fe28Work *w);
/* Release subordinate handles before releasing and clearing the owning resource. */
void Unk10fe28_Unk_1113e0(Unk10fe28Work *w)
{
    func_0210ff80(w);
    func_02053000(w->unk_0018);
    w->unk_0018 = 0;
}

extern u32 data_02151438[];
extern u8 data_021514b0[];
extern u8 data_02151540[];
extern u8 data_02151548[];
extern u8 data_02151550[];
void Unk02e000_Unk_02e0cc(void);
void func_0205ad2c(u32 handle);
void Unk05b82c_CreateEntry(void *entry);
u32 func_0205c2c4(void *resource);
u32 func_0205c3c0(void);
void func_0205c3fc(u32 handle, u32 a, u32 b);
u32 func_0205dcd4(void *resource, int flag);
void func_02061e98(u32 handle, int value, int flag);
void func_02061f10(u32 handle, int a, int b, int c, u32 entry);
u32 func_020629ac(int a, int b, int c, int d);
void Unk065e88_Unk_065e88(void);
void Unk05b82c_Unk_05b82c(int resource);

/* Initialize six descriptors and ten owned entries; +0x18 must already be valid. */
void func_0210fe48(Unk10fe28Work *w)
{
    s32 i;
    u32 n;
    u8 *p;
    u32 entry;

    func_0205ad2c(*data_02151438);
    n = 0;
    p = data_021514b0;
    do {
        Unk05b82c_CreateEntry(p);
        n++;
        p += 0x18;
    } while (n < 6);
    w->unk_001c = func_0205dcd4(data_02151540, 1);
    w->unk_0020 = func_0205c2c4(data_02151548);

    w->unk_0050 = func_020629ac(3, 1, 0, 1);
    func_02061e98(w->unk_0050, 0x10, 1);
    entry = func_0204fed8(func_0204fe68(w->unk_0018, 1), 10);
    func_02061f10(w->unk_0050, -1, 0, 0, entry);

    w->unk_0054 = func_020629ac(5, 2, 0, 1);
    func_02061e98(w->unk_0054, 0x10, 1);
    if (w->unk_000c == 1) {
        Unk065e88_Unk_065e88();
    }
    for (i = 0; i < 10; i++) {
        w->unk_0028[i] = func_0205c3c0();
        func_0205c3fc(w->unk_0028[i], w->unk_001c, w->unk_0020);
    }

    Unk02e000_Unk_02e0cc();
    Unk05b82c_Unk_05b82c(0x39);
    w->unk_0024 = func_0205dcd4(data_02151550, 1);
}

void func_0205c408(u32 handle, u32 value);
void func_0205c6e0(u32 handle);
void func_0205c704(u32 handle);
extern s16 data_0213ca70[];
/* Set and refresh entry i; callers supply an index within the ten handles. */
void Unk10fe28_Unk_110048(Unk10fe28Work *w, int i, u32 v)
{
    func_0205c408(w->unk_0028[i], v);
    func_0205c6e0(w->unk_0028[i]);
}

/* Assign the initial values to entries zero through seven. */
void Unk10fe28_Unk_110074(Unk10fe28Work *w)
{
    int i;
    Unk10fe28_Unk_110048(w, 0, 0);
    Unk10fe28_Unk_110048(w, 1, 2);
    for (i = 2; i <= 7; i++) {
        Unk10fe28_Unk_110048(w, i, 6);
    }
}

/* 0x021100c0: handle event words 0..4 for the entry screen. Event 0 initializes
 * the work, events 1/2 post cleared messages, event 3 restores the four entry
 * slots and event 4 is ignored. See docs/functions/game-unit-0210fe28.md. */
void Unk0bc1a8_SetFlag4Inv(void *w, int v);
u32 Unk0bc1a8_GetHeaderWord(void *w);
void Unk0bc1a8_Unk_0bc928(u32 slot, u32 value, Unk10fe28Message *message);
void Unk0bc1a8_Unk_0bc514(Unk10fe28Work *w, int mode, Unk10fe28Message *message);
int func_020525cc(int a);
u8 *Unk02e000_Unk_02e8f0(void);
void func_02008904(const void *src, void *dst, u32 size);
void func_021100c0(Unk10fe28Work *w, Unk10fe28Event *event)
{
    struct { u32 value; } result;
    u32 ok;
    Unk10fe28Message messageA;
    Unk10fe28Message messageB;
    u32 type = event->type;
    Unk10fe28Payload *payload = &event->payload;

    switch (type) {
    case 0:
        /* The original guards the borrowed payload through &w->unk_000c and a
         * second pointer test; the flag-qualified store is the only path that
         * marks the field valid. */
        if (&w->unk_000c == 0) ok = 0;
        else if (payload == 0) ok = 0;
        else if (Unk10fe28_Payload(payload, &result.value)) {
            w->unk_000c = result.value;
            ok = 1;
        } else ok = 0;
        if (!ok) w->unk_000c = 0;
        Unk0bc1a8_SetFlag4Inv(w, 0);
        func_0210fe48(w);
        w->unk_0000 = 0;
        w->unk_0014 = 0;
        {
            u8 *sel = Unk02e000_Unk_02e8f0();
            w->unk_0008 = 0;
            w->unk_0010 = sel[2];
            func_02008904(sel, w->unk_0058, 8);
        }
        func_02061f10(w->unk_0054, -1, 0, 0, Unk10fe28_Unk_10fe28(w));
        break;
    case 3:
        func_0210fe48(w);
        func_02061f10(w->unk_0054, -1, 0, 0, Unk10fe28_Unk_10fe28(w));
        Unk10fe28_Unk_110048(w, 2, 5);
        Unk10fe28_Unk_110048(w, 8, 3);
        Unk10fe28_Unk_110048(w, 9, 4);
        Unk10fe28_Unk_110048(w, 0, 1);
        func_020525cc(3);
        w->unk_0000 = 4;
        break;
    case 2:
        Unk10fe28_ClearMessage(&messageA);
        Unk0bc1a8_Unk_0bc928(0x28, Unk0bc1a8_GetHeaderWord(w), &messageA);
        break;
    case 1:
        Unk10fe28_ClearMessage(&messageB);
        Unk0bc1a8_Unk_0bc514(w, 1, &messageB);
        break;
    case 4:
        break;
    }
}

/* Apply the entry operation to four handles selected by signed table offsets. */
void Unk10fe28_Unk_1102d4(Unk10fe28Work *w)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        func_0205c704(w->unk_0028[data_0213ca70[i]]);
    }
}

void func_0205ddb4(u32 handle);
void func_0205bb68(void);
void func_020629c4(u32 handle);
void func_0205c3dc(u32 handle);
void func_0205c368(u32 handle);
void Unk065e88_Unk_065eac(void);

/* Release owned handles, clearing each slot so it cannot be reused accidentally. */
void func_0210ff80(Unk10fe28Work *w)
{
    int i;
    u32 n;
    if (w->unk_0024 != 0) {
        func_0205ddb4(w->unk_0024);
        w->unk_0024 = 0;
    }
    func_0205bb68();
    func_020629c4(w->unk_0050);
    w->unk_0050 = 0;
    func_020629c4(w->unk_0054);
    w->unk_0054 = 0;
    for (i = 0; i < 10; i++) {
        if (w->unk_0028[i] != 0) {
            func_0205c3dc(w->unk_0028[i]);
            w->unk_0028[i] = 0;
        }
    }
    if (w->unk_000c == 1) {
        Unk065e88_Unk_065eac();
    }
    if (w->unk_001c != 0) {
        func_0205ddb4(w->unk_001c);
        w->unk_001c = 0;
    }
    if (w->unk_0020 != 0) {
        func_0205c368(w->unk_0020);
        w->unk_0020 = 0;
    }
    for (n = 0; n < 6; n++) {
        func_0205bb68();
    }
}

extern const s16 data_0213ca88[];
void func_02057ddc(u32 value);
void func_02057df8(void);
void func_0205de40(int mode, u32 handle, int entry, int x, int y,
                   float scaleX, float scaleY, int z, float scaleZ, int flags);

/* Submit six table entries, skipping value 4 in mode 1; selected enables +0x08 tinting. */
void func_02110f08(Unk10fe28Work *w, int selected)
{
    u32 i;
    func_02057ddc(0xaddeffff);
    for (i = 0; i < 6; i++) {
        if (w->unk_000c == 1 && data_0213ca88[i] == 4) {
            continue;
        }
        if (selected) {
            if (w->unk_0008 == i) {
                func_02057ddc(~0x3900U);
            } else {
                func_02057ddc(0xaddeffff);
            }
        }
        func_0205de40(2, w->unk_001c, data_0213ca88[i], 0, 0,
                       1.0f, 1.0f, 0, 1.0f, 5);
    }
    func_02057df8();
}

/* 0x02110fc8: draw and advance the two entry rows. States 2/3 render the
 * column grid and cursor; 4..8/10 render the row list, the cursor and the
 * selection, then hand off to func_02110a24; 9/11 only redraw. See docs. */
void func_020580ec(int mode);
void func_02057524(u32 mode);
void func_02057534(void);
void Unk_LoadPalette_020de678(u32 handle);
void func_02057df8(void);
void func_02057e18(int alpha);
void func_02057eb8(int value);
void func_0205c748(u32 mode, u32 handle, int x, int y,
                   float scaleX, float scaleY, int z, float scaleZ, int flags);
void func_02060b60(u32 mode, u32 handle, int x, int y, int z, int flags);
int Unk0bc1a8_IsSlotEmptyOrFlag8(int slot);
void func_02110a24(Unk10fe28Work *w, int selected);

void func_02110fc8(Unk10fe28Work *w)
{
    int pos;
    int i;
    int y;

    if (Unk0bc1a8_IsSlotEmptyOrFlag8(Unk0bc1a8_GetHeaderWord(w)) != 0) {
        return;
    }
    func_020580ec(0);
    func_02057524(0);
    Unk_LoadPalette_020de678(w->unk_0024);
    func_02057534();
    func_02057df8();
    func_02057e18(31);
    Unk02e000_Unk_02e8f0();
    switch (w->unk_0000) {
    case 2:
    case 3:
        if (((Unk10fe28Entry *)w->unk_0028[0])->unk_000c != 0) {
            func_0205de40(2, w->unk_001c, 20, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        }
        pos = 0;
        for (i = 0, y = 0; i <= 7; i++, y += 21) {
            int p;
            if (w->unk_000c == 1 && i == 6) {
                continue;
            }
            p = pos;
            if (i >= 2) {
                p = y - 42;
                if (i == 7) {
                    p += 21;
                }
            }
            func_0205c748(2, w->unk_0028[i], 0, p, 1.0f, 1.0f, 0, 1.0f, 5);
        }
        func_02057e18(31);
        pos = 0;
        if (((Unk10fe28Entry *)w->unk_0028[0])->unk_000c == 0) {
            pos = ((Unk10fe28Entry *)w->unk_0028[0])->unk_0018;
        }
        func_02060b60(2, w->unk_0050, 2, pos, 0, 6);
        if (w->unk_0000 != 3) {
            break;
        }
        func_02060b60(2, w->unk_0054, 13, 0xaa, 0, 6);
        func_02110f08(w, 1);
        func_02110a24(w, 0);
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 10: {
        int j;
        for (j = 0; j < 6; j++) {
            if (w->unk_000c == 1 && j == 4) {
                continue;
            }
            func_02057eb8(0);
            pos = (j == 5 ? j + 1 : j) * 21;
            func_0205de40(2, w->unk_001c, 23, 0, pos, 1.0f, 1.0f, 0, 1.0f, 5);
            func_02057eb8(-1);
        }
        y = w->unk_0008 * 21;
        if (w->unk_0008 == 5) {
            y += 21;
        }
        func_0205c748(2, w->unk_0028[8], 0, y, 1.0f, 1.0f, 0, 1.0f, 5);
        func_0205de40(2, w->unk_001c, 17, 0, y, 1.0f, 1.0f, 0, 1.0f, 5);
        if (w->unk_0000 == 4) {
            func_0205c748(2, w->unk_0028[9], 0, y, 1.0f, 1.0f, 0, 1.0f, 5);
        }
        func_02110f08(w, 1);
        func_0205de40(2, w->unk_001c, 20, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        func_0205de40(2, w->unk_001c, 22, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        func_02057df8();
        func_02057e18(31);
        func_02060b60(2, w->unk_0050, 2, 0, 0, 6);
        func_02060b60(2, w->unk_0054, 13, 0xaa, 0, 6);
        func_0205c748(2, w->unk_0028[0], 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        func_02110a24(w, 1);
        break;
    }
    case 0:
        break;
    case 1:
        break;
    case 9:
        break;
    case 11:
        break;
    }
    func_020580ec(1);
}

void func_02007ba4(int a);
void func_0205257c(int a);
int func_020525cc(int a);
int func_02052728(void);
u32 func_0205ca48(u32 handle);
u32 func_0205ecd8(void);
void func_02057e58(int a, int b, int c);
int func_020654cc(void);
s32 func_0206559c(void);
s32 func_02065e1c(void);
void func_02065c30(void);
void func_02065ca8(void);
void SaveLoadTask_SelectEntry(int id);
void Unk0bc1a8_SetFlag4Inv(void *w, int v);
u32 Unk0bc1a8_GetHeaderWord(void *w);
void Unk0bc1a8_Unk_0bc9b4(u32 header, Unk10fe28Message *message);
void Unk02e000_Unk_02e180(void);
int Unk0e1648_Unk_0e1648(void);

/* Run the twelve-state entry sequence; state 11 posts the completion message. */
void func_0211030c(Unk10fe28Work *w)
{
    int limit;
    int i;

    func_02057e58(0, 0, 4);
    switch (w->unk_0000) {
    case 0:
        func_020525cc(3);
        w->unk_0000 = 1;
        break;
    case 1:
        if (func_02052728()) {
            break;
        }
        w->unk_0000 = 2;
        Unk10fe28_Unk_110074(w);
        w->unk_0004 = 0;
        break;
    case 2:
        limit = 2;
        limit += (s32)w->unk_0004 / 2;
        if (limit > 7) {
            limit = 7;
        }
        for (i = 0; i <= limit; i++) {
            func_0205c704(w->unk_0028[i]);
        }
        w->unk_0004++;
        if (func_0205ca48(w->unk_0028[7]) == 0) {
            w->unk_0000 = 3;
            w->unk_0004 = 0;
        }
        break;
    case 3:
        func_0205c704(w->unk_0028[0]);
        if (++w->unk_0004 < 15) {
            break;
        }
        w->unk_0000 = 4;
        Unk0bc1a8_SetFlag4Inv(w, 1);
        Unk10fe28_Unk_110048(w, 2, 5);
        Unk10fe28_Unk_110048(w, 8, 3);
        Unk10fe28_Unk_110048(w, 9, 4);
        Unk10fe28_Unk_110048(w, 0, 1);
        break;
    case 4:
    case 5:
        Unk10fe28_Unk_1102d4(w);
        break;
    case 7:
        Unk10fe28_Unk_1102d4(w);
        if (!func_020654cc()) {
            break;
        }
        Unk0bc1a8_SetFlag4Inv(w, 1);
        w->unk_0000 = 4;
        break;
    case 6:
        Unk10fe28_Unk_1102d4(w);
        if (!func_020654cc()) {
            break;
        }
        if (!func_0206559c()) {
            break;
        }
        if (!func_02065e1c()) {
            /* The original re-reads the state word after the gate calls; that
             * check distinguishes a frame still in state 6 from one the
             * callback changed, so keep it rather than folding the test. */
            if (w->unk_0000 == 6) {
                w->unk_0000 = 8;
                func_0205257c(3);
            } else {
                w->unk_0000 = 7;
                w->unk_0014 = 1;
                Unk02e000_Unk_02e180();
            }
        } else {
            w->unk_0000 = 7;
        }
        func_02065c30();
        break;
    case 8:
        if (func_02052728()) {
            break;
        }
        if (!func_020654cc()) {
            break;
        }
        func_02007ba4(0);
        break;
    case 10:
        Unk10fe28_Unk_1102d4(w);
        if (func_02052728()) {
            break;
        }
        if (w->unk_0014 != 0 && func_0205ecd8()) {
            SaveLoadTask_SelectEntry(4);
            w->unk_0000 = 9;
            break;
        }
        w->unk_0000 = 11;
        break;
    case 9:
        if (Unk0e1648_Unk_0e1648()) {
            w->unk_0000 = 11;
        }
        break;
    case 11: {
        Unk10fe28Message m;
        func_02065ca8();
        Unk10fe28_ClearMessage(&m);
        Unk0bc1a8_Unk_0bc9b4(Unk0bc1a8_GetHeaderWord(w), &m);
        break;
    }
    }
}

void func_02008904(const void *src, void *dst, u32 size);
s32 func_02053800(s32 arg0, u32 mask);
int func_0205e84c(s32 *field, int a, int b, int c, int d);
void func_020655b4(u32 v);
void func_02065628(u32 v);
void func_0206563c(u32 v);
void func_020658a0(u32 v);
void func_02065bc0(void);
void func_0202e1b8(void);
void Unk0a0ce4_Unk_0a0da4(int se);
u8 *Unk02e000_Unk_02e8f0(void);

/* Run the two interaction states (4 and 5) of the entry selection flow. */
void func_02110658(Unk10fe28Work *w)
{
    u8 *sel = Unk02e000_Unk_02e8f0();

    switch (w->unk_0000) {
    case 4: {
        u32 prev = w->unk_0008;
        if (func_0205e84c((s32 *)&w->unk_0008, 0, 5, 1, 0) != 0) {
            switch (w->unk_000c) {
            case 1: {
                u32 cur = w->unk_0008;
                s32 delta = cur - prev;
                if (cur == 4) {
                    /* The original wraps the cursor with a do/while so one
                     * movement step that lands on entry 4 is skipped. */
                    do {
                        w->unk_0008 += delta;
                    } while (w->unk_0008 == 4);
                }
                break;
            }
            }
            func_02061f10(w->unk_0054, -1, 0, 0, Unk10fe28_Unk_10fe28(w));
            Unk0a0ce4_Unk_0a0da4(0);
            break;
        }
        if (func_02053800(0, 1) != 0) {
            Unk0a0ce4_Unk_0a0da4(1);
            switch (w->unk_0008) {
            case 0:
                w->unk_0010 = sel[2];
                w->unk_0000 = 5;
                break;
            case 1:
                w->unk_0010 = sel[1];
                w->unk_0000 = 5;
                break;
            case 2:
                w->unk_0010 = sel[0];
                w->unk_0000 = 5;
                break;
            case 3:
                w->unk_0010 = sel[3];
                w->unk_0000 = 5;
                break;
            case 4:
                w->unk_0000 = 6;
                Unk0bc1a8_SetFlag4Inv(w, 0);
                {
                    u32 entry = func_0204fed8(func_0204fe68(w->unk_0018, 0), 0);
                    func_02065bc0();
                    func_020655b4(1);
                    func_0206563c(1);
                    func_02065628(1);
                    func_020658a0(entry);
                }
                break;
            case 5:
                func_0205257c(3);
                w->unk_0000 = 10;
                Unk0bc1a8_SetFlag4Inv(w, 0);
                break;
            }
            break;
        }
        if (func_02053800(0, 2) == 0) {
            break;
        }
        if (w->unk_0008 == 5) {
            Unk0a0ce4_Unk_0a0da4(3);
            func_0205257c(3);
            w->unk_0000 = 10;
            Unk0bc1a8_SetFlag4Inv(w, 0);
            w->unk_0014 = 0;
            func_02008904(w->unk_0058, sel, 8);
            func_0202e1b8();
            break;
        }
        Unk0a0ce4_Unk_0a0da4(0);
        w->unk_0008 = 5;
        func_02061f10(w->unk_0054, -1, 0, 0, Unk10fe28_Unk_10fe28(w));
        break;
    }
    case 5:
        if (func_02053800(0, 1) != 0) {
            Unk0a0ce4_Unk_0a0da4(1);
            switch (w->unk_0008) {
            case 0:
                if (sel[2] != w->unk_0010) {
                    sel[2] = w->unk_0010;
                    w->unk_0014 = 1;
                }
                break;
            case 1:
                if (sel[1] != w->unk_0010) {
                    sel[1] = w->unk_0010;
                    w->unk_0014 = 1;
                }
                break;
            case 2:
                if (sel[0] != w->unk_0010) {
                    sel[0] = w->unk_0010;
                    w->unk_0014 = 1;
                }
                break;
            case 3:
                if (sel[3] != w->unk_0010) {
                    sel[3] = w->unk_0010;
                    w->unk_0014 = 1;
                }
                break;
            }
            func_0202e1b8();
            w->unk_0000 = 4;
            break;
        }
        if (func_02053800(0, 2) != 0) {
            Unk0a0ce4_Unk_0a0da4(2);
            w->unk_0000 = 4;
            break;
        }
        {
            /* Entry 3 uses the narrow cursor mode; the original setup feeds
             * mode 1 there and mode 3 elsewhere to func_0205e84c. */
            int mode = 3;
            if (w->unk_0008 == 3) {
                mode = 1;
            }
            switch (w->unk_0008) {
            case 0:
            case 1:
            case 2:
            case 3:
                if (func_0205e84c((s32 *)&w->unk_0010, 0, mode, 0, 1) == 1) {
                    Unk0a0ce4_Unk_0a0da4(0);
                }
                break;
            }
        }
        break;
    }
}
