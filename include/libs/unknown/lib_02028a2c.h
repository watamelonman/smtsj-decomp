#ifndef LIB_02028A2C_H
#define LIB_02028A2C_H
#include "libs/unknown/lib_02028d00.h"

/** Submit SI3D texture SRT; material storage remains caller-owned. */
void func_02028a2c(const MaterialAnimation028d00 *anm);
/** Write six 3ds Max texture entries in a caller-owned Q12 matrix. */
void func_02028bf8(TextureMatrix028d00 *m, const MaterialAnimation028d00 *anm);
#endif
