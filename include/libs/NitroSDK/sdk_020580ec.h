#ifndef SDK_020580EC_H
#define SDK_020580EC_H

#include "types.h"

/** Sets or clears bit 15 of the module state at 0x02168b24; argument one sets it. */
void func_020580ec(int enable);

/** Splits a resource name into the character flags before "Plt:" and the palette flags
 * after it. Each letter A-I sets the matching bit (A = bit 0 through I = bit 8).
 * Returns one when the name contains "Plt:", zero otherwise; both outputs are cleared
 * before parsing and always belong to the caller. */
int func_0205811c(const char *name, u32 *flags, u32 *paletteFlags);

/** Applies a resource name's character and palette flags through the first display-bank
 * accessor pair. Terminates the process when the name has no "Plt:" marker. */
void func_02058258(const char *name);

/** Applies a resource name's flags through the character/palette accessors selected by
 * mode (zero selects the first pair). The palette half is skipped when the name has no
 * "Plt:" marker. */
void func_02058290(int mode, const char *name);

/** Applies a resource name's flags through the second character/palette accessor pair
 * selected by mode (zero selects the first pair), with the same missing-marker rule as
 * func_02058290. */
void func_02058300(int mode, const char *name);

#endif
