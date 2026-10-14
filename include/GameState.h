/* Global game state at gGameState (data_0215dd2c). Field meanings are mostly
 * unknown; names are UnkFieldXXXX until a use site makes them clear. */
#ifndef RE_FORGE_GAME_STATE_H
#define RE_FORGE_GAME_STATE_H

#include "types.h"

typedef struct GameState {
    u8  UnkField0000[0x74f4];
    u16 UnkField74f4;           /* read by GameState_GetUnkField74f4 */
    /* remaining fields not yet named */
} GameState;

extern GameState *gGameState;

GameState *GetGameState(void);
u16 GameState_GetUnkField74f4(void);

#endif
