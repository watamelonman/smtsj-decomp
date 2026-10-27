#ifndef SDK_02003E3C_H
#define SDK_02003E3C_H

#include "types.h"

/** Pack blend planes and coefficients (0..16) into caller-selected blend registers. */
void func_02003e3c(volatile u32 *control, u32 plane1, u32 plane2, s32 eva, s32 evb);
/** Select brighten/darken with a signed level (-16..16); control spans three halfwords. */
void func_02003e58(volatile u16 *control, u32 planes, s32 brightness);
/** Load sixteen caller-owned Q12 matrix words into the current geometry matrix. */
void func_02003e80(const s32 *matrix);
/** Load twelve caller-owned Q12 matrix words into the current geometry matrix. */
void func_02003e9c(const s32 *matrix);
/** Multiply the current geometry matrix by twelve caller-owned Q12 words. */
void func_02003eb8(const s32 *matrix);
/** Multiply the current geometry matrix by nine caller-owned Q12 words. */
void func_02003ed4(const s32 *matrix);
/** Drain pending geometry commands before returning; geometry hardware must be enabled. */
void func_02004068(void);
/** Upload eight caller-owned words (32 fog-density bytes) to geometry hardware. */
void func_02004270(const u32 *table);

#endif
