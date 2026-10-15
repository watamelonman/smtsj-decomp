#include "GameState.h"
#include "types.h"

void func_0203428c(void);
void func_0206146c(void);
void func_02057660(int a, int b);

/* Empty callbacks (no direct callers). */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned long long u64;
typedef signed long long s64;
void Unk02f2a8_Nop_0303c8(void) { }
void Unk02f2a8_Nop_0303cc(void) { }
void Unk02f2a8_Nop_035430(void) { }

/* Forwarders. */
void Unk02f2a8_Thunk_0203428c(void) { func_0203428c(); }
void Unk02f2a8_Thunk_0206146c(void) { func_0206146c(); }

GameState *GetGameState(void) { return gGameState; }

/* Calls func_02057660(2, 0). */
void Unk02f2a8_Call_02057660(void) { func_02057660(2, 0); }

u16 GameState_GetUnkField74f4(void) { return gGameState->UnkField74f4; }







