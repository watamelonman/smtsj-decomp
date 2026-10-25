#include "types.h"

/* Twelve-byte callback work; the creator owns its lifetime. */
typedef struct TransitionWork {
    s8 phase;
    u8 pad_01[3];
    int ticks;
    int argument;
} TransitionWork;

int Unk0fc584_IsFieldCZero(void);
int Unk0fc584_Unk_0fc7f4(void);
int Unk0fc584_IsBelow64(void);
void Unk0fc584_SetDir(int direction);
void func_020fc734(int argument);
void Unk0979d8_AddField344(int argument);
void func_02061424(TransitionWork *work);
TransitionWork *func_020611dc(void (*callback)(TransitionWork *), int, int, int, int, int, int, int);
void Unk09d060_Unk_09d170(void);

/* Advance the five-phase callback, waiting nine ticks at phases 1 and 3.
 * Evidence: signed phase byte, counter at +4 and the fc584 predicate calls.
 * Work is borrowed from func_020611dc and released on the final phase. */
void func_020b1fa0(TransitionWork *work)
{
    switch (work->phase) {
    case 0:
        if (Unk0fc584_IsFieldCZero()) {
            work->phase++;
            work->ticks = 0;
        }
        break;
    case 1:
        if (work->ticks > 8) {
            work->phase++;
            func_020fc734(work->argument);
            Unk0979d8_AddField344(work->argument);
        }
        work->ticks++;
        break;
    case 2:
        if (!Unk0fc584_Unk_0fc7f4()) {
            work->phase++;
            work->ticks = 0;
        }
        break;
    case 3:
        if (work->ticks > 8) {
            work->phase++;
            Unk0fc584_SetDir(0);
        }
        work->ticks++;
        break;
    case 4:
        if (!Unk0fc584_IsBelow64()) {
            func_02061424(work);
        }
        break;
    }
}

/* Allocate the 12-byte callback state and retain the caller's argument.
 * Evidence: allocator size 12, callback literal and stores at +0/+4/+8.
 * Returns null on allocation failure; the callback owns successful work. */
TransitionWork *func_020b208c(int argument)
{
    TransitionWork *work = func_020611dc(func_020b1fa0, 0, 0, 0, 12, 4, 0, 0);
    if (work != 0) {
        Unk09d060_Unk_09d170();
        if (!Unk0fc584_IsBelow64()) {
            Unk0fc584_SetDir(1);
        }
        work->phase = 0;
        work->ticks = 0;
        work->argument = argument;
    }
    return work;
}

/* Borrowed sixteen-byte record; identity and flags retain neutral names. */
typedef struct ScanRecord {
    int state;
    s16 index;
    u8 pad_06[4];
    u8 selector;
    u8 pad_0b[3];
    u8 enabled;
    u8 active;
} ScanRecord;
/* The table prefix and record count are evidenced by the sixteen-entry reset loop. */
typedef struct ScanTable {
    u8 pad_00[0x100];
    ScanRecord records[16];
} ScanTable;
/* Coordinate state borrowed from the engine's work area. */
typedef struct ScanPosition {
    u8 pad_00[0x35c];
    u16 area;
    u8 pad_35e[6];
    s8 x;
    s8 y;
} ScanPosition;
/* Eighty-eight-byte indexed payload; only its signed character data is used here. */
typedef struct ScanPayload {
    u8 pad_00[24];
    s8 text[32];
    u8 pad_38[32];
} ScanPayload;
/* Local view of the caller-owned game state, preserving accessor subobjects. */
typedef struct ScanState {
    u32 pad_00;
    u8 grid[0x3148 - 4];
    ScanPayload *payloads;
    u8 pad_314c[0x5508 - 0x314c];
    u8 cells[0x7494 - 0x5508];
    int override;
    s8 *selected;
} ScanState;
/* Returned grid and cell views remain owned by their respective accessors. */
typedef struct ScanGridEntry { u32 unused; u32 flags; } ScanGridEntry;
typedef struct ScanCell { s8 kind; u8 index; } ScanCell;
ScanTable *Unk02e000_Unk_02e8b8(void);
ScanPosition *Unk02e000_GetWorkArea(void);
void *Unk02f2a8_Unk_034970(void *grid, int x, int y);
ScanGridEntry *Unk038fbc_Unk_039160(void *grid, int x, int y);
ScanCell *Unk0a6174_Unk_0a6a88(void *cells, int x, int y);
ScanRecord *Unk0a6174_Unk_0a6ab4(ScanTable *table, int index);
int func_020987ac(int mode, int selector);
void ScanVisor_Unk_0a2a8c(int mode);
void Unk0e5fb8_Unk_0e639c(int index, int state);
void ScanVisor_Unk_0a2ab0(void);
int Unk04bb9c_GetCtxUnka20(void);
void func_0204c698(int event, s16 x, s16 y);
void func_0204c4cc(s16 x, s16 y);

/* Refresh active records in the radius-three diamond around the work coordinates.
 * Evidence: bounds 45x40, sixteen saved active bytes, kind-2 cell lookup and state-2
 * promotion. State and accessor results must be valid; returns whether any qualify. */
int func_020b2100(ScanState *state)
{
    ScanTable *table = Unk02e000_Unk_02e8b8();
    int saved[16] = {0};
    int found = 0;
    int x, y, dx, dy, i;
    int limit;
    ScanGridEntry *entry;
    ScanCell *cell;
    ScanRecord *record;
    for (i = 0; i < 16; i++) {
        saved[i] = table->records[i].active;
        table->records[i].active = 0;
    }
    for (dy = -3; dy <= 3; dy++) {
        y = dy + Unk02e000_GetWorkArea()->y;
        if (y < 0) continue;
        if (y >= 40) break;
        dx = (dy >= 0 ? dy : -dy) - 3;
        limit = 3 - (dy < 0 ? -dy : dy);
        for (; dx <= limit; dx++) {
            x = dx + Unk02e000_GetWorkArea()->x;
            if (x < 0) continue;
            if (x >= 45) break;
            entry = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(state->grid, x, y), x, y);
            if (entry && ((entry->flags << 16) >> 28) && !state->override) continue;
            cell = Unk0a6174_Unk_0a6a88(state->cells, x, y);
            if (cell->kind != 2) continue;
            record = Unk0a6174_Unk_0a6ab4(table, cell->index);
            if (record->enabled != 1 || func_020987ac(0, record->selector) != 1) continue;
            record->active = 1;
            found = 1;
            if (saved[cell->index]) continue;
            ScanVisor_Unk_0a2a8c(0);
            if (record->state >= 2) continue;
            if (record->index >= 0) Unk0e5fb8_Unk_0e639c(record->index, 2);
            record->state = 2;
            ScanVisor_Unk_0a2ab0();
            i = Unk04bb9c_GetCtxUnka20();
            if (i == Unk02e000_GetWorkArea()->area) {
                func_0204c698(19, (s16)x, (s16)y);
                func_0204c4cc((s16)x, (s16)y);
            }
            if (record->index > -1) {
                ScanPayload *payload = &state->payloads[record->index];
                for (i = 0; i < 32; i++) {
                    if (i == 0) {
                        if (payload->text[i] != 48) {
                            state->selected = payload->text;
                            break;
                        }
                    } else if (payload->text[i] != 0) {
                        state->selected = payload->text;
                        break;
                    }
                }
            }
        }
    }
    return found;
}
