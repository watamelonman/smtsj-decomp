#include "GameState.h"
#include "types.h"

u32 Unk095560_Unk_095764(u32 a);
u32 func_0204fde0(void);
u32 func_0204fe18(u32 a);
void func_02052d7c(u32 a, u32 b);

/* Clear the mode-14 arguments and initialize its backing state; null state is a no-op. */
void Unk09e96c_Unk_09e9cc(void)
{
    GameState *gs = GetGameState();
    u32 v;
    if (gs == 0) {
        return;
    }
    Unk095560_Unk_095764(0);
    v = func_0204fde0();
    gs->unk_7430 = v;
    gs->unk_7434 = 0;
    gs->unk_7438 = 0;
    func_02052d7c(gs->unk_7430, gs->unk_7434);
    gs->unk_73e8 = 0xe;
}

/* Resolve the mode-14 arguments and retain arg1 for its consumer; null state is a no-op. */
void Unk09e96c_Unk_09e96c(u32 arg0, u32 arg1)
{
    GameState *gs = GetGameState();
    u32 v;
    u32 w;
    if (gs == 0) {
        return;
    }
    v = Unk095560_Unk_095764(arg0);
    w = func_0204fde0();
    gs->unk_7430 = w;
    v = func_0204fe18(v);
    gs->unk_7434 = v;
    gs->unk_7438 = arg1;
    func_02052d7c(gs->unk_7430, gs->unk_7434);
    gs->unk_73e8 = 0xe;
}

/* Partial views preserve the offsets used by this transition without changing shared layouts. */
typedef struct TransitionState {
    GameStateRoot *root;
    u8 body[0x54];
    u16 notification;
    u8 pad_005a[0x4a];
    u32 argument;
    u8 payload[0x73e8 - 0xa8];
    u32 mode;
    u8 pad_73ec[0x96];
    u8 x;
    u8 y;
} TransitionState;

/* Borrowed record; only the bit selector at +0x19 is read here. */
typedef struct TransitionRecord {
    u8 pad_00[0x19];
    u8 bit;
} TransitionRecord;

/* Mutable four-byte grid cell returned by GetCell38e8. */
typedef struct TransitionCell {
    u8 flags;
    u8 kind;
    u16 counter;
} TransitionCell;

u8 *Unk02f2a8_Unk_034970(void *body, int x, int y);
u8 *Unk038fbc_Unk_039160(void *table, int x, int y);
u8 *Unk0392f8_Unk_0394b8(void *table, int x, int y);
TransitionRecord *Unk09a268_Unk_09c484(int index);
int Unk09a268_IsType1(const u8 *cell);
TransitionCell *Unk02f2a8_GetCell38e8(int x, int y);
void Unk09a268_Unk_09a80c(TransitionCell *cell, u32 value);
void Unk09a268_Unk_09a830(TransitionCell *cell, u32 value);
void Unk09a268_SetOnlyBit(TransitionCell *cell, u32 bit);
int Unk0a0ce4_Unk_0a0da4(int value);

/* Select a record from the grid entry type, reset its cell and enter mode 15.
 * Evidence: byte type dispatch, GetCell38e8 calls and mode store at +0x73e8.
 * Coordinates must be valid for the grid accessors; missing state/entries are a no-op.
 */
void func_0209ea18(int x, int y)
{
    TransitionState *state;
    u8 *source;
    u8 *entry;
    TransitionRecord *record;
    u32 kind;
    state = (TransitionState *)GetGameState();
    if (state == 0) return;
    entry = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(state->body, x, y), x, y);
    if (entry == 0) return;
    source = Unk0392f8_Unk_0394b8((u8 *)state + 0x3e4, x, y);
    if (source == 0) return;
    record = 0;
    kind = 0;
    switch ((int)*entry) {
    case 4: case 5: case 6: case 7:
        record = Unk09a268_Unk_09c484(4);
        kind = 1;
        break;
    case 8: case 9:
        record = Unk09a268_Unk_09c484(5);
        kind = 1;
        break;
    case 24: case 25:
        record = Unk09a268_Unk_09c484(16);
        kind = Unk09a268_IsType1(source) == 1 ? 1 : 3;
        break;
    case 26: case 27:
        record = Unk09a268_Unk_09c484(17);
        kind = Unk09a268_IsType1(source) == 1 ? 1 : 3;
        break;
    }
    if (record == 0) return;
    source = (u8 *)Unk02f2a8_GetCell38e8(x, y);
    Unk09a268_Unk_09a80c((TransitionCell *)source, 1);
    Unk09a268_Unk_09a830((TransitionCell *)source, 0);
    Unk09a268_SetOnlyBit((TransitionCell *)source, record->bit);
    ((TransitionCell *)source)->kind = kind;
    ((TransitionCell *)source)->counter = 0;
    state->root->unk_5c = 1;
    Unk0a0ce4_Unk_0a0da4(state->notification);
    func_02052d7c((u32)state->payload, state->argument);
    state->x = x;
    state->y = y;
    state->mode = 15;
}
