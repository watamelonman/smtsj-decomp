#include "GameState.h"
#include "types.h"

extern u8 data_02176278[];
void func_02008848(void *dst, int value, u32 size);
/* Clears the singleton storage: the original passes data_02176278 and 0x884
 * bytes to the fill helper, supporting the Init name. */
void Unk09d42c_Init_data_02176278(void)
{
    func_02008848(data_02176278, 0, 0x884);
}

/* Resets the word at +0x808 and compares signed words at +0x800/+0x804.
 * The singleton must contain its full 0x884-byte storage. */
int Unk09d42c_Unk_09d4bc(void)
{
    *(int *)(data_02176278 + 0x808) = 0;
    return *(int *)(data_02176278 + 0x800) > *(int *)(data_02176278 + 0x804);
}

/* Converts the sentinel 0xff to zero; all other signed inputs pass through. */
int Unk09d42c_Unk_09d600(int arg0)
{
    if (arg0 == 0xff) {
        arg0 = 0;
    }
    return arg0;
}

extern u8 data_02176278[];
/* Tests equality of the singleton words at +0x800 and +0x804. */
int Unk09d42c_Unk_09d4e0(void)
{
    return *(int *)(((int)data_02176278) + 0x800) == *(int *)(((int)data_02176278) + 0x804);
}

u32 Unk02e000_GetWorkArea(void);
u32 func_0203611c(u32 a, u32 b);

int func_020445d0(int group, int table);
void *func_0204fde0(int table);
u32 func_0204fe18(int table);
void func_02052da0(u8 *state);
u32 *Unk02f2a8_GetCell38e8(int x, int y);
int Unk09a268_Unk_09a844(void);
int Unk1124f0_Unk_11259c(int index);
/* Maps zero to one and, when enabled, IDs 62..64 to 65..67. These
 * explicit ID comparisons in the original support the MapId name; the result
 * is truncated to a byte for other inputs. */
u8 Unk09d42c_MapId(int a, int b)
{
    if (a == 0) {
        return 1;
    }
    if (b != 0) {
        switch (a) {
        case 62:
            return 65;
        case 63:
            return 66;
        case 64:
            return 67;
        }
    }
    return a;
}

/* Borrows an entry from resource group 9, table 0 (evidence: helper arguments
 * and two-byte stride). Invalid signed indices return the table base. */
u8 *Unk09d42c_GetTable0Entry(int i)
{
    int t = func_020445d0(9, 0);
    u8 *base = (u8 *)func_0204fde0(t);
    if (i < 0 || (u32)i >= (u32)func_0204fe18(t)) {
        return base;
    }
    return base + i * 2;
}

/* Borrows group 9/table 1 storage (lookup arguments in the original).
 * Signed invalid indices return its base; valid entries have 106-byte stride. */
u8 *Unk09d42c_GetTable1Entry(int i)
{
    int t = func_020445d0(9, 1);
    u8 *base = (u8 *)func_0204fde0(t);
    if (i < 0 || (u32)i >= (u32)func_0204fe18(t)) {
        return base;
    }
    return base + i * 106;
}

/* Borrows group 9/table 2 storage (lookup arguments in the original).
 * Signed invalid indices return its base; valid entries have 24-byte stride. */
u8 *Unk09d42c_GetTable2Entry(int i)
{
    int t = func_020445d0(9, 2);
    u8 *base = (u8 *)func_0204fde0(t);
    if (i < 0 || (u32)i >= (u32)func_0204fe18(t)) {
        return base;
    }
    return base + i * 24;
}

typedef struct Unk09d42cList {
    char names[64][32];         /* count from the +0x800 count offset */
    s32 count;
} Unk09d42cList;
typedef struct Unk09d42cMap {
    u16 flag;
    u16 key;
    u16 val;
} Unk09d42cMap;
extern char data_0214c9cc[];
int func_020152cc();
void func_02013c3c();
int Unk0e651c_Unk_0e666c(u16 flag);

/* Scans borrowed six-byte records in group 9/table 4, returning the first
 * value whose key equals id and whose flag helper succeeds, or id if absent. */
u16 Unk09d42c_Unk_09d73c(u16 id)
{
    int tab = func_020445d0(9, 4);
    Unk09d42cMap *e = (Unk09d42cMap *)func_0204fde0(tab);
    u32 n = func_0204fe18(tab);
    u32 i;
    for (i = 0; i < n; i++, e++) {
        if (e->key == id && Unk0e651c_Unk_0e666c(e->flag) != 0) {
            return e->val;
        }
    }
    return id;
}

/* Borrows group 9/table 3 storage (lookup arguments in the original).
 * Signed invalid indices return its base; valid entries have 52-byte stride. */
u8 *Unk09d42c_GetTable3Entry(int i)
{
    int t = func_020445d0(9, 3);
    u8 *base = (u8 *)func_0204fde0(t);
    if (i < 0 || (u32)i >= (u32)func_0204fe18(t)) {
        return base;
    }
    return base + i * 52;
}

/* Updates the supplied state, increments the cell halfword at +2 using signed
 * coordinates at state +0x7482/+0x7483, and tests the helper result for one.
 * State and its selected cell must exist; the halfword increment wraps. */
int Unk09d42c_Unk_09df70(u8 *p)
{
    int r = 0;
    u8 *cell;
    func_02052da0(p);
    cell = (u8 *)Unk02f2a8_GetCell38e8(FIELD(s8, p + 29696, 130), FIELD(s8, p + 29696, 131));
    FIELD(u16, cell, 2) += 1;
    if (Unk09a268_Unk_09a844() == 1) {
        r = 1;
    }
    return r;
}

int Unk0a23f4_Unk_0a246c(void);
void ScanVisor_Unk_0a2b18(void);
int Unk0a23f4_Unk_0a2448(void);

/* Borrowed state prefix exposing only the phase word observed in the original.
 * The caller retains ownership and must supply storage through +0x73f3. */
typedef struct Unk09d42cPhaseState {
    u8 prefix[0x73f0];
    u32 phase;
} Unk09d42cPhaseState;

/* Dispatches the supplied state's +0x73f0 phase. Phase zero advances after
 * the first predicate returns one and the action runs; phase one returns
 * whether the second predicate is zero. Other phases return zero. */
int func_0209e020(Unk09d42cPhaseState *state)
{
    int result = 0;
    switch (state->phase) {
    case 0:
        if (Unk0a23f4_Unk_0a246c() == 1) {
            ScanVisor_Unk_0a2b18();
            state->phase = state->phase + 1;
        }
        break;
    case 1:
        if (Unk0a23f4_Unk_0a2448() == 0) {
            result = 1;
        }
        break;
    }
    return result;
}

/* Calls the optional second callback in the eight-byte record selected by
 * state +0x73ec; an absent callback succeeds with one. State/record must exist. */
int Unk09d42c_Unk_09e080(u8 *p)
{
    int r = 1;
    int (**ent)(void) = (int (**)(void))Unk1124f0_Unk_11259c(FIELD(u32, p + 28672, 1004));
    if (ent[1] != 0) {
        r = ent[1]();
    }
    return r;
}

/* Returns one when no game state exists or its signed +0x73e8 word is -1. */
int Unk09d42c_Unk_09e274(void)
{
    u8 *gs = (u8 *)GetGameState();
    if (gs == 0) {
        return 1;
    }
    return FIELD(s32, gs + 28672, 1000) == -1;
}

/* Resolves arg0 through work-area +0x358, stores the result at root +0x18,
 * sets root +0x14 to four and state +0x73e8 to one. Null state is ignored;
 * a present state must have a root and a valid work area. */
void Unk09d42c_Unk_09e2f4(u32 arg0)
{
    GameState *gs = GetGameState();
    u32 v;
    if (gs == 0) {
        return;
    }
    v = func_0203611c(*(u32 *)(Unk02e000_GetWorkArea() + 0x358), arg0);
    gs->root->unk_18 = v;
    gs->root->unk_14 = 4;
    gs->unk_73e8 = 1;
}

/* Resolves arg0 through work-area +0x358, stores the result at root +0x18,
 * sets root +0x14 to two, and clears root +0xc and state +0x73e8. Null state
 * is ignored; a present state must have a root and a valid work area. */
void Unk09d42c_Unk_09e2a4(u32 arg0)
{
    GameState *gs = GetGameState();
    u32 v;
    if (gs == 0) {
        return;
    }
    v = func_0203611c(*(u32 *)(Unk02e000_GetWorkArea() + 0x358), arg0);
    gs->root->unk_18 = v;
    gs->root->unk_14 = 2;
    gs->root->unk_0c = 0;
    gs->unk_73e8 = 0;
}
