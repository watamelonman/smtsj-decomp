/* Global game state pointed to by gGameState (BSS 0x0215dd2c).
 *
 * Layout from matched C only. Field names are hedged (unk_*) unless a use site
 * makes the meaning clear; see docs/structs.md for confidence notes.
 */
#ifndef RE_FORGE_GAME_STATE_H
#define RE_FORGE_GAME_STATE_H

#include "types.h"

typedef struct GameStateRoot {
    u8  pad_00[4];
    u32 unk_04;
    u8  pad_08[4];
    u32 unk_0c;
    u8  pad_10[4];
    u32 unk_14;
    u32 unk_18;
    u8  pad_1c[0x40];
    u32 unk_5c;
} GameStateRoot;

typedef struct GameState {
    GameStateRoot *root;        /* +0x0000 */
    u8  pad_0004[0x3130];
    u8  unk_3134[0xc];          /* +0x3134  sub-object, torn down by GameState_Shutdown */
    u8  unk_3140[0xc];          /* +0x3140  sub-object (Unk0387bc_*) */
    u8  unk_314c[0x79c];        /* +0x314C  sub-object (Unk038fbc_*); size unknown */
    u8  unk_38e8[4];            /* +0x38E8  base passed to func_0209a884 */
    u8  pad_38ec[0x3ae0];
    u32 unk_73cc;               /* +0x73CC */
    u32 unk_73d0;               /* +0x73D0 */
    u8  pad_73d4[4];
    u32 unk_73d8;               /* +0x73D8 */
    u8  pad_73dc[8];
    u32 unk_73e4;               /* +0x73E4 */
    u32 unk_73e8;               /* +0x73E8  mode id */
    u8  pad_73ec[8];
    u16 unk_73f4;               /* +0x73F4 */
    u16 unk_73f6;               /* +0x73F6 */
    u16 unk_73f8;               /* +0x73F8 */
    u8  pad_73fa[6];
    u32 unk_7400;               /* +0x7400 */
    u8  pad_7404[0x2c];
    u32 unk_7430;               /* +0x7430 */
    u32 unk_7434;               /* +0x7434 */
    u32 unk_7438;               /* +0x7438 */
    u8  pad_743c[0x44];
    u8  unk_7480;               /* +0x7480 */
    u8  pad_7481[0x73];
    u16 unk_74f4;               /* +0x74F4 */
    u8  pad_74f6[0x5a];
    u8  unk_7550[0x48];         /* +0x7550 */
    u8  unk_7598[4];            /* +0x7598 */
} GameState;

extern GameState *gGameState;

GameState *GetGameState(void);
u16 GameState_GetUnkField74f4(void);

#endif
