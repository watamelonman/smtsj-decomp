#include "types.h"

/* Only the fields touched by this callback are modeled. */
typedef struct Unk0f6f48Work {
    u8 pad_0000[0x41c];
    u8 unk_041c[0x24a8 - 0x41c];
    u8 unk_24a8[0x7480 - 0x24a8];
    s8 unk_7480;
    s8 unk_7481;
} Unk0f6f48Work;

/* Three fixed-point components, copied from the original constant records. */
typedef struct Unk0f6f48Vector { s32 x, y, z; } Unk0f6f48Vector;
/* The called routines consume nine words and sixteen words respectively. */
typedef struct Unk0f6f48Matrix { s32 v[9]; } Unk0f6f48Matrix;
typedef struct Unk0f6f48Context { u32 v[16]; } Unk0f6f48Context;
typedef struct Unk0f6f48Global { u8 pad_00[0xfc]; u32 unk_fc; } Unk0f6f48Global;

extern const Unk0f6f48Vector data_0213c96c, data_0213c978;
extern Unk0f6f48Matrix data_02156de4;
extern Unk0f6f48Global data_02156d28;
extern void func_02057830(s32);
extern void func_020580ec(s32);
extern void func_02058a90(void *, s32);
extern void func_02058724(Unk0f6f48Vector *, Unk0f6f48Vector *);
extern void func_020586d0(s32, s32, s32, s32, s32);
extern void func_02057494(Unk0f6f48Vector *, Unk0f6f48Vector *);
extern void func_02022468(Unk0f6f48Vector *);
extern void func_02000edc(Unk0f6f48Matrix *, s32, s32);
extern void func_020087dc(Unk0f6f48Matrix *, Unk0f6f48Matrix *);
extern void func_0202242c(void);
extern void func_02022d40(void *);
extern void func_020572d8(void);
extern void func_02057df8(void);
extern void func_020222d8(void);
extern void func_020251c8(void);
extern void func_02001784(Unk0f6f48Context *);
extern void func_02004600(Unk0f6f48Context *);

/* Run the observed reset sequence for state 2, or eligible substates 0..1.
 * Evidence: signed fields at 0x7480/0x7481 gate the 128-entry reset and calls below. */
void func_020f6f48(Unk0f6f48Work *work)
{
    s32 i;
    switch (work->unk_7480) {
    case 0:
    case 1:
        return;
    case 3:
        if (work->unk_7481 < 0 || work->unk_7481 > 1) return;
        break;
    default:
        if (work->unk_7481 < 0 || work->unk_7481 > 1) return;
        break;
    case 2:
        break;
    }
    func_02057830(0);
    func_020580ec(0);
    for (i = 0; i < 128; i++) func_02058a90(work->unk_24a8, i);
    Unk0f6f48Vector a = data_0213c96c;
    Unk0f6f48Vector b = data_0213c978;
    func_02058724(&a, &b);
    func_020586d0(0x579, 0xf09, 0x1555, 0x1000, 0x190000);
    func_02057494(&a, &b);
    Unk0f6f48Vector zero = {0, 0, 0};
    func_02022468(&zero);
    Unk0f6f48Matrix matrix = {{0}};
    *(volatile u32 *)0x04000444 = 0;
    func_02000edc(&matrix, 0, 0x1000);
    func_020087dc(&matrix, &data_02156de4);
    data_02156d28.unk_fc &= ~0xa4;
    func_0202242c();
    func_02022d40(work->unk_041c);
    *(volatile u32 *)0x04000448 = 1;
    func_020572d8();
    func_02057df8();
    func_020222d8();
    func_020251c8();
    Unk0f6f48Context context;
    func_02001784(&context);
    func_02004600(&context);
    func_020580ec(1);
}

/* A 0x40-byte record; signed scalar and callback meanings remain unknown. */
typedef struct Unk0f6f48Record {
    u32 unk_00, unk_04, unk_08, unk_0c;
    s32 unk_10, unk_14, unk_18;
    u32 unk_1c, unk_20;
    s32 unk_24;
    u32 unk_28, unk_2c, unk_30;
    void (*unk_34)(void);
    void (*unk_38)(void);
    u32 unk_3c;
} Unk0f6f48Record;

/* Initialize all sixteen words, preserving the supplied handles and callbacks.
 * Callers such as func_020eec4c supply a handle, signed values and two callbacks. */
void func_020f711c(Unk0f6f48Record *record, u32 handle, s32 value, u32 a, u32 b, s32 c, u32 d, u32 e, void (*f)(void), void (*g)(void), u32 h)
{
    record->unk_00 = handle;
    record->unk_04 = 0xffff;
    record->unk_08 = 1;
    record->unk_0c = 1;
    record->unk_10 = value;
    record->unk_14 = 0;
    record->unk_18 = value;
    record->unk_1c = a;
    record->unk_20 = b;
    record->unk_24 = c;
    record->unk_28 = 0;
    record->unk_2c = d;
    record->unk_30 = e;
    record->unk_34 = f;
    record->unk_38 = g;
    record->unk_3c = h;
}
