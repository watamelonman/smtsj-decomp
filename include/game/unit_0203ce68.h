#ifndef GAME_UNIT_0203CE68_H
#define GAME_UNIT_0203CE68_H

#include "types.h"

/* Script command handlers; each reads its arguments with func_0203ac00(i), reports any value through
 * Unk03aae8_Unk_03acf4 and returns completion status 1. See docs/functions/game-unit-0203ce68.md. */

/* Reports the work block's u16 slot arg0 (0..3; 0 for others). */
int Unk03ce68_Unk_03ce68(void);
/* Stores id arg1 in work slot 0..3 when Unk09974c_GetEntryUnk08(id) is 3..6. */
int Unk03ce68_Unk_03ced0(void);
int Unk03ce68_Unk_03cf48(void);
u32 Unk03ce68_Unk_03cf78(void);
u32 Unk03ce68_Unk_03cf94(void);
u32 Unk03ce68_Unk_03cfb4(void);
u32 Unk03ce68_Unk_03cfc4(void);
int Unk03ce68_Unk_03cfd4(void);
u32 Unk03ce68_Unk_03cff4(void);
u32 Unk03ce68_Unk_03d010(void);
/* Maps a selector 0..4 to 0, 4, 1, 2, 3 (others to 0). */
int Unk03ce68_Unk_03d038(int sel);
/* Reports a per-target signed byte (target arg0, remapped selector arg1). */
int Unk03ce68_Unk_03d088(void);
/* Stores value arg2 into the per-target byte selected like Unk03ce68_Unk_03d088. */
int Unk03ce68_Unk_03d0f0(void);

#endif /* GAME_UNIT_0203CE68_H */
