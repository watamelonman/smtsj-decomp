#include "types.h"

/* Twelve-byte records: only the leading halfword is consumed here. */
typedef struct { u16 id; u8 rest[10]; } Unk0f1128_Row;
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
extern void func_020bc9f4(int, const Unk0f1128_Control *);
extern void Unk0bc1a8_Unk_0bc504(Unk0f1128_Work *, int);
extern void *Unk0986ac_Unk_098978(u16);
extern int Unk0986ac_Thunk_02098714(void);
extern void Unk0986ac_Unk_09895c(void *);
extern u8 Unk0986ac_Unk_098980(void);
void func_020f2bfc(Unk0f1128_Work *work);

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
void Unk0f1128_Unk_0f2d30(u32 arg0, int arg1, u32 arg2, u32 arg3)
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
                    else work->status += work->rows[work->selected].rest[2];
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

