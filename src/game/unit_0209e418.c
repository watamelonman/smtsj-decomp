#include "GameState.h"
#include "types.h"

/* Select mode 5/code 10 and clear the root status; absent state is a no-op. */
void Unk09e418_Unk_09e468(void)
{
    GameState *gs = GetGameState();
    if (gs == 0) {
        return;
    }
    gs->unk_73cc = 10;
    gs->root->unk_04 = 0;
    gs->unk_73e8 = 5;
}

/* Store three 16-bit mode-4 arguments, select code 9 and clear root status.
 * An absent game state leaves all state untouched. */
void Unk09e418_Unk_09e418(u16 arg0, u16 arg1, u16 arg2)
{
    GameState *gs = GetGameState();
    if (gs == 0) {
        return;
    }
    gs->unk_73cc = 9;
    gs->root->unk_04 = 0;
    gs->unk_73f4 = arg0;
    gs->unk_73f6 = arg1;
    gs->unk_73f8 = arg2;
    gs->unk_73e8 = 4;
}

/* Local state view: offsets follow the signed coordinate loads at 0209e500. */
typedef struct UnitState {
    u8 body[0x73e8];
    u32 mode;
    u32 unused;
    s32 argument;
    u8 pad_73f4[0x8e];
    s8 x;
    s8 y;
} UnitState;

/* Borrowed four-byte grid cell, mutated by the cell helpers. */
typedef struct UnitCell { u8 flags; u8 kind; u16 counter; } UnitCell;
/* Borrowed record; only its bit selector is established here. */
typedef struct UnitRecord { u8 pad[25]; u8 bit; } UnitRecord;
/* Owned temporary table context: constructor/destructor use 140 bytes. */
typedef struct UnitTable { u32 words[35]; } UnitTable;
/* Resource 36 entries have a 40-byte stride. */
typedef struct UnitResource { u8 bytes[40]; } UnitResource;
/* Each link stores a low-nibble selector and four independent enable bits. */
typedef struct UnitLink { u8 selector:4; u8 a:1; u8 b:1; u8 c:1; u8 d:1; } UnitLink;
/* Element word at +4 contains the selector in bits 8..15. */
typedef struct UnitElement { u8 flags[4]; u32 selector; } UnitElement;

void *Unk02f2a8_Unk_034970(void *body, s32 x, s32 y);
u8 *Unk038fbc_Unk_039160(void *table, s32 x, s32 y);
UnitRecord *Unk09a268_Unk_09c484(s32 index);
UnitCell *Unk02f2a8_GetCell38e8(s32 x, s32 y);
void Unk09a268_Unk_09a80c(UnitCell *cell, u32 value);
void Unk09a268_Unk_09a830(UnitCell *cell, u32 value);
void Unk09a268_SetOnlyBit(UnitCell *cell, u32 bit);
void func_020445d0(u32 resource, u32 index);
UnitResource *func_0204fde0(void);
void func_02038ff8(UnitTable *table, UnitResource *entry, u32 a, u32 b);
void *Unk038fbc_GetElement(UnitTable *table, u32 type, u32 index);
s32 Unk02f2a8_GetRes36Unk19(s32 index);
s32 Unk02f2a8_Unk_035b08(s32 index, u32 selector);
void Unk0e651c_Set2Bits(u32 index, u32 selector, u8 value);
void Unk038fbc_Unk_039138(UnitTable *table);

/* For a type-35 grid entry, reset its cell and select mode 6; null state/entry is a no-op. */
void func_0209e49c(s32 x, s32 y, s32 argument)
{
    UnitState *state = (UnitState *)GetGameState();
    u8 *entry;
    UnitCell *cell;
    UnitRecord *record;
    if (!state) return;
    entry = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(state->body + 4, x, y), x, y);
    if (!entry || entry[0] != 35) return;
    state->x = x;
    state->y = y;
    record = Unk09a268_Unk_09c484(23);
    cell = Unk02f2a8_GetCell38e8(state->x, state->y);
    Unk09a268_Unk_09a80c(cell, 1);
    Unk09a268_Unk_09a830(cell, 0);
    Unk09a268_SetOnlyBit(cell, record->bit);
    if (argument == 0) {
        cell->kind = 7;
    } else {
        cell->kind = (argument << 1) - 1;
    }
    cell->counter = 0;
    state->argument = argument;
    state->mode = 6;
}

/* Propagate a two-bit value through the four flagged type-12 links, then enter mode 12.
 * The caller supplies a valid resource index and coordinates; both temporary tables are released. */
void func_0209e564(u32 selected, s32 x, s32 y, u32 value)
{
    UnitState *state = (UnitState *)GetGameState();
    UnitResource *resource;
    u8 *entry;
    UnitLink *links;
    s32 i;
    func_020445d0(36, 0);
    resource = func_0204fde0();
    {
        UnitTable table = {0};
        func_02038ff8(&table, &resource[selected], 0, 0);
        entry = Unk038fbc_Unk_039160(&table, x, y);
        if (entry && entry[0] == 12) {
            links = Unk038fbc_GetElement(&table, 2, entry[1]);
            for (i = 0; i < 4; i++) {
                if (links[i].a || links[i].b || links[i].c || links[i].d) {
                    s32 target = Unk02f2a8_Unk_035b08(Unk02f2a8_GetRes36Unk19(selected), links[i].selector);
                    UnitTable other = {0};
                    func_02038ff8(&other, &resource[target], 0, 0);
                    entry = Unk038fbc_Unk_039160(&other, x, y);
                    if (entry && entry[0] == 12) {
                        UnitElement *element = Unk038fbc_GetElement(&other, 2, entry[1]);
                        Unk0e651c_Set2Bits(target, (element->selector << 16) >> 24, (u8)value);
                    }
                    Unk038fbc_Unk_039138(&other);
                }
            }
        }
        Unk038fbc_Unk_039138(&table);
        state->mode = 12;
    }
}
