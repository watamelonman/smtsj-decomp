#include "types.h"

/* Partial state layout; padding preserves offsets observed in the original. */
typedef struct Unk09ebd0State {
    u8 pad_0000[4];
    u8 body[0x57];
    u8 field_005b;
    u8 pad_005c[0xf8];
    u8 field_0154[0x290];
    u8 field_03e4[0x2d70];
    u8 field_3154[0x794];
    u8 field_38e8[0x3b00];
    u32 mode;
    u8 pad_73ec[0x14];
    u32 field_7400;
    u8 field_7404[0xc];
    u8 field_7410[0x18];
    u16 field_7428;
} Unk09ebd0State;

/* Only the first four bytes of the borrowed cell are used here. */
typedef struct Unk09ebd0Cell {
    u8 type;
    u8 field_01;
    u16 field_02;
} Unk09ebd0Cell;

Unk09ebd0State *GetGameState(void);
void *Unk02f2a8_Unk_034970(void *body, s32 x, s32 y);
Unk09ebd0Cell *Unk038fbc_Unk_039160(void *map, s32 x, s32 y);
void *Unk0392f8_Unk_0394b8(void *map, s32 x, s32 y);
s32 Unk09a268_Unk_09c484(s32 type);
s32 Unk09a268_IsType1(void *cell);
Unk09ebd0Cell *Unk02f2a8_GetCell38e8(s32 x, s32 y);
void Unk09a268_Unk_09a80c(Unk09ebd0Cell *cell, s32 value);
void Unk09a268_Unk_09a830(Unk09ebd0Cell *cell, s32 value);
void Unk09a268_Unk_09a870(Unk09ebd0Cell *cell, s32 value);
void Unk09a268_SetOnlyBit(Unk09ebd0Cell *cell, s32 value);
void func_02035db8(void *work, s8 x, s8 y);
void Unk02f2a8_Unk_035ec4(void *work, s32 value);
void func_02035edc(void *work, void *position);
void func_0203721c(void *work, void *map, void *cells, void *position,
                   u32 value, s32 x, s32 y, u32 flag, s32 kind);

/* Update a borrowed cell for supported map types, then select mode 16.
 * Evidence: type-byte dispatch and writes to state +0x73e8 in 0209ebd0. */
void func_0209ebd0(s32 x, s32 y)
{
    Unk09ebd0State *state = GetGameState();
    Unk09ebd0Cell *cell;
    void *entry;
    s32 enabled, value, flag;
    if (state == 0) return;
    cell = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(state->body, x, y), x, y);
    if (cell == 0) return;
    entry = Unk0392f8_Unk_0394b8(state->field_03e4, x, y);
    if (entry == 0) return;
    enabled = 0;
    value = 0;
    flag = 0;
    switch ((s32)cell->type) {
    case 4: case 5: case 6: case 7:
        enabled = Unk09a268_Unk_09c484(4);
        break;
    case 8: case 9:
        enabled = Unk09a268_Unk_09c484(5);
        break;
    case 24: case 25:
        enabled = Unk09a268_Unk_09c484(16);
        if (Unk09a268_IsType1(entry) == 1) { value = 0; flag = 0; }
        else { value = 2; flag = 1; }
        break;
    case 26: case 27:
        enabled = Unk09a268_Unk_09c484(17);
        if (Unk09a268_IsType1(entry) == 1) { value = 0; flag = 0; }
        else { value = 2; flag = 1; }
        break;
    }
    if (enabled == 0) return;
    entry = Unk02f2a8_GetCell38e8(x, y);
    cell = entry;
    Unk09a268_Unk_09a80c(cell, flag);
    Unk09a268_Unk_09a830(cell, flag);
    Unk09a268_Unk_09a870(cell, 0);
    Unk09a268_SetOnlyBit(cell, 0);
    cell->field_01 = value;
    cell->field_02 = 0;
    state->mode = 16;
}

/* Prepare the coordinate work areas and select mode 17. Coordinates are
 * narrowed only for 02035db8; the remaining callees receive full signed values.
 * Evidence: signed-16-bit script arguments at caller 0203c0ec. */
void func_0209ed78(s32 x, s32 y, s32 value)
{
    Unk09ebd0State *state = GetGameState();
    void *map;
    if (state == 0) return;
    func_02035db8(state->field_7404, (s8)x, (s8)y);
    Unk02f2a8_Unk_035ec4(state->field_7410, value);
    func_02035edc(state->field_7410, state->field_7404);
    state->field_7400 = 1;
    map = Unk02f2a8_Unk_034970(state->body, x, y);
    func_0203721c(state->field_3154, map, state->field_38e8,
                  state->field_7410, state->field_7428, x, y, state->field_005b, 2);
    state->mode = 17;
}
