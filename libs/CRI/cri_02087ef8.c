#include "types.h"

/** Borrowed state prefix; offsets are established by 020880d4's word accesses. */
typedef struct Cri02087ef8State {
    u32 unk_00;
    s32 unk_04;
    u8 pad_08[0x80];
    s32 unk_88;
    u32 unk_8c;
    s32 unk_90;
    s32 unk_94;
    u8 pad_98[0x14];
    s32 unk_ac;
    u8 pad_b0[8];
    void *unk_b8;
    u32 unk_bc;
    s32 unk_c0;
} Cri02087ef8State;

/** Borrowed parent prefix; the state pointer and two words are read during setup. */
typedef struct Cri02087ef8Parent {
    u32 unk_00;
    Cri02087ef8State *unk_04;
    u8 pad_08[0x50];
    s32 unk_58;
    s32 unk_5c;
} Cri02087ef8Parent;

/** Caller-owned context; the embedded block at +0x18 is passed without inspection. */
typedef struct Cri02087ef8Context {
    u32 unk_00;
    Cri02087ef8Parent *unk_04;
    u8 pad_08[8];
    void *unk_10;
    u32 unk_14;
    u32 unk_18;
} Cri02087ef8Context;

extern s32 data_021477f8[2];
extern char data_02148840[], data_02148868[], data_02148894[], data_021488c4[];
extern void (*data_021734ac)(Cri02087ef8Context *);
extern void (*data_02172530)(Cri02087ef8State *);
extern s32 (*data_02172524)(void *);
extern s32 (*data_02172528)(void *);
extern s32 (*data_0217252c)(void *);
extern void (*data_02172540)(void *, s32);
extern void func_0207c1e0(const char *message);
extern void func_0207efa0(void);
extern void func_020832b8(void);
extern void func_020832c4(void);
extern void func_02089ad4(void);
extern void func_02089b7c(void);
extern void *func_02089be4(void *, s32, void *, void *, s32);
extern void func_02089d84(void *);
extern void func_02089cf8(void *);
extern s32 func_02089d48(void *);
extern s32 func_02089d50(void *);
extern void func_02089d58(void *);
extern void func_0208a064(void *);
extern s32 func_0208a094(void *);
extern s32 func_0208a08c(void *);
extern void func_0208a09c(void *, s32, s32);
extern void func_0208a0c8(void *, s32);
extern s32 func_0208a0d8(void *);
extern s32 func_0208a0e0(void *);
extern void func_0208a0ec(void *, s32);
void func_02088040(Cri02087ef8Context *context);
void func_02088060(Cri02087ef8Context *context);
s32 func_020880bc(void *handle);
s32 func_020880c8(void *handle);
void func_020880d4(Cri02087ef8State *state);

/** Copy the two global words to optional caller-owned outputs (02087ef8..7f14). */
void func_02087ef8(s32 *first, s32 *second)
{
    if (first) *first = data_021477f8[0];
    if (second) *second = data_021477f8[1];
}

/** Validate setup storage (at least 0x1800 bytes), then install the observed callbacks. */
void func_02087f20(Cri02087ef8Context *context, void *storage, s32 size)
{
    Cri02087ef8Parent *parent;
    Cri02087ef8State *state;
    void *source;
    void *handle;
    if (!context || !storage) { func_0207c1e0(data_02148840); return; }
    if (size < 0x1800) { func_0207c1e0(data_02148868); return; }
    func_0207efa0();
    func_02088040(context);
    func_02089ad4();
    parent = context->unk_04;
    source = context->unk_10;
    state = parent->unk_04;
    func_020832b8();
    handle = func_02089be4(source, 1, &context->unk_18, storage, size);
    if (!handle) { func_0207c1e0(data_02148894); return; }
    state->unk_b8 = handle;
    data_021734ac = func_02088060;
    data_02172530 = func_020880d4;
    data_02172524 = func_020880c8;
    data_02172528 = func_020880bc;
    data_0217252c = func_02089d50;
    data_02172540 = func_0208a0c8;
    func_0208a09c(handle, parent->unk_58, parent->unk_5c);
    func_020832c4();
}

/** Invoke the optional context callback; the indirect call is visible at 02088054. */
void func_02088040(Cri02087ef8Context *context)
{
    if (data_021734ac) data_021734ac(context);
}

/** Release a present state handle, clearing its borrowed slot before final teardown. */
void func_02088060(Cri02087ef8Context *context)
{
    Cri02087ef8State *state;
    void *handle;
    if (!context) { func_0207c1e0(data_021488c4); return; }
    func_0207efa0();
    state = context->unk_04->unk_04;
    handle = state->unk_b8;
    if (!handle) return;
    func_020832b8();
    func_02089d84(handle);
    func_02089cf8(handle);
    state->unk_b8 = 0;
    func_020832c4();
    func_02089b7c();
}

/** Forward the opaque handle to the provider selected by the 020880bc tail branch. */
s32 func_020880bc(void *handle) { return func_0208a0d8(handle); }

/** Forward the opaque handle to the provider selected by the 020880c8 tail branch. */
s32 func_020880c8(void *handle) { return func_0208a0e0(handle); }

/** Advance states 1/2 and update cumulative/delta words, following 020880d4..81cc. */
void func_020880d4(Cri02087ef8State *state)
{
    void *handle = state->unk_b8;
    s32 i;
    if (func_02089d48(handle) == 0) {
        state->unk_90 = 0;
        state->unk_88 = 0;
        func_02089d84(handle);
    }
    if (state->unk_04 == 1) {
        if (state->unk_ac == 0) func_0208a0ec(handle, 0);
        else func_0208a0ec(handle, 1);
        state->unk_88 = 0;
        func_02089d58(handle);
        state->unk_04 = 2;
    } else if (state->unk_04 == 2) {
        for (i = 0; i < state->unk_c0; i++) func_0208a064(handle);
        state->unk_90 = func_0208a094(handle) - state->unk_88;
        state->unk_88 += state->unk_90;
        state->unk_94 = func_0208a08c(handle);
        if (func_02089d48(handle) == 3) {
            func_02089d84(handle);
            state->unk_04 = 0;
        }
    }
}
