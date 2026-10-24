#include "GameState.h"
#include "types.h"

void func_0203428c(void);
void func_0206146c(void);
void func_02057660(int a, int b);

/* Block returned by the unit_0202e000 accessor. Several units borrow it, so
 * this file only assumes the parts it actually reads. */
u8 *Unk02e000_Unk_02e774(void);

/* Local typed view of the work area returned by Unk02e000_GetWorkArea.
 * include/ is not owned by this card, so only the members read here are typed;
 * other members are still reached through byte offsets. */
typedef struct Unk02f2a8WorkArea {
    u8 pad_0000[0x358];
    u32 unk_0358;               /* direction/heading word */
    u16 unk_035c;               /* id latched by SetField35c */
    u8 pad_035e[6];
    s8 unk_0364;                /* cached grid coordinates set by SetGridPos */
    s8 unk_0365;
    s8 unk_0366;
    s8 unk_0367;
    u8 pad_0368[0xaf2 - 0x368];
    u16 unk_0af2;               /* 16-bit pair reset by Unk_036488 */
    u16 unk_0af4;
} Unk02f2a8WorkArea;

/* Tail of GameState past the range declared by include/GameState.h (not owned
 * by this card): the cached grid source and teardown counter live there. */
typedef struct Unk02f2a8GameStateTail {
    u8 pad_0000[0x73dc];
    u32 unk_73dc;               /* nonzero suppresses the ResetField7478Ex notifies */
    u8 pad_73e0[0x744e - 0x73e0];
    s8 unk_744e;
    s8 unk_744f;
    s32 unk_7450;
    u8 pad_7454[0x7470 - 0x7454];
    u32 unk_7470;               /* set to 1 by SetField7470 with the 3 values below */
    u16 unk_7474;
    u8 unk_7476;
    u8 unk_7477;
    u32 unk_7478;               /* +0x7478..+0x748b cleared by ResetField7478Ex */
    u8 pad_747c[4];
    u8 unk_7480;
    u8 unk_7481;
    u8 pad_7482[2];
    u32 unk_7484;
    u32 unk_7488;
    u8 pad_748c[0x74f0 - 0x748c];
    u32 unk_74f0;
} Unk02f2a8GameStateTail;

/* Local view of an action whose +0x18 word is folded into the work-area
 * direction (+0x358); Unk02f2a8_Unk_02fc10 clears its +0x1c word. Action type 3
 * (Unk02f2a8_Unk_02f8ac) uses the same object and sets +0x9c. */
typedef struct Unk02f2a8Action {
    u32 unk_0000;               /* word handed to 0209aca0 by Unk_03034c */
    u32 unk_0004;
    u8 pad_0008[0x10 - 8];
    u32 unk_0010;
    u32 unk_0014;
    u32 unk_0018;
    u32 unk_001c;
    u32 unk_0020;               /* latched by func_020300ec for mask 0x800 */
    u32 unk_0024;               /* mask 0x400 */
    u32 unk_0028;               /* mask 0x100 */
    u32 unk_002c;               /* mask 0x200 */
    u32 unk_0030;               /* mask 0xf3 */
    u8 pad_0034[0x9c - 0x34];
    u32 unk_009c;
} Unk02f2a8Action;

/* Borrowed root fields used when arming and resetting the state. */
typedef struct Unk02f2a8StateRoot {
    u8 pad_0000[4];
    u32 unk_0004;
    u8 pad_0008[0x10 - 8];
    u32 unk_0010;
    u32 unk_0014;               /* 1/2/0 stored by Unk_032f3c */
    u32 unk_0018;
    u32 unk_001c;
    u8 pad_0020[0x34 - 0x20];
    u32 unk_0034;
    u32 unk_0038;
    u8 pad_003c[8];
    u32 unk_0044;
    u8 pad_0048[4];
    u32 unk_004c;
    u32 unk_0050;
    u32 unk_0054;
    u8 pad_0058[0x7c - 0x58];
    u8 unk_007c[0x94 - 0x7c];   /* size guessed: position block passed to func_0203721c */
    u16 unk_0094;
} Unk02f2a8StateRoot;

/* One map block embedded in the body Unk02f2a8_Unk_034970 picks from; only
 * its extent (the distance between the two blocks) is known. */
typedef struct Unk02f2a8MapBlock {
    u32 unk_0000;               /* nonzero required by Unk_0351b4 */
    u8 *unk_0004;               /* byte table indexed by 034a8c's result + 15 */
    u8 pad_0008[0x2c8 - 0x23c - 8];
} Unk02f2a8MapBlock;

/* Body view used by Unk02f2a8_Unk_034970 (callers pass state +4). */
typedef struct Unk02f2a8Body {
    u8 pad_0000[0x24];
    s16 unk_0024[6]; /* size guessed: indexed by bits 20..23 of a cell word (func_020305a8) */
    s8 unk_0030[15]; /* size guessed: indexed by a 4-bit cell id minus 1 */
    u8 pad_003f[0x57 - 0x3f];
    u8 unk_0057;                /* level byte passed to func_0203721c (state +0x5b) */
    u8 pad_0058[0x214 - 0x58];
    u8 unk_0214[0x23c - 0x214]; /* size guessed: buffer handed to func_020a7474 (state +0x218) */
    Unk02f2a8MapBlock unk_023c;
    Unk02f2a8MapBlock unk_02c8;
} Unk02f2a8Body;

/* Local view of state fields beyond the public GameState layout. */
typedef struct Unk02f2a8State {
    Unk02f2a8StateRoot *root;
    Unk02f2a8Body body;         /* +0x0004 */
    u8 unk_0358[0x3134 - 0x358]; /* buffer sizes up to 0x7330 guessed from the next known field */
    u8 unk_3134[0xc];
    u8 unk_3140[0xc];
    u8 unk_314c[0x3154 - 0x314c]; /* sub-object of unknown size */
    u8 unk_3154[0x38e8 - 0x3154];
    u8 unk_38e8[0x631c - 0x38e8]; /* 45-wide cell table */
    u8 unk_631c[0x7130 - 0x631c];
    u8 unk_7130[0x7330 - 0x7130];
    u8 unk_7330[0x73c8 - 0x7330];
    u32 unk_73c8;
    u32 unk_73cc;
    u32 unk_73d0;
    u8 pad_73d4[4];
    u32 unk_73d8;
    u8 pad_73dc[4];
    u32 unk_73e0;
    u32 unk_73e4;
    u32 unk_73e8;
    u32 unk_73ec;
    u8 pad_73f0[0x7400 - 0x73f0];
    u32 unk_7400;               /* nonzero suppresses the func_0203721c rebuild */
    u8 pad_7404[0x743c - 0x7404];
    u32 unk_743c;
    u8 pad_7440[0x7478 - 0x7440];
    u32 unk_7478;               /* +0x7478..+0x748b cleared by Unk_032f3c */
    u32 unk_747c;
    u8 unk_7480;
    u8 unk_7481;
    u8 pad_7482[2];
    u32 unk_7484;
    u32 unk_7488;
    u8 pad_748c[0x7494 - 0x748c];
    u32 unk_7494;
    u32 unk_7498;               /* nonzero arms root +0x54 in func_02032d4c */
    u8 pad_749c[0x757c - 0x749c];
    u32 unk_757c;
    u8 pad_7580[0x18];
    u32 unk_7598;
} Unk02f2a8State;

Unk02f2a8WorkArea *Unk02e000_GetWorkArea(void);

/* Clear bit 0 of the 64-entry byte table at the Unk02e000_Unk_02e774 block
 * +0x5e12. Ids outside 0..63 are ignored, not clamped, so a bad selector
 * leaves the table untouched. */
void Unk02f2a8_ClearEntry5e12Bit0(int i)
{
    if (i >= 64) {
        return;
    }
    if (i < 0) {
        return;
    }
    {
        u8 *p = (u8 *)Unk02e000_Unk_02e774() + 0x5e12;
        p[i] &= ~1;
    }
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int func_0204b4c4();
int func_0204ca1c();
int func_0204b710();
void func_0202f3d8();
void func_0209aca0();
void func_02116598();
void Unk02f2a8_ApplyPending(u8 *p);
void Unk02f2a8_Unk_02fc10(Unk02f2a8Action *action);
void Unk02f2a8_Unk_02f8ac(Unk02f2a8Action *action);
void Unk02f2a8_Unk_0302f4(Unk02f2a8Action *action);
void Unk02f2a8_Unk_02f378(u8 *p);

/* Typed view of the three slot words in the Unk02e000_Unk_02e774 block that
 * Unk02f2a8_SetField6138 writes. */
typedef struct Unk02f2a8Slots6138 {
    u8 pad_0000[0x6138];
    u32 unk_6138;
    u32 unk_613c;
    u32 unk_6140;
} Unk02f2a8Slots6138;

/* Read slot 1..3 at block +0x6138/+0x613c/+0x6140 (the paired
 * SetField6138 stores there); an invalid selector returns zero. */
u32 Unk02f2a8_GetSlot_02f2dc(int i)
{
    Unk02f2a8Slots6138 *w = (Unk02f2a8Slots6138 *)Unk02e000_Unk_02e774();
    switch (i) {
    case 1: return w->unk_6138;
    case 2: return w->unk_613c;
    case 3: return w->unk_6140;
    }
    return 0;
}

/* Store v in slot k (1..3) of the Unk02e000_Unk_02e774 block, the words at
 * +0x6138/+0x613c/+0x6140 that Unk02f2a8_GetSlot_02f2dc reads back with the
 * same 1-based selector. Any other k is ignored. */
void Unk02f2a8_SetField6138(int k, u32 v)
{
    Unk02f2a8Slots6138 *w = (Unk02f2a8Slots6138 *)Unk02e000_Unk_02e774();
    switch (k) {
    case 1:
        w->unk_6138 = v;
        break;
    case 2:
        w->unk_613c = v;
        break;
    case 3:
        w->unk_6140 = v;
        break;
    }
}

/* Empty callback; callers install these slots but the original does nothing. */
void Unk02f2a8_Nop_0303c8(void) { }
/* Empty callback paired with the slot above at 0x0303CC. */
void Unk02f2a8_Nop_0303cc(void) { }
void func_02035db8(s32 *out, int x, int z);
int Unk02f2a8_SetGridPos(int x, int y, u32 v);
void func_0209e0b0(void);
int Unk095560_Thunk_020961a0(void);

/* Grid-state view: the body Unk02f2a8_Unk_034970 reads sits at +4, followed
 * far later by the latched sound id and the +0x7478 grid fields. */
typedef struct Unk02f2a8GridState {
    u32 unk_0000;
    Unk02f2a8Body body;
    u8 pad_0358[0x73d4 - 0x358];
    s32 unk_73d4;               /* last id handed to func_0205e484 by func_020305a8 */
    u8 pad_73d8[0x73e0 - 0x73d8];
    u32 unk_73e0;               /* 1 suppresses the non-forced func_020305a8 update */
    u8 pad_73e4[0x7478 - 0x73e4];
    u32 unk_7478;
    u8 pad_747c[4];
    u8 unk_7480;
    u8 unk_7481;
    s8 unk_7482;                /* cached grid x */
    s8 unk_7483;                /* cached grid y */
    u32 unk_7484;
    u32 unk_7488;
} Unk02f2a8GridState;

void func_020305a8(Unk02f2a8GridState *s, int forced);
void func_020a269c(int v);
void Unk0a4e48_Unk_0a4e9c();
int Unk02f2a8_GridIndex45(int x, int y);
void Unk02f2a8_Unk_0306a8(Unk02f2a8State *state);

typedef struct Unk02f2a8Obj39160 {
    u32 unk_0000;
    u32 pad_0004_0 : 12;
    u32 unk_0004_12 : 4;
    u32 unk_0004_16 : 4;
    u32 unk_0004_20 : 4;
    u32 pad_0004_24 : 8;
} Unk02f2a8Obj39160;
/* Forward the grid coordinates cached at work-area +0x364/+0x365, plus the
 * caller's object at p+0x70, to func_02035db8. The accessor is called twice,
 * once per coordinate, matching the original instruction stream. */
void Unk02f2a8_Call_02035db8(u8 *p)
{
    Unk02f2a8WorkArea *a = Unk02e000_GetWorkArea();
    Unk02f2a8WorkArea *b = Unk02e000_GetWorkArea();
    func_02035db8((s32 *)(p + 0x70), a->unk_0364, b->unk_0365);
}

/* Push the grid coordinates cached at +0x744e/+0x744f into the work area via
 * SetGridPos. The direction word at +0x7450 wins when it is not the -1 sentinel;
 * otherwise the current work-area word (+0x358) is kept. */
void Unk02f2a8_Call_02036318(GameState *gs)
{
    Unk02f2a8GameStateTail *t = (Unk02f2a8GameStateTail *)gs;
    s8 x = t->unk_744e;
    s8 y = t->unk_744f;
    Unk02f2a8WorkArea *w = Unk02e000_GetWorkArea();
    u32 v = w->unk_0358;
    if (t->unk_7450 != -1) {
        v = t->unk_7450;
    }
    Unk02f2a8_SetGridPos(x, y, v);
}

/* Start the pending action for task `p`. The guard is a "still busy" check:
 * when Unk095560_Thunk_020961a0 reports nonzero the call is dropped. Otherwise
 * the task is armed through Unk02f2a8_Unk_0306a8, func_020305a8 runs its type-1
 * branch, and subsystem 1 is notified. */
void Unk02f2a8_Unk_032a08(int *p)
{
    func_0209e0b0();
    if (Unk095560_Thunk_020961a0() != 0) {
        return;
    }
    Unk02f2a8_Unk_0306a8((Unk02f2a8State *)p);
    func_020305a8((Unk02f2a8GridState *)p, 1);
    func_020a269c(1);
}

/* Reset the partial grid state on a game state: clears the u32 at +0x7478, the
 * byte at +0x7481 and the u32 at +0x7484, then notifies subsystem 2. Unlike
 * Unk02f2a8_ResetField7478Ex it leaves +0x7480 and +0x7488 alone. */
void Unk02f2a8_ResetField7478(GameState *gs)
{
    FIELD(u32, gs, 0x7478) = 0;
    FIELD(u8, gs, 0x7481) = 0;
    FIELD(u32, gs, 0x7484) = 0;
    Unk0a4e48_Unk_0a4e9c(2);
}

/* Full reset of the grid state block: clears +0x7478, +0x7480, +0x7481,
 * +0x7484 and +0x7488 (a superset of Unk02f2a8_ResetField7478). Unless the
 * +0x73dc word is set, it then calls func_020a269c(0), func_0205257c(3),
 * notifies subsystem 2 and posts event 5. */
void Unk02f2a8_ResetField7478Ex(GameState *gs)
{
    Unk02f2a8GameStateTail *t = (Unk02f2a8GameStateTail *)gs;
    t->unk_7478 = 0;
    t->unk_7480 = 0;
    t->unk_7481 = 0;
    t->unk_7484 = 0;
    t->unk_7488 = 0;
    if (t->unk_73dc != 0) {
        return;
    }
    func_020a269c(0);
    func_0205257c(3);
    Unk0a4e48_Unk_0a4e9c(2);
    Unk0a0ce4_Unk_0a0da4(5);
}

/* Main body at +4, or 0 when no GameState exists. */
u8 *GameState_GetBody(void)
{
    if (gGameState != 0) {
        return gGameState->unk_0004;
    }
    return 0;
}

/* Borrowed pointer to the 4-byte cell for grid coordinates (x, y) in the table
 * at gGameState + 0x38E8. Out-of-range coordinates alias cell 0 because
 * Unk02f2a8_GridIndex45 returns 0 for them. */
u32 *Unk02f2a8_GetCell38e8(int x, int y)
{
    return (u32 *)gGameState->unk_38e8 + Unk02f2a8_GridIndex45(x, y);
}

/* Cell for the current signed grid coordinates stored at +0x7482/+0x7483. */
u32 *Unk02f2a8_GetCurrentCell38e8(void)
{
    return Unk02f2a8_GetCell38e8(FIELD(s8, gGameState, 0x7482), FIELD(s8, gGameState, 0x7483));
}

/* Bits 16..19 of the u32 at +4 of the object at grid (x, y); 0 when the grid
 * lookup returns no object. Bit meaning is not established. */
u32 Unk02f2a8_GetObj39160Bits16(u8 *base, int x, int y)
{
    u32 r = 0;
    Unk02f2a8Obj39160 *o = (Unk02f2a8Obj39160 *)Unk038fbc_Unk_039160(base, x, y);
    if (o != 0) {
        r = o->unk_0004_16;
    }
    return r;
}

void *func_020445d0();
u8 *func_0204fde0();
int func_02035890();
int Unk02f2a8_SetField35c(u32 id);

typedef struct Unk02f2a8Res36 {
    s8 unk_0000[0x10];          /* 16-byte key copied by func_0203572c */
    s16 unk_0010[4];            /* indexed by bits 20..23 of a cell word */
    u8 unk_0018;                /* Unk_035820 only matches rows where this is 1 */
    s8 unk_0019;
    s8 unk_001a;
    s8 unk_001b[0xd];
} Unk02f2a8Res36;               /* 40 bytes; entries of resource 36 */

typedef struct Unk02f2a8Pos {
    u16 unk_0000;
    s8 unk_0002;
    s8 unk_0003;
    u32 unk_0004;
} Unk02f2a8Pos;

#define UNK02F2A8_RES36() ((Unk02f2a8Res36 *)func_0204fde0(func_020445d0(36, 0)))

/* Local view of the GameStateRoot words past the end declared by
 * include/GameState.h (the header is not owned by this card). */
typedef struct Unk02f2a8RootTail {
    u8 pad_0000[0x64];
    u32 unk_0064;
    u32 unk_0068;
} Unk02f2a8RootTail;

/* Arm the root request: set the flag at +0x60 and stash the two arguments at
 * +0x64/+0x68. Requires gGameState and its root; GameState_ClearRootUnk60 is
 * the matching disarm path. */
void Unk02f2a8_SetRootUnk60(u32 a, u32 b)
{
    gGameState->root->unk_60 = 1;
    ((Unk02f2a8RootTail *)gGameState->root)->unk_0064 = a;
    ((Unk02f2a8RootTail *)gGameState->root)->unk_0068 = b;
}

/* Clear the root flag at +0x60, paired with Unk02f2a8_SetRootUnk60 above.
 * Requires gGameState and its root to exist; the paired setter establishes
 * the field-access evidence for this name. */
void GameState_ClearRootUnk60(void)
{
    gGameState->root->unk_60 = 0;
}

/* Latch a (u16, u8, u8) triple at gGameState +0x7474..+0x7477 and set the
 * +0x7470 word to 1 to mark it valid. Requires gGameState; what the triple
 * means is not established. */
void Unk02f2a8_SetField7470(u16 a, u8 b, u8 c)
{
    ((Unk02f2a8GameStateTail *)gGameState)->unk_7470 = 1;
    ((Unk02f2a8GameStateTail *)gGameState)->unk_7474 = a;
    ((Unk02f2a8GameStateTail *)gGameState)->unk_7476 = b;
    ((Unk02f2a8GameStateTail *)gGameState)->unk_7477 = c;
}

/* Read the unsigned 16-bit field at gGameState +0x74f6, which supports the
 * offset-based name. Requires gGameState to exist. */
u16 GameState_GetUnkField74f6(void)
{
    return gGameState->unk_74f6;
}

/* Local view of the GameState sub-block headers at +0x240 and +0x2cc;
 * include/GameState.h (not owned by this card) pads both ranges. */
typedef struct Unk02f2a8GameStateSubs {
    u8 pad_0000[0x240];
    u32 unk_0240;
    u8 pad_0244[0x2cc - 0x244];
    u32 unk_02cc;
} Unk02f2a8GameStateSubs;

/* Return the optional sub-block at +0x240 only when the game state exists and
 * the block's first word is nonzero; otherwise null. The pointer is borrowed. */
u8 *Unk02f2a8_GetOptSub240(void)
{
    GameState *gs = gGameState;
    Unk02f2a8GameStateSubs *view;
    if (gs == 0) {
        return 0;
    }
    view = (Unk02f2a8GameStateSubs *)gs;
    if (view->unk_0240 != 0) {
        return (u8 *)&view->unk_0240;
    }
    return 0;
}

/* Same optional-block contract as Unk02f2a8_GetOptSub240, for the block at
 * +0x2cc. Returns null when the game state or the block's first word is zero. */
u8 *Unk02f2a8_GetOptSub2cc(void)
{
    GameState *gs = gGameState;
    Unk02f2a8GameStateSubs *view;
    if (gs == 0) {
        return 0;
    }
    view = (Unk02f2a8GameStateSubs *)gs;
    if (view->unk_02cc != 0) {
        return (u8 *)&view->unk_02cc;
    }
    return 0;
}

/* Empty callback installed at 0x035430; the original body is a bare return. */
void Unk02f2a8_Nop_035430(void) { }

/* Entry-table thunk retained so the original call site keeps its target. */
void Unk02f2a8_Thunk_0203428c(void) { func_0203428c(); }
/* Entry-table thunk retained so the original call site keeps its target. */
void Unk02f2a8_Thunk_0206146c(void) { func_0206146c(); }

/* Global accessor: callers (e.g. 0x0202f378, 0x020352f4) use this singleton. */
GameState *GetGameState(void) { return gGameState; }

/* Range callback: func_02057660 is called with the SDK's fixed (2, 0) range. */
void Unk02f2a8_Call_02057660(void) { func_02057660(2, 0); }

/* Reads the u16 at +0x74F4 of the singleton; field meaning is not established. */
u16 GameState_GetUnkField74f4(void) { return gGameState->unk_74f4; }

int Unk02f2a8_DirToAngle(int dir);
/* Fill a zeroed 8-byte position record through func_02035890(&pos, a), then
 * apply it: the u16 id goes to Unk02f2a8_SetField35c and the signed x/y bytes
 * plus the +4 word go to Unk02f2a8_SetGridPos. Returns func_02035890's result.
 * Selector `a` is never 0 when called from Unk02f2a8_Unk_035440. */
int Unk02f2a8_Unk_035a70(int a)
{
    Unk02f2a8Pos pos = {0};
    int r = func_02035890(&pos, a);
    Unk02f2a8_SetField35c(pos.unk_0000);
    Unk02f2a8_SetGridPos(pos.unk_0002, pos.unk_0003, pos.unk_0004);
    return r;
}

/* Signed byte at +0x19 of entry i in resource 36 (40-byte entries). The field
 * meaning is not established; callers use it as an id or selector. */
s8 Unk02f2a8_GetRes36Unk19(int i)
{
    return UNK02F2A8_RES36()[i].unk_0019;
}

/* Signed byte at +0x1a of entry i in resource 36 (40-byte entries). The field
 * meaning is not established; callers use it as an id or selector. */
s8 Unk02f2a8_GetRes36Unk1a(int i)
{
    return UNK02F2A8_RES36()[i].unk_001a;
}

/* Signed byte at +0x1b + j of entry i in resource 36 (40-byte entries). The
 * caller supplies the sub-index j, so this is the indexed sibling of
 * Unk02f2a8_GetRes36Unk19/1a. A negative byte is returned as -1, the invalid-id
 * sentinel; Unk02f2a8_Unk_035c14 applies the same negative test but maps it to 0. */
int Unk02f2a8_GetRes36Unk1b(int i, int j)
{
    Unk02f2a8Res36 *e = &UNK02F2A8_RES36()[i];
    s8 v = e->unk_001b[j];
    int r = -1;
    if (v >= 0) {
        r = v;
    }
    return r;
}

int Unk0e5fb8_Unk_0e63c8();
int Unk02e000_TestFlag();
void Unk02e000_SetBit_02e968();
/* Look up the signed id byte at +0x1b + j of resource-36 entry i (the same
 * byte Unk02f2a8_GetRes36Unk1b returns) and pass it to Unk0e5fb8_Unk_0e63c8.
 * A negative id (no entry) yields 0 without the call. */
int Unk02f2a8_Unk_035c14(int i, int j)
{
    Unk02f2a8Res36 *e = &UNK02F2A8_RES36()[i];
    s8 v = e->unk_001b[j];
    int r = 0;
    if (v >= 0) {
        r = Unk0e5fb8_Unk_0e63c8(v);
    }
    return r;
}

/* Bounds predicate for the 45x40 map grid: x must be 0..44 and y 0..39. Both
 * tests are signed, so negative coordinates are rejected here and never reach
 * the multiply in Unk02f2a8_GridIndex45. */
int Unk02f2a8_IsInGrid45x40(int x, int y)
{
    if (x < 0) {
        return 0;
    }
    if (x >= 45) {
        return 0;
    }
    if (y < 0) {
        return 0;
    }
    return y < 40;
}

/* Linear index y * 45 + x in the 45x40 grid; 0 for coordinates outside it, so
 * callers cannot distinguish row 0 from an invalid pair. */
int Unk02f2a8_GridIndex45(int x, int y)
{
    if (Unk02f2a8_IsInGrid45x40(x, y) == 0) {
        return 0;
    }
    return y * 45 + x;
}

/* Object whose u16 at +0x18 holds a 16-bit angle (0x10000 = full turn). */
typedef struct Unk02f2a8Angled {
    u8 pad_0000[0x18];
    u16 unk_0018;
} Unk02f2a8Angled;

/* Owner of an Unk02f2a8Angled sub-object embedded at +0x7c. */
typedef struct Unk02f2a8AngledOwner {
    u8 pad_0000[0x7c];
    Unk02f2a8Angled unk_007c;
} Unk02f2a8AngledOwner;

/* Object whose u32 at +0x14 is a state/mode word; 030478 sets it to 5. */
typedef struct Unk02f2a8Obj14 {
    u8 pad_0000[0x14];
    u32 unk_0014;
} Unk02f2a8Obj14;

/* Stores the angle for direction `dir` (see Unk02f2a8_DirToAngle) at obj+0x18. */
void Unk02f2a8_Unk_035ec4(Unk02f2a8Angled *obj, u32 dir)
{
    obj->unk_0018 = Unk02f2a8_DirToAngle(dir);
}

/* Sets the angle of obj's +0x7c sub-object from the work area's direction word (+0x358). */
void Unk02f2a8_Unk_030578(Unk02f2a8AngledOwner *obj)
{
    u8 *w = (u8 *)Unk02e000_GetWorkArea();
    Unk02f2a8_Unk_035ec4(&obj->unk_007c, FIELD(u32, w, 0x358));
}

void func_02061424(void *obj);
/* Null-safe: sets obj+0x14 to 5, then releases the same object through
 * func_02061424. */
void Unk02f2a8_Unk_030478(Unk02f2a8Obj14 *obj)
{
    if (obj == 0) {
        return;
    }
    obj->unk_0014 = 5;
    func_02061424(obj);
}

/* Clears the GameState fields at +0x7478, +0x7480/+0x7481 (bytes), +0x7484 and +0x7488. */
void Unk02f2a8_Unk_033890(GameState *gs)
{
    FIELD(u32, gs, 0x7478) = 0;
    FIELD(u8, gs, 0x7480) = 0;
    FIELD(u8, gs, 0x7481) = 0;
    FIELD(u32, gs, 0x7484) = 0;
    FIELD(u32, gs, 0x7488) = 0;
}

/* Zero the five grid fields at +0x7478/+0x7480/+0x7481/+0x7484/+0x7488; it is
 * the same body as Unk02f2a8_Unk_033890 and is kept as its own symbol because
 * both addresses are called. */
void Unk02f2a8_Unk_033ac8(GameState *gs)
{
    FIELD(u32, gs, 0x7478) = 0;
    FIELD(u8, gs, 0x7480) = 0;
    FIELD(u8, gs, 0x7481) = 0;
    FIELD(u32, gs, 0x7484) = 0;
    FIELD(u32, gs, 0x7488) = 0;
}

int Unk038fbc_Unk_039160();
/* Bits 12..15 of the u32 at +4 of the object at grid (x, y); 0 when the grid
 * lookup returns no object. It reads the nibble below the bits 16..19 that
 * Unk02f2a8_GetObj39160Bits16 returns. */
u32 Unk02f2a8_Unk_034a8c(u8 *base, int x, int y)
{
    u32 r = 0;
    Unk02f2a8Obj39160 *o = (Unk02f2a8Obj39160 *)Unk038fbc_Unk_039160(base, x, y);
    if (o != 0) {
        r = o->unk_0004_12;
    }
    return r;
}

int Unk044394_Unk_044428(int i);
int Unk044394_Unk_044534(int i);
void func_020f43d4(void);
/* Apply pending state for one selector: 0 is remapped to 1, then
 * Unk02f2a8_Unk_035a70 runs with 0x24 passed to Unk044394_Unk_044428 before it
 * and to Unk044394_Unk_044534 after it, then func_020f43d4 is called. The
 * selector and channel meanings are not established. */
void Unk02f2a8_Unk_035440(int arg0)
{
  if (arg0 == 0) {
    arg0 = 1;
  }
  Unk044394_Unk_044428(0x24);
  Unk02f2a8_Unk_035a70(arg0);
  Unk044394_Unk_044534(0x24);
  func_020f43d4();
}

int func_02050088(int mode, int lower, int upper);
/* Map a direction index to a 16-bit binary angle (0x10000 = full turn):
 * 1 -> 0, 2 -> 0x4000, 3 -> 0x8000, 0 -> 0xc000. Name evidence:
 * Unk02f2a8_Unk_035ec4 stores this result in the u16 angle field at +0x18.
 * Out-of-range directions return 0. */
int Unk02f2a8_DirToAngle(int dir)
{
    switch (dir) {
    case 1:
        return 0;
    case 2:
        return 0x4000;
    case 3:
        return 0x8000;
    case 0:
        return 0xc000;
    }
    return 0;
}

/* Latch an id below 90 at work-area +0x35c, then set its bit if clear.
 * Returns one only for a newly set bit; field stores establish the name. */
int Unk02f2a8_SetField35c(u32 id)
{
    Unk02f2a8WorkArea *w;
    if (id >= 90) {
        return 0;
    }
    w = Unk02e000_GetWorkArea();
    w->unk_035c = id;
    if (Unk02e000_TestFlag(w->unk_035c) != 0) {
        return 0;
    }
    Unk02e000_SetBit_02e968(w->unk_035c, 1);
    return 1;
}

/* Cache valid 45x40 grid coordinates twice at +0x364..+0x367 and the
 * direction word at +0x358. IsInGrid45x40 supplies the naming evidence.
 * Invalid coordinates return zero and leave the work area untouched. */
int Unk02f2a8_SetGridPos(int x, int y, u32 v)
{
    Unk02f2a8WorkArea *w;
    if (Unk02f2a8_IsInGrid45x40(x, y) == 0) {
        return 0;
    }
    w = Unk02e000_GetWorkArea();
    w->unk_0364 = x;
    w->unk_0365 = y;
    w->unk_0366 = x;
    w->unk_0367 = y;
    w->unk_0358 = v;
    return 1;
}

/* Reset the two 16-bit work-area fields at +0xaf2/+0xaf4: the value at +0xaf2
 * becomes zero and the value at +0xaf4 is reseeded with func_02050088(1, 50, 100),
 * the shared random helper called with an inclusive 50..100 range (see
 * func_02044488 in unit_02044394). */
void Unk02f2a8_Unk_036488(void)
{
    Unk02f2a8WorkArea *w = Unk02e000_GetWorkArea();
    w->unk_0af2 = 0;
    w->unk_0af4 = func_02050088(1, 0x32, 100);
}

void func_0205bb68(void);

/* Local view of an object whose +8 word counts live entries. */
typedef struct Unk02f2a8Counted {
    u8 pad_0000[8];
    s32 unk_0008;
} Unk02f2a8Counted;

/* Release the object's counted entries: call func_0205bb68 once per live entry,
 * then zero the count. The count is re-read each iteration in the original, so
 * a callee that changes it also changes the loop bound. */
void Unk02f2a8_Unk_0343b4(Unk02f2a8Counted *obj)
{
    s32 i = 0;
    if (0 < obj->unk_0008) {
        do {
            func_0205bb68();
            i++;
        } while (i < obj->unk_0008);
    }
    obj->unk_0008 = 0;
}

void Unk02f2a8_Unk_030d20(u8 *p, int mode);
int func_020572c0();
int func_0205e590();
u32 Unk095560_Unk_0956a8(void);
/* Run the cleanup path for a task context: Unk02f2a8_Unk_030d20(ctx, 1) tears
 * down the shared systems, Unk02f2a8_Unk_030478 resets the object in the
 * context's first word, func_02061424 releases the context itself, and
 * func_020572c0/func_0205e590(0) finish the sequence. */
void Unk02f2a8_Unk_033c94(u32 *ctx)
{
    Unk02f2a8_Unk_030d20((u8 *)ctx, 1);
    Unk095560_Unk_0956a8();
    Unk044394_Unk_044534(0x24);
    Unk02f2a8_Unk_030478((Unk02f2a8Obj14 *)*ctx);
    func_02061424(ctx);
    func_020572c0();
    func_0205e590(0);
}

int func_020361ec(int dir, int amount);
int Unk0a0ce4_Unk_0a0da4();

/* Advance the work-area direction by the action's +0x18 amount
 * (func_020361ec returns the rotated direction), clear the word at +0x1c, then
 * call ScanVisor_Unk_0a2b38 and Unk095560_Unk_09615c and post event
 * 0x2c through Unk0a0ce4_Unk_0a0da4. */
void Unk02f2a8_Unk_02fc10(Unk02f2a8Action *action)
{
    Unk02f2a8WorkArea *dst = Unk02e000_GetWorkArea();
    u32 dir = func_020361ec(((Unk02f2a8WorkArea *)Unk02e000_GetWorkArea())->unk_0358,
                            action->unk_0018);
    dst->unk_0358 = dir;
    action->unk_001c = 0;
    ScanVisor_Unk_0a2b38();
    Unk095560_Unk_09615c();
    Unk0a0ce4_Unk_0a0da4(0x2c);
}

int func_021214e0(u32 v);
int func_021215d4();
/* Action type 3 of the dispatcher above: clears the action's +0x1c word, runs
 * the same ScanVisor/Unk095560 refresh pair as type 4 (Unk02f2a8_Unk_02fc10),
 * and when func_021214e0 accepts the +0x18 word, sets +0x9c and calls
 * func_021215d4 (the GetGameState result is unused). Event 0x1b is posted on
 * both paths. The meaning of +0x18 and +0x9c is not established. */
void Unk02f2a8_Unk_02f8ac(Unk02f2a8Action *action)
{
    action->unk_001c = 0;
    ScanVisor_Unk_0a2b38();
    Unk095560_Unk_09615c();
    if (func_021214e0(action->unk_0018) != 0) {
        action->unk_009c = 1;
        GetGameState();
        func_021215d4();
    }
    Unk0a0ce4_Unk_0a0da4(0x1b);
}

int func_0202f530();
int func_0202f8f0();
int func_0202fc50();
void func_02030204(Unk02f2a8Action *action);
/* Dispatch the action type at +0x10: type zero arms +0x14, types 1..4
 * call their handlers, and other types leave it unchanged. */
void Unk02f2a8_Unk_0302f4(Unk02f2a8Action *action)
{
    switch (action->unk_0010) {
    case 0:
        action->unk_0014 = 1;
        return;
    case 1:
        func_02030204(action);
        return;
    case 2:
        func_0202f530();
        return;
    case 3:
        func_0202f8f0();
        return;
    case 4:
        func_0202fc50();
        return;
    case 5: /* kept so the jump table spans 0..5 like the original */
        return;
    default:
        return;
    }
}

/* Set the state flag at +0x73e0, clear root +4/+0x4c, set +0x757c
 * to 4, reset the +0x7598 object and refresh all seven visor entries.
 * Requires a state with a valid root; the flag meanings remain unknown. */
void Unk02f2a8_Unk_03064c(Unk02f2a8State *state)
{
    int i;
    state->unk_73e0 = 1;
    state->root->unk_0004 = 0;
    state->root->unk_004c = 0;
    state->unk_757c = 4;
    Unk11f2d0_Unk_11f320(&state->unk_7598);
    ScanVisor_Unk_0a2b38();
    ScanVisor_Unk_0a2acc();
    i = 0;
    do {
        ScanVisor_Unk_0a2a8c(i);
        i++;
    } while (i < 7);
}

/* Arm root +0x44/+0x4c/+0x50/+0x54, clear +0x34/+0x38 and the
 * state words +0x73e0/+0x73e4, then notify the three subsystems.
 * The input is a state whose first word points to its root. */
void Unk02f2a8_Unk_0306a8(Unk02f2a8State *state)
{
    state->root->unk_004c = 1;
    state->root->unk_0054 = 1;
    state->root->unk_0044 = 1;
    state->root->unk_0050 = 1;
    state->root->unk_0038 = 0;
    state->root->unk_0034 = 0;
    state->unk_73e0 = 0;
    state->unk_73e4 = 0;
    Unk0caea8_Unk_0caf78();
    Unk0a0ce4_Unk_0a0d30(1);
    Unk0caea8_Unk_0caf88();
}

int func_02035edc();
int func_02036368();
/* Move the counter at +0x6c toward the unsigned limit at +0x68 when
 * +0x60 is one; otherwise decrement a positive signed counter. Requires a
 * context through +0x7c; the two callees consume its updated counter/block. */
void Unk02f2a8_Unk_02f378(u8 *p)
{
    if (FIELD(s32, p, 0x60) == 1) {
        if (FIELD(u32, p, 0x6c) < FIELD(u32, p, 0x68)) {
            FIELD(u32, p, 0x6c)++;
        }
    } else if (FIELD(s32, p, 0x6c) > 0) {
        FIELD(s32, p, 0x6c)--;
    }
    func_02036368(p + 0x7c, FIELD(u32, p, 0x64),
                 FIELD(u32, p, 0x68), FIELD(u32, p, 0x6c));
    func_02035edc(p + 0x7c, p + 0x70);
}

void Unk02f2a8_SetRootUnk60();
int func_0205257c();
/* If 04b4c4 accepts the context, set its +0x20/+0x28/+0x2c flag for
 * selectors 0..2/5/4 respectively. Return one only for a handled selector. */
int func_0209be20(int x, int y);
/* Turn the cached heading by `turn` (func_020361ec) and step one cell from the
 * cached grid position (0: -y, 1: +x, 2: +y, 3: -x, as in func_0202fe08).
 * Out-of-grid targets return 0; with probe == 0 an in-grid target returns 1,
 * otherwise the cell is tested with func_0209be20. */
int func_0202fd64(int probe, int turn)
{
    int direction, x, y;
    direction = func_020361ec(Unk02e000_GetWorkArea()->unk_0358, turn);
    x = Unk02e000_GetWorkArea()->unk_0364;
    y = Unk02e000_GetWorkArea()->unk_0365;
    switch (direction) {
    case 1: x++; break;
    case 2: y++; break;
    case 3: x--; break;
    case 0: y--; break;
    }
    if (!Unk02f2a8_IsInGrid45x40(x, y)) return 0;
    if (probe == 0) return 1;
    return func_0209be20(x, y);
}

int Unk02f2a8_Unk_030198(u8 *p)
{
    if (func_0204b4c4(p) == 0) {
        return 0;
    }
    switch (func_0204ca1c()) {
    case 0:
    case 1:
    case 2:
        FIELD(u32, p, 32) = 1;
        return 1;
    case 5:
        FIELD(u32, p, 40) = 1;
        return 1;
    case 4:
        FIELD(u32, p, 44) = 1;
        return 1;
    }
    return 0;
}

/* Consume pending action +0x14 into current action +0x10 and restore the
 * -1 sentinel. The dispatch and paired 03034c pending check support the name;
 * action one arms +0x5c/+0x50, while actions 2..4 call their setup handlers. */
void Unk02f2a8_ApplyPending(u8 *p)
{
    FIELD(s32, p, 16) = FIELD(s32, p, 20);
    FIELD(s32, p, 20) = -1;
    switch (FIELD(s32, p, 16)) {
    case 0:
        break;
    case 1:
        FIELD(u32, p, 92) = 1;
        FIELD(u32, p, 80) = 1;
        break;
    case 2:
        func_0202f3d8(p);
        break;
    case 3:
        Unk02f2a8_Unk_02f8ac((Unk02f2a8Action *)p);
        break;
    case 4:
        Unk02f2a8_Unk_02fc10((Unk02f2a8Action *)p);
        break;
    }
}

/* Per-frame action step: when a pending action (+0x14 != -1) exists and
 * 04b710 returns 1 or 04ca1c returns -1, ApplyPending promotes it. Then runs
 * 0302f4 and 02f378, passes word +0 and the work-area grid bytes +0x364/+0x365
 * to 0209aca0, and calls 116598. The action is borrowed and must be live. */
void Unk02f2a8_Unk_03034c(Unk02f2a8Action *action)
{
    Unk02f2a8WorkArea *w1;
    Unk02f2a8WorkArea *w2;
    if (action->unk_0014 != -1) {
        if (func_0204b710() == 1 || func_0204ca1c() == -1) {
            Unk02f2a8_ApplyPending((u8 *)action);
        }
    }
    Unk02f2a8_Unk_0302f4(action);
    Unk02f2a8_Unk_02f378((u8 *)action);
    w1 = Unk02e000_GetWorkArea();
    w2 = Unk02e000_GetWorkArea();
    func_0209aca0(action->unk_0000, w1->unk_0364, w2->unk_0365);
    func_02116598();
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int func_02038ff8();
void func_02039520();
int Unk02e000_Unk_02e8b8();
void func_020a7474();

/* Pass a zero-terminated copy of exactly 16 source bytes to 038ff8.
 * src must provide 16 readable bytes; the third ABI argument is unused. */
void Unk02f2a8_Unk_030704(int a, s8 *src, int unused, int c, u8 e)
{
    s8 buf[17] = {0};
    int i;
    for (i = 0; i < 16; i++) {
        buf[i] = src[i];
    }
    func_02038ff8(a, buf, c, e);
}

/* Copy context bytes +0x40..+0x4f to a zero-terminated local buffer for
 * 039520. Requires that context range; the callee borrows the stack buffer. */
void Unk02f2a8_Unk_0308c0(u8 *p)
{
    s8 buf[17] = {0};
    int i;
    for (i = 0; i < 16; i++) {
        buf[i] = FIELD(s8, p + i, 64);
    }
    func_02039520(p, buf);
}

/* Enter the state set up by 05257c(4), 0a4e9c(3) and 05e590(9): runs
 * ScanVisor 0a2660, arms the root request with (0x800, 15), clears state
 * +0x7478..+0x748b, stores root +0x14/+0x18/+0x1c = 1/2/0 and ends with
 * 0a0da4(8). Requires the state and its root to be live. */
void Unk02f2a8_Unk_032f3c(Unk02f2a8State *state)
{
    func_0205257c(4);
    Unk0a4e48_Unk_0a4e9c(3);
    func_0205e590(9);
    ScanVisor_Unk_0a2660();
    Unk02f2a8_SetRootUnk60(0x800, 15);
    state->unk_7478 = 0;
    state->unk_747c = 0;
    state->unk_7480 = 0;
    state->unk_7481 = 0;
    state->unk_7484 = 0;
    state->unk_7488 = 0;
    state->root->unk_0014 = 1;
    state->root->unk_0018 = 2;
    state->root->unk_001c = 0;
    Unk0a0ce4_Unk_0a0da4(8);
}

int Unk03e43c_Unk_03fa28(void);
void Unk03e43c_AdvanceCounter360(void);
void Unk094fe0_Unk_0952ac(void);
/* Detect whether advancing the shared frame counter (+0x360, see
 * Unk03e43c_AdvanceCounter360) crossed a 0..15 table-slot boundary. The slot is
 * sampled before and after; when it changed, Unk094fe0_Unk_0952ac ticks the
 * slot timers. The game state and slot are re-read after the advance because
 * the callee may recreate or rebase them. */
void Unk02f2a8_Unk_03538c(void)
{
    GameState *gs = GetGameState();
    Unk02f2a8GameStateTail *tail = (Unk02f2a8GameStateTail *)gs;
    tail->unk_74f0 = Unk03e43c_Unk_03fa28();
    Unk03e43c_AdvanceCounter360();
    gs = GetGameState();
    tail = (Unk02f2a8GameStateTail *)gs;
    if (tail->unk_74f0 == (u32)Unk03e43c_Unk_03fa28()) {
        return;
    }
    Unk094fe0_Unk_0952ac();
}

int func_0203480c();
int Unk03e43c_SetMode30();
/* Select mode one only for argument one, otherwise mode two, then reset
 * the context blocks at +4/+0x7550/+0x7598 and notify the remaining subsystems.
 * Called by the 033c94 cleanup path; requires a live context and returns void. */
void Unk02f2a8_Unk_030d20(u8 *p, int mode)
{
    ScanVisor_Unk_0a2b38();
    if (mode == 1) {
        Unk03e43c_SetMode30(1);
    } else {
        Unk03e43c_SetMode30(2);
    }
    func_0203480c(p + 4, 1);
    Unk09974c_Unk_09974c(p + 0x7550);
    Unk11f2d0_Unk_11f2d0(p + 0x7598);
    Unk095560_Unk_096130();
    Unk065e88_Unk_065eac();
    Unk0964f8_Unk_0964f8();
    Unk0a23f4_Unk_0a2414();
}

u32 Unk038fbc_Unk_038fbc(int *obj);
u32 Unk0387bc_Unk_038e40(int *obj);
u32 Unk0387bc_Unk_038cbc(int *obj);
void Unk02cad4_Unk_02cbdc(u32 a);

/* Submit context blocks +0x5508/+0x240/+0x18 to 0a7474 with the current
 * map-cell bits, 02e8b8 result and work-area halfword +0x35c. Coordinates
 * are signed bytes at +0x744e/+0x744f; all supplied blocks are borrowed. */
void Unk02f2a8_Unk_0313a4(u8 *p)
{
    int bits = Unk02f2a8_GetObj39160Bits16(p + 576, FIELD(s8, p + 0x7400, 78), FIELD(s8, p + 0x7400, 79));
    int m = Unk02e000_Unk_02e8b8();
    u16 v = FIELD(u16, (u8 *)Unk02e000_GetWorkArea() + 0x300, 92);
    func_020a7474(p + 264 + 0x5400, m, p + 576, p + 24, v, bits, 1);
}

/* Tears down the GameState sub-objects held at +0x314c, +0x3140, +0x3134 and
 * +0x73d0 (in that order) and clears gGameState, so GameState_Exists then
 * reports 0. The GameState memory itself is not freed here. */
void GameState_Shutdown(GameState *gs)
{
    Unk038fbc_Unk_038fbc((int *)gs->unk_314c);
    Unk0387bc_Unk_038e40((int *)gs->unk_3140);
    Unk0387bc_Unk_038cbc((int *)gs->unk_3134);
    Unk02cad4_Unk_02cbdc(gs->unk_73d0);
    gGameState = 0;
}

/* Returns whether the global game state exists. */
int GameState_Exists(void)
{
    return gGameState != 0;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int func_020987ac();
void func_02008644();
void *func_0204459c();
void *func_0204fe68();
void *func_0204fed8();
void func_0200866c();
u32 func_0204fe18();


Unk02f2a8MapBlock *Unk02f2a8_Unk_034970(Unk02f2a8Body *p, int x, int y);

/* Borrow the map block at p+0x23c, or the one at p+0x2c8 when the cell's
 * bits 16..19 select a nonnegative signed id in p+0x30 and its lookup is
 * nonzero. */
Unk02f2a8MapBlock *Unk02f2a8_Unk_034970(Unk02f2a8Body *p, int x, int y)
{
    Unk02f2a8MapBlock *r = &p->unk_023c;
    Unk02f2a8Obj39160 *o = (Unk02f2a8Obj39160 *)Unk038fbc_Unk_039160(r, x, y);
    u32 n;
    if (o != 0) {
        n = o->unk_0004_16;
        if (n != 0) {
            s8 k = p->unk_0030[n - 1];
            if (k >= 0 && Unk0e5fb8_Unk_0e63c8(k) != 0) {
                r = &p->unk_02c8;
            }
        }
    }
    return r;
}

/* Return the work-area id +0x35c unless the cell at x/y in block +0x23c
 * names a slot: bits 16..19 of the cell's +4 word select signed id
 * p->unk_0030[n - 1]; for a nonnegative id whose 0e63c8 count m is positive,
 * returns id * 2 + 90 + m - 1 instead. p is the borrowed state body. */
int Unk02f2a8_Unk_0349c4(Unk02f2a8Body *p, int x, int y)
{
    int r = Unk02e000_GetWorkArea()->unk_035c;
    Unk02f2a8Obj39160 *o = (Unk02f2a8Obj39160 *)Unk038fbc_Unk_039160(&p->unk_023c, x, y);
    u32 n;
    if (o != 0) {
        n = o->unk_0004_16;
        if (n != 0) {
            s8 k = p->unk_0030[n - 1];
            if (k >= 0) {
                int m = Unk0e5fb8_Unk_0e63c8(k);
                if (m > 0) {
                    r = (m - 1) + (k * 2 + 90);
                }
            }
        }
    }
    return r;
}

/* Return whether state +0x73e0 is not 1, +0x73c8 is 2, root +0x10
 * is 1 and root +4 is nonzero. Requires the singleton and its root. */
int Unk02f2a8_Unk_034b24(void)
{
    Unk02f2a8State *s = (Unk02f2a8State *)gGameState;
    if (s->unk_73e0 == 1) {
        return 0;
    }
    if (s->unk_73c8 != 2) {
        return 0;
    }
    if (s->root->unk_0010 != 1) {
        return 0;
    }
    return s->root->unk_0004 != 0;
}

/* Game state viewed as root pointer plus the body used by 034970. */
typedef struct Unk02f2a8StateBody {
    GameStateRoot *root;
    Unk02f2a8Body body;
} Unk02f2a8StateBody;

/* Look up the cell value at x/y: needs gGameState and a nonzero word at
 * body block +0x23c. 034a8c reads the cell in the block chosen by 034970; a
 * positive result n indexes byte n + 15 of the +0x23c block's table, which is
 * passed with 3 to 0987ac. Returns that result, or zero otherwise. */
int Unk02f2a8_Unk_0351b4(int x, int y)
{
    int r;
    int n;
    Unk02f2a8StateBody *g;
    g = (Unk02f2a8StateBody *)gGameState;
    if (g == 0) {
        return 0;
    }
    if (g->body.unk_023c.unk_0000 == 0) {
        return 0;
    }
    r = 0;
    n = Unk02f2a8_Unk_034a8c((u8 *)Unk02f2a8_Unk_034970(&g->body, x, y), x, y);
    if (n > 0) {
        r = func_020987ac(3, (g->body.unk_023c.unk_0004 + n)[15]);
    }
    return r;
}

/* Clear n halfwords at dst through 008644, then copy the record for key from
 * resource 38 (row 0 of 04fe68, lookup 04fed8) into dst, at most 5 halfwords.
 * Returns 1 when the record was copied, 0 when the resource or key is missing
 * (dst stays cleared). dst must hold n halfwords. */
int Unk02f2a8_Unk_03550c(u16 *dst, u32 n, int key)
{
    int r = 0;
    void *h;
    void *t;
    func_02008644(r, dst, n * 2);
    h = func_0204459c(38);
    if (h != 0) {
        t = func_0204fed8(func_0204fe68(h, r), key);
        if (t != 0) {
            if (n >= 5) {
                n = 5;
            }
            func_0200866c(t, dst, n * 2);
            r = 1;
        }
    }
    return r;
}

/* Return the index of the first resource 36 row with byte +0x18 == 1 and
 * signed byte +0x19 == a, or 0 when none matches (indistinguishable from row
 * 0). The u8 index wraps, so the table must have fewer than 256 rows. */
int Unk02f2a8_Unk_035820(int a)
{
    void *h = func_020445d0(36, 0);
    Unk02f2a8Res36 *t = (Unk02f2a8Res36 *)func_0204fde0();
    u32 n = func_0204fe18(h);
    int r = 0;
    u8 i;
    for (i = 0; i < n; i++) {
        Unk02f2a8Res36 *e = &t[i];
        if (e->unk_0018 == 1 && a == e->unk_0019) {
            r = i;
            break;
        }
    }
    return r;
}

/* Return the index of the first resource 36 row whose signed bytes
 * +0x19/+0x1a equal a/b, or 0 when none matches (same as row 0). */
int Unk02f2a8_Unk_035b08(int a, int b)
{
    int r;
    u32 i;
    u32 n;
    Unk02f2a8Res36 *t;
    void *h = func_020445d0(36, 0);
    t = (Unk02f2a8Res36 *)func_0204fde0();
    n = func_0204fe18(h);
    r = 0;
    for (i = 0; i < n; i++, t++) {
        if (a == t->unk_0019 && b == t->unk_001a) {
            r = i;
            break;
        }
    }
    return r;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif

/* Count resource 36 records whose signed byte +0x19 equals a. Records are
 * 40 bytes; the original u8 index wraps, so the resource must have <256 rows. */
int Unk02f2a8_Unk_035b74(int a)
{
    void *h = func_020445d0(36, 0);
    u8 *t = func_0204fde0();
    u32 n = func_0204fe18(h);
    int r = 0;
    u8 i;
    for (i = 0; i < n; i++) {
        if (a == (s8)(t + i * 40)[25]) {
            r++;
        }
    }
    return r;
}

int Unk0986ac_Unk_098978(int id);
int Unk0986ac_Thunk_02098714(int id);

/* Point read by func_02036068: words +0 and +8 (x and z by position; the +4
 * word is not read there). */
typedef struct Unk02f2a8Point {
    s32 x;
    s32 y;
    s32 z;
} Unk02f2a8Point;

int func_020024f8(int a, int b);
void func_02051b18(int *value, int step, int lo, int hi, int mode);

/* Return a signed 16-bit value derived from the offset between two points:
 * dx = to->x - from->x and dz = to->z - from->z (words +0 and +8). Equal x and
 * z return zero without calls. Otherwise 020024f8(dz, dx) seeds a local that
 * 02051b18 updates with -step, bounds -0x8000/0x8000 and mode 2. The value
 * looks like an angle, but the callees are unnamed, so the name stays neutral.
 * Both points are borrowed and read-only. */
s16 func_02036068(const Unk02f2a8Point *from, int step, const Unk02f2a8Point *to)
{
    int dx = to->x - from->x;
    int dz = to->z - from->z;
    int angle;
    if (dx == 0 && dz == 0) {
        return 0;
    }
    angle = func_020024f8(dz, dx);
    func_02051b18(&angle, -step, -0x8000, 0x8000, 2);
    return (s16)angle;
}

/* Scale v by one tenth, halve/third it when predicates for ids 152/163
 * equal one, and clamp to at least one. Soft-float rounding is preserved. */
int Unk02f2a8_Unk_0366dc(int v)
{
    int r = (int)(0.1f * v);
    int a = Unk0986ac_Unk_098978(152);
    int b = Unk0986ac_Unk_098978(163);
    if (Unk0986ac_Thunk_02098714(a) == 1) {
        r /= 2;
    }
    if (Unk0986ac_Thunk_02098714(b) == 1) {
        r /= 3;
    }
    if (r < 1) {
        r = 1;
    }
    return r;
}

int func_02118c6c(int id);
/* Require the key and both derived ids of each nonnegative resource-36
 * signed byte +0x1c..+0x22 to pass 118c6c. The resource is borrowed. */
int func_02036654(int key)
{
    Unk02f2a8Res36 *row;
    int ok;
    int i;
    func_020445d0(36, 0);
    row = (Unk02f2a8Res36 *)func_0204fde0() + key;
    ok = 1;
    if (func_02118c6c(key) == 0) ok = 0;
    for (i = 0; i < 7; i++) {
        int id = row->unk_001b[i + 1];
        if (id < 0) continue;
        id *= 2;
        if (func_02118c6c(id + 90) == 0) { ok = 0; break; }
        if (func_02118c6c(id + 91) == 0) { ok = 0; break; }
    }
    return ok;
}

int Unk04bb9c_GetCtxUnka20(void);
int func_0202fea0(Unk02f2a8Action *action);
int func_020300ec(Unk02f2a8Action *action);
void Unk03e43c_Unk_0441ec(void);
/* For an enabled action, ignore blocked singleton states; compare the work
 * id with the context id and run the corresponding handler, then notify or
 * apply 030198. The borrowed action must remain writable during calls. */
void func_02030204(Unk02f2a8Action *action)
{
    Unk02f2a8WorkArea *work;
    int result;
    if (((Unk02f2a8State *)GetGameState())->unk_73e0 == 1) return;
    if (((Unk02f2a8State *)GetGameState())->unk_743c == 1) return;
    if (action->unk_0004 != 1) return;
    if (func_0204b710() != 1) return;
    work = Unk02e000_GetWorkArea();
    if (work->unk_035c == Unk04bb9c_GetCtxUnka20())
        result = func_0202fea0(action);
    else result = func_020300ec(action);
    if (result == 1) { Unk03e43c_Unk_0441ec(); return; }
    Unk02f2a8_Unk_030198((u8 *)action);
}

/* Callback descriptor observed at 09c498: +4 is the transition predicate,
 * +0x14 selects the cell filter. The descriptor remains borrowed. */
typedef struct Unk02f2a8Descriptor {
    u32 unk_0000;
    int (*unk_0004)(Unk02f2a8State *state);
    int (*unk_0008)(Unk02f2a8State *state);
    u8 pad_000c[8];
    u32 unk_0014;
} Unk02f2a8Descriptor;
Unk02f2a8Descriptor *Unk09a268_Unk_09c498(int id);

/* Poll the optional +4 callback; completion clears pending grid state and
 * arms root flags. The state and its root must both be writable. */
void func_02032adc(Unk02f2a8State *state)
{
    int result = 1;
    Unk02f2a8Descriptor *entry = Unk09a268_Unk_09c498(state->unk_7478);
    if (entry->unk_0004 != 0) result = entry->unk_0004(state);
    if (result != 1) return;
    state->unk_7478 = 0;
    state->unk_7480 = 0;
    state->unk_7481 = 0;
    state->unk_7484 = 0;
    state->unk_7488 = 0;
    state->unk_73cc = 2;
    state->root->unk_0014 = 1;
    state->root->unk_0018 = 2;
    state->root->unk_001c = 0;
    state->root->unk_0044 = 1;
    state->root->unk_0050 = 1;
    state->root->unk_004c = 1;
}

/* Poll the optional +4 callback; completion clears pending grid state and
 * arms root flags. The state and its root must both be writable. */
void func_02032c0c(Unk02f2a8State *state)
{
    int result = 1;
    Unk02f2a8Descriptor *entry = Unk09a268_Unk_09c498(state->unk_7478);
    if (entry->unk_0004 != 0) result = entry->unk_0004(state);
    if (result != 1) return;
    state->unk_7478 = 0;
    state->unk_7480 = 0;
    state->unk_7481 = 0;
    state->unk_7484 = 0;
    state->unk_7488 = 0;
    state->unk_73cc = 2;
    state->root->unk_0014 = 1;
    state->root->unk_0018 = 2;
    state->root->unk_001c = 0;
    state->root->unk_0044 = 1;
    state->root->unk_0050 = 1;
    state->root->unk_004c = 1;
}

/* Use a looked-up object's descriptor +0x14 to accept cell byte +1.
 * Missing objects and selector zero accept; selectors 1/2 accept 1 / 1-or-3. */
int func_02037054(void *map, u8 *cells, int x, int y)
{
    u32 kind;
    int ok = 1;
    Unk02f2a8Obj39160 *obj = (Unk02f2a8Obj39160 *)Unk038fbc_Unk_039160(map, x, y);
    if (obj != 0) {
        kind = Unk09a268_Unk_09c498(*(u8 *)obj)->unk_0014;
        int value = (cells + Unk02f2a8_GridIndex45(x, y) * 4)[1];
        switch (kind) {
        case 0: ok = 1; break;
        case 1: if (value != 1) ok = 0; break;
        case 2: if (value == 1 || value == 3) ok = 1; else ok = 0; break;
        case 3: ok = 0; break;
        default: break;
        }
    }
    return ok;
}

int func_0209c090(int x, int y, int direction, int flag);
/* Only selector two probes the neighboring grid coordinate in the cached
 * direction. Out-of-grid neighbors and other selectors return one. */
int func_0202fe08(int selector)
{
    int direction, x, y;
    if (selector != 2) return 1;
    direction = Unk02e000_GetWorkArea()->unk_0358;
    x = Unk02e000_GetWorkArea()->unk_0364;
    y = Unk02e000_GetWorkArea()->unk_0365;
    switch (direction) {
    case 1: x++; break;
    case 2: y++; break;
    case 3: x--; break;
    case 0: y--; break;
    }
    if (!Unk02f2a8_IsInGrid45x40(x, y)) return 1;
    return func_0209c090(x, y, direction, 1);
}

void func_02008848(void *dst, int value, u32 size);
void func_02036c48(void *work, void *map, void *position, u16 id,
                   int x, int y, u32 flag);
struct Unk02f2a8SortList;
void func_02036fb8(struct Unk02f2a8SortList *list);
void func_020370e8(void *work, void *map, void *cells);
/* Initialize 0x794 writable work bytes, populate from a borrowed position,
 * then attach cells when a map exists. Null position/cells skip setup.
 * The repeated position test and unused final argument preserve the ABI. */
/* Task block allocated by func_020303d0 (0xa0 bytes, the size it requests). */
typedef struct Unk02f2a8Task {
    u32 unk_0000;               /* creator argument */
    u32 unk_0004;
    u32 unk_0008;
    u32 unk_000c;
    u32 unk_0010;
    u32 unk_0014;
    u32 unk_0018;
    u32 unk_001c;
    u8 pad_0020[0x54 - 0x20];
    u32 unk_0054;
    u8 pad_0058[4];
    u32 unk_005c;
    u8 pad_0060[0xa0 - 0x60];
} Unk02f2a8Task;

typedef void (*Unk02f2a8TaskFn)();
void *func_020611dc(Unk02f2a8TaskFn update, Unk02f2a8TaskFn a, int b,
                    Unk02f2a8TaskFn c, int size, int d, int e, int f);
/* Allocate a 0xa0-byte task with Unk02f2a8_Unk_03034c and the two empty
 * callbacks, store `arg` at +0 and the initial words, then position and
 * orient it from the work area. Returns 0 when the allocation fails. */
Unk02f2a8Task *func_020303d0(u32 arg)
{
    Unk02f2a8Task *t = func_020611dc(Unk02f2a8_Unk_03034c, Unk02f2a8_Nop_0303c8, 0,
                                     Unk02f2a8_Nop_0303cc, sizeof(Unk02f2a8Task), 0, 0, 1);
    if (t == 0) return 0;
    t->unk_0000 = arg;
    t->unk_0004 = 0;
    t->unk_0008 = 1;
    t->unk_000c = 1;
    t->unk_0010 = 0;
    t->unk_0014 = 0;
    t->unk_0018 = 2;
    t->unk_001c = 0;
    t->unk_0054 = 0;
    t->unk_005c = 0;
    Unk02f2a8_Call_02035db8((u8 *)t);
    Unk02f2a8_Unk_030578((Unk02f2a8AngledOwner *)t);
    Unk02f2a8_Unk_02f378((u8 *)t);
    return t;
}

void func_0205e484(int id, int mode);
/* Pick the id for the cell under the cached grid position (bits 20..23 of the
 * cell word select an entry of body+0x24) and pass it to func_0205e484 with
 * mode 9, latching it at +0x73d4. Ids >= 29 are ignored. Unless `forced` is 1,
 * nothing happens when +0x73e0 is 1 or the id is already latched. */
void func_020305a8(Unk02f2a8GridState *s, int forced)
{
    u32 k = 0;
    s16 id;
    Unk02f2a8WorkArea *a = Unk02e000_GetWorkArea();
    Unk02f2a8WorkArea *b = Unk02e000_GetWorkArea();
    Unk02f2a8Obj39160 *o = (Unk02f2a8Obj39160 *)Unk038fbc_Unk_039160(&s->body.unk_023c,
                                                                      a->unk_0364, b->unk_0365);
    if (o != 0) {
        k = o->unk_0004_20;
    }
    id = s->body.unk_0024[k];
    if (id >= 29) return;
    if (forced == 1) {
        func_0205e484(id, 9);
        s->unk_73d4 = id;
        return;
    }
    if (s->unk_73e0 == 1 || id == s->unk_73d4) return;
    func_0205e484(id, 9);
    s->unk_73d4 = id;
}

/* Leading byte of the cell object Unk038fbc_Unk_039160 returns. */
typedef struct Unk02f2a8CellHead {
    u8 unk_0000;
} Unk02f2a8CellHead;

typedef void (*Unk02f2a8GridHandler)(Unk02f2a8GridState *s);
Unk02f2a8GridHandler *Unk09a268_Unk_09c4a8(Unk02f2a8MapBlock *b, int x, int y);
/* Look up the handler slot for the cached cell (+0x7482/+0x7483) through
 * Unk09a268_Unk_09c4a8, latch the cell's leading byte at +0x7478 when the
 * cell exists, clear +0x7480..+0x7488 and run the handler if one is set. */
void func_02032a40(Unk02f2a8GridState *s)
{
    s8 y = s->unk_7483;
    s8 x = s->unk_7482;
    Unk02f2a8GridHandler *h = Unk09a268_Unk_09c4a8(Unk02f2a8_Unk_034970(&s->body, x, y), x, y);
    Unk02f2a8CellHead *c;
    y = s->unk_7483;
    x = s->unk_7482;
    c = (Unk02f2a8CellHead *)Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(&s->body, x, y), x, y);
    if (c != 0) {
        s->unk_7478 = c->unk_0000;
    }
    s->unk_7480 = 0;
    s->unk_7481 = 0;
    s->unk_7484 = 0;
    s->unk_7488 = 0;
    if (*h != 0) {
        (*h)(s);
    }
}

/* Look up the handler slot for the cached cell (+0x7482/+0x7483) through
 * Unk09a268_Unk_09c4a8, latch the cell's leading byte at +0x7478 when the
 * cell exists, clear +0x7480..+0x7488 and run the handler if one is set. */
void func_02032b70(Unk02f2a8GridState *s)
{
    s8 y = s->unk_7483;
    s8 x = s->unk_7482;
    Unk02f2a8GridHandler *h = Unk09a268_Unk_09c4a8(Unk02f2a8_Unk_034970(&s->body, x, y), x, y);
    Unk02f2a8CellHead *c;
    y = s->unk_7483;
    x = s->unk_7482;
    c = (Unk02f2a8CellHead *)Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(&s->body, x, y), x, y);
    if (c != 0) {
        s->unk_7478 = c->unk_0000;
    }
    s->unk_7480 = 0;
    s->unk_7481 = 0;
    s->unk_7484 = 0;
    s->unk_7488 = 0;
    if (*h != 0) {
        (*h)(s);
    }
}

/* Counter view of gGameState: per-kind enable bytes at +0x33 and u16 rows of
 * three counters at +0x751e, with the kind-0 counter at +0x754e. */
typedef struct Unk02f2a8Tally {
    u8 pad_0000[0x18];
    Unk02f2a8Res36 unk_0018;    /* copy of a resource-36 row; +0x1b holds the per-kind ids */
    u8 pad_0040[0x74f2 - 0x40];
    /* Both tables are indexed by kind 1..7 with row 0 never used, so the
     * counter table's unused row 0 overlaps the end of the target table. */
    union {
        struct {
            u16 unk_74f2[8][3]; /* targets; row 0 is not stored */
            u16 unk_7522;       /* target for the kind-0 counter */
        } tgt;
        struct {
            u8 pad_0000[0x751e - 0x74f2];
            u16 unk_751e[8][3]; /* counters; row 0 is not stored */
        } cnt;
    } rows;
    u16 unk_754e;
} Unk02f2a8Tally;

void func_02030d84(Unk02f2a8Tally *t, u32 id, int kind);
/* Bump a counter and report it with the work-area id (+0x35c): kind 0 bumps
 * +0x754e (reported with 0); other kinds bump row `kind`, column `slot`
 * (reported with 1) unless the kind's enable byte is negative. No-op without
 * gGameState. */
void func_020352f4(int kind, int slot)
{
    Unk02f2a8Tally *t = (Unk02f2a8Tally *)gGameState;
    if (t == 0) return;
    if (kind == 0) {
        t->unk_754e++;
        func_02030d84(t, Unk02e000_GetWorkArea()->unk_035c, 0);
        return;
    }
    if (t->unk_0018.unk_001b[kind] < 0) return;
    t->rows.cnt.unk_751e[kind][slot]++;
    func_02030d84(t, Unk02e000_GetWorkArea()->unk_035c, 1);
}

int Unk044394_HasEntry(int i);
/* Clear count u16s at dst (func_02008644 with 0), then, when resource 37 is
 * loaded, copy up to 15 u16s from its entry Unk02f2a8_GetRes36Unk19(idx) - 1
 * (func_0200866c). Resource 36 is pinned around the lookup and released again
 * when it was not already held. Returns 1 when the copy happened. */
int func_0203546c(void *dst, u32 count, int idx)
{
    int ok = 0;
    void *res;
    func_02008644(0, dst, count * 2);
    res = func_0204459c(37);
    if (res != 0) {
        int held = Unk044394_HasEntry(36);
        s8 entry;
        void *src;
        Unk044394_Unk_044428(36);
        entry = Unk02f2a8_GetRes36Unk19(idx);
        if (held == 0) {
            Unk044394_Unk_044534(36);
        }
        src = func_0204fed8(func_0204fe68(res, 0), entry - 1);
        if (src != 0) {
            if (count >= 15) count = 15;
            func_0200866c(src, dst, count * 2);
            ok = 1;
        }
    }
    return ok;
}

/* 16-byte record sorted by func_02036fb8 on its +4 key. */
typedef struct Unk02f2a8SortEntry {
    u32 unk_0000;
    s32 unk_0004;               /* sort key */
    u32 unk_0008;
    u32 unk_000c;
} Unk02f2a8SortEntry;

/* Counted record list at the start of the 0x794-byte work block. */
typedef struct Unk02f2a8SortList {
    u32 count;
    Unk02f2a8SortEntry entries[1]; /* size unknown: count entries follow */
} Unk02f2a8SortList;

/* Insertion-sort the list's records by ascending +4 key (stable). */
void func_02036fb8(Unk02f2a8SortList *list)
{
    Unk02f2a8SortEntry tmp = {0};
    u32 i;
    int j;
    for (i = 1; i < list->count; i++) {
        for (j = i; j > 0; j--) {
            if (list->entries[j].unk_0004 >= list->entries[j - 1].unk_0004) break;
            tmp = list->entries[j];
            list->entries[j] = list->entries[j - 1];
            list->entries[j - 1] = tmp;
        }
    }
}

void func_0203721c(void *work, void *map, void *cells, void *position,
                   u16 id, int x, int y, u32 flag, int kind)
{
    if (position == 0 || cells == 0 || position == 0) return;
    func_02008848(work, 0, 0x794);
    func_02036c48(work, map, position, id, x, y, flag);
    func_02036fb8(work);
    if (map == 0) return;
    func_020370e8(work, map, cells);
}

int func_02053800(int channel, int mask);
/* Test masks in priority order and latch the corresponding action word.
 * The 0x800/0x400 paths also notify 0441ec; action storage is borrowed. */
int func_020300ec(Unk02f2a8Action *action)
{
    int result = 0;
    if (func_02053800(0, 0xf3) == 1) {
        result = 1;
        action->unk_0030 = 1;
    } else if (func_02053800(0, 0x800) == 1) {
        result = 1;
        action->unk_0020 = 1;
        Unk03e43c_Unk_0441ec();
    } else if (func_02053800(0, 0x400) == 1) {
        result = 1;
        action->unk_0024 = 1;
        Unk03e43c_Unk_0441ec();
    } else if (func_02053800(0, 0x100) == 1) {
        result = 1;
        action->unk_0028 = 1;
    } else if (func_02053800(0, 0x200) == 1) {
        result = 1;
        action->unk_002c = 1;
    }
    return result;
}

Unk02f2a8Descriptor *Unk09ee4c_Unk_0a03b8(u32 id);

/* Clear the active cell state, then restore root flags if descriptor slot
 * +4 exists and returns zero. Requires a writable state and root. */
void func_02032ca0(Unk02f2a8State *s)
{
    Unk02f2a8Descriptor *d = Unk09ee4c_Unk_0a03b8(s->unk_747c);
    s->unk_7478 = 0;
    s->unk_7480 = 0;
    s->unk_7481 = 0;
    s->unk_7484 = 0;
    s->unk_7488 = 0;
    if (d->unk_0004 != 0 && d->unk_0004(s) == 0) {
        s->root->unk_0014 = 1;
        s->root->unk_0018 = 2;
        s->root->unk_001c = 0;
        s->root->unk_0044 = 1;
        s->root->unk_0050 = 1;
        s->root->unk_004c = 1;
        s->unk_7478 = 0;
        s->unk_747c = 0;
        s->unk_7480 = 0;
        s->unk_7481 = 0;
        s->unk_7484 = 0;
        s->unk_7488 = 0;
        s->unk_73cc = 2;
    }
}

/* Poll descriptor slot +8 (absent means success); success restores root
 * flags, clears the active cell, and optionally arms root +0x54. */
void func_02032d4c(Unk02f2a8State *s)
{
    int result = 1;
    Unk02f2a8Descriptor *d = Unk09ee4c_Unk_0a03b8(s->unk_747c);
    if (d->unk_0008 != 0) result = d->unk_0008(s);
    if (result == 1) {
        s->root->unk_0014 = 1;
        s->root->unk_0018 = 2;
        s->root->unk_001c = 0;
        s->root->unk_0044 = 1;
        s->root->unk_0050 = 1;
        s->root->unk_004c = 1;
        s->unk_7478 = 0;
        s->unk_747c = 0;
        s->unk_7480 = 0;
        s->unk_7481 = 0;
        s->unk_7484 = 0;
        s->unk_7488 = 0;
        s->unk_73cc = 2;
        if (s->unk_7498 != 0) s->root->unk_0054 = 1;
    }
}

/* Cell word's low five bits and bit five are independent packed fields. */
typedef struct Unk02f2a8CellFlags {
    u32 unk_0000;
    u32 unk_0004_0 : 5;
    u32 unk_0004_5 : 1;
    u32 unk_0004_6 : 26;
} Unk02f2a8CellFlags;
int func_020364bc(u16 value);
/* Accept only a live input and a current cell whose low-five-bit predicate
 * returns one and whose bit five is set. Repeated work access is intentional. */
int func_02030494(u32 *input)
{
    int result;
    Unk02f2a8GridState *s;
    Unk02f2a8WorkArea *a, *b;
    Unk02f2a8MapBlock *map;
    Unk02f2a8CellFlags *cell;
    if (*input == 0) return 0;
    result = 0;
    s = (Unk02f2a8GridState *)GetGameState();
    a = Unk02e000_GetWorkArea();
    b = Unk02e000_GetWorkArea();
    map = Unk02f2a8_Unk_034970(&s->body, a->unk_0364, b->unk_0365);
    a = Unk02e000_GetWorkArea();
    b = Unk02e000_GetWorkArea();
    cell = (Unk02f2a8CellFlags *)Unk038fbc_Unk_039160(map, a->unk_0364, b->unk_0365);
    if (cell != 0 && func_020364bc((u16)cell->unk_0004_0) == 1) {
        if (cell->unk_0004_5 == 1) result = 1;
    }
    return result;
}

/* Rebuild map work using the singleton's level byte (state +0x5b); +0x7400
 * suppresses it. Root position +0x7c and cell table +0x38e8 must remain live. */
void func_02118bec(int id, int v);
void Unk094fe0_Unk_0953f0(void);
/* Report counter targets for `id`: when the kind-0 target is set and reached
 * and every kind 1..7 column-0 counter reached its target, call 118bec(id, 1)
 * and 0953f0. With kind 1, also call 118bec(90 + 2 * e + j - 1, 1) for each
 * kind whose enable byte e is nonnegative and whose column j (1, 2) reached
 * its target. Does nothing when the kind-0 target is zero. */
void func_02030d84(Unk02f2a8Tally *t, u32 id, int kind)
{
    Unk02f2a8Res36 *row = &t->unk_0018;
    int all;
    int i;
    int j;
    int k;
    int m;
    if (t->rows.tgt.unk_7522 == 0) return;
    if (t->rows.tgt.unk_7522 <= t->unk_754e) {
        all = 1;
        for (i = 1; i <= 7; i++) {
            if (t->rows.cnt.unk_751e[i][0] < t->rows.tgt.unk_74f2[i][0]) {
                all = 0;
                break;
            }
        }
        if (all == 1) {
            func_02118bec(id, 1);
            Unk094fe0_Unk_0953f0();
        }
    }
    if (kind != 1) return;
    for (k = 1; k <= 7; k++) {
        int e = row->unk_001b[k];
        if (e < 0) continue;
        for (m = 1; m <= 2; m++) {
            if (t->rows.tgt.unk_74f2[k][m] <= t->rows.cnt.unk_751e[k][m]) {
                func_02118bec(m - 1 + (e * 2 + 90), 1);
            }
        }
    }
}

void func_02033f1c();
void func_02034128();
void func_0204b4e0(void);
void Unk0387bc_Unk_038c74(void *obj);
void Unk0387bc_Unk_038df8(void *obj);
void Unk0387bc_Unk_038f7c(void *obj);
void Unk095560_Unk_095af8(u32 id);
void Unk095560_Thunk_0202d15c(void);
void func_02052634(int a, int b, int c);
/* Create the global game state once: allocate the 0x75c0-byte task with
 * GameState_Shutdown as its teardown, publish it in gGameState, set up the
 * three sub-objects at +0x3134/+0x3140/+0x314c and the default words, create
 * the root task over body +0x23c, then run the start-up calls (resource 36,
 * the work-area id +0x35c, 052634(1, 3, 32)). No-op if it already exists. */
void func_0203428c(void)
{
    Unk02f2a8State *s;
    Unk02e000_GetWorkArea();
    if (gGameState != 0) return;
    s = func_020611dc(func_02033f1c, func_02034128, 0, GameState_Shutdown, 0x75c0, 0, 1, 1);
    gGameState = (GameState *)s;
    if (s == 0) return;
    Unk0387bc_Unk_038c74(s->unk_3134);
    Unk0387bc_Unk_038df8(s->unk_3140);
    Unk0387bc_Unk_038f7c(s->unk_314c);
    s->unk_73c8 = 0;
    s->unk_73cc = 0;
    s->unk_73d0 = -1;
    s->unk_73e8 = -1;
    s->unk_73ec = -1;
    s->unk_73d8 = 1;
    s->root = (Unk02f2a8StateRoot *)func_020303d0((u32)&s->body.unk_023c);
    func_0204b4e0();
    Unk044394_Unk_044428(36);
    Unk095560_Unk_095af8(Unk02e000_GetWorkArea()->unk_035c);
    Unk095560_Thunk_0202d15c();
    func_02052634(1, 3, 32);
}

void func_02034e90(void)
{
    Unk02f2a8State *s = (Unk02f2a8State *)gGameState;
    Unk02f2a8StateRoot *root;
    Unk02f2a8WorkArea *a, *b;
    Unk02f2a8MapBlock *map;
    if (s->unk_7400 != 0) return;
    root = s->root;
    a = Unk02e000_GetWorkArea();
    b = Unk02e000_GetWorkArea();
    map = Unk02f2a8_Unk_034970(&s->body, a->unk_0364, b->unk_0365);
    a = Unk02e000_GetWorkArea();
    b = Unk02e000_GetWorkArea();
    func_0203721c(s->unk_3154, map, s->unk_38e8, root->unk_007c,
        root->unk_0094, a->unk_0364, b->unk_0365,
        s->body.unk_0057, root->unk_0018);
}

/* Rebuild the same work with the level byte minus one, clamped to one. */
void func_02034dd0(void)
{
    Unk02f2a8State *s = (Unk02f2a8State *)gGameState;
    Unk02f2a8StateRoot *root;
    u32 value = s->body.unk_0057;
    Unk02f2a8WorkArea *a, *b;
    Unk02f2a8MapBlock *map;
    if (value > 1) value--; else value = 1;
    if (s->unk_7400 == 0) {
        root = s->root;
        a = Unk02e000_GetWorkArea();
        b = Unk02e000_GetWorkArea();
        map = Unk02f2a8_Unk_034970(&s->body, a->unk_0364, b->unk_0365);
        a = Unk02e000_GetWorkArea();
        b = Unk02e000_GetWorkArea();
        func_0203721c(s->unk_3154, map, s->unk_38e8, root->unk_007c,
            root->unk_0094, a->unk_0364, b->unk_0365,
            value, root->unk_0018);
    }
    ScanVisor_Unk_0a2b18();
}

/* Map-table entry reached through Unk02f2a8MapBlock.unk_0004. */
typedef struct Unk02f2a8MapEntry {
    u8 pad_0000[0x20];
    s16 unk_0020;               /* default id for func_02034f44 */
} Unk02f2a8MapEntry;

/* Cell record from Unk038fbc_Unk_039160; unk_0002 == -1 means no override. */
typedef struct Unk02f2a8CellId {
    u16 unk_0000;
    s16 unk_0002;
} Unk02f2a8CellId;

void func_0209da38(void *work, int id, u32 area, u32 value);
/* Enter state seven and initialize +0x7330 using the cell's signed halfword
 * override (unless -1), otherwise map-table halfword +0x20. Resource 9 is held. */
void func_02034f44(void)
{
    s16 id;
    Unk02f2a8State *s = (Unk02f2a8State *)gGameState;
    s8 x, y;
    Unk02f2a8CellId *cell;
    Unk02f2a8MapBlock *map;
    s->unk_73cc = 7;
    s->root->unk_0004 = 0;
    x = Unk02e000_GetWorkArea()->unk_0364;
    y = Unk02e000_GetWorkArea()->unk_0365;
    Unk044394_Unk_044428(9);
    cell = (Unk02f2a8CellId *)Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(&s->body, x, y), x, y);
    map = Unk02f2a8_Unk_034970(&s->body, x, y);
    id = ((Unk02f2a8MapEntry *)map->unk_0004)->unk_0020;
    if (cell != 0 && cell->unk_0002 != -1) id = cell->unk_0002;
    func_0209da38(s->unk_7330, id, Unk02e000_GetWorkArea()->unk_035c, s->unk_7494);
    Unk044394_Unk_044534(9);
}

void Unk0a6174_ClearBuffers(void *a, void *b);
void func_020a6ac0(void *a, void *b, void *c, void *d, u32 id, int f, int g);
/* Clear and rebuild +0x631c/+0x7130, then append each of seven enabled slots.
 * Missing singleton is a no-op; all helpers borrow its embedded buffers. */
void func_02035234(u32 id)
{
    Unk02f2a8State *s = (Unk02f2a8State *)gGameState;
    int i;
    if (s == 0) return;
    Unk0a6174_ClearBuffers(s->unk_631c, s->unk_7130);
    func_020a6ac0(s->unk_631c, s->unk_7130, s->unk_3134, s->unk_0358, id, 0, 0);
    for (i = 0; i < 7; i++) {
        int slot = i + 1;
        if (Unk02f2a8_Unk_035c14(id, slot) != 0) {
            func_020a7474(s->unk_631c, s->unk_7130, s->unk_0358, s->body.unk_0214, id, slot, 0);
        }
    }
}

/* Map a pair of 0..3 directions to 0..3 through a fixed 4x4 table; pairs
 * outside the table give 2. The meaning of the table is not established. */
void *func_020445d0();
int Unk038fbc_Unk_039160();
void Unk038fbc_Unk_039138();
/* Load a temporary map block keyed by the 16-byte name of resource-36 row
 * `row`, read bits 20..23 of the cell at (x, y) and return the row's s16
 * entry for that value (entry 0 when the load or the lookup fails). */
int func_0203572c(int row, int x, int y)
{
    Unk02f2a8Res36 *r;
    u32 k;
    int i;
    func_020445d0(36, 0);
    r = (Unk02f2a8Res36 *)func_0204fde0() + row;
    k = 0;
    s8 key[17] = {0};
    for (i = 0; i < 16; i++) {
        key[i] = r->unk_0000[i];
    }
    Unk02f2a8MapBlock map = {0};
    if (func_02038ff8(&map, key, 0, 0) == 1) {
        Unk02f2a8Obj39160 *o = (Unk02f2a8Obj39160 *)Unk038fbc_Unk_039160(&map, x, y);
        if (o != 0) {
            k = o->unk_0004_20;
        }
        Unk038fbc_Unk_039138(&map);
    }
    return r->unk_0010[k];
}

int func_0200219c(int num, int den);
/* Fixed-point (20.12) interpolation from `from` to `to`: returns
 * from + (to - from) * t / n, with t and n converted to fixed point through
 * rounded float. Returns `to` when n is 0 or t >= n, `from` when t <= 0. */
int func_02035cb4(int from, int to, u32 n, int t)
{
    int d;
    if (n == 0) return to;
    if (t <= 0) return from;
    if (n <= t) return to;
    d = to - from;
    d = (int)(((s64)d * (int)((float)t > 0 ? 4096.0f * (float)t + 0.5f : 4096.0f * (float)t - 0.5f) + 0x800) >> 12);
    return from + func_0200219c(d, (int)((float)n > 0 ? 4096.0f * (float)n + 0.5f : 4096.0f * (float)n - 0.5f));
}

/* Store the position for grid cell (x, z) at out[0..2]: each coordinate is
 * the cell index in 20.12 fixed point times 4.0, and the height is 0x8cd. */
void func_02035db8(s32 *out, int x, int z)
{
    s32 fz = (s32)(((s64)(int)((float)z > 0 ? 4096.0f * (float)z + 0.5f : 4096.0f * (float)z - 0.5f) * 0x4000 + 0x800) >> 12);
    s32 fx = (s32)(((s64)(int)((float)x > 0 ? 4096.0f * (float)x + 0.5f : 4096.0f * (float)x - 0.5f) * 0x4000 + 0x800) >> 12);
    out[0] = fx;
    out[1] = 0x8cd;
    out[2] = fz;
}

int func_0203611c(int a, int b)
{
    int r = 2;
    switch (a) {
    case 1:
        if (b == 1) r = 2;
        else if (b == 2) r = 0;
        else if (b == 3) r = 3;
        else if (b == 0) r = 1;
        break;
    case 2:
        if (b == 1) r = 1;
        else if (b == 2) r = 2;
        else if (b == 3) r = 0;
        else if (b == 0) r = 3;
        break;
    case 3:
        if (b == 1) r = 3;
        else if (b == 2) r = 1;
        else if (b == 3) r = 2;
        else if (b == 0) r = 0;
        break;
    case 0:
        if (b == 1) r = 0;
        else if (b == 2) r = 3;
        else if (b == 3) r = 1;
        else if (b == 0) r = 2;
        break;
    }
    return r;
}

/* Rotate direction `dir` (0..3) by `amount` (0..3) through a fixed table.
 * Callers (Unk02f2a8_Unk_02fc10, the step helper) pass the cached heading.
 * Out-of-range inputs return `dir` unchanged. */
int func_020361ec(int dir, int amount)
{
    switch (dir) {
    case 1:
        if (amount == 0) return 2;
        if (amount == 1) return 0;
        if (amount == 2) return 1;
        if (amount == 3) return 3;
        break;
    case 2:
        if (amount == 0) return 3;
        if (amount == 1) return 1;
        if (amount == 2) return 2;
        if (amount == 3) return 0;
        break;
    case 3:
        if (amount == 0) return 0;
        if (amount == 1) return 2;
        if (amount == 2) return 3;
        if (amount == 3) return 1;
        break;
    case 0:
        if (amount == 0) return 1;
        if (amount == 1) return 3;
        if (amount == 2) return 0;
        if (amount == 3) return 2;
        break;
    }
    return dir;
}
