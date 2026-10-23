/* Map-entry sequence setup and updates; layouts follow the original ARM accesses. */
#include "types.h"

/* Partial view of 0x02176b08; unknown bytes retain their original offsets. */
typedef struct Unk0a50d4Globals {
    u8 pad_0000[0x6];
    s8 unk_06;
    u8 pad_0007;
    u32 unk_08;
} Unk0a50d4Globals;

extern Unk0a50d4Globals data_02176b08;

/* Returns the global word at +8 without interpreting its unproven meaning. */
u32 Unk0a50d4_Unk_0a50d4(void)
{
    return data_02176b08.unk_08;
}

/* Returns global byte +6 with sign extension, as evidenced by the original ldrsb. */
s8 Unk0a50d4_GetUnk06(void)
{
    return data_02176b08.unk_06;
}

/* Only the observed map and state offsets are exposed; callers own the storage. */
typedef struct Unk0a50d4Context {
    u32 unk_00;
    u8 map[0x747c];
    s8 mode;
    s8 state;
    s8 x;
    s8 y;
    int index;
} Unk0a50d4Context;

/* Five four-byte entries are evidenced by the index*4 loads in func_020a5124. */
typedef struct Unk0a50d4Pair {
    s16 id;
    u8 count;
    u8 unk_03;
} Unk0a50d4Pair;

/* The value and kind select the alternate sequence; flag indexes the map bitset. */
typedef struct Unk0a50d4Entry {
    Unk0a50d4Pair pairs[5];
    int value;
    u8 unk_18;
    u8 kind;
    u8 flag;
} Unk0a50d4Entry;

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int func_02002954(u32 registerAddress);

/* Tests either brightness limit; 0x0400106c is the sub-screen MASTER_BRIGHT register. */
int Unk0a50d4_IsSubBrightnessMax(void)
{
    s32 v = func_02002954(0x0400106c);
    if (v == 16) {
        return 1;
    }
    return v == -16;
}

void func_02065bc0(void);
int func_020654cc(void);
void func_0206597c(int value);
int func_02065cd0(void);
void func_02065c58(void);
void *Unk02f2a8_Unk_034970(void *map, int x, int y);
u8 *Unk038fbc_Unk_039160(void *map, int x, int y);
u8 *Unk038fbc_GetElement(void *map, int kind, int index);
u8 *Unk02f2a8_GetCurrentCell38e8(void);
u8 *Unk09a268_Unk_09c484(int kind);
void *Unk02f2a8_Unk_0349c4(void *map, int x, int y);
int Unk0e651c_TestFlag(void *flags, int bit);
void Unk09a268_Unk_09a80c(void *cell, int value);
void Unk09a268_Unk_09a830(void *cell, int value);
void Unk09a268_SetOnlyBit(void *cell, int bit);
void Unk0a0ce4_Unk_0a0da4(int value);
int Unk09a268_Unk_09a844(void *cell);
void Unk09a268_Unk_09a870(void *cell, int value);
void Unk0e651c_SetFlag(void *flags, int bit, int value);
u8 *Unk02e000_GetWorkArea(void);
void func_0204b74c(int x, int y, int value);
void func_0204b6f4(void);
void Unk0fc584_SetDir(int value);
void func_020659a4(int id, int count);
void func_02099a28(int id, int count);
void func_0204faf0(int kind, int value);
void Unk0979d8_AddField344(int value);
void func_020fc734(int value);
int Unk0fc584_Unk_0fc7f4(void);

/* Advances the four substates at +0x7481; helper calls establish the wait sequence. */
int func_020a5490(Unk0a50d4Context *p)
{
    int done = 0;
    switch (p->state) {
    case 0:
        func_02065bc0();
        p->state++;
        break;
    case 1:
        if (func_020654cc() == 1) {
            func_0206597c(8);
            p->state++;
        }
        break;
    case 2:
        if (func_02065cd0() == 1) {
            func_02065c58();
            p->state++;
        }
        break;
    case 3:
        if (func_020654cc() == 1) done = 1;
        break;
    default: done = 1; break;
    }
    return done;
}

/* Checks the type-3 map entry and its flag before initializing the current cell.
 * The coordinates are signed bytes at +0x7482 and +0x7483. */
void func_020a554c(Unk0a50d4Context *p)
{
    u8 *definition = Unk09a268_Unk_09c484(3);
    u8 *cell = Unk02f2a8_GetCurrentCell38e8();
    int y = p->y;
    int x = p->x;
    u8 *entry = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(p->map, x, y), x, y);
    if (entry != 0 && entry[0] == 3) {
        entry = Unk038fbc_GetElement(Unk02f2a8_Unk_034970(p->map,
            p->x, p->y), 0, entry[1]);
        if (Unk0e651c_TestFlag(Unk02f2a8_Unk_0349c4(p->map,
            p->x, p->y), entry[26]) == 0) {
            Unk09a268_Unk_09a80c(cell, 1);
            Unk09a268_Unk_09a830(cell, 0);
            Unk09a268_SetOnlyBit(cell, definition[25]);
            cell[1] = 1;
            FIELD(u16, cell, 2) = 0;
            Unk0a0ce4_Unk_0a0da4(42);
            p->mode = 0;
            return;
        }
    }
    p->mode = 1;
}

/* Updates the map-entry sequence selected by +0x7481, returning one when done.
 * Entry records contain five (signed id, byte count) pairs and a value at +20. */
int func_020a5124(Unk0a50d4Context *p)
{
    int y = p->y;
    int x = p->x;
    u8 *entry = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(p->map, x, y), x, y);
    Unk0a50d4Entry *data = (Unk0a50d4Entry *)Unk038fbc_GetElement(Unk02f2a8_Unk_034970(p->map,
        p->x, p->y), 0, entry[1]);
    u8 *cell = Unk02f2a8_GetCurrentCell38e8();
    int done = 0;
    switch (p->state) {
    case 0:
        FIELD(u16, cell, 2)++;
        if (Unk09a268_Unk_09a844(cell) == 1) {
            Unk09a268_Unk_09a830(cell, 1);
            Unk09a268_Unk_09a870(cell, 0);
            cell[1] = 2;
            FIELD(u16, cell, 2) = 0;
            Unk0e651c_SetFlag(Unk02f2a8_Unk_0349c4(p->map,
                p->x, p->y), data->flag, 1);
            func_0204b74c(p->x, p->y,
                FIELD(u16, Unk02e000_GetWorkArea(), 0x35c));
            func_0204b6f4();
            func_02065bc0();
            if (data->kind == 2) {
                p->index = 0;
                p->state = 20;
                Unk0fc584_SetDir(1);
            } else {
                p->index = 0;
                p->state = 10;
            }
        }
        break;
    case 10:
        if (func_020654cc() == 1) {
            int initial = p->index;
            while (p->index < 5) {
                int index = p->index;
                int id = data->pairs[index].id;
                if (id > 0 && data->pairs[index].count != 0) {
                    func_020659a4(id, data->pairs[index].count);
                    func_02099a28(data->pairs[p->index].id,
                        data->pairs[p->index].count);
                    break;
                }
                p->index++;
            }
            if (initial == 0 && p->index == 5) {
                func_020659a4(51, 1);
                func_02099a28(51, 1);
            }
            p->state++;
        }
        break;
    case 11:
        if (func_02065cd0() == 1) {
            if (p->index < 5) {
                p->index++;
                p->state = 10;
            } else {
                func_02065c58();
                p->state++;
            }
        }
        break;
    case 12:
        if (func_020654cc() == 1) done = 1;
        break;
    case 20:
        if (func_020654cc() == 1) {
            func_0204faf0(1, data->value);
            func_0206597c(16);
            p->state++;
        }
        break;
    case 21:
        if (func_02065cd0() == 1) {
            func_02065c58();
            Unk0979d8_AddField344(data->value);
            func_020fc734(data->value);
            p->state++;
        }
        break;
    case 22:
        if (Unk0fc584_Unk_0fc7f4() == 0) {
            Unk0fc584_SetDir(0);
            p->state++;
        }
        break;
    case 23:
        if (func_020654cc() == 1) done = 1;
        break;
    default: done = 1; break;
    }
    return done;
}

/* Dispatches the caller-owned context by mode +0x7480; unknown modes are complete. */
int Unk0a50d4_Unk_0a5648(Unk0a50d4Context *p)
{
    switch (p->mode) {
    case 0:
        return func_020a5124(p);
    case 1:
        return func_020a5490(p);
    }
    return 1;
}
