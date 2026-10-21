#ifndef GAME_UNIT_0203C274_H
#define GAME_UNIT_0203C274_H

#include "types.h"

/* Script command handlers; each reads its arguments with func_0203ac00(i). */

/* Reads a BGR555 colour and bytes a, b; sends the colour as RGBA8888 with a, b to func_020fd190
 * and (a + 1) * b to the owner's +0xE8 object. Returns 3. */
int func_0203c274(void);
/* Reads an id and an on/off flag; dispatches on the current mode (func_02095818) to the mode's
 * per-id toggle routine, or its no-arg routine when id is 0. Returns 1. */
int func_0203c320(void);
/* Forwards arg 0 to Unk0a0ce4_Unk_0a0da4 (arg 1 is read and ignored). Returns 1. */
int Unk03c274_Unk_03c434(void);
/* Forwards arg 0 to Unk0caea8_Unk_0caf98. Returns 1. */
int Unk03c274_Unk_03c45c(void);

/* Descriptive names for callers. The definitions keep the symbols.txt names because the
 * linked symbols must stay as they are and the match gate looks definitions up by name.
 * The aliases describe the observed behaviour only; the callees are not identified. */
#define ScriptCmd_StartColorEffectAndWait func_0203c274
#define ScriptCmd_ModeToggleById func_0203c320
#define ScriptCmd_ForwardArg0To0a0da4 Unk03c274_Unk_03c434
#define ScriptCmd_ForwardArg0To0caf98 Unk03c274_Unk_03c45c

#endif /* GAME_UNIT_0203C274_H */
