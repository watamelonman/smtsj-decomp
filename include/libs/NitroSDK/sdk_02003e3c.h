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

/** Set fog mode/slope and offset; values must fit the GX hardware fields. */
void func_020041b8(u32 enable, u32 alphaMode, u32 slope, s32 offset);
/** Copy sixteen clip-matrix words to caller storage; return -1 if busy, else zero. */
s32 func_02004210(s32 *matrix);
/** Copy nine vector-matrix words to caller storage; return -1 if busy, else zero. */
s32 func_02004240(s32 *matrix);
/** Set clear color (15 bits), alpha (0..31), depth (15 bits), ID (0..63) and fog. */
void func_02004284(u32 color, u32 alpha, u32 depth, u32 polygonId, u32 fog);
/** Write the position/vector stack level only when ready; return -1 if busy. */
s32 func_0200434c(u32 *level);
/** Write the projection stack level only when ready; return -1 if busy. */
s32 func_0200437c(u32 *level);
/** Construct a Q12 perspective matrix; optional output has sixteen words.
 * Nonzero draw loads it into GX; sine, aspect and clip differences must be nonzero. */
void func_02004440(s32 fovSin, s32 fovCos, s32 aspect, s32 nearPlane,
                   s32 farPlane, s32 scale, u32 draw, s32 *matrix);
/** Construct a Q12 view matrix from three-word vectors; optional output has twelve
 * words. Nonzero draw loads GX. Position/target and up must define a valid basis. */
void func_02004500(const s32 *position, const s32 *up, const s32 *target,
                   u32 draw, s32 *matrix);

#endif
