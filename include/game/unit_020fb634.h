#ifndef GAME_UNIT_020FB634_H
#define GAME_UNIT_020FB634_H

#include "types.h"

/*
 * Work object driven by func_020fb634. Only the offsets that function touches are typed;
 * the gaps are padding.
 */
typedef struct Unk0fb634Work {
    s32 state;          /* 0x00: update state, 0-8 */
    u8 list[0x24];      /* 0x04: Unk0d297c list object; size guessed from its last known field (+0x20) */
    s32 unk_0028;       /* 0x28: current source id, passed to func_020d2c44 */
    s32 unk_002c;       /* 0x2c: requested source id; a change restarts the list build */
    u32 unk_0030;       /* 0x30: output handle for func_02061f10 / func_02060f40 */
    u8 pad_0034[4];
    u16 unk_0038;       /* 0x38: first row of the shown page */
    u8 pad_003a[2];
    s32 unk_003c;       /* 0x3c: row count, from CampStatus_GetUnkField1c(list) */
    u32 unk_0040;       /* 0x40: intro animation 1 */
    u32 unk_0044;       /* 0x44: intro animation 2 */
    u32 unk_0048;       /* 0x48: intro animation 3 */
    u32 unk_004c;       /* 0x4c: animation ticked every frame */
    s32 unk_0050;       /* 0x50: 1 when more rows remain than fit on one page (10) */
} Unk0fb634Work;

/* Per-frame update of the paged list screen; see docs/functions/game-unit-020fb634.md. */
void func_020fb634(Unk0fb634Work *w);

/* Proposed symbols.txt rename (symbols.txt is human-owned). */
#define Unk0fb634_UpdateListScreen func_020fb634

#endif
