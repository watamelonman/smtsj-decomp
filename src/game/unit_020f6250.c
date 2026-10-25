#include "game/unit_020f6250.h"

/* External call contracts inferred from register arguments in these handlers. */
Unk0f6250GlobalWork *Unk02e000_GetWorkArea(void);
void func_02065bc0(void);
int Unk04bb9c_Unk_04c98c(u32 x, u32 y, u16 area);
void func_0204c804(u32 kind, u32 x, u32 y, u16 area);
int func_020654cc(void);
void func_0206597c(u32 value);
int func_02065cd0(void);
void func_02065c58(void);
void func_0205257c(u32 mode);
int func_02052728(void);
void func_02034b7c(u32 area, s32 x, s32 y, u32 direction, u32 a, u32 b, u32 c, u32 d);
Unk0f6250Cell *Unk02f2a8_GetCurrentCell38e8(void);
void func_02052da0(void);
void Unk09a268_Unk_09a870(Unk0f6250Cell *cell, int value);
void ScanVisor_Unk_0a2acc(void);
void ScanVisor_Unk_0a2a8c(int index);
void ScanVisor_Unk_0a2b38(void);
void Unk095560_Unk_09615c(void);
void func_020396cc(void *work);
void Unk02f2a8_Unk_0343b4(void *work);
void Unk09974c_Unk_09974c(void *work);
void Unk11f2d0_Unk_11f2d0(void *work);
int func_020395f8(void *work, const void *data);
extern const u8 data_02150e54[];
void func_020525cc(u32 value);
u32 Unk02f2a8_GetRes36Unk1a(u32 area);
u32 Unk02f2a8_GetRes36Unk19(u32 area);
u32 Unk02f2a8_Unk_035b08(u32 table, s32 index);
void func_0209a4fc(void *work, int value);
void func_0209a588(void *work, int a, int b, int c, int d, int e);
void Unk0a0ce4_Unk_0a0da4(u32 value);
int func_02053800(u32 port, u32 mask);
void Unk02f2a8_SetField7470(u32 area, s32 x, s32 y);
void func_0204c8f4(u32 x, u32 y, u16 area);
int func_020a4f3c(void);
void *Unk02f2a8_Unk_034970(void *work, s32 x, s32 y);
Unk0f6250CellHeader *Unk038fbc_Unk_039160(void *map, s32 x, s32 y);
Unk0f6250VariantRecord *Unk038fbc_GetElement(void *map, u32 kind, u32 index);
u32 Unk02f2a8_Unk_0349c4(void *work, s32 x, s32 y);
u32 Unk0e651c_Get2Bits(u32 value, u32 index);
Unk0f6250CellConfig *Unk09a268_Unk_09c484(u32 kind);
void Unk09a268_Unk_09a80c(Unk0f6250Cell *cell, int value);
void Unk09a268_Unk_09a830(Unk0f6250Cell *cell, int value);
void Unk09a268_SetOnlyBit(Unk0f6250Cell *cell, u32 bit);
void func_02052d7c(void *work, u32 value);
int func_0202d170(void);
int Unk02d15c_IsMode1Match(int mode);
void func_02095f94(void);
void func_0202d198(void);
void func_0204faf0(u16 index, u16 value);
u32 Unk095560_Unk_095778(u32 id);
void func_020658dc(u32 value, u32 a, u32 b, u32 flags);
int func_0206559c(void);
u32 func_02065e1c(void);
void func_02065c30(void);

/* Advance the four preparation phases; coordinates are unsigned for map queries,
 * as evidenced by LDRB, while the phase is a signed byte. */
int func_020f6354(Unk0f6250SceneWork *work)
{
    int done = 0;
    switch (work->substate) {
    case 0:
        func_02065bc0();
        if (Unk04bb9c_Unk_04c98c((u8)work->x, (u8)work->y, Unk02e000_GetWorkArea()->unk_035c) == 0)
            func_0204c804(13, (u8)work->x, (u8)work->y, Unk02e000_GetWorkArea()->unk_035c);
        work->substate++;
        break;
    case 1:
        if (func_020654cc() == 1) { func_0206597c(26); work->substate++; }
        break;
    case 2:
        if (func_02065cd0() == 1) { func_02065c58(); work->substate++; }
        break;
    case 3:
        if (func_020654cc() == 1) done = 1;
        break;
    default: done = 1; break;
    }
    return done;
}

/* Wait for the mode change, move one cell along the global direction, then wait
 * for +0x7440. The four direction cases are evidenced by coordinate +/-1. */
int func_020f6998(Unk0f6250SceneWork *work)
{
    int done = 0;
    work->timer++;
    switch (work->substate) {
    case 0:
        if (func_020654cc() == 1) {
            func_0205257c(3);
            work->parent->unk_0014 = 4;
            work->parent->unk_0018 = 3;
            work->timer = 0;
            work->substate++;
        }
        break;
    case 1:
        if (func_02052728() == 0) {
            Unk0f6250GlobalWork *global = Unk02e000_GetWorkArea();
            int x = work->x;
            int y = work->y;
            switch (global->direction) {
            case 0: y--; break;
            case 1: x++; break;
            case 2: y++; break;
            case 3: x--; break;
            }
            func_02034b7c(global->unk_035c, x, y, global->direction, 3, 0, 0, 1);
            work->timer = 0;
            work->substate++;
        }
        break;
    case 2:
        if (work->unk_7440 != 0) done = 1;
        break;
    default: done = 1; break;
    }
    return done;
}

/* Count frames through four transition phases and initialize embedded blocks.
 * The calls to ScanVisor and the 40/10/2 thresholds are direct assembly evidence. */
int func_020f6454(Unk0f6250SceneWork *work)
{
    Unk0f6250Cell *cell = Unk02f2a8_GetCurrentCell38e8();
    int done = 0;
    func_02052da0();
    work->timer++;
    cell->counter++;
    switch (work->substate) {
    case 0:
        if (work->timer > 40) {
            Unk09a268_Unk_09a870(cell, 0);
            work->parent->unk_0014 = 2;
            work->parent->unk_0018 = 2;
            work->timer = 0;
            work->substate++;
        }
        break;
    case 1:
        if (work->timer > 10) {
            func_0205257c(3);
            work->timer = 0;
            work->substate++;
        }
        break;
    case 2:
        if (func_02052728() == 0) {
            int i;
            ScanVisor_Unk_0a2acc();
            for (i = 0; i < 7; i++) ScanVisor_Unk_0a2a8c(i);
            work->unk_73d8 = 0;
            ScanVisor_Unk_0a2b38();
            Unk095560_Unk_09615c();
            func_020396cc((u8 *)work + 4);
            Unk02f2a8_Unk_0343b4((u8 *)work + 4);
            Unk09974c_Unk_09974c((u8 *)work + 0x7550);
            Unk11f2d0_Unk_11f2d0((u8 *)work + 0x7598);
            work->timer = 0;
            work->substate++;
        }
        break;
    case 3:
        if (work->timer > 2 && func_020395f8((u8 *)work + 4, data_02150e54) == 1) {
            func_020525cc(3);
            work->timer = 0;
            work->substate = 0;
            work->state = 2;
        }
        break;
    default: done = 1; break;
    }
    return done;
}

/* Select a destination from resource 36 and request the map transition after
 * input or timeout; state-4 indexes the resource, as the SUB instruction shows. */
int func_020f6af0(Unk0f6250SceneWork *work)
{
    int done = 0;
    work->timer++;
    switch (work->substate) {
    case 0:
        if (func_020654cc() == 1) {
            int mode;
            if (Unk02f2a8_GetRes36Unk1a(Unk02e000_GetWorkArea()->unk_035c) < work->state - 4) mode = 1;
            else mode = 2;
            func_0209a4fc((u8 *)work + 4, 0);
            func_0209a588((u8 *)work + 4, 0, mode, mode, mode, 0);
            Unk0a0ce4_Unk_0a0da4(53);
            work->timer = 0;
            work->substate++;
        }
        break;
    case 1:
        if ((work->timer > 20 && func_02053800(0, 3) == 1) || work->timer > 200) {
            Unk0f6250GlobalWork *global = Unk02e000_GetWorkArea();
            u32 area = Unk02f2a8_Unk_035b08(Unk02f2a8_GetRes36Unk19(global->unk_035c), work->state - 4);
            Unk02f2a8_SetField7470(area, work->x, work->y);
            func_02034b7c(area, work->x, work->y, global->direction, 3, 1, 0, 1);
            if (Unk04bb9c_Unk_04c98c((u8)work->x, (u8)work->y, area) == 13)
                func_0204c8f4((u8)work->x, (u8)work->y, area);
            work->timer = 0;
            work->substate++;
        }
        break;
    case 2:
        if (func_020a4f3c() == 0 && func_02052728() == 0) {
            Unk0a0ce4_Unk_0a0da4(54);
            work->timer = 0;
            work->substate++;
        }
        break;
    case 3:
        if (work->unk_7440 != 0) done = 1;
        break;
    default: done = 1; break;
    }
    return done;
}

/* Choose state 1 when the current variant has its direction bit enabled, then
 * initialize the current cell and copy the resource record. Bit positions and
 * the four-entry bound are established by the original extraction loop. */
void func_020f6d0c(Unk0f6250SceneWork *work)
{
    int y = work->y;
    int x = work->x;
    Unk0f6250CellHeader *header = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970((u8 *)work + 4, x, y), x, y);
    Unk0f6250VariantRecord *record = Unk038fbc_GetElement(Unk02f2a8_Unk_034970((u8 *)work + 4, work->x, work->y), 2, header->index);
    u32 variant, direction;
    int i;
    work->state = 0;
    variant = Unk02f2a8_GetRes36Unk1a(Unk02e000_GetWorkArea()->unk_035c);
    direction = Unk0e651c_Get2Bits(Unk02f2a8_Unk_0349c4((u8 *)work + 4, work->x, work->y), record->direction_index);
    for (i = 0; i < 4; i++) {
        if (variant == record->entries[i].variant) {
            u32 enabled = 0;
            switch (direction) {
            case 0: enabled = record->entries[i].north; break;
            case 1: enabled = record->entries[i].east; break;
            case 2: enabled = record->entries[i].south; break;
            case 3: enabled = record->entries[i].west; break;
            }
            if (enabled == 1) work->state = 1;
            break;
        }
    }
    if (work->state == 1) {
        Unk0f6250CellConfig *config;
        Unk0f6250Cell *cell;
        work->record = *record;
        config = Unk09a268_Unk_09c484(5);
        cell = Unk02f2a8_GetCurrentCell38e8();
        Unk09a268_Unk_09a80c(cell, 1);
        Unk09a268_Unk_09a830(cell, 0);
        Unk09a268_SetOnlyBit(cell, config->unk_0019);
        cell->unk_0001 = 1;
        cell->counter = 0;
        Unk0a0ce4_Unk_0a0da4(work->unk_0058);
        func_02052d7c((u8 *)work + 0xa8, work->unk_00a4);
        work->unk_748c = 1;
        work->unk_7490 = 1;
        if (Unk04bb9c_Unk_04c98c((u8)work->x, (u8)work->y, Unk02e000_GetWorkArea()->unk_035c) == 13)
            func_0204c8f4((u8)work->x, (u8)work->y, Unk02e000_GetWorkArea()->unk_035c);
    }
}

/* Build a list of enabled alternative variants, wait for a selection, and encode
 * its variant as state = variant+4. Resource entries, direction bits and message
 * IDs 27..29 are evidenced by 020f6604; broader UI semantics remain unknown. */
int func_020f6604(Unk0f6250SceneWork *work)
{
    int done = 0;
    work->timer++;
    switch (work->substate) {
    case 0:
        if (func_02052728() == 0) {
            if (func_0202d170() != 0) {
                int mode = 7;
                do {
                    if (Unk02d15c_IsMode1Match(mode) == 1) {
                        work->unk_73e0 = 1;
                        work->parent->unk_0004 = 0;
                        func_02095f94();
                        break;
                    } else {
                        func_0202d198();
                    }
                } while (func_0202d170() != 0);
            }
            work->timer = 0;
            work->substate++;
        }
        break;
    case 1:
        if (work->unk_73e0 == 0) {
            func_02065bc0();
            work->timer = 0;
            work->substate++;
        }
        break;
    case 2:
        if (func_020654cc() == 1) {
            u32 table = Unk02f2a8_GetRes36Unk19(Unk02e000_GetWorkArea()->unk_035c);
            u32 variant = Unk02f2a8_GetRes36Unk1a(Unk02e000_GetWorkArea()->unk_035c);
            u32 direction = Unk0e651c_Get2Bits(Unk02f2a8_Unk_0349c4((u8 *)work + 4, work->x, work->y), work->record.direction_index);
            int count = 0;
            int i;
            u32 message;
            for (i = 0; i < 4; i++) {
                if (variant != work->record.entries[i].variant) {
                    u32 enabled = 0;
                    switch (direction) {
                    case 0: enabled = work->record.entries[i].north; break;
                    case 1: enabled = work->record.entries[i].east; break;
                    case 2: enabled = work->record.entries[i].south; break;
                    case 3: enabled = work->record.entries[i].west; break;
                    }
                    if (enabled == 1) {
                        func_0204faf0(count + 1, Unk02f2a8_Unk_035b08(table, work->record.entries[i].variant));
                        count++;
                    }
                }
            }
            message = 27;
            switch (count) {
            case 1: break;
            case 2: message = 28; break;
            case 3: message = 29; break;
            }
            func_020658dc(Unk095560_Unk_095778(message), 0, 0, 0x00000101);
            work->substate++;
        }
        break;
    case 3:
        if (func_0206559c() == 1) {
            u32 selection = (u8)func_02065e1c();
            u32 variant, direction;
            int count = 0, i;
            Unk02f2a8_GetRes36Unk19(Unk02e000_GetWorkArea()->unk_035c);
            variant = Unk02f2a8_GetRes36Unk1a(Unk02e000_GetWorkArea()->unk_035c);
            direction = Unk0e651c_Get2Bits(Unk02f2a8_Unk_0349c4((u8 *)work + 4, work->x, work->y), work->record.direction_index);
            count = 0;
            for (i = 0; i < 4; i++) {
                if (variant != work->record.entries[i].variant) {
                    u32 enabled = 0;
                    switch (direction) {
                    case 0: enabled = work->record.entries[i].north; break;
                    case 1: enabled = work->record.entries[i].east; break;
                    case 2: enabled = work->record.entries[i].south; break;
                    case 3: enabled = work->record.entries[i].west; break;
                    }
                    if (enabled == 1) {
                        if (selection == count) {
                            work->state = work->record.entries[i].variant + 4;
                            break;
                        }
                        count++;
                    }
                }
            }
            if (work->state == 2) work->state = 3;
            func_02065c30();
            work->timer = 0;
            work->substate = 0;
        }
        break;
    default: done = 1; break;
    }
    return done;
}

/* Keep this dispatcher after its callees for relocation matching. See DEC-008.
 * Dispatch the signed state byte; states outside 0..3 use the final handler,
 * as evidenced by the jump table and its default branch. */
int func_020f6ef8(Unk0f6250SceneWork *work)
{
    switch (work->state) {
    case 0: return func_020f6354(work);
    case 1: return func_020f6454(work);
    case 2: return func_020f6604(work);
    case 3: return func_020f6998(work);
    default: return func_020f6af0(work);
    }
}

