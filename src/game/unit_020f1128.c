#include "types.h"

/* Twelve-byte records: only the leading halfword is consumed here. */
typedef struct { u16 id; u8 rest[10]; } Unk0f1128_Row;
/* Partial work layout established by loads/stores in 020f2bfc..020f2e78. */
typedef struct {
    void *handle0, *handle4, *handle8, *handlec;
    u8 unk10[16];
    int first;
    u8 status;
    u8 unk25[3];
    u32 count;
    Unk0f1128_Row rows[100];
    void *handles[2];
    int state;
    u8 unk4e8[8];
    int flag;
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
extern void func_020f14ec(void *);
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
    descriptor->callbacks[5] = func_020f14ec;
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
