#ifndef GAME_UNIT_020EE904_H
#define GAME_UNIT_020EE904_H

#include "types.h"

/* Mode eligibility callback: 0 when mode 1 or 2 is currently blocked, else 1. */
int func_020ee904(void *self, int mode);
/* Runs the setup calls for the state (0..3) stored in obj. */
void func_020ee958(void *obj);
/* Re-initialises the work sub-object (unless already set up) and requests the next step. */
void Unk0ee904_Unk_0eeadc(void);

/* Descriptive names for callers. The definitions keep the symbols.txt names because the
 * linked symbols must stay as they are and the match gate looks definitions up by name. */
#define Unk0ee904_IsModeAvailable func_020ee904
#define Unk0ee904_SetupForState func_020ee958
#define Unk0ee904_ResetWork Unk0ee904_Unk_0eeadc

#endif /* GAME_UNIT_020EE904_H */
