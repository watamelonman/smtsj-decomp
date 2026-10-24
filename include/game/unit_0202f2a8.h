#ifndef GAME_UNIT_0202F2A8_H
#define GAME_UNIT_0202F2A8_H

/* Local struct views, helper macros and callee prototypes for
 * src/game/unit_0202f2a8.c, kept here so the TU source stays within the file
 * size limit. Layouts are partial: only members the TU reads are named. */

#include "GameState.h"
#include "types.h"

struct Unk02f2a8SortList;

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
    u8 pad_0058[4];
    u32 unk_005c;               /* one-shot request consumed by func_02033f1c */
    u8 pad_0060[0x7c - 0x60];
    u8 unk_007c[0x94 - 0x7c];   /* size guessed: position block passed to func_0203721c */
    u16 unk_0094;
    u8 pad_0096[0x9c - 0x96];
    u32 unk_009c;
} Unk02f2a8StateRoot;

/* One map block embedded in the body Unk02f2a8_Unk_034970 picks from; only
 * its extent (the distance between the two blocks) is known. */
typedef struct Unk02f2a8MapBlock {
    u8 *unk_0000;               /* nonzero required by Unk_0351b4; +8..+11 bound the
                                 * cell grid scanned by func_02035890 */
    u8 *unk_0004;              /* byte table indexed by 034a8c's result + 15 */
    u8 pad_0008[0x2c8 - 0x23c - 8];
} Unk02f2a8MapBlock;

/* Body view used by Unk02f2a8_Unk_034970 (callers pass state +4). */
typedef struct Unk02f2a8Body {
    u32 unk_0000;               /* nonzero once the body is live (func_02034128) */
    u8 pad_0004[0x14 - 4];
    u8 unk_0014[0x24 - 0x14];   /* size guessed: block handed to func_020a7474 / func_02038888 */
    s16 unk_0024[6]; /* size guessed: indexed by bits 20..23 of a cell word (func_020305a8) */
    s8 unk_0030[15]; /* size guessed: indexed by a 4-bit cell id minus 1 */
    u8 pad_003f[0x57 - 0x3f];
    u8 unk_0057;                /* level byte passed to func_0203721c (state +0x5b) */
    u8 pad_0058[0x214 - 0x58];
    u8 unk_0214[0x23c - 0x214]; /* size guessed: buffer handed to func_020a7474 (state +0x218) */
    Unk02f2a8MapBlock unk_023c;
    Unk02f2a8MapBlock unk_02c8;
} Unk02f2a8Body;

/* Each pending value carries a flag so a zero amount need not arm it. */
typedef struct Unk02f2a8PendingValue {
    u32 flag;
    s32 amount;
} Unk02f2a8PendingValue;

/* Local view of state fields beyond the public GameState layout. */
typedef struct Unk02f2a8State {
    Unk02f2a8StateRoot *root;
    Unk02f2a8Body body;         /* +0x0004 */
    u8 unk_0358[0x3134 - 0x358]; /* buffer sizes up to 0x7330 guessed from the next known field */
    u8 unk_3134[0xc];
    u8 unk_3140[0xc];
    u8 unk_314c[0x3154 - 0x314c]; /* sub-object of unknown size */
    u8 unk_3154[0x38e8 - 0x3154];
    u8 unk_38e8[0x5508 - 0x38e8]; /* 45x40 table of 4-byte cells */
    u8 unk_5508[0x631c - 0x5508]; /* buffer rebuilt by func_02031274; same size as +0x631c */
    u8 unk_631c[0x7130 - 0x631c];
    u8 unk_7130[0x7330 - 0x7130];
    u8 unk_7330[0x73c8 - 0x7330];
    u32 unk_73c8;
    u32 unk_73cc;
    u32 unk_73d0;
    u32 unk_73d4;               /* cell selector compared by func_02034b7c */
    u32 unk_73d8;
    u8 pad_73dc[4];
    u32 unk_73e0;
    u32 unk_73e4;
    u32 unk_73e8;
    u32 unk_73ec;
    u8 pad_73f0[0x73fc - 0x73f0];
    u32 unk_73fc;
    u32 unk_7400;               /* nonzero suppresses the func_0203721c rebuild */
    u8 pad_7404[0x7410 - 0x7404];
    u8 unk_7410[0x7430 - 0x7410]; /* size guessed: position block used instead of root +0x7c */
    u32 unk_7430;               /* nonzero: func_02033f1c runs 052da0 */
    u32 unk_7434;
    u32 unk_7438;               /* 1: func_02033f1c hands +0x7430/+0x7434 to 052d7c */
    u32 unk_743c;               /* 1: transition armed by func_02034b7c */
    u32 unk_7440;
    u32 unk_7444;
    u32 unk_7448;
    u16 unk_744c;               /* func_02034b7c destination id, x, y, heading */
    s8 unk_744e;
    s8 unk_744f;
    u32 unk_7450;
    u16 unk_7454;               /* work-area id, x, y, heading at arm time */
    s8 unk_7456;
    s8 unk_7457;
    u32 unk_7458;
    u32 unk_745c;               /* func_02034b7c mode, brightness flag, a, b */
    u32 unk_7460;
    u32 unk_7464;
    u32 unk_7468;
    u32 unk_746c;               /* 1 when the destination id differs */
    u8 pad_7470[0x7478 - 0x7470];
    u32 unk_7478;               /* +0x7478..+0x748b cleared by Unk_032f3c */
    u32 unk_747c;
    s8 unk_7480;                /* id handed to func_02038888/func_02030924 */
    s8 unk_7481;                /* step of the func_02032e18 sequence */
    s8 unk_7482;                /* grid x/y of the func_02033f1c rebuild */
    s8 unk_7483;
    s32 unk_7484;               /* frame counter of the func_02032e18 sequence */
    u32 unk_7488;
    u32 unk_748c;               /* 1: func_02033f1c rebuilds at +0x7482/+0x7483 */
    u32 unk_7490;
    u32 unk_7494;
    u32 unk_7498;               /* nonzero arms root +0x54 in func_02032d4c */
    u8 pad_749c[8];
    u32 unk_74a4;
    Unk02f2a8PendingValue unk_74a8[4];
    Unk02f2a8PendingValue unk_74c8[4];
    u8 pad_74e8[0x74f0 - 0x74e8];
    u32 unk_74f0;               /* compared with Unk03e43c_Unk_03fa28 by func_02035008 */
    u8 pad_74f4[0x7550 - 0x74f4];
    u8 unk_7550[0x757c - 0x7550]; /* size guessed: block handed to func_02099494 */
    u32 unk_757c;
    u8 pad_7580[0x18];
    u32 unk_7598;
} Unk02f2a8State;

Unk02f2a8WorkArea *Unk02e000_GetWorkArea(void);
void *Unk02e000_Unk_02e8b8(void);
void ScanVisor_Unk_0a2a8c(int i);
void Unk11f2d0_Unk_11f320(void *obj);
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

/* Local view of the GameState sub-block headers at +0x240 and +0x2cc;
 * include/GameState.h (not owned by this card) pads both ranges. */
typedef struct Unk02f2a8GameStateSubs {
    u8 pad_0000[0x240];
    u32 unk_0240;
    u8 pad_0244[0x2cc - 0x244];
    u32 unk_02cc;
} Unk02f2a8GameStateSubs;

int Unk02f2a8_DirToAngle(int dir);
int Unk0e5fb8_Unk_0e63c8();
int Unk02e000_TestFlag();
void Unk02e000_SetBit_02e968();
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

void func_02061424(void *obj);
int Unk038fbc_Unk_039160();
int Unk044394_Unk_044428(int i);
int Unk044394_Unk_044534(int i);
void func_020f43d4(void);
int func_02050088(int mode, int lower, int upper);
void func_0205bb68(void);
/* Local view of an object whose +8 word counts live entries. */
typedef struct Unk02f2a8Counted {
    u8 pad_0000[8];
    s32 unk_0008;
} Unk02f2a8Counted;

void Unk02f2a8_Unk_030d20(u8 *p, int mode);
int func_020572c0();
int func_0205e590();
u32 Unk095560_Unk_0956a8(void);
int func_020361ec(int dir, int amount);
int Unk0a0ce4_Unk_0a0da4();
int func_021214e0(u32 v);
int func_021215d4();
int func_0202f530();
int func_0202f8f0();
int func_0202fc50();
void func_02030204(Unk02f2a8Action *action);
void func_02035edc(void *obj, const void *position);
typedef struct Unk02f2a8Lerp {
    u8 pad_0000[0x1c];
    s32 unk_001c;               /* interpolated value written by func_02036368 */
} Unk02f2a8Lerp;

int func_02036368(Unk02f2a8Lerp *obj, int to, u32 n, int t);
void Unk02f2a8_SetRootUnk60();
int func_0205257c(int v);
/* If 04b4c4 accepts the context, set its +0x20/+0x28/+0x2c flag for
 * selectors 0..2/5/4 respectively. Return one only for a handled selector. */
int func_0209be20(int x, int y);

int func_02038ff8();
void func_02039520();
void func_020a7474(void *a, void *b, void *c, void *d, u32 id, int f, int g);
int Unk03e43c_Unk_03fa28(void);
void Unk03e43c_AdvanceCounter360(void);
void Unk094fe0_Unk_0952ac(void);
void func_0203480c(u8 *body, int mode);
int Unk03e43c_SetMode30();
u32 Unk038fbc_Unk_038fbc(int *obj);
u32 Unk0387bc_Unk_038e40(int *obj);
u32 Unk0387bc_Unk_038cbc(int *obj);
void Unk02cad4_Unk_02cbdc(u32 a);
int func_020987ac();
void func_02008644();
void *func_0204459c();
void *func_0204fe68();
void *func_0204fed8();
void func_0200866c(const void *source, void *dest, u32 size);
u32 func_0204fe18();
Unk02f2a8MapBlock *Unk02f2a8_Unk_034970(Unk02f2a8Body *p, int x, int y);
/* Game state viewed as root pointer plus the body used by 034970. */
typedef struct Unk02f2a8StateBody {
    GameStateRoot *root;
    Unk02f2a8Body body;
} Unk02f2a8StateBody;

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
int func_02118c6c(int id);
int Unk04bb9c_GetCtxUnka20(void);
int func_0202fea0(Unk02f2a8Action *action);
int func_020300ec(Unk02f2a8Action *action);
void Unk03e43c_Unk_0441ec(void);
/* Callback descriptor observed at 09c498: +4 is the transition predicate,
 * +0x14 selects the cell filter. The descriptor remains borrowed. */
typedef struct Unk02f2a8Descriptor {
    int (*unk_0000)(Unk02f2a8State *state);
    int (*unk_0004)(Unk02f2a8State *state);
    int (*unk_0008)(Unk02f2a8State *state);
    void (*unk_000c)(Unk02f2a8State *state);
    u8 pad_0010[4];
    u32 unk_0014;
} Unk02f2a8Descriptor;

Unk02f2a8Descriptor *Unk09a268_Unk_09c498(int id);
int func_0209c090(int x, int y, int direction, int flag);
void func_02008848(void *dst, int value, u32 size);
void func_02036fb8(struct Unk02f2a8SortList *list);
void func_020370e8(struct Unk02f2a8SortList *list, void *map, u8 *cells);
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
void func_0205e484(int id, int mode);
/* Leading byte of the cell object Unk038fbc_Unk_039160 returns. */
typedef struct Unk02f2a8CellHead {
    u8 unk_0000;
} Unk02f2a8CellHead;

typedef void (*Unk02f2a8GridHandler)(Unk02f2a8GridState *s);
Unk02f2a8GridHandler *Unk09a268_Unk_09c4a8(Unk02f2a8MapBlock *b, int x, int y);
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
int Unk044394_HasEntry(int i);
/* 16-byte record sorted by func_02036fb8 on its +4 key. */
typedef struct Unk02f2a8SortEntry {
    u32 unk_0000;               /* set to 1 by func_020370e8 */
    s32 unk_0004;               /* sort key */
    s16 unk_0008;
    s16 unk_000a;
    s8 unk_000c;                /* grid x */
    s8 unk_000d;                /* grid y */
    u8 pad_000e[2];
} Unk02f2a8SortEntry;

/* Counted record list at the start of the 0x794-byte work block. */
typedef struct Unk02f2a8SortList {
    u32 count;
    Unk02f2a8SortEntry entries[1]; /* size unknown: count entries follow */
} Unk02f2a8SortList;

int func_02053800(int channel, int mask);
Unk02f2a8Descriptor *Unk09ee4c_Unk_0a03b8(u32 id);
/* Cell word's low five bits and bit five are independent packed fields. */
typedef struct Unk02f2a8CellFlags {
    u32 unk_0000;
    u32 unk_0004_0 : 5;
    u32 unk_0004_5 : 1;
    u32 unk_0004_6 : 26;
} Unk02f2a8CellFlags;

int func_020364bc(u16 value);
void func_02118bec(int id, int v);
void Unk094fe0_Unk_0953f0(void);
void func_02033f1c();
void func_02034128();
void func_0204b4e0(void);
void Unk0387bc_Unk_038c74(void *obj);
void Unk0387bc_Unk_038df8(void *obj);
void Unk0387bc_Unk_038f7c(void *obj);
void Unk095560_Unk_095af8(u32 id);
void Unk095560_Thunk_0202d15c(void);
void func_02052634(int a, int b, int c);
void Unk0a6174_ClearBuffers(void *a, void *b);
void func_020a6ac0(void *a, void *b, void *c, void *d, u32 id, int f, int g);
void func_020a6c98(void *a, void *b, void *c, void *d, u32 id, int f, int g);
void func_020a6e94(void *a, void *b);
void func_020a7108(void *a, void *b);
int Unk04bb9c_GetCtxUnka20(void);
void func_020a7ae4(void *dst, void *src, int on);
void func_020a7bd0(void *dst, void *src, int on);
struct Unk02f2a8Descriptor *Unk09ee4c_Unk_0a03b8(u32 id);
void ScanVisor_Unk_0a2a60(int i, int mode);
int func_020a4f3c(void);
void Unk038fbc_Unk_039138(void *owner);
void func_02038888(void *block, int id, int flag);
void func_02030924(Unk02f2a8Body *body, int id);
void func_0204cbac(int id);
void func_0204b66c(int id);
void func_0204ccb0(void);
void func_0204b6f4(void);
void func_020525cc(int v);
void func_02032a40(Unk02f2a8GridState *s);
void func_02032b70(Unk02f2a8GridState *s);
void func_02032ca0(Unk02f2a8State *s);
void Unk02f2a8_ResetField7478(GameState *gs);
void Unk02f2a8_ResetField7478Ex(GameState *gs);
void Unk02f2a8_Unk_032f3c(Unk02f2a8State *state);
void Unk02f2a8_Unk_033890(GameState *gs);
void Unk02f2a8_Unk_033ac8(GameState *gs);
void Unk02f2a8_Unk_033c94(u32 *ctx);
void func_02032020(Unk02f2a8State *s);
void func_0203229c(Unk02f2a8State *s);
void func_02032adc(Unk02f2a8State *state);
void func_02032c0c(Unk02f2a8State *state);
void func_02032d4c(Unk02f2a8State *s);
void func_02032e18(Unk02f2a8State *s);
void func_02032fb8(Unk02f2a8State *s);
void func_02033400(Unk02f2a8State *s);
void func_020338b0(Unk02f2a8State *s);
void func_02033ae8(Unk02f2a8State *s);
int func_02052728(void);
void Unk11f2d0_Unk_11f308(void *obj, int frames);
void func_02031758(Unk02f2a8State *s);
void func_02031df8(Unk02f2a8State *s);
void func_020993a8(void *obj);
void Unk11ec7c_Update(void *obj);
void func_02052da0(void);
void func_02052d7c(u32 a, u32 b);
s8 *func_02052dd8(void);
void Unk095560_Unk_0958a8(int x, int y);
void func_02034e90(void);
void func_02037d50(void *cells, void *work, Unk02f2a8Body *body, void *position, int flag);
void func_02099494(void *obj);
void func_0211f0a0(void *obj);
void func_02057fd8(void);
void func_0212168c(Unk02f2a8State *s);
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
void Unk0a6174_ClearBuffers(void *a, void *b);
void func_020a6ac0(void *a, void *b, void *c, void *d, u32 id, int f, int g);
void *func_020445d0();
int Unk038fbc_Unk_039160();
int func_0200219c(int num, int den);
int func_0200219c(int num, int den);
int func_02037054(void *map, u8 *cells, int x, int y);
int Unk0e651c_Unk_0e666c(int id);
int func_021125e8(void);
void *Unk02e000_Thunk_0202e788(void);
int func_020361ec(int dir, int amount);
int ScanVisor_Unk_0a2b38(void);
int Unk095560_Unk_09615c(void);
int Unk09a268_Unk_09beb0(int x, int y);
void func_0209aa00(u32 id, int x, int y);
void func_02116470(void);
void func_020392f8(void *out, const s8 *key, u8 id, u8 value, int arg, int kind);
void func_020396cc(void *body);
void Unk0392f8_Unk_039454(void *obj);
int Unk0a23f4_Unk_0a23f4(int value);
int ScanVisor_Unk_0a273c(int value);
int Unk02dcfc_GetState(void);
int Unk065e88_Unk_065e88(void);
int Unk0964f8_Unk_096508(void);
int Unk095560_Thunk_020773dc(int value);
void func_02099318(void *a, void *b, void *map, void *cells);
void Unk11ec7c_Unk_11f004(void *obj);
int func_020343ec(void *body, int id, int x, int y, int ctx, int a, int b, void *out);
void func_0209a884(void *cells, void *body);
int Unk03e43c_Thunk_0203fa84(void);
u16 func_02061bd4(int group, int index);
void func_02111494(void);
void Unk02cad4_SetupDisplayMode(int mode, int a, int b);
void func_0204b504(void);
void func_0204ccb0(void);
void func_0204b6f4(void);
void Unk02dcfc_Unk_02de6c(void);
/* Direction occupies bits 4..6 in each element word (02031448). */
typedef struct Unk02f2a8Element {
    u32 directionLow : 2;
    u32 pad_0000 : 2;
    u32 direction0 : 3;
    u32 rest_0000 : 25;
    u32 pad_0004 : 4;
    u32 direction1 : 3;
    u32 rest_0004 : 25;
} Unk02f2a8Element;

Unk02f2a8Element *Unk038fbc_GetElement(void *map, int type, int index);
int Unk0a50d4_IsSubBrightnessMax(void);
int func_0205e590(int id);
/* Callback table selected by the halfword ids at actor +0x6c/+0x34. */
typedef struct Unk02f2a8ActorDescriptor {
    u32 unk_0000[2];
    void (*unk_0008)(Unk02f2a8State *state, u8 slot);
} Unk02f2a8ActorDescriptor;

/* Actor views for func_02035008: only the descriptor id halfword is known. */
typedef struct Unk02f2a8LeadActor {
    u8 pad_0000[0x6c];
    u16 unk_006c;
} Unk02f2a8LeadActor;

typedef struct Unk02f2a8MemberActor {
    u8 pad_0000[0x34];
    u16 unk_0034;
} Unk02f2a8MemberActor;

void *Unk02e000_Thunk_0202e788(void);
u8 *Unk02e000_Unk_02e7c0(int index);
Unk02f2a8ActorDescriptor *Unk109230_Unk_109328(u32 id);
int func_02096f54(int changed);
int func_0209701c(int changed);
int func_02097a20(u8 *actor, int changed);
int func_02097ad0(u8 *actor, int changed);
/* Resource position block: 02035890 reads its signed bytes at +0x23/+0x24. */
typedef struct Unk02f2a8PositionBlock {
    u32 words[8];
    u8 pad_0020[3];
    s8 x;
    s8 y;
    u8 pad_0025[0x228 - 0x25];
} Unk02f2a8PositionBlock;

#endif
