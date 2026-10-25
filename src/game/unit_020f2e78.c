#include "types.h"

/* Partial state layout; offsets are established by the original byte/word loads. */
typedef struct Unk0f2e78State {
    struct Unk0f2e78Root *root;
    u8 pad_0004[0x28 - 4];
    s16 unk_0028[16]; /* Guessed extent: indexed by a four-bit cell field. */
    u8 pad_0048[0x58 - 0x48];
    u16 unk_0058;
    u8 pad_005a[0xa4 - 0x5a];
    s32 unk_00a4;
    u8 unk_00a8[0x73cc - 0xa8];
    s32 unk_73cc;
    u8 pad_73d0[4];
    s32 unk_73d4;
    s32 unk_73d8;
    s32 unk_73dc;
    u8 pad_73e0[0x7440 - 0x73e0];
    s32 unk_7440;
    u8 pad_7444[0x7478 - 0x7444];
    s32 unk_7478;
    u8 pad_747c[4];
    s8 unk_7480;
    s8 unk_7481;
    s8 unk_7482;
    s8 unk_7483;
    s32 unk_7484;
    s32 unk_7488;
    s32 unk_748c;
    s32 unk_7490;
} Unk0f2e78State;

int func_020f2e78(Unk0f2e78State *state);
int func_020f307c(Unk0f2e78State *state);
int func_020f347c(Unk0f2e78State *state);
int func_020f370c(Unk0f2e78State *state);
int func_020f362c(Unk0f2e78State *state);
int func_020f3920(Unk0f2e78State *state);
void func_020f3a78(Unk0f2e78State *state);
void func_020a269c(int value);
void func_0205257c(int value);
void Unk0a4e48_Unk_0a4e9c(int value);
int func_020a4f3c(void);
int func_02052728(void);
int func_020654cc(void);
int func_020a25e0(void);

/* Advance the three-phase sequence, waiting for the four subsystem predicates
 * before resetting the state. Meaning of the subsystem values is unresolved. */
int func_020f362c(Unk0f2e78State *state)
{
    state->unk_7484++;
    switch (state->unk_7481) {
    case 0:
        func_020a269c(0);
        func_0205257c(3);
        Unk0a4e48_Unk_0a4e9c(2);
        state->unk_7481++;
        break;
    case 1:
        if (func_020a4f3c() == 0 && func_02052728() == 0 &&
            func_020654cc() != 0 && func_020a25e0() != 0) {
            state->unk_7481++;
        }
        break;
    case 2:
        state->unk_73dc = 1;
        state->unk_7478 = 0;
        state->unk_7480 = 0;
        state->unk_7481 = 0;
        state->unk_7484 = 0;
        state->unk_73cc = 8;
        break;
    }
    return 0;
}

/* Dispatch the six state kinds stored at +0x7480, preserving a zero result
 * for selectors outside 0..5. Each handler borrows the same state. */
int func_020f3ca8(Unk0f2e78State *state)
{
    int result = 0;
    switch (state->unk_7480) {
    case 0: result = func_020f2e78(state); break;
    case 1: result = func_020f307c(state); break;
    case 2: result = func_020f347c(state); break;
    case 3: result = func_020f370c(state); break;
    case 4: result = func_020f362c(state); break;
    case 5: result = func_020f3920(state); break;
    }
    return result;
}

/* Invoke the common setup only in the original kind/phase combinations.
 * The signed phase bounds intentionally reject negative values. */
void func_020f3d28(Unk0f2e78State *state)
{
    switch (state->unk_7480) {
    case 0: break;
    case 1: func_020f3a78(state); break;
    case 2:
        if (state->unk_7481 != 3) func_020f3a78(state);
        break;
    case 3:
        if (state->unk_7481 >= 0 && state->unk_7481 <= 1) func_020f3a78(state);
        break;
    case 4: func_020f3a78(state); break;
    case 5:
        if (state->unk_7481 >= 0 && state->unk_7481 <= 1) func_020f3a78(state);
        break;
    }
}


/* Only the two sequence-control words are known in this borrowed root. */
typedef struct Unk0f2e78Root {
    u8 pad_0000[0x14];
    s32 unk_0014;
    s32 unk_0018;
} Unk0f2e78Root;
/* Work-area direction and id, as loaded by the coordinate advance. */
typedef struct Unk0f2e78Work {
    u8 pad_0000[0x358];
    volatile u32 unk_0358;
    u16 unk_035c;
    u8 pad_035e[6];
    s8 unk_0364;
    s8 unk_0365;
} Unk0f2e78Work;
Unk0f2e78Work *Unk02e000_GetWorkArea(void);
void func_02034b7c(int id, int x, int y, u32 direction,
                   int kind, int a, int b, int c);

/* Step the cached cell one square in the work-area direction after the
 * subsystem finishes; report completion once +0x7440 becomes nonzero. */
int func_020f3920(Unk0f2e78State *state)
{
    int result = 0;
    state->unk_7484++;
    switch (state->unk_7481) {
    case 0:
        if (func_020654cc() == 1) {
            func_0205257c(3);
            state->root->unk_0014 = 4;
            state->root->unk_0018 = 3;
            state->unk_7484 = 0;
            state->unk_7481++;
        }
        break;
    case 1:
        if (func_02052728() == 0) {
            Unk0f2e78Work *work = Unk02e000_GetWorkArea();
            int x = state->unk_7482;
            int y = state->unk_7483;
            switch (work->unk_0358) {
            case 0: y--; break;
            case 1: x++; break;
            case 2: y++; break;
            case 3: x--; break;
            }
            func_02034b7c(work->unk_035c, x, y, work->unk_0358, 3, 0, 0, 1);
            state->unk_7484 = 0;
            state->unk_7481++;
        }
        break;
    case 2:
        if (state->unk_7440 != 0) result = 1;
        break;
    default: result = 1; break;
    }
    return result;
}

void func_0205e590(int value);
void ScanVisor_Unk_0a2acc(void);
void SaveLoadTask_SelectEntry(int value);
int Unk0e1648_Unk_0e1648(void);
void func_020525cc(int value);
void func_0205e484(int value, int kind);
/* Only the four-bit selector at bits 20..23 is used here. */
typedef struct Unk0f2e78Cell {
    u32 unk_0000;
    u32 pad_0004_low : 20;
    u32 unk_0004_selector : 4;
    u32 pad_0004_high : 8;
} Unk0f2e78Cell;
Unk0f2e78Cell *Unk038fbc_Unk_039160(void *map, int x, int y);

/* Run the five-phase sequence, including selection 6 and a cell-selected
 * sound below id 29. The called APIs establish these operations; the overall
 * sequence purpose is unresolved. */
int func_020f347c(Unk0f2e78State *state)
{
    state->unk_7484++;
    switch (state->unk_7481) {
    case 0:
        func_020a269c(0);
        func_0205257c(3);
        func_0205e590(9);
        state->unk_7481++;
        break;
    case 1:
        if (func_02052728() == 0 && func_020654cc() != 0 && func_020a25e0() != 0) {
            ScanVisor_Unk_0a2acc();
            state->unk_7481++;
        }
        break;
    case 2:
        SaveLoadTask_SelectEntry(6);
        state->unk_7481++;
        break;
    case 3:
        if (Unk0e1648_Unk_0e1648() != 0) {
            int selector;
            int sound;
            Unk0f2e78Work *a;
            Unk0f2e78Work *b;
            Unk0f2e78Cell *cell;
            func_020525cc(3);
            func_020a269c(1);
            selector = 0;
            a = Unk02e000_GetWorkArea();
            b = Unk02e000_GetWorkArea();
            cell = Unk038fbc_Unk_039160((u8 *)state + 0x240, a->unk_0364, b->unk_0365);
            if (cell != 0) selector = cell->unk_0004_selector;
            sound = state->unk_0028[selector];
            if (sound < 29) {
                func_0205e484(sound, 9);
                state->unk_73d4 = sound;
            }
            state->unk_7481++;
        }
        break;
    case 4:
        if (func_02052728() == 0) state->unk_7481++;
        break;
    default:
        if (func_020654cc() != 0) {
            state->unk_7480 = 1;
            state->unk_7484 = 0;
            state->unk_7481 = 0;
        }
        break;
    }
    return 0;
}

/* Current cell's leading flags and timer are reset together. */
typedef struct Unk0f2e78CellHead {
    u8 unk_0000;
    u8 unk_0001;
    u16 unk_0002;
} Unk0f2e78CellHead;
/* Record 5 supplies the bit selector at +0x19. */
typedef struct Unk0f2e78Record {
    u8 pad_0000[0x19];
    u8 unk_0019;
} Unk0f2e78Record;
Unk0f2e78Record *Unk09a268_Unk_09c484(int index);
Unk0f2e78CellHead *Unk02f2a8_GetCurrentCell38e8(void);
int Unk02f078_Unk_02f0d8(void);
void Unk09a268_Unk_09a80c(Unk0f2e78CellHead *cell, int value);
void Unk09a268_Unk_09a830(Unk0f2e78CellHead *cell, int value);
void Unk09a268_SetOnlyBit(Unk0f2e78CellHead *cell, int bit);
void Unk0a0ce4_Unk_0a0da4(int value);
void func_02052d7c(void *work, int value);

/* Configure the current cell from record 5, or enter phase 3 when the mode
 * or +0x73dc requests it. The cell flag and timer stores establish the reset. */
void func_020f3be0(Unk0f2e78State *state)
{
    Unk0f2e78Record *record = Unk09a268_Unk_09c484(5);
    Unk0f2e78CellHead *cell = Unk02f2a8_GetCurrentCell38e8();
    if (Unk02f078_Unk_02f0d8() == 2 || state->unk_73dc == 1) {
        state->unk_7480 = 0;
        state->unk_7481 = 3;
        state->unk_7484 = 0;
        state->unk_7488 = 0;
        if (state->unk_73dc == 1) state->unk_7488 = 2;
    } else {
        Unk09a268_Unk_09a80c(cell, 1);
        Unk09a268_Unk_09a830(cell, 0);
        Unk09a268_SetOnlyBit(cell, record->unk_0019);
        cell->unk_0001 = 1;
        cell->unk_0002 = 0;
        Unk0a0ce4_Unk_0a0da4(state->unk_0058);
        func_02052d7c(state->unk_00a8, state->unk_00a4);
    }
    state->unk_748c = 1;
    state->unk_7490 = 1;
    state->unk_7480 = 0;
}

void func_02052da0(void);
void Unk09a268_Unk_09a870(Unk0f2e78CellHead *cell, int value);
void ScanVisor_Unk_0a2a8c(int index);
void ScanVisor_Unk_0a2b38(void);
void Unk095560_Unk_09615c(void);
void func_020396cc(void *body);
void Unk02f2a8_Unk_0343b4(void *body);
void Unk09974c_Unk_09974c(void *work);
void Unk11f2d0_Unk_11f2d0(void *work);
int func_020395f8(void *body, const void *data);
void Unk02f078_Unk_02f0c4(void);
extern const u8 data_02150e14[];

/* Execute the timed five-phase transition. The original waits 40, 10 and 2
 * ticks, clears seven visor slots, and resets the cached cell timer. */
int func_020f2e78(Unk0f2e78State *state)
{
    Unk0f2e78CellHead *cell = Unk02f2a8_GetCurrentCell38e8();
    int result = 0;
    func_02052da0();
    state->unk_7484++;
    cell->unk_0002++;
    switch (state->unk_7481) {
    case 0:
        if (state->unk_7484 > 40) {
            Unk09a268_Unk_09a870(cell, 0);
            state->root->unk_0014 = 2;
            state->root->unk_0018 = 2;
            state->unk_7484 = 0;
            state->unk_7481++;
        }
        break;
    case 1:
        if (state->unk_7484 > 10) {
            func_0205257c(3);
            state->unk_7484 = 0;
            state->unk_7481++;
        }
        break;
    case 2:
        if (func_02052728() == 0) {
            int i;
            ScanVisor_Unk_0a2acc();
            for (i = 0; i < 7; i++) ScanVisor_Unk_0a2a8c(i);
            state->unk_7484 = 0;
            state->unk_7481++;
        }
        break;
    case 3:
        state->unk_73d8 = 0;
        ScanVisor_Unk_0a2b38();
        Unk095560_Unk_09615c();
        func_020396cc((u8 *)state + 4);
        Unk02f2a8_Unk_0343b4((u8 *)state + 4);
        Unk09974c_Unk_09974c((u8 *)state + 0x7550);
        Unk11f2d0_Unk_11f2d0((u8 *)state + 0x7598);
        state->unk_7484 = 0;
        state->unk_7481++;
        break;
    case 4:
        if (state->unk_7484 > 2 && func_020395f8((u8 *)state + 4, data_02150e14) == 1) {
            func_020525cc(3);
            if (Unk02f078_Unk_02f0d8() == 2 || state->unk_73dc == 1) {
                Unk02f078_Unk_02f0c4();
                state->unk_73dc = 0;
                Unk0a4e48_Unk_0a4e9c(0);
                func_020a269c(1);
            }
            state->unk_7484 = 0;
            state->unk_7481 = 0;
            state->unk_7480 = 1;
        }
        break;
    default: result = 1; break;
    }
    return result;
}

/* Three fixed-point components, copied from the original constant records. */
typedef struct Unk0f2e78Vector { s32 x, y, z; } Unk0f2e78Vector;
/* The called routines consume nine words and sixteen words respectively. */
typedef struct Unk0f2e78Matrix { s32 v[9]; } Unk0f2e78Matrix;
typedef struct Unk0f2e78Context { u32 v[16]; } Unk0f2e78Context;
typedef struct Unk0f2e78Global { u8 pad_00[0xfc]; u32 unk_fc; } Unk0f2e78Global;

extern const Unk0f2e78Vector data_0213c888, data_0213c894;
extern Unk0f2e78Matrix data_02156de4;
extern Unk0f2e78Global data_02156d28;
extern void func_02057830(s32);
extern void func_020580ec(s32);
extern void func_02058a90(void *, s32);
extern void func_02058724(Unk0f2e78Vector *, Unk0f2e78Vector *);
extern void func_020586d0(s32, s32, s32, s32, s32);
extern void func_02057494(Unk0f2e78Vector *, Unk0f2e78Vector *);
extern void func_02022468(Unk0f2e78Vector *);
extern void func_02000edc(Unk0f2e78Matrix *, s32, s32);
extern void func_020087dc(Unk0f2e78Matrix *, Unk0f2e78Matrix *);
extern void func_0202242c(void);
extern void func_02022d40(void *);
extern void func_020572d8(void);
extern void func_02057df8(void);
extern void func_020222d8(void);
extern void func_020251c8(void);
extern void func_02001784(Unk0f2e78Context *);
extern void func_02004600(Unk0f2e78Context *);


/* Reset the 128 entries at +0x24a8 and restore the shared vector/matrix
 * rendering state. MMIO writes target the original geometry registers. */
void func_020f3a78(Unk0f2e78State *state)
{
    s32 i;
    func_02057830(0);
    func_020580ec(0);
    for (i = 0; i < 128; i++) func_02058a90(state->unk_00a8 + 0x2400, i);
    Unk0f2e78Vector a = data_0213c888;
    Unk0f2e78Vector b = data_0213c894;
    func_02058724(&a, &b);
    func_020586d0(0x579, 0xf09, 0x1555, 0x1000, 0x190000);
    func_02057494(&a, &b);
    Unk0f2e78Vector zero = {0, 0, 0};
    func_02022468(&zero);
    Unk0f2e78Matrix matrix = {{0}};
    *(volatile u32 *)0x04000444 = 0;
    func_02000edc(&matrix, 0, 0x1000);
    func_020087dc(&matrix, &data_02156de4);
    data_02156d28.unk_fc &= ~0xa4;
    func_0202242c();
    func_02022d40((u8 *)state + 0x41c);
    *(volatile u32 *)0x04000448 = 1;
    func_020572d8();
    func_02057df8();
    func_020222d8();
    func_020251c8();
    Unk0f2e78Context context;
    func_02001784(&context);
    func_02004600(&context);
    func_020580ec(1);
}
