#ifndef GAME_UNIT_0203BBA4_H
#define GAME_UNIT_0203BBA4_H

#include "types.h"

/* Partial view of the work area returned by Unk02e000_GetWorkArea.
 * Only the fields read by unit_0203bba4 are named; the total size is unknown
 * and the gaps are padding, not known layout. */
typedef struct Unk02e000WorkArea {
    u8 pad_0000[0x358];
    u32 unk_0358;
    u8 pad_035c[8];
    s8 unk_0364;
    s8 unk_0365;
} Unk02e000WorkArea;

/* Partial view of the subobject at Unk03aae8Ctx.unk_00e8; unk_0018 holds the
 * substate code written by the command callbacks (6, 19). Size unknown. */
typedef struct Unk03bba4Sub {
    u8 pad_0000[0x18];
    u32 unk_0018;
} Unk03bba4Sub;

/* Partial view of the context returned by Unk03aae8_Unk_03ad14. Size unknown. */
typedef struct Unk03aae8Ctx {
    u8 pad_0000[0xe8];
    Unk03bba4Sub *unk_00e8;
} Unk03aae8Ctx;

#endif
