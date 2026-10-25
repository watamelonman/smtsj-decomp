#ifndef GAME_UNIT_020F6250_H
#define GAME_UNIT_020F6250_H

#include "types.h"

/* Four packed resource entries: low nibble selects an area variant, upper bits
 * enable it for each direction (020f6d0c/020f6604). */
typedef struct {
    u8 variant : 4;
    u8 north : 1;
    u8 east : 1;
    u8 south : 1;
    u8 west : 1;
} Unk0f6250VariantEntry;
/* An eight-byte resource element copied by value into the scene work. */
typedef struct { Unk0f6250VariantEntry entries[4]; u32 flags_low : 8; u32 direction_index : 8; u32 flags_high : 16; } Unk0f6250VariantRecord;

/* Borrowed global-work view; +358 supplies direction and +35c supplies area. */
typedef struct {
    u8 pad_0000[0x358];
    /* Reload at each use, matching the original accesses. See DEC-008. */
    volatile u32 direction;
    u16 unk_035c;
} Unk0f6250GlobalWork;
/* Unk0f6250Parent state words written independently by the scene transitions. */
typedef struct { s32 unk_0000, unk_0004, unk_0008, unk_000c, unk_0010, unk_0014, unk_0018; } Unk0f6250Parent;
/* Partial scene layout; padding spans fields not accessed by these handlers. */
typedef struct {
    Unk0f6250Parent *parent;
    u8 pad_0004[0x58 - 4];
    u16 unk_0058;
    u8 pad_005a[0xa4 - 0x5a];
    u32 unk_00a4;
    u8 pad_00a8[0x73d8 - 0xa8];
    s32 unk_73d8;
    s32 unk_73dc;
    s32 unk_73e0;
    u8 pad_73e4[0x7440 - 0x73e4];
    s32 unk_7440;
    u8 pad_7444[0x7480 - 0x7444];
    s8 state;
    s8 substate;
    s8 x, y;
    s32 timer;
    u8 pad_7488[0x748c - 0x7488];
    s32 unk_748c, unk_7490;
    u8 pad_7494[8];
    Unk0f6250VariantRecord record;
} Unk0f6250SceneWork;

/* Unk0f6250Cell layout evidenced by the halfword counter at +2 in 020f6454. */
typedef struct { u8 unk_0000, unk_0001; u16 counter; } Unk0f6250Cell;

/* Unk0f6250Cell header byte +1 supplies the resource element index. */
typedef struct { u8 unk_0000, index; } Unk0f6250CellHeader;
/* Only the byte at +0x19 is observed in the cell-setup path. */
typedef struct { u8 pad_0000[0x19]; u8 unk_0019; } Unk0f6250CellConfig;

/* Advance preparation phases; work is borrowed and must contain the scene layout. */
int func_020f6354(Unk0f6250SceneWork *work);
/* Advance the timed cell transition; return nonzero only for an unknown phase. */
int func_020f6454(Unk0f6250SceneWork *work);
/* Build and consume the alternative-variant selection in borrowed scene work. */
int func_020f6604(Unk0f6250SceneWork *work);
/* Request a neighboring-cell transition and report completion. */
int func_020f6998(Unk0f6250SceneWork *work);
/* Request the resource-selected destination and report completion. */
int func_020f6af0(Unk0f6250SceneWork *work);
/* Initialize the scene state from its four-entry resource record. */
void func_020f6d0c(Unk0f6250SceneWork *work);
/* Forward the completion result from the handler selected by the state byte. */
int func_020f6ef8(Unk0f6250SceneWork *work);

#endif
