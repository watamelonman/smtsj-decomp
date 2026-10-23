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
    u8 pad_0004[0x10 - 4];
    u32 unk_0010;
    u32 unk_0014;
    u32 unk_0018;
    u32 unk_001c;
    u8 pad_0020[0x9c - 0x20];
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
} Unk02f2a8StateRoot;

/* Local view of state fields beyond the public GameState layout. */
typedef struct Unk02f2a8State {
    Unk02f2a8StateRoot *root;
    u8 pad_0004[0x73c8 - 4];
    u32 unk_73c8;
    u8 pad_73cc[0x73e0 - 0x73cc];
    u32 unk_73e0;
    u32 unk_73e4;
    u8 pad_73e8[0x7478 - 0x73e8];
    u32 unk_7478;               /* +0x7478..+0x748b cleared by Unk_032f3c */
    u32 unk_747c;
    u8 unk_7480;
    u8 unk_7481;
    u8 pad_7482[2];
    u32 unk_7484;
    u32 unk_7488;
    u8 pad_748c[0x757c - 0x748c];
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
void func_02035db8();
int Unk02f2a8_SetGridPos(int x, int y, u32 v);
void func_0209e0b0(void);
int Unk095560_Thunk_020961a0(void);
void func_020305a8(void *p, int v);
void func_020a269c(int v);
void Unk0a4e48_Unk_0a4e9c();
int Unk02f2a8_GridIndex45(int x, int y);
void Unk02f2a8_Unk_0306a8(Unk02f2a8State *state);

typedef struct Unk02f2a8Obj39160 {
    u32 unk_0000;
    u32 pad_0004_0 : 12;
    u32 unk_0004_12 : 4;
    u32 unk_0004_16 : 4;
    u32 pad_0004_20 : 12;
} Unk02f2a8Obj39160;
/* Forward the grid coordinates cached at work-area +0x364/+0x365, plus the
 * caller's object at p+0x70, to func_02035db8. The accessor is called twice,
 * once per coordinate, matching the original instruction stream. */
void Unk02f2a8_Call_02035db8(u8 *p)
{
    Unk02f2a8WorkArea *a = Unk02e000_GetWorkArea();
    Unk02f2a8WorkArea *b = Unk02e000_GetWorkArea();
    func_02035db8(p + 0x70, a->unk_0364, b->unk_0365);
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
    func_020305a8(p, 1);
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
    u8 pad_0000[0x18];
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
int func_02030204();
/* Dispatch the action type at +0x10: type zero arms +0x14, types 1..4
 * call their handlers, and other types leave it unchanged. */
void Unk02f2a8_Unk_0302f4(Unk02f2a8Action *action)
{
    switch (action->unk_0010) {
    case 0:
        action->unk_0014 = 1;
        return;
    case 1:
        func_02030204();
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
void func_02038ff8();
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

/* One map block embedded in the body Unk02f2a8_Unk_034970 picks from; only
 * its extent (the distance between the two blocks) is known. */
typedef struct Unk02f2a8MapBlock {
    u32 unk_0000;               /* nonzero required by Unk_0351b4 */
    u8 *unk_0004;               /* byte table indexed by 034a8c's result + 15 */
    u8 pad_0008[0x2c8 - 0x23c - 8];
} Unk02f2a8MapBlock;

/* Body view used by Unk02f2a8_Unk_034970 (callers pass state +4). */
typedef struct Unk02f2a8Body {
    u8 pad_0000[0x30];
    s8 unk_0030[15]; /* size guessed: indexed by a 4-bit cell id minus 1 */
    u8 pad_003f[0x23c - 0x3f];
    Unk02f2a8MapBlock unk_023c;
    Unk02f2a8MapBlock unk_02c8;
} Unk02f2a8Body;

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

int Unk0986ac_Unk_098978();
int Unk0986ac_Thunk_02098714();

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
