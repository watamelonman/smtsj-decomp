#include "types.h"

/* Offsets are established by the loads and stores in the original callbacks. */
typedef struct Unk0ff030Work {
    s32 unk_00, unk_04, unk_08, unk_0c, unk_10, unk_14, unk_18, unk_1c;
    s32 unk_20, unk_24, unk_28, unk_2c, unk_30, unk_34, unk_38, unk_3c;
} Unk0ff030Work;

typedef void (*Unk0ff030Callback)(Unk0ff030Work *);
/* Callback slots follow the pointer stores in func_020ff248; slot 8 is untouched. */
typedef struct Unk0ff030Descriptor {
    s32 size, flags, unk_08;
    Unk0ff030Callback update, next, unk_14, draw, release;
    void (*message)(Unk0ff030Work *, const void *);
} Unk0ff030Descriptor;

extern void func_02057e18(s32 value);
extern void func_02057ddc(s32 value);
extern void func_02057524(s32 value);
extern void func_02057eb8(s32 value);
extern void func_020572d8(void);
extern void func_0205ddb4(s32 handle);
extern void func_020629c4(s32 handle);
extern s32 func_02052728(void);
extern void CampStatus_Unk_0dd308(s32 *, s32, s32, s32 *, s32 *);
extern u16 *Unk02e000_Thunk_0202e788(void);
extern void CampStatus_Unk_0dde3c(s32, s32, s32, s32 *, s32);
extern void func_02060b60(s32, s32, s32, s32, s32, s32);
extern void func_0205de40(s32, s32, s32, s32, s32, float, float, s32, float, s32);
extern void func_020ff29c(Unk0ff030Work *);
extern void func_020ff638(Unk0ff030Work *);
extern void func_020ffa9c(Unk0ff030Work *, const void *);
void Unk0ff030_Unk_0ff0ec(Unk0ff030Work *work);
void func_020ff120(Unk0ff030Work *work);
void func_020ff5c0(Unk0ff030Work *work);
void Unk0ff030_Unk_0ffa60(Unk0ff030Work *work);

/* Empty callback: the original consists solely of a return instruction. */
void Unk0ff030_Nop_0ff030(void) { }

/* Submit the two operations only in an active state; state 2 consumes +0x20.
 * Evidence: original branches at 020ff044..020ff06c and call arguments. */
void func_020ff034(Unk0ff030Work *work)
{
    s32 order;
    if (work->unk_14 == 0) return;
    if (work->unk_14 == 2) {
        if (work->unk_20 == 0) return;
        work->unk_20 = 0;
    }
    Unk0ff030_Unk_0ff0ec(work);
    order = work->unk_1c;
    func_02060b60(1, work->unk_04, work->unk_0c + 14, work->unk_10 + 116, 0, order + 1);
    func_0205de40(2, work->unk_08, 0, work->unk_0c, work->unk_10, 1.0f, 1.0f, 0, 1.0f, order);
    func_020ff120(work);
}

/* Set the shared call state and apply +0x18 when nonnegative (original loads). */
void Unk0ff030_Unk_0ff0ec(Unk0ff030Work *work)
{
    func_02057e18(31);
    func_02057ddc(-1);
    func_02057524(4);
    if (work->unk_18 < 0) return;
    func_02057eb8(work->unk_18);
}

/* Restore the optional +0x18 setting and finish the operation, per call sequence. */
void func_020ff120(Unk0ff030Work *work)
{
    if (work->unk_18 >= 0) func_02057eb8(-1);
    func_020572d8();
}

/* Populate the 64-byte work descriptor; original relocations identify the slots. */
void func_020ff248(Unk0ff030Descriptor *desc)
{
    desc->size = 64;
    desc->flags = 0;
    desc->update = func_020ff5c0;
    desc->next = func_020ff29c;
    desc->unk_14 = 0;
    desc->draw = func_020ff638;
    desc->release = Unk0ff030_Unk_0ffa60;
    desc->message = func_020ffa9c;
}

/* Advance state 4 once the three observed counters reach their thresholds. */
void func_020ff5c0(Unk0ff030Work *work)
{
    if (work->unk_24 != 4) return;
    if (func_02052728() != 0) return;
    CampStatus_Unk_0dd308(&work->unk_30, -15, 1, &work->unk_34, &work->unk_38);
    if (work->unk_30 > 0) return;
    if (work->unk_34 >= 10 && work->unk_38 >= 10) work->unk_24 = work->unk_28;
}

/* Release the two handles; +4 is passed through even when zero in the original. */
void Unk0ff030_Unk_0ffa60(Unk0ff030Work *work)
{
    if (work->unk_00 != 0) {
        func_0205ddb4(work->unk_00);
        work->unk_00 = 0;
    }
    func_020629c4(work->unk_04);
    if (work->unk_04 != 0) work->unk_04 = 0;
}

/* Copy four borrowed halfwords into call-local words, replacing zero with one;
 * the original passes this array to CampStatus_Unk_0dde3c with count four. */
void func_020ffbcc(s32 handle)
{
    u16 *values = Unk02e000_Thunk_0202e788();
    s32 words[4];
    s32 i;
    words[0] = values[0];
    words[1] = values[1];
    words[2] = values[2];
    words[3] = values[3];
    for (i = 0; i < 4; i++) {
        if (words[i] == 0) words[i] = 1;
    }
    CampStatus_Unk_0dde3c(handle, 6, 0, words, 4);
}

/* Borrowed prefix: +2 selects the special path; bits 10..19 of +4
 * supply the other path's argument, as observed at 020ffcbc..020ffcf4. */
typedef struct Unk0ff030Entry {
    u8 unk_00[2];
    u8 unk_02;
    u8 unk_03;
    u32 unk_04_low : 10;
    u32 unk_04_value : 10;
    u32 unk_04_high : 12;
} Unk0ff030Entry;

/* Borrowed selection prefix passed at work +8; callers keep the difference
 * between +0x10 and +8 in the range 0..3. */
typedef struct Unk0ff030Selection {
    s32 unk_00, unk_04, unk_08, unk_0c, unk_10;
} Unk0ff030Selection;

extern Unk0ff030Entry *Unk09974c_Unk_099c60(s32);
extern s32 Unk09974c_Unk_099cc4(const Unk0ff030Entry *);
extern void func_0204faf0(s32, s32);
extern void Unk0bd5f0_Unk_0c7f70(s32, s32, const s32 *, s32);

/* Select one of four borrowed halfwords and submit its entry information.
 * Evidence: four ldrh switch arms and calls at 020ffcb8..020ffd08.
 * The caller must provide a selection difference in 0..3. */
void func_020ffc44(Unk0ff030Selection *selection)
{
    u16 *values = Unk02e000_Thunk_0202e788();
    s32 selected[1];
    Unk0ff030Entry *entry;
    switch (selection->unk_10 - selection->unk_08) {
    case 0: selected[0] = values[0]; break;
    case 1: selected[0] = values[1]; break;
    case 2: selected[0] = values[2]; break;
    case 3: selected[0] = values[3]; break;
    }
    if (selected[0] == 0) return;
    entry = Unk09974c_Unk_099c60(selected[0]);
    if ((u8)(entry->unk_02 + 253) <= 1) {
        func_0204faf0(1, Unk09974c_Unk_099cc4(entry));
    } else {
        func_0204faf0(1, entry->unk_04_value);
    }
    Unk0bd5f0_Unk_0c7f70(7, 0, selected, 1);
}

/* Two presence bytes govern sixteen optional words; alignment bytes are unused. */
typedef struct Unk0ff030Message {
    u8 flags[2], pad_02[2];
    s32 words[16];
} Unk0ff030Message;

/* Copy a borrowed word at a 32-bit DS address and mark its presence.
 * index is 0..15; value addresses a live s32. See DEC-012. */
static inline void Unk0ff030SetWord(Unk0ff030Message *message, s32 index, u32 value)
{
    message->words[index] = *(s32 *)value;
    message->flags[index / 8] |= 1 << (index % 8);
}

extern const char data_02151108[];
extern s32 func_0205dcd4(const char *, s32);
extern void Unk0bcef4_Unk_0bcef4(Unk0ff030Selection *, s32, s32, s32);
extern void func_020bc9f4(s32, Unk0ff030Message *);
extern void func_020c8210(s32);
extern s32 func_020629ac(s32, s32, s32, s32);
extern void func_02061e98(s32, s32, s32);
extern void Unk0bd5f0_Unk_0c7fbc(void);

/* Initialize the 64-byte work area, allocate its two handles, and submit the
 * initial selection. Evidence: stores and call arguments at 020ff140..020ff238. */
void func_020ff140(Unk0ff030Work *work)
{
    Unk0ff030Message message;
    s32 i;
    s32 first, second;
    work->unk_24 = 4;
    work->unk_28 = 11;
    *(u8 *)&work->unk_2c = 0;
    work->unk_30 = 150;
    work->unk_34 = 0;
    work->unk_38 = 0;
    work->unk_3c = 0;
    work->unk_00 = func_0205dcd4(data_02151108, 1);
    Unk0bcef4_Unk_0bcef4((Unk0ff030Selection *)&work->unk_08, 4, 4, 1);
    for (i = 0; i < 2; i++) message.flags[i] = 0;
    for (i = 0; i < 16; i++) message.words[i] = 0;
    first = 1;
    Unk0ff030SetWord(&message, 2, (u32)&first);
    second = 2;
    Unk0ff030SetWord(&message, 3, (u32)&second);
    func_020bc9f4(1, &message);
    func_020c8210(0);
    work->unk_04 = func_020629ac(4, 3, 1, 1);
    func_02061e98(work->unk_04, 16, 1);
    func_020ffbcc(work->unk_04);
    func_020ffc44((Unk0ff030Selection *)&work->unk_08);
    Unk0bd5f0_Unk_0c7fbc();
}

extern void Unk0bc1a8_Unk_0bc504(Unk0ff030Work *, s32);

/* Clear only the presence bytes and payload words; padding is not observed. */
static inline void Unk0ff030ClearMessage(Unk0ff030Message *message)
{
    s32 i;
    for (i = 0; i < 2; i++) message->flags[i] = 0;
    for (i = 0; i < 16; i++) message->words[i] = 0;
}

extern void func_02057fd8(void);
extern void func_0205dee8(s32, s32, s32, s32, s32, float, float, s32, float, s32);
extern s32 Unk0ca69c_Unk_0ca69c(s32);
extern void func_02058e9c(s32, s32, s32, s32, float, s32, s32);
extern void Unk0ddeb0_Unk_0ddeb0(s32, s32, s32, s32, s32, s32);
extern void func_020c83a0(void);
/* Shared object prefix: only the borrowed word at +0x18 is observed here. */
typedef struct Unk0ff030Shared { s32 unk_00[6]; s32 unk_18; } Unk0ff030Shared;
extern Unk0ff030Shared data_0215f05c;
extern s32 func_020ddf38(s32);
extern void func_02058f10(s32, s32, s32, s32, s32, s32, s32);

/* Submit the observed background pieces, four labels, optional value rows,
 * and state-dependent selection marker. Evidence: resource indices 39..45,
 * four halfword tests, and state checks 7/11 in 020ff638..020ffa54. */
void func_020ff638(Unk0ff030Work *work)
{
    s32 i, y;
    u16 *values;
    s32 selection;
    func_02057fd8();
    func_0205dee8(2, work->unk_00, 39, work->unk_30, 0, 1.0f, 1.0f, 0, *(float *)&work->unk_38, 2);
    func_02057fd8();
    func_0205dee8(2, work->unk_00, 40, work->unk_30, 0, 1.0f, 1.0f, 0, *(float *)&work->unk_38, 3);
    func_0205dee8(2, work->unk_00, 42, work->unk_30, 0, 1.0f, 1.0f, 0, *(float *)&work->unk_38, 3);
    func_02057fd8();
    func_0205dee8(2, work->unk_00, 41, work->unk_30, 0, 1.0f, 1.0f, 0, *(float *)&work->unk_38, 10);
    func_0205dee8(2, work->unk_00, 45, work->unk_30, 0, 1.0f, 1.0f, 0, *(float *)&work->unk_38, 10);
    for (i = 0, y = 15; i < 4; i++, y += 13) {
        s32 label = Unk0ca69c_Unk_0ca69c(i);
        func_02058e9c(2, label, work->unk_30 + 113, y, 1.0f, 0, 10);
    }
    values = Unk02e000_Thunk_0202e788();
    if (values[0]) Unk0ddeb0_Unk_0ddeb0(work->unk_04, work->unk_30 + 172, 14, 0, 8, 10);
    if (values[1]) Unk0ddeb0_Unk_0ddeb0(work->unk_04, work->unk_30 + 172, 27, 1, 8, 10);
    if (values[2]) Unk0ddeb0_Unk_0ddeb0(work->unk_04, work->unk_30 + 172, 40, 2, 8, 10);
    if (values[3]) Unk0ddeb0_Unk_0ddeb0(work->unk_04, work->unk_30 + 172, 53, 3, 8, 10);
    selection = work->unk_18 - work->unk_10;
    if (work->unk_24 == 7) {
        func_02057fd8();
        func_0205dee8(2, work->unk_00, 43, 0, 13 * (work->unk_18 - work->unk_10), 1.0f, 1.0f, 0, 1.0f, 4);
        if ((selection == 0 && values[0]) || (selection == 1 && values[1]) ||
            (selection == 2 && values[2]) || (selection == 3 && values[3])) func_020c83a0();
    }
    if (work->unk_24 == 11) {
        func_02057fd8();
        func_0205dee8(2, work->unk_00, 43, 0, 13 * selection, 1.0f, 1.0f, 0, 1.0f, 4);
        func_02057fd8();
        func_02057e18(func_020ddf38(data_0215f05c.unk_18));
        func_02058f10(2, 0x1d0b, 0, 13 * selection, 144, 12, 5);
        func_02057e18(31);
        if ((selection == 0 && values[0]) || (selection == 1 && values[1]) ||
            (selection == 2 && values[2]) || (selection == 3 && values[3])) func_020c83a0();
    }
}

extern s32 Unk0bcc7c_Unk_0bcdf8(Unk0ff030Selection *);
extern void Unk0a0ce4_Unk_0a0da4(s32);
extern s32 func_020537dc(s32, s32);
extern s32 func_02053800(s32, s32);
extern s32 func_02053824(s32, s32);
extern s32 Unk0bd5f0_IsState22or24(void);
extern s32 func_020c7bc8(s32, s32);
extern void func_020bcacc(s32, Unk0ff030Message *);

/* Process state 11's selection and input transitions. Evidence: state guard,
 * input masks 1/2/0x800 and outgoing slots at 020ff29c..020ff5b0. */
void func_020ff29c(Unk0ff030Work *work)
{
    if (work->unk_24 != 11) return;
    if (Unk0bcc7c_Unk_0bcdf8((Unk0ff030Selection *)&work->unk_08)) {
        work->unk_3c = 1;
        func_020ffc44((Unk0ff030Selection *)&work->unk_08);
        func_020c8210(work->unk_18 - work->unk_10);
        Unk0a0ce4_Unk_0a0da4(0);
    }
    if (work->unk_3c) {
        if (!func_020537dc(0, 64)) return;
        if (!func_020537dc(0, 128)) return;
        if (!func_020537dc(0, 32)) return;
        if (func_020537dc(0, 16)) work->unk_3c = 0;
        return;
    }
    if (!Unk0bd5f0_IsState22or24()) return;
    if (func_02053800(0, 1)) {
        s32 accepted = 0;
        switch (work->unk_18) {
        case 0: accepted = func_020c7bc8(211, 260); break;
        case 1: accepted = func_020c7bc8(261, 310); break;
        case 2: accepted = func_020c7bc8(311, 360); break;
        case 3: accepted = func_020c7bc8(361, 410); break;
        }
        if (accepted) {
            Unk0ff030Message message;
            work->unk_24 = 7;
            Unk0ff030ClearMessage(&message);
            message.words[3] = 12;
            message.flags[0] |= 8;
            func_020bcacc(2, &message);
            Unk0a0ce4_Unk_0a0da4(1);
        } else Unk0a0ce4_Unk_0a0da4(4);
    } else if (func_02053824(0, 2)) {
        Unk0ff030Message message;
        Unk0a0ce4_Unk_0a0da4(2);
        Unk0ff030ClearMessage(&message);
        func_020bc9f4(1, &message);
        message.words[3] = 9;
        message.flags[0] |= 8;
        func_020bcacc(2, &message);
        Unk0bc1a8_Unk_0bc504(work, 0);
    } else if (func_02053800(0, 2048)) {
        Unk0ff030Message message;
        Unk0ff030ClearMessage(&message);
        message.words[3] = 12;
        message.words[1] = 5;
        message.flags[0] |= 10;
        func_020bcacc(3, &message);
        Unk0ff030ClearMessage(&message);
        func_020bc9f4(5, &message);
    }
}
