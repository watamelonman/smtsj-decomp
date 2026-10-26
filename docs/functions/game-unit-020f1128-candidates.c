/* Best-attempt snapshot for M1-T877, not linked into the image.
 * Production src/game/unit_020f1128.c keeps only the 100% functions; the three
 * below remain supplied by the delinked object. Measured with the production
 * mwccarm flags: func_020f1128 98.73%, func_020f1914 81.02%, func_020f21b0 92.32%.
 * Remaining blockers are recorded in docs/functions/game-unit-020f1128.md.
 */
#include "types.h"

/* Twelve-byte provider row. +2 is a halfword threshold and +4 a byte cost,
 * as stored by the initializer at 020f1128. */
typedef struct {
    u16 id;
    u16 required;
    u8 cost;
    u8 unk5[3];
    void *entry;
} Unk0f1128_Row;
/* Provider object: halfwords at +0 (id), +4 (cost) and +6 (threshold).
 * The low bytes are extracted as bitfields, matching the original lsl/lsr. */
typedef struct {
    u16 id;
    u16 unk2;
    u16 cost : 8;
    u16 cost_hi : 8;
    u16 required : 8;
    u16 required_hi : 8;
} Unk0f1128_Provider;
/* Partial work layout established by loads/stores in 020f2bfc..020f2e78. */
typedef struct {
    void *handle0, *handle4, *handle8, *handlec;
    int fade, ticks;
    float progress;
    int selected;
    int first;
    u8 status;
    u8 unk25[3];
    u32 count;
    Unk0f1128_Row rows[100];
    void *handles[2];
    int state;
    int next_state;
    u8 timer;
    u8 unk4ed[3];
    int flag;
    int flag4f4, pending;
    u8 cooldown;
} Unk0f1128_Work;
/* Callback descriptor uses word-sized slots; slot 2 is preserved. */
typedef struct {
    u32 size, flags, reserved;
    void (*callbacks[6])(void *);
} Unk0f1128_Descriptor;
/* Two control bytes followed by sixteen words passed to 020bc9f4. */
typedef struct { u8 flags[2]; u32 words[16]; } Unk0f1128_Control;

extern int CampStatus_Unk_0dde3c(u32, int, int, const int *, int);
extern void Unk0bd5f0_Unk_0c7f70(int, int, const u32 *, int);
extern void func_020f1700(void *);
extern void func_020f1914(void *);
extern void func_020f21b0(void *);
extern void func_020f14ec(void *, void *);
extern void func_0205ddb4(void *);
extern void func_0205c368(void *);
extern void func_02061424(void *);
extern void func_020629c4(void *);
extern void func_02063920(Unk0f1128_Work *);
extern void *func_020445f4(int, int);
extern void *func_0204fed8(void *, u16);
extern void *func_02063a30(void *);
extern void func_02061f10(void *, int, int, int, void *);
extern void Unk0a0ce4_Unk_0a0da4(int);
extern void *Unk02cad4_GetUnk00(void);
extern void func_0205257c(int);
extern void func_020bc9f4(int, const void *, ...);
extern void Unk0bc1a8_Unk_0bc504(Unk0f1128_Work *, int);
extern void *Unk0986ac_Unk_098978(u16);
extern int Unk0986ac_Thunk_02098714(void);
extern void Unk0986ac_Unk_09895c(void *);
extern u8 Unk0986ac_Unk_098980(void);
extern void *func_0205dcd4(const char *, u32);
extern void *func_0205c2c4(const char *);
extern void *Unk065e88_Call_02065fc0(u32, u32, u32, u32);
extern void func_0205c408(void *, int);
extern void func_0205c6f8(void *);
extern void *func_020629ac(int, int, int, int);
extern void func_02061e98(void *, int, int);
extern void func_02008848(void *, int, u32);
extern int Unk09974c_Unk_0998d8(int);
extern Unk0f1128_Provider *Unk09974c_Unk_099d78(int);
extern int Unk09974c_HasFlagsMid(Unk0f1128_Provider *);
extern int Unk0f0eac_Unk_0f1000(const void *, const void *);
extern void func_02013c68(void *, u32, u32, int (*)(const void *, const void *));
extern const char data_02150dd4[], data_02150de4[];
void func_020f2bfc(Unk0f1128_Work *work);
void func_020f2c90(Unk0f1128_Work *work);
void Unk0f1128_Unk_0f2d30(u32, int);
void Unk0f1128_Unk_0f2d60(u32);
extern void Unk065e88_SetFlag3a(void *, int);
extern int func_020537b8(int, int);
extern int func_020537dc(int, int);
extern int func_02053824(int, int);
extern int func_02053800(int, int);
extern void Unk0986ac_Unk_09894c(void *);
extern int Unk0f0eac_Compare(const void *, const void *);
extern int func_020f1020(const void *, const void *);
extern int func_020f10a4(const void *, const void *);
extern void func_020f7bac(u16, int, int);
extern void Unk0bc1a8_Unk_0bc928(int, int);
extern void Unk0bc1a8_SetFlag4Inv(void *, int);
void func_020f2d80(Unk0f1128_Work *work);
void func_020f2e1c(Unk0f1128_Work *work);

/* 020f1128 builds the provider table and the initial control request.
 * Rows borrow provider fields and a lookup result keyed by provider id. */
void func_020f1128(Unk0f1128_Work *work)
{
    void *context;
    int i, j, id;
    Unk0f1128_Control control;

    work->unk25[0] = 1;
    work->fade = 250;
    work->ticks = 0;
    work->progress = 0.0f;
    work->selected = 0;
    work->first = 0;
    work->cooldown = 0;
    work->state = 4;
    work->next_state = 13;
    work->status = Unk0986ac_Unk_098980();
    work->pending = 0;

    work->handle0 = func_0205dcd4(data_02150dd4, 1);
    work->handle4 = func_0205c2c4(data_02150de4);
    work->handles[0] = Unk065e88_Call_02065fc0((u32)work->handle0, (u32)work->handle4, 0, 0);
    work->handles[1] = Unk065e88_Call_02065fc0((u32)work->handle0, (u32)work->handle4, 0, 0);
    func_0205c408(*(void **)work->handles[0], 17);
    func_0205c6f8(*(void **)work->handles[0]);
    Unk065e88_SetFlag3a(work->handles[0], 0);
    *(int *)((u8 *)work->handles[0] + 0x24) = 3;
    func_0205c408(*(void **)work->handles[1], 18);
    func_0205c6f8(*(void **)work->handles[1]);
    Unk065e88_SetFlag3a(work->handles[1], 0);
    *(int *)((u8 *)work->handles[1] + 0x24) = 3;

    work->handle8 = func_020629ac(4, 5, 1, 1);
    func_02061e98(work->handle8, 16, 1);
    work->handlec = func_020629ac(3, 1, 1, 1);
    func_02061e98(work->handlec, 16, 1);
    Unk0f1128_Unk_0f2d30((u32)work->handlec, (s8)work->unk25[0]);

    func_02008848(work->rows, 0, 0x4b0);
    work->count = 0;
    context = func_020445f4(6, 0);
    for (id = 111; id <= 210; id++) {
        Unk0f1128_Provider *provider;
        if (!Unk09974c_Unk_0998d8(id)) continue;
        provider = Unk09974c_Unk_099d78(id);
        if (Unk09974c_HasFlagsMid(provider)) continue;
        work->rows[work->count].id = provider->id;
        work->rows[work->count].cost = provider->cost;
        work->rows[work->count].entry = func_0204fed8(context, provider->id);
        work->rows[work->count].required = provider->required;
        Unk0986ac_Unk_098978(provider->id);
        if (Unk0986ac_Thunk_02098714()) {
            if ((int)work->status < (int)provider->cost) work->status = 0;
            else work->status -= provider->cost;
        }
        work->count++;
    }
    func_02013c68(work->rows, work->count, 12, Unk0f0eac_Unk_0f1000);
    func_020f2c90(work);
    Unk0f1128_Unk_0f2d60(work->rows[work->selected].id);
    Unk0986ac_Unk_098978(138);
    if (Unk0986ac_Thunk_02098714()) {
        work->status = 7;
        for (i = 0; i < work->count; i++) {
            Unk0986ac_Unk_098978(work->rows[i].id);
            if (Unk0986ac_Thunk_02098714()) work->status--;
        }
    }

    for (j = 0; j < 2; j++) control.flags[j] = 0;
    for (j = 0; j < 16; j++) control.words[j] = 0;
    control.words[2] = 1;
    control.words[3] = 2;
    control.flags[0] |= 0xc;
    func_020bc9f4(2, &control, control.flags[0], 1, control.words[3], control.words[2]);
    func_020bc9f4(1, &control);
}

/* The original 020f21ac is a bare return: this callback has no work. */
void Unk0f1128_Nop_0f21ac(void) { }

/* 020f1490 writes size 0x500 and six callback addresses, preserving slot 2. */
void func_020f1490(Unk0f1128_Descriptor *descriptor)
{
    descriptor->size = 0x500;
    descriptor->flags = 0;
    descriptor->callbacks[0] = func_020f1700;
    descriptor->callbacks[1] = func_020f1914;
    descriptor->callbacks[2] = (void (*)(void *))Unk0f1128_Nop_0f21ac;
    descriptor->callbacks[3] = func_020f21b0;
    descriptor->callbacks[4] = (void (*)(void *))func_020f2bfc;
    descriptor->callbacks[5] = (void (*)(void *))func_020f14ec;
}

/* 020f2bfc releases the observed handles and clears each released slot. */
void func_020f2bfc(Unk0f1128_Work *work)
{
    int i;
    if (work->handle0) { func_0205ddb4(work->handle0); work->handle0 = 0; }
    if (work->handle4) { func_0205c368(work->handle4); work->handle4 = 0; }
    for (i = 0; i < 2; i++) {
        func_02061424(work->handles[i]);
        work->handles[i] = 0;
    }
    func_020629c4(work->handle8);
    if (work->handle8) work->handle8 = 0;
    func_020629c4(work->handlec);
    if (work->handlec) work->handlec = 0;
}

/* 020f2c90 processes at most eighteen rows; submits the final result if nonnull. */
void func_020f2c90(Unk0f1128_Work *work)
{
    void *last;
    void *context;
    int i;
    func_02063920(work);
    last = 0;
    context = func_020445f4(6, 0);
    for (i = work->first; i < work->count; i++) {
        if (i >= work->first + 18) break;
        last = func_02063a30(func_0204fed8(context, work->rows[i].id));
    }
    if (last) func_02061f10(work->handle8, -1, 0, 0, last);
}

/* 020f2d30 submits one integer, biased by 200, with command pair 12/23. */
void Unk0f1128_Unk_0f2d30(u32 arg0, int arg1)
{
    int value = arg1 + 200;
    CampStatus_Unk_0dde3c(arg0, 12, 23, &value, 1);
}

/* 020f2d60 forwards one stack-resident word under command 7. */
void Unk0f1128_Unk_0f2d60(u32 value)
{
    u32 argument = value;
    Unk0bd5f0_Unk_0c7f70(7, 0, &argument, 1);
}

/* 020f2d80 selects state 12 when +0x4f0 is set, otherwise clears two controls. */
void func_020f2d80(Unk0f1128_Work *work)
{
    Unk0f1128_Control control;
    int i;
    if (work->flag) {
        Unk0a0ce4_Unk_0a0da4(2);
        Unk02cad4_GetUnk00();
        func_0205257c(0);
        work->state = 12;
        return;
    }
    for (i = 0; i < 2; i++) control.flags[i] = 0;
    for (i = 0; i < 16; i++) control.words[i] = 0;
    func_020bc9f4(1, &control);
    func_020bc9f4(0, &control);
    Unk0bc1a8_Unk_0bc504(work, 1);
}

/* 020f2e1c visits every row id and caches the final byte returned by 02098980. */
void func_020f2e1c(Unk0f1128_Work *work)
{
    int i;
    for (i = 0; i < work->count; i++) {
        void *entry = Unk0986ac_Unk_098978(work->rows[i].id);
        if (Unk0986ac_Thunk_02098714()) Unk0986ac_Unk_09895c(entry);
    }
    work->status = Unk0986ac_Unk_098980();
}

extern int func_02052728(void);
extern void func_0205c6e0(void *);
extern void Unk065e88_SetFlag3a(void *, int);
extern int Unk0bc1a8_IsSlotEmpty(int);
extern void Unk0bc1a8_Unk_0bc928(int, int);
extern int func_02050074(int, int);
extern void func_020f7bac(u16, int, int);
extern void Unk0bc1a8_Unk_0bc9b4(int, int);
extern void Unk0bc1a8_SetFlag4Inv(void *, int);

/* 020f1700 advances states 4/9/10/11/12 and expires the byte at +0x4fc.
 * The callback borrows a full work allocation; handle prefixes contain pointers. */
void func_020f1700(void *argument)
{
    Unk0f1128_Work *work = argument;
    switch (work->state) {
    case 4:
        if (!func_02052728()) {
            if (work->fade > 0) work->fade -= 25;
            if (work->ticks < 10) {
                work->ticks++;
                work->progress = (float)work->ticks / 10.0f;
            }
            if (work->fade >= 0 && work->ticks >= 10) {
                work->state = work->next_state;
                func_0205c6e0(*(void **)work->handles[0]);
                Unk065e88_SetFlag3a(work->handles[0], 1);
                func_0205c6e0(*(void **)work->handles[1]);
                Unk065e88_SetFlag3a(work->handles[1], 1);
            }
        }
        break;
    case 11:
        if (Unk0bc1a8_IsSlotEmpty(7)) {
            work->state = 9;
            work->timer = 0;
            Unk0bc1a8_Unk_0bc928(7, 4);
            if (func_02050074(1, 29) == 1) {
                func_020f7bac(32, 0, 0);
                Unk0a0ce4_Unk_0a0da4(13);
            } else {
                func_020f7bac((u16)(func_02050074(1, 7) + 24), 0, 0);
                Unk0a0ce4_Unk_0a0da4(4);
            }
            work->state = 9;
        }
        break;
    case 9:
    case 10:
        work->timer++;
        if (work->timer > 16) work->timer = 16;
        break;
    case 12:
        if (!func_02052728()) {
            Unk0bc1a8_Unk_0bc9b4(0, 0);
            Unk0bc1a8_Unk_0bc9b4(2, 0);
            Unk0bc1a8_Unk_0bc9b4(1, 0);
            Unk0bc1a8_Unk_0bc9b4(3, 0);
            Unk0bc1a8_Unk_0bc9b4(10, 0);
            Unk0bc1a8_Unk_0bc504(work, 0);
        }
        break;
    }
    if (work->cooldown) {
        work->cooldown--;
        if (!work->cooldown) Unk0bc1a8_SetFlag4Inv(work, 1);
    }
}

/* 020f1914 is the state-13 input callback: it handles column/row navigation,
 * selected-entry activation, and the three sort modes. Providers and rows are
 * borrowed; the two mode-change paths use distinct comparator symbols. */
void func_020f1914(void *argument)
{
    Unk0f1128_Work *w = argument;
    int old, mode, i;
    if (w->state != 13) return;
    if (func_020537b8(0, 512) && ((u8 *)w->handles[0])[0x3a])
        Unk065e88_SetFlag3a(w->handles[0], 0);
    else if (func_020537dc(0, 512) && !((u8 *)w->handles[0])[0x3a])
        Unk065e88_SetFlag3a(w->handles[0], 1);
    if (func_020537b8(0, 256) && ((u8 *)w->handles[1])[0x3a])
        Unk065e88_SetFlag3a(w->handles[1], 0);
    else if (func_020537dc(0, 256) && !((u8 *)w->handles[1])[0x3a])
        Unk065e88_SetFlag3a(w->handles[1], 1);
    old = w->selected;
    mode = (s8)w->unk25[0];
    if (func_02053824(0, 64)) {
        w->selected -= 2;
        if (w->count > 18 && w->selected < w->first) {
            w->first -= 2; func_020f2c90(w);
        }
        if (w->selected % 2 == 0) {
            if (w->selected < 0) {
                w->selected += w->count;
                if (w->selected % 2) w->selected++;
                if (w->count > 18) {
                    w->first = (s16)(w->count - 18);
                    if (w->first % 2) w->first++;
                    func_020f2c90(w);
                }
            }
        } else if (w->selected < 0) {
            w->selected += w->count;
            if (w->count > 18) {
                w->first = (s16)(w->count - 18);
                if (w->first % 2) w->first++;
                func_020f2c90(w);
            }
        }
    } else if (func_02053824(0, 128)) {
        w->selected += 2;
        if (w->selected - w->first >= 18) {
            w->first += 2; func_020f2c90(w);
        }
        if (w->selected % 2 == 0) {
            if (w->selected >= w->count) {
                w->selected = w->first = 0; func_020f2c90(w);
            }
        } else if (w->selected == w->count) w->selected = (s16)(w->count - 1);
        else if (w->selected > w->count) {
            w->selected -= w->count; w->first = 0; func_020f2c90(w);
        }
    } else if (func_02053824(0, 32) || func_02053824(0, 16)) {
        if (w->selected % 2 == 0) {
            if (w->selected < w->count - 1) w->selected++;
        } else w->selected--;
    } else if (func_02053800(0, 1)) {
        if (w->flag4f4) {
            void *entry = Unk0986ac_Unk_098978(w->rows[w->selected].id);
            if (Unk0986ac_Thunk_02098714()) {
                Unk0986ac_Unk_09895c(entry);
                Unk0986ac_Unk_098978(138);
                if (Unk0986ac_Thunk_02098714()) w->status++;
                else w->status += w->rows[w->selected].cost;
                if (w->rows[w->selected].id == 138) {
                    func_020f2e1c(w); w->status = Unk0986ac_Unk_098980();
                }
                Unk0a0ce4_Unk_0a0da4(35);
            } else {
                int enough, changed = 0;
                Unk0f1128_Provider *selected;
                Unk0986ac_Unk_098978(138);
                enough = Unk0986ac_Thunk_02098714() && w->status >= 1;
                if (!enough) {
                    Unk0986ac_Unk_098978(138);
                    enough = !Unk0986ac_Thunk_02098714() && w->status >= w->rows[w->selected].cost;
                }
                if (enough) {
                    if (w->rows[w->selected].id == 138) { func_020f2e1c(w); w->status = 7; }
                    selected = Unk09974c_Unk_099d78(w->rows[w->selected].id);
                    if ((selected->required >> 8) & 63) {
                        for (i = 0; i < w->count; i++) {
                            Unk0f1128_Provider *other = Unk09974c_Unk_099d78(w->rows[i].id);
                            void *other_entry = Unk0986ac_Unk_098978(w->rows[i].id);
                            if (Unk0986ac_Thunk_02098714() &&
                                ((selected->required >> 8) & 63) == ((other->required >> 8) & 63)) {
                                Unk0986ac_Unk_09895c(other_entry);
                                Unk0986ac_Unk_098978(138);
                                if (Unk0986ac_Thunk_02098714()) w->status++;
                                else w->status += (u8)other->cost;
                                changed = 1;
                            }
                        }
                    }
                    Unk0986ac_Unk_09894c(entry);
                    Unk0986ac_Unk_098978(138);
                    if (Unk0986ac_Thunk_02098714()) w->status--;
                    else w->status -= w->rows[w->selected].cost;
                    Unk0a0ce4_Unk_0a0da4(changed ? 35 : 38);
                    if (w->rows[w->selected].id == 139) {
                        Unk0986ac_Unk_098978(139);
                        if (Unk0986ac_Thunk_02098714()) {
                            w->pending = 1; w->state = 10; w->timer = 0;
                            Unk0bc1a8_Unk_0bc928(7, 4); func_020f7bac(23, 0, 1);
                            Unk065e88_SetFlag3a(w->handles[0], 0);
                            Unk065e88_SetFlag3a(w->handles[1], 0);
                        }
                    }
                } else Unk0a0ce4_Unk_0a0da4(4);
            }
        }
    } else if (func_02053800(0, 1024)) {
        if (w->flag4f4) {
            w->state = 9; w->timer = 0;
            Unk0bc1a8_Unk_0bc928(7, 4); func_020f7bac(1, 0, 1);
            Unk065e88_SetFlag3a(w->handles[0], 0);
            Unk065e88_SetFlag3a(w->handles[1], 0);
            Unk0a0ce4_Unk_0a0da4(1);
        }
    } else if (func_02053800(0, 512)) {
        Unk065e88_SetFlag3a(w->handles[0], 0);
        w->unk25[0]--;
        if ((s8)w->unk25[0] < 0) w->unk25[0] = 2;
        Unk0f1128_Unk_0f2d30((u32)w->handlec, (s8)w->unk25[0]);
        switch ((s8)w->unk25[0]) {
        case 0: func_02013c68(w->rows, w->count, 12, Unk0f0eac_Compare); break;
        case 1: func_02013c68(w->rows, w->count, 12, Unk0f0eac_Unk_0f1000); break;
        case 2: func_02013c68(w->rows, w->count, 12, func_020f1020); break;
        }
        func_020f2c90(w); Unk0a0ce4_Unk_0a0da4(11);
        Unk0bc1a8_SetFlag4Inv(w, 0); w->cooldown = 2;
    } else if (func_02053800(0, 256)) {
        Unk065e88_SetFlag3a(w->handles[1], 0);
        w->unk25[0]++;
        if ((s8)w->unk25[0] > 2) w->unk25[0] = 0;
        Unk0f1128_Unk_0f2d30((u32)w->handlec, (s8)w->unk25[0]);
        switch ((s8)w->unk25[0]) {
        case 0: func_02013c68(w->rows, w->count, 12, Unk0f0eac_Compare); break;
        case 1: func_02013c68(w->rows, w->count, 12, Unk0f0eac_Unk_0f1000); break;
        case 2: func_02013c68(w->rows, w->count, 12, func_020f10a4); break;
        }
        func_020f2c90(w); Unk0a0ce4_Unk_0a0da4(11);
        Unk0bc1a8_SetFlag4Inv(w, 0); w->cooldown = 2;
    } else if (func_02053824(0, 2)) {
        Unk065e88_SetFlag3a(w->handles[0], 0);
        Unk065e88_SetFlag3a(w->handles[1], 0); func_020f2d80(w);
    }
    if (old != w->selected || mode != (s8)w->unk25[0]) {
        Unk0f1128_Unk_0f2d60(w->rows[w->selected].id);
        if (old != w->selected) Unk0a0ce4_Unk_0a0da4(0);
    }
}

extern void func_02057e58(int, int, int);
extern void func_02057eb8(int);
extern void func_02057fd8(void);
extern void func_02057df8(void);
extern void func_02057ddc(u32);
extern void func_0205dee8(int, void *, int, int, int, float, float, int, float, int);
extern void func_02058f10(int, int, int, int, int, int, int);
extern void func_020c83a0(void);
extern void func_02057e18(int);
extern void func_020ddf38(void *);
extern int func_02061a04(void *, int, int);
extern void Unk0ddeb0_Unk_0ddeb0(void *, int, int, int, int, int);
extern int func_020a9e14(int, const void *);
extern void func_020a9fd8(int, int, int, int, int, int, const void *, ...);
extern void Unk0bd5f0_Unk_0c842c(void);
extern void func_02057dcc(u32, u32, u32, u32);
extern void func_02057524(int);
extern void func_02057534(void);
extern void func_02057d54(int, int, int, int, int, int);
extern void *data_0215f05c[];
extern const u8 data_02150df4[], data_02150df8[], data_02150dfc[];
extern const u8 data_02150e00[], data_02150e04[], data_02150e08[];
extern const u8 data_02150e0c[], data_02150e10[];

/* 020f21b0 draws the state-13 list and its later state branches. Resource
 * handles and row data are borrowed; grid offsets are pixels. */
void func_020f21b0(void *argument)
{
    Unk0f1128_Work *w = argument;
    u32 count, height, offset;
    int row, column, i, x, y, font;
    func_02057e58(3, 10, 20);
    func_02057eb8(3);
    func_02057fd8();
    func_0205dee8(2, w->handle0, 55, w->fade, 0, 1.0f, 1.0f, 0, w->progress, 1);
    func_02057fd8();
    func_02058f10(2, 0x1d69, w->fade, 0, 1, 126, 2);
    func_0205dee8(2, w->handle0, 65, 0, 0, 1.0f, 1.0f, 0, w->progress, 1);
    func_0205dee8(2, w->handle0, 69, 0, 0, 1.0f, 1.0f, 0, w->progress, 1);
    func_02057fd8();
    count = w->count;
    if (count < 18) count = 18;
    height = ((0x12000U / count) * 116) >> 12;
    offset = (((u32)((w->first / 2) << 12) / ((count & 1) + (count >> 1) - 9)) * (116 - height)) >> 12;
    func_02058f10(2, 0x1d6a, w->fade, offset, 1, height, 2);
    func_02057fd8();
    func_0205dee8(2, w->handle0, 57, w->fade, 0, 1.0f, 1.0f, 0, w->progress, 2);
    for (row = 0; row < 9; row++) {
        for (column = 0; column < 2; column++) {
            Unk0986ac_Unk_098978(w->rows[w->first + row * 2 + column].id);
            if (!Unk0986ac_Thunk_02098714()) {
                int disabled;
                Unk0986ac_Unk_098978(138);
                disabled = Unk0986ac_Thunk_02098714() && w->status == 0;
                if (!disabled) {
                    Unk0986ac_Unk_098978(138);
                    disabled = !Unk0986ac_Thunk_02098714() &&
                        w->rows[w->first + row * 2 + column].cost > w->status;
                }
                if (disabled)
                    func_0205dee8(2, w->handle0, 61, w->fade + column * 122, row * 13, 1.0f, 1.0f, 0, w->progress, 2);
                else
                    func_0205dee8(2, w->handle0, 59, w->fade + column * 122, row * 13, 1.0f, 1.0f, 0, w->progress, 2);
            } else {
                func_0205dee8(2, w->handle0, 59, w->fade + column * 122, row * 13, 1.0f, 1.0f, 0, w->progress, 2);
            }
        }
    }
    func_02057ddc(0x00ffffff);
    func_0205dee8(2, w->handle0, 66, 0, 0, 1.0f, 1.0f, 0, w->progress, 2);
    func_0205dee8(2, w->handle0, 67, 0, 0, 1.0f, 1.0f, 0, w->progress, 2);
    func_02057fd8(); func_02057df8();
    func_0205dee8(2, w->handle0, 68, 0, 0, 1.0f, 1.0f, 0, w->progress, 2);
    func_0205dee8(2, w->handle0, 70, 0, 0, 1.0f, 1.0f, 0, w->progress, 2);
    func_0205dee8(2, w->handle0, 58, w->fade, 0, 1.0f, 1.0f, 0, w->progress, 3);
    if (w->state == 13) {
        int enabled;
        func_02057fd8(); func_020c83a0();
        x = (w->selected % 2) * 122;
        y = ((w->selected - w->first) / 2) * 13;
        Unk0986ac_Unk_098978(w->rows[w->selected].id);
        enabled = Unk0986ac_Thunk_02098714();
        if (enabled) {
            func_0205dee8(2, w->handle0, 60, x, y, 1.0f, 1.0f, 0, 1.0f, 4);
        } else {
            Unk0986ac_Unk_098978(138);
            enabled = Unk0986ac_Thunk_02098714() && w->status >= 1;
            if (!enabled) {
                Unk0986ac_Unk_098978(138);
                enabled = !Unk0986ac_Thunk_02098714() && w->rows[w->selected].cost <= w->status;
            }
            if (enabled) func_0205dee8(2, w->handle0, 60, x, y, 1.0f, 1.0f, 0, 1.0f, 4);
        }
        func_02057fd8();
        func_020ddf38(data_0215f05c[6]);
        func_02057e18(31);
        func_02058f10(2, 0x1d77, x, y, 119, 12, 5);
        func_02057e18(31);
    }
    func_02057fd8();
    func_0205dee8(2, w->handle0, 63, w->fade, 0, 1.0f, 1.0f, 0, w->progress, 6);
    func_02057df8();
    if (w->progress > 0.0f) {
        int width;
        func_02057fd8();
        width = func_02061a04(((void **)w->handlec)[10], ((int *)w->handlec)[5], 0);
        Unk0ddeb0_Unk_0ddeb0(w->handlec, (48 - width) / 2 + 122, 6, 0, 5, 10);
        func_02057df8();
        font = func_020a9e14(1, data_02150df4);
        func_020a9fd8(1, 223, 9, 2, font, 10, data_02150df8, w->status);
        Unk0986ac_Unk_098978(138);
        if (Unk0986ac_Thunk_02098714())
            func_020a9fd8(1, 241, 9, 2, font, 10, data_02150dfc, 7);
        else {
            int status = Unk0986ac_Unk_098980();
            func_020a9fd8(1, 241, 9, 2, font, 10, data_02150e00, status);
        }
        func_020a9fd8(1, 235, 9, 0, 1, 10, data_02150e04);
    }
    Unk0bd5f0_Unk_0c842c();
    for (i = 0; i < 18; i++) {
        if (!w->rows[w->first + i].id) continue;
        x = i % 2 == 0 ? 0 : 122;
        func_02057df8();
        font = func_020a9e14(1, data_02150e08);
        Unk0986ac_Unk_098978(138);
        y = (i / 2) * 13;
        if (Unk0986ac_Thunk_02098714())
            func_020a9fd8(1, x + 111 + w->fade, y + 35, 2, font, 10, data_02150e0c, 1);
        else
            func_020a9fd8(1, x + 111 + w->fade, y + 35, 2, font, 10, data_02150e10, w->rows[w->first + i].cost);
        Unk0986ac_Unk_098978(w->rows[w->first + i].id);
        if (Unk0986ac_Thunk_02098714()) {
            func_0205dee8(2, w->handle0, 64, x + w->fade, y, 1.0f, 1.0f, 0, 1.0f, 10);
            func_02057dcc(0xff942100, 0xff942100, 0xff942100, 0xff942100);
            Unk0ddeb0_Unk_0ddeb0(w->handle8, x + 21 + w->fade, y + 32, i, 8, 10);
        } else {
            int disabled;
            Unk0986ac_Unk_098978(138);
            disabled = Unk0986ac_Thunk_02098714() && w->status < 1;
            if (!disabled) {
                Unk0986ac_Unk_098978(138);
                disabled = !Unk0986ac_Thunk_02098714() && w->status < w->rows[w->first + i].cost;
            }
            if (disabled) func_02057dcc(0x7b7b7b00, 0x7b7b7b00, 0x7b7b7b00, 0x7b7b7b00);
            Unk0ddeb0_Unk_0ddeb0(w->handle8, x + 21 + w->fade, y + 32, i, 8, 10);
        }
    }
    func_02057524(6);
    if ((u32)(w->state - 9) <= 1) {
        func_02057fd8();
        if ((u8)(w->timer * 24 / 16) >= 1) {
            func_02057e18((u8)(w->timer * 24 / 16));
            func_02057d54(0, 0, 0, 256, 192, 21);
            func_02057e18(31);
        }
    }
    func_02057534(); func_02057eb8(-1);
}

/* Borrowed message payload: flags select which word values are present. */
typedef struct { u8 flags; u8 pad[3]; int words[16]; } Unk0f1128_Message;
/* Borrowed callback envelope; payload immediately follows the event word. */
typedef struct { u32 event; Unk0f1128_Message payload; } Unk0f1128_Event;

/* Payload words are loaded before testing presence, as in the callback loads. */
static inline int ReadMessage(Unk0f1128_Message *message, int index, int *value)
{
    if (!message) return 0;
    {
        int present = message->flags & (1 << index);
        int word = message->words[index];
        if (present) {
            *value = word;
            return 1;
        }
        return 0;
    }
}

/* 020f14ec reads event 0/3 payload flags and updates selection completion.
 * Message words are consumed synchronously; work and payload remain borrowed. */
void func_020f14ec(void *argument, void *event_argument)
{
    int value[1] = {0};
    Unk0f1128_Work *work = argument;
    Unk0f1128_Event *event = event_argument;
    Unk0f1128_Message *message = &event->payload;
    switch (event->event) {
    case 0:
        work->flag = 0;
        work->flag4f4 = 0;
        if (ReadMessage(message, 3, value)) {
            if (value[0] == 1) {
                work->flag = 1;
                work->flag4f4 = 1;
            }
            if (value[0] == 2) work->flag = 1;
        }
        break;
    case 1:
    case 2:
    case 4:
        break;
    case 3:
        if (ReadMessage(message, 0, value) && value[0] == 7) {
            if (work->pending) {
                int cancel = 0;
                if (work->state == 10) {
                    if (ReadMessage(message, 3, value)) {
                        if (value[0] == 0) work->state = 11;
                        else cancel = 1;
                    } else cancel = 1;
                } else cancel = 1;
                if (cancel) {
                    work->pending = 0;
                    work->state = 13;
                    Unk0986ac_Unk_09895c(Unk0986ac_Unk_098978(work->rows[work->selected].id));
                    Unk0986ac_Unk_098978(138);
                    if (Unk0986ac_Thunk_02098714()) work->status++;
                    else work->status += work->rows[work->selected].cost;
                    Unk065e88_SetFlag3a(work->handles[0], 1);
                    Unk065e88_SetFlag3a(work->handles[1], 1);
                }
            } else {
                work->state = 13;
                Unk065e88_SetFlag3a(work->handles[0], 1);
                Unk065e88_SetFlag3a(work->handles[1], 1);
                if (ReadMessage(message, 3, value) && value[0] == 0) func_020f2e1c(work);
            }
        }
        break;
    }
}

