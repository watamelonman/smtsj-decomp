/* src/game/unit_0206a224.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk06a224Work {
    u8 pad_0000[0x440];
    u32 unk_0440;
    u32 unk_0444;
    u32 unk_0448;
    u32 unk_044c;
} Unk06a224Work;



/* Six byte pairs, matching the assignment in CampStatus_Copy168. */
typedef struct Unk06a224Pairs {
    u8 pairs[6][2];
} Unk06a224Pairs;

void CampStatus_Copy168(const Unk06a224Pairs *src);
int Unk0986ac_Unk_098978(int id);
int Unk0986ac_Thunk_02098714(int bit);

/* Preserve the mapped flag test result; the callees map id - 0x6f and test it. */
int Unk06a224_Unk_06a9fc(int id)
{
    return Unk0986ac_Thunk_02098714(Unk0986ac_Unk_098978(id));
}

/* Forward a borrowed six-pair source; CampStatus_Copy168 copies it to +0x168. */
void Unk06a224_Thunk_020d6cac(const Unk06a224Pairs *src)
{
    CampStatus_Copy168(src);
}

/* Globals block at 0x0216b9b0; fields named by their accessors. */
typedef struct Unk06a224Globals {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Unk06a224Globals;

extern Unk06a224Globals data_0216b9b0;

/* Read the word at global +8; its meaning is not established. */
u32 Unk06a224_Unk_06a224(void)
{
    return data_0216b9b0.unk_08;
}

/* Read global +0, as evidenced by the target ldr [r0]. */
u32 Unk06a224_GetUnk00(void)
{
    return data_0216b9b0.unk_00;
}

/* Store the supplied word at global +8 without normalization. */
void Unk06a224_Unk_06a244(u32 arg0)
{
    data_0216b9b0.unk_08 = arg0;
}

/* Store global +0, as evidenced by the target str [r1]. */
void Unk06a224_SetUnk00(u32 arg0)
{
    data_0216b9b0.unk_00 = arg0;
}


int func_020537b8(int group, int mask);
typedef struct Unk06a224Slot {
    u16 id;
    u16 pad_0002;
} Unk06a224Slot;
/* Count nonzero halfword IDs in the 489 four-byte records at work +0x408. */
s16 Unk06a224_CountUsedSlots(void)
{
    s16 n = 0;
    int i;
    for (i = 0; i < 489; i++) {
        if (FIELD(Unk06a224Slot *, data_0216b9b0.unk_04, 0x408)[i].id != 0) {
            n++;
        }
    }
    return n;
}

/* Borrowed object view; signed halfwords are established by target ldrsh. */
typedef struct Unk06a224Selection {
    u8 pad_000[0x154];
    s16 unk_154;
    s16 unk_156;
} Unk06a224Selection;

/* Return true for an odd +0x154 value or a positive +0x156 value.
 * Signed remainder behavior is retained for negative values; meaning is unknown. */
int Unk06a224_Unk_06a374(const Unk06a224Selection *o)
{
    if (o->unk_154 % 2 != 0) {
        return 1;
    }
    return o->unk_156 > 0;
}

/* Test the signed selection bounds at +0x154/+0x156 against +0x158.
 * The borrowed object must contain these halfwords; odd selections use a 24 offset. */
int Unk06a224_Unk_06a3a4(u8 *o)
{
    s16 a = FIELD(s16, o, 0x154);
    if (a % 2 == 0) {
        if (a < FIELD(s16, o, 0x158) - 1) {
            return 1;
        }
    } else if (FIELD(s16, o, 0x156) + 24 < FIELD(s16, o, 0x158)) {
        return 1;
    }
    return 0;
}

typedef struct Unk06a224Ctl {
    u8 pad_0000[348];
    u16 *slots[]; /* Borrowed entries at +0x15c; caller supplies a valid index. */
} Unk06a224Ctl;
void func_02099b10(int id, int value);
void func_02067d54(Unk06a224Ctl *c);
s16 Unk06a224_CountUsedSlots(void);

/* Notify func_02099b10 for a populated borrowed slot, clear it, and refresh
 * selection halfwords. The caller guarantees i indexes the slot pointer table. */
void Unk06a224_Unk_06a998(Unk06a224Ctl *c, int i)
{
    u8 *p = (u8 *)c;
    if (c->slots[i] != 0) {
        func_02099b10(*c->slots[i], 1);
    }
    {
        c->slots[i] = 0;
        FIELD(u16, p + 0x100, 84) = 0;
        FIELD(u16, p + 0x100, 86) = 0;
        func_02067d54(c);
        FIELD(s16, p + 0x100, 88) = Unk06a224_CountUsedSlots();
        FIELD(s16, p + 0x100, 88)++;
    }
}

/* Stack request view from target stores: two flag bytes and sixteen words.
 * The two alignment bytes are not initialized by the original routines. */
typedef struct Unk06a224Msg {
    u8 flags[2];
    u8 pad_02[2];
    u32 w[16];
} Unk06a224Msg;
void func_020bcbc4(int channel, const Unk06a224Msg *message);

/* Submit word-1 value 24 with flag 2 to channel 3.
 * The request is borrowed for the duration of func_020bcbc4. */
void Unk06a224_Unk_06aa0c(void)
{
    Unk06a224Msg m;
    int i;
    for (i = 0; i < 2; i++) {
        m.flags[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        m.w[i] = 0;
    }
    m.w[1] = 24;
    m.flags[0] |= 2;
    func_020bcbc4(3, &m);
}

/* Submit word-1 value 2 and caller word 7 with flags 0x82 to channel 3.
 * The request is borrowed for the duration of func_020bcbc4. */
void Unk06a224_Unk_06aafc(u32 x)
{
    Unk06a224Msg m;
    int i;
    for (i = 0; i < 2; i++) {
        m.flags[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        m.w[i] = 0;
    }
    m.w[7] = x;
    m.w[1] = 2;
    m.flags[0] |= 0x82;
    func_020bcbc4(3, &m);
}

void func_020bcacc(int channel, const Unk06a224Msg *message);
void func_020bc9f4(int id, int value);
void CampStatus_SetUnk1a8(int value);
void CampStatus_Copy12c();

/* Call CampStatus_Copy12c before submitting word-1 value 11 with flag 2.
 * The request is borrowed for the duration of func_020bcbc4. */
void Unk06a224_Unk_06ab64(void)
{
    Unk06a224Msg m;
    int i;
    CampStatus_Copy12c();
    for (i = 0; i < 2; i++) {
        m.flags[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        m.w[i] = 0;
    }
    m.w[1] = 11;
    m.flags[0] |= 2;
    func_020bcbc4(3, &m);
}

/* Submit request 20 with caller word 7, word 6 = 1 and flags 0xc2.
 * Instruction stores establish the request fields; submission borrows the stack. */
void Unk06a224_Unk_06ac54(u32 x)
{
    Unk06a224Msg m;
    int i;
    for (i = 0; i < 2; i++) {
        m.flags[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        m.w[i] = 0;
    }
    m.w[7] = x;
    m.w[1] = 20;
    m.w[6] = 1;
    m.flags[0] |= 0x82;
    m.flags[0] |= 0x40;
    func_020bcbc4(3, &m);
}

/* Submit word-1 value 10 and caller word 7 with flags 0x82 to channel 3.
 * The request is borrowed for the duration of func_020bcbc4. */
void Unk06a224_Unk_06accc(u32 x)
{
    Unk06a224Msg m;
    int i;
    for (i = 0; i < 2; i++) {
        m.flags[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        m.w[i] = 0;
    }
    m.w[7] = x;
    m.w[1] = 10;
    m.flags[0] |= 0x82;
    func_020bcbc4(3, &m);
}

/* Submit request 11 with word 3 = 12, then clear the two callee states.
 * Constants and call order follow the original instructions. */
void Unk06a224_Unk_06ad40(void)
{
    Unk06a224Msg m;
    int i;
    for (i = 0; i < 2; i++) {
        m.flags[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        m.w[i] = 0;
    }
    m.w[3] = 12;
    m.w[1] = 11;
    m.flags[0] |= 10;
    func_020bcacc(3, &m);
    func_020bc9f4(11, 0);
    CampStatus_SetUnk1a8(0);
}

/* Submit word-1 value 25 and caller word 7 with flags 0x82 to channel 3.
 * The request is borrowed for the duration of func_020bcbc4. */
void Unk06a224_Unk_06adc0(u32 x)
{
    Unk06a224Msg m;
    int i;
    for (i = 0; i < 2; i++) {
        m.flags[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        m.w[i] = 0;
    }
    m.w[7] = x;
    m.w[1] = 25;
    m.flags[0] |= 0x82;
    func_020bcbc4(3, &m);
}

/* Latch words at +0x440..+0x44c when group-zero masks 0x40, 0x80,
 * 0x20, and 0x10 test nonzero. Unset masks leave existing words untouched. */
void Unk06a224_Unk_06ae28(Unk06a224Work *work)
{
    if (func_020537b8(0, 0x40) != 0) {
        work->unk_0440 = 1;
    }
    if (func_020537b8(0, 0x80) != 0) {
        work->unk_0444 = 1;
    }
    if (func_020537b8(0, 0x20) != 0) {
        work->unk_0448 = 1;
    }
    if (func_020537b8(0, 0x10) != 0) {
        work->unk_044c = 1;
    }
}

/* Borrowed work bytes; the signed byte at +0x348 supplies request word 7. */
u8 *Unk02e000_GetWorkArea(void);

/* Submit request 2 with the signed work byte selected by the caller's index.
 * The caller supplies a valid index into the work byte table at +0x348. */
void func_0206aa70(int index)
{
    Unk06a224Msg m;
    int i;
    for (i = 0; i < 2; i++) m.flags[i] = 0;
    for (i = 0; i < 16; i++) m.w[i] = 0;
    m.w[1] = 2;
    m.flags[0] |= 2;
    m.w[7] = FIELD(s8, Unk02e000_GetWorkArea() + index, 0x348);
    m.flags[0] |= 0x80;
    func_020bcbc4(3, &m);
}

/* Preserve the first argument for CampStatus_Copy12c; a nonzero second argument
 * adds word 3 = 11 and flag 8 to the borrowed channel-three request. */
void func_0206abcc(const void *source, int extra)
{
    Unk06a224Msg m;
    int i;
    CampStatus_Copy12c(source);
    for (i = 0; i < 2; i++) m.flags[i] = 0;
    for (i = 0; i < 16; i++) m.w[i] = 0;
    m.w[1] = 11;
    m.flags[0] |= 2;
    if (extra != 0) {
        m.w[3] = 11;
        m.flags[0] |= 8;
    }
    func_020bcbc4(3, &m);
}

void func_020086a0(int value, void *destination, u32 size);
void func_02063920(void);
void *func_020445f4(int group, int id);
void func_0204fed8(void *resource, int id);
int func_02063a30(void);
void func_02061f10(u32 object, int id, int a, int b, int last);

/* Rebuild the 24 borrowed slot pointers and emit resources for populated IDs.
 * Slot zero uses resource (12,17), ID 5 when empty; the last emitted handle
 * is passed to the object at +0x150, as established by the target call sequence. */
void func_0206a2ac(Unk06a224Ctl *c)
{
    s16 i;
    int last;
    void *emptyResource;
    void *entryResource;
    func_020086a0(0, c->slots, 0x60);
    func_02067d54(c);
    func_02063920();
    emptyResource = func_020445f4(12, 17);
    entryResource = func_020445f4(6, 0);
    for (i = 0; i < 24; i++) {
        if (c->slots[i] == 0) {
            if (i == 0) {
                func_0204fed8(emptyResource, 5);
                last = func_02063a30();
            }
        } else if (*c->slots[i] != 0) {
            func_0204fed8(entryResource, *c->slots[i]);
            last = func_02063a30();
        }
    }
    func_02061f10(FIELD(u32, c, 0x150), -1, 0, 0, last);
}

int func_02053824(int group, int mask);
int func_020537dc(int group, int mask);
int func_02053800(int group, int mask);
void Unk0a0ce4_Unk_0a0da4(int value);

/* Update signed selection and scroll halfwords in response to group-zero input.
 * The target uses 24 visible slots, two-column movement and latched request state
 * at +0x3d8. The caller owns the complete work object through +0x44c. */
int func_0206a3f4(u8 *o)
{
    int oldSelection = FIELD(s16, o, 0x154);
    int oldScroll = FIELD(s16, o, 0x156);
    int result = 1;
    int moved = 0;
    int i;
    if (FIELD(s16, o, 0x158) > 2) {
        if (FIELD(int, o, 0x3d8) == 0 &&
            (func_02053824(0, 0x40) || func_02053824(0, 0x80))) {
            Unk06a224_Unk_06aa0c();
            FIELD(int, o, 0x3d8) = 1;
            Unk06a224_Unk_06ae28((Unk06a224Work *)o);
        }
        if (func_02053824(0, 0x40)) {
            FIELD(s16, o, 0x154) -= 2;
            if (FIELD(s16, o, 0x158) > 24) {
                if (FIELD(s16, o, 0x154) < FIELD(s16, o, 0x156))
                    FIELD(s16, o, 0x156) -= 2;
            }
            if (FIELD(s16, o, 0x154) % 2 == 0) {
                if (FIELD(s16, o, 0x154) < 0) {
                    FIELD(s16, o, 0x154) += FIELD(s16, o, 0x158);
                    if (FIELD(s16, o, 0x154) % 2 != 0) FIELD(s16, o, 0x154)++;
                    if (FIELD(s16, o, 0x158) > 24) {
                        FIELD(s16, o, 0x156) = FIELD(s16, o, 0x158) - 24;
                        if (FIELD(s16, o, 0x156) % 2 != 0) FIELD(s16, o, 0x156)++;
                    }
                }
            } else if (FIELD(s16, o, 0x154) < 0) {
                FIELD(s16, o, 0x154) += FIELD(s16, o, 0x158);
                if (FIELD(s16, o, 0x158) > 24) {
                    FIELD(s16, o, 0x156) = FIELD(s16, o, 0x158) - 24;
                    if (FIELD(s16, o, 0x156) % 2 != 0) FIELD(s16, o, 0x156)++;
                }
            }
        } else if (func_02053824(0, 0x80)) {
            FIELD(s16, o, 0x154) += 2;
            if (FIELD(s16, o, 0x154) - FIELD(s16, o, 0x156) >= 24)
                FIELD(s16, o, 0x156) += 2;
            if (FIELD(s16, o, 0x154) % 2 == 0) {
                if (FIELD(s16, o, 0x154) >= FIELD(s16, o, 0x158)) {
                    FIELD(s16, o, 0x154) = 0;
                    FIELD(s16, o, 0x156) = 0;
                }
            } else if (FIELD(s16, o, 0x154) == FIELD(s16, o, 0x158)) {
                FIELD(s16, o, 0x154) = FIELD(s16, o, 0x158) - 1;
            } else if (FIELD(s16, o, 0x154) > FIELD(s16, o, 0x158)) {
                FIELD(s16, o, 0x154) -= FIELD(s16, o, 0x158);
                FIELD(s16, o, 0x156) = 0;
            }
        }
    }
    if (FIELD(s16, o, 0x158) > 1) {
        if (FIELD(int, o, 0x3d8) == 0 && func_02053824(0, 0x20) &&
            Unk06a224_Unk_06a374((Unk06a224Selection *)o)) {
            Unk06a224_Unk_06aa0c();
            FIELD(int, o, 0x3d8) = 1;
            Unk06a224_Unk_06ae28((Unk06a224Work *)o);
            moved = 1;
        }
        if (func_02053824(0, 0x20)) {
            if (FIELD(s16, o, 0x154) % 2 == 0) {
                for (i = 0; i < 22; i += 2) {
                    if (FIELD(s16, o, 0x156) <= 0) break;
                    FIELD(s16, o, 0x154) -= 2;
                    FIELD(s16, o, 0x156) -= 2;
                }
            } else FIELD(s16, o, 0x154)--;
        }
        if (FIELD(int, o, 0x3d8) == 0 && func_02053824(0, 0x10) &&
            Unk06a224_Unk_06a3a4(o)) {
            Unk06a224_Unk_06aa0c();
            FIELD(int, o, 0x3d8) = 1;
            Unk06a224_Unk_06ae28((Unk06a224Work *)o);
            moved = 1;
        }
        if (func_02053824(0, 0x10)) {
            if (FIELD(s16, o, 0x154) % 2 == 0) {
                if (FIELD(s16, o, 0x154) < FIELD(s16, o, 0x158) - 1) FIELD(s16, o, 0x154)++;
            } else {
                for (i = 0; i < 22; i += 2) {
                    if (FIELD(s16, o, 0x158) - FIELD(s16, o, 0x156) <= 24) break;
                    FIELD(s16, o, 0x154) += 2;
                    FIELD(s16, o, 0x156) += 2;
                }
                if (FIELD(s16, o, 0x154) >= FIELD(s16, o, 0x158)) FIELD(s16, o, 0x154)--;
            }
        }
    }
    if (oldScroll != FIELD(s16, o, 0x156)) func_0206a2ac((Unk06a224Ctl *)o);
    if (oldSelection != FIELD(s16, o, 0x154)) {
        result = 0;
        Unk0a0ce4_Unk_0a0da4(0);
    }
    if (FIELD(int, o, 0x3d8) != 0) {
        if (func_020537dc(0, 0x40) && func_020537dc(0, 0x80) && !moved &&
            (!FIELD(int, o, 0x448) || func_020537dc(0, 0x20) ||
             !Unk06a224_Unk_06a374((Unk06a224Selection *)o)) && !moved &&
            (!FIELD(int, o, 0x44c) || func_020537dc(0, 0x10) || !Unk06a224_Unk_06a3a4(o))) {
            if (FIELD(s16, o, 0x154) == 0 && FIELD(s16, o, 0x156) == 0) {
                Unk06a224_Unk_06aa0c();
            } else {
                u16 id = *((Unk06a224Ctl *)o)->slots[FIELD(s16, o, 0x154) - FIELD(s16, o, 0x156)];
                FIELD(u16, o, 0x3f0) = id;
                Unk06a224_Unk_06accc(id);
            }
            FIELD(int, o, 0x3d8) = 0;
            if (func_020537dc(0, 0x40)) FIELD(int, o, 0x440) = 0;
            if (func_020537dc(0, 0x80)) FIELD(int, o, 0x444) = 0;
            if (func_020537dc(0, 0x20)) FIELD(int, o, 0x448) = 0;
            if (func_020537dc(0, 0x10)) FIELD(int, o, 0x44c) = 0;
        }
    } else if (oldSelection == FIELD(s16, o, 0x154) && func_02053800(0, 0x800)) {
        if (FIELD(s16, o, 0x154) == 0 && FIELD(s16, o, 0x156) == 0) {
            Unk0a0ce4_Unk_0a0da4(4);
        } else {
            Unk06a224_Unk_06ad40();
            result = 0;
        }
    }
    return result;
}
