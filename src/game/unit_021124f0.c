#include "GameState.h"
#include "types.h"

/* Work area at Unk02e000_GetWorkArea(): the fields used here are the active
 * record id (+0x35C) and the signed position pair (+0x364, +0x365). */
typedef struct Unk1124f0WorkArea {
    u8 pad_0000[0x35c];
    u16 unk_035c;
    u8 pad_035e[6];
    s8 unk_0364;
    s8 unk_0365;
} Unk1124f0WorkArea;

/* Object returned by Unk038fbc_Unk_039160 for a position.  Only the four bits
 * at +4 bits 20..23 are read here (extracted as lsl #8 / lsr #28). */
typedef struct Unk1124f0Object {
    u32 unk_0000;
    u32 pad_0004_0 : 20;
    u32 unk_0004_20 : 4;
} Unk1124f0Object;

/* Request block consumed by Unk0bc1a8_Unk_0bc928: bit i of mask marks ptrs[i]
 * valid.  The callee only reads the block through the third argument. */
typedef struct Unk1124f0Req {
    u8 mask[2];
    void *ptrs[16];
} Unk1124f0Req;

int Unk02f2a8_Unk_035b08(int a, int b);
int Unk0e651c_Unk_0e666c(u32 flag);
void func_0209a884(void *a, void *b);
u8 *GameState_GetBody(void);
u8 *Unk02e000_GetWorkArea(void);
u8 *Unk02f2a8_Unk_034970(u8 *p, int x, int y);
u8 *Unk038fbc_Unk_039160(u8 *p, int x, int y);
s8 Unk02f2a8_GetRes36Unk19(int i);
s8 Unk02f2a8_GetRes36Unk1a(int i);
void Unk0bc1a8_Unk_0bc928(u32 id, u32 value, Unk1124f0Req *req);

/* Returns 1 when Unk02f2a8_Unk_035b08(8, 10) matches `id`, the caller's
 * (map, slot) pair is (23, 10), and event flag 344 is set; otherwise 0.
 * Unk1124f0_Unk_112564 uses this to gate its result. */
int Unk1124f0_Unk_1124f0(u16 id, u32 map, u32 slot)
{
    int r = 0;
    if (id == Unk02f2a8_Unk_035b08(8, 10) && map == 23 && slot == 10) {
        if (Unk0e651c_Unk_0e666c(344) == 1) {
            r = 1;
        }
    }
    return r;
}

/* Constant accessor: always returns 1. */
int Unk1124f0_GetConst1(void) { return 1; }

extern u8 data_0213cb24[];
/* Returns the address of the 8-byte record at `index` in data_0213cb24.
 * The original does the address arithmetic in integer registers. */
int Unk1124f0_Unk_11259c(int index)
{
    return ((int)data_0213cb24) + index * 8;
}

/* If a game state exists, hands its +0x38E8 buffer and its body (+4) to
 * func_0209a884; does nothing when there is no game state. */
void Unk1124f0_Unk_112538(void)
{
    GameState *gs = GetGameState();
    if (gs == 0) {
        return;
    }
    func_0209a884(gs->unk_38e8, (u8 *)gs + 4);
}

/* Returns 2 when the work area's active record id (+0x35C) together with the
 * (map, slot) pair satisfies Unk1124f0_Unk_1124f0; otherwise 0. */
u32 Unk1124f0_Unk_112564(u32 map, u32 slot)
{
    u32 result = 0;
    Unk1124f0WorkArea *w = (Unk1124f0WorkArea *)Unk02e000_GetWorkArea();

    if (Unk1124f0_Unk_1124f0(w->unk_035c, map, slot) == 1) {
        result = 2;
    }
    return result;
}

int func_02115bf4(void);
int func_02116f84(u32 a, u32 b, u32 c);
/* Returns 1 only when both func_02115bf4() and func_02116f84(a, b, c) report
 * nonzero; short-circuiting is not possible because both calls are made. */
int Unk1124f0_Unk_1125ac(u32 a, u32 b, u32 c)
{
    int value1 = func_02115bf4();
    int value2 = func_02116f84(a, b, c);

    return value1 != 0 && value2 != 0;
}

/* Returns 0 when the current position object is suppressed by the event-flag
 * checks, 1 otherwise.  Looks up the object at work-area coordinates
 * (+0x364, +0x365).  When resource 36's entry at +0x35C is type 2 and either
 * its sub-type is not 1 or the object's +4 bits 20..23 are nonzero, flags
 * 0x450/0x448 can clear the result; entry type 9 with flag 0x55A clears it as
 * well. */
int func_021125e8(void)
{
    int result = 1;
    Unk1124f0WorkArea *w = (Unk1124f0WorkArea *)Unk02e000_GetWorkArea();
    s8 y = w->unk_0365;
    s8 x = w->unk_0364;
    Unk1124f0Object *o = (Unk1124f0Object *)Unk038fbc_Unk_039160(
        Unk02f2a8_Unk_034970(GameState_GetBody(), x, y), x, y);

    if (o != 0) {
        if (Unk02f2a8_GetRes36Unk19(w->unk_035c) == 2) {
            if (Unk02f2a8_GetRes36Unk1a(w->unk_035c) != 1 ||
                o->unk_0004_20 != 0) {
                if (Unk0e651c_Unk_0e666c(0x450) == 1) {
                    if (Unk0e651c_Unk_0e666c(0x448) == 0) {
                        result = 0;
                    }
                }
            }
        }
        if (Unk02f2a8_GetRes36Unk19(w->unk_035c) == 9) {
            if (Unk0e651c_Unk_0e666c(0x55a) == 1) {
                result = 0;
            }
        }
    }
    return result;
}

/* Builds a request block with `value` in pointer slot 3 (mask bit 3 set) and
 * sends request 39 with `param` as its argument.  The block is short-lived:
 * Unk0bc1a8_Unk_0bc928 copies what it needs before returning. */
void func_021126b4(u32 value, u32 param)
{
    Unk1124f0Req req;
    int i;
    int j;

    for (i = 0; i < 2; i++) {
        req.mask[i] = 0;
    }
    for (j = 0; j < 16; j++) {
        req.ptrs[j] = 0;
    }
    req.ptrs[3] = (void *)value;
    req.mask[0] |= 8;
    Unk0bc1a8_Unk_0bc928(39, param, &req);
}
