#include "types.h"

/* Borrowed owner view: the mode-zero transition clears its second word. */
typedef struct Owner { u32 unk_00, unk_04; } Owner;
/* Borrowed state view; phase bytes are signed and timer is measured in updates. */
typedef struct Work {
    struct Owner *owner;
    u8 pad_0004[0x73e0 - 4];
    s32 pending;
    u8 pad_73e4[0x7480 - 0x73e4];
    s8 mode, phase, x, y;
    s32 timer;
} Work;
/* Borrowed cell descriptor; byte one selects the group-three element. */
typedef struct Cell { u8 unk_00, index; } Cell;
void *Unk02f2a8_Unk_034970(void *, int, int);
Cell *Unk038fbc_Unk_039160(void *, int, int);
void *Unk038fbc_GetElement(void *, int, int);
void Unk0fc584_SetDir(int);
int func_020654cc(void);
void func_0206597c(int);
int func_02065cd0(void);
void func_02065c30(void);
int func_020fe430(Work *);
int func_020fe7b0(Work *);

/* Advance phases 0..2; the caller retains ownership of the persistent work. */
int func_020fe9c4(Work *w)
{
    int done = 0;
    switch (w->phase) {
    case 0:
        func_0206597c(19);
        w->timer = 0;
        w->phase++;
        break;
    case 1:
        if (func_02065cd0() == 1) {
            func_02065c30();
            Unk0fc584_SetDir(0);
            w->timer = 0;
            w->phase++;
        }
        break;
    case 2:
        if (func_020654cc() == 1) done = 1;
        break;
    default: done = 1; break;
    }
    return done;
}

/* Start direction zero, then report completion only when the external poll is one. */
int func_020fea70(Work *w)
{
    int done = 0;
    switch (w->phase) {
    case 0:
        Unk0fc584_SetDir(0);
        w->timer = 0;
        w->phase++;
        break;
    case 1:
        if (func_020654cc() == 1) done = 1;
        break;
    default: done = 1; break;
    }
    return done;
}

/* Resolve the selected cell twice before clearing the dispatch mode (ROM call order). */
void func_020feadc(Work *w)
{
    int y = w->y;
    int x = w->x;
    Cell *cell = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970((u8 *)w + 4, x, y), x, y);
    Unk038fbc_GetElement(Unk02f2a8_Unk_034970((u8 *)w + 4, w->x, w->y), 3, cell->index);
    w->mode = 0;
}

/* Dispatch modes 0..3; unknown signed modes return zero without advancing work. */
int func_020feb40(Work *w)
{
    int result = 0;
    switch (w->mode) {
    case 0: result = func_020fe430(w); break;
    case 1: result = func_020fe7b0(w); break;
    case 2: result = func_020fe9c4(w); break;
    case 3: result = func_020fea70(w); break;
    }
    return result;
}

/* Sixty-byte member view; only paired limits, values and flags are accessed. */
typedef struct Member {
    u8 pad_00[10];
    s16 limit_a, limit_b;
    u8 pad_0e[16];
    s16 value_a, value_b;
    u8 pad_22[18];
    u16 flags;
    u8 pad_36[6];
} Member;
/* Borrowed global view. Twelve records fill the observed gap before +836;
 * this layout does not establish a maximum valid slot beyond the caller contract. */
typedef struct Party {
    u8 pad_00[116];
    Member members[12];
    s32 currency;
    s8 slots[15];
    u8 count;
} Party;
/* Borrowed leader view with distinct offsets from the sixty-byte member records. */
typedef struct Leader {
    u8 pad_00[18];
    s16 limit_a, limit_b;
    u8 pad_16[6];
    s16 value_a, value_b;
    u8 pad_20[76];
    u16 flags;
} Leader;
Party *Unk02e000_GetWorkArea(void);
Leader *Unk02e000_Thunk_0202e788(void);

/* Return one if the leader or an active nonnegative slot has a deficit or flags.
 * Member stride 60 and slot count at +855 are evidenced by the original loop. */
int func_020fe360(void)
{
    int result = 0;
    Party *party = Unk02e000_GetWorkArea();
    Leader *leader = Unk02e000_Thunk_0202e788();
    if (leader->value_a < leader->limit_a) result = 1;
    else if (leader->value_b < leader->limit_b) result = 1;
    else if (leader->flags != 0) result = 1;
    else {
        int i;
        for (i = 0; i < party->count; i++) {
            Member *member;
            int slot = party->slots[i];
            if (slot < 0) continue;
            member = &party->members[slot];
            if (member == 0) continue;
            if (member->value_a < member->limit_a) { result = 1; break; }
            if (member->value_b < member->limit_b) { result = 1; break; }
            if (member->flags != 0) { result = 1; break; }
        }
    }
    return result;
}

int Unk0fc584_Unk_0fc7f4(void);
void func_0205257c(int);
void Unk0a0ce4_Unk_0a0da4(int);
int func_02052728(void);
void func_020525cc(int);

/* Six-phase recovery sequence; restore leader and active members before the delay.
 * The field copies, flag clearing and timer threshold ten are direct ROM evidence. */
int func_020fe7b0(Work *w)
{
    int y = w->y;
    int x = w->x;
    Cell *cell = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970((u8 *)w + 4, x, y), x, y);
    int done;
    Unk038fbc_GetElement(Unk02f2a8_Unk_034970((u8 *)w + 4, w->x, w->y), 3, cell->index);
    done = 0;
    switch (w->phase) {
    case 0:
        w->timer = 0;
        w->phase++;
        break;
    case 1:
        if (Unk0fc584_Unk_0fc7f4() == 0) {
            Unk0fc584_SetDir(0);
            w->timer = 0;
            w->phase++;
        }
        break;
    case 2:
        if (func_020654cc() == 1) {
            func_0205257c(4);
            Unk0a0ce4_Unk_0a0da4(31);
            w->timer = 0;
            w->phase++;
        }
        break;
    case 3:
        if (func_02052728() == 0) {
            Leader *leader = Unk02e000_Thunk_0202e788();
            Party *party;
            int i;
            leader->value_a = leader->limit_a;
            leader->value_b = leader->limit_b;
            leader->flags = 0;
            party = Unk02e000_GetWorkArea();
            for (i = 0; i < party->count; i++) {
                Member *member;
                int slot = party->slots[i];
                if (slot < 0) continue;
                member = &party->members[slot];
                if (member == 0) continue;
                member->value_a = member->limit_a;
                member->value_b = member->limit_b;
                member->flags = 0;
            }
            w->timer = 0;
            w->phase++;
        }
        break;
    case 4:
        if (++w->timer > 10) {
            func_020525cc(4);
            w->timer = 0;
            w->phase++;
        }
        break;
    case 5:
        if (func_02052728() == 0) done = 1;
        break;
    default: done = 1; break;
    }
    return done;
}

int func_0202d170(void);
int Unk02d15c_IsMode1Match(int);
void func_02095f94(Owner *);
void func_0202d198(void);
void func_02065bc0(void);
int Unk0e651c_Unk_0e666c(int);
void Unk0e651c_SetBitChecked(int, int);
void *Unk095560_Unk_095778(int);
void func_0206569c(void);
void func_020658dc(void *, int, int, int);
int func_02098544(int);
void func_0204faf0(int, int);
int func_0206559c(void);
int func_02065e1c(void);
void func_020fc734(int);

/* Mode-zero phase handler. The selected element supplies a packed nibble and
 * price key; currency at +836 is charged only after the confirmation poll. */
int func_020fe430(Work *w)
{
    int y = w->y;
    int x = w->x;
    Cell *cell = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970((u8 *)w + 4, x, y), x, y);
    u32 *element = Unk038fbc_GetElement(Unk02f2a8_Unk_034970((u8 *)w + 4, w->x, w->y), 3, cell->index);
    int done = 0;
    switch (w->phase) {
    case 0:
        if (func_0202d170() != 0) {
            do {
                if (Unk02d15c_IsMode1Match(14) == 1) {
                    w->pending = 1;
                    Owner *owner = w->owner;
                    owner->unk_04 = 0;
                    func_02095f94(owner);
                    break;
                }
                func_0202d198();
            } while (func_0202d170() != 0);
        }
        w->timer = 0;
        w->phase++;
        break;
    case 1:
        if (w->pending == 0) {
            func_02065bc0();
            w->timer = 0;
            w->phase++;
        }
        break;
    case 2:
        if (func_020654cc() == 1) {
            if (Unk0e651c_Unk_0e666c(1856) == 0) {
                Unk0e651c_SetBitChecked(1856, 1);
                Unk095560_Unk_095778(62);
                func_0206569c();
                w->phase++;
            } else w->phase += 2;
        }
        break;
    case 3:
        if (func_02065cd0() == 1) w->phase++;
        break;
    case 4:
        if (func_020fe360() == 1) {
            if ((*element << 24) >> 28 == 0) {
                func_020658dc(Unk095560_Unk_095778(17), 0, 0, 0x101);
            } else {
                Unk02e000_Thunk_0202e788();
                func_0204faf0(2, func_02098544((*element << 8) >> 16));
                func_020658dc(Unk095560_Unk_095778(18), 0, 0, 0x101);
                Unk0fc584_SetDir(1);
            }
            w->timer = 0;
            w->phase++;
        } else {
            func_0206597c(39);
            w->timer = 0;
            w->phase = 10;
        }
        break;
    case 5:
        if (func_0206559c() == 1) {
            if ((u8)func_02065e1c() == 0) {
                if ((*element << 24) >> 28 == 0) {
                    func_02065c30();
                    w->mode = 1;
                } else {
                    Party *party = Unk02e000_GetWorkArea();
                    int price;
                    Unk02e000_Thunk_0202e788();
                    price = func_02098544((*element << 8) >> 16);
                    if (price <= party->currency) {
                        func_02065c30();
                        func_020fc734(-price);
                        party->currency -= price;
                        w->mode = 1;
                    } else w->mode = 2;
                }
            } else {
                func_02065c30();
                w->mode = 3;
            }
            w->timer = 0;
            w->phase = 0;
        }
        break;
    case 10:
        if (func_02065cd0() == 1) {
            func_02065c30();
            w->mode = 3;
            w->timer = 0;
            w->phase = 0;
        }
        break;
    default: done = 1; break;
    }
    return done;
}
