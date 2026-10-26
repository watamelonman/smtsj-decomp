#include "types.h"

/* Only the fields touched by this callback are modeled. */
typedef struct Unk0ee01cWork {
    u8 pad_0000[0x41c];
    u8 unk_041c[0x24a8 - 0x41c];
    u8 pad_24a8[0x7480 - 0x24a8];
    s8 unk_7480;
    s8 unk_7481;
} Unk0ee01cWork;

/* Three fixed-point components, copied from the original constant records. */
typedef struct Unk0ee01cVector { s32 x, y, z; } Unk0ee01cVector;
/* The called routines consume nine words and sixteen words respectively. */
typedef struct Unk0ee01cMatrix { s32 v[9]; } Unk0ee01cMatrix;
typedef struct Unk0ee01cContext { u32 v[16]; } Unk0ee01cContext;
typedef struct Unk0ee01cGlobal { u8 pad_00[0xfc]; u32 unk_fc; } Unk0ee01cGlobal;

extern const Unk0ee01cVector data_0213c870, data_0213c87c;
extern Unk0ee01cMatrix data_02156de4;
extern Unk0ee01cGlobal data_02156d28;
extern void func_02057830(s32);
extern void func_020580ec(s32);
extern void func_02058724(Unk0ee01cVector *, Unk0ee01cVector *);
extern void func_020586d0(s32, s32, s32, s32, s32);
extern void func_02057494(Unk0ee01cVector *, Unk0ee01cVector *);
extern void func_02022468(Unk0ee01cVector *);
extern void func_02000edc(Unk0ee01cMatrix *, s32, s32);
extern void func_020087dc(Unk0ee01cMatrix *, Unk0ee01cMatrix *);
extern void func_0202242c(void);
extern void func_02022d40(void *);
extern void func_020572d8(void);
extern void func_02057df8(void);
extern void func_020222d8(void);
extern void func_020251c8(void);
extern void func_02001784(Unk0ee01cContext *);
extern void func_02004600(Unk0ee01cContext *);

/* Reset the graphics context for substates 4..6; the signed +0x7481
 * field and the original graphics call sequence are the available evidence. */
void func_020ee01c(Unk0ee01cWork *work)
{
    if (work->unk_7481 < 4 || work->unk_7481 > 6) return;
    func_02057830(0);
    func_020580ec(0);
    Unk0ee01cVector a = data_0213c870;
    Unk0ee01cVector b = data_0213c87c;
    func_02058724(&a, &b);
    func_020586d0(0x579, 0xf09, 0x1555, 0x1000, 0x190000);
    func_02057494(&a, &b);
    Unk0ee01cVector zero = {0, 0, 0};
    func_02022468(&zero);
    Unk0ee01cMatrix matrix = {{0}};
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
    Unk0ee01cContext context;
    func_02001784(&context);
    func_02004600(&context);
    func_020580ec(1);
}

/* Each comparison key is an opaque record pointer; the queried pair is signed. */
typedef struct Pair { s16 first, second; } Pair;
extern void func_02049c28(void *, Pair *);

/* Compare the first signed pair components, treating absent records as 256.
 * Evidence: the callback is passed to the six-entry sort in func_020ee1d4. */
s32 func_020ee184(void *const *left, void *const *right)
{
    s32 a = 256, b = 256;
    Pair pa, pb;
    if (*left) {
        func_02049c28(*left, &pa);
        a = pa.first;
    }
    if (*right) {
        func_02049c28(*right, &pb);
        b = pb.first;
    }
    return a - b;
}

